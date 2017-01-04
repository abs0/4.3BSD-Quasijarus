h16028
s 00002/00006/00106
d D 5.4 88/05/04 13:55:57 rick 4 3
c show execution as uuxqt not UUXQT
e
s 00004/00002/00108
d D 5.3 85/06/23 14:02:08 bloom 3 2
c fixes form rick adams
e
s 00037/00016/00073
d D 5.2 85/01/22 14:14:18 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00089/00000/00000
d D 5.1 83/07/02 17:58:11 sam 1 0
c date and time created 83/07/02 17:58:11 by sam
e
u
U
t
T
I 1
#ifndef lint
D 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
I 4
static char sccsid[] = "%W%	(Berkeley) %G%";
E 4
#endif

D 3
#include "uucp.h"
E 3
#include <signal.h>
I 3
#include "uucp.h"
E 3

D 2
/*******
 *	xuucico(rmtname)		start up uucico for rmtname
 *	char *rmtname;
E 2
I 2
int LocalOnly = 0;

I 3
/*LINTLIBRARY*/

E 3
/*
 *	start up uucico for rmtname
E 2
 *
 *	return codes:  none
 */

I 2
#ifdef	VMS
#define	fork	vfork
#endif VMS

E 2
xuucico(rmtname)
char *rmtname;
{
	if (fork() == 0) {
		/*  start uucico for rmtname system  */
		char opt[100];
		close(0);
		close(1);
		close(2);
D 2
		open("/dev/null", 0);
		open("/dev/null", 1);
		open("/dev/null", 1);
E 2
I 2
		open(DEVNULL, 0);
		open(DEVNULL, 1);
		open(DEVNULL, 1);
E 2
		signal(SIGINT, SIG_IGN);
		signal(SIGHUP, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGKILL, SIG_IGN);
		if (rmtname[0] != '\0')
D 3
			sprintf(opt, "-s%.7s", rmtname);
E 3
I 3
			sprintf(opt, "-s%s", rmtname);
E 3
		else
			opt[0] = '\0';
D 2
		execl(UUCICO, "UUCICO", "-r1", opt, (char *)0);
E 2
I 2
#ifndef	VMS
		if (LocalOnly)
			execl(UUCICO, "uucico", "-r1", "-L", opt, (char *)0);
		else
			execl(UUCICO, "uucico", "-r1", opt, (char *)0);
#else	VMS
		/* Under VMS/EUNICE release the batch job */
		if (LocalOnly)
			execl(STARTUUCP, "startuucp", "uucico", "-r1", "-L", opt, (char *)0);
		else
			execl(STARTUUCP, "startuucp", "uucico", "-r1", opt, (char *)0);
#endif	VMS
E 2
		exit(100);
	}
I 2
#ifdef	VMS
	while(wait(0) != -1)
		;	/* Wait for it to finish!! */
#endif	VMS
E 2
	return;
}

D 4

E 4
D 2
/*******
 *	xuuxqt()		start up uuxqt
E 2
I 2
/*
 *	start up uuxqt
E 2
 *
 *	return codes:  none
 */
D 4

E 4
xuuxqt()
{
	if (fork() == 0) {
		/*  start uuxqt  */
		close(0);
		close(1);
		close(2);
D 2
		open("/dev/null", 2);
		open("/dev/null", 2);
		open("/dev/null", 2);
E 2
I 2
		open(DEVNULL, 2);
		open(DEVNULL, 2);
		open(DEVNULL, 2);
E 2
		signal(SIGINT, SIG_IGN);
		signal(SIGHUP, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGKILL, SIG_IGN);
D 4
		execl(UUXQT, "UUXQT",  (char *)0);
E 4
I 4
		execl(UUXQT, "uuxqt",  (char *)0);
E 4
		exit(100);
	}
D 4
	return;
E 4
}
I 2

E 2
xuucp(str)
char *str;
{
	char text[300];
	if (fork() == 0) {
		/*  start uucp  */
		close(0);
		close(1);
		close(2);
D 2
		open("/dev/null", 0);
		open("/dev/null", 1);
		open("/dev/null", 1);
E 2
I 2
		open(DEVNULL, 0);
		open(DEVNULL, 1);
		open(DEVNULL, 1);
E 2
		signal(SIGINT, SIG_IGN);
		signal(SIGHUP, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGKILL, SIG_IGN);
		sprintf(text, "%s -r %s", UUCP, str);
D 2
		execl(SHELL, "sh", "-c", text, (char *)0);
E 2
I 2
		execl(SHELL, "sh", "-c", text, CNULL);
E 2
		exit(100);
	}
	sleep(15);	/* Give uucp chance to finish */
D 4
	return;
E 4
}
E 1
