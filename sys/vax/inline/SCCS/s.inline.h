h14941
s 00001/00001/00080
d D 7.1 86/06/05 01:11:35 mckusick 7 6
c 4.3BSD release version
e
s 00002/00000/00079
d D 1.6 86/04/27 20:53:53 karels 6 5
c break out tables for subset vax on -s option; for kridle and bloom
e
s 00001/00001/00078
d D 1.5 86/03/18 23:25:01 mckusick 5 4
c increase buffer size to 1024
e
s 00001/00000/00078
d D 1.4 85/08/21 20:19:35 mckusick 4 3
c do validity checking on number of arguments (from donn@utah-cs)
e
s 00007/00003/00071
d D 1.3 85/06/08 14:21:31 mckusick 3 2
c Add copyright
e
s 00024/00004/00050
d D 1.2 84/08/20 21:01:43 mckusick 2 1
c add definition of instruction stop table; add comments!
e
s 00054/00000/00000
d D 1.1 84/08/18 17:35:34 mckusick 1 0
c date and time created 84/08/18 17:35:34 by mckusick
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1984 Regents of the University of California */

/* %W%	(Berkeley)	%G%	*/
E 3
I 3
/*
D 7
 * Copyright (c) 1984 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1984, 1986 Regents of the University of California.
E 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3

/*
 * COMMENTCHAR is the character delimiting comments in the assembler.
 * LABELCHAR is the character that separates labels from instructions.
I 2
 * ARGSEPCHAR is the character that separates arguments in instructions.
E 2
 */
#define COMMENTCHAR	'#'
#define LABELCHAR	':'
I 2
#define ARGSEPCHAR	','
E 2

/*
 * Expansion parameters:
 *   QUEUESIZE is the number of instructions to be considered for 
 *	integration of argument pushes and pops
 *   MAXLINELEN is the longest expected input line
 *   MAXARGS is the maximum number of arguments in an assembly instruction
 */
#define QUEUESIZE	16
D 5
#define MAXLINELEN	128
E 5
I 5
#define MAXLINELEN	1024
E 5
#define MAXARGS		10

/*
 * The following global variables are used to manipulate the queue of
 * recently seen instructions.
 *	line - The queue of instructions.
 *	bufhead - Pointer to next availble queue slot. It is not
 *		considered part of te instruction stream until
 *		bufhead is advanced.
 *	buftail - Pointer to last instruction in queue.
 * Note that bufhead == buftail implies that the queue is empty.
 */
int bufhead, buftail;
char line[QUEUESIZE][MAXLINELEN];

#define SUCC(qindex) ((qindex) + 1 == QUEUESIZE ? 0 : (qindex) + 1)
#define PRED(qindex) ((qindex) - 1 < 0 ? QUEUESIZE - 1 : (qindex) - 1)

/*
D 2
 * The hash table should be twice as big as the number of patterns.
 * It must be a power of two.
E 2
I 2
 * Hash table headers should be twice as big as the number of patterns.
 * They must be a power of two.
E 2
 */
#define HSHSIZ	128

I 2
/*
 * These tables specify the substitutions that are to be done.
 */
E 2
struct pats {
I 4
	int	args;
E 4
	char	*name;
	char	*replace;
	struct	pats *next;
	int	size;
};
D 2
struct pats *hashhdr[HSHSIZ];
E 2
I 2
struct pats *patshdr[HSHSIZ];
E 2
extern struct pats language_ptab[], libc_ptab[], machine_ptab[];
I 6
extern struct pats vax_libc_ptab[], vaxsubset_libc_ptab[];
extern struct pats vax_ptab[], vaxsubset_ptab[];
E 6
D 2
struct pats **hash();
E 2
I 2

/*
 * This table defines the set of instructions that demark the
 * end of a basic block.
 */
struct inststoptbl {
	char	*name;
	struct	inststoptbl *next;
	int	size;
};
struct inststoptbl *inststoptblhdr[HSHSIZ];
extern struct inststoptbl inststoptable[];

/*
 * Miscellaneous functions.
 */
E 2
char *newline(), *copyline(), *doreplaceon();
E 1
