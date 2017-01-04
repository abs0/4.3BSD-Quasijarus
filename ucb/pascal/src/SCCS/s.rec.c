h57326
s 00001/00001/00444
d D 5.2 87/04/06 12:08:22 bostic 11 10
c printf format/argument mismatch
e
s 00007/00003/00438
d D 5.1 85/06/05 14:47:59 dist 10 9
c Add copyright
e
s 00000/00000/00441
d D 2.1 84/02/08 20:45:30 aoki 9 8
c synchronize to version 2
e
s 00000/00000/00441
d D 1.7 83/09/19 07:00:24 thien 8 7
c Restoring to unlinted version
e
s 00045/00040/00396
d D 1.6 83/08/19 05:01:28 thien 7 6
c The changes were made to allow successful linting
e
s 00223/00054/00213
d D 1.5 82/10/19 20:42:10 peter 6 5
c c style alignment of variants within records.
e
s 00001/00001/00266
d D 1.4 81/04/01 11:54:14 peter 5 3
c keep snarks out of error messages by checking for blown type.
e
s 00003/00000/00267
d R 1.4 81/04/01 10:42:26 peter 4 3
c check for tag field types being nil to prevent SNARK in error.
e
s 00004/00004/00263
d D 1.3 81/03/08 19:27:26 mckusic 3 2
c merge in onyx changes
e
s 00001/00002/00266
d D 1.2 80/09/22 16:53:25 peter 2 1
c since fields are aligned, they need not be on even boundaries
e
s 00268/00000/00000
d D 1.1 80/08/27 19:56:15 peter 1 0
c date and time created 80/08/27 19:56:15 by peter
e
u
U
t
T
I 1
D 10
/* Copyright (c) 1979 Regents of the University of California */
E 10
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 10

I 7
#ifndef lint
E 7
D 3
static	char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
D 10
static char sccsid[] = "%Z%%M% %I% %G%";
I 7
#endif
E 10
I 10
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 10
E 7
E 3

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
I 6
#include "align.h"
I 7
#include "tree_ty.h"
E 7
E 6

I 6
    /*
     *	set this to TRUE with adb to turn on record alignment/offset debugging.
     */
bool	debug_records = FALSE;
#define	DEBUG_RECORDS(x)	if (debug_records) { x ; } else

E 6
/*
 * Build a record namelist entry.
 * Some of the processing here is somewhat involved.
 * The basic structure we are building is as follows.
 *
D 6
 * Each record has a main RECORD entry, with an attached
 * chain of fields as ->chain;  these include all the fields in all
 * the variants of this record.
E 6
I 6
 * Each record has a main RECORD entry,
 * with an attached chain of fields as ->chain;
D 7
 * these include all the fields in all the variants of this record.
E 7
I 7
 * these enclude all the fields in all the variants of this record.
E 7
 * Fields are cons'ed to the front of the ->chain list as they are discovered.
 * This is for reclook(), but not for sizing and aligning offsets.
E 6
 *
I 6
 * If there are variants to the record, NL_TAG points to the field which
 * is the tag.  If its name is NIL, the tag field is unnamed, and is not
 * allocated any space in the record.
E 6
 * Attached to NL_VARNT is a chain of VARNT structures
 * describing each of the variants.  These are further linked
 * through ->chain.  Each VARNT has, in ->range[0] the value of
 * the associated constant, and each points at a RECORD describing
 * the subrecord through NL_VTOREC.  These pointers are not unique,
 * more than one VARNT may reference the same RECORD.
 *
D 6
 * The involved processing here is in computing the NL_OFFS entry
 * by maxing over the variants.  This works as follows.
 *
 * Each RECORD has two size counters.  NL_OFFS is the maximum size
 * so far of any variant of this record;  NL_FLDSZ gives the size
 * of just the FIELDs to this point as a base for further variants.
 *
 * As we process each variant record, we start its size with the
 * NL_FLDSZ we have so far.  After processing it, if its NL_OFFS
 * is the largest so far, we update the NL_OFFS of this subrecord.
 * This will eventually propagate back and update the NL_OFFS of the
 * entire record.
E 6
I 6
 * On the first pass, we traverse the parse tree and construct the namelist
 * entries.  This pass fills in the alignment of each record (including
 * subrecords (the alignment of a record is the maximum of the alignments
 * of any of its fields).
 * A second pass over the namelist entries fills in the offsets of each field
 * based on the alignments required.  This second pass uses the NL_FIELDLIST
 * chaining of fields, and the NL_TAG pointer and the NL_VARNT pointer to get
 * to fields in the order in which they were declared.
 * This second pass can not be folded into the first pass,
 * as the starting offset of all variants is the same,
 * so we must see all the variants (and especially must know their alignments)
 * before assigning offsets.  With the alignments calculated (by the first
 * pass) this can be done in one top down pass, max'ing over the alignment of
 * variants before assigning offsets to any of them.
E 6
 */

/*
 * P0 points to the outermost RECORD for name searches.
 */
struct	nl *P0;

I 6
struct nl *
E 6
tyrec(r, off)
D 7
	int *r, off;
E 7
I 7
	struct tnode *r;
	int	      off;
E 7
{
I 6
	struct nl	*recp;
E 6

D 6
	    return tyrec1(r, off, 1);
E 6
I 6
	DEBUG_RECORDS(fprintf(stderr,"[tyrec] off=%d\n", off));
	    /*
	     *	build namelist structure for the outermost record type.
	     *	then calculate offsets (starting at 0) of the fields
	     *	in this record and its variant subrecords.
	     */
	recp = tyrec1(r, TRUE);
D 7
	rec_offsets(recp, 0);
E 7
I 7
	rec_offsets(recp, (long) 0);
E 7
	return recp;
E 6
}

/*
 * Define a record namelist entry.
D 6
 * R is the tree for the record to be built.
 * Off is the offset for the first item in this (sub)record.
E 6
I 6
 * r is the tree for the record to be built.
 * first is a boolean indicating whether this is an outermost record,
 * for name lookups.
 * p is the record we define here.
 * P0was is a local which stacks the enclosing value of P0 in the stack frame,
 * since tyrec1() is recursive.
E 6
 */
struct nl *
D 6
tyrec1(r, off, first)
E 6
I 6
tyrec1(r, first)
E 6
D 7
	register int *r;
E 7
I 7
	register struct tnode *r;	/* T_FLDLST */
E 7
D 6
	int off;
	char first;
E 6
I 6
	bool first;
E 6
{
	register struct nl *p, *P0was;

I 6
	DEBUG_RECORDS(fprintf(stderr,"[tyrec1] first=%d\n", first));
E 6
D 7
	p = defnl(0, RECORD, 0, 0);
E 7
I 7
	p = defnl((char *) 0, RECORD, NLNIL, 0);
E 7
	P0was = P0;
	if (first)
		P0 = p;
#ifndef PI0
D 6
	p->value[NL_FLDSZ] = p->value[NL_OFFS] = off;
E 6
I 6
	p->align_info = A_MIN;
E 6
#endif
D 7
	if (r != NIL) {
		fields(p, r[2]);
		variants(p, r[3]);
E 7
I 7
	if (r != TR_NIL) {
		fields(p, r->fldlst.fix_list);
		variants(p, r->fldlst.variant);
E 7
	}
D 6
	    /*
	     *	round the lengths of records up to their alignments
	     */
D 3
	p -> value[ NL_OFFS ] = roundup( p -> value[ NL_OFFS ] , align( p ) );
E 3
I 3
	p->value[NL_OFFS] = roundup(p->value[NL_OFFS], (long)align(p));
E 6
E 3
	P0 = P0was;
	return (p);
}

/*
 * Define the fixed part fields for p.
I 6
 * hang them, in order, from the record entry, through ->ptr[NL_FIELDLIST].
 * the fieldlist is a tconc structure, and is manipulated 
 * just like newlist(), addlist(), fixlist() in the parser.
E 6
 */
D 6
struct nl *
E 6
fields(p, r)
	struct nl *p;
D 7
	int *r;
E 7
I 7
	struct tnode *r;	/* T_LISTPP */
E 7
{
D 6
	register int *fp, *tp, *ip;
	struct nl *jp;
E 6
I 6
D 7
	register int	*fp, *tp, *ip;
E 7
I 7
	register struct tnode	*fp, *tp, *ip;
E 7
	struct nl	*jp;
	struct nl	*fieldnlp;
E 6

I 6
	DEBUG_RECORDS(fprintf(stderr,"[fields]\n"));
E 6
D 7
	for (fp = r; fp != NIL; fp = fp[2]) {
		tp = fp[1];
		if (tp == NIL)
E 7
I 7
	for (fp = r; fp != TR_NIL; fp = fp->list_node.next) {
		tp = fp->list_node.list;
		if (tp == TR_NIL)
E 7
			continue;
D 7
		jp = gtype(tp[3]);
		line = tp[1];
D 6
		for (ip = tp[2]; ip != NIL; ip = ip[2])
			deffld(p, ip[1], jp);
E 6
I 6
		for (ip = tp[2]; ip != NIL; ip = ip[2]) {
		    fieldnlp = deffld(p, ip[1], jp);
E 7
I 7
		jp = gtype(tp->rfield.type);
		line = tp->rfield.line_no;
		for (ip = tp->rfield.id_list; ip != TR_NIL;
				    ip = ip->list_node.next) {
		    fieldnlp = deffld(p, (char *) ip->list_node.list, jp);
E 7
		    if ( p->ptr[NL_FIELDLIST] == NIL ) {
			    /* newlist */
			p->ptr[NL_FIELDLIST] = fieldnlp;
			fieldnlp->ptr[NL_FIELDLIST] = fieldnlp;
		    } else {
			    /* addlist */
			fieldnlp->ptr[NL_FIELDLIST] =
				p->ptr[NL_FIELDLIST]->ptr[NL_FIELDLIST];
			p->ptr[NL_FIELDLIST]->ptr[NL_FIELDLIST] = fieldnlp;
			p->ptr[NL_FIELDLIST] = fieldnlp;
		    }
		}
E 6
	}
I 6
	if ( p->ptr[NL_FIELDLIST] != NIL ) {
		/* fixlist */
	    fieldnlp = p->ptr[NL_FIELDLIST]->ptr[NL_FIELDLIST];
	    p->ptr[NL_FIELDLIST]->ptr[NL_FIELDLIST] = NIL;
	    p->ptr[NL_FIELDLIST] = fieldnlp;
	}
E 6
}

/*
 * Define the variants for RECORD p.
 */
D 6
struct nl *
E 6
variants(p, r)
	struct nl *p;
D 7
	register int *r;
E 7
I 7
	register struct tnode *r;	/* T_TYVARPT */
E 7
{
D 7
	register int *vc, *v;
	int *vr;
E 7
I 7
	register struct tnode *vc, *v;
	struct nl *vr;
E 7
	struct nl *ct;

I 6
	DEBUG_RECORDS(fprintf(stderr,"[variants]\n"));
E 6
D 7
	if (r == NIL)
E 7
I 7
	if (r == TR_NIL)
E 7
		return;
D 7
	ct = gtype(r[3]);
D 5
	if ( isnta( ct , "bcsi" ) ) {
E 5
I 5
	if ( ( ct != NIL ) && ( isnta( ct , "bcsi" ) ) ) {
E 7
I 7
	ct = gtype(r->varpt.type_id);
	if ( ( ct != NLNIL ) && ( isnta( ct , "bcsi" ) ) ) {
E 7
E 5
	    error("Tag fields cannot be %ss" , nameof( ct ) );
	}
D 7
	line = r[1];
E 7
I 7
	line = r->varpt.line_no;
E 7
	/*
	 * Want it even if r[2] is NIL so
	 * we check its type in "new" and "dispose"
	 * calls -- link it to NL_TAG.
	 */
D 7
	p->ptr[NL_TAG] = deffld(p, r[2], ct);
	for (vc = r[4]; vc != NIL; vc = vc[2]) {
		v = vc[1];
		if (v == NIL)
E 7
I 7
	p->ptr[NL_TAG] = deffld(p, r->varpt.cptr, ct);
	for (vc = r->varpt.var_list; vc != TR_NIL; vc = vc->list_node.next) {
		v = vc->list_node.list;
		if (v == TR_NIL)
E 7
			continue;
D 6
		vr = tyrec1(v[3], p->value[NL_FLDSZ], 0);
E 6
I 6
D 7
		vr = tyrec1(v[3], FALSE);
E 7
I 7
		vr = tyrec1(v->tyvarnt.fld_list, FALSE);
E 7
E 6
#ifndef PI0
D 6
		if (vr->value[NL_OFFS] > p->value[NL_OFFS])
			p->value[NL_OFFS] = vr->value[NL_OFFS];
E 6
I 6
		DEBUG_RECORDS(
		    fprintf(stderr,
			"[variants] p->align_info %d vr->align_info %d\n",
			p->align_info, vr->align_info));
		if (vr->align_info > p->align_info) {
		    p->align_info = vr->align_info;
		}
E 6
#endif
D 7
		line = v[1];
		for (v = v[2]; v != NIL; v = v[2])
			defvnt(p, v[1], vr, ct);
E 7
I 7
		line = v->tyvarnt.line_no;
		for (v = v->tyvarnt.const_list; v != TR_NIL;
				v = v->list_node.next)
			(void) defvnt(p, v->list_node.list, vr, ct);
E 7
	}
}

/*
 * Define a field in subrecord p of record P0
 * with name s and type t.
 */
struct nl *
deffld(p, s, t)
	struct nl *p;
	register char *s;
	register struct nl *t;
{
	register struct nl *fp;

I 6
	DEBUG_RECORDS(fprintf(stderr,"[deffld] s=<%s>\n", s));
E 6
	if (reclook(P0, s) != NIL) {
#ifndef PI1
		error("%s is a duplicate field name in this record", s);
#endif
		s = NIL;
	}
D 6
#ifndef PI0
E 6
	    /*
D 6
	     * it used to be easy to keep track of offsets of fields
	     * and total sizes of records.
	     * but now, the offset of the field is aligned
	     * so only it knows it's offset, and calculating 
	     * the total size of the record is based on it,
	     * rather than just the width of the field.
E 6
I 6
	     *	enter the field with its type
E 6
	     */
D 3
	fp = enter( defnl( s , FIELD , t , roundup( p -> value[ NL_OFFS ]
						    , align( t ) ) ) );
E 3
I 3
D 6
	fp = enter(defnl(s, FIELD, t, (int)roundup(p->value[NL_OFFS],
			(long)align(t))));
E 3
#else
E 6
	fp = enter(defnl(s, FIELD, t, 0));
D 6
#endif
E 6
I 6
	    /*
	     *	if no name, then this is an unnamed tag,
	     *	so don't link it into reclook()'s chain.
	     */
E 6
	if (s != NIL) {
		fp->chain = P0->chain;
		P0->chain = fp;
#ifndef PI0
		    /*
D 6
		     * and the size of the record is incremented.
E 6
I 6
		     * and the alignment is propagated back.
E 6
		     */
D 2
		p -> value[ NL_OFFS ] = fp -> value[ NL_OFFS ]
					    + even( width( t ) );
E 2
I 2
D 6
		p -> value[ NL_OFFS ] = fp -> value[ NL_OFFS ] + width( t );
E 2
		p -> value[ NL_FLDSZ ] = p -> value[ NL_OFFS ];
E 6
I 6
		fp->align_info = align(t);
		DEBUG_RECORDS(
		    fprintf(stderr,
			"[deffld] fp->align_info %d p->align_info %d \n",
			fp->align_info, p->align_info));
		if (fp->align_info > p->align_info) {
		    p->align_info = fp->align_info;
		}
E 6
#endif
		if (t != NIL) {
			P0->nl_flags |= t->nl_flags & NFILES;
			p->nl_flags |= t->nl_flags & NFILES;
		}
D 6
#		ifdef PC
		    stabfield( s , p2type( t ) , fp -> value[ NL_OFFS ]
				, lwidth( t ) );
#		endif PC
E 6
	}
	return (fp);
}

/*
 * Define a variant from the constant tree of t
 * in subrecord p of record P0 where the casetype
 * is ct and the variant record to be associated is vr.
 */
struct nl *
defvnt(p, t, vr, ct)
	struct nl *p, *vr;
D 7
	int *t;
E 7
I 7
	struct tnode *t;	/* CHAR_CONST or SIGN_CONST */
E 7
	register struct nl *ct;
{
	register struct nl *av;

	gconst(t);
	if (ct != NIL && incompat(con.ctype, ct , t )) {
#ifndef PI1
		cerror("Variant label type incompatible with selector type");
#endif
		ct = NIL;
	}
D 7
	av = defnl(0, VARNT, ct, 0);
E 7
I 7
	av = defnl((char *) 0, VARNT, ct, 0);
E 7
#ifndef PI1
	if (ct != NIL)
		uniqv(p);
D 6
#endif
E 6
I 6
#endif not PI1
E 6
	av->chain = p->ptr[NL_VARNT];
	p->ptr[NL_VARNT] = av;
	av->ptr[NL_VTOREC] = vr;
	av->range[0] = con.crval;
	return (av);
}

#ifndef PI1
/*
 * Check that the constant label value
 * is unique among the labels in this variant.
 */
uniqv(p)
	struct nl *p;
{
	register struct nl *vt;

	for (vt = p->ptr[NL_VARNT]; vt != NIL; vt = vt->chain)
		if (vt->range[0] == con.crval) {
			error("Duplicate variant case label in record");
			return;
		}
}
#endif

/*
 * See if the field name s is defined
 * in the record p, returning a pointer
 * to it namelist entry if it is.
 */
struct nl *
reclook(p, s)
	register struct nl *p;
	char *s;
{

	if (p == NIL || s == NIL)
		return (NIL);
	for (p = p->chain; p != NIL; p = p->chain)
		if (p->symbol == s)
			return (p);
	return (NIL);
I 6
}

    /*
     *	descend namelist entry for a record and assign offsets.
     *	fields go at the next higher offset that suits their alignment.
     *	all variants of a record start at the same offset, which is suitable
     *	for the alignment of their worst aligned field.  thus the size of a 
     *	record is independent of whether or not it is a variant
     *	(a desirable property).
     *	records come to us in the namelist, where they have been annotated
     *	with the maximum alignment their fields require.
     *	the starting offset is passed to us, and is passed recursively for
     *	variant records within records.
     *	the final maximum size of each record is recorded in the namelist
     *	in the value[NL_OFFS] field of the namelist for the record.
     *
     *	this is supposed to match the offsets used by the c compiler
     *	so people can share records between modules in both languages.
     */
rec_offsets(recp, offset)
    struct nl	*recp;		/* pointer to the namelist record */
    long	offset;		/* starting offset for this record/field */
{
    long	origin;		/* offset of next field */
    struct nl	*fieldnlp;	/* the current field */
    struct nl	*varntnlp;	/* the current variant */
    struct nl	*vrecnlp;	/* record for the current variant */
D 7
    long	alignment;	/* maximum alignment for any variant */
E 7

    if ( recp == NIL ) {
	return;
    }
D 7
    origin = roundup(offset,recp->align_info);
E 7
I 7
    origin = roundup((int) offset,(long) recp->align_info);
E 7
    if (origin != offset) {
	fprintf(stderr,
		"[rec_offsets] offset=%d recp->align_info=%d origin=%d\n",
		offset, recp->align_info, origin);
	panic("rec_offsets");
    }
    DEBUG_RECORDS(
	fprintf(stderr,
	    "[rec_offsets] offset %d recp->align %d origin %d\n",
	    offset, recp->align_info, origin));
	/*
	 *	fixed fields are forward linked though ->ptr[NL_FIELDLIST]
	 *	give them all suitable offsets.
	 */
    for (   fieldnlp = recp->ptr[NL_FIELDLIST];
	    fieldnlp != NIL;
	    fieldnlp = fieldnlp->ptr[NL_FIELDLIST] ) {
D 7
	origin = roundup(origin,align(fieldnlp->type));
E 7
I 7
	origin = roundup((int) origin,(long) align(fieldnlp->type));
E 7
	fieldnlp->value[NL_OFFS] = origin;
	DEBUG_RECORDS(
	    fprintf(stderr,"[rec_offsets] symbol %s origin %d\n",
		    fieldnlp->symbol, origin));
	origin += lwidth(fieldnlp->type);
    }
	/*
	 *	this is the extent of the record, so far
	 */
    recp->value[NL_OFFS] = origin;
	/*
	 *	if we have a tag field, we have variants to deal with
	 */
    if ( recp->ptr[NL_TAG] ) {
	    /*
	     *	if tag field is unnamed, then don't allocate space for it.
	     */
	fieldnlp = recp->ptr[NL_TAG];
	if ( fieldnlp->symbol != NIL ) {
D 7
	    origin = roundup(origin,align(fieldnlp->type));
E 7
I 7
	    origin = roundup((int) origin,(long) align(fieldnlp->type));
E 7
	    fieldnlp->value[NL_OFFS] = origin;
D 11
	    DEBUG_RECORDS(fprintf(stderr,"[rec_offsets] tag %s origin\n",
E 11
I 11
	    DEBUG_RECORDS(fprintf(stderr,"[rec_offsets] tag %s origin %d\n",
E 11
				    fieldnlp->symbol, origin));
	    origin += lwidth(fieldnlp->type);
	}
	    /*
	     *	find maximum alignment of records of variants
	     */
	for (	varntnlp = recp->ptr[NL_VARNT]; 
		varntnlp != NIL;
		varntnlp = varntnlp -> chain ) {
	    vrecnlp = varntnlp->ptr[NL_VTOREC];
	    DEBUG_RECORDS(
		fprintf(stderr,
			"[rec_offsets] maxing variant %d align_info %d\n",
			varntnlp->value[0], vrecnlp->align_info));
D 7
	    origin = roundup(origin,vrecnlp->align_info);
E 7
I 7
	    origin = roundup((int) origin,(long) vrecnlp->align_info);
E 7
	}
	DEBUG_RECORDS(
	    fprintf(stderr, "[rec_offsets] origin of variants %d\n", origin));
	    /*
	     *	assign offsets to fields of records of the variants
	     *	keep maximum length of the current record.
	     */
	for (	varntnlp = recp->ptr[NL_VARNT]; 
		varntnlp != NIL;
		varntnlp = varntnlp -> chain ) {
	    vrecnlp = varntnlp->ptr[NL_VTOREC];
		/*
		 *	assign offsets to fields of the variant.
		 *	recursive call on rec_offsets.
		 */
	    rec_offsets(vrecnlp,origin);
		/*
		 *	extent of the record is the
		 *	maximum extent of all variants
		 */
	    if ( vrecnlp->value[NL_OFFS] > recp->value[NL_OFFS] ) {
		recp->value[NL_OFFS] = vrecnlp->value[NL_OFFS];
	    }
	}
    }
	/*
	 *	roundup the size of the record to its alignment
	 */
    DEBUG_RECORDS(
	fprintf(stderr,
		"[rec_offsets] recp->value[NL_OFFS] %d ->align_info %d\n",
		recp->value[NL_OFFS], recp->align_info));
D 7
    recp->value[NL_OFFS] = roundup(recp->value[NL_OFFS],recp->align_info);
E 7
I 7
    recp->value[NL_OFFS] = roundup(recp->value[NL_OFFS],(long) recp->align_info);
E 7
E 6
}
E 1
