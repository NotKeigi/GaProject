CC = gcc
ga: main.o ga.o day_sycle.o
	$(CC) -Wall -o covid main.o ga.o day_sycle.o
main.o: main.c
	$(CC) -c main.c
ga.o: ga.c
	$(CC) -c ga.c
day_sycle.o: day_sycle.c
	$(CC) -c day_sycle.c
clean:
	rm  covid day_sycle.o ga.o main.o