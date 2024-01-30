#include "./inc/libft.h"

int main(void) {
    t_hashTable* ht = ft_ht_new();
    for (uint64_t i = 0; i < 3; ++i) {
        printf("iteration: %ld\n", i);
        ft_ht_insert(ht, &i, sizeof(i), (void *)i);
    }
    ft_ht_clean(ht);
}