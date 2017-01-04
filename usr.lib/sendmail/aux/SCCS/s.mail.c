h56027
s 00001/00001/00732
d D 4.33 88/02/27 14:11:16 bostic 35 34
c 2.10BSD int/long fixes
e
s 00008/00009/00725
d D 4.32 88/02/27 14:01:11 bostic 34 33
c 2.10BSD int/long fixes
e
s 00004/00016/00730
d D 4.31 88/01/12 22:10:10 bostic 33 32
c check getpwuid(getuid()) in all cases; minor cleanup
e
s 00003/00003/00743
d D 4.30 87/10/22 09:52:09 bostic 32 31
c ANSI C; sprintf now returns an int.
e
s 00002/00002/00744
d D 4.29 87/09/16 13:57:16 bostic 31 30
c getpwnam fix; bug report 4.3BSD/bin/67
e
s 00002/00001/00744
d D 4.28 87/05/30 16:45:17 bostic 30 29
c check return of socket call
e
s 00001/00001/00744
d D 4.27 86/08/12 15:54:54 karels 29 28
c fix keywords
e
s 00023/00017/00722
d D 4.26 86/08/12 15:48:24 karels 28 27
c fix buffer overrun with -r; don't loop on faults
e
s 00008/00001/00731
d D 4.25 85/05/01 16:29:51 miriam 27 26
c Close getlogin problem
e
s 00003/00004/00729
d D 4.24 84/12/18 14:03:54 ralph 26 25
c use mkstemp so people can't substitute a symlink for the temp file.
e
s 00022/00025/00711
d D 4.23 84/08/27 09:24:00 ralph 25 24
c fix uucp mail when given -d option.
e
s 00230/00310/00506
d D 4.22 84/07/19 15:39:55 ralph 24 23
c use flock for mailbox locking
e
s 00000/00000/00816
d D 4.21 83/11/01 10:02:02 karels 23 22
x 21 20
c un-protect -r (removing deltas 4.18, 4.19), so sendmail
c doesn't have to be setuid root and uucp can be known by other names
e
s 00001/00000/00820
d D 4.20 83/10/27 17:00:59 karels 22 21
c usage() sets error status EX_USAGE
e
s 00010/00011/00810
d D 4.19 83/10/25 09:04:27 eric 21 20
c fix botch in 4.18 that rejects all incoming UUCP mail; -r by a normal user
c how just ignores the -r flag rather than rejecting the mail.
e
s 00006/00000/00815
d D 4.18 83/09/09 16:11:07 ralph 20 19
c protects the -r option.
e
s 00001/00001/00814
d D 4.17 83/09/07 09:29:53 ralph 19 18
c only trap signals SIGHUP to SIGTERM, not 0 - 20.
e
s 00004/00002/00811
d D 4.16 83/08/11 19:52:44 sam 18 17
c sccs keyword fixes
e
s 00001/00001/00812
d D 4.15 83/04/12 02:53:41 leres 17 16
c Changed mode of created mail to 600; just like they do in the real world.
e
s 00008/00003/00805
d D 4.14 83/04/10 16:40:46 eric 16 15
c move call to lock before the fopen for append; change decl of "k" in
c copylet from int to long for PDP-11's.  Thanks to Jay Lepreau for these.
e
s 00001/00002/00807
d D 4.13 83/02/09 09:23:59 eric 15 14
c check uux exit status in the forward case; this doesn't happen with
c sendmail, but it offends my sensibilities anyhow.
e
s 00016/00004/00793
d D 4.12 83/01/31 21:18:18 eric 14 13
c patch BIG security hole with symbolic links (oh boy, was this one big!)
e
s 00014/00010/00783
d D 4.11 83/01/10 17:28:55 sam 13 12
c fix biff (rah rah -- sis boom bah)
e
s 00005/00005/00788
d D 4.10 82/12/26 21:34:43 eric 12 11
c change delivermail to sendmail throughout
e
s 00003/00003/00790
d D 4.9 82/11/14 16:33:19 sam 11 10
c convert to 4.1c sys calls and directory layout
e
s 00004/00001/00789
d D 4.8 82/03/31 12:02:35 root 10 9
c no more wellknown.h
e
s 00005/00073/00785
d D 4.7 82/03/15 04:18:08 root 9 8
c machine independent
e
s 00017/00009/00841
d D 4.6 82/02/28 23:59:42 wnj 8 7
c security merged with biff
e
s 00001/00000/00849
d D 4.5 81/10/03 17:45:05 root 7 6
c setuid(getuid()) before execv(DELIVERMAIL)
e
s 00001/00001/00848
d D 4.4 81/10/03 15:52:47 root 6 5
c typo
e
s 00005/00001/00844
d D 4.3 81/10/03 15:46:15 root 5 4
c don't write to mail files with > 1 link
e
s 00010/00000/00835
d D 4.2 81/05/08 15:02:21 wnj 4 3
c added biff to /bin/mail
e
s 00000/00000/00835
d D 4.1 80/10/01 16:39:20 bill 3 2
c Define 4.1
e
s 00013/00002/00822
d D 1.2 80/08/04 23:13:56 eric 2 1
c took out some stuff that delivermail does better (but made it
c 
e
s 00824/00000/00000
d D 1.1 80/08/04 22:59:44 root 1 0
c date and time created 80/08/04 22:59:44 by root
e
u
U
t
T
I 18
#ifndef lint
D 28
static char sccsid[] = "%W% (Berkeley) %G%";
E 28
I 28
D 29
static char sccsid[] = "@(#)mail.c	4.25 (Berkeley) 5/1/85";
E 29
I 29
static char sccsid[] = "%W% (Berkeley) %G%";
E 29
E 28
#endif

I 24
D 28
#include <sys/types.h>
E 28
I 28
#include <sys/param.h>
E 28
#include <sys/stat.h>
#include <sys/file.h>

E 24
E 18
I 1
#include <ctype.h>
#include <stdio.h>
#include <pwd.h>
#include <utmp.h>
#include <signal.h>
D 24
#include <sys/types.h>
#include <sys/stat.h>
E 24
#include <setjmp.h>
D 9
#include <whoami.h>
E 9
#include <sysexits.h>
D 18

I 2
static char SccsId[] = "%W%	%G%";
E 18

E 2
D 12
#define DELIVERMAIL	"/etc/delivermail"
E 12
I 12
#define SENDMAIL	"/usr/lib/sendmail"
E 12

I 24
	/* copylet flags */
#define REMOTE		1		/* remote mail, add rmtmsg */
#define ORDINARY	2
#define ZAP		3		/* zap header and trailing empty line */
#define	FORWARD		4
E 24

D 24
/*copylet flags */
	/*remote mail, add rmtmsg */
#define REMOTE	1
	/* zap header and trailing empty line */
#define ZAP	3
#define ORDINARY 2
#define	FORWARD	4
#define	LSIZE	256
#define	MAXLET	300	/* maximum number of letters */
D 17
#define	MAILMODE (~0644)		/* mode of created mail */
E 17
I 17
#define	MAILMODE (~0600)		/* mode of created mail */
E 24
I 24
#define	LSIZE		256
#define	MAXLET		300		/* maximum number of letters */
#define	MAILMODE	0600		/* mode of created mail */
E 24
E 17
I 2
D 9
# ifndef DELIVERMAIL
E 2
#define	RMAIL	"/usr/net/bin/sendberkmail"
#define LOCNAM1	"csvax"
#define LOCNAM2	"ucbvax"
#define LOCNAM3	"vax"
#define LOCNAM4	"v"
I 2
# endif
E 9
E 2

char	line[LSIZE];
char	resp[LSIZE];
struct let {
	long	adr;
	char	change;
} let[MAXLET];
int	nlet	= 0;
char	lfil[50];
long	iop, time();
char	*getenv();
char	*index();
char	lettmp[] = "/tmp/maXXXXX";
char	maildir[] = "/usr/spool/mail/";
char	mailfile[] = "/usr/spool/mail/xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
char	dead[] = "dead.letter";
D 9
char	*thissys = sysname;
E 9
D 24
char	*netname = "vax";
E 24
char	forwmsg[] = " forwarded\n";
FILE	*tmpf;
FILE	*malf;
D 28
char	*my_name;
E 28
I 28
char	my_name[60];
E 28
char	*getlogin();
D 24
struct	passwd	*getpwuid();
E 24
int	error;
int	changed;
int	forward;
char	from[] = "From ";
long	ftell();
D 24
int	delete();
E 24
I 24
int	delex();
E 24
char	*ctime();
int	flgf;
int	flgp;
int	delflg = 1;
int	hseqno;
jmp_buf	sjbuf;
int	rmail;

main(argc, argv)
char **argv;
{
D 33
	register i;
E 33
I 33
	register int i;
E 33
I 28
	char *name;
E 28
I 27
	struct passwd *pwent;
E 27
D 24
	char sobuf[BUFSIZ];
E 24

D 24
	setbuf(stdout, sobuf);
E 24
D 26
	mktemp(lettmp);
	unlink(lettmp);
E 26
D 28
	my_name = getlogin();
D 24
	if (my_name == NULL || strlen(my_name) == 0) {
E 24
I 24
	if (my_name == NULL || *my_name == '\0') {
E 28
I 28
D 33
	name = getlogin();
	if (name == NULL || *name == '\0') {
E 33
I 33
	if (!(name = getlogin()) || !*name || !(pwent = getpwnam(name)) ||
	    getuid() != pwent->pw_uid) 
E 33
E 28
E 24
D 27
		struct passwd *pwent;
E 27
		pwent = getpwuid(getuid());
D 33
		if (pwent==NULL)
D 28
			my_name = "???";
E 28
I 28
			name = "???";
E 28
		else
D 28
			my_name = pwent->pw_name;
E 28
I 28
			name = pwent->pw_name;
E 28
I 27
	}
	else {
D 31
		pwent = getpwnam(my_name);
		if ( getuid() != pwent->pw_uid) {
E 31
I 31
		pwent = getpwnam(name);
		if (!pwent || getuid() != pwent->pw_uid) {
E 31
			pwent = getpwuid(getuid());
D 28
			my_name = pwent->pw_name;
E 28
I 28
			name = pwent->pw_name;
E 28
		}
E 27
	}
I 28
	strncpy(my_name, name, sizeof(my_name)-1);
E 33
I 33
	strncpy(my_name, pwent ? pwent->pw_name : "???", sizeof(my_name)-1);
E 33
E 28
D 24
	if(setjmp(sjbuf)) done();
D 19
	for (i=0; i<20; i++)
E 19
I 19
	for (i=SIGHUP; i<=SIGTERM; i++)
E 19
		setsig(i, delete);
	tmpf = fopen(lettmp, "w");
	if (tmpf == NULL) {
		fprintf(stderr, "mail: cannot open %s for writing\n", lettmp);
E 24
I 24
	if (setjmp(sjbuf))
E 24
		done();
D 24
	}
E 24
I 24
	for (i=SIGHUP; i<=SIGTERM; i++)
		setsig(i, delex);
D 26
	tmpf = fopen(lettmp, "w+r");
	if (tmpf == NULL)
E 26
I 26
	i = mkstemp(lettmp);
	tmpf = fdopen(i, "r+w");
	if (i < 0 || tmpf == NULL)
E 26
		panic("mail: %s: cannot open for writing", lettmp);
	/*
	 * This protects against others reading mail from temp file and
	 * if we exit, the file will be deleted already.
	 */
	unlink(lettmp);
E 24
	if (argv[0][0] == 'r')
		rmail++;
	if (argv[0][0] != 'r' &&	/* no favors for rmail*/
	   (argc == 1 || argv[1][0] == '-' && !any(argv[1][1], "rhd")))
		printmail(argc, argv);
	else
D 8
		sendmail(argc, argv);
E 8
I 8
		bulkmail(argc, argv);
E 8
	done();
}

setsig(i, f)
int i;
int (*f)();
{
D 24
	if(signal(i, SIG_IGN)!=SIG_IGN)
E 24
I 24
	if (signal(i, SIG_IGN) != SIG_IGN)
E 24
		signal(i, f);
}

any(c, str)
	register int c;
	register char *str;
{

	while (*str)
		if (c == *str++)
			return(1);
	return(0);
}

printmail(argc, argv)
D 24
char **argv;
E 24
I 24
	char **argv;
E 24
{
	int flg, i, j, print;
	char *p, *getarg();
	struct stat statb;

	setuid(getuid());
	cat(mailfile, maildir, my_name);
I 24
#ifdef notdef
E 24
	if (stat(mailfile, &statb) >= 0
	    && (statb.st_mode & S_IFMT) == S_IFDIR) {
		strcat(mailfile, "/");
		strcat(mailfile, my_name);
	}
D 24
	for (; argc>1; argv++, argc--) {
		if (argv[1][0]=='-') {
			if (argv[1][1]=='q')
				delflg = 0;
			else if (argv[1][1]=='p') {
				flgp++;
				delflg = 0;
			} else if (argv[1][1]=='f') {
				if (argc>=3) {
					strcpy(mailfile, argv[2]);
					argv++;
					argc--;
				}
			} else if (argv[1][1]=='r') {
				forward = 1;
			} else if (argv[1][1]=='h') {
				forward = 1;
			} else {
				fprintf(stderr, "mail: unknown option %c\n", argv[1][1]);
				done();
E 24
I 24
#endif
	for (; argc > 1; argv++, argc--) {
		if (argv[1][0] != '-')
			break;
		switch (argv[1][1]) {

		case 'p':
			flgp++;
			/* fall thru... */
		case 'q':
			delflg = 0;
			break;

		case 'f':
			if (argc >= 3) {
				strcpy(mailfile, argv[2]);
				argv++, argc--;
E 24
			}
D 24
		} else
E 24
			break;
I 24

		case 'b':
			forward = 1;
			break;

		default:
			panic("unknown option %c", argv[1][1]);
			/*NOTREACHED*/
		}
E 24
	}
	malf = fopen(mailfile, "r");
	if (malf == NULL) {
D 24
		fprintf(stdout, "No mail.\n");
E 24
I 24
		printf("No mail.\n");
E 24
		return;
	}
D 24
	lock(mailfile);
E 24
I 24
	flock(fileno(malf), LOCK_SH);
E 24
	copymt(malf, tmpf);
D 24
	fclose(malf);
	fclose(tmpf);
	unlock();
	tmpf = fopen(lettmp, "r");
E 24
I 24
	fclose(malf);			/* implicit unlock */
D 34
	fseek(tmpf, 0, L_SET);
E 34
I 34
	fseek(tmpf, 0L, L_SET);
E 34
E 24

	changed = 0;
	print = 1;
	for (i = 0; i < nlet; ) {
		j = forward ? i : nlet - i - 1;
D 24
		if(setjmp(sjbuf)) {
			print=0;
E 24
I 24
		if (setjmp(sjbuf)) {
			print = 0;
E 24
		} else {
			if (print)
				copylet(j, stdout, ORDINARY);
			print = 1;
		}
		if (flgp) {
			i++;
			continue;
		}
		setjmp(sjbuf);
D 24
		fprintf(stdout, "? ");
E 24
I 24
		fputs("? ", stdout);
E 24
		fflush(stdout);
		if (fgets(resp, LSIZE, stdin) == NULL)
			break;
		switch (resp[0]) {

		default:
D 24
			fprintf(stderr, "usage\n");
E 24
I 24
			printf("usage\n");
E 24
		case '?':
			print = 0;
D 24
			fprintf(stderr, "q\tquit\n");
			fprintf(stderr, "x\texit without changing mail\n");
			fprintf(stderr, "p\tprint\n");
			fprintf(stderr, "s[file]\tsave (default mbox)\n");
			fprintf(stderr, "w[file]\tsame without header\n");
			fprintf(stderr, "-\tprint previous\n");
			fprintf(stderr, "d\tdelete\n");
			fprintf(stderr, "+\tnext (no delete)\n");
			fprintf(stderr, "m user\tmail to user\n");
			fprintf(stderr, "! cmd\texecute cmd\n");
E 24
I 24
			printf("q\tquit\n");
			printf("x\texit without changing mail\n");
			printf("p\tprint\n");
			printf("s[file]\tsave (default mbox)\n");
			printf("w[file]\tsame without header\n");
			printf("-\tprint previous\n");
			printf("d\tdelete\n");
			printf("+\tnext (no delete)\n");
			printf("m user\tmail to user\n");
			printf("! cmd\texecute cmd\n");
E 24
			break;

		case '+':
		case 'n':
		case '\n':
			i++;
			break;
		case 'x':
			changed = 0;
		case 'q':
			goto donep;
		case 'p':
			break;
		case '^':
		case '-':
			if (--i < 0)
				i = 0;
			break;
		case 'y':
		case 'w':
		case 's':
			flg = 0;
			if (resp[1] != '\n' && resp[1] != ' ') {
				printf("illegal\n");
				flg++;
				print = 0;
				continue;
			}
			if (resp[1] == '\n' || resp[1] == '\0') {
				p = getenv("HOME");
D 24
				if(p != 0)
E 24
I 24
				if (p != 0)
E 24
					cat(resp+1, p, "/mbox");
				else
					cat(resp+1, "", "mbox");
			}
			for (p = resp+1; (p = getarg(lfil, p)) != NULL; ) {
				malf = fopen(lfil, "a");
				if (malf == NULL) {
D 24
					fprintf(stdout, "mail: cannot append to %s\n", lfil);
E 24
I 24
					printf("mail: %s: cannot append\n",
					    lfil);
E 24
					flg++;
					continue;
				}
				copylet(j, malf, resp[0]=='w'? ZAP: ORDINARY);
				fclose(malf);
			}
			if (flg)
				print = 0;
			else {
				let[j].change = 'd';
				changed++;
				i++;
			}
			break;
		case 'm':
			flg = 0;
			if (resp[1] == '\n' || resp[1] == '\0') {
				i++;
				continue;
			}
			if (resp[1] != ' ') {
				printf("invalid command\n");
				flg++;
				print = 0;
				continue;
			}
			for (p = resp+1; (p = getarg(lfil, p)) != NULL; )
D 24
				if (!sendrmt(j, lfil, "/bin/mail"))	/* couldn't send it */
E 24
I 24
D 25
				if (!sendrmt(j, lfil, "/bin/mail"))
E 25
I 25
				if (!sendmail(j, lfil, my_name))
E 25
E 24
					flg++;
			if (flg)
				print = 0;
			else {
				let[j].change = 'd';
				changed++;
				i++;
			}
			break;
		case '!':
			system(resp+1);
			printf("!\n");
			print = 0;
			break;
		case 'd':
			let[j].change = 'd';
			changed++;
			i++;
			if (resp[1] == 'q')
				goto donep;
			break;
		}
	}
   donep:
	if (changed)
		copyback();
}

D 24
copyback()	/* copy temp or whatever back to /usr/spool/mail */
E 24
I 24
/* copy temp or whatever back to /usr/spool/mail */
copyback()
E 24
{
D 24
	register i, n, c;
	int new = 0;
E 24
I 24
D 34
	register i, c;
	int fd, new = 0, oldmask;
E 34
I 34
	register int i, c;
	long oldmask;
	int fd, new = 0;
E 34
E 24
	struct stat stbuf;

D 24
	signal(SIGINT, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	lock(mailfile);
	stat(mailfile, &stbuf);
E 24
I 24
D 34
#define	mask(s)	(1 << ((s) - 1))
	oldmask = sigblock(mask(SIGINT)|mask(SIGHUP)|mask(SIGQUIT));
#undef mask
E 34
I 34
	oldmask = sigblock(sigmask(SIGINT)|sigmask(SIGHUP)|sigmask(SIGQUIT));
E 34
	fd = open(mailfile, O_RDWR | O_CREAT, MAILMODE);
	if (fd >= 0) {
		flock(fd, LOCK_EX);
		malf = fdopen(fd, "r+w");
	}
	if (fd < 0 || malf == NULL)
		panic("can't rewrite %s", lfil);
	fstat(fd, &stbuf);
E 24
	if (stbuf.st_size != let[nlet].adr) {	/* new mail has arrived */
D 24
		malf = fopen(mailfile, "r");
		if (malf == NULL) {
			fprintf(stdout, "mail: can't re-read %s\n", mailfile);
			done();
		}
		fseek(malf, let[nlet].adr, 0);
		fclose(tmpf);
		tmpf = fopen(lettmp, "a");
		fseek(tmpf, let[nlet].adr, 0);
		while ((c = fgetc(malf)) != EOF)
			fputc(c, tmpf);
		fclose(malf);
		fclose(tmpf);
		tmpf = fopen(lettmp, "r");
E 24
I 24
		fseek(malf, let[nlet].adr, L_SET);
		fseek(tmpf, let[nlet].adr, L_SET);
		while ((c = getc(malf)) != EOF)
			putc(c, tmpf);
E 24
		let[++nlet].adr = stbuf.st_size;
		new = 1;
I 24
D 34
		fseek(malf, 0, L_SET);
E 34
I 34
		fseek(malf, 0L, L_SET);
E 34
E 24
	}
D 24
	malf = fopen(mailfile, "w");
	if (malf == NULL) {
		fprintf(stderr, "mail: can't rewrite %s\n", lfil);
		done();
	}
	n = 0;
E 24
I 24
D 34
	ftruncate(fd, 0);
E 34
I 34
	ftruncate(fd, 0L);
E 34
E 24
	for (i = 0; i < nlet; i++)
D 24
		if (let[i].change != 'd') {
E 24
I 24
		if (let[i].change != 'd')
E 24
			copylet(i, malf, ORDINARY);
D 24
			n++;
		}
	fclose(malf);
E 24
I 24
	fclose(malf);		/* implict unlock */
E 24
	if (new)
D 24
		fprintf(stdout, "new mail arrived\n");
	unlock();
E 24
I 24
		printf("New mail has arrived.\n");
	sigsetmask(oldmask);
E 24
}

D 24
copymt(f1, f2)	/* copy mail (f1) to temp (f2) */
FILE *f1, *f2;
E 24
I 24
/* copy mail (f1) to temp (f2) */
copymt(f1, f2)
	FILE *f1, *f2;
E 24
{
	long nextadr;

	nlet = nextadr = 0;
	let[0].adr = 0;
	while (fgets(line, LSIZE, f1) != NULL) {
		if (isfrom(line))
			let[nlet++].adr = nextadr;
		nextadr += strlen(line);
		fputs(line, f2);
	}
	let[nlet].adr = nextadr;	/* last plus 1 */
}

D 16
copylet(n, f, type) FILE *f;
{	int ch, k;
E 16
I 16
copylet(n, f, type)
	FILE *f;
{
	int ch;
	long k;
I 24
D 28
	char hostname[32];
E 28
I 28
	char hostname[MAXHOSTNAMELEN];
E 28
E 24

E 16
D 24
	fseek(tmpf, let[n].adr, 0);
E 24
I 24
	fseek(tmpf, let[n].adr, L_SET);
E 24
	k = let[n+1].adr - let[n].adr;
D 24
	while(k-- > 1 && (ch=fgetc(tmpf))!='\n')
		if(type!=ZAP) fputc(ch,f);
D 9
	if(type==REMOTE)
		fprintf(f, " remote from %s\n", thissys);
	else if (type==FORWARD)
E 9
I 9
	if(type==REMOTE) {
		char hostname[32];
E 24
I 24
	while (k-- > 1 && (ch = getc(tmpf)) != '\n')
		if (type != ZAP)
			putc(ch, f);
	switch (type) {

	case REMOTE:
E 24
		gethostname(hostname, sizeof (hostname));
		fprintf(f, " remote from %s\n", hostname);
D 24
	} else if (type==FORWARD)
E 24
I 24
		break;

	case FORWARD:
E 24
E 9
		fprintf(f, forwmsg);
D 24
	else if(type==ORDINARY)
		fputc(ch,f);
	while(k-->1)
		fputc(ch=fgetc(tmpf), f);
	if(type!=ZAP || ch!= '\n')
		fputc(fgetc(tmpf), f);
E 24
I 24
		break;

	case ORDINARY:
		putc(ch, f);
		break;

I 25
	case ZAP:
		break;

E 25
	default:
		panic("Bad letter type %d to copylet.", type);
	}
	while (k-- > 1) {
		ch = getc(tmpf);
		putc(ch, f);
	}
	if (type != ZAP || ch != '\n')
		putc(getc(tmpf), f);
E 24
}

isfrom(lp)
register char *lp;
{
	register char *p;

	for (p = from; *p; )
		if (*lp++ != *p++)
			return(0);
	return(1);
}

D 8
sendmail(argc, argv)
E 8
I 8
bulkmail(argc, argv)
E 8
char **argv;
{
D 28
	char truename[100];
E 28
I 28
	char *truename;
E 28
	int first;
	register char *cp;
D 28
	int gaver = 0;
E 28
D 9
# ifdef DELIVERMAIL
E 9
	char *newargv[1000];
	register char **ap;
	register char **vp;
	int dflag;

	dflag = 0;
I 28
	delflg = 0;
E 28
D 24
	if (argc < 1)
E 24
I 24
	if (argc < 1) {
E 24
		fprintf(stderr, "puke\n");
I 24
		return;
	}
E 24
	for (vp = argv, ap = newargv + 1; (*ap = *vp++) != 0; ap++)
D 24
	{
E 24
		if (ap[0][0] == '-' && ap[0][1] == 'd')
			dflag++;
D 24
	}
	if (!dflag)
	{
E 24
I 24
	if (!dflag) {
E 24
D 12
		/* give it to delivermail, rah rah! */
E 12
I 12
		/* give it to sendmail, rah rah! */
E 12
		unlink(lettmp);
		ap = newargv+1;
		if (rmail)
			*ap-- = "-s";
D 12
		*ap = "-delivermail";
E 12
I 12
		*ap = "-sendmail";
E 12
I 7
		setuid(getuid());
E 7
D 12
		execv(DELIVERMAIL, ap);
		perror(DELIVERMAIL);
E 12
I 12
		execv(SENDMAIL, ap);
		perror(SENDMAIL);
E 12
		exit(EX_UNAVAILABLE);
	}
D 9
# endif DELIVERMAIL
E 9

D 28
	truename[0] = 0;
E 28
I 28
	truename = 0;
E 28
	line[0] = '\0';

	/*
	 * When we fall out of this, argv[1] should be first name,
	 * argc should be number of names + 1.
	 */

	while (argc > 1 && *argv[1] == '-') {
		cp = *++argv;
		argc--;
		switch (cp[1]) {
		case 'r':
D 24
			if (argc <= 0) {
E 24
I 24
			if (argc <= 1)
E 24
				usage();
D 24
				done();
			}
E 24
I 20
D 21
			if (strcmp(my_name, "root") &&
			    strcmp(my_name, "daemon") &&
			    strcmp(my_name, "network")) {
				usage();
				done();
E 21
I 21
			if (strcmp(my_name, "root") == 0 ||
			    strcmp(my_name, "daemon") == 0 ||
			    strcmp(my_name, "network") == 0 ||
			    strcmp(my_name, "uucp")) {
				gaver++;
				strcpy(truename, argv[1]);
				fgets(line, LSIZE, stdin);
				if (strncmp("From", line, 4) == 0)
					line[0] = '\0';
E 21
			}
E 20
D 21
D 28
			gaver++;
			strcpy(truename, argv[1]);
E 28
I 28
			truename = argv[1];
E 28
			fgets(line, LSIZE, stdin);
			if (strcmpn("From", line, 4) == 0)
				line[0] = '\0';
E 21
			argv++;
			argc--;
			break;

		case 'h':
D 24
			if (argc <= 0) {
E 24
I 24
			if (argc <= 1)
E 24
				usage();
D 24
				done();
			}
E 24
			hseqno = atoi(argv[1]);
			argv++;
			argc--;
			break;

D 9
# ifdef DELIVERMAIL
E 9
		case 'd':
			break;
D 9
# endif DELIVERMAIL
E 9
		
		default:
			usage();
D 24
			done();
E 24
		}
	}
D 24
	if (argc <= 1) {
E 24
I 24
	if (argc <= 1)
E 24
		usage();
D 24
		done();
	}
E 24
D 28
	if (gaver == 0)
		strcpy(truename, my_name);
E 28
I 28
	if (truename == 0)
		truename = my_name;
E 28
D 24
	/*
	if (argc > 4 && strcmp(argv[1], "-r") == 0) {
		strcpy(truename, argv[2]);
		argc -= 2;
		argv += 2;
		fgets(line, LSIZE, stdin);
D 21
		if (strcmpn("From", line, 4) == 0)
E 21
I 21
		if (strncmp("From", line, 4) == 0)
E 21
			line[0] = '\0';
	} else
		strcpy(truename, my_name);
	*/
E 24
	time(&iop);
	fprintf(tmpf, "%s%s %s", from, truename, ctime(&iop));
	iop = ftell(tmpf);
D 24
	flgf = 1;
	for (first = 1;; first = 0) {
		if (first && line[0] == '\0' && fgets(line, LSIZE, stdin) == NULL)
E 24
I 24
	flgf = first = 1;
	for (;;) {
		if (first) {
			first = 0;
			if (*line == '\0' && fgets(line, LSIZE, stdin) == NULL)
				break;
		} else {
			if (fgets(line, LSIZE, stdin) == NULL)
				break;
		}
		if (*line == '.' && line[1] == '\n' && isatty(fileno(stdin)))
E 24
			break;
D 24
		if (!first && fgets(line, LSIZE, stdin) == NULL)
			break;
		if (line[0] == '.' && line[1] == '\n' && isatty(fileno(stdin)))
			break;
E 24
		if (isfrom(line))
D 24
			fputs(">", tmpf);
E 24
I 24
			putc('>', tmpf);
E 24
		fputs(line, tmpf);
		flgf = 0;
	}
D 24
	fputs("\n", tmpf);
E 24
I 24
	putc('\n', tmpf);
E 24
	nlet = 1;
	let[0].adr = 0;
	let[1].adr = ftell(tmpf);
D 24
	fclose(tmpf);
E 24
	if (flgf)
		return;
D 24
	tmpf = fopen(lettmp, "r");
	if (tmpf == NULL) {
		fprintf(stderr, "mail: cannot reopen %s for reading\n", lettmp);
		return;
	}
D 8
	while (--argc > 0)
		if (!send(0, *++argv, truename))
E 8
I 8
	while (--argc > 0) {
E 24
I 24
	while (--argc > 0)
E 24
		if (!sendmail(0, *++argv, truename))
E 8
			error++;
I 8
D 24
	}
E 24
E 8
D 14
	if (error) {
E 14
I 14
	if (error && safefile(dead)) {
E 14
		setuid(getuid());
		malf = fopen(dead, "w");
		if (malf == NULL) {
D 24
			fprintf(stdout, "mail: cannot open %s\n", dead);
E 24
I 24
			printf("mail: cannot open %s\n", dead);
E 24
			fclose(tmpf);
			return;
		}
		copylet(0, malf, ZAP);
		fclose(malf);
D 24
		fprintf(stdout, "Mail saved in %s\n", dead);
E 24
I 24
		printf("Mail saved in %s\n", dead);
E 24
	}
	fclose(tmpf);
}

D 25
sendrmt(n, name, rcmd)
E 25
I 25
sendrmt(n, name)
E 25
char *name;
D 25
char *rcmd;
E 25
{
	FILE *rmf, *popen();
	register char *p;
	char rsys[64], cmd[64];
D 25
	register local, pid;
E 25
I 25
	register pid;
E 25
	int sts;

D 25
	local = 0;
	if (index(name, '^')) {
E 25
I 25
#ifdef notdef
	if (any('^', name)) {
E 25
		while (p = index(name, '^'))
			*p = '!';
		if (strncmp(name, "researc", 7)) {
			strcpy(rsys, "research");
			if (*name != '!')
				--name;
			goto skip;
		}
	}
D 25
	if (*name=='!')
		name++;
	for(p=rsys; *name!='!'; *p++ = *name++)
		if (*name=='\0') {
			local++;
			break;
		}
E 25
I 25
#endif
	for (p=rsys; *name!='!'; *p++ = *name++)
		if (*name=='\0')
			return(0);	/* local address, no '!' */
E 25
	*p = '\0';
D 25
	if ((!local && *name=='\0') || (local && *rsys=='\0')) {
E 25
I 25
	if (name[1]=='\0') {
E 25
D 24
		fprintf(stdout, "null name\n");
E 24
I 24
		printf("null name\n");
E 24
		return(0);
	}
skip:
	if ((pid = fork()) == -1) {
		fprintf(stderr, "mail: can't create proc for remote\n");
		return(0);
	}
	if (pid) {
		while (wait(&sts) != pid) {
			if (wait(&sts)==-1)
				return(0);
		}
		return(!sts);
	}
	setuid(getuid());
D 25
	if (local)
		sprintf(cmd, "%s %s", rcmd, rsys);
	else {
		if (index(name+1, '!'))
			sprintf(cmd, "uux - %s!rmail \\(%s\\)", rsys, name+1);
		else
			sprintf(cmd, "uux - %s!rmail %s", rsys, name+1);
	}
E 25
I 25
	if (any('!', name+1))
D 32
		sprintf(cmd, "uux - %s!rmail \\(%s\\)", rsys, name+1);
E 32
I 32
		(void)sprintf(cmd, "uux - %s!rmail \\(%s\\)", rsys, name+1);
E 32
	else
D 32
		sprintf(cmd, "uux - %s!rmail %s", rsys, name+1);
E 32
I 32
		(void)sprintf(cmd, "uux - %s!rmail %s", rsys, name+1);
E 32
E 25
	if ((rmf=popen(cmd, "w")) == NULL)
		exit(1);
D 25
	copylet(n, rmf, local ? !strcmp(rcmd, "/bin/mail") ? FORWARD : ORDINARY : REMOTE);
E 25
I 25
	copylet(n, rmf, REMOTE);
E 25
D 15
	pclose(rmf);
	exit(0);
E 15
I 15
	exit(pclose(rmf) != 0);
E 15
}

I 2
D 9
# ifndef DELIVERMAIL
E 2
/*
 * Send mail on the Berkeley network.
 * Sorry Bill, sendrmt() is so awful we just gave up.
 */

sendberkmail(n, name, fromaddr)
	char name[];
	char fromaddr[];
{
	char cmd[200];
	register FILE *cmdf;

	sprintf(cmd, "%s -h %d -f %s -t %s", RMAIL, hseqno, fromaddr, name);
	if ((cmdf = popen(cmd, "w")) == NULL) {
		perror(RMAIL);
		return(0);
	}
	copylet(n, cmdf, ORDINARY);
	pclose(cmdf);
	return(9);
}
I 2
# endif
E 2

E 9
usage()
{

	fprintf(stderr, "Usage: mail [ -f ] people . . .\n");
I 22
	error = EX_USAGE;
I 24
	done();
E 24
E 22
}

D 8
send(n, name, fromaddr)
E 8
I 8
#include <sys/socket.h>
D 11
#include <net/in.h>
E 11
I 11
#include <netinet/in.h>
E 11
D 10
#include <wellknown.h>
E 10
D 13
struct sockaddr_in biffaddr = { AF_INET, IPPORT_BIFFUDP };
char *localhost = "localhost";
E 13
I 13
#include <netdb.h>
D 24
struct sockaddr_in biffaddr;
E 24
E 13

I 24
notifybiff(msg)
	char *msg;
{
	static struct sockaddr_in addr;
	static int f = -1;

	if (addr.sin_family == 0) {
		struct hostent *hp = gethostbyname("localhost");
		struct servent *sp = getservbyname("biff", "udp");

		if (hp && sp) {
			addr.sin_family = hp->h_addrtype;
			bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
			addr.sin_port = sp->s_port;
		}
	}
	if (addr.sin_family) {
		if (f < 0)
			f = socket(AF_INET, SOCK_DGRAM, 0);
D 30
		sendto(f, msg, strlen(msg)+1, 0, &addr, sizeof (addr));
E 30
I 30
		if (f >= 0)
			sendto(f, msg, strlen(msg)+1, 0, &addr, sizeof (addr));
E 30
	}
}

E 24
sendmail(n, name, fromaddr)
E 8
D 24
int n;
char *name;
char *fromaddr;
E 24
I 24
	int n;
	char *name, *fromaddr;
E 24
{
D 24
	char file[100];
	register char *p;
	register mask;
	struct passwd *pw, *getpwnam();
E 24
I 24
	char file[256];
	int mask, fd;
	struct passwd *pw;
#ifdef notdef
E 24
	struct stat statb;
I 24
#endif
E 24
I 4
	char buf[128];
D 24
	int f;
I 13
	struct hostent *hp = NULL;
	struct servent *sp = NULL;
E 24
E 13
E 4

I 2
D 9
# ifndef DELIVERMAIL
E 2
	stripfx(LOCNAM1, &name);
	stripfx(LOCNAM2, &name);
	stripfx(LOCNAM3, &name);
	stripfx(LOCNAM4, &name);
	if(*name == ':')name++;		/* skip colon in to-name */
D 2
	for(p=name; *p!=':' &&*p!='\0'; p++);
E 2
I 2
	for(p=name; *p!=':' && *p!='!' && *p!='^' &&*p!='\0'; p++);
E 2
	/* if(*p == ':') return(sendrmt(n, name, RMAIL)); */
	if (*p == ':')
		return(sendberkmail(n, name, fromaddr));
D 2
	else if (strcmp(name, "msgs") == 0) return(sendrmt(n, "-s", "/usr/ucb/msgs"));
E 2
I 2
	else if (*p=='\0' && strcmp(name, "msgs") == 0)
		return(sendrmt(n, "-s", "/usr/ucb/msgs"));
# endif
E 9
E 2
D 24
	for(p=name; *p!='!'&&*p!='^' &&*p!='\0'; p++)
		;
	if (*p == '!'|| *p=='^')
		return(sendrmt(n, name, 0));
E 24
I 24
D 25
	if (any(name, "!^"))
		return (sendrmt(n, name, 0));
E 25
I 25
	if (*name=='!')
		name++;
	if (any('!', name))
		return (sendrmt(n, name));
E 25
E 24
	if ((pw = getpwnam(name)) == NULL) {
D 24
		fprintf(stdout, "mail: can't send to %s\n", name);
E 24
I 24
		printf("mail: can't send to %s\n", name);
E 24
		return(0);
	}
	cat(file, maildir, name);
I 24
#ifdef notdef
E 24
	if (stat(file, &statb) >= 0 && (statb.st_mode & S_IFMT) == S_IFDIR) {
		strcat(file, "/");
		strcat(file, name);
	}
D 24
	mask = umask(MAILMODE);
E 24
I 24
#endif
E 24
I 5
D 6
	if (stat(file, &stat) >= 0 && stat.st_nlink != 1) {
E 6
I 6
D 14
	if (stat(file, &statb) >= 0 && statb.st_nlink != 1) {
E 6
		fprintf(stdout, "mail: %s's mail file has more than one link\n", name);
E 14
I 14
	if (!safefile(file))
E 14
		return(0);
I 16
D 24
	lock(file);
E 16
D 14
	}
E 14
E 5
	malf = fopen(file, "a");
I 5
D 8
	chown(file, pw->pw_uid, pw->pw_gid);
E 8
E 5
	umask(mask);
	if (malf == NULL) {
I 16
		unlock();
E 16
		fprintf(stdout, "mail: cannot append to %s\n", file);
E 24
I 24
	fd = open(file, O_WRONLY | O_CREAT, MAILMODE);
	if (fd >= 0) {
		flock(fd, LOCK_EX);
		malf = fdopen(fd, "a");
	}
	if (fd < 0 || malf == NULL) {
		close(fd);
		printf("mail: %s: cannot append\n", file);
E 24
		return(0);
	}
D 16
	lock(file);
E 16
I 8
D 24
	chown(file, pw->pw_uid, pw->pw_gid);
E 8
D 5
	chown(file, pw->pw_uid, pw->pw_gid);
E 5
I 4
	{
D 8
		f = open("/dev/mail", 1);
E 8
I 8
D 11
		f = socket(SOCK_DGRAM, 0, 0, 0);
E 11
I 11
D 13
		f = socket(0, SOCK_DGRAM, 0, 0);
E 11
E 8
		sprintf(buf, "%s@%d\n", name, ftell(malf)); 
E 13
I 13
		hp = gethostbyname("localhost");
		sp = getservbyname("biff", "udp");
		if (hp && sp) {
			f = socket(AF_INET, SOCK_DGRAM, 0, 0);
			sprintf(buf, "%s@%d\n", name, ftell(malf)); 
		}
E 13
	}
E 24
I 24
	fchown(fd, pw->pw_uid, pw->pw_gid);
D 32
	sprintf(buf, "%s@%d\n", name, ftell(malf)); 
E 32
I 32
D 34
	(void)sprintf(buf, "%s@%d\n", name, ftell(malf));
E 34
I 34
	(void)sprintf(buf, "%s@%ld\n", name, ftell(malf));
E 34
E 32
E 24
E 4
	copylet(n, malf, ORDINARY);
I 8
	fclose(malf);
E 8
I 4
D 13
	if (f >= 0) {
D 8
		write(f, buf, strlen(buf)+1);
E 8
I 8
		biffaddr.sin_addr.s_addr = rhost(&localhost);
I 10
#if vax
		biffaddr.sin_port =
		    ((biffaddr.sin_port<<8)&0xff00)|((biffaddr.sin_port>>8)&0xff);
#endif
E 13
I 13
D 24
	if (hp && sp) {
		biffaddr.sin_family = hp->h_addrtype;
		bcopy(hp->h_addr, &biffaddr.sin_addr, hp->h_length);
		biffaddr.sin_port = sp->s_port;
E 13
E 10
D 11
		send(f, &biffaddr, buf, strlen(buf)+1);
E 11
I 11
		sendto(f, buf, strlen(buf)+1, 0, &biffaddr, sizeof (biffaddr));
E 11
E 8
		close(f);
	}
E 4
D 8
	fclose(malf);
E 8
	unlock();
E 24
I 24
	notifybiff(buf);
E 24
	return(1);
}

D 24
delete(i)
E 24
I 24
delex(i)
E 24
{
D 24
	setsig(i, delete);
	fprintf(stderr, "\n");
	if(delflg)
E 24
I 24
D 28
	setsig(i, delex);
E 28
I 28
	if (i != SIGINT) {
		setsig(i, SIG_DFL);
D 35
		sigsetmask(sigblock(0) &~ sigmask(i));
E 35
I 35
		sigsetmask(sigblock(0L) &~ sigmask(i));
E 35
	}
E 28
	putc('\n', stderr);
	if (delflg)
E 24
		longjmp(sjbuf, 1);
I 28
	if (error == 0)
		error = i;
E 28
	done();
}

D 24
/*
 * Lock the specified mail file by setting the file mailfile.lock.
 * We must, of course, be careful to unlink the lock file by a call
 * to unlock before we stop.  The algorithm used here is to see if
 * the lock exists, and if it does, to check its modify time.  If it
 * is older than 30 seconds, we assume error and set our own file.
 * Otherwise, we wait for 5 seconds and try again.
 */

char	*maillock	= ".lock";		/* Lock suffix for mailname */
char	*lockname	= "/usr/spool/mail/tmXXXXXX";
char	locktmp[30];				/* Usable lock temporary */
char	curlock[50];				/* Last used name of lock */
int	locked;					/* To note that we locked it */

lock(file)
char *file;
{
	register int f;
	struct stat sbuf;
	long curtime;
	int statfailed;

	if (locked || flgf)
		return(0);
	strcpy(curlock, file);
	strcat(curlock, maillock);
	strcpy(locktmp, lockname);
	mktemp(locktmp);
	unlink(locktmp);
	statfailed = 0;
	for (;;) {
		f = lock1(locktmp, curlock);
		if (f == 0) {
			locked = 1;
			return(0);
		}
		if (stat(curlock, &sbuf) < 0) {
			if (statfailed++ > 5)
				return(-1);
			sleep(5);
			continue;
		}
		statfailed = 0;
		time(&curtime);
		if (curtime < sbuf.st_ctime + 30) {
			sleep(5);
			continue;
		}
		unlink(curlock);
	}
}

/*
 * Remove the mail lock, and note that we no longer
 * have it locked.
 */

unlock()
{

	unlink(curlock);
	locked = 0;
}

/*
 * Attempt to set the lock by creating the temporary file,
 * then doing a link/unlink.  If it fails, return -1 else 0
 */

lock1(tempfile, name)
	char tempfile[], name[];
{
	register int fd;

	fd = creat(tempfile, 0);
	if (fd < 0)
		return(-1);
	close(fd);
	if (link(tempfile, name) < 0) {
		unlink(tempfile);
		return(-1);
	}
	unlink(tempfile);
	return(0);
}

E 24
done()
{
D 24
	if(locked)
		unlock();
E 24
I 24

E 24
	unlink(lettmp);
D 24
	unlink(locktmp);
E 24
	exit(error);
}

cat(to, from1, from2)
D 24
char *to, *from1, *from2;
E 24
I 24
	char *to, *from1, *from2;
E 24
{
D 24
	int i, j;
E 24
I 24
	register char *cp, *dp;
E 24

D 24
	j = 0;
	for (i=0; from1[i]; i++)
		to[j++] = from1[i];
	for (i=0; from2[i]; i++)
		to[j++] = from2[i];
	to[j] = 0;
E 24
I 24
	cp = to;
	for (dp = from1; *cp = *dp++; cp++)
		;
	for (dp = from2; *cp++ = *dp++; )
		;
E 24
}

D 24
char *getarg(s, p)	/* copy p... into s, update p */
register char *s, *p;
E 24
I 24
/* copy p... into s, update p */
char *
getarg(s, p)
	register char *s, *p;
E 24
{
	while (*p == ' ' || *p == '\t')
		p++;
	if (*p == '\n' || *p == '\0')
		return(NULL);
	while (*p != ' ' && *p != '\t' && *p != '\n' && *p != '\0')
		*s++ = *p++;
	*s = '\0';
	return(p);
I 14
}

safefile(f)
	char *f;
{
	struct stat statb;

	if (lstat(f, &statb) < 0)
		return (1);
	if (statb.st_nlink != 1 || (statb.st_mode & S_IFMT) == S_IFLNK) {
D 24
		fprintf(stderr, "mail: %s has more than one link or is a symbolic link\n", f);
E 24
I 24
		fprintf(stderr,
		    "mail: %s has more than one link or is a symbolic link\n",
		    f);
E 24
		return (0);
	}
	return (1);
I 24
}

panic(msg, a1, a2, a3)
	char *msg;
{

	fprintf(stderr, "mail: ");
	fprintf(stderr, msg, a1, a2, a3);
	fprintf(stderr, "\n");
	done();
E 24
E 14
}
I 2
D 9
# ifndef DELIVERMAIL
E 2
/*
	stripfx(prefix string, pointer to string)

	takes a ptr to string and compares it to prefix string.
	may be called multiple times
*/
stripfx(pfx, name)
	char *pfx;
	char **name;
{
	register char *cp = *name;

	while (*pfx && (*cp == *pfx || *cp == toupper(*pfx)))
		cp++, pfx++;
	if (*cp != ':' || *pfx != 0)
		return;
	*name = cp;
}
I 2
# endif
E 9
E 2
E 1
