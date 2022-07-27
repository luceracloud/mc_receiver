#include "status.h"
#include "ipv4.h"
#include <stdio.h>

static void hex(unsigned char c)
{
  fprintf(stdout, "%c", "0123456789abcdef"[(c >> 4) & 15]);
  fprintf(stdout, "%c", "0123456789abcdef"[c & 15]);
}

static void put(char c)
{
  fprintf(stdout, "%c", c);
}

static void put_seq(unsigned int c)
{
  fprintf(stdout, "%u", c);
}

void status(unsigned int seq, char ip[4], unsigned int port)
{
  put_seq(seq);
  put(' ');
  hex(ip[0]);
  hex(ip[1]);
  hex(ip[2]);
  hex(ip[3]);
  put(':');
  hex(port >> 8);
  hex(port & 255);
  put('\n');
}
