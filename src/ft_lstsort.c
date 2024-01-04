//
// Created by loumouli on 11/26/23.
//

#include "libft.h"
#include <stdbool.h>
#include <stdio.h>

void ft_lstsort(t_list* head, int (*cmp_fn)(const void*, const void*)) {
  if (cmp_fn == NULL || head == NULL)
    return;
  bool swapped = false;
  t_list* ptr;
  void* temp;
  do {
    swapped = false;
    ptr = head;

    while (ptr->next != NULL) {
      if (cmp_fn(ptr->content, ptr->next->content) > 0) {
        // Swap the content of the nodes
        temp = ptr->content;
        ptr->content = ptr->next->content;
        ptr->next->content = temp;
        swapped = true;
      }
      ptr = ptr->next;
    }
  }
  while (swapped);
}
