h12599
s 00002/00002/00048
d D 5.2 85/07/12 17:53:08 jerry 3 2
c patch f77_abort(), delete no_lg.c for better way to detect -lg.
e
s 00001/00001/00049
d D 5.1 85/06/26 18:26:45 jerry 2 1
c move f77_abort() and no_lg.c here from libF77
e
s 00050/00000/00000
d D 1.1 85/06/26 18:18:46 jerry 1 0
c date and time created 85/06/26 18:18:46 by jerry
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
D 2
 *	%W%	%D%
E 2
I 2
 *	%W%	%G%
E 2
 *
 *	all f77 aborts eventually call f77_abort.
 *	f77_abort cleans up open files and terminates with a dump if needed,
 *	with a message otherwise.	
 *
 */

#include <signal.h>
#include "fio.h"

char *getenv();
extern int errno;
D 3
extern int _dbsubc;	/* dbsubc is non-zero if -lg was specified to ld */
E 3
I 3
int _lg_flag;	/* _lg_flag is non-zero if -lg was specified to ld */
E 3

f77_abort( err_val, act_core )
{
	char first_char, *env_var;
	int core_dump;

	env_var = getenv("f77_dump_flag");
	first_char = (env_var == NULL) ? 0 : *env_var;

	signal(SIGILL, SIG_DFL);
	sigsetmask(0);			/* don't block */

	/* see if we want a core dump:
		first line checks for signals like hangup - don't dump then.
		second line checks if -lg specified to ld (e.g. by saying
			-g to f77) and checks the f77_dump_flag var. */
	core_dump = ((nargs() != 2) || act_core) &&
D 3
	    ( (_dbsubc && (first_char != 'n')) || first_char == 'y');
E 3
I 3
	    ( (_lg_flag && (first_char != 'n')) || first_char == 'y');
E 3

	if( !core_dump )
		fprintf(units[STDERR].ufd,"*** Execution terminated\n");

	f_exit();
	_cleanup();
	if( nargs() ) errno = err_val;
	else errno = -2;   /* prior value will be meaningless,
				so set it to undefined value */

	if( core_dump ) abort();
	else  exit( errno );
}
E 1
