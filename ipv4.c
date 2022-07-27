#include "ipv4.h"
#include "scan.h"

unsigned int ipv4_scan(ipv4 *i, char *s)
{
  unsigned int r, len = 0;
  unsigned long u;

  if(!(r = scan_ulong(&u,s))) return 0; i->d[0] = u; len += r; s += r;
  if(*s != '.') return 0; ++s; ++len;
  if(!(r = scan_ulong(&u,s))) return 0; i->d[1] = u; len += r; s += r;
  if(*s != '.') return 0; ++s; ++len;
  if(!(r = scan_ulong(&u,s))) return 0; i->d[2] = u; len += r; s += r;
  if(*s != '.') return 0; ++s; ++len;
  if(!(r = scan_ulong(&u,s))) return 0; i->d[3] = u; len += r; s += r;
  return len;
}
