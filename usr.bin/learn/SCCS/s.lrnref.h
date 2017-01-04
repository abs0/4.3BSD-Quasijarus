h33104
s 00001/00001/00052
d D 4.4 86/05/15 17:58:28 bloom 4 3
c updates from John Kunze
e
s 00002/00000/00051
d D 4.3 83/08/11 20:42:28 sam 3 2
c standardize sccs keyword lines
e
s 00007/00004/00044
d D 4.2 83/04/25 23:58:54 mckusick 2 1
c 
e
s 00048/00000/00000
d D 4.1 83/02/24 12:55:54 mckusick 1 0
c date and time created 83/02/24 12:55:54 by mckusick
e
u
U
t
T
I 3
/*	%M%	%I%	%E%	*/

E 3
I 1
D 2
/*	%W%	(Berkeley)	%E%	*/

E 2
#define	READY	0
#define	PRINT	1
#define	COPYIN	2
#define	COPYOUT	3
#define	UNCOPIN	4
#define	UNCOPOUT	5
#define	PIPE	6
#define	UNPIPE	7
#define	YES	8
#define	NO	9
#define	SUCCEED	10
#define	FAIL	11
#define	BYE	12
#define	LOG	13
#define	CHDIR	14
#define	LEARN	15
#define	MV	16
#define	USER	17
#define	NEXT	18
#define	SKIP	19
#define	WHERE	20
#define	MATCH	21
#define	NOP	22
#define	BAD	23
#define	CREATE	24
#define	CMP	25
D 2
#define	GOTO	26
#define	ONCE	27
E 2
I 2
#define	ONCE	26
#define	AGAIN	27
D 4
#define XYZZY	28
E 4
I 4
#define	HINT	28
E 4
E 2

extern	int	more;
extern	char	*level;
extern	int	speed;
extern	char	*sname;
extern	char	*direct;
extern	char	*todo;
extern	int	didok;
extern	int	sequence;
extern	int	comfile;
extern	int	status;
extern	int	wrong;
extern	char	*pwline;
extern	char	*dir;
extern	FILE	*incopy;
extern	FILE	*scrin;
extern	int	logging;
extern	int	ask;
I 2
extern 	int	again;
extern	int	skip;
extern	int	teed;
extern	int	total;
E 2
E 1
