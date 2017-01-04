h52079
s 00032/00032/00406
d D 4.6 88/04/24 15:08:37 bostic 6 5
c fixes for ANSI C
e
s 00020/00007/00418
d D 4.5 87/09/16 15:09:06 bostic 5 4
c sh -ce exits too soon; bug report 4.3BSD/bin/76
e
s 00001/00001/00424
d D 4.4 87/01/11 15:00:11 sam 4 3
c syntax error (from  casey)
e
s 00003/00001/00422
d D 4.3 83/08/11 20:20:37 sam 3 2
c standardize sccs keyword lines
e
s 00001/00001/00422
d D 4.2 83/02/09 14:29:16 sam 2 1
c stuff from sun
e
s 00423/00000/00000
d D 4.1 82/05/07 19:39:52 mckusick 1 0
c date and time created 82/05/07 19:39:52 by mckusick
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 3

#
/*
 * UNIX shell
 *
 * S. R. Bourne
 * Bell Telephone Laboratories
 *
 */

#include	"defs.h"
#include	"sym.h"

LOCAL INT	parent;

SYSTAB		commands;



/* ========	command execution	========*/


execute(argt, execflg, pf1, pf2)
	TREPTR		argt;
	INT		*pf1, *pf2;
{
	/* `stakbot' is preserved by this routine */
	REG TREPTR	t;
	STKPTR		sav=savstak();

	sigchk();

	IF (t=argt) ANDF execbrk==0
	THEN	REG INT		treeflgs;
		INT		oldexit, type;
		REG STRING	*com;

		treeflgs = t->tretyp; type = treeflgs&COMMSK;
		oldexit=exitval; exitval=0;

		SWITCH type IN

		case TCOM:
			BEGIN
			STRING		a1;
			INT		argn, internal;
			ARGPTR		schain=gchain;
D 6
			IOPTR		io=t->treio;
E 6
I 6
			IOPTR		io=t->treio.treio;
E 6
			gchain=0;
			argn = getarg(t);
			com=scan(argn);
			a1=com[1]; gchain=schain;

D 2
			IF (internal=syslook(com[0],commands)) ORF argn==0
E 2
I 2
			IF argn==0 ORF (internal=syslook(com[0],commands))
E 2
D 6
			THEN	setlist(t->comset, 0);
E 6
I 6
			THEN	setlist(t->comnod.comset, 0);
E 6
			FI

			IF argn ANDF (flags&noexec)==0
			THEN	/* print command if execpr */
				IF flags&execpr
				THEN	argn=0;	prs(execpmsg);
					WHILE com[argn]!=ENDARGS
					DO prs(com[argn++]); blank() OD
					newline();
				FI

				SWITCH internal IN

				case SYSDOT:
					IF a1
					THEN	REG INT		f;
	
						IF (f=pathopen(getpath(a1), a1)) < 0
						THEN failed(a1,notfound);
						ELSE execexp(0,f);
						FI
					FI
					break;
	
				case SYSTIMES:
					{
					L_INT	t[4]; times(t);
					prt(t[2]); blank(); prt(t[3]); newline();
					}
					break;
	
				case SYSEXIT:
					exitsh(a1?stoi(a1):oldexit);
	
				case SYSNULL:
					io=0;
					break;
	
				case SYSCONT:
					execbrk = -loopcnt; break;
	
				case SYSBREAK:
					IF (execbrk=loopcnt) ANDF a1
					THEN breakcnt=stoi(a1);
					FI
					break;
	
				case SYSTRAP:
					IF a1
					THEN	BOOL	clear;
						IF (clear=digit(*a1))==0
						THEN	++com;
						FI
						WHILE *++com
						DO INT	i;
						   IF (i=stoi(*com))>=MAXTRAP ORF i<MINTRAP
						   THEN	failed(*com,badtrap);
						   ELIF clear
						   THEN	clrsig(i);
						   ELSE	replace(&trapcom[i],a1);
							IF *a1
							THEN	getsig(i);
							ELSE	ignsig(i);
							FI
						   FI
						OD
					ELSE	/* print out current traps */
						INT		i;
	
						FOR i=0; i<MAXTRAP; i++
						DO IF trapcom[i]
						   THEN	prn(i); prs(colon); prs(trapcom[i]); newline();
						   FI
						OD
					FI
					break;
	
				case SYSEXEC:
					com++;
					initio(io); ioset=0; io=0;
					IF a1==0 THEN break FI
	
				case SYSLOGIN:
					flags |= forked;
					oldsigs(); execa(com); done();
	
				case SYSCD:
					IF flags&rshflg
					THEN	failed(com[0],restricted);
					ELIF (a1==0 ANDF (a1=homenod.namval)==0) ORF chdir(a1)<0
					THEN	failed(a1,baddir);
					FI
					break;
	
				case SYSSHFT:
					IF dolc<1
					THEN	error(badshift);
					ELSE	dolv++; dolc--;
					FI
					assnum(&dolladr, dolc);
					break;
	
				case SYSWAIT:
					await(-1);
					break;
	
				case SYSREAD:
					exitval=readvar(&com[1]);
					break;

/*
				case SYSTST:
					exitval=testcmd(com);
					break;
*/

				case SYSSET:
					IF a1
					THEN	INT	argc;
						argc = options(argn,com);
						IF argc>1
						THEN	setargs(com+argn-argc);
						FI
D 6
					ELIF t->comset==0
E 6
I 6
					ELIF t->comnod.comset==0
E 6
					THEN	/*scan name chain and print*/
						namscan(printnam);
					FI
					break;
	
				case SYSRDONLY:
					exitval=N_RDONLY;
				case SYSXPORT:
					IF exitval==0 THEN exitval=N_EXPORT; FI
	
					IF a1
					THEN	WHILE *++com
						DO attrib(lookup(*com), exitval) OD
					ELSE	namscan(printflg);
					FI
					exitval=0;
					break;
	
				case SYSEVAL:
					IF a1
					THEN	execexp(a1,&com[2]);
					FI
					break;

                                case SYSUMASK:
                                        if (a1) {
D 4
                                                int c, i
E 4
I 4
                                                int c, i;
E 4
                                                i = 0;
                                                while ((c = *a1++) >= '0' &&
                                                        c <= '7')
                                                        i = (i << 3) + c - '0';
                                                umask(i);
                                        } else {
                                                int i, j;
                                                umask(i = umask(0));
                                                prc('0');
                                                for (j = 6; j >= 0; j -= 3)
                                                        prc(((i>>j)&07) + '0');
                                                newline();
                                        }
                                        break;
	
				default:
					internal=builtin(argn,com);
	
				ENDSW

				IF internal
				THEN	IF io THEN error(illegal) FI
					chktrap();
					break;
				FI
D 6
			ELIF t->treio==0
E 6
I 6
			ELIF t->treio.treio==0
E 6
			THEN	break;
			FI
			END
	
		case TFORK:
			IF execflg ANDF (treeflgs&(FAMP|FPOU))==0
			THEN	parent=0;
			ELSE	WHILE (parent=fork()) == -1
				DO sigchk(); alarm(10); pause() OD
			FI

			IF parent
			THEN	/* This is the parent branch of fork;    */
				/* it may or may not wait for the child. */
				IF treeflgs&FPRS ANDF flags&ttyflg
				THEN	prn(parent); newline();
				FI
				IF treeflgs&FPCL THEN closepipe(pf1) FI
				IF (treeflgs&(FAMP|FPOU))==0
				THEN	await(parent);
				ELIF (treeflgs&FAMP)==0
				THEN	post(parent);
				ELSE	assnum(&pcsadr, parent);
				FI

				chktrap();
				break;


			ELSE	/* this is the forked branch (child) of execute */
				flags |= forked; iotemp=0;
				postclr();
				settmp();

				/* Turn off INTR and QUIT if `FINT'  */
				/* Reset ramaining signals to parent */
				/* except for those `lost' by trap   */
				oldsigs();
				IF treeflgs&FINT
				THEN	signal(INTR,1); signal(QUIT,1);
				FI

				/* pipe in or out */
				IF treeflgs&FPIN
				THEN	rename(pf1[INPIPE],0);
					close(pf1[OTPIPE]);
				FI
				IF treeflgs&FPOU
				THEN	rename(pf2[OTPIPE],1);
					close(pf2[INPIPE]);
				FI

				/* default std input for & */
				IF treeflgs&FINT ANDF ioset==0
				THEN	rename(chkopen(devnull),0);
				FI

				/* io redirection */
D 6
				initio(t->treio);
E 6
I 6
				initio(t->treio.treio);
E 6
				IF type!=TCOM
D 6
				THEN	execute(t->forktre,1);
E 6
I 6
				THEN	execute(t->forknod.forktre,1);
E 6
				ELIF com[0]!=ENDARGS
D 6
				THEN	setlist(t->comset,N_EXPORT);
E 6
I 6
				THEN	setlist(t->comnod.comset,N_EXPORT);
E 6
					execa(com);
				FI
				done();
			FI

		case TPAR:
			rename(dup(2),output);
D 6
			execute(t->partre,execflg);
E 6
I 6
			execute(t->parnod.partre,execflg);
E 6
			done();

		case TFIL:
			BEGIN
			   INT pv[2]; chkpipe(pv);
D 6
			   IF execute(t->lstlef, 0, pf1, pv)==0
			   THEN	execute(t->lstrit, execflg, pv, pf2);
E 6
I 6
			   IF execute(t->lstnod.lstlef, 0, pf1, pv)==0
			   THEN	execute(t->lstnod.lstrit, execflg, pv, pf2);
E 6
			   ELSE	closepipe(pv);
			   FI
			END
			break;

		case TLST:
D 6
			execute(t->lstlef,0);
			execute(t->lstrit,execflg);
E 6
I 6
			execute(t->lstnod.lstlef,0);
			execute(t->lstnod.lstrit,execflg);
E 6
			break;

		case TAND:
D 6
			IF execute(t->lstlef,0)==0
			THEN	execute(t->lstrit,execflg);
E 6
I 6
			IF execute(t->lstnod.lstlef,0)==0
			THEN	execute(t->lstnod.lstrit,execflg);
E 6
			FI
			break;

		case TORF:
D 6
			IF execute(t->lstlef,0)!=0
			THEN	execute(t->lstrit,execflg);
E 6
I 6
			IF execute(t->lstnod.lstlef,0)!=0
			THEN	execute(t->lstnod.lstrit,execflg);
E 6
			FI
			break;

		case TFOR:
			BEGIN
D 6
			   NAMPTR	n = lookup(t->fornam);
E 6
I 6
			   NAMPTR	n = lookup(t->fornod.fornam);
E 6
			   STRING	*args;
			   DOLPTR	argsav=0;

D 6
			   IF t->forlst==0
E 6
I 6
			   IF t->fornod.forlst==0
E 6
			   THEN    args=dolv+1;
				   argsav=useargs();
			   ELSE	   ARGPTR	schain=gchain;
				   gchain=0;
D 6
				   trim((args=scan(getarg(t->forlst)))[0]);
E 6
I 6
				   trim((args=scan(getarg(t->fornod.forlst)))[0]);
E 6
				   gchain=schain;
			   FI
			   loopcnt++;
			   WHILE *args!=ENDARGS ANDF execbrk==0
			   DO	assign(n,*args++);
D 6
				execute(t->fortre,0);
E 6
I 6
				execute(t->fornod.fortre,0);
E 6
				IF execbrk<0 THEN execbrk=0 FI
			   OD
			   IF breakcnt THEN breakcnt-- FI
			   execbrk=breakcnt; loopcnt--;
			   argfor=freeargs(argsav);
			END
			break;

		case TWH:
		case TUN:
			BEGIN
D 5
			   INT		i=0;
E 5
I 5
			   INT		i=0, saveflg;
E 5

I 5
			   saveflg = flags&errflg;
E 5
			   loopcnt++;
D 5
			   WHILE execbrk==0 ANDF (execute(t->whtre,0)==0)==(type==TWH)
			   DO i=execute(t->dotre,0);
E 5
I 5
			   WHILE execbrk==0
			   DO flags &= ~errflg;
D 6
			      i=execute(t->whtre,0);
E 6
I 6
			      i=execute(t->whnod.whtre,0);
E 6
			      flags |= saveflg;
			      IF (i==0)!=(type==TWH) THEN break FI
D 6
			      i=execute(t->dotre,0);
E 6
I 6
			      i=execute(t->whnod.dotre,0);
E 6
E 5
			      IF execbrk<0 THEN execbrk=0 FI
			   OD
			   IF breakcnt THEN breakcnt-- FI
			   execbrk=breakcnt; loopcnt--; exitval=i;
			END
			break;

		case TIF:
D 5
			IF execute(t->iftre,0)==0
			THEN	execute(t->thtre,execflg);
			ELSE	execute(t->eltre,execflg);
			FI
E 5
I 5
			BEGIN
			   INT		i, saveflg;

			   saveflg = flags&errflg;
			   flags &= ~errflg;
D 6
			   i=execute(t->iftre,0);
E 6
I 6
			   i=execute(t->ifnod.iftre,0);
E 6
			   flags |= saveflg;
			   IF i==0
D 6
			   THEN	execute(t->thtre,execflg);
			   ELSE	execute(t->eltre,execflg);
E 6
I 6
			   THEN	execute(t->ifnod.thtre,execflg);
			   ELSE	execute(t->ifnod.eltre,execflg);
E 6
			   FI
			END
E 5
			break;

		case TSW:
			BEGIN
D 6
			   REG STRING	r = mactrim(t->swarg);
			   t=t->swlst;
			   WHILE t
			   DO	ARGPTR		rex=t->regptr;
E 6
I 6
			   REG STRING	r = mactrim(t->swnod.swarg);
			   REG REGPTR	eg = t->swnod.swlst;
			   WHILE eg
			   DO	ARGPTR		rex=eg->regptr;
E 6
				WHILE rex
				DO	REG STRING	s;
					IF gmatch(r,s=macro(rex->argval)) ORF (trim(s), eq(r,s))
D 6
					THEN	execute(t->regcom,0);
						t=0; break;
E 6
I 6
					THEN	execute(eg->regcom,0);
						eg=0; break;
E 6
					ELSE	rex=rex->argnxt;
					FI
				OD
D 6
				IF t THEN t=t->regnxt FI
E 6
I 6
				IF eg THEN eg=eg->regnxt FI
E 6
			   OD
			END
			break;
		ENDSW
		exitset();
	FI

	sigchk();
	tdystak(sav);
	return(exitval);
}


execexp(s,f)
	STRING		s;
	UFD		f;
{
	FILEBLK		fb;
	push(&fb);
	IF s
	THEN	estabf(s); fb.feval=f;
	ELIF f>=0
	THEN	initf(f);
	FI
	execute(cmd(NL, NLFLG|MTFLG),0);
	pop();
}
E 1
