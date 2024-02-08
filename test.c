#include "./inc/libft.h"

int main(void) {
  t_bTree* b_tree = ft_bTree_new(sizeof(void*), NULL, NULL);
  for (uint64_t i = 0; i < 10; ++i)
    ft_bTree_insert(b_tree, (void *)i);
  ft_bTree_destroy(b_tree);
}
