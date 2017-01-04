h27425
s 00001/00000/00049
d D 4.3 82/12/24 18:12:28 sam 3 2
c psl.h moved; remove name conflict
e
s 00000/00000/00049
d D 4.2 82/08/17 13:26:34 rrh 2 1
c Changed the data types for the sdb class characters to be unsigned
c characters; this fixed a bug that prevented the arguments to a function
c from being printed symbolically.  The fix was done globally; it is not
c known if the "fix" fixed other bugs
e
s 00049/00000/00000
d D 4.1 80/10/09 23:57:24 bill 1 0
c date and time created 80/10/09 23:57:24 by bill
e
u
U
t
T
I 1
/* "%Z%%M% %I% %G%" */
#
/*
 *	UNIX debugger
 */

#define TYPE	typedef
#define STRUCT	struct
#define UNION	union
#define REG	register

#define BEGIN	{
#define END	}

#define IF	if(
#define THEN	){
#define ELSE	} else {
#define ELIF	} else if (
#define FI	}

#define FOR	for(
#define WHILE	while(
#define DO	){
#define OD	}
#define REP	do{
#define PER	}while(
I 3
#undef DONE
E 3
#define DONE	);
#define LOOP	for(;;){
#define POOL	}

#define SKIP	;
#define DIV	/
#define REM	%
#define NEQ	^
#define ANDF	&&
#define ORF	||

#define TRUE	 (-1)
#define FALSE	0
#define LOBYTE	0377
#define HIBYTE	0177400
#define STRIP	0177
#define HEXMSK	017

#define SP	' '
#define TB	'\t'
#define NL	'\n'

#define SCCSID(arg) static char Sccsid[] = "arg"
E 1
