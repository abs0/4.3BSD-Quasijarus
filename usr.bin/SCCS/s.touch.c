h19277
s 00051/00052/00071
d D 4.6 87/09/14 17:07:19 bostic 7 6
c usage if no args, exit correct value; bug report 4.3BSD/usr.bin/69
e
s 00019/00022/00104
d D 4.5 87/06/29 09:28:30 bostic 6 4
c long/int problems, getopt(3) added
e
s 00017/00020/00106
d R 4.5 87/05/02 16:11:23 bostic 5 4
c fix long/int problems, use getopt for arg parseing
e
s 00002/00001/00124
d D 4.4 87/04/06 12:28:29 bostic 4 3
c access had hard-coded values
e
s 00003/00003/00122
d D 4.3 83/08/11 20:27:58 sam 3 2
c standardize sccs keyword lines
e
s 00108/00054/00017
d D 4.2 82/06/09 16:57:17 mckusick 2 1
c merge system forced touch with user touch (peter)
e
s 00071/00000/00000
d D 4.1 80/10/01 17:28:59 bill 1 0
c date and time created 80/10/01 17:28:59 by bill
e
u
U
t
T
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
D 3
#ifndef LINT
static	char *sccsid = "%W% (Berkeley) %E%";
#endif not LINT
E 3
I 3
#ifndef lint
static	char sccsid[] = "%W% (Berkeley) %G%";
#endif
E 3

/*
 *	attempt to set the modify date of a file to the current date.
 *	if the file exists, read and write its first character.
 *	if the file doesn't exist, create it, unless -c option prevents it.
 *	if the file is read-only, -f forces chmod'ing and touch'ing.
 */

E 2
#include <stdio.h>
I 2
#include <sys/types.h>
I 4
#include <sys/file.h>
E 4
#include <sys/stat.h>
E 2

I 2
int	dontcreate;	/* set if -c option */
int	force;		/* set if -f option */
E 2

I 2
D 7
char *whoami = "touch";

E 2
main(argc,argv)
E 7
I 7
main(argc, argv)
E 7
D 2
int argc;
char *argv[];
E 2
I 2
	int	argc;
	char	**argv;
E 2
{
D 2
int i;
static int force = 1;
E 2
I 2
D 6
	char	*argp;
E 6
I 6
	extern int optind;
D 7
	int ch;
E 7
I 7
	int ch, retval;
E 7
E 6
E 2

D 2
for(i = 1 ; i < argc ; ++i)
	if( strcmp(argv[i], "-c") )
		touch(force, argv[i]);
	else
		force = 0;
E 2
I 2
D 6
	dontcreate = 0;
	force = 0;
	for (argv++; **argv == '-'; argv++) {
		for (argp = &(*argv)[1]; *argp; argp++) {
			switch (*argp) {
			case 'c':
				dontcreate = 1;
				break;
			case 'f':
				force = 1;
				break;
			default:
				fprintf(stderr, "%s: bad option -%c\n",
					whoami, *argp);
				exit(1);
			}
E 6
I 6
D 7
	dontcreate = force = 0;
E 7
I 7
	dontcreate = force = retval = 0;
E 7
	while ((ch = getopt(argc, argv, "cf")) != EOF)
		switch((char)ch) {
		case 'c':
			dontcreate = 1;
			break;
		case 'f':
			force = 1;
			break;
		case '?':
		default:
D 7
			fprintf(stderr, "usage: %s [-cf] file ...\n", whoami);
			exit(1);
E 7
I 7
			usage();
E 7
E 6
		}
D 6
	}
	for (/*void*/; *argv; argv++) {
E 6
I 6
D 7
	for (argv += optind; *argv; ++argv)
E 6
		touch(*argv);
E 7
I 7
	if (!*(argv += optind))
		usage();
	do {
		retval |= touch(*argv);
	} while (*++argv);
	exit(retval);
E 7
D 6
	}
E 6
E 2
}

D 2



#include <sys/types.h>
#include <sys/stat.h>


touch(force, name)
int force;
char *name;
E 2
I 2
touch(filename)
	char	*filename;
E 2
{
D 2
struct stat stbuff;
char junk[1];
int fd;
E 2
I 2
	struct stat	statbuffer;
E 2

D 2
if( stat(name,&stbuff) < 0)
	if(force)
		goto create;
	else
		{
		fprintf(stderr, "touch: file %s does not exist.\n", name);
E 2
I 2
D 7
	if (stat(filename,&statbuffer) == -1) {
		if (!dontcreate) {
D 6
			readwrite(filename,0);
E 6
I 6
			readwrite(filename,0L);
E 6
		} else {
			fprintf(stderr, "%s: %s: does not exist\n",
				whoami, filename);
		}
E 2
		return;
E 7
I 7
	if (stat(filename, &statbuffer) == -1) {
		if (!dontcreate)
			return(readwrite(filename, 0L));
		fprintf(stderr, "touch: %s: does not exist\n", filename);
		return(1);
E 7
I 2
	}
	if ((statbuffer.st_mode & S_IFMT) != S_IFREG) {
D 7
		fprintf(stderr, "%s: %s: can only touch regular files\n",
			whoami, filename);
		return;
E 7
I 7
		fprintf(stderr, "touch: %s: can only touch regular files\n",
			filename);
		return(1);
E 7
	}
D 4
	if (!access(filename,4|2)) {
E 4
I 4
D 7
	if (!access(filename,R_OK | W_OK)) {
E 4
		readwrite(filename,statbuffer.st_size);
		return;
	}
E 7
I 7
	if (!access(filename, R_OK | W_OK))
		return(readwrite(filename,statbuffer.st_size));
E 7
	if (force) {
I 7
		int	retval;

E 7
		if (chmod(filename,0666)) {
D 7
			fprintf(stderr, "%s: %s: couldn't chmod: ",
				whoami, filename);
			perror("");
			return;
E 7
I 7
			fprintf(stderr, "touch: %s: couldn't chmod: ", filename);
			perror((char *)NULL);
			return(1);
E 7
E 2
		}
I 2
D 7
		readwrite(filename,statbuffer.st_size);
E 7
I 7
		retval = readwrite(filename,statbuffer.st_size);
E 7
		if (chmod(filename,statbuffer.st_mode)) {
D 7
			fprintf(stderr, "%s: %s: couldn't chmod back: ",
				whoami, filename);
			perror("");
			return;
E 7
I 7
			fprintf(stderr, "touch: %s: couldn't chmod back: ",
				filename);
			perror((char *)NULL);
			return(1);
E 7
		}
D 7
	} else {
		fprintf(stderr, "%s: %s: cannot touch\n", whoami, filename);
E 7
I 7
		return(retval);
E 7
	}
I 7
	fprintf(stderr, "touch: %s: cannot touch\n", filename);
	return(1);
E 7
}
E 2

D 2
if(stbuff.st_size == 0)
	goto create;
E 2
I 2
D 7
readwrite(filename,size)
E 7
I 7
readwrite(filename, size)
E 7
	char	*filename;
D 6
	int	size;
E 6
I 6
	off_t	size;
E 6
{
	int	filedescriptor;
	char	first;
I 6
	off_t	lseek();
E 6
E 2

D 2
if( (fd = open(name, 2)) < 0)
	goto bad;

if( read(fd, junk, 1) < 1)
	{
	close(fd);
	goto bad;
E 2
I 2
	if (size) {
D 7
		filedescriptor = open(filename,2);
E 7
I 7
		filedescriptor = open(filename, O_RDWR, 0);
E 7
		if (filedescriptor == -1) {
D 7
error:
			fprintf(stderr, "%s: %s: ", whoami, filename);
			perror("");
			return;
E 7
I 7
error:			fprintf(stderr, "touch: %s: ", filename);
			perror((char *)NULL);
			return(1);
E 7
		}
D 7
		if (read(filedescriptor, &first, 1) != 1) {
E 7
I 7
		if (read(filedescriptor, &first, 1) != 1)
E 7
			goto error;
D 7
		}
		if (lseek(filedescriptor,0l,0) == -1) {
E 7
I 7
		if (lseek(filedescriptor, 0L, 0) == -1)
E 7
			goto error;
D 7
		}
		if (write(filedescriptor, &first, 1) != 1) {
E 7
I 7
		if (write(filedescriptor, &first, 1) != 1)
E 7
			goto error;
D 7
		}
E 7
	} else {
D 7
		filedescriptor = creat(filename,0666);
		if (filedescriptor == -1) {
E 7
I 7
		filedescriptor = creat(filename, 0666);
		if (filedescriptor == -1)
E 7
			goto error;
D 7
		}
E 7
E 2
	}
D 2
lseek(fd, 0L, 0);
if( write(fd, junk, 1) < 1 )
	{
	close(fd);
	goto bad;
E 2
I 2
D 7
	if (close(filedescriptor) == -1) {
E 7
I 7
	if (close(filedescriptor) == -1)
E 7
		goto error;
E 2
D 7
	}
E 7
I 7
	return(0);
}

usage()
{
	fputs("usage: touch [-cf] file ...\n", stderr);
	exit(1);
E 7
D 2
close(fd);
return;

bad:
	fprintf(stderr, "Cannot touch %s\n", name);
	return;

create:
	if( (fd = creat(name, 0666)) < 0)
		goto bad;
	close(fd);
E 2
}
E 1
