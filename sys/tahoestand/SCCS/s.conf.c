h06034
s 00010/00005/00033
d D 1.7 88/06/29 17:36:55 bostic 7 6
c install approved copyright notice
e
s 00001/00002/00037
d D 1.6 88/03/04 16:58:56 bostic 6 5
c remove ud driver
e
s 00021/00072/00018
d D 1.5 88/03/04 16:23:17 bostic 5 4
c move dev routines into ../stand/dev.c
e
s 00002/00000/00088
d D 1.4 87/10/27 18:47:21 bostic 4 3
c add hd routines
e
s 00025/00005/00063
d D 1.3 86/12/18 23:52:26 karels 3 2
c updates
e
s 00014/00034/00054
d D 1.2 86/07/16 08:32:22 sam 2 1
c purge cruft; change disk names
e
s 00088/00000/00000
d D 1.1 86/01/12 18:04:57 sam 1 0
c date and time created 86/01/12 18:04:57 by sam
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
/*	conf.c	6.1	83/07/29	*/
E 5
I 5
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
 *
 *	%W% (Berkeley) %G%
 */
E 5

D 5
#include "../machine/pte.h"

E 5
#include "param.h"
#include "inode.h"
#include "fs.h"
D 5

E 5
D 2

E 2
#include "saio.h"

D 5
devread(io)
	register struct iob *io;
{
	int cc;
E 5
I 5
extern int	nullsys(), nodev(), noioctl();
E 5

D 5
	io->i_flgs |= F_RDDATA;
	io->i_error = 0;
	cc = (*devsw[io->i_ino.i_dev].dv_strategy)(io, READ);
	io->i_flgs &= ~F_TYPEMASK;
	return (cc);
}

devwrite(io)
	register struct iob *io;
{
	int cc;

	io->i_flgs |= F_WRDATA;
	io->i_error = 0;
	cc = (*devsw[io->i_ino.i_dev].dv_strategy)(io, WRITE);
	io->i_flgs &= ~F_TYPEMASK;
	return (cc);
}

devopen(io)
	register struct iob *io;
{

	(*devsw[io->i_ino.i_dev].dv_open)(io);
}

devclose(io)
	register struct iob *io;
{

	(*devsw[io->i_ino.i_dev].dv_close)(io);
}

I 3
devioctl(io, cmd, arg)
	register struct iob *io;
	int cmd;
	caddr_t arg;
{

	return ((*devsw[io->i_ino.i_dev].dv_ioctl)(io, cmd, arg));
}

E 3
D 2

E 2
/*ARGSUSED*/
D 2
nullsys(io)
	struct iob *io;
{
E 2
I 2
nullsys(io) struct iob *io; {}
nullopen(io) struct iob *io; { _stop("bad device type"); }
E 2

I 3
/*ARGSUSED*/
noioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{

	return (ECMD);
}

E 5
E 3
D 2
	;
}
E 2
I 2
D 6
int	udstrategy(), udopen();
E 6
int	vdstrategy(), vdopen();
I 4
int	hdstrategy(), hdopen();
E 4
int	cystrategy(), cyopen(), cyclose();
E 2

D 2

int	nullsys();


#define wchstrategy 	nullsys	
#define wchopen 	nullsys 
#define ctstrategy 	nullsys	
#define ctopen 		nullsys		
#define ctclose 	nullsys

int	udstrategy(),	udopen();
int	vdstrategy(),	vdopen();
int	cystrategy(),	cyopen(),	cyclose();

E 2
struct devsw devsw[] = {
D 2
	"fsd",  vdstrategy,	vdopen,		nullsys,
	"smd",  vdstrategy,	vdopen,		nullsys,
	"xfd",  vdstrategy,	vdopen,		nullsys,
	"fuj",  vdstrategy,	vdopen,		nullsys,
	"xsd",  vdstrategy,	vdopen,		nullsys,

	"xmd",	udstrategy,	udopen,		nullsys,
	"flp",	udstrategy,	udopen,		nullsys,
	"cyp",	cystrategy,	cyopen,		cyclose,
	"wch",	wchstrategy,	wchopen,	nullsys,
	"ctp",	ctstrategy,	ctopen,		ctclose,
	0,	0,		0,		0
E 2
I 2
D 3
	{ "ud",	udstrategy,	udopen,		nullsys },
	{ "dk",	vdstrategy,	vdopen,		nullsys },
E 3
I 3
D 5
	{ "ud",	udstrategy,	udopen,		nullsys,	noioctl },
	{ "dk",	vdstrategy,	vdopen,		nullsys,	noioctl },
I 4
	{ "hd",	hdstrategy,	hdopen,		nullsys,	noioctl },
E 5
I 5
D 6
	{ "ud",	udstrategy,	udopen,	nullsys, noioctl },  /* 0 = ud */
E 6
I 6
	{ "ud",	nodev,		nodev,	nullsys, noioctl },  /* 0 = ud */
E 6
	{ "dk",	vdstrategy,	vdopen,	nullsys, noioctl },  /* 1 = ht */
	{ "hd",	hdstrategy,	hdopen,	nullsys, noioctl },  /* 2 = hd */
E 5
E 4
E 3
#ifdef notdef
D 3
	{ "xp",	xpstrategy,	xpopen,		nullsys },
E 3
I 3
D 5
	{ "xp",	xpstrategy,	xpopen,		nullsys,	noioctl },
E 5
I 5
	{ "xp",	xpstrategy,	xpopen,	nullsys, noioctl },  /* 3 = xp */
E 5
E 3
#else
D 3
	{ "xp",	nullopen,	nullsys,	nullsys },
E 3
I 3
D 5
	{ "xp",	nullopen,	nullsys,	nullsys,	noioctl },
E 5
I 5
	{ "xp",	nodev,		nodev,	nullsys, noioctl },
E 5
E 3
#endif
D 3
	{ "cy",	cystrategy,	cyopen,		cyclose },
E 3
I 3
D 5
	{ "cy",	cystrategy,	cyopen,		cyclose,	noioctl },
E 5
I 5
	{ "cy",	cystrategy,	cyopen,	cyclose, noioctl },  /* 4 = cy */
E 5
E 3
	{ 0 }
E 2
};
I 3
D 5
int	ndevs = (sizeof(devsw) / sizeof(devsw[0]) - 1);
E 5
I 5
int	ndevs = (sizeof(devsw)/sizeof(devsw[0]));
E 5
E 3
D 2

E 2
E 1
