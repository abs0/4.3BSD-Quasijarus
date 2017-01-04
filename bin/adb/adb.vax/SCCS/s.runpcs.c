h39527
s 00008/00006/00312
d D 4.6 85/04/25 20:13:44 sam 6 5
c we have the entire instruction, so no need to do read-modify-write when resetting breakpoints
e
s 00013/00013/00305
d D 4.5 84/10/13 19:36:54 sam 5 4
c use definitions in <ptrace.h>
e
s 00000/00002/00318
d D 4.4 83/10/27 16:39:46 ralph 4 3
c no longer strips first char of arguments to :r command
e
s 00003/00002/00317
d D 4.3 83/08/11 20:01:42 sam 3 2
c fix sccs keyword lines
e
s 00028/00007/00291
d D 4.2 82/10/28 14:40:17 rrh 2 1
c Changes per David Mosher: allow space and tab around '<' and '>' on
c output redirection specification when starting a process up.
e
s 00298/00000/00000
d D 4.1 81/05/14 15:19:57 root 1 0
c date and time created 81/05/14 15:19:57 by root
e
u
U
t
T
I 1
D 3
#
E 3
I 3
#ifndef lint
static	char sccsid[] = "%W% %G%";
#endif
E 3
/*
 *
 *	UNIX debugger
 *
 */

#include "defs.h"
D 3
static	char sccsid[] = "%Z%%M% %I% %G%";
E 3

extern	MAP	txtmap;

MSG		NOFORK;
MSG		ENDPCS;
MSG		BADWAIT;

CHAR		*lp;
ADDR		sigint;
ADDR		sigqit;

/* breakpoints */
BKPTR		bkpthead;

REGLIST		reglist[];

CHAR		lastc;

INT		fcor;
INT		fsym;
STRING		errflg;
INT		errno;
INT		signo;
INT		sigcode;

L_INT		dot;
STRING		symfil;
INT		wtflag;
L_INT		pid;
L_INT		expv;
INT		adrflg;
L_INT		loopcnt;





/* service routines for sub process control */

getsig(sig)
{	return(expr(0) ? expv : sig);
}

ADDR userpc = 1;

runpcs(runmode,execsig)
{
	INT		rc;
	REG BKPTR	bkpt;
	IF adrflg THEN userpc=dot; FI
	printf("%s: running\n", symfil);

	WHILE --loopcnt>=0
	DO
#ifdef DEBUG
		printf("\ncontinue %x %d\n",userpc,execsig);
#endif
		IF runmode==SINGLE
		THEN delbp(); /* hardware handles single-stepping */
		ELSE /* continuing from a breakpoint is hard */
			IF bkpt=scanbkpt(userpc)
			THEN execbkpt(bkpt,execsig); execsig=0;
			FI
			setbp();
		FI
		ptrace(runmode,pid,userpc,execsig);
		bpwait(); chkerr(); execsig=0; delbp(); readregs();

		IF (signo==0) ANDF (bkpt=scanbkpt(userpc))
		THEN /* stopped by BPT instruction */
#ifdef DEBUG
			printf("\n BPT code; '%s'%o'%o'%d",
				bkpt->comm,bkpt->comm[0],EOR,bkpt->flag);
#endif
			dot=bkpt->loc;
			IF bkpt->flag==BKPTEXEC
			ORF ((bkpt->flag=BKPTEXEC)
				ANDF bkpt->comm[0]!=EOR
				ANDF command(bkpt->comm,':')
				ANDF --bkpt->count)
			THEN execbkpt(bkpt,execsig); execsig=0; loopcnt++;
			ELSE bkpt->count=bkpt->initcnt; rc=1;
			FI
		ELSE execsig=signo; rc=0;
		FI
	OD
	return(rc);
}

#define BPOUT 0
#define BPIN 1
INT bpstate = BPOUT;

endpcs()
{
	REG BKPTR	bkptr;
	IF pid
D 5
	THEN ptrace(EXIT,pid,0,0); pid=0; userpc=1;
E 5
I 5
	THEN ptrace(PT_KILL,pid,0,0); pid=0; userpc=1;
E 5
	     FOR bkptr=bkpthead; bkptr; bkptr=bkptr->nxtbkpt
	     DO IF bkptr->flag
		THEN bkptr->flag=BKPTSET;
		FI
	     OD
	FI
	bpstate=BPOUT;
}

#ifdef VFORK
nullsig()
{

}
#endif

setup()
{
	close(fsym); fsym = -1;
#ifndef VFORK
	IF (pid = fork()) == 0
#else
	IF (pid = vfork()) == 0
#endif
D 5
	THEN ptrace(SETTRC,0,0,0);
E 5
I 5
	THEN ptrace(PT_TRACE_ME,0,0,0);
E 5
#ifdef VFORK
	     signal(SIGTRAP,nullsig);
#endif
	     signal(SIGINT,sigint); signal(SIGQUIT,sigqit);
	     doexec(); exit(0);
	ELIF pid == -1
	THEN error(NOFORK);
	ELSE bpwait(); readregs(); lp[0]=EOR; lp[1]=0;
	     fsym=open(symfil,wtflag);
	     IF errflg
	     THEN printf("%s: cannot execute\n",symfil);
		  endpcs(); error(0);
	     FI
	FI
	bpstate=BPOUT;
}

execbkpt(bkptr,execsig)
BKPTR	bkptr;
{
#ifdef DEBUG
	printf("exbkpt: %d\n",bkptr->count);
#endif
	delbp();
D 5
	ptrace(SINGLE,pid,bkptr->loc,execsig);
E 5
I 5
	ptrace(PT_STEP,pid,bkptr->loc,execsig);
E 5
	bkptr->flag=BKPTSET;
	bpwait(); chkerr(); readregs();
}


doexec()
{
	STRING		argl[MAXARG];
	CHAR		args[LINSIZ];
	STRING		p, *ap, filnam;
	extern STRING environ;
	ap=argl; p=args;
	*ap++=symfil;
	REP	IF rdc()==EOR THEN break; FI
		*ap = p;
D 2
		WHILE lastc!=EOR ANDF lastc!=SP ANDF lastc!=TB DO *p++=lastc; readchar(); OD
		*p++=0; filnam = *ap+1;
		IF **ap=='<'
		THEN	close(0);
E 2
I 2
		/*
		 * First thing is to look for direction characters
		 * and get filename.  Do not use up the args for filenames.
		 * Then get rid of spaces before next args.
		 */
		IF lastc=='<'
		THEN	REP readchar(); PER lastc==SP ORF lastc==TB DONE
			filnam = p;
			WHILE lastc!=EOR ANDF lastc!=SP ANDF lastc!=TB ANDF lastc!='>'
				DO *p++=lastc; readchar(); OD
			*p = 0;
			close(0);
E 2
			IF open(filnam,0)<0
			THEN	printf("%s: cannot open\n",filnam); _exit(0);
			FI
D 2
		ELIF **ap=='>'
		THEN	close(1);
E 2
I 2
			p = *ap;
		ELIF lastc=='>'
		THEN	REP readchar(); PER lastc==SP ORF lastc==TB DONE
			filnam = p;
			WHILE lastc!=EOR ANDF lastc!=SP ANDF lastc!=TB ANDF lastc!='<'
				DO *p++=lastc; readchar(); OD
			*p = '\0';
			close(1);
E 2
			IF creat(filnam,0666)<0
			THEN	printf("%s: cannot create\n",filnam); _exit(0);
			FI
D 2
		ELSE	ap++;
E 2
I 2
			p = *ap;
		ELSE	
			WHILE lastc!=EOR ANDF lastc!=SP ANDF lastc!=TB ANDF lastc!='>' ANDF lastc!='<'
				DO *p++=lastc; readchar(); OD
			*p++ = '\0';
	 		ap++;
E 2
		FI
I 2
D 4
		WHILE lastc==SP ORF lastc==TB DO readchar(); OD

E 4
E 2
	PER lastc!=EOR DONE
	*ap++=0;
	exect(symfil, argl, environ);
	perror(symfil);
}

BKPTR	scanbkpt(adr)
ADDR adr;
{
	REG BKPTR	bkptr;
	FOR bkptr=bkpthead; bkptr; bkptr=bkptr->nxtbkpt
	DO IF bkptr->flag ANDF bkptr->loc==adr
	   THEN break;
	   FI
	OD
	return(bkptr);
}

delbp()
{
	REG ADDR	a;
	REG BKPTR	bkptr;
	IF bpstate!=BPOUT
	THEN
		FOR bkptr=bkpthead; bkptr; bkptr=bkptr->nxtbkpt
		DO	IF bkptr->flag
			THEN a=bkptr->loc;
				IF a < txtmap.e1 THEN
D 5
				ptrace(WIUSER,pid,a,
					(bkptr->ins&0xFF)|(ptrace(RIUSER,pid,a,0)&~0xFF));
E 5
I 5
D 6
				ptrace(PT_WRITE_I,pid,a,
					(bkptr->ins&0xFF)|(ptrace(PT_READ_I,pid,a,0)&~0xFF));
E 6
I 6
					ptrace(PT_WRITE_I,pid,a,bkptr->ins);
E 6
E 5
				ELSE
D 5
				ptrace(WDUSER,pid,a,
					(bkptr->ins&0xFF)|(ptrace(RDUSER,pid,a,0)&~0xFF));
E 5
I 5
D 6
				ptrace(PT_WRITE_D,pid,a,
					(bkptr->ins&0xFF)|(ptrace(PT_READ_D,pid,a,0)&~0xFF));
E 6
I 6
					ptrace(PT_WRITE_D,pid,a,bkptr->ins);
E 6
E 5
				FI
			FI
		OD
		bpstate=BPOUT;
	FI
}

I 6
#ifdef vax
#define	SETBP(ins)	(BPT | ((ins) &~ 0xFF))
#endif

E 6
setbp()
{
	REG ADDR		a;
	REG BKPTR	bkptr;

	IF bpstate!=BPIN
	THEN
		FOR bkptr=bkpthead; bkptr; bkptr=bkptr->nxtbkpt
		DO IF bkptr->flag
		   THEN a = bkptr->loc;
			IF a < txtmap.e1 THEN
D 5
				bkptr->ins = ptrace(RIUSER, pid, a, 0);
				ptrace(WIUSER, pid, a, BPT | (bkptr->ins&~0xFF));
E 5
I 5
				bkptr->ins = ptrace(PT_READ_I, pid, a, 0);
D 6
				ptrace(PT_WRITE_I, pid, a, BPT | (bkptr->ins&~0xFF));
E 6
I 6
				ptrace(PT_WRITE_I, pid, a, SETBP(bkptr->ins));
E 6
E 5
			ELSE
D 5
				bkptr->ins = ptrace(RDUSER, pid, a, 0);
				ptrace(WDUSER, pid, a, BPT | (bkptr->ins&~0xFF));
E 5
I 5
				bkptr->ins = ptrace(PT_READ_D, pid, a, 0);
D 6
				ptrace(PT_WRITE_D, pid, a, BPT | (bkptr->ins&~0xFF));
E 6
I 6
				ptrace(PT_WRITE_D, pid, a, SETBP(bkptr->ins));
E 6
E 5
			FI
			IF errno
			THEN prints("cannot set breakpoint: ");
			     psymoff(bkptr->loc,ISYM,"\n");
			FI
		   FI
		OD
		bpstate=BPIN;
	FI
}

bpwait()
{
	REG ADDR w;
	ADDR stat;

	signal(SIGINT, 1);
	WHILE (w = wait(&stat))!=pid ANDF w != -1 DONE
	signal(SIGINT,sigint);
	IF w == -1
	THEN pid=0;
	     errflg=BADWAIT;
	ELIF (stat & 0177) != 0177
	THEN sigcode = 0;
	     IF signo = stat&0177
	     THEN sigprint();
	     FI
	     IF stat&0200
	     THEN prints(" - core dumped");
		  close(fcor);
		  setcor();
	     FI
	     pid=0;
	     errflg=ENDPCS;
	ELSE signo = stat>>8;
D 5
	     sigcode = ptrace(RUREGS, pid, &((struct user *)0)->u_code, 0);
E 5
I 5
	     sigcode = ptrace(PT_READ_U, pid, &((struct user *)0)->u_code, 0);
E 5
	     IF signo!=SIGTRAP
	     THEN sigprint();
	     ELSE signo=0;
	     FI
	     flushbuf();
	FI
}

readregs()
{
	/*get REG values from pcs*/
	REG i;
	FOR i=24; --i>=0; 
	DO *(ADDR *)(((ADDR)&u)+reglist[i].roffs) =
D 5
		    ptrace(RUREGS, pid, reglist[i].roffs, 0);
E 5
I 5
		    ptrace(PT_READ_U, pid, reglist[i].roffs, 0);
E 5
	OD
 	userpc= *(ADDR *)(((ADDR)&u)+PC);
}


E 1
