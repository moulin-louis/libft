/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:50:19 by loumouli          #+#    #+#             */
/*   Updated: 2022/05/11 13:17:55 by loumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/libft.h"

void ft_lstadd_front(s_list** lst, s_list* new) {
  new->next = *lst;
  *lst = new;
}
