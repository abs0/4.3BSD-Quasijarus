h59468
s 00012/00010/00921
d D 1.13 87/12/11 00:52:58 donn 13 12
c utah rcsid 1.3 87/01/15 01:40:28: Fixed bug in outstruct() which caused it
c to refer to stab[-1] when dealing with unnamed structures.  Also some minor
c lint fixes.
e
s 00003/00000/00928
d D 1.12 86/03/27 22:30:53 mckusick 12 11
c improper stab of multidimensional array (from donn@utah-cs.arpa)
e
s 00001/00001/00927
d D 1.11 85/04/02 11:52:59 ralph 11 10
c use common header file for intermediate language defs.
e
s 00001/00000/00927
d D 1.10 83/10/22 12:56:29 sam 10 9
c terminate enum stab info
e
s 00003/00002/00924
d D 1.9 83/08/11 23:23:02 sam 9 8
c standardize sccs keyword lines
e
s 00005/00002/00921
d D 1.8 83/08/10 01:49:22 linton 8 7
c fixed problem with stab type for initialized static variables, 
c it used to generate LCSYM for all statics, now does LCSYM for uninitialized, 
c STSYM for initialized statics
e
s 00030/00001/00893
d D 1.7 83/07/15 16:33:24 linton 7 6
c symbol information for arrays with 0 dimension is no longer generated
e
s 00001/00001/00893
d D 1.6 83/04/26 22:50:00 linton 6 5
c changed STSYM to LCSYM so that the addresses for statics are correct
e
s 00001/00001/00893
d D 1.5 83/04/08 02:12:52 linton 5 4
c fixed bug with comparing array information in typelookup
e
s 00008/00002/00886
d D 1.4 83/02/02 00:57:15 linton 4 3
c fixed extern and f(f) problems
e
s 00001/00002/00887
d D 1.3 82/12/24 18:19:29 sam 3 2
c cleanup after mark (broke lint)
e
s 00270/00013/00619
d D 1.2 82/12/18 11:35:44 linton 2 1
c added new symbol stuff for dbx, split symbol table dumping 
c off into separate file ("stab.c")
e
s 00632/00000/00000
d D 1.1 82/12/15 13:23:59 linton 1 0
c date and time created 82/12/15 13:23:59 by linton
e
u
U
t
T
I 9
#ifndef lint
static char *sccsid ="%W% (Berkeley) %G%";
#endif
E 9
I 1
/*
 * Symbolic debugging info interface.
 *
 * Here we generate pseudo-ops that cause the assembler to put
 * symbolic debugging information into the object file.
 */
D 9

static char *sccsid ="%W% (Berkeley) %G%";
E 9

D 11
#include "mfile1"
E 11
I 11
#include "pass1.h"
E 11

#include <sys/types.h>
#include <a.out.h>
#include <stab.h>

#define private static
#define and &&
#define or ||
#define not !
#define div /
#define mod %
#define nil 0

#define bytes(bits) ((bits) / SZCHAR)
#define bsize(p) bytes(dimtab[p->sizoff])	/* size in bytes of a symbol */

#define NILINDEX -1
#define FORWARD -2

D 4
typedef enum { false, true } Boolean;
E 4
I 4
typedef int Boolean;
E 4

I 4
#define false 0
#define true 1

E 4
extern int ddebug;
extern int gdebug;
extern char *malloc();

int stabLCSYM;

/*
I 2
 * Flag for producing either sdb or dbx symbol information.
 */
D 3

Boolean oldway = false;
E 3
I 3
int oldway = false;
E 3

/*
E 2
 * Generate debugging info for a parameter.
 * The offset isn't known when it is first entered into the symbol table
 * since the types are read later.
 */

fixarg(p)
struct symtab *p;
{
D 2
    if (gdebug) {
E 2
I 2
    if (oldway) {
	old_fixarg(p);
    } else if (gdebug) {
E 2
	printf("\t.stabs\t\"%s:p", p->sname);
	gentype(p);
	printf("\",0x%x,0,%d,%d\n", N_PSYM, bsize(p), bytes(argoff));
    }
}

/*
I 7
 * Determine if the given symbol is a global array with dimension 0,
 * which only makes sense if it's dimension is to be given later.
 * We therefore currently do not generate symbol information for
 * such entries.
 */

#define isglobal(class) ( \
    class == EXTDEF or class == EXTERN or class == STATIC \
)

private Boolean zero_length_array(p)
register struct symtab *p;
{
    Boolean b;
    int t;

    if (not isglobal(p->sclass)) {
	b = false;
    } else {
	t = p->stype;
	if (ISFTN(t)) {
	    t = DECREF(t);
	}
	b = (Boolean) (ISARY(t) and dimtab[p->dimoff] == 0);
    }
    return b;
}

/*
E 7
 * Generate debugging info for a given symbol.
 */

outstab(sym)
struct symtab *sym;
{
    register struct symtab *p;
    char *classname;
D 13
    int offset;
E 13
    Boolean ignore;
    static Boolean firsttime = true;

D 2
    if (gdebug) {
E 2
I 2
    if (oldway) {
	old_outstab(sym);
D 7
    } else if (gdebug) {
E 7
I 7
    } else if (gdebug and not zero_length_array(sym)) {
E 7
E 2
	if (firsttime) {
	    firsttime = false;
	    inittypes();
	}
	ignore = false;
	p = sym;
D 13
	offset = bytes(p->offset);
E 13
	switch (p->sclass) {
	case REGISTER:
	    classname = "r";
D 13
	    offset = p->offset;
E 13
	    break;

	/*
	 * Locals are the default class.
	 */
	case AUTO:
	    classname = "";
	    break;

	case STATIC:
	    if (ISFTN(p->stype)) {
		ignore = true;
	    } else if (p->slevel <= 1) {
		classname = "S";
	    } else {
		classname = "V";
	    }
	    break;

	case EXTDEF:
	case EXTERN:
	    if (ISFTN(p->stype)) {
		ignore = true;
	    } else {
		classname = "G";
	    }
	    break;

	case TYPEDEF:
	    classname = "t";
	    break;

	case PARAM:
	case MOS:
	case MOU:
	case MOE:
	    ignore = true;
	    break;

	case ENAME:
	case UNAME:
	case STNAME:
D 13
	    entertype(p->stype, NILINDEX, FORWARD, dimtab[p->sizoff + 3]);
E 13
I 13
	    (void) entertype(p->stype, NILINDEX, FORWARD, dimtab[p->sizoff + 3]);
E 13
	    ignore = true;
	    break;

	default:
	    if ((p->sclass&FIELD) == 0) {
		printf("/* no info for %s (%d) */\n", p->sname, p->sclass);
	    }
	    ignore = true;
	    break;
	}
	if (not ignore) {
	    printf("\t.stabs\t\"%s:%s", p->sname, classname);
	    gentype(p);
	    geninfo(p);
	}
    }
}

/*
 * Since type names are lost in the travels and because C has
 * structural type equivalence we keep a table of type words that
 * we've already seen.  The first time we see a type, it is assigned
 * (inline) a number and future references just list that number.
 * Structures, unions, enums, and arrays must be handled carefully
 * since not all the necessary information is in the type word.
 */

typedef struct Typeid *Typeid;

struct Typeid {
    TWORD tword;
    int tarray;
    int tstruct;
    int tstrtag;
    int tnum;
    Typeid chain;
};

#define TABLESIZE 2003

private int tcount = 1;
private int t_int, t_char;
private Typeid typetable[TABLESIZE];

/*
 * Look for the given type word in the type table.
 */

private Typeid typelookup(type, arrindex, strindex, strtag)
TWORD type;
int arrindex;
int strindex;
int strtag;
{
    register TWORD tword;
    register int i1, i2;
    Typeid t;

    t = typetable[type mod TABLESIZE];
    while (t != nil) {
	if (t->tword == type and
	  strindex == t->tstruct and strtag == t->tstrtag) {
	    if (arrindex == NILINDEX) {
		break;
	    } else {
D 5
		tword = type >> TSHIFT;
E 5
I 5
		tword = type;
E 5
		i1 = arrindex;
		i2 = t->tarray;
		while (ISARY(tword) and dimtab[i1] == dimtab[i2]) {
		    ++i1;
		    ++i2;
		    tword >>= TSHIFT;
		}
		if (!ISARY(tword)) {
		    break;
		}
	    }
	}
	t = t->chain;
    }
    return t;
}

/*
 * Enter a type word and associated symtab indices into the type table.
 */

private int entertype(type, arrindex, strindex, strtag)
TWORD type;
int arrindex;
int strindex;
int strtag;
{
    register Typeid t;
    register int i;

    t = (Typeid) malloc(sizeof(struct Typeid));
    t->tword = type;
    t->tarray = arrindex;
    t->tstruct = strindex;
    t->tstrtag = strtag;
    t->tnum = tcount;
    ++tcount;
    i = type mod TABLESIZE;
    t->chain = typetable[i];
    typetable[i] = t;
    return t->tnum;
}

/*
 * Change the information associated with a type table entry.
 * Since I'm lazy this just creates a new entry with the number
 * as the old one.
 */

private reentertype(typeid, type, arrindex, strindex, strtag)
Typeid typeid;
TWORD type;
int arrindex;
int strindex;
int strtag;
{
    register Typeid t;
    register int i;

    t = (Typeid) malloc(sizeof(struct Typeid));
    t->tword = type;
    t->tarray = arrindex;
    t->tstruct = strindex;
    t->tstrtag = strtag;
    t->tnum = typeid->tnum;
    i = type mod TABLESIZE;
    t->chain = typetable[i];
    typetable[i] = t;
}

/*
 * Initialize type table with predefined types.
 */

#define builtintype(type) entertype(type, NILINDEX, NILINDEX, NILINDEX)

private inittypes()
{
    int t;

    t_int = builtintype(INT);
    t_char = builtintype(CHAR);
    maketype("int", t_int, t_int, 0x80000000L, 0x7fffffffL);
    maketype("char", t_char, t_char, 0L, 127L);
    maketype("long", builtintype(LONG), t_int, 0x80000000L, 0x7fffffffL);
    maketype("short", builtintype(SHORT), t_int, 0xffff8000L, 0x7fffL);
    maketype("unsigned char", builtintype(UCHAR), t_int, 0L, 255L);
    maketype("unsigned short", builtintype(USHORT), t_int, 0L, 0xffffL);
    maketype("unsigned long", builtintype(ULONG), t_int, 0L, 0xffffffffL);
    maketype("unsigned int", builtintype(UNSIGNED), t_int, 0L, 0xffffffffL);
    maketype("float", builtintype(FLOAT), t_int, 4L, 0L);
    maketype("double", builtintype(DOUBLE), t_int, 8L, 0L);
    t = builtintype(UNDEF);
    printf("\t.stabs\t\"void:t%d=%d", t, t);
D 13
    geninfo(nil);
E 13
I 13
    geninfo((struct symtab *)nil);
E 13
I 4
    t = builtintype(FARG);
    printf("\t.stabs\t\"???:t%d=%d", t, t_int);
D 13
    geninfo(nil);
E 13
I 13
    geninfo((struct symtab *)nil);
E 13
E 4
}

/*
 * Generate info for a new range type.
 */

private maketype(name, tnum, eqtnum, lower, upper)
char *name;
int tnum, eqtnum;
long lower, upper;
{
    printf("\t.stabs\t\"%s:t%d=r%d;%d;%d;", name, tnum, eqtnum, lower, upper);
D 13
    geninfo(nil);
E 13
I 13
    geninfo((struct symtab *)nil);
E 13
}

/*
 * Generate debugging information for the given type of the given symbol.
 */

private gentype(sym)
struct symtab *sym;
{
    register struct symtab *p;
    register TWORD t;
    register TWORD basictype;
    register Typeid typeid;
    int i, arrindex, strindex, strtag;

    p = sym;
    t = p->stype;
    if (ISFTN(t)) {
	t = DECREF(t);
    }
    basictype = BTYPE(t);
    if (ISARY(t)) {
	arrindex = p->dimoff;
    } else {
	arrindex = NILINDEX;
    }
    if (basictype == STRTY or basictype == UNIONTY or basictype == ENUMTY) {
	strindex = dimtab[p->sizoff + 1];
	if (strindex == -1) {
	    strindex = FORWARD;
	    strtag = dimtab[p->sizoff + 3];
	} else {
	    strtag = NILINDEX;
	}
    } else {
	strindex = NILINDEX;
	strtag = NILINDEX;
    }
    i = arrindex;
    typeid = typelookup(t, arrindex, strindex, strtag);
    while (t != basictype and typeid == nil) {
	printf("%d=", entertype(t, i, strindex, strtag));
	switch (t&TMASK) {
	case PTR:
	    printf("*");
	    break;

	case FTN:
	    printf("f");
	    break;

	case ARY:
	    printf("ar%d;0;%d;", t_int, dimtab[i++] - 1);
	    break;
	}
	t = DECREF(t);
I 12
	if (i == NILINDEX && ISARY(t)) {
	    i = p->dimoff;
	}
E 12
	if (t == basictype) {
	    typeid = typelookup(t, NILINDEX, strindex, strtag);
	} else {
	    typeid = typelookup(t, i, strindex, strtag);
	}
    }
    if (typeid == nil) {
	if (strindex == FORWARD) {
	    typeid = typelookup(t, NILINDEX, FORWARD, dimtab[p->sizoff + 3]);
	    if (typeid == nil) {
		cerror("unbelievable forward reference");
	    }
	    printf("%d", typeid->tnum);
	} else {
	    genstruct(t, NILINDEX, strindex, p->sname, bsize(p));
	}
    } else {
	printf("%d", typeid->tnum);
    }
}

/*
 * Generate type information for structures, unions, and enumerations.
 */

private genstruct(t, structid, index, name, size)
TWORD t;
int structid;
int index;
char *name;
int size;
{
    register int i;
    register struct symtab *field;
    int id;

    if (structid == NILINDEX) {
	id = entertype(t, NILINDEX, index, NILINDEX);
    } else {
	id = structid;
    }
    switch (t) {
    case STRTY:
    case UNIONTY:
	printf("%d=%c%d", id, t == STRTY ? 's' : 'u', size);
	i = index;
	while (dimtab[i] != -1) {
	    field = &stab[dimtab[i]];
	    printf("%s:", field->sname);
	    gentype(field);
	    if (field->sclass > FIELD) {
		printf(",%d,%d;", field->offset, field->sclass - FIELD);
	    } else {
		printf(",%d,%d;", field->offset,
		    tsize(field->stype, field->dimoff, field->sizoff));
	    }
	    ++i;
	}
	putchar(';');
	break;

    case ENUMTY:
	printf("%d=e", id);
	i = index;
	while (dimtab[i] != -1) {
	    field = &stab[dimtab[i]];
	    printf("%s:%d,", field->sname, field->offset);
	    i++;
	}
I 10
	putchar(';');
E 10
	break;

    default:
	cerror("couldn't find basic type %d for %s\n", t, name);
	break;
    }
}

/*
 * Generate offset and size info.
 */

private geninfo(p)
register struct symtab *p;
{
I 8
    int stabtype;

E 8
    if (p == nil) {
	printf("\",0x%x,0,0,0\n", N_LSYM);
    } else {
	switch (p->sclass) {
	    case EXTERN:
	    case EXTDEF:
		if (ISFTN(p->stype)) {
		    printf("\",0x%x,0,%d,_%s\n", N_FUN, bsize(p), p->sname);
		} else {
D 4
		    printf("\",0x%x,0,%d,_%s\n", N_GSYM, bsize(p), p->sname);
E 4
I 4
		    printf("\",0x%x,0,%d,0\n", N_GSYM, bsize(p));
E 4
		}
		break;

	    case STATIC:
I 8
		stabtype = stabLCSYM ? N_LCSYM : N_STSYM;
E 8
		if (ISFTN(p->stype)) {
		    printf("\",0x%x,0,%d,_%s\n", N_FUN, bsize(p), p->sname);
		} else if (p->slevel > 1) {
D 6
		    printf("\",0x%x,0,%d,L%d\n", N_STSYM, bsize(p), p->offset);
E 6
I 6
D 8
		    printf("\",0x%x,0,%d,L%d\n", N_LCSYM, bsize(p), p->offset);
E 8
I 8
		    printf("\",0x%x,0,%d,L%d\n", stabtype, bsize(p), p->offset);
E 8
E 6
		} else {
D 8
		    printf("\",0x%x,0,%d,_%s\n", N_LCSYM, bsize(p), p->sname);
E 8
I 8
		    printf("\",0x%x,0,%d,_%s\n", stabtype, bsize(p), p->sname);
E 8
		}
		break;

	    case REGISTER:
		printf("\",0x%x,0,%d,%d\n", N_RSYM, bsize(p), p->offset);
		break;

	    case PARAM:
		printf("\",0x%x,0,%d,%d\n", N_PSYM, bsize(p), bytes(argoff));
		break;

	    default:
		printf("\",0x%x,0,%d,%d\n", N_LSYM, bsize(p), bytes(p->offset));
		break;
	}
    }
}

/*
 * Generate information for a newly-defined structure.
 */

I 13
/*ARGSUSED*/
E 13
outstruct(szindex, paramindex)
int szindex, paramindex;
{
    register Typeid typeid;
    register struct symtab *p;
    register int i, t, strindex;

D 2
    if (gdebug) {
E 2
I 2
    if (oldway) {
	/* do nothing */;
    } else if (gdebug) {
E 2
D 13
	i = dimtab[szindex + 3];
	p = &stab[i];
	if (p->sname != nil) {
E 13
I 13
	if ((i = dimtab[szindex + 3]) >= 0 && (p = &stab[i])->sname != nil) {
E 13
	    strindex = dimtab[p->sizoff + 1];
	    typeid = typelookup(p->stype, NILINDEX, FORWARD, i);
	    if (typeid == nil) {
		t = 0;
	    } else {
		t = typeid->tnum;
		reentertype(typeid, p->stype, NILINDEX, strindex, NILINDEX);
	    }
	    printf("\t.stabs\t\"%s:T", p->sname);
	    genstruct(p->stype, t, strindex, p->sname, bsize(p));
	    geninfo(p);
	}
    }
}

pstab(name, type)
char *name;
int type;
{
I 13
#ifndef ASSTRINGS
E 13
    register int i;
    register char c;
I 13
#endif
E 13
D 2
    if (!gdebug) return;
E 2
I 2

    if (!gdebug) {
	return;
    } else if (oldway) {
	old_pstab(name, type);
	return;
    }
E 2
    /* locctr(PROG);  /* .stabs must appear in .text for c2 */
#ifdef ASSTRINGS
    if ( name[0] == '\0')
	printf("\t.stabn\t");
    else
#ifndef FLEXNAMES
	printf("\t.stabs\t\"%.8s\",", name);
#else
	printf("\t.stabs\t\"%s\",", name);
#endif
#else
    printf("    .stab   ");
    for(i=0; i<8; i++) 
	if (c = name[i]) printf("'%c,", c);
	else printf("0,");
#endif
    printf("0%o,", type);
}

#ifdef STABDOT
pstabdot(type, value)
int type;
int value;
{
D 2
    if ( ! gdebug) return;
E 2
I 2
    if ( ! gdebug) {
	return;
    } else if (oldway) {
	old_pstabdot(type, value);
	return;
    }
E 2
    /* locctr(PROG);  /* .stabs must appear in .text for c2 */
    printf("\t.stabd\t");
    printf("0%o,0,0%o\n",type, value);
}
#endif

I 13
#ifndef STABDOT
E 13
extern char NULLNAME[8];
I 13
#endif
E 13
extern int  labelno;
extern int  fdefflag;

psline()
{
    static int lastlineno;
    register char *cp, *cq;
    register int i;
    
D 2
    if (!gdebug) return;
E 2
I 2
    if (!gdebug) {
	return;
    } else if (oldway) {
	old_psline();
	return;
    }
E 2

    cq = ititle;
    cp = ftitle;

    while ( *cq ) if ( *cp++ != *cq++ ) goto neq;
    if ( *cp == '\0' ) goto eq;
    
neq:    for (i=0; i<100; i++)
	ititle[i] = '\0';
    cp = ftitle;
    cq = ititle;
    while ( *cp )  
	*cq++ = *cp++;
    *cq = '\0';
    *--cq = '\0';
#ifndef FLEXNAMES
    for ( cp = ititle+1; *(cp-1); cp += 8 ) {
	pstab(cp, N_SOL);
	if (gdebug) printf("0,0,LL%d\n", labelno);
    }
#else
    pstab(ititle+1, N_SOL);
    if (gdebug) printf("0,0,LL%d\n", labelno);
#endif
    *cq = '"';
    printf("LL%d:\n", labelno++);

eq: if (lineno == lastlineno) return;
    lastlineno = lineno;

    if (fdefflag) {
#ifdef STABDOT
	pstabdot(N_SLINE, lineno);
#else
	pstab(NULLNAME, N_SLINE);
	printf("0,%d,LL%d\n", lineno, labelno);
	printf("LL%d:\n", labelno++);
#endif
    }
}
    
plcstab(level)
int level;
{
D 2
    if (!gdebug) return;
E 2
I 2
    if (!gdebug) {
	return;
    } else if (oldway) {
	old_plcstab(level);
	return;
    }
E 2
#ifdef STABDOT
    pstabdot(N_LBRAC, level);
#else
    pstab(NULLNAME, N_LBRAC);
    printf("0,%d,LL%d\n", level, labelno);
    printf("LL%d:\n", labelno++);
#endif
}
    
prcstab(level)
int level;
{
D 2
    if (!gdebug) return;
E 2
I 2
    if (!gdebug) {
	return;
    } else if (oldway) {
	old_prcstab(level);
	return;
    }
E 2
#ifdef STABDOT
    pstabdot(N_RBRAC, level);
#else
    pstab(NULLNAME, N_RBRAC);
    printf("0,%d,LL%d\n", level, labelno);
    printf("LL%d:\n", labelno++);
#endif
}
    
pfstab(sname) 
char *sname;
{
    register struct symtab *p;

    if (gdebug) {
D 2
	p = &stab[lookup(sname, 0)];
	printf("\t.stabs\t\"%s:", p->sname);
	putchar((p->sclass == STATIC) ? 'f' : 'F');
	gentype(p);
	geninfo(p);
E 2
I 2
	if (oldway) {
	    old_pfstab(sname);
	} else {
	    p = &stab[lookup(sname, 0)];
	    printf("\t.stabs\t\"%s:", p->sname);
	    putchar((p->sclass == STATIC) ? 'f' : 'F');
	    gentype(p);
	    geninfo(p);
	}
E 2
    }
I 2
}

/*
 * Old way of doing things.
 */

private old_fixarg(p)
struct symtab *p; {
	if (gdebug) {
		old_pstab(p->sname, N_PSYM);
		if (gdebug) printf("0,%d,%d\n", p->stype, argoff/SZCHAR);
		old_poffs(p);
	}
}

private old_outstab(p)
struct symtab *p; {
	register TWORD ptype;
	register char *pname;
	register char pclass;
	register int poffset;

	if (!gdebug) return;

	ptype = p->stype;
	pname = p->sname;
	pclass = p->sclass;
	poffset = p->offset;

	if (ISFTN(ptype)) {
		return;
	}
	
	switch (pclass) {
	
	case AUTO:
		old_pstab(pname, N_LSYM);
		printf("0,%d,%d\n", ptype, (-poffset)/SZCHAR);
		old_poffs(p);
		return;
	
	case EXTDEF:
	case EXTERN:
		old_pstab(pname, N_GSYM);
		printf("0,%d,0\n", ptype);
		old_poffs(p);
		return;
			
	case STATIC:
#ifdef LCOMM
		/* stabLCSYM is 1 during nidcl so we can get stab type right */
		old_pstab(pname, stabLCSYM ? N_LCSYM : N_STSYM);
#else
		old_pstab(pname, N_STSYM);
#endif
		if (p->slevel > 1) {
			printf("0,%d,L%d\n", ptype, poffset);
		} else {
			printf("0,%d,%s\n", ptype, exname(pname));
		}
		old_poffs(p);
		return;
	
	case REGISTER:
		old_pstab(pname, N_RSYM);
		printf("0,%d,%d\n", ptype, poffset);
		old_poffs(p);
		return;
	
	case MOS:
	case MOU:
		old_pstab(pname, N_SSYM);
		printf("0,%d,%d\n", ptype, poffset/SZCHAR);
		old_poffs(p);
		return;
	
	case PARAM:
		/* parameter stab entries are processed in dclargs() */
		return;
	
	default:
#ifndef FLEXNAMES
		if (ddebug) printf("	No .stab for %.8s\n", pname);
#else
		if (ddebug) printf("	No .stab for %s\n", pname);
#endif
		
	}
}

private old_pstab(name, type)
char *name;
int type; {
I 13
#ifndef ASSTRINGS
E 13
	register int i;
	register char c;
I 13
#endif
E 13
	if (!gdebug) return;
	/* locctr(PROG);  /* .stabs must appear in .text for c2 */
#ifdef ASSTRINGS
	if ( name[0] == '\0')
		printf("\t.stabn\t");
	else
#ifndef FLEXNAMES
		printf("\t.stabs\t\"%.8s\", ", name);
#else
		printf("\t.stabs\t\"%s\", ", name);
#endif
#else
	printf("	.stab	");
	for(i=0; i<8; i++) 
		if (c = name[i]) printf("'%c,", c);
		else printf("0,");
#endif
	printf("0%o,", type);
}

#ifdef STABDOT
private old_pstabdot(type, value)
	int	type;
	int	value;
{
	if ( ! gdebug) return;
	/* locctr(PROG);  /* .stabs must appear in .text for c2 */
	printf("\t.stabd\t");
	printf("0%o,0,0%o\n",type, value);
}
#endif

private old_poffs(p)
register struct symtab *p; {
	int s;
	if (!gdebug) return;
	if ((s = dimtab[p->sizoff]/SZCHAR) > 1) {
		old_pstab(p->sname, N_LENG);
		printf("1,0,%d\n", s);
	}
}

private old_psline() {
	static int lastlineno;
	register char *cp, *cq;
	register int i;
	
	if (!gdebug) return;

	cq = ititle;
	cp = ftitle;

	while ( *cq ) if ( *cp++ != *cq++ ) goto neq;
	if ( *cp == '\0' ) goto eq;
	
neq:	for (i=0; i<100; i++)
		ititle[i] = '\0';
	cp = ftitle;
	cq = ititle;
	while ( *cp )  
		*cq++ = *cp++;
	*cq = '\0';
	*--cq = '\0';
#ifndef FLEXNAMES
	for ( cp = ititle+1; *(cp-1); cp += 8 ) {
		old_pstab(cp, N_SOL);
		if (gdebug) printf("0,0,LL%d\n", labelno);
		}
#else
	old_pstab(ititle+1, N_SOL);
	if (gdebug) printf("0,0,LL%d\n", labelno);
#endif
	*cq = '"';
	printf("LL%d:\n", labelno++);

eq:	if (lineno == lastlineno) return;
	lastlineno = lineno;

	if (fdefflag) {
#ifdef STABDOT
		old_pstabdot(N_SLINE, lineno);
#else
		old_pstab(NULLNAME, N_SLINE);
		printf("0,%d,LL%d\n", lineno, labelno);
		printf("LL%d:\n", labelno++);
#endif
		}
	}
	
private old_plcstab(level) {
	if (!gdebug) return;
#ifdef STABDOT
	old_pstabdot(N_LBRAC, level);
#else
	old_pstab(NULLNAME, N_LBRAC);
	printf("0,%d,LL%d\n", level, labelno);
	printf("LL%d:\n", labelno++);
#endif
	}
	
private old_prcstab(level) {
	if (!gdebug) return;
#ifdef STABDOT
	pstabdot(N_RBRAC, level);
#else
	pstab(NULLNAME, N_RBRAC);
	printf("0,%d,LL%d\n", level, labelno);
	printf("LL%d:\n", labelno++);
#endif
	}
	
private old_pfstab(sname) 
char *sname; {
	if (!gdebug) return;
	pstab(sname, N_FUN);
#ifndef FLEXNAMES
	printf("0,%d,_%.7s\n", lineno, sname);
#else
	printf("0,%d,_%s\n", lineno, sname);
#endif
E 2
}
E 1
