//
// Created by loumouli on 2/8/24.
//

#include "t_bTree.h"
#include "libft.h"

static t_btNode* ft_bTree_createNode(const void* data);
static int  simple_cmp(const void* data1, const void* data2);

t_bTree* ft_bTree_new(const uint64_t nbytes_data, const t_cmp_fn cmp_fn, const t_free_fn free_fn) {
  t_bTree* b_tree = ft_calloc(1, sizeof(t_bTree));
  if (b_tree == NULL)
    return NULL;
  b_tree->cmp_fn = cmp_fn ? cmp_fn :  simple_cmp;
  b_tree->free_fn = free_fn;
  b_tree->nbytes_data = nbytes_data;
  return b_tree;
}

void ft_bTree_destroy(t_bTree* b_tree) {
  t_set* nodes = ft_set_new(sizeof(void*));
  if (nodes == NULL)
    return;
  ft_set_p
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

const t_btNode* ft_bTree_inorderNext(const t_btNode* bt_node) {
  const t_btNode* tmp = NULL;
  if (bt_node->right != NULL) {
    tmp = bt_node->right;
    while (tmp->left != NULL)
      tmp = tmp->left;
    return tmp;
  }
  tmp = bt_node->parent;
  while (tmp != NULL && bt_node != tmp->right) {
    bt_node = tmp;
    tmp = tmp->parent;
  }
  return NULL;
}

uint64_t ft_bTree_delete(t_bTree* b_tree, const void* data) {
  t_btNode* node = (t_btNode*)ft_bTree_get(b_tree, data);
  if (node == NULL)
    return 1;
  if (node->left == NULL && node->right == NULL) {
    ft_bTree_destroyNode(b_tree->free_fn, node);
    return 0;
  }
  if (node->left == NULL && node->right != NULL) {
    if (node->parent == NULL)
      b_tree->root = node->right;
    else
      node->parent = node->right;
    ft_bTree_destroyNode(b_tree->free_fn, node);
    return 0;
  }
  if (node->left != NULL && node->right == NULL) {
    if (node->parent == NULL)
      b_tree->root = node->left;
    else
      node->parent = node->left;
    ft_bTree_destroyNode(b_tree->free_fn, node);
    return 0;
  }
  //Find the inorder successor of the node
  //swap data
  //delete inorder successor node
  return 0;
}

void  ft_bTree_swapData(t_btNode* node1, t_btNode* node2) {
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

static int  simple_cmp(const void* data1, const void* data2) {
  return data1 - data2;
}