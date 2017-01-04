h25935
s 00010/00005/00065
d D 7.2 88/06/29 17:51:03 bostic 6 5
c install approved copyright notice
e
s 00013/00001/00057
d D 7.1 88/05/21 18:33:13 karels 5 4
c bring up to revision 7 for tahoe release
e
s 00000/00012/00058
d D 1.4 87/06/30 23:39:35 karels 4 3
c build the assumptions into the map
e
s 00006/00006/00064
d D 1.3 86/12/15 20:25:10 sam 3 2
c lint
e
s 00027/00003/00043
d D 1.2 86/12/08 19:06:59 sam 2 1
c add description and macros for VERSAbus segmentation; add 
c stuff for better autoconfiguration
e
s 00046/00000/00000
d D 1.1 86/01/21 11:10:53 sam 1 0
c date and time created 86/01/21 11:10:53 by sam
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * Parameters related to the VERSAbus i/o configuration.
 */

/*
 * VERSAbus i/o devices use either memory mapped interfaces
 * or mapped i/o register banks, or some of both.  Page tables
 * are allocated at boot time by each device driver, as needed.
 * VMEMmap is used to map a fixed size portion of the VERSAbus
 * i/o space, while VMEMmap1 maps dynamically defined portions
 * for devices which utilize shared i/o memory.  VBmap is used
 * for mapping kernel intermediate buffers for DMA devices which
 * are incapable of utilizing user virtual addresses or which
 * require page aligned i/o buffers.  The size of the VMEMmap1
 * VBmap tables must be large enough for the needs of all devices
 * in the system.
 */
extern	struct pte VMEMmap[], VMEMmap1[];
extern	caddr_t	vmem1, vmemend;
extern	struct pte VBmap[];
extern	caddr_t vbbase, vbend; 

I 2
/*
 * The following macros relate to the segmentation of the VERSAbus
 * i/o space.
 *
 * The VERSAbus adapter segments the i/o space (as seen by the cpu)
 * into three regions.  Cpu accesses to the upper 64Kb of the i/o space
 * generate VERSAbus cycles with a 16-bit address and a non-privileged
 * short i/o space address modifier.  Accesses to the next 1Mb - 64Kb
 * generate 24-bit addresses and a non-privileged standard address
 * modifier.  Accesses to the remainder of the 1Gb i/o space generate
 * 32-bit addresses with a non-privileged extended address modifier.
 * Beware that 32-bit addresses generated from this region always have
 * zero in the upper 2 bits; e.g. a reference to physical address fe000000
 * results in a VERSAbus address of 3e000000.
 */
D 3
#define	VBIO16BIT(a)	(0xfffe0000 <= ((unsigned)(a)))
#define	VBIO24BIT(a) \
    (0xff000000 <= ((unsigned)(a)) && ((unsigned)(a)) < 0xfffe0000)
#define	VBIO32BIT(a)	(((unsigned)(a)) < 0xff000000)
E 3
I 3
#define	VBIO16BIT(a)	((unsigned)0xfffe0000 <= ((unsigned)(a)))
#define	VBIO24BIT(a)	((unsigned)0xff000000 <= ((unsigned)(a)) && \
			 ((unsigned)(a)) < (unsigned)0xfffe0000)
#define	VBIO32BIT(a)	(((unsigned)(a)) < (unsigned)0xff000000)
E 3

E 2
/* 
 * The following constants define the fixed size map of the
 * VERSAbus i/o space.  The values should reflect the range
D 2
 * of i/o addresses used by all the controllers handled in
 * the system as specified in the ubminit structure in ioconf.c.
E 2
I 2
 * of i/o addresses used by all the controllers unprepared
 * to allocate and initialize their own page maps.
E 2
 */
#define VBIOBASE	0xfff00000	/* base of VERSAbus address space */
#define VBIOEND		0xffffee45	/* last address in mapped space */
D 2
/* number of entries in the system page pable for i/o space */
E 2
I 2
/* number of entries in the system page table for i/o space */
E 2
#define VBIOSIZE	btoc(VBIOEND-VBIOBASE)
I 2
/* is device in mapped region */
D 3
#define	VBIOMAPPED(a) \
    (VBIOBASE <= ((unsigned)(a)) && ((unsigned)(a)) <= VBIOEND) 
E 3
I 3
#define	VBIOMAPPED(a)	((unsigned)VBIOBASE <= ((unsigned)(a)) && \
			 ((unsigned)(a)) <= (unsigned)VBIOEND) 
E 3
#define	vboff(addr)	((int)(((caddr_t)(addr)) - VBIOBASE))
E 2
D 4

/*
 * Page table map sizes.
 *
 * Current VBmap allotments are:
 *	4 vd controllers	32+1 pte's
 *	2 cy controllers	32+1 pte's
 * Current VBMEMmap allotments are:
 *	2 ace controllers	32+1 pte's
 */
#define	VBPTSIZE	(((4*(32+1))+2*(32+1)+3) &~ 3)
#define	VBMEMSIZE	((2*(32+1)+3) &~ 3)
E 4
E 1
