/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:58:54 by loumouli          #+#    #+#             */
/*   Updated: 2022/05/11 15:22:25 by loumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_sList** lst, void (*del)(void*)) {
  t_sList* temp;

  while (*lst) {
    temp = (*lst)->next;
    ft_lstdelone(*lst, del);
    *lst = temp;
  }
}
