h37391
s 00010/00005/00054
d D 4.3 87/09/28 18:56:50 bostic 3 2
c "master" declarations; bug report 4.3BSD/usr.bin/27
e
s 00001/00001/00058
d D 4.2 85/01/09 15:52:17 ralph 2 1
c fix type warnings
e
s 00059/00000/00000
d D 4.1 83/05/06 23:47:19 tut 1 0
c date and time created 83/05/06 23:47:19 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char *soutput, *tagout, usedir[];

result(master, nf, fc)
D 3
union ptr {
	unsigned *a; 
	long *b;
D 2
} *master;
E 2
I 2
} master;
E 3
I 3
unsigned *master;
E 3
E 2
FILE *fc;
{
	int i, c;
	char *s;
	long lp;
	extern int iflong;
	char res[100];
I 3
	union ptr {
		unsigned *a; 
		long *b;
	} umaster;
E 3

I 3
	if (iflong)
		umaster.b = (long *) master;
	else
		umaster.a = master;
E 3
	for(i=0; i<nf; i++)
	{
D 3
		lp = iflong ? master.b[i] : master.a[i];
E 3
I 3
		lp = iflong ? umaster.b[i] : umaster.a[i];
E 3
		fseek(fc,lp, 0);
		fgets(res, 100, fc);
		for(s=res; c = *s; s++)
			if (c== ';')
			{
				*s=0;
				break;
			}
		if (tagout !=0)
		{
			if (res[0]=='/' || usedir[0]==0)
				sprintf(tagout, "%s", res);
			else
				sprintf(tagout, "%s/%s", usedir, res);
			while (*tagout) tagout++;
		}
		else
		{
			if (res[0]!='/' || usedir[0]==0)
				printf("%s/", usedir);
			printf("%s\n", res);
		}
	}
}

long
gdate(f)
FILE *f;
{
	struct stat sb;
	fstat (f->_file, &sb);
	return  (sb . st_mtime);
}
E 1
