h00640
s 00001/00001/00054
d D 1.5 85/05/04 00:31:25 sam 5 4
c purge old crud
e
s 00001/00001/00054
d D 1.4 82/05/11 22:14:09 sam 4 3
c somehow dir.h was called ndir.h
e
s 00001/00001/00054
d D 1.3 82/05/11 22:13:16 sam 3 2
c wrong arg to readdir
e
s 00009/00013/00046
d D 1.2 82/04/21 19:43:37 sam 2 1
c switch to directory library routines
e
s 00059/00000/00000
d D 1.1 81/01/14 15:17:25 eric 1 0
c date and time created 81/01/14 15:17:25 by eric
e
u
U
f b 
t
T
I 1
# include	"../hdr/defines.h"
D 2
# include	"dir.h"
E 2
I 2
D 4
# include	<ndir.h>
E 4
I 4
D 5
# include	<dir.h>
E 5
I 5
# include	<sys/dir.h>
E 5
E 4
E 2

SCCSID(%W%);

int	nfiles;
char	had_dir;
char	had_standinp;


do_file(p,func)
register char *p;
int (*func)();
{
	extern char *Ffile;
	char str[FILESIZE];
	char ibuf[FILESIZE];
D 2
	char	dbuf[BUFSIZ];
	FILE *iop;
	struct dir dir[2];
E 2
I 2
	DIR *dir;
	struct direct *dp;
E 2
	register char *s;
	int fd;

	if (p[0] == '-') {
		had_standinp = 1;
		while (gets(ibuf) != NULL) {
			if (sccsfile(ibuf)) {
				Ffile = ibuf;
				(*func)(ibuf);
				nfiles++;
			}
		}
	}
	else if (exists(p) && (Statbuf.st_mode & S_IFMT) == S_IFDIR) {
		had_dir = 1;
		Ffile = p;
D 2
		if((iop = fopen(p,"r")) == NULL)
E 2
I 2
		if((dir = opendir(p)) == 0)
E 2
			return;
D 2
		setbuf(iop,dbuf);
		dir[1].d_ino = 0;
		fread(dir,sizeof(dir[0]),1,iop);   /* skip "."  */
		fread(dir,sizeof(dir[0]),1,iop);   /* skip ".."  */
		while(fread(dir,sizeof(dir[0]),1,iop) == 1) {
			if(dir[0].d_ino == 0) continue;
			sprintf(str,"%s/%s",p,dir[0].d_name);
E 2
I 2
		(void) readdir(dir);	/* skip . */
		(void) readdir(dir);	/* and .. */
D 3
		while (dp = readdir(dp)) {
E 3
I 3
		while (dp = readdir(dir)) {
E 3
			sprintf(str,"%s/%s", p, dp->d_name);
E 2
			if(sccsfile(str)) {
				Ffile = str;
				(*func)(str);
				nfiles++;
			}
		}
D 2
		fclose(iop);
E 2
I 2
		closedir(dir);
E 2
	}
	else {
		Ffile = p;
		(*func)(p);
		nfiles++;
	}
}
E 1
