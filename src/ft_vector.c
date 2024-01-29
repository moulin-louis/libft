//
// Created by loumouli on 1/29/24.
//

#include "libft.h"

t_set*  ft_set_new(void) {
  return ft_calloc(1, sizeof(t_set));
}

void  ft_set_clear(t_set* set) {
  set->len = 0;
}

void ft_set_clean(t_set* set) {
  if (set->data)
    free(set->data);
  set->len = 0;
  set->capacity = 0;
  free(set);
}

uint32_t ft_set_reserve(t_set* set, const uint32_t capacity) {
  if (capacity <= set->capacity)
    return 0;
  uint8_t* new_ptr = realloc(set->data, capacity);
  if (new_ptr == NULL)
    return 1;
  set->data = new_ptr;
  set->capacity = capacity;
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