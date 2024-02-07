/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:24:03 by loumouli          #+#    #+#             */
/*   Updated: 2022/05/11 12:22:55 by loumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

s_list* ft_lstnew(void* content) {
	s_list* result;

	result = malloc(sizeof(s_list));
	if (!result)
		return (NULL);
	result->data = content;
	result->next = NULL;
	return (result);
}
