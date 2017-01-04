h36814
s 00032/00000/00000
d D 1.1 86/02/25 16:04:39 sam 1 0
c date and time created 86/02/25 16:04:39 by sam
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
