h31620
s 00010/00005/00118
d D 7.4 88/06/29 18:19:11 bostic 4 3
c install approved copyright notice
e
s 00009/00004/00114
d D 7.3 88/05/27 15:27:23 karels 3 2
c additions to error repertoire
e
s 00036/00001/00082
d D 7.2 88/03/04 17:24:18 bostic 2 1
c print out open errors here, not in the drivers
e
s 00083/00000/00000
d D 7.1 88/02/20 13:49:32 bostic 1 0
c split out machine independent stuff from vaxstand/conf.c
e
u
U
t
T
I 1
/*
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
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
 *
 *	%W% (Berkeley) %G%
 */

#include "param.h"
#include "inode.h"
#include "fs.h"
#include "saio.h"

I 2
/*
 * NB: the value "io->i_ino.i_dev", used to offset the devsw[] array
 * in the routines below, is munged by the vaxstand Makefile to work
 * for certain boots.
 */

E 2
devread(io)
	register struct iob *io;
{
	int cc;

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
D 2
	return (*devsw[io->i_ino.i_dev].dv_open)(io);
E 2
I 2
	int ret;

	if (!(ret = (*devsw[io->i_ino.i_dev].dv_open)(io)))
		return (0);
	printf("%s(%d,%d,%d,%d): ", devsw[io->i_ino.i_dev].dv_name,
		io->i_adapt, io->i_ctlr, io->i_unit, io->i_part);
	switch(ret) {
I 3
	case EIO:
		break;		/* already reported */
E 3
	case EADAPT:
D 3
		printf("bad adaptor\n");
E 3
I 3
		printf("bad adaptor number\n");
E 3
		break;
	case ECTLR:
D 3
		printf("bad controller\n");
E 3
I 3
		printf("bad controller number\n");
E 3
		break;
	case EUNIT:
D 3
		printf("bad drive\n");
E 3
I 3
		printf("bad drive number\n");
E 3
		break;
	case EPART:
		printf("bad partition\n");
		break;
	case ERDLAB:
		printf("can't read disk label\n");
		break;
	case EUNLAB:
		printf("unlabeled\n");
		break;
	case ENXIO:
D 3
	default:
E 3
		printf("bad device specification\n");
I 3
		break;
	default:
		printf("unknown open error\n");
		break;
E 3
	}
	return (ret);
E 2
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
{}

/*ARGSUSED*/
nodev(io)
	struct iob *io;
{
	errno = EBADF;
}

/*ARGSUSED*/
noioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{
	return (ECMD);
}
E 1
