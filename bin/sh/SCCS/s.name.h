h31137
s 00027/00000/00000
d D 4.1 82/05/07 19:38:37 mckusick 1 0
c date and time created 82/05/07 19:38:37 by mckusick
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


#define N_RDONLY 0100000
#define N_EXPORT 0040000
#define N_ENVNAM 0020000
#define N_ENVPOS 0007777

#define N_DEFAULT 0

struct namnod {
	NAMPTR	namlft;
	NAMPTR	namrgt;
	STRING	namid;
	STRING	namval;
	STRING	namenv;
	INT	namflg;
};
E 1
