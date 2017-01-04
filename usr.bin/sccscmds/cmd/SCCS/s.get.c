h58660
s 00016/00019/00717
d D 4.11 2011/07/13 06:37:48 msokolov 12 11
c date keyword handling adjusted for 4-digit years
e
s 00010/00003/00726
d D 4.10 99/12/14 21:47:13 msokolov 11 10
c Y2K
e
s 00014/00009/00715
d D 4.9 88/02/02 15:56:00 bostic 10 9
c sprintf doesn't return a pointer to it's first arg, anymore
e
s 00010/00010/00714
d D 4.8 87/02/15 20:57:46 lepreau 9 8
c modern syntax for asgops & inits cause Donn's latest ccom rejects the old.
e
s 00046/00017/00678
d D 4.7 85/05/04 00:34:42 sam 8 7
c purge some of the old grotty local routines; for get add %Q% for man pages
e
s 00010/00020/00685
d D 4.6 84/05/21 13:22:59 mckusick 7 6
c optimization from R. P. C. Collinson of ukc
e
s 00001/00001/00704
d D 4.5 83/07/03 17:38:37 sam 6 5
c include fix
e
s 00003/00002/00702
d D 4.4 82/10/06 15:22:03 sam 5 3
c handles long file names properly now?
e
s 00001/00001/00703
d R 4.4 81/04/13 11:39:43 eric 4 3
c don't assume -k if -i or -x
e
s 00002/00002/00702
d D 4.3 81/02/19 13:42:18 eric 3 2
c use 0666 for file creation; let umask do the work
e
s 00009/00001/00695
d D 4.2 81/02/16 11:20:59 eric 2 1
c define "writable" as "any write enable bit set" not "i can write"
e
s 00696/00000/00000
d D 4.1 81/01/15 00:16:33 eric 1 0
c date and time created 81/01/15 00:16:33 by eric
e
u
U
f b 
f i 
t
T
I 8
#include <sys/param.h>		/* for MAXPATHLEN */
#undef MAX
E 8
I 1
# include	"../hdr/defines.h"
# include	"../hdr/had.h"
I 5
D 6
# include	<dir.h>
E 6
I 6
# include	<sys/dir.h>
E 6
E 5

D 9
SCCSID(%W%);
E 9
I 9
static char Sccsid[] = "%W%	%G%";
E 9
D 8
USXALLOC();
E 8

D 9
int	Debug	0;
E 9
I 9
int	Debug = 0;
E 9
struct packet gpkt;
struct sid sid;
unsigned	Ser;
int	num_files;
char	had[26];
char	*ilist, *elist, *lfile;
D 9
long	cutoff	0X7FFFFFFFL;	/* max positive long */
E 9
I 9
long	cutoff = 0X7FFFFFFFL;	/* max positive long */
E 9
int verbosity;
D 5
char	Gfile[16];
E 5
I 5
char	Gfile[MAXNAMLEN + 3];
I 7
char	Mod[MAXNAMLEN + 3];		/* should be as large as Gfile? */
E 7
E 5
char	*Type;
int	Did_id;

main(argc,argv)
int argc;
register char *argv[];
{
	register int i;
	register char *p;
	char c;
	int testmore;
	extern int Fcnt;
	extern get();

	Fflags = FTLEXIT | FTLMSG | FTLCLN;
	for(i=1; i<argc; i++)
		if(argv[i][0] == '-' && (c=argv[i][1])) {
			p = &argv[i][2];
			testmore = 0;
			switch (c) {

			case 'a':
				if (!p[0]) {
					argv[i] = 0;
					continue;
				}
				Ser = patoi(p);
				break;
			case 'r':
				if (!p[0]) {
					argv[i] = 0;
					continue;
				}
				chksid(sid_ab(p,&sid),&sid);
				break;
			case 'c':
				if (!p[0]) {
					argv[i] = 0;
					continue;
				}
				if (date_ab(p,&cutoff))
					fatal("bad date/time (cm5)");
				break;
			case 'l':
				lfile = p;
				break;
			case 'i':
				if (!p[0]) {
					argv[i] = 0;
					continue;
				}
				ilist = p;
				break;
			case 'x':
				if (!p[0]) {
					argv[i] = 0;
					continue;
				}
				elist = p;
				break;
			case 'b':
			case 'g':
			case 'e':
			case 'p':
			case 'k':
			case 'm':
			case 'n':
			case 's':
			case 't':
				testmore++;
				break;
			default:
				fatal("unknown key letter (cm1)");
			}

			if (testmore) {
				testmore = 0;
D 10
				if (*p)
					fatal(sprintf(Error,
					  "value after %c arg (cm8)",c));
E 10
I 10
				if (*p) {
					sprintf(Error,"value after %c arg (cm8)",c);
					fatal(Error);
				}
E 10
			}
			if (had[c - 'a']++)
				fatal("key letter twice (cm2)");
			argv[i] = 0;
		}
		else num_files++;

	if(num_files == 0)
		fatal("missing file arg (cm3)");
	if (HADE && HADM)
		fatal("e not allowed with m (ge3)");
	if (HADE || HADI || HADX)
		HADK = 1;
	if (!HADS)
		verbosity = -1;
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
			do_file(p,get);
	exit(Fcnt ? 1 : 0);
}


get(file)
{
	register char *p;
	register unsigned ser;
	extern char had_dir, had_standinp;
	extern char *Sflags[];
	struct stats stats;
	char	str[32];

	if (setjmp(Fjmp))
		return;
	sinit(&gpkt,file,1);
	gpkt.p_ixuser = (HADI | HADX);
	gpkt.p_reqsid.s_rel = sid.s_rel;
	gpkt.p_reqsid.s_lev = sid.s_lev;
	gpkt.p_reqsid.s_br = sid.s_br;
	gpkt.p_reqsid.s_seq = sid.s_seq;
	gpkt.p_verbose = verbosity;
	gpkt.p_stdout = (HADP ? stderr : stdout);
	gpkt.p_cutoff = cutoff;
	gpkt.p_lfile = lfile;
	copy(auxf(gpkt.p_file,'g'),Gfile);

	if (gpkt.p_verbose && (num_files > 1 || had_dir || had_standinp))
		fprintf(gpkt.p_stdout,"\n%s:\n",gpkt.p_file);
	if (dodelt(&gpkt,&stats,0,0) == 0)
		fmterr(&gpkt);
	finduser(&gpkt);
	doflags(&gpkt);
	if (!HADA)
		ser = getser(&gpkt);
	else {
		if ((ser = Ser) > maxser(&gpkt))
			fatal("serial number too large (ge19)");
D 8
		move(&gpkt.p_idel[ser].i_sid, &gpkt.p_gotsid, sizeof(sid));
E 8
I 8
		bcopy(&gpkt.p_idel[ser].i_sid, &gpkt.p_gotsid, sizeof(sid));
E 8
		if (HADR && sid.s_rel != gpkt.p_gotsid.s_rel) {
D 8
			zero(&gpkt.p_reqsid, sizeof(gpkt.p_reqsid));
E 8
I 8
			bzero(&gpkt.p_reqsid, sizeof(gpkt.p_reqsid));
E 8
			gpkt.p_reqsid.s_rel = sid.s_rel;
		}
		else
D 8
			move(&gpkt.p_gotsid, &gpkt.p_reqsid, sizeof(sid));
E 8
I 8
			bcopy(&gpkt.p_gotsid, &gpkt.p_reqsid, sizeof(sid));
E 8
	}
	doie(&gpkt,ilist,elist,0);
	setup(&gpkt,ser);
	if (!(Type = Sflags[TYPEFLAG - 'a']))
		Type = Null;
D 2
	if (!(HADP || HADG) && access(Gfile,2) == 0)
E 2
I 2
D 10
	if (!(HADP || HADG) && writable(Gfile))
E 2
		fatal(sprintf(Error,"writable `%s' exists (ge4)",Gfile));
E 10
I 10
	if (!(HADP || HADG) && writable(Gfile)) {
		sprintf(Error,"writable `%s' exists (ge4)",Gfile);
		fatal(Error);
	}
E 10
	if (gpkt.p_verbose) {
		sid_ba(&gpkt.p_gotsid,str);
		fprintf(gpkt.p_stdout,"%s\n",str);
	}
	if (HADE) {
		if (!HADR)
D 8
			move(&gpkt.p_gotsid,&gpkt.p_reqsid,
E 8
I 8
			bcopy(&gpkt.p_gotsid,&gpkt.p_reqsid,
E 8
			     sizeof(gpkt.p_reqsid));
		newsid(&gpkt,Sflags[BRCHFLAG - 'a'] && HADB);
		permiss(&gpkt);
		wrtpfile(&gpkt,ilist,elist);
	}
	setuid(getuid());
	if (HADL)
		gen_lfile(&gpkt);
	if (HADG) {
		fclose(gpkt.p_iop);
		xfreeall();
		return;
	}
	flushto(&gpkt,EUSERTXT,1);
	idsetup(&gpkt);
	gpkt.p_chkeof = 1;
	Did_id = 0;
	while(readmod(&gpkt)) {
		if (gpkt.p_gout == 0) {
			if (HADP)
				gpkt.p_gout = stdout;
			else
D 3
				gpkt.p_gout = xfcreat(Gfile,HADK ? 0644 : 0444);
E 3
I 3
				gpkt.p_gout = xfcreat(Gfile,HADK ? 0666 : 0444);
E 3
		}
D 7
		prfx(&gpkt);
		p = idsubst(&gpkt,gpkt.p_line);
E 7
I 7
		if (HADN)
			fprintf(gpkt.p_gout,"%s\t",Mod);
		if (HADM) {
			sid_ba(&gpkt.p_inssid,str);
			fprintf(gpkt.p_gout,"%s\t",str);
		}
		p = gpkt.p_line;
		if (!HADK && any('%',p))
			p = idsubst(&gpkt,p);
E 7
		fputs(p,gpkt.p_gout);
	}
	fflush(gpkt.p_gout);
	if (gpkt.p_gout && gpkt.p_gout != stdout)
		fclose(gpkt.p_gout);
	if (gpkt.p_verbose)
		fprintf(gpkt.p_stdout,"%u lines\n",gpkt.p_glnno);
	if (!Did_id && !HADK)
		if (Sflags[IDFLAG - 'a'])
			fatal("no id keywords (cm6)");
		else if (gpkt.p_verbose)
			fprintf(stderr,"No id keywords (cm7)\n");
	xfreeall();
I 2
}

writable(fn)
char *fn;
{
	struct stat s;

	return (stat(fn, &s) >= 0 && (s.st_mode & 0222) != 0);
E 2
}


newsid(pkt,branch)
register struct packet *pkt;
int branch;
{
	int chkbr;

	chkbr = 0;
	if (pkt->p_reqsid.s_br == 0) {
D 9
		pkt->p_reqsid.s_lev =+ 1;
E 9
I 9
		pkt->p_reqsid.s_lev += 1;
E 9
		if (sidtoser(&pkt->p_reqsid,pkt) ||
			pkt->p_maxr > pkt->p_reqsid.s_rel || branch) {
				pkt->p_reqsid.s_rel = pkt->p_gotsid.s_rel;
				pkt->p_reqsid.s_lev = pkt->p_gotsid.s_lev;
				pkt->p_reqsid.s_br = pkt->p_gotsid.s_br + 1;
				pkt->p_reqsid.s_seq = 1;
				chkbr++;
		}
	}
	else if (pkt->p_reqsid.s_seq == 0 && !branch)
		pkt->p_reqsid.s_seq = pkt->p_gotsid.s_seq + 1;
	else {
D 9
		pkt->p_reqsid.s_seq =+ 1;
E 9
I 9
		pkt->p_reqsid.s_seq += 1;
E 9
		if (branch || sidtoser(&pkt->p_reqsid,pkt)) {
D 9
			pkt->p_reqsid.s_br =+ 1;
E 9
I 9
			pkt->p_reqsid.s_br += 1;
E 9
			pkt->p_reqsid.s_seq = 1;
			chkbr++;
		}
	}
	if (chkbr)
		while (sidtoser(&pkt->p_reqsid,pkt))
D 9
			pkt->p_reqsid.s_br =+ 1;
E 9
I 9
			pkt->p_reqsid.s_br += 1;
E 9
	if (sidtoser(&pkt->p_reqsid,pkt))
		fatal("internal error in newsid()");
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
	if (pkt->p_verbose)
		fprintf(pkt->p_stdout,"%s\n",str);
	ap = &pkt->p_apply[n];
	switch(ap->a_code) {

	case EMPTY:
		if (ch == INCLUDE)
			condset(ap,APPLY,INCLUSER);
		else
			condset(ap,NOAPPLY,EXCLUSER);
		break;
	case APPLY:
		sid_ba(sidp,str);
D 10
		fatal(sprintf(Error,"%s already included (ge9)",str));
E 10
I 10
		sprintf(Error,"%s already included (ge9)",str);
		fatal(Error);
E 10
		break;
	case NOAPPLY:
		sid_ba(sidp,str);
D 10
		fatal(sprintf(Error,"%s already excluded (ge10)",str));
E 10
I 10
		sprintf(Error,"%s already excluded (ge10)",str);
		fatal(Error);
E 10
		break;
	default:
		fatal("internal error in get/enter() (ge11)");
		break;
	}
}


gen_lfile(pkt)
register struct packet *pkt;
{
	int n;
	int reason;
	char str[32];
	char line[BUFSIZ];
	struct deltab dt;
	FILE *in;
	FILE *out;

	in = xfopen(pkt->p_file,0);
	if (*pkt->p_lfile)
		out = stdout;
	else
		out = xfcreat(auxf(pkt->p_file,'l'),0444);
	fgets(line,sizeof(line),in);
	while (fgets(line,sizeof(line),in) != NULL && line[0] == CTLCHAR && line[1] == STATS) {
		fgets(line,sizeof(line),in);
		del_ab(line,&dt);
		if (dt.d_type == 'D') {
			reason = pkt->p_apply[dt.d_serial].a_reason;
			if (pkt->p_apply[dt.d_serial].a_code == APPLY) {
				putc(' ',out);
				putc(' ',out);
			}
			else {
				putc('*',out);
				if (reason & IGNR)
					putc(' ',out);
				else
					putc('*',out);
			}
			switch (reason & (INCL | EXCL | CUTOFF)) {
	
			case INCL:
				putc('I',out);
				break;
			case EXCL:
				putc('X',out);
				break;
			case CUTOFF:
				putc('C',out);
				break;
			default:
				putc(' ',out);
				break;
			}
			putc(' ',out);
			sid_ba(&dt.d_sid,str);
			fprintf(out,"%s\t",str);
			date_ba(&dt.d_datetime,str);
			fprintf(out,"%s %s\n",str,dt.d_pgmr);
		}
		while ((n = fgets(line,sizeof(line),in)) != NULL)
			if (line[0] != CTLCHAR)
				break;
			else {
				switch (line[1]) {

				case EDELTAB:
					break;
				default:
					continue;
				case MRNUM:
				case COMMENTS:
					if (dt.d_type == 'D')
						fprintf(out,"\t%s",&line[3]);
					continue;
				}
				break;
			}
		if (n == NULL || line[0] != CTLCHAR)
			break;
		putc('\n',out);
	}
	fclose(in);
	if (out != stdout)
		fclose(out);
}

D 8

E 8
D 12
char	Curdate[18];
E 12
I 12
char	Curdate[20];
E 12
char	*Curtime;
D 12
char	Gdate[9];
char	Chgdate[18];
E 12
I 12
char	Gdate[11];
char	Chgdate[20];
E 12
char	*Chgtime;
D 12
char	Gchgdate[9];
E 12
I 12
char	Gchgdate[11];
E 12
I 8
char	Qchgdate[30];
E 8
char	Sid[32];
D 5
char	Mod[16];
E 5
I 5
D 7
char	Mod[MAXNAMLEN + 3];		/* should be as large as Gfile? */
E 7
E 5
D 8
char	Olddir[BUFSIZ];
char	Pname[BUFSIZ];
char	Dir[BUFSIZ];
E 8
I 8
char	Olddir[MAXPATHLEN+1];
char	Pname[MAXPATHLEN+1];
char	Dir[MAXPATHLEN+1];
E 8

idsetup(pkt)
register struct packet *pkt;
{
	extern long Timenow;
	register int n;
	register char *p;

	date_ba(&Timenow,Curdate);
D 12
	Curtime = &Curdate[9];
	Curdate[8] = 0;
E 12
I 12
	Curtime = &Curdate[11];
	Curdate[10] = 0;
E 12
	copy(pkt->p_file,Dir);
	dname(Dir);
D 8
	if(curdir(Olddir) != 0)
		fatal("curdir failed (ge20)");
E 8
I 8
	if(getwd(Olddir) == 0)
		fatal("getwd failed (ge20)");
E 8
	if(chdir(Dir) != 0)
		fatal("cannot change directory (ge22)");
D 8
	if(curdir(Pname) != 0)
		fatal("curdir failed (ge21)");
E 8
I 8
	if(getwd(Pname) == 0)
		fatal("getwd failed (ge21)");
E 8
	if(chdir(Olddir) != 0)
		fatal("cannot change directory (ge23)");
	makgdate(Curdate,Gdate);
	for (n = maxser(pkt); n; n--)
		if (pkt->p_apply[n].a_code == APPLY)
			break;
	if (n)
		date_ba(&pkt->p_idel[n].i_datetime,Chgdate);
D 12
	Chgtime = &Chgdate[9];
	Chgdate[8] = 0;
E 12
I 12
	Chgtime = &Chgdate[11];
	Chgdate[10] = 0;
E 12
	makgdate(Chgdate,Gchgdate);
I 8
	makqdate(Gchgdate,Qchgdate);
E 8
	sid_ba(&pkt->p_gotsid,Sid);
	if (p = Sflags[MODFLAG - 'a'])
		copy(p,Mod);
	else
		copy(Gfile,Mod);
}


makgdate(old,new)
register char *old, *new;
{
D 12
	if ((*new = old[3]) != '0')
E 12
I 12
	if ((*new = old[5]) != '0')
E 12
		new++;
D 12
	*new++ = old[4];
E 12
I 12
	*new++ = old[6];
E 12
	*new++ = '/';
D 12
	if ((*new = old[6]) != '0')
E 12
I 12
	if ((*new = old[8]) != '0')
E 12
		new++;
D 12
	*new++ = old[7];
E 12
I 12
	*new++ = old[9];
E 12
	*new++ = '/';
	*new++ = old[0];
	*new++ = old[1];
I 12
	*new++ = old[2];
	*new++ = old[3];
E 12
	*new = 0;
}

I 8
makqdate(old,new)
register char *old, *new;
{
	static	char *months[12] =
	    { "January", "February", "March", "April", "May", "June", "July",
	      "August", "September", "October", "November", "December" };
E 8

I 8
	strcpy(new, months[atoi(old)-1]);
	while (*new != '\0')
		new++;
	while (*old++ != '/')
		;
	*new++ = ' ';
	*new++ = *old++;
	if (*old != '/')
		*new++ = *old++;
I 11
	old++;
E 11
	*new++ = ',';
	*new++ = ' ';
D 11
	*new++ = '1'; *new++ = '9';	/* works for this century at least */
	*new++ = *++old;
	*new++ = *++old;
E 11
I 11
D 12
	if (*old >= '7') {
		*new++ = '1';
		*new++ = '9';
	} else {
		*new++ = '2';
		*new++ = '0';
	}
E 12
I 12
	*new++ = *old++;
	*new++ = *old++;
E 12
	*new++ = *old++;
	*new++ = *old++;
E 11
	*new = '\0';
}

E 8
D 9
static char Zkeywd[5]	"@(#)";
E 9
I 9
static char Zkeywd[5] = "@(#)";
E 9

I 8

E 8
idsubst(pkt,line)
register struct packet *pkt;
char line[];
{
	static char tline[BUFSIZ];
	static char str[32];
	register char *lp, *tp;
	extern char *Type;
	extern char *Sflags[];

D 7
	if (HADK || !any('%',line))
		return(line);

E 7
	tp = tline;
	for(lp=line; *lp != 0; lp++) {
		if(lp[0] == '%' && lp[1] != 0 && lp[2] == '%') {
			switch(*++lp) {

			case 'M':
				tp = trans(tp,Mod);
				break;
			case 'R':
				sprintf(str,"%u",pkt->p_gotsid.s_rel);
				tp = trans(tp,str);
				break;
			case 'L':
				sprintf(str,"%u",pkt->p_gotsid.s_lev);
				tp = trans(tp,str);
				break;
			case 'B':
				sprintf(str,"%u",pkt->p_gotsid.s_br);
				tp = trans(tp,str);
				break;
			case 'S':
				sprintf(str,"%u",pkt->p_gotsid.s_seq);
				tp = trans(tp,str);
				break;
			case 'D':
				tp = trans(tp,Curdate);
				break;
			case 'H':
				tp = trans(tp,Gdate);
				break;
			case 'T':
				tp = trans(tp,Curtime);
				break;
			case 'E':
				tp = trans(tp,Chgdate);
				break;
			case 'G':
				tp = trans(tp,Gchgdate);
				break;
I 8
			case 'Q':
				tp = trans(tp,Qchgdate);
				break;
E 8
			case 'U':
				tp = trans(tp,Chgtime);
				break;
			case 'Z':
				tp = trans(tp,Zkeywd);
				break;
			case 'Y':
				tp = trans(tp,Type);
				break;
			case 'W':
				tp = trans(tp,Zkeywd);
				tp = trans(tp,Mod);
				*tp++ = '\t';
			case 'I':
				tp = trans(tp,Sid);
				break;
			case 'P':
				tp = trans(tp,Pname);
				*tp++ = '/';
				tp = trans(tp,(sname(pkt->p_file)));
				break;
			case 'F':
				tp = trans(tp,pkt->p_file);
				break;
			case 'C':
				sprintf(str,"%u",pkt->p_glnno);
				tp = trans(tp,str);
				break;
			case 'A':
				tp = trans(tp,Zkeywd);
				tp = trans(tp,Type);
				*tp++ = ' ';
				tp = trans(tp,Mod);
				*tp++ = ' ';
				tp = trans(tp,Sid);
				tp = trans(tp,Zkeywd);
				break;
			default:
				*tp++ = '%';
				*tp++ = *lp;
				continue;
			}
			lp++;
		}
		else
			*tp++ = *lp;
	}

	*tp = 0;
	return(tline);
}


trans(tp,str)
register char *tp, *str;
{
	Did_id = 1;
	while(*tp++ = *str++)
		;
	return(tp-1);
D 7
}


prfx(pkt)
register struct packet *pkt;
{
	char str[32];

	if (HADN)
		fprintf(pkt->p_gout,"%s\t",Mod);
	if (HADM) {
		sid_ba(&pkt->p_inssid,str);
		fprintf(pkt->p_gout,"%s\t",str);
	}
E 7
}


clean_up(n)
{
	if (gpkt.p_file[0])
		unlockit(auxf(gpkt.p_file,'z'),getpid());
	if (gpkt.p_iop)
		fclose(gpkt.p_iop);
	xfreeall();
}


wrtpfile(pkt,inc,exc)
register struct packet *pkt;
char *inc, *exc;
{
	char line[64], str1[32], str2[32];
	char *user;
	FILE *in, *out;
	struct pfile pf;
	register char *p;
	int fd;
	int i;
	extern long Timenow;

	user = logname();
	if (lockit(auxf(pkt->p_file,'z'),2,getpid()))
		fatal("cannot create lock file (cm4)");
	if (exists(p = auxf(pkt->p_file,'p'))) {
		fd = xopen(p,2);
D 8
		in = fdfopen(fd,0);
E 8
I 8
		in = fdopen(fd,"r");
E 8
		while (fgets(line,sizeof(line),in) != NULL) {
			p = line;
			p[length(p) - 1] = 0;
			pf_ab(p,&pf,0);
			if ((pf.pf_gsid.s_rel == pkt->p_gotsid.s_rel &&
				pf.pf_gsid.s_lev == pkt->p_gotsid.s_lev &&
				pf.pf_gsid.s_br == pkt->p_gotsid.s_br &&
				pf.pf_gsid.s_seq == pkt->p_gotsid.s_seq) ||
				(pf.pf_nsid.s_rel == pkt->p_reqsid.s_rel &&
				pf.pf_nsid.s_lev == pkt->p_reqsid.s_lev &&
				pf.pf_nsid.s_br == pkt->p_reqsid.s_br &&
				pf.pf_nsid.s_seq == pkt->p_reqsid.s_seq)) {
				fclose(in);
D 10
				fatal(sprintf(Error,"being edited: `%s' (ge17)",
					line));
E 10
I 10
				sprintf(Error,"being edited: `%s' (ge17)",line);
				fatal(Error);
E 10
				}
			if (!equal(pf.pf_user,user))
				fprintf(stderr,"WARNING: being edited: `%s' (ge18)\n",line);
		}
D 8
		out = fdfopen(dup(fd),1);
E 8
I 8
		out = fdopen(dup(fd),"w");
E 8
		fclose(in);
	}
	else
D 3
		out = xfcreat(p,0644);
E 3
I 3
		out = xfcreat(p,0666);
E 3
	fseek(out,0L,2);
	sid_ba(&pkt->p_gotsid,str1);
	sid_ba(&pkt->p_reqsid,str2);
	date_ba(&Timenow,line);
	fprintf(out,"%s %s %s %s",str1,str2,user,line);
	if (inc)
		fprintf(out," -i%s",inc);
	if (exc)
		fprintf(out," -x%s",exc);
	fprintf(out,"\n");
	fclose(out);
	if (pkt->p_verbose)
		fprintf(pkt->p_stdout,"new delta %s\n",str2);
	unlockit(auxf(pkt->p_file,'z'),getpid());
}


getser(pkt)
register struct packet *pkt;
{
	register struct idel *rdp;
	int n, ser, def;
	char *p;
	extern char *Sflags[];

	def = 0;
	if (pkt->p_reqsid.s_rel == 0) {
		if (p = Sflags[DEFTFLAG - 'a'])
			chksid(sid_ab(p, &pkt->p_reqsid), &pkt->p_reqsid);
		else {
			pkt->p_reqsid.s_rel = MAX;
			def = 1;
		}
	}
	ser = 0;
	if (pkt->p_reqsid.s_lev == 0) {
		for (n = maxser(pkt); n; n--) {
			rdp = &pkt->p_idel[n];
			if ((rdp->i_sid.s_br == 0 || HADT) &&
				pkt->p_reqsid.s_rel >= rdp->i_sid.s_rel &&
				rdp->i_sid.s_rel > pkt->p_gotsid.s_rel) {
					ser = n;
					pkt->p_gotsid.s_rel = rdp->i_sid.s_rel;
			}
		}
	}
	else if (pkt->p_reqsid.s_br && pkt->p_reqsid.s_seq == 0) {
		for (n = maxser(pkt); n; n--) {
			rdp = &pkt->p_idel[n];
			if (rdp->i_sid.s_rel == pkt->p_reqsid.s_rel &&
				rdp->i_sid.s_lev == pkt->p_reqsid.s_lev &&
				rdp->i_sid.s_br == pkt->p_reqsid.s_br)
					break;
		}
		ser = n;
	}
	else {
		ser = sidtoser(&pkt->p_reqsid,pkt);
	}
	if (ser == 0)
		fatal("nonexistent sid (ge5)");
	rdp = &pkt->p_idel[ser];
D 8
	move(&rdp->i_sid, &pkt->p_gotsid, sizeof(pkt->p_gotsid));
E 8
I 8
	bcopy(&rdp->i_sid, &pkt->p_gotsid, sizeof(pkt->p_gotsid));
E 8
	if (def || (pkt->p_reqsid.s_lev == 0 && pkt->p_reqsid.s_rel == pkt->p_gotsid.s_rel))
D 8
		move(&pkt->p_gotsid, &pkt->p_reqsid, sizeof(pkt->p_gotsid));
E 8
I 8
		bcopy(&pkt->p_gotsid, &pkt->p_reqsid, sizeof(pkt->p_gotsid));
E 8
	return(ser);
}


/* Null routine to satisfy external reference from dodelt() */

escdodelt()
{
}
E 1
