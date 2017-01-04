h11894
s 00008/00000/00501
d D 4.16 99/01/21 00:56:19 msokolov 21 20
c add compress -s and gzip formats
e
s 00000/00001/00501
d D 4.15 88/06/01 17:12:22 bostic 20 19
c rip out sobuf
e
s 00001/00001/00501
d D 4.14 88/04/24 17:12:35 bostic 19 18
c fix for ANSI C
e
s 00005/00003/00497
d D 4.13 87/09/23 13:52:35 bostic 18 17
c make errno, sys_errlist and sys_nerr externs
e
s 00002/00002/00498
d D 4.12 85/11/17 16:11:39 sam 17 16
c who wrote this code anyway?
e
s 00006/00000/00494
d D 4.11 85/09/10 08:33:46 serge 16 15
c recognize compressed (.Z) files
e
s 00084/00019/00410
d D 4.10 85/05/19 23:06:03 sam 15 14
c recognize executable shell scripts and make an attempt to 
c recognize the type of regular scripts
e
s 00045/00015/00384
d D 4.9 85/02/14 14:48:02 serge 14 11
c added socket file type
e
s 00029/00013/00386
d R 4.9 85/02/14 14:27:05 serge 13 11
c added socket file type
e
s 00023/00013/00386
d R 4.9 85/02/05 18:17:15 serge 12 11
c now knows about sockets
e
s 00001/00001/00398
d D 4.8 83/08/11 20:27:45 sam 11 10
c standardize sccs keyword lines
e
s 00001/00001/00398
d D 4.7 83/07/03 20:22:52 sam 10 9
c include fix
e
s 00002/00001/00397
d D 4.6 83/05/22 18:37:24 sam 9 8
c purge pagsiz.h
e
s 00004/00002/00394
d D 4.5 83/04/29 02:15:38 mckusick 8 7
c added sys_errlist messages
e
s 00005/00009/00391
d D 4.4 82/05/09 21:58:04 mckusick 7 6
c get rid of MPX checks, add symbolic link checks
e
s 00001/00001/00399
d D 4.3 82/02/20 11:16:18 root 6 5
c restore keywords
e
s 00009/00001/00391
d D 4.2 82/02/20 11:15:39 root 5 4
c recognize PRESS files
e
s 00000/00000/00392
d D 4.1 80/10/01 16:38:22 bill 4 3
c Define 4.1
e
s 00001/00001/00391
d D 3.3 80/09/21 03:47:40 bill 3 2
c fix reference to newa.out.h to a.out.h
e
s 00004/00000/00388
d D 3.2 80/09/20 18:44:11 bill 2 1
c grok cpio
e
s 00388/00000/00000
d D 3.1 80/08/15 01:55:10 bill 1 0
c date and time created 80/08/15 01:55:10 by bill
e
u
U
t
T
I 9
#ifndef lint
E 9
I 1
D 5
static	char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
D 6
static	char sccsid[] = "@(#)file.c 4.1 10/1/80";
E 6
I 6
D 11
static	char sccsid[] = "%W% (Berkeley) %I%";
E 11
I 11
static	char sccsid[] = "%W% (Berkeley) %G%";
E 11
I 9
#endif
E 9
E 6
E 5
/*
 * file - determine type of file
 */

D 9
#include <pagsiz.h>
E 9
D 14
#include <sys/types.h>
E 14
I 14
#include <sys/param.h>
E 14
D 10
#include <stat.h>
E 10
I 10
#include <sys/stat.h>
E 10
#include <stdio.h>
#include <ctype.h>
D 3
#include <newa.out.h>
E 3
I 3
#include <a.out.h>
I 8
D 18
int	errno;
I 14
int	sys_nerr;
E 14
char	*sys_errlist[];
E 18
I 18

extern int	errno;
extern int	sys_nerr;
extern char	*sys_errlist[];

E 18
E 8
E 3
int in;
int i  = 0;
char buf[BUFSIZ];
char *troff[] = {	/* new troff intermediate lang */
	"x","T","res","init","font","202","V0","p1",0};
char *fort[] = {
	"function","subroutine","common","dimension","block","integer",
	"real","data","double",0};
char *asc[] = {
	"chmk","mov","tst","clr","jmp",0};
char *c[] = {
	"int","char","float","double","struct","extern",0};
char *as[] = {
	"globl","byte","align","text","data","comm",0};
I 15
char *sh[] = {
	"fi", "elif", "esac", "done", "export",
	"readonly", "trap", "PATH", "HOME", 0 };
char *csh[] = {
	"alias", "breaksw", "endsw", "foreach", "limit",  "onintr",
	"repeat", "setenv", "source", "path", "home", 0 };
E 15
int	ifile;

main(argc, argv)
char **argv;
{
	FILE *fl;
	register char *p;
D 14
	char ap[128];
E 14
I 14
	char ap[MAXPATHLEN + 1];
E 14
D 20
	extern char _sobuf[];
E 20

I 14
	if (argc < 2) {
		fprintf(stderr, "usage: %s file ...\n", argv[0]);
		exit(3);
	}
		
E 14
	if (argc>1 && argv[1][0]=='-' && argv[1][1]=='f') {
		if ((fl = fopen(argv[2], "r")) == NULL) {
D 8
			printf("Can't open %s\n", argv[2]);
E 8
I 8
			perror(argv[2]);
E 8
			exit(2);
		}
D 14
		while ((p = fgets(ap, 128, fl)) != NULL) {
E 14
I 14
		while ((p = fgets(ap, sizeof ap, fl)) != NULL) {
E 14
			int l = strlen(p);
			if (l>0)
				p[l-1] = '\0';
			printf("%s:	", p);
			type(p);
			if (ifile>=0)
				close(ifile);
		}
		exit(1);
	}
	while(argc > 1) {
		printf("%s:	", argv[1]);
		type(argv[1]);
		fflush(stdout);
		argc--;
		argv++;
		if (ifile >= 0)
			close(ifile);
	}
I 14
	exit(0);
E 14
}

type(file)
char *file;
{
	int j,nl;
	char ch;
	struct stat mbuf;
I 14
	char slink[MAXPATHLEN + 1];
E 14

	ifile = -1;
D 7
	if(stat(file, &mbuf) < 0) {
E 7
I 7
	if (lstat(file, &mbuf) < 0) {
E 7
D 8
		printf("cannot stat\n");
E 8
I 8
D 14
		printf("%s\n", sys_errlist[errno]);
E 14
I 14
		printf("%s\n",
		(unsigned)errno < sys_nerr? sys_errlist[errno]: "Cannot stat");
E 14
E 8
		return;
	}
	switch (mbuf.st_mode & S_IFMT) {

D 14
	case S_IFCHR:
		printf("character");
		goto spcl;

E 14
D 7
	case S_IFDIR:
		printf("directory\n");
E 7
I 7
	case S_IFLNK:
D 14
		printf("symbolic link\n");
E 14
I 14
		printf("symbolic link");
		j = readlink(file, slink, sizeof slink - 1);
		if (j >= 0) {
			slink[j] = '\0';
			printf(" to %s", slink);
		}
		printf("\n");
E 14
E 7
		return;

D 7
	case S_IFMPC:
		printf("char multiplexor\n");
		return;

	case S_IFMPB:
		printf("block multiplexor\n");
E 7
I 7
	case S_IFDIR:
I 14
		if (mbuf.st_mode & S_ISVTX)
			printf("append-only ");
E 14
		printf("directory\n");
E 7
		return;

I 14
	case S_IFCHR:
E 14
	case S_IFBLK:
D 14
		printf("block");
E 14
I 14
		printf("%s special (%d/%d)\n",
D 17
			mbuf.st_mode&S_IFMT == S_IFCHR ? "character" : "block",
			major(mbuf.st_rdev), minor(mbuf.st_rdev));
E 17
I 17
		    (mbuf.st_mode&S_IFMT) == S_IFCHR ? "character" : "block",
		     major(mbuf.st_rdev), minor(mbuf.st_rdev));
E 17
		return;
E 14

D 14
spcl:
		printf(" special (%d/%d)\n", major(mbuf.st_rdev), minor(mbuf.st_rdev));
E 14
I 14
	case S_IFSOCK:
		printf("socket\n");
E 14
		return;
	}

	ifile = open(file, 0);
	if(ifile < 0) {
D 14
		printf("cannot open\n");
E 14
I 14
		printf("%s\n",
		(unsigned)errno < sys_nerr? sys_errlist[errno]: "Cannot read");
E 14
		return;
	}
	in = read(ifile, buf, BUFSIZ);
	if(in == 0){
		printf("empty\n");
		return;
	}
	switch(*(int *)buf) {

	case 0413:
		printf("demand paged ");

	case 0410:
		printf("pure ");
		goto exec;

	case 0411:
		printf("jfr or pdp-11 unix 411 executable\n");
		return;

	case 0407:
exec:
I 14
		if (mbuf.st_mode & S_ISUID)
			printf("set-uid ");
		if (mbuf.st_mode & S_ISGID)
			printf("set-gid ");
		if (mbuf.st_mode & S_ISVTX)
			printf("sticky ");
E 14
		printf("executable");
		if(((int *)buf)[4] != 0) {
			printf(" not stripped");
			if(oldo(buf))
				printf(" (old format symbol table)");
		}
		printf("\n");
D 15
		goto out;
E 15
I 15
		return;
E 15

	case 0177555:
		printf("very old archive\n");
D 15
		goto out;
E 15
I 15
		return;
E 15

	case 0177545:
		printf("old archive\n");
D 15
		goto out;
E 15
I 15
		return;
E 15
I 2

	case 070707:
		printf("cpio data\n");
D 15
		goto out;
E 15
I 15
		return;
E 15
E 2
	}

I 15
	if (buf[0] == '#' && buf[1] == '!' && shellscript(buf+2, &mbuf))
		return;
I 16
	if (buf[0] == '\037' && buf[1] == '\235') {
		if (buf[2]&0x80)
			printf("block ");
		printf("compressed %d bit code data\n", buf[2]&0x1f);
		return;
	}
I 21
	if (buf[0] == '\037' && buf[1] == '\241') {
		printf("strong compressed data\n");
		return;
	}
	if (buf[0] == '\037' && buf[1] == '\213') {
		printf("gzipped data\n");
		return;
	}
E 21
E 16
E 15
	if(strncmp(buf, "!<arch>\n__.SYMDEF", 17) == 0 ) {
		printf("archive random library\n");
D 15
		goto out;
E 15
I 15
		return;
E 15
	}
	if (strncmp(buf, "!<arch>\n", 8)==0) {
		printf("archive\n");
D 15
		goto out;
E 15
I 15
		return;
E 15
I 5
	}
	if (mbuf.st_size % 512 == 0) {	/* it may be a PRESS file */
		lseek(ifile, -512L, 2);	/* last block */
D 15
		if (read(ifile, buf, BUFSIZ) > 0
		 && *(short int *)buf == 12138) {
E 15
I 15
		if (read(ifile, buf, BUFSIZ) > 0 && *(short *)buf == 12138) {
E 15
			printf("PRESS file\n");
D 15
			goto out;
E 15
I 15
			return;
E 15
		}
E 5
	}
	i = 0;
	if(ccom() == 0)goto notc;
	while(buf[i] == '#'){
		j = i;
		while(buf[i++] != '\n'){
			if(i - j > 255){
				printf("data\n"); 
D 15
				goto out;
E 15
I 15
				return;
E 15
			}
			if(i >= in)goto notc;
		}
		if(ccom() == 0)goto notc;
	}
check:
	if(lookup(c) == 1){
		while((ch = buf[i++]) != ';' && ch != '{')if(i >= in)goto notc;
		printf("c program text");
		goto outa;
	}
	nl = 0;
	while(buf[i] != '('){
		if(buf[i] <= 0)
			goto notas;
		if(buf[i] == ';'){
			i++; 
			goto check; 
		}
		if(buf[i++] == '\n')
			if(nl++ > 6)goto notc;
		if(i >= in)goto notc;
	}
	while(buf[i] != ')'){
		if(buf[i++] == '\n')
			if(nl++ > 6)goto notc;
		if(i >= in)goto notc;
	}
	while(buf[i] != '{'){
		if(buf[i++] == '\n')
			if(nl++ > 6)goto notc;
		if(i >= in)goto notc;
	}
	printf("c program text");
	goto outa;
notc:
	i = 0;
	while(buf[i] == 'c' || buf[i] == '#'){
		while(buf[i++] != '\n')if(i >= in)goto notfort;
	}
	if(lookup(fort) == 1){
		printf("fortran program text");
		goto outa;
	}
notfort:
	i=0;
	if(ascom() == 0)goto notas;
	j = i-1;
	if(buf[i] == '.'){
		i++;
		if(lookup(as) == 1){
			printf("assembler program text"); 
			goto outa;
		}
		else if(buf[j] == '\n' && isalpha(buf[j+2])){
			printf("roff, nroff, or eqn input text");
			goto outa;
		}
	}
	while(lookup(asc) == 0){
		if(ascom() == 0)goto notas;
		while(buf[i] != '\n' && buf[i++] != ':')
			if(i >= in)goto notas;
		while(buf[i] == '\n' || buf[i] == ' ' || buf[i] == '\t')if(i++ >= in)goto notas;
		j = i-1;
		if(buf[i] == '.'){
			i++;
			if(lookup(as) == 1){
				printf("assembler program text"); 
				goto outa; 
			}
			else if(buf[j] == '\n' && isalpha(buf[j+2])){
				printf("roff, nroff, or eqn input text");
				goto outa;
			}
		}
	}
	printf("assembler program text");
	goto outa;
notas:
	for(i=0; i < in; i++)if(buf[i]&0200){
D 15
		if (buf[0]=='\100' && buf[1]=='\357') {
E 15
I 15
		if (buf[0]=='\100' && buf[1]=='\357')
E 15
			printf("troff (CAT) output\n");
D 15
			goto out;
		}
		printf("data\n"); 
		goto out; 
E 15
I 15
		else
			printf("data\n"); 
		return;
E 15
	}
D 14
	if (mbuf.st_mode&((S_IEXEC)|(S_IEXEC>>3)|(S_IEXEC>>6)))
E 14
I 14
	if (mbuf.st_mode&((S_IEXEC)|(S_IEXEC>>3)|(S_IEXEC>>6))) {
		if (mbuf.st_mode & S_ISUID)
			printf("set-uid ");
		if (mbuf.st_mode & S_ISGID)
			printf("set-gid ");
		if (mbuf.st_mode & S_ISVTX)
			printf("sticky ");
E 14
D 15
		printf("commands text");
E 15
I 15
		if (shell(buf, in, sh))
			printf("shell script");
		else if (shell(buf, in, csh))
			printf("c-shell script");
		else
			printf("commands text");
E 15
D 14
	else if (troffint(buf, in))
E 14
I 14
	} else if (troffint(buf, in))
E 14
		printf("troff intermediate output text");
I 15
	else if (shell(buf, in, sh))
		printf("shell commands");
	else if (shell(buf, in, csh))
		printf("c-shell commands");
E 15
	else if (english(buf, in))
		printf("English text");
	else
		printf("ascii text");
outa:
	while(i < in)
		if((buf[i++]&0377) > 127){
			printf(" with garbage\n");
D 15
			goto out;
E 15
I 15
			return;
E 15
		}
	/* if next few lines in then read whole file looking for nulls ...
		while((in = read(ifile,buf,BUFSIZ)) > 0)
			for(i = 0; i < in; i++)
				if((buf[i]&0377) > 127){
					printf(" with garbage\n");
D 15
					goto out;
E 15
I 15
					return;
E 15
				}
		/*.... */
	printf("\n");
D 15
out:;
E 15
}

oldo(cp)
char *cp;
{
	struct exec ex;
	struct stat stb;

	ex = *(struct exec *)cp;
	if (fstat(ifile, &stb) < 0)
		return(0);
	if (N_STROFF(ex)+sizeof(off_t) > stb.st_size)
		return (1);
	return (0);
}



troffint(bp, n)
char *bp;
int n;
{
	int k;

	i = 0;
	for (k = 0; k < 6; k++) {
		if (lookup(troff) == 0)
			return(0);
		if (lookup(troff) == 0)
			return(0);
		while (i < n && buf[i] != '\n')
			i++;
		if (i++ >= n)
			return(0);
	}
	return(1);
}
lookup(tab)
char *tab[];
{
	char r;
	int k,j,l;
	while(buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\n')i++;
	for(j=0; tab[j] != 0; j++){
		l=0;
		for(k=i; ((r=tab[j][l++]) == buf[k] && r != '\0');k++);
		if(r == '\0')
			if(buf[k] == ' ' || buf[k] == '\n' || buf[k] == '\t'
			    || buf[k] == '{' || buf[k] == '/'){
				i=k;
				return(1);
			}
	}
	return(0);
}
ccom(){
	char cc;
	while((cc = buf[i]) == ' ' || cc == '\t' || cc == '\n')if(i++ >= in)return(0);
	if(buf[i] == '/' && buf[i+1] == '*'){
		i += 2;
		while(buf[i] != '*' || buf[i+1] != '/'){
			if(buf[i] == '\\')i += 2;
			else i++;
			if(i >= in)return(0);
		}
		if((i += 2) >= in)return(0);
	}
	if(buf[i] == '\n')if(ccom() == 0)return(0);
	return(1);
}
ascom(){
	while(buf[i] == '/'){
		i++;
		while(buf[i++] != '\n')if(i >= in)return(0);
		while(buf[i] == '\n')if(i++ >= in)return(0);
	}
	return(1);
}

english (bp, n)
char *bp;
{
# define NASC 128
	int ct[NASC], j, vow, freq, rare;
	int badpun = 0, punct = 0;
	if (n<50) return(0); /* no point in statistics on squibs */
	for(j=0; j<NASC; j++)
		ct[j]=0;
	for(j=0; j<n; j++)
	{
D 19
		if (bp[j]<NASC)
E 19
I 19
		if ((u_char)bp[j]<NASC)
E 19
			ct[bp[j]|040]++;
		switch (bp[j])
		{
		case '.': 
		case ',': 
		case ')': 
		case '%':
		case ';': 
		case ':': 
		case '?':
			punct++;
			if ( j < n-1 &&
			    bp[j+1] != ' ' &&
			    bp[j+1] != '\n')
				badpun++;
		}
	}
	if (badpun*5 > punct)
		return(0);
	vow = ct['a'] + ct['e'] + ct['i'] + ct['o'] + ct['u'];
	freq = ct['e'] + ct['t'] + ct['a'] + ct['i'] + ct['o'] + ct['n'];
	rare = ct['v'] + ct['j'] + ct['k'] + ct['q'] + ct['x'] + ct['z'];
	if (2*ct[';'] > ct['e']) return(0);
	if ( (ct['>']+ct['<']+ct['/'])>ct['e']) return(0); /* shell file test */
	return (vow*5 >= n-ct[' '] && freq >= 10*rare);
I 15
}

shellscript(buf, sb)
	char buf[];
	struct stat *sb;
{
	register char *tp;
	char *cp, *xp, *index();

	cp = index(buf, '\n');
	if (cp == 0 || cp - buf > in)
		return (0);
	for (tp = buf; tp != cp && isspace(*tp); tp++)
		if (!isascii(*tp))
			return (0);
	for (xp = tp; tp != cp && !isspace(*tp); tp++)
		if (!isascii(*tp))
			return (0);
	if (tp == xp)
		return (0);
	if (sb->st_mode & S_ISUID)
		printf("set-uid ");
	if (sb->st_mode & S_ISGID)
		printf("set-gid ");
	if (strncmp(xp, "/bin/sh", tp-xp) == 0)
		xp = "shell";
	else if (strncmp(xp, "/bin/csh", tp-xp) == 0)
		xp = "c-shell";
	else
		*tp = '\0';
	printf("executable %s script\n", xp);
	return (1);
}

shell(bp, n, tab)
	char *bp;
	int n;
	char *tab[];
{

	i = 0;
	do {
		if (buf[i] == '#' || buf[i] == ':')
			while (i < n && buf[i] != '\n')
				i++;
		if (++i >= n)
			break;
		if (lookup(tab) == 1)
			return (1);
	} while (i < n);
	return (0);
E 15
}
E 1
