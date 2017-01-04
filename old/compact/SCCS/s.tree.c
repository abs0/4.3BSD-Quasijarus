h15236
s 00054/00040/00103
d D 4.4 84/08/25 23:48:40 sam 4 3
c speed up balanced tree insertion
e
s 00080/00090/00063
d D 4.3 84/08/25 22:04:58 sam 3 2
c rewrite and speed up 
e
s 00003/00001/00150
d D 4.2 83/08/11 22:28:51 sam 2 1
c standardize sccs keyword lines
e
s 00151/00000/00000
d D 4.1 83/02/11 14:56:55 shannon 1 0
c date and time created 83/02/11 14:56:55 by shannon
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif
E 2

#include "compact.h"

D 3

E 3
D 4
insert (ch)
E 4
I 4
insert(ch)
E 4
D 3
int ch;
E 3
I 3
	int ch;
E 3
{
	register struct node *pp;
D 4
	register int c;
E 4
I 4
	register struct son *pson, *bson;
E 4
	union cio d;
D 4
	register struct index *qt, *wt;
E 4
I 4
	register struct index *wt;
E 4

D 4
	c = ch;
E 4
	wt = NEW;
	pp = bottom++;
I 4
	pson = &pp->sons[RIGHT];
	bson = &bottom->sons[LEFT];
E 4
D 3
	bottom -> fath . fp = pp;
	in [c] . flags = (SEEN | FBIT);
	d . integ = bottom -> sp [0] . ch = pp -> sp [1] . ch;
	in [c] . fp = in [d . integ] . fp = pp -> sp [1] . p = wt -> pt = bottom;
	bottom -> fath . flags = (LLEAF | RLEAF | FBIT);
	pp -> fath . flags &= ~RLEAF;
	in [d . integ] . flags = SEEN;
E 3
I 3
	bottom->fath.fp = pp;
D 4
	in[c].flags = (SEEN | FBIT);
	d.integ = bottom->sp[0].ch = pp->sp[1].ch;
	in[c].fp = in[d.integ].fp = pp->sp[1].p = wt->pt = bottom;
E 4
I 4
	in[ch].flags = (SEEN | FBIT);
	d.integ = bson->sp.ch = pson->sp.ch;
	in[ch].fp = in[d.integ].fp = pson->sp.p = wt->pt = bottom;
E 4
	bottom->fath.flags = (LLEAF | RLEAF | FBIT);
	pp->fath.flags &= ~RLEAF;
	in[d.integ].flags = SEEN;
E 3

D 3
	bottom -> count [0] = pp -> count [1];
	qt = pp -> top [1];
	bottom -> top [0] = qt;
	bottom -> sp [1] . ch = c;
	bottom -> count [1] = 0;
	bottom -> top [1] = qt -> next = wt;
	wt -> next = NULL;
E 3
I 3
D 4
	bottom->count[0] = pp->count[1];
	qt = pp->top[1];
	bottom->top[0] = qt;
	bottom->sp[1].ch = c;
	bottom->count[1] = 0;
	bottom->top[1] = qt->next = wt;
E 4
I 4
	bson->count = pson->count;
	bson->top = pson->top;
	bson++;
	bson->sp.ch = ch;
	bson->count = 0;
	bson->top = pson->top->next = wt;
E 4
	wt->next = NULL;
E 3
}

D 4
uptree (ch)
E 4
I 4
uptree(ch)
E 4
D 3
int ch;
E 3
I 3
	int ch;
E 3
{
	register struct node *r;
	union treep q, s;
D 4
	int rs, qs, ss, ts;
E 4
I 4
	int rs, ts, rflags, tflags;
E 4
	longint rc, qc, sc;
	struct node *t;
I 4
	register struct son *rson, *tson;
E 4
	register struct index *rt, *qt, *st;

D 3
	r = in [ch] . fp;
	rs = in [ch] . flags & FBIT;
E 3
I 3
	r = in[ch].fp;
	rs = in[ch].flags & FBIT;
E 3

	do {
D 3
		(r -> count [rs])++;
		rc = r -> count [rs];
		rt = r -> top [rs];
	
		for ( ; ; ) {
E 3
I 3
D 4
		rc = ++r->count[rs];
		rt = r->top[rs];
E 4
I 4
		rson = &r->sons[rs];
		rc = ++rson->count;
		rt = rson->top;
E 4
		for (;;) {
E 3
D 4
			qs = ss = 1 - rs;
D 3
			s . p = r + rs;
			sc = (s . p) -> count [ss];
			st = (s . p) -> top [ss];
E 3
I 3
			s.p = r + rs;
			sc = s.p->count[ss];
			st = s.p->top[ss];
E 3
	
E 4
D 3
			if (rs)
E 3
I 3
			if (rs) {
I 4
				s.p = r + 1;
E 4
E 3
				if (r == bottom) {
					sc = rc - 2;
					st = NULL;
I 4
				} else {
					sc = (r+1)->sons[LEFT].count;
					st = (r+1)->sons[LEFT].top;
E 4
				}
I 4
				qc = r->sons[LEFT].count;
				qt = r->sons[LEFT].top;
E 4
D 3
				else;
			else if (r == dict) {
				qc = rc + 1;
				qt = head;
				break;
E 3
I 3
			} else {
I 4
				s.p = r;
				sc = r->sons[RIGHT].count;
				st = r->sons[RIGHT].top;
E 4
				if (r == dict) {
					qc = rc + 1;
					qt = head;
					break;
I 4
				} else {
					qc = (r-1)->sons[RIGHT].count;
					qt = (r-1)->sons[RIGHT].top;
E 4
				}
E 3
			}
I 3
D 4
			q.p = r - qs;
			qc = q.p->count[qs];
			qt = q.p->top[qs];
E 4
			if (rc <= qc)
				break;
E 3

D 3
			q . p = r - qs;
			qc = (q . p) -> count [qs];
			qt = (q . p) -> top [qs];
			if (rc <= qc) break;
E 3
I 3
			t = qt->pt;
D 4
			ts = (rc <= t->count[0]);
E 4
I 4
			ts = LEFT;
			tson = &t->sons[LEFT];
			if (rc <= tson->count) {
				tson++;
				ts++;
			}
E 4
E 3

D 3
			t = qt -> pt;
			ts = (rc <= t -> count [0] ? 1 : 0);

E 3
			/* exchange pointers of (t, ts) and (r, rs) */
I 3
D 4
			q.ch = t->sp[ts].ch;
			s.ch = r->sp[rs].ch;
			t->sp[ts].ch = s.ch;
			r->sp[rs].ch = q.ch;
E 4
I 4
			q.ch = tson->sp.ch;
			s.ch = rson->sp.ch;
			tson->sp.ch = s.ch;
			rson->sp.ch = q.ch;
E 4
			exch(t, ts, q.ch, r, rs);
			exch(r, rs, s.ch, t, ts);
E 3

D 3
			q . ch = t -> sp [ts] . ch;	/*  {					*/
			s . ch = r -> sp [rs] . ch;	/*  {					*/
			t -> sp [ts] . ch = s . ch;	/*  {					*/
			r -> sp [rs] . ch = q . ch;	/*  { change code when Cory gets v. 7	*/
							/*  {					*/
			exch (t, ts, q . ch, r, rs);	/*  {					*/
			exch (r, rs, s . ch, t, ts);	/*  {					*/

E 3
D 4
			qs = (rs ? RLEAF : LLEAF);
			ss = (ts ? RLEAF : LLEAF);
D 3
			if (((r -> fath . flags & qs) << rs) ^ ((t -> fath . flags & ss) << ts)) {
				r -> fath . flags ^= qs;
				t -> fath . flags ^= ss;
E 3
I 3
			if (((r->fath.flags & qs) << rs) ^ ((t->fath.flags & ss) << ts)) {
				r->fath.flags ^= qs;
				t->fath.flags ^= ss;
E 4
I 4
			rflags = (rs ? RLEAF : LLEAF);
			tflags = (ts ? RLEAF : LLEAF);
			if (((r->fath.flags & rflags) << rs) ^ ((t->fath.flags & tflags) << ts)) {
				r->fath.flags ^= rflags;
				t->fath.flags ^= tflags;
E 4
E 3
			}

D 3
			(t -> count [ts])++;
			(r -> count [rs])--;
			(qt -> pt) += ts;
E 3
I 3
D 4
			t->count[ts]++;
			r->count[rs]--;
			qt->pt += ts;
E 4
I 4
			tson->count++;
			rson->count--;
			if (ts)
				qt->pt++;
E 4
E 3
			r = t;
			rs = ts;
I 4
			rson = tson;
E 4
		}

		if (rc == qc) {
D 3
			r -> top [rs] = qt;
E 3
I 3
D 4
			r->top[rs] = qt;
E 4
I 4
			rson->top = qt;
E 4
E 3
			if (rc > sc + 1) {
D 3
				qt -> next = st;

E 3
I 3
				qt->next = st;
E 3
				/* dispose of rt */
D 3

				rt -> next = flist;
E 3
I 3
				rt->next = flist;
E 3
				flist = rt;
D 3
			}
			else st -> pt = s . p;
		}

		else if (rc == sc + 1) {

E 3
I 3
			} else
				st->pt = s.p;
		} else if (rc == sc + 1) {
E 3
			/* create new index at rt */
D 3

E 3
			rt = NEW;
D 3
			rt -> next = st;
			rt -> pt = r;
			qt -> next = rt;
			if (st) st -> pt = s . p;
			r -> top [rs] = rt;
E 3
I 3
			rt->next = st;
			rt->pt = r;
			qt->next = rt;
			if (st)
				st->pt = s.p;
D 4
			r->top[rs] = rt;
E 4
I 4
			rson->top = rt;
E 4
E 3
		}
D 3

		rs = r -> fath . flags & FBIT;
		r = r -> fath . fp;

E 3
I 3
		rs = r->fath.flags & FBIT;
		r = r->fath.fp;
E 3
	} while (r);
D 3
	dirp = head -> next;
	dirq = dirp -> next;
E 3
I 3
	dirp = head->next;
	dirq = dirp->next;
E 3
}

D 3
exch (v, vs, x, w, ws)
struct node *v, *w;
union treep x;
int vs, ws;
E 3
I 3
exch(v, vs, x, w, ws)
	struct node *v, *w;
	union treep x;
	int vs, ws;
E 3
{

D 3
	if (v -> fath . flags & (vs ? RLEAF : LLEAF)) {
		in [x . ch] . fp = w;
		in [x . ch] . flags &= ~01;
		if (ws) in [x . ch] . flags |= ws;
	}
	else {
		(x . p) -> fath . fp = w;
		(x . p) -> fath . flags &= ~01;
		if (ws) (x . p) -> fath . flags |= ws;
E 3
I 3
	if (v->fath.flags & (vs ? RLEAF : LLEAF)) {
		in[x.ch].fp = w;
		in[x.ch].flags &= ~01;
		if (ws)
			in[x.ch].flags |= ws;
	} else {
		x.p->fath.fp = w;
		x.p->fath.flags &= ~01;
		if (ws)
			x.p->fath.flags |= ws;
E 3
	}
}
E 1
