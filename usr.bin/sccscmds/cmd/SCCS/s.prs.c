h65108
s 00533/00156/00641
d D 4.5 01/05/27 20:16:26 msokolov 7 6
c replace the nonfunctional preliminary version of prs with a real one,
c taken from Ultrix-32 V4.20
e
s 00001/00001/00796
d D 4.4 99/01/07 01:34:52 msokolov 6 5
c SCCS is not "local" any more. /usr/local => /usr/bin
e
s 00002/00001/00795
d D 4.3 88/02/02 15:56:04 bostic 5 4
c sprintf doesn't return a pointer to it's first arg, anymore
e
s 00009/00010/00787
d D 4.2 87/02/15 21:04:54 lepreau 4 3
c modern syntax for asgops & inits cause Donn's latest ccom rejects the old.
e
s 00000/00000/00797
d D 4.1 81/01/15 00:21:03 eric 3 2
c release 4
e
s 00013/00011/00784
d D 1.2 81/01/14 15:30:52 eric 2 1
c fixes for VAX
e
s 00795/00000/00000
d D 1.1 81/01/14 14:42:08 eric 1 0
c date and time created 81/01/14 14:42:08 by eric
e
u
U
t
T
I 7

#ifndef lint
static	char	*sccsid = "%W%	(Berkeley)	%G%";
#endif lint

E 7
I 1
/*************************************************************************/
/*									 */
D 7
/*	prs [-d<dataspec>] [-r<sid>] [-c<cutoff>] [-a]			 */
/*	    [-y<reverse-cutoff>] file ...				 */
E 7
I 7
/*	prs [-d<dataspec>] [-r<sid>] [-l] [-e] [-a] file ...		 */
E 7
/*									 */
/*************************************************************************/

/*
	Program to print parts or all of an SCCS file
	in user supplied format.
	Arguments to the program may appear in any order
	and consist of keyletters, which begin with '-',
	and named files.

	If a direcory is given as an argument, each
	SCCS file within the directory is processed as if
	it had been specifically named. If a name of '-'
	is given, the standard input is read for a list
	of names of SCCS files to be processed.
	Non-SCCS files are ignored.
*/

# include "../hdr/defines.h"
# include "../hdr/had.h"

D 2
SCCSID(@(#)prs.c	1.3);
E 2
I 2
D 4
SCCSID(%W%);
E 4
I 4
D 7
static char Sccsid[] = "%W%	%G%";
E 7
I 7
struct stat Statbuf;
char Null[1];
char Error[128];
E 7
E 4
E 2

I 7
char	*getwd();
E 7
char	had[26];
D 4
char	Getpgm[]	"/usr/local/get";
E 4
I 4
D 6
char	Getpgm[] = "/usr/local/get";
E 6
I 6
D 7
char	Getpgm[] = "/usr/bin/get";
E 7
I 7
char	Getpgm[]   =   "get";
static char defline[]     =     ":Dt:\t:DL:\nMRs:\n:MR:COMMENTS:\n:C:";
char	*sid_ba();
E 7
E 6
E 4
char	Sid[32];
char	Mod[16];
I 7
char	Olddir[BUFSIZ];
char	Pname[BUFSIZ];
char	Dir[BUFSIZ];
E 7
char	*Type;
char	Deltadate[18];
char	*Deltatime;
D 4
char	tempskel[]	"/tmp/prXXXXXX";	/* used to generate temp
						   file names
						*/
E 4
I 4
D 7
char	tempskel[] = "/tmp/prXXXXXX";	/* used to generate temp file names */

E 7
I 7
char	tempskel[]   =   "/tmp/prXXXXXX";	/* used to generate temp
						   file names
						*/
E 7
E 4
char	untmp[32], uttmp[32], cmtmp[32];
char	mrtmp[32], bdtmp[32];
FILE	*UNiop;
FILE	*UTiop;
FILE	*CMiop;
FILE	*MRiop;
FILE	*BDiop;
D 7
char	line[BUFSIZ];
E 7
I 7
char	line[BUFSIZ], *getline();
E 7
int	num_files;
D 7
long	cutoff;
long	revcut;
char	*dataspec;
E 7
I 7
int	HAD_CM, HAD_MR, HAD_FD, HAD_BD, HAD_UN;
char	dt_line[BUFSIZ];
char	*dataspec = &defline[0];
E 7
char	iline[BUFSIZ], xline[BUFSIZ], gline[BUFSIZ];
D 7
char	*maket();
E 7
I 7
FILE	*maket();
E 7
struct	packet	gpkt;
struct	sid	sid;
D 2
struct	time	*Dtime;
E 2
I 2
struct	tm	*Dtime;
E 2

main(argc,argv)
int argc;
char *argv[];
{
	register int j;
	register char *p;
	char c;
D 7
	extern prs();
E 7
I 7
	char *sid_ab();
	extern process();
E 7
	extern int Fcnt;

	/*
	Set flags for 'fatal' to issue message, call clean-up
	routine, and terminate processing.
	*/
	Fflags = FTLMSG | FTLCLN | FTLEXIT;

D 7

E 7
	/*
	The following loop processes keyletters and arguments.
	Note that these are processed only once for each
	invocation of 'main'.
	*/
	for (j = 1; j < argc; j++)
		if (argv[j][0] == '-' && (c = argv[j][1])) {
			p = &argv[j][2];
			switch (c) {
D 7

			case 'r':	/* delta cutoff */
E 7
I 7
			case 'r':	/* specified SID */
E 7
				if (*p) {
					if (invalid(p))
						fatal("invalid sid (co8)");
					sid_ab(p,&sid);
				}
				break;
D 7

			case 'c':	/* time cutoff */
				if (*p && date_ab(p,&cutoff))
					fatal("bad date/time (cm5)");
E 7
I 7
			case 'l':	/* later than specified SID */
			case 'e':	/* earlier than specified SID */
			case 'a':	/* print all delta types (R or D) */
				if (*p) {
					sprintf(Error,
					   "value after %c arg (cm7)",c);
					fatal(Error);
				}
E 7
				break;
D 7

			case 'y':	/* reverse time cutoff */
				if (*p && date_ab(p,&revcut))
					fatal ("bad date/time (cm5)");
				break;

			case 'a':
E 7
I 7
			case 'd':	/* dataspec line */
E 7
				if (*p)
D 7
					fatal("value after a arg (cm7)");
E 7
I 7
					dataspec = p;
E 7
				break;
D 7
			case 'd':	/* dataspec line */
				dataspec = p;
				break;
E 7
			default:
				fatal("unknown key letter (cm1)");
			}

			if (had[c - 'a']++)
				fatal("key letter twice (cm2)");
			argv[j] = 0;
		}
		else
			num_files++;

	if (num_files == 0)
		fatal("missing file arg (cm3)");

D 7
	if (!HADD)
		exit(0);
	if (HADC && HADY)
		fatal("both 'c' and 'y' keyletters specified (prs2)");
E 7
I 7
	/*
	check the dataspec line and determine if any tmp files
	need be created
	*/
	ck_spec(dataspec);
E 7

	setsig();

	/*
	Change flags for 'fatal' so that it will return to this
	routine (main) instead of terminating processing.
	*/
D 4
	Fflags =& ~FTLEXIT;
	Fflags =| FTLJMP;
E 4
I 4
	Fflags &= ~FTLEXIT;
	Fflags |= FTLJMP;
E 4

	/*
D 7
	Call 'prs' routine for each file argument.
E 7
I 7
	Call 'process' routine for each file argument.
E 7
	*/
	for (j = 1; j < argc; j++)
		if (p = argv[j])
D 7
			do_file(p,prs);
E 7
I 7
			do_file(p,process);
E 7

	exit(Fcnt ? 1 : 0);
}


D 7
prs(file)
E 7
I 7
/*
 * This procedure opens the SCCS file and calls all subsequent
 * modules to perform 'prs'.  Once the file is finished, process
 * returns to 'main' to process any other possible files.
*/
process(file)
E 7
register	char	*file;
{
D 7
	int	n;
E 7
	extern	char	had_dir, had_standinp;
I 7
	static	int pr_fname = 0;
E 7

D 7
	if (setjmp(Fjmp))
		return;
E 7
I 7
	if (setjmp(Fjmp))	/* set up to return here from 'fatal' */
		return;		/* and return to caller of 'process' */

E 7
	sinit(&gpkt,file,1);	/* init packet and open SCCS file */

D 7
	gpkt.p_reqsid.s_rel = sid.s_rel;
	gpkt.p_reqsid.s_lev = sid.s_lev;
	gpkt.p_reqsid.s_br = sid.s_br;
	gpkt.p_reqsid.s_seq = sid.s_seq;
	gpkt.p_cutoff = cutoff;
	gpkt.p_reopen = 1;
E 7
I 7
	/*
	move value of global sid into gpkt.p_reqsid for
	later comparision.
	*/
E 7

I 7
	gpkt.p_reqsid = sid;

	gpkt.p_reopen = 1;	/* set reopen flag to 1 for 'getline' */

E 7
	/*
D 7
	read delta table entries checking only for format error
E 7
I 7
	Read delta table entries checking for format error and
	setting the value for the SID if none was specified.
	Also check to see if SID specified does in fact exists.
E 7
	*/
D 7
	deltblchk(&gpkt);
E 7

I 7
	deltblchk(&gpkt);
E 7
	/*
	create auxiliary file for User Name Section
	*/

D 7
	aux_create(UNiop,untmp,EUSERNAM);
E 7
I 7
	if (HAD_UN)
		aux_create(UNiop,untmp,EUSERNAM);
	else read_to(EUSERNAM,&gpkt);
E 7

I 7
	/*
	store flags (if any) into global array called 'Sflags'
	*/

E 7
	doflags(&gpkt);

	/*
	create auxiliary file for the User Text section
	*/

D 7
	aux_create(UTiop,uttmp,EUSERTXT);
E 7
I 7
	if (HAD_FD)
		aux_create(UTiop,uttmp,EUSERTXT);
	else read_to(EUSERTXT,&gpkt);
E 7

	/*
	indicate to 'getline' that EOF is okay
	*/
I 7

E 7
	gpkt.p_chkeof = 1;

	/*
	read body of SCCS file and create temp file for it
	*/
I 7

E 7
	while(read_mod(&gpkt))
		;

D 7
	if (num_files > 1 || had_dir || had_standinp)
		printf("\n%s:\n",gpkt.p_file);
E 7
	/*
D 7
	Here, file has already been re-opened (by 'getline')
E 7
I 7
	Here, file has already been re-opened (by 'getline' after
	EOF was encountered by 'read_mod' calling 'getline')
E 7
	*/
I 7

E 7
	getline(&gpkt);		/* skip over header line */

I 7
	if (!HADD && !HADR && !HADE && !HADL)
		HADE = pr_fname = 1;
	if (!HADD)
		printf("%s:\n\n",file);

E 7
	/*
D 7
	call dodeltbl to read delta table entries
E 7
I 7
	call 'dodeltbl' to read delta table entries
	and determine which deltas are to be considered
E 7
	*/

	dodeltbl(&gpkt);

I 7
	/*
	call 'clean_up' to remove any temporary file created
	during processing of the SCCS file passed as an argument from
	'do_file'
	*/

E 7
	clean_up();

D 7
	return;
E 7
I 7
	return;		/* return to caller of 'process' */
E 7
}


I 7
/*
 * This procedure actually reads the delta table entries and
 * substitutes pre-defined strings and pointers with the information
 * needed during the scanning of the 'dataspec' line
*/
E 7
dodeltbl(pkt)
register struct packet *pkt;
{
D 7
	int	n;
E 7
I 7
	char	*n;
	int	stopdel;
	int	found;
E 7
	struct	deltab	dt;
	struct	stats	stats;

	/*
I 7
	flags used during determination of deltas to be
	considered
	*/

	found = stopdel = 0;

	/*
E 7
	Read entire delta table.
	*/
D 7
	while (getstats(pkt,&stats)) {
E 7
I 7
	while (getstats(pkt,&stats) && !stopdel) {
E 7
		if (getadel(pkt,&dt) != BDELTAB)
			fmterr(pkt);

		/*
I 7
		ignore 'removed' deltas if !HADA keyletter
		*/

		if (!HADA && dt.d_type != 'D') {
			read_to(EDELTAB,pkt);
			continue;
		}

		/*
		determine whether or not to consider current delta
		*/

		if (!(eqsid(&gpkt.p_reqsid, &dt.d_sid)) && !found) {
			/*
			if !HADL or HADE keyletter skip delta entry
			*/
			if ((!HADL) || HADE) {
				read_to(EDELTAB,pkt);
				continue;
			}
		}
		else {
			found = 1;
			stopdel = 1;
		}
		/*
		if HADE keyletter read remainder of delta table entries
		*/
		if (HADE && stopdel)
			stopdel = 0;
		/*
		create temp file for MRs and comments
		*/
		if (HAD_MR)
			MRiop = maket(mrtmp);
		if (HAD_CM)
			CMiop = maket(cmtmp);
		/*
E 7
		Read rest of delta entry. 
		*/
		while ((n = getline(pkt)) != NULL)
			if (pkt->p_line[0] != CTLCHAR)
				break;
			else {
				switch (pkt->p_line[1]) {
D 7
				case EDELTAB:
					scanspec(dataspec,&dt,&stats);
					break;
E 7
				case INCLUDE:
					getit(iline,n);
					continue;
				case EXCLUDE:
					getit(xline,n);
					continue;
				case IGNORE:
					getit(gline,n);
					continue;
				case MRNUM:
I 7
					if (HAD_MR)
						putmr(n);
					continue;
E 7
				case COMMENTS:
I 7
					if (HAD_CM)
						putcom(n);
E 7
					continue;
I 7
				case EDELTAB:
					/*
					close temp files for MRs and comments
					*/
					if (HAD_MR)
						fclose(MRiop);
					if (HAD_CM)
						fclose(CMiop);
					scanspec(dataspec,&dt,&stats);
					/*
					remove temp files for MRs and comments
					*/
					unlink(mrtmp);
					unlink(cmtmp);
					break;
E 7
				default:
					fmterr(pkt);
				}
				break;
			}
		if (n == NULL || pkt->p_line[0] != CTLCHAR)
			fmterr(pkt);
	}
}


/*
 * The scanspec procedure scans the dataspec searching for ID keywords.
 * When a keyword is found the value is replaced and printed on the
 * standard output. Any character that is not an ID keyword is printed
 * immediately.
*/

D 4
static	char	Zkeywd[5]	"@(#)";
E 4
I 4
D 7
static	char	Zkeywd[5] = "@(#)";
E 7
I 7
extern	char	*Sflags[];
static	char	Zkywd[5]   =   "@(#)";

E 7
E 4
scanspec(spec,dtp,statp)
char spec[];
struct	deltab	*dtp;
struct	stats	*statp;
{

D 7
	extern	char	*Sflags[];
E 7
	register char *lp;
	register char	*k;
	union {
		char	str[2];
D 2
		int	istr;
E 2
I 2
D 7
		short	istr;
E 7
I 7
		int	istr;
E 7
E 2
	} u;
	register	char	c;

I 7
	/* Zero union u (one int may be larger than two char's)
	*/
	u.istr = 0;

	/*
	call 'idsetup' to set certain data keywords for
	'scanspec' substitution
	*/
E 7
	idsetup(&dtp->d_sid,&gpkt,&dtp->d_datetime);
I 7

	/*
	scan 'dataspec' line
	*/
E 7
	for(lp = spec; *lp != 0; lp++) {
		if(lp[0] == ':' && lp[1] != 0 && lp[2] == ':') {
			c = *++lp;
			switch (c) {
			case 'I':	/* SID */
				printf("%s",Sid);
				break;
			case 'R':	/* Release number */
				printf("%u",dtp->d_sid.s_rel);
				break;
			case 'L':	/* Level number */
				printf("%u",dtp->d_sid.s_lev);
				break;
			case 'B':	/* Branch number */
				if (dtp->d_sid.s_br != 0)
					printf("%u",dtp->d_sid.s_br);
				break;
			case 'S':	/* Sequence number */
				if (dtp->d_sid.s_seq != 0)
					printf("%u",dtp->d_sid.s_seq);
				break;
			case 'D':	/* Date delta created */
				printf("%s",Deltadate);
				break;
			case 'T':	/* Time delta created */
				printf("%s",Deltatime);
				break;
			case 'P':	/* Programmer who created delta */
				printf("%s",dtp->d_pgmr);
				break;
			case 'C':	/* Comments */
I 7
				if (exists(cmtmp))
					printfile(cmtmp);
E 7
				break;
			case 'Y':	/* Type flag */
				printf("%s",Type);
				break;
			case 'M':	/* Module name */
				printf("%s",Mod);
				break;
			case 'W':	/* Form of what string */
D 7
				printf("%s",Zkeywd);
				printf("%s",Mod);
				putchar('\t');
				printf("%s",Sid);
E 7
I 7
				printf("%s%s\t%s",Zkywd,Mod,Sid);
E 7
				break;
			case 'A':	/* Form of what string */
D 7
				printf("%s",Zkeywd);
				printf("%s ",Type);
				printf("%s ",Mod);
				printf("%s",Sid);
				printf("%s",Zkeywd);
E 7
I 7
				printf("%s%s %s %s%s",Zkywd,Type,Mod,Sid,Zkywd);
E 7
				break;
			case 'Z':	/* what string constructor */
D 7
				printf("%s",Zkeywd);
E 7
I 7
				printf("%s",Zkywd);
E 7
				break;
			case 'F':	/* File name */
				printf("%s",sname(gpkt.p_file));
				break;
			default:
				putchar(':');
D 7
				putchar(c);
				putchar(':');
				break;
E 7
I 7
				--lp;
				continue;
E 7
			}
			lp++;
		}
		else if(lp[0] == ':' && lp[1] != 0 && lp[2] !=0 && lp[3] == ':') {
			if (lp[1] == ':') {
				putchar(':');
D 4
				*lp =+ 2;
E 4
I 4
D 7
				*lp += 2;
E 7
E 4
				continue;
			}
D 2
			u.str[0] = *++lp;
E 2
D 7
			u.str[1] = *++lp;
E 7
I 7
#if u370 || u3b
			u.str[3] = *++lp;
			u.str[2] = *++lp;
#else
E 7
I 2
			u.str[0] = *++lp;
I 7
			u.str[1] = *++lp;
#endif
E 7
E 2
			switch (u.istr) {
D 7
			case 'Dl':	/* Delta line statistics */
				printf("%05d",statp->s_ins);
E 7
I 7
			case 256*'L'+'D':	/* :DL: Delta line statistics */
				printf("%.05d",statp->s_ins);
E 7
				putchar('/');
D 7
				printf("%05d",statp->s_del);
E 7
I 7
				printf("%.05d",statp->s_del);
E 7
				putchar('/');
D 7
				printf("%05d",statp->s_unc);
E 7
I 7
				printf("%.05d",statp->s_unc);
E 7
				break;
D 7
			case 'Li':	/* Lines inserted by delta */
				printf("%05d",statp->s_ins);
E 7
I 7
			case 256*'i'+'L':	/* :Li: Lines inserted by delta */
				printf("%.05d",statp->s_ins);
E 7
				break;
D 7
			case 'Ld':	/* Lines deleted by delta */
				printf("%05d",statp->s_del);
E 7
I 7
			case 256*'d'+'L':	/* :Ld: Lines deleted by delta */
				printf("%.05d",statp->s_del);
E 7
				break;
D 7
			case 'Lu':	/* Lines unchanged by delta */
				printf("%05d",statp->s_unc);
E 7
I 7
			case 256*'u'+'L':	/* :Lu: Lines unchanged by delta */
				printf("%.05d",statp->s_unc);
E 7
				break;
D 7
			case 'DT':	/* Delta type */
E 7
I 7
			case 256*'T'+'D':	/* :DT: Delta type */
E 7
				printf("%c",dtp->d_type);
				break;
D 7
			case 'Dy':	/* Year delta created */
E 7
I 7
			case 256*'y'+'D':	/* :Dy: Year delta created */
E 7
D 2
				printf("%02d",Dtime->t_year);
E 2
I 2
				printf("%02d",Dtime->tm_year);
E 2
				break;
D 7
			case 'Dm':	/* Month delta created */
E 7
I 7
			case 256*'m'+'D':	/* :Dm: Month delta created */
E 7
D 2
				printf("%02d",(Dtime->t_month + 1));
E 2
I 2
				printf("%02d",(Dtime->tm_mon + 1));
E 2
				break;
D 7
			case 'Dd':	/* Day delta created */
E 7
I 7
			case 256*'d'+'D':	/* :Dd: Day delta created */
E 7
D 2
				printf("%02d",Dtime->t_day_month);
E 2
I 2
				printf("%02d",Dtime->tm_mday);
E 2
				break;
D 7
			case 'Th':	/* Hour delta created */
E 7
I 7
			case 256*'h'+'T':	/* :Th: Hour delta created */
E 7
D 2
				printf("%02d",Dtime->t_hours);
E 2
I 2
				printf("%02d",Dtime->tm_hour);
E 2
				break;
D 7
			case 'Tm':	/* Minutes delta created */
E 7
I 7
			case 256*'m'+'T':	/* :Tm: Minutes delta created */
E 7
D 2
				printf("%02d",Dtime->t_minutes);
E 2
I 2
				printf("%02d",Dtime->tm_min);
E 2
				break;
D 7
			case 'Ts':	/* Seconds delta created */
E 7
I 7
			case 256*'s'+'T':	/* :Ts: Seconds delta created */
E 7
D 2
				printf("%02d",Dtime->t_seconds);
E 2
I 2
				printf("%02d",Dtime->tm_sec);
E 2
				break;
D 7
			case 'DS':	/* Delta sequence number */
E 7
I 7
			case 256*'S'+'D':	/* :DS: Delta sequence number */
E 7
				printf("%d",dtp->d_serial);
				break;
D 7
			case 'DP':	/* Predecessor delta sequence number */
E 7
I 7
			case 256*'P'+'D':	/* :DP: Predecessor delta sequence number */
E 7
				printf("%d",dtp->d_pred);
				break;
D 7
			case 'DI':	/* Deltas included,excluded,ignored */
E 7
I 7
			case 256*'I'+'D':	/* :DI: Deltas included,excluded,ignored */
E 7
				printf("%s",iline);
D 7
				putchar('/');
				printf("%s",xline);
				putchar('/');
				printf("%s",gline);
E 7
I 7
				if (length(xline))
					printf("/%s",xline);
				if (length(gline))
					printf("/%s",gline);
E 7
				break;
D 7
			case 'Di':	/* Deltas included */
E 7
I 7
			case 256*'n'+'D':	/* :Dn: Deltas included */
E 7
				printf("%s",iline);
				break;
D 7
			case 'Dx':	/* Deltas excluded */
E 7
I 7
			case 256*'x'+'D':	/* :Dx: Deltas excluded */
E 7
				printf("%s",xline);
				break;
D 7
			case 'Dg':	/* Deltas ignored */
E 7
I 7
			case 256*'g'+'D':	/* :Dg: Deltas ignored */
E 7
				printf("%s",gline);
				break;
D 7
			case 'MR':	/* MR numbers */
E 7
I 7
			case 256*'R'+'M':	/* :MR: MR numbers */
				if (exists(mrtmp))
					printfile(mrtmp);
E 7
				break;
D 7
			case 'UN':	/* User names */
				printfile(untmp);
E 7
I 7
			case 256*'N'+'U':	/* :UN: User names */
				if (exists(untmp))
					printfile(untmp);
E 7
				break;
D 7
			case 'MF':	/* MR validation flag */
E 7
I 7
			case 256*'F'+'M':	/* :MF: MR validation flag */
E 7
				if (Sflags[VALFLAG - 'a'])
					printf("yes");
				else printf("no");
				break;
D 7
			case 'MP':	/* MR validation program */
E 7
I 7
			case 256*'P'+'M':	/* :MP: MR validation program */
E 7
				if (!(k = Sflags[VALFLAG - 'a']))
					printf("none");
				else printf("%s",k);
				break;
D 7
			case 'KF':	/* Keyword err/warn flag */
E 7
I 7
			case 256*'F'+'K':	/* :KF: Keyword err/warn flag */
E 7
				if (Sflags[IDFLAG - 'a'])
					printf("yes");
				else printf("no");
				break;
D 7
			case 'BF':	/* Branch flag */
E 7
I 7
			case 256*'F'+'B':	/* :BF: Branch flag */
E 7
				if (Sflags[BRCHFLAG - 'a'])
					printf("yes");
				else printf("no");
				break;
D 7
			case 'FB':	/* Floor Boundry */
E 7
I 7
			case 256*'B'+'F':	/* :FB: Floor Boundry */
E 7
				if (k = Sflags[FLORFLAG - 'a'])
					printf("%s",k);
				else printf("none");
				break;
D 7
			case 'CB':	/* Ceiling Boundry */
E 7
I 7
			case 256*'B'+'C':	/* :CB: Ceiling Boundry */
E 7
				if (k = Sflags[CEILFLAG - 'a'])
					printf("%s",k);
				else printf("none");
				break;
D 7
			case 'Ds':	/* Default SID */
E 7
I 7
			case 256*'s'+'D':	/* :Ds: Default SID */
E 7
				if (k = Sflags[DEFTFLAG - 'a'])
					printf("%s",k);
				else printf("none");
				break;
D 7
			case 'ND':	/* Null delta */
E 7
I 7
			case 256*'D'+'N':	/* :ND: Null delta */
E 7
				if (Sflags[NULLFLAG - 'a'])
					printf("yes");
				else printf("no");
				break;
D 7
			case 'FD':	/* File descriptive text */
				printfile(uttmp);
E 7
I 7
			case 256*'D'+'F':	/* :FD: File descriptive text */
				if (exists(uttmp))
					printfile(uttmp);
E 7
				break;
D 7
			case 'BD':	/* Entire file body */
				printfile(bdtmp);
E 7
I 7
			case 256*'D'+'B':	/* :BD: Entire file body */
				if (exists(bdtmp))
					printfile(bdtmp);
E 7
				break;
D 7
			case 'GB':	/* Gotten body from 'get' */
E 7
I 7
			case 256*'B'+'G':	/* :GB: Gotten body from 'get' */
E 7
				getbody(&dtp->d_sid,&gpkt);
				break;
I 7
			case 256*'N'+'P':	/* :PN: Full pathname of File */
				copy(gpkt.p_file,Dir);
				dname(Dir);
				if(getwd(Olddir) == NULL)
					fatal("getwd failed (prs2)");
				if(chdir(Dir) != 0)
					fatal("cannot change directory (prs3)");
				if(getwd(Pname) == NULL)
					fatal("getwd failed (prs2)");
				if(chdir(Olddir) != 0)
					fatal("cannot change directory (prs3)");
				printf("%s/",Pname);
				printf("%s",sname(gpkt.p_file));
				break;
			case 256*'L'+'F':	/* :FL: Flag descriptions (as in 'prt') */
				printflags();
				break;
			case 256*'t'+'D':	/* :Dt: Whole delta table line */
				/*
				replace newline with null char to make
				data keyword simple format
				*/
				repl(dt_line,'\n','\0');
				k = dt_line;
				/*
				skip control char, line flag, and blank
				*/
				k += 3;
				printf("%s",k);
				break;
E 7
			default:
				putchar(':');
D 7
				printf("%c",u.istr);
				putchar(':');
				break;
E 7
I 7
				lp -= 2;
				continue;
E 7
			}
			lp++;
		}
		else {
			c = *lp;
			if (c == '\\') {
				switch(*++lp) {
				case 'n':	/* for newline */
					putchar('\n');
					break;
				case ':':	/* for wanted colon */
					putchar(':');
					break;
				case 't':	/* for tab */
					putchar('\t');
					break;
				case 'b':	/* for backspace */
					putchar('\b');
					break;
				case 'r':	/* for carriage return */
					putchar('\r');
					break;
				case 'f':	/* for form feed */
					putchar('\f');
					break;
				case '\\':	/* for backslash */
					putchar('\\');
					break;
				case '\'':	/* for single quote */
					putchar('\'');
					break;
				default:	/* unknown case */
					putchar('\\');
					putchar(*lp);
					break;
				}
			}
			else putchar(*lp);
		}
	}
	/*
	zero out first char of global string lines in case
	a value is not gotten in next delta table entry
	*/
	iline[0] = xline[0] = gline[0] = 0;
	putchar('\n');
	return;
}


I 7
/*
 * This procedure cleans up all temporary files created during
 * 'process' that are used for data keyword substitution
*/
E 7
clean_up()
{
D 7
	unlink(untmp);
	unlink(uttmp);
	unlink(bdtmp);
I 2
	if (gpkt.p_iop)
E 7
I 7
	if (gpkt.p_iop)		/* if SCCS file is open, close it */
E 7
		fclose(gpkt.p_iop);
I 7
	xrm(&gpkt);	      /* remove the 'packet' used for this SCCS file */
	unlink(mrtmp);		/* remove all temporary files from /tmp */
	unlink(cmtmp);		/*			"		*/
	unlink(untmp);		/*			"		*/
	unlink(uttmp);		/*			"		*/
	unlink(bdtmp);		/*			"		*/
E 7
E 2
}


/* This function takes as it's argument the SID inputed and determines
 * whether or not it is valid (e. g. not ambiguous or illegal).
*/
invalid(i_sid)
register char	*i_sid;
{
	register int count;
	register int digits;
	count = digits = 0;
	if (*i_sid == '0' || *i_sid == '.')
		return (1);
	i_sid++;
	digits++;
	while (*i_sid != '\0') {
		if (*i_sid++ == '.') {
			digits = 0;
			count++;
			if (*i_sid == '0' || *i_sid == '.')
				return (1);
		}
		digits++;
		if (digits > 5)
			return (1);
	}
	if (*(--i_sid) == '.' )
		return (1);
	if (count == 1 || count == 3)
		return (0);
	return (1);
}


I 7
/*
 * This procedure checks the delta table entries for correct format.
 * It also checks to see if the SID specified by the -r keyletter
 * is contained in the file.  If no SID was specified assumes the top
 * delta created (last in time).
*/
E 7
deltblchk(pkt)
register struct packet *pkt;
{
D 7
	int	n;
E 7
I 7
	char	*n;
	int	have;
	int	found;
E 7
	struct	deltab	dt;
	struct	stats	stats;

I 7
	have = found = 0;
E 7
	/*
	Read entire delta table.
	*/
	while (getstats(pkt,&stats)) {
		if (getadel(pkt,&dt) != BDELTAB)
			fmterr(pkt);

		/*
I 7
		if no SID was specified, get top delta
		*/
		if (pkt->p_reqsid.s_rel == 0 && !have) {
			/*
			ignore if "removed" delta 
			*/
			if (!HADA && dt.d_type != 'D') {
				read_to(EDELTAB,pkt);
				continue;
			}
			/*
			move current SID into SID to look at
			*/
			gpkt.p_reqsid = dt.d_sid;
			found = have = 1;
		}
		/*
		if SID was specified but not located yet check
		to see if this SID is the one
		*/
		if (pkt->p_reqsid.s_rel != 0 && !found)
			if (eqsid(&gpkt.p_reqsid, &dt.d_sid))
				found = 1;
		/*
E 7
		Read rest of delta entry. 
		*/
		while ((n = getline(pkt)) != NULL)
			if (pkt->p_line[0] != CTLCHAR)
				break;
			else {
				switch (pkt->p_line[1]) {
				case EDELTAB:
					break;
				case INCLUDE:
				case EXCLUDE:
				case IGNORE:
				case MRNUM:
				case COMMENTS:
					continue;
				default:
					fmterr(pkt);
				}
				break;
			}
		if (n == NULL || pkt->p_line[0] != CTLCHAR)
			fmterr(pkt);
	}
I 7
	/*
	if not at the beginning of the User Name section
	there is an internal error
	*/
E 7
	if (pkt->p_line[1] != BUSERNAM)
		fmterr(pkt);
I 7
	/*
	if SID did not exist (the one specified by -r keyletter)
	then there exists an error
	*/
	if (!found)
		fatal("nonexistent SID (prs1)");
E 7
}


I 7
/*
 * This procedure reads the stats line from the delta table entry
 * and places the statisitics into a structure called "stats".
*/
E 7
getstats(pkt,statp)
register struct packet *pkt;
register struct stats *statp;
{
	register char *p;

	p = pkt->p_line;
	if (getline(pkt) == NULL || *p++ != CTLCHAR || *p++ != STATS)
		return(0);
	NONBLANK(p);
	p = satoi(p,&statp->s_ins);
	p = satoi(++p,&statp->s_del);
	satoi(++p,&statp->s_unc);
	return(1);
}


I 7
/*
 * This procedure reads a delta table entry line from the delta
 * table entry and places the contents of the line into a structure
 * called "deltab".
*/
E 7
getadel(pkt,dt)
register struct packet *pkt;
register struct deltab *dt;
{
	if (getline(pkt) == NULL)
		fmterr(pkt);
I 7
	copy(pkt->p_line,dt_line);  /* copy delta table line for :Dt: keywd */
E 7
	return(del_ab(pkt->p_line,dt,pkt));
}

I 7
FILE *fdfopen();
E 7

D 7

char	*maket(file)
E 7
I 7
/*
 * This procedure creates the temporary file used during the
 * "process" subroutine.  The skeleton defined at the beginning
 * of the program is filled in in this function
*/
FILE	*maket(file)
E 7
char	*file;
{
	FILE *iop;
I 7
	char *mktemp();
E 7

D 7
	copy(tempskel,file);
E 7
I 7
	copy(tempskel,file);	/* copy file name into the skeleton */
E 7
	iop = xfcreat(mktemp(file),0644);

	return(iop);
}


I 7
/*
 * This procedure prints (on the standard output) the contents of any___
 * temporary file that may have been created during "process".
*/
E 7
printfile(file)
register	char	*file;
{
	register	char	*p;
	FILE	*iop;

	iop = xfopen(file,0);
	while ((p = fgets(line,sizeof(line),iop)) != NULL)
		printf("%s",p);
	fclose(iop);
}


I 7
/*
 * This procedure reads the body of the SCCS file from beginning to end.
 * It also creates the temporary file /tmp/prbdtmp____________ which contains
 * the body of the SCCS file for data keyword substitution.
*/
E 7
read_mod(pkt)
register struct packet *pkt;
{
	register char *p;
	int ser;
D 7
	int iord;
E 7
I 7
	int iod;
E 7
	register struct apply *ap;
I 7
	int level = 0;
E 7

D 7
	BDiop = maket(bdtmp);
E 7
I 7
	if (HAD_BD)
		BDiop = maket(bdtmp);
E 7
	while (getline(pkt) != NULL) {
		p = pkt->p_line;
D 7
		fputs(p,BDiop);
E 7
I 7
		if (HAD_BD)
			fputs(p,BDiop);
E 7
		if (*p++ != CTLCHAR)
			continue;
		else {
D 7
			if (!((iord = *p++) == INS || iord == DEL || iord == END))
E 7
I 7
			if (!((iod = *p++) == INS || iod == DEL || iod == END))
E 7
				fmterr(pkt);
			NONBLANK(p);
			satoi(p,&ser);
D 7
			if (iord == END)
				remq(pkt,ser);
			else if ((ap = &pkt->p_apply[ser])->a_code == APPLY)
				addq(pkt,ser,iord == INS ? YES : NO,iord,ap->a_reason & USER);
			else
				addq(pkt,ser,iord == INS ? NO : NULL,iord,ap->a_reason & USER);
E 7
I 7
/*
 * The logic here is really wrong. Best I can tell, pkt->p_apply can never
 * be anything but NULL in prs. No routine ever sets it. It appears
 * that the only intent of the code was to check that INS and DEL commands
 * were matched with an equal amount of END commands. So we'll do that
 * instead.
 *			if (iod == END)
 *				remq(pkt,ser);
 *			else if ((ap = &pkt->p_apply[ser])->a_code == APPLY)
 *				addq(pkt,ser,iod == INS ? YES : NO,iod,ap->a_reason & USER);
 *			else
 *				addq(pkt,ser,iod == INS ? NO : NULL,iod,ap->a_reason & USER);
 */
			if (iod == END) {
				if (--level < 0)
					fmterr(pkt);
			} else
				level++;
E 7
		}
	}
D 7
	fclose(BDiop);
	if (pkt->p_q)
E 7
I 7
	if (HAD_BD)
		fclose(BDiop);
	if (level != 0)
E 7
		fatal("premature eof (co5)");
	return(0);
}


I 7
/*
 * This procedure is only called if the :GB: data keyword is specified.
 * It forks and creates a child process to invoke 'get' with the '-p'
 * and '-s' options for the SID currently being processed.  Upon
 * completion, control of the program is returned to 'prs'.
*/
E 7
getbody(gsid,pkt)
struct	sid	*gsid;
struct packet *pkt;
{
	int	i;
	int	status;
	extern	char	Getpgm[];
	char	str[128];
	char	rarg[20];
	char	filearg[80];

	sid_ba(gsid,str);
D 7
	sprintf(rarg,"%s",str);
E 7
I 7
	sprintf(rarg,"-r%s",str);
E 7
	sprintf(filearg,"%s",pkt->p_file);
	/*
	fork here so 'getbody' can execute 'get' to
	print out gotten body :GB:
	*/
	if ((i = fork()) < 0)
		fatal("cannot fork, try again");
D 7
	if (i = 0) {
E 7
I 7
	if (i == 0) {
E 7
		/*
		perform 'get' and redirect output
		to standard output
		*/
D 7
		execl(Getpgm,Getpgm,"-s","-p","-r",rarg,filearg,0);
E 7
I 7
		execlp(Getpgm,Getpgm,"-s","-p",rarg,filearg,0);
E 7
D 5
		fatal(sprintf(Error,"cannot execute '%s'",Getpgm));
E 5
I 5
		sprintf(Error,"cannot execute '%s'",Getpgm);
		fatal(Error);
E 5
	}
	else {
		wait(&status);
		return;
	}
}


I 7
/*
 * This procedure places the line read in "dodeltbl" into a global string
 * 'str'.  This procedure is only called for include, exclude or ignore
 * lines.
*/
E 7
getit(str,cp)
register	char	*str, *cp;
{
D 4
	cp =+ 2;
E 4
I 4
	cp += 2;
E 4
	NONBLANK(cp);
	cp[length(cp) - 1] = '\0';
	sprintf(str,"%s",cp);
}


I 7
/*
 * This procedure creates an auxiliary file for the iop passed as an argument
 * for the file name also passed as an argument.  If no text exists for the
 * named file, an auxiliary file is still created with the text "(none)".
*/
E 7
aux_create(iop,file,delchar)
FILE	*iop;
char	*file;
char	delchar;
{

D 7
	int	n;
E 7
I 7
	char	*n;
E 7
	int	text;
	/*
	create auxiliary file for the named section
	*/

	text = 0;
	iop = maket(file);
	while ((n = getline(&gpkt)) != NULL && gpkt.p_line[0] != CTLCHAR) {
		text = 1;
		fputs(n,iop);
	}
	/*
	check to see that delimiter found is correct
	*/
	if (n == NULL || gpkt.p_line[0] != CTLCHAR || gpkt.p_line[1] != delchar)
		fmterr(&gpkt);
	if (!text)
D 7
		fprintf(iop,"No entries\n");
E 7
I 7
		fprintf(iop,"(none)\n");
E 7
	fclose(iop);
}


I 7
/*
 * This procedure sets the values for certain data keywords which are
 * either shared by more than one data keyword or because substitution
 * here would be easier than doing it in "scanspec" (more efficient etc.)
*/
E 7
idsetup(gsid,pkt,bdate)
struct	sid	*gsid;
struct	packet	*pkt;
long	*bdate;
{

	register	char	*p;
D 2
	extern	struct	time	*localtime();
E 2
I 2
	extern	struct	tm	*localtime();
I 7
	char *auxf(), *date_ba();
E 7
E 2

D 7
	date_ba(bdate,Deltadate);
E 7
I 7
	/***  There doesn't seem to be a comparable routine in Ultrix
	sccs_tzset();
	 ***  and it also doesn't appear to be needed -- depp */
E 7

I 7
	date_ba(bdate,Deltadate);
E 7
	Deltatime = &Deltadate[9];
	Deltadate[8] = 0;
D 7

E 7
	sid_ba(gsid,Sid);
D 7

E 7
	Dtime = localtime(bdate);
D 7

E 7
	if (p = Sflags[MODFLAG - 'a'])
		copy(p,Mod);
D 7
	else sprintf(Mod,"%s",sname(pkt->p_file));

E 7
I 7
	else sprintf(Mod,"%s",auxf(pkt->p_file,'g'));
E 7
	if (!(Type = Sflags[TYPEFLAG - 'a']))
D 7
		Type = "none";
E 7
I 7
		Type = Null;
}


/*
 * This procedure places any MRs that are found in the delta table entry
 * into the temporary file created for that express purpose (/tmp/prmrtmp____________).
*/
putmr(cp)
register char	*cp;
{

	cp += 3;

	if (!(*cp) || (*cp == '\n')) {
		fclose(MRiop);
		unlink(mrtmp);
		return;
	}

	fputs(cp,MRiop);
}


/*
 * This procedure is the same as "putmr" except it is used for the comment
 * section of the delta table entries.
*/
putcom(cp)
register char	*cp;
{

	cp += 3;

	fputs(cp,CMiop);

}


/*
 * This procedure reads through the SCCS file until a line is found
 * containing the character passed as an argument in the 2nd__ position
 * of the line.
*/
read_to(ch,pkt)
register char	ch;
register struct packet *pkt;
{
	register char *p;
	while ((p = getline(pkt)) &&
			!(*p++ == CTLCHAR && *p == ch))
		;
	return;
}


/*
 * This procedure prints a list of all the flags that are present in the
 * SCCS file.  The format is the same as 'prt' except the flag description
 * is _n_o_t preceeded by a "tab".
*/
printflags()
{
	register	char	*k;

	if (Sflags[BRCHFLAG - 'a'])	/* check for 'branch' flag */
		printf("branch\n");
	if ((k = (Sflags[CEILFLAG - 'a'])))	/* check for 'ceiling flag */
		printf("ceiling\t%s\n",k);
	if ((k = (Sflags[DEFTFLAG - 'a'])))  /* check for 'default SID' flag */
		printf("default SID\t%s\n",k);
	if ((k = (Sflags[FLORFLAG - 'a'])))	/* check for 'floor' flag */
		printf("floor\t%s\n",k);
	if (Sflags[IDFLAG - 'a'])	/* check for 'id err/warn' flag */
		printf("id keywd err/warn\n");
	if ((k = (Sflags[MODFLAG - 'a'])))	/* check for 'module' flag */
		printf("module\t%s\n",k);
	if (Sflags[NULLFLAG - 'a'])	/* check for 'null delta' flag */
		printf("null delta\n");
	if ((k = (Sflags[TYPEFLAG - 'a'])))	/* check for 'type' flag */
		printf("type\t%s\n",k);
	if (Sflags[VALFLAG - 'a']) {	/* check for 'MR valid' flag */
		printf("validate MRs\t");
		/*
		check for MR validating program
		(optional)
		*/
		if (k = (Sflags[VALFLAG - 'a']))
			printf("%s\n",k);
		else putchar('\n');
	}
	return;
}


/*
 * This procedure checks the `dataspec' (if user defined) and determines
 * if any temporary files need be created for future keyword replacement
*/
ck_spec(p)
register char *p;
{
	if (libPW_index(p,":C:") != -1)	/* check for Comment keyword */
		HAD_CM = 1;
	if (libPW_index(p,":MR:") != -1)/* check for MR keyword */
		HAD_MR = 1;
	if (libPW_index(p,":UN:") != -1)/* check for User name keyword */
		HAD_UN = 1;
	if (libPW_index(p,":FD:") != -1)/* check for descriptive text kyword */
		HAD_FD = 1;
	if (libPW_index(p,":BD:") != -1)/* check for body keyword */
		HAD_BD = 1;
E 7
}
E 1
