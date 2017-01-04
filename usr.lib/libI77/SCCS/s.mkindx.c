h46927
s 00007/00001/00051
d D 5.1 85/06/07 23:51:46 kre 2 1
c Add copyright
e
s 00052/00000/00000
d D 1.1 85/05/22 22:13:59 libs 1 0
c date and time created 85/05/22 22:13:59 by libs
e
u
U
t
T
I 1
/*
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

/*
E 2
 *  mkindx.c - utility to format a nice index to source files, etc.
 *
 *  usage:  mkindx "title string" [file_name] [filename] .....
 */

# include	<stdio.h>

D 2
char id_mkindx[] = "@(#)mkindx.c	1.1";
E 2
I 2
char id_mkindx[] = "%W% %G%";
E 2

char list[10000] = "pwd >>index; echo \" \" >>index; ls -l ";
char *apndx = ">>index";
char *cp = list;
extern char *ctime();
FILE *fopen(), *index;

main (argc, argv)
char **argv;
{
	short i;
	long time(), t;

	if (index = fopen ("index", "w"))
	{
		fprintf (index, "\n\n\n\n\n\n\n\n\n");
		center (argv[1]);   /* center title on page */
		t = time(0);
		center (ctime(&t));   /* center date & time */
		fprintf (index, "\n");
		fclose (index);
		while (*cp) cp++;   /* find end of shell command */
		for (i = 2; i < argc; i++)
		{
			while (*argv[i]) *cp++ = *(argv[i]++);
			*cp++ = ' ';
		}
		while (*apndx) *cp++ = *apndx++;
		*cp = '\0';
		system (list);
	}
	else fprintf (stderr, "mkindx: can't open index\n");
}

center (string)
char *string;
{
	short pad;

	pad = (72 - strlen(string)) >> 1;
	while (pad-- > 0) fputc(' ', index);
	fprintf (index, "%s\n", string);
}
E 1
