LEX=flex
YACC=yacc
CC=gcc
OBJECT=main
YFILE=mc.y
LFILE=mc.l

$(OBJECT):lex.yy.o y.tab.o  
	$(CC) lex.yy.o y.tab.o -o $(OBJECT)

lex.yy.o: lex.yy.c y.tab.h
	$(CC) -c lex.yy.c

y.tab.o: y.tab.c
	$(CC) -c y.tab.c

y.tab.c y.tab.h:$(YFILE)
	$(YACC) -v -d $(YFILE)

lex.yy.c: $(LFILE)
	$(LEX) $(LFILE)

clean:
	rm -f $(OBJECT) *.o *.c y.tab.h
