#include "fmt.h"

unsigned int fmt_uint(char *s, unsigned int u)
{
  unsigned long l; l = u; return fmt_ulong(s,l);
}

unsigned int fmt_ulong(char *s, unsigned long u)
{
  register unsigned int len; register unsigned long q;
  len = 1; q = u;
  while (q > 9) { ++len; q /= 10; }
  if (s) {
    s += len;
    do { *--s = '0' + (u % 10); u /= 10; } while(u); /* handles u == 0 */
  }
  return len;
}

unsigned int fmt_uint0(char *s, unsigned int u, unsigned int n)
{
  unsigned int len;
  len = fmt_uint(FMT_LEN,u);
  while (len < n) { if (s) *s++ = '0'; ++len; }
  if (s) fmt_uint(s,u);
  return len;
}
