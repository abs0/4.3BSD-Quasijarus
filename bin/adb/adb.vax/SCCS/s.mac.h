h63953
s 00000/00001/00047
d D 4.2 85/09/09 10:57:41 bloom 2 1
c EOF unused and causes redefinition in stdio.h
e
s 00048/00000/00000
d D 4.1 81/05/14 15:23:09 root 1 0
c date and time created 81/05/14 15:23:09 by root
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
D 2
#define EOF	0
E 2
E 1
