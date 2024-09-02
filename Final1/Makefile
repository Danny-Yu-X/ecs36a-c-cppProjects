paint.out: main.o backend.o userInput.o paint.o
	gcc -g -Wall -Werror -o paint.out main.o backend.o userInput.o paint.o
main.o: main.c backend.h userInput.h
	gcc -g -Wall -Werror -c main.c
backend.o: backend.c backend.h
	gcc -g -Wall -Werror -c backend.c
userInput.o: userInput.c userInput.h backend.h paint.h
	gcc -g -Wall -Werror -c userInput.c
paint.o: paint.c paint.h backend.h
	gcc -g -Wall -Werror -c paint.c
clean:
	rm -fr *.o*.out
run: paint.out
	./paint.out
debug: paint.out
	gdb --tui paint.out