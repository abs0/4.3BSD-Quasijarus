h50158
s 00010/00005/00350
d D 5.2 88/06/19 14:10:53 bostic 5 4
c install approved copyright notice
e
s 00011/00005/00344
d D 5.1 88/05/08 15:49:17 bostic 4 3
c add Berkeley header; yank to 5.1
e
s 00006/00000/00343
d D 1.3 85/04/24 15:28:21 edward 3 2
c copyright messages
e
s 00029/00021/00314
d D 1.2 84/11/28 18:29:18 edward 2 1
c Dave's changes
e
s 00335/00000/00000
d D 1.1 84/11/18 18:58:38 edward 1 0
c date and time created 84/11/18 18:58:38 by edward
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

take(from)
unsigned int from[];
{
	int firstnumber, heavy, bulky, value;
	register int n;

	firstnumber = wordnumber;
	if (wordnumber < wordcount && wordvalue[wordnumber+1] == OFF){
		wordnumber++;
		wordvalue[wordnumber] = TAKEOFF;
		return(cypher());
	}
	else {
		while(wordtype[++wordnumber] == ADJS);
		while(wordnumber<=wordcount && wordtype[wordnumber] == OBJECT){
			value = wordvalue[wordnumber];
			printf("%s:\n", objsht[value]);
			for (n=0; objsht[value][n]; n++);
			heavy = (carrying + objwt[value]) <= WEIGHT;
			bulky = (encumber + objcumber[value]) <= CUMBER;
			if ((testbit(from,value) || wiz || tempwiz) && heavy && bulky && !testbit(inven,value)){
				setbit(inven,value);
				carrying += objwt[value];
				encumber += objcumber[value];
				time++;
				if (testbit(from,value))
					printf("Taken.\n");
				else
					printf("Zap! Taken from thin air.\n");
				clearbit(from,value);
				if (value == MEDALION)
					win--;
			}
			else if (testbit(inven,value))
				printf("You're already holding%s%s.\n", (objsht[value][n-1] == 's' ? " " : " a "),objsht[value]);
			else if (!heavy)
				printf("The %s %s too heavy.\n", objsht[value],(objsht[value][n-1] == 's' ? "are" : "is"));
			else if (!bulky)
				printf("The %s %s too cumbersome to hold.\n", objsht[value],(objsht[value][n-1] == 's' ? "are" : "is"));
			else
				printf("I dont see any %s around here.\n", objsht[value]);
			if (wordnumber < wordcount -1 && wordvalue[++wordnumber] == AND)
				wordnumber++;
			else
				return(firstnumber);
		}
	}
			    /* special cases with their own return()'s */

	if (wordnumber <= wordcount && wordtype[wordnumber] == NOUNS)
		switch(wordvalue[wordnumber]){
			
			case SWORD:
				if (testbit(from, SWORD)){
					wordtype[wordnumber--] = OBJECT;
					return(take(from));
				}
				if (testbit(from, TWO_HANDED)){
					wordvalue[wordnumber] = TWO_HANDED;
					wordtype[wordnumber--] = OBJECT;
					return(take(from));
				}
				wordvalue[wordnumber] = BROAD;
				wordtype[wordnumber--] = OBJECT;
				return(take(from));

			case BODY:
				if (testbit(from,MAID)){
					wordvalue[wordnumber] = MAID;
					wordtype[wordnumber--] = OBJECT;
					return(take(from));
				}
				else if (testbit(from,DEADWOOD)){
					wordvalue[wordnumber] = DEADWOOD;
					wordtype[wordnumber--] = OBJECT;
					return(take(from));
				}
				else if (testbit(from,DEADNATIVE)){
					wordvalue[wordnumber] = DEADNATIVE;
					wordtype[wordnumber--] = OBJECT;
					return(take(from));
				}
				else if (testbit(from,DEADGOD)){
					wordvalue[wordnumber] = DEADGOD;
					wordtype[wordnumber--] = OBJECT;
					return(take(from));
				}
				else {
					wordvalue[wordnumber] = DEADTIME;
					wordtype[wordnumber--] = OBJECT;
					return(take(from));
				}
				break;

			case AMULET:
				if (testbit(location[position].objects,AMULET)){
D 2
					puts("The amulet is warm to the touch and its beauty catches your breath.");
					puts("A mist falls over your eyes and then it is gone.  Sounds seem clearer");
E 2
I 2
					puts("The amulet is warm to the touch, and its beauty catches your breath.");
					puts("A mist falls over your eyes, but then it is gone.  Sounds seem clearer");
E 2
					puts("and sharper but far away as if in a dream.  The sound of purling water reaches");
D 2
					puts("you from afar.  The mist falls again and your heart leaps in horror.  The gold");
E 2
I 2
					puts("you from afar.  The mist falls again, and your heart leaps in horror.  The gold");
E 2
					puts("freezes your hands and fathomless darkness engulfs your soul.");
				}
				wordtype[wordnumber--] = OBJECT;
				return(take(from));

			case MEDALION:
				if (testbit(location[position].objects, MEDALION)){
D 2
					puts("The medallion is warm and it rekindles your spirit with the warmth of life.");
E 2
I 2
					puts("The medallion is warm, and it rekindles your spirit with the warmth of life.");
E 2
					puts("Your amulet begins to glow as the medallion is brought near to it, and together\nthey radiate.");
				}
				wordtype[wordnumber--] = OBJECT;
				return(take(from));

			case TALISMAN:
				if (testbit(location[position].objects,TALISMAN)){
D 2
					puts("The talisman is cold to the touch and it sends a chill down your spine.");
E 2
I 2
					puts("The talisman is cold to the touch, and it sends a chill down your spine.");
E 2
				}
				wordtype[wordnumber--] = OBJECT;
				return(take(from));

			case NORMGOD:
				if (testbit(location[position].objects,BATHGOD) && (testbit(wear,AMULET) || testbit(inven,AMULET))){
D 2
					puts("She offers a delicate hand and you help her out of the sparkling springs.");
E 2
I 2
					puts("She offers a delicate hand, and you help her out of the sparkling springs.");
E 2
					puts("Water droplets like liquid silver bedew her golden skin, but when they part");
					puts("from her, they fall as teardrops.  She wraps a single cloth around her and");
					puts("ties it at the waist.  Around her neck hangs a golden amulet.");
					puts("She bids you to follow her.");
					pleasure++;
					followgod = time;
					clearbit(location[position].objects,BATHGOD);
				} else if (!testbit(location[position].objects,BATHGOD))
					puts("You're in no position to take her.");
				else 
					puts("She moves away from you.");
				break;

			default:
				puts("It doesn't seem to work.");
		}
	else
		puts("You've got to be kidding.");
	return(firstnumber);
}

D 2
throw()
E 2
I 2
throw(name)
	char *name;
E 2
{
	int n;
	int deposit = 0;
	int first, value;

	first = wordnumber;
D 2
	if (drop("Thrown") != -1){
E 2
I 2
	if (drop(name) != -1){
E 2
		switch(wordvalue[wordnumber]){
			
			case AHEAD:
				deposit = ahead;
				break;

			case BACK:
				deposit = back;
				break;

			case LEFT:
				deposit = left;
				break;

			case RIGHT:
				deposit = right;
				break;

			case UP:
				deposit = location[position].up * (location[position].access || position == FINAL);
				break;

			case DOWN:
				deposit = location[position].down;
				break;
		}
		wordnumber = first;
		while (wordtype[++wordnumber] == ADJS);
		while (wordnumber <= wordcount){
			value = wordvalue[wordnumber];
			if (deposit && testbit(location[position].objects,value)){
				clearbit(location[position].objects,value);
				if (value != GRENADE)
					setbit(location[deposit].objects,value);
				else{
					puts("A thundering explosion nearby sends up a cloud of smoke and shrapnel.");
					for (n = 0; n < NUMOFWORDS; n ++)
						location[deposit].objects[n] = 0;
					setbit(location[deposit].objects,CHAR);
				}
				if (value == ROPE && position == FINAL)
					location[position].access = 1;
				switch(deposit){
					case 189:
					case 231:
						puts("The stone door is unhinged.");
						location[189].north = 231;
						location[231].south = 189;
						break;
					case 30:
						puts("The wooden door is blown open.");
						location[30].west = 25;
						break;
					case 31:
						puts("The door is not damaged.");
				}
			}
			else if (value == GRENADE && testbit(location[position].objects,value)){
				puts("You are blown into shreds when your grenade explodes.");
				die();
			}
			if (wordnumber < wordcount - 1 && wordvalue[++wordnumber] == AND)
				wordnumber++;
			else 
				return(first);
		}
		return(first);
	}
	return(first);
}

drop(name)
char *name;
{
	
	int firstnumber, value;

	firstnumber = wordnumber;
D 2
	while(wordtype[++wordnumber] == ADJS);
	while(wordnumber<=wordcount && (wordtype[wordnumber] == OBJECT || wordtype[wordnumber] == NOUNS)){
E 2
I 2
	while (wordtype[++wordnumber] == ADJS)
		;
	while (wordnumber<=wordcount && (wordtype[wordnumber] == OBJECT || wordtype[wordnumber] == NOUNS)) {
E 2
		value = wordvalue[wordnumber];
		printf("%s:\n", objsht[value]);
		if (testbit(inven,value)){
			clearbit(inven,value);
			carrying -= objwt[value];
			encumber -= objcumber[value];
			if (value == BOMB){
				puts("The bomb explodes.  A blinding white light and immense concussion obliterate us.");
				die();
			}
			if (value != AMULET && value != MEDALION && value != TALISMAN)
				setbit(location[position].objects,value);
			else
				tempwiz = 0;
			time++;
D 2
			printf("%s.\n", name);
E 2
I 2
			if (*name == 'K')
				puts("Drop kicked.");
			else
				printf("%s.\n", name);
E 2
		}
		else {
D 2
			printf("You aren't holding the %s.\n", objsht[value]);
			if (testbit(location[position].objects,value)){
				if (*name == 'T')
					puts("Kicked instead.");
				if (*name == 'G')
					puts("Given anyway.");
			}
E 2
I 2
			if (*name != 'K') {
				printf("You aren't holding the %s.\n", objsht[value]);
				if (testbit(location[position].objects,value)) {
					if (*name == 'T')
						puts("Kicked instead.");
					else if (*name == 'G')
						puts("Given anyway.");
				}
			} else
				puts("Kicked.");
E 2
		}
		if (wordnumber < wordcount - 1 && wordvalue[++wordnumber] == AND)
			wordnumber++;
		else
			return(firstnumber);
	}
	puts("Do what?");
	return(-1);
}

takeoff()
{
	wordnumber = take(wear);
	return(drop("Dropped"));
}

puton()
{
	wordnumber = take(location[position].objects);
	return(wearit());
}

eat()
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
				puts("Eat what?");
				return(firstnumber);

			default:
				printf("You can't eat%s%s!\n",(objsht[value][n-1] == 's' ? " " : " a "),objsht[value]);
				return(firstnumber);

			case PAPAYAS:
			case PINEAPPLE:
			case KIWI:
			case COCONUTS:	/* eatable things */
			case MANGO:

				printf("%s:\n",objsht[value]);
				if (testbit(inven,value) && time > ate - CYCLE && testbit(inven,KNIFE)){
					clearbit(inven,value);
					carrying -= objwt[value];
					encumber -= objcumber[value];
					ate = max(time,ate) + CYCLE/3;
					snooze += CYCLE/10;
					time++;
D 2
					puts("Eaten.  I can explore a little longer now.");
E 2
I 2
					puts("Eaten.  You can explore a little longer now.");
E 2
				}
				else if (time < ate - CYCLE)
D 2
					puts("I'm stuffed.");
E 2
I 2
					puts("You're stuffed.");
E 2
				else if (!testbit(inven,KNIFE))
					puts("You need a knife.");
				else
					printf("You aren't holding the %s.\n", objsht[value]);
				if (wordnumber < wordcount - 1 && wordvalue[++wordnumber] == AND)
					wordnumber++;
				else 
					return(firstnumber);
		} /* end switch */
	} /* end while */
	return(firstnumber);
D 2
}	
E 2
I 2
}
E 2
E 1
