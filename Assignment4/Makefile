CC=gcc

default_builder: P1 P2
	@echo "Running P1 and P2 for eternity"
	@./P1 &
	@sleep 1
	@./P2 

P1: P1.c
	gcc P1.c -o P1

P2: P2.c
	gcc P2.c -o P2

clean:
	rm P1 P2
