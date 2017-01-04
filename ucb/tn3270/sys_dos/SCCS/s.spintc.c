h47442
s 00009/00018/00156
d D 3.2 88/03/28 12:23:49 bostic 8 7
c add Berkeley specific header
e
s 00000/00000/00174
d D 3.1 87/08/11 10:20:21 minshall 7 6
c New version numbering.
e
s 00025/00000/00149
d D 1.6 87/07/17 10:05:00 minshall 6 5
c Install sccs headers and copyright notices.
e
s 00001/00001/00148
d D 1.5 87/05/22 12:21:14 minshall 5 4
c New directory structure.
e
s 00001/00003/00148
d D 1.4 87/05/20 15:47:30 minshall 4 3
c Fix include.
e
s 00076/00134/00075
d D 1.3 87/05/20 12:24:13 minshall 3 2
c This version works.
e
s 00015/00020/00194
d D 1.2 87/05/19 16:13:16 minshall 2 1
c More and better.
e
s 00214/00000/00000
d D 1.1 87/05/19 14:08:12 minshall 1 0
c date and time created 87/05/19 14:08:12 by minshall
e
u
U
t
T
I 6
/*
D 8
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 8
I 8
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 8
 *
D 8
 *	Permission to use, copy, modify, and distribute these
 *	programs and their documentation for any purpose and
 *	without fee is hereby granted, provided that this
 *	copyright and permission appear on all copies and
 *	supporting documentation, the name of the Regents of
 *	the University of California not be used in advertising
 *	or publicity pertaining to distribution of the programs
 *	without specific prior permission, and notice be given in
 *	supporting documentation that copying and distribution is
 *	by permission of the Regents of the University of California
 *	and by Gregory Glenn Minshall.  Neither the Regents of the
 *	University of California nor Gregory Glenn Minshall make
 *	representations about the suitability of this software
 *	for any purpose.  It is provided "as is" without
 *	express or implied warranty.
E 8
I 8
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif	/* not lint */
E 8
I 8
#endif /* not lint */
E 8

E 6
I 1
D 4
#define	LINT_ARGS

E 4
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>

D 4
#include "../ntn3270/general.h"
E 4
I 4
D 5
#include "../general.h"
E 5
I 5
#include "../general/general.h"
E 5
E 4
I 2
#include "spint.h"
E 2

#define	PSP_ENVIRONMENT		0x2c
#define	PSP_FCB1		0x5c
#define	PSP_FCB2		0x6c

D 2
#define	INTERRUPT_NUMBER	73

E 2
typedef struct {
    int
	environment,		/* Segment address of environment */
	cmd_ptr_offset,		/* Offset of command to execute */
	cmd_ptr_segment,	/* Segment where command lives */
	fcb1_ptr_offset,	/* Offset of FCB 1 */
	fcb1_ptr_segment,	/* Segment of FCB 1 */
	fcb2_ptr_offset,	/* Offset of FCB 2 */
	fcb2_ptr_segment;	/* Segment of FCB 2 */
} ExecList;

I 3

static int int_offset, int_segment;


E 3
D 2
typedef struct {
    union REGS		regs;
    struct SREGS	sregs;
    int			int_no;	/* Which interrupt to wait on */
    int			done;	/* Are we done, or just took an interrupt? */
    int			rc;	/* return code */
} Spawn;


E 2
void
D 3
do_spawn(command, spawn)
E 3
I 3
spint_finish(spint)
Spint *spint;
{
    union REGS regs;
    struct SREGS sregs;

    if (spint->done == 0) {
	return;				/* Not done yet */
    }

    /*
     * Restore old interrupt handler.
     */

    regs.h.ah = 0x25;
    regs.h.al = spint->int_no;
    regs.x.dx = int_offset;
    sregs.ds = int_segment;
    intdosx(&regs, &regs, &sregs);

    if (spint->regs.x.cflag) {
	fprintf(stderr, "0x%x return code from EXEC.\n", spint->regs.x.ax);
	spint->done = 1;
	spint->rc = 99;
	return;
    }

    regs.h.ah = 0x4d;			/* Get return code */

    intdos(&regs, &regs);

    spint->rc = regs.x.ax;
}

void
spint_continue(spint)
Spint *spint;
{
    _spint_continue(spint);		/* Return to caller */
    spint_finish(spint);
}


void
spint_start(command, spint)
E 3
char *command;
D 3
Spawn *spawn;
E 3
I 3
Spint *spint;
E 3
{
    ExecList mylist;
    char *comspec;
D 3
    void int_spawn();
    int int_offset, int_segment;
E 3
I 3
    void _spint_int();
    union REGS regs;
    struct SREGS sregs;
E 3

    /*
     * Get comspec.
     */
    comspec = getenv("COMSPEC");
    if (comspec == 0) {			/* Can't find where command.com is */
	fprintf(stderr, "Unable to find COMSPEC in the environment.");
D 3
	spawn->done = 1;
	spawn->rc = 99;	/* XXX */
E 3
I 3
	spint->done = 1;
	spint->rc = 99;	/* XXX */
E 3
	return;
    }

    /*
     * Now, hook up our interrupt routine.
     */

D 3
    spawn->regs.h.ah = 0x35;
    spawn->regs.h.al = spawn->int_no;
    intdosx(&spawn->regs, &spawn->regs, &spawn->sregs);
E 3
I 3
    regs.h.ah = 0x35;
    regs.h.al = spint->int_no;
    intdosx(&regs, &regs, &sregs);
E 3

    /* Save old routine */
D 3
    int_offset = spawn->regs.x.bx;
    int_segment = spawn->sregs.es;
E 3
I 3
    int_offset = regs.x.bx;
    int_segment = sregs.es;
E 3

D 3
    spawn->regs.h.ah = 0x25;
    spawn->regs.h.al = spawn->int_no;
    spawn->regs.x.dx = (int) int_spawn;
    segread(&spawn->sregs);
    spawn->sregs.ds = spawn->sregs.cs;
    intdosx(&spawn->regs, &spawn->regs, &spawn->sregs);
E 3
I 3
    regs.h.ah = 0x25;
    regs.h.al = spint->int_no;
    regs.x.dx = (int) _spint_int;
    segread(&sregs);
    sregs.ds = sregs.cs;
    intdosx(&regs, &regs, &sregs);
E 3

    /*
     * Read in segment registers.
     */

D 3
    segread(&spawn->sregs);
E 3
I 3
    segread(&spint->sregs);
E 3

    /*
     * Set up registers for the EXEC call.
     */

D 3
    spawn->regs.h.ah = 0x4b;
    spawn->regs.h.al = 0;
    spawn->regs.x.dx = (int) comspec;
    spawn->sregs.es = spawn->sregs.ds;		/* Superfluous, probably */
    spawn->regs.x.bx = (int) &mylist;
E 3
I 3
    spint->regs.h.ah = 0x4b;
    spint->regs.h.al = 0;
    spint->regs.x.dx = (int) comspec;
    spint->sregs.es = spint->sregs.ds;		/* Superfluous, probably */
    spint->regs.x.bx = (int) &mylist;
E 3

    /*
     * Set up EXEC parameter list.
     */

    ClearElement(mylist);
    mylist.cmd_ptr_offset = (int) command;
D 3
    mylist.cmd_ptr_segment = spawn->sregs.ds;
E 3
I 3
    mylist.cmd_ptr_segment = spint->sregs.ds;
E 3
    mylist.fcb1_ptr_offset = PSP_FCB1;
    mylist.fcb1_ptr_segment = _psp;
    mylist.fcb2_ptr_offset = PSP_FCB2;
    mylist.fcb2_ptr_segment = _psp;
    mylist.environment = *((int far *)(((long)_psp<<16)|PSP_ENVIRONMENT));

    /*
     * Call to assembly language routine to actually set up for
D 3
     * the spawn.
E 3
I 3
     * the spint.
E 3
     */

D 3
    start_spawn(spawn);
    spawn->done = 1;			/* XXX */
E 3
I 3
    _spint_start(spint);
E 3

D 3
    if (spawn->done == 0) {
	return;				/* Not done yet */
    }

    if (spawn->regs.x.cflag) {
	fprintf(stderr, "0x%x return code from EXEC.\n", spawn->regs.x.ax);
	spawn->done = 1;
	spawn->rc = 99;
	return;
    }

    spawn->regs.h.ah = 0x4d;			/* Get return code */

    intdos(&spawn->regs, &spawn->regs);

    spawn->rc = spawn->regs.x.ax;

    /*
     * Restore old interrupt handler.
     */

    spawn->regs.h.ah = 0x25;
    spawn->regs.h.al = spawn->int_no;
    spawn->regs.x.dx = int_offset;
    spawn->sregs.ds = int_segment;
    intdosx(&spawn->regs, &spawn->regs, &spawn->sregs);
}
I 2

/* XXX */
E 2

I 2
#define	INTERRUPT_NUMBER	73

E 2
main(argc, argv, envp)
int	argc;				/* Number of passed arguments */
char	*argv[];			/* Arguments passed */
char	*envp[];			/* Inherited environment */
{
    Spawn spawned;
    static char command[256];

    ClearElement(spawned);
    spawned.int_no = INTERRUPT_NUMBER;
    if (argc == 1) {
	command[0] = 0;
    } else {
	char *cmdptr;
	int length;

	argc--;
	argv++;
	strcpy(command, " /c");
	cmdptr = command+strlen(command);
	while (argc) {
	    if ((cmdptr+strlen(*argv)) >= (command+sizeof command)) {
		fprintf(stderr, "Argument list too long at argument *%s*.\n",
			    *argv);
		return 0;
	    }
	    *cmdptr++ = ' ';		/* Blank separators */
	    strcpy(cmdptr, *argv);
	    cmdptr += strlen(cmdptr);
	    argc--;
	    argv++;
	}
	length = strlen(command)-1;
	if (length < 0) {
	    length = 0;
	}
	command[0] = length;
    }

    /*
D 2
     * do_spawn returns when either the command has finished, or when
E 2
I 2
     * do_spawn() returns when either the command has finished, or when
E 2
     * the required interrupt comes in.  In the latter case, the appropriate
     * thing to do is to process the interrupt, and then return to
D 2
     * the interrupt issuer.
E 2
I 2
     * the interrupt issuer by calling continue_spawn().
E 2
     */
    do_spawn(command, &spawned);
D 2
    if (spawned.done == 0) {
E 2
I 2
    while (spawned.done == 0) {
E 2
	/* Process request */
I 2
	spawned.regs.h.al = 0;
	spawned.regs.x.cflag = 0;		/* No errors (yet) */
E 2
	switch (spawned.regs.h.ah) {
	case 1:			/* Add */
D 2
	    spawned.regs.x.cx += spawned.regs.x.dx;
E 2
I 2
	    spawned.regs.x.bx += spawned.regs.x.cx;
E 2
	    break;
	case 2:			/* Subtract */
D 2
	    spawned.regs.x.cx -= spawned.regs.x.dx;
E 2
I 2
	    spawned.regs.x.bx -= spawned.regs.x.cx;
E 2
	    break;
	case 3:			/* Multiply */
D 2
	    spawned.regs.x.cx *= spawned.regs.x.dx;
E 2
I 2
	    spawned.regs.x.bx *= spawned.regs.x.cx;
E 2
	    break;
	case 4:			/* Divide */
D 2
	    spawned.regs.x.cx /= spawned.regs.x.dx;
E 2
I 2
	    spawned.regs.x.bx /= spawned.regs.x.cx;
E 2
	    break;
	default:
	    spawned.regs.h.al = -1;	/* Error */
	    spawned.regs.x.cflag = 1;
	    break;
	}
I 2
	spawned.regs.h.ah = 0;			/* We saw this */
E 2
	continue_spawn(&spawned);
D 2
	/*NOTREACHED*/
	/* continue_spawn() causes an eventual return from do_spawn. */
E 2
    }
    if (spawned.rc != 0) {
	fprintf(stderr, "Process generated a return code of 0x%x.\n",
								spawned.rc);
    }
E 3
I 3
    spint_finish(spint);
E 3
}
E 1
