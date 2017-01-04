h21486
s 00010/00005/00404
d D 5.2 88/06/19 14:11:01 bostic 5 4
c install approved copyright notice
e
s 00011/00005/00398
d D 5.1 88/05/08 15:49:24 bostic 4 3
c add Berkeley header; yank to 5.1
e
s 00006/00000/00397
d D 1.3 85/04/24 15:29:11 edward 3 2
c copyright messages
e
s 00012/00020/00385
d D 1.2 84/11/28 18:29:50 edward 2 1
c Dave's changes
e
s 00405/00000/00000
d D 1.1 84/11/18 19:10:33 edward 1 0
c date and time created 84/11/18 19:10:33 by edward
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

cypher()
{
	register int n;
	int junk;
	int lflag = -1;
	char buffer[10];

	while (wordtype[wordnumber] == ADJS)
		wordnumber++;
	while (wordnumber <= wordcount) {
		switch(wordvalue[wordnumber]) {

			case UP:
				if (location[position].access || wiz || tempwiz) {
					if (!location[position].access)
						puts("Zap!  A gust of wind lifts you up.");
					if (!move(location[position].up, AHEAD))
						return(-1);
				} else {
					puts("There is no way up");
					return(-1);
				}
				lflag = 0;
				break;

			 case DOWN:
				if (!move(location[position].down, AHEAD))
					return(-1);
				lflag = 0;
				break;

			 case LEFT:
				if (!move(left, LEFT))
					return(-1);
				lflag = 0;
				break;

			 case RIGHT:
				if (!move(right, RIGHT))
					return(-1);
				lflag = 0;
				break;
			 
			 case AHEAD:
				if (!move(ahead, AHEAD))
					return(-1);
				lflag = 0;
				break;
			 
			 case BACK:
				if (!move(back, BACK))
					return(-1);
				lflag = 0;
				break;
			 
			 case SHOOT:
				if (wordnumber < wordcount && wordvalue[wordnumber+1] == EVERYTHING){
					for (n=0; n < NUMOFOBJECTS; n++)
						if (testbit(location[position].objects,n) && *objsht[n]){
							wordvalue[wordnumber+1] = n;
							wordnumber = shoot();
						}
				wordnumber++;
				wordnumber++;
				}
				else 
					shoot();
				break;

			 case TAKE:
				if (wordnumber < wordcount && wordvalue[wordnumber+1] == EVERYTHING){
					for (n=0; n < NUMOFOBJECTS; n++)
						if (testbit(location[position].objects,n) && *objsht[n]){
							wordvalue[wordnumber+1] = n;
							wordnumber = take(location[position].objects);
						}
				wordnumber++;
				wordnumber++;
				}
				else 
					take(location[position].objects);
				break;

			 case DROP:

				if (wordnumber < wordcount && wordvalue[wordnumber+1] == EVERYTHING){
					for (n=0; n < NUMOFOBJECTS; n++)
						if (testbit(inven,n)){
							wordvalue[wordnumber+1] = n;
							wordnumber = drop("Dropped");
						}
				wordnumber++;
				wordnumber++;
				}
				else 
					drop("Dropped");
				break;


I 2
			 case KICK:
E 2
			 case THROW:
D 2


E 2
				if (wordnumber < wordcount && wordvalue[wordnumber+1] == EVERYTHING){
					for (n=0; n < NUMOFOBJECTS; n++)
D 2
						if (testbit(inven,n)){
E 2
I 2
						if (testbit(inven,n) ||
						  testbit(location[position].objects, n) && *objsht[n]){
E 2
							wordvalue[wordnumber+1] = n;
D 2
							wordnumber = throw();
E 2
I 2
							wordnumber = throw(wordvalue[wordnumber] == KICK ? "Kicked" : "Thrown");
E 2
						}
D 2
				wordnumber++;
				wordnumber++;
				}
				else 
					throw();
E 2
I 2
					wordnumber += 2;
				} else 
					throw(wordvalue[wordnumber] == KICK ? "Kicked" : "Thrown");
E 2
				break;

			 case TAKEOFF:
D 2

E 2
				if (wordnumber < wordcount && wordvalue[wordnumber+1] == EVERYTHING){
					for (n=0; n < NUMOFOBJECTS; n++)
						if (testbit(wear,n)){
							wordvalue[wordnumber+1] = n;
							wordnumber = takeoff();
						}
D 2
				wordnumber++;
				wordnumber++;
E 2
I 2
					wordnumber += 2;
E 2
				}
				else 
					takeoff();
				break;


			 case DRAW:

				if (wordnumber < wordcount && wordvalue[wordnumber+1] == EVERYTHING){
					for (n=0; n < NUMOFOBJECTS; n++)
						if (testbit(wear,n)){
							wordvalue[wordnumber+1] = n;
							wordnumber = draw();
						}
D 2
				wordnumber++;
				wordnumber++;
E 2
I 2
					wordnumber += 2;
E 2
				}
				else 
					draw();
				break;


			 case PUTON:

				if (wordnumber < wordcount && wordvalue[wordnumber+1] == EVERYTHING){
					for (n=0; n < NUMOFOBJECTS; n++)
						if (testbit(location[position].objects,n) && *objsht[n]){
							wordvalue[wordnumber+1] = n;
							wordnumber = puton();
						}
D 2
				wordnumber++;
				wordnumber++;
E 2
I 2
					wordnumber += 2;
E 2
				}
				else 
					puton();
				break;

			 case WEARIT:

				if (wordnumber < wordcount && wordvalue[wordnumber+1] == EVERYTHING){
					for (n=0; n < NUMOFOBJECTS; n++)
						if (testbit(inven,n)){
							wordvalue[wordnumber+1] = n;
							wordnumber = wearit();
						}
D 2
				wordnumber++;
				wordnumber++;
E 2
I 2
					wordnumber += 2;
E 2
				}
				else 
					wearit();
				break;


			 case EAT:

				if (wordnumber < wordcount && wordvalue[wordnumber+1] == EVERYTHING){
					for (n=0; n < NUMOFOBJECTS; n++)
						if (testbit(inven,n)){
							wordvalue[wordnumber+1] = n;
							wordnumber = eat();
						}
D 2
				wordnumber++;
				wordnumber++;
E 2
I 2
					wordnumber += 2;
E 2
				}
				else 
					eat();
				break;


			case PUT:
				put();
				break;


			case INVEN:
				if (ucard(inven)){
					puts("You are holding:\n");
					for (n=0; n < NUMOFOBJECTS; n++)
						if (testbit(inven,n))
							printf("\t%s\n", objsht[n]);
					printf("\n= %d kilogram%s (%d%%)\n", carrying, (carrying == 1 ? "." : "s."),(WEIGHT ? carrying*100/WEIGHT : -1));
					printf("Your arms are %d%% full.\n",encumber*100/CUMBER);
				}
				else
					puts("You aren't carrying anything.");
					
				if (ucard(wear)){
					puts("\nYou are wearing:\n");
					for (n=0; n < NUMOFOBJECTS; n++)
						if (testbit(wear,n))
							printf("\t%s\n", objsht[n]);
				}
				else
					puts("\nYou are stark naked.");
				if (card(injuries,NUMOFINJURIES)){
					puts("\nYou have suffered:\n");
					for (n=0; n < NUMOFINJURIES; n++)
						if (injuries[n])
							printf("\t%s\n",ouch[n]);
					printf("\nYou can still carry up to %d kilogram%s\n",WEIGHT,(WEIGHT == 1 ? "." : "s."));
				}
				else
					puts("\nYou are in perfect health.");
				break;

			case USE:
				lflag = use();
				break;

			case LOOK:
				if (!notes[CANTSEE] || testbit(inven,LAMPON) || testbit(location[position].objects,LAMPON) || matchlight){
					beenthere[position] = 2;
					writedes();
					printobjs();
					if (matchlight){
						puts("\nYour match splutters out.");
						matchlight = 0;
					}
				} else 
					puts("I can't see anything.");
				return(-1);
				break;

			 case SU:
			 if (wiz || tempwiz){
				printf("\nRoom (was %d) = ", position);
				fgets(buffer,10,stdin);
				if (*buffer != '\n')
					sscanf(buffer,"%d", &position);
				printf("Time (was %d) = ",time);
				fgets(buffer,10,stdin);
				if (*buffer != '\n')
					sscanf(buffer,"%d", &time);
				printf("Fuel (was %d) = ",fuel);
				fgets(buffer,10,stdin);
				if (*buffer != '\n')
					sscanf(buffer,"%d", &fuel);
				printf("Torps (was %d) = ",torps);
				fgets(buffer,10,stdin);
				if (*buffer != '\n')
					sscanf(buffer,"%d", &torps);
				printf("CUMBER (was %d) = ",CUMBER);
				fgets(buffer,10,stdin);
				if (*buffer != '\n')
					sscanf(buffer,"%d", &CUMBER);
				printf("WEIGHT (was %d) = ",WEIGHT);
				fgets(buffer,10,stdin);
				if (*buffer != '\n')
					sscanf(buffer,"%d",&WEIGHT);
				printf("Clock (was %d) = ",clock);
				fgets(buffer,10,stdin);
				if (*buffer != '\n')
					sscanf(buffer,"%d",&clock);
				printf("Wizard (was %d, %d) = ",wiz, tempwiz);
				fgets(buffer,10,stdin);
				if (*buffer != '\n'){
					sscanf(buffer,"%d",&junk);
					if (!junk)
						tempwiz = wiz = 0;
				}
				printf("\nDONE.\n");
				return(0);
			 }
			 else
				 puts("You aren't a wizard.");
			 break;
				
			 case SCORE:
				printf("\tPLEASURE\tPOWER\t\tEGO\n");
				printf("\t%3d\t\t%3d\t\t%3d\n\n",pleasure,power,ego);
				printf("This gives you the rating of %s in %d turns.\n",rate(),time);
				printf("You have visited %d out of %d rooms this run (%d%%).\n",card(beenthere,NUMOFROOMS),NUMOFROOMS,card(beenthere,NUMOFROOMS)*100/NUMOFROOMS);
				break;

			 case KNIFE:
			 case KILL:
				murder();
				break;

			 case UNDRESS:
			 case RAVAGE:
				ravage();
				break;

			 case SAVE:
				save();
				break;

			 case FOLLOW:
				lflag = follow();
				break;

			 case GIVE:
				give();
				break;

			 case KISS:
				kiss();
				break;

			 case LOVE:
				 love();
				 break;

			 case RIDE:
				lflag = ride();
				break;

			 case DRIVE:
				lflag = drive();
				break;

			 case LIGHT:
				 light();
				 break;

			 case LAUNCH:
				if (!launch())
					return(-1);
				else 
					lflag = 0;
				break;

			case LANDIT:
				if (!land())
					return(-1);
				else
					lflag = 0;
				break;

			case TIME:
				chime();
				break;

			 case SLEEP:
				zzz();
				break;

			 case DIG:
				dig();
				break;

			 case JUMP:
				lflag = jump();
				break;

			 case BURY:
				bury();
				break;

			 case SWIM:
				puts("Surf's up!");
				break;

			 case DRINK:
				drink();
				break;

			 case QUIT:
				die();

			 default:
				puts("How's that?");
				return(-1);
				break;

			 
		}
		if (wordnumber < wordcount && *words[wordnumber++] == ',')
			continue;
		else return(lflag);
       }
       return(lflag);
}
E 1
