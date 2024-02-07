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
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <fcntl.h>
# include "farmhash.h"


//LINKED LIST STRUCTURE
typedef struct s_list {
  void* data; //DATA, CAN HOLD A DATA UP TO 64 BITS OR A POINTER
  struct s_list* last_node; //POINTER TO THE LAST NODE OF THE LINKED LIST
  struct s_list* next; //POINTER TO THE NEXT NODE OF THE LINKED LIST
} t_list;

//SET STRUCTURE
typedef struct {
  void* data; //CONTENT ARRAY, GROW DYNAMICALY
  const uint64_t nbytes_data; //NUMBER OF BYTES OF THE DATA
  size_t len; //LEN OF THE SET
  size_t capacity; //CAPACITY OF THE CONTENT ARRAY
} t_set;

//HASHMAP STRUCTURE
typedef struct {
  const void* key; //POINTER TO THE KEY, NEEDED TO ACCESS THE VALUE
  uint64_t nbytes_key; //NUMBER OF BYTES OF THE KEY
  uint64_t hash; //HASH OF THE KEY, HASHED BY THE FARMHASH HASHING FUNCTION
  const void* data; //DATA, CAN HOLD A DATA UP TO 64 BITS OR A POINTER
} t_htItem;

// typedef struct {
  // uint64_t seed; //seed used for hashing algo
  // t_set* items; //vector of items
// } t_hashTable;

//T_HASHTABLE IS A WRAPPER ARROUND T_SET
//HASH THE KEY TO ACCESS DIRECTLY THE SET VIA AN INDEX
typedef t_set t_hashTable;

typedef enum {
  RED,
  BLACK
} e_color;

typedef struct s_rb {
  e_color       color;
  void*         data;
  uint64_t      nbytes_data;
  struct s_rb*  left;
  struct s_rb*  right;
  struct s_rb*  parent;
} t_rb;


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

t_set* ft_set_new(uint64_t nbytes);

t_set* ft_set_clone(const t_set* set);

void ft_set_clear(t_set* set);

void ft_set_clean(t_set* set);

uint64_t ft_set_reserve(t_set* set, uint64_t capacity);

bool ft_set_has(const t_set* set, const void* data);

void* ft_set_get(const t_set* set, uint64_t idx);

uint64_t ft_set_set(const t_set* set, uint64_t idx, const void* data, uint64_t nbytes_data);

uint64_t ft_set_insert(t_set* set, const void* data, uint64_t idx);

uint64_t ft_set_append(t_set* set, const void* data, size_t len);

// HASHTABLES FN

t_hashTable* ft_ht_new(void);

void ft_ht_clean(t_hashTable* ht, uint64_t (*free_fn)(t_htItem* item));

t_htItem* ft_ht_createItem(const void* key, uint32_t nbytes_key, const void* data);

uint32_t ft_ht_insert(t_hashTable* ht, const void* key, uint32_t nbytes_key, const void* data);

uint32_t ft_ht_insertItems(t_hashTable* ht, const t_htItem* item);

bool ft_ht_hasKey(const t_hashTable* ht, const void* key, uint32_t nbytes_key);

bool ft_ht_hasIdx(const t_hashTable* ht, uint64_t idx);

t_htItem* ft_ht_getKey(const t_hashTable* ht, const void* key, uint32_t nbytes_key);

t_htItem* ft_ht_getIdx(const t_hashTable* ht, uint64_t idx);

uint32_t ft_ht_set(const t_hashTable* ht, const void* key, uint32_t nbytes_key, const void* data);

uint32_t ft_ht_deleteKey(const t_hashTable* ht, const void* key, uint64_t nbytes_key);

uint32_t ft_ht_deleteIdx(const t_hashTable* ht, uint64_t idx);

uint64_t ft_ht_iterItem(const t_hashTable* ht, uint64_t (*iter_fn)(t_htItem* item));

void ft_ht_print(const t_hashTable* ht);

void ft_ht_printFn(const t_hashTable* ht, void (*print_key)(const void* key), void (*print_data)(const void* data));

//OTHER FN

t_set* read_file(const char* path);

void ft_hexdump(const void* data, uint64_t nbytes, uint64_t row);

#endif
