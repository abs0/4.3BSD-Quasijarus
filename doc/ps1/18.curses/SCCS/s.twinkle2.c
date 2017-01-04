h06799
s 00007/00016/00066
d D 6.1 86/04/24 00:01:06 mckusick 3 2
c document distributed with 4.3BSD
e
s 00000/00000/00082
d D 5.1 86/04/24 00:00:53 mckusick 2 1
c document distributed with 4.2BSD
e
s 00082/00000/00000
d D 4.1 86/04/24 00:00:41 mckusick 1 0
c document distributed with 4.1BSD
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

D 3
main() {
E 3
I 3
extern int	_putchar();
E 3

I 3
main()
{
E 3
	reg char	*sp;
D 3
	char		*getenv();
	int		_putchar(), die();
E 3

	srand(getpid());		/* initialize random sequence */

	if (isatty(0)) {
	       gettmode();
D 3
	       if (sp=getenv("TERM"))
E 3
I 3
	       if ((sp = getenv("TERM")) != NULL)
E 3
		       setterm(sp);
		signal(SIGINT, die);
	}
	else {
		printf("Need a terminal on %d\n", _tty_ch);
		exit(1);
	}
	_puts(TI);
	_puts(VS);

	noecho();
	nonl();
	tputs(CL, NLINES, _putchar);
	for (;;) {
		makeboard();		/* make the board setup */
		puton('*');		/* put on '*'s */
		puton(' ');		/* cover up with ' 's */
	}
}

D 3
/*
 * _putchar defined for tputs() (and _puts())
 */
_putchar(c)
reg char	c; {

	putchar(c);
}

E 3
puton(ch)
D 3
char	ch; {

	static int	lasty, lastx;
E 3
I 3
char	ch;
{
E 3
	reg LOCS	*lp;
	reg int		r;
	reg LOCS	*end;
	LOCS		temp;
I 3
	static int	lasty, lastx;
E 3

	end = &Layout[Numstars];
	for (lp = Layout; lp < end; lp++) {
		r = rand() % Numstars;
		temp = *lp;
		*lp = Layout[r];
		Layout[r] = temp;
	}

	for (lp = Layout; lp < end; lp++)
			/* prevent scrolling */
		if (!AM || (lp->y < NLINES - 1 || lp->x < NCOLS - 1)) {
			mvcur(lasty, lastx, lp->y, lp->x);
			putchar(ch);
			lasty = lp->y;
			if ((lastx = lp->x + 1) >= NCOLS)
				if (AM) {
					lastx = 0;
					lasty++;
				}
				else
					lastx = NCOLS - 1;
		}
}
E 1
