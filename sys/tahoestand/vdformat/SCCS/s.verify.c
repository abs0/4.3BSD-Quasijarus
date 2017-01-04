h34169
s 00067/00036/00210
d D 1.5 88/06/07 14:33:18 karels 5 4
c fix relocate (I think) and correct, add command to clear corrections,
c don't preserve user- and verify-detected flaws on reformat; *don't* pass
c structures back and forth incessantly
e
s 00023/00017/00223
d D 1.4 87/11/23 15:29:13 karels 4 3
c working again, I think
e
s 00007/00006/00233
d D 1.3 87/06/01 20:59:33 sam 3 2
c header file changes (guess this works, noone's complained)
e
s 00058/00044/00181
d D 1.2 86/11/04 21:24:19 karels 2 1
c version working with eagles, many cleanups and fixes
e
s 00225/00000/00000
d D 1.1 86/07/05 17:37:45 sam 1 0
c date and time created 86/07/05 17:37:45 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley/CCI) %G%";
#endif

#include	"vdfmt.h"

D 2
#define	quiet 0
E 2
I 2
#define	verbose	1
E 2

/*
**
*/

verify()
{
	extern boolean	read_bad_sector_map();

	cur.state = vfy;
	print("Starting verification on ");
	printf("controller %d, drive %d, ", cur.controller, cur.drive);
D 4
	printf("type %s.\n",CURRENT->vc_name);
E 4
I 4
	printf("type %s.\n", lab->d_typename);
E 4

	if(is_formatted() == true) {
		if(read_bad_sector_map() == true) {
D 4
			if(bad_map->bs_id == D_INFO.id) {
E 4
I 4
			if(bad_map->bs_id == D_INFO->id) {
E 4
				verify_users_data_area();
I 4
				writelabel();
E 4
				return;
			}
		}
		print("I can't verify drives with old formats.\n");
		return;
	}
	print("I can't verify unformatted drives.\n");
}


/*
**
*/

load_verify_patterns()
{
	register int index;
D 4
	register struct flawpat *fp = CURRENT->vc_pat;
E 4
I 4
	register struct flawpat *fp = (struct flawpat *)lab->d_pat;
E 4

	/* Init bad block pattern array */
D 4
	for(index=0; index<TRKSIZ; index++) {
E 4
I 4
	for(index=0; index<MAXTRKSIZ; index++) {
E 4
		pattern_0[index] = fp->fp_pat[0];
		pattern_1[index] = fp->fp_pat[1];
		pattern_2[index] = fp->fp_pat[2];
		pattern_3[index] = fp->fp_pat[3];
		pattern_4[index] = fp->fp_pat[4];
		pattern_5[index] = fp->fp_pat[5];
		pattern_6[index] = fp->fp_pat[6];
		pattern_7[index] = fp->fp_pat[7];
		pattern_8[index] = fp->fp_pat[8];
		pattern_9[index] = fp->fp_pat[9];
		pattern_10[index] = fp->fp_pat[10];
		pattern_12[index] = fp->fp_pat[12];
		pattern_13[index] = fp->fp_pat[13];
		pattern_14[index] = fp->fp_pat[14];
		pattern_15[index] = fp->fp_pat[15];
	}
}


/*
**
*/

verify_relocation_area()
{
	cur.substate = sub_vfy;
D 4
	verify_cylinders((int)CURRENT->vc_ncyl - NUMSYS, NUMREL, 16);
E 4
I 4
	verify_cylinders((int)lab->d_ncylinders - NUMSYS, NUMREL, 16);
E 4
	sync_bad_sector_map();
}


/*
**
*/

verify_users_data_area()
{
	int	pats = ops_to_do[cur.controller][cur.drive].numpat;

	cur.substate = sub_vfy;
D 4
	verify_cylinders(0, (int)CURRENT->vc_ncyl - NUMSYS, pats);
E 4
I 4
	verify_cylinders(0, (int)lab->d_ncylinders - NUMSYS, pats);
E 4
	sync_bad_sector_map();
}


/*
**
*/

D 4
verify_maintainence_area()
E 4
I 4
verify_maintenence_area()
E 4
{
	cur.substate = sub_vfy;
D 4
	verify_cylinders(CURRENT->vc_ncyl - NUMSYS + NUMREL, NUMMNT, 16);
E 4
I 4
	verify_cylinders(lab->d_ncylinders - NUMSYS + NUMREL, NUMMNT, 16);
E 4
	sync_bad_sector_map();
}


/*
**	verify_cylinders does full track certification for every track
D 2
** on the cylinder.  This is done for speed and minimal head movement.  If
** an error occurs on any single track the track is flagged for later
** verification by verify sectors.
E 2
I 2
** on the cylinder.
E 2
*/

verify_cylinders(base_cyl, cyl_count, pats)
int	base_cyl, cyl_count, pats;
{
	dskadr		dskaddr;

I 2
	if (pats == 0)
		return;
E 2
	/* verify each track of each cylinder */
D 2
	for (dskaddr.cylinder=base_cyl; dskaddr.cylinder<(base_cyl+cyl_count);
	    dskaddr.cylinder++)
		for (dskaddr.track=0; dskaddr.track<CURRENT->vc_ntrak;
E 2
I 2
	for (dskaddr.cylinder = base_cyl;
	    dskaddr.cylinder < base_cyl + cyl_count; dskaddr.cylinder++)
D 4
		for (dskaddr.track = 0; dskaddr.track < CURRENT->vc_ntrak;
E 4
I 4
		for (dskaddr.track = 0; dskaddr.track < lab->d_ntracks;
E 4
E 2
		    dskaddr.track++)
D 2
			verify_track(&dskaddr, pats, quiet);
E 2
I 2
			verify_track(&dskaddr, pats, verbose);
E 2
}


/*
D 2
**	verify_track verifies a single track. If the full track write and
** compare operation fails then each sector is read individually to determin
** which sectors are really bad.  If a sector is bad it is flagged as bad by
** the verify sector routine.
E 2
I 2
**	verify_track verifies a single track.  If a full-track write fails,
** the sector is flagged; if a full-track read fails, then each sector
** is read individually to determine which sectors are really bad.
** If a sector is bad it is flagged as bad by flag_sector.
E 2
*/

verify_track(dskaddr, pats, verbosity)
dskadr	*dskaddr;
int	pats;
int	verbosity;
{
	register int	index, i;
	register int	count;
	register long	before;
	register long	*after;
D 4
	register long	offset = SECSIZ / sizeof(long);
E 4
I 4
	register long	offset = lab->d_secsize / sizeof(long);
E 4
	int		pattern_count = pats;
I 2
D 5
	int		sectorflagged = -1;
E 5
E 2

D 2
	if(pats == 0)
E 2
I 2
	if (pats == 0)
E 2
		return;
	dskaddr->sector = (char)0;
D 2
	access_dsk((char *)pattern_address[0], dskaddr, WD, CURRENT->vc_nsec, 1);
	for(index = 0; index < pattern_count; index++) {
		if(!data_ok()) {
			if(dcb.operrsta & HEADER_ERROR)  {
				flag_sector(dskaddr, dcb.operrsta, verbosity);
E 2
I 2
D 3
	access_dsk((char *)pattern_address[0], dskaddr, WD,
E 3
I 3
	access_dsk((char *)pattern_address[0], dskaddr, VDOP_WD,
E 3
D 4
	    CURRENT->vc_nsec, 1);
E 4
I 4
	    lab->d_nsectors, 1);
E 4
	for (index = 0; index < pattern_count; index++) {
		if (!data_ok()) {
D 5
			if (dcb.operrsta & HEADER_ERROR)  {
		 
E 5
I 5
			if (dcb.operrsta & HEADER_ERROR &&
			    C_INFO->type == VDTYPE_SMDE) {
E 5
				flag_sector(dskaddr, dcb.operrsta,
D 5
				    dcb.err_code, verbosity);
E 5
I 5
				    dcb.err_code, "write", verbosity);
E 5
E 2
				break;
I 5
			} else {
				indent();
				vd_error("write track");
				exdent(1);
E 5
			}
I 5
#ifdef notdef
			/*
			 * we presume that write errors will be detected
			 * on read or data compare,
			 * don't bother with extra testing.
			 */
E 5
D 2
			if(dcb.operrsta & DATA_ERROR)
E 2
I 2
			if (dcb.operrsta & DATA_ERROR)
E 2
				pattern_count = 16;
I 5
#endif
			/*
			 * Write track a sector at a time,
			 * so that a write aborted on one sector
			 * doesn't cause compare errors on all
			 * subsequent sectors on the track.
			 */
			for (i = 0; i < lab->d_nsectors; i++) {
				dskaddr->sector = i;
				access_dsk((char *)pattern_address[index],
				    dskaddr, VDOP_WD, 1,1);
			}
			dskaddr->sector = (char)0;
E 5
		}
D 2
		access_dsk((char *)scratch,dskaddr,RD,CURRENT->vc_nsec,1);
		if(!data_ok()) {
			if(dcb.operrsta & HEADER_ERROR)  {
				flag_sector(dskaddr, dcb.operrsta, verbosity);
E 2
I 2
D 3
		access_dsk((char *)scratch, dskaddr, RD, CURRENT->vc_nsec, 1);
E 3
I 3
		access_dsk((char *)scratch, dskaddr, VDOP_RD,
D 4
		    CURRENT->vc_nsec, 1);
E 4
I 4
		    lab->d_nsectors, 1);
E 4
E 3
		if (!data_ok()) {
			if (dcb.operrsta & HEADER_ERROR)  {
				flag_sector(dskaddr, dcb.operrsta,
D 5
				    dcb.err_code, verbosity);
E 5
I 5
				    dcb.err_code, "read", verbosity);
E 5
E 2
				break;
			}
D 2
			pattern_count = 16;
			for(i = 0; i < CURRENT->vc_nsec; i++) {
E 2
I 2
D 4
			for (i = 0; i < CURRENT->vc_nsec; i++) {
E 4
I 4
			for (i = 0; i < lab->d_nsectors; i++) {
E 4
E 2
D 5
				register long	*next;

E 5
				dskaddr->sector = i;
D 5
				next = &scratch[i * offset];
D 2
				access_dsk((char *)next,dskaddr,RD,1,1);
				if(!data_ok()) {
					flag_sector(dskaddr,
					    dcb.operrsta,verbosity);
				}
E 2
I 2
D 3
				access_dsk((char *)next, dskaddr, RD, 1, 1);
E 3
I 3
				access_dsk((char *)next, dskaddr, VDOP_RD, 1,1);
E 5
I 5
				access_dsk((char *)&scratch[i * offset],
				    dskaddr, VDOP_RD, 1,1);
E 5
E 3
				if (!data_ok())
					flag_sector(dskaddr, dcb.operrsta,
D 5
					    dcb.err_code, verbosity);
E 5
I 5
					    dcb.err_code, "read", verbosity);
E 5
E 2
			}
			dskaddr->sector = (char)0;
		}
D 2
		if(index+1 < pattern_count)
E 2
I 2
		if (index+1 < pattern_count)
E 2
			access_dsk((char *)pattern_address[index+1],
D 3
			    dskaddr, WD, CURRENT->vc_nsec, 0);
E 3
I 3
D 4
			    dskaddr, VDOP_WD, CURRENT->vc_nsec, 0);
E 3
		count = CURRENT->vc_nsec * offset;
E 4
I 4
			    dskaddr, VDOP_WD, lab->d_nsectors, 0);
		count = lab->d_nsectors * offset;
E 4
		before = *pattern_address[index];
		after = scratch;
D 2
		for(i=0; i<count; i++) {
			if(before != *(after++)) {
				dskaddr->sector = i / offset;
				flag_sector(dskaddr, DATA_ERROR, verbosity);
E 2
I 2
D 5
		for (i = 0; i < count; i++) {
E 5
I 5
		for (i = 0; i < count; ) {
E 5
			if (before != *(after++)) {
				dskaddr->sector = (char)(i / offset);
D 5
				if (dskaddr->sector != sectorflagged)
					flag_sector(dskaddr, 0, 0,
					    verbosity);
				sectorflagged = dskaddr->sector;
E 2
			}
E 5
I 5
				flag_sector(dskaddr, 0, 0,
				    "data compare", verbosity);
				i = (dskaddr->sector + 1) * offset;
				after = scratch + i;
			} else
				++i;
E 5
		}
D 2
		if(index+1 <= pattern_count) {
E 2
I 2
		if (index+1 < pattern_count) {
E 2
			poll(60);
D 2
			if(vdtimeout <= 0) {
E 2
I 2
			if (vdtimeout <= 0) {
E 2
D 5
				printf(" while verifing track.\n");
E 5
I 5
				printf(" while writing track.\n");
E 5
				_longjmp(abort_environ, 1);
			}
		}
D 2
		if(kill_processes == true) {
E 2
I 2
		if (kill_processes == true) {
E 2
			sync_bad_sector_map();
			_longjmp(quit_environ, 1);
		}
	}
I 4
	/* check again in case of header error */
	if (kill_processes == true) {
		sync_bad_sector_map();
		_longjmp(quit_environ, 1);
	}
E 4
}


D 2
flag_sector(dskaddr, status, verbose)
E 2
I 2
D 5
flag_sector(dskaddr, status, ecode, verbosity)
E 5
I 5
flag_sector(dskaddr, status, ecode, func, verbosity)
E 5
E 2
dskadr	*dskaddr;
long	status;
D 2
int	verbose;
E 2
I 2
int	ecode;
I 5
char	*func;
E 5
int	verbosity;
E 2
{
	fmt_err		error;
	bs_entry	entry;
I 5
	int		result;
E 5

D 5
	indent();
D 2
	if(verbose) {
		print("Error at sector %d, status=0x%x.",
		    to_sector(*dskaddr), status);
		printf("  Sector will be relocated.\n");
E 2
I 2
	if (verbosity != 0) {
		print("Error at sector %d (cyl %d trk %d sect %d),\n",
		    to_sector(*dskaddr), dskaddr->cylinder, dskaddr->track,
		    dskaddr->sector);
		if (status)
E 5
I 5
	error.err_adr = *dskaddr;
	error.err_stat = status;
	(*C_INFO->code_pos)(&error, &entry);
	result = add_flaw(&entry);
	if (verbosity != 0 && result != 0) {
		indent();
		print("%s error at sector %d (cyl %d trk %d sect %d)",
		    func, to_sector(*dskaddr), dskaddr->cylinder,
		    dskaddr->track, dskaddr->sector);
		if (status) {
			printf(",\n");
E 5
D 3
			print("  status=%b", status, ERRBITS);
E 3
I 3
			print("  status=%b", status, VDERRBITS);
E 3
D 5
		else
			printf("  data comparison error");
D 3
		if (C_INFO.type == SMD_ECTLR && ecode)
E 3
I 3
D 4
		if (C_INFO.type == VDTYPE_SMDE && ecode)
E 4
I 4
		if (C_INFO->type == VDTYPE_SMDE && ecode)
E 4
E 3
			printf(", ecode=0x%x", ecode);
		printf(".\n  Sector will be relocated.\n");
E 5
I 5
			if (C_INFO->type == VDTYPE_SMDE && ecode)
				printf(", ecode=0x%x", ecode);
		}
		printf(".\n");
		switch (result) {
		case 1:
			print("%s will be relocated.\n",
			    (status & HEADER_ERROR &&
			    C_INFO->type == VDTYPE_SMDE) ? "Track" : "Sector");
			break;
		case -1:
			print("Sector cannot be relocated.\n");
			break;
		}
		exdent(1);
E 5
E 2
	}
D 5
	if(is_in_map(dskaddr) == false) {
		error.err_adr = *dskaddr;
		error.err_stat = status;
D 4
		entry = (*C_INFO.code_pos)(error);
E 4
I 4
		entry = (*C_INFO->code_pos)(error);
E 4
		add_flaw(&entry);
	}
	exdent(1);
E 5
}
E 1
