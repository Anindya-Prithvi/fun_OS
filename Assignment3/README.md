### Done as understood
> run make command first
> `make exes` maybe used incase the checker is a windows host
> `make clean` will clean all the exes/out(s) present in the directory.

Q1. Write a bash script to print the calendar for the entire month, given a date.

A1. Either export the path of this directory in your path variable or run it directly. chmod 777 was already granted. May reduce permission levels as per discretion. The script strictly takes command line arguments and raises appropriate error messages. Pass the month and year --> `cal.sh May 2001` This shall print the calendar of the month May 2001. I have specifically not included the day since that would be useless information (i.e. why would you need a day to print the calendar of the that month -).

Q2. Write a bash script that takes two arguments as command-line arguments for the above arithmetic operations (add, sub, mul, div and exp). The first argument should be the name of the operations, ie. -- ‘add’, ‘sub’, ‘div’, and ‘exp’. The subsequent arguments should be two (or more) operands. Thus, depending upon the operations requested, you may call the appropriate function (bash subroutine), which should perform the corresponding arithmetic operation, using the supplied arguments. 

A2. Either export the path of this directory in your path variable or run it directly. chmod 777 was already granted. May reduce permission levels as per discretion. The script strictly takes command line arguments and raises errors (including invalid options given). To use, just run `calc.sh --add 500 29 4853 343`. Also it is assumed that _non commutative_ functions will have the arguments from [2:end] summed up. That is say `calc.sh --exp 30 20 20 400` has been used, then it will be equivalent to `calc.sh --exp 30 440`.

> It is presumed that `calc.sh: command not found` or `cal.sh: command not found` can be resolved by the checker. If not, prefix `./` to those commands.

Q3.

a. Implement the insertion and deletion operations in a binary search tree in C. 
b. Implement a height-balanced binary search tree.

[Skipped] Hardly contributes to learning. Not a course on DSA. 4 similar programs have already been submitted in Assignment 2.

Q4. [Bubble sort and selection sort] Write a program in C which has two functions bubble sort and selection sort. These functions both take an array as input, and depending on user’s choice given on the console input, the corresponding function is used.

[Copy paste Assignment 2?] A4. Run sorts.out/exe. It will ask for the numbers to sort and the method to use...easy. The sorts are inplace and uses the swapping function made in Assignment 1. The algorithm is standard.
