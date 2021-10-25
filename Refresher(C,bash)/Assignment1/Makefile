# the compiler: gcc for C program
CC = gcc
 
# compiler flags:
CFLAGS  = -O2 -w -g
 
# The build target 
default_builder: 
	@echo -n "making ."
	@$(CC) $(CFLAGS) cp.c -o cp.out
	@echo -n .
	@$(CC) $(CFLAGS) c256int.c -o c256int.out
	@echo -n .
	@$(CC) $(CFLAGS) binsearch.c -o binsearch.out
	@echo -n .
	@$(CC) $(CFLAGS) swapping.c -o swapping.out
	@echo .
	@$(CC) $(CFLAGS) reversestring.c -o reversestring.out
	@echo "done!"

exes: 
	@echo -n "making ."
	@$(CC) $(CFLAGS) cp.c -o cp.exe
	@echo -n .
	@$(CC) $(CFLAGS) c256int.c -o c256int.exe
	@echo -n .
	@$(CC) $(CFLAGS) binsearch.c -o binsearch.exe
	@echo -n .
	@$(CC) $(CFLAGS) swapping.c -o swapping.exe
	@echo .
	@$(CC) $(CFLAGS) reversestring.c -o reversestring.exe
	@echo "done!"
	
clean:
	@rm -rf *.out
	@rm -rf *.exe