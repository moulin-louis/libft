//
// Created by loumouli on 2/8/24.
//

#ifndef T_BTREE_H
#define T_BTREE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef int (*t_cmp_fn)(const void* data1, const void* data2);
typedef void (*t_free_fn)(void* data);

// Struct for a binary tree node
typedef struct s_btNode {
  const void* data; // data, can hold data up to 64 bits or a pointer
  struct s_btNode* left; // left node
  struct s_btNode* right; // right node
  struct s_btNode* parent; // parent node
} t_btNode;

// Struct for the binary tree
typedef struct {
  t_cmp_fn cmp_fn; // cmp_fn used to navigate the tree
  t_free_fn free_fn; // free_fn called on data when deleting a node
  t_btNode* root; // root node of the tree
} t_bTree;

// Red/Black Trees FN

// Init a binary tree on the heap
t_bTree* ft_bTree_new(t_cmp_fn cmp_fn, t_free_fn free_fn);

// Free all node and the t_bTree struct
void ft_bTree_destroy(t_bTree* b_tree);

// Free a single node of the binary tree
void ft_bTree_destroyNode(t_btNode* bt_node, t_free_fn free_fn);

// Insert a data into the Binary Tree
uint64_t ft_bTree_insert(t_bTree* b_tree, const void* data);

// Insert a node into the Binary Tree
void ft_bTree_insertNode(t_bTree* b_tree, t_btNode* bt_node);

// Check if the Binary Tree has this data
// Data must be the same size as nbytes_data
bool ft_bTree_has(const t_bTree* b_tree, const void* data);

// Will return a pointer to the node that contain data, NULL otherwise
// Data must be the same size as nbytes_data
const t_btNode* ft_bTree_get(const t_bTree* b_tree, const void* data);

// Will return a pointer to the node that contain the minimun data of the tree
const t_btNode* ft_bTree_getMin(const t_bTree* b_tree);

// Will return a pointer to the node that contain the maximum data of the tree
const t_btNode* ft_bTree_getMax(const t_bTree* b_tree);

// Will return the next inorder node or NULL
const t_btNode* ft_bTree_inorderNext(const t_btNode* n);

// Delete a value in the Binary Tree, will use the cmp_fn to find the correct node
// Data must be the same size as nbytes_data
void ft_bTree_delete(t_bTree* b_tree, const void* data);

// Delete a given node in the Binary Tree
void ft_bTree_deleteNode(t_bTree* b_tree, t_btNode* node);

// Will swap the data of two node
void ft_bTree_swapData(t_btNode* node1, t_btNode* node2);

// Apply a function to all Binary Tree node
uint64_t ft_bTree_iterItem(const t_bTree* b_tree, uint64_t (*iter_fn)(const t_btNode* item));

// Print the Binary Tree sideways
void ft_bTree_print(const t_btNode* root, uint64_t space);

// Apply a print function to all Binary Tree node in order
void ft_bTree_printFn(const t_btNode* root, uint64_t space, void (*print_data)(const void* data));
#endif // T_BTREE_H
