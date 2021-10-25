CC = gcc
 
# compiler flags: varies everytime
CFLAGS = -no-pie
 
# The build target 
default_builder: b
	@echo "running ... "
	@echo
	@echo "Launching ./b"
	@rm -rf *.o
	@echo "--------------"
	@./b

b: mainA.o B.o C.o
	@$(CC) $(CFLAGS) -o b mainA.o B.o C.o

mainA.o:
	@$(CC) -c mainA.c

B.o:
	@nasm -f elf64 B.asm

C.o:
	@$(CC) -c -masm=intel C.c

clean:
	@rm -f b
	@rm -rf *.o
