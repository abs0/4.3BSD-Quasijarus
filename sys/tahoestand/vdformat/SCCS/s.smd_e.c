h45680
s 00027/00029/00044
d D 1.3 88/06/07 14:33:13 karels 3 2
c fix relocate (I think) and correct, add command to clear corrections,
c don't preserve user- and verify-detected flaws on reformat; *don't* pass
c structures back and forth incessantly
e
s 00004/00025/00069
d D 1.2 87/11/23 15:28:59 karels 2 1
c working again, I think
e
s 00094/00000/00000
d D 1.1 86/07/05 17:37:40 sam 1 0
c date and time created 86/07/05 17:37:40 by sam
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
**	The sector format of the SMD controller looks like this:
**  32 bytes sector gap			(header error)
**   1 byte sync (0x19)			(header error)
**   2 bytes cylinder address		(header error)
**   1 byte track address		(header error)
**   1 byte sector address		(header error)
**   2 bytes alt cylinder address	(header error)
**   1 byte alt track address		(header error)
**   1 byte alt sector address		(header error)
**   4 bytes header crc			(header error)
**  34 bytes header gap			(data error)
** 512 bytes data			(data error)
**   4 byte ecc				(data error)
**  ?? trailing pad			(data error)
*/

D 3
fmt_err smd_e_decode_position(bad_entry)
bs_entry bad_entry;
E 3
I 3
smd_e_decode_position(bad_entry, error)
register bs_entry *bad_entry;
register fmt_err *error;
E 3
{
D 3
	fmt_err	error;
E 3
D 2
	int	sector_length = CURRENT->vc_traksize / CURRENT->vc_nsec;
E 2
I 2
	int	sector_length = lab->d_traksize / lab->d_nsectors;
E 2
D 3
	int	offset = (bad_entry.bs_offset-2) % sector_length;
	int	bytes = (bad_entry.bs_length / 8) + 4;
E 3
I 3
	int	offset = (bad_entry->bs_offset-2) % sector_length;
	int	bytes = (bad_entry->bs_length / 8) + 4;
E 3

D 3
	error.err_adr.cylinder = bad_entry.bs_cyl;
	error.err_adr.track = bad_entry.bs_trk;
	error.err_adr.sector = (bad_entry.bs_offset-2) / sector_length;
D 2
	if(error.err_adr.sector >= CURRENT->vc_nsec) {
		error.err_adr.sector = CURRENT->vc_nsec - 1;
E 2
I 2
	if(error.err_adr.sector >= lab->d_nsectors) {
		error.err_adr.sector = lab->d_nsectors - 1;
E 2
		error.err_stat = DATA_ERROR;
E 3
I 3
	error->err_adr.cylinder = bad_entry->bs_cyl;
	error->err_adr.track = bad_entry->bs_trk;
	error->err_adr.sector = (bad_entry->bs_offset-2) / sector_length;
	if(error->err_adr.sector >= lab->d_nsectors) {
		error->err_adr.sector = lab->d_nsectors - 1;
		error->err_stat = DATA_ERROR;
E 3
	}
	else if((offset < 45) || ((offset+bytes) > sector_length))
D 3
		error.err_stat = HEADER_ERROR;
E 3
I 3
		error->err_stat = HEADER_ERROR;
E 3
	else 
D 3
		error.err_stat = DATA_ERROR;
	return	error;
E 3
I 3
		error->err_stat = DATA_ERROR;
E 3
}


/*
**
*/

D 3
bs_entry smd_e_code_position(error)
fmt_err	error;
E 3
I 3
smd_e_code_position(error, badent)
register fmt_err *error;
register bs_entry *badent;
E 3
{
D 2
	int		sector_length = CURRENT->vc_traksize / CURRENT->vc_nsec;
E 2
I 2
	int		sector_length = lab->d_traksize / lab->d_nsectors;
E 2
D 3
	bs_entry	temp;
E 3

D 3
	temp.bs_length = 1;
	temp.bs_cyl = error.err_adr.cylinder;
	temp.bs_trk = error.err_adr.track;
	temp.bs_offset = error.err_adr.sector * sector_length;
	if(error.err_stat & HEADER_ERROR) {
		temp.bs_offset += 1;
E 3
I 3
	badent->bs_length = 1;
	badent->bs_cyl = error->err_adr.cylinder;
	badent->bs_trk = error->err_adr.track;
	badent->bs_offset = error->err_adr.sector * sector_length;
	if(error->err_stat & HEADER_ERROR) {
		badent->bs_offset += 1;
E 3
	}
	else {
D 3
		temp.bs_offset += 60;
E 3
I 3
		badent->bs_offset += 60;
E 3
	}
D 3
	temp.bs_alt.cylinder = 0;
	temp.bs_alt.track = 0;
	temp.bs_alt.sector = 0;
	temp.bs_how = scanning;
	return	temp;
E 3
I 3
	badent->bs_alt.cylinder = 0;
	badent->bs_alt.track = 0;
	badent->bs_alt.sector = 0;
	badent->bs_how = scanning;
E 3
}
D 2


/*
**
*/

int smd_e_cyl_skew()
{
	return 0;
}


/*
**
*/

int smd_e_trk_skew()
{
	return 0;
}

E 2
E 1
