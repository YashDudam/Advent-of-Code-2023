CC = clang++
CFLAGS = -Wall -Werror -std=c++17

.PHONY: all
all: trebuchet

trebuchet: trebuchet.cpp
	$(CC) $(CFLAGS) -o trebuchet trebuchet.cpp

.PHONY: clean
clean:
	rm -f trebuchet
