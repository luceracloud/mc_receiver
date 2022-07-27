#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>

#define socket_udp4() socket(PF_INET, SOCK_DGRAM, 0)

#include "ipv4.h"

extern int socket_bind4(int, ipv4 *, unsigned int);
extern int socket_add_membership(int, ipv4 *);
extern ssize_t socket4_recv(int, char *, size_t, ipv4 *, unsigned int *);

#endif
