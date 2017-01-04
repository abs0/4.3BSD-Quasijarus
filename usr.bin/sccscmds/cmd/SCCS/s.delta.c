h18392
s 00023/00010/00699
d D 4.12 99/08/28 14:57:33 msokolov 13 12
c fix the LOGDELTA mechanism (remove control characters from the log file
c and use O_APPEND atomic appended writes)
e
s 00001/00001/00708
d D 4.11 99/01/03 20:42:22 msokolov 12 11
c SCCS is not "local" any more. /usr/local => /usr/bin
e
s 00038/00024/00671
d D 4.10 88/02/02 15:55:57 bostic 11 10
c sprintf doesn't return a pointer to it's first arg, anymore
e
s 00004/00004/00691
d D 4.9 87/12/05 15:47:43 bostic 10 9
c old assignment operator
e
s 00007/00007/00688
d D 4.8 87/02/15 21:04:44 lepreau 9 8
c modern syntax for asgops & inits cause Donn's latest ccom rejects the old.
e
s 00011/00011/00684
d D 4.7 85/05/04 00:34:31 sam 8 7
c purge some of the old grotty local routines; for get add %Q% for man pages
e
s 00010/00008/00685
d D 4.6 84/01/06 14:18:13 ralph 7 6
c don't log changes if log file can't be opened (instead of error).
e
s 00025/00003/00668
d D 4.5 83/12/22 14:08:46 ralph 6 5
c added logging of deltas for keeping track of changes.
e
s 00003/00002/00668
d D 4.4 82/05/07 11:58:42 sam 5 4
c allow root to perform delta's for others
e
s 00001/00001/00669
d D 4.3 82/03/13 16:38:54 eric 4 3
c turn magic numbers into the (already existant but unused) defined constants
e
s 00002/00002/00668
d D 4.2 81/01/15 13:38:10 eric 3 2
c skipline <==> skiplines in some places
e
s 00001/00001/00669
d D 4.1 81/01/15 00:20:53 eric 2 1
c release 4
e
s 00670/00000/00000
d D 1.1 80/05/13 17:56:00 root 1 0
c date and time created 80/05/13 17:56:00 by root
e
u
U
t
T
I 1
# include	"../hdr/defines.h"
# include	"../hdr/had.h"
I 13
# include	<sys/file.h>
E 13

D 2
SCCSID(@(#)delta	2.1);
E 2
I 2
D 9
SCCSID(%W%);
E 9
I 9
static char Sccsid[] = "%W%	%G%";
E 9
E 2
USXALLOC();

D 6
char	Diffpgm[]	"/usr/local/bdiff";
E 6
I 6
# ifdef LOGDELTA
char	LogFile[] = "/usr/adm/sccs-log";
D 13
FILE	*Logf;
E 13
I 13
int	Logfd;
E 13
# endif

D 12
char	Diffpgm[] = "/usr/local/bdiff";
E 12
I 12
char	Diffpgm[] = "/usr/bin/bdiff";
E 12
E 6
FILE	*Diffin;
D 9
int	Debug	0;
E 9
I 9
int	Debug = 0;
E 9
struct packet gpkt;
struct sid sid;
int	num_files;
char	had[26];
char	*ilist, *elist, *glist;
char	*Comments, *Mrs;
int	Domrs;
D 6
int verbosity;
E 6
I 6
int	verbosity;
E 6
int	Did_id;
long	Szqfile;
char	Pfilename[FILESIZE];
FILE	*Xiop;
int	Xcreate;

main(argc,argv)
int argc;
register char *argv[];
{
	register int i;
	register char *p;
	char c;
	int testmore;
	extern delta();
	extern int Fcnt;

	Fflags = FTLEXIT | FTLMSG | FTLCLN;
	for(i=1; i<argc; i++)
		if(argv[i][0] == '-' && (c=argv[i][1])) {
			p = &argv[i][2];
			testmore = 0;
			switch (c) {

			case 'r':
				if (!p[0]) {
					argv[i] = 0;
					continue;
				}
				chksid(sid_ab(p,&sid),&sid);
				break;
			case 'g':
				glist = p;
				break;
			case 'y':
				Comments = p;
				break;
			case 'm':
				Mrs = p;
				break;
			case 'p':
			case 'n':
			case 's':
				testmore++;
				break;
			default:
				fatal("unknown key letter (cm1)");
			}

			if (testmore) {
				testmore = 0;
D 11
				if (*p)
					fatal(sprintf(Error,
					  "value after %c arg (cm7)",c));
E 11
I 11
				if (*p) {
					sprintf(Error, "value after %c arg (cm7)",c);
					fatal(Error);
				}
E 11
			}
			if (had[c - 'a']++)
				fatal("key letter twice (cm2)");
			argv[i] = 0;
		}
		else num_files++;

D 6
	if(num_files == 0)
E 6
I 6
	if (num_files == 0)
E 6
		fatal("missing file arg (cm3)");
	if (!HADS)
		verbosity = -1;
I 6
# ifdef LOGDELTA
D 7
	if ((Logf = fopen(LogFile, "a")) == NULL)
		fatal("cannot open logfile");
E 7
I 7
D 13
	Logf = fopen(LogFile, "a");
E 13
I 13
	Logfd = open(LogFile, O_WRONLY | O_CREAT | O_APPEND, 0666);
E 13
E 7
# endif
E 6
	setsig();
D 9
	Fflags =& ~FTLEXIT;
	Fflags =| FTLJMP;
E 9
I 9
	Fflags &= ~FTLEXIT;
	Fflags |= FTLJMP;
E 9
	for (i=1; i<argc; i++)
		if (p=argv[i])
			do_file(p,delta);
I 6
# ifdef LOGDELTA
D 7
	fclose(Logf);
E 7
I 7
D 13
	if (Logf != NULL)
		fclose(Logf);
E 13
I 13
	if (Logfd >= 0)
		close(Logfd);
E 13
E 7
# endif
E 6
	exit(Fcnt ? 1 : 0);
}


delta(file)
I 6
char *file;
E 6
{
D 9
	static int first 1;
E 9
I 9
	static int first = 1;
E 9
	register char *p;
	int n, linenum;
	char type;
	register int ser;
	extern char had_dir, had_standinp;
	extern char *Sflags[];
	char dfilename[FILESIZE];
	char gfilename[FILESIZE];
	char line[512];
	FILE *gin;
	struct stats stats;
	struct pfile *pp;
	int inserted, deleted, orig;
	int newser;
	int status;
	int diffloop;
	int difflim;

	if (setjmp(Fjmp))
		return;
	if (first) {
		first = 0;
		dohist(file);
	}
	sinit(&gpkt,file,1);
	if (lockit(auxf(gpkt.p_file,'z'),2,getpid()))
		fatal("cannot create lock file (cm4)");
	gpkt.p_reopen = 1;
	gpkt.p_stdout = stdout;
	copy(auxf(gpkt.p_file,'g'),gfilename);
	gin = xfopen(gfilename,0);
	pp = rdpfile(&gpkt,&sid);
	gpkt.p_cutoff = pp->pf_date;
	ilist = pp->pf_ilist;
	elist = pp->pf_elist;

	if (dodelt(&gpkt,&stats,0,0) == 0)
		fmterr(&gpkt);
	if ((ser = sidtoser(&pp->pf_gsid,&gpkt)) == 0 ||
		sidtoser(&pp->pf_nsid,&gpkt))
			fatal("invalid sid in p-file (de3)");
	doie(&gpkt,ilist,elist,glist);
	setup(&gpkt,ser);
	finduser(&gpkt);
	doflags(&gpkt);
D 8
	move(&pp->pf_nsid,&gpkt.p_reqsid,sizeof(gpkt.p_reqsid));
E 8
I 8
	bcopy(&pp->pf_nsid,&gpkt.p_reqsid,sizeof(gpkt.p_reqsid));
E 8
	permiss(&gpkt);
	flushto(&gpkt,EUSERTXT,1);
	gpkt.p_chkeof = 1;
	copy(auxf(gpkt.p_file,'d'),dfilename);
	gpkt.p_gout = xfcreat(dfilename,0444);
	while(readmod(&gpkt)) {
		chkid(gpkt.p_line);
		fputs(gpkt.p_line,gpkt.p_gout);
	}
	fclose(gpkt.p_gout);
	orig = gpkt.p_glnno;
	gpkt.p_glnno = 0;
	gpkt.p_verbose = verbosity;
	Did_id = 0;
	while (fgets(line,sizeof(line),gin) != NULL && !chkid(line))
		;
	fclose(gin);
	if (gpkt.p_verbose && (num_files > 1 || had_dir || had_standinp))
		fprintf(gpkt.p_stdout,"\n%s:\n",gpkt.p_file);
	if (!Did_id)
		if (Sflags[IDFLAG - 'a'])
			fatal("no id keywords (cm6)");
		else if (gpkt.p_verbose)
			fprintf(stderr,"No id keywords (cm7)\n");

	/*
	The following while loop executes 'bdiff' on g-file and
	d-file. If 'bdiff' fails (usually because segmentation
	limit it is using is too large for 'diff'), it is
	invoked again, with a lower segmentation limit.
	*/
	difflim = 3500;
	diffloop = 0;
	while (1) {
		inserted = deleted = 0;
		gpkt.p_glnno = 0;
		gpkt.p_upd = 1;
		gpkt.p_wrttn = 1;
		getline(&gpkt);
		gpkt.p_wrttn = 1;
		newser = mkdelt(&gpkt,&pp->pf_nsid,&pp->pf_gsid,
						diffloop,orig);
		diffloop = 1;
		flushto(&gpkt,EUSERTXT,0);
		Diffin = dodiff(auxf(gpkt.p_file,'g'),dfilename,difflim);
		while (n = getdiff(&type,&linenum)) {
			if (type == INS) {
D 9
				inserted =+ n;
E 9
I 9
				inserted += n;
E 9
				insert(&gpkt,linenum,n,newser);
			}
			else {
D 9
				deleted =+ n;
E 9
I 9
				deleted += n;
E 9
				delete(&gpkt,linenum,n,newser);
			}
		}
		fclose(Diffin);
		if (gpkt.p_iop)
			while (readmod(&gpkt))
				;
		wait(&status);
		if (status) {		/* diff failed */
			/*
			Check top byte (exit code of child).
			*/
D 11
			if (((status >> 8) & 0377) == 32) /* 'execl' failed */
				fatal(sprintf(Error,
						"cannot execute '%s' (de12)",
						Diffpgm));
E 11
I 11
			if (((status >> 8) & 0377) == 32) { /* 'execl' failed */
				sprintf(Error, "cannot execute '%s' (de12)", Diffpgm);
				fatal(Error);
			}
E 11
			/*
			Re-try.
			*/
D 10
			if (difflim =- 500) {	/* reduce segmentation */
E 10
I 10
			if (difflim -= 500) {	/* reduce segmentation */
E 10
				fprintf(stderr,
			"'%s' failed, re-trying, segmentation = %d (de13)\n",
					Diffpgm,difflim);
				fclose(Xiop);	/* set up */
				Xiop = 0;	/* for new x-file */
				Xcreate = 0;
				/*
				Re-open s-file.
				*/
				gpkt.p_iop = xfopen(gpkt.p_file,0);
				setbuf(gpkt.p_iop,gpkt.p_buf);
				/*
				Reset counters.
				*/
				gpkt.p_slnno = 0;
				gpkt.p_ihash = 0;
				gpkt.p_chash = 0;
				gpkt.p_nhash = 0;
				gpkt.p_keep = 0;
			}
			else
				/* tried up to 500 lines, can't go on */
				fatal("diff failed (de4)");
		}
		else {		/* no need to try again, worked */
			break;			/* exit while loop */
		}
	}
	unlink(dfilename);
	stats.s_ins = inserted;
	stats.s_del = deleted;
	stats.s_unc = orig - deleted;
	if (gpkt.p_verbose) {
		fprintf(gpkt.p_stdout,"%u inserted\n",stats.s_ins);
		fprintf(gpkt.p_stdout,"%u deleted\n",stats.s_del);
		fprintf(gpkt.p_stdout,"%u unchanged\n",stats.s_unc);
	}
	flushline(&gpkt,&stats);
	rename(auxf(gpkt.p_file,'x'),gpkt.p_file);
	if (Szqfile)
		rename(auxf(&gpkt.p_file,'q'),Pfilename);
	else {
		xunlink(Pfilename);
		xunlink(auxf(&gpkt.p_file,'q'));
	}
	clean_up(0);
	if (!HADN) {
		setuid(getuid());
		unlink(gfilename);
	}
}


mkdelt(pkt,sp,osp,diffloop,orig_nlines)
struct packet *pkt;
struct sid *sp, *osp;
int diffloop;
int orig_nlines;
{
	extern long Timenow;
	struct deltab dt;
	char str[128];
	int newser;
	extern char *Sflags[];
	register char *p;
	int ser_inc, opred, nulldel;

	if (!diffloop && pkt->p_verbose) {
		sid_ba(sp,str);
		fprintf(pkt->p_stdout,"%s\n",str);
	}
D 11
	putline(pkt,sprintf(str,"%c%c00000\n",CTLCHAR,HEAD));
E 11
I 11
	sprintf(str,"%c%c00000\n",CTLCHAR,HEAD);
	putline(pkt,str);
E 11
	newstats(pkt,str,"0");
D 8
	move(sp,&dt.d_sid,sizeof(dt.d_sid));
E 8
I 8
	bcopy(sp,&dt.d_sid,sizeof(dt.d_sid));
E 8

	/*
	Check if 'null' deltas should be inserted
	(only if 'null' flag is in file and
	releases are being skipped) and set
	'nulldel' indicator appropriately.
	*/
	if (Sflags[NULLFLAG - 'a'] && (sp->s_rel > osp->s_rel + 1) &&
			!sp->s_br && !sp->s_seq &&
			!osp->s_br && !osp->s_seq)
		nulldel = 1;
	else
		nulldel = 0;
	/*
	Calculate how many serial numbers are needed.
	*/
	if (nulldel)
		ser_inc = sp->s_rel - osp->s_rel;
	else
		ser_inc = 1;
	/*
	Find serial number of the new delta.
	*/
	newser = dt.d_serial = maxser(pkt) + ser_inc;
	/*
	Find old predecessor's serial number.
	*/
	opred = sidtoser(osp,pkt);
	if (nulldel)
		dt.d_pred = newser - 1;	/* set predecessor to 'null' delta */
	else
		dt.d_pred = opred;
	dt.d_datetime = Timenow;
D 4
	substr(logname(),dt.d_pgmr,0,7);
E 4
I 4
	substr(logname(),dt.d_pgmr,0,LNLNAM);
E 4
	dt.d_type = 'D';
	del_ba(&dt,str);
	putline(pkt,str);
I 6
# ifdef LOGDELTA
D 7
	if (pkt->p_file[0] != '/') {
		char buf[1024];
E 7
I 7
D 13
	if (Logf != NULL) {
		if (pkt->p_file[0] != '/') {
			char buf[1024];
E 13
I 13
	if (Logfd >= 0) {
		char buf[4096], *bp;
		char *cp;
E 13
E 7

D 7
		if (getwd(buf) != NULL)
			fprintf(Logf, "%s/", buf);
E 7
I 7
D 13
			if (getwd(buf) != NULL)
				fprintf(Logf, "%s/", buf);
E 13
I 13
		if (pkt->p_file[0] != '/' && getwd(buf) != NULL)
			strcat(buf, "/");
		else
			buf[0] = '\0';
		strcat(buf, pkt->p_file);
		strcat(buf, ":\n");
		strcat(buf, str + 5);
		bp = buf + strlen(buf);
		for (cp = Comments; *cp;) {
			if (*cp != CTLCHAR)
				*bp++ = *cp++;
			else
				cp += 3;
E 13
		}
D 13
		fprintf(Logf, "%s:\n%s%s\n", pkt->p_file, str + 5, Comments);
E 13
I 13
		*bp++ = '\n';
		write(Logfd, buf, bp - buf);
E 13
E 7
	}
D 7
	fprintf(Logf, "%s:\n%s%s\n", pkt->p_file, str + 5, Comments);
E 7
# endif
E 6
	if (ilist)
		mkixg(pkt,INCLUSER,INCLUDE);
	if (elist)
		mkixg(pkt,EXCLUSER,EXCLUDE);
	if (glist)
		mkixg(pkt,IGNRUSER,IGNORE);
	if (Mrs) {
		if (!(p = Sflags[VALFLAG - 'a']))
			fatal("MRs not allowed (de8)");
		if (*p && !diffloop && valmrs(pkt,p))
			fatal("invalid MRs (de9)");
		putmrs(pkt);
	}
	else if (Sflags[VALFLAG - 'a'])
		fatal("MRs required (de10)");
D 11
	putline(pkt,sprintf(str,"%c%c ",CTLCHAR,COMMENTS));
E 11
I 11
	sprintf(str,"%c%c ",CTLCHAR,COMMENTS);
	putline(pkt,str);
E 11
	putline(pkt,Comments);
	putline(pkt,"\n");
D 11
	putline(pkt,sprintf(str,CTLSTR,CTLCHAR,EDELTAB));
E 11
I 11
	sprintf(str,CTLSTR,CTLCHAR,EDELTAB);
	putline(pkt,str);
E 11
	if (nulldel)			/* insert 'null' deltas */
		while (--ser_inc) {
D 11
			putline(pkt,sprintf(str,"%c%c %s/%s/%05u\n",
				CTLCHAR, STATS,
				"00000", "00000", orig_nlines));
E 11
I 11
			sprintf(str,"%c%c %s/%s/%05u\n", CTLCHAR, STATS, "00000", "00000", orig_nlines);
			putline(pkt,str);
E 11
D 10
			dt.d_sid.s_rel =- 1;
			dt.d_serial =- 1;
E 10
I 10
			dt.d_sid.s_rel -= 1;
			dt.d_serial -= 1;
E 10
			if (ser_inc != 1)
D 10
				dt.d_pred =- 1;
E 10
I 10
				dt.d_pred -= 1;
E 10
			else
				dt.d_pred = opred;	/* point to old pred */
			del_ba(&dt,str);
			putline(pkt,str);
D 11
			putline(pkt,sprintf(str,"%c%c ",CTLCHAR,COMMENTS));
E 11
I 11
			sprintf(str,"%c%c ",CTLCHAR,COMMENTS);
			putline(pkt,str);
E 11
			putline(pkt,"AUTO NULL DELTA\n");
D 11
			putline(pkt,sprintf(str,CTLSTR,CTLCHAR,EDELTAB));
E 11
I 11
			sprintf(str,CTLSTR,CTLCHAR,EDELTAB);
			putline(pkt,str);
E 11
		}
	return(newser);
}


mkixg(pkt,reason,ch)
struct packet *pkt;
int reason;
char ch;
{
	int n;
	char str[512];

D 11
	putline(pkt,sprintf(str,"%c%c",CTLCHAR,ch));
E 11
I 11
	sprintf(str,"%c%c",CTLCHAR,ch);
	putline(pkt,str);
E 11
	for (n = maxser(pkt); n; n--) {
D 11
		if (pkt->p_apply[n].a_reason == reason)
			putline(pkt,sprintf(str," %u",n));
E 11
I 11
		if (pkt->p_apply[n].a_reason == reason) {
			sprintf(str," %u",n);
			putline(pkt,str);
		}
E 11
	}
	putline(pkt,"\n");
}


putmrs(pkt)
struct packet *pkt;
{
	register char **argv;
	char str[64];
	extern char *Varg[];

D 11
	for (argv = &Varg[VSTART]; *argv; argv++)
		putline(pkt,sprintf(str,"%c%c %s\n",CTLCHAR,MRNUM,*argv));
E 11
I 11
	for (argv = &Varg[VSTART]; *argv; argv++) {
		sprintf(str,"%c%c %s\n",CTLCHAR,MRNUM,*argv);
		putline(pkt,str);
	}
E 11
}


rdpfile(pkt,sp)
register struct packet *pkt;
struct sid *sp;
{
	char *user;
	struct pfile pf;
	static struct pfile goodpf;
	char line[512];
D 5
	int cnt;
E 5
I 5
	int cnt, root;
E 5
	FILE *in, *out;

	cnt = -1;
	user = logname();
D 8
	zero(&goodpf,sizeof(goodpf));
E 8
I 8
	bzero(&goodpf,sizeof(goodpf));
E 8
	in = xfopen(auxf(pkt->p_file,'p'),0);
	out = xfcreat(auxf(pkt->p_file,'q'),0644);
I 5
	root = getuid() == 0;
E 5
	while (fgets(line,sizeof(line),in) != NULL) {
		pf_ab(line,&pf,1);
D 5
		if (equal(pf.pf_user,user)) {
E 5
I 5
		if (root || equal(pf.pf_user,user)) {
E 5
			if (sp->s_rel == 0) {
				if (++cnt) {
					fclose(out);
					fclose(in);
					fatal("missing -r argument (de1)");
				}
D 8
				move(&pf,&goodpf,sizeof(pf));
E 8
I 8
				bcopy(&pf,&goodpf,sizeof(pf));
E 8
				continue;
			}
			else if (sp->s_rel == pf.pf_gsid.s_rel &&
				sp->s_lev == pf.pf_gsid.s_lev &&
				sp->s_br == pf.pf_gsid.s_br &&
				sp->s_seq == pf.pf_gsid.s_seq) {
D 8
					move(&pf,&goodpf,sizeof(pf));
E 8
I 8
					bcopy(&pf,&goodpf,sizeof(pf));
E 8
					continue;
			}
		}
		fputs(line,out);
	}
	fflush(out);
	fstat(fileno(out),&Statbuf);
	Szqfile = Statbuf.st_size;
	copy(auxf(pkt->p_file,'p'),Pfilename);
	fclose(out);
	fclose(in);
	if (!goodpf.pf_user[0])
		fatal("not in p-file (de2)");
	return(&goodpf);
}


dodiff(newf,oldf,difflim)
char *newf, *oldf;
int difflim;
{
	register int i;
	int pfd[2];
	FILE *iop;
	extern char Diffpgm[];
	char num[10];

	xpipe(pfd);
	if ((i = fork()) < 0) {
		close(pfd[0]);
		close(pfd[1]);
		fatal("cannot fork, try again (de11)");
	}
	else if (i == 0) {
		close(pfd[0]);
D 8
		close(1);
		dup(pfd[1]);
		close(pfd[1]);
		for (i = 5; i < 15; i++)
E 8
I 8
		dup2(pfd[1], 1);
		if (pfd[1] != 1)
			close(pfd[1]);
		for (i = getdtablesize(); i > 4; i--)
E 8
			close(i);
		sprintf(num,"%d",difflim);
		execl(Diffpgm,Diffpgm,oldf,newf,num,"-s",0);
		close(1);
		exit(32);	/* tell parent that 'execl' failed */
	}
	else {
		close(pfd[1]);
D 8
		iop = fdfopen(pfd[0],0);
E 8
I 8
		iop = fdopen(pfd[0],"r");
E 8
		return(iop);
	}
}


getdiff(type,plinenum)
register char *type;
register int *plinenum;
{
	char line[512];
	register char *p;
	int num_lines;
	static int chg_num, chg_ln;
	int lowline, highline;

D 8
	if ((p = rddiff(line,512)) == NULL)
E 8
I 8
	if ((p = rddiff(line,sizeof (line))) == NULL)
E 8
		return(0);

	if (*p == '-') {
		*type = INS;
		*plinenum = chg_ln;
		num_lines = chg_num;
	}
	else {
		p = linerange(p,&lowline,&highline);
		*plinenum = lowline;

		switch(*p++) {
		case 'd':
			num_lines = highline - lowline + 1;
			*type = DEL;
D 3
			skipline(line,num_lines);
E 3
I 3
			skiplines(line,num_lines);
E 3
			break;

		case 'a':
			linerange(p,&lowline,&highline);
			num_lines = highline - lowline + 1;
			*type = INS;
			break;

		case 'c':
			chg_ln = lowline;
			num_lines = highline - lowline + 1;
			linerange(p,&lowline,&highline);
			chg_num = highline - lowline + 1;
			*type = DEL;
D 3
			skipline(line,num_lines);
E 3
I 3
			skiplines(line,num_lines);
E 3
			break;
		}
	}

	return(num_lines);
}


insert(pkt,linenum,n,ser)
register struct packet *pkt;
register int linenum;
register int n;
int ser;
{
	char str[512];

	after(pkt,linenum);
D 11
	putline(pkt,sprintf(str,"%c%c %u\n",CTLCHAR,INS,ser));
E 11
I 11
	sprintf(str,"%c%c %u\n",CTLCHAR,INS,ser);
	putline(pkt,str);
E 11
	for (++n; --n; ) {
		rddiff(str,sizeof(str));
		putline(pkt,&str[2]);
	}
D 11
	putline(pkt,sprintf(str,"%c%c %u\n",CTLCHAR,END,ser));
E 11
I 11
	sprintf(str,"%c%c %u\n",CTLCHAR,END,ser);
	putline(pkt,str);
E 11
}


delete(pkt,linenum,n,ser)
register struct packet *pkt;
register int linenum;
int n;
register int ser;
{
	char str[512];

	before(pkt,linenum);
D 11
	putline(pkt,sprintf(str,"%c%c %u\n",CTLCHAR,DEL,ser));
E 11
I 11
	sprintf(str,"%c%c %u\n",CTLCHAR,DEL,ser);
	putline(pkt,str);
E 11
	after(pkt,linenum + n - 1);
D 11
	putline(pkt,sprintf(str,"%c%c %u\n",CTLCHAR,END,ser));
E 11
I 11
	sprintf(str,"%c%c %u\n",CTLCHAR,END,ser);
	putline(pkt,str);
E 11
}


after(pkt,n)
register struct packet *pkt;
register int n;
{
	before(pkt,n);
	if (pkt->p_glnno == n)
		putline(pkt,0);
}


before(pkt,n)
register struct packet *pkt;
register int n;
{
	while (pkt->p_glnno < n) {
		if (!readmod(pkt))
			break;
	}
}


linerange(cp,low,high)
register char *cp;
register int *low, *high;
{
	cp = satoi(cp,low);
	if (*cp == ',')
		cp = satoi(++cp,high);
	else
		*high = *low;

	return(cp);
}


skiplines(lp,num)
register char *lp;
register int num;
{
	for (++num;--num;)
		rddiff(lp,512);
}


rddiff(s,n)
register char *s;
register int n;
{
	register int r;

	if ((r = fgets(s,n,Diffin)) != NULL && HADP)
		fputs(s,gpkt.p_stdout);
	return(r);
}


enter(pkt,ch,n,sidp)
struct packet *pkt;
char ch;
int n;
struct sid *sidp;
{
	char str[32];
	register struct apply *ap;

	sid_ba(sidp,str);
	ap = &pkt->p_apply[n];
	if (pkt->p_cutoff > pkt->p_idel[n].i_datetime)
		switch(ap->a_code) {
	
		case EMPTY:
			switch (ch) {
			case INCLUDE:
				condset(ap,APPLY,INCLUSER);
				break;
			case EXCLUDE:
				condset(ap,NOAPPLY,EXCLUSER);
				break;
			case IGNORE:
				condset(ap,EMPTY,IGNRUSER);
				break;
			}
			break;
		case APPLY:
			fatal("internal error in delta/enter() (de5)");
			break;
		case NOAPPLY:
			fatal("internal error in delta/enter() (de6)");
			break;
		default:
			fatal("internal error in delta/enter() (de7)");
			break;
		}
}


escdodelt()	/* dummy routine for dodelt() */
{
}


clean_up(n)
{
	if (gpkt.p_file[0])
		unlockit(auxf(gpkt.p_file,'z'),getpid());
	xrm(&gpkt);
	xfreeall();
}
E 1
