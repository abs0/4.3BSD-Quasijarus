h21641
s 00006/00002/00337
d D 5.3 86/01/12 15:26:24 sam 11 10
c add tahoe
e
s 00004/00005/00335
d D 5.2 85/12/11 16:07:34 bloom 10 9
c fix problem with losing /vmunix in the middle, a bit of lint cleanup
e
s 00007/00001/00333
d D 5.1 85/05/30 16:21:38 mckusick 9 8
c Add copyright
e
s 00034/00068/00300
d D 1.8 85/05/01 01:33:29 sam 8 7
c major rework; fixup netstat stuff; pull disk cmds into common file; change 
c everthing related to disks to use dk_ndrive and global selction; use getw where possible
e
s 00031/00038/00337
d D 1.7 85/04/29 00:42:39 sam 7 6
c cleanup window handling, use subwindows exclusively
e
s 00002/00012/00373
d D 1.6 85/04/28 00:37:13 sam 6 5
c add vsta in; add help command (minimal); make loadav display something 
c which can be turned off
e
s 00001/00001/00384
d D 1.5 84/08/09 19:27:33 mckusick 5 4
c msps defaults to off
e
s 00316/00253/00069
d D 1.4 84/08/09 19:13:31 mckusick 4 3
c update to new sources from sam; weed out unnecessary #includes
e
s 00001/00001/00321
d D 1.3 83/10/02 23:31:54 sam 3 2
c oops
e
s 00012/00008/00310
d D 1.2 83/10/02 22:37:58 sam 2 1
c scale cpu state display 
e
s 00318/00000/00000
d D 1.1 83/10/02 21:41:04 sam 1 0
c date and time created 83/10/02 21:41:04 by sam
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
static char sccsid[] = "%W% (Lucasfilm) %G%";
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
E 7
D 9
#endif
E 9
I 9
#endif not lint
E 9

/*
 * iostat
 */
#include "systat.h"
D 4

E 4
I 4
D 8
#include <sys/param.h>
E 8
E 4
#include <sys/buf.h>
D 4
#include <sys/dk.h>
#ifdef vax
#include <vaxuba/ubavar.h>
#include <vaxmba/mbavar.h>
#endif
#ifdef sun
#include <sundev/mbvar.h>
#endif
E 4
I 4
D 8
#include <sys/file.h>
#include <nlist.h>
E 8
E 4

I 4
D 7
#define WBASEROW        4
#define WBASECOL        5

E 7
E 4
WINDOW *
openiostat()
{
D 4
	static WINDOW *w = NULL;
E 4
I 4
D 7
        static WINDOW *w = NULL;
E 7
E 4

D 7
        if (w == NULL)
D 2
		w = newwin(20, 70, 3, 5);
E 2
I 2
D 4
		w = newwin(20, 70, 4, 5);
E 2
	return (w);
E 4
I 4
                w = newwin(LINES - 1 - WBASEROW, 0, WBASEROW, WBASECOL);
        return (w);
E 7
I 7
	return (subwin(stdscr, LINES-1-5, 0, 5, 0));
E 7
E 4
}

closeiostat(w)
D 4
	WINDOW *w;
E 4
I 4
        WINDOW *w;
E 4
{

D 4
	if (w == NULL)
		return;
	move(5, 0);
	clrtobot();
	wclear(w);
	wrefresh(w);
E 4
I 4
        if (w == NULL)
                return;
D 7
        move(WBASEROW, 0);
        clrtobot();
E 7
        wclear(w);
        wrefresh(w);
I 7
	delwin(w);
E 7
E 4
}

static struct nlist nlst[] = {
D 4
#define	X_DK_BUSY	0
	{ "_dk_busy" },
#define	X_DK_TIME	1
	{ "_dk_time" },
#define	X_DK_XFER	2
	{ "_dk_xfer" },
#define	X_DK_WDS	3
	{ "_dk_wds" },
#define	X_DK_SEEK	4
	{ "_dk_seek" },
#define	X_CP_TIME	5
	{ "_cp_time" },
#define	X_DK_MSPW	6
	{ "_dk_mspw" },
#define	X_HZ		7
	{ "_hz" },

E 4
I 4
#define X_DK_BUSY       0
        { "_dk_busy" },
#define X_DK_TIME       1
        { "_dk_time" },
#define X_DK_XFER       2
        { "_dk_xfer" },
#define X_DK_WDS        3
        { "_dk_wds" },
#define X_DK_SEEK       4
        { "_dk_seek" },
#define X_CP_TIME       5
        { "_cp_time" },
D 6
#define X_DK_MSPW       6
        { "_dk_mspw" },
#define X_HZ            7
        { "_hz" },
E 6
E 4
#ifdef vax
D 4
#define X_MBDINIT	8
	{ "_mbdinit" },
#define X_UBDINIT	9
	{ "_ubdinit" },
E 4
I 4
D 6
#define X_MBDINIT       8
E 6
I 6
D 11
#define X_MBDINIT       6
E 11
I 11
#define X_MBDINIT       (X_CP_TIME+1)
E 11
E 6
        { "_mbdinit" },
D 6
#define X_UBDINIT       9
E 6
I 6
D 11
#define X_UBDINIT       7
E 11
I 11
#define X_UBDINIT       (X_CP_TIME+2)
E 11
E 6
        { "_ubdinit" },
I 11
#endif
#ifdef tahoe
#define	X_VBDINIT	(X_CP_TIME+1)
	{ "_vbdinit" },
E 11
E 4
#endif
D 4
#ifdef sun
#define X_MBDINIT	8
	{ "_mbdinit" },
#endif
	{ "" },
E 4
I 4
        { "" },
E 4
};

D 4
char dr_name[DK_NDRIVE][10];

struct {
	int	dk_busy;
	long	cp_time[CPUSTATES];
	long	dk_time[DK_NDRIVE];
	long	dk_wds[DK_NDRIVE];
	long	dk_seek[DK_NDRIVE];
	long	dk_xfer[DK_NDRIVE];
	float	dk_mspw[DK_NDRIVE];
E 4
I 4
static struct {
        int     dk_busy;
        long    cp_time[CPUSTATES];
D 8
        long    dk_time[DK_NDRIVE];
        long    dk_wds[DK_NDRIVE];
        long    dk_seek[DK_NDRIVE];
        long    dk_xfer[DK_NDRIVE];
E 8
I 8
        long    *dk_time;
        long    *dk_wds;
        long    *dk_seek;
        long    *dk_xfer;
E 8
E 4
} s, s1;

D 4
int	kmem;
int	hz;
double	etime;
E 4
I 4
static  int linesperregion;
static  double etime;
static  int numbers = 0;                /* default display bar graphs */
D 5
static  int msps = 1;                   /* default ms/seek shown */
E 5
I 5
static  int msps = 0;                   /* default ms/seek shown */
E 5
D 8
static  int dk_select[DK_NDRIVE];
E 8
E 4

initiostat()
{
D 4
	register  i;
E 4
I 4
D 10
        register  i;
E 10
E 4

D 4
	if (nlst[X_DK_BUSY].n_type == 0) {
		nlist("/vmunix", nlst);
		if (nlst[X_DK_BUSY].n_type == 0) {
			error("Disk init information isn't in namelist");
			return;
		}
	}
	lseek(kmem, (long)nlst[X_DK_MSPW].n_value, L_SET);
	read(kmem, s.dk_mspw, sizeof s.dk_mspw);
	for (i = 0; i < DK_NDRIVE; i++)
		sprintf(dr_name[i], "dk%d", i);
	lseek(kmem, (long)nlst[X_DK_MSPW].n_value, L_SET);
	read(kmem, s.dk_mspw, sizeof s.dk_mspw);
	lseek(kmem, (long)nlst[X_HZ].n_value, L_SET);
	read(kmem, &hz, sizeof hz);
	read_names();
}
E 4
I 4
        if (nlst[X_DK_BUSY].n_type == 0) {
                nlist("/vmunix", nlst);
                if (nlst[X_DK_BUSY].n_type == 0) {
                        error("Disk init information isn't in namelist");
D 10
                        return;
E 10
I 10
                        return(0);
E 10
                }
        }
D 8
        if (ndrives == 0) {
D 6
                lseek(kmem, (long)nlst[X_DK_MSPW].n_value, L_SET);
                read(kmem, dk_mspw, sizeof (dk_mspw));
E 6
                for (i = 0; i < DK_NDRIVE; i++)
                        if (dk_mspw[i] != 0.0)
                                sprintf(dr_name[i], "dk%d", i), ndrives++;
#ifdef vax
                read_names(nlst[X_MBDINIT].n_value, nlst[X_UBDINIT].n_value);
#endif
D 6
        }
        if (hz == 0) {
                lseek(kmem, (long)nlst[X_HZ].n_value, L_SET);
                read(kmem, &hz, sizeof hz);
E 6
        }
        for (i = 0; i < DK_NDRIVE; i++)
                dk_select[i] = 1;
E 8
I 8
D 10
	dkinit();
E 10
I 10
	if (! dkinit())
		return(0);
E 10
	if (dk_ndrive) {
#define	allocate(e, t) \
    s./**/e = (t *)calloc(dk_ndrive, sizeof (t)); \
    s1./**/e = (t *)calloc(dk_ndrive, sizeof (t));
		allocate(dk_time, long);
		allocate(dk_wds, long);
		allocate(dk_seek, long);
		allocate(dk_xfer, long);
#undef allocate
	}
I 10
	return(1);
E 10
E 8
}
E 4

fetchiostat()
{

D 4
	if (nlst[X_DK_BUSY].n_type == 0)
		return;
	lseek(kmem, (long)nlst[X_DK_BUSY].n_value, L_SET);
 	read(kmem, &s.dk_busy, sizeof s.dk_busy);
 	lseek(kmem, (long)nlst[X_DK_TIME].n_value, L_SET);
 	read(kmem, s.dk_time, sizeof s.dk_time);
 	lseek(kmem, (long)nlst[X_DK_XFER].n_value, L_SET);
 	read(kmem, s.dk_xfer, sizeof s.dk_xfer);
 	lseek(kmem, (long)nlst[X_DK_WDS].n_value, L_SET);
 	read(kmem, s.dk_wds, sizeof s.dk_wds);
	lseek(kmem, (long)nlst[X_DK_SEEK].n_value, L_SET);
	read(kmem, s.dk_seek, sizeof s.dk_seek);
	lseek(kmem, (long)nlst[X_CP_TIME].n_value, L_SET);
	read(kmem, s.cp_time, sizeof s.cp_time);
E 4
I 4
        if (nlst[X_DK_BUSY].n_type == 0)
                return;
D 8
        lseek(kmem, (long)nlst[X_DK_BUSY].n_value, L_SET);
        read(kmem, &s.dk_busy, sizeof s.dk_busy);
E 8
I 8
	s.dk_busy = getw(nlst[X_DK_BUSY].n_value);
E 8
        lseek(kmem, (long)nlst[X_DK_TIME].n_value, L_SET);
D 8
        read(kmem, s.dk_time, sizeof s.dk_time);
E 8
I 8
        read(kmem, s.dk_time, dk_ndrive * sizeof (long));
E 8
        lseek(kmem, (long)nlst[X_DK_XFER].n_value, L_SET);
D 8
        read(kmem, s.dk_xfer, sizeof s.dk_xfer);
E 8
I 8
        read(kmem, s.dk_xfer, dk_ndrive * sizeof (long));
E 8
        lseek(kmem, (long)nlst[X_DK_WDS].n_value, L_SET);
D 8
        read(kmem, s.dk_wds, sizeof s.dk_wds);
E 8
I 8
        read(kmem, s.dk_wds, dk_ndrive * sizeof (long));
E 8
        lseek(kmem, (long)nlst[X_DK_SEEK].n_value, L_SET);
D 8
        read(kmem, s.dk_seek, sizeof s.dk_seek);
E 8
I 8
        read(kmem, s.dk_seek, dk_ndrive * sizeof (long));
E 8
        lseek(kmem, (long)nlst[X_CP_TIME].n_value, L_SET);
        read(kmem, s.cp_time, sizeof s.cp_time);
E 4
}

I 7
#define	INSET	10

E 7
labeliostat()
{
D 4
	register int i, row;
E 4
I 4
        int row;
E 4

D 4
	if (nlst[X_DK_BUSY].n_type == 0) {
		error("No dk_busy defined.");
		return;
	}
	row = 5;
I 2
	move(row, 0); clrtoeol();
	mvaddstr(row++, 10,
E 4
I 4
        if (nlst[X_DK_BUSY].n_type == 0) {
                error("No dk_busy defined.");
                return;
        }
D 7
        row = WBASEROW + 1;
        move(row, 0); clrtobot();
        mvaddstr(row++, WBASECOL + 5, 
E 7
I 7
        row = 0;
        wmove(wnd, row, 0); wclrtobot(wnd);
        mvwaddstr(wnd, row++, INSET, 
E 7
E 4
            "/0   /10  /20  /30  /40  /50  /60  /70  /80  /90  /100");
E 2
D 4
	mvaddstr(row++, 0, "cpu  user|"); clrtoeol();
	mvaddstr(row++, 0, "     nice|"); clrtoeol();
	mvaddstr(row++, 0, "   system|"); clrtoeol();
	mvaddstr(row++, 0, "     idle|"); clrtoeol();
	row++;
	for (i = 0; i < DK_NDRIVE; i++)
		if (s.dk_mspw[i] != 0.0) {
			mvprintw(row++, 0, "%3.3s   bps|", dr_name[i]);
			clrtoeol();
			mvaddstr(row++, 0, "      tps|"); clrtoeol();
			mvaddstr(row++, 0, "      mps|"); clrtoeol();
		}
E 4
I 4
D 7
        mvaddstr(row++, 0, "cpu  user|");
        mvaddstr(row++, 0, "     nice|");
        mvaddstr(row++, 0, "   system|");
        mvaddstr(row++, 0, "     idle|");
E 7
I 7
        mvwaddstr(wnd, row++, 0, "cpu  user|");
        mvwaddstr(wnd, row++, 0, "     nice|");
        mvwaddstr(wnd, row++, 0, "   system|");
        mvwaddstr(wnd, row++, 0, "     idle|");
E 7
        if (numbers)
                row = numlabels(row + 1);
        else
                row = barlabels(row + 1);
E 4
}

I 4
static
numlabels(row)
{
D 8
        int i, col, regions;
E 8
I 8
        int i, col, regions, ndrives;
E 8

#define COLWIDTH        14
D 7
#define DRIVESPERLINE   ((COLS - WBASECOL) / COLWIDTH)
E 7
I 7
#define DRIVESPERLINE   ((wnd->_maxx - INSET) / COLWIDTH)
I 8
	for (ndrives = 0, i = 0; i < dk_ndrive; i++)
		if (dk_select[i])
			ndrives++;
E 8
E 7
        regions = howmany(ndrives, DRIVESPERLINE);
        /*
         * Deduct -regions for blank line after each scrolling region.
         */
D 7
        linesperregion = (CMDLINE - row - regions) / regions;
E 7
I 7
        linesperregion = (wnd->_maxy - row - regions) / regions;
E 7
        /*
         * Minimum region contains space for two
         * label lines and one line of statistics.
         */
        if (linesperregion < 3)
                linesperregion = 3;
        col = 0;
D 8
        for (i = 0; i < DK_NDRIVE; i++)
E 8
I 8
        for (i = 0; i < dk_ndrive; i++)
E 8
                if (dk_select[i] && dk_mspw[i] != 0.0) {
D 7
                        if (col + COLWIDTH >= COLS - WBASECOL) {
E 7
I 7
                        if (col + COLWIDTH >= wnd->_maxx - INSET) {
E 7
                                col = 0, row += linesperregion + 1;
D 7
                                if (row > CMDLINE - (linesperregion + 1))
E 7
I 7
                                if (row > wnd->_maxy - (linesperregion + 1))
E 7
                                        break;
                        }
D 7
                        mvwaddstr(wnd, row - WBASEROW, col + 4, dr_name[i]);
                        mvwaddstr(wnd, row + 1 - WBASEROW, col, "bps tps msps");
E 7
I 7
                        mvwaddstr(wnd, row, col + 4, dr_name[i]);
                        mvwaddstr(wnd, row + 1, col, "bps tps msps");
E 7
                        col += COLWIDTH;
                }
        if (col)
                row += linesperregion + 1;
        return (row);
}

static
barlabels(row)
        int row;
{
        int i;

D 7
        mvaddstr(row++, 10,
E 7
I 7
        mvwaddstr(wnd, row++, INSET,
E 7
            "/0   /5   /10  /15  /20  /25  /30  /35  /40  /45  /50");
        linesperregion = 2 + msps;
D 8
        for (i = 0; i < DK_NDRIVE; i++)
E 8
I 8
        for (i = 0; i < dk_ndrive; i++)
E 8
                if (dk_select[i] && dk_mspw[i] != 0.0) {
D 7
                        if (row > CMDLINE - linesperregion)
E 7
I 7
                        if (row > wnd->_maxy - linesperregion)
E 7
                                break;
D 7
                        mvprintw(row++, 0, "%3.3s   bps|", dr_name[i]);
                        mvaddstr(row++, 0, "      tps|");
E 7
I 7
                        mvwprintw(wnd, row++, 0, "%3.3s   bps|", dr_name[i]);
                        mvwaddstr(wnd, row++, 0, "      tps|");
E 7
                        if (msps)
D 7
                                mvaddstr(row++, 0, "     msps|");
E 7
I 7
                                mvwaddstr(wnd, row++, 0, "     msps|");
E 7
                }
        return (row);
}

E 4
showiostat()
{
D 4
	register int i;
	register long t;
	int row;
E 4
I 4
        register int i, row, col;
        register long t;
E 4

D 4
	if (nlst[X_DK_BUSY].n_type == 0)
		return;
	for (i = 0; i < DK_NDRIVE; i++) {
#define X(fld)	t = s.fld[i]; s.fld[i] -= s1.fld[i]; s1.fld[i] = t
		X(dk_xfer); X(dk_seek); X(dk_wds); X(dk_time);
	}
	etime = 0;
	for(i = 0; i < CPUSTATES; i++) {
		X(cp_time);
		etime += s.cp_time[i];
	}
	if (etime == 0.0)
		etime = 1.0;
	etime /= (float) hz;
	row = 2;
	for (i = 0; i < CPUSTATES; i++)
		stat1(row++, i);
	row++;
	for (i = 0; i < DK_NDRIVE; i++)
		if (s.dk_mspw[i] != 0.0)
			row = stats(row, i);
}
E 4
I 4
        if (nlst[X_DK_BUSY].n_type == 0)
                return;
D 8
        for (i = 0; i < DK_NDRIVE; i++) {
E 8
I 8
        for (i = 0; i < dk_ndrive; i++) {
E 8
#define X(fld)  t = s.fld[i]; s.fld[i] -= s1.fld[i]; s1.fld[i] = t
                X(dk_xfer); X(dk_seek); X(dk_wds); X(dk_time);
        }
        etime = 0;
        for(i = 0; i < CPUSTATES; i++) {
                X(cp_time);
                etime += s.cp_time[i];
        }
        if (etime == 0.0)
                etime = 1.0;
        etime /= (float) hz;
D 7
        row = 2;
E 7
I 7
        row = 1;
E 7
        for (i = 0; i < CPUSTATES; i++)
                stat1(row++, i);
        if (!numbers) {
                row += 2;
D 8
                for (i = 0; i < DK_NDRIVE; i++)
E 8
I 8
                for (i = 0; i < dk_ndrive; i++)
E 8
                        if (dk_select[i] && dk_mspw[i] != 0.0) {
D 7
                                if (row > CMDLINE - linesperregion - WBASEROW)
E 7
I 7
                                if (row > wnd->_maxy - linesperregion)
E 7
                                        break;
D 7
                                row = stats(row, 10 - WBASECOL, i);
E 7
I 7
                                row = stats(row, INSET, i);
E 7
                        }
                return;
        }
        col = 0;
        wmove(wnd, row + linesperregion, 0);
        wdeleteln(wnd);
        wmove(wnd, row + 3, 0);
        winsertln(wnd);
D 8
        for (i = 0; i < DK_NDRIVE; i++)
E 8
I 8
        for (i = 0; i < dk_ndrive; i++)
E 8
                if (dk_select[i] && dk_mspw[i] != 0.0) {
D 7
                        if (col + COLWIDTH >= COLS - WBASECOL) {
E 7
I 7
                        if (col + COLWIDTH >= wnd->_maxx) {
E 7
                                col = 0, row += linesperregion + 1;
D 7
                                if (row + WBASEROW >
                                    CMDLINE - (linesperregion + 1))
E 7
I 7
                                if (row > wnd->_maxy - (linesperregion + 1))
E 7
                                        break;
                                wmove(wnd, row + linesperregion, 0);
                                wdeleteln(wnd);
                                wmove(wnd, row + 3, 0);
                                winsertln(wnd);
                        }
                        (void) stats(row + 3, col, i);
                        col += COLWIDTH;
                }
}
E 4

D 4
stats(row, dn)
	int row, dn;
E 4
I 4
static
stats(row, col, dn)
        int row, dn;
E 4
{
D 4
	register i;
	double atime, words, xtime, itime;
E 4
I 4
D 10
        register i;
E 10
        double atime, words, xtime, itime;
E 4

D 4
	if (s.dk_mspw[dn] == 0.0) {
		wmove(wnd, row++, 5); wclrtoeol(wnd);
		wmove(wnd, row++, 5); wclrtoeol(wnd);
		wmove(wnd, row++, 5); wclrtoeol(wnd);
		return (row);
	}
	atime = s.dk_time[dn];
	atime /= (float) hz;
	words = s.dk_wds[dn]*32.0;	/* number of words transferred */
	xtime = s.dk_mspw[dn]*words;	/* transfer time */
	itime = atime - xtime;		/* time not transferring */
	if (xtime < 0)
		itime += xtime, xtime = 0;
	if (itime < 0)
		xtime += itime, itime = 0;
D 2
	wmove(wnd, row++, 5); histogram(words / 512 / etime, 60, 'X');
	wmove(wnd, row++, 5); histogram(s.dk_xfer[dn] / etime, 60, 'X');
E 2
I 2
	wmove(wnd, row++, 5); histogram(words / 512 / etime, 60, 1.0, 'X');
	wmove(wnd, row++, 5); histogram(s.dk_xfer[dn] / etime, 60, 1.0, 'X');
E 2
	wmove(wnd, row++, 5); histogram(s.dk_seek[dn] ?
D 2
	    itime * 1000. / s.dk_seek[dn] : 0, 60, 'X');
E 2
I 2
	    itime * 1000. / s.dk_seek[dn] : 0, 60, 1.0, 'X');
E 2
	return (row);
E 4
I 4
        atime = s.dk_time[dn];
        atime /= (float) hz;
        words = s.dk_wds[dn]*32.0;      /* number of words transferred */
        xtime = dk_mspw[dn]*words;      /* transfer time */
        itime = atime - xtime;          /* time not transferring */
        if (xtime < 0)
                itime += xtime, xtime = 0;
        if (itime < 0)
                xtime += itime, itime = 0;
        if (numbers) {
                mvwprintw(wnd, row, col, "%3.0f%4.0f%5.1f",
                    words / 512 / etime, s.dk_xfer[dn] / etime,
                    s.dk_seek[dn] ? itime * 1000. / s.dk_seek[dn] : 0.0);
                return (row);
        }
        wmove(wnd, row++, col);
        histogram(words / 512 / etime, 50, 1.0);
        wmove(wnd, row++, col);
        histogram(s.dk_xfer[dn] / etime, 50, 1.0);
        if (msps) {
                wmove(wnd, row++, col);
                histogram(s.dk_seek[dn] ? itime * 1000. / s.dk_seek[dn] : 0,
                   50, 1.0);
        }
        return (row);
E 4
}

I 4
static
E 4
stat1(row, o)
D 4
	int row, o;
E 4
I 4
        int row, o;
E 4
{
D 4
	register i;
	double time;
E 4
I 4
        register i;
        double time;
E 4

D 4
	time = 0;
	for (i = 0; i < CPUSTATES; i++)
		time += s.cp_time[i];
	if (time == 0.0)
		time = 1.0;
D 2
	wmove(wnd, row, 5); histogram(100*s.cp_time[o] / time, 60, 'X');
E 2
I 2
	wmove(wnd, row, 5); histogram(100*s.cp_time[o] / time, 60, 0.5, 'X');
E 4
I 4
        time = 0;
        for (i = 0; i < CPUSTATES; i++)
                time += s.cp_time[i];
        if (time == 0.0)
                time = 1.0;
D 7
        wmove(wnd, row, 5);
E 7
I 7
        wmove(wnd, row, INSET);
E 7
#define CPUSCALE        0.5
        histogram(100 * s.cp_time[o] / time, 50, CPUSCALE);
E 4
E 2
}

D 2
histogram(val, colwidth, c)
E 2
I 2
D 4
histogram(val, colwidth, scale, c)
E 2
	double val;
	int colwidth;
I 2
	double scale;
E 2
	char c;
E 4
I 4
histogram(val, colwidth, scale)
        double val;
        int colwidth;
        double scale;
E 4
{
D 4
	char buf[10];
	register int k;
D 2
	register int v = (int)(val + 0.5);
E 2
I 2
	register int v = (int)(val * scale) + 0.5;
E 4
I 4
        char buf[10];
        register int k;
        register int v = (int)(val * scale) + 0.5;
E 4
E 2

D 4
	k = MIN(v, colwidth);
	if (v > colwidth) {
D 2
		sprintf(buf, " %d", v);
E 2
I 2
D 3
		sprintf(buf, "%4.1f", v);
E 3
I 3
		sprintf(buf, "%4.1f", val);
E 3
E 2
		k -= strlen(buf);
		while (k--)
			waddch(wnd, c);
		waddstr(wnd, buf);
		return;
	}
	while (k--)
		waddch(wnd, c);
	wclrtoeol(wnd);
E 4
I 4
        k = MIN(v, colwidth);
        if (v > colwidth) {
                sprintf(buf, "%4.1f", val);
                k -= strlen(buf);
                while (k--)
                        waddch(wnd, 'X');
                waddstr(wnd, buf);
                return;
        }
        while (k--)
                waddch(wnd, 'X');
        wclrtoeol(wnd);
E 4
}

D 4
#define steal(where, var) \
	lseek(kmem, where, L_SET); read(kmem, &var, sizeof var);

#ifdef vax
read_names()
E 4
I 4
cmdiostat(cmd, args)
        char *cmd, *args;
E 4
{
D 4
	struct mba_device mdev;
	register struct mba_device *mp;
	struct mba_driver mdrv;
	short two_char;
	char *cp = (char *) &two_char;
	struct uba_device udev, *up;
	struct uba_driver udrv;
E 4
I 4
D 10
        int i;
E 10
E 4

D 4
	mp = (struct mba_device *) nlst[X_MBDINIT].n_value;
	up = (struct uba_device *) nlst[X_UBDINIT].n_value;
	if (up == 0) {
		error("Disk init info not in namelist\n");
		return;
	}
	if (mp) for (;;) {
		steal(mp++, mdev);
		if (mdev.mi_driver == 0)
			break;
		if (mdev.mi_dk < 0 || mdev.mi_alive == 0)
			continue;
		steal(mdev.mi_driver, mdrv);
		steal(mdrv.md_dname, two_char);
		sprintf(dr_name[mdev.mi_dk], "%c%c%d",
		    cp[0], cp[1], mdev.mi_unit);
	}
	if (up) for (;;) {
		steal(up++, udev);
		if (udev.ui_driver == 0)
			break;
		if (udev.ui_dk < 0 || udev.ui_alive == 0)
			continue;
		steal(udev.ui_driver, udrv);
		steal(udrv.ud_dname, two_char);
		sprintf(dr_name[udev.ui_dk], "%c%c%d",
		    cp[0], cp[1], udev.ui_unit);
	}
E 4
I 4
D 8
        if (prefix(cmd, "msps")) {
E 8
I 8
        if (prefix(cmd, "msps"))
E 8
                msps = !msps;
D 8
                goto fixdisplay;
        }
        if (prefix(cmd, "numbers")) {
E 8
I 8
	else if (prefix(cmd, "numbers"))
E 8
                numbers = 1;
D 8
                goto fixdisplay;
        }
        if (prefix(cmd, "bars")) {
E 8
I 8
	else if (prefix(cmd, "bars"))
E 8
                numbers = 0;
D 8
                goto fixdisplay;
        }
D 7
        if (prefix(cmd, "display")) {
E 7
I 7
        if (prefix(cmd, "display") || prefix(cmd, "add")) {
E 7
                dkselect(args, 1, dk_select);
                goto fixdisplay;
        }
D 7
        if (prefix(cmd, "ignore")) {
E 7
I 7
        if (prefix(cmd, "ignore") || prefix(cmd, "delete")) {
E 7
                dkselect(args, 0, dk_select);
                goto fixdisplay;
        }
        if (prefix(cmd, "drives")) {
                move(CMDLINE, 0);
                for (i = 0; i < DK_NDRIVE; i++)
                        if (dk_mspw[i] != 0.0)
                                printw("%s ", dr_name[i]);
                return (1);
        }
        return (0);
fixdisplay:
E 8
I 8
	else if (!dkcmd(cmd, args))
		return (0);
E 8
        wclear(wnd);
D 7
        wrefresh(wnd);
E 7
        labeliostat();
        refresh();
        return (1);
E 4
D 8
}
D 4
#endif
E 4

D 4
#ifdef sun
read_names()
E 4
I 4
prefix(s1, s2)
        register char *s1, *s2;
E 4
{
D 4
	struct mb_device mdev;
	register struct mb_device *mp;
	struct mb_driver mdrv;
	short two_char;
	char *cp = (char *) &two_char;
E 4

D 4
	mp = (struct mb_device *) nlst[X_MBDINIT].n_value;
	if (mp == 0) {
		error("Disk init info not in namelist\n");
		return;
	}
	for (;;) {
		steal(mp++, mdev);
		if (mdev.md_driver == 0)
			break;
		if (mdev.md_dk < 0 || mdev.md_alive == 0)
			continue;
		steal(mdev.md_driver, mdrv);
		steal(mdrv.mdr_dname, two_char);
		sprintf(dr_name[mdev.md_dk], "%c%c%d",
		    cp[0], cp[1], mdev.md_unit);
	}
E 4
I 4
        while (*s1 == *s2) {
                if (*s1 == '\0')
                        return (1);
                s1++, s2++;
        }
        return (*s1 == '\0');
E 8
E 4
}
D 4
#endif
E 4
E 1
