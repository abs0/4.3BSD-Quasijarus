h12267
s 00004/00004/00592
d D 5.8 88/05/19 15:38:43 bostic 16 15
c install C version of _doprnt
e
s 00003/00003/00593
d D 5.7 87/06/25 09:15:12 bostic 15 14
c csh long/int mismatches; bug report 4.3BSD/bin/45
e
s 00006/00020/00590
d D 5.6 86/05/18 23:01:00 lepreau 14 13
c don't mess with SIGWINCH, instead get winsz every time need to do a LIST--
c otherwise csh misses too much.  Optimize when have 0 items matched.
e
s 00052/00034/00558
d D 5.5 86/05/13 01:01:12 lepreau 13 12
c get winsz via ioctl and respond to SIGWINCH.
c make filetype smarter: *,/,@,> types.
c avoid divide-by-zero in print_by_column.
c use the compare routine in sh.glob.c for qsort.
e
s 00011/00014/00581
d D 5.4 86/03/29 07:28:44 lepreau 12 11
c don't sigblock(SIGINT) around setting t_brkc to save 2 syscalls/line;
c nits and comments
e
s 00071/00019/00524
d D 5.3 86/02/12 11:10:08 edward 11 10
c changes from John Coker
e
s 00003/00003/00540
d D 5.2 85/06/06 13:09:28 edward 10 9
c cleaning up after bozos
e
s 00008/00002/00535
d D 5.1 85/06/04 10:58:15 dist 9 8
c Add copyright
e
s 00007/00006/00530
d D 1.8 85/04/28 17:34:11 edward 8 7
c don't use passwd for our own home directory, just use variable "home"
c (from broome)
e
s 00002/00009/00534
d D 1.7 85/04/25 18:11:18 edward 7 6
c use xalloc not malloc
e
s 00036/00044/00507
d D 1.6 84/12/13 14:43:56 edward 6 5
c performance
e
s 00002/00002/00549
d D 1.5 84/11/27 14:46:44 bloom 5 4
c Fix a couple sysntax errors
e
s 00363/00390/00188
d D 1.4 84/09/02 16:50:50 sam 4 3
c I can't stand it, if layer's gonna put this crap in the source code, 
c the least he can do is reformat it to conform to the rest of the code
e
s 00014/00018/00564
d D 1.3 84/08/31 09:32:29 ralph 3 2
c use new signal calls instead of compatibility routines.
e
s 00001/00003/00581
d D 1.2 83/11/13 23:33:22 layer 2 1
c don't turn on ECHO after every command.  This was very annoying in
c and emacs window, since emacs does the echo'ing, and one couldn't
c shut up the shell.
e
s 00584/00000/00000
d D 1.1 83/11/02 13:44:07 layer 1 0
c date and time created 83/11/02 13:44:07 by layer
e
u
U
t
T
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
E 10
I 10
 * All rights reserved.  The Berkeley Software License Agreement
E 10
 * specifies the terms and conditions for redistribution.
 */

E 9
I 4
#ifndef lint
E 4
I 1
D 6
static	char *sccsid = "%Z%%M% %I% (Berkeley from Hp Labs) %G%";
E 6
I 6
D 9
static	char *sccsid = "%W% (Berkeley from Hp Labs) %G%";
E 6
I 4
#endif
E 9
I 9
D 10
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 10
I 10
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 10
E 9
E 4

I 6
#ifdef FILEC
E 6
/*
 * Tenex style file name recognition, .. and more.
 * History:
 *	Author: Ken Greer, Sept. 1975, CMU.
 *	Finally got around to adding to the Cshell., Ken Greer, Dec. 1981.
 */

D 6
#include <sys/types.h>
#include <sys/stat.h>
E 6
I 6
#include "sh.h"
E 6
#include <sgtty.h>
#include <sys/dir.h>
D 6
#include <signal.h>
E 6
#include <pwd.h>

D 3
/*
 * For 4.2bsd signals.
 *
 * (can't include sh.h)
 */
#define	mask(s)		(1 << ((s)-1))
#define	sigsys(s, a)	signal(s, a)
#define	sighold(s)	sigblock(mask(s))

E 3
D 6
extern short SHIN, SHOUT;

E 6
#define TRUE	1
#define FALSE	0
#define ON	1
#define OFF	0
D 6
#define FILSIZ	512			/* Max reasonable file name length */
E 6

#define ESC	'\033'

typedef enum {LIST, RECOGNIZE} COMMAND;

I 13
int	sortscmp();			/* defined in sh.glob.c */

E 13
D 6
#define equal(a, b)	(strcmp(a, b) == 0)

E 6
D 12
static struct tchars  tchars;		/* INT, QUIT, XON, XOFF, EOF, BRK */

E 12
I 6
/*
 * Put this here so the binary can be patched with adb to enable file
D 11
 * completion by default.
E 11
I 11
 * completion by default.  Filec controls completion, nobeep controls
 * ringing the terminal bell on incomplete expansions.
E 11
 */
bool filec = 0;

E 6
static
D 4
setup_tty (on)
E 4
I 4
setup_tty(on)
	int on;
E 4
{
D 3
    sigignore (SIGINT);
E 3
I 3
D 4
    int omask;

    omask = sigblock(sigmask(SIGINT));
E 3
    if (on)
    {
E 4
	struct sgttyb sgtty;
D 4
	ioctl (SHIN, TIOCGETC, &tchars);
	tchars.t_brkc = ESC;
	ioctl (SHIN, TIOCSETC, &tchars);
	/*
	 * This is a useful feature in it's own right...
	 * The shell makes sure that the tty is not in some weird state
	 * and fixes it if it is.  But it should be noted that the
	 * tenex routine will not work correctly in CBREAK or RAW mode
	 * so this code below is, therefore, mandatory.
	 */
	ioctl (SHIN, TIOCGETP, &sgtty);
D 2
	if ((sgtty.sg_flags & (RAW | CBREAK)) ||
	   ((sgtty.sg_flags & ECHO) == 0))	/* not manditory, but nice */
E 2
I 2
	if (sgtty.sg_flags & (RAW | CBREAK))
E 2
	{
	    sgtty.sg_flags &= ~(RAW | CBREAK);
D 2
	    sgtty.sg_flags |= ECHO;
E 2
	    ioctl (SHIN, TIOCSETP, &sgtty);
E 4
I 4
D 12
	int omask;
E 12
I 12
	static struct tchars tchars;	/* INT, QUIT, XON, XOFF, EOF, BRK */
E 12

D 12
	omask = sigblock(sigmask(SIGINT));
E 12
	if (on) {
D 6
		ioctl(SHIN, TIOCGETC, &tchars);
E 6
I 6
		(void) ioctl(SHIN, TIOCGETC, (char *)&tchars);
E 6
		tchars.t_brkc = ESC;
D 6
		ioctl(SHIN, TIOCSETC, &tchars);
E 6
I 6
		(void) ioctl(SHIN, TIOCSETC, (char *)&tchars);
E 6
		/*
D 12
		 * This is a useful feature in it's own right...
		 * The shell makes sure that the tty is not in some weird state
		 * and fixes it if it is.  But it should be noted that the
		 * tenex routine will not work correctly in CBREAK or RAW mode
		 * so this code below is, therefore, mandatory.
E 12
I 12
		 * This must be done after every command: if
		 * the tty gets into raw or cbreak mode the user
		 * can't even type 'reset'.
E 12
		 */
D 6
		ioctl(SHIN, TIOCGETP, &sgtty);
E 6
I 6
		(void) ioctl(SHIN, TIOCGETP, (char *)&sgtty);
E 6
		if (sgtty.sg_flags & (RAW|CBREAK)) {
			 sgtty.sg_flags &= ~(RAW|CBREAK);
D 6
			 ioctl(SHIN, TIOCSETP, &sgtty);
E 6
I 6
			 (void) ioctl(SHIN, TIOCSETP, (char *)&sgtty);
E 6
		}
	} else {
		tchars.t_brkc = -1;
D 6
		ioctl(SHIN, TIOCSETC, &tchars);
E 6
I 6
		(void) ioctl(SHIN, TIOCSETC, (char *)&tchars);
E 6
E 4
	}
D 4
    }
    else
    {
	tchars.t_brkc = -1;
	ioctl (SHIN, TIOCSETC, &tchars);
    }
D 3
    sigrelse (SIGINT);
E 3
I 3
    sigsetmask (omask);
E 4
I 4
D 6
	sigsetmask (omask);
E 6
I 6
D 11
	(void) sigsetmask (omask);
E 11
I 11
D 12
	(void) sigsetmask(omask);
E 12
E 11
E 6
E 4
E 3
}

/*
 * Move back to beginning of current line
 */
static
D 4
back_to_col_1 ()
E 4
I 4
back_to_col_1()
E 4
{
D 4
    struct sgttyb tty, tty_normal;
D 3
    sigignore (SIGINT);
E 3
I 3
    int omask;
E 4
I 4
	struct sgttyb tty, tty_normal;
D 15
	int omask;
E 15
I 15
	long omask;
E 15
E 4

D 4
    omask = sigblock (sigmask(SIGINT));
E 3
    ioctl (SHIN, TIOCGETP, &tty);
    tty_normal = tty;
    tty.sg_flags &= ~CRMOD;
    ioctl (SHIN, TIOCSETN, &tty);
    (void) write (SHOUT, "\r", 1);
    ioctl (SHIN, TIOCSETN, &tty_normal);
D 3
    sigrelse (SIGINT);
E 3
I 3
    sigsetmask (omask);
E 4
I 4
	omask = sigblock(sigmask(SIGINT));
D 6
	ioctl(SHIN, TIOCGETP, &tty);
E 6
I 6
	(void) ioctl(SHIN, TIOCGETP, (char *)&tty);
E 6
	tty_normal = tty;
	tty.sg_flags &= ~CRMOD;
D 6
	ioctl(SHIN, TIOCSETN, &tty);
E 6
I 6
	(void) ioctl(SHIN, TIOCSETN, (char *)&tty);
E 6
	(void) write(SHOUT, "\r", 1);
D 6
	ioctl(SHIN, TIOCSETN, &tty_normal);
	sigsetmask(omask);
E 6
I 6
	(void) ioctl(SHIN, TIOCSETN, (char *)&tty_normal);
	(void) sigsetmask(omask);
E 6
E 4
E 3
}

/*
 * Push string contents back into tty queue
 */
static
D 4
pushback (string)
char  *string;
E 4
I 4
pushback(string)
	char *string;
E 4
{
D 4
    register char  *p;
    struct sgttyb   tty, tty_normal;
I 3
    int omask;
E 4
I 4
	register char *p;
	struct sgttyb tty, tty_normal;
D 15
	int omask;
E 15
I 15
	long omask;
E 15
E 4
E 3

D 3
    sigignore (SIGINT);
E 3
I 3
D 4
    omask = sigblock (sigmask(SIGINT));
E 3
    ioctl (SHOUT, TIOCGETP, &tty);
    tty_normal = tty;
    tty.sg_flags &= ~ECHO;
    ioctl (SHOUT, TIOCSETN, &tty);
E 4
I 4
	omask = sigblock(sigmask(SIGINT));
D 6
	ioctl(SHOUT, TIOCGETP, &tty);
E 6
I 6
	(void) ioctl(SHOUT, TIOCGETP, (char *)&tty);
E 6
	tty_normal = tty;
	tty.sg_flags &= ~ECHO;
D 6
	ioctl(SHOUT, TIOCSETN, &tty);
E 6
I 6
	(void) ioctl(SHOUT, TIOCSETN, (char *)&tty);
E 6
E 4

D 4
    for (p = string; *p; p++)
	ioctl (SHOUT, TIOCSTI, p);
    ioctl (SHOUT, TIOCSETN, &tty_normal);
D 3
    sigrelse (SIGINT);
E 3
I 3
    sigsetmask (omask);
E 4
I 4
	for (p = string; *p; p++)
D 6
		ioctl(SHOUT, TIOCSTI, p);
	ioctl(SHOUT, TIOCSETN, &tty_normal);
	sigsetmask(omask);
E 6
I 6
		(void) ioctl(SHOUT, TIOCSTI, p);
	(void) ioctl(SHOUT, TIOCSETN, (char *)&tty_normal);
	(void) sigsetmask(omask);
E 6
E 4
E 3
}

/*
D 4
 * Concatonate src onto tail of des.
E 4
I 4
 * Concatenate src onto tail of des.
E 4
 * Des is a string whose maximum length is count.
 * Always null terminate.
 */
I 12
static
E 12
D 4
catn (des, src, count)
register char *des, *src;
register count;
E 4
I 4
catn(des, src, count)
	register char *des, *src;
	register count;
E 4
{
D 4
    while (--count >= 0 && *des)
	des++;
    while (--count >= 0)
	if ((*des++ = *src++) == 0)
	    return;
    *des = '\0';
E 4
I 4

	while (--count >= 0 && *des)
		des++;
	while (--count >= 0)
		if ((*des++ = *src++) == 0)
			 return;
	*des = '\0';
E 4
}

D 13
static
D 4
max (a, b)
E 4
I 4
max(a, b)
E 4
{
D 4
    if (a > b)
	return (a);
    return (b);
E 4
I 4

	return (a > b ? a : b);
E 4
}

E 13
/*
D 4
 * like strncpy but always leave room for trailing \0
E 4
I 4
 * Like strncpy but always leave room for trailing \0
E 4
 * and always null terminate.
 */
I 12
static
E 12
D 4
copyn (des, src, count)
register char *des, *src;
register count;
E 4
I 4
copyn(des, src, count)
	register char *des, *src;
	register count;
E 4
{
D 4
    while (--count >= 0)
	if ((*des++ = *src++) == 0)
	    return;
    *des = '\0';
E 4
I 4

	while (--count >= 0)
		if ((*des++ = *src++) == 0)
			return;
	*des = '\0';
E 4
}

D 13
/*
 * For qsort()
 */
static
D 4
fcompare (file1, file2)
char  **file1, **file2;
E 4
I 4
fcompare(file1, file2)
	char **file1, **file2;
E 4
{
D 4
    return (strcmp (*file1, *file2));
E 4
I 4

	 return (strcmp(*file1, *file2));
E 4
}

E 13
static char
D 4
filetype (dir, file)
char *dir, *file;
E 4
I 4
filetype(dir, file)
	char *dir, *file;
E 4
{
D 4
    if (dir)
    {
E 4
D 13
	char path[512];
E 13
I 13
	char path[MAXPATHLEN];
E 13
	struct stat statb;
D 6
	extern char *strcpy ();
E 6
D 4
	catn (strcpy (path, dir), file, sizeof path);
	if (stat (path, &statb) >= 0)
	{
	    if (statb.st_mode & S_IFDIR)
		return ('/');
	    if (statb.st_mode & 0111)
		return ('*');
E 4
I 4

D 13
	if (dir) {
D 6
		catn(strcpy (path, dir), file, sizeof path);
E 6
I 6
		catn(strcpy(path, dir), file, sizeof path);
E 6
		if (stat(path, &statb) >= 0) {
			if (statb.st_mode & S_IFDIR)
				return ('/');
E 13
I 13
	catn(strcpy(path, dir), file, sizeof path);
	if (lstat(path, &statb) == 0) {
		switch(statb.st_mode & S_IFMT) {
		    case S_IFDIR:
			return ('/');

		    case S_IFLNK:
			if (stat(path, &statb) == 0 &&	    /* follow it out */
			   (statb.st_mode & S_IFMT) == S_IFDIR)
				return ('>');
			else
				return ('@');

		    case S_IFSOCK:
			return ('=');

		    default:
E 13
			if (statb.st_mode & 0111)
				return ('*');
		}
E 4
	}
D 4
    }
    return (' ');
E 4
I 4
	return (' ');
E 4
}

I 13
D 14
static int donewin;
E 14
static struct winsize win;

D 14
static
winch()
{

	if (ioctl(SHIN, TIOCGWINSZ, (char *)&win) < 0) {
		win.ws_col = 80;
		signal(SIGWINCH, SIG_IGN);
	}
	if (win.ws_col == 0)
		win.ws_col = 80;
	donewin = 1;
}

E 14
E 13
/*
 * Print sorted down columns
 */
static
D 4
print_by_column (dir, items, count)
char *dir, *items[];
E 4
I 4
print_by_column(dir, items, count)
	char *dir, *items[];
E 4
{
D 4
    register int i, rows, r, c, maxwidth = 0, columns;
    for (i = 0; i < count; i++)
	maxwidth = max (maxwidth, strlen (items[i]));
    maxwidth += 2;				/* for the file tag and space */
    columns = 78 / maxwidth;
    rows = (count + (columns - 1)) / columns;
    for (r = 0; r < rows; r++)
    {
	for (c = 0; c < columns; c++)
	{
	    i = c * rows + r;
	    if (i < count)
	    {
		register int w;
		printf("%s", items[i]);
		putchar (filetype (dir, items[i]));	/* '/' or '*' or ' ' */
		if (c < (columns - 1))			/* Not last column? */
		    for (w = strlen (items[i]) + 1; w < maxwidth; w++)
			printf (" ");
	    }
E 4
I 4
	register int i, rows, r, c, maxwidth = 0, columns;

I 13
D 14
	if (!donewin) {
		signal(SIGWINCH, winch);
		winch();
	}
E 14
I 14
	if (ioctl(SHOUT, TIOCGWINSZ, (char *)&win) < 0 || win.ws_col == 0)
		win.ws_col = 80;
E 14
E 13
	for (i = 0; i < count; i++)
D 13
		maxwidth = max(maxwidth, strlen(items[i]));
E 13
I 13
		maxwidth = maxwidth > (r = strlen(items[i])) ? maxwidth : r;
E 13
	maxwidth += 2;			/* for the file tag and space */
D 13
	columns = 78 / maxwidth;
E 13
I 13
	columns = win.ws_col / maxwidth;
	if (columns == 0)
		columns = 1;
E 13
	rows = (count + (columns - 1)) / columns;
	for (r = 0; r < rows; r++) {
		for (c = 0; c < columns; c++) {
			i = c * rows + r;
			if (i < count) {
				register int w;

				printf("%s", items[i]);
D 13
				putchar(filetype(dir, items[i]));
E 13
I 13
D 16
				putchar(dir ? filetype(dir, items[i]) : ' ');
E 16
I 16
				cshputchar(dir ? filetype(dir, items[i]) : ' ');
E 16
E 13
				if (c < columns - 1) {	/* last column? */
					w = strlen(items[i]) + 1;
					for (; w < maxwidth; w++)
D 13
						printf(" ");
E 13
I 13
D 16
						putchar(' ');
E 16
I 16
						cshputchar(' ');
E 16
E 13
				}
			}
		}
D 11
		printf ("\n");
E 11
I 11
D 13
		printf("\n");
E 13
I 13
D 16
		putchar('\n');
E 16
I 16
		cshputchar('\n');
E 16
E 13
E 11
E 4
	}
D 4
	printf ("\n");
    }
E 4
}

/*
D 4
 * expand file name with possible tilde usage
 *		~person/mumble
E 4
I 4
 * Expand file name with possible tilde usage
 *	~person/mumble
E 4
 * expands to
D 4
 *		home_directory_of_person/mumble
 *
 * Usage: tilde (new, old) char *new, *old;
E 4
I 4
 *	home_directory_of_person/mumble
E 4
 */
D 4

E 4
D 12
char *
E 12
I 12
static char *
E 12
D 4
tilde (new, old)
char *new, *old;
E 4
I 4
tilde(new, old)
	char *new, *old;
E 4
{
D 4
    extern char *strcpy ();
    extern struct passwd *getpwuid (), *getpwnam ();
E 4
I 4
	register char *o, *p;
	register struct passwd *pw;
	static char person[40];
D 6
	extern char *strcpy();
	extern struct passwd *getpwuid(), *getpwnam();
E 6
E 4

D 4
    register char *o, *p;
    register struct passwd *pw;
    static char person[40] = {0};
E 4
I 4
	if (old[0] != '~')
		return (strcpy(new, old));
E 4

D 4
    if (old[0] != '~')
	return (strcpy (new, old));

    for (p = person, o = &old[1]; *o && *o != '/'; *p++ = *o++);
    *p = '\0';

    if (person[0] == '\0')			/* then use current uid */
	pw = getpwuid (getuid ());
    else
	pw = getpwnam (person);

    if (pw == NULL)
	return (NULL);

    strcpy (new, pw -> pw_dir);
    (void) strcat (new, o);
    return (new);
E 4
I 4
	for (p = person, o = &old[1]; *o && *o != '/'; *p++ = *o++)
		;
	*p = '\0';
D 8
	if (person[0] == '\0')			/* then use current uid */
		pw = getpwuid(getuid());
	else
E 8
I 8
	if (person[0] == '\0')
		(void) strcpy(new, value("home"));
	else {
E 8
		pw = getpwnam(person);
D 8
	if (pw == NULL)
		return (NULL);
D 6
	strcpy(new, pw->pw_dir);
E 6
I 6
	(void) strcpy(new, pw->pw_dir);
E 8
I 8
		if (pw == NULL)
			return (NULL);
		(void) strcpy(new, pw->pw_dir);
	}
E 8
E 6
	(void) strcat(new, o);
	return (new);
E 4
}

/*
 * Cause pending line to be printed
 */
static
D 4
retype ()
E 4
I 4
retype()
E 4
{
D 4
    int     pending_input = LPENDIN;
    ioctl (SHOUT, TIOCLBIS, &pending_input);
E 4
I 4
	int pending_input = LPENDIN;

D 6
	ioctl(SHOUT, TIOCLBIS, &pending_input);
E 6
I 6
	(void) ioctl(SHOUT, TIOCLBIS, (char *)&pending_input);
E 6
E 4
}

static
D 4
beep ()
E 4
I 4
beep()
E 4
{
D 4
    (void) write (SHOUT, "\07", 1);
E 4
I 4

D 11
	(void) write(SHOUT, "\07", 1);
E 11
I 11
	if (adrof("nobeep") == 0)
		(void) write(SHOUT, "\007", 1);
E 11
E 4
}

/*
 * Erase that silly ^[ and
 * print the recognized part of the string
 */
static
D 4
print_recognized_stuff (recognized_part)
char *recognized_part;
E 4
I 4
print_recognized_stuff(recognized_part)
	char *recognized_part;
E 4
{
D 4
    /* An optimized erasing of that silly ^[ */
    switch (strlen (recognized_part))
    {
E 4
I 4

	/* An optimized erasing of that silly ^[ */
	switch (strlen(recognized_part)) {

E 4
	case 0:				/* erase two characters: ^[ */
D 4
	    printf ("\210\210  \210\210");
	    break;
E 4
I 4
		printf("\210\210  \210\210");
		break;

E 4
	case 1:				/* overstrike the ^, erase the [ */
D 4
	    printf ("\210\210%s \210", recognized_part);
	    break;
E 4
I 4
		printf("\210\210%s \210", recognized_part);
		break;

E 4
	default:			/* overstrike both characters ^[ */
D 4
	    printf ("\210\210%s", recognized_part);
	    break;
    }
    flush ();
E 4
I 4
		printf("\210\210%s", recognized_part);
		break;
	}
	flush();
E 4
}

/*
D 4
 * parse full path in file into 2 parts: directory and file names
E 4
I 4
 * Parse full path in file into 2 parts: directory and file names
E 4
 * Should leave final slash (/) at end of dir.
 */
static
D 4
extract_dir_and_name (path, dir, name)
char   *path, *dir, *name;
E 4
I 4
extract_dir_and_name(path, dir, name)
	char *path, *dir, *name;
E 4
{
D 4
    extern char *rindex ();
    register char  *p;
    p = rindex (path, '/');
    if (p == NULL)
    {
	copyn (name, path, MAXNAMLEN);
	dir[0] = '\0';
    }
    else
    {
	p++;
	copyn (name, p, MAXNAMLEN);
	copyn (dir, path, p - path);
    }
E 4
I 4
	register char  *p;
D 6
	extern char *rindex();
E 6

D 6
	p = rindex (path, '/');
E 6
I 6
	p = rindex(path, '/');
E 6
	if (p == NULL) {
		copyn(name, path, MAXNAMLEN);
		dir[0] = '\0';
	} else {
		copyn(name, ++p, MAXNAMLEN);
		copyn(dir, path, p - path);
	}
E 4
}

D 4

E 4
D 12
char *
E 12
I 12
static char *
E 12
D 4
getentry (dir_fd, looking_for_lognames)
DIR *dir_fd;
E 4
I 4
getentry(dir_fd, looking_for_lognames)
	DIR *dir_fd;
E 4
{
D 4
    if (looking_for_lognames)			/* Is it login names we want? */
    {
	extern struct passwd *getpwent ();
E 4
	register struct passwd *pw;
D 4
	if ((pw = getpwent ()) == NULL)
	    return (NULL);
	return (pw -> pw_name);
    }
    else					/* It's a dir entry we want */
    {
E 4
	register struct direct *dirp;
D 4
	if (dirp = readdir (dir_fd))
	    return (dirp -> d_name);
E 4
I 4
D 6
	extern struct passwd *getpwent();
E 6

	if (looking_for_lognames) {
D 13
		if ((pw = getpwent ()) == NULL)
E 13
I 13
		if ((pw = getpwent()) == NULL)
E 13
			return (NULL);
		return (pw->pw_name);
	}
	if (dirp = readdir(dir_fd))
		return (dirp->d_name);
E 4
	return (NULL);
D 4
    }
E 4
}

static
D 4
free_items (items)
register char **items;
E 4
I 4
free_items(items)
	register char **items;
E 4
{
D 4
    register int i;
    for (i = 0; items[i]; i++)
	free (items[i]);
    free (items);
E 4
I 4
	register int i;

	for (i = 0; items[i]; i++)
		free(items[i]);
D 6
	free(items);
E 6
I 6
	free((char *)items);
E 6
E 4
}

D 4
#define FREE_ITEMS(items)\
D 3
{\
    sighold (SIGINT);\
E 3
I 3
{   int omask;\
    omask = sigblock (sigmask(SIGINT));\
E 3
    free_items (items);\
    items = NULL;\
D 3
    sigrelse (SIGINT);\
E 3
I 3
    sigsetmask (omask);\
E 4
I 4
#define FREE_ITEMS(items) { \
D 15
	int omask;\
E 15
I 15
	long omask;\
E 15
D 5

E 5
I 5
\
E 5
	omask = sigblock(sigmask(SIGINT));\
	free_items(items);\
	items = NULL;\
D 6
	sigsetmask(omask);\
E 6
I 6
	(void) sigsetmask(omask);\
E 6
E 4
E 3
}

/*
 * Perform a RECOGNIZE or LIST command on string "word".
 */
static
D 4
search (word, command, max_word_length)
char   *word;
COMMAND command;
E 4
I 4
search(word, command, max_word_length)
	char *word;
	COMMAND command;
E 4
{
D 4
#   define MAXITEMS 1024
    register DIR *dir_fd;
    register numitems,
	    name_length,		/* Length of prefix (file name) */
	    looking_for_lognames;	/* True if looking for login names */
    char    tilded_dir[FILSIZ + 1],	/* dir after ~ expansion */
	    dir[FILSIZ + 1],		/* /x/y/z/ part in /x/y/z/f */
            name[MAXNAMLEN + 1],	/* f part in /d/d/d/f */
            extended_name[MAXNAMLEN+1],	/* the recognized (extended) name */
            *entry;			/* single directory entry or logname */
    static char
           **items = NULL;		/* file names when doing a LIST */
E 4
I 4
	static char **items = NULL;
	register DIR *dir_fd;
D 11
	register numitems, name_length, looking_for_lognames;
E 11
I 11
	register numitems = 0, ignoring = TRUE, nignored = 0;
	register name_length, looking_for_lognames;
E 11
D 6
	char tilded_dir[FILSIZ + 1], dir[FILSIZ + 1];
E 6
I 6
	char tilded_dir[MAXPATHLEN + 1], dir[MAXPATHLEN + 1];
E 6
D 5
	char name[MAXNAMLEN + 1], extended_name[MAXNAMLEN+1],
E 5
I 5
	char name[MAXNAMLEN + 1], extended_name[MAXNAMLEN+1];
E 5
	char *entry;
#define MAXITEMS 1024
E 4

D 4
    if (items != NULL)
	FREE_ITEMS (items);
E 4
I 4
	if (items != NULL)
		FREE_ITEMS(items);
E 4

D 4
    looking_for_lognames = (*word == '~') && (index (word, '/') == NULL);
    if (looking_for_lognames)			/* Looking for login names? */
    {
	setpwent ();				/* Open passwd file */
	copyn (name, &word[1], MAXNAMLEN);	/* name sans ~ */
    }
    else
    {						/* Open directory */
	extract_dir_and_name (word, dir, name);
	if (tilde (tilded_dir, dir) == 0)	/* expand ~user/... stuff */
	    return (0);
	if ((dir_fd = opendir (*tilded_dir ? tilded_dir : ".")) == NULL)
	   return (0);
    }

    name_length = strlen (name);

    for (numitems = 0; entry = getentry (dir_fd, looking_for_lognames);)
    {
	if (!is_prefix (name, entry))
	    continue;

	/* Don't match . files on null prefix match */
	if (name_length == 0 && entry[0] == '.' && !looking_for_lognames)
	    continue;

	if (command == LIST)		/* LIST command */
	{
	    extern char *malloc ();
	    if (numitems >= MAXITEMS)
	    {
		printf ("\nYikes!! Too many %s!!\n",
		    looking_for_lognames ? "names in password file":"files");
		break;
	    }
	    if (items == NULL)
	    {
		items = (char **) calloc (sizeof (items[1]), MAXITEMS);
		if (items == NULL)
		    break;
	    }
	    if ((items[numitems] = malloc (strlen(entry) + 1)) == NULL)
	    {
		printf ("out of mem\n");
		break;
	    }
	    copyn (items[numitems], entry, MAXNAMLEN);
	    numitems++;
E 4
I 4
	looking_for_lognames = (*word == '~') && (index(word, '/') == NULL);
	if (looking_for_lognames) {
D 6
		setpwent();
E 6
I 6
		(void) setpwent();
E 6
		copyn(name, &word[1], MAXNAMLEN);	/* name sans ~ */
	} else {
		extract_dir_and_name(word, dir, name);
		if (tilde(tilded_dir, dir) == 0)
			return (0);
		dir_fd = opendir(*tilded_dir ? tilded_dir : ".");
		if (dir_fd == NULL)
			return (0);
E 4
	}
I 11

again:	/* search for matches */
E 11
D 4
	else					/* RECOGNIZE command */
	    if (recognize (extended_name, entry, name_length, ++numitems))
		break;
    }
E 4
I 4
	name_length = strlen(name);
	for (numitems = 0; entry = getentry(dir_fd, looking_for_lognames); ) {
		if (!is_prefix(name, entry))
			continue;
		/* Don't match . files on null prefix match */
		if (name_length == 0 && entry[0] == '.' &&
		    !looking_for_lognames)
			continue;
		if (command == LIST) {
D 6
			extern char *malloc ();
E 4

E 6
D 4
    if (looking_for_lognames)
	endpwent ();
    else
	closedir (dir_fd);

    if (command == RECOGNIZE && numitems > 0)
    {
E 4
I 4
			if (numitems >= MAXITEMS) {
				printf ("\nYikes!! Too many %s!!\n",
				    looking_for_lognames ?
					"names in password file":"files");
				break;
			}
D 7
			if (items == NULL) {
E 7
I 7
			if (items == NULL)
E 7
				items = (char **) calloc(sizeof (items[1]),
				    MAXITEMS);
D 7
				if (items == NULL)
					break;
			}
D 6
			items[numitems] = malloc(strlen(entry) + 1);
E 6
I 6
			items[numitems] = malloc((unsigned)strlen(entry) + 1);
E 6
			if (items[numitems] == NULL) {
				printf("out of mem\n");
				break;
			}
E 7
I 7
			items[numitems] = xalloc((unsigned)strlen(entry) + 1);
E 7
			copyn(items[numitems], entry, MAXNAMLEN);
			numitems++;
D 11
		} else				/* RECOGNIZE command */
			if (recognize(extended_name, entry, name_length,
			    ++numitems))
E 11
I 11
		} else {			/* RECOGNIZE command */
			if (ignoring && ignored(entry))
				nignored++;
			else if (recognize(extended_name,
			    entry, name_length, ++numitems))
E 11
				break;
I 11
		}
E 11
	}
I 11
	if (ignoring && numitems == 0 && nignored > 0) {
		ignoring = FALSE;
		nignored = 0;
		if (looking_for_lognames)
D 13
			(void)setpwent();
E 13
I 13
			(void) setpwent();
E 13
		else
			rewinddir(dir_fd);
		goto again;
	}

E 11
E 4
	if (looking_for_lognames)
D 4
	    copyn (word, "~", 1);
E 4
I 4
D 6
		endpwent();
E 6
I 6
		(void) endpwent();
E 6
E 4
	else
D 4
	    copyn (word, dir, max_word_length);		/* put back dir part */
	catn (word, extended_name, max_word_length);	/* add extended name */
	return (numitems);
    }
E 4
I 4
		closedir(dir_fd);
D 14
	if (command == RECOGNIZE && numitems > 0) {
E 14
I 14
	if (numitems == 0)
		return (0);
	if (command == RECOGNIZE) {
E 14
		if (looking_for_lognames)
			 copyn(word, "~", 1);
		else
			/* put back dir part */
			copyn(word, dir, max_word_length);
		/* add extended name */
		catn(word, extended_name, max_word_length);
		return (numitems);
	}
D 14
	if (command == LIST) {
E 14
I 14
	else { 				/* LIST */
E 14
D 6
		register int i;
E 4

D 4
    if (command == LIST)
    {
	register int i;
	qsort (items, numitems, sizeof (items[1]), fcompare);
	print_by_column(looking_for_lognames ? NULL:tilded_dir, items,numitems);
	if (items != NULL)
	    FREE_ITEMS (items);
    }
    return (0);
E 4
I 4
		qsort(items, numitems, sizeof(items[1]), fcompare);
E 6
I 6
D 13
		qsort((char *)items, numitems, sizeof(items[1]), fcompare);
E 13
I 13
		qsort((char *)items, numitems, sizeof(items[1]), sortscmp);
E 13
E 6
		print_by_column(looking_for_lognames ? NULL : tilded_dir,
		    items, numitems);
		if (items != NULL)
			FREE_ITEMS(items);
	}
	return (0);
E 4
}

/*
 * Object: extend what user typed up to an ambiguity.
 * Algorithm:
 * On first match, copy full entry (assume it'll be the only match) 
 * On subsequent matches, shorten extended_name to the first
 * character mismatch between extended_name and entry.
 * If we shorten it back to the prefix length, stop searching.
 */
I 12
static
E 12
D 4
recognize (extended_name, entry, name_length, numitems)
char *extended_name, *entry;
E 4
I 4
recognize(extended_name, entry, name_length, numitems)
	char *extended_name, *entry;
E 4
{
D 4
    if (numitems == 1)				/* 1st match */
	copyn (extended_name, entry, MAXNAMLEN);
    else					/* 2nd and subsequent matches */
    {
	register char *x, *ent;
	register int len = 0;
	for (x = extended_name, ent = entry; *x && *x == *ent++; x++, len++);
	*x = '\0';				/* Shorten at 1st char diff */
	if (len == name_length)			/* Ambiguous to prefix? */
	    return (-1);			/* So stop now and save time */
    }
    return (0);
E 4
I 4

D 13
	if (numitems == 1)				/* 1st match */
E 13
I 13
	if (numitems == 1)			/* 1st match */
E 13
		copyn(extended_name, entry, MAXNAMLEN);
D 13
	else {					/* 2nd and subsequent matches */
E 13
I 13
	else {					/* 2nd & subsequent matches */
E 13
		register char *x, *ent;
		register int len = 0;

		x = extended_name;
		for (ent = entry; *x && *x == *ent++; x++, len++)
			;
		*x = '\0';			/* Shorten at 1st char diff */
		if (len == name_length)		/* Ambiguous to prefix? */
			return (-1);		/* So stop now and save time */
	}
	return (0);
E 4
}

/*
D 4
 * return true if check items initial chars in template
E 4
I 4
D 12
 * Return true if check items initial chars in template
E 12
I 12
 * Return true if check matches initial chars in template.
E 12
E 4
 * This differs from PWB imatch in that if check is null
D 12
 * it items anything
E 12
I 12
 * it matches anything.
E 12
 */
static
D 4
is_prefix (check, template)
char   *check,
       *template;
E 4
I 4
is_prefix(check, template)
D 11
	char *check, *template;
E 11
I 11
	register char *check, *template;
E 11
E 4
{
D 4
    register char  *check_char,
                   *template_char;
E 4
I 4
D 11
	register char *check_char, *template_char;
E 11
E 4

D 4
    check_char = check;
    template_char = template;
    do
	if (*check_char == 0)
	    return (TRUE);
    while (*check_char++ == *template_char++);
    return (FALSE);
E 4
I 4
D 11
	check_char = check;
	template_char = template;
E 11
	do
D 11
		if (*check_char == 0)
E 11
I 11
		if (*check == 0)
E 11
			return (TRUE);
D 11
	while (*check_char++ == *template_char++);
E 11
I 11
	while (*check++ == *template++);
E 11
	return (FALSE);
E 4
}

I 11
/*
 *  Return true if the chars in template appear at the
 *  end of check, I.e., are it's suffix.
 */
static
is_suffix(check, template)
	char *check, *template;
{
	register char *c, *t;

	for (c = check; *c++;)
		;
	for (t = template; *t++;)
		;
	for (;;) {
		if (t == template)
			return 1;
		if (c == check || *--t != *--c)
			return 0;
	}
}

E 11
D 4
tenex (inputline, inputline_size)
char   *inputline;
int     inputline_size;
E 4
I 4
tenex(inputline, inputline_size)
	char *inputline;
	int inputline_size;
E 4
{
D 4
    register int numitems, num_read;
E 4
I 4
	register int numitems, num_read;
E 4

D 4
    setup_tty (ON);
    while((num_read = read (SHIN, inputline, inputline_size)) > 0)
    {
	static char *delims = " '\"\t;&<>()|^%";
	register char *str_end, *word_start, last_char, should_retype;
	register int space_left;
	COMMAND command;
E 4
I 4
	setup_tty(ON);
D 11
	while ((num_read = read (SHIN, inputline, inputline_size)) > 0) {
E 11
I 11
	while ((num_read = read(SHIN, inputline, inputline_size)) > 0) {
E 11
		static char *delims = " '\"\t;&<>()|^%";
		register char *str_end, *word_start, last_char, should_retype;
		register int space_left;
		COMMAND command;
E 4

D 4
	last_char = inputline[num_read - 1] & 0177;
E 4
I 4
		last_char = inputline[num_read - 1] & 0177;
E 4

D 4
	if (last_char == '\n' || num_read == inputline_size)
	    break;
E 4
I 4
		if (last_char == '\n' || num_read == inputline_size)
			break;
		command = (last_char == ESC) ? RECOGNIZE : LIST;
		if (command == LIST)
D 11
			putchar ('\n');
E 11
I 11
D 16
			putchar('\n');
E 16
I 16
			cshputchar('\n');
E 16
E 11
		str_end = &inputline[num_read];
		if (last_char == ESC)
			--str_end;		/* wipeout trailing cmd char */
		*str_end = '\0';
		/*
		 * Find LAST occurence of a delimiter in the inputline.
		 * The word start is one character past it.
		 */
		for (word_start = str_end; word_start > inputline; --word_start)
			if (index(delims, word_start[-1]))
				break;
		space_left = inputline_size - (word_start - inputline) - 1;
		numitems = search(word_start, command, space_left);
E 4

D 4
	command = (last_char == ESC) ? RECOGNIZE : LIST;
E 4
I 4
		if (command == RECOGNIZE) {
			/* print from str_end on */
			print_recognized_stuff(str_end);
			if (numitems != 1)	/* Beep = No match/ambiguous */
D 11
				beep ();
E 11
I 11
				beep();
E 11
		}
E 4

D 4
	if (command == LIST)
	    putchar ('\n');

	str_end = &inputline[num_read];
	if(last_char == ESC)
	    --str_end;			/* wipeout trailing command character */
	*str_end = '\0';
	/*
	 * Find LAST occurence of a delimiter in the inputline.
	 * The word start is one character past it.
	 */
	for (word_start = str_end; word_start > inputline; --word_start)
	    if (index (delims, word_start[-1]))
		break;

	space_left = inputline_size - (word_start - inputline) - 1;

	numitems = search (word_start, command, space_left);

	if (command == RECOGNIZE)
	{
	    print_recognized_stuff (str_end);	/* Print from str_end on */
	    if (numitems != 1) 			/* Beep = No match/ambiguous */
		beep ();
E 4
I 4
		/*
		 * Tabs in the input line cause trouble after a pushback.
		 * tty driver won't backspace over them because column
		 * positions are now incorrect. This is solved by retyping
		 * over current line.
		 */
		should_retype = FALSE;
		if (index(inputline, '\t')) {	/* tab char in input line? */
			back_to_col_1();
			should_retype = TRUE;
		}
		if (command == LIST)		/* Always retype after a LIST */
			should_retype = TRUE;
		if (should_retype)
			printprompt();
		pushback(inputline);
		if (should_retype)
D 11
			retype ();
E 11
I 11
			retype();
E 11
E 4
	}
D 4

	/*
	 * Tabs in the input line cause trouble after a pushback.
	 * tty driver won't backspace over them because column positions
	 * are now incorrect. This is solved by retyping over current line.
	 */
	should_retype = FALSE;
	if (index (inputline, '\t'))		/* tab char in input line? */
	{
	    back_to_col_1 ();
	    should_retype = TRUE;
	}
	if (command == LIST)			/* Always retype after a LIST */
	    should_retype = TRUE;

	if (should_retype)
	    printprompt ();

	pushback (inputline);

	if (should_retype)
	    retype ();
    }

    setup_tty (OFF);

    return (num_read);
E 4
I 4
D 11
	setup_tty (OFF);
E 11
I 11
	setup_tty(OFF);
E 11
	return (num_read);
I 11
}

static
ignored(entry)
	register char *entry;
{
	struct varent *vp;
	register char **cp;

	if ((vp = adrof("fignore")) == NULL || (cp = vp->vec) == NULL)
		return (FALSE);
	for (; *cp != NULL; cp++)
		if (is_suffix(entry, *cp))
			return (TRUE);
	return (FALSE);
E 11
E 4
}
I 6
#endif FILEC
E 6
E 1
