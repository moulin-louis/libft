/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:20:59 by loumouli          #+#   #+#            */
/*   Updated: 2022/05/11 11:44:21 by loumouli         ###  ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include "memory.h" //memory prototype FN
#include "character.h" //character prototype FN
#include "io.h" // I/O FN prototype FN
#include "s_list.h" //s_list definition + prototype FN
#include "string.h" //string FN prototype
#include "t_hashTable.h" //t_hashTable/htItem defination + prototype FN
#include "t_rb.h" //t_rb definition + prototype FN
#include "t_set.h" //Set definition + prototype FN

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

//OTHER FN
void ft_hexdump(const void* data, uint64_t nbytes, uint64_t row);

#endif
