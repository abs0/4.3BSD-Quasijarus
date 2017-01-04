h14682
s 00005/00002/00032
d D 1.3 87/11/23 15:29:02 karels 3 2
c working again, I think
e
s 00001/00000/00033
d D 1.2 86/11/04 21:24:15 karels 2 1
c version working with eagles, many cleanups and fixes
e
s 00033/00000/00000
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
**
*/

start_commands()
{
	register int	ctlr, drive, cur_op;

	indent();
	for(ctlr=0; ctlr<MAXCTLR; ctlr++)
		for(drive=0; drive<MAXDRIVE; drive++) {
			for(cur_op=0; cur_op<NUMOPS; cur_op++) {
				if(ops_to_do[ctlr][drive].op & (1<<cur_op)) {
					cur.controller = ctlr;
					cur.drive = drive;
I 3
					C_INFO = &c_info[ctlr];
					D_INFO = &d_info[ctlr][drive];
					lab = &D_INFO->label;
E 3
					if(!_setjmp(abort_environ)) {
I 2
						cur.state = setup;
E 2
						load_verify_patterns();
D 3
						spin_up_drive();
E 3
I 3
						if (D_INFO->alive != u_true)
							spin_up_drive();
E 3
						(*operations[cur_op].routine)();
					}
					ops_to_do[ctlr][drive].op&=~(1<<cur_op);
				}
			}
		}
	exdent(1);
}
D 3

E 3
E 1
