//
// Created by loumouli on 2/7/24.
//

#include "libft.h"
#include "t_rb.h"

t_rb* ft_rb_new(uint64_t nbytes_data) {
  t_rb* result = calloc(1, sizeof(t_rb));
  if (result == NULL)
    return NULL;
  result->color = BLACK;
  result->nbytes_data = nbytes_data;
  return result;
}
