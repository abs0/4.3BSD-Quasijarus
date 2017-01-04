h47742
s 00009/00010/00044
d D 4.3 88/04/24 17:05:49 bostic 3 2
c fixes for ANSI C
e
s 00002/00002/00052
d D 4.2 85/01/09 15:52:24 ralph 2 1
c fix type warnings
e
s 00054/00000/00000
d D 4.1 83/05/06 23:47:32 tut 1 0
c date and time created 83/05/06 23:47:32 by tut
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

recopy (ft, fb, fa, nhash)
FILE *ft, *fb, *fa;
{
	/* copy fb (old hash items/pointers) to ft (new ones) */
	int n, i, iflong;
	long getl();
	int getw();
	int *hpt_s;
D 3
	int (*getfun)();
E 3
	long *hpt_l;
	long k, lp;
	if (fa==NULL)
	{
		err("No old pointers",0);
		return;
	}
	fread(&n, sizeof(n), 1, fa);
	fread(&iflong, sizeof(iflong), 1, fa);
	if (iflong)
	{
D 2
		hpt_l =  calloc(sizeof(*hpt_l), n+1);
E 2
I 2
		hpt_l = (long *) calloc(sizeof(*hpt_l), n+1);
E 2
		n =fread(hpt_l, sizeof(*hpt_l), n, fa);
	}
	else
	{
D 2
		hpt_s =  calloc(sizeof(*hpt_s), n+1);
E 2
I 2
		hpt_s =  (int *) calloc(sizeof(*hpt_s), n+1);
E 2
		n =fread(hpt_s, sizeof(*hpt_s), n, fa);
	}
	if (n!= nhash)
		fprintf(stderr, "Changing hash value to old %d\n",n);
	fclose(fa);
D 3
	if (iflong)
		getfun = getl;
	else
		getfun = getw;
E 3
	for(i=0; i<n; i++)
	{
D 3
		if (iflong)
E 3
I 3
		if (iflong) {
E 3
			lp = hpt_l[i];
D 3
		else
E 3
I 3
			fseek(fb, lp, 0);
			while ( (k= getl(fb) ) != -1)
				fprintf(ft, "%04d %06ld\n",i,k);
		} else {
E 3
			lp = hpt_s[i];
D 3
		fseek(fb, lp, 0);
		while ( (k= (*getfun)(fb) ) != -1)
			fprintf(ft, "%04d %06ld\n",i,k);
E 3
I 3
			fseek(fb, lp, 0);
			while ( (k= getw(fb) ) != -1)
				fprintf(ft, "%04d %06ld\n",i,k);
		}
E 3
	}
	fclose(fb);
	return(n);
}
E 1
