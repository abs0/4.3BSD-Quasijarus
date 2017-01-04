h14300
s 00001/00002/00070
d D 7.5 04/02/26 18:30:45 msokolov 12 11
c fix ancient bug breaking NMAGIC images (only lseek to 0x400 for ZMAGIC)
e
s 00004/00005/00068
d D 7.4 88/02/04 12:10:53 bostic 11 10
c use #defines in lseek calls and for magic numbers
e
s 00005/00005/00068
d D 7.3 88/01/28 20:52:56 karels 10 9
c uvax changes; fix devsw index in confxx; header updates
e
s 00004/00015/00069
d D 7.2 87/09/16 13:13:40 karels 9 8
c just use opendev
e
s 00001/00001/00083
d D 7.1 86/06/05 01:40:29 mckusick 8 7
c 4.3BSD release version
e
s 00016/00003/00068
d D 6.4 86/03/12 11:15:06 karels 7 6
c new device encoding, sepcified in reboot.h; pass boot device to kernel;
c construct boot string from boot device and vice versa
e
s 00003/00004/00068
d D 6.3 85/11/08 19:15:09 karels 6 5
c so much cleaning: make skip-sector work in formatter, clean up
c ioctls for formatting options, make boothp small enough to fit,
c configure 9766's properly (sorry, 9300's!), don't use _exit from libc
e
s 00007/00001/00065
d D 6.2 85/06/08 13:06:53 mckusick 5 4
c Add copyright
e
s 00000/00000/00066
d D 6.1 83/07/29 07:46:35 sam 4 3
c 4.2 distribution
e
s 00001/00015/00065
d D 4.3 83/02/20 20:23:18 sam 3 2
c more general
e
s 00006/00000/00074
d D 4.2 83/02/16 23:44:51 sam 2 1
c uda50 and rl11 boot blocks; 730 crud
e
s 00074/00000/00000
d D 4.1 82/07/19 21:24:07 kre 1 0
c date and time created 82/07/19 21:24:07 by kre
e
u
U
f i 
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

D 10
#include "../h/param.h"
#include "../h/inode.h"
#include "../h/fs.h"
#include "../h/vm.h"
E 10
I 10
#include "param.h"
#include "inode.h"
#include "fs.h"
#include "vm.h"
#include "reboot.h"
E 10
#include <a.out.h>
#include "saio.h"
D 10
#include "../h/reboot.h"
E 10

D 3
#ifdef	BOOTRK
char bootprog[] = "hk(0,0)boot";
#endif
#ifdef	BOOTHP
char bootprog[] = "hp(0,0)boot";
#endif
#ifdef	BOOTUP
char bootprog[] = "up(0,0)boot";
#endif
I 2
#ifdef	BOOTRA
char bootprog[] = "ra(0,0)boot";
#endif
#ifdef	BOOTRL
char bootprog[] = "rl(0,0)boot";
#endif
E 3
I 3
D 7
char bootprog[] = "xx(0,0)boot";
E 7
I 7
D 9
char bootprog[20] = "xx(0,0)boot";
E 9
I 9
char bootprog[] = "boot";
extern	unsigned opendev;
E 9
E 7
E 3
E 2

/*
 * Boot program... arguments passed in r10 and r11
 * are passed through to the full boot program.
 */

main()
{
D 7
	register howto, devtype;	/* howto=r11, devtype=r10 */
	int io;
E 7
I 7
	register unsigned howto, devtype;	/* howto=r11, devtype=r10 */
	int io, unit, partition;
	register char *cp;
E 7

#ifdef lint
D 9
	howto = 0; devtype = 0;
E 9
I 9
	howto = 0; devtype = 0; devtype = devtype;
E 9
#endif
I 7
D 9
	unit = (devtype >> B_UNITSHIFT) & B_UNITMASK;
	unit += 8 * ((devtype >> B_ADAPTORSHIFT) & B_ADAPTORMASK);
	partition = (devtype >> B_PARTITIONSHIFT) & B_PARTITIONMASK;
	cp = bootprog + 3;
	if (unit >= 10)
		*cp++ = unit / 10 + '0';
	*cp++ = unit % 10 + '0';
	*cp++ = ',';
	if (partition >= 10)
		*cp++ = partition / 10 + '0';
	*cp++ = partition % 10 + '0';
	bcopy((caddr_t) ")boot", cp, 6);
E 9
E 7
D 6
	printf("loading %s", bootprog);
E 6
I 6
	printf("loading %s\n", bootprog);
E 6
	io = open(bootprog, 0);
	if (io >= 0)
D 9
		copyunix(howto, devtype, io);
E 9
I 9
		copyunix(howto, opendev, io);
E 9
D 6
	printf("boot failed");
	_exit();
E 6
I 6
	_stop("boot failed\n");
E 6
}

/*ARGSUSED*/
copyunix(howto, devtype, io)
	register howto, devtype, io;	/* howto=r11, devtype=r10 */
{
	struct exec x;
	register int i;
	char *addr;

	i = read(io, (char *)&x, sizeof x);
D 11
	if (i != sizeof x ||
	    (x.a_magic != 0407 && x.a_magic != 0413 && x.a_magic != 0410))
E 11
I 11
	if (i != sizeof x || N_BADMAG(x))
E 11
		_stop("Bad format\n");
D 11
	if ((x.a_magic == 0413 || x.a_magic == 0410) &&
	    lseek(io, 0x400, 0) == -1)
E 11
I 11
D 12
	if ((x.a_magic == ZMAGIC || x.a_magic == NMAGIC) &&
	    lseek(io, 0x400, L_SET) == -1)
E 12
I 12
	if (x.a_magic == ZMAGIC && lseek(io, 0x400, L_SET) == -1)
E 12
E 11
		goto shread;
	if (read(io, (char *)0, x.a_text) != x.a_text)
		goto shread;
	addr = (char *)x.a_text;
D 11
	if (x.a_magic == 0413 || x.a_magic == 0410)
E 11
I 11
	if (x.a_magic == ZMAGIC || x.a_magic == NMAGIC)
E 11
		while ((int)addr & CLOFSET)
			*addr++ = 0;
	if (read(io, addr, x.a_data) != x.a_data)
		goto shread;
	addr += x.a_data;
	x.a_bss += 128*512;	/* slop */
	for (i = 0; i < x.a_bss; i++)
		*addr++ = 0;
	x.a_entry &= 0x7fffffff;
	(*((int (*)()) x.a_entry))();
D 6
	_exit();
E 6
I 6
	return;
E 6
shread:
	_stop("Short read\n");
}
E 1
