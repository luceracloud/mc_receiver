#include "array.h"
#include "alloc.h"
#include "byte.h"
#include "str.h"

int array_rdy(array *a, unsigned int len)
{
  if(a->x){
    if(a->a < len){
      if(!alloc_re(&a->x, a->l, len)) return 0;
      a->a = len;
    }
    return 1;
  }
  if(!(a->x = alloc(len))) return 0;
  a->l = 0;
  a->a = len;
  return 1;
}

int array_rdypls(array *a, unsigned int len)
{
  if(a->x){
    unsigned int n;
    if(a->a < (n = a->l + len)){
      if(!alloc_re(&a->x, a->l, n)) return 0;
      a->a = n;
    }
    return 1;
  }
  if(!(a->x = alloc(len))) return 0;
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

int array_copyb(array *a, char *s, unsigned int l)
{
  if(!array_rdy(a,l)) return 0;
  byte_copy(a->x, s, l);
  a->l = l;
  return 1;
}

int array_copys(array *a, char *s)
{
  return array_copyb(a,s,str_len(s));
}
