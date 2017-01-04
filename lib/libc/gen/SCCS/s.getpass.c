h57037
s 00002/00002/00042
d D 5.2 86/03/09 19:48:03 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00040
d D 5.1 85/06/05 12:22:08 mckusick 4 3
c Add copyright
e
s 00003/00003/00038
d D 4.3 84/05/16 10:58:16 ralph 3 2
c inline expand gtty() and stty().
e
s 00002/00002/00039
d D 4.2 81/07/01 16:58:56 root 2 1
c allow for prompts with % and flush stderr
e
s 00041/00000/00000
d D 4.1 80/12/21 16:50:35 wnj 1 0
c date and time created 80/12/21 16:50:35 by wnj
e
u
U
t
T
I 1
D 4
/* %W% (Berkeley) %G% */
E 4
I 4
D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS and not lint
E 5

E 4
#include <stdio.h>
#include <signal.h>
#include <sgtty.h>

char *
getpass(prompt)
char *prompt;
{
	struct sgttyb ttyb;
	int flags;
	register char *p;
	register c;
	FILE *fi;
	static char pbuf[9];
	int (*signal())();
	int (*sig)();

	if ((fi = fdopen(open("/dev/tty", 2), "r")) == NULL)
		fi = stdin;
	else
		setbuf(fi, (char *)NULL);
	sig = signal(SIGINT, SIG_IGN);
D 3
	gtty(fileno(fi), &ttyb);
E 3
I 3
	ioctl(fileno(fi), TIOCGETP, &ttyb);
E 3
	flags = ttyb.sg_flags;
	ttyb.sg_flags &= ~ECHO;
D 3
	stty(fileno(fi), &ttyb);
E 3
I 3
	ioctl(fileno(fi), TIOCSETP, &ttyb);
E 3
D 2
	fprintf(stderr, prompt);
E 2
I 2
	fprintf(stderr, "%s", prompt); fflush(stderr);
E 2
	for (p=pbuf; (c = getc(fi))!='\n' && c!=EOF;) {
		if (p < &pbuf[8])
			*p++ = c;
	}
	*p = '\0';
D 2
	fprintf(stderr, "\n");
E 2
I 2
	fprintf(stderr, "\n"); fflush(stderr);
E 2
	ttyb.sg_flags = flags;
D 3
	stty(fileno(fi), &ttyb);
E 3
I 3
	ioctl(fileno(fi), TIOCSETP, &ttyb);
E 3
	signal(SIGINT, sig);
	if (fi != stdin)
		fclose(fi);
	return(pbuf);
}
E 1
