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

t_hashTable* ft_ht_new(void);

void ft_ht_destroy(t_hashTable* ht, uint64_t (*free_fn)(t_htItem* item));

t_htItem* ft_ht_createItem(const void* key, uint64_t nbytes_key, const void* data);

uint64_t ft_ht_insert(t_hashTable* ht, const void* key, uint64_t nbytes_key, const void* data);

uint64_t ft_ht_insertItem(t_hashTable* ht, const t_htItem* item);

bool ft_ht_hasKey(const t_hashTable* ht, const void* key, uint64_t nbytes_key);

bool ft_ht_hasIdx(const t_hashTable* ht, uint64_t idx);

t_htItem* ft_ht_getKey(const t_hashTable* ht, const void* key, uint64_t nbytes_key);

t_htItem* ft_ht_getIdx(const t_hashTable* ht, uint64_t idx);

uint64_t ft_ht_set(const t_hashTable* ht, const void* key, uint64_t nbytes_key, const void* data);

uint64_t ft_ht_deleteKey(const t_hashTable* ht, const void* key, uint64_t nbytes_key);

uint64_t ft_ht_deleteIdx(const t_hashTable* ht, uint64_t idx);

uint64_t ft_ht_iterItem(const t_hashTable* ht, uint64_t (*iter_fn)(t_htItem* item));

void ft_ht_print(const t_hashTable* ht);

void ft_ht_printFn(const t_hashTable* ht, void (*print_key)(const void* key), void (*print_data)(const void* data));

#endif // T_HASHTABLE_H
