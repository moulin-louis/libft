//
// Created by loumouli on 2/7/24.
//

#include "t_rb.h"
#include "libft.h"

static void ft_rb_treeFixViolation(t_rb* rb, t_rbNode* node);
static void ft_rb_rotateLeft(t_rb* rb, t_rbNode* node);
static void ft_rb_rotateRight(t_rb* rb, t_rbNode* node);
static t_rbNode* ft_rb_newNode(const void* data);
static int simple_cmp(const void* data1, const void* data2);
static void simple_print(const void* data);

t_rb* ft_rb_new(const t_cmp_fn cmp_fn, const t_free_fn free_fn) {
  t_rb* result = calloc(1, sizeof(t_rbNode));
  if (result == NULL)
    return NULL;
  cmp_fn ? (result->cmp_fn = cmp_fn) : (result->cmp_fn = simple_cmp);
  result->free_fn = free_fn;
  return result;
}

void ft_rb_destroy(t_rb* rb) { ft_bTree_destroy((t_bTree*)rb); }

void ft_rb_destroyNode(t_rbNode* rb_node, const t_free_fn free_fn) {
  if (free_fn)
    free_fn((void*)rb_node->data);
  free(rb_node);
}

uint64_t ft_rb_insert(t_rb* rb, const void* data) {
  if (ft_rb_has(rb, data))
    return 1;
  // Insert the data like  we are in a classic binary tree, can damage the red/black integrity
  t_rbNode* node = ft_rb_newNode(data);
  if (node == NULL)
    return 1;
  if (rb->root == NULL) {
    node->color = BLACK;
    rb->root = node;
    return 0;
  }
  ft_bTree_insertNode((t_bTree*)rb, (t_btNode*)node);
  ft_rb_treeFixViolation(rb, node);
  return 0;
}

bool ft_rb_has(const t_rb* rb, const void* data) { return ft_rb_get(rb, data) ? true : false; }

const t_rbNode* ft_rb_get(const t_rb* rb, const void* data) {
  return (const t_rbNode*)ft_bTree_get((t_bTree*)rb, data);
}

const t_rbNode* ft_rb_getMin(const t_rb* rb) { return (const t_rbNode*)ft_bTree_getMin((t_bTree*)rb); }

const t_rbNode* ft_rb_getMax(const t_rb* rb) { return (const t_rbNode*)ft_bTree_getMax((t_bTree*)rb); }

const t_rbNode* ft_rb_inorderNext(const t_rbNode* node) {
  return (const t_rbNode*)ft_bTree_inorderNext((t_btNode*)node);
}

void ft_rb_print(const t_rbNode* root, const uint64_t space) { ft_bTree_printFn((const t_btNode*)root, space, simple_print); }

 void ft_rb_printFn(const t_rbNode* root, uint64_t space, void (*print_data)(const void* data)) {
  ft_bTree_printFn((t_btNode*)root, space, print_data);
}

// Private FN, to balance the tree after the insertion
static void ft_rb_treeFixViolation(t_rb* rb, t_rbNode* node) {
  t_rbNode* u = NULL;
  while (node->parent && node->parent->color == RED) {
    printf("one iter\n");
    if (node->parent == node->parent->parent->right) {
      u = node->parent->parent->left;
      if (u->color == RED) {
        u->color = BLACK;
        node->parent->color = BLACK;
        node->parent->parent = RED;
        node = node->parent->parent;
      }
      else {
        if (node == node->parent->left) {
          node = node->parent;
          ft_rb_rotateRight(rb, node);
        }
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
      }
    }
    else {
      u = node->parent->parent->right;
      if (node->color == RED) {
        u->color = BLACK;
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
      }
      else {
        if (node == node->parent->right) {
          node = node->parent;
          ft_rb_rotateLeft(rb, node);
        }
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        ft_rb_rotateRight(rb, node);
      }
    }
    if (node == rb->root)
      break;
  }
}

// Private FN, left rotate the node inside the RB tree
static void ft_rb_rotateLeft(t_rb* rb, t_rbNode* node) {
  t_rbNode* y = node->right;
  node->right = y->left;
  if (y->left != NULL)
    y->left->parent = node;
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
  t_rbNode* y = node->left;
  node->left = y->right;
  if (y->right != NULL) {
    y->right->parent = node;
  }
  y->parent = node->parent;
  if (node->parent == NULL) {
    rb->root = y;
  }
  else if (node == node->parent->right) {
    node->parent->right = y;
  }
  else {
    node->parent->left = y;
  }
  y->right = node;
  node->parent = y;
}

// Private FN, create a new node on the heap that hold data
static t_rbNode* ft_rb_newNode(const void* data) {
  t_rbNode* result = calloc(1, sizeof(t_rbNode));
  printf("one node created at %p\n", result);
  if (result == NULL)
    return NULL;
  result->data = data;
  result->color = RED;
  return result;
}

// Private FN, simple cmp FN if none is provided by the user
static int simple_cmp(const void* data1, const void* data2) { return data1 - data2; }

static void simple_print(const void* data) {
  const t_rbNode* node = (t_rbNode*)data;
  printf("0x%lx:%s\n", (uint64_t)node->data, node->color ? "BLACK" : "RED");
}
