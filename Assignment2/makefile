# the compiler: gcc for C program
CC = gcc
 
# compiler flags:
CFLAGS  = -O2 -w -g
 
# The build target 
default_builder:
	@echo -n "making ."
	@$(CC) $(CFLAGS) doublyll.c -o doublyll.out
	@echo -n .
	@$(CC) $(CFLAGS) functionptr.c -o functionptr.out
	@echo -n .
	@$(CC) $(CFLAGS) matrixita.c -o matrixita.out
	@echo -n .
	@$(CC) $(CFLAGS) matrixitb.c -o matrixitb.out
	@echo -n .
	@$(CC) $(CFLAGS) queues.c -o queues.out
	@echo -n .
	@$(CC) $(CFLAGS) singlyll.c -o singlyll.out
	@echo -n .
	@$(CC) $(CFLAGS) sorts.c -o sorts.out
	@echo -n .
	@$(CC) $(CFLAGS) stacksll.c -o stacksll.out
	@echo -n .
	@$(CC) $(CFLAGS) no_ret_function.c -o no_ret_function.out
	@echo "done!"

exes:
	@echo -n "making ."
	@$(CC) $(CFLAGS) doublyll.c -o doublyll.exe
	@echo -n .
	@$(CC) $(CFLAGS) functionptr.c -o functionptr.exe
	@echo -n .
	@$(CC) $(CFLAGS) matrixita.c -o matrixita.exe
	@echo -n .
	@$(CC) $(CFLAGS) matrixitb.c -o matrixitb.exe
	@echo -n .
	@$(CC) $(CFLAGS) queues.c -o queues.exe
	@echo -n .
	@$(CC) $(CFLAGS) singlyll.c -o singlyll.exe
	@echo -n .
	@$(CC) $(CFLAGS) sorts.c -o sorts.exe
	@echo -n .
	@$(CC) $(CFLAGS) stacksll.c -o stacksll.exe
	@echo -n .
	@$(CC) $(CFLAGS) no_ret_function.c -o no_ret_function.exe
	@echo "done!"

# the last one may fail, but that isnt part of assnm anymore lol
clean:
	@rm -rf *.out
	@rm -rf *.exe