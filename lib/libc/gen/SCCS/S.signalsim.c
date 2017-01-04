h39768
s 00031/00006/00013
d D 4.4 84/11/04 23:03:22 mckusick 4 3
c add signal simulation routine in case signal syscall is not implemented
e
s 00001/00001/00018
d D 4.3 83/07/02 12:14:40 sam 3 2
c 
e
s 00010/00002/00009
d D 4.2 83/06/10 22:43:20 sam 2 1
c sigvec is a moving target no more
e
s 00011/00000/00000
d D 4.1 83/06/04 10:44:13 root 1 0
c date and time created 83/06/04 10:44:13 by root
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

/*
D 3
 * Backwards compatible signal.
E 3
I 3
 * Almost backwards compatible signal.
E 3
 */
I 2
#include <signal.h>
E 2

I 4
enum {NATIVE = 0x0, UNKNOWN = 0x1, SIMULATE = 0x3} _sigsim = UNKNOWN;

E 4
D 2
signal(s, a)
E 2
I 2
int (*
D 4
signal(s, a))()
E 4
I 4
signalsim(s, a))()
E 4
	int s, (*a)();
E 2
{
I 2
	struct sigvec osv, sv;
I 4
	int badcall();
E 4
E 2

D 2
	return (sigvec(s, a, 0));
E 2
I 2
D 4
	sv.sv_handler = a;
	sv.sv_mask = sv.sv_onstack = 0;
	if (sigvec(s, &sv, &osv) < 0)
		return (BADSIG);
	return (osv.sv_handler);
E 4
I 4
	switch (_sigsim) {
	case UNKNOWN:
		sv.sv_handler = badcall;
		sv.sv_mask = sv.sv_onstack = 0;
		if (sigvec(SIGSYS, &sv, &osv) < 0) {
			_sigsim = SIMULATE;
		} else {
			_sigsim = NATIVE;
			signal(SIGSYS, osv.sv_handler);
		}
		/* fall through */
	case NATIVE:
	case SIMULATE:
		sv.sv_handler = a;
		sv.sv_mask = sv.sv_onstack = 0;
		if (sigvec(s, &sv, &osv) < 0)
			return (BADSIG);
		return (osv.sv_handler);
	}
}

/*
 * Signal call will trap to here if not implemented
 */
badcall()
{
	_sigsim = SIMULATE;
E 4
E 2
}
E 1
