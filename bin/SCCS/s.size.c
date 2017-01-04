h51496
s 00010/00005/00062
d D 4.6 88/06/18 13:20:46 bostic 6 5
c install approved copyright notice
e
s 00047/00033/00020
d D 4.5 88/06/08 19:44:26 bostic 5 4
c rewritten from manual page; added Berkeley specific header
e
s 00004/00000/00049
d D 4.4 85/04/22 08:17:26 bloom 4 3
c add exit value 
e
s 00002/00002/00047
d D 4.3 81/07/02 15:41:10 root 3 2
c fix per bill jolitz
e
s 00014/00006/00035
d D 4.2 80/10/10 00:56:14 bill 2 1
c cleanup of format
e
s 00041/00000/00000
d D 4.1 80/10/01 17:28:25 bill 1 0
c date and time created 80/10/01 17:28:25 by bill
e
u
U
t
T
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
D 5
static	char *sccsid = "%W% (Berkeley) %G%";
E 5
E 2
/*
D 5
 * size
E 5
I 5
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 6
E 5
 */
I 2

E 2
D 5
#include	<stdio.h>
#include 	<a.out.h>
E 5
I 5
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */
E 5

I 2
D 5
int	header;
E 5
I 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 5

I 5
#include <sys/param.h>
#include <sys/file.h>
#include <a.out.h>
#include <stdio.h>

E 5
E 2
main(argc, argv)
D 5
char **argv;
E 5
I 5
	int argc;
	char **argv;
E 5
{
D 5
	struct exec buf;
	long sum;
	int gorp,i;
I 4
	int err = 0;
E 4
	FILE *f;
E 5
I 5
	struct exec head;
	u_long total;
	int exval, fd, first;
E 5

D 5
	if (argc==1) {
E 5
I 5
	if (!*argv[1])
E 5
		*argv = "a.out";
D 5
		argc++;
		--argv;
	}
	gorp = argc;
	while(--argc) {
E 5
I 5
	else
E 5
		++argv;
D 5
		if ((f = fopen(*argv, "r"))==NULL) {
			printf("size: %s not found\n", *argv);
I 4
			err++;
E 5
I 5
	for (first = 1, exval = 0; *argv; ++argv) {
		if ((fd = open(*argv, O_RDONLY, 0)) < 0) {
			fprintf(stderr, "size: ");
			perror(*argv);
			exval = 1;
E 5
E 4
			continue;
		}
D 3
		fread((char *)&buf, sizeof(buf), 1, f);
D 2
		if (N_BADMAG(buf)) {
E 2
I 2
		if(N_BADMAG(buf)) {
E 3
I 3
D 5
		if (fread((char *)&buf, sizeof(buf), 1, f) != 1 ||
		    N_BADMAG(buf)) {
E 3
E 2
			printf("size: %s not an object file\n", *argv);
			fclose(f);
I 4
			err++;
E 5
I 5
		if (read(fd, (char *)&head, sizeof(head)) != sizeof(head) ||
		    N_BADMAG(head)) {
			fprintf(stderr, "size: %s: not in a.out format.\n",
			    *argv);
			exval = 1;
E 5
E 4
			continue;
		}
D 2
		if (gorp>2)
			printf("%s: ", *argv);
		printf("%u+%u+%u = ", buf.a_text,buf.a_data,buf.a_bss);
E 2
I 2
D 5
		if (header == 0) {
E 5
I 5
		(void)close(fd);
		if (first) {
			first = 0;
E 5
			printf("text\tdata\tbss\tdec\thex\n");
D 5
			header = 1;
E 5
		}
D 5
		printf("%u\t%u\t%u\t", buf.a_text,buf.a_data,buf.a_bss);
E 2
		sum = (long) buf.a_text + (long) buf.a_data + (long) buf.a_bss;
D 2
		printf("%Db = 0x%Xb\n", sum, sum);
E 2
I 2
		printf("%ld\t%lx", sum, sum);
		if (gorp>2)
E 5
I 5
		total = head.a_text + head.a_data + head.a_bss;
		printf("%lu\t%lu\t%lu\t%lu\t%lx", head.a_text, head.a_data,
		    head.a_bss, total, total);
		if (argc > 2)
E 5
			printf("\t%s", *argv);
		printf("\n");
E 2
D 5
		fclose(f);
E 5
	}
I 4
D 5
	exit(err);
E 5
I 5
	exit(exval);
E 5
E 4
}
E 1
