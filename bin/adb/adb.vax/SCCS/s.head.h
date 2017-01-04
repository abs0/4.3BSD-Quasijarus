h37063
s 00032/00000/00000
d D 4.1 81/05/14 15:23:08 root 1 0
c date and time created 81/05/14 15:23:08 by root
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

ADDR	maxoff;
ADDR	localval;

struct	nlist *symtab, *esymtab;
struct	nlist *cursym;
struct	nlist *lookup();

struct	exec filhdr;

long	var[36];

int	xargc;

MAP	txtmap;
MAP	datmap;
INT	wtflag;
INT	fcor;
INT	fsym;
L_INT	maxfile;
L_INT	maxstor;
INT	signo;

union {
	struct	user U;
	char	UU[ctob(UPAGES)];
} udot;
#define	u	udot.U

char	*corfil, *symfil;

E 1
