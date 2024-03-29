//
// Created by loumouli on 1/29/24.
//

#include "libft.h"

inline t_set* ft_set_new(const uint64_t nbytes) {
  t_set* result = ft_calloc(1, sizeof(t_set));
  if (result == NULL)
    return NULL;
  *(uint64_t*)&result->nbytes_data = nbytes;
  if (ft_set_reserve(result, 16) != 0) {
    ft_set_destroy(result, NULL);
    return NULL;
  }
  return result;
}

inline t_set* ft_set_clone(const t_set* set) {
  t_set* result = ft_set_new(set->nbytes_data);
  if (result == NULL)
    return NULL;
  if (ft_set_reserve(result, set->capacity)) {
    ft_set_destroy(result, NULL);
    return NULL;
  }
  ft_set_push(result, set->data, set->len * set->nbytes_data);
  return result;
}

void ft_set_clear(t_set* set, uint64_t (*destroy_fn)(void *data)) {
  ft_set_iter(set, destroy_fn);
  set->len = 0;
  }

void ft_set_destroy(t_set* set, uint64_t (*destroy_fn)(void *data)) {
  ft_set_iter(set, destroy_fn);
  if (set->data)
    free(set->data);
  free(set);
}

inline uint64_t ft_set_reserve(t_set* set, const uint64_t capacity) {
  if (capacity <= set->capacity)
    return 0;
  uint8_t* new_ptr = realloc(set->data, capacity * set->nbytes_data);
  if (new_ptr == NULL)
    return 1;
  set->data = new_ptr;
  set->capacity = capacity;
  ft_memset(set->data + set->len * set->nbytes_data, 0, (set->capacity - set->len) * set->nbytes_data);
  return 0;
}

inline bool ft_set_has(const t_set* set, const void* data) {
  for (uint64_t i = 0; i < set->len; ++i) {
    const void* item = ft_set_get(set, i);
    if (ft_memcmp(item, data, set->nbytes_data) == 0)
      return true;
  }
  return false;
}

inline void* ft_set_get(const t_set* set, const uint64_t idx) {
  if (idx > set->len)
    return NULL;
  return set->data + idx * set->nbytes_data;
}

inline uint64_t ft_set_insert(t_set* set, const void* data, const uint64_t idx) {
  if (idx < set->len) {
    ft_memcpy(set->data + idx * set->nbytes_data, &data, set->nbytes_data);
    return 0;
  }
  if (set->capacity < set->len + (idx - set->len)) {
    if (ft_set_reserve(set, (set->capacity + (idx - set->len)) * 2))
      return 1;
  }
  set->len = idx;
  ft_memcpy(set->data + idx * set->nbytes_data, &data, set->nbytes_data);
  return 0;
}

inline uint64_t ft_set_push(t_set* set, const void* data, uint64_t len) {
  if (set->capacity < set->len + len / set->nbytes_data) {
    if (ft_set_reserve(set, (set->capacity + len / set->nbytes_data) * 2))
      return 1;
  }
  ft_memcpy(set->data + set->len * set->nbytes_data, data, len);
  set->len += (len / set->nbytes_data);
  return 0;
}

uint64_t ft_set_iter(const t_set* set, uint64_t (*iter_fn)(void*)) {
  if (iter_fn == NULL)
    return 0;
  for (uint64_t idx = 0; idx < set->len; ++idx) {
    const uint64_t retval = iter_fn(ft_set_get(set, idx));
    if (retval)
      return retval;
  }
  return 0;
}
