h58559
s 00004/00002/00243
d D 4.13 86/03/13 18:40:46 mckusick 13 12
c setgid to group "write" so that terminals need not be world writable
e
s 00006/00012/00239
d D 4.12 86/02/04 15:35:06 karels 12 11
c more grot
e
s 00029/00018/00222
d D 4.11 86/02/04 15:28:02 karels 11 10
c (once more?) look for writable terminal if first found isn't writable;
c if root, still look for writable terminal before barging in, but use first
c if none are writable
e
s 00003/00002/00237
d D 4.10 85/06/07 14:59:21 lepreau 10 9
c allow superuser to do anything
e
s 00054/00024/00185
d D 4.9 85/06/07 03:08:54 serge 9 8
c print visible representations of non printable characters
e
s 00001/00001/00208
d D 4.8 83/07/01 23:58:28 wnj 8 7
c include problems
e
s 00002/00002/00207
d D 4.7 83/03/01 21:58:24 leres 7 6
c Changed ^G's to \007's
e
s 00004/00001/00205
d D 4.6 82/07/14 21:24:24 kre 6 5
c indicate if write fails (usually since other end hung up).
e
s 00043/00043/00163
d D 4.5 82/03/15 04:25:01 root 5 4
c machine independent
e
s 00003/00002/00203
d D 4.4 82/01/27 10:16:01 root 4 3
c Changed notification of write message to include the system name
e
s 00008/00000/00197
d D 4.3 80/12/10 18:27:23 erics 3 2
c Check whether writer has write permission turned on
e
s 00002/00000/00195
d D 4.2 80/11/10 20:18:04 eric 2 1
c fix to bug when adding delete ttys lines
e
s 00195/00000/00000
d D 4.1 80/10/01 17:29:40 bill 1 0
c date and time created 80/10/01 17:29:40 by bill
e
u
U
t
T
I 9
#ifndef	lint
E 9
I 1
D 5
static char *sccsid = "%W% (Berkeley) %G%";
E 5
I 5
static char *sccsid = "%W% %G%";
I 9
#endif
E 9
E 5
/*
 * write to another user
 */

#include <stdio.h>
I 9
#include <ctype.h>
E 9
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <utmp.h>
D 8
#include <time.h>
E 8
I 8
#include <sys/time.h>
E 8
I 4
D 5
#include <whoami.h>
E 5
E 4

D 5
#define NMAX sizeof(ubuf.ut_name)
#define LMAX sizeof(ubuf.ut_line)
E 5
I 5
#define	NMAX	sizeof(ubuf.ut_name)
#define	LMAX	sizeof(ubuf.ut_line)
E 5

char	*strcat();
char	*strcpy();
struct	utmp ubuf;
int	signum[] = {SIGHUP, SIGINT, SIGQUIT, 0};
D 9
char	me[10]	= "???";
E 9
I 9
char	me[NMAX + 1]	= "???";
E 9
char	*him;
char	*mytty;
char	histty[32];
I 11
char	ttybuf[32];
E 11
char	*histtya;
char	*ttyname();
char	*rindex();
int	logcnt;
int	eof();
int	timout();
FILE	*tf;
char	*getenv();

main(argc, argv)
D 5
char *argv[];
E 5
I 5
	int argc;
	char *argv[];
E 5
{
	struct stat stbuf;
	register i;
	register FILE *uf;
	int c1, c2;
D 5
	long	clock = time( 0 );
E 5
I 5
	long clock = time(0);
I 10
	int suser = getuid() == 0;
I 11
	int nomesg = 0;
E 11
E 10
E 5
	struct tm *localtime();
	struct tm *localclock = localtime( &clock );

D 5
	if(argc < 2) {
E 5
I 5
	if (argc < 2) {
E 5
D 9
		printf("usage: write user [ttyname]\n");
E 9
I 9
		fprintf(stderr, "Usage: write user [ttyname]\n");
E 9
		exit(1);
	}
	him = argv[1];
D 5
	if(argc > 2)
E 5
I 5
	if (argc > 2)
E 5
		histtya = argv[2];
	if ((uf = fopen("/etc/utmp", "r")) == NULL) {
D 9
		printf("cannot open /etc/utmp\n");
E 9
I 9
		perror("write: Can't open /etc/utmp");
I 12
		if (histtya == 0)
			exit(10);
E 12
E 9
		goto cont;
	}
	mytty = ttyname(2);
	if (mytty == NULL) {
D 9
		printf("Can't find your tty\n");
E 9
I 9
		fprintf(stderr, "write: Can't find your tty\n");
E 9
		exit(1);
	}
I 3
D 5
	if (stat (mytty, &stbuf) < 0) {
		printf ("Can't stat your tty\n");
		exit (1);
E 5
I 5
	if (stat(mytty, &stbuf) < 0) {
D 9
		printf("Can't stat your tty\n");
E 9
I 9
		perror("write: Can't stat your tty");
E 9
		exit(1);
E 5
	}
D 10
	if ((stbuf.st_mode&02) == 0) {
E 10
I 10
D 11
	if (!suser && (stbuf.st_mode&02) == 0) {
E 11
I 11
D 13
	if ((stbuf.st_mode&02) == 0) {
E 13
I 13
	if ((stbuf.st_mode&020) == 0) {
E 13
E 11
E 10
D 5
		printf ("You have write permission turned off.\n");
		exit (1);
E 5
I 5
D 9
		printf("You have write permission turned off.\n");
E 9
I 9
		fprintf(stderr,
			"write: You have write permission turned off\n");
E 9
D 11
		exit(1);
E 11
I 11
		if (!suser)
			exit(1);
E 11
E 5
	}
E 3
	mytty = rindex(mytty, '/') + 1;
	if (histtya) {
		strcpy(histty, "/dev/");
		strcat(histty, histtya);
	}
	while (fread((char *)&ubuf, sizeof(ubuf), 1, uf) == 1) {
I 2
		if (ubuf.ut_name[0] == '\0')
			continue;
E 2
		if (strcmp(ubuf.ut_line, mytty)==0) {
D 5
			for(i=0; i<NMAX; i++) {
E 5
I 5
			for (i=0; i<NMAX; i++) {
E 5
				c1 = ubuf.ut_name[i];
D 5
				if(c1 == ' ')
E 5
I 5
				if (c1 == ' ')
E 5
					c1 = 0;
				me[i] = c1;
D 5
				if(c1 == 0)
E 5
I 5
				if (c1 == 0)
E 5
					break;
			}
		}
D 5
		if(him[0] != '-' || him[1] != 0)
		for(i=0; i<NMAX; i++) {
E 5
I 5
D 9
		if (him[0] != '-' || him[1] != 0)
E 9
I 9
		if (him[0] == '-' && him[1] == 0)
			goto nomat;
E 9
		for (i=0; i<NMAX; i++) {
E 5
			c1 = him[i];
			c2 = ubuf.ut_name[i];
D 5
			if(c1 == 0)
				if(c2 == 0 || c2 == ' ')
E 5
I 5
			if (c1 == 0)
				if (c2 == 0 || c2 == ' ')
E 5
					break;
D 5
			if(c1 != c2)
E 5
I 5
			if (c1 != c2)
E 5
				goto nomat;
		}
I 11
		if (histtya && strncmp(histtya, ubuf.ut_line,
		    sizeof(ubuf.ut_line)))
			continue;
E 11
		logcnt++;
D 11
		if (histty[0]==0) {
			strcpy(histty, "/dev/");
			strcat(histty, ubuf.ut_line);
E 11
I 11
		if (histty[0]==0 || nomesg && histtya == 0) {
			strcpy(ttybuf, "/dev/");
			strcat(ttybuf, ubuf.ut_line);
			if (histty[0]==0)
				strcpy(histty, ttybuf);
			if (access(ttybuf, 0) < 0 || stat(ttybuf, &stbuf) < 0 ||
D 13
			    (stbuf.st_mode&02) == 0)
E 13
I 13
			    (stbuf.st_mode&020) == 0)
E 13
				nomesg++;
			else {
				strcpy(histty, ttybuf);
				nomesg = 0;
			}
E 11
		}
	nomat:
		;
	}
D 12
cont:
E 12
I 12
	fclose(uf);
E 12
D 11
	if (logcnt==0 && histty[0]=='\0') {
E 11
I 11
	if (logcnt==0) {
E 11
D 9
		printf("%s not logged in.\n", him);
E 9
I 9
D 12
		fprintf(stderr, "write: %s not logged in\n", him);
E 12
I 12
		fprintf(stderr, "write: %s not logged in%s\n", him,
			histtya ? " on that tty" : "");
E 12
E 9
		exit(1);
	}
D 9
	fclose(uf);
E 9
I 9
D 12
	if (uf != NULL)
		fclose(uf);
E 12
E 9
	if (histtya==0 && logcnt > 1) {
D 9
		printf("%s logged more than once\nwriting to %s\n", him, histty+5);
E 9
I 9
		fprintf(stderr,
		"write: %s logged in more than once ... writing to %s\n",
			him, histty+5);
E 9
	}
D 5
	if(histty[0] == 0) {
E 5
I 5
D 11
	if (histty[0] == 0) {
E 11
I 11
D 12
	if (logcnt == 0) {
E 11
E 5
		printf(him);
D 5
		if(logcnt)
E 5
I 5
D 11
		if (logcnt)
E 5
			printf(" not on that tty\n"); else
E 11
I 11
		if (histtya)
			printf(" not on that tty\n");
		else
E 11
			printf(" not logged in\n");
		exit(1);
	}
E 12
I 12
cont:
E 12
	if (access(histty, 0) < 0) {
D 9
		printf("No such tty\n");
E 9
I 9
		fprintf(stderr, "write: No such tty\n");
E 9
		exit(1);
	}
	signal(SIGALRM, timout);
	alarm(5);
D 11
	if ((tf = fopen(histty, "w")) == NULL)
		goto perm;
E 11
I 11
	if ((tf = fopen(histty, "w")) == NULL) {
		fprintf(stderr, "write: Permission denied\n");
		exit(1);
	}
E 11
	alarm(0);
D 11
	if (fstat(fileno(tf), &stbuf) < 0)
		goto perm;
D 10
	if ((stbuf.st_mode&02) == 0)
E 10
I 10
	if (!suser && (stbuf.st_mode&02) == 0)
E 10
		goto perm;
E 11
	sigs(eof);
D 5
	fprintf(tf, "\r\nMessage from ");
#ifdef interdata
	fprintf(tf, "(Interdata) " );
#endif
D 4
	fprintf(tf, "%s on %s at %d:%02d ...\r\n"
	       , me, mytty , localclock -> tm_hour , localclock -> tm_min );
E 4
I 4
	fprintf(tf, "%s!%s on %s at %d:%02d ...\r\n"
	       , sysname , me, mytty , localclock -> tm_hour , localclock -> tm_min );
E 5
I 5
	{ char hostname[32];
	  gethostname(hostname, sizeof (hostname));
D 9
	  fprintf(tf, "\r\nMessage from ");
D 7
	  fprintf(tf, "%s!%s on %s at %d:%02d ...\r\n",
E 7
I 7
	  fprintf(tf, "%s!%s on %s at %d:%02d ...\r\n\007\007\007",
E 7
	      hostname, me, mytty, localclock->tm_hour, localclock->tm_min);
	}
E 9
I 9
	  fprintf(tf,
	      "\r\nMessage from %s@%s on %s at %d:%02d ...\r\n\007\007\007",
	      me, hostname, mytty, localclock->tm_hour, localclock->tm_min);
E 9
E 5
E 4
	fflush(tf);
I 9
	}
E 9
D 5
	for(;;) {
E 5
I 5
	for (;;) {
E 5
D 9
		char buf[128];
		i = read(0, buf, 128);
E 9
I 9
		char buf[BUFSIZ];
		register char *bp;
		i = read(0, buf, sizeof buf);
E 9
D 5
		if(i <= 0)
E 5
I 5
		if (i <= 0)
E 5
			eof();
D 5
		if(buf[0] == '!') {
E 5
I 5
		if (buf[0] == '!') {
E 5
			buf[i] = 0;
			ex(buf);
			continue;
		}
D 6
		write(fileno(tf), buf, i);
E 6
I 6
D 9
		if (write(fileno(tf), buf, i) != i) {
D 7
			printf("\n\7Write failed (%s logged out?)\n", him);
E 7
I 7
			printf("\n\007Write failed (%s logged out?)\n", him);
E 7
			exit(1);
E 9
I 9
		for (bp = buf; --i >= 0; bp++) {
			if (*bp == '\n')
				putc('\r', tf);

			if (!isascii(*bp)) {
				putc('M', tf);
				putc('-', tf);
				*bp = toascii(*bp);
			}

			if (isprint(*bp) ||
			    *bp == ' ' || *bp == '\t' || *bp == '\n') {
				putc(*bp, tf);
			} else {
				putc('^', tf);
				putc(*bp ^ 0100, tf);
			}

			if (*bp == '\n')
				fflush(tf);

			if (ferror(tf) || feof(tf)) {
				printf("\n\007Write failed (%s logged out?)\n",
					him);
				exit(1);
			}
E 9
		}
E 6
D 5
		if ( buf[ i - 1 ] == '\n' )
		    write( fileno( tf ) , "\r" , 1 );
E 5
I 5
D 9
		if (buf[i-1] == '\n')
			write(fileno(tf), "\r", 1);
E 9
E 5
	}
D 5

E 5
D 11
perm:
D 9
	printf("Permission denied\n");
E 9
I 9
	fprintf(stderr, "write: Permission denied\n");
E 9
	exit(1);
E 11
}

timout()
{

D 9
	printf("Timeout opening their tty\n");
E 9
I 9
	fprintf(stderr, "write: Timeout opening their tty\n");
E 9
	exit(1);
}

eof()
{

	fprintf(tf, "EOF\r\n");
	exit(0);
}

ex(bp)
D 5
char *bp;
E 5
I 5
	char *bp;
E 5
{
	register i;

	sigs(SIG_IGN);
	i = fork();
D 5
	if(i < 0) {
E 5
I 5
	if (i < 0) {
E 5
		printf("Try again\n");
		goto out;
	}
D 5
	if(i == 0) {
E 5
I 5
	if (i == 0) {
I 13
		fclose(tf);		/* Close his terminal */
		setgid(getgid());	/* Give up effective group privs */
E 13
E 5
		sigs((int (*)())0);
D 5
		execl(getenv("SHELL") ? getenv("SHELL") : "/bin/sh", "sh", "-c", bp+1, 0);
E 5
I 5
		execl(getenv("SHELL") ?
		    getenv("SHELL") : "/bin/sh", "sh", "-c", bp+1, 0);
E 5
		exit(0);
	}
D 5
	while(wait((int *)NULL) != i)
E 5
I 5
	while (wait((int *)NULL) != i)
E 5
		;
	printf("!\n");
out:
	sigs(eof);
}

sigs(sig)
D 5
int (*sig)();
E 5
I 5
	int (*sig)();
E 5
{
	register i;

D 5
	for(i=0;signum[i];i++)
		signal(signum[i],sig);
E 5
I 5
	for (i=0; signum[i]; i++)
		signal(signum[i], sig);
E 5
}
E 1
