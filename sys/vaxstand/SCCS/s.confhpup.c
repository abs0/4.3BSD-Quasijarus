h49014
s 00010/00005/00025
d D 7.4 88/06/29 18:04:52 bostic 8 7
c install approved copyright notice
e
s 00013/00074/00017
d D 7.3 88/02/22 12:52:29 bostic 7 6
c move dev routines into machine independent file
e
s 00003/00001/00088
d D 7.2 87/09/17 09:34:07 karels 6 5
c updates
e
s 00001/00001/00088
d D 7.1 86/06/05 01:40:58 mckusick 5 4
c 4.3BSD release version
e
s 00007/00001/00082
d D 6.2 85/06/08 13:07:30 mckusick 4 3
c Add copyright
e
s 00000/00000/00083
d D 6.1 83/07/29 07:46:42 sam 3 2
c 4.2 distribution
e
s 00008/00006/00075
d D 4.2 83/02/16 21:49:53 sam 2 1
c read and write should return transfer count, not errno
e
s 00081/00000/00000
d D 4.1 83/02/04 08:46:41 sam 1 0
c date and time created 83/02/04 08:46:41 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
D 5
 * Copyright (c) 1982 Regents of the University of California.
E 5
I 5
D 7
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.
E 7
 *
I 7
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
 *
E 7
 *	%W% (Berkeley) %G%
 */
E 4

D 7
#include "../machine/pte.h"

#include "../h/param.h"
#include "../h/inode.h"
#include "../h/fs.h"
E 7
I 7
#include "param.h"
#include "fs.h"
#include "inode.h"
E 7
#include "saio.h"

D 7
devread(io)
	register struct iob *io;
{
D 2
	int error;
E 2
I 2
	int cc;
E 2

	io->i_flgs |= F_RDDATA;
D 2
	error = (*devsw[io->i_ino.i_dev].dv_strategy)(io, READ);
E 2
I 2
	io->i_error = 0;
	cc = (*devsw[io->i_ino.i_dev].dv_strategy)(io, READ);
E 2
	io->i_flgs &= ~F_TYPEMASK;
D 2
	return (error);
E 2
I 2
	return (cc);
E 2
}

devwrite(io)
	register struct iob *io;
{
D 2
	int error;
E 2
I 2
	int cc;
E 2

	io->i_flgs |= F_WRDATA;
D 2
	error = (*devsw[io->i_ino.i_dev].dv_strategy)(io, WRITE);
E 2
I 2
	io->i_error = 0;
	cc = (*devsw[io->i_ino.i_dev].dv_strategy)(io, WRITE);
E 2
	io->i_flgs &= ~F_TYPEMASK;
D 2
	return (error);
E 2
I 2
	return (cc);
E 2
}

devopen(io)
	register struct iob *io;
{

D 6
	(*devsw[io->i_ino.i_dev].dv_open)(io);
E 6
I 6
	return (*devsw[io->i_ino.i_dev].dv_open)(io);
E 6
}

devclose(io)
	register struct iob *io;
{

	(*devsw[io->i_ino.i_dev].dv_close)(io);
}

devioctl(io, cmd, arg)
	register struct iob *io;
	int cmd;
	caddr_t arg;
{

	return ((*devsw[io->i_ino.i_dev].dv_ioctl)(io, cmd, arg));
}

/*ARGSUSED*/
nullsys(io)
	struct iob *io;
{

	;
}

/*ARGSUSED*/
nullioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{

	return (ECMD);
}

int	nullsys(), nullioctl();
E 7
I 7
int	nullsys();
E 7
int	hpstrategy(), hpopen(), hpioctl();
int	upstrategy(), upopen(), upioctl();

struct devsw devsw[] = {
	{ "hp",	hpstrategy,	hpopen,		nullsys,	hpioctl },
	{ "up",	upstrategy,	upopen,		nullsys,	upioctl },
	{ 0, 0, 0, 0, 0 }
};
I 6

int	ndevs = (sizeof(devsw) / sizeof(devsw[0]) - 1);
E 6
E 1
