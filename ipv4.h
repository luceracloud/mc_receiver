#ifndef IPV4_H
#define IPV4_H

typedef struct ipv4 {
  unsigned char d[4];
} ipv4;

extern unsigned int ipv4_scan(ipv4 *, char *);

#endif
