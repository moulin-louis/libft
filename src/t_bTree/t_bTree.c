//
// Created by loumouli on 2/8/24.
//

#include "t_bTree.h"
#include "libft.h"

static t_btNode* ft_bTree_createNode(const void* data);
static int simple_cmp(const void* data1, const void* data2);

t_bTree* ft_bTree_new(const uint64_t nbytes_data, const t_cmp_fn cmp_fn, const t_free_fn free_fn) {
  t_bTree* b_tree = ft_calloc(1, sizeof(t_bTree));
  if (b_tree == NULL)
    return NULL;
  b_tree->cmp_fn = cmp_fn ? cmp_fn : simple_cmp;
  b_tree->free_fn = free_fn;
  b_tree->nbytes_data = nbytes_data;
  return b_tree;
}

void ft_bTree_destroy(t_bTree* b_tree) {
  if (b_tree->root == NULL) {
    free(b_tree);
    return;
  }
  t_set* nodes = ft_set_new(sizeof(void*));
  if (nodes == NULL)
    return;
  const t_btNode* node = ft_bTree_getMin(b_tree);
  for (; node; node = ft_bTree_inorderNext(node))
    ft_set_push(nodes, &node, sizeof(void*));
  for (uint64_t i = 0; i < nodes->len; ++i)
    ft_bTree_destroyNode(b_tree->free_fn, *(t_btNode**)ft_set_get(nodes, i));
  ft_set_destroy(nodes);
  free(b_tree);
}

void ft_bTree_destroyNode(const t_free_fn free_fn, t_btNode* bt_node) {
  if (free_fn)
    free_fn((void*)bt_node->data);
  free(bt_node);
}

uint64_t ft_bTree_insert(t_bTree* b_tree, const void* data) {
  t_btNode* bt_node = ft_bTree_createNode(data);
  if (bt_node == NULL)
    return 1;
  if (b_tree->root == NULL) {
    b_tree->root = bt_node;
    return 0;
  }
  t_btNode* y = NULL;
  t_btNode* x = b_tree->root;
  while (x != NULL) {
    y = x;
    if (b_tree->cmp_fn(bt_node->data, x->data) < 0)
      x = x->left;
    else
      x = x->right;
  }
  bt_node->parent = y;
  if (b_tree->cmp_fn(bt_node->data, y->data) > 0)
    y->right = bt_node;
  else
    y->left = bt_node;
  return 0;
}

bool ft_bTree_has(const t_bTree* b_tree, const void* data) { return ft_bTree_get(b_tree, data) ? true : false; }

const t_btNode* ft_bTree_get(const t_bTree* b_tree, const void* data) {
  const t_btNode* x = b_tree->root;
  while (x != NULL) {
    if (b_tree->cmp_fn(x->data, data) == 0)
      return x;
    if (b_tree->cmp_fn(x->data, data) < 0)
      x = x->right;
    else
      x = x->left;
  }
  return NULL;
}

const t_btNode* ft_bTree_getMin(const t_bTree* b_tree) {
  if (b_tree->root == NULL)
    return NULL;
  const t_btNode* x = b_tree->root;
  for (; x->left; x = x->left) {
  }
  return x;
}

const t_btNode* ft_bTree_getMax(const t_bTree* b_tree) {
  if (b_tree->root == NULL)
    return NULL;
  const t_btNode* x = b_tree->root;
  for (; x->left; x = x->right) {
  }
  return x;
}

const t_btNode* ft_bTree_inorderNext(const t_btNode* n) {
  const t_btNode* p = NULL;
  if (n->right != NULL) {
    p = n->right;
    while (p->left != NULL)
      p = p->left;
    return p;
  }
  p = n->parent;
  while (p != NULL && n == p->right) {
    n = p;
    p = p->parent;
  }
  return p;
}

void ft_bTree_delete(t_bTree* b_tree, const void* data) {
  t_btNode* node = (t_btNode*)ft_bTree_get(b_tree, data);
  if (node == NULL)
    return;
  ft_bTree_deleteNode(b_tree, node);
}

void ft_bTree_deleteNode(t_bTree* b_tree, t_btNode* node) {
  if (node == NULL)
    return;
  if (node->left == NULL && node->right == NULL) {
    if (node->parent)
      node->parent->right == node ? (node->parent->right = NULL) : (node->parent->left = NULL);
    else
      b_tree->root = NULL;
    ft_bTree_destroyNode(b_tree->free_fn, node);
    return;
  }
  if (node->left == NULL) {
    if (node->parent == NULL)
      b_tree->root = node->right;
    else
      node->parent = node->right;
    ft_bTree_destroyNode(b_tree->free_fn, node);
    return;
  }
  if (node->right == NULL) {
    if (node->parent == NULL) {
      b_tree->root = node->left;
      b_tree->root->parent = NULL;
    }
    else
      node->parent = node->left;
    ft_bTree_destroyNode(b_tree->free_fn, node);
    return;
  }
  // Find the inorder successor of the node
  t_btNode* next_node = (t_btNode*)ft_bTree_inorderNext(node); // Cant be NULL cause we check all other conditions
  // swap data
  ft_bTree_swapData(node, next_node);
  // delete inorder successor node
  ft_bTree_deleteNode(b_tree, next_node);
  // ft_bTree_destroyNode(b_tree->free_fn, next_node);
}

void ft_bTree_print(const t_btNode* root, uint64_t space) {
  if (root == NULL)
    return;
  space += 10;
  ft_bTree_print(root->right, space);
  printf("\n");
  for (uint64_t i = 10; i < space; i++)
    printf(" ");
  printf("%lu\n", (uint64_t)root->data);
  ft_bTree_print(root->left, space);
}

void ft_bTree_swapData(t_btNode* node1, t_btNode* node2) {
  const void* tmp = node1->data;
  node1->data = node2->data;
  node2->data = tmp;
}

static t_btNode* ft_bTree_createNode(const void* data) {
  t_btNode* bt_node = ft_calloc(1, sizeof(t_btNode));
  if (bt_node == NULL)
    return NULL;
  bt_node->data = data;
  return bt_node;
}

static int simple_cmp(const void* data1, const void* data2) { return data1 - data2; }
