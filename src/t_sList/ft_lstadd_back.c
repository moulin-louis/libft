/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:06:47 by loumouli          #+#    #+#             */
/*   Updated: 2022/05/11 14:53:06 by loumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void ft_lstadd_back(t_sList** lst, t_sList* new) {
  t_sList* temp;

  if (!*lst)
    *lst = new;
  else {
    temp = ft_lstlast(*lst);
    temp->next = new;
  }
}
