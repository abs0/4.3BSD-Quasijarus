h31402
s 00018/00000/00000
d D 4.1 83/05/06 23:50:10 tut 1 0
c date and time created 83/05/06 23:50:10 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

#if LONG
# define ptr long
# define uptr long
# define getp getl
# define putp putl
# define MONE -1L
extern long getl();
#else
# define ptr int
# define uptr unsigned
# define getp getw
# define putp putw
# define MONE -1
#endif
E 1
