h32238
s 00003/00003/00064
d D 1.3 87/11/23 15:28:52 karels 3 2
c working again, I think
e
s 00002/00002/00065
d D 1.2 87/06/01 20:59:25 sam 2 1
c header file changes (guess this works, noone's complained)
e
s 00067/00000/00000
d D 1.1 86/07/05 17:37:38 sam 1 0
c date and time created 86/07/05 17:37:38 by sam
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

#define	cycles	10

/*
**
*/

profile()
{
	unsigned int	total_time, i, step, remainder;
	dskadr		ead, zero;
	char		digit_buf[20];

	print("Disk seek profile for ");
	printf("controller %d, drive %d, ", cur.controller, cur.drive);
D 3
	printf("type %s.\n",CURRENT->vc_name);
E 3
I 3
	printf("type %s.\n", lab->d_typename);
E 3

	indent();
	if(is_formatted() == false) {
		print("Can not profile unformatted drives!\n");
		_longjmp(abort_environ, 1);
	}
	print(" Seek  |                  Seek time (ms)\n");
	print("Length |0    5    10   15   20   25   30   35   40   45   50\n");
	print("-------|-----+----+----+----+----+----+----+----+----+----+\n");

	cur.state = prof;
	zero.cylinder = zero.track = zero.sector=0;
	ead.track = ead.sector=0;
D 3
	step = CURRENT->vc_ncyl / 55;
	for(ead.cylinder=1; ead.cylinder<CURRENT->vc_ncyl; ead.cylinder+=step){
E 3
I 3
	step = lab->d_ncylinders / 55;
	for(ead.cylinder=1; ead.cylinder<lab->d_ncylinders; ead.cylinder+=step){
E 3
		total_time = 0;
		for(i=0; i<cycles; i++) {
D 2
			access_dsk((char *)save, &zero, SEEK, 1, 60);
			access_dsk((char *)save, &ead, SEEK, 1, 60);
E 2
I 2
			access_dsk((char *)save, &zero, VDOP_SEEK, 1, 60);
			access_dsk((char *)save, &ead, VDOP_SEEK, 1, 60);
E 2
			if(kill_processes == true)
				_longjmp(quit_environ, 1);
			total_time += ((2*60*1000*1000) - vdtimeout);
		}
		print("");
		sprintf(digit_buf, "%d      ", ead.cylinder);
		for(i=0; i<7; i++)
			putchar(digit_buf[i]);
		putchar('|');	
		total_time /= cycles;
		remainder = total_time % 10;
		total_time /= 10;
		while(total_time--)
			putchar(' ');
		if(remainder >= 5)
			printf("+\n");
		else
			printf("*\n");
		DELAY(400000);
	}
	print("-------|-----+----+----+----+----+----+----+----+----+----+\n");
	print("       |0    5    10   15   20   25   30   35   40   45   50\n");
	exdent(1);
	printf("Profile completed successfully.\n");
}

E 1
