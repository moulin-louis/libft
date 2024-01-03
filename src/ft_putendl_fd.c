/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:56:43 by loumouli          #+#    #+#             */
/*   Updated: 2022/05/05 12:14:36 by loumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void ft_putendl_fd(char* s, int fd) {
	int i;

	i = 0;
	while (s[i]) {
		int _x = write(fd, &s[i], 1);
		(void)_x;
		i++;
	}
	int _y = write(fd, "\n", 1);
	(void)_y;
}
