shogi.o: shogi.c shogi.h macros.h
	gcc shogi.c -c
test01: test01.c shogi.o
	gcc test01.c shogi.o -o test01