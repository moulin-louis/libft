//
// Created by loumouli on 2/7/24.
//

#include "t_rb.h"
#include "libft.h"

static void ft_rb_treeInsert(t_cmp_fn cmp_fn, t_rbNode** root, t_rbNode* node);
static void ft_rb_treeBalanceInsertion(t_rb* rb, t_rbNode* node);
static void ft_rb_rotateLeft(t_rb* rb, t_rbNode* node);
static void ft_rb_rotateRight(t_rb* rb, t_rbNode* node);
static t_rbNode* ft_rb_newNode(const void* data);
static int simple_cmp(const void* data1, const void* data2);
static uint64_t inorder(const t_rbNode* node, uint64_t (*fn)(const t_rbNode*));

t_rb* ft_rb_new(const t_cmp_fn cmp_fn, const uint64_t nbytes_data) {
  t_rb* result = calloc(1, sizeof(t_rbNode));
  if (result == NULL)
    return NULL;
  cmp_fn ? (result->cmp_fn = cmp_fn) : (result->cmp_fn = simple_cmp);
  result->nbytes_data = nbytes_data;
  return result;
}

void ft_rb_destroy(t_rb* rb) {
  // ITERATE OVER ALL NODE AND FREE THEM
  free(rb);
}

uint64_t ft_rb_insert(t_rb* rb, const void* data) {
  // Insert the data like we are in a classic binary tree, can damage the red/black integrity
  t_rbNode* node = ft_rb_newNode(data);
  if (node == NULL)
    return 1;
  if (rb->root == NULL) {
    node->color = BLACK;
    rb->root = node;
    return 0;
  }
  ft_rb_treeInsert(rb->cmp_fn, &rb->root, node);
  ft_rb_treeBalanceInsertion(rb, node);
  return 0;
}

bool ft_rb_has(const t_rb* rb, const void* data) { return ft_rb_get(rb, data) ? true : false; }

const t_rbNode* ft_rb_get(const t_rb* rb, const void* data) {
  const t_rbNode* x = rb->root;
  while (x != NULL) {
    if (rb->cmp_fn(x->data, data) == 0)
      return x;
    if (rb->cmp_fn(x->data, data) < 0)
      x = x->right;
    else
      x = x->left;
  }
  return NULL;
}

uint64_t ft_rb_iterItem(const t_rb* rb, uint64_t (*iter_fn)(const t_rbNode*)) { return inorder(rb->root, iter_fn); }

void ft_rb_print(const t_rbNode* root, uint64_t space) {
  if (root == NULL)
    return;
  space += 10;
  ft_rb_print(root->right, space);
  printf("\n");
  for (uint64_t i = 10; i < space; i++)
    printf(" ");
  printf("%#lx|%s\n", (uint64_t)root->data, root->color ? "BLACK" : "RED");
  ft_rb_print(root->left, space);
}

// Private FN, insert a node inside the tree
static void ft_rb_treeInsert(t_cmp_fn cmp_fn, t_rbNode** root, t_rbNode* node) {
  t_rbNode* y = NULL;
  t_rbNode* x = *root;
  while (x != NULL) {
    y = x;
    if (cmp_fn(node->data, x->data) < 0)
      x = x->left;
    else
      x = x->right;
  }
  node->parent = y;
  if (cmp_fn(node->data, y->data) > 0)
    y->right = node;
  else
    y->left = node;
  node->color = RED;
}

// Private FN, to balance the tree after the insertion
static void ft_rb_treeBalanceInsertion(t_rb* rb, t_rbNode* node) {
  while (node != rb->root && node != rb->root->left && node != rb->root->right && node->parent->color == RED) {
    t_rbNode* y = NULL;
    if (node->parent && node->parent->parent && node->parent == node->parent->parent->left)
      y = node->parent->parent->right;
    else
      y = node->parent->parent->left;
    if (!y)
      node = node->parent->parent;
    else if (y->color == RED) {
      y->color = BLACK;
      node->parent->color = BLACK;
      node->parent->parent->color = RED;
      node = node->parent->parent;
      continue;
    }
    // case 0
    if (node->parent && node->parent->parent && node->parent == node->parent->parent->left &&
        node == node->parent->left) {
      const e_color tmp = node->parent->color;
      node->parent->color = node->parent->parent->color;
      node->parent->parent->color = tmp;
      ft_rb_rotateRight(rb, node->parent->parent);
    }
    // case 1
    if (node->parent && node->parent->parent && node->parent == node->parent->parent->left &&
        node == node->parent->right) {
      const e_color tmp = node->color;
      node->color = node->parent->parent->color;
      node->parent->parent->color = tmp;
      ft_rb_rotateLeft(rb, node->parent);
      ft_rb_rotateRight(rb, node->parent->parent);
    }
    // case 2
    if (node->parent && node->parent->parent && node->parent == node->parent->parent->right &&
        node == node->parent->right) {
      const e_color tmp = node->parent->color;
      node->parent->color = node->parent->parent->color;
      node->parent->parent->color = tmp;
      ft_rb_rotateLeft(rb, node->parent->parent);
    }
    // case 3
    if (node->parent && node->parent->parent && node->parent == node->parent->parent->right &&
        node == node->parent->left) {
      const e_color tmp = node->color;
      node->color = node->parent->parent->color;
      node->parent->parent->color = tmp;
      ft_rb_rotateRight(rb, node->parent);
      ft_rb_rotateLeft(rb, node->parent->parent);
    }
  }
  rb->root->color = BLACK;
}

// Private FN, left rotate the node inside the RB tree
static void ft_rb_rotateLeft(t_rb* rb, t_rbNode* node) {
  if (node == NULL || node->right == NULL)
    return;
  t_rbNode* y = node->right;
  node->right = y->left;
  if (node->right != NULL)
    node->right->parent = node;
  y->parent = node->parent;
  if (node->parent == NULL)
    rb->root = y;
  else if (node == node->parent->left)
    node->parent->left = y;
  else
    node->parent->right = y;
  y->left = node;
  node->parent = y;
}

// Private FN, right rotate the node inside the RB tree
static void ft_rb_rotateRight(t_rb* rb, t_rbNode* node) {
  if (node == NULL || node->left == NULL)
    return;
  t_rbNode* y = node->left;
  y->left = node->right;
  if (node->right != NULL)
    node->parent = y->parent;
  node->parent = y->parent;
  if (node->parent == NULL)
    rb->root = node;
  else if (y == y->parent->left)
    y->parent->left = node;
  else
    y->parent->right = node;
  node->right = y;
  y->parent = node;
}

// Private FN, create a new node on the heap that hold data
static t_rbNode* ft_rb_newNode(const void* data) {
  t_rbNode* result = calloc(1, sizeof(t_rbNode));
  if (result == NULL)
    return NULL;
  result->color = RED;
  result->data = data;
  return result;
}

// Privatae FN, simple cmp FN if none is provided by the user
static int simple_cmp(const void* data1, const void* data2) { return data1 - data2; }

static uint64_t inorder(const t_rbNode* node, uint64_t (*fn)(const t_rbNode*)) {
  if (node == NULL)
    return 0;
  inorder(node->left, fn);
  if (fn(node))
    return 1;
  inorder(node->right, fn);
  return 0;
}
