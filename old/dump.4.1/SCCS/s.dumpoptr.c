h55906
s 00010/00001/00438
d D 5.1 85/06/05 08:42:33 dist 7 6
c Add copyright
e
s 00005/00007/00434
d D 1.6 83/06/19 18:20:44 sam 6 5
c no more strncmp's needed
e
s 00077/00044/00364
d D 1.5 83/06/12 16:24:37 sam 5 4
c new fstab and utmp
e
s 00001/00001/00407
d D 1.4 80/12/18 00:52:46 wnj 4 3
c dump moans about ``Mount next tape'' unnecessarily; dump is rude
e
s 00009/00004/00399
d D 1.3 80/10/16 10:12:28 root 3 2
c Option 'w' tells only what to dump; 'W' tells most recent dump(s)
e
s 00010/00008/00393
d D 1.2 80/10/13 17:38:04 root 2 1
c added calls to fstab routines
e
s 00401/00000/00000
d D 1.1 80/10/13 17:30:28 root 1 0
c date and time created 80/10/13 17:30:28 by root
e
u
U
t
T
I 1
D 7
static	char *sccsid = "%W% (Berkeley) %G%";
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 7
#include "dump.h"

/*
 *	This is from /usr/include/grp.h
 *	That defined struct group, which conflicts
 *	with the struct group defined in param.h
 */
struct	Group { /* see getgrent(3) */
	char	*gr_name;
	char	*gr_passwd;
	int	gr_gid;
	char	**gr_mem;
};
struct	Group *getgrnam();
/*
 *	Query the operator; This fascist piece of code requires
 *	an exact response.
 *	It is intended to protect dump aborting by inquisitive
 *	people banging on the console terminal to see what is
 *	happening which might cause dump to croak, destroying
 *	a large number of hours of work.
 *
 *	Every 2 minutes we reprint the message, alerting others
 *	that dump needs attention.
 */
int	timeout;
char	*attnmessage;		/* attemtion message */
query(question)
	char	*question;
{
	char	replybuffer[64];
	int	back;
	FILE	*mytty;

	if ( (mytty = fopen("/dev/tty", "r")) == NULL){
		msg("fopen on /dev/tty fails\n");
		abort();
	}
	attnmessage = question;
	timeout = 0;
	alarmcatch();
	for(;;){
		if ( fgets(replybuffer, 63, mytty) == NULL){
			if (ferror(mytty)){
				clearerr(mytty);
				continue;
			}
		} else if ( (strcmp(replybuffer, "yes\n") == 0) ||
			    (strcmp(replybuffer, "Yes\n") == 0)){
				back = 1;
				goto done;
		} else if ( (strcmp(replybuffer, "no\n") == 0) ||
			    (strcmp(replybuffer, "No\n") == 0)){
				back = 0;
				goto done;
		} else {
			msg("\"Yes\" or \"No\" ONLY!\n");
			alarmcatch();
		}
	}
    done:
	/*
	 *	Turn off the alarm, and reset the signal to trap out..
	 */
	alarm(0);
	if (signal(SIGALRM, sigalrm) == SIG_IGN)
		signal(SIGALRM, SIG_IGN);
	fclose(mytty);
	return(back);
}
/*
 *	Alert the console operator, and enable the alarm clock to
 *	sleep for 2 minutes in case nobody comes to satisfy dump
 */
alarmcatch()
{
	if (timeout)
		msgtail("\n");
	msg("NEEDS ATTENTION: %s: (\"yes\" or \"no\") ",
		attnmessage);
	signal(SIGALRM, alarmcatch);
	alarm(120);
	timeout = 1;
}
/*
 *	Here if an inquisitive operator interrupts the dump program
 */
interrupt()
{
	msg("Interrupt received. Do >>>YOU<<< know what are you doing?\n");
	if (query("Do you really want to abort dump?"))
		dumpabort();
	signal(SIGINT, interrupt);
}

/*
 *	The following variables and routines manage alerting
 *	operators to the status of dump.
 *	This works much like wall(1) does.
 */
struct	Group *gp;

/*
 *	Get the names from the group entry "operator" to notify.
 */	
set_operators()
{
	if (!notify)		/*not going to notify*/
		return;
	gp = getgrnam(OPGRENT);
	endgrent();
	if (gp == (struct Group *)0){
		msg("No entry in /etc/group for %s.\n",
			OPGRENT);
		notify = 0;
		return;
	}
}

struct tm *localtime();
struct tm *localclock;

/*
 *	We fork a child to do the actual broadcasting, so
 *	that the process control groups are not messed up
 */
broadcast(message)
	char	*message;
{
	time_t		clock;
	FILE	*f_utmp;
	struct	utmp	utmp;
	int	nusers;
	char	**np;
	int	pid, s;

	switch (pid = fork()) {
	case -1:
		return;
	case 0:
		break;
	default:
		while (wait(&s) != pid)
			continue;
		return;
	}

	if (!notify || gp == 0)
D 4
		return;
E 4
I 4
		exit(0);
E 4
	clock = time(0);
	localclock = localtime(&clock);

	if((f_utmp = fopen("/etc/utmp", "r")) == NULL) {
		msg("Cannot open /etc/utmp\n");
		return;
	}

	nusers = 0;
	while (!feof(f_utmp)){
		if (fread(&utmp, sizeof (struct utmp), 1, f_utmp) != 1)
			break;
		if (utmp.ut_name[0] == 0)
			continue;
		nusers++;
		for (np = gp->gr_mem; *np; np++){
			if (strncmp(*np, utmp.ut_name, sizeof(utmp.ut_name)) != 0)
				continue;
			/*
			 *	Do not send messages to operators on dialups
			 */
			if (strncmp(utmp.ut_line, DIALUP, strlen(DIALUP)) == 0)
				continue;
#ifdef DEBUG
			msg("Message to %s at %s\n",
				utmp.ut_name, utmp.ut_line);
#endif DEBUG
			sendmes(utmp.ut_line, message);
		}
	}
	fclose(f_utmp);
	Exit(0);	/* the wait in this same routine will catch this */
	/* NOTREACHED */
}

sendmes(tty, message)
char *tty, *message;
{
	char t[50], buf[BUFSIZ];
	register char *cp;
	register int c, ch;
	int	msize;
	FILE *f_tty;

	msize = strlen(message);
	strcpy(t, "/dev/");
	strcat(t, tty);

	if((f_tty = fopen(t, "w")) != NULL) {
		setbuf(f_tty, buf);
		fprintf(f_tty, "\nMessage from the dump program to all operators at %d:%02d ...\r\n\n"
		       ,localclock->tm_hour
		       ,localclock->tm_min);
		for (cp = message, c = msize; c-- > 0; cp++) {
			ch = *cp;
			if (ch == '\n')
				putc('\r', f_tty);
			putc(ch, f_tty);
		}
		fclose(f_tty);
	}
}

/*
 *	print out an estimate of the amount of time left to do the dump
 */

time_t	tschedule = 0;

timeest()
{
	time_t	tnow, deltat;

	time (&tnow);
	if (tnow >= tschedule){
		tschedule = tnow + 300;
		if (blockswritten < 500)
			return;	
		deltat = tstart_writing - tnow +
			(((1.0*(tnow - tstart_writing))/blockswritten) * esize);
		msg("%3.2f%% done, finished in %d:%02d\n",
			(blockswritten*100.0)/esize,
			deltat/3600, (deltat%3600)/60);
	}
}

int blocksontape()
{
	/*
	 *	esize: total number of blocks estimated over all reels
	 *	blockswritten:	blocks actually written, over all reels
	 *	etapes:	estimated number of tapes to write
	 *
	 *	tsize:	blocks can write on this reel
	 *	asize:	blocks written on this reel
	 *	tapeno:	number of tapes written so far
	 */
	if (tapeno == etapes)
		return(esize - (etapes - 1)*tsize);
	return(tsize);
}

	/* VARARGS1 */
	/* ARGSUSED */
msg(fmt, a1, a2, a3, a4, a5)
	char	*fmt;
{
	fprintf(stderr,"  DUMP: ");
#ifdef TDEBUG
	fprintf(stderr,"pid=%d ", getpid());
#endif
	fprintf(stderr, fmt, a1, a2, a3, a4, a5);
	fflush(stdout);
	fflush(stderr);
}

	/* VARARGS1 */
	/* ARGSUSED */
msgtail(fmt, a1, a2, a3, a4, a5)
	char	*fmt;
{
	fprintf(stderr, fmt, a1, a2, a3, a4, a5);
}
/*
 *	Tell the operator what has to be done;
 *	we don't actually do it
 */

I 5
struct fstab *
allocfsent(fs)
	register struct fstab *fs;
{
	register struct fstab *new;
	register char *cp;
	char *malloc();

	new = (struct fstab *)malloc(sizeof (*fs));
	cp = malloc(strlen(fs->fs_file) + 1);
	strcpy(cp, fs->fs_file);
	new->fs_file = cp;
	cp = malloc(strlen(fs->fs_type) + 1);
	strcpy(cp, fs->fs_type);
	new->fs_type = cp;
	cp = malloc(strlen(fs->fs_spec) + 1);
	strcpy(cp, fs->fs_spec);
	new->fs_spec = cp;
	new->fs_passno = fs->fs_passno;
	new->fs_freq = fs->fs_freq;
	return (new);
}

struct	pfstab {
	struct	pfstab *pf_next;
	struct	fstab *pf_fstab;
};

static	struct pfstab *table = NULL;

E 5
getfstab()
{
D 5
	register	struct	fstab	*dt;
D 2
			FILE	*fstabfile;
E 2
I 2
			struct	fstab	*fsp;
E 5
I 5
	register struct fstab *fs;
	register struct pfstab *pf;
E 5
E 2

D 5
	nfstab = 0;
E 5
D 2
	if ( (fstabfile = fopen(FSTAB, "r")) == NULL){
E 2
I 2
	if (setfsent() == 0) {
E 2
		msg("Can't open %s for dump table information.\n", FSTAB);
D 5
	} else {
		for (nfstab = 0, dt = fstab; nfstab < MAXFSTAB;){
D 2
			if (feof(fstabfile))
E 2
I 2
			if ( (fsp = getfsent()) == 0)
E 2
				break;
D 2
			fscanf(fstabfile, FSTABFMT, FSTABARG(dt));
			if (!strcmp(dt->fs_type, "rw") ||
			    !strcmp(dt->fs_type, "ro"))
				nfstab++, dt++;
E 2
I 2
			if (   (strcmp(fsp->fs_type, FSTAB_RW) == 0)
			    || (strcmp(fsp->fs_type, FSTAB_RO) == 0) ){
				*dt = *fsp;
				nfstab++; 
				dt++;
			}
E 2
		}
D 2
		fclose(fstabfile);
E 2
I 2
		endfsent();
E 5
I 5
		return;
E 5
E 2
	}
I 5
	while (fs = getfsent()) {
		if (strcmp(fs->fs_type, FSTAB_RW) &&
		    strcmp(fs->fs_type, FSTAB_RO) &&
		    strcmp(fs->fs_type, FSTAB_RQ))
			continue;
		fs = allocfsent(fs);
		pf = (struct pfstab *)malloc(sizeof (*pf));
		pf->pf_fstab = fs;
		pf->pf_next = table;
		table = pf;
	}
	endfsent();
E 5
}

/*
D 5
 *	Search in the fstab for a file name.
 *	This file name can be either the special or the path file name.
E 5
I 5
 * Search in the fstab for a file name.
 * This file name can be either the special or the path file name.
E 5
 *
D 5
 *	The entries in the fstab are the BLOCK special names, not the
 *	character special names.
 *	The caller of fstabsearch assures that the character device
 *	is dumped (that is much faster)
E 5
I 5
 * The entries in the fstab are the BLOCK special names, not the
 * character special names.
 * The caller of fstabsearch assures that the character device
 * is dumped (that is much faster)
E 5
 *
D 5
 *	The file name can omit the leading '/'.
E 5
I 5
 * The file name can omit the leading '/'.
E 5
 */
D 5
struct	fstab	*fstabsearch(key)
	char	*key;
E 5
I 5
struct fstab *
fstabsearch(key)
	char *key;
E 5
{
D 5
	register	struct	fstab *dt;
			int	i;
			int	keylength;
			char	*rawname();
E 5
I 5
	register struct pfstab *pf;
	register struct fstab *fs;
D 6
	register int i, keylength;
E 6
	char *rawname();
E 5

D 5
	keylength = min(strlen(key), sizeof (dt->fs_file));
	for (i = 0, dt = fstab; i < nfstab; i++, dt++){
		if (strncmp(dt->fs_file, key, keylength) == 0)
			return(dt);
		if (strncmp(dt->fs_spec, key, keylength) == 0)
			return(dt);
		if (strncmp(rawname(dt->fs_spec), key, keylength) == 0)
			return(dt);

E 5
I 5
	if (table == NULL)
		return ((struct fstab *)0);
D 6
	keylength = min(strlen(key), sizeof (table->pf_fstab->fs_file));
E 6
	for (pf = table; pf; pf = pf->pf_next) {
		fs = pf->pf_fstab;
D 6
		if (strncmp(fs->fs_file, key, keylength) == 0)
E 6
I 6
		if (strcmp(fs->fs_file, key) == 0)
E 6
			return (fs);
D 6
		if (strncmp(fs->fs_spec, key, keylength) == 0)
E 6
I 6
		if (strcmp(fs->fs_spec, key) == 0)
E 6
			return (fs);
D 6
		if (strncmp(rawname(fs->fs_spec), key, keylength) == 0)
E 6
I 6
		if (strcmp(rawname(fs->fs_spec), key) == 0)
E 6
			return (fs);
E 5
		if (key[0] != '/'){
D 5
			if (   (dt->fs_spec[0] == '/')
			    && (strncmp(dt->fs_spec+1, key, keylength) == 0))
				return(dt);
			if (   (dt->fs_file[0] == '/')
			    && (strncmp(dt->fs_file+1, key, keylength) == 0))
				return(dt);
E 5
I 5
			if (*fs->fs_spec == '/' &&
D 6
			    strncmp(fs->fs_spec + 1, key, keylength) == 0)
E 6
I 6
			    strcmp(fs->fs_spec + 1, key) == 0)
E 6
				return (fs);
			if (*fs->fs_file == '/' &&
D 6
			    strncmp(fs->fs_file + 1, key, keylength) == 0)
E 6
I 6
			    strcmp(fs->fs_file + 1, key) == 0)
E 6
				return (fs);
E 5
		}
	}
D 5
	return(0);
E 5
I 5
	return (0);
E 5
}

/*
 *	Tell the operator what to do
 */
D 3
lastdump()
E 3
I 3
lastdump(arg)
	char	arg;		/* w ==> just what to do; W ==> most recent dumps */
E 3
{
			char	*lastname;
			char	*date;
	register	int	i;
			time_t	tnow;
	register	struct	fstab	*dt;
			int	dumpme;
	register	struct	idates	*itwalk;

	int	idatesort();

	time(&tnow);
	getfstab();		/* /etc/fstab input */
	inititimes();		/* /etc/dumpdates input */
	qsort(idatev, nidates, sizeof(struct idates *), idatesort);

D 3
	fprintf(stdout, "Last dump(s) done (Dump '*' file systems):\n");
E 3
I 3
	if (arg == 'w')
		fprintf(stdout, "Dump these file systems:\n");
	else
		fprintf(stdout, "Last dump(s) done (Dump '>' file systems):\n");
E 3
	lastname = "??";
	ITITERATE(i, itwalk){
		if (strncmp(lastname, itwalk->id_name, sizeof(itwalk->id_name)) == 0)
			continue;
		date = (char *)ctime(&itwalk->id_ddate);
		date[16] = '\0';		/* blast away seconds and year */
		lastname = itwalk->id_name;
		dt = fstabsearch(itwalk->id_name);
		dumpme = (  (dt != 0)
			 && (dt->fs_freq != 0)
			 && (itwalk->id_ddate < tnow - (dt->fs_freq*DAY)));
D 3
		fprintf(stdout,"%c %8s\t(%6s) Last dump: Level %c, Date %s\n",
			dumpme ? '*' : ' ',
E 3
I 3
		if ( (arg != 'w') || dumpme)
		  fprintf(stdout,"%c %8s\t(%6s) Last dump: Level %c, Date %s\n",
			dumpme && (arg != 'w') ? '>' : ' ',
E 3
			itwalk->id_name,
			dt ? dt->fs_file : 0,
			itwalk->id_incno,
			date
		    );
	}
}

int	idatesort(p1, p2)
	struct	idates	**p1, **p2;
{
	int	diff;

	diff = strncmp((*p1)->id_name, (*p2)->id_name, sizeof((*p1)->id_name));
	if (diff == 0)
		return ((*p2)->id_ddate - (*p1)->id_ddate);
	else
		return (diff);
}

int max(a,b)
{
	return(a>b?a:b);
}
int min(a,b)
{
	return(a<b?a:b);
}
E 1
