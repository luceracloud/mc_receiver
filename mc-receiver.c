#include <unistd.h>
#include <stdio.h>
#include <net/if.h>

#include "exit.h"
#include "byte.h"
#include "scan.h"
#include "ipv4.h"
#include "socket.h"
#include "strerr.h"
#include "status.h"
#include "array.h"
#include "interface.h"

#define uint  unsigned int
#define ulong unsigned long

static void usage(int ret)
{
  strerr_die1x(ret, "mc-tester: [-h] -g group -p port [-s] [-t]");
}

static ipv4  gFlag;	/* Group Address */
static ulong pFlag;	/* Port */
static uint  sFlag;	/* Send Flag */
static ulong tFlag = 1;	/* TTL */
static ipv4  xFlag;	/* Source Address */

static uint has_x;

static void setup(int argc, char **argv)
{
  int r;
  uint has_g = 0;

  while((r = getopt(argc,argv,"g:hp:st:x:")) != -1){
    switch(r){
      case 'g': has_g = ipv4_scan(&gFlag, optarg); break;
      case 'h': usage(0);
      case 'p': scan_ulong(&pFlag, optarg); break;
      case 's': sFlag = 1; break;
      case 't': scan_ulong(&tFlag, optarg); break;
      case 'x': has_x = ipv4_scan(&xFlag, optarg); break;
      default: strerr_die1x(1, "Unknown option");
    }
  }

  if(!has_g) usage(1);
  if(!pFlag) usage(1);
}


static void _receive()
{
  int sock;

  if((sock = socket_udp4()) == -1) strerr_die1x(111, "Unable to create socket");
  if(socket_bind4(sock, &gFlag, pFlag) == -1) strerr_die1x(111, "Failed to bind to socket");
  if(socket_add_membership(sock, &gFlag)   == -1) strerr_die1x(111, "Failed to add membership");

  for(;;){
    char message[50];
    unsigned int seq;
    ipv4 ip;
    unsigned int port;

    ssize_t cnt = socket4_recv(sock, (char *)&message, sizeof(message), &ip, &port);
    if(cnt == -1) strerr_die1x(111, "Error in recvfrom");
    if(cnt == 0) break;

    byte_copy(&seq, &message, 4);
    status(seq, (char *)&ip, port);
  }
}

static void test() {
  array a = {0}, b = {0};
  interface_get_rpfilter_values(&a);
  strerr_warn1x("Interfaces which have rp_filter set:");
  while(array_pop(&a, &b, sizeof(array)))
    strerr_warn2x("\t", (char *)b.x);
}

int main(int argc, char **argv)
{
  setup(argc,argv);
  test();
  if(!sFlag) _receive();
  _exit(0);
}
