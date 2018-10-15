.PHONY: clean

stat : stat.o
	gcc -o stat $^ 
stat.o : stat.c
	gcc -c $^ -o stat.o -w
clean:
	rm stat stat.o
