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

// Read the entire file into memory using a vector, return non-zero value if fail
t_set* read_file(const char* path) {
  const int file = open(path, O_RDONLY);
  if (file == -1)
    return NULL;
  t_set* set = ft_set_new(sizeof(char));
  if (set == NULL)
    return NULL;
  while (1) {
    char buff[4096];
    const ssize_t retval = read(file, buff, sizeof(buff) - 1);
    if (retval == -1) {
      ft_set_destroy(set, NULL);
      close(file);
      return NULL;
    }
    if (retval == 0)
      break;
    buff[retval] = 0;
    if (ft_set_push(set, buff, retval + 1)) {
      close(file);
      ft_set_destroy(set, NULL);
      return NULL;
    }
  }
  close(file);
  return set;
}
