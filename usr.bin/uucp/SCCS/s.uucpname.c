h06999
s 00008/00006/00218
d D 5.5 85/10/09 16:34:18 bloom 5 4
c handle domains better (from rick@seismo)
e
s 00036/00032/00188
d D 5.4 85/06/23 13:43:04 bloom 4 3
c fixes and changes from rick adams
e
s 00000/00001/00220
d D 5.3 85/04/10 15:22:14 ralph 3 2
c more changes from rick adams.
e
s 00025/00017/00196
d D 5.2 85/01/22 14:12:54 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00213/00000/00000
d D 5.1 83/07/02 17:57:47 sam 1 0
c date and time created 83/07/02 17:57:47 by sam
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
D 3
#include <sys/types.h>
E 3
#include <sys/stat.h>

I 4
/*LINTLIBRARY*/

E 4
#ifdef	GETMYHNAME
#include <UNET/unetio.h>
#endif

#ifdef	UNAME
/* Use USG uname() library routine */
#include <sys/utsname.h>
#endif

#ifdef	CCWHOAMI
/* Compile in 'sysname' as found in standard(!) include file */
#include <whoami.h>
#endif
I 4
char Myfullname[64];
E 4

D 2
/*******
E 2
I 2
/*
E 2
 *	uucpname(name)		get the uucp name
 *
 *	return code - none
 */
D 2

E 2
uucpname(name)
register char *name;
{
D 4
	register char *s, *d;
E 4
I 4
	register char *s;
E 4

D 2
	/* HUGE KLUDGE HERE!  rti!trt
E 2
I 2
	/*
E 2
	 * Since some UNIX systems do not honor the set-user-id bit
	 * when the invoking user is root, we must change the uid here.
	 * So uucp files are created with the correct owner.
	 */
	if (geteuid() == 0 && getuid() == 0) {
		struct stat stbuf;
		stbuf.st_uid = 0;	/* In case the stat fails */
		stbuf.st_gid = 0;
		stat(UUCICO, &stbuf);	/* Assume uucico is correctly owned */
		setgid(stbuf.st_gid);
		setuid(stbuf.st_uid);
	}

	s = NULL;	/* system name unknown, so far */

D 2
#ifdef	GETHOSTNAME
	/* Use 4.1a library routine */
E 2
I 2
#ifdef GETHOSTNAME
E 2
	if (s == NULL || *s == '\0') {
D 4
		char hostname[32];
E 4
I 2
#ifdef VMS
D 4
		int i = sizeof(hostname);
E 4
I 4
		int i = sizeof(Myfullname);
E 4
#endif VMS
E 2

D 4
		s = hostname;
E 4
I 4
		s = Myfullname;
E 4
I 2
#ifdef VMS
D 4
		if(gethostname(hostname, &i) == -1) {
E 4
I 4
		if(gethostname(Myfullname, &i) == -1) {
E 4
#else !VMS
E 2
D 4
		if(gethostname(hostname, sizeof(hostname)) == -1) {
E 4
I 4
		if(gethostname(Myfullname, sizeof(Myfullname)) == -1) {
E 4
D 2
			DEBUG(1, "gethostname", "FAILED");
E 2
I 2
#endif !VMS
			DEBUG(1, "gethostname", _FAILED);
E 2
			s = NULL;
		}
	}
D 2
#endif
E 2
I 2
#endif GETHOSTNAME
E 2

#ifdef	UNAME
	/* Use USG library routine */
	if (s == NULL || *s == '\0') {
		struct utsname utsn;

D 4
		s = utsn.nodename;
E 4
		if (uname(&utsn) == -1) {
D 2
			DEBUG(1, "uname", "FAILED");
E 2
I 2
			DEBUG(1, "uname", _FAILED);
E 2
			s = NULL;
I 4
		} else {
			strncpy(Myfullname, utsn.nodename, sizeof Myfullname);
			s = Myfullname;
E 4
		}
	}
#endif

#ifdef	WHOAMI
	/* Use fake gethostname() routine */
	if (s == NULL || *s == '\0') {
D 4
		char fakehost[32];
E 4

D 4
		s = fakehost;
		if (fakegethostname(fakehost, sizeof(fakehost)) == -1) {
E 4
I 4
		s = Myfullname;
		if (fakegethostname(Myfullname, sizeof(Myfullname)) == -1) {
E 4
D 2
			DEBUG(1, "whoami search", "FAILED");
E 2
I 2
			DEBUG(1, "whoami search", _FAILED);
E 2
			s = NULL;
		}
	}
#endif

#ifdef	CCWHOAMI
	/* compile sysname right into uucp */
	if (s == NULL || *s == '\0') {
		s = sysname;
I 5
		strncpy(Myfullname, s, sizeof Myfullname);
E 5
	}
#endif

#ifdef	UUNAME
	/* uucp name is stored in /etc/uucpname or /local/uucpname */
	if (s == NULL || *s == '\0') {
		FILE *uucpf;
D 4
		char stmp[10];
E 4

D 4
		s = stmp;
E 4
I 4
		s = Myfullname;
E 4
		if (((uucpf = fopen("/etc/uucpname", "r")) == NULL &&
		     (uucpf = fopen("/local/uucpname", "r")) == NULL) ||
D 4
			fgets(s, 8, uucpf) == NULL) {
E 4
I 4
			fgets(Myfullname, sizeof Myfullname, uucpf) == NULL) {
E 4
D 2
				DEBUG(1, "uuname search", "FAILED");
E 2
I 2
				DEBUG(1, "uuname search", _FAILED);
E 2
				s = NULL;
D 4
		} else {
			for (d = stmp; *d && *d != '\n' && d < stmp + 8; d++)
				;
			*d = '\0';
E 4
		}
I 4
		if (s == Myfullname) {
			register char *p;
			p = index(s, '\n');
			if (p)
				*p = '\0';
  		}
E 4
		if (uucpf != NULL)
			fclose(uucpf);
	}
#endif

#ifdef	GETMYHNAME
	/* Use 3Com's getmyhname() routine */
	if (s == NULL || *s == '\0') {
D 4
		if ((s == getmyhname()) == NULL)
E 4
I 4
		if ((s = getmyhname()) == NULL)
E 4
D 2
			DEBUG(1, "getmyhname", "FAILED");
E 2
I 2
			DEBUG(1, "getmyhname", _FAILED);
I 4
		else
			strncpy(Myfullname, s, sizeof Myfullname);
E 4
E 2
	}
#endif

#ifdef	MYNAME
	if (s == NULL || *s == '\0') {
		s = MYNAME;
I 5
		strncpy(Myfullname, s, sizeof Myfullname);
E 5
	}
#endif

	if (s == NULL || *s == '\0') {
		/*
		 * As a last ditch thing, we *could* search Spool
		 * for D.<uucpname> and use that,
		 * but that is too much trouble, isn't it?
		 */
		logent("SYSTEM NAME", "CANNOT DETERMINE");
D 5
		s = "unknown";
E 5
I 5
		strcpy(Myfullname, "unknown");
E 5
	}

	/*
I 2
D 4
	 * save entire name for TCP/IP verification
	 */

	strcpy(Myfullname, s);

	/*
E 4
E 2
	 * copy uucpname back to caller-supplied buffer,
D 4
	 * truncating to 7 characters.
	 * Also set up subdirectory names, if subdirs are being used.
E 4
I 4
	 * truncating to MAXBASENAME characters.
	 * Also set up subdirectory names
	 * Truncate names at '.' if found to handle cases like
D 5
	 * seismo.arpa being returned by gethostname().
E 5
I 5
	 * seismo.css.gov being returned by gethostname().
E 5
	 * uucp sites should not have '.' in their name anyway
E 4
	 */
D 4
	d = name;
	while ((*d = *s++) && d < name + 7)
		d++;
	*(name + 7) = '\0';
E 4
I 4
D 5
	strncpy(name, s, MAXBASENAME);
	name[MAXBASENAME] = '\0';
	s = index(name, '.');
E 5
I 5
	s = index(Myfullname, '.');
E 5
	if (s != NULL)
		*s = '\0';
I 5
	strncpy(name, Myfullname, MAXBASENAME);
	name[MAXBASENAME] = '\0';
E 5
E 4
	DEBUG(1, "My uucpname = %s\n", name);

D 2
#ifdef	UUDIR
E 2
D 4
	sprintf(DLocal, "D.%s", name);
	sprintf(DLocalX, "D.%sX", name);
E 4
I 4
	sprintf(DLocal, "D.%.*s", SYSNSIZE, name);
	sprintf(DLocalX, "D.%.*sX", SYSNSIZE, name);
E 4
D 2
#endif
E 2
}

#ifdef	WHOAMI
/*
D 2
 * simulate the 4.1a bsd system call by reading /usr/include/whoami.h
E 2
I 2
 * simulate the 4.2 bsd system call by reading /usr/include/whoami.h
E 2
 * and looking for the #define sysname
D 2
 * CHANGE NOTICE (rti!trt): returns -1 on failure, 0 on success.
E 2
 */

#define	HDRFILE "/usr/include/whoami.h"

fakegethostname(name, len)
char *name;
int len;
{
	char buf[BUFSIZ];
	char bname[32];
	char hname[32];
	char nname[128];
	register char *p, *q, *nptr;
	int i;
	register FILE *fd;
	
	fd = fopen(HDRFILE, "r");
	if (fd == NULL)
		return(-1);
	
D 5
	hname[0] = 0;	/* rti!trt: was "hostunknown" */
E 5
I 5
	hname[0] = 0;
E 5
	nname[0] = 0;
	nptr = nname;

	while (fgets(buf, sizeof buf, fd) != NULL) { /* each line in the file */
		if (sscanf(buf, "#define sysname \"%[^\"]\"", bname) == 1) {
			strcpy(hname, bname);
		} else if (sscanf(buf, "#define nickname \"%[^\"]\"", bname) == 1) {
			strcpy(nptr, bname);
			nptr += strlen(bname) + 1;
		} else if (sscanf(buf, "#define nickname%d \"%[^\"]\"", &i, bname) == 2) {
			strcpy(nptr, bname);
			nptr += strlen(bname) + 1;
		}
	}
	fclose(fd);
	if (hname[0] == 0)
D 2
		return(-1);	/* added by rti!trt */
E 2
I 2
		return FAIL;
E 2
	strncpy(name, hname, len);
	p = nname;
	i = strlen(hname) + 1;
	q = name + i;
	while (i < len && (p[0] != 0 || p[1] != 0)) {
		*q++ = *p++;
		i++;
	}
	*q++ = 0;
D 2
	return(0);
E 2
I 2
	return SUCCESS;
E 2
}
#endif
E 1
