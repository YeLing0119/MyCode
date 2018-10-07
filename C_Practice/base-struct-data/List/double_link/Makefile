.PHONY : main clean all

CC=gcc
CFLAGS=-Wall -g
OBJS=main.o double_link.o
TARGETS=main test

all : main

main : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean :
	rm *.o main
