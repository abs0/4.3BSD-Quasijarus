h47350
s 00002/00001/00115
d D 4.4 87/09/11 13:47:57 jak 4 3
c bugs caught by Sun and some clearerr-type problems I thought I'd fixed
e
s 00001/00001/00115
d D 4.3 86/05/15 17:58:53 bloom 3 2
c updates from John Kunze
e
s 00031/00021/00085
d D 4.2 83/04/25 23:59:16 mckusick 2 1
c 
e
s 00106/00000/00000
d D 4.1 83/02/24 12:56:13 mckusick 1 0
c date and time created 83/02/24 12:56:13 by mckusick
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include "stdio.h"
#include "lrnref.h"

int	nsave	= 0;
I 2
int	review	= 0;
E 2

selunit()
{
D 2
	char fnam[20], s[50];
E 2
	static char dobuff[50];
I 2
	static char saved[20];
	char fnam[80], s[80], zb[200];
E 2
	char posslev[20][20];
	int diff[20], i, k, m, n, best, alts;
I 2
	char *getlesson();
E 2
	FILE *f;
D 2
	char zb[200];
	static char saved[20];
E 2

I 2
	if (again) {
		again = 0;
		if (todo=getlesson()) {
			if (!review)
				unsetdid(todo);
			return;
		}
		wrapup(1);
	}
E 2
	while (ask) {
		printf("What lesson? ");
		fflush(stdout);
D 4
		gets(dobuff);
E 4
I 4
		if (gets(dobuff) == NULL)
			wrapup(1);
E 4
		if (strcmp(dobuff, "bye") == 0)
D 2
			wrapup(0);
		level = todo = dobuff;
		sprintf(s, "../../%s/L%s", sname, dobuff);
		if (access(s, 04) == 0)
E 2
I 2
			wrapup(1);
		level = dobuff;
		if (todo=getlesson())
E 2
			return;
D 2
		printf("no such lesson\n");
E 2
	}
	alts = 0;
retry:
D 2
	f=scrin;
E 2
I 2
	f = scrin;			/* use old lesson to find next */
E 2
	if (f==NULL) {
D 2
		sprintf(fnam, "../../%s/L%s", sname, level);
E 2
I 2
		sprintf(fnam, "%s/%s/L%s", direct, sname, level);
E 2
		f = fopen(fnam, "r");
		if (f==NULL) {
D 2
			fprintf(stderr, "No script for lesson %s.\n", level);
E 2
I 2
			perror(fnam);
			fprintf(stderr, "Selunit:  no script for lesson %s.\n", level);
E 2
			wrapup(1);
		}
		while (fgets(zb, 200, f)) {
			trim(zb);
			if (strcmp(zb, "#next")==0)
				break;
		}
	}
	if (feof(f)) {
		printf("Congratulations; you have finished this sequence.\n");
		fflush(stdout);
		todo = 0;
D 3
		return;
E 3
I 3
		wrapup(-1);
E 3
	}
D 2
	for(i=0; fgets(s, 50, f); i++) {
E 2
I 2
	for(i=0; fgets(s, 80, f); i++) {
E 2
		sscanf(s, "%s %d", posslev[i], &diff[i]);
	}
	best = -1;
	/* cycle through lessons from random start */
	/* first try the current place, failing that back up to
	     last place there are untried alternatives (but only one backup) */
	n = grand()%i;
	for(k=0; k<i; k++) {
		m = (n+k)%i;
D 2
		if (already(posslev[m],0)) continue;
		if (best<0) best=m;
		/* real alternatives */
		alts++;
E 2
I 2
		if (already(posslev[m]))
			continue;
		if (best<0)
			best = m;
		alts++;				/* real alternatives */
E 2
		if (abs(diff[m]-speed) < abs(diff[best]-speed))
D 2
			best=m;
E 2
I 2
			best = m;
E 2
	}
	if (best < 0 && nsave) {
		nsave--;
		strcpy(level, saved);
		goto retry;
	}
D 2
	if (best <0) {
E 2
I 2
	if (best < 0) {
E 2
		/* lessons exhausted or missing */
		printf("Sorry, there are no alternative lessons at this stage.\n");
		printf("See someone for help.\n");
		fflush(stdout);
		todo = 0;
		return;
	}
	strcpy (dobuff, posslev[best]);
	if (alts>1) {
D 2
		nsave=1;
		strcpy (saved, level);
E 2
I 2
		nsave = 1;
		strcpy(saved, level);
E 2
	}
	todo = dobuff;
	fclose(f);
}

abs(x)
{
D 2
	return(x>=0? x: -x);
E 2
I 2
	return(x>=0 ? x : -x);
E 2
}

grand()
{
	static int garbage;
	int a[2], b;

	time(a);
	b = a[1]+10*garbage++;
	return(b&077777);
}
E 1
