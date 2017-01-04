h12161
s 00001/00000/00337
d D 4.5 87/12/02 17:11:39 bostic 5 4
c bug report 4.3BSD/usr.bin/111; exit 0 on success
e
s 00001/00002/00336
d D 4.4 87/05/02 17:02:23 bostic 4 3
c bug report 4.2BSD/usr.bin/71; fix control characters in comments
e
s 00048/00045/00290
d D 4.3 85/09/21 14:53:01 sam 3 2
c remove escape codes from comment
e
s 00002/00001/00333
d D 4.2 82/11/27 19:56:10 shannon 2 1
c fix large floating point constants for SUN
e
s 00334/00000/00000
d D 4.1 80/10/01 17:28:31 bill 1 0
c date and time created 80/10/01 17:28:31 by bill
e
u
U
t
T
I 3
#ifndef lint
E 3
I 1
static char *sccsid = "%W% (Berkeley) %G%";
I 3
#endif

E 3
#include <stdio.h>
I 2
#include <math.h>
E 2

#define NP 1000
D 2
#define INF 1.e37
E 2
I 2
#define INF HUGE
E 2

struct proj { int lbf,ubf; float a,b,lb,ub,quant,mult,val[NP]; } x,y;
float *diag, *r;
float dx = 1.;
float ni = 100.;
int n;
int auta;
int periodic;
float konst = 0.0;
float zero = 0.;

/* Spline fit technique
let x,y be vectors of abscissas and ordinates
D 3
    h   be vector of differences h9i8=x9i8-x9i-1988
E 3
I 3
    h   be vector of differences hi=xi-xi-1
E 3
    y"  be vector of 2nd derivs of approx function
If the points are numbered 0,1,2,...,n+1 then y" satisfies
(R W Hamming, Numerical Methods for Engineers and Scientists,
2nd Ed, p349ff)
D 3
	h9i8y"9i-1988+2(h9i8+h9i+18)y"9i8+h9i+18y"9i+18
E 3
I 3
	hiy"i-1+2(hi+hi+1)y"i+hi+1y"i+1
E 3
	
D 3
	= 6[(y9i+18-y9i8)/h9i+18-(y9i8-y9i-18)/h9i8]   i=1,2,...,n
E 3
I 3
	= 6[(yi+1-yi)/hi+1-(yi-yi-1)/hi]   i=1,2,...,n
E 3

D 3
where y"908 = y"9n+18 = 0
E 3
I 3
where y"0 = y"n+1 = 0
E 3
This is a symmetric tridiagonal system of the form

D 3
	| a918 h928               |  |y"918|      |b918|
	| h928 a928 h938            |  |y"928|      |b928|
	|    h938 a938 h948         |  |y"938|  =   |b938|
E 3
I 3
	| a1 h2               |  |y"1|      |b1|
	| h2 a2 h3            |  |y"2|      |b2|
	|    h3 a3 h4         |  |y"3|  =   |b3|
E 3
	|         .           |  | .|      | .|
	|            .        |  | .|      | .|
It can be triangularized into
D 3
	| d918 h928               |  |y"918|      |r918|
	|    d928 h938            |  |y"928|      |r928|
	|       d938 h948         |  |y"938|  =   |r938|
E 3
I 3
	| d1 h2               |  |y"1|      |r1|
	|    d2 h3            |  |y"2|      |r2|
	|       d3 h4         |  |y"3|  =   |r3|
E 3
	|          .          |  | .|      | .|
	|             .       |  | .|      | .|
where
D 3
	d918 = a918
E 3
I 3
	d1 = a1
E 3

D 3
	r908 = 0
E 3
I 3
	r0 = 0
E 3

D 3
	d9i8 = a9i8 - h9i8829/d9i-18	1<i<_n
E 3
I 3
	di = ai - hi2/di-1	1<i<_n
E 3

D 3
	r9i8 = b9i8 - h9i8r9i-18/d9i-1i8	1<_i<_n
E 3
I 3
D 4
	ri = bi - hiri-1/di-1i	1<_i<_n
E 4
I 4
	ri = bi - hiri-1/di-1i	1<_i<_n
E 4
E 3

the back solution is
D 3
	y"9n8 = r9n8/d9n8
E 3
I 3
	y"n = rn/dn
E 3

D 3
	y"9i8 = (r9i8-h9i+18y"9i+18)/d9i8	1<_i<n
E 3
I 3
	y"i = (ri-hi+1y"i+1)/di	1<_i<n
E 3

D 3
superficially, d9i8 and r9i8 don't have to be stored for they can be
E 3
I 3
superficially, di and ri don't have to be stored for they can be
E 3
recalculated backward by the formulas

D 3
	d9i-18 = h9i8829/(a9i8-d9i8)	1<i<_n
E 3
I 3
	di-1 = hi2/(ai-di)	1<i<_n
E 3

D 3
	r9i-18 = (b9i8-r9i8)d9i-18/h9i8	1<i<_n
E 3
I 3
	ri-1 = (bi-ri)di-1/hi	1<i<_n
E 3

unhappily it turns out that the recursion forward for d
is quite strongly geometrically convergent--and is wildly
unstable going backward.
There's similar trouble with r, so the intermediate
results must be kept.

Note that n-1 in the program below plays the role of n+1 in the theory

D 3
Other boundary conditions_________________________
E 3
I 3
Other boundary conditions_________________________
E 3

The boundary conditions are easily generalized to handle

D 3
	y908" = ky918", y9n+18"   = ky9n8"
E 3
I 3
	y0" = ky1", yn+1"   = kyn"
E 3

for some constant k.  The above analysis was for k = 0;
k = 1 fits parabolas perfectly as well as stright lines;
k = 1/2 has been recommended as somehow pleasant.

D 3
All that is necessary is to add h918 to a918 and h9n+18 to a9n8.
E 3
I 3
All that is necessary is to add h1 to a1 and hn+1 to an.
E 3


D 3
Periodic case_____________
E 3
I 3
Periodic case_____________
E 3

To do this, add 1 more row and column thus

D 3
	| a918 h928            h918 |  |y918"|     |b918|
	| h928 a928 h938            |  |y928"|     |b928|
	|    h938 a948 h948         |  |y938"|     |b938|
E 3
I 3
	| a1 h2            h1 |  |y1"|     |b1|
	| h2 a2 h3            |  |y2"|     |b2|
	|    h3 a4 h4         |  |y3"|     |b3|
E 3
	|                     |  | .|  =  | .|
	|             .       |  | .|     | .|
D 3
	| h918            h908 a908 |  | .|     | .|
E 3
I 3
	| h1            h0 a0 |  | .|     | .|
E 3

D 3
where h908=_ h9n+18
E 3
I 3
where h0=_ hn+1
E 3

The same diagonalization procedure works, except for
D 3
the effect of the 2 corner elements.  Let s9i8 be the part
of the last element in the i8th9 "diagonalized" row that
E 3
I 3
the effect of the 2 corner elements.  Let si be the part
of the last element in the ith "diagonalized" row that
E 3
arises from the extra top corner element.

D 3
		s918 = h918
E 3
I 3
		s1 = h1
E 3

D 3
		s9i8 = -s9i-18h9i8/d9i-18	2<_i<_n+1
E 3
I 3
		si = -si-1hi/di-1	2<_i<_n+1
E 3

After "diagonalizing", the lower corner element remains.
D 3
Call t9i8 the bottom element that appears in the i8th9 colomn
E 3
I 3
Call ti the bottom element that appears in the ith colomn
E 3
as the bottom element to its left is eliminated

D 3
		t918 = h918
E 3
I 3
		t1 = h1
E 3

D 3
		t9i8 = -t9i-18h9i8/d9i-18
E 3
I 3
		ti = -ti-1hi/di-1
E 3

D 3
Evidently t9i8 = s9i8.
E 3
I 3
Evidently ti = si.
E 3
Elimination along the bottom row
introduces further corrections to the bottom right element
and to the last element of the right hand side.
Call these corrections u and v.

D 3
	u918 = v918 = 0
E 3
I 3
	u1 = v1 = 0
E 3

D 3
	u9i8 = u9i-18-s9i-18*t9i-18/d9i-18
E 3
I 3
	ui = ui-1-si-1*ti-1/di-1
E 3

D 3
	v9i8 = v9i-18-r9i-18*t9i-18/d9i-18	2<_i<_n+1
E 3
I 3
	vi = vi-1-ri-1*ti-1/di-1	2<_i<_n+1
E 3

The back solution is now obtained as follows

D 3
	y"9n+18 = (r9n+18+v9n+18)/(d9n+18+s9n+18+t9n+18+u9n+18)
E 3
I 3
	y"n+1 = (rn+1+vn+1)/(dn+1+sn+1+tn+1+un+1)
E 3

D 3
	y"9i8 = (r9i8-h9i+18*y9i+18-s9i8*y9n+18)/d9i8	1<_i<_n
E 3
I 3
	y"i = (ri-hi+1*yi+1-si*yn+1)/di	1<_i<_n
E 3

D 3
Interpolation in the interval x9i8<_x<_x9i+18 is by the formula
E 3
I 3
Interpolation in the interval xi<_x<_xi+1 is by the formula
E 3

D 3
	y = y9i8x9+8 + y9i+18x9-8 -(h8299i+18/6)[y"9i8(x9+8-x9+8839)+y"9i+18(x9-8-x9-8839)]
E 3
I 3
	y = yix+ + yi+1x- -(h2i+1/6)[y"i(x+-x+3)+y"i+1(x--x-3)]
E 3
where
D 3
	x9+8 = x9i+18-x
E 3
I 3
	x+ = xi+1-x
E 3

D 3
	x9-8 = x-x9i8
E 3
I 3
	x- = x-xi
E 3
*/

float
rhs(i){
	int i_;
	double zz;
	i_ = i==n-1?0:i;
	zz = (y.val[i]-y.val[i-1])/(x.val[i]-x.val[i-1]);
	return(6*((y.val[i_+1]-y.val[i_])/(x.val[i+1]-x.val[i]) - zz));
}

spline(){
	float d,s,u,v,hi,hi1;
	float h;
	float D2yi,D2yi1,D2yn1,x0,x1,yy,a;
	int end;
	float corr;
	int i,j,m;
	if(n<3) return(0);
	if(periodic) konst = 0;
	d = 1;
	r[0] = 0;
	s = periodic?-1:0;
	for(i=0;++i<n-!periodic;){	/* triangularize */
		hi = x.val[i]-x.val[i-1];
		hi1 = i==n-1?x.val[1]-x.val[0]:
			x.val[i+1]-x.val[i];
		if(hi1*hi<=0) return(0);
		u = i==1?zero:u-s*s/d;
		v = i==1?zero:v-s*r[i-1]/d;
		r[i] = rhs(i)-hi*r[i-1]/d;
		s = -hi*s/d;
		a = 2*(hi+hi1);
		if(i==1) a += konst*hi;
		if(i==n-2) a += konst*hi1;
		diag[i] = d = i==1? a:
		    a - hi*hi/d; 
		}
	D2yi = D2yn1 = 0;
	for(i=n-!periodic;--i>=0;){	/* back substitute */
		end = i==n-1;
		hi1 = end?x.val[1]-x.val[0]:
			x.val[i+1]-x.val[i];
		D2yi1 = D2yi;
		if(i>0){
			hi = x.val[i]-x.val[i-1];
			corr = end?2*s+u:zero;
			D2yi = (end*v+r[i]-hi1*D2yi1-s*D2yn1)/
				(diag[i]+corr);
			if(end) D2yn1 = D2yi;
			if(i>1){
				a = 2*(hi+hi1);
				if(i==1) a += konst*hi;
				if(i==n-2) a += konst*hi1;
				d = diag[i-1];
				s = -s*d/hi; 
			}}
		else D2yi = D2yn1;
		if(!periodic) {
			if(i==0) D2yi = konst*D2yi1;
			if(i==n-2) D2yi1 = konst*D2yi;
			}
		if(end) continue;
		m = hi1>0?ni:-ni;
		m = 1.001*m*hi1/(x.ub-x.lb);
		if(m<=0) m = 1;
		h = hi1/m;
		for(j=m;j>0||i==0&&j==0;j--){	/* interpolate */
			x0 = (m-j)*h/hi1;
			x1 = j*h/hi1;
			yy = D2yi*(x0-x0*x0*x0)+D2yi1*(x1-x1*x1*x1);
			yy = y.val[i]*x0+y.val[i+1]*x1 -hi1*hi1*yy/6;
			printf("%f ",x.val[i]+j*h);
			printf("%f\n",yy);
			}
		}
	return(1);
	}
readin() {
	for(n=0;n<NP;n++){
		if(auta) x.val[n] = n*dx+x.lb;
		else if(!getfloat(&x.val[n])) break;
		if(!getfloat(&y.val[n])) break; } }

getfloat(p)
	float *p;{
	char buf[30];
	register c;
	int i;
	extern double atof();
	for(;;){
		c = getchar();
		if (c==EOF) {
			*buf = '\0';
			return(0);
		}
		*buf = c;
		switch(*buf){
			case ' ':
			case '\t':
			case '\n':
				continue;}
		break;}
	for(i=1;i<30;i++){
		c = getchar();
		if (c==EOF) {
			buf[i] = '\0';
			break;
		}
		buf[i] = c;
		if('0'<=c && c<='9') continue;
		switch(c) {
			case '.':
			case '+':
			case '-':
			case 'E':
			case 'e':
				continue;}
		break; }
	buf[i] = ' ';
	*p = atof(buf);
	return(1); }

getlim(p)
	struct proj *p; {
	int i;
	for(i=0;i<n;i++) {
		if(!p->lbf && p->lb>(p->val[i])) p->lb = p->val[i];
		if(!p->ubf && p->ub<(p->val[i])) p->ub = p->val[i]; }
	}


main(argc,argv)
	char *argv[];{
	extern char *malloc();
	int i;
	x.lbf = x.ubf = y.lbf = y.ubf = 0;
	x.lb = INF;
	x.ub = -INF;
	y.lb = INF;
	y.ub = -INF;
	while(--argc > 0) {
		argv++;
again:		switch(argv[0][0]) {
		case '-':
			argv[0]++;
			goto again;
		case 'a':
			auta = 1;
			numb(&dx,&argc,&argv);
			break;
		case 'k':
			numb(&konst,&argc,&argv);
			break;
		case 'n':
			numb(&ni,&argc,&argv);
			break;
		case 'p':
			periodic = 1;
			break;
		case 'x':
			if(!numb(&x.lb,&argc,&argv)) break;
			x.lbf = 1;
			if(!numb(&x.ub,&argc,&argv)) break;
			x.ubf = 1;
			break;
		default:
			fprintf(stderr, "Bad agrument\n");
			exit(1);
		}
	}
	if(auta&&!x.lbf) x.lb = 0;
	readin();
	getlim(&x);
	getlim(&y);
	i = (n+1)*sizeof(dx);
	diag = (float *)malloc((unsigned)i);
	r = (float *)malloc((unsigned)i);
	if(r==NULL||!spline()) for(i=0;i<n;i++){
		printf("%f ",x.val[i]);
		printf("%f\n",y.val[i]); }
I 5
	exit(0);
E 5
}
numb(np,argcp,argvp)
	int *argcp;
	float *np;
	char ***argvp;{
	double atof();
	char c;
	if(*argcp<=1) return(0);
	c = (*argvp)[1][0];
	if(!('0'<=c&&c<='9' || c=='-' || c== '.' )) return(0);
	*np = atof((*argvp)[1]);
	(*argcp)--;
	(*argvp)++; 
	return(1); }
D 4

E 4
E 1
