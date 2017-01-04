h35212
s 00002/00000/00309
d D 5.4 86/07/20 10:58:22 sam 12 11
c range check number of swap devices
e
s 00003/00000/00306
d D 5.3 86/01/12 15:26:27 sam 11 10
c add tahoe
e
s 00003/00003/00303
d D 5.2 85/12/11 16:08:16 bloom 10 9
c fix problem with losing /vmunix in the middle, a bit of lint cleanup
e
s 00008/00002/00298
d D 5.1 85/05/30 16:27:02 mckusick 9 8
c Add copyright
e
s 00000/00003/00300
d D 1.8 85/05/01 01:34:39 sam 8 7
c major rework; fixup netstat stuff; pull disk cmds into common file; change 
c everthing related to disks to use dk_ndrive and global selction; use getw where possible
e
s 00020/00024/00283
d D 1.7 85/04/29 00:43:04 sam 7 6
c cleanup window handling, use subwindows exclusively
e
s 00010/00000/00297
d D 1.6 84/08/09 19:13:07 mckusick 6 5
c update to new sources from sam; weed out unnecessary #includes
e
s 00161/00126/00136
d D 1.5 83/10/02 20:45:55 sam 5 4
c reorganize window management to allow display routines to set 
c up optimal window definitions
e
s 00028/00009/00234
d D 1.4 83/10/02 15:09:47 sam 4 3
c add some sanity checks
e
s 00160/00219/00083
d D 1.3 83/10/02 14:40:33 sam 3 2
c add init routine and mbuf display; redo swap space display
e
s 00219/00194/00083
d D 1.2 83/10/01 21:22:55 sam 2 1
c 1st version of swap usage; must redo to show swap in use rather than free
e
s 00277/00000/00000
d D 1.1 83/10/01 12:21:03 sam 1 0
c date and time created 83/10/01 12:21:03 by sam
e
u
U
t
T
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 9
I 1
#ifndef lint
D 7
static char *sccsid = "%W% (Lucasfilm) %G%";
E 7
I 7
D 9
static char *sccsid = "%W% (Berkeley) %G%";
E 7
#endif
E 9
I 9
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9

#include "systat.h"
I 6
D 8
#include <sys/param.h>
E 8
#include <sys/dir.h>
#include <sys/user.h>
#include <sys/proc.h>
#include <sys/text.h>
#include <sys/conf.h>
D 8
#include <sys/file.h>
E 8
#include <sys/vmmac.h>
#include <machine/pte.h>
D 8
#include <nlist.h>
E 8
E 6

D 5
#include <sys/map.h>
#include <sys/conf.h>
I 3
#include <sys/text.h>
E 3

/* these don't belong here */
I 3
#define X_PROC          0
#define X_NPROC         1
#define X_USRPTMAP      4
#define X_USRPT         5
E 3
#define X_NSWAP         6
D 3
#define X_SWAPMAP       7
#define X_NSWAPMAP      8
E 3
#define X_DMMIN         9
#define X_DMMAX         10
#define X_NSWDEV        11
I 2
#define	X_SWDEVT	12
I 3
#define	X_NTEXT		13
#define	X_TEXT		14
#define	X_DMTEXT	15
E 3
E 2

D 3
static  int dmmin;
static  int dmmax;
static  int nswdev;
static  int nswapmap;
static  int nswap;
static  struct map *swapmap;
I 2
static	short *buckets;
static	short *overflow;
E 3
I 3
int	dmmin;
int	dmmax;
int	dmtext;
int	nswdev;
#define	MAXSWAPDEV	4
short	buckets[MAXSWAPDEV][NDMAP];
E 3
struct	swdevt *swdevt;
I 3
struct	proc *kprocp;
int	ntext;
int	textaddr;
struct	text *xtext;
E 3
E 2

D 3
fetchswap()
E 3
I 3
initswap()
E 5
I 5
WINDOW *
openswap()
E 5
E 3
{
I 5
D 7
	static WINDOW *w = NULL;
E 7
E 5

D 3
        if (nswapmap == 0) {
                nswapmap = getw(nlst[X_NSWAPMAP].n_value);
                swapmap = (struct map *)calloc(nswapmap, sizeof (struct map));
                nswap = getw(nlst[X_NSWAP].n_value);
E 3
I 3
D 5
        if (nswdev == 0) {
E 3
                dmmin = getw(nlst[X_DMMIN].n_value);
                dmmax = getw(nlst[X_DMMAX].n_value);
I 3
                dmtext = getw(nlst[X_DMTEXT].n_value);
E 3
                nswdev = getw(nlst[X_NSWDEV].n_value);
I 2
D 3
		buckets = (short *)calloc(nswdev, sizeof (short));
		overflow = (short *)calloc(nswdev, sizeof (short));
E 3
		swdevt = (struct swdevt *)calloc(nswdev, sizeof (*swdevt));
		klseek(kmem, nlst[X_SWDEVT].n_value, L_SET);
		read(kmem, swdevt, nswdev * sizeof (struct swdevt));
D 3
		swapmap->m_name = "swap";
E 2
                return;
E 3
I 3
		ntext = getw(nlst[X_NTEXT].n_value);
D 4
		xtext = (struct text *)calloc(ntext, sizeof (struct text));
E 4
		textaddr = getw(nlst[X_TEXT].n_value);
E 3
        }
D 3
        klseek(kmem, getw(nlst[X_SWAPMAP].n_value), L_SET);
        read(kmem, swapmap, nswapmap * sizeof (struct map));
E 3
I 3
        if (procp == NULL) {
                procp = getw(nlst[X_PROC].n_value);
                nproc = getw(nlst[X_NPROC].n_value);
D 4
                kprocp = (struct proc *)malloc(sizeof (*kprocp) * nproc);
E 4
        }
I 4
	if (xtext == NULL)
		xtext = (struct text *)calloc(ntext, sizeof (struct text));
	if (kprocp == NULL)
                kprocp = (struct proc *)calloc(nproc, sizeof (struct proc));
E 4
        if (usrpt != NULL)
                return;
	usrpt = (struct pte *)nlst[X_USRPT].n_value;
	Usrptma = (struct pte *)nlst[X_USRPTMAP].n_value;
D 4
	pt = (struct p_times *)malloc(nproc * sizeof (struct p_times));
E 4
I 4
	if (pt == NULL)
		pt = (struct p_times *)malloc(nproc * sizeof (struct p_times));
E 5
I 5
D 7
        if (w == NULL)
		w = newwin(20, 70, 3, 5);
	return (w);
E 7
I 7
	return (subwin(stdscr, LINES-5-1, 0, 5, 0));
E 7
E 5
E 4
E 3
D 2
        swapmap->m_name = "swap";
E 2
}

I 3
D 5
fetchswap()
E 5
I 5
closeswap(w)
	WINDOW *w;
E 5
{

I 4
D 5
	if (kprocp == NULL) {
                kprocp = (struct proc *)malloc(sizeof (*kprocp) * nproc);
		if (kprocp == NULL)
			return;
	}
E 4
        lseek(kmem, procp, L_SET);
D 4
        read(kmem, kprocp, sizeof (struct proc) * nproc);
E 4
I 4
        if (read(kmem, kprocp, sizeof (struct proc) * nproc) !=
	    sizeof (struct proc) * nproc) {
		error("couldn't read proc table");
E 5
I 5
	if (w == NULL)
E 5
		return;
D 5
	}
	if (xtext == NULL) {
		xtext = (struct text *)calloc(ntext, sizeof (struct text));
		if (xtext == NULL)
			return;
	}
E 4
	lseek(kmem, textaddr, L_SET);
D 4
	read(kmem, xtext, ntext * sizeof (struct text));
E 4
I 4
	if (read(kmem, xtext, ntext * sizeof (struct text)) !=
	    sizeof (struct text) * ntext)
		error("couldn't read text table");
E 5
I 5
D 7
	move(5, 0);
	clrtobot();
E 7
	wclear(w);
	wrefresh(w);
I 7
	delwin(w);
E 7
E 5
E 4
}

E 3
I 2
D 5
#ifdef vax
char	*devnames[] =
     { "hp", "ht", "up", "rk", "sw", "tm", "ts", "mt", "tu", "ra", "ut",
       "rb", "rx", "rl" };
#endif
E 5
I 5
int	dmmin;
int	dmmax;
int	dmtext;
int	nswdev;
#define	MAXSWAPDEV	4
short	buckets[MAXSWAPDEV][NDMAP];
struct	swdevt *swdevt;
E 5
int	colwidth;

E 2
D 5
labelswap()
{
I 2
	register int i, j;
I 3
	register int row;
E 3
E 2

I 2
	if (nswdev == 0)
D 3
		fetchswap();
E 3
I 3
		initswap();
E 3
	if (nswdev == 0) {
		mvaddstr(22, 0, "Can't find number of swap devices.\n");
		return;
	}
E 2
        move(5, 0);
D 2
        clrtoeol();
        mvaddstr(5, 20, "/0   /5   /10  /15  /20  /25  /30  /35  /40  /45  /50");
E 2
I 2
	colwidth = (70 - (nswdev - 1)) / nswdev;
I 3
	row = swaplabel(5, dmtext, 1);
	(void) swaplabel(row, dmmax, 0);
}

swaplabel(row, dmbound, donames)
	register int row;
	int dmbound, donames;
{
	register int i, j;

E 3
	for (i = 0; i < nswdev; i++) {
D 3
		move(5, 5 + i * (1 + colwidth) + (colwidth - 3) / 2);
		printw("%s%d", devnames[major(swdevt[i].sw_dev)],
		    minor(swdevt[i].sw_dev) >> 3);
E 3
I 3
		if (donames) {
			move(row, 5 + i * (1 + colwidth) + (colwidth - 3) / 2);
			printw("%s%d", devnames[major(swdevt[i].sw_dev)],
			    minor(swdevt[i].sw_dev) >> 3);
		}
E 3
		for (j = 0; j + 5 < colwidth; j += 5) {
D 3
			move(6, 5 + i * (1 + colwidth) + j);
E 3
I 3
			move(row + donames, 5 + i * (1 + colwidth) + j);
E 3
			printw("/%-2d  ", j);
		}
	}
D 3
	for (j = 0, i = dmmax; i >= dmmin; i /= 2, j++) {
E 3
I 3
	row += 1 + donames;
	for (j = 0, i = dmmin; i <= dmbound; i *= 2, j++, row++) {
E 3
		int k;

D 3
		mvprintw(7 + j, 0, "%4d|", i);
E 3
I 3
		mvprintw(row, 0, "%4d|", i);
E 3
		for (k = 1; k < nswdev; k++)
D 3
			mvwaddch(wnd, 4 + j, k * (1 + colwidth) - 1, '|');
E 3
I 3
			mvwaddch(wnd, row - 3, k * (1 + colwidth) - 1, '|');
E 3
	}
I 3
	return (row);
E 3
E 2
}

E 5
I 3
extern union {
        struct  user user;
        char    upages[UPAGES][NBPG];
} user;
#define u       user.user

E 3
showswap()
{
I 2
        register int i, j;
I 3
	register struct proc *pp;
	register struct text *xp;
E 3
E 2
	register int row;
I 3
	register int ts;
	register swblk_t *dp;
E 3
D 2
        register int i, j, free;
#ifdef notdef
        register struct mapent *me;
E 2

D 2
        free = 0;
        for (me = (struct mapent *)(swapmap+1);
            me < (struct mapent *)&swapmap[nswapmap]; me++)
                free += me->m_size;
        free /= nswdev;
        for (i = 0; i < nswdev; i++)
                for (space = free; space > 0; space -= j) {
                        j = rmalloc(swapmap, dev));
                        if (j == 0)
                                break;
                }
#else
	for (row = 5, i = dmmax; i >= dmmin; i /= 2, row++) {
		j = 0;
		while (rmalloc(swapmap, i) != 0)
			j++;
                mvwprintw(wnd, row, 10, "%5d", i);
                wmove(wnd, row, 15);
                wclrtoeol(wnd);
                while (j--)
                        waddch(wnd, 'X');
        }
E 2
I 2
D 4
	if (nswdev == 0)
E 4
I 4
	if (xtext == 0)
E 4
		return;
D 3
	for (row = 4, i = dmmax; i >= dmmin; i /= 2, row++) {
move(22, 0); clrtoeol(); printw("size %d", i); refresh();
		do {
			j = rmalloc(swapmap, i);
			if (j)
				buckets[(j / dmmax) % nswdev]++;
		} while (j);
		for (j = 0; j < nswdev; j++) {
			register int k;
move(21 - j, 0); clrtoeol();
printw("buckets[%d]=%d", j, buckets[j]);
refresh();
			wmove(wnd, row, j * (1 + colwidth));
			k = MIN(buckets[j], colwidth);
			while (k--)
				waddch(wnd, 'X');
			k = MAX(colwidth - buckets[j], 0);
			while (k--)
				waddch(wnd, ' ');
			buckets[j] = 0;
E 3
I 3
	for (xp = xtext; xp < &xtext[ntext]; xp++) {
		if (xp->x_iptr == NULL)
			continue;
		ts = ctod(xp->x_size);
		dp = xp->x_daddr;
		for (i = 0; i < ts; i += dmtext) {
			j = ts - i;
			if (j > dmtext)
				j = dmtext;
#define	swatodev(addr)	(((addr) / dmmax) % nswdev)
			buckets[swatodev(*dp)][dmtoindex(j)]++;
			dp++;
E 3
		}
I 3
		if ((xp->x_flag & XPAGI) && xp->x_ptdaddr)
			buckets[swatodev(xp->x_ptdaddr)]
			    [dmtoindex(ctod(ctopt(xp->x_size)))]++;
E 3
	}
I 3
D 7
	row = swapdisplay(4, dmtext, 'X');
E 7
I 7
	row = swapdisplay(2, dmtext, 'X');
E 7
I 4
	if (kprocp == NULL)
		return;
E 4
        for (i = 0, pp = kprocp; i < nproc; i++, pp++) {
		if (pp->p_stat == 0 || pp->p_stat == SZOMB)
			continue;
		if (pp->p_flag & SSYS)
			continue;
D 4
		if (getu(pp) == 0) {
			error("showswap: getu failed on pid %d", pp->p_pid);
E 4
I 4
		if (getu(pp) == 0)
E 4
			continue;
D 4
		}
E 4
		vsacct(&u.u_dmap);
		vsacct(&u.u_smap);
E 3
#ifdef notdef
D 3
	printf("overflow:");
	for (i = 0; i < nswdev; i++)
		printf("\t%d", overflow[i]);
	printf("\n");
E 3
I 3
		if ((pp->p_flag & SLOAD) == 0)
			vusize(pp);
E 3
E 2
#endif
I 3
        }
D 7
	(void) swapdisplay(row + 1, dmmax, 'X');
E 7
I 7
	(void) swapdisplay(1+row, dmmax, 'X');
E 7
E 3
}

I 7
#define	OFFSET	5			/* left hand column */

E 7
D 2
#ifdef notdef
up(size)
        register int size;
{
        register int i, block;

        i = 0;
        block = dmmin;
        while (i < size) {
                i += block;
                if (block < dmmax)
                        block *= 2;
        }
        return (i);
}
#endif

E 2
D 3
/*
 * Allocate 'size' units from the given
 * map. Return the base of the allocated space.
 * In a map, the addresses are increasing and the
 * list is terminated by a 0 size.
 *
 * Algorithm is first-fit.
 *
 * This routine knows about the interleaving of the swapmap
 * and handles that.
 */
long
rmalloc(mp, size)
D 2
        register struct map *mp;
        long size;
E 2
I 2
	register struct map *mp;
	long size;
E 3
I 3
swapdisplay(baserow, dmbound, c)
	int baserow, dmbound;
	char c;
E 3
E 2
{
D 2
        register struct mapent *ep = (struct mapent *)(mp+1);
        register int addr;
        register struct mapent *bp;
        swblk_t first, rest;
E 2
I 2
D 3
	register struct mapent *ep = (struct mapent *)(mp+1);
	register int addr;
	register struct mapent *bp;
	swblk_t first, rest;
E 3
I 3
	register int i, j, k, row;
	register short *pb;
	char buf[10];
E 3
E 2

D 2
        if (size <= 0 || size > dmmax)
                return (0);
        /*
         * Search for a piece of the resource map which has enough
         * free space to accomodate the request.
         */
        for (bp = ep; bp->m_size; bp++) {
                if (bp->m_size >= size) {
                        /*
                         * If allocating from swapmap,
                         * then have to respect interleaving
                         * boundaries.
                         */
                        if (nswdev > 1 &&
                            (first = dmmax - bp->m_addr%dmmax) < bp->m_size) {
                                if (bp->m_size - first < size)
                                        continue;
                                addr = bp->m_addr + first;
                                rest = bp->m_size - first - size;
                                bp->m_size = first;
                                if (rest)
                                        rmfree(mp, rest, addr+size);
                                return (addr);
                        }
                        /*
                         * Allocate from the map.
                         * If there is no space left of the piece
                         * we allocated from, move the rest of
                         * the pieces to the left.
                         */
                        addr = bp->m_addr;
                        bp->m_addr += size;
                        if ((bp->m_size -= size) == 0) {
                                do {
                                        bp++;
                                        (bp-1)->m_addr = bp->m_addr;
                                } while ((bp-1)->m_size = bp->m_size);
                        }
                        if (addr % CLSIZE)
                                return (0);
                        return (addr);
                }
        }
        return (0);
}
E 2
I 2
D 3
	if (size <= 0 || size > dmmax)
		return (0);
	/*
	 * Search for a piece of the resource map which has enough
	 * free space to accomodate the request.
	 */
	for (bp = ep; bp->m_size; bp++) {
		if (bp->m_size >= size) {
			/*
			 * If allocating from swapmap,
			 * then have to respect interleaving
			 * boundaries.
			 */
			if (nswdev > 1 &&
			    (first = dmmax - bp->m_addr%dmmax) < bp->m_size) {
				if (bp->m_size - first < size)
					continue;
				addr = bp->m_addr + first;
				rest = bp->m_size - first - size;
				bp->m_size = first;
				if (rest)
					rmfree(mp, rest, addr+size);
				return (addr);
E 3
I 3
	for (row = baserow, i = dmmin; i <= dmbound; i *= 2, row++) {
		for (j = 0; j < nswdev; j++) {
			pb = &buckets[j][row - baserow];
D 7
			wmove(wnd, row, j * (1 + colwidth));
E 7
I 7
			wmove(wnd, row, OFFSET + j * (1 + colwidth));
E 7
			k = MIN(*pb, colwidth);
			if (*pb > colwidth) {
				sprintf(buf, " %d", *pb);
				k -= strlen(buf);
				while (k--)
					waddch(wnd, c);
				waddstr(wnd, buf);
			} else {
				while (k--)
					waddch(wnd, c);
				k = MAX(colwidth - *pb, 0);
				while (k--)
					waddch(wnd, ' ');
E 3
			}
D 3
			/*
			 * Allocate from the map.
			 * If there is no space left of the piece
			 * we allocated from, move the rest of
			 * the pieces to the left.
			 */
			addr = bp->m_addr;
			bp->m_addr += size;
			if ((bp->m_size -= size) == 0) {
				do {
					bp++;
					(bp-1)->m_addr = bp->m_addr;
				} while ((bp-1)->m_size = bp->m_size);
			}
			if (addr % CLSIZE)
				return (0);
			return (addr);
E 3
I 3
			*pb = 0;
E 3
		}
	}
D 3
	return (0);
E 3
I 3
	return (row);
E 3
}
E 2

D 3
/*
 * Free the previously allocated space at addr
 * of size units into the specified map.
 * Sort addr into map and combine on
 * one or both ends if possible.
 */
rmfree(mp, size, addr)
D 2
        struct map *mp;
        long size, addr;
E 2
I 2
	struct map *mp;
	long size, addr;
E 3
I 3
vsacct(dmp)
	register struct dmap *dmp;
E 3
E 2
{
D 2
        struct mapent *firstbp;
        register struct mapent *bp;
        register int t;
E 2
I 2
D 3
	struct mapent *firstbp;
	register struct mapent *bp;
	register int t;
E 3
I 3
	register swblk_t *ip;
	register int blk = dmmin, index = 0;
E 3
E 2

D 2
        /*
         * Both address and size must be
         * positive, or the protocol has broken down.
         */
        if (addr <= 0 || size <= 0)
                goto badrmfree;
        /*
         * Locate the piece of the map which starts after the
         * returned space (or the end of the map).
         */
        firstbp = bp = (struct mapent *)(mp + 1);
        for (; bp->m_addr <= addr && bp->m_size != 0; bp++)
                continue;
        /*
         * If the piece on the left abuts us,
         * then we should combine with it.
         */
        if (bp > firstbp && (bp-1)->m_addr+(bp-1)->m_size >= addr) {
                /*
                 * Check no overlap (internal error).
                 */
                if ((bp-1)->m_addr+(bp-1)->m_size > addr)
                        goto badrmfree;
                /*
                 * Add into piece on the left by increasing its size.
                 */
                (bp-1)->m_size += size;
                /*
                 * If the combined piece abuts the piece on
                 * the right now, compress it in also,
                 * by shifting the remaining pieces of the map over.
                 */
                if (bp->m_addr && addr+size >= bp->m_addr) {
                        if (addr+size > bp->m_addr)
                                goto badrmfree;
                        (bp-1)->m_size += bp->m_size;
                        while (bp->m_size) {
                                bp++;
                                (bp-1)->m_addr = bp->m_addr;
                                (bp-1)->m_size = bp->m_size;
                        }
                }
                goto done;
        }
        /*
         * Don't abut on the left, check for abutting on
         * the right.
         */
        if (addr+size >= bp->m_addr && bp->m_size) {
                if (addr+size > bp->m_addr)
                        goto badrmfree;
                bp->m_addr -= size;
                bp->m_size += size;
                goto done;
        }
        /*
         * Don't abut at all.  Make a new entry
         * and check for map overflow.
         */
        do {
                t = bp->m_addr;
                bp->m_addr = addr;
                addr = t;
                t = bp->m_size;
                bp->m_size = size;
                bp++;
        } while (size = t);
        /*
         * Segment at bp is to be the delimiter;
         * If there is not room for it 
         * then the table is too full
         * and we must discard something.
         */
        if (bp+1 > mp->m_limit) {
                /*
                 * Back bp up to last available segment.
                 * which contains a segment already and must
                 * be made into the delimiter.
                 * Discard second to last entry,
                 * since it is presumably smaller than the last
                 * and move the last entry back one.
                 */
                bp--;
E 2
I 2
D 3
	/*
	 * Both address and size must be
	 * positive, or the protocol has broken down.
	 */
	if (addr <= 0 || size <= 0)
		goto badrmfree;
	/*
	 * Locate the piece of the map which starts after the
	 * returned space (or the end of the map).
	 */
	firstbp = bp = (struct mapent *)(mp + 1);
	for (; bp->m_addr <= addr && bp->m_size != 0; bp++)
		continue;
	/*
	 * If the piece on the left abuts us,
	 * then we should combine with it.
	 */
	if (bp > firstbp && (bp-1)->m_addr+(bp-1)->m_size >= addr) {
		/*
		 * Check no overlap (internal error).
		 */
		if ((bp-1)->m_addr+(bp-1)->m_size > addr)
			goto badrmfree;
		/*
		 * Add into piece on the left by increasing its size.
		 */
		(bp-1)->m_size += size;
		/*
		 * If the combined piece abuts the piece on
		 * the right now, compress it in also,
		 * by shifting the remaining pieces of the map over.
		 */
		if (bp->m_addr && addr+size >= bp->m_addr) {
			if (addr+size > bp->m_addr)
				goto badrmfree;
			(bp-1)->m_size += bp->m_size;
			while (bp->m_size) {
				bp++;
				(bp-1)->m_addr = bp->m_addr;
				(bp-1)->m_size = bp->m_size;
			}
E 3
I 3
	for (ip = dmp->dm_map; dmp->dm_alloc > 0; ip++) {
		if (ip - dmp->dm_map >= NDMAP) {
			error("vsacct NDMAP");
			break;
E 3
		}
D 3
		goto done;
E 3
I 3
		if (*ip == 0)
			error("vsacct *ip == 0");
		buckets[swatodev(*ip)][index]++;
		dmp->dm_alloc -= blk;
		if (blk < dmmax) {
			blk *= 2;
			index++;
		}
E 3
	}
D 3
	/*
	 * Don't abut on the left, check for abutting on
	 * the right.
	 */
	if (addr+size >= bp->m_addr && bp->m_size) {
		if (addr+size > bp->m_addr)
			goto badrmfree;
		bp->m_addr -= size;
		bp->m_size += size;
		goto done;
	}
	/*
	 * Don't abut at all.  Make a new entry
	 * and check for map overflow.
	 */
	do {
		t = bp->m_addr;
		bp->m_addr = addr;
		addr = t;
		t = bp->m_size;
		bp->m_size = size;
		bp++;
	} while (size = t);
	/*
	 * Segment at bp is to be the delimiter;
	 * If there is not room for it 
	 * then the table is too full
	 * and we must discard something.
	 */
	if (bp+1 > mp->m_limit) {
		/*
		 * Back bp up to last available segment.
		 * which contains a segment already and must
		 * be made into the delimiter.
		 * Discard second to last entry,
		 * since it is presumably smaller than the last
		 * and move the last entry back one.
		 */
		bp--;
		overflow[((bp-1)->m_addr % dmmax) / nswdev] += 
		    (bp-1)->m_size;
E 2
#ifdef notdef
D 2
                printf("%s: rmap ovflo, lost [%d,%d)\n", mp->m_name,
                    (bp-1)->m_addr, (bp-1)->m_addr+(bp-1)->m_size);
E 2
I 2
		printf("%s: rmap ovflo, lost [%d,%d)\n", mp->m_name,
		    (bp-1)->m_addr, (bp-1)->m_addr+(bp-1)->m_size);
E 2
#endif
D 2
                bp[-1] = bp[0];
                bp[0].m_size = bp[0].m_addr = 0;
        }
E 2
I 2
		bp[-1] = bp[0];
		bp[0].m_size = bp[0].m_addr = 0;
	}
E 2
done:
D 2
        return;
E 2
I 2
	return;
E 2
badrmfree:
D 2
        ;
#ifdef notdef
        printf("bad rmfree\n");
#endif
E 2
I 2
	printf("bad rmfree\n");
E 3
I 3
}

dmtoindex(dm)
	int dm;
{
	register int i, j;

	for (j = 0, i = dmmin; i <= dmmax; i *= 2, j++)
		if (dm <= i)
			return (j);
	error("dmtoindex(%d)", dm);
	return (NDMAP - 1);
I 5
}

static struct nlist nlst[] = {
#define X_PROC          0
        { "_proc" },
#define X_NPROC         1
        { "_nproc" },
#define X_USRPTMAP      2
        { "_Usrptmap" },
#define X_USRPT         3
        { "_usrpt" },
#define X_NSWAP         4
        { "_nswap" },
#define X_DMMIN         5
        { "_dmmin" },
#define X_DMMAX         6
        { "_dmmax" },
#define	X_DMTEXT	7
	{ "_dmtext" },
#define X_NSWDEV        8
        { "_nswdev" },
#define	X_SWDEVT	9
	{ "_swdevt" },
#define	X_NTEXT		10
	{ "_ntext" },
#define	X_TEXT		11
	{ "_text" },
        { "" }
};

initswap()
{

	if (nlst[X_PROC].n_type == 0) {
		nlist("/vmunix", nlst);
		if (nlst[X_PROC].n_type == 0) {
			error("namelist on /vmunix failed");
D 10
			return;
E 10
I 10
			return(0);
E 10
		}
	}
        if (nswdev == 0) {
                dmmin = getw(nlst[X_DMMIN].n_value);
                dmmax = getw(nlst[X_DMMAX].n_value);
                dmtext = getw(nlst[X_DMTEXT].n_value);
                nswdev = getw(nlst[X_NSWDEV].n_value);
I 12
		if (nswdev > MAXSWAPDEV)
			nswdev = MAXSWAPDEV;
E 12
		swdevt = (struct swdevt *)calloc(nswdev, sizeof (*swdevt));
		klseek(kmem, nlst[X_SWDEVT].n_value, L_SET);
		read(kmem, swdevt, nswdev * sizeof (struct swdevt));
		ntext = getw(nlst[X_NTEXT].n_value);
		textp = getw(nlst[X_TEXT].n_value);
        }
        if (procp == NULL) {
                procp = getw(nlst[X_PROC].n_value);
                nproc = getw(nlst[X_NPROC].n_value);
        }
	if (xtext == NULL)
		xtext = (struct text *)calloc(ntext, sizeof (struct text));
	if (kprocp == NULL)
                kprocp = (struct proc *)calloc(nproc, sizeof (struct proc));
        if (usrpt != NULL)
D 10
                return;
E 10
I 10
                return(1);
E 10
	usrpt = (struct pte *)nlst[X_USRPT].n_value;
	Usrptma = (struct pte *)nlst[X_USRPTMAP].n_value;
	if (pt == NULL)
		pt = (struct p_times *)malloc(nproc * sizeof (struct p_times));
I 10
	return(1);
E 10
}

fetchswap()
{

	if (nlst[X_PROC].n_type == 0)
		return;
	if (kprocp == NULL) {
                kprocp = (struct proc *)malloc(sizeof (*kprocp) * nproc);
		if (kprocp == NULL)
			return;
	}
        lseek(kmem, procp, L_SET);
        if (read(kmem, kprocp, sizeof (struct proc) * nproc) !=
	    sizeof (struct proc) * nproc) {
		error("couldn't read proc table");
		return;
	}
	if (xtext == NULL) {
		xtext = (struct text *)calloc(ntext, sizeof (struct text));
		if (xtext == NULL)
			return;
	}
	lseek(kmem, textp, L_SET);
	if (read(kmem, xtext, ntext * sizeof (struct text)) !=
	    sizeof (struct text) * ntext)
		error("couldn't read text table");
}

#ifdef vax
char	*devnames[] =
     { "hp", "ht", "up", "rk", "sw", "tm", "ts", "mt", "tu", "ra", "ut",
       "rb", "rx", "rl" };
#endif
I 11
#ifdef tahoe
char	*devnames[] = { "ud", "vd", "xp", "cy", "sw" };
#endif
E 11

labelswap()
{
D 10
	register int i, j;
E 10
	register int row;

	if (nswdev == 0) {
		error("Don't know how many swap devices.\n");
		return;
	}
D 7
        move(5, 0);
	colwidth = (70 - (nswdev - 1)) / nswdev;
	row = swaplabel(5, dmtext, 1);
E 7
I 7
	colwidth = (COLS - OFFSET - (nswdev - 1)) / nswdev;
	row = swaplabel(0, dmtext, 1);
E 7
	(void) swaplabel(row, dmmax, 0);
}

swaplabel(row, dmbound, donames)
	register int row;
	int dmbound, donames;
{
	register int i, j;

	for (i = 0; i < nswdev; i++) {
D 7
		if (donames) {
			move(row, 5 + i * (1 + colwidth) + (colwidth - 3) / 2);
			printw("%s%d", devnames[major(swdevt[i].sw_dev)],
			    minor(swdevt[i].sw_dev) >> 3);
		}
		for (j = 0; j + 5 < colwidth; j += 5) {
			move(row + donames, 5 + i * (1 + colwidth) + j);
			printw("/%-2d  ", j);
		}
E 7
I 7
		if (donames)
			mvwprintw(wnd,
			    row, OFFSET + i*(1 + colwidth) + (colwidth - 3)/2,
			    "%s%d", devnames[major(swdevt[i].sw_dev)],
			        minor(swdevt[i].sw_dev) >> 3);
		for (j = 0; j + 5 < colwidth; j += 5)
			mvwprintw(wnd, row + donames,
			    OFFSET + i*(1 + colwidth) + j, "/%-2d  ", j);
E 7
	}
	row += 1 + donames;
	for (j = 0, i = dmmin; i <= dmbound; i *= 2, j++, row++) {
		int k;

D 7
		mvprintw(row, 0, "%4d|", i);
E 7
I 7
		mvwprintw(wnd, row, 0, "%4d|", i);
E 7
		for (k = 1; k < nswdev; k++)
D 7
			mvwaddch(wnd, row - 3, k * (1 + colwidth) - 1, '|');
E 7
I 7
			mvwaddch(wnd, row, OFFSET + k*(1 + colwidth) - 1, '|');
E 7
	}
	return (row);
E 5
E 3
E 2
}
E 1
