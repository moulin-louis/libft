/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:19:29 by loumouli          #+#    #+#             */
/*   Updated: 2022/05/02 18:09:28 by loumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef FT_BUILTIN

size_t ft_strlen(const char* str) {
  uint64_t i;
  for (i = 0; str[i]; ++i) {}
  return i;
}
#endif