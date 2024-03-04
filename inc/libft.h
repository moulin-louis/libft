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

#include "character.h" //character prototype FN
#include "io.h" // I/O FN prototype FN
#include "memory.h" //memory prototype FN
#include "strings.h" //string FN prototype
#include "t_bTree.h" //t_bTree definition + prototype FN
#include "t_hashTable.h" //t_hashTable/htItem defination + prototype FN
#include "t_rb.h" //t_rb definition + prototype FN
#include "t_sList.h" //s_list definition + prototype FN
#include "t_set.h" //Set definition + prototype FN

#ifndef FT_BUILTIN
#define ft_memset(dest, src, size) __builtin_memset(dest, src, size)
#define ft_memcpy(dest, src, size) __builtin_memcpy(dest, src, size)
#define ft_memmove(dest, src, size) __builtin_memmove(dest, src, size)
#define ft_memchr(dest, src, size) __builtin_memchr(dest, src, size)
#define ft_memcmp(dest, src, size) __builtin_memcmp(dest, src, size)
#define ft_strlen(str) __builtin_strlen(str)
#define ft_strlcpy(dest, src, size) __builtin_strlcpy(dest, src, size)
#define ft_strlcat(dest, src, size) __builtin_strlcat(dest, src, size)
#define ft_strchr(str, c) __builtin_strchr(str, c)
#define ft_strrchr(str, c) __builtin_strrchr(str, c)
#define ft_strnstr(dest, src, size) __builtin_strnstr(dest, src, size)
#define ft_strncmp(dest, src, size) __builtin_strncmp(dest, src, size)
#define ft_atoi(str) __builtin_atoi(str)
#define ft_strdup(str) __builtin_strdup(str)
#endif

#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// hexdump a given array, will put a '\n' every row
void ft_hexdump(const void* data, uint64_t nbytes, uint64_t row);

#endif
