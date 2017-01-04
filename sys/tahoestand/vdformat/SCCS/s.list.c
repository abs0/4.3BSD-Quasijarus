h54436
s 00001/00001/00071
d D 1.2 87/11/23 15:28:39 karels 2 1
c working again, I think
e
s 00072/00000/00000
d D 1.1 86/07/05 17:37:36 sam 1 0
c date and time created 86/07/05 17:37:36 by sam
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
**	Lists all the operations specified so far.
*/

list()
{
	register int	ctlr, drive;
	boolean		can_do = false;

	/* Determine if there are any operations to do */
	for(ctlr=0; ctlr<MAXCTLR; ctlr++)
		for(drive=0; drive<MAXDRIVE; drive++) {
			if(ops_to_do[ctlr][drive].op)
				can_do = true;
		}
	if(can_do == false) {
		indent();
		print("There are no operations to list!\n\n");
		exdent(1);
		return;
	}
	indent();
	print("The following operations will occur when Start is issued:\n");
	indent();
	for(ctlr=0; ctlr<MAXCTLR; ctlr++)
		for(drive=0; drive<MAXDRIVE; drive++)
			if(ops_to_do[ctlr][drive].op != 0) {
				print("");  /* force an indent */
				display_operations(ctlr, drive);
			}
	exdent(2);
}


/*
**
*/

display_operations(ctlr, drive)
register int	ctlr, drive;
{
	print_op_list(ops_to_do[ctlr][drive].op);
	printf(": Controller %d, drive %d", ctlr, drive);
D 2
	printf(", type %s.\n", d_info[ctlr][drive].info->vc_name);
E 2
I 2
	printf(", type %s.\n", d_info[ctlr][drive].label.d_typename);
E 2
}


/*
**
*/

print_op_list(ops)
int	ops;
{
	register int	cur_op;
	char		*prefix = "";

	for(cur_op=0; cur_op<NUMOPS; cur_op++) {
		if(ops & (1 << cur_op)) {
			printf("%s%s", prefix, operations[cur_op].op_name);
			prefix = ", ";
		}
	}
}

E 1
