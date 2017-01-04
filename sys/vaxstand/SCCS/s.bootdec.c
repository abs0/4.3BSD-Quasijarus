h63255
s 00043/00002/00082
d D 7.4 04/02/28 23:02:31 msokolov 4 3
c added ROM boot support code
e
s 00002/00002/00082
d D 7.3 04/02/28 22:25:45 msokolov 3 2
c move to using R5<31:28> instead of <15:12> for partition
e
s 00001/00002/00083
d D 7.2 04/02/26 18:30:46 msokolov 2 1
c fix ancient bug breaking NMAGIC images (only lseek to 0x400 for ZMAGIC)
e
s 00085/00000/00000
d D 7.1 04/02/07 18:58:16 msokolov 1 0
c first version, VMB only
e
u
U
t
T
I 1
/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

#include "param.h"
#include "inode.h"
#include "fs.h"
#include "vm.h"
#include "reboot.h"
#include <a.out.h>
#include "saio.h"
#include "../mdec/vmb.h"

char bootprog[] = "boot";
char vmbprog[] = "vmb.exe";
extern	unsigned bootdev, opendev;
D 4
extern	unsigned mode;
E 4
I 4
extern	unsigned mode, ROM_r3, ROM_r5;
E 4
extern	struct vmb_info *vmb_info;

/*
 * Boot program... arguments passed in r10 and r11
 * are passed through to the full boot program.
 */

main()
{
	register unsigned howto, devtype;	/* howto=r11, devtype=r10 */
	int io, unit, partition;
	register char *cp;

#ifdef lint
	howto = 0; devtype = 0; devtype = devtype;
#endif
D 4
	if (mode & VMB_BOOT) {
E 4
I 4
	if (mode & VMB_BOOT) {				/* boot via VMB */
E 4
		howto = vmb_info->rpbbas->rpb_bootr5;
D 3
		partition = (howto & 0xF000) >> 12;
		howto &= ~0xF000;
E 3
I 3
		partition = howto >> 28;
		howto &= 0x0FFFFFFF;
E 3
		unit = vmb_info->rpbbas->rpb_unit;
		bootdev = MAKEBOOTDEV(0, 0, 0, unit, partition);
		printf("loading %s\n", bootprog);
		io = open(bootprog, 0);
		if (io >= 0) {
			devtype = MAKEBOOTDEV(12, 0, 0, unit, partition);
			copyunix(howto, devtype, io);
		}
	}
I 4
	if (mode & ROM_BOOT) {				/* 750 style boot */
		howto = ROM_r5;
		partition = howto >> 28;
		howto &= 0x0FFFFFFF;
		unit = ROM_r3;
		bootdev = MAKEBOOTDEV(1, 0, 0, unit, partition);
		printf("loading %s\n", vmbprog);
		io = open(vmbprog, 0);
		if (io >= 0) {
			if (load_vmb(io))
				start_vmb();		/* go start it */
		}
	}
E 4
	_stop("boot failed\n");
}

/*ARGSUSED*/
copyunix(howto, devtype, io)
	register howto, devtype, io;	/* howto=r11, devtype=r10 */
{
	struct exec x;
	register int i;
	char *addr;

	i = read(io, (char *)&x, sizeof x);
	if (i != sizeof x || N_BADMAG(x))
		_stop("Bad format\n");
D 2
	if ((x.a_magic == ZMAGIC || x.a_magic == NMAGIC) &&
	    lseek(io, 0x400, L_SET) == -1)
E 2
I 2
	if (x.a_magic == ZMAGIC && lseek(io, 0x400, L_SET) == -1)
E 2
		goto shread;
	if (read(io, (char *)0, x.a_text) != x.a_text)
		goto shread;
	addr = (char *)x.a_text;
	if (x.a_magic == ZMAGIC || x.a_magic == NMAGIC)
		while ((int)addr & CLOFSET)
			*addr++ = 0;
	if (read(io, addr, x.a_data) != x.a_data)
		goto shread;
	addr += x.a_data;
	x.a_bss += 128*512;	/* slop */
	for (i = 0; i < x.a_bss; i++)
		*addr++ = 0;
	x.a_entry &= 0x7fffffff;
	(*((int (*)()) x.a_entry))(vmb_info);
	return;
shread:
	_stop("Short read\n");
I 4
}

/*
 * Functional Discription:
 *	For a ROM_BOOT mode, vmb.exe is loaded by this routine.
 *	It always assumes good memory and is loaded at 0x200.
 *
 * Inputs:
 *	io channel
 *
 * Outputs:
 *	0 = bad load
 *	1 = good load
 *
 */
load_vmb (io)
int     io;
{
	int     cnt, i;
	char   *addr = (char *) 0x200;

	for (i = 0;; i += 10240) {
		if ((cnt = read (io, addr + i, 10240)) < 0)
			return(0);	/* no good */
		if (!cnt)
			break;
	}
	return(1);
E 4
}
E 1
