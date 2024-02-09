/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:37:06 by loumouli          #+#    #+#             */
/*   Updated: 2022/05/11 15:15:31 by loumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void ft_lstdelone(s_list* lst, void (*del)(void*)) {
  if (lst) {
    del ? del(lst->data) : 0;
    free(lst);
  }
}
