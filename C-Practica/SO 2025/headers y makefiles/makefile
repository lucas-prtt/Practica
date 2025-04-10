
ejecutable: main.o funciones.o
	gcc main.o funciones.o -o "ejecutable"

main.o: main.c
	gcc -c main.c
	echo "MAIN!!!"

funciones.o: funciones.c
	gcc -c funciones.c 
	echo "FUNCIONES???"

,PHONY: clean
clean:
	rm -rf *.o