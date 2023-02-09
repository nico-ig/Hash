CC = gcc
CFLAGS = -g -Wall -std=c99

myht: *.o
	$(CC) *.o -o myht -lm 

*.o: *.c
	$(CC) $(CFLAGS) -c *.c

clean:
	rm -rf *.o vgcore* teste?.out

purge: clean
	rm -rf myht
