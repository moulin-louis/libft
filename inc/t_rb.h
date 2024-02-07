//
// Created by loumouli on 2/7/24.
//

#ifndef T_RB_H
#define T_RB_H

#include <stdlib.h>
#include <stdint.h>

//RB Item structure
typedef struct {
  const void* key; //Pointer to the key, needed to access the value
  uint64_t nbytes_key; //Number of bytes of the key
  const void* data; //Actual data, can hold up to 64 bits or a pointer
} t_rbItem;

//Enum for red/black trees
typedef enum {
  RED,      //RED variant
  BLACK,    //Black variant
} e_color;

//Struct for a red black trees
typedef struct s_rb {
  e_color       color;        //Color of the current node (red or black)
  void*         data;         //data, can hold data up to 64 bits or a pointer
  uint64_t      nbytes_data;  //number of bytes of the data
  struct s_rb*  left;         //left node
  struct s_rb*  right;        //right node
  struct s_rb*  parent;       //parent node
} t_rb;

//Red/Black Trees FN

t_rb* ft_rb_new(uint64_t nbytes_data);

void ft_rb_clean(t_rb* rb);

t_rbItem* ft_rb_createItem(const void* key, uint64_t nbytes_key, const void* data);

uint64_t  ft_rb_insert(t_rb* rb, const void* key, uint64_t nbytes_key, const void* data);

uint64_t ft_rb_insertItems(t_hashTable* ht, const t_htItem* item);

bool ft_rb_hasKey(const t_hashTable* ht, const void* key, uint64_t nbytes_key);

t_htItem* ft_rb_getKey(const t_hashTable* ht, const void* key, uint64_t nbytes_key);

uint64_t ft_rb_set(const t_hashTable* ht, const void* key, uint64_t nbytes_key, const void* data);

uint64_t ft_rb_deleteKey(const t_hashTable* ht, const void* key, uint64_t nbytes_key);

uint64_t ft_rb_iterItem(const t_hashTable* ht, uint64_t (*iter_fn)(t_htItem* item));

void ft_rb_print(const t_hashTable* ht);

void ft_rb_printFn(const t_hashTable* ht, void (*print_key)(const void* key), void (*print_data)(const void* data));
#endif //T_RB_H
