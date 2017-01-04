h10912
s 00100/00068/00643
d D 1.7 88/06/07 14:33:07 karels 7 6
c fix relocate (I think) and correct, add command to clear corrections,
c don't preserve user- and verify-detected flaws on reformat; *don't* pass
c structures back and forth incessantly
e
s 00006/00006/00705
d D 1.6 88/05/31 08:45:02 karels 6 5
c get rid of private blk* routines, use (faster) libc versions
e
s 00080/00080/00631
d D 1.5 87/11/23 15:28:42 karels 5 4
c working again, I think
e
s 00012/00012/00699
d D 1.4 87/06/01 20:59:20 sam 4 3
c header file changes (guess this works, noone's complained)
e
s 00000/00008/00711
d D 1.3 86/12/23 13:43:48 karels 3 2
c rm debugging
e
s 00030/00014/00689
d D 1.2 86/11/04 21:24:10 karels 2 1
c version working with eagles, many cleanups and fixes
e
s 00703/00000/00000
d D 1.1 86/07/05 17:37:37 sam 1 0
c date and time created 86/07/05 17:37:37 by sam
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


/*
**
*/

boolean align_buf(buf, sync)
unsigned long	*buf;
unsigned long	sync;
{
	register int	i, shift;

	/* find shift amount */
D 5
	for(shift=0; shift<32; shift++) {
E 5
I 5
	for(shift=0; shift < 32; shift++) {
E 5
		if((*buf >> shift ) == sync) {
			for(i=(512/sizeof(long))-1; i >= 0; i--) {
				*(buf+i+1) |= *(buf+i) << (32 - shift);
				*(buf+i) = *(buf+i) >> shift;
			}
			return true;
		}
	}
	return false;
}


/*
**	Looks for two maps in a row that are the same.
*/

D 2
boolean read_map(flags)
E 2
I 2
boolean
read_map(flags)
E 2
short	flags;
{
	register int	trk, i;
	dskadr		dskaddr;

D 5
	dskaddr.cylinder = (CURRENT->vc_ncyl - 1) | flags;
	for(i=0; i<100; i++)
E 5
I 5
	dskaddr.cylinder = (lab->d_ncylinders - 1) | flags;
	for(i=0; i < 100; i++)
E 5
		scratch[i] = -1;
D 5
	for(trk=0; trk<CURRENT->vc_ntrak; trk++) {
E 5
I 5
	for(trk=0; trk < lab->d_ntracks; trk++) {
E 5
		dskaddr.track = trk;
		dskaddr.sector = 0;
D 4
		if(access_dsk((char *)save,&dskaddr,RD,CURRENT->vc_nsec,1)& HRDERR)
E 4
I 4
		if(access_dsk((char *)save,&dskaddr, VDOP_RD,
D 5
		    CURRENT->vc_nsec,1)& VDERR_HARD)
E 5
I 5
		    lab->d_nsectors,1)& VDERR_HARD)
E 5
E 4
			continue;
D 6
		if(blkcmp((char *)scratch, (char *)save, bytes_trk) == true) {
			blkcopy((char *)save, (char *)bad_map, bytes_trk);
E 6
I 6
		if(bcmp((char *)scratch, (char *)save, bytes_trk) == true) {
			bcopy((char *)save, (char *)bad_map, bytes_trk);
E 6
			if(bad_map->bs_count <= MAX_FLAWS) {
D 5
				for(i=0; i<bad_map->bs_count; i++) {
E 5
I 5
				for(i=0; i < bad_map->bs_count; i++) {
E 5
					if(bad_map->list[i].bs_cyl >=
D 5
					    CURRENT->vc_ncyl)
E 5
I 5
					    lab->d_ncylinders)
E 5
						break;
					if(bad_map->list[i].bs_trk >=
D 5
					    CURRENT->vc_ntrak)
E 5
I 5
					    lab->d_ntracks)
E 5
						break;
					if(bad_map->list[i].bs_offset >=
D 5
					    CURRENT->vc_traksize)
E 5
I 5
					    lab->d_traksize)
E 5
						break;
				}
				if(i == bad_map->bs_count) {
					load_free_table();
					return true;
				}
D 2
			} 
E 2
I 2
D 3
else
printf("%d: junk, slot %d/%d\n", trk, i, bad_map->bs_count);
E 3
			}
E 2
D 6
			blkzero(bad_map, bytes_trk);
E 6
I 6
			bzero(bad_map, bytes_trk);
E 6
			bad_map->bs_id = 0;
			bad_map->bs_max = MAX_FLAWS;
		}
D 6
		blkcopy((char *)save, (char *)scratch, bytes_trk);
E 6
I 6
		bcopy((char *)save, (char *)scratch, bytes_trk);
E 6
	}
	return false;
}


/*
**
*/

boolean read_bad_sector_map()
{
	dskadr		dskaddr;

D 5
	dskaddr.cylinder = CURRENT->vc_ncyl - 1;
E 5
I 5
	dskaddr.cylinder = lab->d_ncylinders - 1;
E 5
	dskaddr.track = 0;
	dskaddr.sector = 0;
	/* start with nothing in map */
D 6
	blkzero(bad_map, bytes_trk);
E 6
I 6
	bzero(bad_map, bytes_trk);
E 6
	bad_map->bs_id = 0;
	bad_map->bs_max = MAX_FLAWS;
D 2
	if(C_INFO.type == SMD_ECTLR) {
E 2
I 2
D 4
	if (C_INFO.type == SMD_ECTLR) {
E 2
		access_dsk((char *)save, &dskaddr, RD_RAW, 1, 1);
E 4
I 4
D 5
	if (C_INFO.type == VDTYPE_SMDE) {
E 5
I 5
	if (C_INFO->type == VDTYPE_SMDE) {
E 5
		access_dsk((char *)save, &dskaddr, VDOP_RDRAW, 1, 1);
E 4
D 2
		if(align_buf((unsigned long *)save, CDCSYNC) == true) {
E 2
I 2
		if (align_buf((unsigned long *)save, CDCSYNC) == true) {
D 3
printf("Reading manufacturer's flaw maps...");
E 3
E 2
			read_flaw_map();
D 2
			return false;
		}
		if(read_map(NRM) == false) {
E 2
I 2
D 3
printf("\n");
E 3
			return (false);
		} else if (read_map(NRM) == true) {
			return (true);
		} else {
D 3
printf("Scanning for old relocations...");
E 3
E 2
			get_smde_relocations();
I 2
D 3
printf("\n");
E 3
E 2
			return false;
		}
I 2
	} else {
		if (read_map(WPT) == true)
			return (true);
		else {
D 3
printf("Scanning for old relocations...");
E 3
			get_relocations_the_hard_way();
D 3
printf("\n");
E 3
			return (false);
		}
E 2
	}
D 2
	else if(read_map(WPT) == false) {
		get_relocations_the_hard_way();
		return false;
	}
	return true;
E 2
}


/*
**
*/

get_relocations_the_hard_way()
{
	register int	cyl, trk;
	register int	status;
	dskadr		dskaddr;

	dskaddr.sector = 0;
	/* scan each sector to see if it is relocated and take note if it is */
D 5
	for(cyl=0; cyl<CURRENT->vc_ncyl-NUMSYS; cyl++) {
E 5
I 5
	for(cyl=0; cyl < lab->d_ncylinders - NUMSYS; cyl++) {
E 5
		dskaddr.cylinder = cyl;
D 5
		for(trk=0; trk<CURRENT->vc_ntrak; trk++) {
E 5
I 5
		for(trk=0; trk < lab->d_ntracks; trk++) {
E 5
			dskaddr.track = trk;
			status=access_dsk((char *)scratch, &dskaddr,
D 4
			    RD, CURRENT->vc_nsec, 1);
			if(status & ALTACC)
E 4
I 4
D 5
			    VDOP_RD, CURRENT->vc_nsec, 1);
E 5
I 5
			    VDOP_RD, lab->d_nsectors, 1);
E 5
			if(status & DCBS_ATA)
E 4
				get_track_relocations(dskaddr);
		}
	}
	load_free_table();
}


/*
**
*/

get_track_relocations(dskaddr)
dskadr	dskaddr;
{
	register int	status;
	bs_entry	temp;
	fmt_err		error;
	
D 5
	for(dskaddr.sector=0; dskaddr.sector<CURRENT->vc_nsec; dskaddr.sector++) {
E 5
I 5
	for(dskaddr.sector=0; dskaddr.sector < lab->d_nsectors; dskaddr.sector++) {
E 5
D 4
		status = access_dsk((char *)scratch, &dskaddr, RD, 1, 1);
		if(status & ALTACC) {
E 4
I 4
		status = access_dsk((char *)scratch, &dskaddr, VDOP_RD, 1, 1);
		if(status & DCBS_ATA) {
E 4
			error.err_adr = dskaddr;
			error.err_stat = DATA_ERROR;
D 5
			temp = (*C_INFO.code_pos)(error);
E 5
I 5
D 7
			temp = (*C_INFO->code_pos)(error);
E 7
I 7
			(*C_INFO->code_pos)(&error, &temp);
E 7
E 5
			temp.bs_how = operator;
			add_flaw(&temp);
		}
	}
}


/*
**
*/

remove_user_relocations(entry)
D 7
bs_entry	entry;
E 7
I 7
bs_entry	*entry;
E 7
{
	register int	i, j;
	fmt_err		temp;
	fmt_err		error;
D 7
	bs_entry	*ptr;	
E 7
I 7
	register bs_entry *ptr;	
E 7

D 5
	error = (*C_INFO.decode_pos)(entry);
E 5
I 5
D 7
	error = (*C_INFO->decode_pos)(entry);
E 5
	if(is_in_map(&error.err_adr) == true) {
		ptr = bad_map->list;
D 5
		for(i=0; i<bad_map->bs_count; i++) {
			temp = (*C_INFO.decode_pos)(*ptr);
E 5
I 5
		for(i=0; i < bad_map->bs_count; i++) {
			temp = (*C_INFO->decode_pos)(*ptr);
E 5
			if((ptr->bs_how == operator) &&
			    (temp.err_adr.cylinder == error.err_adr.cylinder) &&
			    (temp.err_adr.track == error.err_adr.track) &&
			    (temp.err_adr.sector == error.err_adr.sector)) {
E 7
I 7
	(*C_INFO->decode_pos)(entry, &error);
	ptr = bad_map->list;
	for(i=0; i < bad_map->bs_count; i++) {
		if (ptr->bs_cyl != entry->bs_cyl ||
		    ptr->bs_trk != entry->bs_trk)
			continue;
		(*C_INFO->decode_pos)(ptr, &temp);
		if((ptr->bs_how != flaw_map) &&
		    (temp.err_adr.cylinder == error.err_adr.cylinder) &&
		    (temp.err_adr.track == error.err_adr.track) &&
		    (temp.err_adr.sector == error.err_adr.sector)) {
			if(temp.err_stat & HEADER_ERROR)
				remove_track(&temp, ptr);
			else
				remove_sector(&temp, ptr);
			for(j=i+1; j < bad_map->bs_count; j++)
				bad_map->list[j-1] = bad_map->list[j];
			bad_map->bs_count--;
			return;
		}
		ptr++;
	}
	indent();
	print("Sector %d is not in bad sector map!\n",
	    to_sector(error.err_adr));
	exdent(1);
}

clear_relocations(reformat)
boolean reformat;
{
	fmt_err		temp;
	register bs_entry *ptr1, *ptr2, *end;	
	int oldsub = cur.substate;

	cur.substate = sub_rel;
	ptr1 = bad_map->list;
	ptr2 = bad_map->list;
	end = &bad_map->list[bad_map->bs_count];
	for (; ptr1 < end; ptr1++) {
		if (ptr1->bs_how != flaw_map) {
			if (reformat == true) {
				(*C_INFO->decode_pos)(ptr1, &temp);
E 7
				if(temp.err_stat & HEADER_ERROR)
D 7
					remove_track(temp, ptr);
E 7
I 7
					remove_track(&temp, ptr1);
E 7
				else
D 7
					remove_sector(temp, ptr);
D 5
				for(j=i+1; j<bad_map->bs_count; j++)
E 5
I 5
				for(j=i+1; j < bad_map->bs_count; j++)
E 5
					bad_map->list[j-1] = bad_map->list[j];
				bad_map->bs_count--;
				return;
E 7
I 7
					remove_sector(&temp, ptr1);
E 7
			}
D 7
			ptr++;
E 7
I 7
			bad_map->bs_count--;
		} else {
			if (ptr1 != ptr2)
				*ptr2 = *ptr1;
			ptr2++;
E 7
		}
	}
D 7
	else {
		indent();
		print("Sector %d is not in bad sector map!\n",
		    to_sector(error.err_adr));
		exdent(1);
	}
E 7
I 7
	cur.substate = oldsub;
E 7
}


/*
**
*/

remove_sector(error, entry)
D 7
fmt_err		error;
E 7
I 7
fmt_err		*error;
E 7
bs_entry	*entry;
{
D 7
	format_sectors(&error.err_adr, &error.err_adr, NRM, 1);
E 7
I 7
	format_sectors(&error->err_adr, &error->err_adr, NRM, 1);
E 7
	format_sectors(&entry->bs_alt, &entry->bs_alt, NRM, 1);
}


/*
**
*/

remove_track(error, entry)
D 7
fmt_err		error;
E 7
I 7
fmt_err		*error;
E 7
bs_entry	*entry;
{
D 5
	format_sectors(&error.err_adr,&error.err_adr,NRM,(long)CURRENT->vc_nsec);
	format_sectors(&entry->bs_alt,&entry->bs_alt,NRM,(long)CURRENT->vc_nsec);
E 5
I 5
D 7
	format_sectors(&error.err_adr,&error.err_adr,NRM,(long)lab->d_nsectors);
E 7
I 7
	format_sectors(&error->err_adr,&error->err_adr,NRM,(long)lab->d_nsectors);
E 7
	format_sectors(&entry->bs_alt,&entry->bs_alt,NRM,(long)lab->d_nsectors);
E 5
}


/*
**
*/

write_bad_sector_map()
{
	register int	trk, sec;
	dskadr		dskaddr;

D 5
	dskaddr.cylinder = (CURRENT->vc_ncyl - NUMMAP);
	for(trk=0; trk<CURRENT->vc_ntrak; trk++) {
		for(sec = 0; sec < CURRENT->vc_nsec; sec++) {
D 2
			blkcopy((char *)&bs_map_space[sec * SECSIZ],
E 2
I 2
			blkcopy((char *)bs_map_space + (sec * SECSIZ),
E 2
			    (char *)scratch, SECSIZ);
E 5
I 5
	dskaddr.cylinder = (lab->d_ncylinders - NUMMAP);
	for(trk=0; trk < lab->d_ntracks; trk++) {
		for(sec = 0; sec < lab->d_nsectors; sec++) {
D 6
			blkcopy((char *)bs_map_space + (sec * lab->d_secsize),
E 6
I 6
			bcopy((char *)bs_map_space + (sec * lab->d_secsize),
E 6
			    (char *)scratch, lab->d_secsize);
E 5
			dskaddr.track = trk;
			dskaddr.sector = sec;
			format_sectors(&dskaddr, &dskaddr, WPT, 1);
		}
	}
}


/*
**
*/

zero_bad_sector_map()
{
	bs_map		*bm = bad_map;
	register int	i;
	dskadr		zero;

	zero.cylinder = 0;
	zero.track = 0;
	zero.sector = 0;
D 5
	for(i=0; i<bm->bs_count; i++)
E 5
I 5
	for(i=0; i < bm->bs_count; i++)
E 5
		bm->list[i].bs_alt = zero;
	load_free_table();
}


/*
**
*/

read_flaw_map()
{
	register int	cyl, trk;
	dskadr		dskaddr;
	flaw		buffer;

	dskaddr.sector = 0;
D 5
	for  (cyl=0; cyl<CURRENT->vc_ncyl; cyl++) {
E 5
I 5
	for  (cyl=0; cyl < lab->d_ncylinders; cyl++) {
E 5
		dskaddr.cylinder = cyl;
D 5
		for  (trk=0; trk<CURRENT->vc_ntrak; trk++) {
E 5
I 5
		for  (trk=0; trk < lab->d_ntracks; trk++) {
E 5
			dskaddr.track = trk;
D 4
			access_dsk(&buffer, &dskaddr, RD_RAW, 1, 1);
E 4
I 4
			access_dsk(&buffer, &dskaddr, VDOP_RDRAW, 1, 1);
E 4
			if(align_buf(&buffer, CDCSYNC) == true) {
				add_flaw_entries(&buffer);
				continue;
			}
		}	
	}
	load_free_table();
}


/*
**
*/

get_smde_relocations()
{
	register int	cyl, trk, sec;
	smde_hdr	buffer;
	dskadr		dskaddr;
	fmt_err		bad;
	bs_entry	temp;
	boolean		bad_track;

	/* Read any old drive relocations */
D 5
	for(cyl=0; cyl<NUMREL; cyl++) {
		dskaddr.cylinder = CURRENT->vc_ncyl - NUMSYS + cyl;
		for(trk=0; trk<CURRENT->vc_ntrak; trk++) {
E 5
I 5
	for(cyl=0; cyl < NUMREL; cyl++) {
		dskaddr.cylinder = lab->d_ncylinders - NUMSYS + cyl;
		for(trk=0; trk < lab->d_ntracks; trk++) {
E 5
			dskaddr.track = trk;
			bad_track = true;
D 5
			for(sec=0; sec<CURRENT->vc_nsec; sec++) {
E 5
I 5
			for(sec=0; sec < lab->d_nsectors; sec++) {
E 5
				dskaddr.sector = sec;
D 4
				access_dsk(&buffer, &dskaddr, RD_RAW, 1, 1);
E 4
I 4
				access_dsk(&buffer, &dskaddr, VDOP_RDRAW, 1, 1);
E 4
				if(align_buf(&buffer, SMDE1SYNC) == false) {
					bad_track = false;
					break;
				}
			}
			if(bad_track == true) {
				dskaddr.sector = 0;
				bad.err_adr.cylinder = buffer.alt_cyl;
				bad.err_adr.track = buffer.alt_trk;
				bad.err_adr.sector = 0;
				bad.err_stat = HEADER_ERROR;
D 5
				temp = (*C_INFO.code_pos)(bad);
E 5
I 5
D 7
				temp = (*C_INFO->code_pos)(bad);
E 7
I 7
				(*C_INFO->code_pos)(&bad, &temp);
E 7
E 5
				temp.bs_alt = dskaddr;
				temp.bs_how = scanning;
				add_flaw(&temp);
				continue;
			}
D 5
			for(sec=0; sec<CURRENT->vc_nsec; sec++) {
E 5
I 5
			for(sec=0; sec < lab->d_nsectors; sec++) {
E 5
				dskaddr.sector = sec;
D 4
				access_dsk(&buffer, &dskaddr, RD_RAW, 1, 1);
E 4
I 4
				access_dsk(&buffer, &dskaddr, VDOP_RDRAW, 1, 1);
E 4
				if(align_buf(&buffer, SMDE1SYNC) == true) {
					bad.err_adr.cylinder = buffer.alt_cyl;
					bad.err_adr.track = buffer.alt_trk;
					bad.err_adr.sector = buffer.alt_sec;
					bad.err_stat = DATA_ERROR;
D 5
					temp = (*C_INFO.code_pos)(bad);
E 5
I 5
D 7
					temp = (*C_INFO->code_pos)(bad);
E 7
I 7
					(*C_INFO->code_pos)(&bad, &temp);
E 7
E 5
					temp.bs_alt = dskaddr;
					temp.bs_how = scanning;
					add_flaw(&temp);
				}
			}
		}
	}
	load_free_table();
}


/*
**
*/

add_flaw_entries(buffer)
flaw	*buffer;
{
	register int	i;
	bs_entry	temp;

	temp.bs_cyl = buffer->flaw_cyl & 0x7fff; /* clear off bad track bit */
	temp.bs_trk = buffer->flaw_trk;
D 5
	for(i=0; i<4; i++) {
E 5
I 5
	for(i=0; i < 4; i++) {
E 5
		if(buffer->flaw_pos[i].flaw_length != 0) {
			temp.bs_offset = buffer->flaw_pos[i].flaw_offset;
			temp.bs_length = buffer->flaw_pos[i].flaw_length;
			temp.bs_alt.cylinder = 0;
			temp.bs_alt.track = 0;
			temp.bs_alt.sector = 0;
			temp.bs_how = flaw_map;
			add_flaw(&temp);
		}
	}
}


cmp_entry(a, b)
bs_entry	*a;
bs_entry	*b;
{
	if(a->bs_cyl == b->bs_cyl) {
		if(a->bs_trk == b->bs_trk) {
			if(a->bs_offset == b->bs_offset)
				return 0;
			else if(a->bs_offset < b->bs_offset)
				return -1;
D 2
		}
E 2
I 2
		 }
E 2
		else if(a->bs_trk < b->bs_trk)
			return -1;
	}
	else if(a->bs_cyl < b->bs_cyl)
		return -1;
	return 1;
}


I 7
/*
 * Add flaw to map.
 * Return value:
 *   1	OK
 *   0	sector was in map
 *  -1	failure
 */
E 7
add_flaw(entry)
bs_entry	*entry;
{
	extern	int	cmp_entry();
	bs_map		*bm = bad_map;
	register int	i;

	if(bm->bs_count > MAX_FLAWS)
I 2
D 7
		return;
E 7
I 7
		return (-1);
E 7
D 5
	if (entry->bs_cyl >= CURRENT->vc_ncyl ||
	    entry->bs_trk >= CURRENT->vc_ntrak ||
	    entry->bs_offset >= CURRENT->vc_traksize)
E 5
I 5
	if (entry->bs_cyl >= lab->d_ncylinders ||
	    entry->bs_trk >= lab->d_ntracks ||
	    entry->bs_offset >= lab->d_traksize)
E 5
E 2
D 7
		return;
E 7
I 7
		return (-1);
E 7
D 5
	for(i=0; i<bm->bs_count; i++) {
E 5
I 5
	for(i=0; i < bm->bs_count; i++) {
E 5
		if(((bm->list[i].bs_cyl == entry->bs_cyl)) &&
		    (bm->list[i].bs_trk == entry->bs_trk) &&
		    (bm->list[i].bs_offset == entry->bs_offset)) {
			if((int)bm->list[i].bs_how > (int)entry->bs_how)
				bm->list[i].bs_how = entry->bs_how;
D 7
			return;
E 7
I 7
			return (0);
E 7
		}
	}
	bm->list[i] = *entry;
	bm->list[i].bs_alt.cylinder = 0;
	bm->list[i].bs_alt.track = 0;
	bm->list[i].bs_alt.sector = 0;
	bm->bs_count++;
	qsort((char *)&(bm->list[0]), (unsigned)bm->bs_count,
	    sizeof(bs_entry), cmp_entry);
I 7
	return (1);
E 7
}


/*
**	Is_in_map checks to see if a block is known to be bad already.
*/

boolean is_in_map(dskaddr)
dskadr	*dskaddr;
{
	register int	i;
	fmt_err		temp;

D 5
	for(i=0; i<bad_map->bs_count; i++) {
		temp = (*C_INFO.decode_pos)(bad_map->list[i]);
E 5
I 5
	for(i=0; i < bad_map->bs_count; i++) {
D 7
		temp = (*C_INFO->decode_pos)(bad_map->list[i]);
E 7
I 7
		(*C_INFO->decode_pos)(&bad_map->list[i], &temp);
E 7
E 5
		if((temp.err_adr.cylinder == dskaddr->cylinder) &&
		    (temp.err_adr.track == dskaddr->track) &&
		    (temp.err_adr.sector == dskaddr->sector)) {
			return true;
		}
	}
	return false;
}


/*
**
*/

print_bad_sector_list()
{
	register int	i;
	fmt_err		errloc;
I 7
	register bs_entry *bad;
E 7

	if(bad_map->bs_count == 0) {
		print("There are no bad sectors in bad sector map.\n");
		return;
	}
	print("The following sector%s known to be bad:\n",
	    (bad_map->bs_count == 1) ? " is" : "s are");
	indent();
D 5
	for(i=0; i<bad_map->bs_count; i++) {
E 5
I 5
D 7
	for(i=0; i < bad_map->bs_count; i++) {
E 5
		print("cyl %d, head %d, pos %d, len %d ",
			bad_map->list[i].bs_cyl,
			bad_map->list[i].bs_trk,
			bad_map->list[i].bs_offset,
			bad_map->list[i].bs_length);
D 5
		errloc = (*C_INFO.decode_pos)(bad_map->list[i]);
E 5
I 5
		errloc = (*C_INFO->decode_pos)(bad_map->list[i]);
E 5
		if(errloc.err_stat & HEADER_ERROR) {
			printf("(Track #%d)", to_track(errloc.err_adr));
E 7
I 7
	for(i=0, bad = bad_map->list; i < bad_map->bs_count; i++, bad++) {
		(*C_INFO->decode_pos)(bad, &errloc);
		print("%s %d cn %d tn %d sn %d pos %d len %d ",
			errloc.err_stat & HEADER_ERROR ? "Track@" : "Sector",
			to_sector(errloc.err_adr),
			bad->bs_cyl,
			bad->bs_trk,
			errloc.err_adr.sector,
			bad->bs_offset,
			bad->bs_length);
		if (bad->bs_how == flaw_map)
			printf("(flawmap) ");
		else if (bad->bs_how == scanning)
			printf("(verify) ");
		else
			printf("(operator) ");
		if((bad->bs_alt.cylinder != 0) || (bad->bs_alt.track != 0) ||
		    (bad->bs_alt.sector != 0)) {
			printf("-> ");
			printf("cn %d tn %d sn %d", bad->bs_alt.cylinder,
			    bad->bs_alt.track, bad->bs_alt.sector);
E 7
		}
D 7
		else {
			printf("(Sector #%d)", to_sector(errloc.err_adr));
		}
		if((bad_map->list[i].bs_alt.cylinder != 0) ||
		    (bad_map->list[i].bs_alt.track != 0) ||
		    (bad_map->list[i].bs_alt.sector != 0)) {
			indent();
			printf(" -> ");
			if(errloc.err_stat & HEADER_ERROR) {
				printf("Track %d",
		    		    to_track(bad_map->list[i].bs_alt));
			}
			else {
				printf("Sector %d",
		    		    to_sector(bad_map->list[i].bs_alt));
			}
			exdent(1);
		}
		printf(".\n");
E 7
I 7
		printf("\n");
E 7
	}
	exdent(1);
}


/*
D 7
**	Vdload_free_table checks each block in the bad block relocation area
E 7
I 7
**	load_free_table checks each block in the bad block relocation area
E 7
** to see if it is used. If it is, the free relocation block table is updated.
*/

load_free_table()
{
	register int	i, j;
	fmt_err		temp;

	/* Clear free table before starting */
D 5
	for(i = 0; i < (CURRENT->vc_ntrak * NUMREL); i++) {
		for(j=0; j < CURRENT->vc_nsec; j++)
E 5
I 5
	for(i = 0; i < (lab->d_ntracks * NUMREL); i++) {
		for(j=0; j < lab->d_nsectors; j++)
E 5
			free_tbl[i][j].free_status = NOTALLOCATED;
	}
D 5
	for(i=0; i<bad_map->bs_count; i++)
E 5
I 5
	for(i=0; i < bad_map->bs_count; i++)
E 5
		if((bad_map->list[i].bs_alt.cylinder != 0) ||
		    (bad_map->list[i].bs_alt.track != 0) ||
		    (bad_map->list[i].bs_alt.sector != 0)) {
D 5
			temp = (*C_INFO.decode_pos)(bad_map->list[i]);
E 5
I 5
D 7
			temp = (*C_INFO->decode_pos)(bad_map->list[i]);
E 7
I 7
			(*C_INFO->decode_pos)(&bad_map->list[i], &temp);
E 7
E 5
			allocate(&(bad_map->list[i].bs_alt), temp.err_stat);
		}
}


/*
**	allocate marks a replacement sector as used.
*/

allocate(dskaddr, status)
dskadr	*dskaddr;
long	status;
{
	register int	trk, sec;

D 5
	trk = dskaddr->cylinder - (CURRENT->vc_ncyl - NUMSYS);
E 5
I 5
	trk = dskaddr->cylinder - (lab->d_ncylinders - NUMSYS);
E 5
	if((trk < 0) || (trk >= NUMREL))
		return;
D 5
	trk *= CURRENT->vc_ntrak;
E 5
I 5
	trk *= lab->d_ntracks;
E 5
	trk += dskaddr->track;
	if(status & HEADER_ERROR)
D 5
		for(sec=0; sec<CURRENT->vc_nsec; sec++)
E 5
I 5
		for(sec=0; sec < lab->d_nsectors; sec++)
E 5
			free_tbl[trk][sec].free_status = ALLOCATED;
	else
		free_tbl[trk][dskaddr->sector].free_status = ALLOCATED;
}


/*
**
*/

boolean mapping_collision(entry)
bs_entry	*entry;
{
	register int	trk, sec;
	fmt_err		temp;

D 5
	trk = entry->bs_cyl - (CURRENT->vc_ncyl - NUMSYS);
E 5
I 5
	trk = entry->bs_cyl - (lab->d_ncylinders - NUMSYS);
E 5
	if((trk < 0) || (trk >= NUMREL))
		return false;
D 5
	trk *= CURRENT->vc_ntrak;
E 5
I 5
	trk *= lab->d_ntracks;
E 5
	trk += entry->bs_trk;
D 5
	temp = (*C_INFO.decode_pos)(*entry);
E 5
I 5
D 7
	temp = (*C_INFO->decode_pos)(*entry);
E 7
I 7
	(*C_INFO->decode_pos)(entry, &temp);
E 7
E 5
	/* if this relocation should take up the whole track */
	if(temp.err_stat & HEADER_ERROR) {
D 5
		for(sec=0; sec<CURRENT->vc_nsec; sec++)
E 5
I 5
		for(sec=0; sec < lab->d_nsectors; sec++)
E 5
			if(free_tbl[trk][sec].free_status == ALLOCATED)
				return true;
	}
	/* else just check the current sector */
	else {
		if(free_tbl[trk][temp.err_adr.sector].free_status == ALLOCATED)
			return true;
	}
	return false;
}


/*
**
*/

report_collision()
{
	indent();
	print("Sector resides in relocation area");
	printf("but it has a sector mapped to it already.\n");
	print("Please reformat disk with 0 patterns to eliminate problem.\n");
	exdent(1);
}


/*
**
*/

add_user_relocations(entry)
bs_entry	*entry;
{
	fmt_err		error;
	
D 5
	error = (*C_INFO.decode_pos)(*entry);
E 5
I 5
D 7
	error = (*C_INFO->decode_pos)(*entry);
E 7
I 7
	(*C_INFO->decode_pos)(entry, &error);
E 7
E 5
	if(is_in_map(&error.err_adr) == false) {
		if(mapping_collision(entry) == true)
			report_collision();
		entry->bs_how = operator;
		add_flaw(entry);
	}
	else {
		indent();
		print("Sector %d is already mapped out!\n",
		    to_sector(error.err_adr));
		exdent(1);
	}
}


/*
** 	New_location allocates a replacement block given a bad block address.
**  The algorithm is fairly simple; it simply searches for the first
**  free sector that has the same sector number of the bad sector.  If no sector
**  is found then the drive should be considered bad because of a microcode bug
**  in the controller that forces us to use the same sector number as the bad
**  sector for relocation purposes.  Using different tracks and cylinders is ok
**  of course.
*/

dskadr *new_location(entry)
bs_entry	*entry;
{
	register int	i, sec;
	static fmt_err	temp;
	static dskadr	newaddr;

	newaddr.cylinder = 0;
	newaddr.track = 0;
	newaddr.sector = 0;
D 5
	temp = (*C_INFO.decode_pos)(*entry);
E 5
I 5
D 7
	temp = (*C_INFO->decode_pos)(*entry);
E 7
I 7
	(*C_INFO->decode_pos)(entry, &temp);
E 7
E 5
	/* If it is ouside of the user's data area */
D 5
	if(entry->bs_cyl >= CURRENT->vc_ncyl-NUMSYS) {
E 5
I 5
	if(entry->bs_cyl >= lab->d_ncylinders-NUMSYS) {
E 5
		/* if it is in the relocation area */
D 5
		if(entry->bs_cyl < (CURRENT->vc_ncyl - NUMMAP - NUMMNT)) {
E 5
I 5
		if(entry->bs_cyl < (lab->d_ncylinders - NUMMAP - NUMMNT)) {
E 5
			/* mark space as allocated */
			allocate(&temp.err_adr, temp.err_stat);
			return &temp.err_adr;
		}
		/* if it is in the map area forget about it */
D 5
		if(entry->bs_cyl != (CURRENT->vc_ncyl - NUMMAP - NUMMNT))
E 5
I 5
		if(entry->bs_cyl != (lab->d_ncylinders - NUMMAP - NUMMNT))
E 5
			return &temp.err_adr;
		/* otherwise treat maintainence cylinder normally */
	}
	if(temp.err_stat & (HEADER_ERROR)) {
D 5
		for(i = 0; i < (CURRENT->vc_ntrak * NUMREL); i++) {
			for(sec=0; sec < CURRENT->vc_nsec; sec++) {
E 5
I 5
		for(i = 0; i < (lab->d_ntracks * NUMREL); i++) {
			for(sec=0; sec < lab->d_nsectors; sec++) {
E 5
				if(free_tbl[i][sec].free_status == ALLOCATED)
					break;
			}
D 5
			if(sec == CURRENT->vc_nsec) {
				for(sec = 0; sec < CURRENT->vc_nsec; sec++)
E 5
I 5
			if(sec == lab->d_nsectors) {
				for(sec = 0; sec < lab->d_nsectors; sec++)
E 5
					free_tbl[i][sec].free_status=ALLOCATED;
D 5
				newaddr.cylinder = i / CURRENT->vc_ntrak +
				    (CURRENT->vc_ncyl - NUMSYS);
				newaddr.track = i % CURRENT->vc_ntrak;
E 5
I 5
				newaddr.cylinder = i / lab->d_ntracks +
				    (lab->d_ncylinders - NUMSYS);
				newaddr.track = i % lab->d_ntracks;
E 5
				break;
			}
		}
	}
D 4
	else if(C_INFO.type == SMDCTLR) {
E 4
I 4
D 5
	else if(C_INFO.type == VDTYPE_VDDC) {
E 4
		for(i = 0; i < (CURRENT->vc_ntrak * NUMREL); i++) {
E 5
I 5
	else if(C_INFO->type == VDTYPE_VDDC) {
		for(i = 0; i < (lab->d_ntracks * NUMREL); i++) {
E 5
			if(free_tbl[i][temp.err_adr.sector].free_status !=
			    ALLOCATED) {
				free_tbl[i][temp.err_adr.sector].free_status =
				    ALLOCATED;
D 5
				newaddr.cylinder = i / CURRENT->vc_ntrak +
				    (CURRENT->vc_ncyl - NUMSYS);
				newaddr.track = i % CURRENT->vc_ntrak;
E 5
I 5
				newaddr.cylinder = i / lab->d_ntracks +
				    (lab->d_ncylinders - NUMSYS);
				newaddr.track = i % lab->d_ntracks;
E 5
				newaddr.sector = temp.err_adr.sector;
				break;
			}	
		}
	}
	else {
D 5
		for(i = 0; i < (CURRENT->vc_ntrak * NUMREL); i++) {
			for(sec=0; sec < CURRENT->vc_nsec; sec++)
E 5
I 5
		for(i = 0; i < (lab->d_ntracks * NUMREL); i++) {
			for(sec=0; sec < lab->d_nsectors; sec++)
E 5
				if(free_tbl[i][sec].free_status != ALLOCATED)
					break;
D 5
			if(sec < CURRENT->vc_nsec) {
E 5
I 5
			if(sec < lab->d_nsectors) {
E 5
				free_tbl[i][sec].free_status = ALLOCATED;
D 5
				newaddr.cylinder = i / CURRENT->vc_ntrak +
				    (CURRENT->vc_ncyl - NUMSYS);
				newaddr.track = i % CURRENT->vc_ntrak;
E 5
I 5
				newaddr.cylinder = i / lab->d_ntracks +
				    (lab->d_ncylinders - NUMSYS);
				newaddr.track = i % lab->d_ntracks;
E 5
				newaddr.sector = sec;
				break;
			}
		}
	}
	return &newaddr;
}
D 4

E 4
E 1
