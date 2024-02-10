//
// Created by loumouli on 2/7/24.
//

#ifndef T_HASHTABLE_H
#define T_HASHTABLE_H


#include <stdbool.h>
#include <stdint.h>

#include "t_set.h"

// HashTable Item structure
typedef struct {
  const void* key; // Pointer to the key, needed to access the value
  uint64_t nbytes_key; // Number of bytes of the key
  uint64_t hash; // Hash of the ky, hashed by the farmhash hashing function
  const void* data; // Actual data, can hold up to 64 bits or a pointer
} t_htItem;

// HashTable (HashMap/Dictionary) definition
// t_hashTable is a wrapper arround t_set
// the key is hashed to access direclt the set via an index
typedef t_set t_hashTable;

// HASHTABLES FN

// Init a new t_hashTable on the heap
t_hashTable* ft_ht_new(void);

//Destroy the t_hastTable and call `free_fn` on every data
void ft_ht_destroy(t_hashTable* ht, uint64_t (*free_fn)(t_htItem* item));

// Create a new item, the key hash will be stored on this item
t_htItem* ft_ht_createItem(const void* key, uint64_t nbytes_key, const void* data);

//Insert a key-val in the hashtable
uint64_t ft_ht_insert(t_hashTable* ht, const void* key, uint64_t nbytes_key, const void* data);

//Inert a item in the hashtable
uint64_t ft_ht_insertItem(t_hashTable* ht, const t_htItem* item);

// Check if the hashtable has a given key
bool ft_ht_hasKey(const t_hashTable* ht, const void* key, uint64_t nbytes_key);

// Check if the given idx has an item
bool ft_ht_hasIdx(const t_hashTable* ht, uint64_t idx);

//Get the item in the table from a key, NULL if not found
t_htItem* ft_ht_getKey(const t_hashTable* ht, const void* key, uint64_t nbytes_key);

//Get the item in the table from an index, NULL if not found
t_htItem* ft_ht_getIdx(const t_hashTable* ht, uint64_t idx);

// Set a given key to a new data
uint64_t ft_ht_set(const t_hashTable* ht, const void* key, uint64_t nbytes_key, const void* data);

// Delete an item based on a key
uint64_t ft_ht_deleteKey(const t_hashTable* ht, const void* key, uint64_t nbytes_key);

// Delete an item based on a index
uint64_t ft_ht_deleteIdx(const t_hashTable* ht, uint64_t idx);

//Apply a function to every item in the table
uint64_t ft_ht_iterItem(const t_hashTable* ht, uint64_t (*iter_fn)(t_htItem* item));

// Print every item in the table
void ft_ht_print(const t_hashTable* ht);

//Print every item in the table with a user print function
void ft_ht_printFn(const t_hashTable* ht, void (*print_key)(const void* key), void (*print_data)(const void* data));

#endif // T_HASHTABLE_H
