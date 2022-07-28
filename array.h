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
extern unsigned int array_len(array *, unsigned int);
extern int array_cats(array *, char *);
extern int array_cat0(array *);
extern int array_copyb(array *, char *, unsigned int);
extern int array_copys(array *, char *);

#endif
