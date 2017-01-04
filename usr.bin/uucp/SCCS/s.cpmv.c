h37229
s 00005/00007/00067
d D 5.5 85/10/09 15:46:28 bloom 5 4
c use constants, lint from rick@seismo
e
s 00004/00004/00070
d D 5.4 85/06/19 18:39:38 bloom 4 3
c lint fixes from rick adams
e
s 00018/00015/00056
d D 5.3 85/01/22 14:08:11 ralph 3 2
c bug fixes and changes from Rick Adams
e
s 00001/00001/00070
d D 5.2 84/08/30 16:15:20 ralph 2 1
c added network device NET
e
s 00071/00000/00000
d D 5.1 83/07/02 17:56:44 sam 1 0
c date and time created 83/07/02 17:56:44 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include "uucp.h"
D 4
#include <sys/types.h>
E 4
#include <sys/stat.h>

D 3

E 3
D 4
/***
 *	xcp(f1, f2)	copy f1 to f2
 *	char *f1, *f2;
E 4
I 4
/*LINTLIBRARY*/

/*
 *	copy f1 to f2
E 4
 *
D 5
 *	return - 0 ok  |  FAIL failed
E 5
I 5
 *	return - SUCCESS | FAIL
E 5
 */
D 5

E 5
xcp(f1, f2)
char *f1, *f2;
{
	char buf[BUFSIZ];
	register int len;
D 3
	register FILE *fp1, *fp2;
E 3
I 3
	register int fp1, fp2;
E 3
	char *lastpart();
D 2
	char full[100];
E 2
I 2
D 3
	char full[MAXFULLNAME];
E 3
I 3
D 5
	char full[100];
E 5
I 5
	char full[MAXFULLNAME];
E 5
E 3
E 2
	struct stat s;

D 3
	if ((fp1 = fopen(subfile(f1), "r")) == NULL)
		return(FAIL);
E 3
I 3
	if ((fp1 = open(subfile(f1), 0)) < 0)
		return FAIL;
E 3
	strcpy(full, f2);
	if (stat(subfile(f2), &s) == 0) {
		/* check for directory */
		if ((s.st_mode & S_IFMT) == S_IFDIR) {
			strcat(full, "/");
			strcat(full, lastpart(f1));
		}
	}
	DEBUG(4, "full %s\n", full);
D 3
	if ((fp2 = fopen(subfile(full), "w")) == NULL) {
		fclose(fp1);
		return(FAIL);
E 3
I 3
	if ((fp2 = creat(subfile(full), 0666)) < 0) {
		close(fp1);
		return FAIL;
E 3
	}
D 3
	while((len = fread(buf, sizeof (char), BUFSIZ, fp1)) > 0)
		fwrite(buf, sizeof (char), len, fp2);
	fclose(fp1);
	fclose(fp2);
	return(0);
E 3
I 3
	while((len = read(fp1, buf, BUFSIZ)) > 0)
		 if (write(fp2, buf, len) != len) {
			len = -1;
			break;
		}

	close(fp1);
	close(fp2);
	return len < 0 ? FAIL: SUCCESS;
E 3
}


/*
D 5
 *	xmv(f1, f2)	move f1 to f2
 *	char * f1, *f2;
E 5
I 5
 *	move f1 to f2
E 5
 *
 *	return  0 ok  |  FAIL failed
 */
D 5

E 5
xmv(f1, f2)
register char *f1, *f2;
{
	register int ret;

I 5
	(void) unlink(subfile(f2));
E 5
	if (link(subfile(f1), subfile(f2)) < 0) {
		/*  copy file  */
		ret = xcp(f1, f2);
		if (ret == 0)
			unlink(subfile(f1));
D 3
		return(ret);
E 3
I 3
		return ret;
E 3
	}
D 5
	unlink(subfile(f1));
E 5
I 5
	(void) unlink(subfile(f1));
E 5
D 3
	return(0);
E 3
I 3
	return 0;
E 3
}
E 1
