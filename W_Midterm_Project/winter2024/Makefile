connectn.out: board.o input_validation.o main.o  play_game.o setup.o winning.o 
	gcc -g -Wall -Werror -o connectn.out board.o input_validation.o main.o  play_game.o setup.o winning.o
board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c 
input_validation.o: input_validation.c input_validation.h
	gcc -g -Wall -Werror -c input_validation.c
main.o: main.c setup.h play_game.h
	gcc -g -Wall -Werror -c main.c
play_game.o: play_game.c board.h play_game.h winning.h input_validation.h
	gcc -g -Wall -Werror -c play_game.c
setup.o: setup.c setup.h input_validation.h board.h
	gcc -g -Wall -Werror -c setup.c
winning.o: winning.c winning.h board.h
	gcc -g -Wall -Werror -c winning.c
clean: 
	rm *.out *.o 

debug: connectn.out
	gdb --tui connectn.out 

run: connectn.out
	./connectn.out 