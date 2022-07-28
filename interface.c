#include "interface.h"
#include "open.h"
#include "read.h"
#include "close.h"
#include "byte.h"
#include "str.h"
#include "scan.h"
#include "array.h"
#include "slurpclose.h"

array data;

static int get1(char *name)
{
  unsigned long u;
  int fd;

  if(!array_copys(&data, "/proc/sys/net/ipv4/conf/")) return -1;
  if(!array_cats(&data, name)) return -1;
  if(!array_cats(&data, "/rp_filter")) return -1;
  if(!array_cat0(&data)) return -1;

  if((fd = open_read(data.x)) == -1) return -1;
  if(!array_copys(&data, "")) return -1;
  if(slurpclose(fd,&data,10) == -1) return -1;
  if(!array_cat0(&data)) return -1;

  if(!scan_ulong(&u, data.x)) return 0;
  return (u != 1);
}

#include <net/if.h>

int interface_get_rpfilter_values(array *a)
{
  struct if_nameindex *if_nidxs;

  if_nidxs = if_nameindex();
  if(if_nidxs){
    struct if_nameindex *intf;
    array x;
    for (intf = if_nidxs; intf->if_index || intf->if_name; intf++){
      byte_zero(&x, sizeof(array));
      if(get1(intf->if_name) != 1) continue;
      if(!array_push(&x,intf->if_name,str_len(intf->if_name))) return -1;
      if(!array_push0(&x, sizeof(char))) return 0;
      if(!array_push(a,&x,sizeof(array))) return 0;
    }
    if_freenameindex(if_nidxs);
  }
  return 1;
}
