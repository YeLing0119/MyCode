main : add.o sub.o mul.o main.o
	gcc add.o sub.o mul.o main.o -o main 

add.o : add.c
	gcc -c add.c -o add.o -I ../include

mul.o : mul.c
	gcc -c mul.c -o mul.o -I ../include

sub.o : sub.c
	gcc -c sub.c -o sub.o -I ../include

main.o : main.c
	gcc -c main.c -o main.o -I ../include
