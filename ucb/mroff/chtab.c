#ifndef lint
static char sccsid[] = "@(#)chtab.c	5.18 (Berkeley) 2012/07/16";
#endif lint

#define BYTE 8
#define PAIR(A,B) (A|(B<<BYTE))
/*
character name table
*/


int chtab [] = {
/* European letters (mostly ISO) */
PAIR('A','`'),	0xC0,
PAIR('A','\''),	0xC1,
PAIR('A','^'),	0xC2,
PAIR('A','~'),	0xC3,
PAIR('A','"'),	0xC4,
PAIR('A','*'),	0xC5,
PAIR('A','E'),	0xC6,
PAIR('C',','),	0xC7,
PAIR('D','-'),	0xD0,
PAIR('E','`'),	0xC8,
PAIR('E','\''),	0xC9,
PAIR('E','^'),	0xCA,
PAIR('E','"'),	0xCB,
PAIR('I','`'),	0xCC,
PAIR('I','\''),	0xCD,
PAIR('I','^'),	0xCE,
PAIR('I','"'),	0xCF,
PAIR('L','/'),	0x84,
PAIR('N','~'),	0xD1,
PAIR('O','`'),	0xD2,
PAIR('O','\''),	0xD3,
PAIR('O','^'),	0xD4,
PAIR('O','~'),	0xD5,
PAIR('O','"'),	0xD6,
PAIR('O','/'),	0xD8,
PAIR('O','E'),	0x85,
PAIR('S','v'),	0x86,
PAIR('T','H'),	0xDE,
PAIR('T','h'),	0xDE,
PAIR('U','`'),	0xD9,
PAIR('U','\''),	0xDA,
PAIR('U','^'),	0xDB,
PAIR('U','"'),	0xDC,
PAIR('Y','\''),	0xDD,
PAIR('Y','"'),	0x83,
PAIR('Z','v'),	0x87,
PAIR('a','`'),	0xE0,
PAIR('a','\''),	0xE1,
PAIR('a','^'),	0xE2,
PAIR('a','~'),	0xE3,
PAIR('a','"'),	0xE4,
PAIR('a','*'),	0xE5,
PAIR('a','e'),	0xE6,
PAIR('c',','),	0xE7,
PAIR('d','-'),	0xF0,
PAIR('e','`'),	0xE8,
PAIR('e','\''),	0xE9,
PAIR('e','^'),	0xEA,
PAIR('e','"'),	0xEB,
PAIR('i','`'),	0xEC,
PAIR('i','\''),	0xED,
PAIR('i','^'),	0xEE,
PAIR('i','"'),	0xEF,
PAIR('l','/'),	0x8C,
PAIR('n','~'),	0xF1,
PAIR('o','`'),	0xF2,
PAIR('o','\''),	0xF3,
PAIR('o','^'),	0xF4,
PAIR('o','~'),	0xF5,
PAIR('o','"'),	0xF6,
PAIR('o','/'),	0xF8,
PAIR('o','e'),	0x8D,
PAIR('s','v'),	0x8E,
PAIR('t','h'),	0xFE,
PAIR('u','`'),	0xF9,
PAIR('u','\''),	0xFA,
PAIR('u','^'),	0xFB,
PAIR('u','"'),	0xFC,
PAIR('y','\''),	0xFD,
PAIR('y','"'),	0xFF,
PAIR('z','v'),	0x8F,
PAIR('s','s'),	0xDF,
/* ISO Latin-1 characters */
PAIR('!','!'), 0xA1,	/*inverted !*/
PAIR('I','!'), 0xA1,	/*equiv from University of Rochester*/
PAIR('c','t'), 0242,	/*cent sign*/
PAIR('p','o'), 0243,	/*pound sterling*/
PAIR('p','s'), 0243,	/*ditto*/
PAIR('$','J'), 0245,	/*Japanese Yen*/
PAIR('y','i'), 0245,	/*ditto*/
PAIR('s','c'), 0247,	/*section*/
PAIR('h','y'), 0xAD,	/*hyphen*/
PAIR('d','e'), 0xB0,	/*degree*/
PAIR('p','p'), 0266,	/*paragraph symbol*/
PAIR('1','4'), 0274,	/*1/4*/
PAIR('1','2'), 0275,	/*1/2*/
PAIR('3','4'), 0276,	/*3/4*/
PAIR('d','<'), 0253,	/*double left guillemet*/
PAIR('d','>'), 0273,	/*double right guillemet*/
PAIR('?','?'), 0xBF,	/*inverted ?*/
PAIR('I','?'), 0xBF,	/*equiv from University of Rochester*/
PAIR('c','o'), 0251,	/*copyright*/
PAIR('r','g'), 0256,	/*registered*/
/* other base font chars */
PAIR('b','u'), 0007,	/*bullet*/
PAIR('e','m'), 0x88,	/*emdash*/
PAIR('e','n'), 0x89,	/*endash*/
PAIR('f','i'), 0x8A,	/*fi*/
PAIR('f','l'), 0x8B,	/*fl*/
PAIR('d','g'), 0200,	/*dagger*/
PAIR('d','d'), 0201,	/*dbl dagger*/
PAIR('t','m'), 0006,	/*trademark*/
PAIR('a','a'), 0222,	/*acute accent*/
PAIR('g','a'), 0221,	/*grave accent*/
PAIR('l','q'), 0x16,	/*left double quote*/
PAIR('r','q'), 0x17,	/*right double quote*/
PAIR('n','\''),0x19,	/*neutral single quote*/
PAIR('p','m'), 0x14,	/*permille*/
PAIR('u','i'), 0x90,	/*undotted i*/
/* Symbol characters */
PAIR('m','i'), 0455,	/*equation minus*/
PAIR('*','a'), 0541,	/*alpha*/
PAIR('*','b'), 0542,	/*beta*/
PAIR('*','g'), 0547,	/*gamma*/
PAIR('*','d'), 0544,	/*delta*/
PAIR('*','e'), 0545,	/*epsilon*/
PAIR('*','z'), 0572,	/*zeta*/
PAIR('*','y'), 0550,	/*eta*/
PAIR('*','h'), 0561,	/*theta*/
PAIR('*','i'), 0551,	/*iota*/
PAIR('*','k'), 0553,	/*kappa*/
PAIR('*','l'), 0554,	/*lambda*/
PAIR('*','m'), 0555,	/*mu*/
PAIR('*','n'), 0556,	/*nu*/
PAIR('*','c'), 0570,	/*xi*/
PAIR('*','o'), 0557,	/*omicron*/
PAIR('*','p'), 0560,	/*pi*/
PAIR('*','r'), 0562,	/*rho*/
PAIR('*','s'), 0563,	/*sigma*/
PAIR('*','t'), 0564,	/*tau*/
PAIR('*','u'), 0565,	/*upsilon*/
PAIR('*','f'), 0546,	/*phi*/
PAIR('*','x'), 0543,	/*chi*/
PAIR('*','q'), 0571,	/*psi*/
PAIR('*','w'), 0567,	/*omega*/
PAIR('*','A'), 0501,	/*Alpha*/
PAIR('*','B'), 0502,	/*Beta*/
PAIR('*','G'), 0507,	/*Gamma*/
PAIR('*','D'), 0504,	/*Delta*/
PAIR('*','E'), 0505,	/*Epsilon*/
PAIR('*','Z'), 0532,	/*Zeta*/
PAIR('*','Y'), 0510,	/*Eta*/
PAIR('*','H'), 0521,	/*Theta*/
PAIR('*','I'), 0511,	/*Iota*/
PAIR('*','K'), 0513,	/*Kappa*/
PAIR('*','L'), 0514,	/*Lambda*/
PAIR('*','M'), 0515,	/*Mu*/
PAIR('*','N'), 0516,	/*Nu*/
PAIR('*','C'), 0530,	/*Xi*/
PAIR('*','O'), 0517,	/*Omicron*/
PAIR('*','P'), 0520,	/*Pi*/
PAIR('*','R'), 0522,	/*Rho*/
PAIR('*','S'), 0523,	/*Sigma*/
PAIR('*','T'), 0524,	/*Tau*/
PAIR('*','U'), 0641,	/*Upsilon*/
PAIR('*','F'), 0506,	/*Phi*/
PAIR('*','X'), 0503,	/*Chi*/
PAIR('*','Q'), 0531,	/*Psi*/
PAIR('*','W'), 0527,	/*Omega*/
PAIR('s','r'), 0726,	/*square root*/
PAIR('s','x'), 0540,	/*square root extension*/
PAIR('t','s'), 0526,	/*terminal sigma*/
PAIR('>','='), 0663,	/*>=*/
PAIR('<','='), 0643,	/*<=*/
PAIR('=','='), 0672,	/*identically equal*/
PAIR('~','='), 0673,	/*approx =*/
PAIR('~','~'), 0673,	/*approx = as drawn in Symbol*/
PAIR('a','p'), 0576,	/*approximates (similar)*/
PAIR('!','='), 0671,	/*not equal*/
PAIR('-','>'), 0656,	/*right arrow*/
PAIR('<','-'), 0654,	/*left arrow*/
PAIR('u','a'), 0655,	/*up arrow*/
PAIR('d','a'), 0657,	/*down arrow*/
PAIR('e','q'), 0475,	/*equation equal*/
PAIR('m','u'), 0664,	/*multiply*/
PAIR('d','i'), 0670,	/*divide*/
PAIR('+','-'), 0661,	/*plus-minus*/
PAIR('c','u'), 0710,	/*cup (union)*/
PAIR('c','a'), 0707,	/*cap (intersection)*/
PAIR('s','b'), 0714,	/*subset of*/
PAIR('s','p'), 0711,	/*superset of*/
PAIR('i','b'), 0715,	/*improper subset*/
PAIR('i','p'), 0712,	/*  " superset*/
PAIR('i','f'), 0645,	/*infinity*/
PAIR('p','d'), 0666,	/*partial derivative*/
PAIR('g','r'), 0721,	/*gradient*/
PAIR('n','o'), 0730,	/*not*/
PAIR('i','s'), 0762,	/*integral sign*/
PAIR('p','t'), 0665,	/*proportional to*/
PAIR('e','s'), 0706,	/*empty set*/
PAIR('m','o'), 0716,	/*member of*/
PAIR('p','l'), 0453,	/*equation plus*/
PAIR('*','*'), 0452,	/*math * */
PAIR('M','i'), 0642,	/*minute*/
PAIR('S','e'), 0662,	/*second*/
PAIR('l','t'), 0754,	/*left top (of big curly)*/
PAIR('l','b'), 0756,	/*left bottom*/
PAIR('r','t'), 0774,	/*right top*/
PAIR('r','b'), 0776,	/*right bot*/
PAIR('l','k'), 0755,	/*left center of big curly bracket*/
PAIR('r','k'), 0775,	/*right center of big curly bracket*/
PAIR('b','x'), 0757,	/*big curly bracket extension*/
PAIR('l','f'), 0753,	/*left floor (left bot of big sq bract)*/
PAIR('r','f'), 0773,	/*right floor (rb of ")*/
PAIR('l','c'), 0751,	/*left ceiling (lt of ")*/
PAIR('r','c'), 0771,	/*right ceiling (rt of ")*/
PAIR('l','x'), 0752,	/*left extension*/
PAIR('r','x'), 0772,	/*right extension*/
/* Symbol characters (community additions) */
PAIR('!','m'), 0717,	/*not member of*/
PAIR('n','m'), 0717,	/*ditto*/
PAIR('!','s'), 0713,	/*not subset*/
PAIR('<',':'), 0x1DC,	/*left double arrow*/
PAIR(':','>'), 0x1DE,	/*right double arrow*/
PAIR('<','>'), 0653,	/*single arrow both ways*/
PAIR('a','+'), 0705,	/*abstract plus*/
PAIR('a','x'), 0704,	/*abstract multiply*/
PAIR('a','g'), 0720,	/*angle*/
PAIR('a','l'), 0700,	/*aleph*/
PAIR('b','t'), 0536,	/*bottom (perpendicular)*/
PAIR('c','r'), 0677,	/*carriage return*/
PAIR('d','m'), 0740,	/*diamond (lozenge)*/
PAIR('f','a'), 0442,	/*for all*/
PAIR('l','a'), 0731,	/*logical and*/
PAIR('l','o'), 0732,	/*logical or*/
PAIR('m','.'), 0727,	/*math dot (centered dot)*/
PAIR('t','e'), 0444,	/*there exists*/
PAIR('t','f'), 0534,	/*therefore*/
/* line drawing characters */
PAIR('r','u'), 0x112,	/*baseline rule*/
PAIR('u','l'), 0x10F,	/*underrule*/
PAIR('r','n'), 0x110,	/*overrule*/
PAIR('b','r'), 0x111,	/*box vert rule*/
/* troff compatibility (approximations) */
PAIR('f','m'), 0642,	/*foot mark => minute*/
PAIR('b','v'), 0757,	/*bold vertical => big curly bracket extension*/
PAIR('o','r'), 0574,	/*Bell's idea of 'or' => | on Symbol*/
PAIR('s','l'), '/',	/*slash (the standard one matches backslash)*/
/* map hands to double arrows unless overridden by ZD & SS */
PAIR('l','h'), 0x1DC,	/*left hand => left double arrow*/
PAIR('r','h'), 0x1DE,	/*right hand => right double arrow*/
/*
 * The following characters are available only with the special
 * troff-emulating fonts.  They are NOT available with standard
 * Adobe fonts.  However, there is no detriment to having them always
 * included in this compiled-in table: if the corresponding character
 * doesn't appear in the loaded font width table, troff won't try to
 * print it, and the effect will be exactly the same as if it wasn't
 * found in the present table: the \(xx escape will be ignored.
 */
PAIR('f','f'), 0x1C,	/*ff ligature*/
PAIR('F','i'), 0x1D,	/*ffi ligature*/
PAIR('F','l'), 0x1E,	/*ffl ligature*/
PAIR('s','q'), 0x1F,	/*square*/
PAIR('b','s'), 0760,	/*Bell System logo*/
0,0};
