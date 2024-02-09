//
// Created by loumouli on 1/29/24.
//

#include "farmhash.h"
#include "libft.h"

static uint64_t ft_ht_expendCapacity(t_hashTable** ht);
static void ft_ht_cleanItems(const t_set* items);

t_hashTable* ft_ht_new(void) {
  t_hashTable* result = ft_set_new(sizeof(void*));
  ft_set_reserve(result, 27);
  return result;
}

void ft_ht_destroy(t_hashTable* ht, uint64_t (*free_fn)(t_htItem* item)) {
  if (free_fn)
    ft_ht_iterItem(ht, free_fn);
  ft_ht_cleanItems(ht);
  ft_set_destroy(ht);
}

t_htItem* ft_ht_createItem(const void* key, const uint64_t nbytes_key, const void* data) {
  t_htItem* result = calloc(1, sizeof(t_htItem));
  if (result == NULL)
    return NULL;
  result->key = key;
  result->nbytes_key = nbytes_key;
  result->hash = farmhash64(key, nbytes_key);
  result->data = data;
  return result;
}

uint64_t ft_ht_insert(t_hashTable* ht, const void* key, const uint64_t nbytes_key, const void* data) {
  const t_htItem* item = ft_ht_createItem(key, nbytes_key, data);
  if (item == NULL)
    return 1;
  ft_ht_insertItem(ht, item);
  return 0;
}

uint64_t ft_ht_insertItem(t_hashTable* ht, const t_htItem* item) {
  uint64_t idx = item->hash % ht->capacity;
  while (ft_ht_hasIdx(ht, idx)) {
    t_htItem* tmp = ft_ht_getIdx(ht, idx);
    if (item->key == tmp->key) {
      free(tmp);
      ft_set_insert(ht, item, idx);
      return 0;
    }
    if (ft_ht_expendCapacity(&ht))
      return 1;
    idx = item->hash % ht->capacity;
  }
  ft_set_insert(ht, item, idx);
  return 0;
}

bool ft_ht_hasKey(const t_hashTable* ht, const void* key, const uint64_t nbytes_key) {
  const uint64_t idx = farmhash64(key, nbytes_key) % ht->capacity;
  return ft_ht_hasIdx(ht, idx);
}

bool ft_ht_hasIdx(const t_hashTable* ht, const uint64_t idx) {
  if (idx > ht->len)
    return false;
  t_htItem** item = ft_set_get(ht, idx);
  return ft_memcmp(item, (uint64_t[]){0}, ht->nbytes_data) ? true : false;
}

t_htItem* ft_ht_getKey(const t_hashTable* ht, const void* key, const uint64_t nbytes_key) {
  const uint64_t idx = farmhash64(key, nbytes_key) % ht->capacity;
  return ft_ht_getIdx(ht, idx);
}

t_htItem* ft_ht_getIdx(const t_hashTable* ht, const uint64_t idx) {
  t_htItem** item = ft_set_get(ht, idx);
  return ft_memcmp(item, (uint64_t[]){0}, ht->nbytes_data) ? *item : NULL;
}

uint64_t ft_ht_deleteKey(const t_hashTable* ht, const void* key, const uint64_t nbytes_key) {
  const uint64_t idx = farmhash64(key, nbytes_key) % ht->capacity;
  return ft_ht_deleteIdx(ht, idx);
}

uint64_t ft_ht_deleteIdx(const t_hashTable* ht, const uint64_t idx) {
  t_htItem* item = ft_ht_getIdx(ht, idx);
  if (item == NULL)
    return 1;
  free(item);
  return 0;
}

uint64_t ft_ht_iterItem(const t_hashTable* ht, uint64_t (*iter_fn)(t_htItem* item)) {
  for (uint64_t i = 0; i <= ht->len; ++i) {
    t_htItem* item = ft_ht_getIdx(ht, i);
    if (item == NULL)
      continue;
    const uint64_t ret = iter_fn(item);
    if (ret)
      return ret;
  }
  return 0;
}

void ft_ht_print(const t_hashTable* ht) { ft_ht_printFn(ht, NULL, NULL); }

void ft_ht_printFn(const t_hashTable* ht, void (*print_key)(const void* key), void (*print_data)(const void* data)) {
  for (uint64_t i = 0; i < ht->len; ++i) {
    const t_htItem* item = ft_ht_getIdx(ht, i);
    if (item == NULL)
      continue;
    printf("Item:\t%lu\t", i);
    print_key ? print_key(item->key) : printf("key: %#lx\t", *(uint64_t*)item->key);
    printf("hash: %#lx\t", item->hash);
    print_data ? print_data(item->data) : printf("data: %p\n", item->data);
  }
}

static uint64_t ft_ht_expendCapacity(t_hashTable** ht) {
  t_hashTable* ht2 = ft_ht_new();
  if (ht2 == NULL)
    return 1;
  ft_set_reserve(ht2, (*ht)->capacity * 4);
  for (uint64_t i = 0; i <= (*ht)->len; ++i) {
    const t_htItem* item = ft_ht_getIdx(*ht, i);
    if (item == NULL)
      continue;
    ft_ht_insertItem(ht2, item);
  }
  free((*ht)->data);
  (*ht)->data = ht2->data;
  (*ht)->len = ht2->len;
  (*ht)->capacity = ht2->capacity;
  free(ht2);
  return 0;
}

static void ft_ht_cleanItems(const t_set* items) {
  for (uint64_t i = 0; i <= items->len; ++i) {
    t_htItem* item = ft_ht_getIdx(items, i);
    if (item == NULL)
      continue;
    free(item);
  }
}
