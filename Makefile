mixed01.o: mixed01.c mixed01.h
	mixed01.c -c -Wall
shogi.o: shogi.c shogi.h
	gcc shogi.c mixed01 -o -c -Wall
test01: test01.c shogi.o
	gcc test01.c shogi.o -o test01 -Wall