h37576
s 00010/00005/00395
d D 5.4 88/06/18 19:56:05 bostic 21 20
c install approved copyright notice
e
s 00009/00003/00391
d D 5.3 88/03/09 12:30:43 bostic 20 19
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00008/00007/00386
d D 5.2 86/01/21 18:09:46 edward 19 18
c use fwrite instead of fputs, and other changes
e
s 00005/00005/00388
d D 5.1 85/05/29 16:11:30 dist 18 17
c Add copyright
e
s 00006/00000/00387
d D 2.10 85/04/23 21:52:22 edward 17 16
c copyright message
e
s 00004/00001/00383
d D 2.9 85/04/22 01:48:19 edward 16 15
c -b flag for no bells
e
s 00012/00012/00372
d D 2.8 85/04/06 00:02:19 edward 15 14
c don't rely on duped file descriptor
e
s 00026/00027/00358
d D 2.7 85/03/04 18:06:11 edward 14 13
c more cleanup; sail, driver, sail.log merged into single program
e
s 00004/00004/00381
d D 2.6 84/04/28 13:08:02 edward 13 12
c time out factor increased to 5 min, too long?
e
s 00061/00012/00324
d D 2.5 84/02/23 15:54:03 edward 12 11
c file locking with flock(), plus error return from Sync().
e
s 00008/00008/00328
d D 2.4 84/01/27 15:02:09 edward 11 10
c portability
e
s 00048/00019/00288
d D 2.3 83/12/17 12:39:19 edward 10 9
c new grapple and foul data structure.
e
s 00002/00001/00305
d D 2.2 83/11/01 17:32:29 edward 9 8
c check sync_fp before calling fclose().
e
s 00000/00000/00306
d D 2.1 83/10/31 13:46:13 edward 8 7
c new version
e
s 00004/00001/00302
d D 1.7 83/10/28 22:46:08 edward 7 6
c check for -1 in CAPTURED
e
s 00012/00001/00291
d D 1.6 83/10/28 21:14:16 edward 6 5
c remove old tmp files
e
s 00001/00002/00291
d D 1.5 83/10/28 19:23:41 edward 5 4
c rearranged player and screen stuff
e
s 00001/00000/00292
d D 1.4 83/10/14 23:08:35 edward 4 3
c lint
e
s 00004/00009/00288
d D 1.3 83/10/14 22:47:19 edward 3 2
c last remnant of old Signal() scheme
e
s 00006/00000/00291
d D 1.2 83/10/14 20:51:38 edward 2 1
c signal stuff, needs more work.
e
s 00291/00000/00000
d D 1.1 83/10/10 20:12:40 edward 1 0
c date and time created 83/10/10 20:12:40 by edward
e
u
U
t
T
I 17
/*
D 18
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 18
I 18
 * Copyright (c) 1983 Regents of the University of California.
D 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 20
I 20
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 21
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 21
I 21
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
E 21
E 20
E 18
 */

E 17
I 1
#ifndef lint
D 18
static	char *sccsid = "%W% %E%";
#endif
E 18
I 18
static char sccsid[] = "%W% (Berkeley) %G%";
D 20
#endif not lint
E 20
I 20
#endif /* not lint */
E 20
E 18

#include "externs.h"
I 12
#include <sys/file.h>
#include <sys/errno.h>
E 12

I 14
#define BUFSIZE 4096

E 14
static char sync_buf[BUFSIZE];
D 11
static char *sync_bufp = sync_buf;
E 11
I 11
static char *sync_bp = sync_buf;
E 11
static char sync_lock[25];
static char sync_file[25];
static long sync_seek;
static FILE *sync_fp;
#define SF "/tmp/#sailsink.%d"
#define LF "/tmp/#saillock.%d"

/*VARARGS3*/
makesignal(from, fmt, ship, a, b, c)
D 14
struct ship *from;
char *fmt;
register struct ship *ship;
E 14
I 14
	struct ship *from;
	char *fmt;
	register struct ship *ship;
E 14
{
	char message[80];

	if (ship == 0)
		(void) sprintf(message, fmt, a, b, c);
	else
		(void) sprintf(message, fmt,
			ship->shipname, colours(ship),
			sterncolour(ship), a, b, c);
	Write(W_SIGNAL, from, 1, (int)message, 0, 0, 0);
}

I 6
#include <sys/types.h>
#include <sys/stat.h>
E 6
sync_exists(game)
{
	char buf[sizeof sync_file];
I 6
	struct stat s;
	time_t t;
E 6

	(void) sprintf(buf, SF, game);
D 6
	return access(buf, 0) >= 0;
E 6
I 6
D 10
	time(&t);
E 10
I 10
	(void) time(&t);
E 10
	if (stat(buf, &s) < 0)
		return 0;
	if (s.st_mtime < t - 60*60*2) {		/* 2 hours */
D 10
		unlink(buf);
E 10
I 10
		(void) unlink(buf);
I 12
		(void) sprintf(buf, LF, game);
		(void) unlink(buf);
E 12
E 10
		return 0;
	} else
		return 1;
E 6
}

sync_open()
{
D 14
	(void) sprintf(sync_lock, LF, game);
	(void) sprintf(sync_file, SF, game);
	if (access(sync_file, 0) < 0) {
		int omask;
#ifdef SETUID
		omask = umask(077);
#else
		omask = umask(011);
#endif
		sync_fp = fopen(sync_file, "w+");
		(void) umask(omask);
	} else
		sync_fp = fopen(sync_file, "r+");
	if (sync_fp == 0)
		return -1;
E 14
I 14
D 15
	if (sync_fp == NULL) {
		(void) sprintf(sync_lock, LF, game);
		(void) sprintf(sync_file, SF, game);
		if (access(sync_file, 0) < 0) {
			int omask = umask(issetuid ? 077 : 011);
			sync_fp = fopen(sync_file, "w+");
			(void) umask(omask);
		} else
			sync_fp = fopen(sync_file, "r+");
		if (sync_fp == NULL)
			return -1;
	}
E 15
I 15
	if (sync_fp != NULL)
		(void) fclose(sync_fp);
	(void) sprintf(sync_lock, LF, game);
	(void) sprintf(sync_file, SF, game);
	if (access(sync_file, 0) < 0) {
		int omask = umask(issetuid ? 077 : 011);
		sync_fp = fopen(sync_file, "w+");
		(void) umask(omask);
	} else
		sync_fp = fopen(sync_file, "r+");
	if (sync_fp == NULL)
		return -1;
E 15
E 14
D 19
	sync_seek == 0;
E 19
I 19
	sync_seek = 0;
E 19
I 4
	return 0;
E 4
}

sync_close(remove)
D 14
char remove;
E 14
I 14
	char remove;
E 14
{
D 9
	(void) fclose(sync_fp);
E 9
I 9
	if (sync_fp != 0)
		(void) fclose(sync_fp);
E 9
	if (remove)
		(void) unlink(sync_file);
}

Write(type, ship, isstr, a, b, c, d)
D 14
int type;
struct ship *ship;
char isstr;
int a, b, c, d;
E 14
I 14
	int type;
	struct ship *ship;
	char isstr;
	int a, b, c, d;
E 14
{
	if (isstr)
D 11
		(void) sprintf(sync_bufp, "%d %d %d %s\n",
E 11
I 11
		(void) sprintf(sync_bp, "%d %d %d %s\n",
E 11
D 10
			type, ship-SHIP(0), isstr, a);
E 10
I 10
			type, ship->file->index, isstr, a);
E 10
	else
D 11
		(void) sprintf(sync_bufp, "%d %d %d %d %d %d %d\n",
E 11
I 11
		(void) sprintf(sync_bp, "%d %d %d %d %d %d %d\n",
E 11
D 10
			type, ship-SHIP(0), isstr, a, b, c, d);
E 10
I 10
			type, ship->file->index, isstr, a, b, c, d);
E 10
D 11
	while (*sync_bufp++)
E 11
I 11
	while (*sync_bp++)
E 11
		;
D 11
	sync_bufp--;
	if (sync_bufp >= &sync_buf[sizeof sync_buf])
E 11
I 11
	sync_bp--;
	if (sync_bp >= &sync_buf[sizeof sync_buf])
E 11
		abort();
D 12
	sync_update(type, ship, a, b, c, d);
E 12
I 12
	(void) sync_update(type, ship, a, b, c, d);
E 12
}

Sync()
{
D 19
	int (*sig1)(), (*sig2)();
E 19
I 19
	int (*sighup)(), (*sigint)();
E 19
D 12
	int type, shipnum, isstr, a, b, c, d;
	char buf[60];
	register char *p = buf;
E 12
D 13
	int n;
E 13
I 13
	register n;
E 13
I 12
	int type, shipnum, isstr, a, b, c, d;
	char buf[80];
	char erred = 0;
	extern errno;
E 12

D 19
	sig1 = signal(SIGHUP, SIG_IGN);
	sig2 = signal(SIGINT, SIG_IGN);
E 19
I 19
	sighup = signal(SIGHUP, SIG_IGN);
	sigint = signal(SIGINT, SIG_IGN);
E 19
D 12
	for (n = 0; link(sync_file, sync_lock) < 0 && n < 30; n++)
E 12
I 12
D 13
	for (n = 0; n < 30; n++) {
E 13
I 13
	for (n = TIMEOUT; --n >= 0;) {
E 13
#ifdef LOCK_EX
		if (flock(fileno(sync_fp), LOCK_EX|LOCK_NB) >= 0)
			break;
		if (errno != EWOULDBLOCK)
			return -1;
#else
		if (link(sync_file, sync_lock) >= 0)
			break;
		if (errno != EEXIST)
			return -1;
#endif
E 12
D 13
		sleep(2);
E 13
I 13
		sleep(1);
E 13
I 12
	}
D 13
	if (n >= 30)
E 13
I 13
	if (n <= 0)
E 13
		return -1;
E 12
	(void) fseek(sync_fp, sync_seek, 0);
D 12
	while (fscanf(sync_fp, "%d%d%d", &type, &shipnum, &isstr) != EOF) {
E 12
I 12
	for (;;) {
		switch (fscanf(sync_fp, "%d%d%d", &type, &shipnum, &isstr)) {
		case 3:
			break;
		case EOF:
			goto out;
		default:
			goto bad;
		}
		if (shipnum < 0 || shipnum >= cc->vessels)
			goto bad;
		if (isstr != 0 && isstr != 1)
			goto bad;
E 12
		if (isstr) {
I 12
			register char *p;
E 12
			for (p = buf;;) {
				switch (*p++ = getc(sync_fp)) {
				case '\n':
					p--;
				case EOF:
					break;
				default:
I 12
					if (p >= buf + sizeof buf)
						p--;
E 12
					continue;
				}
				break;
			}
			*p = 0;
			for (p = buf; *p == ' '; p++)
				;
			a = (int)p;
			b = c = d = 0;
		} else
D 12
			(void) fscanf(sync_fp, "%d%d%d%d", &a, &b, &c, &d);
		sync_update(type, SHIP(shipnum), a, b, c, d);
E 12
I 12
			if (fscanf(sync_fp, "%d%d%d%d", &a, &b, &c, &d) != 4)
				goto bad;
		if (sync_update(type, SHIP(shipnum), a, b, c, d) < 0)
			goto bad;
E 12
	}
D 11
	if (sync_bufp != sync_buf) {
E 11
I 11
D 12
	if (sync_bp != sync_buf) {
E 12
I 12
bad:
	erred++;
out:
	if (!erred && sync_bp != sync_buf) {
E 12
E 11
		(void) fseek(sync_fp, 0L, 2);
D 19
		(void) fputs(sync_buf, sync_fp);
E 19
I 19
		(void) fwrite(sync_buf, sizeof *sync_buf, sync_bp - sync_buf,
			sync_fp);
E 19
		(void) fflush(sync_fp);
D 11
		sync_bufp = sync_buf;
E 11
I 11
		sync_bp = sync_buf;
E 11
	}
	sync_seek = ftell(sync_fp);
I 12
#ifdef LOCK_EX
	(void) flock(fileno(sync_fp), LOCK_UN);
#else
E 12
	(void) unlink(sync_lock);
I 12
#endif
E 12
D 19
	(void) signal(SIGHUP, sig1);
	(void) signal(SIGINT, sig2);
E 19
I 19
	(void) signal(SIGHUP, sighup);
	(void) signal(SIGINT, sigint);
E 19
I 12
	return erred ? -1 : 0;
E 12
}

sync_update(type, ship, a, b, c, d)
D 14
int type;
register struct ship *ship;
int a, b, c, d;
E 14
I 14
	int type;
	register struct ship *ship;
	int a, b, c, d;
E 14
{
	switch (type) {
	case W_DBP: {
		register struct BP *p = &ship->file->DBP[a];
		p->turnsent = b;
		p->toship = SHIP(c);
		p->mensent = d;
		break;
		}
	case W_OBP: {
		register struct BP *p = &ship->file->OBP[a];
		p->turnsent = b;
		p->toship = SHIP(c);
		p->mensent = d;
		break;
		}
	case W_FOUL: {
D 10
		register struct snag *p = &ship->file->fouls[a];
		p->turnfoul = b;
		p->toship = SHIP(c);
E 10
I 10
		register struct snag *p = &ship->file->foul[a];
		if (SHIP(a)->file->dir == 0)
			break;
		if (p->sn_count++ == 0)
			p->sn_turn = turn;
		ship->file->nfoul++;
E 10
		break;
		}
	case W_GRAP: {
D 10
		register struct snag *p = &ship->file->grapples[a];
		p->turnfoul = b;
		p->toship = SHIP(c);
E 10
I 10
		register struct snag *p = &ship->file->grap[a];
		if (SHIP(a)->file->dir == 0)
			break;
		if (p->sn_count++ == 0)
			p->sn_turn = turn;
		ship->file->ngrap++;
E 10
		break;
		}
I 10
	case W_UNFOUL: {
		register struct snag *p = &ship->file->foul[a];
		if (p->sn_count > 0)
			if (b) {
				ship->file->nfoul -= p->sn_count;
				p->sn_count = 0;
			} else {
				ship->file->nfoul--;
				p->sn_count--;
			}
		break;
		}
	case W_UNGRAP: {
		register struct snag *p = &ship->file->grap[a];
		if (p->sn_count > 0)
			if (b) {
				ship->file->ngrap -= p->sn_count;
				p->sn_count = 0;
			} else {
				ship->file->ngrap--;
				p->sn_count--;
			}
		break;
		}
E 10
	case W_SIGNAL:
I 2
D 3
		/*
		(void) putchar('\7');
		*/
		Signal("%s (%c%c): %s", ship, a);
		/*
E 2
		(void) strncpy(ship->file->signal, (char *)a,
			sizeof ship->file->signal - 1);
		ship->file->signal[sizeof ship->file->signal - 1] = 0;
I 2
		*/
E 3
I 3
D 10
		if (isplayer) {
E 10
I 10
D 14
		if (isplayer)
E 14
I 14
		if (mode == MODE_PLAYER)
E 14
E 10
D 5
			(void) putchar('\7');
			Signal("%s (%c%c): %s", ship, a);
E 5
I 5
D 16
			Signal("\7%s (%c%c): %s", ship, a);
E 16
I 16
			if (nobells)
				Signal("%s (%c%c): %s", ship, a);
			else
				Signal("\7%s (%c%c): %s", ship, a);
E 16
E 5
D 10
		}
E 10
E 3
E 2
		break;
	case W_CREW: {
		register struct shipspecs *s = ship->specs;
		s->crew1 = a;
		s->crew2 = b;
		s->crew3 = c;
		break;
		}
	case W_CAPTAIN:
		(void) strncpy(ship->file->captain, (char *)a,
			sizeof ship->file->captain - 1);
		ship->file->captain[sizeof ship->file->captain - 1] = 0;
		break;
	case W_CAPTURED:
D 7
		ship->file->captured = SHIP(a);
E 7
I 7
		if (a < 0)
			ship->file->captured = 0;
		else
			ship->file->captured = SHIP(a);
E 7
		break;
	case W_CLASS:
		ship->specs->class = a;
		break;
	case W_DRIFT:
		ship->file->drift = a;
		break;
	case W_EXPLODE:
		if ((ship->file->explode = a) == 2)
			ship->file->dir = 0;
		break;
	case W_FS:
		ship->file->FS = a;
		break;
	case W_GUNL: {
		register struct shipspecs *s = ship->specs;
		s->gunL = a;
		s->carL = b;
		break;
		}
	case W_GUNR: {
		register struct shipspecs *s = ship->specs;
		s->gunR = a;
		s->carR = b;
		break;
		}
	case W_HULL:
		ship->specs->hull = a;
		break;
D 10
	case W_LAST:
		(void) strncpy(ship->file->last, (char *)a,
			sizeof ship->file->last - 1);
		ship->file->last[sizeof ship->file->last - 1] = 0;
E 10
I 10
	case W_MOVE:
		(void) strncpy(ship->file->movebuf, (char *)a,
			sizeof ship->file->movebuf - 1);
		ship->file->movebuf[sizeof ship->file->movebuf - 1] = 0;
E 10
		break;
	case W_PCREW:
		ship->file->pcrew = a;
		break;
	case W_POINTS:
		ship->file->points = a;
		break;
	case W_QUAL:
		ship->specs->qual = a;
		break;
	case W_RIGG: {
		register struct shipspecs *s = ship->specs;
		s->rig1 = a;
		s->rig2 = b;
		s->rig3 = c;
		s->rig4 = d;
		break;
		}
	case W_RIG1:
		ship->specs->rig1 = a;
		break;
	case W_RIG2:
		ship->specs->rig2 = a;
		break;
	case W_RIG3:
		ship->specs->rig3 = a;
		break;
	case W_RIG4:
		ship->specs->rig4 = a;
		break;
D 10
	case W_SHIPCOL:
E 10
I 10
	case W_COL:
E 10
		ship->file->col = a;
		break;
D 10
	case W_SHIPDIR:
E 10
I 10
	case W_DIR:
E 10
		ship->file->dir = a;
		break;
D 10
	case W_SHIPROW:
E 10
I 10
	case W_ROW:
E 10
		ship->file->row = a;
		break;
	case W_SINK:
		if ((ship->file->sink = a) == 2)
			ship->file->dir = 0;
		break;
	case W_STRUCK:
		ship->file->struck = a;
		break;
	case W_TA:
		ship->specs->ta = a;
		break;
	case W_ALIVE:
		alive = 1;
		break;
	case W_TURN:
		turn = a;
		break;
	case W_WIND:
		winddir = a;
		windspeed = b;
		break;
	case W_BEGIN:
		(void) strcpy(ship->file->captain, "begin");
		people++;
		break;
	case W_END:
D 12
		(void) strcpy(ship->file->captain, "");
E 12
I 12
		*ship->file->captain = 0;
		ship->file->points = 0;
E 12
		people--;
		break;
D 12
	default:
		fprintf(stderr, "sync_update: unknown type %d\n", type);
E 12
I 12
	case W_DDEAD:
		hasdriver = 0;
E 12
		break;
I 12
	default:
		fprintf(stderr, "sync_update: unknown type %d\r\n", type);
		return -1;
E 12
	}
I 12
	return 0;
E 12
}
E 1
