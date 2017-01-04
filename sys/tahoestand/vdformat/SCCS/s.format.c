h57798
s 00001/00004/00175
d D 1.7 88/06/07 14:33:03 karels 7 6
c fix relocate (I think) and correct, add command to clear corrections,
c don't preserve user- and verify-detected flaws on reformat; *don't* pass
c structures back and forth incessantly
e
s 00002/00000/00177
d D 1.6 88/05/31 08:44:17 karels 6 5
c clean up error reporting
e
s 00024/00014/00153
d D 1.5 87/11/23 15:28:33 karels 5 4
c working again, I think
e
s 00010/00011/00157
d D 1.4 87/06/01 20:59:16 sam 4 3
c header file changes (guess this works, noone's complained)
e
s 00000/00004/00168
d D 1.3 86/12/26 12:28:03 sam 3 2
c take out debugging printfs
e
s 00006/00000/00166
d D 1.2 86/11/04 21:24:07 karels 2 1
c version working with eagles, many cleanups and fixes
e
s 00166/00000/00000
d D 1.1 86/07/05 17:37:34 sam 1 0
c date and time created 86/07/05 17:37:34 by sam
e
u
U
f b 
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley/CCI) %G%";
#endif

#include	"vdfmt.h"

/*
**
*/

format()
{
	boolean	read_bad_sector_map();
	cur.state = fmt;
	print("Starting format on ");
	printf("controller %d, drive %d, ", cur.controller, cur.drive);
D 5
	printf("type %s.\n",CURRENT->vc_name);
E 5
I 5
	printf("type %s.\n", lab->d_typename);
E 5

	/* Read the flaw map from the disk (where ever it may be) */
	if(read_bad_sector_map() == true) {
D 5
		if(bad_map->bs_id != D_INFO.id) {
E 5
I 5
		if(bad_map->bs_id != D_INFO->id) {
E 5
			print("Module serial numbers do not match!\n");
I 5
#ifdef notdef
E 5
			print("Use `info' to find the real serial number.\n");
			_longjmp(abort_environ, 1);
I 5
#else
			printf("Using serial number from drive, %d\n",
			    bad_map->bs_id);
			D_INFO->id = bad_map->bs_id;
#endif
E 5
		}
I 7
		clear_relocations(false);
E 7
	}
	else
D 5
		bad_map->bs_id = D_INFO.id;
E 5
I 5
		bad_map->bs_id = D_INFO->id;
E 5

	/* Re-Initialize bad sector map relocation pointers */
	zero_bad_sector_map();
	write_bad_sector_map();
	if(kill_processes == true)
		_longjmp(quit_environ, 1);

	/* format the disk surface */
I 2
D 3
printf("Starting format on system areas\n");
E 3
E 2
	format_relocation_area();
D 5
	format_maintainence_area();
E 5
I 5
	format_maintenence_area();
E 5
I 2
D 3
printf("Starting format on data area\n");
E 3
E 2
	format_users_data_area();
D 7
	if(kill_processes == true)
		_longjmp(quit_environ, 1);
E 7


	/* verify the surface */
I 2
D 3
printf("Starting verify on system areas\n");
E 3
E 2
	verify_relocation_area();
D 5
	verify_maintainence_area();
E 5
I 5
	verify_maintenence_area();
E 5
I 2
D 3
printf("Starting verify on data area\n");
E 3
E 2
	verify_users_data_area();
I 5

	(void) writelabel();
E 5
}


/*
**
*/

format_relocation_area()
{
	register long		sector_count;
	dskadr			dskaddr;

	cur.substate = sub_fmt;
D 5
	dskaddr.cylinder = (short)(CURRENT->vc_ncyl - NUMSYS);
E 5
I 5
	dskaddr.cylinder = (short)(lab->d_ncylinders - NUMSYS);
E 5
	dskaddr.track = (char)0;
	dskaddr.sector = (char)0;
D 5
	sector_count = (long)(NUMREL * CURRENT->vc_ntrak * CURRENT->vc_nsec);
E 5
I 5
	sector_count = (long)(NUMREL * lab->d_ntracks * lab->d_nsectors);
E 5
	format_sectors(&dskaddr, &dskaddr, NRM, sector_count);
}


/*
**
*/

format_users_data_area()
{
	register long		sector_count;
	dskadr			dskaddr;
	register int		cyl;

	cur.substate = sub_fmt;
D 5
	sector_count = (long)(CURRENT->vc_ntrak * CURRENT->vc_nsec);
E 5
I 5
	sector_count = (long)(lab->d_ntracks * lab->d_nsectors);
E 5
	dskaddr.track = (char)0;
	dskaddr.sector = (char)0;
D 5
	for(cyl=0; cyl < (CURRENT->vc_ncyl - NUMSYS); cyl++) {
E 5
I 5
	for(cyl=0; cyl < (lab->d_ncylinders - NUMSYS); cyl++) {
E 5
		dskaddr.cylinder = cyl;
		format_sectors(&dskaddr, &dskaddr, NRM, sector_count);
I 2
		if (kill_processes)
			return;
E 2
	}
}


/*
**
*/

D 5
format_maintainence_area()
E 5
I 5
format_maintenence_area()
E 5
{
	register long		sector_count;
	dskadr			dskaddr;

	cur.substate = sub_fmt;
D 5
	dskaddr.cylinder = (short)(CURRENT->vc_ncyl - NUMMNT - NUMMAP);
E 5
I 5
	dskaddr.cylinder = (short)(lab->d_ncylinders - NUMMNT - NUMMAP);
E 5
	dskaddr.track = (char)0;
	dskaddr.sector = (char)0;
D 5
	sector_count = (long)(NUMMNT * CURRENT->vc_ntrak * CURRENT->vc_nsec);
E 5
I 5
	sector_count = (long)(NUMMNT * lab->d_ntracks * lab->d_nsectors);
E 5
	format_sectors(&dskaddr, &dskaddr, NRM, sector_count);
}


/*
**
*/

boolean is_formatted()
{
	extern boolean	align_buf();
	dskadr		dskaddr;

	dskaddr.cylinder = 0;
	dskaddr.track = 0;
	dskaddr.sector = 0;
D 4
	if(C_INFO.type == SMD_ECTLR) {
		access_dsk((char *)save, &dskaddr, RD_RAW, 1, 1);
E 4
I 4
D 5
	if(C_INFO.type == VDTYPE_SMDE) {
E 5
I 5
	if(C_INFO->type == VDTYPE_SMDE) {
E 5
		access_dsk((char *)save, &dskaddr, VDOP_RDRAW, 1, 1);
E 4
		if(align_buf((unsigned long *)save, CDCSYNC) == false)
			return true;
		return	false;
	}
D 4
	else if(access_dsk((char *)save, &dskaddr, RD, 1, 1) & HEADER_ERROR)
E 4
I 4
	else if(access_dsk((char *)save, &dskaddr, VDOP_RD, 1, 1)&HEADER_ERROR)
E 4
		return false;
	return true;
}


/*
**	Vdformat_sectors is used to do the actual formatting of a block.
*/

format_sectors(dskaddr, hdraddr, flags, count)
dskadr	*dskaddr, *hdraddr;
short	flags;
long	count;
{
	cur.daddr.cylinder = dskaddr->cylinder & 0xfff;
	cur.daddr.track = dskaddr->track;
D 4
	dcb.opcode = FSECT;		/* format sector command */
	dcb.intflg = NOINT;
	dcb.nxtdcb = (fmt_dcb *)0;	/* end of chain */
E 4
I 4
	dcb.opcode = VDOP_FSECT;		/* format sector command */
	dcb.intflg = DCBINT_NONE;
	dcb.nxtdcb = (struct dcb *)0;	/* end of chain */
E 4
	dcb.operrsta  = 0;
	dcb.devselect = (char)cur.drive;
D 4
	dcb.trailcnt = (char)(sizeof(trfmt) / sizeof(long));
E 4
I 4
	dcb.trailcnt = (char)(sizeof(struct trfmt) / sizeof(long));
E 4
	dcb.trail.fmtrail.addr = (char *)scratch; 
	dcb.trail.fmtrail.nsectors = count;
	dcb.trail.fmtrail.disk.cylinder = dskaddr->cylinder | flags;
	dcb.trail.fmtrail.disk.track = dskaddr->track;
	dcb.trail.fmtrail.disk.sector = dskaddr->sector;
	dcb.trail.fmtrail.hdr.cylinder = hdraddr->cylinder | flags;
	dcb.trail.fmtrail.hdr.track = hdraddr->track;
	dcb.trail.fmtrail.hdr.sector = hdraddr->sector;
D 4
	mdcb.firstdcb = &dcb;
	mdcb.vddcstat = 0;
	VDDC_ATTENTION(C_INFO.addr, &mdcb, C_INFO.type);
E 4
I 4
	mdcb.mdcb_head = &dcb;
	mdcb.mdcb_status = 0;
D 5
	VDGO(C_INFO.addr, (u_long)&mdcb, C_INFO.type);
E 5
I 5
	VDGO(C_INFO->addr, (u_long)&mdcb, C_INFO->type);
E 5
E 4
	poll((int)(((count+849)/850)+120));
	if(vdtimeout <= 0) {
		printf(" while formatting sectors.\n");
		_longjmp(abort_environ, 1);
	}
I 6
	if (dcb.operrsta & DCBS_HARD)
		vd_error("format");
E 6
I 5
D 7
	if(kill_processes == true)
		_longjmp(quit_environ, 1);
E 7
E 5
}
D 4

E 4
E 1
