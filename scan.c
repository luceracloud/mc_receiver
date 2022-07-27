#include "scan.h"

unsigned int scan_ulong(unsigned long *u, char *s)
{
  unsigned int len = 0;
  unsigned long r, result = 0;

  while((r = (unsigned long)(unsigned char)s[len] - '0') < 10){
    result = result * 10 + r;
    ++len;
  }
  *u = result;
  return len;
}
