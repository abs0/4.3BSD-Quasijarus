h31884
s 00016/00016/00118
d D 6.1 86/04/24 00:00:11 mckusick 3 2
c document distributed with 4.3BSD
e
s 00000/00000/00134
d D 5.1 86/04/23 23:59:57 mckusick 2 1
c document distributed with 4.2BSD
e
s 00134/00000/00000
d D 4.1 86/04/23 23:59:21 mckusick 1 0
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

# include	<curses.h>
# include	<signal.h>

/*
 * the idea for this program was a product of the imagination of
 * Kurt Schoens.  Not responsible for minds lost or stolen.
 */

# define	NCOLS	80
# define	NLINES	24
# define	MAXPATTERNS	4

D 3
struct locs {
	char	y, x;
};
E 3
I 3
typedef struct {
	int	y, x;
} LOCS;
E 3

D 3
typedef struct locs	LOCS;

E 3
LOCS	Layout[NCOLS * NLINES];	/* current board layout */

int	Pattern,		/* current pattern number */
	Numstars;		/* number of stars in pattern */

D 3
main() {
E 3
I 3
char	*getenv();
E 3

D 3
	char		*getenv();
	int		die();
E 3
I 3
int	die();
E 3

I 3
main()
{
E 3
	srand(getpid());		/* initialize random sequence */

	initscr();
	signal(SIGINT, die);
	noecho();
	nonl();
	leaveok(stdscr, TRUE);
	scrollok(stdscr, FALSE);

	for (;;) {
		makeboard();		/* make the board setup */
		puton('*');		/* put on '*'s */
		puton(' ');		/* cover up with ' 's */
	}
}

/*
 * On program exit, move the cursor to the lower left corner by
 * direct addressing, since current location is not guaranteed.
 * We lie and say we used to be at the upper right corner to guarantee
 * absolute addressing.
 */
D 3
die() {

E 3
I 3
die()
{
E 3
	signal(SIGINT, SIG_IGN);
D 3
	mvcur(0, COLS-1, LINES-1, 0);
E 3
I 3
	mvcur(0, COLS - 1, LINES - 1, 0);
E 3
	endwin();
	exit(0);
}


/*
 * Make the current board setup.  It picks a random pattern and
 * calls ison() to determine if the character is on that pattern
 * or not.
 */
D 3
makeboard() {

E 3
I 3
makeboard()
{
E 3
	reg int		y, x;
	reg LOCS	*lp;

	Pattern = rand() % MAXPATTERNS;
	lp = Layout;
	for (y = 0; y < NLINES; y++)
		for (x = 0; x < NCOLS; x++)
			if (ison(y, x)) {
				lp->y = y;
D 3
				lp++->x = x;
E 3
I 3
				lp->x = x;
				lp++;
E 3
			}
	Numstars = lp - Layout;
}

/*
 * Return TRUE if (y, x) is on the current pattern.
 */
ison(y, x)
reg int	y, x; {

	switch (Pattern) {
	  case 0:	/* alternating lines */
		return !(y & 01);
	  case 1:	/* box */
		if (x >= LINES && y >= NCOLS)
			return FALSE;
		if (y < 3 || y >= NLINES - 3)
			return TRUE;
		return (x < 3 || x >= NCOLS - 3);
	  case 2:	/* holy pattern! */
		return ((x + y) & 01);
	  case 3:	/* bar across center */
		return (y >= 9 && y <= 15);
	}
	/* NOTREACHED */
}

puton(ch)
D 3
reg char	ch; {

E 3
I 3
reg char	ch;
{
E 3
	reg LOCS	*lp;
	reg int		r;
	reg LOCS	*end;
	LOCS		temp;

	end = &Layout[Numstars];
	for (lp = Layout; lp < end; lp++) {
		r = rand() % Numstars;
		temp = *lp;
		*lp = Layout[r];
		Layout[r] = temp;
	}

	for (lp = Layout; lp < end; lp++) {
		mvaddch(lp->y, lp->x, ch);
		refresh();
	}
}
E 1
