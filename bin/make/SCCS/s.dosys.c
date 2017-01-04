h16762
s 00001/00001/00186
d D 4.11 87/11/15 14:58:23 bostic 11 10
c use dirfd macro
e
s 00001/00001/00186
d D 4.10 84/12/23 17:34:49 sam 10 9
c botched sccsid
e
s 00020/00001/00167
d D 4.9 84/12/23 17:27:57 sam 9 8
c close open directory file descriptors on fork; from brl
e
s 00001/00019/00167
d D 4.8 84/03/21 11:13:58 ralph 8 7
c close files on vfork properly.
e
s 00001/00002/00185
d D 4.7 83/06/22 17:42:30 root 7 6
c put back, problem not here
e
s 00002/00002/00185
d D 4.6 83/05/22 19:05:46 mckusick 6 5
c oops, semantics of vfork changed; file table is now copied before exec
e
s 00004/00002/00183
d D 4.5 82/10/19 15:09:36 sam 5 4
c stupid missing bounds check
e
s 00000/00004/00185
d D 4.4 82/06/17 00:08:19 root 4 3
c remove lstats
e
s 00005/00005/00184
d D 4.3 82/04/20 18:56:07 mckusick 3 2
c add new directory access routines
e
s 00004/00000/00185
d D 4.2 82/03/14 13:27:04 sam 2 1
c state->lstat for symbolic links
e
s 00185/00000/00000
d D 4.1 81/02/28 21:15:53 wnj 1 0
c date and time created 81/02/28 21:15:53 by wnj
e
u
U
t
T
I 1
D 9
static	char *sccsid = "%W% (Berkeley) %E%";
E 9
I 9
D 10
static	char *sccsid = "%W% (Berkeley) %G%;
E 10
I 10
static	char *sccsid = "%W% (Berkeley) %G%";
E 10
E 9
#include "defs"
#include <signal.h>

dosys(comstring,nohalt)
register char *comstring;
int nohalt;
{
register int status;

if(metas(comstring))
	status = doshell(comstring,nohalt);
else	status = doexec(comstring);

return(status);
}



metas(s)   /* Are there are any  Shell meta-characters? */
register char *s;
{
register char c;

while( (funny[c = *s++] & META) == 0 )
	;
return( c );
}

doshell(comstring,nohalt)
char *comstring;
int nohalt;
{
#ifdef SHELLENV
char *getenv(), *rindex();
char *shellcom = getenv("SHELL");
char *shellstr;
#endif
D 6
if((waitpid = vfork()) == 0)
E 6
I 6
D 7
if((waitpid = fork()) == 0)
E 7
I 7
if((waitpid = vfork()) == 0)
E 7
E 6
	{
	enbint(SIG_DFL);
I 9
	doclose();
E 9
D 8
	doclose();
E 8

#ifdef SHELLENV
	if (shellcom == 0) shellcom = SHELLCOM;
	shellstr = rindex(shellcom, '/') + 1;
	execl(shellcom, shellstr, (nohalt ? "-c" : "-ce"), comstring, 0);
#else
	execl(SHELLCOM, "sh", (nohalt ? "-c" : "-ce"), comstring, 0);
#endif
	fatal("Couldn't load Shell");
	}

return( await() );
}




int intrupt();

await()
{
int status;
register int pid;

enbint(SIG_IGN);
while( (pid = wait(&status)) != waitpid)
	if(pid == -1)
		fatal("bad wait code");
waitpid = 0;
enbint(intrupt);
return(status);
}
I 9

/*
 * Close open directory files before exec'ing
 */
doclose()
{
register struct dirhdr *od;

for (od = firstod; od; od = od->nxtopendir)
	if (od->dirfc != NULL)
		/*
		 * vfork kludge...
		 * we cannot call closedir since this will modify
		 * the parents data space; just call close directly.
		 */
D 11
		close(od->dirfc->dd_fd);
E 11
I 11
		(void)close(dirfd(od->dirfc));
E 11
}
E 9
D 8






doclose()	/* Close open directory files before exec'ing */
{
D 3
register struct opendir *od;
E 3
I 3
register struct dirhdr *od;
E 3

for (od = firstod; od; od = od->nxtopendir)
D 3
	if (od->dirfc != NULL)
		/* fclose(od->dirfc); */
		close(od->dirfc->_file);
E 3
I 3
	if (od->dirfc != NULL) {
		closedir(od->dirfc);
		od->dirfc = NULL;
	}
E 3
}
E 8



I 5
#define MAXARGV	400
E 5

D 5

E 5
doexec(str)
register char *str;
{
register char *t;
D 5
char *argv[200];
E 5
I 5
char *argv[MAXARGV];
E 5
register char **p;

while( *str==' ' || *str=='\t' )
	++str;
if( *str == '\0' )
	return(-1);	/* no command */

p = argv;
for(t = str ; *t ; )
	{
I 5
	if (p >= argv + MAXARGV)
		fatal1("%s: Too many arguments.", str);
E 5
	*p++ = t;
	while(*t!=' ' && *t!='\t' && *t!='\0')
		++t;
	if(*t)
		for( *t++ = '\0' ; *t==' ' || *t=='\t'  ; ++t)
			;
	}

*p = NULL;

D 6
if((waitpid = vfork()) == 0)
E 6
I 6
D 8
if((waitpid = fork()) == 0)
E 8
I 8
if((waitpid = vfork()) == 0)
E 8
E 6
	{
	enbint(SIG_DFL);
I 9
	doclose();
E 9
D 8
	doclose();
E 8
	enbint(intrupt);
	execvp(str, argv);
	fatal1("Cannot load %s",str);
	}

return( await() );
}

#include <errno.h>

D 3
#include <sys/types.h>
E 3
#include <sys/stat.h>
D 7

E 7



touch(force, name)
int force;
char *name;
{
struct stat stbuff;
char junk[1];
int fd;

I 2
D 4
#if vax
if (lstat(name, &stbuff) < 0)
#else
E 4
E 2
if( stat(name,&stbuff) < 0)
I 2
D 4
#endif
E 4
E 2
	if(force)
		goto create;
	else
		{
		fprintf(stderr, "touch: file %s does not exist.\n", name);
		return;
		}

if(stbuff.st_size == 0)
	goto create;

if( (fd = open(name, 2)) < 0)
	goto bad;

if( read(fd, junk, 1) < 1)
	{
	close(fd);
	goto bad;
	}
lseek(fd, 0L, 0);
if( write(fd, junk, 1) < 1 )
	{
	close(fd);
	goto bad;
	}
close(fd);
return;

bad:
	fprintf(stderr, "Cannot touch %s\n", name);
	return;

create:
	if( (fd = creat(name, 0666)) < 0)
		goto bad;
	close(fd);
}
E 1
