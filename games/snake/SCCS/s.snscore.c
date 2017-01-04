h48027
s 00010/00005/00090
d D 5.3 88/06/18 19:30:55 bostic 5 4
c install approved copyright notice
e
s 00015/00003/00080
d D 5.2 88/03/09 11:29:55 bostic 4 3
c add Berkeley specific header
e
s 00007/00001/00076
d D 5.1 85/05/30 08:45:38 dist 3 2
c Add copyright
e
s 00000/00017/00077
d D 4.2 84/07/06 19:02:36 karels 2 1
c don't need internal getpwuid now
e
s 00094/00000/00000
d D 4.1 83/07/04 12:48:31 sam 1 0
c date and time created 83/07/04 12:48:31 by sam
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 5
E 4
 */

E 3
I 1
#ifndef lint
I 4
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4
E 3

#include <stdio.h>
#include <pwd.h>
char *recfile = "/usr/games/lib/snakerawscores";
#define MAXPLAYERS 256

struct	passwd	*getpwuid();
char	*malloc();

struct	player	{
	short	uids;
	short	scores;
	char	*name;
} players[MAXPLAYERS], temp;

main()
{
	char	buf[80], cp;
	short	uid, score;
	FILE	*fd;
	int	noplayers;
	int	i, j, notsorted;
	short	whoallbest, allbest;
	char	*q;
	struct	passwd	*p;

	fd = fopen(recfile, "r");
	if (fd == NULL) {
		perror(recfile);
		exit(1);
	}
	printf("Snake players scores to date\n");
	fread(&whoallbest, sizeof(short), 1, fd);
	fread(&allbest, sizeof(short), 1, fd);
	for (uid=2;;uid++) {
		if(fread(&score, sizeof(short), 1, fd) == 0)
			break;
		if (score > 0) {
			if (noplayers > MAXPLAYERS) {
				printf("too many players\n");
				exit(2);
			}
			players[noplayers].uids = uid;
			players[noplayers].scores = score;
D 2
			/* This is faster if passwd is sorted by uid. */
E 2
			p = getpwuid(uid);
			if (p == NULL)
				continue;
			q = p -> pw_name;
			players[noplayers].name = malloc(strlen(q)+1);
			strcpy(players[noplayers].name, q);
			noplayers++;
		}
	}

	/* bubble sort scores */
	for (notsorted=1; notsorted; ) {
		notsorted = 0;
		for (i=0; i<noplayers-1; i++)
			if (players[i].scores < players[i+1].scores) {
				temp = players[i];
				players[i] = players[i+1];
				players[i+1] = temp;
				notsorted++;
			}
	}

	j = 1;
	for (i=0; i<noplayers; i++) {
		printf("%d:\t$%d\t%s\n", j, players[i].scores, players[i].name);
		if (players[i].scores > players[i+1].scores)
			j = i+2;
	}
	exit(0);
D 2
}

struct passwd *
getpwuid(uid)
register uid;
{
	register struct passwd *p;
	struct passwd *getpwent();

	while( (p = getpwent()) && p->pw_uid != uid );
	if (p->pw_uid == uid)
		return(p);
	setpwent();
	while( (p = getpwent()) && p->pw_uid != uid );
	endpwent();
	return(p);
E 2
}
E 1
