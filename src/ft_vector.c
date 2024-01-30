//
// Created by loumouli on 1/29/24.
//

#include "libft.h"

t_set* ft_set_new(const uint32_t nbytes) {
  t_set* result = ft_calloc(1, sizeof(t_set));
  if (result == NULL)
    return NULL;
  result->nbytes_data = nbytes;
  return result;
}

void ft_set_clear(t_set* set) {
  set->len = 0;
}

void ft_set_clean(t_set* set) {
  if (set->data)
    free(set->data);
  free(set);
}

uint32_t ft_set_reserve(t_set* set, const uint32_t capacity) {
  if (capacity <= set->capacity)
    return 0;
  uint8_t* new_ptr = realloc(set->data, capacity * set->nbytes_data);
  if (new_ptr == NULL)
    return 1;
  set->data = new_ptr;
  set->capacity = capacity;
  memset(set->data + set->len, 0, (set->capacity - set->len) * set->nbytes_data);
  return 0;
}

bool  ft_set_has(const t_set* set, const void* data) {
  for (uint32_t idx = 0; idx < set->len * set->nbytes_data; idx += set->nbytes_data) {
    if (ft_memcmp(set->data + idx, data, set->nbytes_data) == 0)
      return true;
  }
  return false;
}

void* ft_set_get(const t_set* set, const uint32_t idx) {
  if (idx > set->len)
    return NULL;
  return set->data + idx * set->nbytes_data;
}

uint32_t ft_set_set(const t_set* set, const uint32_t idx, const void* data, const uint32_t nbytes_data) {
  if (idx > set->len)
    return 1;
  ft_memcpy(set->data + idx * set->nbytes_data, data, nbytes_data);
  return 0;
}

uint32_t ft_set_insert(t_set* set, const void* data, const uint32_t idx) {
  if (set->capacity < set->len + (idx - set->len)) {
    if (ft_set_reserve(set, (set->capacity + (idx - set->len)) * 2))
      return 1;
  }
  if (idx > set->len) {
    ft_memset(set->data + set->len, 0, idx - set->len);
    set->len = idx;
  }
  ft_memcpy(set->data + idx * set->nbytes_data, &data, set->nbytes_data);
  return 0;
}

uint32_t ft_set_append(t_set* set, const void* data, const size_t len) {
  if (set->capacity < set->len + len) {
    if (ft_set_reserve(set, (set->capacity + len) * 2))
      return 1;
  }
  ft_memcpy(set->data + set->len, data, len);
  set->len += len;
  return 0;
}
