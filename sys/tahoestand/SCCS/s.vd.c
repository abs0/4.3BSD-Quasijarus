h07002
s 00001/00000/00413
d D 7.10 88/06/14 18:47:59 bostic 10 9
c support 2361 super eagles; From: muller%sdcc7@ucsd.edu (Keith Muller)
e
s 00033/00037/00380
d D 7.9 88/05/24 13:33:48 bostic 9 8
c change to dev(a,b,c,d) format
e
s 00048/00030/00369
d D 7.8 87/11/12 09:40:48 karels 8 7
c esdi support, cleanups
e
s 00014/00012/00385
d D 7.7 87/04/06 18:27:22 karels 7 6
c fix compat code
e
s 00298/00290/00099
d D 7.6 87/02/18 22:03:22 sam 6 5
c rewrite; disk label support
e
s 00031/00049/00358
d D 7.5 86/12/19 08:41:21 sam 5 4
c make it look more like the system version; controller addresses 
c are now physical addresses (were offsets from VBIOBASE before)
e
s 00013/00006/00394
d D 7.4 86/11/04 21:28:01 karels 4 3
c sundry fixes
e
s 00188/00253/00212
d D 7.3 86/07/16 08:35:04 sam 3 2
c structure renames and merges; purge cruft
e
s 00045/00012/00420
d D 7.2 86/01/21 11:38:22 sam 2 1
c make things compile again after changing vdreg.h and creatng vbparam.h
e
s 00432/00000/00000
d D 7.1 86/01/12 18:05:04 sam 1 0
c date and time created 86/01/12 18:05:04 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/
I 3

E 3
/*
D 3
** Stand alone driver for the VDDC controller 
**	TAHOE Version, Oct 1983.
**
*/
E 3
I 3
D 6
 * Stand alone driver for the VDDC controller 
 *	TAHOE Version, Oct 1983.
E 6
I 6
 * Stand alone driver for the VDDC/SMDE controller 
E 6
 */
E 3
#include "../machine/mtpr.h"

#include "param.h"
#include "inode.h"
#include "fs.h"
I 7
#include "buf.h"
E 7
D 6
#define VDGENDATA 1
E 6
I 6
#include "disklabel.h"
#include "saio.h"

E 6
D 2
#include "../tahoevba/vddcreg.h"
E 2
I 2
#include "../tahoevba/vdreg.h"
E 2
D 6
#undef	VDGENDATA
E 6
I 2
#include "../tahoevba/vbaparam.h"
E 2
D 6
#include "saio.h"
E 6

D 6
#define NVD		4			/* Max number of controllers */
D 3

#define TRUE		1
#define	FALSE		0
E 3
#define VDUNIT(x)	(minor(x) & 0x3)
#define VDCTLR(x)	(minor(x) >> 2)
E 6
I 6
#define	COMPAT_42	1
E 6

D 3
/*
**	MDCB
*/

E 3
D 6
fmt_mdcb	mdcb;
D 3

/*
**	DCB
*/

E 3
fmt_dcb		dcb;
E 6
I 6
D 9
#define NVD		4
E 9
I 9
#define NVD		4		/* controllers */
E 9
#define	NDRIVE		8		/* drives per controller */
D 9
#define VDSLAVE(x)	((x) % NDRIVE)
#define VDCTLR(x)	((x) / NDRIVE)
E 9
E 6

D 6
/*
D 3
** Unit specific information.
*/

struct {
E 3
I 3
 * Drive specific information.
 */
struct dkinfo {
E 3
	char	configured;
	fs_tab	info;
D 3
}unit_info[NVD][16];
E 3
I 3
} dkinfo[NVD][16];
E 6
I 6
#define	VDADDR(ctlr)	((struct vddevice *)vdaddrs[ctlr])
long	vdaddrs[NVD] = { 0xffff2000, 0xffff2100, 0xffff2200, 0xffff2300 };
E 6
E 3

D 6
/*
D 3
** Controller specific information.
*/
E 3
I 3
 * Controller specific information.
 */
struct vdinfo {
	u_short	vd_flags;
#define	VDF_INIT	0x1		/* controller initialized */
#define	VDF_BUSY	0x2		/* controller running */
	u_short	vd_type;		/* smd or smde */
	char	*vd_name;
} vdinfo[NVD];
E 6
I 6
u_char	vdinit[NVD];			/* controller initialized */
u_char	vdtype[NVD];			/* controller type */
D 9
u_char	dkconfigured[NVD*NDRIVE];	/* unit configured */
E 9
I 9
u_char	dkconfigured[NVD][NDRIVE];	/* unit configured */
E 9
D 8
struct	disklabel dklabel[NVD*NDRIVE];	/* pack label */
E 8
I 8
u_char	dkflags[NVD][NDRIVE];		/* unit flags */
E 8
E 6
E 3

D 3
struct {
	unsigned char	ctlr_type;
	char		*ctlr_name;
	unsigned char	initialized;
	unsigned char	ctlr_started;
} ctlr_info[NVD];

E 3
D 6
static char	junk[1024];
E 6
I 6
D 8
struct	mdcb mdcb;
struct	dcb dcb;
char	lbuf[DEV_BSIZE];
E 8
I 8
D 9
static	struct disklabel dklabel[NVD*NDRIVE];	/* pack label */
E 9
I 9
static	struct disklabel dklabel[NVD][NDRIVE];	/* pack label */
E 9
static	struct mdcb mdcb;
static	struct dcb dcb;
static	char lbuf[DEV_BSIZE];
E 8
E 6

D 2

E 2
I 2
D 5
#define	VDADDR(ctlr)	((cdr *)(vddcaddr[(ctlr)]+VBIOBASE))
E 5
I 5
D 6
#define	VDADDR(ctlr)	((cdr *)vddcaddr[(ctlr)])
E 5
E 2
D 3
/*
**
*/
E 3

E 6
vdopen(io)
D 3
register struct iob	*io;
E 3
I 3
	register struct iob *io;
E 3
{
D 3
	register int	ctlr = VDCTLR(io->i_unit);
	register int	unit = VDUNIT(io->i_unit);
	register int	i, j;
E 3
I 3
D 6
	register int ctlr = VDCTLR(io->i_unit), unit = VDUNIT(io->i_unit);
	struct vdinfo *vd;
	register int i, j;
E 6
I 6
D 9
	register int ctlr = VDCTLR(io->i_unit);
E 9
I 9
	register int ctlr = io->i_ctlr;
E 9
	register struct dkinfo *dk;
D 7
	register struct disklabel *lp;
E 7
I 7
	register struct disklabel *lp, *dlp;
E 7
	int error;
E 6
E 3

D 6
	/* Make sure controller number is in range */
E 6
D 3
	if(ctlr >= NVD) {
		printf("vd%d: Unit number can't be greater than %x!\n",
		    io->i_unit, (NVD * 4) - 1);
E 3
I 3
D 9
	if (ctlr >= NVD) {
D 6
		printf(
		    "dk%d: invalid controller (only configured for %d vd's)\n",
		    io->i_unit, NVD);
E 3
		_stop("");
E 6
I 6
		printf("invalid controller number\n");
		return (ENXIO);
E 6
	}
E 9
I 9
	if ((u_int)io->i_adapt)
		return (EADAPT);
	if ((u_int)ctlr >= NVD)
		return (ECTLR);
E 9
D 6
	/* check file system for validity */
D 3
	if((io->i_boff < 0) || (io->i_boff > 5)) {
		printf("vd%d: File system #%d, should be less than #6.\n",
E 3
I 3
D 4
	if ((unsigned)io->i_boff > 5) {
E 4
I 4
D 5
	if ((unsigned)io->i_boff > 8) {
E 5
I 5
	if ((unsigned)io->i_boff >= 8) {
E 5
E 4
		printf("dk%d: invalid partition number (%d)\n",
E 3
		    io->i_unit, io->i_boff);
		_stop("");
E 6
I 6
	if (!vdinit[ctlr] && (error = vdreset_ctlr(ctlr, io->i_unit)))
		return (error);
D 9
	lp = &dklabel[io->i_unit];
	if (!dkconfigured[io->i_unit]) {
E 9
I 9
	lp = &dklabel[io->i_ctlr][io->i_unit];
	if (!dkconfigured[io->i_ctlr][io->i_unit]) {
E 9
		struct iob tio;

		/*
		 * Read in the pack label.
		 */
D 8
		lp->d_secsize = 512;
		lp->d_nsectors = 32;
E 8
I 8
		lp->d_secsize = 1024;
		lp->d_nsectors = 72;
E 8
		lp->d_ntracks = 24;
		lp->d_ncylinders = 711;
D 8
		lp->d_secpercyl = 32*24;
E 8
I 8
		lp->d_secpercyl = 72*24;
E 8
		if (!vdreset_drive(io))
			return (ENXIO);
		tio = *io;
		tio.i_bn = LABELSECTOR;
		tio.i_ma = lbuf;
		tio.i_cc = DEV_BSIZE;
		tio.i_flgs |= F_RDDATA;
D 9
		if (vdstrategy(&tio, READ) != DEV_BSIZE) {
D 8
			printf("can't read disk label");
E 8
I 8
			printf("dk%d: can't read disk label\n", io->i_unit);
E 8
			return (EIO);
		}
E 9
I 9
		if (vdstrategy(&tio, READ) != DEV_BSIZE)
			return (ERDLAB);
E 9
D 7
		*lp = *(struct disklabel *)(lbuf + LABELOFFSET);
		if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC) {
			printf("dk%d: unlabeled\n", io->i_unit);
E 7
I 7
		dlp = (struct disklabel *)(lbuf + LABELOFFSET);
D 9
		if (dlp->d_magic != DISKMAGIC || dlp->d_magic2 != DISKMAGIC) {
E 9
I 9
		if (dlp->d_magic != DISKMAGIC || dlp->d_magic2 != DISKMAGIC)
E 9
E 7
#ifdef COMPAT_42
I 9
		{
			printf("dk%d: unlabeled\n", io->i_unit);
E 9
			if (error = vdmaptype(io))
				return (error);
I 9
		}
E 9
#else
I 7
D 9
			printf("dk%d: unlabeled\n", io->i_unit);
E 7
			return (ENXIO);
E 9
I 9
			return (EUNLAB);
E 9
#endif
D 7
		}
E 7
I 7
D 8
		} else
E 8
I 8
D 9
		} else {
E 9
I 9
		else {
E 9
E 8
			*lp = *dlp;
E 7
D 8
		if (!vdreset_drive(io))
			return (ENXIO);
E 8
I 8
			if (!vdreset_drive(io))
				return (ENXIO);
		}
E 8
D 9
		dkconfigured[io->i_unit] = 1;
E 9
I 9
		dkconfigured[io->i_ctlr][io->i_unit] = 1;
E 9
E 6
	}
D 3
	if(!ctlr_info[ctlr].initialized) {
E 3
I 3
D 6
	vd = &vdinfo[ctlr];
	if ((vd->vd_flags&VDF_INIT) == 0) {
E 3
		vdinit(io);	/* initialize controller/drive */
D 3
		ctlr_info[ctlr].initialized = TRUE;
		for(i=0; i<NVD; i++)
			for(j=0; j<16; j++)
				unit_info[i][j].configured = FALSE;
E 3
I 3
		vd->vd_flags |= VDF_INIT;
		for (j = 0; j < 16; j++)
			dkinfo[ctlr][j].configured = 0;
E 6
I 6
D 9
	if (io->i_boff < 0 || io->i_boff >= lp->d_npartitions ||
	    lp->d_partitions[io->i_boff].p_size == 0) {
D 7
		printf("dk bad minor");
E 7
I 7
		printf("dk%d: bad minor\n", io->i_unit);
E 7
		return (EUNIT);
E 6
E 3
	}
E 9
I 9
	if (io->i_part < 0 || io->i_part >= lp->d_npartitions ||
	    lp->d_partitions[io->i_part].p_size == 0)
		return (EPART);
E 9
D 3
	if(!unit_info[ctlr][unit].configured) {
E 3
I 3
D 6
	if (!dkinfo[ctlr][unit].configured) {
E 3
		vdconfigure_drive(io);
D 3
		unit_info[ctlr][unit].configured = TRUE;
E 3
I 3
		dkinfo[ctlr][unit].configured = 1;
E 3
	}
D 3
	io->i_boff = unit_info[ctlr][unit].info.partition[io->i_boff].par_start;
E 3
I 3
	io->i_boff = dkinfo[ctlr][unit].info.partition[io->i_boff].par_start;
E 6
I 6
	io->i_boff =
D 9
	    (lp->d_partitions[io->i_boff].p_offset * lp->d_secsize) / DEV_BSIZE;
E 9
I 9
	    (lp->d_partitions[io->i_part].p_offset * lp->d_secsize) / DEV_BSIZE;
E 9
	return (0);
E 6
E 3
}

D 3

/*
**
*/

E 3
D 6
vdinit(io)
D 3
register struct iob	*io;
E 3
I 3
	register struct iob *io;
E 6
I 6
/*
 * Reset and initialize the controller.
 */
vdreset_ctlr(ctlr, unit)
	register int ctlr, unit;
E 6
E 3
{
D 3
	register int	ctlr = VDCTLR(io->i_unit);
	register int	unit = VDUNIT(io->i_unit);
D 2
	register cdr	*ctlr_addr = (cdr *)(vddcaddr[ctlr]+IOBASE);
E 2
I 2
	register cdr	*ctlr_addr = VDADDR(ctlr);
E 2
	register char	*ctlr_type;
E 3
I 3
D 6
	register int ctlr = VDCTLR(io->i_unit), unit = VDUNIT(io->i_unit);
	register cdr *ctlr_addr = VDADDR(ctlr);
	register struct vdinfo *vd = &vdinfo[ctlr];
E 6
I 6
	register int i;
	register struct vddevice *vdaddr = VDADDR(ctlr);
E 6
E 3

D 6
	/* Check to see if controller is really there */
D 3
	if(badaddr(ctlr_addr, 2)) {
		printf("vd%d: Controller %d is non-existant!\n",
		    io->i_unit, ctlr);
E 3
I 3
	if (badaddr(ctlr_addr, 2)) {
		printf("dk%d: vd%d csr doesn't respond\n", io->i_unit, ctlr);
E 3
		_stop("");
E 6
I 6
	if (badaddr(vdaddr, 2)) {
		printf("vd%d: %x: invalid csr\n", ctlr, vdaddr);
		return (ENXIO);
E 6
	}
D 6
	/* Probe further to find what kind of controller it is */
	ctlr_addr->cdr_reset = 0xffffffff;
E 6
I 6
	/* probe further to find what kind of controller it is */
	vdaddr->vdreset = 0xffffffff;
E 6
	DELAY(1000000);
D 3
	/* Probe further to find what kind of controller it is */
	if(ctlr_addr->cdr_reset != 0xffffffff) {
		ctlr_info[ctlr].ctlr_type = SMDCTLR;
		ctlr_info[ctlr].ctlr_name = "SMD";
E 3
I 3
D 6
	if (ctlr_addr->cdr_reset != 0xffffffff) {
		vd->vd_type = SMDCTLR;
		vd->vd_name = "smd";
E 6
I 6
	if (vdaddr->vdreset != 0xffffffff) {
		vdtype[ctlr] = VDTYPE_VDDC;
E 6
E 3
		DELAY(1000000);
D 3
	}
	else {
		ctlr_info[ctlr].ctlr_type = SMD_ECTLR;
		ctlr_info[ctlr].ctlr_name = "SMD/E";
E 3
I 3
	} else {
D 6
		vd->vd_type = SMD_ECTLR;
		vd->vd_name = "smde";
E 3
		ctlr_addr->cdr_reserved = 0x0;
E 6
I 6
		vdtype[ctlr] = VDTYPE_SMDE;
		vdaddr->vdrstclr = 0;
E 6
		DELAY(3000000);
I 6
		vdaddr->vdcsr =  0;
		vdaddr->vdtcf_mdcb = AM_ENPDA;
		vdaddr->vdtcf_dcb = AM_ENPDA;
		vdaddr->vdtcf_trail = AM_ENPDA;
		vdaddr->vdtcf_data = AM_ENPDA;
		vdaddr->vdccf = CCF_SEN | CCF_DER | CCF_STS |
		    XMD_32BIT | BSZ_16WRD |
		    CCF_ENP | CCF_EPE | CCF_EDE | CCF_ECE | CCF_ERR;
E 6
	}
D 3
	if(ctlr_info[ctlr].ctlr_type == SMD_ECTLR) {
E 3
I 3
D 6
	if (vd->vd_type == SMD_ECTLR) {
E 3
		ctlr_addr->cdr_csr =  0;
		ctlr_addr->mdcb_tcf = AM_ENPDA;
		ctlr_addr->dcb_tcf = AM_ENPDA;
		ctlr_addr->trail_tcf = AM_ENPDA;
		ctlr_addr->data_tcf = AM_ENPDA;
		ctlr_addr->cdr_ccf = CCF_STS | XMD_32BIT | BSZ_16WRD |
		    CCF_ENP | CCF_EPE /* | CCF_EDE */ | CCF_ECE | CCF_ERR;
E 6
I 6
	if (!vdcmd(ctlr, 0, VDOP_INIT, 10) ||
	    !vdcmd(ctlr, 0, VDOP_DIAG, 10)) {
		vderror(unit, dcb.opcode == VDOP_INIT ? "init" : "diag", &dcb);
		return (EIO);
E 6
	}
D 3
	if(vdaccess_with_no_trailer(io, INIT, 8) & HRDERR) {
		vdprint_error(io->i_unit, "Initialization error",
E 3
I 3
D 5
	if (vdaccess_with_no_trailer(io, INIT, 8) & HRDERR) {
E 5
I 5
D 6
	if (vdnotrailer(io, INIT, 8) & HRDERR) {
E 5
		vdprint_error(io->i_unit, "init error",
E 3
D 5
		    dcb.operrsta,dcb.err_code);
E 5
I 5
		    dcb.operrsta, dcb.err_code);
E 5
		_stop("");
	}
D 3
	if(vdaccess_with_no_trailer(io, DIAG, 8) & HRDERR) {
		vdprint_error(io->i_unit, "Diagnostic error",
E 3
I 3
D 5
	if (vdaccess_with_no_trailer(io, DIAG, 8) & HRDERR) {
E 5
I 5
	if (vdnotrailer(io, DIAG, 8) & HRDERR) {
E 5
		vdprint_error(io->i_unit, "diagnostic error",
E 3
		    dcb.operrsta, dcb.err_code);
		_stop("");
	}
E 6
I 6
	vdinit[ctlr] = 1;
D 9
	for (i = unit = ctlr * NDRIVE; i < unit + NDRIVE; i++)
		dkconfigured[i] = 0;
E 9
I 9
	for (i = NDRIVE - 1; i >= 0; i--)
		dkconfigured[ctlr][i] = 0;
E 9
	return (0);
E 6
}

D 3

/*
**
*/

E 3
D 6
vdconfigure_drive(io)
E 6
I 6
/*
 * Reset and configure a drive's parameters.
 */
vdreset_drive(io)
E 6
D 3
register struct iob	*io;
E 3
I 3
	register struct iob *io;
E 3
{
D 3
	register int	ctlr = VDCTLR(io->i_unit);
	register int	unit = VDUNIT(io->i_unit);
E 3
I 3
D 6
	register int ctlr = VDCTLR(io->i_unit), unit = VDUNIT(io->i_unit);
E 3
	register fs_tab	*file_sys;
D 3
	dskadr		daddr;
	register int	i;
E 3
I 3
	register struct dkinfo *dk = &dkinfo[ctlr][unit];
	dskadr daddr;
	register int i;
E 6
I 6
D 9
	register int ctlr = VDCTLR(io->i_unit), slave = VDSLAVE(io->i_unit);
D 8
	register struct disklabel *lp;
E 8
I 8
	register struct disklabel *lp = &dklabel[io->i_unit];
E 9
I 9
	register int ctlr = io->i_ctlr, slave = io->i_unit;
	register struct disklabel *lp = &dklabel[io->i_ctlr][io->i_unit];
E 9
E 8
	register struct vddevice *vdaddr = VDADDR(ctlr);
	int pass = 0, type = vdtype[ctlr], error;
I 8
	int devflags = dkflags[ctlr][slave];		/* starts with 0 */
E 8
E 6
E 3

D 3
	for(i=0; i < nvddrv; i++) {
		unit_info[ctlr][unit].info = vdst[i];
		if(ctlr_info[ctlr].ctlr_type == SMDCTLR)
			if(unit_info[ctlr][unit].info.nsec != 32)
E 3
I 3
D 6
	for (i = 0; i < nvddrv; i++) {
		dk->info = vdst[i];
		if (vdinfo[ctlr].vd_type == SMDCTLR)
			if (dk->info.nsec != 32)
E 3
				continue;
		vdconfigure(io, 0);
D 3
		daddr.cylinder = unit_info[ctlr][unit].info.ncyl - 2;
		daddr.track = unit_info[ctlr][unit].info.ntrak - 1;
		daddr.sector = unit_info[ctlr][unit].info.nsec - 1;
E 3
I 3
		daddr.cylinder = dk->info.ncyl - 2;
		daddr.track = dk->info.ntrak - 1;
		daddr.sector = dk->info.nsec - 1;
E 3
		io->i_ma = junk;
D 3
		io->i_cc = unit_info[ctlr][unit].info.secsize;
		if(!(vdaccess(io, &daddr, RD) & HRDERR))
E 3
I 3
		io->i_cc = dk->info.secsize;
		if ((vdaccess(io, &daddr, RD) & HRDERR) == 0)
E 3
			return;
E 6
I 6
D 8
	lp = &dklabel[io->i_unit];
E 8
again:
	dcb.opcode = VDOP_CONFIG;		/* command */
	dcb.intflg = DCBINT_NONE;
	dcb.nxtdcb = (struct dcb *)0;	/* end of chain */
	dcb.operrsta = 0;
D 8
	dcb.devselect = slave;
E 8
I 8
	dcb.devselect = slave | devflags;
E 8
	dcb.trail.rstrail.ncyl = lp->d_ncylinders;
	dcb.trail.rstrail.nsurfaces = lp->d_ntracks;
	if (type == VDTYPE_SMDE) {
D 7
		dcb.trailcnt = sizeof (treset) / sizeof (long);
E 7
I 7
		dcb.trailcnt = sizeof (struct treset) / sizeof (long);
E 7
		dcb.trail.rstrail.nsectors = lp->d_nsectors;
D 8
		dcb.trail.rstrail.slip_sec = 0;		/* XXX */
		dcb.trail.rstrail.recovery = 0x18f;	/* ??? */
E 8
I 8
		dcb.trail.rstrail.slip_sec = lp->d_trackskew;
		dcb.trail.rstrail.recovery = VDRF_NORMAL;
E 8
	} else
		dcb.trailcnt = 2;	/* XXX */
	mdcb.mdcb_head = &dcb;
	mdcb.mdcb_status = 0;
	VDGO(vdaddr, (u_long)&mdcb, type);
	if (!vdpoll(vdaddr, &dcb, 10, type)) {
		if (pass++ != 0) {
			printf(" during drive configuration.\n");
			return (0);
		}
		VDRESET(vdaddr, type);
		if (error = vdreset_ctlr(ctlr, io->i_unit))
			return (error);
		goto again;
E 6
	}
D 3
	printf("vd%d: Unrecognizable drive; controller %d, unit %d!\n",
	    io->i_unit, ctlr, unit);
E 3
I 3
D 6
	printf("dk%d: unknown drive type\n", io->i_unit);
E 3
	_stop("");
}

D 3

/*
**
*/

E 3
vdstart_drive(io)
D 3
register struct iob	*io;
E 3
I 3
	register struct iob *io;
E 3
{
D 3
	register int	ctlr = VDCTLR(io->i_unit);
	register int	unit = VDUNIT(io->i_unit);
	register int	io_unit_save = io->i_unit;
E 3
I 3
	register int ctlr = VDCTLR(io->i_unit), unit = VDUNIT(io->i_unit);
	int ounit = io->i_unit;
E 3

D 3
	if(ctlr_info[ctlr].ctlr_started) {
E 3
I 3
D 5
	if (vdinfo[ctlr].vd_flags&VDF_BUSY) {
E 3
		DELAY(5500000);
D 3
		return TRUE;
E 3
I 3
		return;
E 3
	}
E 5
	io->i_unit &= ~3;
D 3
	if(vdaccess_with_no_trailer(io, VDSTART, ((unit * 6) + 62)) & HRDERR) {
		vdprint_error(io->i_unit, "Start error",
E 3
I 3
D 5
	if (vdaccess_with_no_trailer(io, VDSTART, ((unit * 6) + 62)) & HRDERR) {
E 5
I 5
	if (vdnotrailer(io, VDSTART, 62) & HRDERR) {
E 5
		vdprint_error(io->i_unit, "start error",
E 3
		    dcb.operrsta, dcb.err_code);
		_stop("");
E 6
I 6
D 8
	if ((dcb.operrsta & VDERR_HARD) == 0)		/* success */
E 8
I 8
	if ((dcb.operrsta & VDERR_HARD) == 0) {		/* success */
		dkflags[ctlr][slave] = devflags;
E 8
		return (1);
I 8
	}
	if (devflags == 0) {
		devflags = VD_ESDI;
		goto again;
	}
E 8
	if (type == VDTYPE_SMDE && (vdaddr->vdstatus[slave] & STA_US) == 0) {
		printf("dk%d: nonexistent drive\n", io->i_unit);
		return (0);
E 6
	}
D 3
	ctlr_info[ctlr].ctlr_started = TRUE;
	io->i_unit = io_unit_save;
E 3
I 3
D 6
	vdinfo[ctlr].vd_flags |= VDF_BUSY;
	io->i_unit = ounit;
E 6
I 6
	if ((dcb.operrsta & (DCBS_OCYL|DCBS_NRDY)) == 0) {
		vderror(io->i_unit, "config", &dcb);
		return (0);
	}
I 8
	devflags = 0;
E 8
	if (pass++)			/* give up */
		return (0);
	/*
	 * Try to spin up drive with remote command.
	 */
	if (!vdcmd(ctlr, 0, VDOP_START, 62)) {
		vderror(io->i_unit, "start", &dcb);
		return (0);
	}
E 6
E 3
D 4
	DELAY((unit * 5500000) + 62000000);
E 4
I 4
	DELAY(62000000);
I 6
	goto again;
E 6
E 4
D 3
	return TRUE;
E 3
}

D 3

E 3
D 6
/*
D 3
**  This routine actually configures a particular drive.
**
**  If the controller is an SMD/E controller then the number of sectors per
**  track is loaded into the appropriate register, otherwise it is left 
**  alone because the old SMD controller requires a constant 32 sectors
**  per track for it's drives. (an error would be returned if the value is
**  loaded.)
**
**  In the stand-alone spirit of things the system is halted if an error
**  occurs during this operation.
*/

E 3
I 3
 * This routine actually configures a particular drive.
 *
 * If the controller is an SMD/E controller then the number of sectors per
 * track is loaded into the appropriate register, otherwise it is left 
 * alone because the old SMD controller requires a constant 32 sectors
 * per track for it's drives. (an error would be returned if the value is
 * loaded.)
 */
E 3
vdconfigure(io, pass)
D 3
register struct iob	*io;
int	pass;
E 3
I 3
	register struct iob *io;
	int pass;
E 6
I 6
vdcmd(ctlr, unit, cmd, time)
	register int ctlr;
	int unit, cmd, time;
E 6
E 3
{
D 3
	register int	ctlr = VDCTLR(io->i_unit);
	register int	unit = VDUNIT(io->i_unit);
D 2
	register cdr	*ctlr_addr = (cdr *)(vddcaddr[ctlr]+IOBASE);
E 2
I 2
	register cdr	*ctlr_addr = VDADDR(ctlr);
E 3
I 3
D 6
	register int ctlr = VDCTLR(io->i_unit), unit = VDUNIT(io->i_unit);
	register cdr *ctlr_addr = VDADDR(ctlr);
E 6
I 6
	register struct vddevice *vdaddr = VDADDR(ctlr);
E 6
E 3
E 2

D 6
	dcb.opcode = RSTCFG;		/* command */
	dcb.intflg = NOINT;
	dcb.nxtdcb = (fmt_dcb *)0;	/* end of chain */
E 6
I 6
	dcb.opcode = cmd;
	dcb.intflg = DCBINT_NONE;
	dcb.nxtdcb = (struct dcb *)0;	/* end of chain */
E 6
	dcb.operrsta  = 0;
D 6
	dcb.devselect = (char)unit;
D 3
	dcb.trail.rstrail.ncyl = unit_info[ctlr][unit].info.ncyl;
	dcb.trail.rstrail.nsurfaces = unit_info[ctlr][unit].info.ntrak;
	if(ctlr_info[ctlr].ctlr_type == SMD_ECTLR) {
E 3
I 3
	dcb.trail.rstrail.ncyl = dkinfo[ctlr][unit].info.ncyl;
	dcb.trail.rstrail.nsurfaces = dkinfo[ctlr][unit].info.ntrak;
	if (vdinfo[ctlr].vd_type == SMD_ECTLR) {
E 3
D 4
		dcb.trailcnt = (char)4;
E 4
I 4
		dcb.trailcnt = (char)5;
E 4
D 3
		dcb.trail.rstrail.nsectors = unit_info[ctlr][unit].info.nsec;
		dcb.trail.rstrail.slip_sec = unit_info[ctlr][unit].info.nslip;
	}
	else
E 3
I 3
		dcb.trail.rstrail.nsectors = dkinfo[ctlr][unit].info.nsec;
		dcb.trail.rstrail.slip_sec = dkinfo[ctlr][unit].info.nslip;
I 4
		dcb.trail.rstrail.recovery = 0x18f;
E 4
	} else
E 3
		dcb.trailcnt = (char)2;
	mdcb.firstdcb = &dcb;
	mdcb.vddcstat = 0;
D 3
	VDDC_ATTENTION(ctlr_addr, &mdcb, ctlr_info[ctlr].ctlr_type);
D 2
	POLLTILLDONE(ctlr_addr,&dcb,5,ctlr_info[ctlr].ctlr_type);
	if(vdtimeout <= 0)
E 2
I 2
	if (!vdpoll(ctlr_addr,&dcb,5,ctlr_info[ctlr].ctlr_type))
E 3
I 3
	VDDC_ATTENTION(ctlr_addr, &mdcb, vdinfo[ctlr].vd_type);
D 4
	if (!vdpoll(ctlr_addr,&dcb,10,vdinfo[ctlr].vd_type))
E 3
E 2
		_stop(" during drive configuration.\n");
E 4
I 4
	if (!vdpoll(ctlr_addr,&dcb,10,vdinfo[ctlr].vd_type)) {
		if (pass == 0) {
			VDDC_RESET(ctlr_addr, vdinfo[ctlr].vd_type);
			vdconfigure(io, 1);
		} else
			_stop(" during drive configuration.\n");
	}
E 4
D 3
	if(dcb.operrsta & (NOTCYLERR | DRVNRDY))
		if(!pass) {
			vdstart_drive(io);
			vdconfigure(io, 1);
		}
	if(dcb.operrsta & HRDERR) {
		vdprint_error(io->i_unit, "Configuration error",
E 3
I 3
D 5
	if ((dcb.operrsta & (NOTCYLERR | DRVNRDY)) && !pass) {
		vdstart_drive(io);
		vdconfigure(io, 1);
	}
E 5
	if (dcb.operrsta & HRDERR) {
D 5
		vdprint_error(io->i_unit, "configuration error",
E 3
		    dcb.operrsta, dcb.err_code);
		_stop("");
E 5
I 5
		if (vdinfo[ctlr].vd_type == SMD_ECTLR &&
		    (ctlr_addr->cdr_status[io->i_unit] & STA_US) == 0) {
			printf("dk%d: ", io->i_unit);
			_stop("nonexistent drive");
		}
		if ((dcb.operrsta & (NOTCYLERR|DRVNRDY)) == 0) {
			vdprint_error(io->i_unit, "configuration error",
			    dcb.operrsta, dcb.err_code);
			_stop("");
		}
		if (pass == 0) {
			vdstart_drive(io);
			vdconfigure(io, 1);
		}
E 5
	}
E 6
I 6
D 8
	dcb.devselect = unit;
E 8
I 8
	dcb.devselect = unit | dkflags[ctlr][unit];
E 8
	dcb.trailcnt = 0;
	mdcb.mdcb_head = &dcb;
	mdcb.mdcb_status = 0;
	VDGO(vdaddr, (u_long)&mdcb, vdtype[ctlr]);
	if (!vdpoll(vdaddr, &dcb, time, vdtype[ctlr]))
		_stop(" during initialization operation.\n");
	return ((dcb.operrsta & VDERR_HARD) == 0);
E 6
}

D 3

E 3
D 6
/*
D 3
**  Strategy is called to the actual I/O to the disk drives.
**
**  Some simple checks are made to make sure we don't do anything rediculus,
**  If everything is sane then the request is issued.
**
**  If no errors occured then the original byte count is returned,
**  otherwise -1 is returned to indicate an error occured.
*/

E 3
I 3
 * Strategy is called to do the actual I/O to the disk drives.
 *
D 4
 * Some simple checks are made to make sure we don't do anything rediculus,
E 4
I 4
 * Some simple checks are made to make sure we don't do anything rediculous,
E 4
 * If everything is sane then the request is issued.
 *
 * If no errors occured then the original byte count is returned,
 * otherwise -1 is returned to indicate an error occured.
 */
E 3
vdstrategy(io, func)
E 6
I 6
vdstrategy(io, cmd)
E 6
D 3
register struct iob	*io;
register int func;
E 3
I 3
	register struct iob *io;
D 6
	register int func;
E 6
I 6
	int cmd;
E 6
E 3
{
D 3
	dskadr		daddr;
	register int	ctlr = VDCTLR(io->i_unit);
	register int	unit = VDUNIT(io->i_unit);
	register fs_tab	*u_info = &unit_info[ctlr][unit].info;
	register int	op = (func == READ) ? RD : WD;
	register int	blk;
E 3
I 3
D 6
	dskadr daddr;
	register int ctlr = VDCTLR(io->i_unit), unit = VDUNIT(io->i_unit);
	register fs_tab	*u_info = &dkinfo[ctlr][unit].info;
	register int op = (func == READ) ? RD : WD;
	register int blk;
E 6
I 6
	register struct disklabel *lp;
D 8
	int ctlr, cn, tn, sn;
E 8
I 8
	int ctlr, cn, tn, sn, slave, retries = 0;
E 8
	daddr_t bn;
	struct vddevice *vdaddr;
E 6
E 3

D 3
	if(io->i_cc == 0)
		_stop("vd: Can't transfer zero length records!\n");
	if(io->i_cc > 0xffff)
		_stop("vd: Can't transfer greater than 2 to the 16th bytes!\n");
E 3
I 3
	if (io->i_cc == 0 || io->i_cc > 65535) {
		printf("dk%d: invalid transfer size %d\n", io->i_unit,
		    io->i_cc);
D 6
		_stop("");
E 6
I 6
		io->i_error = EIO;
		return (-1);
E 6
	}
E 3
D 6
	blk = io->i_bn * DEV_BSIZE / u_info->secsize;
	daddr.sector = blk % u_info->nsec;
	daddr.track = (blk / u_info->nsec) % u_info->ntrak;
	daddr.cylinder = (blk/u_info->nsec) / u_info->ntrak;
D 3
	if(vdaccess(io, &daddr, op) & HRDERR) {
		vdprint_error(io->i_unit,"I/O error",dcb.operrsta,dcb.err_code);
		return(-1);
E 3
I 3
	if (vdaccess(io, &daddr, op) & HRDERR) {
		vdprint_error(io->i_unit, "i/o error", dcb.operrsta,
		    dcb.err_code);
E 6
I 6
D 9
	lp = &dklabel[io->i_unit];
E 9
I 9
	lp = &dklabel[io->i_ctlr][io->i_unit];
E 9
	bn = io->i_bn * (DEV_BSIZE / lp->d_secsize);
	cn = bn / lp->d_secpercyl;
	sn = bn % lp->d_secpercyl;
	tn = sn / lp->d_nsectors;
	sn = sn % lp->d_nsectors;

I 8
top:
E 8
	dcb.opcode = (cmd == READ ? VDOP_RD : VDOP_WD);
	dcb.intflg = DCBINT_NONE;
	dcb.nxtdcb = (struct dcb *)0;	/* end of chain */
	dcb.operrsta  = 0;
D 8
	dcb.devselect = VDSLAVE(io->i_unit);
E 8
I 8
D 9
	ctlr = VDCTLR(io->i_unit);
	slave = VDSLAVE(io->i_unit);
E 9
I 9
	ctlr = io->i_ctlr;
	slave = io->i_unit;
E 9
	dcb.devselect = slave | dkflags[ctlr][slave];
E 8
D 7
	dcb.trailcnt = sizeof (trrw) / sizeof (int);
	dcb.trail.rwtrail.memadr = io->i_ma; 
E 7
I 7
	dcb.trailcnt = sizeof (struct trrw) / sizeof (int);
	dcb.trail.rwtrail.memadr = (u_long)io->i_ma; 
E 7
	dcb.trail.rwtrail.wcount = (io->i_cc + 1) / sizeof (short);
	dcb.trail.rwtrail.disk.cylinder = cn;
	dcb.trail.rwtrail.disk.track = tn;
	dcb.trail.rwtrail.disk.sector = sn;
	mdcb.mdcb_head = &dcb;
	mdcb.mdcb_status = 0;
D 8
	ctlr = VDCTLR(io->i_unit);
E 8
	vdaddr = VDADDR(ctlr);
	VDGO(vdaddr, (u_long)&mdcb, vdtype[ctlr]);
	if (!vdpoll(vdaddr, &dcb, 60, vdtype[ctlr]))
		_stop(" during i/o operation.\n");
	if (dcb.operrsta & VDERR_HARD) {
I 8
		if (retries++ == 0 && vdreset_ctlr(ctlr, io->i_unit) == 0 &&
		    vdreset_drive(io))
			goto top;
E 8
		vderror(io->i_unit, cmd == READ ? "read" : "write", &dcb);
E 6
I 5
		io->i_error = EIO;
E 5
		return (-1);
E 3
	}
	mtpr(PADC, 0);
D 3
	return(io->i_cc);
E 3
I 3
	return (io->i_cc);
E 3
}

I 3
D 5
struct	vdstatus {
	int	bit;
	char	*meaning;
} vdstatus[] = {
	{ DRVNRDY,	"drive not ready" },
	{ INVDADR,	"invalid disk address" },
	{ DNEMEM,	"non-existent memory" },
	{ PARERR,	"parity error" },
	{ OPABRT,	"operation aborted" },
	{ WPTERR,	"drive write protect" },
	{ DSEEKERR,	"seek error" },
	{ UCDATERR,	"uncorrectable data error" },
	{ CTLRERR,	"controller error" },
	{ NOTCYLERR,	"not on cylinder" },
	{ INVCMD,	"invalid controller command" },
	{ -1,		"controller error" }
};
#define	NVDSTATUS	(sizeof (vdstatus) / sizeof (vdstatus[0]))
E 3

E 5
D 3

/*
**
*/

E 3
D 6
vdprint_error(unit, str, status, smde_status)
E 6
I 6
vderror(unit, cmd, dcb)
E 6
D 3
int		unit;
char		*str;
unsigned long	status;
unsigned long	smde_status;
E 3
I 3
	int unit;
D 6
	char *str;
	u_long status;
	u_long smde_status;
E 6
I 6
	char *cmd;
	struct dcb *dcb;
E 6
E 3
{
D 3
	printf("vd%d: %s; ", unit, str);
	if(status & DRVNRDY)
		printf("Drive is not ready");
	else if(status & INVDADR)
		printf("Invalid disk address issued");
	else if(status & DNEMEM)
		printf("Non-existent memory error");
	else if(status & PARERR)
		printf("Main memory parity error");
	else if(status & OPABRT) 
		printf("Program aborted operation");
	else if(status & WPTERR)
		printf("Drive is write protected");
	else if(status & DSEEKERR)
		printf("Disk seek error");
	else if(status & UCDATERR)
		printf("Uncorrectable data error");
	else if(status & CTLRERR)
		printf("Controller faulted");
	else if(status & NOTCYLERR)
		printf("Not on cylinder error");
	else if(status & INVCMD)
		printf("Invalid command issued to controller");
	else 
		printf("Controller error");
	printf("!  Status = 0x%x", status);
	if(smde_status)
		printf("  Error code = %x", smde_status);
E 3
I 3
D 6
	register struct vdstatus *sp;
E 6

D 5
	printf("dk%d: %s; ", unit, str);
	for (sp = vdstatus; sp < &vdstatus[NVDSTATUS]; sp++)
		if (status & sp->bit) {
			printf("%s. status %x", sp->meaning, status);
			break;
		}
E 5
I 5
D 6
	printf("dk%d: %s; status %b", unit, str, status, ERRBITS);
E 5
	if (smde_status)
		printf(", code %x", smde_status);
E 6
I 6
	printf("dk%d: %s error; status %b", unit, cmd,
	    dcb->operrsta, VDERRBITS);
	if (dcb->err_code)
		printf(", code %x", dcb->err_code);
E 6
E 3
	printf("\n");
}

D 3

/*
**
*/

E 3
D 5
vdaccess_with_no_trailer(io, function, time)
E 5
I 5
D 6
vdnotrailer(io, function, time)
E 5
D 3
register struct iob	*io;
register int		function, time;
E 3
I 3
	register struct iob *io;
	register int function, time;
E 3
{
D 3
	register int	ctlr = VDCTLR(io->i_unit);
D 2
	register cdr	*ctlr_addr = (cdr *)(vddcaddr[ctlr]+IOBASE);
E 2
I 2
	register cdr	*ctlr_addr = VDADDR(ctlr);
E 3
I 3
	register int ctlr = VDCTLR(io->i_unit);
	register cdr *ctlr_addr = VDADDR(ctlr);
E 3
E 2

	dcb.opcode = function;		/* command */
	dcb.intflg = NOINT;
	dcb.nxtdcb = (fmt_dcb *)0;	/* end of chain */
	dcb.operrsta  = 0;
	dcb.devselect = (char)VDUNIT(io->i_unit);
	dcb.trailcnt = (char)0;
	mdcb.firstdcb = &dcb;
	mdcb.vddcstat = 0;
D 3
	VDDC_ATTENTION(ctlr_addr, &mdcb, ctlr_info[ctlr].ctlr_type);
D 2
	POLLTILLDONE(ctlr_addr,&dcb,time,ctlr_info[ctlr].ctlr_type);
	if(vdtimeout <= 0)
E 2
I 2
	if (!vdpoll(ctlr_addr,&dcb,time,ctlr_info[ctlr].ctlr_type))
E 3
I 3
	VDDC_ATTENTION(ctlr_addr, &mdcb, vdinfo[ctlr].vd_type);
	if (!vdpoll(ctlr_addr, &dcb, time, vdinfo[ctlr].vd_type))
E 3
E 2
		_stop(" during initialization operation.\n");
	return dcb.operrsta;
}

D 3

/*
**
*/

E 3
vdaccess(io, daddr, func)
D 3
register struct iob	*io;
dskadr			*daddr;
int			func;
E 3
I 3
	register struct iob *io;
	dskadr *daddr;
	int func;
E 3
{
D 3
	register int	ctlr = VDCTLR(io->i_unit);
D 2
	register cdr	*ctlr_addr = (cdr *)(vddcaddr[ctlr]+IOBASE);
E 2
I 2
	register cdr	*ctlr_addr = VDADDR(ctlr);
E 3
I 3
	register int ctlr = VDCTLR(io->i_unit);
	register cdr *ctlr_addr = VDADDR(ctlr);
E 3
E 2

D 3
	dcb.opcode = (short)func;		/* format sector command */
E 3
I 3
	dcb.opcode = (short)func;	/* format sector command */
E 3
	dcb.intflg = NOINT;
	dcb.nxtdcb = (fmt_dcb *)0;	/* end of chain */
	dcb.operrsta  = 0;
	dcb.devselect = (char)VDUNIT(io->i_unit);
	dcb.trailcnt = (char)(sizeof(trrw) / 4);
	dcb.trail.rwtrail.memadr = io->i_ma; 
	dcb.trail.rwtrail.wcount = ((io->i_cc + 1) / sizeof(short));
	dcb.trail.rwtrail.disk.cylinder = daddr->cylinder;
	dcb.trail.rwtrail.disk.track = daddr->track;
	dcb.trail.rwtrail.disk.sector = daddr->sector;
	mdcb.firstdcb = &dcb;
	mdcb.vddcstat = 0;
D 3
	VDDC_ATTENTION(ctlr_addr, &mdcb, ctlr_info[ctlr].ctlr_type);
D 2
	POLLTILLDONE(ctlr_addr, &dcb, 60, ctlr_info[ctlr].ctlr_type);
	if(vdtimeout <= 0)
E 2
I 2
	if (!vdpoll(ctlr_addr, &dcb, 60, ctlr_info[ctlr].ctlr_type))
E 2
		_stop(" during I/O operation.\n");
	return dcb.operrsta;
E 3
I 3
	VDDC_ATTENTION(ctlr_addr, &mdcb, vdinfo[ctlr].vd_type);
	if (!vdpoll(ctlr_addr, &dcb, 60, vdinfo[ctlr].vd_type))
		_stop(" during i/o operation.\n");
	return (dcb.operrsta);
E 3
}

E 6
/*
D 3
**	Print_dcb() dumps the MDCB and DCB for diagnostic purposes.  This
** routine is called whenever a fatal error is encountered.
*/

E 3
I 3
D 6
 * Dump the MDCB and DCB for diagnostic purposes.  This
 * routine is called whenever a fatal error is encountered.
E 6
I 6
 * Poll controller until operation
 * completes or timeout expires.
E 6
 */
E 3
D 6
vdprintdcb(ptr)
D 3
register long	*ptr;
E 3
I 3
	register long *ptr;
E 3
{
D 3
	register long	i;
	register long	trailer_count;
E 3
I 3
	register long i, trailer_count;
E 3

D 3
	printf("Dump of MDCB: ");
	for(i=0; i<4; i++)
		printf("  %lx", *(ptr+i));
	if(ptr = (long *)*ptr) {
		printf(" and DCB:");
		trailer_count = *(ptr+3) & 0xff;
		for(i=0; i<7+trailer_count; i++) {
			uncache(ptr+i);
			printf("  %lx", *(ptr+i));
E 3
I 3
	printf("mdcb: %lx %lx %lx %lx\n", ptr[0], ptr[1], ptr[2], ptr[3]);
	if (ptr = (long *)*ptr) {
		printf("dcb:");
		trailer_count = ptr[3] & 0xff;
		for (i=0; i<7+trailer_count; i++) {
			uncache(&ptr[i]);
			printf("  %lx", ptr[i]);
E 3
		}
	}
	printf("\n");
D 3
	for(i=0; i<5000000; i++) ;
E 3
I 3
	DELAY(5000000);
E 3
}

I 2
/*
 * Poll controller until operation completes
 * or timeout expires.
 */
vdpoll(addr, dcb, t, type)
	register cdr *addr;
	register fmt_dcb *dcb;
E 6
I 6
vdpoll(vdaddr, dcb, t, type)
	register struct vddevice *vdaddr;
	register struct dcb *dcb;
E 6
	register int t, type;
{

	t *= 1000;
D 5
	uncache(&dcb->operrsta);
	while ((dcb->operrsta&(DCBCMP|DCBABT)) == 0) {
		DELAY(1000);
E 5
I 5
	for (;;) {
E 5
		uncache(&dcb->operrsta);
I 5
D 6
		if (dcb->operrsta & (DCBCMP|DCBABT))
E 6
I 6
		if (dcb->operrsta & (DCBS_DONE|DCBS_ABORT))
E 6
			break;
E 5
		if (--t <= 0) {
			printf("vd: controller timeout");
D 6
			VDDC_ABORT(addr, type);
E 6
I 6
			VDABORT(vdaddr, type);
E 6
			DELAY(30000);
			uncache(&dcb->operrsta);
			return (0);
		}
I 5
		DELAY(1000);
E 5
	}
D 6
	if (type == SMD_ECTLR) {
E 6
I 6
	if (type == VDTYPE_SMDE) {
E 6
D 5
		uncache(&addr->cdr_csr);
		while (addr->cdr_csr&CS_GO) {
			DELAY(50);
E 5
I 5
		for (;;) {
E 5
D 6
			uncache(&addr->cdr_csr);
I 5
			if ((addr->cdr_csr & CS_GO) == 0)
E 6
I 6
			uncache(&vdaddr->vdcsr);
			if ((vdaddr->vdcsr & CS_GO) == 0)
E 6
				break;
			DELAY(50);
E 5
		}
		DELAY(300);
I 4
		uncache(&dcb->err_code);
E 4
	}
	DELAY(200);
	uncache(&dcb->operrsta);
	return (1);
}
I 6

#ifdef COMPAT_42
struct	dkcompat {
	int	nsectors;		/* sectors per track */
	int	ntracks;		/* tracks per cylinder */
	int	ncylinders;		/* cylinders per drive */
I 8
	int	secsize;		/* sector size */
E 8
#define	NPART	2
	int	poff[NPART];		/* [a+b] for bootstrapping */
} dkcompat[] = {
I 10
	{ 64, 20,  842,  512, 0, 61440 },	/* 2361a eagle */
E 10
D 8
	{ 48, 24, 711, 0, 61056 },	/* xsd */
	{ 44, 20, 842, 0, 52800 },	/* eagle */
	{ 64, 10, 823, 0, 38400 },	/* fuji 360 */
	{ 32, 24, 711, 0, 40704 },	/* xfd */
	{ 32, 19, 823, 0, 40128 },	/* smd */
	{ 32, 10, 823, 0, 19200 },	/* fsd */
E 8
I 8
	{ 48, 24,  711,  512, 0, 61056 },	/* xsd */
	{ 44, 20,  842,  512, 0, 52800 },	/* eagle */
	{ 64, 10,  823,  512, 0, 38400 },	/* fuji 360 */
	{ 32, 24,  711,  512, 0, 40704 },	/* xfd */
	{ 32, 19,  823,  512, 0, 40128 },	/* smd */
	{ 32, 10,  823,  512, 0, 19200 },	/* fsd */
	{ 18, 15, 1224, 1024, 0, 21600 },	/* mxd */
E 8
};
#define	NDKCOMPAT	(sizeof (dkcompat) / sizeof (dkcompat[0]))

/*
 * Identify and configure drive from above table
 * by trying to read the last sector until a description
 * is found for which we're successful.
 */
vdmaptype(io)
	struct iob *io;
{
D 9
	register struct disklabel *lp = &dklabel[io->i_unit];
E 9
I 9
	register struct disklabel *lp = &dklabel[io->i_ctlr][io->i_unit];
E 9
	register struct dkcompat *dp;
D 8
	int i, ctlr, type;
E 8
I 8
	int i, ctlr, slave, type;
E 8
	struct vddevice *vdaddr;

D 9
	ctlr = VDCTLR(io->i_unit);
I 8
	slave = VDSLAVE(io->i_unit);
E 9
I 9
	ctlr = io->i_ctlr;
	slave = io->i_unit;
E 9
E 8
	vdaddr = VDADDR(ctlr);
	type = vdtype[ctlr];
	for (dp = dkcompat; dp < &dkcompat[NDKCOMPAT]; dp++) {
		if (type == VDTYPE_VDDC && dp->nsectors != 32)
			continue;
		lp->d_nsectors = dp->nsectors;
		lp->d_ntracks = dp->ntracks;
		lp->d_ncylinders = dp->ncylinders;
I 8
		lp->d_secsize = dp->secsize;
E 8
		if (!vdreset_drive(io))		/* set drive parameters */
			return (EIO);
		dcb.opcode = VDOP_RD;
		dcb.intflg = DCBINT_NONE;
		dcb.nxtdcb = (struct dcb *)0;	/* end of chain */
D 8
		dcb.devselect = VDSLAVE(io->i_unit);
E 8
I 8
		dcb.devselect = slave | dkflags[ctlr][slave];
E 8
		dcb.operrsta = 0;
D 7
		dcb.trailcnt = sizeof (trrw) / sizeof (long);
		dcb.trail.rwtrail.memadr = lbuf; 
		dcb.trail.rwtrail.wcount = sizeof (lbuf) / sizeof (short);
E 7
I 7
		dcb.trailcnt = sizeof (struct trrw) / sizeof (long);
		dcb.trail.rwtrail.memadr = (u_long)lbuf; 
D 8
		dcb.trail.rwtrail.wcount = 512 / sizeof (short);
E 8
I 8
		dcb.trail.rwtrail.wcount = lp->d_secsize / sizeof (short);
E 8
E 7
		dcb.trail.rwtrail.disk.cylinder = dp->ncylinders - 2;
		dcb.trail.rwtrail.disk.track = dp->ntracks - 1;
		dcb.trail.rwtrail.disk.sector = dp->nsectors - 1;
		mdcb.mdcb_head = &dcb;
		mdcb.mdcb_status = 0;
		VDGO(vdaddr, (u_long)&mdcb, type);
		if (!vdpoll(vdaddr, &dcb, 60, type))
			_stop(" during i/o operation.\n");
		if (dcb.operrsta & VDERR_HARD)
			continue;
		/* simulate necessary parts of disk label */
		lp->d_secpercyl = lp->d_nsectors * lp->d_ntracks;
		lp->d_secperunit = lp->d_secpercyl * lp->d_ncylinders;
		lp->d_npartitions = NPART;
		for (i = 0; i < NPART; i++) {
			lp->d_partitions[i].p_offset = dp->poff[i];
			lp->d_partitions[i].p_size =
			    lp->d_secperunit - dp->poff[i];
		}
		return (0);
	}
	printf("dk%d: unknown drive type\n", io->i_unit);
	return (ENXIO);
}
#endif
E 6
E 2
E 1
