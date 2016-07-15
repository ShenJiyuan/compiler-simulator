scs: lex.yy.o yaccc.tab.o
	gcc lex.yy.o yaccc.tab.o -o scs
yaccc.tab.o: yaccc.tab.c 
	gcc -c yaccc.tab.c
lex.yy.o: lex.yy.c yaccc.tab.h
	gcc -c lex.yy.c
yaccc.tab.c yaccc.tab.h : yaccc.y
	bison -d yaccc.y
lex.yy.c: lexxx.l
	lex lexxx.l
clean:
	rm lex.* yaccc.tab.* scs

