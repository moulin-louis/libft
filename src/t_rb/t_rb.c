//
// Created by loumouli on 2/7/24.
//

#include "libft.h"
#include "t_rb.h"

static t_rbNode*   ft_rb_treeInsert(t_cmp_fn cmp_fn, t_rbNode* root, const void* data);
static t_rbNode*  ft_rb_newNode(e_color color, const void* data);

int simple_cmp(const void* data1, const void* data2) {
  return data1 - data2;
}

t_rb* ft_rb_new(const t_cmp_fn cmp_fn, const uint64_t nbytes_data) {
  t_rb* result = calloc(1, sizeof(t_rbNode));
  if (result == NULL)
    return NULL;
  cmp_fn ? (result->cmp_fn = cmp_fn) : (result->cmp_fn = simple_cmp);
  result->nbytes_data = nbytes_data;
  return result;
}

void  ft_rb_clean(t_rb* rb) {
  //ITERATE OVER ALL NODE AND FREE THEM
  free(rb);
}

uint64_t ft_rb_insert(t_rb* rb, const void* data) {
  //Insert the data like we are in a classic binary tree, can damage the red/black integrity
  rb->root = ft_rb_treeInsert(rb->cmp_fn, rb->root, data);
  //Restore the red/black tree property
  return 0;
}

void  ft_rb_print(const t_rbNode* root, uint64_t space) {
  if (root == NULL)
    return;
  space += 10;
  ft_rb_print(root->right, space);
  printf("\n");
  for (uint64_t i = 10; i < space; i++)
    printf(" ");
  printf("%#lx\n", (uint64_t)root->data);
  ft_rb_print(root->left, spacez);
}

static t_rbNode* ft_rb_treeInsert(const t_cmp_fn cmp_fn, t_rbNode* root, const void* data) {
  if (root == NULL)
    return ft_rb_newNode(RED, data);
  if (cmp_fn(root->data, data) < 0)
    root->right = ft_rb_treeInsert(cmp_fn, root->right, data);
  if (cmp_fn(root->data, data) > 0)
    root->left = ft_rb_treeInsert(cmp_fn, root->left, data);
  return root;
}

static t_rbNode*  ft_rb_newNode(const e_color color, const void* data) {
  t_rbNode* result = calloc(1, sizeof(t_rbNode));
  if (result == NULL)
    return NULL;
  result->color = color;
  result->data = data;
  return result;
}
