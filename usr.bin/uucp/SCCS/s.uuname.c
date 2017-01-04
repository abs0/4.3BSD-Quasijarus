h26186
s 00030/00045/00033
d D 5.4 88/04/05 12:25:12 rick 4 3
c use syslog for errors, plus run through indent so it's readable
e
s 00005/00004/00073
d D 5.3 85/10/09 16:39:13 bloom 3 2
c add definition of Now (from rick@seismo)
e
s 00010/00002/00067
d D 5.2 85/01/22 14:13:14 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00069/00000/00000
d D 5.1 83/07/02 17:57:55 sam 1 0
c date and time created 83/07/02 17:57:55 by sam
e
u
U
t
T
I 1
#ifndef lint
D 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
I 4
static char sccsid[] = "%W%	(Berkeley) %G%";
E 4
#endif

#include "uucp.h"
D 4
#include <signal.h>
E 4

D 3
/*******
 *      uuname  -  return list of all remote systems 
 *		   recognized by uucp, or  (with -l) the local
 *		   uucp name.
E 3
I 3
/*
D 4
 *      return list of all remote systems 
 *	recognized by uucp, or  (with -l) the local  uucp name.
E 4
I 4
 * return list of all remote systems recognized by uucp, or  (with -l) the
 * local  uucp name. 
E 4
E 3
 *
D 4
 *      return codes: 0 | 1  (can't read)
E 4
I 4
 * return codes: 0 | 1  (can't read) 
E 4
 */
I 3

struct timeb Now;
E 3
D 4
 
main(argc,argv)
E 4
I 4

main(argc, argv)
E 4
char *argv[];
int argc;
{
I 2
D 4
	int ret;
E 2
	int i;
	int intrEXIT();
	FILE *np;
/* Increase buffers for s and prev.  cornell!pavel */
	char prev[1000];
	char s[1000];
E 4
I 4
	register FILE *np;
	register char *buf;
	char s[BUFSIZ];
	char prev[BUFSIZ];
E 4

D 2
	chdir(Spool);
E 2
I 2
D 4
	ret = chdir(Spool);
	ASSERT(ret >= 0, "CHDIR FAILED", Spool, ret);
E 4
E 2
	strcpy(Progname, "uuname");
D 4
	signal(SIGILL, intrEXIT);
	signal(SIGTRAP, intrEXIT);
	signal(SIGIOT, intrEXIT);
	signal(SIGEMT, intrEXIT);
	signal(SIGFPE, intrEXIT);
	signal(SIGBUS, intrEXIT);
	signal(SIGSEGV, intrEXIT);
	signal(SIGSYS, intrEXIT);
	signal(SIGINT, intrEXIT);
	signal(SIGHUP, intrEXIT);
	signal(SIGQUIT, intrEXIT);
	signal(SIGTERM, intrEXIT);
E 4

D 2
	if(argv[1][0] == '-' && argv[1][1] == 'l') {
E 2
I 2
D 4
	if(argc > 1 && argv[1][0] == '-' && argv[1][1] == 'l') {
E 4
I 4
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'l') {
E 4
E 2
		uucpname(s);
D 4
		printf("%s\n",s);
E 4
I 4
		puts(s);
E 4
		exit(0);
	}
D 4
        if(argc != 1) {printf("Usage: uuname [-l]\n"); exit(1);}
	if((np = fopen(SYSFILE,"r")) == NULL) {
		printf("%s (name file) protected\n",SYSFILE);
E 4
I 4
	if (argc != 1) {
		fprintf(stderr, "Usage: uuname [-l]\n");
E 4
		exit(1);
	}
D 4
	while ( cfgets(s,sizeof(s),np) != NULL ) {
		for(i=0; s[i]!=' ' && s[i]!='\t'; i++)
			;
		s[i]='\0';
E 4
I 4
	if ((np = fopen(SYSFILE, "r")) == NULL) {
		syslog(LOG_WARNING, "fopen(%s) failed: %m", SYSFILE);
		exit(1);
	}
	buf = s;
	while (cfgets(buf, sizeof(s), np) != NULL) {
		register char *cp;
		cp = strpbrk(buf, " \t");
		if (cp)
			*cp = '\0';
E 4
		if (strcmp(s, prev) == SAME)
			continue;
D 4
		if(s[0]=='x' && s[1]=='x' && s[2]=='x')
E 4
I 4
		if (*buf == 'x' && buf[1] == 'x' && buf[2] == 'x')
E 4
			continue;
D 4
		printf("%s\n",s);
		strcpy(prev, s);
E 4
I 4
		puts(buf);
		if (buf == s)
			buf = prev;
		else
			buf = s;
E 4
	}
D 4
 
E 4
	exit(0);
D 4
}
intrEXIT(inter)
{
	exit(inter);
E 4
I 2
}

cleanup(code)
int code;
{
	exit(code);
E 2
}
E 1
