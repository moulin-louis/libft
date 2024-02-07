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

#include "../inc/libft.h"

s_list* ft_lstmap(s_list* lst, void*(*f)(void*), void (*del)(void*)) {
	s_list* result;
	s_list* temp;

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
