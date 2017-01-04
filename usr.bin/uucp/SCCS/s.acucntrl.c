h04077
s 00006/00009/00766
d D 5.15 88/05/04 13:50:52 rick 15 14
c remove restriction on ttyd*;allow 4th arg for uucp use
e
s 00003/00003/00772
d D 5.14 88/04/24 16:40:04 bostic 14 13
c fix for ANSI C
e
s 00001/00001/00774
d D 5.13 88/04/15 19:00:57 bostic 13 12
c typo
e
s 00003/00005/00772
d D 5.12 88/04/05 12:28:20 rick 12 11
c make sure null padded when writing in /etc/utmp
e
s 00006/00001/00771
d D 5.11 88/02/24 21:14:02 rick 11 10
c print error message if not compiled in
e
s 00047/00001/00725
d D 5.10 88/02/24 19:45:09 rick 10 9
c add ifdefs for non-vaxes and sequents
e
s 00001/00005/00725
d D 5.9 87/06/18 23:53:51 bostic 9 8
c fix include problem, this all goes away eventually
e
s 00000/00002/00730
d D 5.8 86/02/12 17:50:09 bloom 8 7
c always compile this even if not being enabled otherwise
e
s 00008/00001/00724
d D 5.7 86/01/24 13:17:46 bloom 7 6
c still more fixes and changes from rick@seismo
e
s 00010/00001/00715
d D 5.6 85/11/01 14:06:10 bloom 6 5
c one field in /etc/ttys may be quoted (from entropy!hubert@uw-beaver)
e
s 00036/00045/00680
d D 5.5 85/10/09 15:28:38 bloom 5 4
c support new format of /etc/ttys (from rick@seismo)
e
s 00227/00089/00498
d D 5.4 85/06/24 09:48:47 bloom 4 3
c add support for new format of /etc/ttys (from rick adams)
e
s 00003/00003/00584
d D 5.3 85/06/19 17:12:17 bloom 3 2
c fix include path and use strncpy
e
s 00054/00038/00533
d D 5.2 85/04/10 15:17:21 ralph 2 1
c more changes from rick adams.
e
s 00571/00000/00000
d D 5.1 85/03/22 10:10:11 ralph 1 0
c date and time created 85/03/22 10:10:11 by ralph
e
u
U
t
T
I 1
#ifndef lint
D 12
static char sccsid[] = "%W% (Berkeley) %G%";
E 12
I 12
static char sccsid[] = "%W%	(Berkeley) %G%";
E 12
#endif

/*  acucntrl - turn around tty line between dialin and dialout
 * 
 * Usage:	acucntrl {enable,disable} /dev/ttydX
 *
 * History:
 *	First written by Allan Wilkes (fisher!allan)
 *
 *	Modified June 8,1983 by W.Sebok (astrovax!wls) to poke kernel rather
 * 	than use kernel hack to turn on/off modem control, using subroutine
 *	stolen from program written by Tsutomu Shimomura
 *	{astrovax,escher}!tsutomu
 *
 *	Worked over many times by W.Sebok (i.e. hacked to death)
 *
 * Operation:
 *   disable (i.e. setup for dialing out)
 *	(1) check input arguments
 *	(2) look in /etc/utmp to check that the line is not in use by another
 *	(3) disable modem control on terminal
 *	(4) check for carrier on device
 *	(5) change owner of device to real id
 *	(6) edit /etc/ttys,  changing the first character of the appropriate
 *	    line to 0
 *	(7) send a hangup to process 1 to poke init to disable getty
 *	(8) post uid name in capitals in /etc/utmp to let world know device has
 *	    been grabbed
 *	(9) make sure that DTR is on
 *
 *   enable (i.e.) restore for dialin
 *	(1) check input arguments
 *	(2) look in /etc/utmp to check that the line is not in use by another
 *	(3) make sure modem control on terminal is disabled
 *	(4) turn off DTR to make sure line is hung up
 *	(5) condition line: clear exclusive use and set hangup on close modes
 *	(6) turn on modem control
 *	(7) edit /etc/ttys,  changing the first character of the appropriate
 *	    line to 1
 *	(8) send a hangup to process 1 to poke init to enable getty
 *	(9) clear uid name for /etc/utmp
 */

/* #define SENSECARRIER */

#include "uucp.h"
I 10
#ifdef DIALINOUT
E 10
I 7
D 8
#ifdef DIALINOUT
E 8
E 7
D 2
#include <sys/param.h>
E 2
#include <sys/buf.h>
I 2
#include <signal.h>
E 2
#include <sys/conf.h>
D 9
#ifdef BSD4_2
D 3
#include "/sys/vaxuba/ubavar.h"
E 3
I 3
#include <vaxuba/ubavar.h>
E 3
D 2
#else !BSD4_2
E 2
I 2
#else
E 2
#include <sys/ubavar.h>
D 2
#endif !BSD4_2
E 2
I 2
#endif
E 9
I 9
D 10
#include "/sys/vaxuba/ubavar.h"
E 10
I 10
#ifdef vax
#ifdef BSD4_2
#include <vaxuba/ubavar.h>
#else
#include <sys/ubavar.h>
#endif
#endif /* vax */
E 10
E 9
E 2
#include <sys/stat.h>
#include <nlist.h>
#include <sgtty.h>
#include <utmp.h>
#include <pwd.h>
#include <stdio.h>
I 5
#include <sys/file.h>
E 5

#define NDZLINE	8	/* lines/dz */
#define NDHLINE	16	/* lines/dh */
#define NDMFLINE 8	/* lines/dmf */

#define DZ11	1
#define DH11	2
#define DMF	3

#define NLVALUE(val)	(nl[val].n_value)

struct nlist nl[] = {
#define CDEVSW	0
	{ "_cdevsw" },

#define DZOPEN	1
	{ "_dzopen" },
#define DZINFO	2
	{ "_dzinfo" },
#define NDZ11	3
	{ "_dz_cnt" },
#define DZSCAR	4
	{ "_dzsoftCAR" },

#define DHOPEN	5
	{ "_dhopen" },
#define DHINFO	6
	{ "_dhinfo" },
#define NDH11	7
	{ "_ndh11" },
#define DHSCAR	8
	{ "_dhsoftCAR" },

#define DMFOPEN	9
	{ "_dmfopen" },
#define DMFINFO	10
	{ "_dmfinfo" },
#define NDMF	11
	{ "_ndmf" },
#define DMFSCAR	12
	{ "_dmfsoftCAR" },

	{ "\0" }
};

#define ENABLE	1
#define DISABLE	0

char Etcutmp[] = "/etc/utmp";
char Etcttys[] = "/etc/ttys";
I 4
#ifdef BSD4_3
I 5
FILE *ttysfile, *nttysfile;
E 5
char NEtcttys[] = "/etc/ttys.new";
extern long ftell();
#endif BSD4_3
E 4
char Devhome[] = "/dev";

char usage[] = "Usage: acucntrl {dis|en}able ttydX\n";

struct utmp utmp;
char resettty, resetmodem;
int etcutmp;
I 14
D 15
extern int errno;
extern char *sys_errlist[];
E 15
E 14
D 2
int utmploc;
int ttyslnbeg;
E 2
I 2
off_t utmploc;
off_t ttyslnbeg;
I 15
extern int errno;
extern char *sys_errlist[];
E 15
I 14
off_t lseek();
E 14
E 2

#define NAMSIZ	sizeof(utmp.ut_name)
#define	LINSIZ	sizeof(utmp.ut_line)

main(argc, argv)
int argc; char *argv[];
{
	register char *p;
	register int i;
	char uname[NAMSIZ], Uname[NAMSIZ];
	int enable ;
	char *device;
	int devfile;
	int uid, gid;
D 2
	long lseek();
E 2
I 2
D 14
	off_t lseek();
E 14
E 2
	struct passwd *getpwuid();
	char *rindex();
D 14
	extern int errno;
	extern char *sys_errlist[];
E 14

	/* check input arguments */
D 15
	if (argc!=3) {
E 15
I 15
	if (argc!=3 && argc != 4) {
E 15
		fprintf(stderr, usage);
		exit(1);
	}

	/* interpret command type */
D 4
	if (prefix(argv[1], "disable")  || strcmp(argv[1],"dialout")==0)
E 4
I 4
	if (prefix(argv[1], "disable")  || strcmp(argv[1], "dialout")==0)
E 4
		enable = 0;
D 4
	else if (prefix(argv[1], "enable")  || strcmp(argv[1],"dialin")==0)
E 4
I 4
	else if (prefix(argv[1], "enable")  || strcmp(argv[1], "dialin")==0)
E 4
		enable = 1;
	else {
		fprintf(stderr, usage);
		exit(1);
	}

D 4
	device = rindex(argv[2],'/');
E 4
I 4
	device = rindex(argv[2], '/');
E 4
	device = (device == NULL) ? argv[2]: device+1;

D 15
	/* only recognize devices of the form ttydX */
D 4
	if (strncmp(device,"ttyd",4)!=0) {
		fprintf(stderr,"Bad Device Name %s",device);
E 4
I 4
	if (strncmp(device, "ttyd", 4)!=0) {
		fprintf(stderr, "Bad Device Name %s", device);
E 4
		exit(1);
	}

E 15
	opnttys(device);

I 10
#ifdef vax
E 10
	/* Get nlist info */
D 4
	nlist("/vmunix",nl);
E 4
I 4
	nlist("/vmunix", nl);
I 10
#endif vax
E 10
E 4

	/* Chdir to /dev */
	if(chdir(Devhome) < 0) {
		fprintf(stderr, "Cannot chdir to %s: %s\r\n",
			Devhome, sys_errlist[errno]);
		exit(1);
	}

	/* Get uid information */
	uid = getuid();
	gid = getgid();

	p = getpwuid(uid)->pw_name;
	if (p==NULL) {
D 4
		fprintf(stderr,"cannot get uid name\n");
E 4
I 4
		fprintf(stderr, "cannot get uid name\n");
E 4
		exit(1);
	}
I 15

	if (strcmp(p, "uucp") == 0 && argc == 4)
		p = argv[3];
E 15

	/*  to upper case */
	i = 0;
	do {
		uname[i] = *p;
D 12
		Uname[i] = (*p>='a' && *p<='z') ? (*p - ('a'-'A')) : *p;
		i++; p++;
	} while (*p && i<NAMSIZ);

E 12
I 12
		Uname[i++] = (*p>='a' && *p<='z') ? (*p - ('a'-'A')) : *p;
	} while (*p++ && i<NAMSIZ);
E 12

	/* check to see if line is being used */
	if( (etcutmp = open(Etcutmp, 2)) < 0) {
D 4
		fprintf(stderr,"On open %s open: %s\n",
			Etcutmp,sys_errlist[errno]);
E 4
I 4
		fprintf(stderr, "On open %s open: %s\n",
			Etcutmp, sys_errlist[errno]);
E 4
		exit(1);
	}

D 4
	(void)lseek(etcutmp,utmploc, 0);
E 4
I 4
	(void)lseek(etcutmp, utmploc, 0);
E 4

D 2
	i = read(etcutmp,&utmp,sizeof(struct utmp));
E 2
I 2
D 4
	i = read(etcutmp,(char *)&utmp,sizeof(struct utmp));
E 4
I 4
	i = read(etcutmp, (char *)&utmp, sizeof(struct utmp));
E 4
E 2

	if(
		i == sizeof(struct utmp) &&
		utmp.ut_line[0] != '\0'  &&
		utmp.ut_name[0] != '\0'  &&
		(
D 4
			!upcase(utmp.ut_name,NAMSIZ) ||
E 4
I 4
			!upcase(utmp.ut_name, NAMSIZ) ||
E 4
			(
				uid != 0 &&
D 4
				strncmp(utmp.ut_name,Uname,NAMSIZ) != 0
E 4
I 4
				strncmp(utmp.ut_name, Uname, NAMSIZ) != 0
E 4
			)
		)
	) {
		fprintf(stderr, "%s in use by %s\n", device, utmp.ut_name);
		exit(2);
	}

I 10
#ifndef sequent
E 10
	/* Disable modem control */
D 4
	if (setmodem(device,DISABLE)<0) {
		fprintf(stderr,"Unable to disable modem control\n");
E 4
I 4
	if (setmodem(device, DISABLE) < 0) {
		fprintf(stderr, "Unable to disable modem control\n");
E 4
		exit(1);
	}
I 10
#endif !sequent
E 10

	if (enable) {
I 10
#ifdef sequent
		if (setmodem(device, ENABLE) < 0) {
			fprintf(stderr, "Cannot Enable modem control\n");
			(void)setmodem(device, i);
			exit(1);
		}
#endif sequent
#ifndef sequent
E 10
		if((devfile = open(device, 1)) < 0) {
D 4
			fprintf(stderr,"On open of %s: %s\n",
E 4
I 4
			fprintf(stderr, "On open of %s: %s\n",
E 4
				device, sys_errlist[errno]);
D 4
			(void)setmodem(device,resetmodem);
E 4
I 4
			(void)setmodem(device, resetmodem);
E 4
			exit(1);
		}
		/* Try one last time to hang up */
D 2
		if (ioctl(devfile,TIOCCDTR,0) < 0)
E 2
I 2
D 4
		if (ioctl(devfile,(int)TIOCCDTR,(char *)0) < 0)
E 2
			fprintf(stderr,"On TIOCCDTR ioctl: %s\n",
E 4
I 4
		if (ioctl(devfile, (int)TIOCCDTR, (char *)0) < 0)
			fprintf(stderr, "On TIOCCDTR ioctl: %s\n",
E 4
				sys_errlist[errno]);

D 2
		if (ioctl(devfile, TIOCNXCL,0) < 0)
E 2
I 2
D 4
		if (ioctl(devfile, (int)TIOCNXCL,(char *)0) < 0)
E 4
I 4
		if (ioctl(devfile, (int)TIOCNXCL, (char *)0) < 0)
E 4
E 2
			fprintf(stderr,
			    "Cannot clear Exclusive Use on %s: %s\n",
				device, sys_errlist[errno]);

D 2
		if (ioctl(devfile, TIOCHPCL,0) < 0)
E 2
I 2
D 4
		if (ioctl(devfile, (int)TIOCHPCL,(char *)0) < 0)
E 4
I 4
		if (ioctl(devfile, (int)TIOCHPCL, (char *)0) < 0)
E 4
E 2
			fprintf(stderr,
			    "Cannot set hangup on close on %s: %s\n",
				device, sys_errlist[errno]);

I 10
#endif !sequent
E 10
		i = resetmodem;

I 10
#ifndef sequent
E 10
D 4
		if (setmodem(device,ENABLE) < 0) {
			fprintf(stderr,"Cannot Enable modem control\n");
			(void)setmodem(device,i);
E 4
I 4
		if (setmodem(device, ENABLE) < 0) {
			fprintf(stderr, "Cannot Enable modem control\n");
			(void)setmodem(device, i);
E 4
			exit(1);
		}
I 10
#endif sequent
E 10
		resetmodem=i;

D 2
		settys(ENABLE);

		pokeinit(device,Uname,enable);
E 2
I 2
		if (settys(ENABLE)) {
D 4
			fprintf(stderr,"%s already enabled\n",device);
E 4
I 4
			fprintf(stderr, "%s already enabled\n", device);
E 4
		} else {
D 4
			pokeinit(device,Uname,enable);
E 4
I 4
			pokeinit(device, Uname, enable);
E 4
		}
E 2
D 4
		post(device,"");
E 4
I 4
		post(device, "");
E 4

	} else {
#if defined(TIOCMGET) && defined(SENSECARRIER)
		if (uid!=0) {
			int linestat = 0;

			/* check for presence of carrier */
			sleep(2); /* need time after modem control turnoff */

			if((devfile = open(device, 1)) < 0) {
D 4
				fprintf(stderr,"On open of %s: %s\n",
E 4
I 4
				fprintf(stderr, "On open of %s: %s\n",
E 4
					device, sys_errlist[errno]);
D 4
				(void)setmodem(device,resetmodem);
E 4
I 4
				(void)setmodem(device, resetmodem);
E 4
				exit(1);
			}

D 4
			(void)ioctl(devfile,TIOCMGET,&linestat);
E 4
I 4
			(void)ioctl(devfile, TIOCMGET, &linestat);
E 4

			if (linestat&TIOCM_CAR) {
D 4
				fprintf(stderr,"%s is in use (Carrier On)\n",
E 4
I 4
				fprintf(stderr, "%s is in use (Carrier On)\n",
E 4
					device);
D 4
				(void)setmodem(device,resetmodem);
E 4
I 4
				(void)setmodem(device, resetmodem);
E 4
				exit(2);
			}
			(void)close(devfile);
		}
#endif TIOCMGET
		/* chown device */
		if(chown(device, uid, gid) < 0)
			fprintf(stderr, "Cannot chown %s: %s\n",
				device, sys_errlist[errno]);


		/* poke init */
D 2
		settys(DISABLE);
		pokeinit(device,Uname,enable);
E 2
I 2
		if(settys(DISABLE)) {
D 4
			fprintf(stderr,"%s already disabled\n",device);
E 4
I 4
			fprintf(stderr, "%s already disabled\n", device);
E 4
		} else {
D 4
			pokeinit(device,Uname,enable);
E 4
I 4
			pokeinit(device, Uname, enable);
E 4
		}
E 2
D 4
		post(device,Uname);
E 4
I 4
		post(device, Uname);
I 10
#ifdef sequent
	/* Disable modem control */
	if (setmodem(device, DISABLE) < 0) {
		fprintf(stderr, "Unable to disable modem control\n");
		exit(1);
	}
#endif sequent
E 10
E 4
D 5
		if((devfile = open(device, 1)) < 0) {
E 5
I 5
		if((devfile = open(device, O_RDWR|O_NDELAY)) < 0) {
E 5
			fprintf(stderr, "On %s open: %s\n",
				device, sys_errlist[errno]);
		} else {
D 2
			if(ioctl(devfile, TIOCSDTR, 0) < 0)
E 2
I 2
			if(ioctl(devfile, (int)TIOCSDTR, (char *)0) < 0)
E 2
				fprintf(stderr,
				    "Cannot set DTR on %s: %s\n",
					device, sys_errlist[errno]);
		}
	}

	exit(0);
}

/* return true if no lower case */
D 4
upcase(str,len)
E 4
I 4
upcase(str, len)
E 4
register char *str;
register int len;
{
	for (; *str, --len >= 0 ; str++)
		if (*str>='a' && *str<='z')
			return(0);
	return(1);
}

/* Post name to public */
D 4
post(device,name)
E 4
I 4
post(device, name)
E 4
char *device, *name;
{
D 2
	(void)time(&utmp.ut_time);
E 2
I 2
	(void)time((time_t *)&utmp.ut_time);
E 2
D 3
	strcpyn(utmp.ut_line, device, LINSIZ);
	strcpyn(utmp.ut_name, name,  NAMSIZ);
E 3
I 3
	strncpy(utmp.ut_line, device, LINSIZ);
	strncpy(utmp.ut_name, name,  NAMSIZ);
E 3
D 5
	if (lseek(etcutmp, utmploc, 0)<0)
E 5
I 5
	if (lseek(etcutmp, utmploc, 0) < 0)
E 5
D 4
		fprintf(stderr,"on lseek in /etc/utmp: %s",
E 4
I 4
		fprintf(stderr, "on lseek in /etc/utmp: %s",
E 4
			sys_errlist[errno]);
D 5
	if (write(etcutmp, (char *)&utmp, sizeof(utmp))<0)
E 5
I 5
	if (write(etcutmp, (char *)&utmp, sizeof(utmp)) < 0)
E 5
D 4
		fprintf(stderr,"on write in /etc/utmp: %s",
E 4
I 4
		fprintf(stderr, "on write in /etc/utmp: %s",
E 4
			sys_errlist[errno]);
}
	
/* poke process 1 and wait for it to do its thing */
D 4
pokeinit(device,uname,enable)
E 4
I 4
pokeinit(device, uname, enable)
E 4
char *uname, *device; int enable;
{
	struct utmp utmp;
I 2
	register int i;
E 2

	post(device, uname);

	/* poke init */
	if (kill(1, SIGHUP)) {
		fprintf(stderr,
		    "Cannot send hangup to init process: %s\n",
			sys_errlist[errno]);
D 2
		settys(resettty);
E 2
I 2
		(void)settys(resettty);
E 2
D 4
		(void)setmodem(device,resetmodem);
E 4
I 4
		(void)setmodem(device, resetmodem);
E 4
		exit(1);
	}

	if (enable)
		return;

	/* wait till init has responded, clearing the utmp entry */
I 2
D 5
	i=100;
E 5
I 5
	i = 100;
E 5
E 2
	do {
		sleep(1);
D 4
		if (lseek(etcutmp,utmploc,0)<0)
			fprintf(stderr,"On lseek in /etc/utmp: %s",
E 4
I 4
D 5
		if (lseek(etcutmp, utmploc, 0)<0)
E 5
I 5
		if (lseek(etcutmp, utmploc, 0) < 0)
E 5
			fprintf(stderr, "On lseek in /etc/utmp: %s",
E 4
				sys_errlist[errno]);
D 2
		if (read(etcutmp,&utmp,sizeof utmp)<0)
E 2
I 2
D 4
		if (read(etcutmp,(char *)&utmp,sizeof utmp)<0)
E 2
			fprintf(stderr,"On read from /etc/utmp: %s",
E 4
I 4
D 5
		if (read(etcutmp, (char *)&utmp, sizeof utmp)<0)
E 5
I 5
		if (read(etcutmp, (char *)&utmp, sizeof utmp) < 0)
E 5
			fprintf(stderr, "On read from /etc/utmp: %s",
E 4
				sys_errlist[errno]);
D 2
	} while (utmp.ut_name[0] !='\0');
E 2
I 2
	} while (utmp.ut_name[0] != '\0' && --i > 0);
E 2
}

I 4
#ifdef BSD4_3
E 4
/* identify terminal line in ttys */
opnttys(device)
char *device;
{
I 4
D 5
	register FILE *ttysfile, *nttysfile;
E 5
	register int  ndevice; 
	register char *p;
	char *index();
	char linebuf[BUFSIZ];

D 5
	ttysfile = fopen(Etcttys, "r");
	if(ttysfile == NULL) {
		fprintf(stderr, "Cannot open %s: %s\n", Etcttys,
			sys_errlist[errno]);
		exit(1);
	}
E 5
I 5
	ttysfile = NULL;
	do {
		if (ttysfile != NULL) {
			fclose(ttysfile);
			sleep(5);
		}
		ttysfile = fopen(Etcttys, "r");
		if(ttysfile == NULL) {
			fprintf(stderr, "Cannot open %s: %s\n", Etcttys,
				sys_errlist[errno]);
			exit(1);
		}
	} while (flock(fileno(ttysfile), LOCK_NB|LOCK_EX) < 0);
E 5
	nttysfile = fopen(NEtcttys, "w");
	if(nttysfile == NULL) {
		fprintf(stderr, "Cannot open %s: %s\n", Etcttys,
			sys_errlist[errno]);
		exit(1);
	}

	ndevice = strlen(device);
I 7
#ifndef BRL4_2
E 7
D 5
	utmploc = 0;
E 5
I 5
	utmploc = sizeof(utmp);
I 7
#else BRL4_2
	utmploc = 0;
#endif BRL4_2
E 7
E 5

D 5
	ttyslnbeg = 0;
E 5
	while(fgets(linebuf, sizeof(linebuf) - 1, ttysfile) != NULL) {
D 5
		utmploc += sizeof(utmp);
		if(strncmp(device, linebuf, ndevice) == 0) {
			fclose(ttysfile);
			fclose(nttysfile);
E 5
I 5
		if(strncmp(device, linebuf, ndevice) == 0)
E 5
			return;
D 5
		}
		ttyslnbeg = ftell(ttysfile);
E 5
I 5
		ttyslnbeg += strlen(linebuf);
D 7
		utmploc += sizeof(utmp);
E 7
I 7
		if (linebuf[0] != '#' && linebuf[0] != '\0')
			utmploc += sizeof(utmp);
E 7
E 5
		if (fputs(linebuf, nttysfile) == NULL) {
			fprintf(stderr, "On %s write: %s\n",
				Etcttys, sys_errlist[errno]);
			exit(1);
		}
		
	}
	fprintf(stderr, "%s not found in %s\n", device, Etcttys);
	exit(1);
}

/* modify appropriate line in /etc/ttys to turn on/off the device */
settys(enable)
int enable;
{
	register char *cp, *cp2;
D 5
	FILE *ittysfil, *nttysfil;
E 5
	char lbuf[BUFSIZ];
	int i;
	char c1, c2;

D 5
	ittysfil = fopen(Etcttys, "r");
	if(ittysfil == NULL) {
		fprintf(stderr, "Cannot open %s for output: %s\n",
			Etcttys, sys_errlist[errno]);
		exit(1);
	}
	nttysfil = fopen(NEtcttys, "a");
	if(nttysfil == NULL) {
		fprintf(stderr, "Cannot open %s for output: %s\n",
			NEtcttys, sys_errlist[errno]);
		exit(1);
	}
	(void)fseek(ittysfil, ttyslnbeg, 0);
	if(fgets(lbuf, BUFSIZ, ittysfil) == NULL) {
E 5
I 5
	(void) fseek(ttysfile, ttyslnbeg, 0);
	if(fgets(lbuf, BUFSIZ, ttysfile) == NULL) {
E 5
		fprintf(stderr, "On %s read: %s\n",
			Etcttys, sys_errlist[errno]);
		exit(1);
	}
	/* format is now */
	/* ttyd0 std.100 dialup on secure # comment */
I 6
	/* except, 2nd item may have embedded spaces inside quotes, Hubert */
E 6
	cp = lbuf;
	for (i=0;*cp && i<3;i++) {
D 6
		while (*cp && *cp != ' ' && *cp != '\t')
E 6
I 6
		if (*cp == '"') {
E 6
			cp++;
I 6
			while (*cp && *cp != '"')
				cp++;
			if (*cp != '\0')
				cp++;
		}else {
			while (*cp && *cp != ' ' && *cp != '\t')
				cp++;
		}
E 6
		while (*cp && (*cp == ' ' || *cp == '\t'))
			cp++;
	}
	if (*cp == '\0') {
		fprintf(stderr,"Badly formatted line in /etc/ttys:\n%s", lbuf);
		exit(1);
	}
	c1 = *--cp;
	*cp++ = '\0';
	cp2 = cp;
	while (*cp && *cp != ' ' && *cp != '\t' && *cp != '\n')
		cp++;
	if (*cp == '\0') {
		fprintf(stderr,"Badly formatted line in /etc/ttys:\n%s", lbuf);
		exit(1);
	}
	c2 = *cp;
	*cp++ = '\0';
	while (*cp && (*cp == ' ' || *cp == '\t'))
		cp++;
	resettty = strcmp("on", cp2) != 0;
D 5
	fprintf(nttysfil,"%s%c%s%c%s", lbuf, c1, enable ? "on" : "off", c2, cp);
	if (ferror(nttysfil)) {
E 5
I 5
	fprintf(nttysfile,"%s%c%s%c%s", lbuf, c1, enable ? "on" : "off", c2, cp);
	if (ferror(nttysfile)) {
E 5
		fprintf(stderr, "On %s fprintf: %s\n",
			NEtcttys, sys_errlist[errno]);
		exit(1);
	}
D 5
	while(fgets(lbuf, sizeof(lbuf) - 1, ittysfil) != NULL) {
		if (fputs(lbuf, nttysfil) == NULL) {
E 5
I 5
	while(fgets(lbuf, sizeof(lbuf) - 1, ttysfile) != NULL) {
		if (fputs(lbuf, nttysfile) == NULL) {
E 5
			fprintf(stderr, "On %s write: %s\n",
				NEtcttys, sys_errlist[errno]);
			exit(1);
		}
	}
		
	if (enable^resettty)
		(void) unlink(NEtcttys);
	else {
		struct stat statb;
		if (stat(Etcttys, &statb) == 0) {
D 5
			fchmod(fileno(nttysfil) ,statb.st_mode);
			fchown(fileno(nttysfil), statb.st_uid, statb.st_gid);
E 5
I 5
			fchmod(fileno(nttysfile) ,statb.st_mode);
			fchown(fileno(nttysfile), statb.st_uid, statb.st_gid);
E 5
		}
		(void) rename(NEtcttys, Etcttys);
	}
D 5
	(void) fclose(ittysfil);
	(void) fclose(nttysfil);
E 5
I 5
	(void) fclose(nttysfile);
	(void) fclose(ttysfile);
E 5
	return enable^resettty;
}

#else !BSD4_3

/* identify terminal line in ttys */
opnttys(device)
char *device;
{
E 4
	register FILE *ttysfile;
	register int  ndevice, lnsiz; 
	register char *p;
	char *index();
D 4
	char linebuf[100];
E 4
I 4
	char linebuf[BUFSIZ];
E 4

	ttysfile = fopen(Etcttys, "r");
	if(ttysfile == NULL) {
		fprintf(stderr, "Cannot open %s: %s\n", Etcttys,
			sys_errlist[errno]);
		exit(1);
	}

	ndevice = strlen(device);
	ttyslnbeg = 0;
	utmploc = 0;

	while(fgets(linebuf, sizeof(linebuf) - 1, ttysfile) != NULL) {
D 5
		utmploc += sizeof(utmp);
E 5
		lnsiz = strlen(linebuf);
D 4
		if ((p = index(linebuf,'\n')) != NULL)
E 4
I 4
		if ((p = index(linebuf, '\n')) != NULL)
E 4
			*p = '\0';
		if(strncmp(device, &linebuf[2], ndevice) == 0) {
			(void)fclose(ttysfile);
I 10
#ifdef sequent
			/* Why is the sequent off by one? */
			utmploc += sizeof(utmp);
#endif sequent
E 10
			return;
		}
		ttyslnbeg += lnsiz;
I 5
		utmploc += sizeof(utmp);
E 5
	}
	fprintf(stderr, "%s not found in %s\n", device, Etcttys);
	exit(1);
}

/* modify appropriate line in /etc/ttys to turn on/off the device */
settys(enable)
int enable;
{
	int ittysfil;
D 2
	int  lnbeg, foundit, ndevice; 
E 2
D 4
	char out,in;
E 4
I 4
	char out, in;
E 4

	ittysfil = open(Etcttys, 2);
D 4
	if(ittysfil == NULL) {
E 4
I 4
	if(ittysfil < 0) {
E 4
		fprintf(stderr, "Cannot open %s for output: %s\n",
			Etcttys, sys_errlist[errno]);
		exit(1);
	}
D 2
	(void)lseek(ittysfil,(long)ttyslnbeg,0);
E 2
I 2
D 4
	(void)lseek(ittysfil,ttyslnbeg,0);
E 2
	if(read(ittysfil,&in,1)<0) {
		fprintf(stderr,"On %s write: %s\n",
E 4
I 4
	(void)lseek(ittysfil, ttyslnbeg, 0);
	if(read(ittysfil, &in, 1)<0) {
		fprintf(stderr, "On %s write: %s\n",
E 4
			Etcttys, sys_errlist[errno]);
		exit(1);
	}
	resettty = (in == '1');
	out = enable ? '1' : '0';
D 2
	(void)lseek(ittysfil,(long)ttyslnbeg,0);
E 2
I 2
D 4
	(void)lseek(ittysfil,ttyslnbeg,0);
E 2
	if(write(ittysfil,&out,1)<0) {
		fprintf(stderr,"On %s write: %s\n",
E 4
I 4
	(void)lseek(ittysfil, ttyslnbeg, 0);
	if(write(ittysfil, &out, 1)<0) {
		fprintf(stderr, "On %s write: %s\n",
E 4
			Etcttys, sys_errlist[errno]);
		exit(1);
	}
	(void)close(ittysfil);
I 2
	return(in==out);
E 2
}
I 4
#endif !BSD4_3
E 4

I 10
#ifdef sequent
setmodem(ttyline, enable)
char *ttyline; int enable;
{
	char *sysbuf[BUFSIZ];
	sprintf(sysbuf,"/etc/ttyconfig /dev/%s -special %s", ttyline,
		enable ? "-carrier" : "-nocarrier");
	system(sysbuf);
}
#endif /* sequent */
#ifdef vax
E 10
/*
D 4
 * Excerpted from (June 8,1983 W.Sebok)
E 4
I 4
 * Excerpted from (June 8, 1983 W.Sebok)
E 4
 * > ttymodem.c - enable/disable modem control for tty lines.
 * >
 * > Knows about DZ11s and DH11/DM11s.
 * > 23.3.83 - TS
D 4
 * > modified to know about DMF's  (hasn't been tested) Nov 8,1984 - WLS
E 4
I 4
 * > modified to know about DMF's  (hasn't been tested) Nov 8, 1984 - WLS
E 4
 */


D 4
setmodem(ttyline,enable)
E 4
I 4
setmodem(ttyline, enable)
E 4
char *ttyline; int enable;
{
	dev_t dev;
	int kmem;
D 4
	int unit,line,nlines,addr,tflags;
E 4
I 4
	int unit, line, nlines, addr, tflags;
E 4
I 2
	int devtype=0;
	char cflags; short sflags;
#ifdef BSD4_2
	int flags;
#else
	short flags;
#endif
E 2
	struct uba_device *ubinfo;
	struct stat statb;
D 2
	short flags,devtype=0;
E 2
	struct cdevsw cdevsw;

	if(nl[CDEVSW].n_type == 0) {
D 4
		fprintf(stderr,"No namelist.\n");
E 4
I 4
		fprintf(stderr, "No namelist.\n");
E 4
		return(-1);
	}

	if((kmem = open("/dev/kmem", 2)) < 0) {
D 4
		fprintf(stderr,"/dev/kmem open: %s\n", sys_errlist[errno]);
E 4
I 4
		fprintf(stderr, "/dev/kmem open: %s\n", sys_errlist[errno]);
E 4
		return(-1);
	}

D 4
	if(stat(ttyline,&statb) < 0) {
		fprintf(stderr,"%s stat: %s\n", ttyline, sys_errlist[errno]);
E 4
I 4
	if(stat(ttyline, &statb) < 0) {
		fprintf(stderr, "%s stat: %s\n", ttyline, sys_errlist[errno]);
E 4
		return(-1);
	}

D 2
	if(statb.st_mode&S_IFMT != S_IFCHR) {
E 2
I 2
	if((statb.st_mode&S_IFMT) != S_IFCHR) {
E 2
D 4
		fprintf(stderr,"%s is not a character device.\n",ttyline);
E 4
I 4
		fprintf(stderr, "%s is not a character device.\n",ttyline);
E 4
		return(-1);
	}

	dev = statb.st_rdev;
	(void)lseek(kmem,
D 2
		(int) &(((struct cdevsw *)NLVALUE(CDEVSW))[major(dev)]),0);
E 2
I 2
		(off_t) &(((struct cdevsw *)NLVALUE(CDEVSW))[major(dev)]),0);
E 2
D 4
	(void)read(kmem,(char *) &cdevsw,sizeof cdevsw);
E 4
I 4
	(void)read(kmem, (char *) &cdevsw, sizeof cdevsw);
E 4

	if((int)(cdevsw.d_open) == NLVALUE(DZOPEN)) {
		devtype = DZ11;
		unit = minor(dev) / NDZLINE;
		line = minor(dev) % NDZLINE;
		addr = (int) &(((int *)NLVALUE(DZINFO))[unit]);
D 2
		(void)lseek(kmem,(int) NLVALUE(NDZ11),0);
E 2
I 2
D 4
		(void)lseek(kmem,(off_t) NLVALUE(NDZ11),0);
E 4
I 4
		(void)lseek(kmem, (off_t) NLVALUE(NDZ11), 0);
E 4
E 2
	} else if((int)(cdevsw.d_open) == NLVALUE(DHOPEN)) {
		devtype = DH11;
		unit = minor(dev) / NDHLINE;
		line = minor(dev) % NDHLINE;
		addr = (int) &(((int *)NLVALUE(DHINFO))[unit]);
D 2
		(void)lseek(kmem,(int) NLVALUE(NDH11),0);
E 2
I 2
D 4
		(void)lseek(kmem,(off_t) NLVALUE(NDH11),0);
E 4
I 4
		(void)lseek(kmem, (off_t) NLVALUE(NDH11), 0);
E 4
E 2
	} else if((int)(cdevsw.d_open) == NLVALUE(DMFOPEN)) {
		devtype = DMF;
		unit = minor(dev) / NDMFLINE;
		line = minor(dev) % NDMFLINE;
		addr = (int) &(((int *)NLVALUE(DMFINFO))[unit]);
D 2
		(void)lseek(kmem,(int) NLVALUE(NDMF),0);
E 2
I 2
D 4
		(void)lseek(kmem,(off_t) NLVALUE(NDMF),0);
E 4
I 4
		(void)lseek(kmem, (off_t) NLVALUE(NDMF), 0);
E 4
E 2
	} else {
D 4
		fprintf(stderr,"Device %s (%d/%d) unknown.\n",ttyline,
		    major(dev),minor(dev));
E 4
I 4
		fprintf(stderr, "Device %s (%d/%d) unknown.\n", ttyline,
		    major(dev), minor(dev));
E 4
		return(-1);
	}

D 4
	(void)read(kmem,(char *) &nlines,sizeof nlines);
E 4
I 4
	(void)read(kmem, (char *) &nlines, sizeof nlines);
E 4
	if(minor(dev) >= nlines) {
D 4
		fprintf(stderr,"Sub-device %d does not exist (only %d).\n",
		    minor(dev),nlines);
E 4
I 4
		fprintf(stderr, "Sub-device %d does not exist (only %d).\n",
		    minor(dev), nlines);
E 4
		return(-1);
	}

D 2
	(void)lseek(kmem,addr,0);
E 2
I 2
D 4
	(void)lseek(kmem,(off_t)addr,0);
E 2
	(void)read(kmem,(char *) &ubinfo,sizeof ubinfo);
D 2
	(void)lseek(kmem,(int) &(ubinfo->ui_flags),0);
E 2
I 2
	(void)lseek(kmem,(off_t) &(ubinfo->ui_flags),0);
E 2
	(void)read(kmem,(char *) &flags,sizeof flags);
E 4
I 4
	(void)lseek(kmem, (off_t)addr, 0);
	(void)read(kmem, (char *) &ubinfo, sizeof ubinfo);
	(void)lseek(kmem, (off_t) &(ubinfo->ui_flags), 0);
	(void)read(kmem, (char *) &flags, sizeof flags);
E 4

	tflags = 1<<line;
	resetmodem = ((flags&tflags) == 0);
	flags = enable ? (flags & ~tflags) : (flags | tflags);
D 2
	(void)lseek(kmem,(int) &(ubinfo->ui_flags),0);
E 2
I 2
D 4
	(void)lseek(kmem,(off_t) &(ubinfo->ui_flags),0);
E 2
	(void)write(kmem,(char *) &flags, sizeof flags);
E 4
I 4
	(void)lseek(kmem, (off_t) &(ubinfo->ui_flags), 0);
	(void)write(kmem, (char *) &flags, sizeof flags);
E 4
	switch(devtype) {
		case DZ11:
			if((addr = NLVALUE(DZSCAR)) == 0) {
D 4
				fprintf(stderr,"No dzsoftCAR.\n");
E 4
I 4
				fprintf(stderr, "No dzsoftCAR.\n");
E 4
				return(-1);
			}
D 2
			(void)lseek(kmem,(int) &(((char *)addr)[unit]),0);
			(void)write(kmem,(char *) &flags, sizeof flags);
E 2
I 2
			cflags = flags;
D 4
			(void)lseek(kmem,(off_t) &(((char *)addr)[unit]),0);
			(void)write(kmem,(char *) &cflags, sizeof cflags);
E 4
I 4
			(void)lseek(kmem, (off_t) &(((char *)addr)[unit]), 0);
			(void)write(kmem, (char *) &cflags, sizeof cflags);
E 4
E 2
			break;
		case DH11:
			if((addr = NLVALUE(DHSCAR)) == 0) {
D 4
				fprintf(stderr,"No dhsoftCAR.\n");
E 4
I 4
				fprintf(stderr, "No dhsoftCAR.\n");
E 4
				return(-1);
			}
D 2
			(void)lseek(kmem,(int) &(((short *)addr)[unit]),0);
			(void)write(kmem,(char *) &flags, sizeof flags);
E 2
I 2
			sflags = flags;
D 4
			(void)lseek(kmem,(off_t) &(((short *)addr)[unit]),0);
			(void)write(kmem,(char *) &sflags, sizeof sflags);
E 4
I 4
			(void)lseek(kmem, (off_t) &(((short *)addr)[unit]), 0);
			(void)write(kmem, (char *) &sflags, sizeof sflags);
E 4
E 2
			break;
		case DMF:
			if((addr = NLVALUE(DMFSCAR)) == 0) {
D 4
				fprintf(stderr,"No dmfsoftCAR.\n");
E 4
I 4
				fprintf(stderr, "No dmfsoftCAR.\n");
E 4
				return(-1);
			}
D 2
			(void)lseek(kmem,(int) &(((short *)addr)[unit]),0);
			(void)write(kmem,(char *) &flags,2);
E 2
I 2
			cflags = flags;
D 4
			(void)lseek(kmem,(off_t) &(((char *)addr)[unit]),0);
			(void)write(kmem,(char *) &flags, sizeof cflags);
E 4
I 4
			(void)lseek(kmem, (off_t) &(((char *)addr)[unit]), 0);
D 13
			(void)write(kmem, (char *) &flags, sizeof cflags);
E 13
I 13
			(void)write(kmem, (char *) &cflags, sizeof cflags);
E 13
E 4
E 2
			break;
		default:
D 4
			fprintf(stderr,"Unknown device type\n");
E 4
I 4
			fprintf(stderr, "Unknown device type\n");
E 4
			return(-1);
	}
	return(0);
}
I 10
#endif /* vax */
E 10

prefix(s1, s2)
	register char *s1, *s2;
{
	register char c;

	while ((c = *s1++) == *s2++)
		if (c == '\0')
			return (1);
	return (c == '\0');
}
I 10
D 11
#endif /* DIALINOUT */
E 11
I 11
#else	/* !DIALINOUT */
main()
{
	fprintf(stderr,"acucntrl is not supported on this system\n");
}
#endif /* !DIALINOUT */
E 11
E 10
I 7
D 8
#endif DIALINOUT
E 8
E 7
E 1
