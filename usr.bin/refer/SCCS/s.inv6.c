h65407
s 00004/00004/00080
d D 4.2 85/01/09 15:52:28 ralph 2 1
c fix type warnings
e
s 00084/00000/00000
d D 4.1 83/05/06 23:47:34 tut 1 0
c date and time created 83/05/06 23:47:34 by tut
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

whash(ft, fa, fb, nhash, iflong, ptotct, phused)
FILE *fa, *fb, *ft;
int nhash, *phused;
long *ptotct;
{
	char line[100];
	int hash = 0, hused = 0;
	long totct = 0L;
	int ct = 0;
	long point;
	long opoint = -1;
	int m;
	int k; 
	long lp;
	long *hpt;
D 2
	int *hfreq = NULL;
E 2
I 2
	int *hfreq;
E 2

D 2
	hpt = calloc (nhash+1, sizeof(*hpt));
E 2
I 2
	hpt = (long *) calloc (nhash+1, sizeof(*hpt));
E 2
	_assert (hpt != NULL);
D 2
	hfreq = calloc (nhash, sizeof(*hfreq));
	_assert (hfreq !=NULL);
E 2
I 2
	hfreq = (int *) calloc (nhash, sizeof(*hfreq));
	_assert (hfreq != NULL);
E 2
	hpt[0] = 0;
	lp= 0;
	while (fgets(line, 100, ft))
	{
		totct++;
		sscanf(line, "%d %ld", &k, &point);
		if (hash < k)
		{
			hused++;
			if (iflong) putl(-1L, fb); 
			else putw(-1, fb);
			hfreq[hash]=ct;
			while (hash<k)
			{
				hpt[++hash] = lp;
				hfreq[hash] = 0;
			}
			hpt[hash] = lp += iflong? sizeof(long) : sizeof(int);
			opoint= -1;
			ct=0;
		}
		if (point!=opoint)
		{
			if (iflong)
				putl(opoint=point, fb);
			else
				putw( (int)(opoint=point), fb);
			lp += iflong? sizeof(long) : sizeof(int);
			ct++;
		}
	}
	if (iflong) putl(-1L, fb); 
	else putw(-1,fb);
	while (hash<nhash)
		hpt[++hash]=lp;
	fwrite(&nhash, sizeof(nhash), 1, fa);
	fwrite(&iflong, sizeof(iflong), 1, fa);
	fwrite(hpt, sizeof(*hpt), nhash, fa);
	fwrite (hfreq, sizeof(*hfreq), nhash, fa);
	*ptotct = totct;
	*phused = hused;
}

putl(ll, f)
long ll;
FILE *f;
{
	putw(ll, f);
}

long
getl(f)
FILE *f;
{
	return(getw(f));
}
E 1
