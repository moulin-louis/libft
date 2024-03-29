// CODE BY MOTERO

#include "libft.h"


#ifdef FT_BUILTIN
void* ft_memcpy(void* dest, const void* src, uint64_t n) {
  char* d;
  const char* s;

  d = dest;
  s = src;
  while (n && ((long)d % sizeof(long) != 0 || (long)s % sizeof(long) != 0)) {
    *d++ = *s++;
    n--;
  }
  while (n >= sizeof(long)) {
    *(long*)d = *(const long*)s;
    d += sizeof(long);
    s += sizeof(long);
    n -= sizeof(long);
  }
  while (n) {
    *d++ = *s++;
    n--;
  }
  return (dest);
}
#endif