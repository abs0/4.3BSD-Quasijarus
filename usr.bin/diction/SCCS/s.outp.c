h03500
s 00047/00013/00278
d D 4.2 82/11/06 14:34:04 rrh 2 1
c Bill Jolitz @ Berkeley received this version from Lorindia Cherry
c around September 1981, as the ``most recent version''.  Deltas 
c seem to be progressive, rather than regressive, although the BTL sid for
c deroff.c is retrograde; this is probably a case of parallel development
e
s 00291/00000/00000
d D 4.1 82/11/06 13:47:48 rrh 1 0
c Oldest available version at Berkeley
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%E%";
#endif not lint

I 2
#include <stdio.h>
#include <ctype.h>
E 2
#include "style.h"
#include "names.h"
#include "conp.h"
char *names[] = {
	"noun", "verb", "interjection", "adjective", "adverb", "conjunction", "possessive",
D 2
	"pronoun", "article", "preposition", "auxiliary", "tobe", "subordinate conjunction", "", "expletive"
E 2
I 2
	"pronoun", "article", "preposition", "auxiliary", "tobe", "", "subordinate conjunction",  "expletive"
E 2
};
I 2
extern int barebones;
E 2
outp(){
	struct ss *st;
	char *ssp;
	char *spart, ff;
	int index, lverbc;
	int nn, sc, f, kk,comp, begsc;
	int conjf, verbf,lpas,bflg,lexp,olvb;
I 2
	int nom;
E 2
	int infinf, ovflg;
	int lvowel,nlet;
	int imper;
	float rd;
I 2
	extern FILE *deb;
	extern int nosave;
E 2

I 2
	if(barebones){
		for(sentp=sent;sentp->cc != END;sentp++)
			printf("%s %c %c\n",sentp->sp,sentp->ic,sentp->cc);
		printf("%s %c %c\n",sentp->sp,sentp->ic,sentp->cc);
		return;
	}
	if(topic){
		for(sentp=sent;sentp->cc != END;sentp++){
			if(sentp->cc==ADJ && (sentp+1)->cc==NOUN){
				printf("%s ",sentp->sp);
				sentp++;
				printf("%s\n",sentp->sp);
			}
			else if(sentp->cc==NOUN)printf("%s\n",sentp->sp);
		}
		return;
	}
E 2
	if(style){
	nn = kk = 0;
	for(sentp=sent;sentp->cc != END;sentp++){
		if(sentp->cc != ',' && sentp->cc != '"')nn++;
		if(sentp->cc == VERB || sentp->cc == BE || sentp->cc == AUX)kk++;
	}
	if(nn < 4 && kk == 0)return;
	}

D 2
	imper = lexp = lpas = index = lverbc = 0;
E 2
I 2
	imper = lexp = lpas = index = lverbc = nom = 0;
E 2
	conjf = verbf = kk = nn = sc = comp = begsc = 0;
	bflg = olvb = infinf = ovflg = 0;
	nlet = 0;
	f = 1;
	sentp=sent;
	while(sentp->cc != END){
/*	printf("%c:",sentp->ic);	*/
		if(sentp->cc == ';')comp++;
		else {
			if((sentp->cc != ',') && (sentp->cc != '"')){
				if(*sentp->sp != 'x'){
					nn++;
					nlet += sentp->leng;
				}
				kk++;
			}
		}
		switch(sentp->cc){
		case NOUN:
			spart ="noun";
			if(f)index=0;
I 2
			if((sentp->ic==NOM)||(sentp->ic==PNOUN  && islower(*(sentp->sp)))){
				sentp->ic = NOM;
				nom++;
				if(nosave && (deb != NULL))	/* SAVE NOM */
					fprintf(deb,"%s\n",sentp->sp);
			}
E 2
			if(*sentp->sp != 'x'){
				noun++;
				numnonf++;
				letnonf += sentp->leng;
			}
			bflg = infinf = ovflg = 0;
			break;
		case VERB:
			spart = "verb";
			if(f)index=1;
			if(sentp->ic==TO){
				infin++;
				infinf=1;
				lverbc++;
			}
			else {
				if(f)imper=1;
				if(ovflg == 0 && infinf == 0){
					ovflg = 1;
					lverbc++;
					olvb++;
				}
				numnonf++;
				letnonf += sentp->leng;
				if(infinf == 0){
					if(verbf == 0)verbf++;
					else if(conjf)comp++;
				}
D 2
				if(bflg && sentp->ic == ED)lpas = ++passive;
E 2
I 2
				if(bflg && sentp->ic == ED){lpas++; ++passive;}
E 2
			}
			break;
		case INTER:
			spart = "interj";
			if(f)index=2;
			bflg = infinf = ovflg = 0;
			break;
		case ADJ:
			spart = "adj";
			if(f)index=3;
			adj++;
			numnonf++;
I 2
			if(sentp->ic == NOM){
				nom++;
				if(nosave && (deb != NULL))	/* SAVE NOM */
					fprintf(deb,"%s\n",sentp->sp);
			}
E 2
			letnonf += sentp->leng;
			bflg = infinf = ovflg = 0;
			break;
		case ADV:
			spart = "adv";
			if(f)index=4;
			adv++;
			numnonf++;
			letnonf += sentp->leng;
			break;
		case CONJ:
			spart = "conj";
			conjc++;
			if(f)index=5;
			if(infinf && (sentp+1)->cc == VERB);
			else {
				if(verbf)conjf++;
				bflg = infinf = ovflg = 0;
			}
			break;
		case POS:
			spart = "pos";
			if(f)index=6;
			bflg = infinf = ovflg = 0;
			break;
		case PRONS:
		case PRONP:
			spart = "pron";
			pron++;
			if(f){
				index=7;
				if((sentp+1)->cc == BE){
				if(sentp->leng == 5 && *(sentp->sp) == 't' && *((sentp->sp)+3)=='r'){index=14;lexp=1;}
				else if(sentp->leng ==2&& *(sentp->sp) == 'i' ){index=14;lexp=1;}
				}
			}
			bflg = infinf = ovflg = 0;
			if(sentp->ic == THAT || sentp->ic == WHO)sc++;
			break;
		case ART:
			spart = "art";
			if(f)index=8;
			bflg = infinf = ovflg = 0;
			break;
		case PREP:
			spart = "prep";
			if(f)index=9;
			prepc++;
			bflg = infinf = ovflg = 0;
			break;
		case AUXX:
			spart = "aux";
			if(ovflg == 0 && infinf == 0){
				ovflg = 1;
				lverbc++;
				olvb++;
				aux++;
			}
			if(f)index=10;
			break;
		case BE:
			if(ovflg == 0 && infinf == 0){
				ovflg = 1;
				lverbc++;
				olvb++;
			}
			spart = "be";
			if(f)index=11;
			tobe++;
			bflg = 1;
			if(verbf == 0)verbf++;
			else if(conjf)comp++;
			break;
		case SUBCONJ:
			spart = "subcj";
			if(f){
				index=13;
				begsc++;
			}
			sc++;
			if((sentp-1)->cc != CONJ)
				verbf = conjf = 0;
			bflg = infinf = ovflg = 0;
			break;
		default:
			if(sentp->cc == ','){
				if(begsc)conjf=verbf=0;
			}
			spart = sentp->sp;
		}
	if(part){
		printf("%s	%s\n",spart,sentp->sp);
	}
D 2
	else if(pstyle){
		printf("%s ",sentp->sp);
		if(kk == 15){
			printf("\n");
			kk=0;
		}
	}
E 2
	if(style){
		ssp=sentp->sp;
		lvowel = 0;
		while(*ssp != '\0'){
			if(*ssp >= '0' && *ssp <= '9'){
				lvowel=0;
				break;
			}
			switch(*(ssp++)){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'y':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
			case 'Y':
				lvowel++;
				continue;
			}
		}
		if(lvowel != 0){
			vowel += lvowel;
			twds++;
		}
	}
		if(f){
			ff=sentp->cc;
			f=0;
		}
		sentp++;
	}
	if(part){
D 2
	printf(".	%s\n",sentp->sp);
E 2
I 2
		printf(".	%s\n",sentp->sp);
		if(sentno < MAXPAR && nn > 0)
			leng[sentno++] = nn;
E 2
	}
I 2
	if(nn == 0)return;
E 2
	numsent++;
	numlet += nlet;
	tverbc += lverbc;
	verbc += olvb;
	if(*(sentp->sp) == '?'){
		if(sc > 0)sc -= 1;
		qcount++;
	}
	else if(*(sentp->sp) == '/')icount++;
	else if(imper)icount++;
	if(rstyle||pstyle)rd = 4.71*((float)(nlet)/(float)(nn))+.5*(float)(nn)-21.43;
D 2
	if((rstyle&& rd>=rthresh)||(lstyle&&nn >= lthresh)||(pastyle&&lpas)||(estyle&&lexp)){
E 2
I 2
	if(pstyle ||
	    (rstyle&& rd>=rthresh)||(lstyle&&nn >= lthresh)||(pastyle&&lpas)||(estyle&&lexp)
	    || (nstyle && (nom > 1 || (nom && lpas)))|| (Nstyle && nom)){
E 2
		if(!part){
			for(st=sent, kk=0;st->cc != END;st++){
D 2
				printf("%s ",st->sp);
E 2
I 2
				if(st->ic == NOM)
					printf("*%s* ",st->sp);
				else printf("%s ",st->sp);
E 2
				if(kk++ >= 15){
					kk=0;
					printf("\n");
				}
			}
		}
		kk=1;
	}
	else kk=0;
	if(pstyle || kk){
		if(!part)printf("%s\n",sentp->sp);
		printf(" sentence length: %d ",nn);
		if(sc == 0){
			if(comp == 0)printf("SIMPLE ");
			else printf("COMPOUND ");
		}
		else if(comp == 0)printf("COMPLEX ");
		else printf("COMPOUND-COMPLEX ");
		if(index==14)printf(":expletive:");
		if(lpas)printf(":passive:");
		if(rstyle||pstyle)printf(" readability %4.2f ",rd);
		printf(": begins with %s\n\n",names[index]);
	}
	if(index < 15)beg[index]++;
	if(nn > maxsent){
		maxsent=nn;
		maxindex=numsent;
	}
	if(nn < minsent ){
		minsent = nn;
		minindex=numsent;
	}
	numwds += nn;
	if(nn > 49)nn=49;
	sleng[nn]++;
	if(sc == 0){
		if(comp == 0)simple++;
		else compound++;
	}
	else if(comp == 0)complex++;
	else compdx++;
}
E 1
