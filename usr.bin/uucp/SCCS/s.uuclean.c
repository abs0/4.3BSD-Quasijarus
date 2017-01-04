h09887
s 00013/00013/00218
d D 5.7 88/02/24 20:02:12 rick 7 6
c rewrite to use readdir directly for speed
e
s 00001/00000/00230
d D 5.6 85/10/09 16:20:56 bloom 6 5
c need Now defined (from rick@seismo)
e
s 00003/00005/00227
d D 5.5 85/06/23 13:13:57 bloom 5 4
c cleanup from rick adams
e
s 00000/00001/00232
d D 5.4 85/04/10 15:21:20 ralph 4 3
c more changes from rick adams.
e
s 00021/00025/00212
d D 5.3 85/01/22 14:11:44 ralph 3 2
c bug fixes and changes from Rick Adams
e
s 00001/00001/00236
d D 5.2 83/07/02 18:05:45 sam 2 1
c include fixes
e
s 00237/00000/00000
d D 5.1 83/07/02 17:57:41 sam 1 0
c date and time created 83/07/02 17:57:41 by sam
e
u
U
t
T
I 1
#ifndef lint
D 7
static char sccsid[] = "%W% (Berkeley) %G%";
E 7
I 7
static char sccsid[] = "%W%	%G%";
E 7
#endif

D 5
#include "uucp.h"
E 5
#include <signal.h>
I 5
#include "uucp.h"
E 5
#include <pwd.h>
D 4
#include <sys/types.h>
E 4
#include <sys/stat.h>
#ifdef	NDIR
#include "ndir.h"
#else
D 2
#include <dir.h>
E 2
I 2
#include <sys/dir.h>
E 2
#endif

D 5
extern time_t time();

D 3

E 3
/*******
E 5
I 5
/*
E 5
 *
D 5
 *	uuclean  -  this program will search through the spool
E 5
I 5
 *	this program will search through the spool
E 5
 *	directory (Spool) and delete all files with a requested
 *	prefix which are older than (nomtime) seconds.
 *	If the -m option is set, the program will try to
 *	send mail to the usid of the file.
 *
 *	options:
 *		-m  -  send mail for deleted file
 *		-d  -  directory to clean
 *		-n  -  time to age files before delete (in hours)
 *		-p  -  prefix for search
 *		-x  -  turn on debug outputs
 *	exit status:
 *		0  -  normal return
 *		1  -  can not read directory
 */

D 3
#define DPREFIX "U"
E 3
#define NOMTIME 72	/* hours to age files before deletion */

I 3
int checkprefix = 0;
I 6
struct timeb Now;
E 6

E 3
main(argc, argv)
char *argv[];
{
D 7
	DIR *dirp;
	char file[NAMESIZE];
E 7
I 7
	register DIR *dirp;
	register struct direct *dentp;
E 7
	time_t nomtime, ptime;
	struct stat stbuf;
D 7
	int mflg=0;
E 7
I 7
	int mflg = 0;
E 7
D 3
	int orig_uid = getuid();
E 3

	strcpy(Progname, "uuclean");
	uucpname(Myname);
	nomtime = NOMTIME * (time_t)3600;

	while (argc>1 && argv[1][0] == '-') {
		switch (argv[1][1]) {
		case 'd':
			Spool = &argv[1][2];
			break;
		case 'm':
			mflg = 1;
			break;
		case 'n':
			nomtime = atoi(&argv[1][2]) * (time_t)3600;
			break;
		case 'p':
I 3
			checkprefix = 1;
E 3
			if (&argv[1][2] != '\0')
				stpre(&argv[1][2]);
			break;
		case 'x':
D 3
			chkdebug(orig_uid);
E 3
I 3
			chkdebug();
E 3
			Debug = atoi(&argv[1][2]);
			if (Debug <= 0)
				Debug = 1;
			break;
		default:
			printf("unknown flag %s\n", argv[1]); break;
		}
		--argc;  argv++;
	}

	DEBUG(4, "DEBUG# %s\n", "START");
D 3
	chdir(Spool);	/* NO subdirs in uuclean!  rti!trt */
E 3
I 3
	if (chdir(Spool) < 0) {	/* NO subdirs in uuclean!  rti!trt */
		printf("%s directory inaccessible\n", Spool);
		exit(1);
	}
E 3

	if ((dirp = opendir(Spool)) == NULL) {
		printf("%s directory unreadable\n", Spool);
		exit(1);
	}

	time(&ptime);
D 7
	while (gnamef(dirp, file)) {
D 3
		if (!chkpre(file))
E 3
I 3
		if (checkprefix && !chkpre(file))
E 7
I 7
	while (dentp = readdir(dirp)) {
		if (checkprefix && !chkpre(dentp->d_name))
E 7
E 3
			continue;

D 3
		if (stat(file, &stbuf) == -1) {	/* NO subdirs in uuclean! */
		DEBUG(4, "stat on %s failed\n", file);
E 3
I 3
D 7
		if (stat(file, &stbuf) == -1) {
			DEBUG(4, "stat on %s failed\n", file);
E 7
I 7
		if (stat(dentp->d_name, &stbuf) == -1) {
			DEBUG(4, "stat on %s failed\n", dentp->d_name);
E 7
E 3
			continue;
		}


		if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
			continue;
D 3
/*
 * teklabs.1518, Terry Laskodi, +2s/ctime/mtime/
 * so mv-ing files about does not defeat uuclean
 */
E 3
		if ((ptime - stbuf.st_mtime) < nomtime)
			continue;
D 7
		if (file[0] == CMDPRE)
			notfyuser(file);
		DEBUG(4, "unlink file %s\n", file);
		unlink(file);
E 7
I 7
		if (dentp->d_name[0] == CMDPRE)
			notfyuser(dentp->d_name);
		DEBUG(4, "unlink file %s\n", dentp->d_name);
		unlink(dentp->d_name);
E 7
D 3
		if (mflg) sdmail(file, stbuf.st_uid);
E 3
I 3
		if (mflg)
D 7
			sdmail(file, stbuf.st_uid);
E 7
I 7
			sdmail(dentp->d_name, stbuf.st_uid);
E 7
E 3
	}

	closedir(dirp);
	exit(0);
}


#define MAXPRE 10
char Pre[MAXPRE][NAMESIZE];
int Npre = 0;
/***
 *	chkpre(file)	check for prefix
 *	char *file;
 *
 *	return codes:
 *		0  -  not prefix
 *		1  -  is prefix
 */

chkpre(file)
char *file;
{
	int i;

	for (i = 0; i < Npre; i++) {
		if (prefix(Pre[i], file))
			return(1);
		}
	return(0);
}

/***
 *	stpre(p)	store prefix
 *	char *p;
 *
 *	return codes:  none
 */

stpre(p)
char *p;
{
	if (Npre < MAXPRE - 2)
		strcpy(Pre[Npre++], p);
	return;
}

/***
 *	notfyuser(file)	- notfiy requestor of deleted requres
 *
 *	return code - none
 */

notfyuser(file)
char *file;
{
	FILE *fp;
	int numrq;
	char frqst[100], lrqst[100];
	char msg[BUFSIZ];
	char *args[10];

	if ((fp = fopen(file, "r")) == NULL)
		return;
	if (fgets(frqst, 100, fp) == NULL) {
		fclose(fp);
		return;
	}
	numrq = 1;
	while (fgets(lrqst, 100, fp))
		numrq++;
	fclose(fp);
	sprintf(msg,
	  "File %s delete. \nCould not contact remote. \n%d requests deleted.\n", file, numrq);
	if (numrq == 1) {
		strcat(msg, "REQUEST: ");
		strcat(msg, frqst);
D 3
	}
	else {
E 3
I 3
	} else {
E 3
		strcat(msg, "FIRST REQUEST: ");
		strcat(msg, frqst);
		strcat(msg, "\nLAST REQUEST: ");
		strcat(msg, lrqst);
	}
D 3
	getargs(frqst, args);
	mailst(args[3], msg, "");
	return;
E 3
I 3
	getargs(frqst, args, 10);
	mailst(args[3], msg, CNULL);
E 3
}


/***
 *	sdmail(file, uid)
 *
 *	sdmail  -  this routine will determine the owner
 *	of the file (file), create a message string and
 *	call "mailst" to send the cleanup message.
 *	This is only implemented for local system
 *	mail at this time.
 */

sdmail(file, uid)
char *file;
{
	static struct passwd *pwd;
	struct passwd *getpwuid();
	char mstr[40];

	sprintf(mstr, "uuclean deleted file %s\n", file);
D 3
	if (pwd->pw_uid == uid) {
		mailst(pwd->pw_name, mstr, "");
	return(0);
E 3
I 3
	if (pwd != NULL && pwd->pw_uid == uid) {
		mailst(pwd->pw_name, mstr, CNULL);
		return;
E 3
	}

	setpwent();
D 3
	if ((pwd = getpwuid(uid)) != NULL) {
		mailst(pwd->pw_name, mstr, "");
	}
	return(0);
E 3
I 3
	if ((pwd = getpwuid(uid)) != NULL)
		mailst(pwd->pw_name, mstr, CNULL);
E 3
}

cleanup(code)
int code;
{
	exit(code);
}
E 1
