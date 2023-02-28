CC = gcc
CC_FLAGS = -Wall -Wextra -std=c99 -O0 -g

capture: capture.o
	$(CC) capture.o -o capture

capture.o: capture.c
	$(CC) -c $(CC_FLAGS) capture.c -o capture.o

clean:
	rm -f capture capture.o *~
