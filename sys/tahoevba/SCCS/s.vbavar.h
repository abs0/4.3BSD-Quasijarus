h25175
s 00010/00005/00178
d D 7.2 88/06/29 17:51:05 bostic 8 7
c install approved copyright notice
e
s 00013/00001/00170
d D 7.1 88/05/21 18:33:14 karels 7 6
c bring up to revision 7 for tahoe release
e
s 00007/00008/00164
d D 1.6 87/04/01 11:56:27 karels 6 5
c new stats, support for scatter-gather
e
s 00049/00000/00123
d D 1.5 87/03/10 18:12:22 karels 5 4
c working (I think!) with uncacheable intermediate buffers:
c add vb_buf struct and vbinit to set up, rm b_upte, remove (old)vbasetup
c and rename vbastart to vbasetup ala uba; use bcopy to kernel, double-
c mapping to user space, and purge user-space cache with dkeyinval
e
s 00001/00002/00122
d D 1.4 86/12/15 20:24:56 sam 4 3
c lint
e
s 00014/00014/00110
d D 1.3 86/01/20 23:47:44 sam 3 2
c make ui_flags a long so ace driver can get addr of dual ported memory
e
s 00012/00010/00112
d D 1.2 86/01/12 15:53:13 sam 2 1
c start of autoconfig
e
s 00122/00000/00000
d D 1.1 85/07/21 20:36:05 sam 1 0
c date and time created 85/07/21 20:36:05 by sam
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
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
 *	%W% (Berkeley) %G%
 */
E 7

/*
 * This file contains definitions related to the kernel structures
D 3
 * for dealing with the Versabus adapters.
E 3
I 3
 * for dealing with the VERSAbus adapters.
E 3
 *
I 2
D 3
 * Each Versabus has a vba_hd structure.
E 2
 * Each Versabus controller which is not a device has a vba_ctlr structure.
 * Each Versabus device has a vba_device structure.
E 3
I 3
 * Each VERSAbus has a vba_hd structure.
 * Each VERSAbus controller which is not a device has a vba_ctlr structure.
 * Each VERSAbus device has a vba_device structure.
E 3
 */

D 2

E 2
#ifndef LOCORE
/*
I 2
 * Per-vba structure.
 */
struct	vba_hd {
	int	vh_lastiv;		/* last interrupt vector assigned */
};

/*
E 2
 * Per-controller structure.
 * (E.g. one for each disk and tape controller, and other things
 * which use and release buffered data paths.)
 *
 * If a controller has devices attached, then there are
 * cross-referenced vba_drive structures.
D 3
 * This structure is the one which is queued in Versabus resource wait,
 * and saves the information about Versabus resources which are used.
E 3
I 3
 * This structure is the one which is queued in VERSAbus resource wait,
 * and saves the information about VERSAbus resources which are used.
E 3
 * The queue of devices waiting to transfer is also attached here.
 */
struct vba_ctlr {
	struct	vba_driver *um_driver;
	short	um_ctlr;	/* controller index in driver */
	short	um_vbanum;	/* the vba it is on */
	short	um_alive;	/* controller exists */
	int	(**um_intr)();	/* interrupt handler(s) */
	caddr_t	um_addr;	/* address of device in i/o space */
I 2
	struct	vba_hd *um_hd;
E 2
/* the driver saves the prototype command here for use in its go routine */
	int	um_cmd;		/* communication to dgo() */
D 3
	int	um_vbinfo;	/* save Versabus registers, etc */
E 3
I 3
	int	um_vbinfo;	/* save VERSAbus registers, etc */
E 3
	struct	buf um_tab;	/* queue of devices for this controller */
};

/*
 * Per ``device'' structure.
 * (A controller has devices or uses and releases buffered data paths).
 * (Everything else is a ``device''.)
 *
 * If a controller has many drives attached, then there will
 * be several vba_device structures associated with a single vba_ctlr
 * structure.
 *
 * This structure contains all the information necessary to run
D 3
 * a Versabus device.  It also contains information
 * for slaves of Versabus controllers as to which device on the slave
E 3
I 3
 * a VERSAbus device.  It also contains information
 * for slaves of VERSAbus controllers as to which device on the slave
E 3
 * this is.  A flags field here can also be given in the system specification
D 3
 * and is used to tell which vcx lines are hard wired or other device
E 3
I 3
 * and is used to tell which tty lines are hard wired or other device
E 3
 * specific parameters.
 */
struct vba_device {
	struct	vba_driver *ui_driver;
	short	ui_unit;	/* unit number on the system */
	short	ui_ctlr;	/* mass ctlr number; -1 if none */
	short	ui_vbanum;	/* the vba it is on */
	short	ui_slave;	/* slave on controller */
	int	(**ui_intr)();	/* interrupt handler(s) */
	caddr_t	ui_addr;	/* address of device in i/o space */
	short	ui_dk;		/* if init 1 set to number for iostat */
D 3
	short	ui_flags;	/* parameter from system specification */
E 3
I 3
	long	ui_flags;	/* parameter from system specification */
E 3
	short	ui_alive;	/* device exists */
	short	ui_type;	/* driver specific type information */
	caddr_t	ui_physaddr;	/* phys addr, for standalone (dump) code */
/* this is the forward link in a list of devices on a controller */
	struct	vba_device *ui_forw;
/* if the device is connected to a controller, this is the controller */
	struct	vba_ctlr *ui_mi;
I 2
	struct	vba_hd *ui_hd;
E 2
};
#endif

/*
 * Per-driver structure.
 *
D 3
 * Each Versabus driver defines entries for a set of routines
E 3
I 3
 * Each VERSAbus driver defines entries for a set of routines
E 3
 * as well as an array of types which are acceptable to it.
 * These are used at boot time by the configuration program.
 */
struct vba_driver {
	int	(*ud_probe)();		/* see if a driver is really there */
	int	(*ud_slave)();		/* see if a slave is there */
	int	(*ud_attach)();		/* setup driver for a slave */
	int	(*ud_dgo)();		/* fill csr/ba to start transfer */
	long	*ud_addr;		/* device csr addresses */
	char	*ud_dname;		/* name of a device */
	struct	vba_device **ud_dinfo;	/* backpointers to vbdinit structs */
	char	*ud_mname;		/* name of a controller */
	struct	vba_ctlr **ud_minfo;	/* backpointers to vbminit structs */
D 2
	short	ud_xclu;		/* want exclusive use of bdp's */
E 2
};

I 5
/*
 * Common state for Versabus driver I/O resources,
 * including memory for intermediate buffer and page map,
 * allocated by vbainit.
 */
struct vb_buf {
	/* these fields set up once by vbainit */
	int	vb_flags;		/* device parameters */
	struct	pte *vb_map;		/* private page entries */
	caddr_t	vb_utl;			/* virtual addresses mapped by vb_map */
	caddr_t	vb_rawbuf;		/* intermediate buffer */
	u_long	vb_physbuf;		/* phys addr of intermediate buffer */
I 6
	u_long	vb_bufsize;		/* intermediate buffer size */
E 6
	u_long	vb_maxphys;		/* physical address limit */
	/* remaining fields apply to current transfer: */
	int	vb_copy;		/* copy to/from intermediate buffer */
	int	vb_iskernel;		/* is to/from kernel address space */
};

/*
 * flags to vbainit
 */
#define	VB_32BIT	0x00		/* device uses 32-bit addressing */
#define	VB_24BIT	0x01		/* device uses 24-bit addressing */
#define	VB_20BIT	0x02		/* device uses 20-bit addressing */
#define	VB_SCATTER	0x04		/* device does scatter-gather */

/*
 * hardware addressing limits
 */
#define	VB_MAXADDR20	0x000fffff	/* highest addr for 20-bit */
#define	VB_MAXADDR24	0x007fffff	/* highest addr for 23/24-bit */
#define	VB_MAXADDR32	0x3effffff	/* highest addr for 32-bit */

/*
 * Statistics on vba operations.
 */
struct vbastat {
D 6
	u_long	kw_raw;			/* wrote from kernel DMA buffer */
	u_long	uw_raw;			/* wrote from user DMA buffer */
	u_long	kw_copy;		/* write copied from kernel */
	u_long	uw_copy;		/* write copied from user */
	u_long	kr_raw;			/* read, purged kernel DMA buffer */
	u_long	ur_raw;			/* invalidated key on user DMA buffer */
	u_long	kr_copy;		/* read copied to kernel */
	u_long	ur_copy;		/* read copied to user & inval'd key */
E 6
I 6
	u_long	k_raw;		/* to/from contiguous kernel DMA buffer */
	u_long	u_raw;		/* to/from contiguous user DMA buffer */
	u_long	k_copy;		/* copied to/from kernel */
	u_long	u_copy;		/* copied to/from user */
	u_long	k_sg;		/* scatter-gather to/from kernel */
	u_long	u_sg;		/* scatter-gather to/from user */
E 6
};

E 5
D 2
/*
 * Flags to VBA map/bdp allocation routines
 */
#define	VBA_NEEDBDP	1		/* transfer needs a bdp */
#define	VBA_CANTWAIT	2		/* don't block me */
#define	VBA_NEED16	3		/* need 16 bit addresses only */

#define	numvba  1				/* number of vba's */
E 2
#ifndef LOCORE
#ifdef KERNEL
/*
 * VBA related kernel variables
 */
I 2
int	numvba;					/* number of uba's */
struct	vba_hd vba_hd[];
I 5
struct	vbastat vbastat;
E 5
E 2

/*
 * Vbminit and vbdinit initialize the mass storage controller and
 * device tables specifying possible devices.
 */
extern	struct	vba_ctlr vbminit[];
extern	struct	vba_device vbdinit[];

/*
D 3
 * Versabus device address space is mapped by VMEMmap
 * into virtual address umem[][].
E 3
I 3
 * VERSAbus device address space is mapped by VMEMmap
 * into virtual address vmem[][].
E 3
 */
extern	struct pte VMEMmap[];	/* vba device addr pte's */
D 4
extern	char vmem[];		/* vba device addr space */

E 4
I 4
extern	caddr_t vmem;		/* vba device addr space */
I 5
u_long	vbasetup();
E 5
E 4
#endif KERNEL
#endif !LOCORE
E 1
