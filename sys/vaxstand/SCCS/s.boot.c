h23254
s 00003/00001/00217
d D 7.13 04/02/29 00:08:50 msokolov 38 37
c pass vmb_info along to the kernel
e
s 00004/00003/00214
d D 7.12 89/03/21 09:08:03 karels 37 36
c print "Boot" again if prog exits; put back "Bad format"
e
s 00002/00004/00215
d D 7.11 88/09/11 20:57:11 bostic 36 35
c bad format isn't useful; use a.out macro
e
s 00000/00001/00219
d D 7.10 88/03/04 13:33:20 bostic 35 34
c remove UNIX define
e
s 00002/00003/00218
d D 7.9 88/02/22 12:50:54 bostic 34 33
c retry is local
e
s 00001/00001/00220
d D 7.8 88/02/05 11:01:24 bostic 33 32
c put SCCS macro in place
e
s 00006/00006/00215
d D 7.7 88/02/05 11:00:16 bostic 32 31
c use L_SET for lseeks, #defines for magic numbers
e
s 00007/00003/00214
d D 7.6 88/01/28 20:52:54 karels 31 30
c uvax changes; fix devsw index in confxx; header updates
e
s 00011/00009/00206
d D 7.5 87/09/16 13:12:36 karels 30 29
c fix pcs code for new device specs
e
s 00005/00003/00210
d D 7.4 87/04/17 15:57:33 karels 29 28
c add esym (for kdb)
e
s 00035/00014/00178
d D 7.3 87/04/02 16:37:43 karels 28 27
c kdb (for sam)
e
s 00014/00066/00178
d D 7.2 87/02/21 11:41:28 karels 27 26
c pack labels; various cleanups: open returns failure instead of stopping
e
s 00001/00001/00243
d D 7.1 86/06/05 01:40:17 mckusick 26 25
c 4.3BSD release version
e
s 00001/00001/00243
d D 6.10 86/03/14 10:04:44 karels 25 24
c it used to be ok...
e
s 00001/00000/00243
d D 6.9 86/03/13 20:42:51 karels 24 23
c add device magic for kernel
e
s 00035/00023/00208
d D 6.8 86/03/12 11:14:59 karels 23 22
c new device encoding, sepcified in reboot.h; pass boot device to kernel;
c construct boot string from boot device and vice versa
e
s 00006/00002/00225
d D 6.7 86/03/08 13:34:03 karels 22 21
c unbreak loadpcs
e
s 00015/00007/00212
d D 6.6 85/12/19 14:02:43 karels 21 20
c that looked silly
e
s 00006/00006/00213
d D 6.5 85/11/08 19:15:03 karels 20 19
c so much cleaning: make skip-sector work in formatter, clean up
c ioctls for formatting options, make boothp small enough to fit,
c configure 9766's properly (sorry, 9300's!), don't use _exit from libc
e
s 00031/00006/00188
d D 6.4 85/08/08 16:15:02 bloom 19 18
c add support for booting from different drives and controllers using register
c values
e
s 00007/00001/00187
d D 6.3 85/06/08 13:06:40 mckusick 18 17
c Add copyright
e
s 00079/00001/00109
d D 6.2 84/09/18 09:10:25 tef 17 16
c Added code for loading patachable control store on 750's
e
s 00000/00000/00110
d D 6.1 83/07/29 07:46:32 sam 16 15
c 4.2 distribution
e
s 00003/00000/00107
d D 4.10 83/06/16 18:36:04 sam 15 14
c rl02
e
s 00002/00001/00105
d D 4.9 83/04/08 18:48:11 leres 14 13
c Added rb, just like in 4.1a...
e
s 00001/00002/00105
d D 4.8 82/07/15 21:30:53 root 13 12
c new boot scheme
e
s 00010/00007/00097
d D 4.7 82/03/07 19:12:52 mckusic 12 11
c changes to accomodate 407 and 413 files
e
s 00001/00000/00103
d D 4.6 81/12/01 09:36:30 sam 11 10
c added ut device
e
s 00006/00000/00097
d D 4.5 81/11/12 13:47:28 root 10 9
c added in uda and mt support
e
s 00007/00005/00090
d D 4.4 81/03/22 20:36:20 wnj 9 8
c fix howto
e
s 00006/00003/00089
d D 4.3 81/03/16 00:54:18 wnj 8 7
c fixes for generic functionality
e
s 00003/00005/00089
d D 4.2 81/03/15 20:45:46 wnj 7 5
c 
e
s 00001/00001/00093
d R 4.2 81/01/29 17:12:53 toy 6 5
c Made it always ask when compiled for a 750 system.  (MCT)
e
s 00000/00000/00094
d D 4.1 80/11/09 16:29:06 bill 5 4
c stamp for 4bsd
e
s 00001/00001/00093
d D 1.4 80/10/21 22:06:26 bill 4 3
c RB_SINGLE when tape
e
s 00004/00000/00090
d D 1.3 80/10/20 15:09:17 bill 3 2
c JUSTASK from tape
e
s 00043/00010/00047
d D 1.2 80/10/16 11:36:54 bill 2 1
c new boot with auto-reboot
e
s 00057/00000/00000
d D 1.1 80/06/28 10:42:45 bill 1 0
c date and time created 80/06/28 10:42:45 by bill
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%G% */
E 7
I 7
D 18
/*	%M%	%I%	%E%	*/
E 18
I 18
/*
D 26
 * Copyright (c) 1982 Regents of the University of California.
E 26
I 26
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 26
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
D 32
 *	%W% (Berkeley) %G%
E 32
I 32
D 33
 *	@(#)boot.c	7.6 (Berkeley) 1/28/88
E 33
I 33
 *	%W% (Berkeley) %G%
E 33
E 32
 */
E 18
E 7

D 28
#include "../h/param.h"
D 12
#include "../h/ino.h"
E 12
#include "../h/inode.h"
D 12
#include "../h/filsys.h"
#include "../h/dir.h"
E 12
I 12
#include "../h/fs.h"
E 12
#include "../h/vm.h"
E 28
I 28
#include "param.h"
#include "inode.h"
#include "fs.h"
#include "vm.h"
I 31
#include "reboot.h"

E 31
E 28
#include <a.out.h>
#include "saio.h"
I 38
#include "../mdec/vmb.h"
E 38
I 2
D 12
#include <sys/reboot.h>
E 12
I 12
D 28
#include "../h/reboot.h"
E 28
I 28
D 31
#include "reboot.h"
E 31
E 28
E 12
E 2

D 2
char line[100];
E 2
I 2
/*
 * Boot program... arguments passed in r10 and r11 determine
 * whether boot stops to ask for system name and which device
 * boot comes from.
 */
E 2

I 2
D 27
/* Types in r10 specifying major device */
char	devname[][2] = {
	'h','p',	/* 0 = hp */
	0,0,		/* 1 = ht */
	'u','p',	/* 2 = up */
D 7
	'r','k',	/* 3 = rk */
E 7
I 7
	'h','k',	/* 3 = hk */
I 10
	0,0,		/* 4 = sw */
	0,0,		/* 5 = tm */
	0,0,		/* 6 = ts */
	0,0,		/* 7 = mt */
	0,0,		/* 8 = tu */
	'r','a',	/* 9 = ra */
I 11
D 14
	'u', 't',	/* 10 = ut */
E 14
I 14
	'u','t',	/* 10 = ut */
	'r','b',	/* 11 = rb */
I 15
	0,0,		/* 12 = uu */
	0,0,		/* 13 = rx */
	'r','l',	/* 14 = rl */
E 15
E 14
E 11
E 10
E 7
};
I 23
#define	MAXTYPE	(sizeof(devname) / sizeof(devname[0]))
E 23

D 19
char line[100] = "xx(0,0)vmunix";
E 19
I 19
D 23
/*
 * constants for converting a "minor" device numbers to unit number
 * and partition number
 */
#define UNITSHIFT	16
#define UNITMASK	0x1ff
#define PARTITIONMASK	0x7
#define PARTITIONSHIFT	3
E 19

E 23
I 19
D 21
char line[100] = "xx(00,0)vmunix";
E 21
I 21
#define	UNIX	"vmunix"
E 27
I 27
D 35
#define	UNIX	"/vmunix"
E 35
E 27
char line[100];
E 21

E 19
I 9
D 34
int	retry = 0;
E 34
I 27
D 28
unsigned bootdev;
E 28
extern	unsigned opendev;
I 38
extern	struct vmb_info *vmb_info;
E 38
E 27

E 9
E 2
main()
{
D 2
	int i;
E 2
I 2
D 23
	register howto, devtype;	/* howto=r11, devtype=r10 */
D 9
	int io, retry;
E 9
I 9
	int io;
E 23
I 23
	register unsigned howto, devtype;	/* howto=r11, devtype=r10 */
D 27
	int io, i;
E 23
I 19
	register type, part, unit;
I 21
	register char *cp;
I 23
	long atol();
E 27
I 27
D 34
	int io, type;
E 34
I 34
D 37
	int io, retry, type;
E 37
I 37
	int io = 0, retry, type;
E 37
E 34
E 27
E 23
E 21
E 19
E 9
E 2

I 8
#ifdef lint
	howto = 0; devtype = 0;
#endif
I 27
D 28
	bootdev = devtype;
E 28
E 27
E 8
D 20
	printf("\nBoot\n");
E 20
I 20
D 21
	printf("Boot\n");
E 21
I 21
D 37
	printf("\nBoot\n");
E 37
E 21
D 22
	loadpcs();
E 22
E 20
I 3
#ifdef JUSTASK
D 4
	howto = RB_ASKNAME;
E 4
I 4
	howto = RB_ASKNAME|RB_SINGLE;
E 4
#else
I 19
D 23
	type = devtype & 0xff;
	unit = (int)((unsigned)devtype >> UNITSHIFT) & UNITMASK;
	part = unit & PARTITIONMASK;
	unit = unit >> PARTITIONSHIFT;
E 19
E 3
D 2
	do {
		printf(": "); gets(line);
		i = open(line,0);
	} while (i < 0);

	copyunix(i);
E 2
I 2
	if ((howto&RB_ASKNAME)==0) {
D 19
		if (devtype>=0 && devtype<sizeof(devname)/2
		    && devname[devtype][0]) {
			line[0] = devname[devtype][0];
			line[1] = devname[devtype][1];
E 19
I 19
		if (type >= 0 && type < sizeof(devname) / 2
		    && devname[type][0]) {
E 23
I 23
D 27
	type = (devtype >> B_TYPESHIFT) & B_TYPEMASK;
	unit = (devtype >> B_UNITSHIFT) & B_UNITMASK;
D 25
	unit += 8 * (devtype >> B_ADAPTORSHIFT) & B_ADAPTORMASK;
E 25
I 25
	unit += 8 * ((devtype >> B_ADAPTORSHIFT) & B_ADAPTORMASK);
E 25
	part = (devtype >> B_PARTITIONSHIFT) & B_PARTITIONMASK;
E 27
	if ((howto & RB_ASKNAME) == 0) {
D 27
		if (type >= 0 && type <= MAXTYPE && devname[type][0]) {
E 23
D 21
			line[0] = devname[type][0];
			line[1] = devname[type][1];
			line[3] = unit / 10 + '0';
			line[4] = unit % 10 + '0';
			line[6] = part + '0';
E 21
I 21
			cp = line;
			*cp++ = devname[type][0];
			*cp++ = devname[type][1];
			*cp++ = '(';
			if (unit >= 10)
				*cp++ = unit / 10 + '0';
			*cp++ = unit % 10 + '0';
			*cp++ = ',';
			*cp++ = part + '0';
			*cp++ = ')';
			strcpy(cp, UNIX);
E 21
E 19
D 7
		} else {
			printf("DID YOU MEAN ``BOOT ANY?'' (Bad devtype (r10=%x))\n", devtype);
E 7
I 7
		} else
E 27
I 27
		type = (devtype >> B_TYPESHIFT) & B_TYPEMASK;
D 31
		if ((unsigned)type < ndevs && devsw[type].dv_name[0])
E 31
I 31
		if ((unsigned)type < ndevs && devsw[type].dv_name)
E 31
			strcpy(line, UNIX);
		else
E 27
E 7
D 28
			howto = RB_SINGLE|RB_ASKNAME;
E 28
I 28
			howto |= RB_SINGLE|RB_ASKNAME;
E 28
D 7
		}
E 7
	}
I 3
#endif
E 3
D 9
	retry = 0;
E 9
D 34
	for (;;) {
E 34
I 34
	for (retry = 0;;) {
I 37
		if (io >= 0)
			printf("\nBoot\n");
E 37
E 34
		if (howto & RB_ASKNAME) {
			printf(": ");
			gets(line);
I 27
			if (line[0] == 0) {
				strcpy(line, UNIX);
				printf(": %s\n", line);
			}
E 27
		} else
			printf(": %s\n", line);
		io = open(line, 0);
D 17
		if (io >= 0)
E 17
I 17
		if (io >= 0) {
I 31
#ifdef VAX750
E 31
I 23
D 27
			if (howto & RB_ASKNAME) {
				/*
				 * Build up devtype register to pass on to
				 * booted program.
				 */ 
				cp = line;
				for (i = 0; i <= MAXTYPE; i++)
					if ((devname[i][0] == cp[0]) && 
					    (devname[i][1] == cp[1]))
					    	break;
				if (i <= MAXTYPE) {
					devtype = i << B_TYPESHIFT;
					cp += 3;
					i = *cp++ - '0';
					if (*cp >= '0' && *cp <= '9')
						i = i * 10 + *cp++ - '0';
					cp++;
					devtype |= ((i % 8) << B_UNITSHIFT);
					devtype |= ((i / 8) << B_ADAPTORSHIFT);
					devtype |= atol(cp) << B_PARTITIONSHIFT;
				}
			}
I 24
			devtype |= B_DEVMAGIC;
E 27
E 24
E 23
I 22
			loadpcs();
I 31
#endif
E 31
E 22
D 20
			loadpcs();
E 20
E 17
D 8
			copyunix(howto, io);
E 8
I 8
D 9
			copyunix(io);
E 9
I 9
D 23
			copyunix(howto, io);
E 23
I 23
D 27
			copyunix(howto, devtype, io);
E 27
I 27
			copyunix(howto, opendev, io);
E 27
E 23
I 20
			close(io);
D 28
			howto = RB_SINGLE|RB_ASKNAME;
E 28
I 28
			howto |= RB_SINGLE|RB_ASKNAME;
E 28
E 20
I 17
		}
E 17
E 9
E 8
		if (++retry > 2)
D 28
			howto = RB_SINGLE|RB_ASKNAME;
E 28
I 28
			howto |= RB_SINGLE|RB_ASKNAME;
E 28
	}
E 2
}

D 2
copyunix(io)
register io;
E 2
I 2
D 8
copyunix(howto, io)
	register howto, io;
E 8
I 8
D 9
copyunix(io)
	register io;
E 9
I 9
/*ARGSUSED*/
D 23
copyunix(howto, io)
	register howto, io;
E 23
I 23
D 29
copyunix(howto, devtype, io)
	register howto, devtype, io;	/* howto=r11, devtype=r10 */
E 29
I 29
copyunix(howto, devtype, aio)
	register howto, devtype;	/* howto=r11, devtype=r10 */
	int aio;
E 29
E 23
E 9
E 8
E 2
{
I 29
	register int esym;		/* must be r9 */
E 29
	struct exec x;
D 29
	register int i;
E 29
I 29
	register int io = aio, i;
E 29
	char *addr;

D 32
	i = read(io, (char *)&x, sizeof x);
D 12
	if (i != sizeof x || x.a_magic != 0410)
E 12
I 12
	if (i != sizeof x ||
D 28
	    (x.a_magic != 0407 && x.a_magic != 0413 && x.a_magic != 0410))
E 12
		_stop("Bad format\n");
E 28
I 28
	    (x.a_magic != 0407 && x.a_magic != 0413 && x.a_magic != 0410)) {
E 32
I 32
D 36
	i = read(io, (char *)&x, sizeof(x));
	if (i != sizeof(x) || (x.a_magic != OMAGIC && x.a_magic != ZMAGIC
	    && x.a_magic != NMAGIC)) {
E 32
		printf("Bad format\n");
E 36
I 36
	if (read(io, (char *)&x, sizeof(x)) != sizeof(x) || N_BADMAG(x)) {
D 37
		printf("bad magic #\n");
E 37
I 37
		printf("Bad format\n");
E 37
E 36
		return;
	}
E 28
	printf("%d", x.a_text);
I 12
D 13
	if ((x.a_magic == 0413 || x.a_magic == 0410) &&
	    lseek(io, 0x400, 0) == -1)
E 13
I 13
D 32
	if (x.a_magic == 0413 && lseek(io, 0x400, 0) == -1)
E 32
I 32
	if (x.a_magic == ZMAGIC && lseek(io, 0x400, L_SET) == -1)
E 32
E 13
		goto shread;
E 12
	if (read(io, (char *)0, x.a_text) != x.a_text)
		goto shread;
	addr = (char *)x.a_text;
D 12
	while ((int)addr & CLOFSET)
		*addr++ = 0;
E 12
I 12
D 32
	if (x.a_magic == 0413 || x.a_magic == 0410)
E 32
I 32
	if (x.a_magic == ZMAGIC || x.a_magic == NMAGIC)
E 32
		while ((int)addr & CLOFSET)
			*addr++ = 0;
E 12
	printf("+%d", x.a_data);
	if (read(io, addr, x.a_data) != x.a_data)
		goto shread;
	addr += x.a_data;
	printf("+%d", x.a_bss);
D 28
	x.a_bss += 128*512;	/* slop */
E 28
	for (i = 0; i < x.a_bss; i++)
		*addr++ = 0;
I 28
	if (howto & RB_KDB && x.a_syms) {
		*(int *)addr = x.a_syms;		/* symbol table size */
		addr += sizeof (int);
		printf("[+%d", x.a_syms);
		if (read(io, addr, x.a_syms) != x.a_syms)
			goto shread;
		addr += x.a_syms;
		if (read(io, addr, sizeof (int)) != sizeof (int))
			goto shread;
		i = *(int *)addr - sizeof (int);	/* string table size */
		addr += sizeof (int);
		printf("+%d]", i);
		if (read(io, addr, i) != i)
			goto shread;
		addr += i;
		esym = roundup((int)addr, sizeof (int));
		x.a_bss = 0;
	} else
		howto &= ~RB_KDB;
	for (i = 0; i < 128*512; i++)	/* slop */
		*addr++ = 0;
E 28
	x.a_entry &= 0x7fffffff;
	printf(" start 0x%x\n", x.a_entry);
D 38
	(*((int (*)()) x.a_entry))();
E 38
I 38
	(*((int (*)()) x.a_entry))(vmb_info);
E 38
D 20
	_exit();
E 20
I 20
	return;
E 20
shread:
D 28
	_stop("Short read\n");
E 28
I 28
	printf("Short read\n");
	return;
E 28
I 17
}

I 31
#ifdef VAX750
E 31
I 22
D 23
#ifndef SMALL
E 23
E 22
/* 750 Patchable Control Store magic */

#include "../vax/mtpr.h"
#include "../vax/cpu.h"
#define	PCS_BITCNT	0x2000		/* number of patchbits */
#define	PCS_MICRONUM	0x400		/* number of ucode locs */
#define	PCS_PATCHADDR	0xf00000	/* start addr of patchbits */
#define	PCS_PCSADDR	(PCS_PATCHADDR+0x8000)	/* start addr of pcs */
#define	PCS_PATCHBIT	(PCS_PATCHADDR+0xc000)	/* patchbits enable reg */
#define	PCS_ENABLE	0xfff00000	/* enable bits for pcs */

loadpcs()
{
	register int *ip;	/* known to be r11 below */
	register int i;		/* known to be r10 below */
	register int *jp;	/* known to be r9 below */
	register int j;
I 22
	static int pcsdone = 0;
E 22
D 20
	static int pcsdone = 0;
E 20
	union cpusid sid;
	char pcs[100];
I 19
D 30
	char *closeparen;
E 30
I 30
	char *cp;
E 30
D 31
	char *index();
E 31
E 19

	sid.cpusid = mfpr(SID);
D 20
	if (sid.cpuany.cp_type!=VAX_750 || sid.cpu750.cp_urev<95 || pcsdone)
E 20
I 20
D 22
	if (sid.cpuany.cp_type!=VAX_750 || sid.cpu750.cp_urev<95)
E 22
I 22
	if (sid.cpuany.cp_type!=VAX_750 || sid.cpu750.cp_urev<95 || pcsdone)
E 22
E 20
		return;
	printf("Updating 11/750 microcode: ");
D 19
	strncpy(pcs, line, strlen("xx(0,0)"));
E 19
I 19
D 30
	strncpy(pcs, line, 99);
	pcs[99] = 0;
	closeparen = index(pcs, ')');
	if (closeparen)
		*(++closeparen) = 0;
	else
		return;
E 19
	strcat(pcs, "pcs750.bin");
E 30
I 30
	for (cp = line; *cp; cp++)
		if (*cp == ')' || *cp == ':')
			break;
	if (*cp) {
		strncpy(pcs, line, 99);
		pcs[99] = 0;
		i = cp - line + 1;
	} else
		i = 0;
	strcpy(pcs + i, "pcs750.bin");
E 30
	i = open(pcs, 0);
	if (i < 0)
		return;
	/*
	 * We ask for more than we need to be sure we get only what we expect.
	 * After read:
	 *	locs 0 - 1023	packed patchbits
	 *	 1024 - 11264	packed microcode
	 */
	if (read(i, (char *)0, 23*512) != 22*512) {
		printf("Error reading %s\n", pcs);
		close(i);
		return;
	}
	close(i);

	/*
	 * Enable patchbit loading and load the bits one at a time.
	 */
	*((int *)PCS_PATCHBIT) = 1;
	ip = (int *)PCS_PATCHADDR;
	jp = (int *)0;
	for (i=0; i < PCS_BITCNT; i++) {
		asm("	extzv	r10,$1,(r9),(r11)+");
	}
	*((int *)PCS_PATCHBIT) = 0;

	/*
	 * Load PCS microcode 20 bits at a time.
	 */
	ip = (int *)PCS_PCSADDR;
	jp = (int *)1024;
	for (i=j=0; j < PCS_MICRONUM * 4; i+=20, j++) {
		asm("	extzv	r10,$20,(r9),(r11)+");
	}

	/*
	 * Enable PCS.
	 */
	i = *jp;		/* get 1st 20 bits of microcode again */
	i &= 0xfffff;
	i |= PCS_ENABLE;	/* reload these bits with PCS enable set */
	*((int *)PCS_PCSADDR) = i;

	sid.cpusid = mfpr(SID);
	printf("new rev level=%d\n", sid.cpu750.cp_urev);
I 22
	pcsdone = 1;
E 22
D 20
	pcsdone = 1;
E 20
E 17
}
I 31
#endif
E 31
I 22
D 23
#endif SMALL
E 23
E 22
E 1
