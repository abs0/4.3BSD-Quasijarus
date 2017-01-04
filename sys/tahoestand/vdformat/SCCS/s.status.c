h14025
s 00031/00022/00060
d D 1.3 88/06/07 14:34:31 karels 3 2
c not doing *anything* while waiting for input; add substate
c for writing maps
e
s 00004/00000/00078
d D 1.2 86/11/04 21:24:16 karels 2 1
c version working with eagles, many cleanups and fixes
e
s 00078/00000/00000
d D 1.1 86/07/05 17:37:41 sam 1 0
c date and time created 86/07/05 17:37:41 by sam
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
**	These routines are used to display the status of the formatter.
*/

status()
{
	indent();
	switch (cur.state) {
		case cmd :
			print("Waiting for operator response.\n");
			break;
		case fmt :
			dump_state("Formatting");
			break;
		case vfy :
			dump_state("Verifying");
			break;
		case rel :
			dump_state("Relocating");
			break;
		case cor :
			dump_state("Correcting");
			break;
		case inf :
			dump_state("Collecting information");
			break;
		case exec :
			dump_state("Exercising disk");
			break;
I 2
		case setup:
			printf("Initializing for operation ");
			printf("on controller %d, drive %d.\n",
				cur.controller, cur.drive);
E 2
		default:
			print("Current state is unknown.\n");
	}
	exdent(1);
}


/*
**
*/

dump_state(string)
char	*string;
{
I 3
	extern int wait_for_char;

E 3
	indent();
	print("%s on controller %d, drive %d.\n",
	    string, cur.controller, cur.drive);
D 3
	print("Currently accessing cylinder %d, head %d.\n",
	    cur.daddr.cylinder, cur.daddr.track);
	print("Currently ");
	switch (cur.substate) {
		case sub_chk :
			printf("determining drive state.\n");
			break;
		case sub_fmt :
			printf("formatting drive surface.\n");
			break;
		case sub_vfy :
			printf("verifying drive surface.\n");
			break;
		case sub_rel :
			printf("performing relocation operations.\n");
			break;
		case sub_rcvr :
			printf("recovering from hardware error.\n");
			break;
		default :
			printf("I don't know what is happening.\n");
			break;
E 3
I 3
	if (wait_for_char)
		print("Waiting for operator response.\n");
	else {
		print("Currently accessing cylinder %d, head %d.\n",
		    cur.daddr.cylinder, cur.daddr.track);
		print("Currently ");
		switch (cur.substate) {
			case sub_chk :
				printf("determining drive state.\n");
				break;
			case sub_fmt :
				printf("formatting drive surface.\n");
				break;
			case sub_vfy :
				printf("verifying drive surface.\n");
				break;
			case sub_rel :
				printf("performing relocation operations.\n");
				break;
			case sub_rcvr :
				printf("recovering from hardware error.\n");
				break;
			case sub_wmap :
				printf("writing relocation map.\n");
				break;
			default :
				printf("I don't know what is happening.\n");
				break;
		}
E 3
	}
	exdent(1);
}

E 1
