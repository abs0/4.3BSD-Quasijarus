h06628
s 00003/00003/00456
d D 4.13 83/06/13 02:51:18 sam 15 14
c purge some old stuff
e
s 00000/00001/00459
d D 4.12 83/05/24 16:07:47 sam 14 13
c banner moved to getty.h
e
s 00001/00001/00459
d D 4.11 83/05/24 12:44:33 sam 13 12
c typo
e
s 00267/00098/00193
d D 4.10 83/05/23 01:52:15 sam 12 10
c mods from dlw; accept both #@ and CERASE/CKILL
e
s 00007/00005/00286
d R 4.10 83/02/09 14:33:03 sam 11 10
c from sun
e
s 00000/00009/00291
d D 4.9 82/12/23 13:12:14 sam 10 9
c use global definitions
e
s 00017/00000/00283
d D 4.8 82/04/08 00:45:21 sklower 9 8
c add port selector cycle (9600-300-1200) (by sklower)
e
s 00001/00001/00282
d D 4.7 82/03/27 22:39:29 wnj 8 7
c CRMOD on console
e
s 00002/00005/00281
d D 4.6 82/03/15 04:10:32 root 7 6
c machineindependent
e
s 00019/00021/00267
d D 4.5 82/02/26 14:06:17 root 6 5
c streamlined prints on login:
e
s 00001/00001/00287
d D 4.4 81/08/13 15:17:50 wnj 5 4
c bug fix per mrh
e
s 00005/00001/00283
d D 4.3 81/07/04 16:09:59 root 4 3
c fix to allow mixed case names per ittvax!swatt
e
s 00000/00001/00284
d D 4.2 81/02/28 23:05:04 wnj 3 1
c don't print Virtual...
e
s 00000/00000/00285
d R 4.2 81/01/09 19:17:29 root 2 1
c 
e
s 00285/00000/00000
d D 4.1 80/10/01 17:27:02 bill 1 0
c date and time created 80/10/01 17:27:02 by bill
e
u
U
t
T
I 1
D 6
static char *sccsid = "%W% (Berkeley) %G%";
E 6
I 6
D 12
static char *sccsid = "%W% %I% %E%";
E 12
I 12
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 12
E 6
/*
 * getty -- adapt to terminal speed on dialup, and call login
 */

I 12
#include <getty.h>
E 12
#include <sgtty.h>
#include <signal.h>
I 4
#include <ctype.h>
E 4
D 7
#include <ident.h>
I 6
#include <whoami.h>
E 7
E 6

I 12
D 13
#define BANNER	"\r\n\r\n4.2BSD UNIX (%s)\r\n\r\r\n\r%s" */
E 13
I 13
D 14
#define BANNER	"\r\n\r\n4.2BSD UNIX (%s)\r\n\r\r\n\r%s"
E 14
E 13
/* include 1200 baud in the dialup rotation */
#define	FASTDIALUP	1
/* take code for the Develcon data switch */
/*#define	PORTSELECTOR	GT_SELECTOR */
/* hang up the phone on dialups that don't log in */
#define	DROPDIALUP	1

/*
 * The old standard erase and kill are understood
 * as well as the (possibly different) system standard
 * erase and kill characters.
 */
E 12
#define ERASE	'#'
#define KILL	'@'

I 12
#define	DEFTAB	GT_DIALUP	/* Default speed table */
#define	DIALUP	GT_DIALUP	/* normal dialup table */

char	hostname[32];
char	prompt[] = "login: ";
E 12
D 10
#define	CEOT	004
#define	CKILL	'@'
#define	CQUIT	034		/* FS, cntl shift L */
#define	CINTR	0177		/* DEL */
#define	CSTOP	023		/* Stop output: ctl-s */
#define	CSTART	021		/* Start output: ctl-q */
#define	CBRK	0377


E 10
struct sgttyb tmode;

struct	tab {
	char	tname;		/* this table name */
	char	nname;		/* successor table name */
	int	iflags;		/* initial flags */
	int	fflags;		/* final flags */
	int	ispeed;		/* input speed */
	int	ospeed;		/* output speed */
	char	*message;	/* login message */
} itab[] = {

D 12
/* table '0'-1-2-3 300,1200,150,110 */
E 12
I 12
/* Table order based on baud rates as specified in <sgtty.h> */
/* Baud rates that are not particularly useful are omitted.  */
E 12

D 12
	'0', 1,
E 12
I 12
/* table '?' -- 50 */

/* table '?' -- 75 */

/* 110 baud */
	GT_B110, GT_B110,
	ANYP+RAW+NL1+CR1, ANYP+ECHO+CRMOD+XTABS+LCASE+CR1,
	B110, B110,
	prompt,

/* 134 baud */
	GT_B134, GT_B134,
	ANYP+RAW+NL1+CR1, EVENP+ECHO+FF1+CR2+TAB1+NL1,
	B134, B134,
	prompt,

/* 150 baud */
	GT_B150, GT_B150,
	ANYP+RAW+NL1+CR1, EVENP+ECHO+FF1+CR2+TAB1+NL1,
	B150, B150,
	"\033:\006\006\017login: ",

/* table '?' -- 200 */

/* 300 baud */
	GT_B300, GT_B300,
	ANYP+RAW+NL1+CR1, ANYP+XTABS+ECHO+CRMOD+CR1,
	B300, B300,
	prompt,

/* 600 baud */
	GT_B600, GT_B600,
	ANYP+RAW+NL1+CR1, ANYP+XTABS+ECHO+CRMOD+CR1,
	B600, B600,
	prompt,

/* 1200 baud */
	GT_B1200, GT_B1200,
	ANYP+RAW+NL1+CR1, ANYP+XTABS+ECHO+CRMOD+FF1,
	B1200, B1200,
	prompt,

/* table '?' -- 1800 */

/* 2400 baud */
	GT_B2400, GT_B2400 ,
	ANYP+RAW , ANYP+ECHO+CRMOD ,
	B2400 , B2400 ,
	prompt,
 
/* 4800 baud */
	GT_B4800 , GT_B4800 ,
	ANYP+RAW , ANYP+ECHO+CRMOD ,
	B4800 , B4800 ,
	prompt ,

/* 9600 baud */
	GT_B9600, GT_B9600,
	ANYP+RAW+NL1+CR1, ANYP+XTABS+ECHO+CRMOD,
	B9600, B9600,
	prompt,

/* 300,(1200,)150,110 baud -- Dialup lines */
	GT_DIALUP, 1,
E 12
	ANYP+RAW+NL1+CR1, ANYP+XTABS+ECHO+CRMOD+CR2,
	B300, B300,
D 6
	"\n\rlogin: ",
E 6
I 6
D 12
	"login: ",
E 12
I 12
	prompt,
E 12
E 6

I 12
#ifdef	FASTDIALUP
E 12
	1, 2,
	ANYP+RAW+NL1+CR1, ANYP+XTABS+ECHO+CRMOD+FF1,
	B1200, B1200,
D 6
	"\n\rlogin: ",
E 6
I 6
D 12
	"login: ",
E 12
I 12
	prompt,
E 12
E 6

	2, 3,
I 12
#else
	1, 3,
#endif
E 12
	ANYP+RAW+NL1+CR1, EVENP+ECHO+FF1+CR2+TAB1+NL1,
	B150, B150,
D 6
	"\n\rlogin: ",
E 6
I 6
D 12
	"login: ",
E 12
I 12
	prompt,
E 12
E 6

D 12
	3, '0',
E 12
I 12
	3, GT_DIALUP,
E 12
	ANYP+RAW+NL1+CR1, ANYP+ECHO+CRMOD+XTABS+LCASE+CR1,
	B110, B110,
D 6
	"\n\rlogin: ",
E 6
I 6
D 12
	"login: ",
E 12
I 12
	prompt,
E 12
E 6

D 12
/* table '-' -- Console TTY 110 */
	'-', '-',
E 12
I 12
/* Model 33 TTY, 110 baud */
	GT_TTY33, GT_TTY33,
E 12
	ANYP+RAW+NL1+CR1, ANYP+ECHO+CRMOD+XTABS+LCASE+CR1,
	B110, B110,
D 6
	"\n\rlogin: ",
E 6
I 6
D 12
	"login: ",
E 12
I 12
	prompt,
E 12
E 6

D 12
/* table '1' -- 150 */
	'1', '1',
	ANYP+RAW+NL1+CR1, EVENP+ECHO+FF1+CR2+TAB1+NL1,
	B150, B150,
	"\n\r\033:\006\006\017login: ",
E 12
I 12
/* Console Decwriter II */
	GT_DW2CONSOLE, GT_DW2CONSOLE,
	ANYP+RAW+CRMOD, ANYP+ECHO+CRMOD+XTABS,
	B300, B300,
	prompt,
E 12

D 12
/* table '2' -- 9600 */
	'2', '2',
	ANYP+RAW+NL1+CR1, ANYP+XTABS+ECHO+CRMOD,
	B9600, B9600,
D 6
	"\n\rlogin: ",
E 6
I 6
	"login: ",
E 6

/* table '3'-'5' -- 1200,300 */
	'3', '5',
E 12
I 12
/* 1200,300 baud -- typically dialup or hardcopy terminals */
	GT_FASTDIALUP, GT_FASTDIALUP1,
E 12
	ANYP+RAW+NL1+CR1, ANYP+XTABS+ECHO+CRMOD+FF1,
	B1200, B1200,
D 6
	"\n\rlogin: ",
E 6
I 6
D 12
	"login: ",
E 12
I 12
	prompt,
E 12
E 6

D 12
/* table '5'-'3' -- 300,1200 */
	'5', '3',
	ANYP+RAW+NL1+CR1, ANYP+ECHO+CR1,
E 12
I 12
	GT_FASTDIALUP1, GT_FASTDIALUP,
	ANYP+RAW+NL1+CR1, ANYP+ECHO+CRMOD+CR1,
E 12
	B300, B300,
D 6
	"\n\rlogin: ",
E 6
I 6
D 12
	"login: ",
E 12
I 12
	prompt,
E 12
E 6

D 12
/* table '4' -- Console Decwriter */
	'4', '4',
D 8
	ANYP+RAW, ANYP+ECHO+CRMOD+XTABS,
E 8
I 8
	ANYP+RAW+CRMOD, ANYP+ECHO+CRMOD+XTABS,
E 8
	B300, B300,
D 6
	"\n\rlogin: ",
E 6
I 6
	"login: ",
E 6

/* table '6' -- 2400  */
	'6', '6' ,
	ANYP+RAW , ANYP+ECHO+CRMOD ,
	B2400 , B2400 ,
D 6
	"\n\rlogin: ",
E 6
I 6
	"login: ",
E 6
 
/* table '7' - - 4800 */
	'7' , '7' ,
	ANYP+RAW , ANYP+ECHO+CRMOD ,
	B4800 , B4800 ,
D 6
	"\n\rlogin: " ,
E 6
I 6
	"login: " ,
E 6

/* table '8'-'9' - - 9600 - 300 */
	'8', '9',
E 12
I 12
/* 9600,300 baud -- typically CRTs with hardcopy */
	GT_CRT_HCPY, GT_HCPY_CRT,
E 12
	ANYP+RAW+NL1+CR1, ANYP+XTABS+ECHO+CRMOD,
	B9600, B9600,
D 6
	"\n\rlogin: ",
E 6
I 6
D 12
	"login: ",
E 12
I 12
	prompt,
E 12
E 6

D 12
	'9', '8',
E 12
I 12
	GT_HCPY_CRT, GT_CRT_HCPY,
E 12
	ANYP+RAW+NL1+CR2, ANYP+XTABS+ECHO+CRMOD+CR2,
	B300, B300,
D 6
	"\n\rlogin: ",
E 6
I 6
D 12
	"login: ",
E 12
I 12
	prompt,
E 12
E 6

D 12
/* table 'i' -- Interdata Console */
	'i', 'i',
	RAW+CRMOD, CRMOD+ECHO+LCASE,
	0, 0,
D 6
	"\n\rlogin: ",
E 6
I 6
	"login: ",
E 6

/* table 'l' -- LSI Chess Terminal */
	'l', 'l',
	ANYP+RAW/*+HUPCL*/, ANYP+ECHO/*+HUPCL*/,
	B300, B300,
	"*",
I 9

/* table 'p'-'q'-'r' -- 9600 - 300 - 1200 */
	'p', 'q',
E 12
I 12
/* 9600-300-1200 -- Plugboard or CRT's with slow hardcopy */
	GT_PLUGBOARD, GT_PLUGBOARD1,
E 12
	ANYP+RAW+NL1+CR1, ANYP+XTABS+ECHO+CRMOD,
	B9600, B9600,
D 12
	"login: ",
E 12
I 12
	prompt,
E 12

D 12
	'q', 'r',
E 12
I 12
	GT_PLUGBOARD1, GT_PLUGBOARD2,
E 12
	ANYP+RAW+NL1+CR2, ANYP+XTABS+ECHO+CRMOD+CR2,
	B300, B300,
D 12
	"login: ",
E 12
I 12
	prompt,
E 12

D 12
	'r', 'p',
E 12
I 12
	GT_PLUGBOARD2, GT_PLUGBOARD,
E 12
	ANYP+RAW+NL1+CR1, ANYP+XTABS+ECHO+CRMOD+FF1,
	B1200, B1200,
D 12
	"login: ",
E 12
I 12
	prompt,
E 12

I 12
/* Interdata Console */
	GT_INTERDATA, GT_INTERDATA,
	RAW+CRMOD, CRMOD+ECHO+LCASE,
	0, 0,
	prompt,

/* LSI Chess Terminal */
	GT_CHESS, GT_CHESS,
	ANYP+RAW/*+HUPCL*/, ANYP+ECHO/*+HUPCL*/,
	B300, B300,
	"*",
E 12
E 9
};

#define	NITAB	sizeof itab/sizeof itab[0]
#define	EOT	04		/* EOT char */

char	name[16];
int	crmod;
int	upper;
int	lower;

char partab[] = {
	0001,0201,0201,0001,0201,0001,0001,0201,
	0202,0004,0003,0205,0005,0206,0201,0001,
	0201,0001,0001,0201,0001,0201,0201,0001,
	0001,0201,0201,0001,0201,0001,0001,0201,
	0200,0000,0000,0200,0000,0200,0200,0000,
	0000,0200,0200,0000,0200,0000,0000,0200,
	0000,0200,0200,0000,0200,0000,0000,0200,
	0200,0000,0000,0200,0000,0200,0200,0000,
	0200,0000,0000,0200,0000,0200,0200,0000,
	0000,0200,0200,0000,0200,0000,0000,0200,
	0000,0200,0200,0000,0200,0000,0000,0200,
	0200,0000,0000,0200,0000,0200,0200,0000,
	0000,0200,0200,0000,0200,0000,0000,0200,
	0200,0000,0000,0200,0000,0200,0200,0000,
	0200,0000,0000,0200,0000,0200,0200,0000,
	0000,0200,0200,0000,0200,0000,0000,0201
};

I 12
#ifdef DROPDIALUP
dropdtr()
{

	ioctl(0, TIOCHPCL, 0);
	exit(1);
}
#endif

E 12
main(argc, argv)
D 12
char **argv;
E 12
I 12
	char *argv[];
E 12
{
	register struct tab *tabp;
	char tname;
	struct tchars tc;
I 12
	int flush_noise = 1;
#ifdef PORTSELECTOR
	char getspeed();
#endif
E 12

D 12
/*
	signal(SIGINT, 1);
	signal(SIGQUIT, 0);
*/
	tname = '0';
E 12
I 12
	gethostname(hostname, sizeof(hostname));
	tname = DEFTAB;
E 12
	if (argc > 1)
		tname = argv[1][0];
I 12
	if (tname == DIALUP) {
#if DROPDIALUP
		signal(SIGALRM, dropdtr);
		alarm(5*60);
#endif
		flush_noise = 0;
	}
#ifdef PORTSELECTOR
	if (tname == PORTSELECTOR) {
		ioctl(0, TIOCHPCL, 0);
		alarm(5*60);
		tname = getspeed();
		flush_noise = 0;
		sleep(2);	/* wait for connection to complete */
	}
#endif
E 12
	for (;;) {
		int ldisp = 0;
		for(tabp = itab; tabp < &itab[NITAB]; tabp++)
			if(tabp->tname == tname)
				break;
D 12
		if(tabp >= &itab[NITAB])
E 12
I 12
		if (tabp >= &itab[NITAB])
E 12
			tabp = itab;
		tmode.sg_ispeed = tabp->ispeed;
		tmode.sg_ospeed = tabp->ospeed;
		tmode.sg_flags = tabp->iflags;
		tmode.sg_ispeed = tabp->ispeed;
		tmode.sg_ospeed = tabp->ospeed;
D 15
		stty(0, &tmode);
E 15
I 15
		ioctl(0, TIOCSETP, &tmode);
E 15
		tc.t_intrc = CINTR;
		tc.t_quitc = CQUIT;
		tc.t_stopc = CSTOP;
		tc.t_startc = CSTART;
		tc.t_brkc = CBRK;
		tc.t_eofc = CEOT;
		ioctl(0, TIOCSETC, &tc);
		ioctl(0, TIOCSETD, &ldisp);
D 6
		if (tmode.sg_ospeed > B1200)
			puts("\n\r\n\r");
		else
			puts("\n\r\r\r\r\r\n\r\r\r\r\r");
D 3
		puts("Virtual ");
E 3
		puts(myname);
		puts("\n\r\r\r\r");
E 6
I 6
D 12
		putchr('\r'); putchr('\n');
D 7
		puts(sysname);
		puts(" ");
E 6
		puts(tabp->message);
E 7
I 7
		{ char hostname[32]; gethostname(hostname, sizeof (hostname));
		  puts(hostname); puts(" "); puts(tabp->message); }
E 7
		/*
		 * Wait a while, then flush input to get rid
		 * of noise from open lines
		 */
		sleep(1);
		stty(0, &tmode);
		if(getname()) {
E 12
I 12
		printf(BANNER, hostname, tabp->message);
		if (flush_noise) {
			/*
			 * Wait a while, then flush input to get rid
			 * of noise from open lines
			 */
			sleep(1);
D 15
			stty(0, &tmode);
E 15
I 15
			ioctl(0, TIOCSETP, &tmode);
E 15
		}
		if (getname()) {
E 12
			if (upper == 0 && lower == 0)
				continue;
			tmode.sg_erase = ERASE;
			tmode.sg_kill = KILL;
			tmode.sg_flags = tabp->fflags;
			if(crmod)
				tmode.sg_flags |= CRMOD;
			if(upper)
				tmode.sg_flags |= LCASE;
			if(lower)
				tmode.sg_flags &= ~LCASE;
D 15
			stty(0, &tmode);
E 15
I 15
			ioctl(0, TIOCSETP, &tmode);
E 15
			putchr('\n');
			execl("/bin/login", "login", name, 0);
			exit(1);
		}
		tname = tabp->nname;
	}
}

getname()
{
	register char *np;
	register c;
	char cs;

	crmod = 0;
	upper = 0;
	lower = 0;
	np = name;
	for (;;) {
D 12
		if (read(0, &cs, 1) <= 0)
E 12
I 12
		if (getchr(&cs) <= 0)
E 12
			exit(0);
D 12
		if ((c = cs&0177) == 0)
E 12
I 12
		if ((c = cs) == 0)
E 12
			return(0);
D 12
		if (c==EOT)
E 12
I 12
		if (c == EOT)
E 12
			exit(1);
D 12
		if (c=='\r' || c=='\n' || np >= &name[16])
E 12
I 12
		if (c == '\r' || c == '\n' || np >= &name[16])
E 12
			break;
		putchr(cs);
		if (c>='a' && c <='z')
			lower++;
D 12
		else if (c>='A' && c<='Z') {
E 12
I 12
		else if (c >= 'A' && c <= 'Z')
E 12
			upper++;
D 4
			c += 'a'-'A';
E 4
D 12
		} else if (c==ERASE) {
E 12
I 12
		else if (c == ERASE || c == CERASE) {
E 12
			if (np > name)
				np--;
			continue;
D 12
		} else if (c==KILL) {
E 12
I 12
		} else if (c == KILL || c == CKILL) {
E 12
			putchr('\r');
			putchr('\n');
			np = name;
			continue;
D 12
		} else if(c == ' ')
E 12
I 12
		} else if (c == ' ')
E 12
			c = '_';
		*np++ = c;
	}
	*np = 0;
	if (c == '\r')
		crmod++;
I 4
	if (upper && !lower)
		for (np = name; *np; np++)
			if (isupper(*np))
D 5
				np = tolower(*np);
E 5
I 5
				*np = tolower(*np);
E 5
E 4
D 12
	return(1);
E 12
I 12
	return (1);
E 12
}

I 12
/*
 * Very simple version - only knows about %s
 */
printf(fmt, args)
	char *fmt;
	struct { char *str[10]; } args;
{
	register char *f, **as;

	for (f = fmt, as = args.str; *f; f++) {
		if (*f != '%') {
			putchr(*f);
			continue;
		}
		switch (*++f) {

		case 's':
			puts(*as++);
			break;

		default:
			putchr(*f);
		}
	}
}

E 12
puts(as)
D 12
char *as;
E 12
I 12
	char *as;
E 12
{
	register char *s;

	s = as;
	while (*s)
		putchr(*s++);
}

putchr(cc)
{
	char c;
	c = cc;
	c |= partab[c&0177] & 0200;
	write(1, &c, 1);
}
I 12

getchr(c)
	char *c;
{
	int n;
	n = read(0, c, 1);
	*c &= 0177;
	return (n);
}

#ifdef PORTSELECTOR
/*
 * This speed select mechanism is written for the Develcon DATASWITCH.
 * The Develcon sends a string of the form "B{speed}\n" at a predefined
 * baud rate. This string indicates the user's actual speed.
 * The routine below returns the appropriate table identifier.
 */
struct speedtab {
	char	speed[7];
	char	tabname;
} st[] = {
	"B110",		GT_B110,
	"B134",		GT_B134,
	"B150",		GT_B150,
	"B300",		GT_B300,
	"B600",		GT_B600,
	"B1200",	GT_B1200,
	"B2400",	GT_B2400,
	"B4800",	GT_B4800,
	"B9600",	GT_B9600,
	"",		DEFTAB
};

char	user_spd[7];

char
getspeed()
{
	char c;
	int i = 0;

	while (getchr(&c) > 0 && c != '\n' && c != '\r') {
		if (c == 'B')
			i = 0;		/* in case of leading garbage */
		if (i < (sizeof (user_spd) - 1))
			user_spd[i++] = c;
	}
	user_spd[i] = '\0';
	for (i = 0; st[i].speed[0]; i++)
		if (strcmp(st[i].speed, user_spd) == 0)
			break;
	return (st[i].tabname);
}
#endif
E 12
E 1
