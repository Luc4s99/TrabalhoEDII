main:	main.o	TADGrafo.o
	gcc main.o	TADGrafo.o -o	main.exe
	rm *.o
main.o:	main.c
	gcc -c main.c
TADGrafo.o:	TADGrafo.c	TADGrafo.h
	gcc -c TADGrafo.c
