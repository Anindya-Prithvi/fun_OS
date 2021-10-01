# the compiler: gcc for C program
CC = gcc
 
# compiler flags:
CFLAGS  = -O2 -w -g
 
# The build target 
default_builder:
	@echo -n "making ."
	@$(CC) $(CFLAGS) sorts.c -o sorts.out
	@echo -n .
	@echo "done!"

exes:
	@echo -n "making ."
	@$(CC) $(CFLAGS) sorts.c -o sorts.exe
	@echo .
	@echo "done!"
	
clean:
	@rm -rf *.out
	@rm -rf *.exe