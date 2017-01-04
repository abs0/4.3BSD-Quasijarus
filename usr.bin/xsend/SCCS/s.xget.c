h14750
s 00005/00005/00149
d D 4.4 83/06/30 14:28:22 sam 4 3
c fix includes
e
s 00016/00005/00138
d D 4.3 83/05/19 10:27:52 ralph 3 2
c added help command.
e
s 00010/00010/00133
d D 4.2 83/05/11 20:53:57 mckusick 2 1
c convert to use new directory access routines
e
s 00143/00000/00000
d D 4.1 83/03/30 12:08:47 sam 1 0
c date and time created 83/03/30 12:08:47 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif

#include "xmail.h"
D 4
#include "sys/types.h"
D 2
#include "sys/dir.h"
E 2
I 2
#include "dir.h"
E 2
#include "ctype.h"
#include "pwd.h"
#include "sys/stat.h"
E 4
I 4
#include <sys/types.h>
#include <sys/dir.h>
#include <ctype.h>
#include <pwd.h>
#include <sys/stat.h>
E 4
char *myname;
int uid;
D 2
struct direct dbuf;
E 2
I 2
struct direct *dbuf;
E 2
char *maildir = "/usr/spool/secretmail/";
D 2
FILE *kf, *mf, *df;
E 2
I 2
FILE *kf, *mf;
DIR *df;
E 2
MINT *x, *b, *one, *t45, *z, *q, *r;
MINT *two, *t15, *mbuf;
char buf[256], line[128];
#define MXF 100
int fnum[MXF], fcnt;
struct stat stbuf;
main()
{	int i;
	char *p;
I 2

E 2
	uid = getuid();
D 2
	myname = getlogin();
E 2
I 2
	myname = (char *)getlogin();
E 2
	if(myname == NULL)
		myname = getpwuid(uid)->pw_name;
	comminit();
	mbuf = itom(0);
	files();
	setup(getpass("Key: "));
	mkb();
	mkx();
#ifndef debug
	invert(x, b, x);
#else
	invert(x, b, z);
	mult(x, z, z);
	mdiv(z, b, q, z);
	omout(z);
	invert(x, b, x);
#endif
	for(i=0; i<fcnt; i++)
	{	sprintf(line, "%s%s.%d", maildir, myname, fnum[i]);
		if(stat(line, &stbuf)<0)
		{	perror(line);
			continue;
		}
		if(stbuf.st_size == 0)
		{	printf("zero length mail file\n");
			unlink(line);
			continue;
		}
		if((mf = fopen(line, "r"))==NULL)
		{	perror(line);
			continue;
		}
		decipher(mf, stdout);
	cmnd:
		printf("? ");
		fgets(buf, sizeof(buf), stdin);
		if(feof(stdin)) exit(0);
		switch(buf[0])
		{
		case 'q':
			exit(0);
		case 'n':
		case 'd':
		case '\n':
D 3
			unlink(line);
E 3
			fclose(mf);
I 3
			unlink(line);
E 3
			break;
		case '!':
			system(buf+1);
			printf("!\n");
			goto cmnd;
		case 's':
		case 'w':
			rewind(mf);
			if(buf[1] == '\n' || buf[1] == '\0')
				strcpy(buf, "s mbox\n");
D 3
			for(p=buf; !isspace(*p); p++);
			for(; isspace(*p); p++);
E 3
I 3
			for(p = buf+1; isspace(*p); p++);
E 3
			p[strlen(p)-1] = 0;
			kf = fopen(p, "a");
			if(kf == NULL)
			{	perror(p);
D 3
				break;
E 3
I 3
				goto cmnd;
E 3
			}
			decipher(mf, kf);
			fclose(mf);
			fclose(kf);
			unlink(line);
			break;
I 3
		default:
			printf("Commands are:\n");
			printf("q	quit, leaving unread messages\n");
			printf("n	delete current message and goto next\n");
			printf("d	same as above\n");
			printf("\\n	same as above\n");
			printf("!	execute shell command\n");
			printf("s	save message in the named file or mbox\n");
			printf("w	same as above\n");
			printf("?	prints this list\n");
			goto cmnd;
E 3
		}
	}
	exit(0);
}
icmp(a, b) int *a, *b;
{
	return(*a - *b);
}
files()
{	int i;
D 2
	if((df = fopen(maildir, "r")) == NULL)
E 2
I 2
	if((df = opendir(maildir)) == NULL)
E 2
	{	perror(maildir);
		exit(1);
	}
	strcpy(line, myname);
	strcat(line, ".%d");
D 2
	for(; !feof(df);)
	{	fread(&dbuf, sizeof(dbuf), 1, df);
		if(feof(df)) break;
		if(dbuf.d_ino == 0) continue;
		if(sscanf(dbuf.d_name, line, &i) != 1)
E 2
I 2
	while ((dbuf = readdir(df)) != NULL) 
D 3
	{	if(sscanf(dbuf->d_name, line, &i) != 1)
E 3
I 3
	{
		if(sscanf(dbuf->d_name, line, &i) != 1)
E 3
E 2
			continue;
		if(fcnt >= MXF)
			break;
		fnum[fcnt++] = i;
	}
I 2
	closedir(df);
E 2
	if(fcnt == 0)
	{	printf("no secret mail\n");
		exit(0);
	}
	qsort(fnum, fcnt, sizeof(int), icmp);
}
decipher(u, w) FILE *u, *w;
{	int i;
	short a;
	for(;;)
	{	nin(mbuf, u);
		if(feof(u)) break;
		mult(mbuf, x, mbuf);
		mdiv(mbuf, b, q, mbuf);
		for(i=1; i<=3; i++)
		{	a = mbuf->val[i];
			putc(a&0177, w);
			a >>= 8;
			putc(a&0177, w);
		}
	}
}
E 1
