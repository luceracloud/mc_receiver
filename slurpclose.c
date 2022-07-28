#include "slurpclose.h"
#include "close.h"
#include "read.h"
#include "array.h"
#include <errno.h>	/* Linux is incredibly dumb */

int slurpclose(int fd, array *a, unsigned int bufsize)
{
  for(;;){
    int r;
    if(!array_rdypls(a,bufsize)) { (void)close(fd); return -1; }
    r = read(fd,a->x + a->l,bufsize);
    if(r == -1) if(errno == EINTR) continue;
    if(r <= 0) { (void)close(fd); return r; }
    a->l += r;
  }
}
