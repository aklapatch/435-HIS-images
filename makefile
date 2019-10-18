jpeglib:


all: main.c
	gcc -g -Og -lm main.c jpeg-9c/example.c jpeg-9c/.libs/libjpeg.a -o main

clean:
	rm -f main h_*.jpg i_*.jpg s_*.jpg
