h10084
s 00007/00001/00142
d D 5.1 85/05/30 16:21:06 mckusick 6 5
c Add copyright
e
s 00001/00003/00142
d D 1.5 85/05/01 01:33:23 sam 5 4
c major rework; fixup netstat stuff; pull disk cmds into common file; change 
c everthing related to disks to use dk_ndrive and global selction; use getw where possible
e
s 00008/00000/00137
d D 1.4 84/08/09 19:12:49 mckusick 4 3
c update to new sources from sam; weed out unnecessary #includes
e
s 00003/00000/00134
d D 1.3 83/10/02 20:45:29 sam 3 2
c reorganize window management to allow display routines to set 
c up optimal window definitions
e
s 00015/00012/00119
d D 1.2 83/10/02 14:40:15 sam 2 1
c add init routine and mbuf display; redo swap space display
e
s 00131/00000/00000
d D 1.1 83/10/01 12:20:58 sam 1 0
c date and time created 83/10/01 12:20:58 by sam
e
u
U
t
T
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 6
I 1
#ifndef lint
D 5
static char sccsid[] = "%W% (Lucasfilm) %G%";
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
D 6
#endif
E 6
I 6
#endif not lint
E 6

#include "systat.h"
I 4
D 5
#include <sys/param.h>
E 5
#include <sys/dir.h>
#include <sys/user.h>
#include <sys/proc.h>
D 5
#include <sys/file.h>
E 5
#include <sys/vmmac.h>
#include <machine/pte.h>
#include <pwd.h>
E 4

long
getw(loc)
        int loc;
{
        long word;

        lseek(kmem, loc, L_SET);
        if (read(kmem, &word, sizeof (word)) != sizeof (word))
                printf("Error reading kmem at %x\n", loc);
        return (word);
}

char *
getpname(pid, mproc)
        int pid;
        register struct proc *mproc;
{
        register struct procs *pp;
        register char *namp;
        register int j;
        char *getcmd();

        pp = procs;
        for (j = numprocs - 1; j >= 0; j--) {
                if (pp->pid == pid)
                        return (pp->cmd);
                pp++;
        }
        if (j < 0) {
                if (numprocs < 200) {
                        pp = &procs[numprocs];
                        namp = strncpy(pp->cmd, getcmd(pid, mproc), 15);
                        pp->cmd[15] = 0;
                        pp->pid = pid;
                        numprocs++;
                } else
                        namp = getcmd(pid, mproc);
        }
        return (namp);
}

union {
        struct  user user;
        char    upages[UPAGES][NBPG];
} user;
#define u       user.user

char *
getcmd(pid, mproc)
        int pid;
        register struct proc *mproc;
{
        static char cmd[30];

D 2
        if (mproc == NULL || mproc->p_stat == SZOMB ||
            mproc->p_flag&(SSYS|SWEXIT))
E 2
I 2
        if (mproc == NULL || mproc->p_stat == SZOMB)
		return ("");
	if (pid == 1)
		return ("swapper");
	if (pid == 2)
		return ("pagedaemon");
        if (mproc->p_flag&(SSYS|SWEXIT))
E 2
                return ("");
D 2
        getu(mproc);
E 2
I 2
        if (getu(mproc) == 0)
		return ("???");
E 2
        (void) strncpy(cmd, u.u_comm, sizeof (cmd));
        return (cmd);
}

I 3
static	int argaddr;
static	int pcbpf;

E 3
getu(mproc)
        register struct proc *mproc;
{
        struct pte *pteaddr, apte;
        struct pte arguutl[UPAGES+CLSIZE];
        register int i;
        int ncl, size;

        size = sizeof (struct user);
        if ((mproc->p_flag & SLOAD) == 0) {
                if (swap < 0)
                        return (0);
                (void) lseek(swap, (long)dtob(mproc->p_swaddr), L_SET);
                if (read(swap, (char *)&user.user, size) != size) {
D 2
                        fprintf(stderr, "ps: cant read u for pid %d from %s\n",
                            mproc->p_pid, swapf);
E 2
I 2
			error("cant read u for pid %d", mproc->p_pid);
E 2
                        return (0);
                }
                pcbpf = 0;
                argaddr = 0;
                return (1);
        }
        pteaddr = &Usrptma[btokmx(mproc->p_p0br) + mproc->p_szpt - 1];
        klseek(kmem, (long)pteaddr, L_SET);
        if (read(kmem, (char *)&apte, sizeof (apte)) != sizeof (apte)) {
D 2
                printf("ps: cant read indir pte to get u for pid %d from %s\n",
                    mproc->p_pid, swapf);
E 2
I 2
                error("cant read indir pte to get u for pid %d", mproc->p_pid);
E 2
                return (0);
        }
        klseek(mem,
            (long)ctob(apte.pg_pfnum+1) - (UPAGES+CLSIZE) * sizeof (struct pte),
                L_SET);
        if (read(mem, (char *)arguutl, sizeof (arguutl)) != sizeof (arguutl)) {
D 2
                printf("ps: cant read page table for u of pid %d from %s\n",
                    mproc->p_pid, kmemf);
E 2
I 2
                error("cant read page table for u of pid %d", mproc->p_pid);
E 2
                return (0);
        }
        if (arguutl[0].pg_fod == 0 && arguutl[0].pg_pfnum)
                argaddr = ctob(arguutl[0].pg_pfnum);
        else
                argaddr = 0;
        pcbpf = arguutl[CLSIZE].pg_pfnum;
        ncl = (size + NBPG*CLSIZE - 1) / (NBPG*CLSIZE);
        while (--ncl >= 0) {
                i = ncl * CLSIZE;
                klseek(mem, (long)ctob(arguutl[CLSIZE+i].pg_pfnum), L_SET);
                if (read(mem, user.upages[i], CLSIZE*NBPG) != CLSIZE*NBPG) {
D 2
                        printf("ps: cant read page %d of u of pid %d from %s\n",
                            arguutl[CLSIZE+i].pg_pfnum, mproc->p_pid, memf);
                        return(0);
E 2
I 2
                        error("cant read page %d of u of pid %d\n",
                            arguutl[CLSIZE+i].pg_pfnum, mproc->p_pid);
                        return (0);
E 2
                }
        }
        return (1);
}

klseek(fd, loc, off)
        int fd;
        long loc;
        int off;
{

        (void) lseek(fd, (long)loc, off);
}
E 1
