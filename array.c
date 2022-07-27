#include "array.h"
#include "alloc.h"
#include "byte.h"

static int array_rdypls(array *a, unsigned int len)
{
  if(a->x){
    unsigned int n;
    if(a->a < (n = a->l + len)){
      if(!alloc_re(&a->x, a->l, n)) return 0;
      a->a = n;
    }
    return 1;
  }
  a->x = alloc(len);
  if(!a->x) return 0;
  a->l = 0;
  a->a = len;
  return 1;
}

array *array_alloc()
{
  array *x = alloc(sizeof(array));
  if(!x) return 0;
  byte_zero(x,sizeof(array));
  return x;
}

int array_push(array *a, void *obj, unsigned int len)
{
  if(!array_rdypls(a,len)) return 0;
  byte_copy(a->x + a->l, obj, len);
  a->l += len;
  return 1;
}

int array_pop(array *a, void *obj, unsigned int len)
{
  if((a->l - len) > a->l) return 0;
  a->l -= len;
  byte_copy(obj,a->x + a->l, len);
  return 1;
}

int array_push0(array *a, unsigned int len)
{
  if(!array_rdypls(a,len)) return 0;
  byte_zero(a->x + a->l, len);
  a->l += len;
  return 1;
}

unsigned int array_len(array *a, unsigned int len)
{
  return a->l / len;
}
