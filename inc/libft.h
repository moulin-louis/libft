/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loumouli <loumouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:20:59 by loumouli          #+#    #+#             */
/*   Updated: 2022/05/11 11:44:21 by loumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

typedef struct s_list {
  void* content;
  struct s_list* last_node;
  struct s_list* next;
} t_list;

typedef struct {
  uint8_t* data;
  size_t len;
  size_t capacity;
} t_set;

typedef struct {
  uint8_t* key;
  uint8_t* data;
} t_htItem;

typedef struct {
  uint32_t size;
  uint32_t count;
  t_set   *items;
} t_hashTable;

t_list* ft_lstmap(t_list* lst, void*(*f)(void*), void (*del)(void*));

void ft_lstiter(t_list* lst, void (*f)(void*));

void ft_lstclear(t_list** lst, void (*del)(void*));

void ft_lstdelone(t_list* lst, void (*del)(void*));

void ft_lstsort(t_list* head, int32_t (*cmp_fn)(const void*, const void*));

void filter_lst(t_list** head, int32_t (*filter)(const void*), void (*del)(void*));

char* ft_substr(char const* s, int32_t start, size_t len);

char ft_tolower(char c);

int32_t ft_toupper(int32_t c);

char* ft_strrchr(const char* s, int32_t c);

char* ft_strnstr(const char* big, const char* little, size_t len);

int32_t ft_strncmp(const char* s1, const char* s2, size_t n);

int32_t ft_strncmp_map(const char* s1, const char* s2, size_t n, char (*map)(char));

int32_t ft_strcmp(const char* s1, const char* s2);

size_t ft_strlen(const char* s);

size_t ft_strlcpy(char* dest, const char* src, size_t size);

size_t ft_strlcat(char* dst, const char* src, size_t size);

char* ft_strdup(const char* s);

char* ft_strchr(const char* s, int32_t c);

void* ft_memset(void* s, int32_t c, size_t n);

void* ft_memmove(void* dest, const void* src, size_t n);

void* ft_memcpy(void* dest, const void* src, size_t n);

void* memcpy_avx(void* dest, const void* src, size_t n);

void* memcpy_x86(void* dest, const void* src, size_t n);

int32_t ft_memcmp(const void* s1, const void* s2, size_t n);

void* ft_memchr(const void* s, int32_t c, size_t n);

int32_t ft_isprint(int32_t c);

int32_t ft_isdigit(int32_t c);

int32_t ft_isascii(int32_t c);

int32_t ft_isalpha(int32_t c);

int32_t ft_isalnum(int32_t c);

void* ft_calloc(size_t nmemb, size_t size);

void ft_bzero(void* s, size_t n);

int32_t ft_atoi(const char* nptr);

char* ft_strjoin(char const* s1, char const* s2);

char* ft_strtrim(char const* s1, char const* set);

char** ft_split(char const* s, char c);

char* ft_itoa(int32_t n);

char* ft_strmapi(char const* s, char (*f)(unsigned int32_t, char));

void ft_striteri(char* s, void (*f)(unsigned int32_t, char*));

void ft_putchar_fd(char c, int32_t fd);

void ft_putstr_fd(const char* s, int32_t fd);

void ft_putendl_fd(char* s, int32_t fd);

void ft_putnbr_fd(int32_t n, int32_t fd);

void ft_lstadd_back(t_list** lst, t_list* new);

t_list* ft_lstlast(t_list* lst);

int32_t ft_lstsize(t_list* lst);

t_list* ft_lstnew(void* content);

void ft_lstadd_front(t_list** lst, t_list* new);

void ft_lstdelone(t_list* lst, void (*del)(void*));

void clean_array(char** arr);

//VECTOR FN

uint32_t ft_set_append(t_set* set, const void* data, size_t len);

uint32_t ft_set_reserve(t_set* set, uint32_t capacity);

void ft_set_clean(t_set* set);

void ft_set_clear(t_set* set);

t_set* ft_set_new(void);

// HASHMAP FN

t_hashTable* ft_ht_new(void);

void ft_ht_clean(t_hashTable* ht);

//OTHER FN

t_set* read_file(const char* path);

#endif
