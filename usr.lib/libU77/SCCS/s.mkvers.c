h60518
s 00007/00001/00072
d D 5.1 85/06/07 23:26:34 kre 3 2
c Add copyright
e
s 00009/00001/00064
d D 1.2 83/04/20 23:18:48 dlw 2 1
c made array name be lib name_id. DLW
e
s 00065/00000/00000
d D 1.1 83/01/21 15:05:46 dlw 1 0
c date and time created 83/01/21 15:05:46 by dlw
e
u
U
t
T
I 1
D 3
char id_mkvers[] = "%W%";
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

char id_mkvers[] = "%W% %G%";
E 3
/*
 * extract sccs id strings from source files
 * first arg is lib name.
 * Put them in Version.c
 */

#include	<stdio.h>

#define SCCS_ID		"@(#)"
#define VERSION		"Version.c"

main(argc, argv)
int argc; char **argv;
{
	char buf[256];
	char *s, *e;
	char *index(), *ctime();
	long t;
	FILE *V, *fdopen();

	V = stdout; /* fdopen(creat(VERSION, 0644), "w"); */
	if (!V)
	{
		perror("mkvers");
		exit(1);
	}
D 2
	fprintf(V, "char *sccs_id[] = {\n");
E 2
I 2
	if (argc > 1 && argv[1][0] != '.')
	{
		fprintf(V, "char *");
		for (s = argv[1]; *s && *s != '.'; s++)
			fputc(*s, V);
		fprintf(V, "_id[] = {\n");
	}
	else
		fprintf(V, "char *sccs_id[] = {\n");
E 2
	if (argc-- > 1)
	{
		time(&t);
		s = ctime(&t) + 4;
		s[20] = '\0';
		fprintf(V, "\t\"%s%s\t%s\",\n", SCCS_ID, *++argv, s);
	}
	while (--argc)
	{
		if (freopen(*++argv, "r", stdin) == NULL)
		{
			perror(*argv);
			continue;
		}
		while(gets(buf))
		{
			s = buf;
			while(s = index(s, '@'))
				if (strncmp(s, SCCS_ID, 4) == 0)
					break;
			if (s)
			{
				e = index(s, '"');
				if (e)
					*e = '\0';
				fprintf(V, "\t\"%s\",\n", s);
				break;
			}
		}
		if (feof(stdin))
			fprintf(stderr, "%s: no sccs id string\n", *argv);
	}
	fprintf(V, "};\n");
	fclose(V);
	fflush(stdout);
	fflush(stderr);
}
E 1
