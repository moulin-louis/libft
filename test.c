#include "./inc/libft.h"

int main(void) {
  t_rb* rb = ft_rb_new(NULL, sizeof(void*));
  ft_rb_insert(rb, (void*)4);
  ft_rb_insert(rb, (void*)2);
  ft_rb_insert(rb, (void*)6);
  ft_rb_print(rb->root, 0);
  ft_rb_clean(rb);
}
