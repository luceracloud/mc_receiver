#include "interface.h"
#include "open.h"
#include "read.h"
#include "close.h"
#include "byte.h"
#include "str.h"
#include <stdio.h>
#include <net/if.h>
#include <linux/limits.h>	/* For PATH_MAX, even if it truly isn't */

static int get1(char *name)
{
  char fn[PATH_MAX];
  int fd;

  snprintf(fn, PATH_MAX, "/proc/sys/net/ipv4/conf/%s/rp_filter", name);
  if((fd = open_read(fn)) == -1) goto err3;
  if(read(fd,&fn,1) != 1) goto err2;
  if(fn[0] == '0') { (void)close(fd); return 0; }
err2:
  (void)close(fd);
err3:
  return 1;
}

void interface_get_rpfilter_values(array *a)
{
  struct if_nameindex *if_nidxs;

  if_nidxs = if_nameindex();
  if(if_nidxs){
    struct if_nameindex *intf;
    array x;
    for (intf = if_nidxs; intf->if_index || intf->if_name; intf++){
      byte_zero(&x, sizeof(array));
      if(!get1(intf->if_name)) continue;
      array_push(&x,intf->if_name,str_len(intf->if_name));
      array_push0(&x, sizeof(char));
      array_push(a,&x,sizeof(array));
    }
    if_freenameindex(if_nidxs);
  }
  return;
}
