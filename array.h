#ifndef ARRAY_H
#define ARRAY_H

typedef struct array {
  void *x;
  unsigned int l;
  unsigned int a;
} array;

extern array *array_alloc();
extern int array_rdypls(array *, unsigned int);
extern int array_push(array *, void *, unsigned int);
extern int array_push0(array *, unsigned int);
extern int array_pop(array *, void *, unsigned int);
extern int array_copyb(array *, char *, unsigned int);
extern int array_copys(array *, char *);

static inline unsigned int array_len(array *a, unsigned int len)
{
  return a->l / len;
}

static int array_cat0(array *a)
{
  return array_push0(a,sizeof(char));
}

#include "str.h"

static int array_cats(array *a, char *obj)
{
  return array_push(a,obj,str_len(obj));
}

#endif
