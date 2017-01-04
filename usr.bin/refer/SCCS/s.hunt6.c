h09920
s 00021/00016/00116
d D 4.3 87/09/28 18:56:51 bostic 3 2
c "master" declarations; bug report 4.3BSD/usr.bin/27
e
s 00002/00002/00130
d D 4.2 85/01/09 15:52:20 ralph 2 1
c fix type warnings
e
s 00132/00000/00000
d D 4.1 83/05/06 23:47:21 tut 1 0
c date and time created 83/05/06 23:47:21 by tut
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
#include <assert.h>
#define TXTLEN 1000

char *outbuf = 0;
extern char *soutput;
extern int soutlen, iflong;
extern long indexdate;

baddrop(master, nf, fc, nitem, qitem, rprog, full)
D 3
union ptr {
	unsigned *a; 
	long *b; 
} 
master;
E 3
I 3
unsigned *master;
E 3
FILE *fc;
char *qitem[], *rprog;
{
	/* checks list of drops for real bad drops; finds items with "deliv" */
I 3
	union ptr {
		unsigned *a; 
		long *b; 
	} umaster;
E 3
	int i, g, j, need, got, na, len;
	long lp;
	char res[100], *ar[50], output[TXTLEN];
	extern int colevel, reached;
I 3
	
	if (iflong)
		umaster.b = (long *) master;
	else
		umaster.a = master;
E 3
# if D1
	if (iflong)
D 3
		fprintf(stderr,"in baddrop, nf %d master %ld %ld %ld\n",
			nf, master.b[0], master.b[1], master.b[2]);
E 3
I 3
		fprintf(stderr,"in baddrop, nf %d umaster %ld %ld %ld\n",
			nf, umaster.b[0], umaster.b[1], umaster.b[2]);
E 3
	else
D 3
		fprintf(stderr,"in baddrop, nf %d master %d %d %d\n",
			nf, master.a[0], master.a[1], master.a[2]);
E 3
I 3
		fprintf(stderr,"in baddrop, nf %d umaster %d %d %d\n",
			nf, umaster.a[0], umaster.a[1], umaster.a[2]);
E 3
# endif
	for (i=g=0; i<nf; i++)
	{
D 3
		lp = iflong ? master.b[i] : master.a[i];
E 3
I 3
		lp = iflong ? umaster.b[i] : umaster.a[i];
E 3
# if D1
		if (iflong)
D 3
			fprintf(stderr, "i %d master %lo lp %lo\n",
				i, master.b[i], lp);
E 3
I 3
			fprintf(stderr, "i %d umaster %lo lp %lo\n",
				i, umaster.b[i], lp);
E 3
		else
D 3
			fprintf(stderr, "i %d master %o lp %lo\n",
				i, master.a[i], lp);
E 3
I 3
			fprintf(stderr, "i %d umaster %o lp %lo\n",
				i, umaster.a[i], lp);
E 3
# endif
		fseek (fc, lp, 0);
		fgets( res, 100, fc);
# if D1
		fprintf(stderr, "tag %s", res);
# endif
		if (!auxil(res,output))
		{
			char *s; 
			int c;
# if D1
			fprintf(stderr, "not auxil try rprog %c\n",
				rprog? 'y': 'n');
# endif
			for(s=res; c= *s; s++)
				if (c == ';' || c == '\n')
				{
					*s=0; 
					break;
				}
			len = rprog ?
			corout (res, output, rprog, 0, TXTLEN) :
			findline (res, output, TXTLEN, indexdate);
		}
# if D1
		_assert (len <TXTLEN);
		fprintf(stderr,"item %d of %d, tag %s len %d output\n%s\n..\n",
			i, nf, res, len, output);
# endif
		if (len==0)
			continue;
		need = colevel ? reached : nitem;
		na=0;
		ar[na++] = "fgrep";
		ar[na++] = "-r";
		ar[na++] = "-n";
D 2
		ar[na++] = need;
E 2
I 2
		ar[na++] = (char *) need;
E 2
		ar[na++] = "-i";
		ar[na++] = output;
D 2
		ar[na++] = len;
E 2
I 2
		ar[na++] = (char *) len;
E 2
		for(j=0; j<nitem; j++)
			ar[na++] = qitem[j];
# ifdef D1
		fprintf(stderr, "calling fgrep len %d ar[4] %s %o %d \n",
			len,ar[4],ar[5],ar[6]);
# endif
		if (fgrep(na, ar)==0)
		{
# ifdef D1
			fprintf(stderr, "fgrep found it\n");
# endif
			if (iflong)
D 3
				master.b[g++] = master.b[i];
E 3
I 3
				umaster.b[g++] = umaster.b[i];
E 3
			else
D 3
				master.a[g++] = master.a[i];
E 3
I 3
				umaster.a[g++] = umaster.a[i];
E 3
			if (full >= g)
				if (soutput==0)
					fputs(output, stdout);
				else
					strcpy (soutput, output);
		}
# ifdef D1
		fprintf(stderr, "after fgrep\n");
# endif
	}
	return(g);
}

auxil( res, output)
char *res, *output;
{
	extern FILE *fd;
	long lp, c; 
	int len;
	if (fd==0)return(0);
	while (c = *res++) 
	{
		if (c == ';')
		{
			sscanf(res, "%ld,%d", &lp, &len);
			fseek (fd, lp, 0);
			fgets(output, len, fd);
			return(1);
		}
	}
	return(0);
}
E 1
