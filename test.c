#include "./inc/libft.h"


typedef void(^block_fn)(void);

block_fn foo(void) {
  int x = 42;
  void (^lbd)(void) = ^{
    printf("x = %d", x);
  };
  lbd();
  return lbd;
}

int main(void) {
  //call foo with a clang lambda/block
  block_fn lbd = foo();
  (void)lbd;
  // lbd();
}
