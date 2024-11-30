CFLAGS = -Wall -Wextra -Wswitch-enum -std=c11 -pedantic
LIBS =
.PHONY: all 
all: ebasm ami
ebasm: ./src/ebasm.c ./src/am.c
	$(CC) $(CFLAGS) -o ebasm ./src/ebasm.c $(LIB)
ami: ./src/ami.c ./src/am.c
	$(CC) $(CFLAGS) -o ami ./src/ami.c $(LIB)

.PHONY: examples
examples: ./examples/fib.am ./examples/123.am

./examples/fib.am: ./examples/fib.ebasm
	./ebasm ./examples/fib.ebasm ./examples/fib.am
./examples/123.am: ./examples/123.ebasm
	./ebasm ./examples/123.ebasm ./examples/123.am