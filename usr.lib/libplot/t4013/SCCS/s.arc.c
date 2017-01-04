h35907
s 00003/00003/00112
d D 5.2 85/06/23 13:40:52 mckusick 3 2
c check args to sqrt() (from jerry@opal)
e
s 00007/00001/00108
d D 5.1 85/06/07 08:24:55 dist 2 1
c Add copyright
e
s 00109/00000/00000
d D 1.1 85/01/02 20:10:33 jak 1 0
c date and time created 85/01/02 20:10:33 by jak
e
u
U
t
T
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 2
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif
E 2
I 2
#endif not lint
E 2

int del = 20;
step(d){
	del = d;
}
arc(x,y,x0,y0,x1,y1){
	double pc;
	double sqrt();
	int flg,m,xc,yc,xs,ys,qs,qf;
	float dx,dy,r;
	char use;
	dx = x-x0;
	dy = y-y0;
	r = dx*dx+dy*dy;
	pc = r;
D 3
	pc = sqrt(pc);
E 3
I 3
	pc = pc > 0 ? sqrt(pc) : 0;
E 3
	flg = pc/4;
	if(flg == 0)step(1);
	else if(flg < del)step(flg);
	xc = xs = x0;
	yc = ys = y0;
	move(xs,ys);
	if(x0 == x1 && y0 == y1)flg=0;
	else flg=1;
	qs = quad(x,y,x0,y0);
	qf = quad(x,y,x1,y1);
	if(abs(x-x1) < abs(y-y1)){
		use = 'x';
		if(qs == 2 || qs ==3)m = -1;
		else m=1;
	}
	else {
		use = 'y';
		if(qs > 2)m= -1;
		else m= 1;
	}
	while(1){
		switch(use){
		case 'x':	
			if(qs == 2 || qs == 3)yc -= del;
			else yc += del;
			dy = yc-y;
			pc = r-dy*dy;
D 3
			xc = m*sqrt(pc)+x;
E 3
I 3
			xc = m*(pc > 0 ? sqrt(pc) : 0)+x;
E 3
			if((x < xs && x >= xc) || ( x > xs && x <= xc) ||
			    (y < ys && y >= yc) || ( y > ys && y <=  yc) )
			{
				if(++qs > 4)qs=1;
				if(qs == 2 || qs == 3)m= -1;
				else m=1;
				flg=1;
			}
			cont(xc,yc);
			xs = xc; 
			ys = yc;
			if(qs == qf && flg == 1)
				switch(qf){
				case 3:
				case 4:	
					if(xs >= x1)return;
					continue;
				case 1:
				case 2:
					if(xs <= x1)return;
				}
			continue;
		case 'y':	
			if(qs > 2)xc += del;
			else xc -= del;
			dx = xc-x;
			pc = r-dx*dx;
D 3
			yc = m*sqrt(pc)+y;
E 3
I 3
			yc = m*(pc > 0 ? sqrt(pc) : 0)+y;
E 3
			if((x < xs && x >= xc) || ( x > xs && x <= xc ) ||
			    (y < ys && y >= yc) || (y > ys && y <= yc) )
			{
				if(++qs > 4)qs=1;
				if(qs > 2)m = -1;
				else m = 1;
				flg=1;
			}
			cont(xc,yc);
			xs = xc; 
			ys = yc;
			if(qs == qf && flg == 1)
				switch(qs){
				case 1:
				case 4:
					if(ys >= y1)return;
					continue;
				case 2:
				case 3:
					if(ys <= y1)return;
				}
		}
	}
}
quad(x,y,xp,yp){
	if(x < xp)
		if(y <= yp)return(1);
		else return(4);
	else if(x > xp)
		if(y < yp)return(2);
		else return(3);
	else if(y < yp)return(2);
	else return(4);
}
E 1
