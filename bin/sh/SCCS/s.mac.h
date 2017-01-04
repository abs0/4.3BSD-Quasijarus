h22605
s 00000/00002/00061
d D 4.3 87/10/26 07:31:55 bostic 3 2
c MAX not used; redefined in param.h anyway
e
s 00001/00000/00062
d D 4.2 82/12/24 18:44:24 sam 2 1
c cleanup redefinition from ttydev.h
e
s 00062/00000/00000
d D 4.1 82/05/07 19:37:52 mckusick 1 0
c date and time created 82/05/07 19:37:52 by mckusick
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#
/*
 *	UNIX shell
 *
 *	S. R. Bourne
 *	Bell Telephone Laboratories
 *
 */

#define LOCAL	static
#define PROC	extern
#define TYPE	typedef
#define STRUCT	TYPE struct
#define UNION	TYPE union
#define REG	register

#define IF	if(
#define THEN	){
#define ELSE	} else {
#define ELIF	} else if (
#define FI	;}

#define BEGIN	{
#define END	}
#define SWITCH	switch(
#define IN	){
#define ENDSW	}
#define FOR	for(
#define WHILE	while(
#define DO	){
#define OD	;}
#define REP	do{
#define PER	}while(
I 2
#undef DONE
E 2
#define DONE	);
#define LOOP	for(;;){
#define POOL	}


#define SKIP	;
#define DIV	/
#define REM	%
#define NEQ	^
#define ANDF	&&
#define ORF	||

#define TRUE	(-1)
#define FALSE	0
#define LOBYTE	0377
#define STRIP	0177
#define QUOTE	0200

#define EOF	0
#define NL	'\n'
#define SP	' '
#define LQ	'`'
#define RQ	'\''
#define MINUS	'-'
#define COLON	':'
D 3

#define MAX(a,b)	((a)>(b)?(a):(b))
E 3
E 1
