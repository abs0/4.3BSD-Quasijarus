h33247
s 00003/00003/00187
d D 4.3 85/07/29 09:37:58 bloom 3 2
c fix from ks@purdue-ecn
e
s 00002/00002/00188
d D 4.2 84/06/05 16:45:26 ralph 2 1
c fix problem with dup references and -e -s options.
e
s 00190/00000/00000
d D 4.1 83/05/06 23:30:07 tut 1 0
c date and time created 83/05/06 23:30:07 by tut
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
#define NFLD 30
#define TLEN 512

extern FILE *in;
char one[ANSLEN];
int onelen = ANSLEN;
D 3
static char dr [100] = "";
E 3
I 3
extern char usedir[];
E 3

doref(line1)
char *line1;
{
	char buff[QLEN], dbuff[3*QLEN];
	char answer[ANSLEN], temp[TLEN], line[BUFSIZ];
	char *p, **sr, *flds[NFLD], *r;
	int stat, nf, nr, query = 0, alph, digs;

   again:
	buff[0] = dbuff[0] = NULL;
	if (biblio && Iline == 1 && line1[0] == '%')
		strcat(dbuff, line1);
	while (input(line)) {		/* get query */
		Iline++;
		if (prefix(".]", line))
			break;
		if (biblio && line[0] == '\n')
			break;
		if (biblio && line[0] == '%' && line[1] == *convert)
			break;
		if (control(line[0]))
			query = 1;
		strcat(query ? dbuff : buff, line);
		if (strlen(buff) > QLEN)
			err("query too long (%d)", strlen(buff));
		if (strlen(dbuff) > 3 * QLEN)
			err("record at line %d too long", Iline-1);
	}
	if (biblio && line[0] == '\n' && feof(in))
		return;
	if (strcmp(buff, "$LIST$\n")==0) {
		assert (dbuff[0] == 0);
		dumpold();
		return;
	}
	answer[0] = 0;
	for (p = buff; *p; p++) {
		if (isupper(*p))
			*p |= 040;
	}
	alph = digs = 0;
	for (p = buff; *p; p++) {
		if (isalpha(*p))
			alph++;
		else
			if (isdigit(*p))
				digs++;
			else {
				*p = 0;
				if ((alph+digs < 3) || common(p-alph)) {
					r = p-alph;
					while (r < p)
						*r++ = ' ';
				}
				if (alph == 0 && digs > 0) {
					r = p-digs;
					if (digs != 4 || atoi(r)/100 != 19) { 
						while (r < p)
							*r++ = ' ';
					}
				}
				*p = ' ';
				alph = digs = 0;
			}
	}
	one[0] = 0;
	if (buff[0]) {	/* do not search if no query */
		for (sr = rdata; sr < search; sr++) {
			temp[0] = 0;
			corout(buff, temp, "hunt", *sr, TLEN);
			assert(strlen(temp) < TLEN);
			if (strlen(temp)+strlen(answer) > BUFSIZ)
				err("Accumulated answers too large",0);
			strcat(answer, temp);
			if (strlen(answer)>BUFSIZ)
				err("answer too long (%d)", strlen(answer));
			if (newline(answer) > 0)
				break;
		}
	}
	assert(strlen(one) < ANSLEN);
	assert(strlen(answer) < ANSLEN);
	if (buff[0])
		switch (newline(answer)) {
		case 0:
			fprintf(stderr, "No such paper: %s\n", buff);
			return;
		default:
			fprintf(stderr, "Too many hits: %s\n", trimnl(buff));
			choices(answer);
			p = buff;
			while (*p != '\n')
				p++;
			*++p = 0;
		case 1:
			if (endpush)
				if (nr = chkdup(answer)) {
					if (bare < 2) {
						nf = tabs(flds, one);
						nf += tabs(flds+nf, dbuff);
						assert(nf < NFLD);
D 2
						putsig(nf,flds,nr,line1,line);
E 2
I 2
						putsig(nf,flds,nr,line1,line,0);
E 2
					}
					return;
				}
			if (one[0] == 0)
D 3
				corout(answer, one, "deliv", dr, QLEN);
E 3
I 3
				corout(answer, one, "deliv", usedir, QLEN);
E 3
			break;
		}
	assert(strlen(buff) < QLEN);
	assert(strlen(one) < ANSLEN);
	nf = tabs(flds, one);
	nf += tabs(flds+nf, dbuff);
	assert(nf < NFLD);
	refnum++;
	if (sort)
		putkey(nf, flds, refnum, keystr);
	if (bare < 2)
D 2
		putsig(nf, flds, refnum, line1, line);
E 2
I 2
		putsig(nf, flds, refnum, line1, line, 1);
E 2
	else
		flout();
	putref(nf, flds);
	if (biblio && line[0] == '\n')
		goto again;
	if (biblio && line[0] == '%' && line[1] == *convert)
		fprintf(fo, "%s%c%s", convert+1, sep, line+3);
}

newline(s)
char *s;
{
	int k = 0, c;

	while (c = *s++)
		if (c == '\n')
			k++;
	return(k);
}

choices(buff)
char *buff;
{
	char ob[BUFSIZ], *p, *r, *q, *t;
	int nl;

	for (r = p = buff; *p; p++) {
		if (*p == '\n') {
			*p++ = 0;
D 3
			corout(r, ob, "deliv", dr, BUFSIZ);
E 3
I 3
			corout(r, ob, "deliv", usedir, BUFSIZ);
E 3
			nl = 1;
			for (q = ob; *q; q++) {
				if (nl && (q[0]=='.'||q[0]=='%') && q[1]=='T') {
					q += 3;
					for (t = q; *t && *t != '\n'; t++)
						;
					*t = 0;
					fprintf(stderr, "%.70s\n", q);
					q = 0; 
					break;
				}
				nl = *q == '\n';
			}
			if (q)
				fprintf(stderr, "??? at %s\n",r);
			r=p;
		}
	}
}

control(c)
{
	if (c == '.')
		return(1);
	if (c == '%')
		return(1);
	return(0);
}
E 1
