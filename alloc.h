#ifndef ALLOC_H
#define ALLOC_H

extern void *alloc(unsigned int);
extern void alloc_free(void *);
extern int alloc_re(void **, unsigned int, unsigned int);

#endif