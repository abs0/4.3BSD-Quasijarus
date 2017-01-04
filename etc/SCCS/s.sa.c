h34295
s 00001/00001/01150
d D 4.10 87/10/22 10:45:12 bostic 11 10
c ANSI C; sprintf now returns an int.
e
s 00058/00019/01093
d D 4.9 84/12/12 09:23:56 karels 10 9
c from lepreau: use AHZ, some units fixes, and allow alternate acct. file
e
s 00002/00002/01110
d D 4.8 84/07/18 19:49:15 sam 9 8
c random corrections from kre
e
s 00001/00001/01111
d D 4.7 84/07/15 13:24:29 sam 8 7
c io figures returned multipled by 64
e
s 00026/00022/01086
d D 4.6 84/07/14 14:47:08 sam 7 6
c track changes to kernel: times now returned in 64ths of a second, 
c average memory use now in software page size units
e
s 00001/00001/01107
d D 4.5 83/10/14 21:57:16 sam 6 4
c correct -u printout
e
s 00007/00007/01101
d R 4.5 83/10/07 00:07:55 sam 5 4
c correct belief that accounting time is in 60 hz clock ticks
e
s 00001/00001/01107
d D 4.4 83/08/11 13:44:56 mckusick 4 3
c say what you mean... kre
e
s 00078/00071/01030
d D 4.3 83/04/04 21:46:23 sam 3 2
c reformat and insure acct times are interpreted as seconds 
c instead of clock ticks (60ths)
e
s 00629/00179/00472
d D 4.2 81/02/28 22:00:25 wnj 2 1
c henryized
e
s 00651/00000/00000
d D 4.1 80/10/01 17:28:19 bill 1 0
c date and time created 80/10/01 17:28:19 by bill
e
u
U
t
T
I 3
#ifndef lint
E 3
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
D 10
static	char *sccsid = "%W% (Berkeley) %E%";
E 10
I 10
static char *sccsid = "%W% (Berkeley) %G%";
E 10
I 3
#endif
E 3

/*
 *	Extensive modifications to internal data structures
 *	to allow arbitrary number of different commands and users added.
 *	
 *	Also allowed the digit option on the -v flag (interactive
 *	threshold compress) to be a digit string, so one can
 *	set the threshold > 9.
 *
 *	Also added the -f flag, to force no interactive threshold
 *	compression with the -v flag.
 *
 *	Robert Henry
 *	UC Berkeley
 *	31jan81
 */
E 2
#include <stdio.h>
I 7
#include <ctype.h>
E 7
#include <sys/types.h>
#include <sys/acct.h>
#include <signal.h>
I 2
#include <utmp.h>
#include <pwd.h>
E 2

/* interpret command time accounting */

D 2
#define	size 	2500
E 2
#define	NC	sizeof(acctbuf.ac_comm)
I 2

E 2
struct acct acctbuf;
int	lflg;
int	cflg;
int	Dflg;
int	dflg;
int	iflg;
int	jflg;
int	Kflg;
int	kflg;
int	nflg;
int	aflg;
int	rflg;
int	oflg;
int	tflg;
int	vflg;
I 2
int	fflg;
E 2
int	uflg;
D 2
int	thres	= 1;
E 2
I 2
int	thres;
E 2
int	sflg;
int	bflg;
int	mflg;

I 2
struct	utmp	utmp;
#define	NAMELG	(sizeof(utmp.ut_name)+1)

struct 	Olduser{
	int	Us_cnt;
	double	Us_ctime;
	double	Us_io;
	double	Us_imem;
};
	
E 2
struct	user {
D 2
	int	us_cnt;
	double	us_ctime;
	double	us_io;
	double	us_imem;
} user[1000];
E 2
I 2
	char	name[NC];		/* this is <\001><user id><\000> */
	struct	Olduser	oldu;
	char	us_name[NAMELG];
};
#define	us_cnt		oldu.Us_cnt
#define	us_ctime	oldu.Us_ctime
#define	us_io		oldu.Us_io
#define	us_imem		oldu.Us_imem
E 2

D 2
struct	tab {
E 2
I 2
/*
 *	We protect ourselves from preposterous user id's by looking
 *	through the passwd file for the highest uid allocated, and
 *	then adding 10 to that.
 *	This prevents the user structure from growing too large.
 */
#define	USERSLOP	10
int	maxuser;		/* highest uid from /etc/passwd, + 10 for slop*/

struct	process {
E 2
	char	name[NC];
	int	count;
	double	realt;
	double	cput;
	double	syst;
	double	imem;
	double	io;
D 2
} tab[size];
E 2
I 2
};
E 2

I 2
union	Tab{
	struct	process	p;
	struct	user	u;
};

typedef	union Tab cell;

int	(*cmp)();	/* compares 2 cells; set to appropriate func */
cell	*enter();
struct	user *finduser();
struct	user *wasuser();

/*
 *	Table elements are keyed by the name of the file exec'ed.
 *	Because on large systems, many files can be exec'ed,
 *	a static table size may grow to be too large.
 *
 *	Table elements are allocated in chunks dynamically, linked
 *	together so that they may be retrieved sequentially.
 *
 *	An index into the table structure is provided by hashing through
 *	a seperate hash table.
 *	The hash table is segmented, and dynamically extendable.
 *	Realize that the hash table and accounting information is kept
 *	in different segments!
 *
 *	We have a linked list of hash table segments; within each
 *	segment we use a quadratic rehash that touches no more than 1/2
 *	of the buckets in the hash table when probing.
 *	If the probe does not find the desired symbol, it moves to the
 *	next segment, or allocates a new segment.
 *
 *	Hash table segments are kept on the linked list with the first
 *	segment always first (that will probably contain the
 *	most frequently executed commands) and
 *	the last added segment immediately after the first segment,
 *	to hopefully gain something by locality of reference.
 *
 *	We store the per user information in the same structure as
 *	the per exec'ed file information.  This allows us to use the
 *	same managers for both, as the number of user id's may be very
 *	large.
 *	User information is keyed by the first character in the name
 *	being a '\001', followed by four bytes of (long extended)
 *	user id number, followed by a null byte.
 *	The actual user names are kept in a seperate field of the
 *	user structure, and is filled in upon demand later.
 *	Iteration through all users by low user id to high user id
 *	is done by just probing the table, which is gross.
 */
#define	USERKEY	'\001'
#define	ISPROCESS(tp)	(tp->p.name[0] && (tp->p.name[0] != USERKEY))
#define	ISUSER(tp)	(tp->p.name[0] && (tp->p.name[0] == USERKEY))

#define	TABDALLOP	500
struct 	allocbox{
	struct	allocbox	*nextalloc;
	cell			tabslots[TABDALLOP];
};

struct	allocbox	*allochead;	/*head of chunk list*/
struct	allocbox	*alloctail;	/*tail*/
struct	allocbox	*newbox;	/*for creating a new chunk*/
cell			*nexttab;	/*next table element that is free*/
int			tabsleft;	/*slots left in current chunk*/
int			ntabs;
/*
 *	Iterate through all symbols in the symbol table in declaration
 *	order.
 *	struct	allocbox	*allocwalk;
 *	cell			*sp, *ub;
 *
 *	sp points to the desired item, allocwalk and ub are there
 *	to make the iteration go.
 */

#define DECLITERATE(allocwalk, walkpointer, ubpointer) \
	for(allocwalk = allochead; \
	    allocwalk != 0; \
	    allocwalk = allocwalk->nextalloc) \
		for (walkpointer = &allocwalk->tabslots[0],\
		        ubpointer = &allocwalk->tabslots[TABDALLOP], \
		        ubpointer = ubpointer > ( (cell *)alloctail) \
				 ? nexttab : ubpointer ;\
		     walkpointer < ubpointer; \
		     walkpointer++ )

#define TABCHUNKS(allocwalk, tabptr, size) \
	for (allocwalk = allochead; \
	    allocwalk != 0; \
	    allocwalk = allocwalk->nextalloc) \
	    if ( \
		(tabptr = &allocwalk->tabslots[0]), \
		(size = \
		 (   (&allocwalk->tabslots[TABDALLOP]) \
		   > ((cell *)alloctail) \
		 ) \
		   ? (nexttab - tabptr) : TABDALLOP \
		), \
		1 \
	    )
#define	PROCESSITERATE(allocwalk, walkpointer, ubpointer) \
	DECLITERATE(allocwalk, walkpointer, ubpointer) \
	if (ISPROCESS(walkpointer))

#define	USERITERATE(allocwalk, walkpointer, ubpointer) \
	DECLITERATE(allocwalk, walkpointer, ubpointer) \
	if (ISUSER(walkpointer))
/*
 *	When we have to sort the segmented accounting table, we
 *	create a vector of sorted queues that is merged
 *	to sort the entire accounting table.
 */
struct chunkdesc   {
	cell	*chunk_tp;
	int	chunk_n;
};

/*
 *	Hash table segments and manager
 */
#define	NHASH	1103
struct hashdallop {
	int	h_nused;
	struct	hashdallop	*h_next;
	cell		*h_tab[NHASH];
};
struct	hashdallop	*htab;	/* head of the list */
int	htabinstall;		/* install the symbol */

E 2
double	treal;
double	tcpu;
double	tsys;
double	tio;
double	timem;
D 2
int	junkp = -1;
E 2
I 2
cell	*junkp;
E 2
char	*sname;
double	ncom;
time_t	expand();
char	*getname();

I 2
/*
 *	usracct saves records of type Olduser.
 *	There is one record for every possible uid less than
 *	the largest uid seen in the previous usracct or in savacct.
 *	uid's that had no activity correspond to zero filled slots;
 *	thus one can index the file and get the user record out.
 *	It would be better to save only user information for users
 *	that the system knows about to save space, but that is not
 *	upward compatabile with the old system.
 *
 *	In the old version of sa, uid's greater than 999 were not handled
 *	properly; this system will do that.
 */

#ifdef	DEBUG
#define	USRACCT "./usracct"
#define	SAVACCT	"./savacct"
#define	ACCT	"./acct"
#else
#define	USRACCT "/usr/adm/usracct"
#define	SAVACCT	"/usr/adm/savacct"
#define	ACCT	"/usr/adm/acct"
#endif	DEBUG


I 10
char *usracct = USRACCT;
char *savacct = SAVACCT;

E 10
int	cellcmp();
cell	*junkp = 0;
/*
 *	The threshold is built up from digits in the argv ;
 *	eg, -v1s0u1
 *	will build a value of thres of 101.
 *
 *	If the threshold is zero after processing argv, it is set to 1
 */
int	thres = 0;	
int	htabinstall = 1;
int	maxuser = -1;
int	(*cmp)();

I 7
/* we assume pagesize is at least 1k */
int	pgdiv;
#define	pgtok(x)	((x) / pgdiv)

E 7
I 3
extern	tcmp(), ncmp(), bcmp(), dcmp(), Dcmp(), kcmp(), Kcmp();
extern	double sum();

E 3
E 2
main(argc, argv)
D 3
char **argv;
E 3
I 3
	char **argv;
E 3
{
	FILE *ff;
D 2
	int i, j, k;
	int (*cmp)();
	extern tcmp(), ncmp(), bcmp(), dcmp(), Dcmp(), kcmp(), Kcmp();
	extern double sum();
	double ft;
E 2
I 2
D 3
	int i, j;
	extern	tcmp(), ncmp(), bcmp(), dcmp(), Dcmp(), kcmp(), Kcmp();
	extern	double sum();
	double	ft;
	register	struct	allocbox	*allocwalk;
	register	cell	*tp, *ub;
	int	size;
	int	nchunks;
	struct	chunkdesc	*chunkvector;
	int	smallest;
E 3
I 3
	double ft;
	register struct	allocbox *allocwalk;
	register cell *tp, *ub;
	int i, j, size, nchunks, smallest;
	struct chunkdesc *chunkvector;
E 3
E 2

I 7
	pgdiv = getpagesize() / 1024;
	if (pgdiv == 0)
		pgdiv = 1;
E 7
I 2
	maxuser = USERSLOP + getmaxuid();

	tabinit();
E 2
	cmp = tcmp;
	if (argc>1)
	if (argv[1][0]=='-') {
		argv++;
		argc--;
		for(i=1; argv[0][i]; i++)
		switch(argv[0][i]) {

		case 'o':
			oflg++;
			break;

		case 'i':
			iflg++;
			break;

		case 'b':
			bflg++;
			cmp = bcmp;
			break;

		case 'l':
			lflg++;
			break;

		case 'c':
			cflg++;
			break;

		case 'd':
			dflg++;
			cmp = dcmp;
			break;

		case 'D':
			Dflg++;
			cmp = Dcmp;
			break;

		case 'j':
			jflg++;
			break;

		case 'k':
			kflg++;
			cmp = kcmp;
			break;

		case 'K':
			Kflg++;
			cmp = Kcmp;
			break;

		case 'n':
			nflg++;
			cmp = ncmp;
			break;

		case 'a':
			aflg++;
			break;

		case 'r':
			rflg++;
			break;

		case 't':
			tflg++;
			break;

		case 's':
			sflg++;
			aflg++;
			break;

		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
D 2
			thres = argv[0][i]-'0';
E 2
I 2
			thres = thres * 10 + (argv[0][i]-'0');
E 2
			break;

		case 'v':
			vflg++;
			break;

I 2
		case 'f':
			fflg++;	/* force v option; no tty interaction */
			break;

E 2
		case 'u':
			uflg++;
			break;

		case 'm':
			mflg++;
			break;
I 10

		case 'U':
		case 'S':
			if (i != 1 || argv[0][2]) {	/* gross! */
				fprintf(stderr, "-U and -S options must be separate\n");
				exit(1);
			}
			argc++, argv--;			/* backup - yuk */
			goto doUS;

		default:
		    	fprintf(stderr, "Invalid option %c\n", argv[0][1]);
			exit(1);
E 10
		}
	}
I 10

#define optfile(f) {if (argc < 2) \
			{ fprintf(stderr, "Missing filename\n"); exit(1); } \
			argc--, argv++; f = argv[0]; }

doUS:
	for (argc--, argv++; argc && argv[0][0] == '-'; argc--, argv++) {
		switch(argv[0][1]) {
		    case 'U':
		    	optfile(usracct);
			break;

		    case 'S':
		    	optfile(savacct);
			break;

		    default:
		    	fprintf(stderr, "Invalid option %c\n", argv[0][1]);
			exit(1);
		}
	}

E 10
I 2
	if (thres == 0)
		thres = 1;
E 2
	if (iflg==0)
		init();
D 10
	if (argc<2)
E 10
I 10
	if (argc<1)
E 10
D 2
		doacct("/usr/adm/acct");
E 2
I 2
		doacct(ACCT);
E 2
D 10
	else while (--argc)
		doacct(*++argv);
E 10
I 10
	else while (argc--)
		doacct(*argv++);
E 10
	if (uflg) {
		return;
	}

/*
 * cleanup pass
 * put junk together
 */

	if (vflg)
		strip();
	if(!aflg)
D 2
	for (i=0; i<size; i++)
	if (tab[i].name[0]) {
E 2
I 2
	PROCESSITERATE(allocwalk, tp, ub){
E 2
		for(j=0; j<NC; j++)
D 2
			if(tab[i].name[j] == '?')
E 2
I 2
			if(tp->p.name[j] == '?')
E 2
				goto yes;
D 2
		if(tab[i].count != 1)
E 2
I 2
		if(tp->p.count != 1)
E 2
			continue;
	yes:
D 2
		if(junkp == -1)
E 2
I 2
		if(junkp == 0)
E 2
			junkp = enter("***other");
D 2
		tab[junkp].count += tab[i].count;
		tab[junkp].realt += tab[i].realt;
		tab[junkp].cput += tab[i].cput;
		tab[junkp].syst += tab[i].syst;
		tab[junkp].imem += tab[i].imem;
		tab[junkp].io += tab[i].io;
		tab[i].name[0] = 0;
E 2
I 2
		junkp->p.count += tp->p.count;
		junkp->p.realt += tp->p.realt;
		junkp->p.cput += tp->p.cput;
		junkp->p.syst += tp->p.syst;
		junkp->p.imem += tp->p.imem;
		junkp->p.io += tp->p.io;
		tp->p.name[0] = 0;
E 2
	}
D 2
	for(i=k=0; i<size; i++)
	if(tab[i].name[0]) {
		tab[k] = tab[i];
		k++;
	}
E 2
	if (sflg) {
		signal(SIGINT, SIG_IGN);
D 2
		if ((ff = fopen("/usr/adm/usracct", "w")) != NULL) {
			fwrite((char *)user, sizeof(user), 1, ff);
			fclose(ff);
E 2
I 2
D 10
		if ((ff = fopen(USRACCT, "w")) != NULL) {
E 10
I 10
		if ((ff = fopen(usracct, "w")) != NULL) {
E 10
			static	struct	user ZeroUser = {0};
			struct 	user	*up;
			int	uid;
			/*
			 *	Write out just enough user slots,
			 *	filling with zero slots for users that
			 *	weren't found.
			 *	The file can be indexed directly by uid
			 *	to get the correct record.
			 */
			for (uid = 0; uid < maxuser; uid++){
				if ( (up = wasuser(uid)) != 0)
					fwrite((char *)&(up->oldu),
						sizeof(struct Olduser),1,ff);
				else
					fwrite((char *)&(ZeroUser.oldu),
						sizeof(struct Olduser),1,ff);
			}
E 2
		}
D 2
		if ((ff = fopen("/usr/adm/savacct", "w")) == NULL) {
E 2
I 2
D 10
		if ((ff = fopen(SAVACCT, "w")) == NULL) {
E 10
I 10
		if ((ff = fopen(savacct, "w")) == NULL) {
E 10
E 2
			printf("Can't save\n");
			exit(0);
		}
D 2
		fwrite((char *)tab, sizeof(tab[0]), k, ff);
E 2
I 2
		PROCESSITERATE(allocwalk, tp, ub)
			fwrite((char *)&(tp->p), sizeof(struct process), 1, ff);
E 2
		fclose(ff);
D 2
		creat("/usr/adm/acct", 0644);
E 2
I 2
		creat(sname, 0644);
E 2
		signal(SIGINT, SIG_DFL);
	}
/*
 * sort and print
 */
D 2

E 2
	if (mflg) {
		printmoney();
		exit(0);
	}
D 2
	qsort(tab, k, sizeof(tab[0]), cmp);
E 2
	column(ncom, treal, tcpu, tsys, timem, tio);
	printf("\n");
D 2
	for (i=0; i<k; i++)
	if (tab[i].name[0]) {
		ft = tab[i].count;
		column(ft, tab[i].realt, tab[i].cput, tab[i].syst, tab[i].imem, tab[i].io);
		printf("   %.14s\n", tab[i].name);
E 2
I 2

	/*
	 *	the fragmented table is sorted by sorting each fragment
	 *	and then merging.
	 */
	nchunks = 0;
	TABCHUNKS(allocwalk, tp, size){
		qsort(tp, size, sizeof(cell), cellcmp);
		nchunks ++;
E 2
	}
I 2
	chunkvector = (struct chunkdesc *)calloc(nchunks,
		sizeof(struct chunkdesc));
	nchunks = 0;
	TABCHUNKS(allocwalk, tp, size){
		chunkvector[nchunks].chunk_tp = tp;
		chunkvector[nchunks].chunk_n = size;
		nchunks++;
	}
	for(; nchunks; ){
		/*
		 *	Find the smallest element at the head of the queues.
		 */
		smallest = 0;
		for (i = 1; i < nchunks; i++){
			if (cellcmp(chunkvector[i].chunk_tp,
				chunkvector[smallest].chunk_tp) < 0)
					smallest = i;
		}
		tp = chunkvector[smallest].chunk_tp++;
		/*
		 *	If this queue is drained, drop the chunk count,
		 *	and readjust the queues.
		 */
		if (--chunkvector[smallest].chunk_n == 0){
			nchunks--;
			for (i = smallest; i < nchunks; i++)
				chunkvector[i] = chunkvector[i+1];
		}
		if (ISPROCESS(tp)){
			ft = tp->p.count;
			column(ft, tp->p.realt, tp->p.cput,
				tp->p.syst, tp->p.imem, tp->p.io);
			printf("   %.14s\n", tp->p.name);
		}
	}	/* iterate to merge the lists */
E 2
}

printmoney()
{
	register i;
D 2
	char buf[128];
E 2
	register char *cp;
I 2
	register	struct user	*up;
E 2

D 2
	for (i=0; i<sizeof(user)/sizeof(user[0]); i++) {
		if (user[i].us_cnt && user[i].us_ctime) {
			cp = getname(i);
			if (cp == 0)
				printf("%-8d", i);
			else 
				printf("%-8s", cp);
			printf("%7u %9.2fcpu %10.0ftio %12.0fk*sec\n",
			    user[i].us_cnt, user[i].us_ctime/60,
			    user[i].us_io,
			    user[i].us_imem / (60 * 2));
E 2
I 2
	getnames();		/* fetches all of the names! */
	for (i = 0; i < maxuser; i++) {
		if ( (up = wasuser(i)) != 0){
			if (up->us_cnt) {
				if (up->us_name[0])
					printf("%-8s", up->us_name);
				else 
					printf("%-8d", i);
				printf("%7u %9.2fcpu %10.0ftio %12.0fk*sec\n",
D 3
					up->us_cnt, up->us_ctime/60,
E 3
I 3
					up->us_cnt, up->us_ctime / 60,
E 3
					up->us_io,
D 7
					up->us_imem / (60 * 2));
E 7
I 7
D 10
					up->us_imem / 60);
E 10
I 10
					up->us_imem / AHZ);
E 10
E 7
			}
E 2
		}
	}
}

column(n, a, b, c, d, e)
D 3
double n, a, b, c, d, e;
E 3
I 3
	double n, a, b, c, d, e;
E 3
{

	printf("%8.0f", n);
	if(cflg) {
		if(n == ncom)
			printf("%9s", ""); else
			printf("%8.2f%%", 100.*n/ncom);
	}
	col(n, a, treal, "re");
	if (oflg)
D 7
		col(n, 3600*(b/(b+c)), tcpu+tsys, "u/s");
E 7
I 7
D 10
		col(n, 60*64*(b/(b+c)), tcpu+tsys, "u/s");
E 10
I 10
		col(n, 60*AHZ*(b/(b+c)), tcpu+tsys, "u/s");
E 10
E 7
	else if(lflg) {
		col(n, b, tcpu, "u");
		col(n, c, tsys, "s");
	} else
		col(n, b+c, tcpu+tsys, "cp");
	if(tflg)
D 10
		printf("%8.1f", a/(b+c), "re/cp");
E 10
I 10
		printf("%8.1fre/cp", a/(b+c));
E 10
	if(dflg || !Dflg)
		printf("%10.0favio", e/(n?n:1));
	else
		printf("%10.0ftio", e);
	if (kflg || !Kflg)
D 7
		printf("%10.0fk", d/(2*((b+c)!=0.0?(b+c):1.0)));
E 7
I 7
		printf("%10.0fk", d/((b+c)!=0.0?(b+c):1.0));
E 7
	else
D 7
		printf("%10.0fk*sec", d/(2*60));
E 7
I 7
D 10
		printf("%10.0fk*sec", d/60);
E 10
I 10
		printf("%10.0fk*sec", d/AHZ);
E 10
E 7
}

col(n, a, m, cp)
D 3
double n, a, m;
char *cp;
E 3
I 3
	double n, a, m;
	char *cp;
E 3
{

	if(jflg)
D 7
		printf("%11.2f%s", a/(n*60.), cp); else
		printf("%11.2f%s", a/3600., cp);
E 7
I 7
D 10
		printf("%11.2f%s", a/(n*64.), cp); else
D 9
		printf("%11.2f%s", a/60*64., cp);
E 9
I 9
		printf("%11.2f%s", a/(60*64.), cp);
E 10
I 10
		printf("%11.2f%s", a/(n*(double)AHZ), cp); else
		printf("%11.2f%s", a/(60.*(double)AHZ), cp);
E 10
E 9
E 7
	if(cflg) {
		if(a == m)
			printf("%9s", ""); else
			printf("%8.2f%%", 100.*a/m);
	}
}

doacct(f)
char *f;
{
D 2
	int i;
E 2
	FILE *ff;
	long x, y, z;
	struct acct fbuf;
	register char *cp;
	register int c;
I 2
D 3
	register	struct	user	*up;
	register	cell	*tp;
E 3
I 3
	register struct	user *up;
	register cell *tp;
E 3
#ifdef DEBUG
	int	nrecords = 0;
#endif DEBUG
E 2

	if (sflg && sname) {
		printf("Only 1 file with -s\n");
		exit(0);
	}
	if (sflg)
		sname = f;
	if ((ff = fopen(f, "r"))==NULL) {
		printf("Can't open %s\n", f);
		return;
	}
	while (fread((char *)&fbuf, sizeof(fbuf), 1, ff) == 1) {
I 2
#ifdef DEBUG
		if (++nrecords % 1000 == 0)
			printf("Input record from %s number %d\n",
				f, nrecords);
#endif DEBUG
E 2
D 7
		if (fbuf.ac_comm[0]==0) {
			fbuf.ac_comm[0] = '?';
		}
		for (cp = fbuf.ac_comm; cp < &fbuf.ac_comm[NC]; cp++) {
			c = *cp & 0377;
			if (c && (c < ' ' || c >= 0200)) {
E 7
I 7
		for (cp = fbuf.ac_comm; *cp && cp < &fbuf.ac_comm[NC]; cp++)
			if (!isascii(*cp) || iscntrl(*cp))
E 7
				*cp = '?';
D 7
			}
		}
E 7
I 7
		if (cp == fbuf.ac_comm)
			*cp++ = '?';
E 7
		if (fbuf.ac_flag&AFORK) {
D 7
			for (cp=fbuf.ac_comm; cp < &fbuf.ac_comm[NC]; cp++)
				if (*cp==0) {
					*cp = '*';
					break;
				}
E 7
I 7
			if (cp >= &fbuf.ac_comm[NC])
D 9
				cp = &fbuf.ac_comm[NC];
E 9
I 9
				cp = &fbuf.ac_comm[NC-1];
E 9
			*cp++ = '*';
E 7
		}
I 7
		if (cp < &fbuf.ac_comm[NC])
			*cp = '\0';
E 7
		x = expand(fbuf.ac_utime) + expand(fbuf.ac_stime);
D 7
		y = fbuf.ac_mem;
E 7
I 7
		y = pgtok((u_short)fbuf.ac_mem);
E 7
D 8
		z = expand(fbuf.ac_io);
E 8
I 8
D 10
		z = expand(fbuf.ac_io) >> 6;
E 10
I 10
		z = expand(fbuf.ac_io) / AHZ;
E 10
E 8
		if (uflg) {
D 6
			printf("%3d%6.1fcp %6dmem %6dio %.14s\n",
E 6
I 6
D 7
			printf("%3d %6d cpu %8u mem %6d io %.14s\n",
E 6
D 3
			    fbuf.ac_uid, x/60.0, y, z,
			    fbuf.ac_comm);
E 3
I 3
			    fbuf.ac_uid, x, y, z, fbuf.ac_comm);
E 7
I 7
D 10
			printf("%3d %6.2f cpu %8uk mem %6d io %.*s\n",
			    fbuf.ac_uid, x / 64.0, y, z, NC, fbuf.ac_comm);
E 10
I 10
			printf("%3d %6.2f cpu %8luk mem %6ld io %.*s\n",
			    fbuf.ac_uid, x/(double)AHZ, y, z, NC, fbuf.ac_comm);
E 10
E 7
E 3
			continue;
		}
D 2
		c = fbuf.ac_uid;
		user[c].us_cnt++;
		user[c].us_ctime += x/60.;
		user[c].us_imem += x * y;
		user[c].us_io += z;
E 2
I 2
		up = finduser(fbuf.ac_uid);
		if (up == 0)
			continue;	/* preposterous user id */
		up->us_cnt++;
D 3
		up->us_ctime += x/60.;
E 3
I 3
D 10
		up->us_ctime += x;
E 10
I 10
		up->us_ctime += x/(double)AHZ;
E 10
E 3
		up->us_imem += x * y;
		up->us_io += z;
E 2
		ncom += 1.0;
D 2
		i = enter(fbuf.ac_comm);
		tab[i].imem += x * y;
E 2
I 2

		tp = enter(fbuf.ac_comm);
		tp->p.imem += x * y;
E 2
		timem += x * y;
D 2
		tab[i].count++;
E 2
I 2
		tp->p.count++;
E 2
D 3
		x = expand(fbuf.ac_etime)*60;
E 3
I 3
		x = expand(fbuf.ac_etime);
E 3
D 2
		tab[i].realt += x;
E 2
I 2
		tp->p.realt += x;
E 2
		treal += x;
		x = expand(fbuf.ac_utime);
D 2
		tab[i].cput += x;
E 2
I 2
		tp->p.cput += x;
E 2
		tcpu += x;
		x = expand(fbuf.ac_stime);
D 2
		tab[i].syst += x;
E 2
I 2
		tp->p.syst += x;
E 2
		tsys += x;
D 2
		tab[i].io += z;
E 2
I 2
		tp->p.io += z;
E 2
		tio += z;
	}
	fclose(ff);
}

I 2
/*
 *	Generalized cell compare routine, to cast out users
 */
cellcmp(p1, p2)
D 3
	cell	*p1, *p2;
E 3
I 3
	cell *p1, *p2;
E 3
{
	if (ISPROCESS(p1)){
		if (ISPROCESS(p2))
D 4
			return(cmp(p1, p2));
E 4
I 4
			return((*cmp)(p1, p2));
E 4
		return(-1);
	}
	if (ISPROCESS(p2))
		return(1);
	return(0);
}
I 3

E 3
E 2
ncmp(p1, p2)
D 2
struct tab *p1, *p2;
E 2
I 2
D 3
cell *p1, *p2;
E 3
I 3
	cell *p1, *p2;
E 3
E 2
{

D 2
	if(p1->count == p2->count)
E 2
I 2
	if(p1->p.count == p2->p.count)
E 2
		return(tcmp(p1, p2));
	if(rflg)
D 2
		return(p1->count - p2->count);
	return(p2->count - p1->count);
E 2
I 2
		return(p1->p.count - p2->p.count);
	return(p2->p.count - p1->p.count);
E 2
}

bcmp(p1, p2)
D 2
struct tab *p1, *p2;
E 2
I 2
D 3
cell *p1, *p2;
E 3
I 3
	cell *p1, *p2;
E 3
E 2
{
	double f1, f2;
	double sum();

D 2
	f1 = sum(p1)/p1->count;
	f2 = sum(p2)/p2->count;
E 2
I 2
	f1 = sum(p1)/p1->p.count;
	f2 = sum(p2)/p2->p.count;
E 2
	if(f1 < f2) {
		if(rflg)
			return(-1);
		return(1);
	}
	if(f1 > f2) {
		if(rflg)
			return(1);
		return(-1);
	}
	return(0);
}

Kcmp(p1, p2)
D 2
struct tab *p1, *p2;
E 2
I 2
D 3
cell *p1, *p2;
E 3
I 3
	cell *p1, *p2;
E 3
E 2
{

D 2
	if (p1->imem < p2->imem) {
E 2
I 2
	if (p1->p.imem < p2->p.imem) {
E 2
		if(rflg)
			return(-1);
		return(1);
	}
D 2
	if (p1->imem > p2->imem) {
E 2
I 2
	if (p1->p.imem > p2->p.imem) {
E 2
		if(rflg)
			return(1);
		return(-1);
	}
	return(0);
}

kcmp(p1, p2)
D 2
struct tab *p1, *p2;
E 2
I 2
D 3
cell *p1, *p2;
E 3
I 3
	cell *p1, *p2;
E 3
E 2
{
	double a1, a2;

D 2
	a1 = p1->imem / ((p1->cput+p1->syst)?(p1->cput+p1->syst):1);
	a2 = p2->imem / ((p2->cput+p2->syst)?(p2->cput+p2->syst):1);
E 2
I 2
	a1 = p1->p.imem / ((p1->p.cput+p1->p.syst)?(p1->p.cput+p1->p.syst):1);
	a2 = p2->p.imem / ((p2->p.cput+p2->p.syst)?(p2->p.cput+p2->p.syst):1);
E 2
	if (a1 < a2) {
		if(rflg)
			return(-1);
		return(1);
	}
	if (a1 > a2) {
		if(rflg)
			return(1);
		return(-1);
	}
	return(0);
}

dcmp(p1, p2)
D 2
struct tab *p1, *p2;
E 2
I 2
D 3
cell *p1, *p2;
E 3
I 3
	cell *p1, *p2;
E 3
E 2
{
	double a1, a2;

D 2
	a1 = p1->io / (p1->count?p1->count:1);
	a2 = p2->io / (p2->count?p2->count:1);
E 2
I 2
	a1 = p1->p.io / (p1->p.count?p1->p.count:1);
	a2 = p2->p.io / (p2->p.count?p2->p.count:1);
E 2
	if (a1 < a2) {
		if(rflg)
			return(-1);
		return(1);
	}
	if (a1 > a2) {
		if(rflg)
			return(1);
		return(-1);
	}
	return(0);
}

Dcmp(p1, p2)
D 2
struct tab *p1, *p2;
E 2
I 2
D 3
cell *p1, *p2;
E 3
I 3
	cell *p1, *p2;
E 3
E 2
{

D 2
	if (p1->io < p2->io) {
E 2
I 2
	if (p1->p.io < p2->p.io) {
E 2
		if(rflg)
			return(-1);
		return(1);
	}
D 2
	if (p1->io > p2->io) {
E 2
I 2
	if (p1->p.io > p2->p.io) {
E 2
		if(rflg)
			return(1);
		return(-1);
	}
	return(0);
}

tcmp(p1, p2)
D 2
struct tab *p1, *p2;
E 2
I 2
D 3
cell *p1, *p2;
E 3
I 3
	cell *p1, *p2;
E 3
E 2
{
	extern double sum();
	double f1, f2;

	f1 = sum(p1);
	f2 = sum(p2);
	if(f1 < f2) {
		if(rflg)
			return(-1);
		return(1);
	}
	if(f1 > f2) {
		if(rflg)
			return(1);
		return(-1);
	}
	return(0);
}

double sum(p)
D 2
struct tab *p;
E 2
I 2
D 3
cell *p;
E 3
I 3
	cell *p;
E 3
E 2
{

D 2
	if(p->name[0] == 0)
E 2
I 2
	if(p->p.name[0] == 0)
E 2
		return(0.0);
D 2
	return(
		p->cput+
		p->syst);
E 2
I 2
	return( p->p.cput + p->p.syst);
E 2
}

init()
{
D 2
	struct tab tbuf;
	int i;
E 2
I 2
D 3
	struct	user	userbuf;
	struct	process	tbuf;
	register	cell	*tp;
	register	struct	user	*up;
	int		uid;
E 3
I 3
	struct user userbuf;
	struct process	tbuf;
	register cell *tp;
	register struct user *up;
	int uid;
E 3
E 2
	FILE *f;

D 2
	if ((f = fopen("/usr/adm/savacct", "r")) == NULL)
E 2
I 2
D 10
	if ((f = fopen(SAVACCT, "r")) == NULL)
E 10
I 10
	if ((f = fopen(savacct, "r")) == NULL)
E 10
E 2
		goto gshm;
D 2
	while (fread((char *)&tbuf, sizeof(tbuf), 1, f) == 1) {
		i = enter(tbuf.name);
E 2
I 2
	while (fread((char *)&tbuf, sizeof(struct process), 1, f) == 1) {
		tp = enter(tbuf.name);
E 2
		ncom += tbuf.count;
D 2
		tab[i].count = tbuf.count;
E 2
I 2
		tp->p.count = tbuf.count;
E 2
		treal += tbuf.realt;
D 2
		tab[i].realt = tbuf.realt;
E 2
I 2
		tp->p.realt = tbuf.realt;
E 2
		tcpu += tbuf.cput;
D 2
		tab[i].cput = tbuf.cput;
E 2
I 2
		tp->p.cput = tbuf.cput;
E 2
		tsys += tbuf.syst;
D 2
		tab[i].syst = tbuf.syst;
E 2
I 2
		tp->p.syst = tbuf.syst;
E 2
		tio += tbuf.io;
D 2
		tab[i].io = tbuf.io;
E 2
I 2
		tp->p.io = tbuf.io;
E 2
		timem += tbuf.imem;
D 2
		tab[i].imem = tbuf.imem;
E 2
I 2
		tp->p.imem = tbuf.imem;
E 2
	}
	fclose(f);
 gshm:
D 2
	if ((f = fopen("/usr/adm/usracct", "r")) == NULL)
E 2
I 2
D 10
	if ((f = fopen(USRACCT, "r")) == NULL)
E 10
I 10
	if ((f = fopen(usracct, "r")) == NULL)
E 10
E 2
		return;
D 2
	fread((char *)user, sizeof(user), 1, f);
E 2
I 2
	for(uid = 0;
	    fread((char *)&(userbuf.oldu), sizeof(struct Olduser), 1, f) == 1;
	    uid++){
		if (userbuf.us_cnt){
			up = finduser(uid);
			if (up == 0)
				continue;	/* preposterous user id */
			up->oldu = userbuf.oldu;
		}
	}
E 2
	fclose(f);
}

D 2
enter(np)
char *np;
{
	int i, j;

	for (i=j=0; i<NC; i++) {
		if (np[i]==0)
			j = i;
		if (j)
			np[i] = 0;
	}
	for (i=j=0; j<NC; j++) {
		i = i*7 + np[j];
	}
	if (i < 0)
		i = -i;
	for (i%=size; tab[i].name[0]; i = (i+1)%size) {
		for (j=0; j<NC; j++)
			if (tab[i].name[j]!=np[j])
				goto no;
		goto yes;
	no:;
	}
	for (j=0; j<NC; j++)
		tab[i].name[j] = np[j];
yes:
	return(i);
}

E 2
strip()
{
D 2
	int i, j, c;
E 2
I 2
D 3
	int	c;
	register	struct	allocbox	*allocwalk;
	register	cell	*tp, *ub, *junkp;
E 3
I 3
	int c;
	register struct allocbox *allocwalk;
	register cell *tp, *ub, *junkp;
E 3
E 2

D 2
	j = enter("**junk**");
	for (i = 0; i<size; i++) {
		if (tab[i].name[0] && tab[i].count<=thres) {
			printf("%.14s--", tab[i].name);
			if ((c=getchar())=='y') {
				tab[i].name[0] = '\0';
				tab[j].count += tab[i].count;
				tab[j].realt += tab[i].realt;
				tab[j].cput += tab[i].cput;
				tab[j].syst += tab[i].syst;
E 2
I 2
	if (fflg)
		printf("Categorizing commands used %d times or fewer as **junk**\n",
			thres);
	junkp = enter("**junk**");
	PROCESSITERATE(allocwalk, tp, ub){
		if (tp->p.name[0] && tp->p.count <= thres) {
			if (!fflg)
				printf("%.14s--", tp->p.name);
			if (fflg || ((c=getchar())=='y')) {
				tp->p.name[0] = '\0';
				junkp->p.count += tp->p.count;
				junkp->p.realt += tp->p.realt;
				junkp->p.cput += tp->p.cput;
				junkp->p.syst += tp->p.syst;
				junkp->p.imem += tp->p.imem;
				junkp->p.io += tp->p.io;
E 2
			}
D 2
			while (c && c!='\n')
				c = getchar();
E 2
I 2
			if (!fflg)
				while (c && c!='\n')
					c = getchar();
E 2
		}
	}
}

time_t
expand(t)
D 3
unsigned t;
E 3
I 3
	unsigned t;
E 3
{
	register time_t nt;

	nt = t&017777;
	t >>= 13;
	while (t!=0) {
		t--;
		nt <<= 3;
	}
	return(nt);
}

D 2
#include <utmp.h>
#include <pwd.h>
E 2
I 2
D 3
static	char	UserKey[NAMELG + 2];
char *makekey(uid)
	int	uid;
E 3
I 3
static	char UserKey[NAMELG + 2];

char *
makekey(uid)
	int uid;
E 3
{
D 11
	sprintf(UserKey+1, "%04x", uid);
E 11
I 11
	(void)sprintf(UserKey+1, "%04x", uid);
E 11
	UserKey[0] = USERKEY;
	return(UserKey);
}
E 2

D 2
struct	utmp utmp;
#define	NMAX	sizeof (utmp.ut_name)
#define	NUID	2048
E 2
I 2
D 3
struct user *wasuser(uid)
	int 	uid;
E 3
I 3
struct user *
wasuser(uid)
	int uid;
E 3
{
D 3
	struct	user	*tp;
E 3
I 3
	struct user *tp;

E 3
	htabinstall = 0;
	tp = finduser(uid);
	htabinstall = 1;
	return(tp);
}
I 3

E 3
/*
 *	Only call this if you really want to insert it in the table!
 */
D 3
struct user *finduser(uid)
	int	uid;
E 3
I 3
struct user *
finduser(uid)
	int uid;
E 3
{
I 3

E 3
	if (uid > maxuser){
		fprintf(stderr, "Preposterous user id, %d: ignored\n", uid);
		return(0);
D 3
	} else {
		return((struct user*)enter(makekey(uid)));
E 3
	}
I 3
	return((struct user*)enter(makekey(uid)));
E 3
}
E 2

D 2
char	names[NUID][NMAX+1];

char *
getname(uid)
E 2
I 2
/*
 *	Set the names of all users in the password file.
 *	We will later not print those that didn't do anything.
 */
getnames()
E 2
{
I 2
D 3
	register	struct user	*tp;
E 3
I 3
	register struct user *tp;
E 3
E 2
	register struct passwd *pw;
D 2
	static init;
E 2
	struct passwd *getpwent();

D 2
	if (names[uid][0])
		return (&names[uid][0]);
	if (init == 2)
		return (0);
	if (init == 0)
		setpwent(), init = 1;
	while (pw = getpwent()) {
		if (pw->pw_uid >= NUID)
			continue;
		if (names[pw->pw_uid][0])
			continue;
		strncpy(names[pw->pw_uid], pw->pw_name, NMAX);
		if (pw->pw_uid == uid)
			return (&names[uid][0]);
E 2
I 2
	setpwent();
	while (pw = getpwent()){
D 10
		if ( (tp = wasuser(pw->pw_uid)) != 0)
E 10
I 10
		/* use first name in passwd file for duplicate uid's */
		if ((tp = wasuser(pw->pw_uid)) != 0 && !isalpha(tp->us_name[0]))
E 10
			strncpy(tp->us_name, pw->pw_name, NAMELG);
E 2
	}
D 2
	init = 2;
E 2
	endpwent();
D 2
	return (0);
E 2
}
I 2

D 3
int getmaxuid()
E 3
I 3
int
getmaxuid()
E 3
{
D 3
	register	struct	user	*tp;
	register	struct	passwd	*pw;
	struct		passwd	*getpwent();
	int		maxuid = -1;
E 3
I 3
	register struct user *tp;
	register struct passwd *pw;
	struct passwd *getpwent();
	int maxuid = -1;
E 3

	setpwent();
	while(pw = getpwent()){
		if (pw->pw_uid > maxuid)
			maxuid = pw->pw_uid;
	}
	endpwent();
	return(maxuid);
}

tabinit()
{
	allochead = 0;
	alloctail = 0;
	nexttab = 0;
	tabsleft = 0;
	htab = 0;
	ntabs = 0;
	htaballoc();		/* get the first part of the hash table */
}

#define ALLOCQTY 	sizeof (struct allocbox)
D 3
cell *taballoc()
E 3
I 3
cell *
taballoc()
E 3
{
I 3

E 3
	if (tabsleft == 0){
		newbox = (struct allocbox *)calloc(1, ALLOCQTY);
		tabsleft = TABDALLOP;
		nexttab = &newbox->tabslots[0];
		if (alloctail == 0){
			allochead = alloctail = newbox;
		} else {
			alloctail->nextalloc = newbox;
			alloctail = newbox;
		}
	}
	--tabsleft;
	++ntabs;
#ifdef DEBUG
	if (ntabs % 100 == 0)
		printf("##Accounting table slot # %d\n", ntabs);
#endif DEBUG
	return(nexttab++);
}

htaballoc()
{
D 3
	register	struct	hashdallop	*new;
E 3
I 3
	register struct hashdallop *new;
E 3
#ifdef DEBUG
D 3
	static	int	ntables = 0;
E 3
I 3
	static int ntables = 0;

E 3
	printf("%%%New hash table chunk allocated, number %d\n", ++ntables);
#endif DEBUG
	new = (struct hashdallop *)calloc(1, sizeof (struct hashdallop));
	if (htab == 0)
		htab = new;
	else {		/* add AFTER the 1st slot */
		new->h_next = htab->h_next;
		htab->h_next = new;
	}
}

#define 	HASHCLOGGED	(NHASH / 2)
/*
 *	Lookup a symbol passed in as the argument.
 *
 *	We take pains to avoid function calls; this function
 *	is called quite frequently, and the calling overhead
 *	contributes significantly to the overall execution speed of sa.
 */
D 3
cell *enter(name)
	char	*name;	
E 3
I 3
cell *
enter(name)
	char *name;	
E 3
{
D 3
	static	 int		initialprobe;
	register cell	 	**hp;
	register char 		*from;
	register char		*to;
	register	int	len;
	register	int	nprobes;
	static	 struct hashdallop *hdallop;
	static	 cell		**emptyslot;
	static 	 struct hashdallop *emptyhd;
	static	 cell		**hp_ub;
E 3
I 3
	static int initialprobe;
	register cell **hp;
	register char *from, *to;
	register int len, nprobes;
	static struct hashdallop *hdallop, *emptyhd;
	static cell **emptyslot, **hp_ub;
E 3

	emptyslot = 0;
	for (nprobes = 0, from = name, len = 0;
	     *from && len < NC;
	     nprobes <<= 2, nprobes += *from++, len++)
		continue;
	nprobes += from[-1] << 5;
	nprobes %= NHASH;
	if (nprobes < 0)
		nprobes += NHASH;

	initialprobe = nprobes;
	for (hdallop = htab; hdallop != 0; hdallop = hdallop->h_next){
		for (hp = &(hdallop->h_tab[initialprobe]),
				nprobes = 1,
				hp_ub = &(hdallop->h_tab[NHASH]);
		     (*hp) && (nprobes < NHASH);
				hp += nprobes,
				hp -= (hp >= hp_ub) ? NHASH:0,
				nprobes += 2)
		{
			from = name;
			to = (*hp)->p.name;

			for (len = 0; (len<NC) && *from; len++)
				if (*from++ != *to++)
					goto nextprobe;
			if (len >= NC)		/*both are maximal length*/
				return(*hp);
			if (*to == 0)		/*assert *from == 0*/
				return(*hp);
	nextprobe: ;
		}
		if (*hp == 0 && emptyslot == 0 &&
		    hdallop->h_nused < HASHCLOGGED) {
			emptyslot = hp;
			emptyhd = hdallop;
		}
	}
	if (emptyslot == 0) {
		htaballoc();
		hdallop = htab->h_next;		/* aren't we smart! */
		hp = &hdallop->h_tab[initialprobe];
	} else {
		hdallop = emptyhd;
		hp = emptyslot;
	}
	if (htabinstall){
		*hp = taballoc();
		hdallop->h_nused++;
		for(len = 0, from = name, to = (*hp)->p.name; (len<NC); len++)
			if ((*to++ = *from++) == '\0')
				break;
		return(*hp);
	}
	return(0);
D 3
}	/*end of lookup*/
E 3
I 3
}
E 3
E 2
E 1
