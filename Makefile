shogi.o: shogi.c shogi.h macros01.h
	gcc shogi.c -c -Wall
test01: test01.c shogi.o
	gcc test01.c shogi.o -o test01 -Wall