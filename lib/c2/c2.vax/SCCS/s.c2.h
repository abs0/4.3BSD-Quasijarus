h14246
s 00003/00001/00207
d D 4.12 00/08/31 22:43:06 msokolov 12 11
c break up into routines on .word's (procedure entry points) instead of .globl's
c so that it doesn't depend on whether functions are static or not
e
s 00002/00004/00206
d D 4.11 00/08/29 20:42:51 msokolov 11 10
c remove JCC and JCS, they are aliases for JHIS and JLO respectively
e
s 00012/00004/00198
d D 4.10 85/08/22 18:45:19 mckusick 10 9
c update from donn@utah-cs
e
s 00019/00008/00183
d D 4.9 85/03/19 10:54:10 ralph 9 8
c lint changes from donn@utah-cs.
e
s 00005/00000/00186
d D 4.8 85/01/16 11:42:06 ralph 8 7
c changes to merge f2 and c2. Added -f flag to act as f2.
e
s 00002/00002/00184
d D 4.7 83/08/11 23:20:59 sam 7 6
c standardize sccs keyword lines
e
s 00008/00008/00178
d D 4.6 82/05/27 12:42:31 rrh 6 5
c Resort to the original type enumeration order, putting the three
c new data types at the end of the original ordering.  This makes c2 work again
c let's hear it for consistent use of magic numbers and clear coding style.
e
s 00022/00007/00164
d D 4.5 82/02/14 16:01:30 root 5 4
c (by rrh) Added three extra data types: GFLOAT, HFLOAT and OCTA
c Allowed c2 to optimize instructions manipulating G and H format instructions
c just as it can now optimize F and D format instructions.
c c22.c now is mostly empty; data for c2 is now stored in as/instrs, to
c minimize the duplication that existed formerly.
c New data types have ordinal assignments after existing ones;
c because of the flakiness of c2, it is not clear what this may break.
e
s 00001/00001/00170
d D 4.4 81/03/02 17:53:42 toy 4 3
c Changed ASIZE to 128
e
s 00005/00003/00166
d D 4.3 81/03/02 12:39:48 toy 3 2
c Changed constant 20 to C2_ASIZE (64)
e
s 00004/00004/00165
d D 4.2 80/10/18 01:13:53 bill 2 1
c minimize stupid differences
e
s 00169/00000/00000
d D 4.1 80/10/17 01:46:17 bill 1 0
c date and time created 80/10/17 01:46:17 by bill
e
u
U
t
T
I 1
D 7
/*static	char sccsid[] = "%Z%%M% %I% %G%";*/
D 2
/* @(#)c2.h 1.18 80/03/14 10:27:01 */
E 2
I 2
/* @(#)c2.h 1.19 80/08/26 13:39:07 */
E 7
I 7
/*	%M%	%I%	%E%	*/

E 7
E 2
/*
 * Header for object code improver
 */

#define	JBR	1
#define	CBR	2
#define	JMP	3
#define	LABEL	4
#define	DLABEL	5
D 12
#define	EROU	7
E 12
I 12
#define	GLOBL	7
E 12
#define	JSW	9
#define	MOV	10
#define	CLR	11
#define	INC	12
#define	DEC	13
#define	TST	14
#define	PUSH	15
#define CVT 16
#define	CMP	17
#define	ADD	18
#define	SUB	19
#define	BIT	20
#define	BIC	21
#define	BIS	22
#define	XOR	23
#define	COM	24
#define	NEG	25
#define	MUL	26
#define	DIV	27
#define	ASH	28
#define EXTV	29
#define EXTZV	30
#define INSV	31
#define	CALLS	32
#define RET	33
#define	CASE	34
#define	SOB	35
#define	TEXT	36
#define	DATA	37
#define	BSS	38
#define	ALIGN	39
#define	END	40
#define MOVZ 41
#define WGEN 42
#define SOBGEQ 43
#define SOBGTR 44
#define AOBLEQ 45
#define AOBLSS 46
#define ACB 47
#define MOVA 48
#define PUSHA 49
#define LGEN 50
#define SET 51
#define MOVC3 52
#define RSB 53
#define JSB 54
#define MFPR 55
#define MTPR 56
#define PROBER 57
#define PROBEW 58
D 2
#define	COMM 59
#define LCOMM 60
E 2
I 2
#define	LCOMM 59
#define	COMM 60
I 12

#define	EROU	WGEN
E 12
E 2

#define	JEQ	0
#define	JNE	1
#define	JLE	2
#define	JGE	3
#define	JLT	4
#define	JGT	5
/* rearranged for unsigned branches so that jxxu = jxx + 6 */
#define	JLOS	8
#define	JHIS	9
#define	JLO	10
#define	JHI	11

#define JBC 12
#define JBS 13
#define JLBC 14
#define JLBS 15
#define JBCC 16
#define JBSC 17
#define JBCS 18
#define JBSS 19

I 8
D 11
#define	JCC 20
#define	JCS 21
#define	JVC 22
#define	JVS 23
E 11
I 11
#define	JVC 20
#define	JVS 21
E 11

E 8
I 5
/*
 *	When the new opcodes were added, the relative
 *	ordering of the first 3 (those that are not float)
 *	had to be retained, so that other parts of the program
 *	were not broken.
 *
 *	In addition, the distance between OP3 and OP2 must be preserved.
 *	The order of definitions above OP2 must not be changed.
 *
 *	Note that these definitions DO NOT correspond to
 *	those definitions used in as, adb and sdb.
 */
E 5
#define	BYTE	1
#define	WORD	2
#define LONG	3
D 5
#define	FLOAT	4
#define	DOUBLE	5
#define QUAD	6
#define OP2	7
#define OP3	8
#define OPB 9
#define OPX 10
E 5
I 5
#define	FFLOAT	4
#define	DFLOAT	5
D 6
#define	GFLOAT	6
#define	HFLOAT	7
#define QUAD	8
#define OCTA	9
#define OP2	10
#define OP3	11
#define OPB	12
#define OPX	13
E 6
I 6
#define QUAD	6
#define OP2	7
#define OP3	8
#define OPB	9
#define OPX	10
#define	GFLOAT	11
#define	HFLOAT	12
#define OCTA	13
E 6
E 5

#define T(a,b) (a|((b)<<8))
#define U(a,b) (a|((b)<<4))

I 3
D 4
#define C2_ASIZE 64
E 4
I 4
#define C2_ASIZE 128
E 4

E 3
struct optab {
	char	opstring[7];
	short	opcode;
} optab[];

struct node {
D 9
	char	op;
	char	subop;
E 9
I 9
	union {
		struct {
			char op_op;
			char op_subop;
		} un_op;
		short	un_combop;
	} op_un;
E 9
	short	refc;
	struct	node	*forw;
	struct	node	*back;
	struct	node	*ref;
	char	*code;
	struct	optab	*pop;
D 2
	int	labno;
E 2
I 2
	long	labno;
E 2
	short	seq;
};

D 9
struct {
	short	combop;
};
E 9
I 9
#define op op_un.un_op.op_op
#define subop op_un.un_op.op_subop
#define combop op_un.un_combop
E 9

char	line[512];
struct	node	first;
char	*curlp;
int	nbrbr;
int	nsaddr;
int	redunm;
int	iaftbr;
int	njp1;
int	nrlab;
int	nxjump;
int	ncmot;
int	nrevbr;
int	loopiv;
int	nredunj;
int	nskip;
int	ncomj;
int	nsob;
int	nrtst;
int nbj;
int nfield;

int	nchange;
D 9
int	isn;
E 9
I 9
long	isn;
E 9
int	debug;
D 10
char	*lasta;
char	*lastr;
char	*firstr;
E 10
char	revbr[];
#define	NREG	12
char	*regs[NREG+5]; /* 0-11, 4 for operands, 1 for running off end */
D 3
char	conloc[20];
char	conval[20];
char	ccloc[20];
E 3
I 3
char	conloc[C2_ASIZE];
char	conval[C2_ASIZE];
char	ccloc[C2_ASIZE];
E 3

#define	RT1	12
#define	RT2	13
#define RT3 14
#define RT4 15
#define	LABHS	127

D 9
struct { char lbyte; };

E 9
char *copy();
long getnum();
struct node *codemove();
struct node *insertl();
struct node *nonlab();
I 9
D 10
struct node *alloc();
E 10

#ifdef notdef
#define decref(p) \
	((p) && --(p)->refc <= 0 ? nrlab++, delnode(p) : 0)
#define delnode(p) \
	((p)->back->forw = (p)->forw, (p)->forw->back = (p)->back)
#endif notdef
I 10

char *xalloc();
extern char *newa;
extern char *lasta;
extern char *lastr;
#define	XALIGN(n) \
		(((n)+(sizeof (char *) - 1)) & ~(sizeof (char *) - 1))
#define	alloc(n) \
		((struct node *) \
		 ((newa = lasta) + (n) > lastr ? \
			xalloc(n) : \
			(lasta += XALIGN(n), newa)))
E 10
E 9
E 1
