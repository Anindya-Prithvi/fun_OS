CC="gcc"
CFLAGS="-masm=intel"

run_program: main SR ST
	@echo Running program!
	@./main

main: ST SR
	@$(CC) main.c -o main

ST:
	@$(CC) $(CFLAGS) ST.c -o ST

SR:
	@$(CC) $(CFLAGS) SR.c -o SR
	
clean:
	@rm -f main SR ST