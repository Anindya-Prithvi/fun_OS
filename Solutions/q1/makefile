# the compiler: gcc for C program
CC = gcc
 
# compiler flags: varies everytime
CFLAGS  = 
 
# The build target 
default_builder: a1 a2
	@echo "running ..."
	@echo
	@echo "Launching ./a1"
	@./a1
	@echo
	@echo "Launching ./a2"
	@./a2

a1: a1.c
	@echo "Compiling for a1.c started"
	@echo "Producing preprocessor output :"
	
	@$(CC) -E -o a1.e a1.c
	@echo Output written to a1.e
	@echo "Producing Assembly output :"
	
	@$(CC) -S -o a1.s a1.c
	@echo Output written to a1.s
	@echo "Producing object code :"
	
	@$(CC) -c a1.c
	@echo Output written to a1.o
	@echo "Producing linked executable :"
	
	@$(CC) -o a1 a1.c
	@echo Output written to a1
	@echo "done!"

a2: a2.c
	@echo "Compiling for a2.c started"
	@echo -n "Producing preprocessor output :"
	
	@$(CC) -E -pthread -o a2.e a2.c -v
	@echo Output written to a2.e
	@echo -n "Producing Assembly output :"
	
	@$(CC) -S -pthread -o a2.s a2.c
	@echo Output written to a2.s
	@echo -n "Producing object code :"
	
	@$(CC) -c -pthread a2.c
	@echo Output written to a2.o
	@echo -n "Producing linked executable :"
	
	@$(CC) -pthread -o a2 a2.c
	@echo Output written to a2
	@echo "done!"
	
clean:
	@rm -rf *.o *.s *.e
	@rm -f a1
	@rm -f a2
