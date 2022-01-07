CC=gcc

default-builder: M1 M2 C
	@echo "launch executables manually"
	@echo "use --> ./M1 for first program with 1 fork usage"
	@echo "use --> ./M2 for second program with 2 fork usage"
	@echo "use --> ./C for classical deadlock"


M1: diningphil1fork4sauce.c
	gcc diningphil1fork4sauce.c -o M1 -pthread

M2: diningphil2fork4sauce.c
	gcc diningphil2fork4sauce.c -o M2 -pthread

C: diningphilclassical.c
	gcc diningphilclassical.c -o C -pthread

clean:
	rm -f M2 M1 C
	