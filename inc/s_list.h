//
// Created by loumouli on 2/7/24.
//

#ifndef S_LIST_H
#define S_LIST_H

#include <stdlib.h>

// Singled Linked List structure
typedef struct sl_list {
  void* data; // Actual data, can hold up to 64 bits or a pointer
  struct sl_list* last_node; // Pointer to the last node of the single linked list
  struct sl_list* next; // Pointer to the next node of the single linked list
} s_list;

// Singled Linked List FN
s_list* ft_lstnew(void* content);

s_list* ft_lstmap(s_list* lst, void* (*f)(void*), void (*del)(void*));

void ft_lstiter(s_list* lst, void (*f)(void*));

void ft_lstclear(s_list** lst, void (*del)(void*));

void ft_lstdelone(s_list* lst, void (*del)(void*));

void ft_lstsort(s_list* head, int32_t (*cmp_fn)(const void*, const void*));

void filter_lst(s_list** head, int32_t (*filter)(const void*), void (*del)(void*));

s_list* ft_lstlast(s_list* lst);

int32_t ft_lstsize(s_list* lst);

void ft_lstadd_back(s_list** lst, s_list* new);

void ft_lstadd_front(s_list** lst, s_list* new);

void ft_lstdelone(s_list* lst, void (*del)(void*));

#endif // S_LIST_H
