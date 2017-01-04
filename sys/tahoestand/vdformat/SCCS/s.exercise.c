h17377
s 00005/00005/00051
d D 1.3 87/11/23 15:28:32 karels 3 2
c working again, I think
e
s 00002/00001/00054
d D 1.2 87/06/01 20:59:14 sam 2 1
c header file changes (guess this works, noone's complained)
e
s 00055/00000/00000
d D 1.1 86/07/05 17:37:34 sam 1 0
c date and time created 86/07/05 17:37:34 by sam
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

#define	verbose	1

/*
**
*/

exercise()
{
	int		cyl, trk;
	dskadr		ead, sad;

	print("Starting disk exercise on ");
	printf("controller %d, drive %d, ", cur.controller, cur.drive);
D 3
	printf("type %s.\n",CURRENT->vc_name);
E 3
I 3
	printf("type %s.\n", lab->d_typename);
E 3

	if(read_bad_sector_map() == true) {
D 3
		if(bad_map->bs_id != D_INFO.id) {
E 3
I 3
		if(bad_map->bs_id != D_INFO->id) {
E 3
			print("Module serial numbers do not match!\n");
			print("Use `info' to find the real serial number.\n");
			_longjmp(abort_environ, 1);
		}
	}
	else if(is_formatted() == false) {
		print("Can not exercise unformatted drives!\n");
		_longjmp(abort_environ, 1);
	}
	print("Starting read test.\n");
	cur.state = exec;
	sad.track = sad.sector = 0;
	indent();
D 3
	for(sad.cylinder=0; sad.cylinder<CURRENT->vc_ncyl; sad.cylinder++) {
E 3
I 3
	for(sad.cylinder=0; sad.cylinder<lab->d_ncylinders; sad.cylinder++) {
E 3
		print("pass %d...\n", sad.cylinder);
D 3
		for(cyl=0; cyl<CURRENT->vc_ncyl-NUMSYS; cyl++){
E 3
I 3
		for(cyl=0; cyl<lab->d_ncylinders-NUMSYS; cyl++){
E 3
			ead.cylinder = cyl;
D 3
			for(trk=0; trk<CURRENT->vc_ntrak; trk++) {
E 3
I 3
			for(trk=0; trk<lab->d_ntracks; trk++) {
E 3
				ead.track = trk;
				ead.sector = 0;
D 2
				access_dsk((char *)scratch, &sad, SEEK, 1, 1);
E 2
I 2
				access_dsk((char *)scratch, &sad,
				    VDOP_SEEK, 1, 1);
E 2
				verify_track(&ead, 16, verbose);
				if(kill_processes == true)
					goto exit;
			}
		}
	}
	exdent(2);
exit:	sync_bad_sector_map();
	printf("Exercise completed successfully.\n");
}

E 1
