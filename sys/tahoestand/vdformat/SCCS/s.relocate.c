h26888
s 00029/00033/00353
d D 1.6 88/06/07 14:33:09 karels 6 5
c fix relocate (I think) and correct, add command to clear corrections,
c don't preserve user- and verify-detected flaws on reformat; *don't* pass
c structures back and forth incessantly
e
s 00002/00001/00384
d D 1.5 88/05/31 08:45:49 karels 5 4
c correct info msg
e
s 00035/00030/00350
d D 1.4 87/11/23 15:28:54 karels 4 3
c working again, I think
e
s 00005/00008/00375
d D 1.3 87/06/01 20:59:26 sam 3 2
c header file changes (guess this works, noone's complained)
e
s 00005/00003/00378
d D 1.2 86/11/04 21:25:51 karels 2 1
c cleanups
e
s 00381/00000/00000
d D 1.1 86/07/05 17:37:39 sam 1 0
c date and time created 86/07/05 17:37:39 by sam
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
#include	"cmd.h"

/*
**
*/

relocate()
{
	extern boolean	is_formatted();

	cur.state = rel;
D 2
	print("Adding flaws to bad setor map on ");
E 2
I 2
	print("Adding flaws to bad sector map on ");
E 2
	printf("controller %d, drive %d, ", cur.controller, cur.drive);
D 4
	printf("type %s.\n",CURRENT->vc_name);
E 4
I 4
	printf("type %s.\n", lab->d_typename);
E 4

	indent();
	if(is_formatted() == true) {
		if(read_bad_sector_map() == true)
D 4
			if(bad_map->bs_id != D_INFO.id) {
E 4
I 4
			if(bad_map->bs_id != D_INFO->id) {
E 4
				print("Drive serial numbers do not match!\n");
				exdent(1);
				_longjmp(abort_environ, 1);
			}
		get_new_relocations();
I 6
		cur.substate = sub_wmap;
E 6
		sync_bad_sector_map();
	}
	else
		print("Drive must be formatted befor relocations are done.\n");
	exdent(1);
}


/*
**
*/

rel_help()
{
	indent();
	print("Relocation commands are in the following form:\n");
	indent();
D 4
	print("[a-h] (block)   -  UNIX file system format.\n");
E 4
I 4
D 5
	print("[a-h] (block)   -  UNIX file system block (frag) number.\n");
E 5
I 5
	print("[a-h] (block)   -  UNIX file system block (%s-byte) number.\n",
	    DEV_BSIZE);
E 5
E 4
	print("SEctor (sector) -  Absolute sector number on disk.\n");
	print("Track (track)   -  Absolute disk track number.\n");
	print("(cylinder) (head) (offset) (length) - CDC flaw map format.\n");
	print("STARt           -  Starts relocation process.\n\n");
	exdent(2);
}


/*
**
*/

get_new_relocations()
{
	char		line[256];
	char		*ptr;
	bs_entry	entry;
	dskadr		dskaddr;
I 6
	fmt_err		dskerr;
E 6
	int		max_track;
I 6
	register int	block;
E 6

D 4
	dskaddr.cylinder = CURRENT->vc_ncyl - 1;
	dskaddr.cylinder = CURRENT->vc_ntrak - 1;
E 4
I 4
	dskaddr.cylinder = lab->d_ncylinders - 1;
	dskaddr.cylinder = lab->d_ntracks - 1;
E 4
	max_track = to_track(dskaddr);
	for(;;) {
		print("Location? ");
		get_string_cmd(line, rel_help);
		if(kill_processes == true)
			_longjmp(quit_environ, 1);
		if(line[0] == '\0')
			continue;
		ptr = line;
		trim_white(ptr);
		if(!strncmp(ptr, "he", 2) || !strncmp(ptr, "?", 1) ||
		    !strncmp(ptr, "stat", 4) || !strncmp(ptr, "!", 1))
			continue;
		indent();
		if((*ptr >= 'a') && (*ptr <= 'h')) {
			register char	par = *(ptr++);
D 6
			register int	block = get_next_digit(ptr);
E 6

D 6
			dskaddr = *from_unix((unsigned char)par,
E 6
I 6
			block = get_next_digit(ptr);
			dskerr.err_adr = *from_unix((unsigned char)par,
E 6
			    (unsigned int)block);
D 6
			if((dskaddr.cylinder == -1) || (block == -1)) {
E 6
I 6
			if((dskerr.err_adr.cylinder == -1) || (block == -1)) {
E 6
				print("Invalid UNIX block number!\n");
				goto next;
			}
			print("Confirm block %d on file-system '%c'",block,par);
I 4
D 6
			printf(" (cyl %d, track %d, sector %d)",
			    dskaddr.cylinder, dskaddr.track, dskaddr.sector);
E 6
I 6
			dskerr.err_stat = DATA_ERROR;
		doreloc:
			printf(" (cn %d tn %d sn %d)", dskerr.err_adr.cylinder,
			    dskerr.err_adr.track, dskerr.err_adr.sector);
E 6
E 4
			if(get_yes_no("") == true) {
D 4
				entry=(*C_INFO.code_pos)(dskaddr,HEADER_ERROR);
E 4
I 4
D 6
				entry=(*C_INFO->code_pos)(dskaddr, DATA_ERROR);
E 6
I 6
				(*C_INFO->code_pos)(&dskerr, &entry);
E 6
E 4
				add_user_relocations(&entry);
			}
		}
		else if(*ptr == 't') {
D 6
			register int	trk = get_next_digit(ptr);

			if((trk == -1) || (trk >= max_track)) {
E 6
I 6
			block = get_next_digit(ptr);
			if((block == -1) || (block >= max_track)) {
E 6
				print("Invalid track number!\n");
				goto next;
			}
D 4
			print("Confirm track %d", trk);
E 4
I 4
D 6
			dskaddr = *from_track(trk);
			print("Confirm track %d (cyl %d, track %d)",
			    trk, dskaddr.cylinder, dskaddr.track);
E 4
			if(get_yes_no("") == true) {
D 4
				dskaddr = *from_track(trk);
				entry=(*C_INFO.code_pos)(dskaddr,HEADER_ERROR);
E 4
I 4
				entry=(*C_INFO->code_pos)(dskaddr,HEADER_ERROR);
E 4
				add_user_relocations(&entry);
			}
E 6
I 6
			dskerr.err_adr = *from_track(block);
			dskerr.err_stat = HEADER_ERROR;
			print("Confirm track %d", block);
			goto doreloc;
E 6
		}
		else if(!strncmp(ptr, "se", 2)) {
D 6
			register int	sec = get_next_digit(ptr);
E 6
I 6
			block = get_next_digit(ptr);
E 6

D 6
			if((sec == -1) ||
D 4
			    ((CURRENT->vc_nsec*CURRENT->vc_ntrak*CURRENT->vc_ncyl)<sec)){
E 4
I 4
			    ((lab->d_nsectors*lab->d_ntracks*lab->d_ncylinders)<sec)){
E 6
I 6
			if((block == -1) ||
			    ((lab->d_nsectors*lab->d_ntracks*lab->d_ncylinders)<block)){
E 6
E 4
				print("Invalid sector number!\n");
				goto next;
			}
D 4
			print("Confirm sector %d", sec);
E 4
I 4
D 6
			dskaddr = *from_sector((unsigned int)sec);
			print("Confirm sector %d (cyl %d, track %d, sector %d)",
			    sec,
			    dskaddr.cylinder, dskaddr.track, dskaddr.sector);
E 4
			if(get_yes_no("") == true) {
D 4
				dskaddr = *from_sector((unsigned int)sec);
				entry = (*C_INFO.code_pos)(dskaddr, DATA_ERROR);
E 4
I 4
				entry = (*C_INFO->code_pos)(dskaddr, DATA_ERROR);
E 4
				add_user_relocations(&entry);
			}
E 6
I 6
			dskerr.err_adr = *from_sector((unsigned int)block);
			dskerr.err_stat = DATA_ERROR;
			goto doreloc;
E 6
		}
		else if(is_digit(*ptr)) {
			entry.bs_cyl = get_next_digit(ptr);
			skipdigits(ptr);
			finddigit(ptr);
			entry.bs_trk = get_next_digit(ptr);
			skipdigits(ptr);
			finddigit(ptr);
			entry.bs_offset = get_next_digit(ptr);
			skipdigits(ptr);
			finddigit(ptr);
			entry.bs_length = get_next_digit(ptr);
			if((entry.bs_trk != -1) && (entry.bs_offset != -1) &&
			    (entry.bs_length != -1)) {
D 4
				if(entry.bs_cyl >= CURRENT->vc_ncyl)
E 4
I 4
				if(entry.bs_cyl >= lab->d_ncylinders)
E 4
					print("Cylinder number to high!\n");
D 4
				else if(entry.bs_trk >= CURRENT->vc_ntrak)
E 4
I 4
				else if(entry.bs_trk >= lab->d_ntracks)
E 4
					print("Head number to high!\n");
D 4
				else if(entry.bs_offset >= CURRENT->vc_traksize)
E 4
I 4
				else if(entry.bs_offset >= lab->d_traksize)
E 4
					print("Offset too long!\n");
				else if(entry.bs_length == 0)
					print("Can't have a 0 length error!\n");
				else {
					print("Confirm  Cyl %d, ",entry.bs_cyl);
					printf("Head %d, ", entry.bs_trk);
					printf("offset %d, ", entry.bs_offset);
					printf("length %d", entry.bs_length);
					if(get_yes_no("") == true)
						add_user_relocations(&entry);
				}
			}
			else
				goto bad;
		}
D 2
		else if(!strncmp(ptr, "star", 4)) {
E 2
I 2
		else if(!strncmp(ptr, "start", 4)) {
E 2
			exdent(1);
			break;
		}
		else
bad:			print("What?\n");
next:		exdent(1);
	}
}

dskadr check_track_for_relocations(entry, i)
bs_entry	entry;
register int	i;
{
	register int	j = i;
	fmt_err		temp, cmp;
	boolean		bad_track = false;

D 4
	cmp = (*C_INFO.decode_pos)(entry);
E 4
I 4
D 6
	cmp = (*C_INFO->decode_pos)(entry);
E 6
I 6
	(*C_INFO->decode_pos)(&entry, &cmp);
E 6
E 4
	/* Check to see if a alternate track is or will be on this track */
	while((bad_map->list[j].bs_cyl == entry.bs_cyl) &&
	    (bad_map->list[j].bs_trk == entry.bs_trk)) {
D 4
		temp = (*C_INFO.decode_pos)(bad_map->list[j]);
E 4
I 4
D 6
		temp = (*C_INFO->decode_pos)(bad_map->list[j]);
E 6
I 6
		(*C_INFO->decode_pos)(&bad_map->list[j], &temp);
E 6
E 4
		if(temp.err_stat & HEADER_ERROR) {
			bad_track = true;
			/* if track was mapped out (it can't be us) */
			if(((bad_map->list[j].bs_alt.cylinder != 0)) ||
		    	    (bad_map->list[j].bs_alt.track != 0) ||
		    	    (bad_map->list[j].bs_alt.sector != 0)) {
				return cmp.err_adr;
			}
		}
		j++;
	}
	/*
	**    If it was a bad track and it was not the current entry
	** that produced it then then map it
	** to itself and forget about it for now since it will be taken
	** care of later.
	**
	**    If it was the current entry return zero and the track will be
	** mapped out correctly.
	*/
	if(bad_track == true) {
		if(cmp.err_stat & HEADER_ERROR)
			return entry.bs_alt; /* better known as zero */
		else
			return cmp.err_adr;
	}
	/*
	**   if we made it through all the bad track stuff then check for
	** multiple errors on the same sector that are already mapped!
	*/
	j = i;
	while((bad_map->list[j].bs_cyl == entry.bs_cyl) &&
	    (bad_map->list[j].bs_trk == entry.bs_trk)) {
D 4
		temp = (*C_INFO.decode_pos)(bad_map->list[j]);
E 4
I 4
D 6
		temp = (*C_INFO->decode_pos)(bad_map->list[j]);
E 6
I 6
		(*C_INFO->decode_pos)(&bad_map->list[j], &temp);
E 6
E 4
		if(temp.err_adr.sector == cmp.err_adr.sector) {
			/* if it is not really the current entry */
			if((bad_map->list[j].bs_offset != entry.bs_offset) ||
			    (bad_map->list[j].bs_length != entry.bs_length)) { 
				/* if the sector is already mapped out */
				if(((bad_map->list[j].bs_alt.cylinder != 0)) ||
		   	 	    (bad_map->list[j].bs_alt.track != 0) ||
		    		    (bad_map->list[j].bs_alt.sector != 0)) {
					return temp.err_adr;
				}
			}
		}
		j++;
	}
	return	entry.bs_alt;
}


/*
**
*/

dskadr	is_relocated(entry)
bs_entry	entry;
{
	register int	i;

	for(i=0; i<bad_map->bs_count; i++)
		if((bad_map->list[i].bs_cyl == entry.bs_cyl) &&
		    (bad_map->list[i].bs_trk == entry.bs_trk))
			return check_track_for_relocations(entry, i);
	return entry.bs_alt;
}



/*
**
*/

sync_bad_sector_map()
{
	register int	i;
	dskadr		dskaddr;

	/*
	** do all the relocation cylinders first to allocate all flaws in
	** relocation area.
	*/
	for(i=bad_map->bs_count-1; i>=0; i--) {
D 4
		if((bad_map->list[i].bs_cyl >= CURRENT->vc_ncyl-NUMSYS) &&
		    (bad_map->list[i].bs_cyl < CURRENT->vc_ncyl-NUMMAP-NUMMNT)) {
E 4
I 4
		if((bad_map->list[i].bs_cyl >= lab->d_ncylinders-NUMSYS) &&
		    (bad_map->list[i].bs_cyl < lab->d_ncylinders-NUMMAP-NUMMNT)) {
E 4
			if((bad_map->list[i].bs_alt.cylinder == 0) &&
			    (bad_map->list[i].bs_alt.track == 0) &&
			    (bad_map->list[i].bs_alt.sector == 0)) {
				bad_map->list[i].bs_alt = 
				    *new_location(&bad_map->list[i]);
			}
		}
	}
	for(i=bad_map->bs_count-1; i>=0; i--) {
		if((bad_map->list[i].bs_alt.cylinder == 0) &&
		    (bad_map->list[i].bs_alt.track == 0) &&
		    (bad_map->list[i].bs_alt.sector == 0)) {
			dskaddr = is_relocated(bad_map->list[i]);
			if((dskaddr.cylinder == 0) && (dskaddr.track == 0) &&
			    (dskaddr.sector == 0)) {
				bad_map->list[i].bs_alt = 
				    *new_location(&bad_map->list[i]);
				do_relocation(bad_map->list[i]);
			}
			else
				bad_map->list[i].bs_alt = dskaddr;
		}
	}
	write_bad_sector_map();
}



/*
**
*/

do_relocation(entry)
bs_entry	entry;
{
	fmt_err	temp;

D 4
	if(entry.bs_cyl >= CURRENT->vc_ncyl-NUMSYS)
		if(entry.bs_cyl != (CURRENT->vc_ncyl - NUMMAP - NUMMNT))
E 4
I 4
	if(entry.bs_cyl >= lab->d_ncylinders-NUMSYS)
		if(entry.bs_cyl != (lab->d_ncylinders - NUMMAP - NUMMNT))
E 4
			return;
D 4
	temp = (*C_INFO.decode_pos)(entry);
E 4
I 4
D 6
	temp = (*C_INFO->decode_pos)(entry);
E 6
I 6
	(*C_INFO->decode_pos)(&entry, &temp);
E 6
E 4
	if((entry.bs_alt.cylinder == 0) && (entry.bs_alt.track == 0) &&
	    (entry.bs_alt.sector == 0))
		print_unix_block(temp.err_adr);
	else if(temp.err_stat & HEADER_ERROR)
D 3
		if(C_INFO.type == SMDCTLR) {
E 3
I 3
D 4
		if(C_INFO.type == VDTYPE_VDDC) {
E 4
I 4
		if(C_INFO->type == VDTYPE_VDDC) {
E 4
E 3
			print("Can't relocate tracks on VDDC controllers.\n");
			print_unix_block(temp.err_adr);
		}
		else
			relocate_track(entry);
	else
		relocate_sector(entry);
}


/*
**
*/

relocate_sector(entry)
bs_entry	entry;
{
	dskadr		phys, reloc;
	fmt_err		temp;
	register long	status;

D 4
	temp = (*C_INFO.decode_pos)(entry);
E 4
I 4
D 6
	temp = (*C_INFO->decode_pos)(entry);
E 6
I 6
	(*C_INFO->decode_pos)(&entry, &temp);
E 6
E 4
	phys = temp.err_adr;
	reloc = entry.bs_alt;
	format_sectors(&phys, &reloc, RELOC_SECTOR, (long)1);
	
	format_sectors(&reloc, &phys, ALT_SECTOR, (long)1);
D 3
	status = access_dsk((char *)save, &temp.err_adr, WD, 1, 1);
	if(!((status & ALTACC) && !(status & (HRDERR |SFTERR)))) {
E 3
I 3
	status = access_dsk((char *)save, &temp.err_adr, VDOP_WD, 1, 1);
	if(!((status & DCBS_ATA) && !(status & (DCBS_HARD|DCBS_SOFT)))) {
E 3
D 2
		print("Sector relocation failed.  Status = 0x%x.\n", status);
E 2
I 2
		print(
		"Sector relocation failed (c %d t %d s %d).  Status = 0x%x.\n",
		    phys.cylinder, phys.track, phys.sector, status);
E 2
		print_unix_block(phys);
	}
}



/*
**
*/

relocate_track(entry)
bs_entry	entry;
{
	dskadr		phys, reloc;
	fmt_err		temp;
	register long	status;

D 4
	temp = (*C_INFO.decode_pos)(entry);
E 4
I 4
D 6
	temp = (*C_INFO->decode_pos)(entry);
E 6
I 6
	(*C_INFO->decode_pos)(&entry, &temp);
E 6
E 4
	temp.err_adr.sector = 0;
	phys = temp.err_adr;
	reloc = entry.bs_alt;
	reloc.sector = 0xff;
D 4
	format_sectors(&phys, &reloc, RELOC_SECTOR, (long)CURRENT->vc_nsec);
E 4
I 4
	format_sectors(&phys, &reloc, RELOC_SECTOR, (long)lab->d_nsectors);
E 4
	
	reloc.sector = 0x00;
D 4
	format_sectors(&reloc, &phys, ALT_SECTOR, (long)CURRENT->vc_nsec);
D 3
	status = access_dsk((char *)save, &temp.err_adr, WD, CURRENT->vc_nsec, 1);
	if(!((status & ALTACC) && !(status & (HRDERR | SFTERR)))) {
E 3
I 3
	status = access_dsk((char *)save, &temp.err_adr, VDOP_WD, CURRENT->vc_nsec, 1);
E 4
I 4
	format_sectors(&reloc, &phys, ALT_SECTOR, (long)lab->d_nsectors);
	status = access_dsk((char *)save, &temp.err_adr, VDOP_WD, lab->d_nsectors, 1);
E 4
	if(!((status & DCBS_ATA) && !(status & (DCBS_HARD|DCBS_SOFT)))) {
E 3
		print("Track relocation failed.  Status = 0x%x.\n", status);
		print_unix_block(phys);
	}
}
D 3



E 3
E 1
