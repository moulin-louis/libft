#include "./inc/libft.h"

t_hashTable *test() {
  t_hashTable *ht = ft_ht_new();
  for (uint64_t i = 0; i < 5; ++i) {
    uint64_t* tmp = malloc(sizeof(uint64_t));
    *tmp = i;
    ft_ht_insert(ht, tmp, sizeof(tmp), (void *)i);
  }
  return ht;
}

uint64_t free_item(t_htItem* item) {
  free((void *)item->key);
  return 0;
}

uint64_t iter_fn(t_htItem* item) {
  item->data += 2;
  return 0;
}

int main(void) {
  t_hashTable *ht = test();
  ft_ht_print(ht);
  ft_ht_iterItem(ht, iter_fn);
  ft_ht_print(ht);
  ft_ht_clean(ht, free_item);
}
