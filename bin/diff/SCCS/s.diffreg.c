h49943
s 00004/00006/01044
d D 4.18 03/07/10 23:03:14 msokolov 18 17
c add -a option to disable the check for binary files
c add -J debug option to report the "jackpot"
e
s 00001/00001/01049
d D 4.17 87/10/22 10:04:42 bostic 17 16
c ANSI C; sprintf now returns an int.
e
s 00003/00000/01047
d D 4.16 86/03/29 02:07:45 lepreau 16 15
c avoid problems if one file is prefix of another (from mann@su-pescadero.arpa)
e
s 00001/00001/01046
d D 4.15 86/02/16 17:07:39 van 15 14
c fix abort if diff -c & files same
e
s 00025/00004/01022
d D 4.14 86/01/13 20:27:46 mckusick 14 13
c fix for directory comparison (from sun!gorodish!guy)
e
s 00010/00000/01016
d D 4.13 85/08/16 21:12:33 van 13 12
c added -n flag from rcs diff
e
s 00048/00043/00968
d D 4.12 85/08/16 18:49:00 mckusick 12 11
c changes to make diff -c work with patch
e
s 00022/00007/00989
d D 4.11 85/08/13 04:30:39 lepreau 11 10
c put back urem avoidance speedup rm'ed in last delta; other minor speedups
e
s 00278/00075/00718
d D 4.10 85/06/07 03:03:03 van 10 9
c added -w, -i & -t flags.  Changed -c output to group together
c adjacent changes.
e
s 00000/00001/00793
d D 4.9 85/06/03 23:13:38 lepreau 9 8
c speedup by pitching the "compacting" realloc, which loses with new malloc
e
s 00008/00005/00786
d D 4.8 85/04/11 09:05:47 ralph 8 7
c speedups.
e
s 00000/00002/00791
d D 4.7 83/02/28 16:19:14 sam 7 6
c spurious fclose's cause core dumps (budah say)
e
s 00003/00003/00790
d D 4.6 82/11/08 11:50:44 rrh 6 5
c Fix order of 2nd and 3rd arguments to fread so the count of the
c number of bytes read is correctly returned
e
s 00005/00000/00788
d D 4.5 82/11/06 16:06:30 rrh 5 4
c Correctly set the return status (0 or 1) after doing byte by byte compare
e
s 00039/00005/00749
d D 4.4 82/10/29 15:22:48 mckusick 4 3
c cannot mix non-stdio with stdio!!!
e
s 00053/00014/00701
d D 4.3 82/10/22 17:16:48 mckusick 3 2
c don't try to do diffs of binary files
e
s 00001/00001/00714
d D 4.2 82/05/05 14:04:34 sam 2 1
c missing arg
e
s 00715/00000/00000
d D 4.1 80/10/09 22:46:51 bill 1 0
c date and time created 80/10/09 22:46:51 by bill
e
u
U
t
T
I 1
static	char sccsid[] = "%Z%%M% %I% %G%";

#include "diff.h"
/*
 * diff - compare two files.
 */

/*
 *	Uses an algorithm due to Harold Stone, which finds
 *	a pair of longest identical subsequences in the two
 *	files.
 *
 *	The major goal is to generate the match vector J.
 *	J[i] is the index of the line in file1 corresponding
 *	to line i file0. J[i] = 0 if there is no
 *	such line in file1.
 *
 *	Lines are hashed so as to work in core. All potential
 *	matches are located by sorting the lines of each file
 *	on the hash (called ``value''). In particular, this
 *	collects the equivalence classes in file1 together.
 *	Subroutine equiv replaces the value of each line in
 *	file0 by the index of the first element of its 
 *	matching equivalence in (the reordered) file1.
 *	To save space equiv squeezes file1 into a single
 *	array member in which the equivalence classes
 *	are simply concatenated, except that their first
 *	members are flagged by changing sign.
 *
 *	Next the indices that point into member are unsorted into
 *	array class according to the original order of file0.
 *
 *	The cleverness lies in routine stone. This marches
 *	through the lines of file0, developing a vector klist
 *	of "k-candidates". At step i a k-candidate is a matched
 *	pair of lines x,y (x in file0 y in file1) such that
 *	there is a common subsequence of length k
 *	between the first i lines of file0 and the first y 
 *	lines of file1, but there is no such subsequence for
 *	any smaller y. x is the earliest possible mate to y
 *	that occurs in such a subsequence.
 *
 *	Whenever any of the members of the equivalence class of
 *	lines in file1 matable to a line in file0 has serial number 
 *	less than the y of some k-candidate, that k-candidate 
 *	with the smallest such y is replaced. The new 
 *	k-candidate is chained (via pred) to the current
 *	k-1 candidate so that the actual subsequence can
 *	be recovered. When a member has serial number greater
 *	that the y of all k-candidates, the klist is extended.
 *	At the end, the longest subsequence is pulled out
 *	and placed in the array J by unravel
 *
 *	With J in hand, the matches there recorded are
 *	check'ed against reality to assure that no spurious
 *	matches have crept in due to hashing. If they have,
 *	they are broken, and "jackpot" is recorded--a harmless
 *	matter except that a true match for a spuriously
 *	mated line may now be unnecessarily reported as a change.
 *
 *	Much of the complexity of the program comes simply
 *	from trying to minimize core utilization and
 *	maximize the range of doable problems by dynamically
 *	allocating what is needed and reusing what is not.
 *	The core requirements for problems larger than somewhat
 *	are (in words) 2*length(file0) + length(file1) +
 *	3*(number of k-candidates installed),  typically about
 *	6n words for files of length n. 
 */

#define	prints(s)	fputs(s,stdout)

FILE	*input[2];
FILE	*fopen();

struct cand {
	int	x;
	int	y;
	int	pred;
} cand;
struct line {
	int	serial;
	int	value;
} *file[2], line;
int	len[2];
struct	line *sfile[2];	/* shortened by pruning common prefix and suffix */
int	slen[2];
int	pref, suff;	/* length of prefix and suffix */
int	*class;		/* will be overlaid on file[0] */
int	*member;	/* will be overlaid on file[1] */
int	*klist;		/* will be overlaid on file[0] after class */
struct	cand *clist;	/* merely a free storage pot for candidates */
int	clen = 0;
int	*J;		/* will be overlaid on class */
long	*ixold;		/* will be overlaid on klist */
long	*ixnew;		/* will be overlaid on file[1] */
I 10
char	*chrtran;	/* translation table for case-folding */
E 10

I 10
/* chrtran points to one of 2 translation tables:
 *	cup2low if folding upper to lower case
 *	clow2low if not folding case
 */
char	clow2low[256] = {
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x5f,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,
0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x9f,
0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,
0xb0,0xb1,0xb2,0xb3,0xb4,0xb5,0xb6,0xb7,0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0xbe,0xbf,
0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,
0xd0,0xd1,0xd2,0xd3,0xd4,0xd5,0xd6,0xd7,0xd8,0xd9,0xda,0xdb,0xdc,0xdd,0xde,0xdf,
0xe0,0xe1,0xe2,0xe3,0xe4,0xe5,0xe6,0xe7,0xe8,0xe9,0xea,0xeb,0xec,0xed,0xee,0xef,
0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff
};

char	cup2low[256] = {
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,
0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x9f,
0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,
0xb0,0xb1,0xb2,0xb3,0xb4,0xb5,0xb6,0xb7,0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0xbe,0xbf,
0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,
0xd0,0xd1,0xd2,0xd3,0xd4,0xd5,0xd6,0xd7,0xd8,0xd9,0xda,0xdb,0xdc,0xdd,0xde,0xdf,
0xe0,0xe1,0xe2,0xe3,0xe4,0xe5,0xe6,0xe7,0xe8,0xe9,0xea,0xeb,0xec,0xed,0xee,0xef,
0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff
};

E 10
diffreg()
{
D 3
	register int k;
E 3
I 3
	register int i, j;
	FILE *f1, *f2;
	char buf1[BUFSIZ], buf2[BUFSIZ];
E 3

	if (hflag) {
		diffargv[0] = "diffh";
		execv(diffh, diffargv);
		fprintf(stderr, "diff: ");
		perror(diffh);
		done();
	}
I 10
	chrtran = (iflag? cup2low : clow2low);
E 10
D 9
	dummy = malloc(1);
E 9
D 14
	if ((stb1.st_mode & S_IFMT) == S_IFDIR)
E 14
I 14
	if ((stb1.st_mode & S_IFMT) == S_IFDIR) {
E 14
		file1 = splice(file1, file2);
D 14
	else if ((stb2.st_mode & S_IFMT) == S_IFDIR)
E 14
I 14
		if (stat(file1, &stb1) < 0) {
			fprintf(stderr, "diff: ");
			perror(file1);
			done();
		}
	} else if ((stb2.st_mode & S_IFMT) == S_IFDIR) {
E 14
		file2 = splice(file2, file1);
D 14
	else if (!strcmp(file1, "-")) {
E 14
I 14
		if (stat(file2, &stb2) < 0) {
			fprintf(stderr, "diff: ");
			perror(file2);
			done();
		}
	} else if (!strcmp(file1, "-")) {
E 14
		if (!strcmp(file2, "-")) {
			fprintf(stderr, "diff: can't specify - -\n");
			done();
		}
		file1 = copytemp();
D 14
	} else if (!strcmp(file2, "-"))
E 14
I 14
		if (stat(file1, &stb1) < 0) {
			fprintf(stderr, "diff: ");
			perror(file1);
			done();
		}
	} else if (!strcmp(file2, "-")) {
E 14
		file2 = copytemp();
I 14
		if (stat(file2, &stb2) < 0) {
			fprintf(stderr, "diff: ");
			perror(file2);
			done();
		}
	}
E 14
D 3
	prepare(0, file1);
	prepare(1, file2);
E 3
I 3
	if ((f1 = fopen(file1, "r")) == NULL) {
		fprintf(stderr, "diff: ");
		perror(file1);
D 7
		fclose(f1);
E 7
		done();
	}
	if ((f2 = fopen(file2, "r")) == NULL) {
		fprintf(stderr, "diff: ");
		perror(file2);
		fclose(f1);
D 7
		fclose(f2);
E 7
		done();
	}
	if (stb1.st_size != stb2.st_size)
		goto notsame;
	for (;;) {
D 6
		i = fread(buf1, BUFSIZ, 1, f1);
		j = fread(buf2, BUFSIZ, 1, f2);
E 6
I 6
		i = fread(buf1, 1, BUFSIZ, f1);
		j = fread(buf2, 1, BUFSIZ, f2);
E 6
		if (i < 0 || j < 0 || i != j)
			goto notsame;
		if (i == 0 && j == 0) {
			fclose(f1);
			fclose(f2);
I 5
			status = 0;		/* files don't differ */
E 5
			goto same;
		}
		for (j = 0; j < i; j++)
			if (buf1[j] != buf2[j])
				goto notsame;
	}
notsame:
I 5
	/*
	 *	Files certainly differ at this point; set status accordingly
	 */
	status = 1;
E 5
D 4
	if (!ascii(fileno(f1)) || !ascii(fileno(f2))) {
E 4
I 4
D 18
	if (!asciifile(f1) || !asciifile(f2)) {
E 18
I 18
	if (!aflag && (!asciifile(f1) || !asciifile(f2))) {
E 18
E 4
		printf("Binary files %s and %s differ\n", file1, file2);
		fclose(f1);
		fclose(f2);
		done();
	}
	prepare(0, f1);
	prepare(1, f2);
	fclose(f1);
	fclose(f2);
E 3
	prune();
	sort(sfile[0],slen[0]);
	sort(sfile[1],slen[1]);

	member = (int *)file[1];
	equiv(sfile[0], slen[0], sfile[1], slen[1], member);
	member = (int *)ralloc((char *)member,(slen[1]+2)*sizeof(int));

	class = (int *)file[0];
	unsort(sfile[0], slen[0], class);
	class = (int *)ralloc((char *)class,(slen[0]+2)*sizeof(int));

	klist = (int *)talloc((slen[0]+2)*sizeof(int));
	clist = (struct cand *)talloc(sizeof(cand));
D 3
	k = stone(class, slen[0], member, klist);
E 3
I 3
	i = stone(class, slen[0], member, klist);
E 3
	free((char *)member);
	free((char *)class);

	J = (int *)talloc((len[0]+2)*sizeof(int));
D 3
	unravel(klist[k]);
E 3
I 3
	unravel(klist[i]);
E 3
	free((char *)clist);
	free((char *)klist);

	ixold = (long *)talloc((len[0]+2)*sizeof(long));
	ixnew = (long *)talloc((len[1]+2)*sizeof(long));
	check();
	output();
	status = anychange;
I 3
same:
E 3
	if (opt == D_CONTEXT && anychange == 0)
		printf("No differences encountered\n");
	done();
}

char *
copytemp()
{
	char buf[BUFSIZ];
	register int i, f;

	signal(SIGHUP,done);
	signal(SIGINT,done);
	signal(SIGPIPE,done);
	signal(SIGTERM,done);
	tempfile = mktemp("/tmp/dXXXXX");
	f = creat(tempfile,0600);
	if (f < 0) {
D 2
		fprintf("diff: ");
E 2
I 2
		fprintf(stderr, "diff: ");
E 2
		perror(tempfile);
		done();
	}
	while ((i = read(0,buf,BUFSIZ)) > 0)
		if (write(f,buf,i) != i) {
			fprintf(stderr, "diff: ");
			perror(tempfile);
			done();
		}
	close(f);
	return (tempfile);
}

char *
splice(dir, file)
	char *dir, *file;
{
	char *tail;
	char buf[BUFSIZ];

	if (!strcmp(file, "-")) {
		fprintf(stderr, "diff: can't specify - with other arg directory\n");
		done();
	}
	tail = rindex(file, '/');
	if (tail == 0)
		tail = file;
	else
		tail++;
D 17
	sprintf(buf, "%s/%s", dir, tail);
E 17
I 17
	(void)sprintf(buf, "%s/%s", dir, tail);
E 17
	return (savestr(buf));
}

D 3
prepare(i, arg)
char *arg;
E 3
I 3
prepare(i, fd)
	int i;
	FILE *fd;
E 3
{
	register struct line *p;
	register j,h;
D 3
	if((input[i] = fopen(arg,"r")) == NULL){
		fprintf(stderr, "diff: ");
		perror(arg);
		done();
	}
E 3
I 3

D 4
	input[i] = fd;
E 4
	fseek(fd, (long)0, 0);
E 3
	p = (struct line *)talloc(3*sizeof(line));
D 3
	for(j=0; h=readhash(input[i]);) {
E 3
I 3
	for(j=0; h=readhash(fd);) {
E 3
		p = (struct line *)ralloc((char *)p,(++j+3)*sizeof(line));
		p[j].value = h;
	}
	len[i] = j;
	file[i] = p;
D 3
	fclose(input[i]);
E 3
}

prune()
{
	register i,j;
	for(pref=0;pref<len[0]&&pref<len[1]&&
		file[0][pref+1].value==file[1][pref+1].value;
		pref++ ) ;
	for(suff=0;suff<len[0]-pref&&suff<len[1]-pref&&
		file[0][len[0]-suff].value==file[1][len[1]-suff].value;
		suff++) ;
	for(j=0;j<2;j++) {
		sfile[j] = file[j]+pref;
		slen[j] = len[j]-pref-suff;
		for(i=0;i<=slen[j];i++)
			sfile[j][i].serial = i;
	}
}

equiv(a,n,b,m,c)
struct line *a, *b;
int *c;
{
	register int i, j;
	i = j = 1;
	while(i<=n && j<=m) {
		if(a[i].value <b[j].value)
			a[i++].value = 0;
		else if(a[i].value == b[j].value)
			a[i++].value = j;
		else
			j++;
	}
	while(i <= n)
		a[i++].value = 0;
	b[m+1].value = 0;
	j = 0;
	while(++j <= m) {
		c[j] = -b[j].serial;
		while(b[j+1].value == b[j].value) {
			j++;
			c[j] = b[j].serial;
		}
	}
	c[j] = -1;
}

stone(a,n,b,c)
int *a;
int *b;
D 8
int *c;
E 8
I 8
register int *c;
E 8
{
	register int i, k,y;
	int j, l;
	int oldc, tc;
	int oldl;
	k = 0;
	c[0] = newcand(0,0,0);
	for(i=1; i<=n; i++) {
		j = a[i];
		if(j==0)
			continue;
		y = -b[j];
		oldl = 0;
		oldc = c[0];
		do {
			if(y <= clist[oldc].y)
				continue;
			l = search(c, k, y);
			if(l!=oldl+1)
				oldc = c[l-1];
			if(l<=k) {
				if(clist[c[l]].y <= y)
					continue;
				tc = c[l];
				c[l] = newcand(i,y,oldc);
				oldc = tc;
				oldl = l;
			} else {
				c[l] = newcand(i,y,oldc);
				k++;
				break;
			}
		} while((y=b[++j]) > 0);
	}
	return(k);
}

newcand(x,y,pred)
{
	register struct cand *q;
	clist = (struct cand *)ralloc((char *)clist,++clen*sizeof(cand));
	q = clist + clen -1;
	q->x = x;
	q->y = y;
	q->pred = pred;
	return(clen-1);
}

search(c, k, y)
int *c;
{
	register int i, j, l;
	int t;
	if(clist[c[k]].y<y)	/*quick look for typical case*/
		return(k+1);
	i = 0;
	j = k+1;
D 8
	while((l=(i+j)/2) > i) {
E 8
I 8
	while (1) {
		l = i + j;
		if ((l >>= 1) <= i) 
			break;
E 8
		t = clist[c[l]].y;
		if(t > y)
			j = l;
		else if(t < y)
			i = l;
		else
			return(l);
	}
	return(l+1);
}

unravel(p)
{
	register int i;
	register struct cand *q;
	for(i=0; i<=len[0]; i++)
		J[i] =	i<=pref ? i:
			i>len[0]-suff ? i+len[1]-len[0]:
			0;
	for(q=clist+p;q->y!=0;q=clist+q->pred)
		J[q->x+pref] = q->y+pref;
}

/* check does double duty:
1.  ferret out any fortuitous correspondences due
to confounding by hashing (which result in "jackpot")
2.  collect random access indexes to the two files */

check()
{
	register int i, j;
	int jackpot;
	long ctold, ctnew;
D 11
	char c,d;
E 11
I 11
	register int c,d;
E 11
D 4
	input[0] = fopen(file1,"r");
	input[1] = fopen(file2,"r");
E 4
I 4

	if ((input[0] = fopen(file1,"r")) == NULL) {
		perror(file1);
		done();
	}
	if ((input[1] = fopen(file2,"r")) == NULL) {
		perror(file2);
		done();
	}
E 4
	j = 1;
	ixold[0] = ixnew[0] = 0;
	jackpot = 0;
	ctold = ctnew = 0;
	for(i=1;i<=len[0];i++) {
		if(J[i]==0) {
			ixold[i] = ctold += skipline(0);
			continue;
		}
		while(j<J[i]) {
			ixnew[j] = ctnew += skipline(1);
			j++;
		}
D 10
		for(;;) {
			c = getc(input[0]);
			d = getc(input[1]);
			ctold++;
			ctnew++;
			if(bflag && isspace(c) && isspace(d)) {
				do {
					if(c=='\n') break;
					ctold++;
				} while(isspace(c=getc(input[0])));
				do {
					if(d=='\n') break;
					ctnew++;
				} while(isspace(d=getc(input[1])));
E 10
I 10
		if(bflag || wflag || iflag) {
			for(;;) {
				c = getc(input[0]);
				d = getc(input[1]);
				ctold++;
				ctnew++;
				if(bflag && isspace(c) && isspace(d)) {
					do {
						if(c=='\n')
							break;
						ctold++;
					} while(isspace(c=getc(input[0])));
					do {
						if(d=='\n')
							break;
						ctnew++;
					} while(isspace(d=getc(input[1])));
				} else if ( wflag ) {
					while( isspace(c) && c!='\n' ) {
						c=getc(input[0]);
						ctold++;
					}
					while( isspace(d) && d!='\n' ) {
						d=getc(input[1]);
						ctnew++;
					}
				}
				if(chrtran[c] != chrtran[d]) {
					jackpot++;
					J[i] = 0;
					if(c!='\n')
						ctold += skipline(0);
					if(d!='\n')
						ctnew += skipline(1);
					break;
				}
				if(c=='\n')
					break;
E 10
			}
D 10
			if(c!=d) {
				jackpot++;
				J[i] = 0;
				if(c!='\n')
					ctold += skipline(0);
				if(d!='\n')
					ctnew += skipline(1);
				break;
E 10
I 10
		} else {
			for(;;) {
				ctold++;
				ctnew++;
				if((c=getc(input[0])) != (d=getc(input[1]))) {
D 18
					/* jackpot++; */
E 18
I 18
					jackpot++;
E 18
					J[i] = 0;
					if(c!='\n')
						ctold += skipline(0);
					if(d!='\n')
						ctnew += skipline(1);
					break;
				}
				if(c=='\n')
					break;
E 10
			}
D 10
			if(c=='\n')
				break;
E 10
		}
		ixold[i] = ctold;
		ixnew[j] = ctnew;
		j++;
	}
	for(;j<=len[1];j++) {
		ixnew[j] = ctnew += skipline(1);
	}
	fclose(input[0]);
	fclose(input[1]);
D 18
/*
	if(jackpot)
		fprintf(stderr, "jackpot\n");
*/
E 18
I 18
	if(jackpot && Jflag)
		fprintf(stderr, "jackpot %d lines\n", jackpot);
E 18
}

sort(a,n)	/*shellsort CACM #201*/
struct line *a;
{
	struct line w;
	register int j,m;
	struct line *ai;
	register struct line *aim;
	int k;
I 16

	if (n == 0)
		return;
E 16
	for(j=1;j<=n;j*= 2)
		m = 2*j - 1;
	for(m/=2;m!=0;m/=2) {
		k = n-m;
		for(j=1;j<=k;j++) {
			for(ai = &a[j]; ai > a; ai -= m) {
				aim = &ai[m];
				if(aim < ai)
					break;	/*wraparound*/
				if(aim->value > ai[0].value ||
				   aim->value == ai[0].value &&
				   aim->serial > ai[0].serial)
					break;
				w.value = ai[0].value;
				ai[0].value = aim->value;
				aim->value = w.value;
				w.serial = ai[0].serial;
				ai[0].serial = aim->serial;
				aim->serial = w.serial;
			}
		}
	}
}

unsort(f, l, b)
struct line *f;
int *b;
{
	register int *a;
	register int i;
	a = (int *)talloc((l+1)*sizeof(int));
	for(i=1;i<=l;i++)
		a[f[i].serial] = f[i].value;
	for(i=1;i<=l;i++)
		b[i] = a[i];
	free((char *)a);
}

skipline(f)
{
D 11
	register i;
D 4
	for(i=1;getc(input[f])!='\n';i++) ;
E 4
I 4
	char c;
E 11
I 11
	register i, c;
E 11

	for(i=1;(c=getc(input[f]))!='\n';i++)
		if (c < 0)
			return(i);
E 4
	return(i);
}

output()
{
	int m;
	register int i0, i1, j1;
	int j0;
	input[0] = fopen(file1,"r");
	input[1] = fopen(file2,"r");
	m = len[0];
	J[0] = 0;
	J[m+1] = len[1]+1;
	if(opt!=D_EDIT) for(i0=1;i0<=m;i0=i1+1) {
		while(i0<=m&&J[i0]==J[i0-1]+1) i0++;
		j0 = J[i0-1]+1;
		i1 = i0-1;
		while(i1<m&&J[i1+1]==0) i1++;
		j1 = J[i1+1]-1;
		J[i1] = j1;
		change(i0,i1,j0,j1);
	} else for(i0=m;i0>=1;i0=i1-1) {
		while(i0>=1&&J[i0]==J[i0+1]-1&&J[i0]!=0) i0--;
		j0 = J[i0+1]-1;
		i1 = i0+1;
		while(i1>1&&J[i1-1]==0) i1--;
		j1 = J[i1-1]+1;
		J[i1] = j1;
		change(i1,i0,j1,j0);
	}
	if(m==0)
		change(1,0,1,len[1]);
	if (opt==D_IFDEF) {
		for (;;) {
#define	c i0
			c = getc(input[0]);
			if (c < 0)
				return;
			putchar(c);
		}
#undef c
	}
I 10
D 15
	if (opt == D_CONTEXT)
E 15
I 15
	if (anychange && opt == D_CONTEXT)
E 15
		dump_context_vec();
E 10
}

I 10
/*
 * The following struct is used to record change information when
 * doing a "context" diff.  (see routine "change" to understand the
 * highly mneumonic field names)
 */
struct context_vec {
	int	a;	/* start line in old file */
	int	b;	/* end line in old file */
	int	c;	/* start line in new file */
	int	d;	/* end line in new file */
};

struct	context_vec	*context_vec_start,
			*context_vec_end,
			*context_vec_ptr;

#define	MAX_CONTEXT	128

E 10
/* indicate that there is a difference between lines a and b of the from file
   to get to lines c to d of the to file.
   If a is greater then b then there are no lines in the from file involved
   and this means that there were lines appended (beginning at b).
   If c is greater than d then there are lines missing from the to file.
*/
change(a,b,c,d)
{
D 11
	char ch;
E 11
I 11
	int ch;
E 11
	int lowa,upb,lowc,upd;
	struct stat stbuf;

	if (opt != D_IFDEF && a>b && c>d)
		return;
	if (anychange == 0) {
		anychange = 1;
		if(opt == D_CONTEXT) {
			printf("*** %s	", file1);
			stat(file1, &stbuf);
			printf("%s--- %s	",
			    ctime(&stbuf.st_mtime), file2);
			stat(file2, &stbuf);
			printf("%s", ctime(&stbuf.st_mtime));
I 10

			context_vec_start = (struct context_vec *) 
						malloc(MAX_CONTEXT *
						   sizeof(struct context_vec));
			context_vec_end = context_vec_start + MAX_CONTEXT;
			context_vec_ptr = context_vec_start - 1;
E 10
		}
	}
	if (a <= b && c <= d)
		ch = 'c';
	else
		ch = (a <= b) ? 'd' : 'a';
	if(opt == D_CONTEXT) {
D 10
		lowa = max(1, a-context);
		upb  = min(len[0], b+context);
		lowc = max(1, c-context);
		upd  = min(len[1], d+context);
E 10
I 10
		/*
		 * if this new change is within 'context' lines of
		 * the previous change, just add it to the change
		 * record.  If the record is full or if this
		 * change is more than 'context' lines from the previous
		 * change, dump the record, reset it & add the new change.
		 */
		if ( context_vec_ptr >= context_vec_end ||
		     ( context_vec_ptr >= context_vec_start &&
		       a > (context_vec_ptr->b + 2*context) &&
		       c > (context_vec_ptr->d + 2*context) ) )
			dump_context_vec();
E 10

D 10
		/* print out from file */
		printf("***************\n*** ");
		range(lowa,upb,",");
		printf("\n");
		if (ch == 'a')
			fetch(ixold,lowa,upb,input[0],"  ");
		else {
			fetch(ixold,lowa,a-1,input[0],"  ");
			fetch(ixold,a,b,input[0],ch == 'c' ? "! " : "- ");
			fetch(ixold,b+1,upb,input[0],"  ");
		}
		putchar('\n');
		printf("--- ");
		range(lowc,upd,",");
		printf(" -----\n");
		if (ch == 'd')
			fetch(ixnew,lowc,upd,input[1],"  ");
		else {
			fetch(ixnew,lowc,c-1,input[1],"  ");
			fetch(ixnew,c,d,input[1],ch == 'c' ? "! " : "+ ");
			fetch(ixnew,d+1,upd,input[1],"  ");
		}
E 10
I 10
		context_vec_ptr++;
		context_vec_ptr->a = a;
		context_vec_ptr->b = b;
		context_vec_ptr->c = c;
		context_vec_ptr->d = d;
E 10
		return;
	}
	switch (opt) {

	case D_NORMAL:
	case D_EDIT:
		range(a,b,",");
		putchar(a>b?'a':c>d?'d':'c');
		if(opt==D_NORMAL)
			range(c,d,",");
		putchar('\n');
		break;
	case D_REVERSE:
		putchar(a>b?'a':c>d?'d':'c');
		range(a,b," ");
		putchar('\n');
		break;
I 13
        case D_NREVERSE:
                if (a>b)
                        printf("a%d %d\n",b,d-c+1);
                else {
                        printf("d%d %d\n",a,b-a+1);
                        if (!(c>d))
                           /* add changed lines */
                           printf("a%d %d\n",b, d-c+1);
                }
                break;
E 13
	}
	if(opt == D_NORMAL || opt == D_IFDEF) {
		fetch(ixold,a,b,input[0],"< ", 1);
		if(a<=b&&c<=d && opt == D_NORMAL)
			prints("---\n");
	}
	fetch(ixnew,c,d,input[1],opt==D_NORMAL?"> ":"", 0);
	if ((opt ==D_EDIT || opt == D_REVERSE) && c<=d)
		prints(".\n");
	if (inifdef) {
		fprintf(stdout, "#endif %s\n", endifname);
		inifdef = 0;
	}
}

range(a,b,separator)
char *separator;
{
	printf("%d", a>b?b:a);
	if(a<b) {
		printf("%s%d", separator, b);
	}
}

fetch(f,a,b,lb,s,oldfile)
long *f;
FILE *lb;
char *s;
{
	register int i, j;
I 10
	register int c;
	register int col;
E 10
	register int nc;
	int oneflag = (*ifdef1!='\0') != (*ifdef2!='\0');

	/*
	 * When doing #ifdef's, copy down to current line
	 * if this is the first file, so that stuff makes it to output.
	 */
	if (opt == D_IFDEF && oldfile){
		long curpos = ftell(lb);
		/* print through if append (a>b), else to (nb: 0 vs 1 orig) */
		nc = f[a>b? b : a-1 ] - curpos;
		for (i = 0; i < nc; i++)
			putchar(getc(lb));
	}
	if (a > b)
		return;
	if (opt == D_IFDEF) {
		if (inifdef)
			fprintf(stdout, "#else %s%s\n", oneflag && oldfile==1 ? "!" : "", ifdef2);
		else {
			if (oneflag) {
				/* There was only one ifdef given */
				endifname = ifdef2;
				if (oldfile)
					fprintf(stdout, "#ifndef %s\n", endifname);
				else
					fprintf(stdout, "#ifdef %s\n", endifname);
			}
			else {
				endifname = oldfile ? ifdef1 : ifdef2;
				fprintf(stdout, "#ifdef %s\n", endifname);
			}
		}
		inifdef = 1+oldfile;
	}
I 10

E 10
	for(i=a;i<=b;i++) {
		fseek(lb,f[i-1],0);
		nc = f[i]-f[i-1];
		if (opt != D_IFDEF)
			prints(s);
D 10
		for(j=0;j<nc;j++)
			putchar(getc(lb));
E 10
I 10
		col = 0;
		for(j=0;j<nc;j++) {
			c = getc(lb);
			if (c == '\t' && tflag)
				do
					putchar(' ');
				while (++col & 7);
			else {
				putchar(c);
				col++;
			}
		}
E 10
	}
I 10

E 10
	if (inifdef && !wantelses) {
		fprintf(stdout, "#endif %s\n", endifname);
		inifdef = 0;
	}
}

I 11
#define POW2			/* define only if HALFLONG is 2**n */
E 11
#define HALFLONG 16
#define low(x)	(x&((1L<<HALFLONG)-1))
#define high(x)	(x>>HALFLONG)

/*
 * hashing has the effect of
 * arranging line in 7-bit bytes and then
 * summing 1-s complement in 16-bit hunks 
 */
readhash(f)
D 8
FILE *f;
E 8
I 8
register FILE *f;
E 8
{
D 10
	long sum;
E 10
I 10
	register long sum;
E 10
	register unsigned shift;
D 10
	register space;
E 10
	register t;
I 10
	register space;

E 10
	sum = 1;
	space = 0;
D 10
	if(!bflag) for(shift=0;(t=getc(f))!='\n';shift+=7) {
		if(t==-1)
			return(0);
D 8
		sum += (long)t << (shift%=HALFLONG);
E 8
I 8
		sum += (long)t << (shift &= HALFLONG - 1);
E 8
	}
	else for(shift=0;;) {
		switch(t=getc(f)) {
		case -1:
			return(0);
		case '\t':
		case ' ':
			space++;
			continue;
		default:
			if(space) {
E 10
I 10
	if(!bflag && !wflag) {
		if(iflag)
			for(shift=0;(t=getc(f))!='\n';shift+=7) {
				if(t==-1)
					return(0);
D 11
				sum += (long)chrtran[t] << (shift%=HALFLONG);
E 11
I 11
				sum += (long)chrtran[t] << (shift
#ifdef POW2
				    &= HALFLONG - 1);
#else
				    %= HALFLONG);
#endif
E 11
			}
		else
			for(shift=0;(t=getc(f))!='\n';shift+=7) {
				if(t==-1)
					return(0);
D 11
				sum += (long)t << (shift%=HALFLONG);
E 11
I 11
				sum += (long)t << (shift
#ifdef POW2
				    &= HALFLONG - 1);
#else
				    %= HALFLONG);
#endif
E 11
			}
	} else {
		for(shift=0;;) {
			switch(t=getc(f)) {
			case -1:
				return(0);
			case '\t':
			case ' ':
				space++;
				continue;
			default:
				if(space && !wflag) {
					shift += 7;
					space = 0;
				}
D 11
				sum += (long)chrtran[t] << (shift%=HALFLONG);
E 11
I 11
				sum += (long)chrtran[t] << (shift
#ifdef POW2
				    &= HALFLONG - 1);
#else
				    %= HALFLONG);
#endif
E 11
E 10
				shift += 7;
D 10
				space = 0;
E 10
I 10
				continue;
			case '\n':
				break;
E 10
			}
D 8
			sum += (long)t << (shift%=HALFLONG);
E 8
I 8
D 10
			sum += (long)t << (shift &= HALFLONG - 1);
E 8
			shift += 7;
			continue;
		case '\n':
E 10
			break;
		}
D 10
		break;
E 10
	}
	sum = low(sum) + high(sum);
	return((short)low(sum) + (short)high(sum));
I 4
}

#include <a.out.h>

asciifile(f)
	FILE *f;
{
	char buf[BUFSIZ];
	register int cnt;
	register char *cp;

	fseek(f, (long)0, 0);
D 6
	cnt = fread(buf, BUFSIZ, 1, f);
E 6
I 6
	cnt = fread(buf, 1, BUFSIZ, f);
E 6
	if (cnt >= sizeof (struct exec)) {
		struct exec hdr;
		hdr = *(struct exec *)buf;
		if (!N_BADMAG(hdr))
			return (0);
	}
	cp = buf;
	while (--cnt >= 0)
		if (*cp++ & 0200)
			return (0);
	return (1);
I 10
}


/* dump accumulated "context" diff changes */
dump_context_vec()
{
	register int	a, b, c, d;
	register char	ch;
	register struct	context_vec *cvp = context_vec_start;
	register int	lowa, upb, lowc, upd;
I 12
	register int	do_output;
E 12

	if ( cvp > context_vec_ptr )
		return;

	lowa = max(1, cvp->a - context);
	upb  = min(len[0], context_vec_ptr->b + context);
	lowc = max(1, cvp->c - context);
	upd  = min(len[1], context_vec_ptr->d + context);

	printf("***************\n*** ");
	range(lowa,upb,",");
D 12
	printf(" ****\n--- ");
	range(lowc,upd,",");
	printf(" ----\n");
E 12
I 12
	printf(" ****\n");
E 12

	/*
D 12
	 * output changes to the "old" file.  The first loop is a
	 * hack that suppresses the output if there were no changes to
	 * the "old" file (we'll see the "old" lines as context in the
	 * "new" list).
E 12
I 12
	 * output changes to the "old" file.  The first loop suppresses
	 * output if there were no changes to the "old" file (we'll see
	 * the "old" lines as context in the "new" list).
E 12
	 */
D 12
	while (cvp <= context_vec_ptr) {
E 12
I 12
	do_output = 0;
	for ( ; cvp <= context_vec_ptr; cvp++)
E 12
		if (cvp->a <= cvp->b) {
			cvp = context_vec_start;
I 12
			do_output++;
E 12
			break;
		}
D 12
		cvp++;
	}
	while (cvp <= context_vec_ptr) {
		a = cvp->a; b = cvp->b; c = cvp->c; d = cvp->d;
E 12
I 12
	
	if ( do_output ) {
		while (cvp <= context_vec_ptr) {
			a = cvp->a; b = cvp->b; c = cvp->c; d = cvp->d;
E 12

D 12
		if (a <= b && c <= d)
			ch = 'c';
		else
			ch = (a <= b) ? 'd' : 'a';
E 12
I 12
			if (a <= b && c <= d)
				ch = 'c';
			else
				ch = (a <= b) ? 'd' : 'a';
E 12

D 12
		if (ch == 'a')
			fetch(ixold,lowa,b,input[0],"  ");
		else {
			fetch(ixold,lowa,a-1,input[0],"  ");
			fetch(ixold,a,b,input[0],ch == 'c' ? "!<" : "-<");
E 12
I 12
			if (ch == 'a')
				fetch(ixold,lowa,b,input[0],"  ");
			else {
				fetch(ixold,lowa,a-1,input[0],"  ");
				fetch(ixold,a,b,input[0],ch == 'c' ? "! " : "- ");
			}
			lowa = b + 1;
			cvp++;
E 12
		}
D 12
		lowa = b + 1;
		cvp++;
E 12
I 12
		fetch(ixold, b+1, upb, input[0], "  ");
E 12
	}
D 12
	fetch(ixold, b+1, upb, input[0], "  ");
E 12

	/* output changes to the "new" file */
D 12
	printf("---------------\n");
E 12
I 12
	printf("--- ");
	range(lowc,upd,",");
	printf(" ----\n");
E 12

D 12
	cvp = context_vec_start;
	while (cvp <= context_vec_ptr) {
E 12
I 12
	do_output = 0;
	for (cvp = context_vec_start; cvp <= context_vec_ptr; cvp++)
E 12
		if (cvp->c <= cvp->d) {
			cvp = context_vec_start;
I 12
			do_output++;
E 12
			break;
		}
D 12
		cvp++;
	}
	while (cvp <= context_vec_ptr) {
		a = cvp->a; b = cvp->b; c = cvp->c; d = cvp->d;
E 12
I 12
	
	if (do_output) {
		while (cvp <= context_vec_ptr) {
			a = cvp->a; b = cvp->b; c = cvp->c; d = cvp->d;
E 12

D 12
		if (a <= b && c <= d)
			ch = 'c';
		else
			ch = (a <= b) ? 'd' : 'a';
E 12
I 12
			if (a <= b && c <= d)
				ch = 'c';
			else
				ch = (a <= b) ? 'd' : 'a';
E 12

D 12
		if (ch == 'd')
			fetch(ixnew,lowc,d,input[1],"  ");
		else {
			fetch(ixnew,lowc,c-1,input[1],"  ");
			fetch(ixnew,c,d,input[1],ch == 'c' ? "!>" : "+>");
E 12
I 12
			if (ch == 'd')
				fetch(ixnew,lowc,d,input[1],"  ");
			else {
				fetch(ixnew,lowc,c-1,input[1],"  ");
				fetch(ixnew,c,d,input[1],ch == 'c' ? "! " : "+ ");
			}
			lowc = d + 1;
			cvp++;
E 12
		}
D 12
		lowc = d + 1;
		cvp++;
E 12
I 12
		fetch(ixnew, d+1, upd, input[1], "  ");
E 12
	}
D 12
	fetch(ixnew, d+1, upd, input[1], "  ");
E 12

	context_vec_ptr = context_vec_start - 1;
E 10
E 4
}
E 1
