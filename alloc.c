#include "alloc.h"
#include "byte.h"

int alloc_re(void **x, unsigned int m, unsigned int n)
{
  void *y;

  y = alloc(n);
  if(!y) return 0;
  byte_copy(y,*x,n);
  alloc_free(*x);
  *x = y;
  return 1;
}
