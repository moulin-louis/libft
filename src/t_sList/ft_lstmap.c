/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:35:12 by loumouli          #+#    #+#             */
/*   Updated: 2022/05/11 11:55:22 by loumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sList* ft_lstmap(t_sList* lst, void* (*f)(void*), void (*del)(void*)) {
  t_sList* result;
  t_sList* temp;

  if (!f || !del || !lst)
    return (NULL);
  result = ft_lstnew(f(lst->data));
  if (!result)
    return (NULL);
  temp = result;
  lst = lst->next;
  while (lst) {
    result->next = ft_lstnew(f(lst->data));
    if (!result->next)
      ft_lstdelone(result->next, del);
    result = result->next;
    lst = lst->next;
  }
  return (temp);
}
