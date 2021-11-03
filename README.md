# CS-5348-Operating-Systems

Project 1 

Large Scale Matrix Multiplication
 
These two programs solve the same problem: prog1.c is single threaded and prog2.c is multi-threaded. We would like to know the elapsed time (on the computer) for each of the two programs to run. 

A and B are two large matrices, which are 10000 by 10000 matrices. 

Matrice C = A x B. Note that C[i, j] = sum(A[i, k]*B[k,j]) for all k from 1 to 10000. 
 
Prog1.c will solve the matrix multiplication program using a single thread and prog2.c will solve the same problem using 25 threads with each thread computing 1/25 th of the elements of matrix C. In both cases, after computing one element of matrix C, have a delay of 10 microseconds. 
 
Matrices A and B are generated using independent random numbers in the range 1 to 2000. And the result produced by prog1 and prog2 are identical. 
 
Measure the time taken by each of the two programs and report the result. It can be as simple as capturing the dialogue using script as shown below: 
```sh  
date && prog1 
date && prog2 
date
```
