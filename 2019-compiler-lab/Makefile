all: minipy
lex.yy.c:minipy-lab.l
	lex minipy-lab.l
y.tab.c:lex.yy.c y.tab.h minipy-lab.y
	yacc minipy-lab.y
minipy:y.tab.c
	g++ y.tab.c
