h31528
s 00011/00006/00028
d D 5.4 88/06/27 18:22:52 bostic 4 3
c install approved copyright notice
e
s 00015/00001/00019
d D 5.3 88/05/20 17:15:07 bostic 3 2
c add Berkeley specific header
e
s 00015/00001/00005
d D 5.2 84/11/04 23:04:20 mckusick 2 1
c call signal emulation routine if signal syscall is not implemented
e
s 00006/00000/00000
d D 5.1 84/08/24 16:53:34 mckusick 1 0
c date and time created 84/08/24 16:53:34 by mckusick
e
u
U
t
T
I 1
D 3
/* %M% %I% %E% */
E 3
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 4
 */

#if defined(SYSLIBC_SCCS) && !defined(lint)
D 4
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 4
I 4
	.asciz "%W% (Berkeley) %G%"
E 4
#endif /* SYSLIBC_SCCS and not lint */
E 3

#include "SYS.h"

D 2
SYSCALL(signal)
E 2
I 2
	.globl	__sigsim
ENTRY(signal)
	blbs	__sigsim,2f
	chmk	$SYS_signal
	bcs	1f
	ret
1:
	jmp	cerror

/*
 * Must simulate signal 
 */
2:
	movq	4(ap),-(sp)
	calls	$2,_signalsim
E 2
	ret
E 1
