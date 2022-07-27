#ifndef OPEN_H
#define OPEN_H

#include <fcntl.h>

#define open_read(fn) open(fn, O_RDONLY)

#endif
