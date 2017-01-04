h05144
s 00010/00005/00270
d D 5.2 88/06/19 14:10:48 bostic 5 4
c install approved copyright notice
e
s 00011/00005/00264
d D 5.1 88/05/08 15:49:14 bostic 4 3
c add Berkeley header; yank to 5.1
e
s 00006/00000/00263
d D 1.3 85/04/24 15:32:41 edward 3 2
c copyright messages
e
s 00008/00008/00255
d D 1.2 84/11/28 18:31:25 edward 2 1
c Dave's changes
e
s 00263/00000/00000
d D 1.1 84/11/18 18:58:35 edward 1 0
c date and time created 84/11/18 18:58:35 by edward
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

wearit()		/* synonyms = {sheathe, sheath} */
{
	register int n;
	int firstnumber, value;

	firstnumber = wordnumber;
	while(wordtype[++wordnumber] == ADJS);
	while(wordnumber <= wordcount){
		value = wordvalue[wordnumber];
		for (n=0; objsht[value][n]; n++);
		switch(value){
			
			case -1:
				puts("Wear what?");
				return(firstnumber);

			default:
				printf("You can't wear%s%s!\n",(objsht[value][n-1] == 's' ? " " : " a "),objsht[value]);
				return(firstnumber);

			case KNIFE:
		/*	case SHIRT:	*/
			case ROBE:
			case LEVIS:	/* wearable things */
			case SWORD:
			case MAIL:
			case HELM:
			case SHOES:
			case PAJAMAS:
			case COMPASS:
			case LASER:
			case AMULET:
			case TALISMAN:
			case MEDALION:
			case ROPE:
			case RING:
			case BRACELET:
			case GRENADE:

				if (testbit(inven,value)){
					clearbit(inven,value);
					setbit(wear,value);
					carrying -= objwt[value];
					encumber -= objcumber[value];
					time++;
					printf("You are now wearing %s %s.\n",(objsht[value][n-1] == 's' ? "the" : "a"), objsht[value]);
				}
				else if (testbit(wear,value))
					printf("You are already wearing the %s.\n", objsht[value]);
				else 
					printf("You aren't holding the %s.\n", objsht[value]);
				if (wordnumber < wordcount - 1 && wordvalue[++wordnumber] == AND)
					wordnumber++;
				else 
					return(firstnumber);
		} /* end switch */
	} /* end while */
	puts("Don't be ridiculous.");
	return(firstnumber);
}

put()		/* synonyms = {buckle, strap, tie} */
{
	if (wordvalue[wordnumber + 1] == ON){
		wordvalue[++wordnumber] = PUTON;
		return(cypher());
	}
	if (wordvalue[wordnumber + 1] == DOWN){
		wordvalue[++wordnumber] = DROP;
		return(cypher());
	}
	puts("I don't understand what you want to put.");
	return(-1);

}

draw() 			/* synonyms = {pull, carry} */
{
	return(take(wear));
}

use()
{
	while (wordtype[++wordnumber] == ADJS && wordnumber < wordcount);
	if (wordvalue[wordnumber] == AMULET && testbit(inven,AMULET) && position != FINAL){
		puts("The amulet begins to glow.");
		if (testbit(inven,MEDALION)){
			puts("The medallion comes to life too.");
			if (position == 114){
				location[position].down = 160;
				whichway(location[position]);
				puts("The waves subside and it is possible to descend to the sea cave now.");
				time++;
				return(-1);
			}
		}
		puts("A light mist falls over your eyes and the sound of purling water trickles in");
		puts("your ears.   When the mist lifts you are standing beside a cool stream.");
		if (position == 229)
			position = 224;
		else
			position = 229;
		time++;
		return(0);
	}
	else if (position == FINAL)
		puts("The amulet won't work in here.");
	else if (wordvalue[wordnumber] == COMPASS && testbit(inven,COMPASS))
		printf("Your compass points %s.\n",truedirec(NORTH,'-'));
	else if (wordvalue[wordnumber] == COMPASS)
		puts("You aren't holding the compass.");
	else if (wordvalue[wordnumber] == AMULET)
		puts("You aren't holding the amulet.");
	else
		puts("There is no apparent use.");
	return(-1);
}

murder()
{
	register int n;

	for (n=0; !((n == SWORD || n == KNIFE || n == TWO_HANDED || n == MACE || n == CLEAVER || n == BROAD || n == CHAIN || n == SHOVEL || n == HALBERD) && testbit(inven,n)) && n < NUMOFOBJECTS; n++);
	if (n == NUMOFOBJECTS)
		puts("You don't have suitable weapons to kill.");
	else {
		printf("Your %s should do the trick.\n",objsht[n]);
		while (wordtype[++wordnumber] == ADJS);
		switch(wordvalue[wordnumber]){
			
			case NORMGOD:
				if (testbit(location[position].objects,BATHGOD)){
					puts("The goddess's head slices off.  Her corpse floats in the water.");
					clearbit(location[position].objects,BATHGOD);
					setbit(location[position].objects,DEADGOD);
					power += 5;
					notes[JINXED]++;
				} else if (testbit(location[position].objects,NORMGOD)){
					puts("The goddess pleads but you strike her mercilessly.  Her broken body lies in a\npool of blood.");
					clearbit(location[position].objects,NORMGOD);
					setbit(location[position].objects,DEADGOD);
					power += 5;
					notes[JINXED]++;
					if (wintime)
						live();
				} else puts("I dont see her anywhere.");
				break;
			case TIMER:
				if (testbit(location[position].objects,TIMER)){
					puts("The old man offers no resistance.");
					clearbit(location[position].objects,TIMER);
					setbit(location[position].objects,DEADTIME);
					power++;
					notes[JINXED]++;
				} else puts("Who?");
				break;
			case NATIVE:
				if (testbit(location[position].objects,NATIVE)){
					puts("The girl screams as you cut her body to shreds.  She is dead.");
					clearbit(location[position].objects,NATIVE);
					setbit(location[position].objects,DEADNATIVE);
					power += 5;
					notes[JINXED]++;
				} else puts("What girl?");
				break;
			case MAN:
				if (testbit(location[position].objects,MAN)){
D 2
					puts("You strike him to the ground and he coughs up blood.");
E 2
I 2
					puts("You strike him to the ground, and he coughs up blood.");
E 2
					puts("Your fantasy is over.");
					die();
				}
			case -1:
				puts("Kill what?");
				break;

			default:
				if (wordtype[wordnumber] != NOUNS)
					puts("Kill what?");
				else
					printf("You can't kill the %s!\n",objsht[wordvalue[wordnumber]]);
		}
	}
}

ravage()
{
	while (wordtype[++wordnumber] != NOUNS && wordnumber <= wordcount);
	if (wordtype[wordnumber] == NOUNS && testbit(location[position].objects,wordvalue[wordnumber])){
		time++;
		switch(wordvalue[wordnumber]){
			case NORMGOD:
D 2
				puts("You attack the goddess and she screams as you beat her.  She falls down");
E 2
I 2
				puts("You attack the goddess, and she screams as you beat her.  She falls down");
E 2
				puts("crying and tries to hold her torn and bloodied dress around her.");
				power += 5;
				pleasure += 8;
				ego -= 10;
				wordnumber--;
				godready = -30000;
				murder();
				win = -30000;
				break;
			case NATIVE:
D 2
				puts("The girl tries to run but you catch her and throw her down.  Her face is");
				puts("bleeding and she screams as you tear off her clothes.");
E 2
I 2
				puts("The girl tries to run, but you catch her and throw her down.  Her face is");
				puts("bleeding, and she screams as you tear off her clothes.");
E 2
				power += 3;
				pleasure += 5;
				ego -= 10;
				wordnumber--;
				murder();
D 2
				if (rnd(100) < 20){
E 2
I 2
				if (rnd(100) < 50){
E 2
					puts("Her screams have attracted attention.  I think we are surrounded.");
					setbit(location[ahead].objects,WOODSMAN);
					setbit(location[ahead].objects,DEADWOOD);
					setbit(location[ahead].objects,MALLET);
					setbit(location[back].objects,WOODSMAN);
					setbit(location[back].objects,DEADWOOD);
					setbit(location[back].objects,MALLET);
					setbit(location[left].objects,WOODSMAN);
					setbit(location[left].objects,DEADWOOD);
					setbit(location[left].objects,MALLET);
					setbit(location[right].objects,WOODSMAN);
					setbit(location[right].objects,DEADWOOD);
					setbit(location[right].objects,MALLET);
				}
				break;
			default:
				puts("You are perverted.");
		}
	}
	else
		puts("Who?");
}

follow()
{
	if (followfight == time){
D 2
		puts("The Dark Lord leaps and runs down secret tunnels and corridoors.  You chase");
		puts("him through the darkness and splash in pools of water.  You have cornered him.");
		puts("His laser sword extends as he steps forward.");
E 2
I 2
		puts("The Dark Lord leaps away and runs down secret tunnels and corridoors.");
		puts("You chase him through the darkness and splash in pools of water.");
		puts("You have cornered him.  His laser sword extends as he steps forward.");
E 2
		position = FINAL;
		fight(DARK,75);
		setbit(location[position].objects,TALISMAN);
		setbit(location[position].objects,AMULET);
		return(0);
	}
	else if (followgod == time){
		puts("The goddess leads you down a steamy tunnel and into a high, wide chamber.");
		puts("She sits down on a throne.");
		position = 268;
		setbit(location[position].objects,NORMGOD);
		notes[CANTSEE] = 1;
		return(0);
	}
	else 
		puts("There is no one to follow.");
	return(-1);
}
E 1
