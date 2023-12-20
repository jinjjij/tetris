

CC = g++
CFLAGS = -Wall -std=c++11

all : app

app : bin/main.o lib/graphics.o
	$(CC) $(CFLAGS) $^ -o $@

bin/main.o : bin/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

lib/graphics.o : lib/graphics.cpp lib/graphics.h
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f bin/*.o lib/*.o app