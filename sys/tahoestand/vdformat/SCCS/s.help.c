h22843
s 00049/00000/00000
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
#include	"cmd.h"

/*
**	These routines are used to display all the system help messages
** that the operator requests.  They look through the system command 
** tables to print the commands and the help messages in a neat mannor.
**
**	The only break in this rule is the help processor for digit entry
** Which informs the operator what numeric range is valid.
*/

help_text(tbl)
cmd_text_element	*tbl;
{
	indent();
	print_common_help();
	indent();
	while(tbl->cmd_token != 0) {
		register int	count;

		count = 9 - strlen(tbl->cmd_text);
		print("%s", tbl->cmd_text);
		while(count--)
			putchar(' ');
		printf("- %s.\n", tbl->cmd_help);
		tbl++;
	}
	exdent(2);
	print("\n");
}


/*
**
*/

print_common_help()
{
	print("The following commands are available:\n");
	indent();
	print("%s - %s.\n", "KILL    ", "Abort all operations");
	print("%s - %s.\n", "STATus  ", "Display formatter state");
	exdent(1);
}
E 1
