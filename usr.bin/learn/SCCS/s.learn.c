h09184
s 00005/00001/00071
d D 4.4 86/05/15 17:58:21 bloom 6 5
c updates from John Kunze
e
s 00000/00003/00072
d D 4.3 84/05/15 11:19:09 ralph 5 4
c remove useless setbuf()'s.
e
s 00008/00001/00067
d D 4.2 83/04/27 15:26:06 mckusick 4 1
c now works with C shell and Ex -- see README for details
e
s 00000/00000/00075
d R 4.3 83/04/27 15:20:57 mckusick 3 2
c 
e
s 00008/00001/00067
d R 4.2 83/04/25 23:58:50 mckusick 2 1
c 
e
s 00068/00000/00000
d D 4.1 83/02/24 12:55:48 mckusick 1 0
c date and time created 83/02/24 12:55:48 by mckusick
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include "stdio.h"
#include "lrnref.h"
#include "signal.h"

char	*direct	= "/usr/lib/learn";	/* CHANGE THIS ON YOUR SYSTEM */
int	more;
char	*level;
int	speed;
char	*sname;
char	*todo;
FILE	*incopy	= NULL;
int	didok;
int	sequence	= 1;
int	comfile	= -1;
int	status;
int	wrong;
char	*pwline;
char	*dir;
FILE	*scrin;
int	logging	= 1;	/* set to 0 to turn off logging */
int	ask;
I 4
int	again;
int	skip;
int	teed;
int	total;
E 4

main(argc,argv)
I 4
int argc;
E 4
char *argv[];
{
	extern hangup(), intrpt();
D 6
	extern char * getlogin();
E 6
I 6
	extern char * getlogin(), *malloc();
E 6
D 5
	char *malloc();
E 5

	speed = 0;
	more = 1;
	pwline = getlogin();
I 6
#ifndef BSD4_2
	setbuf(stdout, malloc(BUFSIZ));
	setbuf(stderr, malloc(BUFSIZ));
#endif
E 6
D 5
	setbuf(stdout, malloc(BUFSIZ));
I 4
	setbuf(stderr, malloc(BUFSIZ));
E 5
E 4
	selsub(argc, argv);
I 4
	chgenv();
E 4
	signal(SIGHUP, hangup);
	signal(SIGINT, intrpt);
	while (more) {
		selunit();
		dounit();
		whatnow();
	}
	wrapup(0);
}

hangup()
{
	wrapup(1);
}

intrpt()
{
	char response[20], *p;

	signal(SIGINT, hangup);
	write(2, "\nInterrupt.\nWant to go on?  ", 28);
	p = response;
	*p = 'n';
	while (read(0, p, 1) == 1 && *p != '\n')
		p++;
	if (response[0] != 'y')
D 4
		wrapup(1);
E 4
I 4
		wrapup(0);
E 4
	ungetc('\n', stdin);
	signal(SIGINT, intrpt);
}
E 1
