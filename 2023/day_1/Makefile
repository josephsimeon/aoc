
COMMON_DIR = ../../common

puzzle_output: main.o day_1.o puzzle.o
	gcc main.o day_1.o puzzle.o -o puzzle_output

main.o: main.c
	gcc -c main.c

day_1.o: day_1.c day_1.h
	gcc -c day_1.c

puzzle.o: $(COMMON_DIR)/puzzle.c $(COMMON_DIR)/puzzle.h
	gcc -c $(COMMON_DIR)/puzzle.c

clean:
	rm *.o puzzle_output
