#include "libft.h"

typedef void(^block_fn)(void);

void foo(block_fn lbd) {
  lbd();
}

int main(void) {
  //call foo with a clang lambda/block
  int x = 42;
  auto lbd = ^(void) {
    printf("%d\n", x);
  };
  foo(lbd);
}
