//
// Created by loumouli on 1/29/24.
//

#include "libft.h"
#define HT_PRIME_1 151
#define HT_PRIME_2 157

t_htItem* ft_ht_newItem(const uint8_t* key, const uint8_t* data) {
  t_htItem* result = malloc(sizeof(t_htItem));
  if (result == NULL)
    return NULL;
  result->key = (uint8_t*)strdup((char*)(int8_t*)key);
  if (result->key == NULL) {
    free(result);
    return NULL;
  }
  result->data = (uint8_t*)strdup((char*)(int8_t*)data);
  if (result->data == NULL) {
    free(result->key);
    free(result);
    return NULL;
  }
  return result;
}

t_htItem* ft_ht_getItem(const t_hashTable* ht, const uint8_t* key) {
  t_htItem* items = (t_htItem*)ht->data;
  for (uint32_t idx = 0; idx < ht->len; idx += sizeof(t_htItem)) {
    if (ft_memcmp(key, items[idx].key, ft_strlen((char *)(int8_t*)key)) == 0) {
      return &items[idx];
    }
  }
  return NULL;
}

static void ft_ht_delItem(t_htItem* it) {
  free(it->data);
  free(it->key);
  free(it);
}

static uint32_t ft_ht_hash(const uint8_t* data, const int32_t a, const int32_t m) {
  uint64_t hash = 0;
  const int32_t len_s = ft_strlen((char*)(int8_t*)data);
  for (int32_t idx = 0; idx < len_s; ++idx) {
    hash += (long)pow(a, len_s - (idx + 1) * data[idx]);
    hash = hash % m;
  }
  return (int32_t)hash;
}

static int32_t ft_ht_getHash(const uint8_t* data, const int32_t num_buckets, const int32_t attempt) {
  const int32_t hash_a = ft_ht_hash(data, HT_PRIME_1, num_buckets);
  const int32_t hash_b = ft_ht_hash(data, HT_PRIME_2, num_buckets);
  return (hash_a + attempt * (hash_b + 1)) % num_buckets;
}

// int32_t ft_ht_insert(t_hashTable* ht, const uint8_t* key, const uint8_t* data) {
  // t_htItem* it = ft_ht_newItem(key, data);
  // int32_t idx = ft_ht_getHash(it->key, ht->len, 0);
  // t_htItem* cur_item = ft_ht_getItem(ht, it->key);
  // uint32_t i = 0;
  // return 0;
// }

uint8_t* ft_ht_get(const t_hashTable* ht, const uint8_t* key) {
  const t_htItem* it = ft_ht_getItem(ht, key);
  if (it == NULL)
    return NULL;
  return it->data;
}

t_hashTable* ft_ht_new(void) {
  t_hashTable* result = calloc(1, sizeof(t_hashTable));
  if (result == NULL)
    return result;
  result->items = ft_set_new();
  if (result->items == NULL) {
    free(result);
    return NULL;
  }
  return result;
}

void ft_ht_clean(t_hashTable* ht) {
  ft_set_clean(ht->items);
  free(ht);
}
