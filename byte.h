#ifndef BYTE_H
#define BYTE_H

#include <string.h>

#define byte_zero(d,l)   (void)memset(d,0,l)
#define byte_copy(d,s,l) (void)memcpy(d,s,l)

#endif
