h37791
s 00003/00001/00014
d D 1.2 88/12/22 12:54:20 sam 2 1
c use setjmp jmp_buf definition
e
s 00015/00000/00000
d D 1.1 88/12/22 12:53:49 sam 1 0
c date and time created 88/12/22 12:53:49 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

I 2
#include <setjmp.h>

E 2
extern int Fflags;
extern char *Ffile;
extern int Fvalue;
extern int (*Ffunc)();
D 2
extern int Fjmp[10];
E 2
I 2
extern jmp_buf Fjmp;
E 2

#define FTLMSG 0100000
#define FTLCLN 0040000
#define FTLFUNC 020000
#define FTLACT     077
#define FTLJMP      02
#define FTLEXIT      1
#define FTLRET       0
E 1
