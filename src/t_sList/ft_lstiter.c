/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:31:32 by loumouli          #+#    #+#             */
/*   Updated: 2022/05/11 15:52:01 by loumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstiter(t_sList* lst, void (*f)(void*)) {
  t_sList* temp;

  while (lst) {
    temp = lst->next;
    f(lst->data);
    lst = temp;
  }
}
