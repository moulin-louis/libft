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

// Init a new s_list on the heap
s_list* ft_lstnew(void* content);

// Clone the given list but with all node data applied the function `f`, call `del` on the node if `f` failed
s_list* ft_lstmap(s_list* lst, void* (*f)(void*), void (*del)(void*));

// Call `f` on every nodes data of the list
void ft_lstiter(s_list* lst, void (*f)(void*));

// Call `del` function on every data of the list
void ft_lstclear(s_list** lst, void (*del)(void*));

// Delete one node with `del` applied on the data
void ft_lstdelone(s_list* lst, void (*del)(void*));

// Sort the list based on a compare function
void ft_lstsort(s_list* head, int32_t (*cmp_fn)(const void*, const void*));

// Filter the list based on a filter function
void filter_lst(s_list** head, int32_t (*filter)(const void*), void (*del)(void*));

// Return the last node of the list
s_list* ft_lstlast(s_list* lst);

// Return the size of the list
int32_t ft_lstsize(s_list* lst);

// Add a node to the end of the list
void ft_lstadd_back(s_list** lst, s_list* new);

// Add a node to the front of the list
void ft_lstadd_front(s_list** lst, s_list* new);

#endif // S_LIST_H
