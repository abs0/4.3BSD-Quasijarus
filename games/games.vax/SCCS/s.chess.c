h28223
s 00011/00000/00000
d D 4.1 82/10/24 18:26:12 mckusick 1 0
c date and time created 82/10/24 18:26:12 by mckusick
e
u
U
t
T
I 1

static char sccsid[] = "	%M%	%I%	%E%	";

#include <stdio.h>
main()
{
	execl("/usr/games/lib/compat", "chess", "/usr/games/lib/chess", 0);
	execl("/usr/games/DUNGEON", "chess", "/usr/games/lib/chess", 0);
	printf(stderr, "Sorry, not today\n");
	exit(1);
}
E 1
