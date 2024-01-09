CC = clang++
CFLAGS = -Wall -Werror

.PHONY: all
all: gear-ratio

gear-ratio: gear-ratio.cpp
	$(CC) $(CFLAGS) -o gear-ratio gear-ratio.cpp

.PHONY: clean
clean:
	rm -f gear-ratio
