zero(p,n) register char *p; register int n;{
char *op=p; while (--n>=0) *p++=0;
return(op);
}
