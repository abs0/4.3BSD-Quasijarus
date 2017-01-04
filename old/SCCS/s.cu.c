h11430
s 00109/00071/00849
d D 4.7 82/10/21 23:39:37 mckusick 7 6
c updates from arpavax
e
s 00001/00001/00919
d D 4.6 81/07/02 02:23:14 bugs 6 5
c s/12345/1
e
s 00002/00002/00918
d D 4.5 81/07/02 01:50:07 root 5 4
c prevent kill(-1, ...) accidentally
e
s 00001/00001/00919
d D 4.4 81/07/02 01:43:20 root 4 3
c get rid of dangerous -1 as pid
e
s 00007/00002/00913
d D 4.3 81/02/28 20:18:31 wnj 3 2
c fix line overflow and failure to remove lock on signal bugs
e
s 00271/00006/00644
d D 4.2 81/02/07 18:53:20 mark 2 1
c now abides by uucp locking conventions for acu/line.  also fixed
c bug preventing stdin from being a pipe. - mrh
e
s 00650/00000/00000
d D 4.1 80/10/01 17:26:00 bill 1 0
c date and time created 80/10/01 17:26:00 by bill
e
u
U
t
T
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
E 3
I 3
static	char *sccsid = "%W% (Berkeley) %E%";
I 7

E 7
E 3
#include <stdio.h>
#include <signal.h>
#include <sgtty.h>
I 2

E 2
/*
I 2
 * defs that come from uucp.h
 */
#define NAMESIZE 15
#define FAIL -1
#define SAME 0
#define SLCKTIME 5400	/* system/device timeout (LCK.. files) in seconds */
#define ASSERT(e, f, v) if (!(e)) {\
	fprintf(stderr, "AERROR - (%s) ", "e");\
	fprintf(stderr, f, v);\
	cleanup(FAIL);\
}

/*
E 2
D 7
 *	cu telno [-t] [-s speed] [-l line] [-a acu]
E 7
I 7
 *	cu telno [-t] [-s speed] [-l line] [-a acu] [-p]
E 7
 *
 *	-t is for dial-out to terminal.
D 7
 *	speeds are: 110, 134, 150, 300, 1200. 300 is default.
E 7
I 7
 *	speeds are: 110, 134, 150, 300, 1200, 2400. 300 is default.
E 7
 *
I 7
 *	-p says strip parity of characters transmitted.  (to compensate
 *	for c100's)
 *
E 7
 *	Escape with `~' at beginning of line.
 *	Ordinary diversions are ~<, ~> and ~>>.
 *	Silent output diversions are ~>: and ~>>:.
 *	Terminate output diversion with ~> alone.
 *	Quit is ~. and ~! gives local command or shell.
 *	Also ~$ for canned procedure pumping remote.
 *	~%put from [to]  and  ~%take from [to] invoke builtins
 */

#define CRLF "\r\n"
#define wrc(ds) write(ds,&c,1)


char	*devcul	= "/dev/cul0";
char	*devcua	= "/dev/cua0";
char	*lspeed	= "300";

int	ln;	/* fd for comm line */
char	tkill, terase;	/* current input kill & erase */
int	efk;		/* process of id of listener  */
char	c;
char	oc;

char	*connmsg[] = {
	"",
	"line busy",
	"call dropped",
	"no carrier",
	"can't fork",
	"acu access",
	"tty access",
	"tty hung",
D 2
	"usage: cu telno [-t] [-s speed] [-l line] [-a acu]"
E 2
I 2
	"usage: cu telno [-t] [-s speed] [-l line] [-a acu]",
	"lock failed: line busy"
E 2
};

rdc(ds) {

	ds=read(ds,&c,1); 
	oc = c;
	c &= 0177;
	return (ds);
}

int intr;

sig2()
{
	signal(SIGINT, SIG_IGN); 
	intr = 1;
}

int set14;

xsleep(n)
{
	xalarm(n);
	pause();
	xalarm(0);
}

xalarm(n)
{
	set14=n; 
	alarm(n);
}

sig14()
{
	signal(SIGALRM, sig14); 
	if (set14) alarm(1);
}

int	dout;
int	nhup;
int	dbflag;
I 7
int	pflag;		/* strip parity on chars sent to remote */
E 7
I 2
int	nullbrk;	/* turn breaks (nulls) into dels */
I 7
int	pipes[2] = { -1, -1 };
E 7
E 2

/*
 *	main: get connection, set speed for line.
 *	spawn child to invoke rd to read from line, output to fd 1
 *	main line invokes wr to read tty, write to line
 */
main(ac,av)
char *av[];
{
	int fk;
	int speed;
	char *telno;
	struct sgttyb stbuf;
I 3
	int cleanup();
E 3

	signal(SIGALRM, sig14);
I 3
	signal(SIGINT, cleanup);
	signal(SIGHUP, cleanup);
	signal(SIGQUIT, cleanup);
E 3
	if (ac < 2) {
		prf(connmsg[8]);
		exit(8);
	}
	for (; ac > 1; av++,ac--) {
		if (av[1][0] != '-')
			telno = av[1];
		else switch(av[1][1]) {
		case 't':
			dout = 1;
			--ac;
			continue;
I 2
		case 'b':
			nullbrk++;
			continue;
E 2
		case 'd':
			dbflag++;
			continue;
I 7
		case 'p':
			pflag++;
			continue;
E 7
		case 's':
			lspeed = av[2]; ++av; --ac;
			break;
		case 'l':
			devcul = av[2]; ++av; --ac;
			break;
		case 'a':
			devcua = av[2]; ++av; --ac;
			break;
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			devcua[strlen(devcua)-1] = av[1][1];
			devcul[strlen(devcul)-1] = av[1][1];
			break;
		default:
			prf("Bad flag %s", av[1]);
			break;
		}
	}
	if (!exists(devcua) || !exists(devcul))
		exit(9);
	ln = conn(devcul, devcua, telno);
	if (ln < 0) {
		prf("Connect failed: %s",connmsg[-ln]);
D 2
		exit(-ln);
E 2
I 2
		cleanup(-ln);
E 2
	}
	switch(atoi(lspeed)) {
	case 110:
		speed = B110;break;
	case 150:
		speed = B150;break;
	default:
	case 300:
		speed = B300;break;
	case 1200:
		speed = B1200;break;
I 7
	case 2400:
		speed = B2400;break;
E 7
	}
	stbuf.sg_ispeed = speed;
	stbuf.sg_ospeed = speed;
	stbuf.sg_flags = EVENP|ODDP;
	if (!dout) {
		stbuf.sg_flags |= RAW;
		stbuf.sg_flags &= ~ECHO;
	}
	ioctl(ln, TIOCSETP, &stbuf);
	ioctl(ln, TIOCEXCL, (struct sgttyb *)NULL);
	ioctl(ln, TIOCHPCL, (struct sgttyb *)NULL);
	prf("Connected");
I 7
	pipe(pipes);
E 7
	if (dout)
D 4
		fk = -1;
E 4
I 4
D 6
		fk = -12345;
E 6
I 6
		fk = -1;
E 6
E 4
	else
		fk = fork();
	nhup = (int)signal(SIGINT, SIG_IGN);
	if (fk == 0) {
		chwrsig();
		rd();
		prf("\007Lost carrier");
D 2
		exit(3);
E 2
I 2
		cleanup(3);
E 2
	}
	mode(1);
	efk = fk;
	wr();
	mode(0);
D 5
	kill(fk, SIGKILL);
E 5
I 5
	if (fk != -1) kill(fk, SIGKILL);
E 5
	wait((int *)NULL);
	stbuf.sg_ispeed = 0;
	stbuf.sg_ospeed = 0;
	ioctl(ln, TIOCSETP, &stbuf);
	prf("Disconnected");
D 2
	exit(0);
E 2
I 2
	cleanup(0);
E 2
}

/*
 *	conn: establish dial-out connection.
 *	Example:  fd = conn("/dev/ttyh","/dev/dn1","4500");
 *	Returns descriptor open to tty for reading and writing.
 *	Negative values (-1...-7) denote errors in connmsg.
 *	Uses alarm and fork/wait; requires sig14 handler.
 *	Be sure to disconnect tty when done, via HUPCL or stty 0.
 */

conn(dev,acu,telno)
char *dev, *acu, *telno;
{
	struct sgttyb stbuf;
	extern errno;
	char *p, *q, b[30];
I 2
	char *ltail, *atail;
	char *rindex();
E 2
	int er, fk, dn, dh, t;
	er=0; 
	fk=(-1);
I 2
	atail = rindex(acu, '/')+1;
	if (mlock(atail) == FAIL) {
		er = 9;
		goto X;
	}
	ltail = rindex(dev, '/')+1;
	if (mlock(ltail) == FAIL) {
		er = 9;
		delock(atail);
		goto X;
	}
E 2
	if ((dn=open(acu,1))<0) {
		er=(errno == 6? 1:5); 
		goto X;
	}
	if ((fk=fork()) == (-1)) {
		er=4; 
		goto X;
	}
	if (fk == 0) {
		open(dev,2); 
		for (;;) pause();
	}
	xsleep(2);
	/*
	 *	copy phone #, assure EON
	 */
	p=b; 
	q=telno;
	while (*p++=(*q++))
		;
	p--;
	if (*(p-1)!='<') {
		/*if (*(p-1)!='-') *p++='-';*/
		*p++='<';
	}
	t=p-b;
	xalarm(5*t);
	t=write(dn,b,t);
	xalarm(0);
	if (t<0) {
		er=2; 
		goto X;
	}
	/* close(dn) */
	xalarm(40);		/* was 5; sometimes missed carrier */
	dh = open(dev,2);
	xalarm(0);
	if (dh<0) {
		er=(errno == 4? 3:6); 
		goto X;
	}
D 2
	ioctl(ln, TIOCGETP, &stbuf);
E 2
I 2
	ioctl(dh, TIOCGETP, &stbuf);
E 2
	stbuf.sg_flags &= ~ECHO;
	xalarm(10);
	ioctl(dh, TIOCSETP, &stbuf);
	ioctl(dh, TIOCHPCL, (struct sgttyb *)NULL);
	xalarm(0);
X: 
	if (er) close(dn);
I 2
	delock(atail);
E 2
	if (fk!=(-1)) {
		kill(fk, SIGKILL);
		xalarm(10);
		while ((t=wait((int *)NULL))!=(-1) && t!=fk);
		xalarm(0);
	}
	return (er? -er:dh);
}

/*
 *	wr: write to remote: 0 -> line.
 *	~.	terminate
 *	~<file	send file
 *	~!	local login-style shell
 *	~!cmd	execute cmd locally
 *	~$proc	execute proc locally, send output to line
 *	~%cmd	execute builtin cmd (put and take)
 *	~#	send 1-sec break
I 2
 *	~^Z	suspend cu process.
E 2
 */

wr()
{
	int ds,fk,lcl,x;
	char *p,b[600];
	for (;;) {
		p=b;
		while (rdc(0) == 1) {
			if (p == b) lcl=(c == '~');
			if (p == b+1 && b[0] == '~') lcl=(c!='~');
D 2
			/* if (c == 0) oc=c=0177; fake break kludge */
E 2
I 2
			if (nullbrk && c == 0) oc=c=0177; /* fake break kludge */
E 2
			if (!lcl) {
D 7
				c = oc;
E 7
I 7
				if(!pflag)c = oc;
E 7
				if (wrc(ln) == 0) {
					prf("line gone"); return;
				}
				c &= 0177;
			}
			if (lcl) {
				if (c == 0177) c=tkill;
				if (c == '\r' || c == '\n') goto A;
				if (!dout) wrc(0);
			}
			*p++=c;
			if (c == terase) {
				p=p-2; 
				if (p<b) p=b;
			}
			if (c == tkill || c == 0177 || c == '\4' || c == '\r' || c == '\n') p=b;
		}
		return;
A: 
		if (!dout) echo("");
		*p=0;
		switch (b[1]) {
		case '.':
		case '\004':
			return;
		case '#':
			ioctl(ln, TIOCSBRK, 0);
			sleep(1);
			ioctl(ln, TIOCCBRK, 0);
			continue;
		case '!':
		case '$':
			fk = fork();
			if (fk == 0) {
				char *getenv();
				char *shell = getenv("SHELL");
				if (shell == 0) shell = "/bin/sh";
				close(1);
				dup(b[1] == '$'? ln:2);
				close(ln);
				mode(0);
				if (!nhup) signal(SIGINT, SIG_DFL);
				if (b[2] == 0) execl(shell,shell,0);
				/* if (b[2] == 0) execl(shell,"-",0); */
				else execl(shell,"sh","-c",b+2,0);
				prf("Can't execute shell");
				exit(~0);
			}
			if (fk!=(-1)) {
				while (wait(&x)!=fk);
			}
			mode(1);
			if (b[1] == '!') echo("!");
			else {
				if (dout) echo("$");
			}
			break;
		case '<':
			if (b[2] == 0) break;
			if ((ds=open(b+2,0))<0) {
				prf("Can't divert %s",b+1); 
				break;
			}
			intr=x=0;
			mode(2);
			if (!nhup) signal(SIGINT, sig2);
			while (!intr && rdc(ds) == 1) {
				if (wrc(ln) == 0) {
					x=1; 
					break;
				}
			}
			signal(SIGINT, SIG_IGN);
			close(ds);
			mode(1);
			if (x) return;
			if (dout) echo("<");
			break;
		case '>':
		case ':':
			{
D 7
			FILE *fp; char tbuff[128]; register char *q;
			sprintf(tbuff,"/tmp/cu%d",efk);
			if(NULL==(fp = fopen(tbuff,"w"))) {
E 7
I 7
			register char *q;

			if(pipes[1]==-1) {
E 7
				prf("Can't tell other demon to divert");
				break;
			}
D 7
			fprintf(fp,"%s\n",(b[1]=='>'?&b[2]: &b[1] ));
			if(dbflag) prf("name to be written in temporary:"),prf(&b[2]);
			fclose(fp);
E 7
I 7
			q = b+1;
			if(*q=='>') q++;
			write(pipes[1],q,strlen(q)+1);
			if(dbflag) prf("msg to be delivered:"),prf(q);
E 7
D 5
			kill(efk,SIGEMT);
E 5
I 5
			if (efk != -1) kill(efk,SIGEMT);
E 5
			}
			break;
#ifdef SIGTSTP
#define CTRLZ	26
		case CTRLZ:
			mode(0);
			kill(getpid(), SIGTSTP);
			mode(1);
			break;
#endif
		case '%':
			dopercen(&b[2]);
			break;
		default:
			prf("Use `~~' to start line with `~'");
		}
		continue;
	}
}

dopercen(line)
register char *line;
{
	char *args[10];
	register narg, f;
	int rcount;
	for (narg = 0; narg < 10;) {
		while(*line == ' ' || *line == '\t')
			line++;
		if (*line == '\0')
			break;
		args[narg++] = line;
		while(*line != '\0' && *line != ' ' && *line != '\t')
			line++;
		if (*line == '\0')
			break;
		*line++ = '\0';
	}
	if (equal(args[0], "take")) {
		if (narg < 2) {
			prf("usage: ~%%take from [to]");
			return;
		}
		if (narg < 3)
			args[2] = args[1];
D 7
		wrln("echo '~>:'");
E 7
I 7
		write(pipes[1], ">:/dev/null",sizeof(">:/dev/null"));
		if(dbflag) prf("sending take message");
		if (efk != -1) kill(efk,SIGEMT);
		xsleep(5);
		wrln("echo '~>");
E 7
		wrln(args[2]);
D 7
		wrln(";tee /dev/null <");
E 7
I 7
		wrln("'; tee /dev/null <");
E 7
		wrln(args[1]);
		wrln(";echo '~>'\n");
		return;
	} else if (equal(args[0], "put")) {
		if (narg < 2) {
			prf("usage: ~%%put from [to]");
			return;
		}
		if (narg < 3)
			args[2] = args[1];
		if ((f = open(args[1], 0)) < 0) {
			prf("cannot open: %s", args[1]);
			return;
		}
		wrln("stty -echo;cat >");
		wrln(args[2]);
		wrln(";stty echo\n");
		xsleep(5);
		intr = 0;
		if (!nhup)
			signal(SIGINT, sig2);
		mode(2);
		rcount = 0;
		while(!intr && rdc(f) == 1) {
			rcount++;
			if (c == tkill || c == terase)
				wrln("\\");
			if (wrc(ln) != 1) {
				xsleep(2);
				if (wrc(ln) != 1) {
					prf("character missed");
					intr = 1;
					break;
				}
			}
		}
		signal(SIGINT, SIG_IGN);
		close(f);
		if (intr) {
			wrln("\n");
			prf("stopped after %d bytes", rcount);
		}
		wrln("\004");
		xsleep(5);
		mode(1);
		return;
	}
	prf("~%%%s unknown\n", args[0]);
}

equal(s1, s2)
register char *s1, *s2;
{
	while (*s1++ == *s2)
		if (*s2++ == '\0')
			return(1);
	return(0);
}

wrln(s)
register char *s;
{
	while (*s)
		write(ln, s++, 1);
}
/*	chwrsig:  Catch orders from wr process 
 *	to instigate diversion
 */
int whoami;
chwrsig(){
D 7
	int dodiver(); 
E 7
I 7
	int readmsg(); 
E 7
	whoami = getpid();
D 7
	signal(SIGEMT,dodiver);
E 7
I 7
	signal(SIGEMT,readmsg);
E 7
}
D 7
int ds,slnt;
E 7
I 7
int ds,slnt,taking;
E 7
int justrung;
D 7
dodiver(){
	static char dobuff[128], morejunk[256]; register char *cp; 
	FILE *fp;
E 7
I 7
readmsg(){
	static char dobuff[128], morejunk[256];
	int n;
E 7
	justrung = 1;
D 7
	signal(SIGEMT,dodiver);
	sprintf(dobuff,"/tmp/cu%d",whoami);
	fp = fopen(dobuff,"r");
	if(fp==NULL) prf("Couldn't open temporary");
	unlink(dobuff);
E 7
I 7
	signal(SIGEMT,readmsg);
E 7
	if(dbflag) {
D 7
		prf("Name of temporary:");
		prf(dobuff);
E 7
I 7
		prf("About to read from pipe");
E 7
	}
D 7
	fgets(dobuff,128,fp); fclose(fp);
E 7
I 7
	n = read(pipes[0],morejunk,256);
E 7
	if(dbflag) {
D 7
		prf("Name of target file:");
		prf(dobuff);
E 7
I 7
		prf("diversion mesg recieved is");
		prf(morejunk);
		prf(CRLF);
E 7
	}
D 7
	for(cp = dobuff-1; *++cp; ) /* squash newline */
		if(*cp=='\n') *cp=0;
	cp = dobuff;
E 7
I 7
	dodiver(morejunk);
}
dodiver(msg)
char *msg;
{
	register char *cp = msg; 

E 7
	if (*cp=='>') cp++;
	if (*cp==':') {
		cp++;
		if(*cp==0) {
			slnt ^= 1;
			return;
		} else  {
			slnt = 1;
		}
	}
	if (ds >= 0) close(ds);
	if (*cp==0) {
		slnt = 0;
		ds = -1;
		return;
	}
D 7
	if (*dobuff!='>' || (ds=open(cp,1))<0) ds=creat(cp,0644);
E 7
I 7
	if (*msg!='>' || (ds=open(cp,1))<0) ds=creat(cp,0644);
E 7
	lseek(ds, (long)0, 2);
	if(ds < 0) prf("Creat failed:"), prf(cp);
	if (ds<0) prf("Can't divert %s",cp+1);
}


/*
 *	rd: read from remote: line -> 1
D 7
 *	catch:
 *	~>[>][:][file]
 *	stuff from file...
 *	~>	(ends diversion)
E 7
I 7
 *	catch: diversion caught by interrupt routine
E 7
 */

I 7
#define ORDIN 0
#define SAWCR 1
#define EOL   2
#define SAWTL 3
#define DIVER 4

E 7
rd()
{
	extern int ds,slnt;
D 7
	char *p,*q,b[600];
	p=b;
E 7
I 7
	char rb[600], lb[600], *rlim, *llim, c;
	register char *p,*q;
	int cnt, state = 0, mustecho, oldslnt;

E 7
	ds=(-1);
I 7
	p = lb; llim = lb+600;
E 7
agin:
D 7
	while (rdc(ln) == 1) {
		if (!slnt) wrc(1);
D 3
		*p++=c;
E 3
I 3
		if (p < &b[600])
			*p++=c;
E 3
		if (c!='\n') continue;
		q=p; 
		p=b;
		if (b[0]!='~' || b[1]!='>') {
			if (*(q-2) == '\r') {
				q--; 
				*(q-1)=(*q);
E 7
I 7
	while((cnt = read(ln,rb,600)) > 0) {
		if(!slnt) write(1,rb,cnt);
		if(ds < 0) continue;
		oldslnt = slnt;
		for( q=rb, rlim = rb + cnt - 1; q <= rlim; ) {
			c = *q++ & 0177;
			if(p < llim) *p++ = c;
			switch(state) {
			case ORDIN:
				if(c=='\r') state = SAWCR;
				break;
			case SAWCR:
				if(c=='\n') {
					state = EOL;
					p--;
					p[-1] = '\n';
				} else state = ORDIN;
				break;
			case EOL:
				state = (c=='~' ? SAWTL : 
					 (c=='\r' ? SAWCR : ORDIN));
				break;
			case SAWTL:
				state = (c=='>' ? DIVER : 
					 (c=='\r' ? SAWCR : ORDIN));
				break;
			case DIVER:
				if(c=='\r') {
					p--;
				} else if (c=='\n') {
					state = ORDIN;
					p[-1] = 0;
					dodiver(lb+2);
					c = 0; p = lb;
				}
E 7
			}
D 7
			if (ds>=0) write(ds,b,q-b);
			continue;
E 7
I 7
			if(slnt==0 && oldslnt) {
				if(c=='\n') {
					write(ln,lb,p-lb-1);
					write(ln,CRLF,sizeof(CRLF));
				} else if(q==rlim) {
					write(ln,lb,p-lb);
					c = '\n';  /*force flush to file*/
				}
			}
			if(c=='\n') {
				if(ds >= 0)
					write(ds,lb,p-lb);
				p = lb;
			}
E 7
		}
D 7
		if (ds>=0) close(ds);
		if (slnt) {
			write(1, b, q - b);
			write(1, CRLF, sizeof(CRLF));
		}
		if (*(q-2) == '\r') q--;
		*(q-1)=0;
		slnt=0;
		q=b+2;
		if (*q == '>') q++;
		if (*q == ':') {
			slnt=1; 
			q++;
		}
		if (*q == 0) {
			ds=(-1); 
			continue;
		}
		if (b[2]!='>' || (ds=open(q,1))<0) ds=creat(q,0644);
		lseek(ds, (long)0, 2);
		if (ds<0) prf("Can't divert %s",b+1);
E 7
	}
	if(justrung) {
		justrung = 0;
		goto agin;
	}
}

struct {char lobyte; char hibyte;};
mode(f)
{
	struct sgttyb stbuf;
	if (dout) return;
	ioctl(0, TIOCGETP, &stbuf);
	tkill = stbuf.sg_kill;
	terase = stbuf.sg_erase;
	if (f == 0) {
		stbuf.sg_flags &= ~RAW;
		stbuf.sg_flags |= ECHO|CRMOD;
	}
	if (f == 1) {
		stbuf.sg_flags |= RAW;
		stbuf.sg_flags &= ~(ECHO|CRMOD);
	}
	if (f == 2) {
		stbuf.sg_flags &= ~RAW;
		stbuf.sg_flags &= ~(ECHO|CRMOD);
	}
	ioctl(0, TIOCSETP, &stbuf);
}

echo(s)
char *s;
{
	char *p;
	for (p=s;*p;p++);
	if (p>s) write(0,s,p-s);
	write(0,CRLF, sizeof(CRLF));
}

prf(f, s)
char *f;
char *s;
{
	fprintf(stderr, f, s);
	fprintf(stderr, CRLF);
}

exists(devname)
char *devname;
{
	if (access(devname, 0)==0)
		return(1);
	prf("%s does not exist", devname);
	return(0);
I 2
}

cleanup(code)
{
	rmlock(NULL);
	exit(code);
}

/*
 * This code is taken directly from uucp and follows the same
 * conventions.  This is important since uucp and cu should
 * respect each others locks.
 */

	/*  ulockf 3.2  10/26/79  11:40:29  */
/* #include "uucp.h" */
#include <sys/types.h>
#include <sys/stat.h>



/*******
 *	ulockf(file, atime)
 *	char *file;
 *	time_t atime;
 *
 *	ulockf  -  this routine will create a lock file (file).
 *	If one already exists, the create time is checked for
 *	older than the age time (atime).
 *	If it is older, an attempt will be made to unlink it
 *	and create a new one.
 *
 *	return codes:  0  |  FAIL
 */

ulockf(file, atime)
char *file;
time_t atime;
{
	struct stat stbuf;
	time_t ptime;
	int ret;
	static int pid = -1;
	static char tempfile[NAMESIZE];

	if (pid < 0) {
		pid = getpid();
		sprintf(tempfile, "/usr/spool/uucp/LTMP.%d", pid);
	}
	if (onelock(pid, tempfile, file) == -1) {
		/* lock file exists */
		/* get status to check age of the lock file */
		ret = stat(file, &stbuf);
		if (ret != -1) {
			time(&ptime);
			if ((ptime - stbuf.st_ctime) < atime) {
				/* file not old enough to delete */
				return(FAIL);
			}
		}
		ret = unlink(file);
		ret = onelock(pid, tempfile, file);
		if (ret != 0)
			return(FAIL);
	}
	stlock(file);
	return(0);
}


#define MAXLOCKS 10	/* maximum number of lock files */
char *Lockfile[MAXLOCKS];
int Nlocks = 0;

/***
 *	stlock(name)	put name in list of lock files
 *	char *name;
 *
 *	return codes:  none
 */

stlock(name)
char *name;
{
	char *p;
	extern char *calloc();
	int i;

	for (i = 0; i < Nlocks; i++) {
		if (Lockfile[i] == NULL)
			break;
	}
	ASSERT(i < MAXLOCKS, "TOO MANY LOCKS %d", i);
	if (i >= Nlocks)
		i = Nlocks++;
	p = calloc(strlen(name) + 1, sizeof (char));
	ASSERT(p != NULL, "CAN NOT ALLOCATE FOR %s", name);
	strcpy(p, name);
	Lockfile[i] = p;
	return;
}


/***
 *	rmlock(name)	remove all lock files in list
 *	char *name;	or name
 *
 *	return codes: none
 */

rmlock(name)
char *name;
{
	int i;

	for (i = 0; i < Nlocks; i++) {
		if (Lockfile[i] == NULL)
			continue;
		if (name == NULL
		|| strcmp(name, Lockfile[i]) == SAME) {
			unlink(Lockfile[i]);
			free(Lockfile[i]);
			Lockfile[i] = NULL;
		}
	}
	return;
}


/*  this stuff from pjw  */
/*  /usr/pjw/bin/recover - check pids to remove unnecessary locks */
/*	isalock(name) returns 0 if the name is a lock */
/*	unlock(name)  unlocks name if it is a lock*/
/*	onelock(pid,tempfile,name) makes lock a name
	on behalf of pid.  Tempfile must be in the same
	file system as name. */
/*	lock(pid,tempfile,names) either locks all the
	names or none of them */
isalock(name) char *name;
{
	struct stat xstat;
	if(stat(name,&xstat)<0) return(0);
	if(xstat.st_size!=sizeof(int)) return(0);
	return(1);
}
unlock(name) char *name;
{
	if(isalock(name)) return(unlink(name));
	else return(-1);
}
onelock(pid,tempfile,name) char *tempfile,*name;
{	int fd;
	fd=creat(tempfile,0444);
	if(fd<0) return(-1);
	write(fd,(char *) &pid,sizeof(int));
	close(fd);
	if(link(tempfile,name)<0)
	{	unlink(tempfile);
		return(-1);
	}
	unlink(tempfile);
	return(0);
}
lock(pid,tempfile,names) char *tempfile,**names;
{	int i,j;
	for(i=0;names[i]!=0;i++)
	{	if(onelock(pid,tempfile,names[i])==0) continue;
		for(j=0;j<i;j++) unlink(names[j]);
		return(-1);
	}
	return(0);
}

#define LOCKPRE "/usr/spool/uucp/LCK."

/***
 *	delock(s)	remove a lock file
 *	char *s;
 *
 *	return codes:  0  |  FAIL
 */

delock(s)
char *s;
{
	char ln[30];

	sprintf(ln, "%s.%s", LOCKPRE, s);
	rmlock(ln);
}


/***
 *	mlock(sys)	create system lock
 *	char *sys;
 *
 *	return codes:  0  |  FAIL
 */

mlock(sys)
char *sys;
{
	char lname[30];
	sprintf(lname, "%s.%s", LOCKPRE, sys);
	return(ulockf(lname, (time_t) SLCKTIME ) < 0 ? FAIL : 0);
}



/***
 *	ultouch()	update access and modify times for lock files
 *
 *	return code - none
 */

ultouch()
{
	time_t time();
	int i;
	struct ut {
		time_t actime;
		time_t modtime;
	} ut;

	ut.actime = time(&ut.modtime);
	for (i = 0; i < Nlocks; i++) {
		if (Lockfile[i] == NULL)
			continue;
		utime(Lockfile[i], &ut);
	}
	return;
E 2
}
E 1
