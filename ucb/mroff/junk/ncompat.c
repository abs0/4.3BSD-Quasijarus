#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif lint

/*
nroff compatibility table
*/

/* convert an old nroff terminal table */
convert_codetab()
{
	char *ocodetab[224];
	extern int ncompat[512];
	register int i, j;

	bcopy(t.codetab, ocodetab, sizeof(char *) * 224);
	for (i = 0; i < 512; i++) {
		j = ncompat[i];
		if (j < 256) {
			if (j < 32)
				t.codetab[i] = "\0";
			else
				t.codetab[i] = ocodetab[j-32];
		} else
			t.codetab[i] = (char *) j;
	}
}

int ncompat[512] = {
0,		/*00*/
0,		/*01*/
0,		/*02*/
0,		/*03*/
0,		/*04*/
0,		/*05*/
(int)"\004(tm)",/*06 trademark*/
0201,		/*07 bullet*/
0,		/*08*/
0,		/*09*/
0,		/*0A*/
0,		/*0B*/
0,		/*0C*/
0,		/*0D*/
0,		/*0E*/
0,		/*0F*/
(int) "\001<",	/*10 guilsinglleft*/
(int) "\001>",	/*11 guilsinglright*/
0,		/*12*/
0,		/*13*/
0,		/*14*/
(int) "\001\"",	/*15 quotedblbase*/
(int) "\001\"",	/*16 quotedblleft*/
(int) "\001\"",	/*17 quotedblright*/
(int) "\001\'",	/*18 quotesinglbase*/
(int) "\001\'",	/*19 quotesingle*/
0,		/*1A*/
0,		/*1B*/
0,		/*1C*/
0,		/*1D*/
0,		/*1E*/
0,		/*1F*/
' ','!','\"','#','$','%','&','\'','(',')','*','+',',','-','.','/',
'0','1','2' ,'3','4','5','6','7' ,'8','9',':',';','<','=','>','?',
'@','A','B','C','D','E','F','G','H','I','J','K','L', 'M','N','O',
'P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_',
'`','a','b','c','d','e','f','g','h','i','j','k','l', 'm','n','o',
'p','q','r','s','t','u','v','w','x','y','z','{','|' ,'}','~',0,
0217,		/*80 dagger*/
0341,		/*81 dbl dagger*/
(int)"\003...",	/*82 ellipsis*/
(int)"\201Y\b\"",	/*83 Ydieresis*/
(int)"\201L\b/",/*84 Lslash*/
(int)"\202OE",	/*85 OE*/
(int)"\201S",	/*86 Scaron*/
(int)"\201Z",	/*87 Zcaron*/
0203,		/*88 emdash*/
0203,		/*89 endash => emdash*/
0211,		/*8A fi*/
0212,		/*8B fl*/
(int)"\201l\b/",/*8C lslash*/
(int)"\202oe",	/*8D oe*/
(int)"\201s",	/*8E scaron*/
(int)"\201z",	/*8F zcaron*/
(int)"\201i",	/*90 dotlessi*/
0223,		/*91 grave*/
0222,		/*92 acute*/
(int)"\001^",	/*93 circumflex*/
(int)"\001~",	/*94 tilde*/
(int)"\001~",	/*95 macron*/
(int)"\001^",	/*96 breve*/
0,		/*97 dotaccent*/
(int)"\001\"",	/*98 dieresis*/
(int)"\001f",	/*99 florin*/
0216,		/*9A ring => degree*/
(int)"\001,",	/*9B cedilla*/
(int)"\001/",	/*9C fraction*/
(int)"\001\"",	/*9D hungarumlaut*/
0,		/*9E ogonek*/
0, 		/*9F caron*/
0227,		/*A0*/
0,		/*A1*/
0340,		/*A2 cent*/
(int)"\001L\b-",/*A3 pound*/
0,		/*A4*/
0,		/*A5*/
(int)"\001|",	/*A6*/
0220,		/*A7 section*/
(int)"\001\"",	/*A8 dieresis*/
0336,		/*A9 copyright*/
0,		/*AA*/
(int)"\002<<",	/*AB*/
0327,		/*AC not*/
0200,		/*AD hyphen*/
0335,		/*AE registered*/
(int)"\001~",	/*AF macron*/
