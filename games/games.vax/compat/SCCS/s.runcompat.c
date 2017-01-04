h57913
s 00065/00056/00184
d D 4.2 83/07/31 23:02:26 sam 3 2
c update to run under 4.2bsd; reformat to my style (or a reasonable 
c facimile thereof); major hacking on signal handling for 4.2 signal interface
e
s 00000/00000/00240
d D 4.1 82/05/12 11:14:02 rrh 2 1
c sync to release 4.1
e
s 00240/00000/00000
d D 1.1 82/05/12 11:03:26 rrh 1 0
c date and time created 82/05/12 11:03:26 by rrh
e
u
U
t
T
I 1
D 3
static char sccsid[] = "	%M%	%I%	%E%	";
E 3
I 3
static char sccsid[] = "%W% %E%";
E 3

D 3
#define FBSD
E 3
/*
D 3
 *	Compatability mode support under UNIX-32V
E 3
I 3
 *	Compatability mode support
E 3
 *	written by Art Wetzel during August 1979
 *	at the Interdisciplinary Dept of Information Science
 *	Room 711, LIS Bldg
 *	University of Pittsburgh
 *	Pittsburgh, Pa 15260
 *
 *	No claims are made on the completeness of the support of any
 *	of the systems simulated under this package
 */
I 3

E 3
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "defs.h"
#ifdef UNIX
#include "unixhdr.h"
#endif
#ifdef RT11
#include "rt11.h"
#endif
D 3
struct	stat	stat32v;
unsigned short regs[8];
unsigned long psl;
unsigned short *pc;
int incompat;
E 3
I 3

struct	stat stat32v;
u_short	regs[8];
u_long	psl;
u_short	*pc;
int	incompat;
E 3
char	*progname;
char	*nameend;
D 3
main(argc, argv, envp) int argc; char **argv, **envp; {
	if(argc < 2){
E 3
I 3

main(argc, argv, envp)
	int argc;
	char **argv, **envp;
{

	if (argc < 2) {
E 3
		fprintf(stderr,"Usage: %s [-rootdir] file args...\n",argv[0]);
		exit(1);
	}
	/* remember where the program name etc should go for using ps */
	progname = argv[0];
	nameend = envp[0]-1;
	argv++;
	/* set up alternate root directory if flagged for */
D 3
	if(*argv[0] == '-') {
		if(chroot(argv[0]+1)) {
E 3
I 3
	if (*argv[0] == '-') {
		if (chroot(argv[0]+1)) {
E 3
			fprintf(stderr,"Can't change root to %s\n",argv[0]+1);
			exit(-1);
		}
		argv++;
	}
	/* check out file stats of file to run */
D 3
	if(stat(argv[0], &stat32v)) {
E 3
I 3
	if (stat(argv[0], &stat32v)) {
E 3
		fprintf(stderr,"%s does not exist\n",argv[0]);
		exit(1);
	}
	/* a version of SETUID and SETGID file executions */
	/* the binary of this program should be SETUID root for this to work */
	/* requires nonstandard seteuid and setegid sys calls */
D 3
	if(!(stat32v.st_mode & S_ISGID) || setegid(stat32v.st_gid))
E 3
I 3
	if (!(stat32v.st_mode & S_ISGID) || setegid(stat32v.st_gid))
E 3
		/* if not SETGID file or error, drop back to real group */
		setgid(getgid());
D 3
	if(!(stat32v.st_mode & S_ISUID) || seteuid(stat32v.st_uid))
E 3
I 3
	if (!(stat32v.st_mode & S_ISUID) || seteuid(stat32v.st_uid))
E 3
		/* if not SETUID file or error, drop back to real uid */
		setuid(getuid());
#ifdef V6UNIX
	/* no umasks in version 6 */
	umask(0);
#endif
	/* go try to execute , passing along args and environment */
	execute(argv[0], argv, envp);
	/* only get here if execute fails */
	fprintf(stderr,"Execution failure on %s\n",argv[0]);
	exit(1);
}
D 3
execute(file, argv, envp) char *file, **argv, **envp; {
E 3
I 3

execute(file, argv, envp)
	char *file, **argv, **envp;
{
E 3
	int fd, n, tloadpt, dloadpt, tloadsize, dloadsize, stacksize;
	register short *p;
	extern illtrap();
	extern char **environ;
I 3

E 3
	/* file to run should be readable */
D 3
	if((fd = open(file, 0)) == -1) {
E 3
I 3
	if ((fd = open(file, 0)) == -1) {
E 3
		fprintf(stderr,"Can't open %s for read access\n",file);
		return(-1);
	}
#ifdef UNIX
D 3
	if((n = read(fd, &header, sizeof header)) != sizeof header)
E 3
I 3
	if ((n = read(fd, &header, sizeof header)) != sizeof header)
E 3
		return(ENOEXEC);
	/* check to see if really unix file */
D 3
	if(header.magic != MAGIC1 && header.magic != MAGIC2 &&
		header.magic != MAGIC3 && header.magic != MAGIC4) {
E 3
I 3
	if (header.magic != MAGIC1 && header.magic != MAGIC2 &&
	    header.magic != MAGIC3 && header.magic != MAGIC4) {
E 3
		return(ENOEXEC);
	}
D 3
	/* if a UNIX-32V file run it */
	if(header.textsize == 0) {
E 3
I 3
	/* if a UNIX file run it */
	if (header.textsize == 0) {
E 3
		close(fd);
		/* if no explicit env, pass along environ */
D 3
		if(!envp || *envp == 0)
E 3
I 3
		if (!envp || *envp == 0)
E 3
			return(execve(file, argv, environ));
		return(execve(file, argv,  envp));
	}
	/* checks out OK as PDP-11 UNIX file */
D 3
	if(header.magic == MAGIC3) {
E 3
I 3
	if (header.magic == MAGIC3) {
E 3
		fprintf(stderr,"%s compiled for separate I/D space\n",argv[0]);
		return(-1);
	}
	/* unix text loads at 0 */
	tloadpt = 0;
	/* set starting pc value */
	pc = (unsigned short *)header.entry;
	/* figure out where to load initialized data */
	dloadpt = tloadsize = header.textsize;
	/* check if alignment of data segment to 8k byte boundary */
D 3
	if(header.magic == MAGIC2)
E 3
I 3
	if (header.magic == MAGIC2)
E 3
		dloadpt = (dloadpt+8191) & (~8191);
	/* how much data */
	dloadsize = header.datasize;
	stacksize = header.bsssize;
#endif
#ifdef RT11
D 3
	if((n = read(fd, shortspace, RTHDRSIZ)) != RTHDRSIZ) {
E 3
I 3
	if ((n = read(fd, shortspace, RTHDRSIZ)) != RTHDRSIZ) {
E 3
		fprintf(stderr,"Error reading 1st block\n");
		return(-1);
	}
	/* rt11 files are 0 aligned including the header */
	tloadpt = RTHDRSIZ;
	/* set starting pc value */
	pc = (unsigned short *)shortspace[RTPC];
	/* initialize stack location */
	regs[6] = shortspace[RTSP];
	/* figure how much to load */
	dloadpt = tloadsize = shortspace[RTHGH]-RTHDRSIZ;
	/* no separate data as in unix */
	dloadsize = 0;
	stacksize = 0;
#endif
	/* see if it all fits into available memory space */
D 3
	if((dloadpt+dloadsize+stacksize) > (int)memsiz) {
E 3
I 3
	if ((dloadpt+dloadsize+stacksize) > (int)memsiz) {
E 3
		fprintf(stderr,"File too big to run\n");
		return(-1);
	}
	/* read text segment */
D 3
	if((n = read(fd, tloadpt, tloadsize)) < tloadsize) {
E 3
I 3
	if ((n = read(fd, tloadpt, tloadsize)) < tloadsize) {
E 3
		fprintf(stderr,"Text read failure\n");
		return(-1);
	}
	/* read data segment */
D 3
	if((n = read(fd, dloadpt, dloadsize)) < dloadsize) {
E 3
I 3
	if ((n = read(fd, dloadpt, dloadsize)) < dloadsize) {
E 3
		fprintf(stderr,"Data read failure\n");
		return(-1);
	}
	/* clear out the rest of memory */
	p = (short *)(dloadpt + dloadsize);
D 3
	while(p < (short *)memsiz) *p++ = 0;
E 3
I 3
	while (p < (short *)memsiz)
		*p++ = 0;
E 3
	/* close file before starting it */
	close(fd);
	/* set up illegal instruction trapping */
	signal(SIGILL, illtrap);
	/* lets give it a try */
	start(argv, envp);
}
D 3
#ifdef FBSD
illtrap(signum,faultcode,myaddr,stpc,stps) int signum; {
#else
illtrap(){
#endif
E 3
I 3

illtrap(signum, faultcode, scp)
	int signum, faultcode;
	struct sigcontext *scp;
{
E 3
	unsigned short *pcptr;
	int instr;
	register int i;
	extern getregs();
I 3

E 3
	/* record the fact that we are not in compatability mode now */
	incompat = 0;
	/* get the register values before they get clobbered */
	getregs();
	/* figure out what the pc was */
D 3
#ifdef FBSD
	pcptr = (unsigned short *) &stpc;
#else
	pcptr = (unsigned short *)((char *)&pcptr + 20);
#endif
E 3
I 3
	pcptr = (unsigned short *) &scp->sc_pc;
E 3
	pc = (unsigned short *) *pcptr;
	/* get the instruction */
	instr = *pc;
	/* incriment the pc over this instruction */
	pc++;
	/* set register 7 as pc synonym */
	regs[7] = (unsigned short)(int)pc;
	/* set up psl with condition codes */
	/* a UNIX-32V monitor patch is required to not clear condition codes */
D 3
#ifdef FBSD
	psl = 0x83c00000 | (stps & 017);
#else
	psl = 0x83c00000 | (*(pcptr - 6) & 017);
#endif
E 3
I 3
	psl = 0x83c00000 | (scp->sc_ps & 017);
	sigsetmask(scp->sc_mask);
E 3
	/* pick out the appropriate action for this illegal instruction */
	switch(instr>>8){
D 3
	case	TRAPS:
E 3
I 3

	case TRAPS:
E 3
		dotrap(instr & 0377);
		break;
D 3
	case	EMTS:
		if(sigvals[SIGEMT] && ((sigvals[SIGEMT]%2) != 1)) {
E 3
I 3

	case EMTS:
		if (sigvals[SIGEMT] && ((sigvals[SIGEMT]%2) != 1)) {
E 3
			dosig(SIGEMT, pc);
			break;
		}
		doemt(instr & 0377);
		break;
I 3

E 3
	default:
D 3
		if(instr >= 075000 && instr < 075040) {
E 3
I 3
		if (instr >= 075000 && instr < 075040) {
E 3
			/* fis instructions */
D 3
			if(dofloat(instr) == 0)
E 3
I 3
			if (dofloat(instr) == 0)
E 3
				break;
		}
D 3
		if(instr >=  0170000) {
E 3
I 3
		if (instr >=  0170000) {
E 3
			/* floating point unit instructions */
D 3
			if(dofloat(instr) == 0)
E 3
I 3
			if (dofloat(instr) == 0)
E 3
				break;
		}
		/* genuine illegal instruction */
		/* if signal trap set go to user's trap location */
D 3
		if(sigvals[SIGILL] && ((sigvals[SIGILL]%2) != 1)) {
E 3
I 3
		if (sigvals[SIGILL] && ((sigvals[SIGILL]%2) != 1)) {
E 3
			dosig(SIGILL, pc);
			break;
		}
		/* ignore uncaught setd instructions */
D 3
		if(instr == SETD)
E 3
I 3
		if (instr == SETD)
E 3
			break;
		/* otherwise put out a message and quit */
D 3
		printf("illegal instruction, psl 0x%08x, pc 0%04o\n",psl,pc-1);
		for(i=0; i<7; i++) printf("0x%04x  ",regs[i]);
E 3
I 3
		printf("Illegal instruction, psl 0x%08x, pc 0%04o\n",psl,pc-1);
		for (i = 0; i < 7; i++)
			printf("0x%04x  ",regs[i]);
E 3
		printf("0x%04x -> 0%o\n",pc-1,instr);
		/* set up to dump on illegal instruction */
		signal(SIGILL,SIG_DFL);
		/* set pc back to bad instruction */
		pc--;
		/* go do it again for dump */
		compat();
	}
	/* go back to compatability mode */
	incompat++;
	compat();
}
E 1
