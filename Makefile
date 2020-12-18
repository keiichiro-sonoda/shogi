mixed01.o: mixed01.c mixed01.h
	gcc mixed01.c -c -Wall
shogi.o: shogi.c shogi.h
	gcc shogi.c -c -Wall
test01: test01.c shogi.o mixed01.o
	gcc test01.c shogi.o mixed01.o -o test01 -Wall