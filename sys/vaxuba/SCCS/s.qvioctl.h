h47590
s 00000/00000/00067
d D 1.5 04/12/08 07:48:10 msokolov 5 4
x 2
c ioctl debostication
e
s 00001/00000/00066
d D 1.4 88/06/03 17:54:34 marc 4 3
c tahoe release
e
s 00011/00008/00055
d D 1.3 88/05/27 20:32:30 marc 3 2
c add header, fix include files
e
s 00005/00005/00058
d D 1.2 87/12/22 12:40:23 bostic 2 1
c make ANSI C compatible
e
s 00063/00000/00000
d D 1.1 87/12/22 12:39:38 bostic 1 0
c date and time created 87/12/22 12:39:38 by bostic
e
u
U
t
T
I 1
/*
D 3
 *	@(#)qvioctl.h	1.7 (ULTRIX) 6/11/85
E 3
I 3
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
 *
I 3
 * 		%W%  Berkeley  %G%
I 4
 * 
E 4
 *	derived from: @(#)qvioctl.h	1.7 (ULTRIX) 6/11/85
 */
/*
E 3
 * Ioctl definitions for the qvss.
D 3
 *
 *	%W% (Berkeley) %G%
 *
E 3
 */
#ifdef KERNEL
D 3
#include "qevent.h"
#include "../h/ioctl.h"
E 3
I 3
#include "ioctl.h"
E 3
#include "qvreg.h"
I 3
#include "qevent.h"
E 3
#else
D 3
#include <qevent.h>
E 3
#include <sys/ioctl.h>
D 3
#include <qvreg.h>
E 3
I 3
#include <vaxuba/qvreg.h>
#include <vaxuba/qevent.h>
E 3
#endif

struct qv_kpcmd {
	char nbytes;		/* number of bytes in parameter */
	unsigned char cmd;	/* command to be sent, peripheral bit will */
				/* be forced by driver */
	unsigned char par[2];	/* bytes of parameters to be sent */
};
/*
 * qvss information block
 */

struct qv_info {
	short	mswitches;		/* current value of mouse buttons */
	vsCursor tablet;		/* current tablet position	*/
	short	tswitches;		/* current tablet buttons NI!	*/
	vsCursor cursor;		/* current cursor position	*/
	short	row;			/* screen row			*/
	short	col;			/* screen col			*/
	short	max_row;		/* max character row		*/
	short	max_col;		/* max character col		*/
	short	max_x;			/* max x position		*/
	short	max_y;			/* max y position		*/
	short	max_cur_x;		/* max cursor y position 	*/
	short	max_cur_y;		/* max cursor y position	*/
	char	*bitmap;		/* bit map position		*/
	short	*scanmap;		/* scanline map position	*/
	short	*cursorbits;		/* cursor bit position		*/
	struct	qvdevice *qvaddr;	/* virtual address of the csr	*/
	vsEvent *ibuff;			/* pointer to event queue	*/
	int 	iqsize;			/* may assume power of two 	*/
	int 	ihead;			/* atomic write			*/
	int 	itail;			/* atomic read			*/
	vsCursor mouse;			/* atomic read/write		*/
	vsBox	mbox;			/* atomic read/write		*/
	short	mthreshold;		/* mouse motion parameter	*/
	short	mscale;			/* mouse scale factor (if 
					   negative, then do square).	*/
};
typedef struct qv_info vsIoAddr;

D 2
#define QIOCGINFO 	_IOR(q, 1, struct qv_info)	/* get the info	 */
#define QIOCSMSTATE	_IOW(q, 2, vsCursor)		/* set mouse pos */
#define QIOCINIT	_IO(q, 4)			/* init screen   */
#define QIOCKPCMD	_IOW(q, 5, struct qv_kpcmd)	/* keybd. per. cmd */
#define QIOCADDR	_IOR(q, 6, struct qv_info *)	/* get address */
E 2
I 2
#define QIOCGINFO 	_IOR('q', 1, struct qv_info)	/* get the info	 */
#define QIOCSMSTATE	_IOW('q', 2, vsCursor)		/* set mouse pos */
#define QIOCINIT	_IO('q', 4)			/* init screen   */
#define QIOCKPCMD	_IOW('q', 5, struct qv_kpcmd)	/* keybd. per. cmd */
#define QIOCADDR	_IOR('q', 6, struct qv_info *)	/* get address */
E 2

E 1
