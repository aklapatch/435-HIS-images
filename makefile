thisproj: main.c jpeglib
	gcc -g -Og -lm main.c example.c jpeg-9c/.libs/libjpeg.a -o main

jpeglib: jpeg-9c/configure
	chmod +x jpeg-9c/configure
	cd ./jpeg-9c/; test -f config.status || sh ./configure; make 


clean: cleanjpg
	rm -f i_*.jpg h_*.jpg s_*.jpg main *raw

cleanjpg:
	cd jpeg-9c/; make clean
