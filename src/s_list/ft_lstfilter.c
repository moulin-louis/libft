//
// Created by loumouli on 11/26/23.
//

#include "libft.h"

void filter_lst(s_list** head, int (*filter)(const void*), void (*del)(void*)) {
  s_list* current = *head;
  s_list* prev = NULL;

  while (current != NULL) {
    if (filter(current->data)) {
      if (prev == NULL) {
        *head = current->next;
        del(current->data);
        free(current);
        current = *head;
      }
      else {
        s_list* temp = current;
        prev->next = current->next;
        current = current->next;
        del(temp->data);
        free(temp);
      }
    }
    else {
      prev = current;
      current = current->next;
    }
  }
}
