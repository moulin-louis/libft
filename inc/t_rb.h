//
// Created by loumouli on 2/7/24.
//

#ifndef T_RB_H
#define T_RB_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//Enum for red/black trees
typedef enum {
  RED = 0,    //Red variant
  BLACK = 1,  //Black variant
} e_color;

typedef int (*t_cmp_fn)(const void *data1, const void *data2);

//Struct for a red black trees node
typedef struct s_rb {
  e_color color; //Color of the current node (red or black)
  const void *data; //data, can hold data up to 64 bits or a pointer
  struct s_rb *left; //left node
  struct s_rb *right; //right node
  struct s_rb *parent; //parent node
} t_rbNode;

//Struct for the red black tree
typedef struct {
  uint64_t nbytes_data; //number of bytes of the data
  t_cmp_fn cmp_fn; //cmp_fn used to navigate the tree
  t_rbNode *root; //root node of the tree
} t_rb;

//Red/Black Trees FN

//Init a red black tree on the heap
t_rb *ft_rb_new(t_cmp_fn cmp_fn, uint64_t nbytes_data);

//Free all node and the t_rb struct
void ft_rb_destroy(t_rb *rb);

//Insert a data into the RB tree
uint64_t ft_rb_insert(t_rb *rb, const void *data);

//Check if the RB tree has this data
//Data must be the same size of nbytes_data
bool ft_rb_has(const t_rb *rb, const void *data);

//Will return a pointer to the node that contain data, NULL otherwise
//Data must be the same size of nbytes_data
const t_rbNode* ft_rb_get(const t_rb* rb, const void* data);

//Delete a value in the RB tree, will use the cmp_fn to find the correct node
//Data must be the same size of nbytes_data
uint64_t ft_rb_delete(t_rb *rb, const void *data);

//Apply a function to all RB tree node
uint64_t ft_rb_iterItem(const t_rb *rb, uint64_t (*iter_fn)(const t_rbNode *item));

//Print the RB tree sideways
void ft_rb_print(const t_rbNode *root, uint64_t space);

//Apply a print function to all RB tree node in order
void ft_rb_printFn(const t_rb *rb, void (*print_data)(const void *data));
#endif //T_RB_H
