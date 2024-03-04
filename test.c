#include "libft.h"

int main(void) {
  t_rb* rb = ft_rb_new(NULL, NULL);
  for (uint64_t i = 0; i < 3; ++i)
    ft_rb_insert(rb, (void*)i);
  ft_rb_print(rb->root, 0);
  ft_rb_destroy(rb);
}
