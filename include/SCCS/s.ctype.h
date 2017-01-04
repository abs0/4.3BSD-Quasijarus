h18533
s 00001/00001/00027
d R 4.3 87/04/11 16:24:21 bostic 3 2
c bug report 4.2BSD/lib/25
e
s 00003/00001/00025
d D 4.2 85/09/04 16:08:36 bloom 2 1
c isprint(space) shoudl be true and add isgraph
e
s 00026/00000/00000
d D 4.1 83/05/03 13:47:55 sam 1 0
c date and time created 83/05/03 13:47:55 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#define	_U	01
#define	_L	02
#define	_N	04
#define	_S	010
#define _P	020
#define _C	040
#define _X	0100
I 2
#define	_B	0200
E 2

extern	char	_ctype_[];

#define	isalpha(c)	((_ctype_+1)[c]&(_U|_L))
#define	isupper(c)	((_ctype_+1)[c]&_U)
#define	islower(c)	((_ctype_+1)[c]&_L)
#define	isdigit(c)	((_ctype_+1)[c]&_N)
#define	isxdigit(c)	((_ctype_+1)[c]&(_N|_X))
#define	isspace(c)	((_ctype_+1)[c]&_S)
#define ispunct(c)	((_ctype_+1)[c]&_P)
#define isalnum(c)	((_ctype_+1)[c]&(_U|_L|_N))
D 2
#define isprint(c)	((_ctype_+1)[c]&(_P|_U|_L|_N))
E 2
I 2
#define isprint(c)	((_ctype_+1)[c]&(_P|_U|_L|_N|_B))
#define isgraph(c)	((_ctype_+1)[c]&(_P|_U|_L|_N))
E 2
#define iscntrl(c)	((_ctype_+1)[c]&_C)
#define isascii(c)	((unsigned)(c)<=0177)
#define toupper(c)	((c)-'a'+'A')
#define tolower(c)	((c)-'A'+'a')
#define toascii(c)	((c)&0177)
E 1
