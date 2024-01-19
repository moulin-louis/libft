/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:39:27 by loumouli          #+#    #+#             */
/*   Updated: 2023/02/12 13:39:27 by loumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

     {
  if (set->capacity < set->len + len) {
    const size_t new_capacity = (set->capacity + len) * 2;
    const void* new_data = realloc(set->data, new_capacity);
    if (new_data == NULL) {
      return 1;
    }
    set->capacity = new_capacity;
    set->data = (uint8_t *)new_data;
  }
  ft_memcpy(set->data + set->len, data, len);
  set->len += len;
  return 0;
}

//Read the entire file into memory using a vector, return non-zero value if fail
int32_t read_file(const char* path, uint8_t** result, size_t* len) {
  t_set set = {};
  const int file = open(path, O_RDONLY);
  if (file == -1)
    return 1;
  set.data = malloc(1024);
  if (set.data == NULL) {
    close(file);
    return 1;
  }
  set.capacity = 1024;
  while (1) {
    char buff[4096];
    const ssize_t retval = read(file, buff, sizeof(buff));
    if (retval == -1) {
      free(set.data);
      close(file);
      return 1;
    }
    if (retval == 0)
      break;
    if (append_data_set(&set, buff, retval)) {
      close(file);
      free(set.data);
      return 1;
    }
  }
  close(file);
  *result = set.data;
  *len = set.len;
  return 0;
}