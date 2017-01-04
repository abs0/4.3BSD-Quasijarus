h50350
s 00010/00005/00016
d D 7.5 88/06/29 18:04:53 bostic 11 10
c install approved copyright notice
e
s 00010/00077/00011
d D 7.4 88/02/22 12:52:53 bostic 10 9
c move dev routines into machine independent file
e
s 00006/00007/00082
d D 7.3 88/01/28 20:54:30 karels 9 8
c uvax changes; fix devsw index in confxx; header updates
e
s 00007/00005/00082
d D 7.2 87/09/16 13:14:10 karels 8 7
c open returns a value, add ndevs
e
s 00001/00001/00086
d D 7.1 86/06/05 01:41:08 mckusick 7 6
c 4.3BSD release version
e
s 00007/00001/00080
d D 6.2 85/06/08 13:07:39 mckusick 6 5
c Add copyright
e
s 00000/00000/00081
d D 6.1 83/07/29 07:46:44 sam 5 4
c 4.2 distribution
e
s 00008/00006/00073
d D 4.4 83/02/16 23:44:58 sam 4 3
c uda50 and rl11 boot blocks; 730 crud
e
s 00036/00007/00043
d D 4.3 82/12/30 15:32:30 sam 3 2
c add ioctl's and errno
e
s 00002/00001/00048
d D 4.2 82/12/17 17:00:07 sam 2 1
c pte.h is now in ../machine/
e
s 00049/00000/00000
d D 4.1 82/07/19 21:24:18 kre 1 0
c date and time created 82/07/19 21:24:18 by kre
e
u
U
f i 
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
D 7
 * Copyright (c) 1982 Regents of the University of California.
E 7
I 7
D 10
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 10
 *
I 10
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
 *
E 10
 *	%W% (Berkeley) %G%
 */
E 6

I 2
D 8
#include "../machine/pte.h"
E 8
I 8
D 10
#include "machine/pte.h"
E 8

E 2
D 8
#include "../h/param.h"
#include "../h/inode.h"
D 2
#include "../h/pte.h"
E 2
#include "../h/fs.h"
E 8
I 8
#include "param.h"
#include "inode.h"
#include "fs.h"
E 8
#include "saio.h"

devread(io)
	register struct iob *io;
{
I 3
D 4
	int error;
E 4
I 4
	int cc;
E 4
E 3

D 3
	return( (*devsw[io->i_ino.i_dev].dv_strategy)(io, READ) );
E 3
I 3
	io->i_flgs |= F_RDDATA;
D 4
	error = (*devsw[io->i_ino.i_dev].dv_strategy)(io, READ);
E 4
I 4
	io->i_error = 0;
D 9
	cc = (*devsw[io->i_ino.i_dev].dv_strategy)(io, READ);
E 9
I 9
	cc = (*devsw[0].dv_strategy)(io, READ);
E 9
E 4
	io->i_flgs &= ~F_TYPEMASK;
D 4
	return (error);
E 4
I 4
	return (cc);
E 4
E 3
}

devwrite(io)
	register struct iob *io;
{
I 3
D 4
	int error;
E 4
I 4
	int cc;
E 4
E 3

D 3
	return( (*devsw[io->i_ino.i_dev].dv_strategy)(io, WRITE) );
E 3
I 3
	io->i_flgs |= F_WRDATA;
D 4
	error = (*devsw[io->i_ino.i_dev].dv_strategy)(io, WRITE);
E 4
I 4
	io->i_error = 0;
D 9
	cc = (*devsw[io->i_ino.i_dev].dv_strategy)(io, WRITE);
E 9
I 9
	cc = (*devsw[0].dv_strategy)(io, WRITE);
E 9
E 4
	io->i_flgs &= ~F_TYPEMASK;
D 4
	return (error);
E 4
I 4
	return (cc);
E 4
E 3
}

devopen(io)
	register struct iob *io;
{

D 8
	(*devsw[io->i_ino.i_dev].dv_open)(io);
E 8
I 8
D 9
	return (*devsw[io->i_ino.i_dev].dv_open)(io);
E 9
I 9
	return (*devsw[0].dv_open)(io);
E 9
E 8
}

devclose(io)
	register struct iob *io;
{

D 9
	(*devsw[io->i_ino.i_dev].dv_close)(io);
E 9
I 9
	(*devsw[0].dv_close)(io);
E 9
}

D 3
nullsys()
E 3
I 3
devioctl(io, cmd, arg)
	register struct iob *io;
	int cmd;
	caddr_t arg;
E 3
{

I 3
D 9
	return ((*devsw[io->i_ino.i_dev].dv_ioctl)(io, cmd, arg));
E 9
I 9
	return ((*devsw[0].dv_ioctl)(io, cmd, arg));
E 9
}

/*ARGSUSED*/
nullsys(io)
	struct iob *io;
{

E 3
	;
}

D 3
int	nullsys();
int	xxstrategy(), xxopen();
E 3
I 3
/*ARGSUSED*/
nullioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{
E 3

I 3
	return (ECMD);
}

int	nullsys(), nullioctl();
E 10
int	xxstrategy(), xxopen(), xxioctl();

E 3
struct devsw devsw[] = {
D 3
	"XX",	xxstrategy,	xxopen,		nullsys,
	0,0,0,0
E 3
I 3
D 10
	{ "XX",	xxstrategy,	xxopen,		nullsys,	xxioctl },
E 10
I 10
	{ "XX",	xxstrategy,	xxopen,		nullsys,	noioctl },
E 10
D 9
	{ 0, 0, 0, 0, 0 }
E 9
E 3
};
I 8

D 9
int	ndevs = (sizeof(devsw) / sizeof(devsw[0]) - 1);
E 9
I 9
int	ndevs = (sizeof(devsw) / sizeof(devsw[0]));
E 9
E 8
E 1
