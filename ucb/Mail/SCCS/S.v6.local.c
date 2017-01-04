h02074
s 00000/00000/00104
d D 2.1 81/07/01 11:10:41 kurt 2 1
c Release to Heidi Stettner
e
s 00104/00000/00000
d D 1.1 80/10/08 09:52:12 kas 1 0
c date and time created 80/10/08 09:52:12 by kas
e
u
U
f b 
t
T
I 1
#

/*
 * Mail -- a mail program
 *
 * Unix version 6.0
 *
 * Local routines that are installation dependent.
 * All fiddlers please note:  if you make careful note of
 * what you change here, I will incorporate your changes and
 * you won't have to remake them each release.
 */

static char *SccsId = "%W% %G%";

#include "rcv.h"

/*
 * Locate the user's mailbox file (ie, the place where new, unread
 * mail is queued).  In Version 6, it is in ~/.mail
 */

findmail()
{
	register char *cp;

	cp = copy(homedir, mailname);
	copy("/.mail", cp);
}

/*
 * Get rid of the queued mail.
 */

demail()
{
	close(creat(mailname, 0666));
	alter(mailname);
}

/*
 * Get an environment variable.  At present, we only support
 * "SHELL" and "HOME".  This routine makes use of the getpw
 * routine in the neighboring getname.c stuff.
 */

char *
getenv(name)
	char name[];
{
	char pwline[LINESIZE];
	static char val[30];
	register char *cp, *dp;
	register int cc;

	if (equal(name, "SHELL"))
		cc = 6;
	else if (equal(name, "HOME"))
		cc = 5;
	else
		return(NOSTR);
	if (getpw(uid, pwline) < 0)
		return(NOSTR);
	for (cp = pwline; *cp && cc > 0;)
		if (*cp++ == ':')
			cc--;
	dp = cp;
	while (*cp != ':' && *cp != '\0')
		cp++;
	*cp = '\0';
	if (*dp == '\0')
		return(NOSTR);
	copy(dp, val);
	return(val);
}

/*
 * Lock and unlock retrofits which are only
 * significant in version 7.
 */

lock(name)
	char *name;
{

	return(0);
}

unlock()
{

	return(0);
}

/*
 * Discover user login name.
 */

username(uid, namebuf)
	char namebuf[];
{

	return(getname(uid, namebuf));
}
E 1
