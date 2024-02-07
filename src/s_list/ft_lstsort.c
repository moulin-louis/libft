//
// Created by loumouli on 11/26/23.
//

#include "libft.h"
#include <stdbool.h>
#include <stdio.h>

void ft_lstsort(s_list* head, int (*cmp_fn)(const void*, const void*)) {
  if (cmp_fn == NULL || head == NULL)
    return;
  bool swapped = false;
  s_list* ptr;
  void* temp;
  do {
    swapped = false;
    ptr = head;

    while (ptr->next != NULL) {
      if (cmp_fn(ptr->data, ptr->next->data) > 0) {
        // Swap the content of the nodes
        temp = ptr->data;
        ptr->data = ptr->next->data;
        ptr->next->data = temp;
        swapped = true;
      }
      ptr = ptr->next;
    }
  }
  while (swapped);
}
