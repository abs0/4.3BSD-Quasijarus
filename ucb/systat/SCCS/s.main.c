h25932
s 00002/00002/00215
d D 5.3 87/03/26 00:30:34 tef 12 11
c Get the right args on the command line; allow naptimes < 5 seconds.
e
s 00002/00001/00215
d D 5.2 85/08/13 11:08:57 mckusick 11 10
c let curses handle SIGTSTP
e
s 00013/00001/00203
d D 5.1 85/05/30 16:23:42 mckusick 10 9
c Add copyright
e
s 00005/00014/00199
d D 1.9 85/05/01 01:34:07 sam 9 8
c major rework; fixup netstat stuff; pull disk cmds into common file; change 
c everthing related to disks to use dk_ndrive and global selction; use getw where possible
e
s 00041/00024/00172
d D 1.8 85/04/28 00:37:34 sam 8 7
c add vsta in; add help command (minimal); make loadav display something 
c which can be turned off
e
s 00013/00004/00183
d D 1.7 84/08/09 19:12:54 mckusick 7 6
c update to new sources from sam; weed out unnecessary #includes
e
s 00002/00006/00185
d D 1.6 83/10/02 21:59:58 sam 6 5
c add command prefix recognition
e
s 00021/00011/00170
d D 1.5 83/10/02 21:31:55 sam 5 4
c put load average in a separate window; make idle process be 
c named <idle> (instead of using name field)
e
s 00050/00235/00131
d D 1.4 83/10/02 20:45:34 sam 4 3
c reorganize window management to allow display routines to set 
c up optimal window definitions
e
s 00040/00010/00326
d D 1.3 83/10/02 14:40:20 sam 3 2
c add init routine and mbuf display; redo swap space display
e
s 00042/00012/00294
d D 1.2 83/10/01 21:22:27 sam 2 1
c add command from arg line, addition of 1st version of swap usage
e
s 00306/00000/00000
d D 1.1 83/10/01 12:20:59 sam 1 0
c date and time created 83/10/01 12:20:59 by sam
e
u
U
t
T
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 10
I 1
D 2
/*% cc -a % -lcurses -ltermlib -lm
 */
E 2
#ifndef lint
I 10
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
E 10
D 9
static char sccsid[] = "%W% (Lucasfilm) %G%";
E 9
I 9
static char sccsid[] = "%W% (Berkeley) %G%";
E 9
D 10
#endif
E 10
I 10
#endif not lint
E 10

#include "systat.h"
I 7
D 9
#include <sys/file.h>
#include <nlist.h>
#include <signal.h>
E 9
E 7

D 4
struct nlist nlst[] = {
#define X_PROC          0
        { "_proc" },
#define X_NPROC         1
        { "_nproc" },
#define X_CCPU          2
E 4
I 4
static struct nlist nlst[] = {
#define X_CCPU          0
E 4
        { "_ccpu" },
D 4
#define X_AVENRUN       3
E 4
I 4
#define X_AVENRUN       1
E 4
        { "_avenrun" },
I 8
D 9
#define	X_DK_MSPW	2
	{ "_dk_mspw" },
#define	X_HZ		3
E 9
I 9
#define	X_HZ		2
E 9
	{ "_hz" },
D 9
#define	X_PHZ		4
E 9
I 9
#define	X_PHZ		3
E 9
	{ "_phz" },
E 8
D 4
#define X_USRPTMAP      4
        { "_Usrptmap" },
#define X_USRPT         5
        { "_usrpt" },
#define X_NSWAP         6
        { "_nswap" },
#define X_SWAPMAP       7
        { "_swapmap" },
#define X_NSWAPMAP      8
        { "_nswapmap" },
#define X_DMMIN         9
        { "_dmmin" },
#define X_DMMAX         10
        { "_dmmax" },
#define X_NSWDEV        11
        { "_nswdev" },
I 2
#define	X_SWDEVT	12
	{ "_swdevt" },
I 3
#define	X_NTEXT		13
	{ "_ntext" },
#define	X_TEXT		14
	{ "_text" },
#define	X_DMTEXT	15
	{ "_dmtext" },
#define	X_MBSTAT	16
	{ "_mbstat" },
E 4
E 3
E 2
        { "" }
};

int     kmem = -1;
int     mem = -1;
int     swap = -1;
I 2
int	naptime = 5;
E 2

int     die();
int     display();
int     suspend();
I 11
int	(*sigtstpdfl)();
E 11

I 7
D 8
double	lave, ccpu;
E 8
I 8
double	ccpu;
E 8
int     dellave;

E 7
I 5
static	WINDOW *wload;			/* one line window for load average */

E 5
D 3
int     showpigs(), openpigs(), fetchpigs(), labelpigs();
int     showswap(), fetchswap(), labelswap();
int     showuser(), openuser(), fetchuser(), labeluser();
int     shownet(), opennet(), fetchnet(), labelnet();
E 3
I 3
D 4
int     showpigs(), openpigs(), fetchpigs(), labelpigs(), initpigs();
int     showswap(), fetchswap(), labelswap(), initswap();
int	showmbufs(), fetchmbufs(), labelmbufs(), initmbufs();
#ifdef notdef
int     showuser(), openuser(), fetchuser(), labeluser(), inituser();
int     shownet(), opennet(), fetchnet(), labelnet(), initnet();
#endif
E 3

struct  cmdtab {
        char    *c_name;
        int     (*c_refresh)();
        int     (*c_open)();
        int     (*c_fetch)();
        int     (*c_label)();
I 3
	int	(*c_init)();
	char	c_flags;
E 3
} cmdtab[] = {
        { "pigs",       showpigs,       openpigs,       fetchpigs,
D 3
          labelpigs },
E 3
I 3
          labelpigs,	initpigs },
E 3
        { "swap",       showswap,       openpigs,       fetchswap,
D 3
          labelswap },
E 3
I 3
          labelswap,	initswap },
        { "mbufs",	showmbufs,	openpigs,       fetchmbufs,
          labelmbufs,	initmbufs },
E 3
#ifdef notdef
        { "user",       showuser,       openuser,       fetchuser,
D 3
          labeluser },
E 3
I 3
          labeluser,	inituser },
E 3
        { "net",        shownet,        opennet,        fetchnet,
D 3
          labelnet },
E 3
I 3
          labelnet,	initnet },
E 3
#endif
        { "" }
};
struct  cmdtab *curcmd = &cmdtab[0];

E 4
main(argc, argv)
        int argc;
        char **argv;
{
D 4
        char ch, line[80];
E 4

I 2
	argc--, argv++;
	while (argc > 0) {
		if (argv[0][0] == '-') {
			struct cmdtab *p;

D 6
			for (p = cmdtab; *p->c_name; p++)
				if (strcmp(p->c_name, &argv[0][1]) == 0)
					break;
			if (*p->c_name == 0) {
E 6
I 6
			p = lookup(&argv[0][1]);
			if (p == (struct cmdtab *)-1) {
E 6
				fprintf(stderr, "%s: unknown request\n",
				    &argv[0][1]);
				exit(1);
			}
			curcmd = p;
		} else {
D 12
			naptime = atoi(argv[1]);
			if (naptime < 5)
E 12
I 12
			naptime = atoi(argv[0]);
			if (naptime <= 0)
E 12
				naptime = 5;
		}
		argc--, argv++;
	}
E 2
        nlist("/vmunix", nlst);
D 4
        (*curcmd->c_open)();
E 4
I 4
	if (nlst[X_CCPU].n_type == 0) {
		fprintf(stderr, "Couldn't namelist /vmunix.\n");
		exit(1);
	}
	kmemf = "/dev/kmem";
	kmem = open(kmemf, O_RDONLY);
	if (kmem < 0) {
		perror(kmemf);
		exit(1);
	}
	memf = "/dev/mem";
	mem = open(memf, O_RDONLY);
	if (mem < 0) {
		perror(memf);
		exit(1);
	}
	swapf = "/dev/drum";
	swap = open(swapf, O_RDONLY);
	if (swap < 0) {
		perror(swapf);
		exit(1);
	}
E 4
D 2
        naptime = 5;
        if (argc != 1)
                naptime = atoi(argv[1]);
        if (naptime < 5)
                naptime = 5;
E 2
        signal(SIGINT, die);
        signal(SIGQUIT, die);
        signal(SIGTERM, die);

D 4
        /* Initialize curses. */
E 4
I 4
        /*
D 5
	 * Initialize display.  Load average appears in standard
	 * window with current display's overlapping sub-window
	 * maintained by the display routines to minimize update
	 * work by curses.
E 5
I 5
	 * Initialize display.  Load average appears in a one line
	 * window of its own.  Current command's display appears in
	 * an overlapping sub-window of stdscr configured by the display
	 * routines to minimize update work by curses.
E 5
	 */
E 4
        initscr();
I 7
	CMDLINE = LINES - 1;
E 7
D 4
        wnd = newwin(20, 70, 3, 5);
E 4
I 4
	wnd = (*curcmd->c_open)();
	if (wnd == NULL) {
		fprintf(stderr, "Couldn't initialize display.\n");
		die();
	}
I 5
	wload = newwin(1, 0, 3, 20);
	if (wload == NULL) {
		fprintf(stderr, "Couldn't set up load average window.\n");
		die();
	}
E 5
E 4

I 2
D 6
#ifdef notdef
E 6
        gethostname(hostname, sizeof (hostname));
D 6
#endif
E 6
E 2
D 8
        lseek(kmem, nlst[X_CCPU].n_value, 0);
E 8
I 8
        lseek(kmem, nlst[X_CCPU].n_value, L_SET);
E 8
        read(kmem, &ccpu, sizeof (ccpu));
        lccpu = log(ccpu);
I 8
D 9
	lseek(kmem, nlst[X_DK_MSPW].n_value, L_SET);
	read(kmem, dk_mspw, sizeof (dk_mspw));
	lseek(kmem, nlst[X_HZ].n_value, L_SET);
	read(kmem, &hz, sizeof (hz));
	lseek(kmem, nlst[X_PHZ].n_value, L_SET);
	read(kmem, &phz, sizeof (phz));
E 9
I 9
	hz = getw(nlst[X_HZ].n_value);
	phz = getw(nlst[X_PHZ].n_value);
E 9
E 8
I 4
	(*curcmd->c_init)();
D 8
	curcmd->c_flags = 1;
E 8
I 8
	curcmd->c_flags |= CF_INIT;
E 8
E 4
D 3
        (*curcmd->c_fetch)();
E 3
D 2
        gethostname(hostname, sizeof (hostname));
E 2
        labels();

        known[0].k_uid = -1;
D 5
        strcpy(known[0].k_name, "<idle>");
E 5
I 5
	known[0].k_name[0] = '\0';
E 5
        numknown = 1;
I 5
	procs[0].pid = -1;
	strcpy(procs[0].cmd, "<idle>");
	numprocs = 1;
E 5
        dellave = 0.0;

        signal(SIGALRM, display);
D 11
        signal(SIGTSTP, suspend);
E 11
I 11
        sigtstpdfl = signal(SIGTSTP, suspend);
E 11
        display();
        noecho();
        crmode();
D 4
        for (;;) {
                col = 0;
                move(22, 0);
                do {
                        refresh();
                        ch = getch() & 0177;
                        if (ch == 0177 && ferror(stdin)) {
                                clearerr(stdin);
                                continue;
                        }
                        if (ch >= 'A' && ch <= 'Z')
                                ch += 'a' - 'A';
                        if (col == 0) {
I 3
#define	mask(s)	(1 << ((s) - 1))
E 3
                                if (ch == CTRL(l)) {
D 3
                                        wrefresh(curscr);
E 3
I 3
					int oldmask = sigblock(mask(SIGALRM));

					wrefresh(curscr);
					sigsetmask(oldmask);
E 3
                                        continue;
                                }
                                if (ch != ':')
                                        continue;
                                move(22, 0);
                                clrtoeol();
                        }
                        if (ch == _tty.sg_erase && col > 0) {
                                if (col == 1 && line[0] == ':')
                                        continue;
                                col--;
                                goto doerase;
                        }
                        if (ch == CTRL(w) && col > 0) {
                                while (--col >= 0 && isspace(line[col]))
                                        ;
                                col++;
                                while (--col >= 0 && !isspace(line[col]))
                                        if (col == 0 && line[0] == ':')
                                                break;
                                col++;
                                goto doerase;
                        }
                        if (ch == _tty.sg_kill && col > 0) {
                                col = 0;
                                if (line[0] == ':')
                                        col++;
                doerase:
                                move(22, col);
                                clrtoeol();
                                continue;
                        }
                        if (isprint(ch)) {
                                line[col] = ch;
                                mvaddch(22, col, ch);
                                col++;
                        }
                } while (col == 0 || (ch != '\r' && ch != '\n'));
                line[col] = '\0';
                command(line + 1);
        }
}
E 4
I 4
	keyboard();
	/*NOTREACHED*/
}
E 4

D 4
command(cmd)
        char *cmd;
{
        register char *cp;
        register struct cmdtab *p;
        char *arg;

        for (cp = cmd; *cp && !isspace(*cp); cp++)
                ;
        if (*cp)
                *cp++ = '\0';
        if (strcmp(cmd, "quit") == 0)
                die();
        if (strcmp(cmd, "status") == 0 || strcmp(cmd, "help") == 0) {
                status();
                return;
        }
I 2
	if (strcmp(cmd, "load") == 0) {
		lseek(kmem, nlst[X_AVENRUN].n_value, L_SET);
		read(kmem, &lave, sizeof (lave));
		mvprintw(22, 0, "%4.1f", lave);
		clrtoeol();
		return;
	}
E 2
        for (p = cmdtab; *p->c_name; p++)
                if (strcmp(cmd, p->c_name) == 0)
                        break;
        if (*p->c_name) {
                if (curcmd == p)
                        return;
                alarm(0);
                curcmd = p;
D 2
                wclear(wnd);
                (*p->c_label)();
E 2
I 2
		clear(); wclear(wnd);
		labels();
E 2
                display();
                status();
                return;
        }
        if (strcmp(cmd, "stop") == 0) {
                alarm(0);
                mvaddstr(22, 0, "Refresh disabled.");
                clrtoeol();
                return;
        }
        /* commands with arguments */
        for (; *cp && isspace(*cp); cp++)
                ;
        if (strcmp(cmd, "start") == 0) {
                int x;

                if (*cp == '\0')
                        x = naptime;
                else
                        x = atoi(cp);
                if (x <= 0) {
                        mvprintw(22, 0, "%d: bad interval.", x);
                        clrtoeol();
                        return;
                }
                alarm(0);
                naptime = x;
                display();
                status();
                return;
        }
D 2
        mvprintw(22, 0, "%s: Unknown command.", cmd);
        clrtoeol();
E 2
I 2
	if (*cmd) {
		mvprintw(22, 0, "%s: Unknown command.", cmd);
		clrtoeol();
	}
E 2
}

status()
{

        mvprintw(22, 0, "Showing %s, refresh every %d seconds.",
          curcmd->c_name, naptime);
        clrtoeol();
}

suspend()
{
        int oldmask;

I 2
	alarm(0);
E 2
        move(22, 0);
        refresh();
        echo();
        nocrmode();
        signal(SIGTSTP, SIG_DFL);
        oldmask = sigsetmask(0);
        kill(getpid(), SIGTSTP);
        sigsetmask(oldmask);
        signal(SIGTSTP, suspend);
        crmode();
        noecho();
        move(22, col);
        wrefresh(curscr);
I 2
	alarm(naptime);
E 2
}

E 4
labels()
{

D 8
        mvaddstr(2, 20,
                "/0   /1   /2   /3   /4   /5   /6   /7   /8   /9   /10");
D 5
        mvwaddstr(wnd, 0, 0, "Load Average");
E 5
I 5
        mvaddstr(3, 5, "Load Average");
E 8
I 8
	if (curcmd->c_flags & CF_LOADAV) {
		mvaddstr(2, 20,
		    "/0   /1   /2   /3   /4   /5   /6   /7   /8   /9   /10");
		mvaddstr(3, 5, "Load Average");
	}
E 8
E 5
        (*curcmd->c_label)();
#ifdef notdef
        mvprintw(21, 25, "CPU usage on %s", hostname);
#endif
        refresh();
}

display()
{
        register int i, j;

        /* Get the load average over the last minute. */
        lseek(kmem, nlst[X_AVENRUN].n_value, L_SET);
D 8
        read(kmem, &lave, sizeof (lave));
E 8
I 8
	read(kmem, avenrun, sizeof (avenrun));
E 8
I 3
D 4
	if (curcmd->c_flags == 0) {
		(*curcmd->c_init)();
		curcmd->c_flags = 1;
	}
E 4
E 3
        (*curcmd->c_fetch)();
D 8
        j = 5.0*lave + 0.5;
        dellave -= lave;
        if (dellave >= 0.0)
                c = '<';
        else {
                c = '>';
                dellave = -dellave;
        }
        if (dellave < 0.1)
                c = '|';
        dellave = lave;
D 5
        wmove(wnd, 0, 15);
        wclrtoeol(wnd);
        for (i = (j > 50)? 50 : j; i > 0; i--)
                waddch(wnd, c);
E 5
I 5
        wmove(wload, 0, 0); wclrtoeol(wload);
        for (i = (j > 50) ? 50 : j; i > 0; i--)
                waddch(wload, c);
E 5
        if (j > 50)
D 5
                wprintw(wnd, " %4.1f", lave);
E 5
I 5
                wprintw(wload, " %4.1f", lave);
E 8
I 8
	if (curcmd->c_flags & CF_LOADAV) {
		j = 5.0*avenrun[0] + 0.5;
		dellave -= avenrun[0];
		if (dellave >= 0.0)
			c = '<';
		else {
			c = '>';
			dellave = -dellave;
		}
		if (dellave < 0.1)
			c = '|';
		dellave = avenrun[0];
		wmove(wload, 0, 0); wclrtoeol(wload);
		for (i = (j > 50) ? 50 : j; i > 0; i--)
			waddch(wload, c);
		if (j > 50)
			wprintw(wload, " %4.1f", avenrun[0]);
	}
E 8
E 5
        (*curcmd->c_refresh)();
I 5
D 8
	wrefresh(wload);
E 8
I 8
	if (curcmd->c_flags & CF_LOADAV)
		wrefresh(wload);
E 8
E 5
        wrefresh(wnd);
D 7
        move(22, col);
E 7
I 7
        move(CMDLINE, col);
E 7
        refresh();
        alarm(naptime);
I 4
}

load()
{
I 7
	double	avenrun[3];
E 7

	lseek(kmem, nlst[X_AVENRUN].n_value, L_SET);
D 7
	read(kmem, &lave, sizeof (lave));
	mvprintw(22, 0, "%4.1f", lave);
E 7
I 7
	read(kmem, avenrun, sizeof (avenrun));
	mvprintw(CMDLINE, 0, "%4.1f %4.1f %4.1f",
	    avenrun[0], avenrun[1], avenrun[2]);
E 7
	clrtoeol();
E 4
}

die()
{

        endwin();
        exit(0);
I 3
}

error(fmt, a1, a2, a3)
{

D 7
	mvprintw(22, 0, fmt, a1, a2, a3);
E 7
I 7
	mvprintw(CMDLINE, 0, fmt, a1, a2, a3);
E 7
	clrtoeol();
	refresh();
E 3
}
E 1
