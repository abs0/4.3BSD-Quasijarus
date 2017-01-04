h09521
s 00010/00005/00179
d D 5.2 88/06/19 14:10:57 bostic 5 4
c install approved copyright notice
e
s 00011/00005/00173
d D 5.1 88/05/08 15:49:20 bostic 4 3
c add Berkeley header; yank to 5.1
e
s 00006/00000/00172
d D 1.3 85/04/24 15:28:45 edward 3 2
c copyright messages
e
s 00003/00001/00169
d D 1.2 84/11/28 18:29:33 edward 2 1
c Dave's changes
e
s 00170/00000/00000
d D 1.1 84/11/18 18:58:43 edward 1 0
c date and time created 84/11/18 18:58:43 by edward
e
u
U
t
T
I 3
/*
D 4
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 4
I 4
 * Copyright (c) 1983 Regents of the University of California.
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
D 4
static char sccsid[] = "%W% %G%";
#endif
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 4

#include "externs.h"

launch()
{
	if (testbit(location[position].objects,VIPER) && !notes[CANTLAUNCH]){
		if (fuel > 4){
			clearbit(location[position].objects,VIPER);
			position = location[position].up;
			notes[LAUNCHED] = 1;
			time++;
			fuel -= 4;
			puts("You climb into the viper and prepare for launch.");
			puts("With a touch of your thumb the turbo engines ignite, thrusting you back into\nyour seat.");
			return(1);
		}
		else
			puts("Not enough fuel to launch.");
	 }
	 else
		puts("Can't launch.");
	 return(0);
}

land()
{
	if (notes[LAUNCHED] && testbit(location[position].objects,LAND) && location[position].down){
		notes[LAUNCHED] = 0;
		position = location[position].down;
		setbit(location[position].objects,VIPER);
		fuel -= 2;
		time++;
		puts("You are down.");
		return(1);
	}
	else
		puts("You can't land here.");
	return(0);
}

die() 		/* endgame */
{
	printf("bye.\nYour rating was %s.\n", rate());
	post(' ');
	exit(0);
}

live()
{
	puts("\nYou win!");
	post('!');
	exit(0);
}

#include <sys/time.h>
post(ch)
char ch;
{
	FILE *fp;
	struct timeval tv;
	char *date;
I 2
	int s = sigblock(sigmask(SIGINT));
E 2

	gettimeofday(&tv, (struct timezone *)0);	/* can't call time */
	date = ctime(&tv.tv_sec);
	date[24] = '\0';
	if (fp = fopen(logfile,"a")) {
		fprintf(fp, "%s  %8s  %c%20s", date, uname, ch, rate());
		if (wiz)
			fprintf(fp, "   wizard\n");
		else if (tempwiz)
			fprintf(fp, "   WIZARD!\n");
		else
			fprintf(fp, "\n");
	} else
		perror(logfile);
I 2
	sigsetmask(s);
E 2
}

char *
rate()
{
	int score;

	score = max(max(pleasure,power),ego);
	if (score == pleasure){
		if (score < 5)
			return("novice");
		else if (score < 20)
			return("junior voyeur");
		else if (score < 35)
			return("Don Juan");
		else return("Marquis De Sade");
	}
	else if (score == power){
		if (score < 5)
			return("serf");
		else if (score < 8)
			return("Samurai");
		else if (score < 13)
			return("Klingon");
		else if (score < 22)
			return("Darth Vader");
		else return("Sauron the Great");
	}
	else{
		if (score < 5)
			return("Polyanna");
		else if (score < 10)
			return("philanthropist");
		else if (score < 20)
			return("Tattoo");
		else return("Mr. Roarke");
	}
}

drive()
{
	if (testbit(location[position].objects,CAR)){
D 2
		puts("You hop in the car and turn the key.  There is a perceptible grating noise");
E 2
I 2
		puts("You hop in the car and turn the key.  There is a perceptible grating noise,");
E 2
		puts("and an explosion knocks you unconscious...");
		clearbit(location[position].objects,CAR);
		setbit(location[position].objects,CRASH);
		injuries[5] = injuries[6] = injuries[7] = injuries[8] = 1;
		time += 15;
		zzz();
		return(0);
	}
	else
		puts("There is nothing to drive here.");
	return(-1);
}

ride()
{
	if (testbit(location[position].objects,HORSE)){
		puts("You climb onto the stallion and kick it in the guts.  The stupid steed launches");
		puts("forward through bush and fern.  You are thrown and the horse gallups off.");
		clearbit(location[position].objects,HORSE);
		while (!(position = rnd(NUMOFROOMS+1)) || !OUTSIDE || !beenthere[position] || location[position].flyhere);
		setbit(location[position].objects,HORSE);
		if (location[position].north)
			position = location[position].north;
		else if (location[position].south)
			position = location[position].south;
		else if (location[position].east)
			position = location[position].east;
		else
			position = location[position].west;
		return(0);
	}
	else puts("There is no horse here.");
	return(-1);
}

light()		/* synonyms = {strike, smoke} */
{		/* for matches, cigars */
	if (testbit(inven,MATCHES) && matchcount){
		puts("Your match splutters to life.");
		time++;
		matchlight = 1;
		matchcount--;
		if (position == 217){
			puts("The whole bungalow explodes with an intense blast.");
			die();
		}
	}
	else puts("You're out of matches.");
}
E 1
