h54815
s 00006/00013/00190
d D 4.2 84/06/28 10:20:57 ralph 2 1
c fix memory allocation - don't realloc().
e
s 00203/00000/00000
d D 4.1 82/12/18 15:14:15 sam 1 0
c date and time created 82/12/18 15:14:15 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif

#include "tp.h"

main(argc,argv)
char **argv;
{
	register char c,*ptr;
	extern cmd(), cmr(),cmx(), cmt();

	tname = tc;
	command = cmr;
	if ((narg = rnarg = argc) < 2)	narg = 2;
	else {
		ptr = argv[1];	/* get first argument */
		parg = &argv[2];	/* pointer to second argument */
		while (c = *ptr++) switch(c)  {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
				tc[8] = c;
				mt[8] = c;
				continue;

			case 'f':
				tname = *parg++;
				flags |= flm;
				narg--; rnarg--;
				continue;
			case 'c':
				flags |= flc;  continue;
			case 'd':
				setcom(cmd);  continue;
			case 'i':
				flags |= fli;  continue;
			case 'm':
				tname = mt;
				flags |= flm;
				continue;
			case 'r':
				flags &= ~flu;  setcom(cmr);  continue;
			case 's':
				flags |= fls; continue;
			case 't':
				setcom(cmt);  continue;
			case 'u':
				flags |= flu;  setcom(cmr);  continue;
			case 'v':
				flags |= flv;  continue;
			case 'w':
				flags |= flw;  continue;
			case 'x':
				setcom(cmx);  continue;
			default:
				useerr();
		}
	}
	optap();
D 2
	nptr = nameblk = malloc(1000);
	top = nptr + 1000;
E 2
	(*command)();
}

optap()
{
	extern cmr();

	if ((flags & flm) == 0) {	/*  DECTAPE */
		tapsiz = TCSIZ;
		ndirent = TCDIRS;
		fio =open(tc,2);
	} else {			/* MAGTAPE */
		tapsiz = MTSIZ;
		ndirent = MDIRENT;
		if(command == cmr) {
			fio = open(tname,1);
			if (fio < 0) fio = creat(tname,0666);
		} else
			fio = open(tname,0);
	}
	if (fio < 0)  {
		printf("Tape open error\n");
		done();
	}
	ndentb = ndirent/TPB;
	edir = &dir[ndirent];
}

setcom(newcom)
int (*newcom)();
{
	extern cmr();

	if (command != cmr)  	useerr();
	command = newcom;
}

useerr()
{
	printf("Bad usage\n");
	done();
}

/*/* COMMANDS */

cmd()
{
	extern delete();

	if (flags & (flm|flc))	useerr();
	if (narg <= 2)			useerr();
	rddir();
	gettape(delete);
	wrdir();
	check();
}

cmr()
{
	if (flags & (flc|flm))		clrdir();
	else				rddir();
	getfiles();
	update();
	check();
}

cmt()
{
	extern taboc();

	if (flags & (flc|flw))	useerr();
	rddir();
	if (flags & flv)
		printf("   mode    uid gid tapa    size   date    time name\n");
	gettape(taboc);
	check();
}

cmx()
{
	extern extract();

	if (flags & (flc))		useerr();
	rddir();
	gettape(extract);
	done();
}

check()
{
	usage();
	done();
}

done()
{
	printf("End\n");
	exit(0);
}

encode(pname,dptr)	/* pname points to the pathname
D 2
			 * nptr points to next location in nameblk
E 2
			 * dptr points to the dir entry		   */
char	*pname;
struct	dent *dptr;
{
	register  char *np;
	register n;
I 2
	extern char *malloc();
E 2

D 2
	dptr->d_namep = np = nptr;
	if (np > top - NAMELEN)  {
		int size = top - nptr;
		if (nptr = realloc(nptr, 2 * size) == 0) {
			printf("Out of core\n");
			done();
		}
		top = nptr + 2 * size;
	}
E 2
	if((n=strlen(pname)) > NAMELEN) {
		printf("Pathname too long - %s\nFile ignored\n",pname);
		clrent(dptr);
	}
	else {
D 2
		nptr += n+1;
E 2
I 2
		dptr->d_namep = np = malloc(n + 1);
		if (np == 0) {
			printf("Out of core\n");
			done();
		}
E 2
		strcpy(np, pname);
	}
}

decode(pname,dptr)	/* dptr points to the dir entry
			 * name is placed in pname[] */
char	*pname;
struct	dent *dptr;
{

	strcpy(pname, dptr->d_namep);
}
E 1
