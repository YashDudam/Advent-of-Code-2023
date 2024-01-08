CC = clang++
CFLAGS = -Wall -Werror -std=c++17

.PHONY: all
all: cube-conundrum

cube-conundrum: cube-conundrum.cpp Game.o
	$(CC) $(CFLAGS) -o cube-conundrum cube-conundrum.cpp Game.o

Game.o: Game.cpp Game.hpp
	$(CC) $(CFLAGS) -c -o Game.o Game.cpp


.PHONY: clean
clean:
	rm -f *.o cube-conundrum
