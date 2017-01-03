/*
 * Stand alone driver for the HDC controller
 *
 *	%W% (Berkeley) %G%
 */
#define	KERNEL

#include "machine/mtpr.h"

#include "param.h"
#include "inode.h"
#include "fs.h"
#include "buf.h"
#include "ioctl.h"
#include "disklabel.h"
#include "saio.h"

#define	HDC_STANDALONE

#include "../tahoevba/hdc.h"

#define	NDRIVE		8		/* pretend drives per controller */

hdc_ctlr_type	hdc_ctlr[HDC_MAXCTLR][HDC_MAXBUS];
hdc_unit_type	hdc_unit[HDC_MAXDRIVE][HDC_MAXCTLR][HDC_MAXBUS];

hdopen(io)
	register struct iob *io;
{
	register struct disklabel *lp, *dlp;
	drive_stat_type status;		/* the hdc status is read to here */
	hdc_mid_type *id;		/* the hdc module id */
	hdc_ctlr_type *hc;		/* hdc ctlr information table */
	hdc_unit_type *hu;		/* disk unit information table */
	mcb_type *mcb;			/* an mcb to send commands to hdc */
	long junk = 0;
	int bus, ctlr, drive, error, i, par;
	char lbuf[DEV_BSIZE];

	/* validate the device specification */
	if ((u_int)(bus = io->i_adapt) >= HDC_DEFBUS)
		return(EADAPT);
	if ((u_int)(ctlr = io->i_ctlr) >= HDC_MAXCTLR)
		return(ECTLR);
	if ((u_int)(drive = io->i_unit) >= HDC_MAXDRIVE)
		return(EUNIT);
	if ((u_int)(par = io->i_part) > 7)
		return(EPART);
	bus = HDC_DEFBUS;

printf("ctlr {%d} drive {%d} bus {%d} par {%d} unit {%d}\n",
ctlr,drive,bus,par,io->i_unit);
	hu = &hdc_unit[drive][ctlr][bus];
	hc = &hdc_ctlr[ctlr][bus];
	mcb = &hc->mcb;

	/* init drive structure. */
	hu->slave = drive;
	hc->registers = (hdc_regs_type *)(bus ?
		0x80000000 | ctlr << 24 | HDC_MID << 16 :
		0xC0000000 | ctlr << 24 | HDC_MID << 16);

	/* insure that this is an hdc, then reset the hdc. */
	if (wbadaddr(&hc->registers->module_id_reg, 4, &junk)) {
		printf("hd%d: %x: invalid csr\n", ctlr, (u_int)hc->registers);
		return(ENXIO);
	}
	HDC_REGISTER(soft_reset_reg) = 0;
	DELAY(1000000);

	/*
	 * Read in the hdc module id word.  The controller is bad if the
	 * hdc's writeable control store is not loaded or if the hdc failed
	 * the functional integrity test for any reason.
	 */
	id = &hc->mid;
	HDC_REGISTER(module_id_reg) = (u_long)id;
	DELAY(10000);
	mtpr(PADC, 0);

printf("id {%x} rev {%x} fit {%x}\n",id->module_id,
id->code_rev, id->fit);
	if (id->module_id != (u_char)HDC_MID) {
		printf("hdc: controller bad module id: id = %x\n",
		    id->module_id);
		return(ENXIO);
	}
	if (id->code_rev == (u_char)0xff) {
		printf("hdc: controller micro-code is not loaded.\n");
		return(ENXIO);
	}
	if (id->fit != (u_char)0xff) {
		printf("hdc: controller FIT test failed: error= %x\n",
		    id->fit);
		return(ENXIO);
	}

	/* Read the drive status. Save important info. */
	mcb->command = HCMD_STATUS;
	mcb->drive = drive;
	mcb->cyl = 0;
	mcb->head = 0;
	mcb->sector = 0;
	mcb->chain[0].lwc = (long)sizeof(drive_stat_type) / sizeof(long);
	mcb->chain[0].ta  = (long)&status;
	if (hdmcb(mcb, io))
		return(EIO);

	/*
	 * Report drive down if anything in the drive status is bad.
	 * If fault condition, reading will try to clear the fault.
	 */
	if (status.drs & DRS_FAULT)
		printf("hdc: clearing drive fault.\n");
	if (!(status.drs & DRS_ONLINE)) {
		printf("hdc: drive is not online.\n");
		return(EIO);
	}

	hu->cylinders = status.max_cyl+1;
	hu->heads = status.max_head+1;
	hu->sectors = status.max_sector+1;
	hu->spc = hu->heads * hu->sectors;
	hu->def_cyl = status.def_cyl;
	hu->def_cyl_count = status.def_cyl_count;
	hu->diag_cyl = status.diag_cyl;
	hu->diag_cyl_count = status.diag_cyl_count;
	hu->phys_cylinders = status.max_phys_cyl+1;
	hu->phys_heads = status.max_phys_head+1;
	hu->phys_sectors = status.max_phys_sector+1;
	hu->bytes_per_sec = status.bytes_per_sec;
	hu->id = status.id;
	hu->rpm = status.rpm;
	hu->partition[HDC_DEFPART].start=
		hu->def_cyl * hu->sectors * hu->heads / HDC_SPB;
	hu->partition[HDC_DEFPART].length =
		hu->def_cyl_count * hu->sectors * hu->heads / HDC_SPB;

	/* Read in the pack label */
	mcb->command = HCMD_READ;
	mcb->drive = drive;
	mcb->cyl = 0;
	mcb->head = 0;
	mcb->sector = LABELSECTOR;
	mcb->chain[0].lwc = DEV_BSIZE;
	mcb->chain[0].ta  = (long)lbuf;
	if (hdmcb(mcb, io))
		return(ERDLAB);
	dlp = (struct disklabel *)(lbuf + LABELOFFSET);
	if (dlp->d_magic != DISKMAGIC || dlp->d_magic2 != DISKMAGIC)
#ifdef COMPAT_42
	{
		printf("hdc%d: unlabeled\n", io->i_unit);
		if (error = hdmaptype(io, hu, dlp))
			return(error);
	}
#else
		return(EUNLAB);
#endif
	else
		hu->dklabel = *dlp;
	if (io->i_part >= dlp->d_npartitions ||
	    dlp->d_partitions[io->i_part].p_size == 0)
		return(EPART);
	io->i_boff =
	    (dlp->d_partitions[io->i_part].p_offset * dlp->d_secsize) / DEV_BSIZE;
	return(0);
}

hdstrategy(io, cmd)
	register struct iob *io;	/* i/o block */
	int cmd;			/* i/o operation to perform */
{
	mcb_type *mcb;			/* mcb to send to the hdc */
	hdc_unit_type *hu;		/* disk unit information table */
	hdc_ctlr_type *hc;		/* hdc ctlr information table */
	long sector;
	int partstart, partlen, bytes, bus, ctlr, drive;

	bus = io->i_adapt;
	ctlr = io->i_ctlr;
	drive = io->i_unit;
	hu = &hdc_unit[drive][ctlr][bus];
	hc = &hdc_ctlr[ctlr][bus];

	if (io->i_cc & 3) {
		printf("hdc: i/o not a longword multiple.\n");
		return(0);
	}

	/* insure the transfer fits in the partition. */
	partstart = hu->partition[io->i_part].start;
	partlen = hu->partition[io->i_part].length;
/* KB this looks wrong -- i_bn + i_cc > partstart + partlen??? */
	if (io->i_bn < partstart || io->i_bn >= partstart + partlen)
		return(0);
	bytes = MIN(io->i_cc, DEV_BSIZE * (partstart + partlen - io->i_bn));

	/* set up the mcb and send it to the hdc. */
	mcb = &hc->mcb;
	sector = io->i_bn * HDC_SPB;
	mcb->command = (cmd == READ) ? HCMD_READ : HCMD_WRITE;
	mcb->drive = hu->slave;
	mcb->cyl = sector / (hu->sectors * hu->heads);
	mcb->head = (sector / hu->sectors) % hu->heads;
	mcb->sector = sector % hu->sectors;
	mcb->chain[0].ta  = (u_long)io->i_ma;
	mcb->chain[0].lwc = (bytes + 3) / sizeof(long);
	io->i_error = hdmcb(mcb, io);
	return(io->i_error ? 0 : bytes);
}

static
hdmcb(mcb, io)
	register mcb_type *mcb;		/* mcb to send to the hdc */
	register struct iob *io;	/* i/o block */
{
	register u_int *ptr;
	master_mcb_type *master_mcb;	/* the hdc's master mcb */
	hdc_ctlr_type *hc;		/* hdc ctlr information table */
	int timeout, bus, ctlr, i, end;

	bus = io->i_adapt;
	ctlr = io->i_ctlr;
	hc = &hdc_ctlr[ctlr][bus];

	mcb->interrupt = 0;
	mcb->priority = 0;
	mcb->forw_phaddr = 0;
	mcb->context = 0;
	mcb->reserved[0] = 0;
	mcb->reserved[1] = 0;
	master_mcb = &hc->master_mcb;
	master_mcb->forw_phaddr = (long)&mcb->forw_phaddr;
	master_mcb->mcs = 0;
	master_mcb->interrupt = 0;
	master_mcb->reserve1 = 0;
	master_mcb->reserve2 = 0;
	master_mcb->context = 0;
	master_mcb->mcl = MCL_IMMEDIATE;
	for (i = 0; i < HDC_XSTAT_SIZE; i++)
		master_mcb->xstatus[i] = 0;
	HDC_REGISTER(master_mcb_reg) = (u_long)master_mcb;
	for (timeout = 15000;;) {
		DELAY(1000);
		mtpr(PADC, 0);
		if (master_mcb->mcs & MCS_FATALERROR) {
			printf("hdc: controller fatal error.\n");
			break;
		}
		if (master_mcb->mcs & MCS_DONE)
			return(0);
		if (!--timeout) {
			printf("hdc: controller timed out.\n");
			break;
		}
	}

	printf("mmcb: ");
	ptr = (u_int *)master_mcb;
	for (i = 0; i < 8; i++)
		printf(" %x", ptr[i]);
	for (i = 7 + HDC_XSTAT_SIZE; i > 7; i--) {
		end = i;
		if (ptr[i] != 0)
			break;
	}
	for (i = 8; i <= end; i++)
		printf(" %x", ptr[i]);

	printf("\nmcb:  ");
	ptr = (u_int *)&mcb->forw_phaddr;
	for (i = 0; i < 6; i++)
		printf(" %x", ptr[i]);
	for (i = 6; i < 72; i += 2) {
		printf("  %x %x", ptr[i], ptr[i+1]);
		if (!(ptr[i] & 0x80000000))
			break;
	}
	printf("\n");
	return(1);
}

#ifdef COMPAT_42
hdmaptype(io, hu, dlp)
	register struct iob *io;
	hdc_unit_type *hu;
	register struct disklabel *dlp;
{
	geometry_sector geometry;
	geometry_block *geo;
	mcb_type *mcb;
	int i;

	/*
	 * Read the geometry block (at head = 0 sector = 0 of the drive
	 * definition cylinder), validate it (must have the correct version
	 * number, header, and checksum).
	 */
	geo = &geometry.geometry_block;
	mcb->command = HCMD_READ;
	mcb->drive = hu->slave;
	mcb->cyl = hu->def_cyl;
	mcb->head = 0;
	mcb->sector = 0;
	mcb->chain[0].lwc = sizeof(geometry_sector) / sizeof(long);
	mcb->chain[0].ta  = (long)&geometry;
	io->i_boff = hu->partition[HDC_DEFPART].start;		/* default */
	if (hdmcb(mcb, io)) {
 		printf("hd%d: can't read default geometry.\n", io->i_unit);
		return(EIO);
	}
 	if (geo->version > 64000  ||  geo->version < 0) {
 		printf("hd%d: bad default geometry version#.\n", io->i_unit);
		return(ENXIO);
	}
 	if (strcmp(&geo->id[0], GB_ID)) {
 		printf("hd%d: bad default geometry header.\n", io->i_unit);
		return(ENXIO);
	}
	GB_CHECKSUM(geo, i);
	if (geometry.checksum != i) {
		printf("hd%d: bad default geometry checksum.\n", io->i_unit);
		return(ENXIO);
	}
	for (i = 0; i < GB_MAXPART; i++) {
		dlp->d_partitions[i].p_offset = geo->partition[i].start;
		dlp->d_partitions[i].p_size = geo->partition[i].length;
	}
	dlp->d_secsize = hu->bytes_per_sec;
	dlp->d_nsectors = hu->sectors;
	dlp->d_secpercyl = hu->spc;
	dlp->d_ntracks = dlp->d_secpercyl / hu->sectors;
	dlp->d_ncylinders = hu->cylinders;
	dlp->d_npartitions = GB_MAXPART;
	dlp->d_rpm = hu->rpm;
	bcopy("hdc (default)", dlp->d_typename, 14);
	return(0);
}
#endif /* COMPAT_42 */
