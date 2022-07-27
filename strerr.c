#include "strerr.h"
#include "exit.h"
#include <stdio.h>

void strerr_warn(char *s1, char *s2, char *s3, char *s4, char *s5)
{
  if(s1) fprintf(stderr, "%s", s1);
  if(s2) fprintf(stderr, "%s", s2);
  if(s3) fprintf(stderr, "%s", s3);
  if(s4) fprintf(stderr, "%s", s4);
  if(s5) fprintf(stderr, "%s", s5);
  fprintf(stderr, "\n");
}

void strerr_die(int c, char *s1, char *s2, char *s3, char *s4, char *s5)
{
  strerr_warn(s1,s2,s3,s4,s5);
  _exit(c);
}
