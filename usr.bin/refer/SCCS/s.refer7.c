h01370
s 00004/00002/00161
d D 4.4 87/09/30 16:19:40 sam 4 3
c add some paranoia -- fo can be null if errors occur
e
s 00061/00002/00102
d D 4.3 86/04/23 18:19:19 mckusick 3 2
c fix sequencing numbers (from Keith Muller)
e
s 00001/00001/00103
d D 4.2 86/03/12 17:52:30 mckusick 2 1
c fold upper/lowercase when sorting (from muller@nprdc.arpa (Keith Muller))
e
s 00104/00000/00000
d D 4.1 83/05/06 23:30:16 tut 1 0
c date and time created 83/05/06 23:30:16 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

#include "refer..c"

int newr[250];

chkdup(tag)
char *tag;
{
	int i;

	for(i = 1; i <= refnum; i++) {
		if (strcmp(reftable[i], tag)==0)
			return(i);
	}
	reftable[refnum+1] = rtp;
	if (refnum >= NRFTBL)
		err("too many references (%d) for table", refnum);
	strcpy(rtp, tag);
	while (*rtp++);
	if (rtp > reftext + NRFTXT)
		err("reference pointers too long (%d)", rtp-reftext);
	return(0);
}

dumpold()
{
	FILE *fi;
	int c, g1 = 0, nr = 1;

	if (!endpush)
		return;
D 4
	fclose(fo);
	fo = NULL;
E 4
I 4
	if (fo != NULL) {
		fclose(fo);
		fo = NULL;
	}
E 4
	if (sort) {
		char comm[100];
D 2
		sprintf(comm, "sort %s -o %s", tfile, tfile);
E 2
I 2
		sprintf(comm, "sort -f %s -o %s", tfile, tfile);
E 2
		system(comm);
	}
	fi = fopen(tfile, "r");
	if (fi == NULL)
		return;
	flout();
	fprintf(ftemp, ".]<\n");
	while ((c = getc(fi)) > 0) {
		if (c == '\n') {
			nr++;
			g1 = 0;
		}
		if (c == sep)
			c = '\n';
		if (c == FLAG) {
			/* make old-new ref number table */
			char tb[20];
			char *s = tb;
			while ((c = getc(fi)) != FLAG)
				*s++ = c;
			*s = 0;
			if (g1++ == 0)
				newr[atoi(tb)] = nr;
#if EBUG
			fprintf(stderr,
				"nr %d assigned to atoi(tb) %d\n",nr,atoi(tb));
# endif
			fprintf(ftemp,"%d", nr);
			continue;
		}
		putc(c, ftemp);
	}
	fclose(fi);
#ifndef TF
	unlink(tfile);
#endif
	fprintf(ftemp, ".]>\n");
}

recopy (fnam)
char *fnam;
{
	int c;
I 3
	int *wref = NULL;
	int wcnt = 0;
	int wsize = 50;
	int finalrn;
	char sig[MXSIG];
	extern int *realloc();
E 3

I 3
	wref = (int *)calloc((unsigned)wsize, (unsigned)sizeof(int));
E 3
	fclose(ftemp);
	ftemp = fopen(fnam, "r");
	if (ftemp == NULL) {
		fprintf(stderr, "Can't reopen %s\n", fnam);
		exit(1);
	}
	while ((c = getc(ftemp)) != EOF) {
		if (c == FLAG) {
			char tb[10];
			char *s = tb;
			while ((c = getc(ftemp)) != FLAG)
				*s++ = c;
			*s = 0;
D 3
			printf("%d", newr[atoi(tb)]);
			continue;
E 3
I 3
			/*
			 * If sort was done, permute the reference number
			 * to obtain the final reference number, finalrn.
			 */
			if (sort)
				finalrn = newr[atoi(tb)];
			else
				finalrn = atoi(tb);
			if ((++wcnt > wsize) && 
			 ((wref=realloc(wref,(wsize+=50)*sizeof(int)))==NULL)){
				fprintf(stderr, "Ref condense out of memory.");
				exit(1);
			}
			wref[wcnt-1] = finalrn;
			if ((c = getc(ftemp)) == AFLAG) 
				continue;
			wref[wcnt] = 0;
			condense(wref,wcnt,sig);
			wcnt = 0;
			printf("%s", sig);
E 3
		}
		putchar(c);
	}
	fclose(ftemp);
	unlink(fnam);
I 3
}

/*
 * sort and condense referance signals when they are placed in
 * the text. Viz, the signal 1,2,3,4 is condensed to 1-4 and signals
 * of the form 5,2,9 are converted to 2,5,9
 */
condense(wref, wcnt, sig)
int	*wref;
int	wcnt;
char	*sig;
{
	register int i = 0;
	char wt[4];
	extern int wswap();

	qsort(wref, wcnt, sizeof(int), wswap);
	sig[0] = 0;
	while (i < wcnt) {
		sprintf(wt,"%d",wref[i]);
		strcat(sig,wt);
		if ((i+2 < wcnt) && (wref[i] == (wref[i+2] - 2))) {
			while (wref[i] == (wref[i+1] - 1))
				i++;
			strcat(sig, "-");
		} else if (++i < wcnt)
			strcat(sig,",\\|");
	}
}

wswap(iw1, iw2)
register int *iw1,*iw2;
{
	return(*iw1 - *iw2);
E 3
}
E 1
