//
// Created by loumouli on 2/7/24.
//

#ifndef T_RB_H
#define T_RB_H

#include <stdlib.h>
#include <stdint.h>

//Enum for red/black trees
typedef enum {
  RED,      //RED variant
  BLACK,    //Black variant
} e_color;

typedef int(*t_cmp_fn)(const void*  data1, const void* data2);

//Struct for a red black trees node
typedef struct s_rb {
  e_color       color;        //Color of the current node (red or black)
  const void*   data;         //data, can hold data up to 64 bits or a pointer
  struct s_rb*  left;         //left node
  struct s_rb*  right;        //right node
  struct s_rb*  parent;       //parent node
} t_rbNode;

typedef struct {
  uint64_t  nbr_nodes;    //number of nodes in the tree
  uint64_t  nbytes_data;  //number of bytes of the data
  t_cmp_fn  cmp_fn;       //cmp_fn used to navigate the tree
  t_rbNode* root;         //root node of the tree
} t_rb;

//Red/Black Trees FN

t_rb* ft_rb_new(t_cmp_fn cmp_fn, uint64_t nbytes_data);

void ft_rb_clean(t_rb* rb);

uint64_t  ft_rb_insert(t_rb* rb, const void* data);

bool ft_rb_has(const t_rb* ht, const void* data, uint64_t nbytes_data);

t_htItem* ft_rb_get(const t_rb* ht, const void* data, uint64_t nbytes_data);

uint64_t ft_rb_delete(t_rb* ht, const void* data, uint64_t nbytes_data);

uint64_t ft_rb_iterItem(const t_rb* ht, uint64_t (*iter_fn)(t_htItem* item));

void ft_rb_print(const t_rbNode* ht, uint64_t space);

void ft_rb_printFn(const t_rb* ht, void (*print_data)(const void* data));
#endif //T_RB_H
