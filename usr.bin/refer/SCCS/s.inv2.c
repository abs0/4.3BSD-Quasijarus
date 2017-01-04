h03723
s 00097/00000/00000
d D 4.1 83/05/06 23:47:29 tut 1 0
c date and time created 83/05/06 23:47:29 by tut
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
#define LINESIZ 1250

newkeys (outf, inf, recf, nhash, fd, iflong)
FILE *outf, *inf, *recf, *fd;
int *iflong;
{
	/* reads key lines from inf; hashes and writes on outf;
	 * writes orig key on recf, records pointer on outf too.
	 * format of outf is : hash code space record pointer
	 */

	long lp, ftell();
	long ld = 0; 
	int ll = 0, lt = 0;
	char line[LINESIZ];
	char key[30], bkeys[40];
	char *p, *s;
	char *keyv[500];
	int i, nk, ndoc = 0, more = 0, c;

	lp = ftell (recf);
	while (fgets(line, LINESIZ, inf))
	{
		p = line;
		while (*p != '\t') p++;
		*p++ =0;
		fputs(line, recf);
		if (fd)
		{
			sprintf(bkeys, ";%ld", ld);
			ll = strlen(p);
			lt = strlen(bkeys);
			fputs(bkeys, recf);
			sprintf(bkeys, ",%d", ll);
			lt += strlen(bkeys);
			fputs(bkeys, recf);
			ld += ll;
			fputs(p, fd);
		}
		putc('\n',recf);
		for(s=p; *s; s++);
		if (*--s == '\n')
		{
			more=0;
			*s=0;
		}
		else
			more=1;
		_assert (fd==0 || more==0);
		nk = getargs(p, keyv);
		if (more)
			nk--;
		for(i=0; i<nk; i++)
			fprintf(outf,"%04d %06ld\n",hash(keyv[i])%nhash, lp);
# if D1
		for(i=0; i<nk; i++)
			printf("key %s hash %d\n",keyv[i],hash(keyv[i])%nhash);
# endif
		if (more) /* allow more than LINESIZ keys */
		{
			strcpy(key, keyv[nk]);
			for(s=key; *s; s++);
			while ( (c=getc(inf)) != '\n')
			{
				if (c != ' ')
				{
					*s++ = c;
					continue;
				}
				*s=0;
				if (s>key)
					fprintf(outf, "%04d %06ld\n",hash(key)%nhash, lp);
				s = key;
			}
		}
		lp += (strlen(line)+lt+1);
		ndoc++;
	}
	*iflong = (lp>=65536L);
	if (sizeof(int)>2) *iflong=1; /* force long on VAX */
	fclose(recf);
	return(ndoc);
}

trimnl(p)
char *p;
{
	while (*p) p++;
	p--;
	if (*p == '\n') *p=0;
}
E 1
