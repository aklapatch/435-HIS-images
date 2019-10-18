all:
	gcc -g -Og -lm main.c jpeg-9c/example.c jpeg-9c/.libs/libjpeg.a -o main.out
