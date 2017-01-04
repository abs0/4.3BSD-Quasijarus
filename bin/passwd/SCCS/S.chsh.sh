h22306
s 00005/00167/00000
d D 4.10 85/03/24 15:04:53 mckusick 10 9
c subsummed by passwd
e
s 00052/00033/00115
d D 4.9 83/12/20 13:37:10 ralph 9 8
c update dbm passwd database directly.
e
s 00040/00019/00108
d D 4.8 83/12/02 17:31:50 ralph 8 7
c changed to rebuild passwd hash database.
e
s 00001/00000/00126
d D 4.7 83/07/10 17:53:44 sam 7 6
c beware of screwey user umasks
e
s 00002/00002/00124
d D 4.6 83/07/02 00:54:39 sam 6 5
c include fixes
e
s 00079/00078/00047
d D 4.5 83/06/10 23:33:34 sam 5 4
c do locking a la password
e
s 00007/00003/00118
d D 4.4 83/02/09 17:02:31 layer 4 3
c added /usr/new/csh as valid shell, and fixed call to stat
e
s 00003/00003/00118
d D 4.3 82/06/28 03:47:14 wnj 3 2
c allow only /bin/csh, not /bin/oldcsh
e
s 00006/00000/00115
d D 4.2 82/02/13 22:54:33 root 2 1
c change not to allow chsh to now existant qualified shells
e
s 00115/00000/00000
d D 4.1 80/10/01 17:25:33 bill 1 0
c date and time created 80/10/01 17:25:33 by bill
e
u
U
f b 
t
T
I 5
D 10
#ifndef lint
E 5
I 1
static char *sccsid = "%W% (Berkeley) %G%";
I 5
#endif

E 5
/*
 * chsh
 */
#include <stdio.h>
I 4
D 5
#include <sys/types.h>
#include <stat.h>
E 5
E 4
#include <signal.h>
#include <pwd.h>
I 9
#include <ndbm.h>
E 9
I 5
#include <sys/file.h>
D 6
#include <time.h>
#include <resource.h>
E 6
I 6
#include <sys/time.h>
#include <sys/resource.h>
E 6
E 5

I 8
char	temp[] = "/etc/ptmp";
D 9
char	temp_pag[] = "/etc/ptmp.pag";
char	temp_dir[] = "/etc/ptmp.dir";
E 9
E 8
char	passwd[] = "/etc/passwd";
D 8
char	temp[]	 = "/etc/ptmp";
E 8
I 8
D 9
char	passwd_pag[] = "/etc/passwd.pag";
char	passwd_dir[] = "/etc/passwd.dir";
E 9
E 8
struct	passwd *pwd;
struct	passwd *getpwent();
int	endpwent();
char	*crypt();
char	*getpass();
D 5
char	*pw;
char	pwbuf[10];
E 5
I 5
char	*strcat();
E 5
char	buf[BUFSIZ];

main(argc, argv)
D 5
char *argv[];
E 5
I 5
register char *argv[];
E 5
{
D 5
	char *p;
	int i;
	char saltc[2];
	long salt;
	int u,fi,fo;
	int insist;
	int ok, flags;
	int c;
	int pwlen;
	FILE *tf;
I 4
	struct stat sbuf;
E 5
I 5
	register int u, fd;
	register FILE *tf;
I 9
	DBM *dp;
E 9
E 5
E 4

D 5
	insist = 0;
	if(argc < 2 || argc > 3) {
E 5
I 5
	if (argc < 2 || argc > 3) {
E 5
D 3
		printf("Usage: chsh user [ /bin/oldcsh ] [ /bin/csh ]\n");
E 3
I 3
		printf("Usage: chsh user [ /bin/csh ]\n");
E 3
D 5
		goto bex;
E 5
I 5
		exit(1);
E 5
	}
	if (argc == 2)
		argv[2] = "";
D 3
	else if (strcmp(argv[2], "/bin/oldcsh") && strcmp(argv[2], "/bin/csh") && getuid()) {
		printf("Only /bin/oldcsh or /bin/csh may be specified\n");
E 3
I 3
D 4
	else if (strcmp(argv[2], "/bin/csh") && getuid()) {
		printf("Only /bin/csh may be specified\n");
E 4
I 4
D 5
	else if (strcmp(argv[2], "/bin/csh") != 0 &&
		 strcmp(argv[2], "/usr/new/csh") != 0 && getuid()) {
		printf("Only /bin/csh or /usr/new/csh may be specified\n");
E 4
E 3
		exit(1);
	}
I 2
	if (argc == 3)
D 4
		if (stat(argv[2]) < 0)
E 4
I 4
		if (stat(argv[2],&sbuf) < 0)
E 4
		{
			printf("%s is unavailable\n",argv[2]);
E 5
I 5
	else {
		if (argv[2][0] != '/')
			argv[2] = strcat(
			    "/bin/\0 12345678901234567890123456789", argv[2]);
		if (strcmp(argv[2], "/bin/csh") &&
		    strcmp(argv[2], "/bin/oldcsh") &&
		    strcmp(argv[2], "/bin/newcsh") &&
		    strcmp(argv[2], "/usr/new/csh") &&
			/* and, for cretins who can't read the manual */
		    strcmp(argv[2], "/bin/sh") &&
		    getuid()) {
			printf(
			    "Only /bin/csh may be specified\n"
			);
E 5
			exit(1);
		}
E 2
D 5
	while((pwd=getpwent()) != NULL){
		if(strcmp(pwd->pw_name,argv[1]) == 0){
E 5
I 5
		if (access(argv[2], 1) < 0) {
			printf("%s is not available\n", argv[2]);
			exit(1);
		}
	}
	unlimit(RLIMIT_CPU);
	unlimit(RLIMIT_FSIZE);
D 8
	while ((pwd=getpwent()) != NULL) {
		if (strcmp(pwd->pw_name, argv[1]) == 0) {
E 5
			u = getuid();
D 5
			if(u!=0 && u != pwd->pw_uid){
E 5
I 5
			if (u!=0 && u != pwd->pw_uid) {
E 5
				printf("Permission denied.\n");
D 5
				goto bex;
				}
			break;
E 5
I 5
				exit(1);
E 5
			}
I 5
			break;
E 5
		}
E 8
I 8
	u = getuid();
	if (u != 0 && ((pwd = getpwnam(argv[1])) == NULL || u != pwd->pw_uid)) {
		printf("Permission denied.\n");
		exit(1);
E 8
I 5
	}
E 5
D 8
	endpwent();
E 8
D 5
	signal(SIGHUP, 1);
	signal(SIGINT, 1);
	signal(SIGQUIT, 1);
	signal(SIGTSTP, 1);
E 5

D 5
	if(access(temp, 0) >= 0) {
E 5
I 5
	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
I 7
	(void) umask(0);
E 7
	if ((fd = open(temp, O_CREAT|O_EXCL|O_RDWR, 0644)) < 0) {
E 5
		printf("Temporary file busy -- try again\n");
D 5
		goto bex;
E 5
I 5
		exit(1);
E 5
	}
D 5
	if((tf=fopen(temp,"w")) == NULL) {
		printf("Cannot create temporary file\n");
		goto bex;
E 5
I 5
D 9
	if ((tf=fdopen(fd, "w")) == NULL) {
E 9
I 9
	if ((tf = fdopen(fd, "w")) == NULL) {
E 9
		printf("Absurd fdopen failure - seek help\n");
		goto out;
E 5
	}
I 9
	if ((dp = ndbmopen(passwd, O_RDWR, 0644)) == NULL) {
		fprintf(stderr, "Warning: dbminit failed: ");
		perror(passwd);
	} else if (flock(dp->db_dirf, LOCK_EX) < 0) {
		perror("Warning: lock failed");
		ndbmclose(dp);
		dp = NULL;
	}
E 9
D 5

/*
 *	copy passwd to temp, replacing matching lines
 *	with new shell.
 */

	while((pwd=getpwent()) != NULL) {
		if(strcmp(pwd->pw_name,argv[1]) == 0) {
E 5
I 5
	/*
	 * Copy passwd to temp, replacing matching lines
	 * with new shell.
	 */
D 9
	while ((pwd=getpwent()) != NULL) {
E 9
I 9
	while ((pwd = getpwent()) != NULL) {
E 9
		if (strcmp(pwd->pw_name, argv[1]) == 0) {
E 5
D 8
			u = getuid();
E 8
D 5
			if(u != 0 && u != pwd->pw_uid) {
E 5
I 5
			if (u != 0 && u != pwd->pw_uid) {
E 5
				printf("Permission denied.\n");
				goto out;
			}
			pwd->pw_shell = argv[2];
I 9
			replace(dp, pwd);
E 9
		}
D 5
		fprintf(tf,"%s:%s:%d:%d:%s:%s:%s\n",
			pwd->pw_name,
			pwd->pw_passwd,
			pwd->pw_uid,
			pwd->pw_gid,
			pwd->pw_gecos,
			pwd->pw_dir,
			pwd->pw_shell);
E 5
I 5
		if (strcmp(pwd->pw_shell, "/bin/sh") == 0)
			pwd->pw_shell = "";
		fprintf(tf, "%s:%s:%d:%d:%s:%s:%s\n"
			, pwd->pw_name
			, pwd->pw_passwd
			, pwd->pw_uid
			, pwd->pw_gid
			, pwd->pw_gecos
			, pwd->pw_dir
			, pwd->pw_shell
		);
E 5
	}
	endpwent();
I 5
D 8
	if (rename(temp, passwd) < 0) {
		fprintf(stderr, "chsh: "); perror("rename");
  out:
		unlink(temp);
		exit(1);
	}
E 8
E 5
D 9
	fclose(tf);
I 5
D 8
	exit(0);
E 8
I 8
	if (makedb(temp) < 0)
		fprintf(stderr, "chsh: mkpasswd failed\n");
	else if (rename(temp_pag, passwd_pag) < 0)
		fprintf(stderr, "chsh: "), perror(temp_pag);
	else if (rename(temp_dir, passwd_dir) < 0)
		fprintf(stderr, "chsh: "), perror(temp_dir);
	else if (rename(temp, passwd) < 0)
E 9
I 9
	(void) fclose(tf);
	ndbmclose(dp);
	if (rename(temp, passwd) < 0) {
E 9
		fprintf(stderr, "chsh: "), perror("rename");
D 9
	else
		exit(0);
out:
	unlink(temp_pag);
	unlink(temp_dir);
	unlink(temp);
	exit(1);
E 9
I 9
	out:
		(void) unlink(temp);
		exit(1);
	}
	exit(0);
E 9
E 8
}
E 5

D 5
/*
 *	copy temp back to passwd file
 */
E 5
I 5
unlimit(lim)
{
	struct rlimit rlim;
E 5

D 5
	if((fi=open(temp,0)) < 0) {
		printf("Temp file disappeared!\n");
		goto out;
	}
	if((fo=creat(passwd, 0644)) < 0) {
		printf("Cannot recreat passwd file.\n");
		goto out;
	}
	while((u=read(fi,buf,sizeof(buf))) > 0) write(fo,buf,u);

out:
	unlink(temp);

bex:
	exit(1);
E 5
I 5
	rlim.rlim_cur = rlim.rlim_max = RLIM_INFINITY;
	setrlimit(lim, &rlim);
I 8
}

D 9
makedb(file)
	char *file;
E 9
I 9
/*
 * Replace the password entry in the dbm data base with pwd.
 */
replace(dp, pwd)
	DBM *dp;
	struct passwd *pwd;
E 9
{
D 9
	int status, pid, w;
E 9
I 9
	datum key, content;
	register char *cp, *tp;
	char buf[BUFSIZ];
E 9

D 9
	if ((pid = vfork()) == 0) {
		execl("/etc/mkpasswd", "mkpasswd", file, 0);
		_exit(127);
	}
	while ((w = wait(&status)) != pid && w != -1)
		;
	if (w == -1 || status != 0)
		status = -1;
	return(status);
E 9
I 9
	if (dp == NULL)
		return;

	cp = buf;
#define	COMPACT(e)	tp = pwd->pw_/**/e; while (*cp++ = *tp++);
	COMPACT(name);
	COMPACT(passwd);
	*(int *)cp = pwd->pw_uid; cp += sizeof (int);
	*(int *)cp = pwd->pw_gid; cp += sizeof (int);
	*(int *)cp = pwd->pw_quota; cp += sizeof (int);
	COMPACT(comment);
	COMPACT(gecos);
	COMPACT(dir);
	COMPACT(shell);
	content.dptr = buf;
	content.dsize = cp - buf;
	key.dptr = pwd->pw_name;
	key.dsize = strlen(pwd->pw_name);
	dbmstore(dp, key, content, DB_REPLACE);
	key.dptr = (char *)&pwd->pw_uid;
	key.dsize = sizeof (int);
	dbmstore(dp, key, content, DB_REPLACE);
E 9
E 8
E 5
}
E 10
I 10
#!/bin/sh
#
#	%W% (Berkeley) %G%
#
echo 'Use "passwd -s"'
E 10
E 1
