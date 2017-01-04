h36224
s 00010/00006/00061
d D 7.5 88/06/27 18:43:06 bostic 14 13
c install approved copyright notice
e
s 00039/00014/00028
d D 7.4 88/03/08 10:19:16 karels 13 12
c new header, add adaptor, provide macros for splitting/making bootdev
e
s 00002/00003/00040
d D 7.3 87/03/27 17:50:10 karels 12 11
c add opt for readonly root, merge panic crap
e
s 00001/00000/00042
d D 7.2 86/11/25 16:41:21 sam 11 9
c kdb additions
e
s 00002/00001/00041
d R 7.2 86/11/25 16:40:53 sam 10 9
c kdb additions
e
s 00001/00001/00041
d D 7.1 86/06/04 23:27:14 mckusick 9 8
c 4.3BSD release version
e
s 00005/00002/00037
d D 6.4 86/03/13 20:43:27 karels 8 7
c add device magic field for kernel
e
s 00016/00000/00023
d D 6.3 86/03/12 11:12:08 karels 7 6
c add defines for boot's "dev_t" fields, flag to avoid moving root
c to load device
e
s 00007/00001/00016
d D 6.2 85/06/08 15:06:15 mckusick 6 5
c Add copyright
e
s 00000/00000/00017
d D 6.1 83/07/29 06:13:47 sam 5 4
c 4.2 distribution
e
s 00005/00004/00012
d D 4.3 82/10/31 16:28:47 root 4 3
c add RB_INITNAME
e
s 00001/00001/00015
d D 4.2 81/02/19 21:42:03 wnj 3 2
c %G%->%E%
e
s 00000/00000/00016
d D 4.1 80/11/09 17:02:39 bill 2 1
c stamp for 4bsd
e
s 00016/00000/00000
d D 3.1 80/10/08 22:36:22 bill 1 0
c date and time created 80/10/08 22:36:22 by bill
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%G%	*/
E 3
I 3
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
D 13
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
I 13
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
 * All rights reserved.
E 13
 *
I 13
 * Redistribution and use in source and binary forms are permitted
D 14
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 14
I 14
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
E 14
 *
E 13
 *	%W% (Berkeley) %G%
 */
E 6
E 3
D 14

E 14
I 13

E 13
/*
 * Arguments to reboot system call.
 * These are passed to boot program in r11,
 * and on to init.
 */
#define	RB_AUTOBOOT	0	/* flags for system auto-booting itself */

D 4
#define	RB_ASKNAME	1	/* ask for file name to reboot from */
#define	RB_SINGLE	2	/* reboot to single user only */
#define	RB_NOSYNC	4	/* dont sync before reboot */
#define	RB_HALT		8	/* don't reboot, just halt */
E 4
I 4
#define	RB_ASKNAME	0x01	/* ask for file name to reboot from */
#define	RB_SINGLE	0x02	/* reboot to single user only */
#define	RB_NOSYNC	0x04	/* dont sync before reboot */
#define	RB_HALT		0x08	/* don't reboot, just halt */
D 13
#define	RB_INITNAME	0x10	/* name given for /etc/init */
E 13
I 13
#define	RB_INITNAME	0x10	/* name given for /etc/init (unused) */
E 13
I 7
#define	RB_DFLTROOT	0x20	/* use compiled-in rootdev */
I 11
#define	RB_KDB		0x40	/* give control to kernel debugger */
E 11
E 7
E 4
D 12

#define	RB_PANIC	0	/* reboot due to panic */
#define	RB_BOOT		1	/* reboot due to boot() */
E 12
I 12
#define	RB_RDONLY	0x80	/* mount root fs read-only */
#define	RB_DUMP		0x100	/* dump kernel memory before reboot */
E 12
I 7

/*
 * Constants for converting boot-style device number to type,
 * adaptor (uba, mba, etc), unit number and partition number.
 * Type (== major device number) is in the low byte
D 8
 * for backward compatibility.
E 8
I 8
 * for backward compatibility.  Except for that of the "magic
 * number", each mask applies to the shifted value.
I 13
 * Format:
 *	 (4) (4) (4) (4)  (8)     (8)
 *	--------------------------------
 *	|MA | AD| CT| UN| PART  | TYPE |
 *	--------------------------------
E 13
E 8
 */
D 13
#define	B_ADAPTORSHIFT	24
D 8
#define	B_ADAPTORMASK	0xff
E 8
I 8
#define	B_ADAPTORMASK	0x0f
E 8
#define B_UNITSHIFT	16
#define B_UNITMASK	0xff
#define B_PARTITIONSHIFT 8
#define B_PARTITIONMASK	0xff
#define	B_TYPESHIFT	0
#define	B_TYPEMASK	0xff
I 8
#define	B_MAGICMASK	0xf0000000
#define	B_DEVMAGIC	0xa0000000
E 13
I 13
#define	B_ADAPTORSHIFT		24
#define	B_ADAPTORMASK		0x0f
#define	B_ADAPTOR(val)		(((val) >> B_ADAPTORSHIFT) & B_ADAPTORMASK)
#define B_CONTROLLERSHIFT	20
#define B_CONTROLLERMASK	0xf
#define	B_CONTROLLER(val)	(((val)>>B_CONTROLLERSHIFT) & B_CONTROLLERMASK)
#define B_UNITSHIFT		16
#define B_UNITMASK		0xf
#define	B_UNIT(val)		(((val) >> B_UNITSHIFT) & B_UNITMASK)
#define B_PARTITIONSHIFT	8
#define B_PARTITIONMASK		0xff
#define	B_PARTITION(val)	(((val) >> B_PARTITIONSHIFT) & B_PARTITIONMASK)
#define	B_TYPESHIFT		0
#define	B_TYPEMASK		0xff
#define	B_TYPE(val)		(((val) >> B_TYPESHIFT) & B_TYPEMASK)

#define	B_MAGICMASK	((u_long)0xf0000000)
#define	B_DEVMAGIC	((u_long)0xa0000000)

#define MAKEBOOTDEV(type, adaptor, controller, unit, partition) \
	(((type) << B_TYPESHIFT) | ((adaptor) << B_ADAPTORSHIFT) | \
	((controller) << B_CONTROLLERSHIFT) | ((unit) << B_UNITSHIFT) | \
	((partition) << B_PARTITIONSHIFT) | B_DEVMAGIC)
E 13
E 8
E 7
E 1
