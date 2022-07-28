#ifndef ALLOC_H
#define ALLOC_H

extern void *malloc();
extern void free();

static inline void *alloc(unsigned int n)
{
  return malloc((long unsigned int)n);
}

static inline void alloc_free(void *x)
{
  if(x) free(x);
}

extern int alloc_re(void **, unsigned int, unsigned int);

#endif
