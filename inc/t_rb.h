//
// Created by loumouli on 2/7/24.
//

#ifndef T_RB_H
#define T_RB_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "t_bTree.h"

// Enum for red/black trees
typedef enum {
  RED = 0, // Red variant
  BLACK = 1, // Black variant
} e_color;

typedef int (*t_cmp_fn)(const void* data1, const void* data2);
typedef void (*t_free_fn)(void* data);

// Struct for a red black trees node
typedef struct s_rb {
  const void* data; // data, can hold data up to 64 bits or a pointer
  struct s_rb* left; // left node
  struct s_rb* right; // right node
  struct s_rb* parent; // parent node
  e_color color; // Color of the current node (red or black)
} t_rbNode;

// Struct for the red black tree
typedef struct {
  t_cmp_fn cmp_fn; // cmp_fn used to navigate the tree
  t_free_fn free_fn; // free_fn called on data when deleting a node
  t_rbNode* root; // root node of the tree
} t_rb;

// Red/Black Trees FN

// Init a red black tree on the heap
t_rb* ft_rb_new(t_cmp_fn cmp_fn, t_free_fn free_fn);

// Free all node and the t_rb struct
void ft_rb_destroy(t_rb* rb);

// Free a single node of the binary tree
void ft_rb_destroyNode(t_rbNode* rb_node, t_free_fn free_fn);

// Insert a data into the RB tree
uint64_t ft_rb_insert(t_rb* rb, const void* data);

// Check if the RB tree has this data
// Data must be the same size of nbytes_data
bool ft_rb_has(const t_rb* rb, const void* data);

// Will return a pointer to the node that contain data, NULL otherwise
// Data must be the same size of nbytes_data
const t_rbNode* ft_rb_get(const t_rb* rb, const void* data);

// Will return a pointer to the node that contain the minimun data of the tree
const t_rbNode* ft_rb_getMin(const t_rb* rb);

// Will return a pointer to the node that contain the maximum data of the tree
const t_rbNode* ft_rb_getMax(const t_rb* rb);

// Will return the next inorder node or NULL
const t_rbNode* ft_rb_inorderNext(const t_rbNode* node);

// Delete a value in the RB tree, will use the cmp_fn to find the correct node
// Data must be the same size of nbytes_data
uint64_t ft_rb_delete(t_rb* rb, const void* data);

// Delete a given node in the Binary Tree
void ft_rb_deleteNode(t_rb* rb, t_rbNode* node);

// Apply a function to all RB tree node
uint64_t ft_rb_iterItem(const t_rb* rb, uint64_t (*iter_fn)(const t_rbNode* item));

// Print the RB tree sideways
void ft_rb_print(const t_rbNode* root, uint64_t space);

// Apply a print function to all RB tree node in order
void ft_rb_printFn(const t_rbNode* root, uint64_t space, void (*print_data)(const void* data));
#endif // T_RB_H
