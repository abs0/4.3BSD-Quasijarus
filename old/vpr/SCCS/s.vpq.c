h33054
s 00002/00002/00153
d D 1.4 87/11/04 21:14:38 bostic 6 5
c fix includes
e
s 00015/00018/00140
d D 1.3 82/08/06 17:20:39 mckusick 5 4
c update to new directory structure
e
s 00005/00002/00153
d D 1.2 81/02/12 15:42:40 halbert 4 1
c Added printing of C and V commands lines; removed printing of B
c lines.  This is for vdmp and vpltdmp.  (Dan Fitzpatrick)
e
s 00005/00002/00153
d R 1.2 81/02/12 15:17:54 halbert 3 1
c added command line printing for commands C and V; removed B.
c Done for vdmp and vpltdmp software. (Dan Fitzpatrick)
e
s 00005/00002/00153
d R 1.2 81/02/12 15:11:02 halbert 2 1
c added printing of C and V command lines; removed printing of
c B command lines.  (For vdmp and vpltdmp; Dan Fitzpatrick)
e
s 00155/00000/00000
d D 1.1 80/11/30 15:56:31 root 1 0
c date and time created 80/11/30 15:56:31 by root
e
u
U
t
T
I 1
D 4
/*
E 4
I 4
/* %M%		%G%
E 4
 * Varian and Versatec queue
 */

I 4
static char vpqSCCSid[] = "%W%\t%G%";

E 4
D 5
#include <sys/types.h>
E 5
I 5
#include <sys/param.h>
E 5
D 6
#include <dir.h>
#include <stat.h>
E 6
I 6
#include <sys/dir.h>
#include <sys/stat.h>
E 6
#include <stdio.h>
#include <errno.h>
#define	MAXJOBS 100

D 5
struct	dir dirent;
E 5
struct	stat stbuf;
int	nextflag;
int	linecnt;
D 5
FILE	*df;
E 5
FILE	*jf;
char	line[100];
char	username[10];
int	cnt;
extern	int errno;
extern	char _sobuf[];

main(argc, argv)
int argc;
char **argv;
{
	int varian = 1;
	int versatec = 1;

	setbuf(stdout, _sobuf);

	argc--, argv++;
	while (argc > 0 && argv[0][0] == '-') {
		switch (argv[0][1]) {

		case 'W':		/* Wide: the versatec. */
			varian = 0;
			versatec++;
			break;

		case 'b':
			varian++;
			versatec++;
			break;

		default:
			fprintf(stderr, "usage: vpq [ -W ] [ -b ]\n");
			exit(1);
		}
		argc--, argv++;
	}
	if (varian)
		queue("/dev/va0", "Varian", "/usr/spool/vad", "/usr/lib/vad");
	if (versatec)
		queue("/dev/vp0", "Versatec", "/usr/spool/vpd", "/usr/lib/vpd");
	exit(0);
}


queue(device, devname, spooldir, daemon)
char *device, *devname, *spooldir, *daemon;
{
	FILE *vc;
I 5
	DIR *df;
	register struct direct *dirp;
E 5

	printf("%s: ", devname);
	vc = fopen(device, "w");
	if (vc == NULL) {
		if (errno == EIO)
			printf("offline\n");
		else if (errno == ENXIO)
			printf("in use\n");
		else
			printf("not available\n");
	} else {
		printf("ready and idle.\n");
		fclose(vc);
	}
	if (access(daemon, 1))
		printf("Daemon is disabled.\n");
	if (chdir(spooldir) < 0) {
		perror(spooldir);
		return;
	}
D 5
oloop:
	df = fopen(".", "r");
E 5
I 5
	df = opendir(".");
E 5
	if (df == NULL) {
		perror(spooldir);
		return;
	}
D 5
loop:
	fseek(df, 0l, 0);
E 5
	linecnt = 0;
	cnt = 0;
D 5
	while (fread(&dirent, sizeof dirent, 1, df) == 1) {
		if (dirent.d_ino == 0)
E 5
I 5
	while ((dirp = readdir(df)) != NULL) {
		if (dirp->d_name[0] != 'd')
E 5
			continue;
D 5
		if (dirent.d_name[0] != 'd')
E 5
I 5
		if (dirp->d_name[1] != 'f')
E 5
			continue;
D 5
		if (dirent.d_name[1] != 'f')
E 5
I 5
		if (stat(dirp->d_name, &stbuf) < 0)
E 5
			continue;
D 5
		if (stat(dirent.d_name, &stbuf) < 0)
			continue;
E 5
		if (cnt == 0)
			printf("Owner\t  Id      Chars  Filename\n");
		cnt++;
D 5
		process();
E 5
I 5
		process(dirp);
E 5
	}
I 5
	closedir(df);
E 5
	if (cnt == 0)
		printf("Queue is empty.\n");
	printf("\n");
}

D 5
process()
E 5
I 5
process(dirp)
	register struct direct *dirp;
E 5
{

D 5
	jf = fopen(dirent.d_name, "r");
E 5
I 5
	jf = fopen(dirp->d_name, "r");
E 5
	if (jf == NULL)
		return;
	while (getline()) {
		switch (line[0]) {

		case 'L':
			strcpy(username, line+1);
			break;

D 4
		case 'B':
E 4
I 4
		case 'C':
		case 'V':
E 4
		case 'F':
		case 'G':
		case 'P':
		case 'T':
			if (stat(line+1, &stbuf) < 0)
				stbuf.st_size = 0;
D 5
			printf("%-10s%5s%8d  %s\n", username, dirent.d_name+3,
			    stbuf.st_size, line+1);
E 5
I 5
			printf("%-10s%5s%8d  %s\n", username,
			    &(dirp->d_name[3]), stbuf.st_size, line+1);
E 5
			break;
		}
	}
	fclose(jf);
}

getline()
{
	register int i, c;

	i = 0;
	while ((c = getc(jf)) != '\n') {
		if (c <= 0)
			return(0);
		if (i < 100)
			line[i++] = c;
	}
	line[i++] = 0;
	return (1);
}
E 1
