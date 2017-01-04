h35889
s 00001/00001/00076
d D 5.2 88/04/01 10:46:01 bostic 7 6
c fprintf missing an argument; bug report 4.3BSD/bin/120
e
s 00014/00002/00063
d D 5.1 85/04/30 15:05:21 dist 6 5
c Add copyright
e
s 00018/00069/00047
d D 4.5 83/07/06 23:30:56 sam 5 4
c suped up version uses ftruncate...(I knew there was a reason 
c to add that system call)
e
s 00006/00002/00110
d D 4.4 83/05/22 18:32:34 sam 4 3
c pagsiz.h must go....
e
s 00001/00001/00111
d D 4.3 83/04/29 00:51:57 mckusick 3 2
c added perror
e
s 00001/00001/00111
d D 4.2 82/03/31 22:45:56 mckusic 2 1
c explicit define BUFSIZ as 1024
e
s 00112/00000/00000
d D 4.1 80/10/01 17:28:39 bill 1 0
c date and time created 80/10/01 17:28:39 by bill
e
u
U
t
T
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 6
I 4
#ifndef lint
E 4
I 1
D 6
static char *sccsid = "%W% (Berkeley) %G%";
I 4
#endif
E 6
I 6
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6

E 4
#include <a.out.h>
#include <signal.h>
I 5
#include <stdio.h>
#include <sys/file.h>
E 5
D 4
#include <pagsiz.h>
E 4

D 2
#define	BUFSIZ	BSIZE
E 2
I 2
D 5
#define	BUFSIZ	1024
E 2

char	*tname;
char	*mktemp();
struct exec head;
E 5
I 5
struct	exec head;
E 5
int	status;
D 5
int	tf;
E 5
I 4
int	pagesize;
E 4

main(argc, argv)
D 5
char *argv[];
E 5
I 5
	char *argv[];
E 5
{
	register i;

I 4
	pagesize = getpagesize();
E 4
	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
D 5
	tname = mktemp("/tmp/sXXXXX");
	close(creat(tname, 0600));
	tf = open(tname, 2);
	if(tf < 0) {
		printf("cannot create temp file\n");
		exit(2);
	}
	for(i=1; i<argc; i++) {
E 5
I 5
	for (i = 1; i < argc; i++) {
E 5
		strip(argv[i]);
D 5
		if(status > 1)
E 5
I 5
		if (status > 1)
E 5
			break;
	}
D 5
	close(tf);
	unlink(tname);
E 5
	exit(status);
}

strip(name)
D 5
char *name;
E 5
I 5
	char *name;
E 5
{
	register f;
	long size;
D 5
	int i;
E 5

D 5
	f = open(name, 0);
	if(f < 0) {
D 3
		printf("cannot open %s\n", name);
E 3
I 3
		perror(name);
E 5
I 5
	f = open(name, O_RDWR);
	if (f < 0) {
		fprintf(stderr, "strip: "); perror(name);
E 5
E 3
		status = 1;
		goto out;
	}
D 5
	read(f, (char *)&head, sizeof(head));
	if (N_BADMAG(head)) {
		printf("%s not in a.out format\n", name);
E 5
I 5
	if (read(f, (char *)&head, sizeof (head)) < 0 || N_BADMAG(head)) {
		printf("strip: %s not in a.out format\n", name);
E 5
		status = 1;
		goto out;
	}
	if ((head.a_syms == 0) && (head.a_trsize == 0) && (head.a_drsize ==0)) {
D 5
		printf("%s already stripped\n", name);
E 5
I 5
		printf("strip: %s already stripped\n", name);
E 5
		goto out;
	}
	size = (long)head.a_text + head.a_data;
D 5
	head.a_syms = head.a_trsize = head.a_drsize = 0 ;
	lseek(tf, (long)0, 0);
	write(tf, (char *)&head, sizeof(head));
E 5
I 5
	head.a_syms = head.a_trsize = head.a_drsize = 0;
E 5
	if (head.a_magic == ZMAGIC)
D 4
		size += PAGSIZ - sizeof (head);
E 4
I 4
		size += pagesize - sizeof (head);
E 4
D 5
	if (copy(name, f, tf, size)) {
E 5
I 5
	if (ftruncate(f, size + sizeof (head)) < 0) {
D 7
		fprintf("strip: "); perror(name);
E 7
I 7
		fputs("strip: ", stderr); perror(name);
E 7
E 5
		status = 1;
		goto out;
	}
D 5
	size += sizeof(head);
	close(f);
	f = creat(name, 0666);
	if(f < 0) {
		printf("%s cannot recreate\n", name);
		status = 1;
		goto out;
	}
	lseek(tf, (long)0, 0);
	if(copy(name, tf, f, size))
		status = 2;

E 5
I 5
	(void) lseek(f, (long)0, L_SET);
	(void) write(f, (char *)&head, sizeof (head));
E 5
out:
	close(f);
D 5
}

copy(name, fr, to, size)
char *name;
long size;
{
	register s, n;
	char buf[BUFSIZ];

	while(size != 0) {
		s = BUFSIZ;
		if(size < BUFSIZ)
			s = size;
		n = read(fr, buf, s);
		if(n != s) {
			printf("%s unexpected eof\n", name);
			return(1);
		}
		n = write(to, buf, s);
		if(n != s) {
			printf("%s unexpected write eof\n", name);
			return(1);
		}
		size -= s;
	}
	return(0);
E 5
}
E 1
