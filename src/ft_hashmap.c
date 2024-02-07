//
// Created by loumouli on 1/29/24.
//

#include "libft.h"

static uint32_t ft_ht_expendCapacity(t_hashTable *ht);
static void ft_ht_cleanItems(const t_set *items);

t_hashTable *ft_ht_new(void) {
  t_hashTable *result = ft_calloc(1, sizeof(t_hashTable));
  if (result == NULL)
    return NULL;
  result->items = ft_set_new(sizeof(void *));
  if (result->items == NULL) {
    free(result);
    return NULL;
  }
  ft_set_reserve(result->items, 27);
  result->seed = 1707303718;
  return result;
}

void ft_ht_clean(t_hashTable *ht, uint64_t (*free_fn)(t_htItem *item)) {
  if (free_fn)
    ft_ht_iterItem(ht, free_fn);
  ft_ht_cleanItems(ht->items);
  ft_set_clean(ht->items);
  free(ht);
}

t_htItem *ft_ht_createItem(const void *key, const uint32_t nbytes_key, const void *data) {
  t_htItem *result = calloc(1, sizeof(t_htItem));
  if (result == NULL)
    return NULL;
  result->key = key;
  result->nbytes_key = nbytes_key;
  result->hash = farmhash64(key, nbytes_key);
  result->data = data;
  return result;
}

uint32_t ft_ht_insert(t_hashTable *ht, const void *key, const uint32_t nbytes_key, const void *data) {
  const t_htItem *item = ft_ht_createItem(key, nbytes_key, data);
  if (item == NULL)
    return 1;
  ft_ht_insertItems(ht, item);
  return 0;
}

uint32_t ft_ht_insertItems(t_hashTable *ht, const t_htItem *item) {
  uint64_t idx = item->hash % ht->items->capacity;
  while (ft_ht_hasIdx(ht, idx)) {
    t_htItem *tmp = ft_ht_getIdx(ht, idx);
    if (item->key == tmp->key) {
      free(tmp);
      ft_set_insert(ht->items, item, idx);
      return 0;
    }
    if (ft_ht_expendCapacity(ht)) {
      return 1;
    }
    idx = item->hash % ht->items->capacity;
  }
  ft_set_insert(ht->items, item, idx);
  return 0;
}

bool ft_ht_hasKey(const t_hashTable *ht, const void *key, const uint32_t nbytes_key) {
  const uint64_t idx = farmhash64(key, nbytes_key) % ht->items->capacity;
  return ft_ht_hasIdx(ht, idx);
}

bool ft_ht_hasIdx(const t_hashTable *ht, const uint64_t idx) {
  if (idx > ht->items->len)
    return false;
  t_htItem **item = ft_set_get(ht->items, idx);
  return ft_memcmp(item, (uint64_t[]){0}, ht->items->nbytes_data) ? true : false;
}

t_htItem *ft_ht_getKey(const t_hashTable *ht, const void *key, const uint32_t nbytes_key) {
  const uint64_t idx = farmhash64(key, nbytes_key) % ht->items->capacity;
  return ft_ht_getIdx(ht, idx);
}

t_htItem *ft_ht_getIdx(const t_hashTable *ht, const uint64_t idx) {
  t_htItem **item = ft_set_get(ht->items, idx);
  return ft_memcmp(item, (uint64_t[]){0}, ht->items->nbytes_data) ? *item : NULL;
}

uint32_t ft_ht_deleteKey(const t_hashTable *ht, const void *key, const uint64_t nbytes_key) {
  const uint64_t idx = farmhash64(key, nbytes_key) % ht->items->capacity;
  return ft_ht_deleteIdx(ht, idx);
}

uint32_t ft_ht_deleteIdx(const t_hashTable *ht, const uint64_t idx) {
  t_htItem *item = ft_ht_getIdx(ht, idx);
  if (item == NULL)
    return 1;
  free(item);
  return 0;
}

uint64_t ft_ht_iterItem(const t_hashTable *ht, uint64_t (*iter_fn)(t_htItem *item)) {
  for (uint64_t i = 0; i <= ht->items->len; ++i) {
    t_htItem* item = ft_ht_getIdx(ht, i);
    if (item == NULL)
      continue;
    const uint64_t ret =  iter_fn(item);
    if (ret)
      return ret;
  }
  return 0;
}

void ft_ht_print(const t_hashTable *ht) {
  ft_ht_printFn(ht, NULL, NULL);
}

void ft_ht_printFn(const t_hashTable *ht, void (*print_key)(const void *key), void (*print_data)(const void *data)) {
  for (uint64_t i = 0; i < ht->items->len; ++i) {
    const t_htItem *item = ft_ht_getIdx(ht, i);
    if (item == NULL)
      continue;
    printf("Item:\t%lu\t", i);
    print_key ? print_key(item->key) : printf("key: %#lx\t", *(uint64_t *)item->key);
    printf("hash: %#lx\t", item->hash);
    print_data ? print_data(item->data) : printf("data: %p\n", item->data);
  }
}

static uint32_t ft_ht_expendCapacity(t_hashTable *ht) {
  t_hashTable *ht2 = ft_ht_new();
  if (ht2 == NULL)
    return 1;
  ft_set_reserve(ht2->items, ht->items->capacity * 4);
  for (uint64_t i = 0; i <= ht->items->len; ++i) {
    const t_htItem *item = ft_ht_getIdx(ht, i);
    if (item == NULL)
      continue;
    ft_ht_insertItems(ht2, item);
  }
  ft_set_clean(ht->items);
  ht->items = ht2->items;
  free(ht2);
  return 0;
}

static void ft_ht_cleanItems(const t_set *items) {
  for (uint32_t i = 0; i <= items->len; ++i) {
    t_htItem **item = ft_set_get(items, i);
    if (memcmp(item, (uint64_t[]){0}, items->nbytes_data) == 0)
      continue;
    free(*item);
  }
}



