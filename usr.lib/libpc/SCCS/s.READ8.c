h24142
s 00000/00019/00180
d D 1.9 83/11/06 22:22:57 peter 9 8
c oops.  i left the diagnostics in.
c oh good, now they are in the sccs file in case we need them.
e
s 00036/00013/00163
d D 1.8 83/11/06 21:52:29 peter 8 7
c yet another try at getting reals read correctly.
e
s 00049/00018/00127
d D 1.7 83/10/28 17:21:15 mckusick 7 6
c massive cleanups to make accept the standard
e
s 00101/00003/00044
d D 1.6 83/10/01 01:19:02 mckusick 6 5
c peter gets pissy and wants it to be "right"!
e
s 00014/00000/00033
d D 1.5 82/04/09 15:28:55 mckusick 5 4
c put in checking for overflow/underflow
e
s 00004/00004/00029
d D 1.4 81/06/10 00:43:51 mckusic 4 3
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00001/00000/00032
d D 1.3 81/01/28 20:33:51 mckusic 3 2
c clear EOLN so that partial last lines can be detected
e
s 00007/00001/00025
d D 1.2 81/01/24 17:25:11 mckusic 2 1
c check for EOF after data read
e
s 00026/00000/00000
d D 1.1 80/10/30 00:34:40 mckusick 1 0
c date and time created 80/10/30 00:34:40 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

#include "h00vars.h"
I 5
#include <errno.h>
extern int errno;
E 5
D 4
#include "h01errs.h"
E 4

double
READ8(curfile)
D 8

E 8
	register struct iorec	*curfile;
{
	double			data;
I 2
	int			retval;
E 2

	if (curfile->funit & FWRITE) {
D 4
		ERROR(EREADIT, curfile->pfname);
E 4
I 4
		ERROR("%s: Attempt to read, but open for writing\n",
			curfile->pfname);
E 4
		return;
	}
	UNSYNC(curfile);
I 5
	errno = 0;
E 5
D 2
	if (fscanf(curfile->fbuf, "%lf", &data) == 0) {
E 2
I 2
D 6
	retval = fscanf(curfile->fbuf, "%lf", &data);
E 6
I 6
D 7
	retval = readreal(curfile->fbuf, &data);
E 7
I 7
	retval = readreal(curfile, &data);
E 7
E 6
	if (retval == EOF) {
D 4
		ERROR(EPASTEOF, curfile->pfname);
E 4
I 4
		ERROR("%s: Tried to read past end of file\n", curfile->pfname);
E 4
		return;
	}
	if (retval == 0) {
E 2
D 4
		ERROR(EBADFNUM, curfile->pfname);
E 4
I 4
		ERROR("%s: Bad data found on real read\n", curfile->pfname);
I 5
		return;
	}
	if (errno == ERANGE) {
		if (data == 0.0)
			ERROR("%s: Underflow on real read\n", curfile->pfname);
		else
			ERROR("%s: Overflow on real read\n", curfile->pfname);
		return;
	}
	if (errno != 0) {
D 6
		PERROR(curfile->pfname);
E 6
I 6
		PERROR("Error encountered on real read ", curfile->pfname);
E 6
E 5
E 4
		return;
	}
I 3
D 7
	curfile->funit &= ~EOLN;
E 3
	curfile->funit |= SYNC;
E 7
D 6
	return data;
E 6
I 6
	return (data);
}

/*
 *	given a file pointer, read a sequence of characters of the
 *	syntax of section 6.1.5 and form them into a double.
 *
 *	the syntax of a signed-real is:
D 8
 *	    [-|+] digit {digit} e [+|-] digit {digit}
 *	or
 *	    [-|+] digit {digit} . digit {digit} [e [+|-] digit {digit}]
E 8
I 8
 *	    [-|+] digit {digit} [ . digit {digit} ] [ e [+|-] digit {digit} ]
E 8
 *
 *	returns:
 *		1	for success (with value in *doublep)
 *		0	on error (with *doublep unchanged)
 *	       -1	on end-of-file during read (with *doublep unchanged)
 *	side effects:
 *	      errno	may be set to ERANGE if atof() sets it.
 */
D 7
readreal(filep, doublep)
	FILE	*filep;
	double	*doublep;
E 7
I 7
readreal(curfile, doublep)
	struct iorec	*curfile;
	double		*doublep;
E 7
{
D 7
	char	sequence[BUFSIZ];	/* the character sequence */
E 7
I 7
	FILE	*filep = curfile->fbuf;	/* current file variable */
E 7
	char	*sequencep;		/* a pointer into sequence */
	int	read;			/* return value from fscanf() */
I 7
	char	sequence[BUFSIZ];	/* the character sequence */
E 7
	double	atof();

I 7
#define PUSHBACK(curfile, sequencep) \
	if (ungetc(*--(sequencep), (curfile)->fbuf) != EOF) { \
		*(sequencep) = '\0'; \
	} else if ((curfile)->funit & SYNC) { \
		(curfile)->funit &= ~SYNC; \
		*(curfile)->fileptr = *(sequencep); \
		*(sequencep) = '\0'; \
	} else { \
		return (0); \
	}

E 7
#define	RETURN_ON_EOF(read) \
	if (read == EOF) \
		return (EOF); \
	else \
		/* void */;

#define	PUSH_TO_NULL(sequencep) \
	while (*sequencep) \
		sequencep++;

I 8
	/* general reader of the next character */
#define	NEXT_CHAR(read, filep, format, sequencep) \
	read = fscanf(filep, "%c", sequencep); \
	RETURN_ON_EOF(read); \
	*++sequencep = '\0';

	/* e.g. use %[0123456789] for {digit}, and check read */
E 8
#define	SOME(read, filep, format, sequencep) \
	read = fscanf(filep, format, sequencep); \
	RETURN_ON_EOF(read); \
	PUSH_TO_NULL(sequencep);

I 8
	/* e.g. use %[0123456789] for digit {digit} */
E 8
#define	AT_LEAST_ONE(read, filep, format, sequencep) \
	read = fscanf(filep, format, sequencep); \
	RETURN_ON_EOF(read); \
	if (strlen(sequencep) < 1) \
		return (0); \
	PUSH_TO_NULL(sequencep);

D 8
#define	EXACTLY_ONE(read, filep, format, sequencep) \
E 8
I 8
#define	ANY_ONE_OF(read, filep, format, sequencep) \
E 8
	read = fscanf(filep, format, sequencep); \
	RETURN_ON_EOF(read); \
	if (strlen(sequencep) != 1) \
		return (0); \
	PUSH_TO_NULL(sequencep);

#define	AT_MOST_ONE(read, filep, format, sequencep) \
	read = fscanf(filep, format, sequencep); \
	RETURN_ON_EOF(read); \
	if (strlen(sequencep) > 1) \
		return (0); \
	PUSH_TO_NULL(sequencep);
		
	sequencep = &sequence[0];
	*sequencep = '\0';
	/*
D 8
	 * skip leading whitespace
E 8
I 8
	 *	skip leading whitespace
E 8
	 */
	SOME(read, filep, "%*[ \t\n]", sequencep);
	/*
I 8
	 *	this much is required:
E 8
	 *	[ "+" | "-" ] digit {digits}
	 */
	AT_MOST_ONE(read, filep, "%[+-]", sequencep);
I 8
D 9
fprintf(stderr,	"leading sign		<%s>\n", sequence);
E 9
E 8
	AT_LEAST_ONE(read, filep, "%[0123456789]", sequencep);
I 8
D 9
fprintf(stderr,	"leading digits		<%s>\n", sequence);
E 9
E 8
	/*
D 8
	 *	either
	 *		"." digit {digit} [ "e" [ "+" | "-" ] digit {digits} ]
	 *	or
	 *		"e" [ "+" | "-" ] digit {digits}
E 8
I 8
	 *	any of this is optional:
	 *	[ `.' digit {digit} ] [ `e' [ `+' | `-' ] digit {digits} ]
E 8
	 */
D 7
	AT_MOST_ONE(read, filep, "%[.]", sequencep);
	if (read) {
		AT_LEAST_ONE(read, filep, "%[0123456789]", sequencep);
		AT_MOST_ONE(read, filep, "%[e]", sequencep);
		if (read) {
			AT_MOST_ONE(read, filep, "%[+-]", sequencep);
			AT_LEAST_ONE(read, filep, "%[0123456789]", sequencep);
E 7
I 7
D 8
	AT_MOST_ONE(read, filep, "%c", sequencep);
E 8
I 8
D 9
*sequencep = getc(filep);
fprintf(stderr,	"before [.e]		0x%x\n", *sequencep);
ungetc(*sequencep, filep);
*sequencep = '\0';
	/* ANY_ONE_OF(read, filep, "%c", sequencep);*/
	/* read = fscanf(filep, "%c", sequencep);
	 * *++sequencep = '\0';
	 */
E 9
	NEXT_CHAR(read, filep, "%c", sequencep);
D 9
fprintf(stderr,	"[.e] (read %d)		<%s>\n", read, sequence);
E 9
E 8
	switch (sequencep[-1]) {
	default:
		PUSHBACK(curfile, sequencep);
		goto convert;
	case '.':
		SOME(read, filep, "%[0123456789]", sequencep);
I 8
D 9
fprintf(stderr,	"trailing digits	<%s>\n", sequence);
E 9
E 8
		if (!read) {
			PUSHBACK(curfile, sequencep);
			goto convert;
E 7
		}
D 7
	} else {
		EXACTLY_ONE(read, filep, "%[e]", sequencep);
		AT_MOST_ONE(read, filep, "%[+-]", sequencep);
		AT_LEAST_ONE(read, filep, "%[0123456789]", sequencep);
E 7
I 7
D 8
		AT_MOST_ONE(read, filep, "%c", sequencep);
E 8
I 8
D 9
		/* AT_MOST_ONE(read, filep, "%c", sequencep); */
E 9
		NEXT_CHAR(read, filep, "%c", sequencep);
D 9
fprintf(stderr,	"optional e		<%s>\n", sequence);
E 9
E 8
		if (sequencep[-1] != 'e') {
			PUSHBACK(curfile, sequencep);
			goto convert;
		}
		/* fall through */
	case 'e':
D 8
		AT_MOST_ONE(read, filep, "%c", sequencep);
E 8
I 8
D 9
		/* ANY_ONE_OF(read, filep, "%c", sequencep); */
E 9
		NEXT_CHAR(read, filep, "%c", sequencep);
D 9
fprintf(stderr,	"exponent sign		<%s>\n", sequence);
E 9
E 8
		if (sequencep[-1] != '+' && sequencep[-1] != '-') {
			PUSHBACK(curfile, sequencep);
			SOME(read, filep, "%[0123456789]", sequencep);
I 8
D 9
fprintf(stderr,	"signed exponent	<%s>\n", sequence);
E 9
E 8
			if (!read)
				PUSHBACK(curfile, sequencep);
			goto convert;
		}
		SOME(read, filep, "%[0123456789]", sequencep);
I 8
D 9
fprintf(stderr,	"unsigned exponent	<%s>\n", sequence);
E 9
E 8
		if (!read) {
			PUSHBACK(curfile, sequencep);
			PUSHBACK(curfile, sequencep);
		}
E 7
	}
I 7

convert:
E 7
	/*
	 * convert sequence to double
	 */
I 8
D 9
fprintf(stderr,	"convert		<%s>\n", sequence);
E 9
E 8
	*doublep = atof(&sequence[0]);
	return (1);
E 6
}
E 1
