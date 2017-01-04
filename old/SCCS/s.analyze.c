h17179
s 00001/00001/00880
d D 5.2 86/05/14 11:25:40 karels 9 8
c follow kernel units change; still broken
e
s 00014/00002/00867
d D 5.1 85/06/06 10:57:58 dist 8 7
c Add copyright
e
s 00030/00018/00839
d D 4.7 83/05/24 12:16:41 sam 7 6
c fixed for new swap map setup
e
s 00028/00014/00829
d D 4.6 83/02/09 14:30:59 sam 6 5
c from sun
e
s 00001/00001/00842
d D 4.5 82/12/24 12:47:24 sam 5 4
c pte.h moved
e
s 00020/00009/00823
d D 4.4 81/05/18 09:28:12 root 4 3
c more robust against cmap crud
e
s 00053/00016/00779
d D 4.3 81/04/15 03:06:39 root 3 2
c fixed to work again
e
s 00022/00004/00773
d D 4.2 81/02/28 23:03:36 wnj 2 1
c fix long names in name list and add 'u' flag
e
s 00777/00000/00000
d D 4.1 80/10/01 17:24:40 bill 1 0
c date and time created 80/10/01 17:24:40 by bill
e
u
U
t
T
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 8
I 7
#ifndef lint
E 7
I 1
D 8
static char *sccsid = "%W% (Berkeley) %G%";
I 7
#endif
E 8
I 8
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8

/*
 * Analyze - analyze a core (and optional paging area) saved from
 * a virtual Unix system crash.
 */
E 7
#include <stdio.h>
#include <sys/param.h>
#include <sys/dir.h>
D 5
#include <sys/pte.h>
E 5
I 5
#include <machine/pte.h>
E 5
#include <nlist.h>
#include <sys/map.h>
#include <sys/user.h>
#include <sys/proc.h>
#include <sys/text.h>
#include <sys/cmap.h>
#include <sys/vm.h>

D 7
/*
 * Analyze - analyze a core (and optional paging area) saved from
 * a virtual Unix system crash.
 */

E 7
int	Dflg;
int	dflg;
int	vflg;
int	mflg;
int	fflg;
int	sflg;
I 2
int	uflg;
E 2

/* use vprintf with care; it plays havoc with ``else's'' */
#define	vprintf	if (vflg) printf

I 6
#ifdef vax
E 6
#define	clear(x)	((int)x & 0x7fffffff)
I 6
#else
#define clear(x)	((int)x)
#endif
E 6

D 3
struct	proc proc[NPROC];
struct	text text[NTEXT];
struct	map swapmap[SMAPSIZ];
E 3
I 3
D 4
struct	proc *proc;
E 4
I 4
struct	proc *proc, *aproc;
E 4
int	nproc;
D 4
struct	text *text;
E 4
I 4
struct	text *text, *atext;
E 4
int	ntext;
struct	mapent *swapmap;
int	nswapmap;
I 7
int	dmmin, dmmax, dmtext;
E 7
E 3
struct	cmap *cmap;
I 2
int	ecmx;
E 2
struct	pte *usrpt;
struct	pte *Usrptma;
int	firstfree;
int	maxfree;
int	freemem;
D 9
struct	pte p0br[ctopt(MAXTSIZ+MAXDSIZ+MAXSSIZ)][NPTEPG];
E 9
I 9
struct	pte p0br[ctopt(btoc(MAXTSIZ+MAXDSIZ+MAXSSIZ))][NPTEPG];
E 9
int	pid;

struct	paginfo {
	char	z_type;
	char	z_count;
	short	z_pid;
	struct	pte z_pte;
} *paginfo;
#define	ZLOST	0
#define	ZDATA	1
#define	ZSTACK	2
#define	ZUDOT	3
#define	ZPAGET	4
#define	ZTEXT	5
#define	ZFREE	6
#define	ZINTRAN	7

D 3
#define	NDBLKS	(2*SMAPSIZ)
E 3
struct	dblks {
	short	d_first;
	short	d_size;
	char	d_type;
	char	d_index;
D 3
} dblks[NDBLKS];
E 3
I 3
} *dblks;
E 3
int	ndblks;

#define	DFREE	0
#define	DDATA	1
#define	DSTACK	2
#define	DTEXT	3
#define	DUDOT	4
#define	DPAGET	5

union	{
D 6
	char buf[UPAGES][512];
E 6
I 6
	char buf[UPAGES][NBPG];
E 6
	struct user U;
} u_area;
#define	u	u_area.U

int	fcore = -1;
int	fswap = -1;

struct	nlist nl[] = {
#define	X_PROC 0
	{ "_proc" },
#define	X_USRPT 1
	{ "_usrpt" },
#define	X_PTMA	2
D 2
	{ "_Usrptma" },
E 2
I 2
	{ "_Usrptmap" },
E 2
#define	X_FIRSTFREE 3
D 2
	{ "_firstfr" },
E 2
I 2
	{ "_firstfree" },
E 2
#define	X_MAXFREE 4
	{ "_maxfree" },
#define	X_TEXT 5
	{ "_text" },
#define	X_FREEMEM 6
	{ "_freemem" },
#define	X_CMAP 7
	{ "_cmap" },
#define	X_ECMAP 8
	{ "_ecmap" },
#define	X_SWAPMAP 9
	{ "_swapmap" },
I 3
#define	X_NPROC 10
	{ "_nproc" },
#define	X_NTEXT 11
	{ "_ntext" },
#define	X_NSWAPMAP 12
	{ "_nswapmap" },
E 3
D 7
	{ 0 }
E 7
I 7
#define	X_DMMIN	13
	{ "_dmmin" },
#define	X_DMMAX	14
	{ "_dmmax" },
#define	X_DMTEXT 15
	{ "_dmtext" },
	{ "" }
E 7
};

main(argc, argv)
	int argc;
	char **argv;
{
	register struct nlist *np;
	register struct proc *p;
	register struct text *xp;
	register struct pte *pte;
	register int i;
	int w, a;

I 6
#ifdef DEBUG
	setbuf(stdout, NULL);
#endif
E 6
	argc--, argv++;
	while (argc > 0 && argv[0][0] == '-') {
		register char *cp = *argv++;
		argc--;
		while (*++cp) switch (*cp) {

		case 'm':
			mflg++;
			break;

		case 'v':
			vflg++;
			break;

		case 's':
			if (argc < 2)
				goto usage;
			if ((fswap = open(argv[0], 0)) < 0) {
				perror(argv[0]);
				exit(1);
			}
			argc--,argv++;
			sflg++;
			break;

		case 'f':
			fflg++;
			break;

		case 'D':
			Dflg++;
			break;

		case 'd':
			dflg++;
			break;

I 2
		case 'u':
			uflg++;
			break;

E 2
		default:
			goto usage;
		}
	}
	if (argc < 1) {
usage:
		fprintf(stderr, "usage: analyze [ -vmfd ] [ -s swapfile ] corefile [ system ]\n");
		exit(1);
	}
	close(0);
	if ((fcore = open(argv[0], 0)) < 0) {
		perror(argv[0]);
		exit(1);
	}
	nlist(argc > 1 ? argv[1] : "/vmunix", nl);
	if (nl[0].n_value == 0) {
		fprintf(stderr, "%s: bad namelist\n",
		    argc > 1 ? argv[1] : "/vmunix");
		exit(1);
	}
D 6
	for (np = nl; np->n_name[0]; np++)
E 6
I 6
D 7
	for (np = nl; np->n_name; np++)
E 7
I 7
	for (np = nl; np->n_name && *np->n_name; np++)
E 7
E 6
		vprintf("%8.8s %x\n", np->n_name ,np->n_value );
	usrpt = (struct pte *)clear(nl[X_USRPT].n_value);
	Usrptma = (struct pte *)clear(nl[X_PTMA].n_value);
	firstfree = get(nl[X_FIRSTFREE].n_value);
	maxfree = get(nl[X_MAXFREE].n_value);
	freemem = get(nl[X_FREEMEM].n_value);
I 7
	dmmin = get(nl[X_DMMIN]);
	dmmax = get(nl[X_DMMAX]);
	dmtext = get(nl[X_DMTEXT]);
E 7
	paginfo = (struct paginfo *)calloc(maxfree, sizeof (struct paginfo));
	if (paginfo == NULL) {
		fprintf(stderr, "maxfree %x?... out of mem!\n", maxfree);
		exit(1);
	}
	vprintf("usrpt %x\nUsrptma %x\nfirstfree %x\nmaxfree %x\nfreemem %x\n",
		    usrpt, Usrptma, firstfree, maxfree, freemem);
D 3
	lseek(fcore, (long)clear(nl[X_PROC].n_value), 0);
	if (read(fcore, (char *)proc, sizeof proc) != sizeof proc) {
E 3
I 3
D 4
	{ struct proc *aproc; 
E 4
I 4
	{
E 4
	  lseek(fcore, (long)clear(nl[X_PROC].n_value), 0);
	  read(fcore, (char *)&aproc, sizeof aproc);
	  lseek(fcore, (long)clear(nl[X_NPROC].n_value), 0);
	  read(fcore, (char *)&nproc, sizeof nproc);
	  printf("%d procs\n", nproc);
	  proc = (struct proc *)calloc(nproc, sizeof (struct proc));
	  lseek(fcore, (long)clear(aproc), 0);
	  if (read(fcore, (char *)proc, nproc * sizeof (struct proc))
	    != nproc * sizeof (struct proc)) {
E 3
	 	perror("proc read");
		exit(1);
I 3
	  }
E 3
	}
D 3
	lseek(fcore, (long)clear(nl[X_TEXT].n_value), 0);
	if (read(fcore, (char *)text, sizeof text) != sizeof text) {
E 3
I 3
D 4
	{ struct text *atext;
E 4
I 4
	{
E 4
	  lseek(fcore, (long)clear(nl[X_TEXT].n_value), 0);
	  read(fcore, (char *)&atext, sizeof atext);
	  lseek(fcore, (long)clear(nl[X_NTEXT].n_value), 0);
	  read(fcore, (char *)&ntext, sizeof ntext);
	  printf("%d texts\n", ntext);
	  text = (struct text *)calloc(ntext, sizeof (struct text));
	  lseek(fcore, (long)clear(atext), 0);
	  if (read(fcore, (char *)text, ntext * sizeof (struct text))
	    != ntext * sizeof (struct text)) {
E 3
		perror("text read");
		exit(1);
I 3
	  }
E 3
	}
	i = (get(nl[X_ECMAP].n_value) - get(nl[X_CMAP].n_value));
I 2
	ecmx = i / sizeof (struct cmap);
E 2
	cmap = (struct cmap *)calloc(i, 1);
	if (cmap == NULL) {
		fprintf(stderr, "not enough mem for %x bytes of cmap\n", i);
		exit(1);
	}
	lseek(fcore, (long)clear(get(nl[X_CMAP].n_value)), 0);
	if (read(fcore, (char *)cmap, i) != i) {
		perror("cmap read");
		exit(1);
	}
D 3
	lseek(fcore, (long)clear(nl[X_SWAPMAP].n_value), 0);
	if (read(fcore, (char *)swapmap, sizeof swapmap) != sizeof swapmap) {
E 3
I 3
	{ struct mapent *aswapmap;
	  lseek(fcore, (long)clear(nl[X_SWAPMAP].n_value), 0);
	  read(fcore, (char *)&aswapmap, sizeof aswapmap);
	  lseek(fcore, (long)clear(nl[X_NSWAPMAP].n_value), 0);
	  read(fcore, (char *)&nswapmap, sizeof nswapmap);
	  nswapmap--;
	  printf("%d swapmap entries\n", nswapmap);
	  swapmap = (struct mapent *)calloc(nswapmap, sizeof (struct mapent));
	  dblks = (struct dblks *)calloc(2 * nswapmap, sizeof (struct dblks));
	  lseek(fcore, (long)clear(aswapmap+1), 0);
	  if (read(fcore, (char *)swapmap, nswapmap * sizeof (struct mapent))
	    != nswapmap * sizeof (struct mapent)) {
E 3
		perror("swapmap read");
		exit(1);
I 3
	  }
E 3
	}
D 3
	for (p = &proc[1]; p < &proc[NPROC]; p++) {
E 3
I 3
	for (p = &proc[1]; p < proc+nproc; p++) {
E 3
		p->p_p0br = (struct pte *)clear(p->p_p0br);
		p->p_addr = (struct pte *)clear(p->p_addr);
		if (p->p_stat == 0)
			continue;
		printf("proc %d ", p->p_pid);
		if (p->p_stat == SZOMB) {
			printf("zombie\n");
			continue;
		}
		if (p->p_flag & SLOAD) {
			printf("loaded, p0br %x, ", p->p_p0br);
			printf("%d pages of page tables:", p->p_szpt);
			a = btokmx(p->p_p0br);
			for (i = 0; i < p->p_szpt; i++) {
				w = get(&Usrptma[a + i]);
				printf(" %x", w & PG_PFNUM);
			}
			printf("\n");
			for(i = 0; i < p->p_szpt; i++) {
				w = get(&Usrptma[a + i]);
				if (getpt(w, i))
					count(p, (struct pte *)&w, ZPAGET);
			}
		} else {
			/* i = ctopt(btoc(u.u_exdata.ux_dsize)); */
			i = clrnd(ctopt(p->p_tsize + p->p_dsize + p->p_ssize));
			printf("swapped, swaddr %x\n", p->p_swaddr);
D 6
			duse(p->p_swaddr, clrnd(ctod(UPAGES)), DUDOT, p - proc);
E 6
I 6
			duse(p->p_swaddr, ctod(clrnd(UPAGES)), DUDOT, p - proc);
E 6
			duse(p->p_swaddr + ctod(UPAGES),
D 6
			    clrnd(i - p->p_tsize / NPTEPG), DPAGET, p - proc); 
E 6
I 6
			    ctod(clrnd(i - p->p_tsize / NPTEPG)), 
				DPAGET, p - proc); 
E 6
			    /* i, DPAGET, p - proc); */
		}
		p->p_p0br = (struct pte *)p0br;
		p->p_addr = uaddr(p);
D 4
		p->p_textp = &text[p->p_textp - (struct text *)nl[X_TEXT].n_value];
E 4
I 4
D 6
		p->p_textp = &text[p->p_textp - atext];
E 6
I 6
		if (p->p_textp)
			p->p_textp = &text[p->p_textp - atext];
E 6
E 4
		if (p->p_pid == 2)
			continue;
		if (getu(p))
			continue;
		u.u_procp = p;
		pdmap();
		if ((p->p_flag & SLOAD) == 0)
			continue;
		pid = p->p_pid;
		for (i = 0; i < p->p_tsize; i++) {
			pte = tptopte(p, i);
			if (pte->pg_fod || pte->pg_pfnum == 0)
				continue;
			if (pte->pg_pfnum >= firstfree && pte->pg_pfnum < maxfree && cmap[pgtocm(pte->pg_pfnum)].c_intrans)
				count(p, pte, ZINTRAN);
			else
				count(p, pte, ZTEXT);
		}
		vprintf("\n");
		for (i = 0; i < p->p_dsize; i++) {
			pte = dptopte(p, i);
			if (pte->pg_fod || pte->pg_pfnum == 0)
				continue;
			if (pte->pg_pfnum >= firstfree && pte->pg_pfnum < maxfree && cmap[pgtocm(pte->pg_pfnum)].c_intrans)
				count(p, pte, ZINTRAN);
			else
				count(p, pte, ZDATA);
		}
		vprintf("\n");
		for (i = 0; i < p->p_ssize; i++) {
			pte = sptopte(p, i);
			if (pte->pg_fod || pte->pg_pfnum == 0)
				continue;
			if (pte->pg_pfnum >= firstfree && pte->pg_pfnum < maxfree && cmap[pgtocm(pte->pg_pfnum)].c_intrans)
				count(p, pte, ZINTRAN);
			else
				count(p, pte, ZSTACK);
		}
		vprintf("\n");
		for (i = 0; i < UPAGES; i++)
			count(p, &p->p_addr[i], ZUDOT);
		vprintf("\n");
		vprintf("\n");
	}
D 3
	for (xp = &text[0]; xp < &text[NTEXT]; xp++)
E 3
I 3
	for (xp = &text[0]; xp < text+ntext; xp++)
E 3
		if (xp->x_iptr) {
D 6
			for (i = 0; i < xp->x_size; i += DMTEXT)
E 6
I 6
			int size = ctod(xp->x_size);

D 7
			for (i = 0; i < size; i += DMTEXT)
E 7
I 7
			for (i = 0; i < size; i += dmtext)
E 7
E 6
				duse(xp->x_daddr[i],
D 6
				    (xp->x_size - i) > DMTEXT
					? DMTEXT : xp->x_size - i,
E 6
I 6
D 7
				    (size - i) > DMTEXT
					? DMTEXT : size - i,
E 7
I 7
				    (size - i) > dmtext
					? dmtext : size - i,
E 7
E 6
				    DTEXT, xp - text);
			if (xp->x_flag & XPAGI)
D 6
				duse(xp->x_ptdaddr, clrnd(ctopt(xp->x_size)),
E 6
I 6
				duse(xp->x_ptdaddr, 
					ctod(clrnd(ctopt(xp->x_size))),
E 6
				    DTEXT, xp - text);
		}
	dmcheck();
	fixfree();
	summary();
	exit(0);
}

pdmap()
{
	register struct text *xp;

	if (fswap == -1 && (u.u_procp->p_flag & SLOAD) == 0)
		return;
	if (Dflg)
		printf("disk for pid %d", u.u_procp->p_pid);
	if ((xp = u.u_procp->p_textp) && Dflg)
		ptdmap(xp->x_daddr, xp->x_size);
	pdmseg("data", &u.u_dmap, DDATA);
	pdmseg("stack", &u.u_smap, DSTACK);
	if (Dflg)
		printf("\n");
}

ptdmap(dp, size)
	register daddr_t *dp;
	int size;
{
	register int i;
	int rem;

	if (Dflg)
		printf(" text:");
	for (i = 0, rem = size; rem > 0; i++) {
		if (Dflg)
D 7
			printf(" %x<%x>", dp[i], rem < DMTEXT ? rem : DMTEXT);
		rem -= rem < DMTEXT ? rem : DMTEXT;
E 7
I 7
			printf(" %x<%x>", dp[i], rem < dmtext ? rem : dmtext);
		rem -= rem < dmtext ? rem : dmtext;
E 7
	}
}

pdmseg(cp, dmp, type)
	char *cp;
	struct dmap *dmp;
{
	register int i;
	int b, rem;

	if (Dflg)
		printf(", %s:", cp);
D 7
	b = DMMIN;
E 7
I 7
	b = dmmin;
E 7
	for (i = 0, rem = dmp->dm_size; rem > 0; i++) {
		if (Dflg)
			printf(" %x<%x>", dmp->dm_map[i], rem < b ? rem : b);
		duse(dmp->dm_map[i], b, type, u.u_procp - proc);
		rem -= b;
D 7
		if (b < DMMAX)
E 7
I 7
		if (b < dmmax)
E 7
			b *= 2;
	}
}

duse(first, size, type, index)
{
	register struct dblks *dp;

	if (fswap == -1)
		return;
	dp = &dblks[ndblks];
D 3
	if (++ndblks > NDBLKS) {
		fprintf(stderr, "too many disk blocks, increase NDBLKS\n");
E 3
I 3
	if (++ndblks > 2*nswapmap) {
		fprintf(stderr, "too many disk blocks\n");
E 3
		exit(1);
	}
	dp->d_first = first;
	dp->d_size = size;
	dp->d_type = type;
	dp->d_index = index;
}

dsort(d, e)
	register struct dblks *d, *e;
{

	return (e->d_first - d->d_first);
}

dmcheck()
{
D 3
	register struct map *smp;
E 3
I 3
	register struct mapent *smp;
E 3
	register struct dblks *d, *e;

	for (smp = swapmap; smp->m_size; smp++)
		duse(smp->m_addr, smp->m_size, DFREE, 0);
D 6
	duse(CLSIZE, DMTEXT - CLSIZE, DFREE, 0);
E 6
I 6
D 7
	duse(ctod(CLSIZE), DMTEXT - ctod(CLSIZE), DFREE, 0);
E 7
I 7
	duse(ctod(CLSIZE), dmtext - ctod(CLSIZE), DFREE, 0);
E 7
E 6
	qsort(dblks, ndblks, sizeof (struct dblks), dsort);
	d = &dblks[ndblks - 1];
	if (d->d_first > 1)
		printf("lost swap map: start %x size %x\n", 1, d->d_first);
	for (; d > dblks; d--) {
		if (dflg)
			dprint(d);
		e = d - 1;
		if (d->d_first + d->d_size > e->d_first) {
			printf("overlap in swap mappings:\n");
			dprint(d);
			dprint(e);
		} else if (d->d_first + d->d_size < e->d_first) {
			printf("lost swap map: start %x size %x\n",
			    d->d_first + d->d_size,
			    e->d_first - (d->d_first + d->d_size)); 
		}
	}
	if (dflg)
		dprint(dblks);
	if (sflg)
		printf("swap space ends at %x\n", d->d_first + d->d_size);
}

char *dnames[] = {
	"DFREE",
	"DDATA",
	"DSTACK",
	"DTEXT",
	"DUDOT",
	"DPAGET",
};

dprint(d)
	register struct dblks *d;
{

	printf("at %4x size %4x type %s", d->d_first, d->d_size,
		dnames[d->d_type]);
	switch (d->d_type) {

	case DSTACK:
	case DDATA:
		printf(" pid %d", proc[d->d_index].p_pid);
		break;
	}
	printf("\n");
}

getpt(x, i)
	int x, i;
{

	lseek(fcore, (long)ctob((x & PG_PFNUM)), 0);
	if (read(fcore, (char *)(p0br[i]), NBPG) != NBPG) {
		perror("read");
		fprintf(stderr, "getpt error reading frame %x\n", clear(x));
		return (0);
	}
	return (1);
}

checkpg(p, pte, type)
	register struct pte *pte;
	register struct proc *p;
	int type;
{
	char corepg[NBPG], swapg[NBPG];
	register int i, count, dblock;
	register int pfnum = pte->pg_pfnum;

	if (type == ZPAGET || type == ZUDOT)
		return (0);
	lseek(fcore, (long)(NBPG * pfnum), 0);
	if (read(fcore, corepg, NBPG) != NBPG){
		perror("read");
		fprintf(stderr, "Error reading core page %x\n", pfnum);
		return (0);
	}
	switch (type) {

	case ZDATA:
		if (ptetodp(p, pte) >= u.u_dmap.dm_size)
			return (0);
		break;

	case ZTEXT:
		break;

	case ZSTACK:
		if (ptetosp(p, pte) >= u.u_smap.dm_size)
			return (0);
		break;

	default:
		return(0);
		break;
	}
	dblock = vtod(p, ptetov(p, pte), &u.u_dmap, &u.u_smap);
	vprintf("   %x", dblock);
	if (pte->pg_fod || pte->pg_pfnum == 0)
		return (0);
	if (cmap[pgtocm(pte->pg_pfnum)].c_intrans || pte->pg_m || pte->pg_swapm)
		return (0);
D 6
	lseek(fswap, (long)(NBPG * dblock), 0);
E 6
I 6
	lseek(fswap, (long)(DEV_BSIZE * dblock), 0);
E 6
	if (read(fswap, swapg, NBPG) != NBPG) {
		fprintf(stderr,"swap page %x: ", dblock);
		perror("read");
	}
	count = 0;
	for (i = 0; i < NBPG; i++)
		if (corepg[i] != swapg[i])
			count++;
	if (count == 0)
		vprintf("\tsame");
	return (count);
}

getu(p)
	register struct proc *p;
{
	int i, w, cc, errs = 0;

I 2
	if (uflg && (p->p_flag & SLOAD))
		printf("pid %d u. pages:", p->p_pid);
E 2
	for (i = 0; i < UPAGES; i++) {
		if (p->p_flag & SLOAD) {
I 2
			if (uflg)
				printf(" %x", p->p_addr[i].pg_pfnum);
E 2
			lseek(fcore, ctob(p->p_addr[i].pg_pfnum), 0);
			if (read(fcore, u_area.buf[i], NBPG) != NBPG)
				perror("core u. read"), errs++;
		} else if (fswap >= 0) {
			lseek(fswap, (long)(NBPG * (p->p_swaddr+i)), 0);
			if (read(fswap, u_area.buf[i], NBPG) != NBPG)
				perror("swap u. read"), errs++;
		}
	}
I 2
	if (uflg && (p->p_flag & SLOAD))
		printf("\n");
E 2
	return (errs);
}

char	*typepg[] = {
	"lost",
	"data",
	"stack",
	"udot",
	"paget",
	"text",
	"free",
	"intransit",
};

count(p, pte, type)
	struct proc *p;
	register struct pte *pte;
	int type;
{
	register int pfnum = pte->pg_pfnum;
	register struct paginfo *zp = &paginfo[pfnum];
	int ndif;
#define	zprintf	if (type==ZINTRAN || vflg) printf

	if (type == ZINTRAN && pfnum == 0)
		return;
	zprintf("page %x %s", pfnum, typepg[type]);
	if (sflg == 0 || (ndif = checkpg(p, pte, type)) == 0) {
		zprintf("\n");
	} else {
		if (vflg == 0 && type != ZINTRAN)
			printf("page %x %s,", pfnum, typepg[type]);
		printf(" %d bytes differ\n",ndif);
	}
	if (pfnum < firstfree || pfnum > maxfree) {
		printf("page number out of range:\n");
		printf("\tpage %x type %s pid %d\n", pfnum, typepg[type], pid);
		return;
	}
	if (bad(zp, type)) {
		printf("dup page pte %x", *(int *)pte);
		dumpcm("", pte->pg_pfnum);
		dump(zp);
		printf("pte %x and as %s in pid %d\n", zp->z_pte, typepg[type], pid);
		return;
	}
	zp->z_type = type;
	zp->z_count++;
	zp->z_pid = pid;
	zp->z_pte = *pte;
}

bad(zp, type)
	struct paginfo *zp;
{
	if (type == ZTEXT) {
		if (zp->z_type != 0 && zp->z_type != ZTEXT)
			return (1);
		return (0);
	}
	return (zp->z_count);
}

dump(zp)
	struct paginfo *zp;
{

	printf("page %x type %s pid %d ", zp - paginfo, typepg[zp->z_type], zp->z_pid);
}

summary()
{
	register int i;
	register struct paginfo *zp;
	register int pfnum;

D 2
	for (i = firstfree + UPAGES; i < maxfree; i++) {
E 2
I 2
	for (i = firstfree + UPAGES; i < maxfree; i+= CLSIZE) {
E 2
		zp = &paginfo[i];
		if (zp->z_type == ZLOST)
			dumpcm("lost", i);
		pfnum = pgtocm(i);
		if (cmap[pfnum].c_lock && cmap[pfnum].c_type != CSYS)
			dumpcm("locked", i);
		if (mflg)
			dumpcm("mem", i);
	}
}

char	*tynames[] = {
	"sys",
	"text",
	"data",
	"stack"
};
dumpcm(cp, pg)
	char *cp;
	int pg;
{
	int pslot;
	int cm;
	register struct cmap *c;

D 2
	printf("%s page %x ", cp, pg);
E 2
	cm = pgtocm(pg);
I 2
	printf("cm %x %s page %x ", cm, cp, pg);
E 2
	c = &cmap[cm];
	printf("\t[%x, %x", c->c_page, c->c_ndx);
D 4
	if (c->c_type != CTEXT)
E 4
I 4
	if (c->c_type == CSYS)
		goto skip;
	if (c->c_type != CTEXT) {
		if (c->c_ndx >= nproc) {
			printf(" [text c->c_ndx %d?]", c->c_ndx);
			goto skip;
		}
E 4
		printf(" (=pid %d)", proc[c->c_ndx].p_pid);
D 4
	else {
		pslot=(text[c->c_ndx].x_caddr - (struct proc *)nl[X_PROC].n_value);
E 4
I 4
	} else {
		if (c->c_ndx >= ntext) {
			printf(" [text c->c_ndx %d?]", c->c_ndx);
			goto skip;
		}
		pslot= (text[c->c_ndx].x_caddr - aproc);
E 4
		printf(" (=pid");
		for(;;) {
			printf(" %d", proc[pslot].p_pid);
			if (proc[pslot].p_xlink == 0)
				break;
D 4
			pslot=(proc[pslot].p_xlink - (struct proc *)nl[X_PROC].n_value);
E 4
I 4
			pslot= (proc[pslot].p_xlink - aproc);
E 4
		}
		printf(")");
	}
I 4
skip:
E 4
	printf("] ");
	printf(tynames[c->c_type]);
	if (c->c_free)
		printf(" free");
	if (c->c_gone)
		printf(" gone");
	if (c->c_lock)
		printf(" lock");
	if (c->c_want)
		printf(" want");
	if (c->c_intrans)
		printf(" intrans");
	if (c->c_blkno)
		printf(" blkno %x mdev %d", c->c_blkno, c->c_mdev);
I 2
	if (c->c_hlink) {
		printf(" hlink %x page %x", c->c_hlink, cmtopg(c->c_hlink));
		if (c->c_hlink > ecmx)
			printf(" <<<");
	}
E 2
	printf("\n");
}

fixfree()
{
	register int i, next, prev;

	next = CMHEAD;
	for (i=freemem/CLSIZE; --i >=0; ) {
		prev = next;
		next = cmap[next].c_next;
		if (cmap[next].c_free == 0) {
			printf("link to non free block: in %x to %x\n", cmtopg(prev), cmtopg(next));
			dumpcm("bad free link in", cmtopg(prev));
			dumpcm("to non free block", cmtopg(next));
		}
		if (cmtopg(next) > maxfree) {
			printf("free list link out of range: in %x to %x\n", cmtopg(prev), cmtopg(next));
			dumpcm("bad link in", cmtopg(prev));
		}
		paginfo[cmtopg(next)].z_type = ZFREE;
		if (fflg)
			dumpcm("free", cmtopg(next));
		paginfo[cmtopg(next)+1].z_type = ZFREE;
		if (fflg)
			dumpcm("free", cmtopg(next)+1);
	}
}

get(loc)
unsigned loc;
{
	int x;
	
	lseek(fcore, (long)clear(loc), 0);
	if (read(fcore, (char *)&x, sizeof (int)) != sizeof (int)) {
		perror("read");
		fprintf(stderr, "get failed on %x\n", clear(loc));
		return (0);
	}
	return (x);
}
/*
 * Convert a virtual page number 
 * to its corresponding disk block number.
 * Used in pagein/pageout to initiate single page transfers.
 */
vtod(p, v, dmap, smap)
	register struct proc *p;
	register struct dmap *dmap, *smap;
{
	struct dblock db;

D 6
	if (v < p->p_tsize)
E 6
I 6
	if (isatsv(p, v)) {
		v = ctod(vtotp(p, v));
E 6
D 7
		return(p->p_textp->x_daddr[v / DMTEXT] + v % DMTEXT);
E 7
I 7
		return(p->p_textp->x_daddr[v / dmtext] + v % dmtext);
E 7
I 6
	}
E 6
	if (isassv(p, v))
D 6
		vstodb(vtosp(p, v), 1, smap, &db, 1);
E 6
I 6
		vstodb(ctod(vtosp(p, v)), ctod(1), smap, &db, 1);
E 6
	else
D 6
		vstodb(vtodp(p, v), 1, dmap, &db, 0);
E 6
I 6
		vstodb(ctod(vtodp(p, v)), ctod(1), dmap, &db, 0);
E 6
	return (db.db_base);
}

/* 
 * Convert a pte pointer to
 * a virtual page number.
 */
ptetov(p, pte)
	register struct proc *p;
	register struct pte *pte;
{

	if (isatpte(p, pte))
		return (tptov(p, ptetotp(p, pte)));
	else if (isadpte(p, pte))
		return (dptov(p, ptetodp(p, pte)));
	else
		return (sptov(p, ptetosp(p, pte)));
}

/*
 * Given a base/size pair in virtual swap area,
 * return a physical base/size pair which is the
 * (largest) initial, physically contiguous block.
 */
vstodb(vsbase, vssize, dmp, dbp, rev)
	register int vsbase;
	int vssize;
	register struct dmap *dmp;
	register struct dblock *dbp;
{
D 7
	register int blk = DMMIN;
E 7
I 7
	register int blk = dmmin;
E 7
	register swblk_t *ip = dmp->dm_map;

	if (vsbase < 0 || vsbase + vssize > dmp->dm_size)
		panic("vstodb");
	while (vsbase >= blk) {
		vsbase -= blk;
D 7
		if (blk < DMMAX)
E 7
I 7
		if (blk < dmmax)
E 7
			blk *= 2;
		ip++;
	}
	dbp->db_size = min(vssize, blk - vsbase);
	dbp->db_base = *ip + (rev ? blk - (vsbase + vssize) : vsbase);
}

panic(cp)
	char *cp;
{
	printf("panic!: %s\n", cp);
}

min(a, b)
{
	return (a < b ? a : b);
}
E 1
