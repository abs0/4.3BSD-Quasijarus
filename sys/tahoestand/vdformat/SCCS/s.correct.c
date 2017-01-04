h03947
s 00034/00029/00154
d D 1.3 88/06/07 14:33:00 karels 3 2
c fix relocate (I think) and correct, add command to clear corrections,
c don't preserve user- and verify-detected flaws on reformat; *don't* pass
c structures back and forth incessantly
e
s 00012/00012/00171
d D 1.2 87/11/23 15:28:30 karels 2 1
c working again, I think
e
s 00183/00000/00000
d D 1.1 86/07/05 17:37:33 sam 1 0
c date and time created 86/07/05 17:37:33 by sam
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

correct()
{
	cur.state = cor;
	print("Making corrections to bad sector map on ");
	printf("controller %d, drive %d, ", cur.controller, cur.drive);
D 2
	printf("type %s.\n",CURRENT->vc_name);
E 2
I 2
	printf("type %s.\n", lab->d_typename);
E 2

	indent();
	if(is_formatted() == true)
		if(read_bad_sector_map() == true) {
			get_corrections();
I 3
			cur.substate = sub_wmap;
E 3
			sync_bad_sector_map();
		}
		else 
			print("There is no bad sector map on this drive!\n");
	else
		print("Drive must be formatted befor corrections are done.\n");
	exdent(1);
}


/*
**
*/

cor_help()
{
	indent();
	print("Correction commands are in the following form:\n");
	indent();
	print("ID              -  Correct module serial number.\n");
	print("[a-h] (block)   -  UNIX file system format.\n");
	print("SEctor (sector) -  Absolute sector number on disk.\n");
	print("Track (track)   -  Absolute disk track number.\n");
	print("(cylinder) (head) (offset) (length) - CDC flaw map format.\n");
I 3
	print("CLEAR           -  Remove all relocations not from flaw map.\n");
E 3
	print("STARt           -  Ends correction process.\n\n");
	exdent(2);
}


/*
**
*/

get_corrections()
{
	extern int	id_help();
	char		line[256];
	char		*ptr;
	bs_entry	entry;
	dskadr		dskaddr;
I 3
	fmt_err		dskerr;
E 3
	int		max_track;
I 3
	register int	block;
E 3

D 2
	dskaddr.cylinder = CURRENT->vc_ncyl - 1;
	dskaddr.cylinder = CURRENT->vc_ntrak - 1;
E 2
I 2
	dskaddr.cylinder = lab->d_ncylinders - 1;
	dskaddr.cylinder = lab->d_ntracks - 1;
E 2
	max_track = to_track(dskaddr);
	indent();
	for(;;) {
		print("Location? ");
		get_string_cmd(line, cor_help);
		if(kill_processes == true)
			break;
		if(line[0] == '\0')
			continue;
		ptr = line;
		trim_white(ptr);
		if(!strncmp(ptr, "he", 2) || !strncmp(ptr, "?", 1) ||
		    !strncmp(ptr, "stat", 4) || !strncmp(ptr, "!", 1))
			continue;
		indent();
		if(!strncmp(ptr, "id", 2)) {
			register int	temp;

			for(;;) {
				print("Pack ID is %d. Change to? ",
				    bad_map->bs_id);
				temp = get_digit_cmd(id_help);
				if(temp > 0)
					break;
			}
D 2
			D_INFO.id = bad_map->bs_id = temp;
E 2
I 2
			D_INFO->id = bad_map->bs_id = temp;
I 3
		} else if (!strcmp(ptr, "clear")) {
			print(
		     "Confirm removal of ALL relocations installed manually\n");
			if (get_yes_no("or by verification") == true)
				clear_relocations(true);
E 3
E 2
		}
		else if((*ptr  >= 'a') && (*ptr <= 'h')) {
			register char	par = *ptr++;
D 3
			register int	block = get_next_digit(ptr);
				
			dskaddr = *from_unix((unsigned char)par,
E 3
I 3

			block = get_next_digit(ptr);
			dskerr.err_adr = *from_unix((unsigned char)par,
E 3
			    (unsigned int)block);
D 3
			if((dskaddr.cylinder == -1) || (block == -1)) {
E 3
I 3
			if((dskerr.err_adr.cylinder == -1) || (block == -1)) {
E 3
				print("Invalid UNIX block number!\n");
				goto	next;
			}
			print("Confirm block %d on file-system '%c'",block,par);
I 3
			dskerr.err_stat = DATA_ERROR;
		doreloc:
			printf(" (cn %d tn %d bn %d)", dskerr.err_adr.cylinder,
			    dskerr.err_adr.track, dskerr.err_adr.sector);
E 3
			if(get_yes_no("") == true) {
D 2
				entry=(*C_INFO.code_pos)(dskaddr,HEADER_ERROR);
E 2
I 2
D 3
				entry=(*C_INFO->code_pos)(dskaddr,HEADER_ERROR);
E 2
				remove_user_relocations(entry);
E 3
I 3
				(*C_INFO->code_pos)(&dskerr, &entry);
				remove_user_relocations(&entry);
E 3
			}
		}
		else if(*ptr == 't') {
D 3
			register int	trk = get_next_digit(ptr);

			if((trk == -1) || (trk >= max_track)) {
E 3
I 3
			block = get_next_digit(ptr);
			if((block == -1) || (block >= max_track)) {
E 3
				print("Invalid track number!\n");
				goto	next;
			}
D 3
			print("Confirm track %d", trk);
			if(get_yes_no("") == true) {
				dskaddr = *from_track(trk);
D 2
				entry=(*C_INFO.code_pos)(dskaddr,HEADER_ERROR);
E 2
I 2
				entry=(*C_INFO->code_pos)(dskaddr,HEADER_ERROR);
E 2
				remove_user_relocations(entry);
			}
E 3
I 3
			dskerr.err_adr = *from_track(block);
			dskerr.err_stat = HEADER_ERROR;
			print("Confirm track %d", block);
			goto doreloc;
E 3
		}
		else if(!strncmp(ptr, "se", 2)) {
D 3
			register int	sec = get_next_digit(ptr);

D 2
			if((sec == -1) ||
			    ((CURRENT->vc_nsec*CURRENT->vc_ntrak*CURRENT->vc_ncyl)<sec)){
E 2
I 2
			if (sec == -1 ||
			    sec > lab->d_nsectors*lab->d_ntracks*lab->d_ncylinders) {
E 3
I 3
			block = get_next_digit(ptr);
			if (block == -1 ||
			    block > lab->d_nsectors*lab->d_ntracks*lab->d_ncylinders) {
E 3
E 2
				print("Invalid sector number!\n");
				goto	next;
			}
D 3
			print("Confirm sector %d", sec);
			if(get_yes_no("") == true) {
				dskaddr = *from_sector((unsigned int)sec);
D 2
				entry = (*C_INFO.code_pos)(dskaddr, DATA_ERROR);
E 2
I 2
				entry = (*C_INFO->code_pos)(dskaddr, DATA_ERROR);
E 2
				remove_user_relocations(entry);
			}
E 3
I 3
			dskerr.err_adr = *from_sector((unsigned int)block);
			dskerr.err_stat = DATA_ERROR;
			print("Confirm sector %d", block);
			goto doreloc;
E 3
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
D 2
				if(entry.bs_cyl >= CURRENT->vc_ncyl)
E 2
I 2
				if(entry.bs_cyl >= lab->d_ncylinders)
E 2
					print("Cylinder number to high!\n");
D 2
				else if(entry.bs_trk >= CURRENT->vc_ntrak)
E 2
I 2
				else if(entry.bs_trk >= lab->d_ntracks)
E 2
					print("Head number to high!\n");
D 2
				else if(entry.bs_offset >= CURRENT->vc_traksize)
E 2
I 2
				else if(entry.bs_offset >= lab->d_traksize)
E 2
					print("Offset too long!\n");
				else if(entry.bs_length == 0)
					print("Can't have a 0 length error!\n");
				else {
					print("Confirm  Cyl %d, ",entry.bs_cyl);
					printf("Head %d, ", entry.bs_trk);
					printf("offset %d, ", entry.bs_offset);
					printf("length %d", entry.bs_length);
					if(get_yes_no("") == true)
D 3
						remove_user_relocations(entry);
E 3
I 3
						remove_user_relocations(&entry);
E 3
				}
			}
			else
				goto bad;
D 3
		}
		else if(!strncmp(ptr, "star", 4)) {
E 3
I 3
		} else if(!strncmp(ptr, "star", 4)) {
E 3
			exdent(1);
			break;
		}
		else
bad:			print("What?\n");
next:		exdent(1);
	}
D 3
	write_bad_sector_map();
E 3
	exdent(1);
}

E 1
