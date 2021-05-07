Programa: programa1.o auxiliares.o alinhas.o estruturas.o readfiles.o menu.o
	gcc -o Programa programa1.o auxiliares.o alinhas.o estruturas.o readfiles.o menu.o

programa1.o: programa1.c auxiliares.h alinhas.h estruturas.h readfiles.h
	gcc -c programa1.c

auxiliares.o: auxiliares.c auxiliares.h
	gcc -c auxiliares.c

estruturas.o: estruturas.c estruturas.h
	gcc -c estruturas.c

alinhas.o: alinhas.c alinhas.h 
	gcc -c alinhas.c

readfiles.o: readfiles.c readfiles.h
	gcc -c readfiles.c

menu.o: menu.c menu.h alinhas.h
	gcc -c menu.c

clean:
	rm -rf *.o all

run:
	./Programa