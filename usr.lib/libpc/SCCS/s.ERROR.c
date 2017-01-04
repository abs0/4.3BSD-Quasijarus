h57020
s 00002/00001/00022
d D 1.10 83/01/10 16:42:49 mckusick 11 10
c SETRACE() -> kill()
e
s 00001/00010/00022
d D 1.9 82/02/02 16:01:29 mckusic 10 9
c break out case range error into CASERNG
e
s 00013/00142/00019
d D 1.8 81/06/10 00:37:41 mckusic 9 8
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00010/00021/00151
d D 1.7 81/06/08 00:35:19 mckusic 8 7
c put in better error messages
e
s 00000/00010/00172
d D 1.6 81/03/18 15:01:18 mckusic 7 6
c mods for new formal routine syntax
e
s 00001/00001/00181
d D 1.5 81/03/10 14:40:00 mckusic 6 5
c disallow zero length format widths
e
s 00003/00006/00179
d D 1.4 81/03/08 19:10:51 mckusic 5 4
c fix onyx bug
e
s 00024/00020/00161
d D 1.3 81/03/07 15:54:50 mckusic 4 3
c merge in onyx changes
e
s 00007/00002/00174
d D 1.2 81/01/16 14:18:50 mckusic 3 1
c add ability to catch runtime errors
e
s 00005/00000/00176
d R 1.2 81/01/16 12:59:09 mckusic 2 1
c add extension to catch runtime errors
e
s 00176/00000/00000
d D 1.1 80/10/30 00:33:08 mckusick 1 0
c date and time created 80/10/30 00:33:08 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

D 3
#include	"stdio.h"
#include	"signal.h"
E 3
I 3
#include	<stdio.h>
I 11
#include	<signal.h>
E 11
D 10
#include	<signal.h>
#include	"h00vars.h"
E 10
E 3
D 9
#include	"h01errs.h"
E 9

/*
D 9
 * Routine ERROR is called from the runtime library when a runtime error
 * occurs. Its arguments are the internal number of the error which occurred,
 * and an error specific piece of error data. The error file is constructed
 * from errdata by the makefile using the editor script make.ed1.
E 9
I 9
 * Routine ERROR is called from the runtime library when a runtime
 * error occurs. Its arguments are a pointer to an error message and 
 * an error specific piece of data.
E 9
 */
D 4
ERROR(errnum, errdata)
E 4
I 4
long
D 5
ERROR(errnum, errordata)
E 5
I 5
D 8
ERROR(errnum, errdata)
E 8
I 8
D 9
ERROR(msg, d1, d2, d3, d4)
E 9
I 9
ERROR(msg, d1, d2)
E 9
E 8
E 5
E 4

D 4
	long		errnum;
E 4
I 4
D 5
	short	errnum;
	double	errordata;
{
E 5
I 5
D 8
	int	errnum;
E 8
I 8
	char	*msg;
D 9
	int	d1, d2, d3, d4;
E 9
I 9
	long	d1, d2;
E 9
{
E 8
E 5
E 4
D 9
	union cvt {
I 8
		int	intdat;
E 8
		long	longdat;
		char	*strngdat;
		double	dbldat;
	} errdata;
D 4
{
E 4
I 4
D 5

	errdata.dbldat = errordata;
E 5
I 5
D 8
{
E 8
I 8

	errdata.dbldat = 0.0;
	errdata.intdat = d1;
E 9
E 8
E 5
E 4
	PFLUSH();
I 3
D 8
	if (_entry[errnum].entryaddr != 0) {
		(*_entry[errnum].entryaddr)(errdata);
		return;
	}
E 8
E 3
	fputc('\n',stderr);
D 10
	SETRACE();
D 8
	switch (errnum) {
E 8
I 8
D 9
	switch ((int)msg) {
E 8
	case ECHR:
D 4
		fprintf(stderr, "Argument to chr of %d is out of range\n"
E 4
I 4
		fprintf(stderr, "Argument to chr of %D is out of range\n"
E 4
			,errdata.longdat);
		return(errdata.longdat);
	case EHALT:
		fputs("Call to procedure halt\n",stderr);
		PCEXIT(0);
	case ENILPTR:
		fputs("Pointer value out of legal range\n",stderr);
		return(0);
	case EPASTEOF:
		fprintf(stderr,"%s: Tried to read past end of file\n"
			,errdata.strngdat);
		return(0);
	case EREADIT:
		fprintf(stderr,"%s: Attempt to read, but open for writing\n"
			,errdata.strngdat);
		return(0);
	case EWRITEIT:
		fprintf(stderr,"%s: Attempt to write, but open for reading\n"
			,errdata.strngdat);
		return(0);
	case ECLOSE:
		fprintf(stderr,"%s: Close failed\n",errdata.strngdat);
		return(0);
	case ELLIMIT:
		fprintf(stderr,"%s: Line limit exceeded\n",errdata.strngdat);
		return(0);
	case ESQRT:
D 4
		fprintf(stderr,"Negative argument of %E to sqrt\n"
E 4
I 4
		fprintf(stderr,"Negative argument of %e to sqrt\n"
E 4
			,errdata.dbldat);
		return(errdata.dbldat);
	case EREFINAF:
		fprintf(stderr,"%s: ",errdata.strngdat);
	case ENOFILE:
		fputs("Reference to an inactive file\n",stderr);
		return(0);
	case EWRITE:
		fputs("Could not write to ",stderr);
		perror(errdata.strngdat);
		return(0);
	case EOPEN:
		fputs("Could not open ",stderr);
		perror(errdata.strngdat);
		return(0);
	case ECREATE:
		fputs("Could not create ",stderr);
		perror(errdata.strngdat);
		return(0);
	case EREMOVE:
		fputs("Could not remove ",stderr);
		perror(errdata.strngdat);
		return(0);
	case ESEEK:
		fputs("Could not reset ",stderr);
		perror(errdata.strngdat);
		return(0);
	case ENAMESIZE:
		fprintf(stderr,"%s: File name too long\n",errdata.strngdat);
		return(0);
	case ELN:
D 4
		fprintf(stderr,"Non-positive argument of %E to ln\n"
E 4
I 4
		fprintf(stderr,"Non-positive argument of %e to ln\n"
E 4
			,errdata.dbldat);
		return(errdata.dbldat);
	case EBADINUM:
		fprintf(stderr,"%s: Bad data found on integer read\n"
			,errdata.strngdat);
		return(0);
	case EBADFNUM:
		fprintf(stderr,"%s: Bad data found on real read\n"
			,errdata.strngdat);
		return(0);
	case ENUMNTFD:
		fprintf(stderr,
			"Unknown name \"%s\" found on enumerated type read\n",
			errdata.strngdat);
		return(0);
	case ENAMRNG:
		fprintf(stderr,
D 4
			"Enumerated type value of %d is out of range on output\n",
E 4
I 4
			"Enumerated type value of %D is out of range on output\n",
E 4
			errdata.longdat);
		return(errdata.longdat);
	case EFMTSIZE:
D 4
		fprintf(stderr,"Negative format width: %d\n",errdata.longdat);
E 4
I 4
D 6
		fprintf(stderr,"Negative format width: %D\n",errdata.longdat);
E 6
I 6
		fprintf(stderr,"Non-positive format width: %D\n",errdata.longdat);
E 6
E 4
		return(0);
	case EGOTO:
		fputs("Active frame not found in non-local goto\n", stderr);
		return(0);
	case ECASE:
D 4
		fprintf(stderr,"Label of %d not found in case\n"
E 4
I 4
		fprintf(stderr,"Label of %D not found in case\n"
E 4
			,errdata.longdat);
		return(errdata.longdat);
	case EOUTOFMEM:
		fputs("Ran out of memory\n",stderr);
		return(0);
D 8
	case ECTLWR:
D 4
		fprintf(stderr, "Range lower bound of %d out of set bounds\n",
E 4
I 4
		fprintf(stderr, "Range lower bound of %D out of set bounds\n",
E 4
			errdata.longdat);
		return(0);
	case ECTUPR:
D 4
		fprintf(stderr, "Range upper bound of %d out of set bounds\n",
E 4
I 4
		fprintf(stderr, "Range upper bound of %D out of set bounds\n",
E 4
			errdata.longdat);
		return(0);
	case ECTSNG:
D 4
		fprintf(stderr, "Value of %d out of set bounds\n",
E 4
I 4
		fprintf(stderr, "Value of %D out of set bounds\n",
E 4
			errdata.longdat);
		return(0);
E 8
D 7
	case ENARGS:
		if (errdata.longdat < 0)
			fprintf(stderr,
D 4
				"There were %d too few arguments to formal routine\n",
E 4
I 4
				"There were %D too few arguments to formal routine\n",
E 4
				-errdata.longdat);
		else
			fprintf(stderr,
D 4
				"There were %d too many arguments to formal routine\n",
E 4
I 4
				"There were %D too many arguments to formal routine\n",
E 4
				errdata.longdat);
		return(0);
E 7
	case EARGV:
D 4
		fprintf(stderr,"Argument to argv of %d is out of range\n"
E 4
I 4
		fprintf(stderr,"Argument to argv of %D is out of range\n"
E 4
			,errdata.longdat);
		return(errdata.longdat);
	case EPACK:
D 4
		fprintf(stderr,"i = %d: Bad i to pack(a,i,z)\n"
E 4
I 4
		fprintf(stderr,"i = %D: Bad i to pack(a,i,z)\n"
E 4
			,errdata.longdat);
		return(errdata.longdat);
	case EUNPACK:
D 4
		fprintf(stderr,"i = %d: Bad i to unpack(z,a,i)\n"
E 4
I 4
		fprintf(stderr,"i = %D: Bad i to unpack(z,a,i)\n"
E 4
			,errdata.longdat);
		return(errdata.longdat);
	case ERANGE:
D 4
		fprintf(stderr,"Value of %d is out of range\n",errdata.longdat);
E 4
I 4
		fprintf(stderr,"Value of %D is out of range\n",errdata.longdat);
E 4
		return(errdata.longdat);
	case ESUBSC:
D 4
		fprintf(stderr,"Subscript value of %d is out of range\n"
E 4
I 4
		fprintf(stderr,"Subscript value of %D is out of range\n"
E 4
			,errdata.longdat);
		return(errdata.longdat);
	case EASRT:
		fprintf(stderr,"Assertion failed: %s\n",errdata.strngdat);
		return(0);
	case ESTLIM:
		fprintf(stderr,
D 4
			"Statement count limit exceeded, %d statements executed\n",
E 4
I 4
			"Statement count limit exceeded, %D statements executed\n",
E 4
			errdata.longdat);
		return(errdata.longdat);
	default:
D 8
		fputs("Panic: unknown error\n",stderr);
E 8
I 8
		fprintf(stderr, msg, d1, d2, d3, d4);
E 8
		return(0);
E 9
I 9
	/*
	 * Historical anomaly
	 */
	if ((int)msg == 5) {
		fprintf(stderr, "Label of %D not found in case\n", d1);
		return d1;
E 9
	}
E 10
I 9
	fprintf(stderr, msg, d1, d2);
I 10
D 11
	SETRACE();
E 11
I 11
	kill(getpid(), SIGTRAP);
E 11
E 10
	return d1;
E 9
}
E 1
