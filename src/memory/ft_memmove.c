/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:50:33 by loumouli          #+#    #+#             */
/*   Updated: 2022/05/11 12:09:12 by loumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef FT_BUILTIN
void* ft_memmove(void* dest, const void* src, uint64_t n) {
  char* s;
  char* d;
  uint64_t i;

  s = (char*)src;
  d = (char*)dest;
  i = 0;
  if (!dest && !src)
    return (NULL);
  if (d > s)
    while (n-- > 0)
      d[n] = s[n];
  else {
    while (i < n) {
      d[i] = s[i];
      i++;
    }
  }
  return (dest);
}
#endif