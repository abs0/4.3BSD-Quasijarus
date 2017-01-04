all:	Clang.ps

Clang.ps: Clang.t cmac1 tpwbmm.m
	tbl Clang.t | pstroff -fR,I,B,BI,S,C,CO > $@

clean:
	rm -f *.ps errs core
