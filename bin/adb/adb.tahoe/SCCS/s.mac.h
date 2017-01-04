h50912
s 00043/00000/00000
d D 1.1 86/02/25 16:04:40 sam 1 0
c date and time created 86/02/25 16:04:40 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

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
#define DONE	);
#define LOOP	for(;;){
#define POOL	}

#define ANDF	&&
#define ORF	||

#define TRUE	 (-1)
#define FALSE	0
#define LOBYTE	0377
#define STRIP	0177

#define SP	' '
#define TB	'\t'
#define EOR	'\n'

#define	eqstr(a,b)	(strcmp(a,b)==0)
E 1
