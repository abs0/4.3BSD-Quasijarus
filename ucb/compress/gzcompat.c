#ifndef lint
static char sccsid[] = "@(#)gzcompat.c	5.2 (Berkeley) 12/21/00";
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

int main(argc, argv)
	char **argv;
{
	FILE *infile;
	char *inname;
	char buf[4096];
	int len;
	int mkgzip;

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

	/* First read the input magic number. */
	len = fread(buf, 1, 2, infile);
	if (len < 0) {
		perror(inname);
		exit(1);
	}
	if (len != 2) {
		fprintf(stderr, "%s: not in compress -s or gzip format\n",
			inname);
		exit(1);
	}
	if (buf[0] == magic_strong[0] && buf[1] == magic_strong[1])
		mkgzip = 1;
	else if (buf[0] == magic_gzip[0] && buf[1] == magic_gzip[1])
		mkgzip = 0;
	else {
		fprintf(stderr, "%s: not in compress -s or gzip format\n",
			inname);
		exit(1);
	}

	/* Now read and check the gzip header if necessary. */
	if (!mkgzip) {
		len = fread(&gzheader, sizeof(struct gzheader), 1, infile);
		if (len < 0) {
			perror(inname);
			exit(1);
		}
		if (len != 1) {
			fprintf(stderr, "%s: invalid gzip header\n", inname);
			exit(1);
		}
		if (gzheader.cm != CM_DEFLATE || gzheader.flg & FRSVD) {
			fprintf(stderr, "%s: invalid gzip header\n", inname);
			exit(1);
		}
		if (gzheader.flg & FEXTRA) {
			int count;

			count = getc(infile);
			if (ferror(infile)) {
				perror(inname);
				exit(1);
			}
			if (feof(infile)) {
				fprintf(stderr, "%s: invalid gzip header\n",
					inname);
				exit(1);
			}
			while (count) {
				getc(infile);
				if (ferror(infile)) {
					perror(inname);
					exit(1);
				}
				if (feof(infile)) {
					fprintf(stderr, "%s: invalid gzip header\n", inname);
					exit(1);
				}
				count--;
			}
		}
		if (gzheader.flg & FNAME) {
			int ch;

			do {
				ch = getc(infile);
				if (ferror(infile)) {
					perror(inname);
					exit(1);
				}
				if (feof(infile)) {
					fprintf(stderr, "%s: invalid gzip header\n", inname);
					exit(1);
				}
			}
			while (ch);
		}
		if (gzheader.flg & FCOMMENT) {
			int ch;

			do {
				ch = getc(infile);
				if (ferror(infile)) {
					perror(inname);
					exit(1);
				}
				if (feof(infile)) {
					fprintf(stderr, "%s: invalid gzip header\n", inname);
					exit(1);
				}
			}
			while (ch);
		}
		if (gzheader.flg & FHCRC) {
			len = fread(buf, 1, 2, infile);
			if (len < 0) {
				perror(inname);
				exit(1);
			}
			if (len != 2) {
				fprintf(stderr, "%s: invalid gzip header\n",
					inname);
				exit(1);
			}
		}
	}

	/* Now write the output magic number. */
	if (mkgzip) {
		if (fwrite(magic_gzip, 1, 2, stdout) != 2) {
			perror("stdout");
			exit(1);
		}
	}
	else {
		if (fwrite(magic_strong, 1, 2, stdout) != 2) {
			perror("stdout");
			exit(1);
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
			exit(1);
		}
	}

	/* Now actually copy the data! */
	for (;;) {
		len = fread(buf, 1, sizeof(buf), infile);
		if (len < 0) {
			perror(inname);
			exit(1);
		}
		if (len == 0)
			break;
		if (fwrite(buf, 1, len, stdout) != len) {
			perror("stdout");
			exit(1);
		}
	}

	/* I can't believe we're done! */
	if (argc == 2)
		fclose(infile);
	return(0);
}
