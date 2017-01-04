h35686
s 00080/00056/00132
d D 5.2 00/12/21 22:37:52 msokolov 2 1
c allow the input file to be specified on the command line
e
s 00188/00000/00000
d D 5.1 99/01/21 00:36:46 msokolov 1 0
c date and time created 99/01/21 00:36:46 by msokolov
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

/* gzcompat converts between compress -s and gzip formats. */

#include <stdio.h>

char magic_strong[2] = {037, 0241};
char magic_gzip[2]   = {037, 0213};

struct gzheader {
	unsigned char cm;
	unsigned char flg;
	unsigned char mtime[4];
	unsigned char xfl;
	unsigned char os;
} gzheader;

#define CM_DEFLATE 0x08

#define FTEXT    0x01
#define FHCRC    0x02
#define FEXTRA   0x04
#define FNAME    0x08
#define FCOMMENT 0x10
#define FRSVD    0xE0

#define OS_UNIX 0x03

D 2
int main()
E 2
I 2
int main(argc, argv)
	char **argv;
E 2
{
I 2
	FILE *infile;
	char *inname;
E 2
	char buf[4096];
	int len;
	int mkgzip;

I 2
	if (argc == 1) {
		infile = stdin;
		inname = "stdin";
	} else if (argc == 2) {
		inname = argv[1];
		infile = fopen(inname, "r");
		if (infile == NULL) {
			perror(inname);
			exit(1);
		}
	} else {
		fprintf(stderr, "usage: %s [infile]\n", argv[0]);
		exit(1);
	}

E 2
	/* First read the input magic number. */
D 2
	len = fread(buf, 1, 2, stdin);
E 2
I 2
	len = fread(buf, 1, 2, infile);
E 2
	if (len < 0) {
D 2
		perror("stdin");
		return 1;
E 2
I 2
		perror(inname);
		exit(1);
E 2
	}
	if (len != 2) {
D 2
		fprintf(stderr, "stdin: not in compress -s or gzip format\n");
		return 1;
E 2
I 2
		fprintf(stderr, "%s: not in compress -s or gzip format\n",
			inname);
		exit(1);
E 2
	}
	if (buf[0] == magic_strong[0] && buf[1] == magic_strong[1])
		mkgzip = 1;
	else if (buf[0] == magic_gzip[0] && buf[1] == magic_gzip[1])
		mkgzip = 0;
	else {
D 2
		fprintf(stderr, "stdin: not in compress -s or gzip format\n");
		return 1;
E 2
I 2
		fprintf(stderr, "%s: not in compress -s or gzip format\n",
			inname);
		exit(1);
E 2
	}

	/* Now read and check the gzip header if necessary. */
	if (!mkgzip) {
D 2
		len = fread(&gzheader, sizeof(struct gzheader), 1, stdin);
E 2
I 2
		len = fread(&gzheader, sizeof(struct gzheader), 1, infile);
E 2
		if (len < 0) {
D 2
			perror("stdin");
			return 1;
E 2
I 2
			perror(inname);
			exit(1);
E 2
		}
		if (len != 1) {
D 2
			fprintf(stderr, "stdin: invalid gzip header\n");
			return 1;
E 2
I 2
			fprintf(stderr, "%s: invalid gzip header\n", inname);
			exit(1);
E 2
		}
		if (gzheader.cm != CM_DEFLATE || gzheader.flg & FRSVD) {
D 2
			fprintf(stderr, "stdin: invalid gzip header\n");
			return 1;
E 2
I 2
			fprintf(stderr, "%s: invalid gzip header\n", inname);
			exit(1);
E 2
		}
		if (gzheader.flg & FEXTRA) {
			int count;

D 2
			count = getchar();
			if (ferror(stdin)) {
				perror("stdin");
				return 1;
E 2
I 2
			count = getc(infile);
			if (ferror(infile)) {
				perror(inname);
				exit(1);
E 2
			}
D 2
			if (feof(stdin)) {
				fprintf(stderr, "stdin: invalid gzip header\n");
				return 1;
E 2
I 2
			if (feof(infile)) {
				fprintf(stderr, "%s: invalid gzip header\n",
					inname);
				exit(1);
E 2
			}
			while (count) {
D 2
				getchar();
				if (ferror(stdin)) {
					perror("stdin");
					return 1;
E 2
I 2
				getc(infile);
				if (ferror(infile)) {
					perror(inname);
					exit(1);
E 2
				}
D 2
				if (feof(stdin)) {
					fprintf(stderr, "stdin: invalid gzip header\n");
					return 1;
E 2
I 2
				if (feof(infile)) {
					fprintf(stderr, "%s: invalid gzip header\n", inname);
					exit(1);
E 2
				}
				count--;
			}
		}
		if (gzheader.flg & FNAME) {
			int ch;

			do {
D 2
				ch = getchar();
				if (ferror(stdin)) {
					perror("stdin");
					return 1;
E 2
I 2
				ch = getc(infile);
				if (ferror(infile)) {
					perror(inname);
					exit(1);
E 2
				}
D 2
				if (feof(stdin)) {
					fprintf(stderr, "stdin: invalid gzip header\n");
					return 1;
E 2
I 2
				if (feof(infile)) {
					fprintf(stderr, "%s: invalid gzip header\n", inname);
					exit(1);
E 2
				}
			}
			while (ch);
		}
		if (gzheader.flg & FCOMMENT) {
			int ch;

			do {
D 2
				ch = getchar();
				if (ferror(stdin)) {
					perror("stdin");
					return 1;
E 2
I 2
				ch = getc(infile);
				if (ferror(infile)) {
					perror(inname);
					exit(1);
E 2
				}
D 2
				if (feof(stdin)) {
					fprintf(stderr, "stdin: invalid gzip header\n");
					return 1;
E 2
I 2
				if (feof(infile)) {
					fprintf(stderr, "%s: invalid gzip header\n", inname);
					exit(1);
E 2
				}
			}
			while (ch);
		}
		if (gzheader.flg & FHCRC) {
D 2
			len = fread(buf, 1, 2, stdin);
E 2
I 2
			len = fread(buf, 1, 2, infile);
E 2
			if (len < 0) {
D 2
				perror("stdin");
				return 1;
E 2
I 2
				perror(inname);
				exit(1);
E 2
			}
			if (len != 2) {
D 2
				fprintf(stderr, "stdin: invalid gzip header\n");
				return 1;
E 2
I 2
				fprintf(stderr, "%s: invalid gzip header\n",
					inname);
				exit(1);
E 2
			}
		}
	}

	/* Now write the output magic number. */
	if (mkgzip) {
		if (fwrite(magic_gzip, 1, 2, stdout) != 2) {
			perror("stdout");
D 2
			return 1;
E 2
I 2
			exit(1);
E 2
		}
	}
	else {
		if (fwrite(magic_strong, 1, 2, stdout) != 2) {
			perror("stdout");
D 2
			return 1;
E 2
I 2
			exit(1);
E 2
		}
	}

	/* Now write the gzip header if necessary. */
	if (mkgzip) {
		gzheader.cm = CM_DEFLATE;
		gzheader.flg = 0;
		gzheader.mtime[0] = 0;
		gzheader.mtime[1] = 0;
		gzheader.mtime[2] = 0;
		gzheader.mtime[3] = 0;
		gzheader.xfl = 0;
		gzheader.os = OS_UNIX;
		if (fwrite(&gzheader, sizeof(struct gzheader), 1, stdout) != 1) {
			perror("stdout");
D 2
			return 1;
E 2
I 2
			exit(1);
E 2
		}
	}

	/* Now actually copy the data! */
	for (;;) {
D 2
		len = fread(buf, 1, sizeof(buf), stdin);
E 2
I 2
		len = fread(buf, 1, sizeof(buf), infile);
E 2
		if (len < 0) {
D 2
			perror("stdin");
			return 1;
E 2
I 2
			perror(inname);
			exit(1);
E 2
		}
		if (len == 0)
			break;
		if (fwrite(buf, 1, len, stdout) != len) {
			perror("stdout");
D 2
			return 1;
E 2
I 2
			exit(1);
E 2
		}
	}

	/* I can't believe we're done! */
D 2
	return 0;
E 2
I 2
	if (argc == 2)
		fclose(infile);
	return(0);
E 2
}
E 1
