//
// Created by loumouli on 11/26/23.
//

#include "libft.h"

void filter_lst(t_sList** head, int (*filter)(const void*), void (*del)(void*)) {
  t_sList* current = *head;
  t_sList* prev = NULL;

  while (current != NULL) {
    if (filter(current->data)) {
      if (prev == NULL) {
        *head = current->next;
        del(current->data);
        free(current);
        current = *head;
      }
      else {
        t_sList* temp = current;
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
