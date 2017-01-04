h25531
s 00005/00003/00363
d D 4.4 87/09/11 13:47:51 jak 4 3
c bugs caught by Sun and some clearerr-type problems I thought I'd fixed
e
s 00004/00002/00362
d D 4.3 86/05/15 17:58:10 bloom 3 2
c updates from John Kunze
e
s 00110/00022/00254
d D 4.2 83/04/25 23:58:37 mckusick 2 1
c 
e
s 00276/00000/00000
d D 4.1 83/02/24 12:55:34 mckusick 1 0
c date and time created 83/02/24 12:55:34 by mckusick
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
#include "signal.h"
#include "lrnref.h"

I 2
char togo[50];
E 2
char last[100];
char logf[100];
char subdir[100];
D 2
extern char * ctime();
E 2
I 2
extern char *ctime();
extern int review;
int noclobber;
E 2

copy(prompt, fin)
I 2
int prompt;
E 2
FILE *fin;
{
	FILE *fout, *f;
D 2
	char s[100], t[100], s1[100], *r, *tod;
	char nm[30];
E 2
I 2
	char s[100], t[100], s1[100], nm[30];
	char *r, *tod, c;
E 2
	int *p, tv[2];
	extern int intrpt(), *action();
	extern char *wordb();
	int nmatch = 0;
I 2
	long mark;
E 2

	if (subdir[0]==0)
D 2
		sprintf(subdir, "../../%s", sname);
E 2
I 2
		sprintf(subdir, "%s/%s", direct, sname);
E 2
	for (;;) {
		if (pgets(s, prompt, fin) == 0)
			if (fin == stdin) {
D 2
				/* fprintf(stderr, "Don't type control-D\n"); */
				/* this didn't work out very well */
E 2
I 2
				fprintf(stderr, "Type \"bye\" if you want to leave learn.\n");
				fflush(stderr);
I 3
				clearerr(stdin);
E 3
E 2
				continue;
			} else
				break;
D 2
		trim(s);
E 2
I 2
		trim(s);		/* trim newline */
E 2
		/* change the sequence %s to lesson directory */
		/* if needed */
		for (r = s; *r; r++)
			if (*r == '%') {
				sprintf(s1, s, subdir, subdir, subdir);
				strcpy(s, s1);
				break;
			}
D 2
		r = wordb(s, t);
		p = action(t);
E 2
I 2
		r = wordb(s, t);	/* t = first token, r = rest */
		p = action(t);		/* p = token class */
E 2
D 4
		if (*p == ONCE) {	/* some actions done only once per script */
E 4
I 4
		if (p && *p == ONCE) {	/* some actions done only once per script */
E 4
D 2
			if (wrong) {	/* we are on 2nd time */
E 2
I 2
			if (wrong && !review) {	/* we are on 2nd time */
E 2
				scopy(fin, NULL);
				continue;
			}
			strcpy(s, r);
			r = wordb(s, t);
			p = action(t);
		}
		if (p == 0) {
D 2
			if (comfile >= 0) {
E 2
I 2
			if (comfile >= 0) {	/* if #pipe in effect ... */
E 2
				write(comfile, s, strlen(s));
				write(comfile, "\n", 1);
			}
D 2
			else {
E 2
I 2
			else {		/* else must be UNIX command ... */
E 2
				signal(SIGINT, SIG_IGN);
				status = mysys(s);
				signal(SIGINT, intrpt);
			}
			if (incopy) {
				fprintf(incopy, "%s\n", s);
				strcpy(last, s);
			}
			continue;
		}
		switch (*p) {
		case READY:
			if (incopy && r) {
				fprintf(incopy, "%s\n", r);
				strcpy(last, r);
			}
			return;
		case PRINT:
			if (wrong)
				scopy(fin, NULL);	/* don't repeat message */
			else if (r)
				list(r);
			else
				scopy(fin, stdout);
			break;
I 2
D 3
		case XYZZY:
E 3
I 3
		case HINT:
E 3
			mark = ftell(scrin);
			if (r)
				rewind(scrin);
			while ((int)(c=fgetc(scrin)) != EOF)
				putchar(c);
			fflush(stdout);
			fseek(scrin, mark, 0);
			break;
E 2
		case NOP:
			break;
		case MATCH:
			if (nmatch > 0)	/* we have already passed */
				scopy(fin, NULL);
			else if ((status = strcmp(r, last)) == 0) {	/* did we pass this time? */
				nmatch++;
				scopy(fin, stdout);
			} else
				scopy(fin, NULL);
			break;
		case BAD:
			if (strcmp(r, last) == 0) {
				scopy(fin, stdout);
			} else
				scopy(fin, NULL);
			break;
		case SUCCEED:
			scopy(fin, (status == 0) ? stdout : NULL);
			break;
		case FAIL:
			scopy(fin, (status != 0) ? stdout : NULL);
			break;
		case CREATE:
D 2
			fout = fopen(r, "w");
E 2
I 2
			if (noclobber)
				fout = NULL;
			else
				fout = fopen(r, "w");
E 2
			scopy(fin, fout);
D 2
			fclose(fout);
E 2
I 2
			if (!noclobber)
				fclose(fout);
E 2
			break;
		case CMP:
			status = cmp(r);	/* contains two file names */
			break;
		case MV:
			sprintf(nm, "%s/L%s.%s", subdir, todo, r);
			fcopy(r, nm);
			break;
		case USER:
		case NEXT:
I 2
			if (noclobber)
				noclobber = 0;
E 2
			more = 1;
			return;
I 3
		/* "again previous_lesson" has a hard-to-reproduce bug */
E 3
I 2
		case AGAIN:
			review = 0;
			if (!r) {
				r = todo;
				noclobber = 1;
				review = 1;
			}
			again = 1;
			strcpy(togo, r);
			unhook();
			return;
		case SKIP:
			skip = 1;
			unhook();
			return;
E 2
		case COPYIN:
			incopy = fopen(".copy", "w");
			break;
		case UNCOPIN:
			fclose(incopy);
			incopy = NULL;
			break;
		case COPYOUT:
D 2
			maktee();
E 2
I 2
			teed = maktee();
E 2
			break;
		case UNCOPOUT:
			untee();
I 2
			teed = 0;
E 2
			break;
		case PIPE:
			comfile = makpipe();
			break;
		case UNPIPE:
			close(comfile);
			wait(0);
			comfile = -1;
			break;
		case YES:
		case NO:
			if (incopy) {
				fprintf(incopy, "%s\n", s);
				strcpy(last, s);
			}
			return;
		case WHERE:
D 2
			printf("You are in lesson %s\n", todo);
E 2
I 2
			printf("You are in lesson %s of \"%s\" with a speed rating of %d.\n", todo, sname, speed);
			printf("You have completed %d out of a possible %d lessons.\n", sequence-1, total);
			if (r)
				tellwhich();
E 2
			fflush(stdout);
			break;
		case BYE:
			more=0;
			return;
		case CHDIR:
			printf("cd not allowed\n");
			fflush(stdout);
			break;
		case LEARN:
			printf("You are already in learn.\n");
			fflush(stdout);
			break;
D 3
		case LOG:
E 3
I 3
		case LOG:	/* logfiles should be created mode 666 */
E 3
			if (!logging)
				break;
			if (logf[0] == 0)
				sprintf(logf, "%s/log/%s", direct, sname);
D 2
			f = fopen( (r? r : logf), "a");
E 2
I 2
			f = fopen((r ? r : logf), "a");
E 2
			if (f == NULL)
				break;
			time(tv);
			tod = ctime(tv);
			tod[24] = 0;
			fprintf(f, "%s L%-6s %s %2d %s\n", tod,
				todo, status? "fail" : "pass", speed, pwline);
			fclose(f);
			break;
		}
	}
	return;
}

pgets(s, prompt, f)
I 2
char *s;
int prompt;
E 2
FILE *f;
{
	if (prompt) {
		if (comfile < 0)
D 2
			printf("$ ");
E 2
I 2
			fputs("% ", stdout);
E 2
		fflush(stdout);
	}
	if (fgets(s, 100,f))
		return(1);
	else
		return(0);
}

trim(s)
char *s;
{
	while (*s)
		s++;
	if (*--s == '\n')
		*s=0;
}

D 2
scopy(fi, fo)	/* copy fi to fo until a line with # */
E 2
I 2
scopy(fi, fo)	/* copy fi to fo until a line with #
		 * sequence "#\n" means a line not ending with \n
		 * control-M's are filtered out */
E 2
FILE *fi, *fo;
{
	int c;

	while ((c = getc(fi)) != '#' && c != EOF) {
		do {
I 2
			if (c == '#')   {
				c = getc(fi);
				if (c == '\n')
					break;
				if (c == EOF)   {
D 4
					fflush(fo);
E 4
I 4
					if (fo != NULL)
						fflush(fo);
E 4
					return;
				}
				if (fo != NULL)
					putc('#', fo);
			}
			if (c == '\r')
				break;
E 2
			if (fo != NULL)
				putc(c, fo);
			if (c == '\n')
				break;
		} while ((c = getc(fi)) != EOF);
	}
	if (c == '#')
		ungetc(c, fi);
D 4
	fflush(fo);
E 4
I 4
	if (fo != NULL)
		fflush(fo);
E 4
}

D 2
cmp(r)	/* compare two files for status */
E 2
I 2
cmp(r)	/* compare two files for status; #cmp f1 f2 [ firstnlinesonly ] */
E 2
char *r;
{
D 2
	char *s;
E 2
I 2
	char *s, *h;
E 2
	FILE *f1, *f2;
D 2
	int c1, c2, stat;
E 2
I 2
	int c1, c2, stat, n;
E 2

	for (s = r; *s != ' ' && *s != '\0'; s++)
		;
	*s++ = 0;	/* r contains file 1 */
	while (*s == ' ')
		s++;
I 2
	for (h = s; *h != ' ' && *h != '\0'; h++)
		;
	if (*h) {
		*h++ = 0;
		while (*h == ' ')
			h++;
		n = atoi(h);
	}
	else
		n = 077777;
E 2
	f1 = fopen(r, "r");
	f2 = fopen(s, "r");
	if (f1 == NULL || f2 == NULL)
		return(1);	/* failure */
	stat = 0;
	for (;;) {
		c1 = getc(f1);
		c2 = getc(f2);
		if (c1 != c2) {
			stat = 1;
			break;
		}
I 2
		if (*h && c1 == '\n')
			if (--n)
				break;
E 2
		if (c1 == EOF || c2 == EOF)
			break;
	}
	fclose(f1);
	fclose(f2);
	return(stat);
}

char *
wordb(s, t)	/* in s, t is prefix; return tail */
char *s, *t;
{
	int c;

	while (c = *s++) {
		if (c == ' ' || c == '\t')
			break;
		*t++ = c;
	}
	*t = 0;
	while (*s == ' ' || *s == '\t')
		s++;
	return(c ? s : NULL);
I 2
}

unhook()
{
	if (incopy) {
		fclose(incopy);
		incopy = NULL;
	}
	if (comfile >= 0) {
		close(comfile);
		wait(0);
		comfile = -1;
	}
	if (teed) {
		teed = 0;
		untee();
	}
	fclose(scrin);
	scrin = NULL;
E 2
}
E 1
