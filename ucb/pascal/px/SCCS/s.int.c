h09582
s 00014/00002/00180
d D 5.1 85/06/05 13:50:11 dist 11 10
c Add copyright
e
s 00000/00000/00182
d D 2.1 84/02/08 20:29:03 aoki 10 9
c synchronize to version 2
e
s 00008/00000/00174
d D 1.8 82/02/11 10:54:59 mckusic 9 8
c put in check for old style objs
e
s 00002/00002/00172
d D 1.7 82/02/03 00:00:08 mckusic 8 7
c get rid of panics, so that all signals and errors pass through ERROR()
e
s 00007/00002/00167
d D 1.6 82/02/02 15:36:07 mckusic 7 6
c give correct name when complaining about obsolete files
e
s 00052/00022/00117
d D 1.5 82/02/02 13:32:24 linton 6 5
c added some hooks for pdx
e
s 00028/00044/00111
d D 1.4 81/06/21 16:46:37 mckusic 5 3
c fix code to read from pipes to request only what it needs
e
s 00004/00003/00152
d R 1.4 81/06/19 13:20:33 mckusic 4 3
c change pipesize to BUFSIZ since incore pipes are smaller
e
s 00001/00001/00154
d D 1.3 81/06/07 21:55:38 mckusic 3 2
c change error message for non-interpreter files handed to px
e
s 00122/00118/00033
d D 1.2 81/03/06 22:58:51 mckusic 2 1
c add onyx code
e
s 00151/00000/00000
d D 1.1 81/01/07 16:55:08 mckusick 1 0
c date and time created 81/01/07 16:55:08 by mckusick
e
u
U
t
T
I 1
D 11
/* Copyright (c) 1979 Regents of the University of California */
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 11

D 11
static char sccsid[] = "%Z%%M% %I% %G%";
E 11
I 11
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 11

/*
 * px - interpreter for Berkeley Pascal
 * Version 3.0 Winter 1979
 *
 * Original version for the PDP 11/70 authored by:
 * Bill Joy, Charles Haley, Ken Thompson
 *
 * Rewritten for VAX 11/780 by Kirk McKusick
 */

#include	<signal.h>
I 2
#include	"whoami.h"
E 2
#include	"vars.h"
I 8
#include	"libpc.h"
E 8
#include	"objfmt.h"

I 6
/*
 * New stuff for pdx
 */

extern char *end;
extern loopaddr();
union progcntr *pcaddrp;	/* address of interpreter frame address */

E 6
main(ac,av)

D 2
long	ac;
char	**av;
E 2
I 2
	int	ac;
	char	**av;
E 2

{
D 2
register long bytesread, block;
register char *objprog, *file;
register FILE *prog;
struct	 pxhdr pxhd;
#define	 pipe 3
#define	 pipesize 4096
E 2
I 2
	register char *objprog, *file;
I 7
	char *name;
E 7
D 5
	register long bytesread, block;
E 5
I 5
	register long bytesread, bytestoread, block;
E 5
	register FILE *prog;
	struct	 pxhdr pxhd;
#	define	 pipe 3
D 5
#	define	 pipesize 4096
E 5
E 2

D 2
/*
 * Initialize everything
 */
_argc = ac;
_argv = av;
_nodump = 0;
E 2
I 2
	/*
	 * Initialize everything
	 */
	_argc = ac;
	_argv = av;
	_nodump = FALSE;
E 2

D 2
/*
 * Determine how PX was invoked, and how to process the program 
 */
if (_argv[0][0] == '-' && _argv[0][1] == 'o')
	{
	file = &_argv[0][2];
	_mode = PIX;
	}
else if (_argc <= 1)
	{
	file = "obj";
	_mode = PX;
	}
else if (_argv[1][0] != '-')
	{
	file = _argv[1];
	_mode = PX;
	}
else if (_argv[1][1] == 0)
	{
	file = _argv[0];
	_mode = PIPE;
	_argc -= 1;
	_argv[1] = _argv[0];
	_argv = &_argv[1];
	}
else
	{
	fputs("Improper specification of object file to PX\n",stderr);
	exit(1);
	}
E 2
I 2
	/*
	 * Determine how PX was invoked, and how to process the program 
	 */
D 5
	if (_argv[0][0] == '-' && _argv[0][1] == 'o')
		{
E 5
I 5
D 6
	if (_argv[0][0] == '-' && _argv[0][1] == 'o') {
E 5
		file = &_argv[0][2];
E 6
I 6
	file = _argv[1];
	if (!strcmp(_argv[0], "pdx")) {
		_mode = PDX;
		_argv += 2; _argc -= 2;
I 7
		name = _argv[0];
E 7
	} else if (!strcmp(_argv[0], "pix")) {
E 6
		_mode = PIX;
D 5
		}
	else if (_argc <= 1)
		{
E 5
I 5
D 6
	} else if (_argc <= 1) {
E 5
		file = "obj";
		_mode = PX;
D 5
		}
	else if (_argv[1][0] != '-')
		{
E 5
I 5
	} else if (_argv[1][0] != '-') {
E 5
		file = _argv[1];
		_mode = PX;
D 5
		}
	else if (_argv[1][1] == 0)
		{
E 5
I 5
	} else if (_argv[1][1] == 0) {
E 5
		file = _argv[0];
E 6
I 6
		_argv++; _argc--;
I 7
		name = _argv[0];
E 7
	} else if (!strcmp(_argv[0], "pipe")) {
E 6
		_mode = PIPE;
D 6
		_argc -= 1;
		_argv[1] = _argv[0];
		_argv = &_argv[1];
E 6
I 6
		file = "PIPE";
		_argv++; _argc--;
I 7
		name = _argv[0];
E 7
E 6
D 5
		}
	else
		{
E 5
I 5
	} else {
E 5
D 6
		fputs("Improper specification of object file to PX\n",stderr);
		exit(1);
E 6
I 6
		_mode = PX;
		if (_argc <= 1)
			file = "obj";
I 7
		name = file;
E 7
E 6
D 5
		}
E 5
I 5
	}
E 5
E 2

D 2
/*
 * Process program header information
 */
if (_mode == PIPE)
	read(pipe,&pxhd,sizeof(struct pxhdr));
else
	{
	prog = fopen(file,"r");
	if (prog == NULL)
E 2
I 2
	/*
I 9
	 * kludge to check for old style objs.
	 */
	if (_mode == PX && !strcmp(file, "-")) {
		fprintf(stderr, "%s is obsolete and must be recompiled\n",
		    _argv[0]);
		exit(1);
	}
	/*
E 9
	 * Process program header information
	 */
D 5
	if (_mode == PIPE)
E 5
I 5
	if (_mode == PIPE) {
E 5
		read(pipe,&pxhd,sizeof(struct pxhdr));
D 5
	else
E 2
		{
E 5
I 5
	} else {
E 5
D 2
		perror(file);
E 2
I 2
		prog = fopen(file,"r");
D 5
		if (prog == NULL)
			{
E 5
I 5
		if (prog == NULL) {
E 5
			perror(file);
			exit(1);
D 5
			}
E 5
I 5
		}
E 5
D 6
		fseek(prog,(long)(HEADER_BYTES-sizeof(struct pxhdr)),0);
E 6
		fread(&pxhd,sizeof(struct pxhdr),1,prog);
I 6
		if (pxhd.magicnum != MAGICNUM) {
			fseek(prog,(long)(HEADER_BYTES-sizeof(struct pxhdr)),0);
			fread(&pxhd,sizeof(struct pxhdr),1,prog);
		}
E 6
D 5
		}
	if (pxhd.maketime < createtime)
		{
E 5
I 5
	}
D 6
	if (pxhd.maketime < createtime) {
E 5
		fprintf(stderr,"%s is obsolete and must be recompiled\n",file);
E 2
		exit(1);
D 5
		}
D 2
	fseek(prog,HEADER_BYTES-sizeof(struct pxhdr),0);
	fread(&pxhd,sizeof(struct pxhdr),1,prog);
	}
if (pxhd.maketime < createtime)
	{
	fprintf(stderr,"%s is obsolete and must be recompiled\n",file);
	exit(1);
	}
if (pxhd.magicnum != 0403)
	{
	fprintf(stderr,"%s is not a Pascal program\n",file);
	exit(1);
	}
E 2
I 2
	if (pxhd.magicnum != MAGICNUM)
		{
E 5
I 5
	}
E 6
	if (pxhd.magicnum != MAGICNUM) {
E 5
D 3
		fprintf(stderr,"%s is not a Pascal program\n",file);
E 3
I 3
D 7
		fprintf(stderr,"%s is not a Pascal interpreter file\n",file);
E 7
I 7
		fprintf(stderr,"%s is not a Pascal interpreter file\n",name);
E 7
E 3
		exit(1);
D 5
		}
E 5
I 5
	}
I 6
	if (pxhd.maketime < createtime) {
D 7
		fprintf(stderr,"%s is obsolete and must be recompiled\n",file);
E 7
I 7
		fprintf(stderr,"%s is obsolete and must be recompiled\n",name);
E 7
		exit(1);
	}
E 6
E 5
E 2

D 2
/*
 * Load program into memory
 */
objprog = malloc(pxhd.objsize);
if (_mode == PIPE)
	{
	bytesread = 0;
	do
E 2
I 2
	/*
	 * Load program into memory
	 */
	objprog = malloc((int)pxhd.objsize);
D 5
	if (_mode == PIPE)
E 2
		{
E 5
I 5
	if (_mode == PIPE) {
		bytestoread = pxhd.objsize;
E 5
D 2
		block = read(pipe,objprog+bytesread,pipesize);
		bytesread += block;
E 2
I 2
		bytesread = 0;
D 5
		do
			{
			block = read(pipe,(int)(objprog+bytesread),pipesize);
			bytesread += block;
E 5
I 5
		do	{
			block = read(pipe,(int)(objprog+bytesread),bytestoread);
			if (block > 0) {
				bytesread += block;
				bytestoread -= block;
E 5
			}
D 5
			while (block);
E 2
		}
D 2
		while (block);
	}
else
	{
	bytesread = fread(objprog,1,pxhd.objsize,prog);
	fclose(prog);
E 2
I 2
	else
		{
E 5
I 5
		} while (block > 0);
	} else {
E 5
		bytesread = fread(objprog,1,(int)pxhd.objsize,prog);
		fclose(prog);
D 6
		if (_mode == PIX)
			unlink(file);
E 6
D 5
		}
	if (bytesread != pxhd.objsize)
		{
E 5
I 5
	}
	if (bytesread != pxhd.objsize) {
E 5
		fprintf(stderr,"Read error occurred while loading %s\n",file);
		exit(1);
D 5
		}
E 5
I 5
	}
E 5
E 2
	if (_mode == PIX)
D 2
		unlink(file);
	}
if (bytesread != pxhd.objsize)
	{
	fprintf(stderr,"Read error occurred while loading %s\n",file);
	exit(1);
	}
if (_mode == PIX)
	fputs("Execution begins...\n",stderr);
/*
 * set interpreter to catch expected signals and begin interpretation
 */
signal(SIGILL,syserr);
signal(SIGBUS,syserr);
signal(SIGSYS,syserr);
if (signal(SIGINT,SIG_IGN) != SIG_IGN)
	signal(SIGINT,intr);
signal(SIGSEGV,memsize);
signal(SIGFPE,except);
signal(SIGTRAP,liberr);
interpreter(objprog);
/*
 * reset signals, deallocate memory, and exit normally
 */
signal(SIGINT,SIG_IGN);
signal(SIGSEGV,SIG_DFL);
signal(SIGFPE,SIG_DFL);
signal(SIGTRAP,SIG_DFL);
signal(SIGILL,SIG_DFL);
signal(SIGBUS,SIG_DFL);
signal(SIGSYS,SIG_DFL);
PFLUSH();
/* pfree(objprog); */
psexit(0);
E 2
I 2
		fputs("Execution begins...\n",stderr);
	/*
	 * set interpreter to catch expected signals and begin interpretation
	 */
	signal(SIGILL,syserr);
	signal(SIGBUS,syserr);
	signal(SIGSYS,syserr);
	if (signal(SIGINT,SIG_IGN) != SIG_IGN)
		signal(SIGINT,intr);
	signal(SIGSEGV,memsize);
D 8
	signal(SIGFPE,except);
E 8
I 8
	signal(SIGFPE,EXCEPT);
E 8
	signal(SIGTRAP,liberr);
I 6

E 6
	/*
I 6
	 * See if we're being watched by the debugger, if so set a trap.
	 */
	if (_mode == PDX || (_mode == PIX && pxhd.symtabsize > 0)) {
		inittrap(&_display, &_dp, objprog, &pcaddrp, loopaddr);
	}

	/*
E 6
	 * do it
	 */
	interpreter(objprog);
	/*
	 * reset signals, deallocate memory, and exit normally
	 */
	signal(SIGINT,SIG_IGN);
	signal(SIGSEGV,SIG_DFL);
	signal(SIGFPE,SIG_DFL);
	signal(SIGTRAP,SIG_DFL);
	signal(SIGILL,SIG_DFL);
	signal(SIGBUS,SIG_DFL);
	signal(SIGSYS,SIG_DFL);
	PFLUSH();
D 8
	/* pfree(objprog); */
E 8
	psexit(0);
I 6
}

/*
 * Generate an IOT trap to tell the debugger that the object code
 * has been read in.  Parameters are there for debugger to look at,
 * not the procedure.
 */

static inittrap(dispaddr, dpaddr, endaddr, pcaddrp, loopaddrp)
union disply *dispaddr;
struct disp *dpaddr;
char *endaddr;
union progcntr **pcaddrp;
char **loopaddrp;
{
	kill(getpid(), SIGIOT);
E 6
E 2
}
E 1
