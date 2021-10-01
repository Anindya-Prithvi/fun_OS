### Done as understood
> run make command first
> `make exes` maybe used incase the checker is a windows host
> `make clean` will clean all the exes/out(s) present in the directory.

Q1. Write the `cp’ program that takes arguments as source and destination filenames and copies the source to the destination. (use fread and fwrite).

A1. This program taken a total of 2 arguments, the first being the source and second being the destination. It also has minor error handling like invalid args, inoperable destination/source. The idea is to open the source and destination and read, write respectively. Then read a single byte (char) and write to the other file. This will continue till fread returns 1 (i.e. successfully read), otherwise it stops and closes the files. If the operation is a success it also prints an ascii emoji.
___

Q2. Store a 256-bit unsigned integer number on a 32 byte character array. Add two such 256-bit numbers.

A2. Run the c256int.exe OR c256int.out file (whichever compiled by make->gcc). Enter a 256 bit number as a decimal value. Enter the second number. Both the numbers are added and saved in the variable `thesum`. The output is printed as well. The idea is to take in the decimal, convert it to binary by the traditional division and modulo and then sum it (manually). The overflow is always detected and reported.
___

Q3. Write a C program to Swap elements of two variables and two arrays.

A3. Run the swapping.exe/out . The variables are hardcoded. The integer swapper takes in the memory addr of the variable and creates a temporary variable to store the value stored in any one addr then proceeds to exchange it. The array swapper just calls the previous _swapper_ n times (where n is the size of the array).
___

Q4. Write a program to reverse a string.

A4. Run reverstring.out/exe . Program takes in input till newline(\n) and just writes in the reverse order in a new array + suffixes \0. Finally printf is called with %s and the string is printed.
___

Q5. Write a program with a function that performs binary search. Assume unsigned integers, and the following
elements are present: 4294967290, 4294967295, 10400.

A5. Run binsearch.exe/out . The array is hardcoded and sorted using qsort. You may modify the array in the source file, it'll sort it correctly (given the input is correct, ofc). The binsearch function takes in the array (which is just the memory addr) and the endpoints along with the element to search (it is set as 10400). If it is found "FOUND" is printed and the program waits for input before exiting (getchar).