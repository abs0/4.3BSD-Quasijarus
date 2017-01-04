h44168
s 00001/00001/00304
d D 5.3 05/11/24 23:03:23 msokolov 3 2
c fixed eps create -w option
e
s 00035/00002/00270
d D 5.2 05/01/12 08:31:08 msokolov 2 1
c implemented passwd, fixed validacctname
e
s 00272/00000/00000
d D 5.1 05/01/07 19:23:22 msokolov 1 0
c date and time created 05/01/07 19:23:22 by msokolov
e
u
U
t
T
I 1
/*
 * Electronic parcel service
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <sys/param.h>
#include <sys/file.h>
#include <sys/time.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include <pwd.h>

struct passwd *mypwd;
char account[10], newfile[14];
char owner[10], dir[MAXPATHLEN+2], cryptpass[16], comment[130];
int limit;

cmd_create(argv)
	register char **argv;
{
	register char *cp;
	register int i;
	FILE *f;

	strcpy(owner, mypwd->pw_name);
D 3
	if (*argv && *argv[0] == '-' && *argv[1] == 'w') {
E 3
I 3
	if (argv[0] && argv[0][0] == '-' && argv[0][1] == 'w') {
E 3
		cp = *argv++ + 2;
		if (!*cp)
			cp = *argv++;
		if (!cp) {
			fprintf(stderr,
				"eps: create -w option requires an argument\n");
			exit(1);
		}
		limit = atoi(cp);
	}
	if (!*argv) {
		fprintf(stderr, "eps: create: must specify directory\n");
		exit(1);
	}
	if (strlen(*argv) > MAXPATHLEN) {
		fprintf(stderr, "eps: directory argument is too long\n");
		exit(1);
	}
	strcpy(dir, *argv++);
	if (*argv) {
		if (strlen(*argv) > 128) {
			fprintf(stderr, "eps: comment is too long\n");
			exit(1);
		}
		strcpy(comment, *argv);
	}
	initrandom();
	getpasswd();
	/* create it! */
	for (;;) {
		sprintf(account, "eps%06d", random() & 0x7FFFF);
		i = open(account, O_WRONLY|O_CREAT|O_EXCL, 0600);
		if (i >= 0)
			break;
	}
	f = fdopen(i, "w");
	writefile(f);
	fclose(f);
	printf("EPS account %s created\n", account);
	return(0);
}

cmd_delete(argv)
	char **argv;
{
	if (!*argv) {
		fprintf(stderr, "eps delete: account name argument required\n");
		exit(1);
	}
	getacct(*argv);
	enforceowner();
	unlink(account);
	return(0);
}

I 2
cmd_passwd(argv)
	char **argv;
{
	if (!*argv) {
		fprintf(stderr, "eps passwd: account name argument required\n");
		exit(1);
	}
	getacct(*argv);
	enforceowner();
	initrandom();
	getpasswd();
	updateacct();
	return(0);
}

E 2
struct cmdtab {
	char	*cmdname;
	int	(*cmdfunc)();
} cmdtab[] = {
	{"create",	cmd_create},
	{"delete",	cmd_delete},
	{"list",	NULL},
	{"info",	NULL},
D 2
	{"passwd",	NULL},
E 2
I 2
	{"passwd",	cmd_passwd},
E 2
	{"limit",	NULL},
	{"comment",	NULL},
	{NULL,		NULL}
};

main(argc, argv)
	char **argv;
{
	register struct cmdtab *ctp;

	mypwd = getpwuid(getuid());
	if (!mypwd) {
		fprintf(stderr, "who are you?\n");
		exit(1);
	}
	if (chdir("/usr/spool/eps") < 0) {
		fprintf(stderr, "eps: cannot change to EPS spool directory\n");
		exit(1);
	}
	if (argc < 2) {
		fprintf(stderr, "usage: eps <command> [args]\n");
		exit(1);
	}
	for (ctp = cmdtab; ctp->cmdname; ctp++)
		if (!strcmp(argv[1], ctp->cmdname))
			break;
	if (!ctp->cmdfunc) {
		fprintf(stderr, "eps: %s: unknown or unimplemented command\n",
			argv[1]);
		exit(1);
	}
	return(ctp->cmdfunc(argv + 2));
}

initrandom()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	srandom(tv.tv_sec ^ tv.tv_usec ^ getpid());
}

getpasswd()
{
	char pwbuf[9], saltc[2];
	register int i;

	strcpy(pwbuf, getpass("Set password for the EPS account:"));
	if (!pwbuf[0]) {
		fprintf(stderr, "Canceled\n");
		exit(1);
	}
	if (strcmp(pwbuf, getpass("Confirm:"))) {
		fprintf(stderr, "Mismatch\n");
		exit(1);
	}
	i = random();
	saltc[0] = i & 0x3F;
	saltc[1] = (i >> 6) & 0x3F;
	for (i = 0; i < 2; i++) {
		saltc[i] += '.';
		if (saltc[i] > '9')
			saltc[i] += 7;
		if (saltc[i] > 'Z')
			saltc[i] += 6;
	}
	strcpy(cryptpass, crypt(pwbuf, saltc));
}

writefile(f)
	register FILE *f;
{
	fprintf(f, "%s\n", owner);
	fprintf(f, "%s\n", dir);
	fprintf(f, "%s\n", cryptpass);
	fprintf(f, "%d\n", limit);
	if (comment[0])
		fprintf(f, "%s\n", comment);
}

validacctname(s)
	char *s;
{
	register char *cp;
	register int i;

	cp = s;
	if (*cp++ != 'e')
		return(0);
	if (*cp++ != 'p')
		return(0);
	if (*cp++ != 's')
		return(0);
	for (i = 0; i < 6; i++)
		if (!isdigit(*cp++))
			return(0);
D 2
	if (*cp)
E 2
I 2
	if (!*cp)
E 2
		return(1);
	else
		return(0);
}

readaccount()
{
	register FILE *f;
	register char *cp;
	char buf[16];

	f = fopen(account, "r");
	if (!f)
		return(-1);
	if (!fgets(owner, sizeof(owner), f))
		goto bad;
	cp = index(owner, '\n');
	if (cp)
		*cp = '\0';
	else
		goto bad;
	if (!fgets(dir, sizeof(dir), f))
		goto bad;
	cp = index(dir, '\n');
	if (cp)
		*cp = '\0';
	else
		goto bad;
	if (!fgets(cryptpass, sizeof(cryptpass), f))
		goto bad;
	cp = index(cryptpass, '\n');
	if (cp)
		*cp = '\0';
	else
		goto bad;
	if (!fgets(buf, sizeof(buf), f))
		goto bad;
	if (!index(buf, '\n'))
		goto bad;
	limit = atoi(buf);
	if (fgets(comment, sizeof(comment), f)) {
		cp = index(comment, '\n');
		if (cp)
			*cp = '\0';
		else
			goto bad;
	} else
		comment[0] = '\0';
	fclose(f);
	return(0);
bad:	fclose(f);
	return(-2);
}

enforceowner()
{
	if (strcmp(owner, mypwd->pw_name) && getuid()) {
		fprintf(stderr, "You are not the owner of account %s\n",
			account);
		exit(1);
	}
}

getacct(name)
	char *name;
{
	register int i;

	if (!validacctname(name)) {
badacct:	fprintf(stderr, "eps: no account named %s\n", name);
		exit(1);
	}
	strcpy(account, name);
	i = readaccount();
	if (i == -1)
		goto badacct;
	if (i < 0) {
		fprintf(stderr, "eps: %s account file is corrupt\n", account);
		exit(1);
	}
I 2
}

updateacct()
{
	register int i;
	register FILE *f;

	strcpy(newfile, account);
	strcat(newfile, ".new");
	i = open(newfile, O_WRONLY|O_CREAT|O_EXCL, 0600);
	if (i < 0) {
		fprintf(stderr, "eps: account %s is busy\n", account);
		exit(1);
	}
	f = fdopen(i, "w");
	writefile(f);
	fclose(f);
	rename(newfile, account);
E 2
}
E 1
