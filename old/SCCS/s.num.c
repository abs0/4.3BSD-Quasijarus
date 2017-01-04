h30860
s 00001/00001/00057
d D 4.2 82/10/13 20:21:44 mckusick 2 1
c "stdio.h" becomes <stdio.h>
e
s 00058/00000/00000
d D 4.1 80/10/01 17:27:40 bill 1 0
c date and time created 80/10/01 17:27:40 by bill
e
u
U
t
T
I 1
static char *sccsid = "%W% (Berkeley) %G%";
D 2
#include	"stdio.h"
E 2
I 2
#include	<stdio.h>
E 2
#define		formfeed 0xc

/*
 * number - a cat like program which prints a file with line
 *	    numbers. Printing of numbers is suppressed on blank
 *	    lines.
 *
 * Original Version by William Joy, June 1977
 * Updated October 1979 by M. Kirk McKusick
 */
main(ac, av)
	int ac;
	char *av[];
	{
	register int argc = ac;
	register char **argv = av;
	register int lino;
	register char *lineptr;
	register FILE *STDOUT = stdout;
	register FILE *STDIN = stdin;
	char line[512];
	extern char _sibuf[], _sobuf[];

	argv++;
	argc--;
	lino = 1;
	setbuf(STDIN,_sibuf);
	setbuf(STDOUT,_sobuf);
	do
		{
		if (argc)
			if (freopen(*argv++, "r", STDIN) == NULL)
				{
				perror(*--argv);
				exit(1);
				}
		for(;;)
			{
			lineptr = line;
			*lineptr = 0;
			fscanf(STDIN,"%[^\n]",lineptr);
			if (feof(STDIN))
				break;
			if (*lineptr == formfeed)
				putc(*lineptr++,STDOUT);
			if (!*lineptr)
				putc('\n',STDOUT);
			else
				fprintf(STDOUT,"%6d  %s\n",lino,lineptr);
			lino++;
			getc(STDIN);
			}
		}
		while (--argc > 0);
	exit();
	}
E 1
