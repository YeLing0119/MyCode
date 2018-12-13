.PHONY : main

main : ProgressBar.o
	gcc $^ -o $@

%.o : %.c
	gcc -c $< -o $@

clean : 
	rm *.o main
