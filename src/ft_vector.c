//
// Created by loumouli on 1/29/24.
//

#include "libft.h"

t_set* ft_set_new(const uint64_t nbytes) {
  t_set* result = ft_calloc(1, sizeof(t_set));
  if (result == NULL)
    return NULL;
  memcpy((void *)&result->nbytes_data, &nbytes, sizeof(void*));
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
  ft_memset(set->data + set->len * set->nbytes_data, 0, (set->capacity - set->len) * set->nbytes_data);
  return 0;
}

bool  ft_set_has(const t_set* set, const void* data) {
  for (uint64_t i = 0; i < set->len; ++i) {
    const void *item = ft_set_get(set, i);
    if (ft_memcmp(item, data, set->nbytes_data) == 0)
      return true;
  }
  return false;
}

void* ft_set_get(const t_set* set, const uint32_t idx) {
  if (idx > set->len)
    return NULL;
  return set->data + idx * set->nbytes_data;
}

uint32_t ft_set_insert(t_set* set, const void* data, const uint32_t idx) {

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

uint32_t ft_set_append(t_set* set, const void* data, const size_t len) {
  if (set->capacity < set->len + len) {
    if (ft_set_reserve(set, (set->capacity + len) * 2))
      return 1;
  }
  ft_memcpy(set->data + set->len * set->nbytes_data, data, len);
  set->len += len;
  return 0;
}
