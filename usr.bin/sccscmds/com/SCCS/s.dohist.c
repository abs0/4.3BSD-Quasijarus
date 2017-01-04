h40277
s 00002/00001/00161
d D 1.4 88/02/02 15:56:52 bostic 4 3
c sprintf doesn't return a pointer to it's first arg, anymore
e
s 00002/00002/00160
d D 1.3 87/02/15 16:42:23 lepreau 3 2
c modern syntax for asgops & inits; sccs keywords
e
s 00002/00002/00160
d D 1.2 85/05/04 00:31:28 sam 2 1
c purge old crud
e
s 00162/00000/00000
d D 1.1 85/05/03 13:18:28 sam 1 0
c date and time created 85/05/03 13:18:28 by sam
e
u
U
t
T
I 1
# include	"../hdr/defines.h"

D 3
SCCSID(@(#)dohist	2.1);
E 3
I 3
static char Sccsid[] = "%W%	%G%";
E 3

char	Cstr[RESPSIZE];
char	Mstr[RESPSIZE];

dohist(file)
char *file;
{
	char line[BUFSIZ];
	int tty[3];
	int doprmt;
	register char *p;
	FILE *in;
	extern char *Mrs;
	extern char *Comments;
	extern int Domrs;

	in = xfopen(file,0);
	while ((p = fgets(line,sizeof(line),in)) != NULL)
		if (line[0] == CTLCHAR && line[1] == EUSERNAM)
			break;
	if (p != NULL) {
		while ((p = fgets(line,sizeof(line),in)) != NULL)
			if (line[3] == VALFLAG && line[1] == FLAG && line[0] == CTLCHAR)
				break;
			else if (line[1] == BUSERTXT && line[0] == CTLCHAR)
				break;
		if (p != NULL && line[1] == FLAG) {
			Domrs++;
		}
	}
	fclose(in);
	doprmt = 0;
	if (gtty(0,tty) >= 0)
		doprmt++;
	if (Domrs && !Mrs) {
		if (doprmt)
			printf("MRs? ");
		Mrs = getresp(" ",Mstr);
	}
	if (Domrs)
		mrfixup();
	if (!Comments) {
		if (doprmt)
			printf("comments? ");
D 4
		Comments = getresp(sprintf(line,"\n%c%c ",CTLCHAR,COMMENTS),Cstr);
E 4
I 4
		sprintf(line,"\n%c%c ",CTLCHAR,COMMENTS);
		Comments = getresp(line,Cstr);
E 4
	}
}


getresp(repstr,result)
char *repstr;
char *result;
{
D 2
	char line[BUFSIZ];
E 2
I 2
	char line[BUFSIZ], *index();
E 2
	register int done, sz;
	register char *p;

	result[0] = 0;
	done = 0;
	setbuf(stdin,NULL);
	sz = sizeof(line) - size(repstr);
	while (!done && fgets(line,sz,stdin) != NULL) {
D 2
		p = strend(line);
E 2
I 2
		p = index(line, '\0');
E 2
		if (*--p == '\n') {
			if (*--p == '\\') {
				copy(repstr,p);
			}
			else {
				*++p = 0;
				++done;
			}
		}
		else
			fatal("line too long (co18)");
		if ((size(line) + size(result)) > RESPSIZE)
			fatal("response too long (co19)");
		strcat(result,line);
	}
	return(result);
}


char	*Varg[NVARGS];

valmrs(pkt,pgm)
struct packet *pkt;
char *pgm;
{
	extern char *Sflags[];
	register int i;
	int st;
	register char *p;

	Varg[0] = pgm;
	Varg[1] = auxf(pkt->p_file,'g');
	if (p = Sflags[TYPEFLAG - 'a'])
		Varg[2] = p;
	else
		Varg[2] = Null;
	if ((i = fork()) < 0) {
		fatal("cannot fork; try again (co20)");
	}
	else if (i == 0) {
		for (i = 4; i < 15; i++)
			close(i);
		pexec(pgm,Varg);
		exit(1);
	}
	else {
		wait(&st);
		return(st);
	}
}


mrfixup()
{
	register char **argv, *p, c;
	char *ap;

	argv = &Varg[VSTART];
	p = Mrs;
	NONBLANK(p);
	for (ap = p; *p; p++) {
		if (*p == ' ' || *p == '\t') {
			if (argv >= &Varg[(NVARGS - 1)])
				fatal("too many MRs (co21)");
			*argv = stalloc(size(ap));
			c = *p;
			*p = 0;
			copy(ap,*argv);
			*p = c;
			argv++;
			NONBLANK(p);
			ap = p;
		}
	}
	--p;
	if (*p != ' ' && *p != '\t')
		copy(ap,*argv++ = stalloc(size(ap)));
	*argv = 0;
}


# define STBUFSZ	500

stalloc(n)
register int n;
{
	static char stbuf[STBUFSZ];
	static int stind;
	register char *p;

	p = &stbuf[stind];
	if (&p[n] >= &stbuf[STBUFSZ])
		fatal("out of space (co22)");
D 3
	stind =+ n;
E 3
I 3
	stind += n;
E 3
	return(p);
}
E 1
