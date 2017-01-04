h42561
s 00001/00002/00059
d D 5.2 83/07/19 11:33:10 gray 2 1
c security fixes
e
s 00061/00000/00000
d D 5.1 83/07/02 17:57:28 sam 1 0
c date and time created 83/07/02 17:57:28 by sam
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
#include <pwd.h>

/*******
 *	sdmail(file, uid)
 *
 *	sdmail  -  this routine will determine the owner
 *	of the file (file), create a message string and
 *	call "mailst" to send the cleanup message.
 *	This is only implemented for local system
 *	mail at this time.
 */

sdmail(file, uid)
char *file;
register int uid;
{
	static struct passwd *pwd = NULL;
	struct passwd *getpwuid();
	char mstr[40];

	sprintf(mstr, "uuclean deleted file %s\n", file);
	if (pwd != NULL && pwd->pw_uid == uid) {
		mailst(pwd->pw_name, mstr);
		return(0);
	}

	if ((pwd = getpwuid(uid)) != NULL) {
		mailst(pwd->pw_name, mstr);
	}
	return(0);
}


/***
 *	mailst(user, str)
 *	char *user, *str;
 *
 *	mailst  -  this routine will fork and execute
 *	a mail command sending string (str) to user (user).
 */

mailst(user, str)
char *user, *str;
{
	register FILE *fp;
D 2
	extern FILE *popen(), *pclose();
E 2
	char cmd[100];

	sprintf(cmd, "mail %s", user);
D 2
	if ((fp = popen(cmd, "w")) == NULL)
E 2
I 2
	if ((fp = rpopen(cmd, "w")) == NULL)
E 2
		return;
/* \n added to mail message.  uw-beave!jim (Jim Rees) */
	fprintf(fp, "%s\n", str);
	pclose(fp);
	return;
}
E 1
