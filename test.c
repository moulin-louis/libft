#include "./inc/libft.h"

int main(void) {
  t_bTree* b_tree = ft_bTree_new(sizeof(void*), NULL, NULL);

  ft_bTree_insert(b_tree, (void*)5);
  ft_bTree_insert(b_tree, (void*)0);
  ft_bTree_insert(b_tree, (void*)10);
  ft_bTree_print(b_tree->root, 0);
  ft_bTree_destroy(b_tree);
}
