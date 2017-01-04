h51983
s 00007/00001/00125
d D 5.1 85/06/05 16:31:43 dist 7 6
c Add copyright
e
s 00002/00003/00124
d D 1.6 83/07/26 10:01:34 peter 6 5
c using checksums for include files and flag days for source files.
e
s 00001/00000/00126
d D 1.5 82/07/29 19:16:45 peter 5 4
c protect against conflicts with library routines and data.
e
s 00003/00001/00123
d D 1.4 82/07/29 17:05:18 peter 4 3
c add -w flag to suppress warning messages; reclassify some 
c warnings as errors.
e
s 00002/00002/00122
d D 1.3 80/09/04 23:12:23 peter 3 2
c N_PC stabs with subtypes
e
s 00016/00004/00108
d D 1.2 80/09/02 15:24:34 peter 2 1
c formatting polish
e
s 00112/00000/00000
d D 1.1 80/08/31 17:20:10 peter 1 0
c date and time created 80/08/31 17:20:10 by peter
e
u
U
t
T
I 1
D 7
    /* Copyright (c) 1980 Regents of the University of California */
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7

    /*	static	char sccsid[] = "%Z%%M% %I% %G%"; */

    /*
     *	a symbol table entry.
     */
struct symbol {
    char		*name;			/* pointer to string table */
D 3
    unsigned char	type;			/* symbol type */
E 3
I 3
    short		desc;			/* symbol description */
E 3
    int			lookup;			/* whether new or old */
I 6
    struct symbol	*fromp;			/* its defining .p file */
E 6
    union {					/* either */
	struct {				/*   for a symbol, */
D 6
	    struct symbol	*fromp;		/*     its defining .p file */
E 6
	    struct symbol	*fromi;		/*     its defining .i file */
	    long		iline;		/*     the .i file line */
	    struct symbol	*rfilep;	/*     its resolving file */
	    long		rline;		/*     resolving file line */
D 3
	}			sym_str;
E 3
I 3
	}		sym_str;
E 3
D 6
	time_t		modtime;		/*   for a file, its st_mtime */
E 6
I 6
	long		checksum;		/*   for a file, its checksum */
E 6
    }			sym_un;
};

D 2
#define	NIL	0

E 2
I 2
    /*
     *	struct for an argument .o file.
     */
E 2
struct fileinfo {
    FILE		*file;
    char		*name;
D 6
    time_t		modtime;
E 6
    off_t		nextoffset;
};

I 2
    /*
     *	old archive magic for error detection.
     */
E 2
#define	OARMAG	0177545

    /*
     *	this is used to trim pointers into the range of a mod of a prime.
     */
#define	SHORT_ABS( n )	( n & 077777 )

    /*
D 2
     *	a prime number which rounds a struct symboltableinfo up to ~BUFSIZ
E 2
I 2
     *	a prime number which gets sizeof( struct symboltableinfo )
     *	up to a multiple of BUFSIZ.
E 2
     */
#define	SYMBOLPRIME	1021
I 2

E 2
    /*
     *	number of entries used in this symbol table,
     *	a chain to the next symbol table,
     *	and the entries. (pointers to struct symbols.)
     */
struct symboltableinfo {
    long			used;
    struct symboltableinfo	*chain;
    struct symbol		*entry[ SYMBOLPRIME ];
};

    /*
     *	if new struct symbols are needed,
     *	allocate this much space and hack it up into struct symbols.
     */
#define	SYMBOLALLOC	BUFSIZ

    /*
D 2
     *	a prime number which rounds a struct stringtableinfo up to ~BUFSIZ
E 2
I 2
     *	a prime number which gets sizeof( struct stringtableinfo )
     *	up to a multiple of BUFSIZ.
E 2
     */
#define	STRINGPRIME	1021

    /*
     *	number of entries used in this string table,
     *	a chain to the next string table,
     *	and the entries. (pointers to the character table.)
     */
struct stringtableinfo {
    long			used;
    struct stringtableinfo	*chain;
    char			*entry[ STRINGPRIME ];
};

    /*
     *	if more character table space is needed,
     *	allocate this much and hack it up into strings.
     */
#define	CHARALLOC	BUFSIZ
I 2

    /*
     *	uninitialized pointer
     */
#define	NIL	0
E 2

    /*
     *	an enumeration for error types
     */
D 4
#define	FATAL	0
E 4
I 4
#define	NONE	0
E 4
#define	WARNING	1
I 4
#define ERROR	2
#define	FATAL	3
E 4

    /*
     *	an enumeration for lookups
     */
#define	NEW	0
#define	OLD	1

    /*
     *	booleans
     */
#define	BOOL	int
#define	FALSE	0
#define	TRUE	1

    /*
     *	function types.
     */
struct symbol	*entersymbol();
struct symbol	*symbolalloc();
long		stringhash();
char		*enterstring();
char		*charalloc();
BOOL		nextelement();
time_t		mtime();
char		*classify();
I 5
char		*article();
E 5
E 1
