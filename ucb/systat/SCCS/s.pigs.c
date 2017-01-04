h64095
s 00000/00001/00242
d D 5.5 86/07/20 10:58:40 sam 13 12
c purge redundant include
e
s 00003/00003/00240
d D 5.4 85/12/11 16:08:07 bloom 12 11
c fix problem with losing /vmunix in the middle, a bit of lint cleanup
e
s 00004/00002/00239
d D 5.3 85/08/13 11:08:24 mckusick 11 10
c do not expand cpu percentages, only compress them
e
s 00022/00003/00219
d D 5.2 85/07/26 18:03:36 mckusick 10 9
c more accurate calculation of idle time
e
s 00011/00001/00211
d D 5.1 85/05/30 16:26:26 mckusick 9 8
c Add copyright
e
s 00000/00003/00212
d D 1.8 85/05/01 01:34:33 sam 8 7
c major rework; fixup netstat stuff; pull disk cmds into common file; change 
c everthing related to disks to use dk_ndrive and global selction; use getw where possible
e
s 00014/00020/00201
d D 1.7 85/04/29 00:42:58 sam 7 6
c cleanup window handling, use subwindows exclusively
e
s 00013/00000/00208
d D 1.6 84/08/09 19:13:01 mckusick 6 5
c update to new sources from sam; weed out unnecessary #includes
e
s 00004/00004/00204
d D 1.5 83/10/02 21:34:00 sam 5 4
c addjust window to display; expand user and process name fields
e
s 00043/00030/00165
d D 1.4 83/10/02 20:45:49 sam 4 3
c reorganize window management to allow display routines to set 
c up optimal window definitions
e
s 00014/00002/00181
d D 1.3 83/10/02 15:09:41 sam 3 2
c add some sanity checks
e
s 00015/00011/00168
d D 1.2 83/10/02 14:40:29 sam 2 1
c add init routine and mbuf display; redo swap space display
e
s 00179/00000/00000
d D 1.1 83/10/01 12:21:02 sam 1 0
c date and time created 83/10/01 12:21:02 by sam
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

/*
 * Pigs display from Bill Reeves at Lucasfilm
 */
E 9

#include "systat.h"
I 6
D 8
#include <sys/param.h>
E 8
#include <sys/dir.h>
#include <sys/time.h>
#include <sys/proc.h>
I 10
D 13
#include <sys/dk.h>
E 13
E 10
D 8
#include <sys/file.h>
#include <nlist.h>
E 8
#include <pwd.h>
E 6

I 4
WINDOW *
openpigs()
{
D 7
	static WINDOW *w = NULL;
E 7

D 7
	if (w == NULL)
D 5
		w = newwin(20, 70, 3, 5);
E 5
I 5
		w = newwin(20, 0, 3, 0);
E 5
        return (w);
E 7
I 7
	return (subwin(stdscr, LINES-5-1, 0, 5, 0));
E 7
}

closepigs(w)
	WINDOW *w;
{

	if (w == NULL)
		return;
D 7
	move(5, 20);
	clrtobot();
E 7
	wclear(w);
	wrefresh(w);
I 7
	delwin(w);
E 7
}
I 6

int	maxind;
int     factor;
float   total;
struct  passwd *getpwuid();
char    pidname[30];
I 10
long	stime[CPUSTATES];
double	idle;
E 10
E 6

E 4
showpigs()
{
        register short auid;
        register int i, j, y;
        register float max;
        register struct p_times *ptptr;
        struct p_times temppt;
        register struct users *knptr;
        char *getpname(), *pnamp;

I 4
	if (pt == NULL)
		return;
E 4
        /* Accumulate the percent of cpu per user. */
        ptptr = pt;
        numprocs = 0;
        total = 0.0;
        for (i = 0; i < nproc; i++) {
                /* discard inactive processes */
                if (ptptr->pt_uid == -1) {
                        ptptr++;
                        continue;
                }
                /* Accumulate the percentage. */
                total += ptptr->pt_pctcpu;
                numprocs++;
                ptptr++;
        }

D 10
        pt[numprocs].pt_pctcpu = 1.0 - total;
E 10
I 10
D 11
        pt[numprocs].pt_pctcpu = total / (1.0 - idle) * idle;
	total += pt[numprocs].pt_pctcpu;
E 11
I 11
        pt[numprocs].pt_pctcpu = idle;
	total += idle;
E 11
E 10
        pt[numprocs].pt_uid = -1;
        pt[numprocs].pt_pid = -1;
        pt[numprocs].pt_pp = NULL;

I 11
	if (total < 1.0)
		total = 1.0;
E 11
D 10
        if (total < 1.0)
                total = 1.0;
E 10
        factor = 50.0/total;

D 7
        /* Find the top ten by executing a "bubble pass" ten times. */
        y = numprocs + 1 < 15 ? numprocs + 1 : 15;
E 7
I 7
        /* Find the top few by executing a "bubble pass" ten times. */
	y = numprocs + 1;
	if (y > wnd->_maxy-1)
		y = wnd->_maxy-1;
E 7
        for (i = 0; i < y; i++) {
                ptptr = &pt[i];
                max = -10000.0;
                maxind = i;
                for (j = i; j < numprocs + 1; j++) {
                        if (ptptr->pt_pctcpu > max) {
                                max = ptptr->pt_pctcpu;
                                maxind = j;
                        }
                        ptptr++;
                }
                if (maxind != i) {
                        temppt = pt[i];
                        pt[i] = pt[maxind];
                        pt[maxind] = temppt;
                }
        }
D 7

        /* Display the top fifteen. */
        y = 4;
E 7
I 7
        y = 1;
E 7
        ptptr = pt;
D 7
        i = numprocs+1 < 15 ? numprocs+1 : 15;
E 7
I 7
	i = numprocs + 1;
	if (i > wnd->_maxy-1)
		i = wnd->_maxy-1;
E 7
        for (; i > 0 && ptptr->pt_pctcpu > 0.01; i--) {
                /* Find the user's name. */
                knptr = known;
                auid = ptptr->pt_uid;
                for (j = numknown - 1; j >= 0; j--) {
                        if (knptr->k_uid == auid) {
                                namp = knptr->k_name;
                                break;
                        }
                        knptr++;
                }
                if (j < 0) {
                        if (numknown < 30) {
                                knptr = &known[numknown];
                                namp = strncpy(knptr->k_name,
                                    getpwuid(auid)->pw_name, 15);
                                knptr->k_name[15] = '\0';
                                knptr->k_uid = auid;
                                numknown++;
                        } else
                                namp = getpwuid(auid)-> pw_name;
                }
                pnamp = getpname(ptptr->pt_pid, ptptr->pt_pp);
                wmove(wnd, y, 0);
                wclrtoeol(wnd);
                mvwaddstr(wnd, y, 0, namp);
D 5
                sprintf(pidname, "%8.8s", pnamp);
                mvwaddstr(wnd, y, 6, pidname);
                wmove(wnd, y++, 15);
E 5
I 5
                sprintf(pidname, "%10.10s", pnamp);
                mvwaddstr(wnd, y, 9, pidname);
                wmove(wnd, y++, 20);
E 5
                for (j = ptptr->pt_pctcpu*factor + 0.5; j > 0; j--)
                        waddch(wnd, 'X');
                ptptr++;
        }
D 7

        while (y < 19) {
                wmove(wnd, y++, 0);
                wclrtoeol(wnd);
        }
E 7
I 7
	wmove(wnd, y, 0); wclrtobot(wnd);
E 7
}

D 4
openpigs()
{

        kmemf = "/dev/kmem";
        kmem = open(kmemf, 0);
        if (kmem < 0) {
                perror(kmemf);
                exit(1);
        }
        memf = "/dev/mem";
        mem = open(memf, 0);
        if (mem < 0) {
                perror(memf);
                exit(1);
        }
        swapf = "/dev/drum";
        swap = open(swapf, 0);
        if (swap < 0) {
                perror(swapf);
                exit(1);
        }
}

/* these don't belong here */
E 4
I 4
static struct nlist nlst[] = {
E 4
#define X_PROC          0
I 4
        { "_proc" },
E 4
#define X_NPROC         1
D 4
#define X_USRPTMAP      4
#define X_USRPT         5
E 4
I 4
        { "_nproc" },
#define X_USRPTMAP      2
        { "_Usrptmap" },
#define X_USRPT         3
        { "_usrpt" },
I 10
#define X_CPTIME	4
	{ "_cp_time" },
E 10
        { "" }
};
E 4

D 4
struct proc *kprocp;

E 4
D 2
fetchpigs()
E 2
I 2
initpigs()
E 2
{
D 2
        register int i;
        register struct p_times *prt;
        register float time;
        register struct proc *pp;
E 2

I 4
	if (nlst[X_PROC].n_type == 0) {
		nlist("/vmunix", nlst);
		if (nlst[X_PROC].n_type == 0) {
			error("namelist on /vmunix failed");
D 12
			return;
E 12
I 12
			return(0);
E 12
		}
	}
E 4
        if (procp == NULL) {
                procp = getw(nlst[X_PROC].n_value);
                nproc = getw(nlst[X_NPROC].n_value);
D 3
                kprocp = (struct proc *)malloc(sizeof (*kprocp) * nproc);
E 3
        }
I 3
	if (kprocp == NULL)
                kprocp = (struct proc *)calloc(nproc, sizeof (struct proc));
E 3
D 2
        if (usrpt == NULL) {
                usrpt = (struct pte *)nlst[X_USRPT].n_value;
                Usrptma = (struct pte *)nlst[X_USRPTMAP].n_value;
                pt = (struct p_times *)malloc(nproc * sizeof (struct p_times));
                return;
        }
E 2
I 2
        if (usrpt != NULL)
D 12
		return;
E 12
I 12
		return(1);
E 12
	usrpt = (struct pte *)nlst[X_USRPT].n_value;
	Usrptma = (struct pte *)nlst[X_USRPTMAP].n_value;
D 3
	pt = (struct p_times *)malloc(nproc * sizeof (struct p_times));
E 3
I 3
	if (pt == NULL)
		pt = (struct p_times *)calloc(nproc, sizeof (struct p_times));
I 10
	lseek(kmem, (long)nlst[X_CPTIME].n_value, L_SET);
	read(kmem, stime, sizeof stime);
I 12
	return(1);
E 12
E 10
E 3
}

fetchpigs()
{
        register int i;
        register struct p_times *prt;
        register float time;
        register struct proc *pp;
I 10
	long ctime[CPUSTATES];
D 12
	char buf[25];
E 12
	double t;
E 10

I 4
	if (nlst[X_PROC].n_type == 0)
		return;
E 4
I 3
	if (kprocp == NULL) {
		kprocp = (struct proc *)calloc(nproc, sizeof (struct proc));
		if (kprocp == NULL)
			return;
	}
	if (pt == NULL) {
		pt = (struct p_times *)calloc(nproc, sizeof (struct p_times));
		if (pt == NULL)
			return;
	}
E 3
E 2
        prt = pt;
        lseek(kmem, procp, L_SET);
        read(kmem, kprocp, sizeof (struct proc) * nproc);
        for (i = 0, pp = kprocp; i < nproc; i++, pp++) {
                time = pp->p_time;
                if (time == 0 || (pp->p_flag & SLOAD) == 0)
                        continue;
                prt->pt_pid = pp->p_pid;
                prt->pt_pp = pp;
                prt->pt_pctcpu = pp->p_pctcpu / (1.0 - exp(time * lccpu));
                prt->pt_uid = pp->p_uid;
                prt++;
        }
        for (; prt < &pt[nproc]; prt++)
                prt->pt_uid = -1;
I 10
	lseek(kmem, (long)nlst[X_CPTIME].n_value, L_SET);
	read(kmem, ctime, sizeof ctime);
	t = 0;
	for (i = 0; i < CPUSTATES; i++)
		t += ctime[i] - stime[i];
	if (t == 0.0)
		t = 1.0;
	idle = (ctime[CP_IDLE] - stime[CP_IDLE]) / t;
	for (i = 0; i < CPUSTATES; i++)
		stime[i] = ctime[i];
E 10
}

labelpigs()
{

D 4
        move(5, 0);
        clrtoeol();
E 4
I 4
D 7
        move(5, 0); clrtoeol();
E 4
        mvaddstr(5, 20,
E 7
I 7
	wmove(wnd, 0, 0); wclrtoeol(wnd);
        mvwaddstr(wnd, 0, 20,
E 7
                "/0   /10  /20  /30  /40  /50  /60  /70  /80  /90  /100");
}
E 1
