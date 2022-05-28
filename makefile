CC = gcc
LD = gcc
CCFLAGS = -g -Wall -std=c99
LDFLAGS =
OBJ = main.o vector.o queue.o deque.o list.o stack.o sorting.o
HDR = vector.h queue.h deque.h list.h sorting.h stack.h

main.o: main.c $(HDR)
	@$(CC) $(CCFLAGS) -c main.c
stack.o: stack.c stack.h
	@$(CC) $(CCFLAGS) -c stack.c
sorting.o: sorting.h sorting.c
	@$(CC) $(CCFLAGS) -c sorting.c
vector.o: vector.c vector.h
	@$(CC) $(CCFLAGS) -c vector.c
queue.o: queue.c queue.h
	@$(CC) $(CCFLAGS) -c queue.c
deque.o: deque.c deque.c
	@$(CC) $(CCFLAGS) -c deque.c
list.o: list.c list.h
	@$(CC) $(CCFLAGS) -c list.c
clean:
	@rm -f *.o main
