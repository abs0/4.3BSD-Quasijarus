h27246
s 00001/00001/00036
d D 4.7 05/04/19 13:38:07 msokolov 7 6
c bump DIMTABSZ to 8400
e
s 00001/00001/00036
d D 4.6 00/12/22 19:42:06 msokolov 6 5
c bump TREESZ to 2000, people started bumping into the limit...
e
s 00001/00001/00036
d D 4.5 00/04/13 22:51:48 msokolov 5 4
c bump SYMTSZ to 6000, people started bumping into the limit...
e
s 00001/00001/00036
d D 4.4 00/04/10 19:11:43 msokolov 4 3
c bump PARAMSZ to 600, it was limiting some huge enums...
e
s 00001/00000/00036
d D 4.3 85/08/22 19:03:53 mckusick 3 2
c update from donn@utah-cs
e
s 00003/00003/00033
d D 4.2 85/04/08 11:47:16 ralph 2 1
c move ONEPASS definition so lint will compile.
e
s 00036/00000/00000
d D 4.1 85/03/19 13:01:22 ralph 1 0
c date and time created 85/03/19 13:01:22 by ralph
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#ifndef _CONFIG_
#define	_CONFIG_
/*
 * Compiler configuration definitions.
 */

/*
 * These flags control global compiler operation.
 */
D 2
#ifndef FORT
#define	ONEPASS		1		/* one-pass compiler */
#endif
E 2
#define	BUFSTDERR	1		/* buffer output to stderr */
#define STDPRTREE	1		/* means include prtree */
#define NESTCALLS	1		/* disallow two concurrent store()'s */
#define	FLEXNAMES	1		/* arbitrary length identifiers */
I 2
#ifdef FORT
#define	NOMAIN		1		/* use f1 main routine */
#endif
E 2

/*
 * Table sizes.
 */
D 6
#define TREESZ		1000		/* parse tree table size */
E 6
I 6
#define TREESZ		2000		/* parse tree table size */
E 6
#define BCSZ		100		/* break/continue table size */
D 5
#define SYMTSZ		3000		/* symbol table size */
E 5
I 5
#define SYMTSZ		6000		/* symbol table size */
E 5
D 7
#define DIMTABSZ 	4200		/* dimension/size table size */
E 7
I 7
#define DIMTABSZ 	8400		/* dimension/size table size */
E 7
D 4
#define PARAMSZ		300		/* parameter stack size */
E 4
I 4
#define PARAMSZ		600		/* parameter stack size */
E 4
#define SWITSZ		500		/* switch table size */
#define	DELAYS		20		/* delayed evaluation table size */
#define NRECUR		(10*TREESZ)	/* maximum eval recursion depth */
I 3
#define	MAXSCOPES	(SYMTSZ/30)	/* maximum active scopes */
E 3

/* in case anyone still uses fixed length names */
#ifndef FLEXNAMES
#define	NCHNAM		8		/* significant chars of identifier */
#endif
#endif
E 1
