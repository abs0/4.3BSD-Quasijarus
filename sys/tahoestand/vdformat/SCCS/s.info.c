h06177
s 00001/00002/00028
d D 1.2 87/11/23 15:28:35 karels 2 1
c working again, I think
e
s 00030/00000/00000
d D 1.1 86/07/05 17:37:35 sam 1 0
c date and time created 86/07/05 17:37:35 by sam
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

info()
{
	extern boolean	read_bad_sector_map();
	boolean		has_map;

	cur.state = inf;
	print("Gathering information for ");
	printf("controller %d, drive %d.\n\n", cur.controller, cur.drive);

	has_map = read_bad_sector_map();
	print("Module serial number is %d.\n", bad_map->bs_id);
D 2
	print("Drive type is %s.\n", CURRENT->vc_name);
E 2
I 2
	print("Drive type is %s.\n", lab->d_typename);
E 2
	if(has_map == true)
		print("Drive contains a bad sector map.\n");
	else
		print("Drive does not contain a bad sector map.\n");
	print_bad_sector_list();
D 2
	print("Information display completed successfully.\n");
E 2
}

E 1
