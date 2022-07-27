#ifndef STRERR_H
#define STRERR_H

#define strerr_warn1x(s1) strerr_warn(s1,0,0,0,0)
#define strerr_warn2x(s1,s2) strerr_warn(s1,s2,0,0,0)
extern void strerr_warn(char *, char *, char *, char *, char *);

#define strerr_die1x(c, s1) strerr_die(c,s1,0,0,0,0)
extern void strerr_die(int, char *, char *, char *, char *, char *);

#endif
