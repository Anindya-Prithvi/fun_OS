### Done as understood
> run make command first
> `make exes` maybe used incase the checker is a windows host
> `make clean` will clean all the exes/out(s) present in the directory.

Q1.

1. Write a C program to create a 6 row, variable column matrix.
2. Allow the user to change the number of columns in each row. You may populate each cell by a random number between 1 and 10.

A1.

1. Run matrixita.exe/out (whichever compiled by makefile->gcc). Since the no. of columns in each row were given an array has been created to store the values. Malloc has been used with appropriate size to return a pointer to the allocated space. The program by default prints the created matrix using the row number eg.
```
1 1 1 1 1 1 1
2 2 2 2
3 3 3 3 3 3
4 4
```
but the concerned may add a gdb watch as well.

2. Run matrixitb.exe/out . Here the no. of columns in each row must be given (in the console) and it will be stored in an array. Malloc has been used with appropriate size to return a pointer to the allocated space (as requested by the user). The program by default prints the created matrix using the row number eg.
```
1 1 1 1 1 1 1
2 2 2 2
3 3 3 3 3 3
4 4
```
but the concerned may add a gdb watch as well.
___

Q2.

1. Write a C program to implement a singly linked list. The list should store student records i.e. -- name, rollno., year of joining and enrolled academic program.
2. Reimplement (a) but with a doubly linked list. 
3. Implement stack and queue using linked list.

A2.

1. Run singlyll.exe/out. However it is recommended to check the source file for the implementation. I have implemented function to find, traverse, insert, delete, and show. The structure is named student which has a pointer named next which is basically equivalent to the next node in an SLL. Other functions are trivial and standard, the code is self explanatory.

2. Run doublyll.exe/out. Same instructions as above. Only that now there is also a prev pointer which points to the student right before.

3. Run stacksll.exe/out , queues.exe/out. Both function just pop and push equivalents and are implemented using the singly linked list style (i.e. not creating an array but pointers.) Memory is freed whenever deletion occurs.
___

Q3. Create an array of (void * -type) pointers of length 5. Each of these pointers should be pointing to individual functions that perform operations like addition, subtraction, division, multiplication, exponentiation. 

A3. Run functionptr.exe/out. Pretty straight forward, see the code. It is far less complicated than a stack and nonsensical to not have a value returned from the function. a void array is created for the purpose.
__

Q4. Write a C program such that there are the three following functions, viz. -- A(), B() and C(). The function A() should at some point call function B(). However, you need to design B (i.e. manipulate its stack), so that B() doesn’t return back to A(). The return; operation from B() should invoke the execution of function C().

A4. As of now it works on my system (32 bit mode). Use and run the `no_ret_function.EXP` included in the file (and hope it works). What it does: A() calls the function B. An array of size 1 is declared in B. Using objdump -D it was found that the 6th index (array[6]) contains the return address. Since C allows us to change these values, I proceed and modify it to the memory address of function C(). This way when return of B is invoked, the program starts executing C. Now C lacks a return address so the memory address of A after the function call of B (is obtained using objdump) and written using the same method. This completes the function and has been tested on my system.
___

Q5. [Bubble sort and selection sort] Write a program in C which has two functions bubble sort and selection sort. These functions both take an array as input, and depending on user’s choice given on the console input, the corresponding function is used.

A5. Run sorts.out/exe. It will ask for the numbers to sort and the method to use...easy. The sorts are inplace and uses the swapping function made in Assignment 1. The algorithm is standard.