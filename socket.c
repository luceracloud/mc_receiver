#include "socket.h"
#include "byte.h"
#include <netinet/in.h>

int socket_bind4(int sock, ipv4 *ip4, unsigned int port)
{
  struct sockaddr_in addr;
  byte_zero(&addr, sizeof(addr));
  byte_copy(&addr.sin_addr, ip4, 4);
  addr.sin_port = htons(port);
  addr.sin_family = AF_INET;
  return bind(sock, (struct sockaddr *)&addr, sizeof(addr));
}

int socket_add_membership(int sock, ipv4 *addr)
{
  struct ip_mreq member;
  byte_copy(&member.imr_multiaddr.s_addr, addr, 4);
  member.imr_interface.s_addr = htonl(INADDR_ANY);
  return setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &member, sizeof(member));
}

ssize_t socket4_recv(int sock, char *buf, size_t len, ipv4 *ip, unsigned int *port)
{
  struct sockaddr_in addr;
  socklen_t addrlen;
  ssize_t r;

  addrlen = sizeof(addr);
  if((r = recvfrom(sock, buf, len, 0, (struct sockaddr *)&addr, &addrlen)) < 0) return -1;
  byte_copy(ip,&addr.sin_addr,4);
  *port = ntohs(addr.sin_port);
  return r;
}
