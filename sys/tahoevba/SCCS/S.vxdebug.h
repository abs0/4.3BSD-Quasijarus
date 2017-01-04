h34408
s 00001/00001/00013
d D 1.2 86/01/12 21:46:25 sam 2 1
c fix some includes and make scope points globally controlled
e
s 00014/00000/00000
d D 1.1 85/07/21 20:36:07 sam 1 0
c date and time created 85/07/21 20:36:07 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#ifdef VX_DEBUG
#define VXERR4		1
#define VXNOBUF		2
extern long vxintr4;

extern long vxdebug;
#define VXVCM	1
#define VXVCC	2
#define VXVCX	4

D 2
#include "../sna/snadebug.h"
E 2
I 2
#include "../tahoesna/snadebug.h"
E 2
#endif
E 1
