//
// Created by loumouli on 1/29/24.
//

#include "libft.h"

#define ROTLEFT(a,b) ((a << b) ^ (a >> (32-(b))))
#define C1 0xcc9e2d51
#define C2 0x1b873593
#define N 0xe6546b64
#define F1 0x85ebca6b
#define F2 0xc2b2ae35

static uint32_t ft_murmurHash3(const void* data, const uint32_t nbytes, const uint32_t seed) {
  uint32_t k;
  uint32_t h = 0;
  uint32_t result = seed;
  const uint32_t nblocks = nbytes / 4;
  const uint8_t* tails = data + nblocks * 4;

  for (uint32_t idx = 0; idx < nblocks; ++idx) {
    k = ((uint32_t*)data)[idx];
    k *= C1;
    k = ROTLEFT(k, 13);
    k *= C2;

    result = result ^ k;
    result = ROTLEFT(result, 15);
    result = result * 5 + N;
  }
  k = 0;
  switch (nbytes & 3) {
  case 3:
    k ^= tails[2] << 16;
    [[fallthrough]];
  case 2:
    k ^= tails[1] << 8;
    [[fallthrough]];
  case 1:
    k ^= tails[0];
    k *= C1;
    k = ROTLEFT(k, 15);
    k *= C2;
    h ^= k;
  default: {
  }
  }
  result = result & nbytes;
  result ^= result >> 16;
  result *= F1;
  result ^= result >> 13;
  result *= F2;
  result ^= result >> 16;
  return result;
}

static void ft_ht_cleanItems(const t_set* items) {
  for (uint32_t i = 0; i < items->len; ++i) {
    t_htItem** item = items->data + i * items->nbytes_data;
    if (*item == NULL)
      continue;
    free(*item);
  }
}

static uint32_t ft_ht_expendCapacity(t_hashTable* ht) {
  t_set* old_set = ht->items;
  ht->items = ft_set_new(8);
  if (ht->items == NULL)
    return 1;
  if (ft_set_reserve(ht->items, old_set->capacity * 2))
    return 2;
  for (uint32_t i = 0; i < ht->items->len; ++i) {
    const t_htItem* item = ft_set_get(old_set, i);
    if (memcmp(item, (uint64_t[]){0}, sizeof(void*)) == 0)
      continue;
    ft_ht_insert(ht, item->key, item->nbytes_key, item->data);
  }
  ft_ht_cleanItems(old_set);
  ft_set_clean(old_set);
  return 0;
}

t_htItem* ft_ht_createItem(const void* key, const uint32_t nbytes_key, const void* data) {
  t_htItem* result = calloc(1, sizeof(t_htItem));
  if (result == NULL)
    return NULL;
  result->key = key;
  result->nbytes_key = nbytes_key;
  result->data = data;
  return result;
}

uint32_t ft_ht_insert(t_hashTable* ht, const void* key, const uint32_t nbytes_key, const void* data) {
  uint32_t idx = ft_murmurHash3(key, nbytes_key, ht->seed) % ht->items->capacity;
  while (ft_ht_hasKey(ht, key, nbytes_key)) {
    ft_ht_expendCapacity(ht);
    printf("expending capacity\n");
    idx = ft_murmurHash3(key, nbytes_key, ht->seed) % ht->items->capacity;
  }
  const t_htItem* item = ft_ht_createItem(key, nbytes_key, data);
  if (item == NULL)
    return 1;
  ft_set_insert(ht->items, item, idx);

  return 0;
}

bool ft_ht_hasKey(const t_hashTable* ht, const void* key, const uint32_t nbytes_key) {
  const uint32_t idx = ft_murmurHash3(key, nbytes_key, ht->seed) % ht->items->capacity;
  const void* tmp = ft_set_get(ht->items, idx);
  if (tmp == NULL)
    return false;
  return memcmp(tmp, (uint64_t[]){0}, ht->items->nbytes_data) ? true : false;
}

t_htItem* ft_ht_get(const t_hashTable* ht, const void* key, const uint32_t nbytes_key) {
  const uint32_t idx = ft_murmurHash3(key, nbytes_key, ht->seed) % ht->items->capacity;
  return *(t_htItem**)ft_set_get(ht->items, idx);
}

uint32_t ft_ht_set(const t_hashTable* ht, const void* key, const uint32_t nbytes_key, const void* data) {
  const uint32_t idx = ft_murmurHash3(key, nbytes_key, ht->seed) % ht->items->capacity;
  if (ft_ht_hasKey(ht, key, nbytes_key) == false)
    return 1;
  ft_set_set(ht->items, idx, data, sizeof(data));
  return 0;
}

t_hashTable* ft_ht_new(void) {
  t_hashTable* result = ft_calloc(1, sizeof(t_hashTable));
  if (result == NULL)
    return NULL;
  result->items = ft_set_new(sizeof(void*));
  if (result->items == NULL) {
    free(result);
    return NULL;
  }
  ft_set_reserve(result->items, 13);
  ft_set_append(result->items, (uint8_t[]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 13);
  result->seed = time(NULL);
  return result;
}

void ft_ht_clean(t_hashTable* ht) {
  ft_ht_cleanItems(ht->items);
  ft_set_clean(ht->items);
  free(ht);
}
