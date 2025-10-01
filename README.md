# CMP_SC 3050 FS2025
## Assignment 3: Implement Hashing Algorithms

### **Description: Submit to Canvas**

You are to implement the functions that have been "stubbed out" in hash.c. Basically, you are to implement a hash table that just returns -1 (failure) when there is a collision (the function InsertFailCollision) and a hash table that uses chaining to always succeed even when there is a collision (the function InsertChain). You will also need to implement analogous search functions as well as hashing functions to perform the Division Method and Multiplication Method (all also stubbed out in hash.c). Notice that the insertion and searching functions need the hash function you are using as a parameter.

You are given a main() program, a Makefile, a library, and some starter code. All you need to do is complete the actual code for the functions in hash.c.

Notice that the main() program only tests the InsertFailCollision function with each of the two hashing functions and the InsertChain fuction with just the MultMethod hashing function.

### How to Get Started

The starter code is publicly available on GitHub. You can clone it using git via the following command:

git clone https://github.com/angrynarwhal/cs3050fs2025-lab-3 

I recommend you clone this code somewhere on your own computer, or on hellbender. You are welcome to clone this and work on your code on any platform you like. However, you should be aware that submissions will [[only]{.underline}]{.mark} be evaluated by the TAs in Canvas. If, for example, something works on your machine but doesn't compile for us, you will get a zero.

Once you have cloned the files, you should change directories to the newly cloned directory and type "make". This will build the code and leave you with two executable files called "myhash" and "jimrhash" respectively. The jimrhash program is an example of a completed program -- note that it uses the same main as your own "myhash" program but uses functions from the provided library rather than the functions you will implement in hash.c. This means that you can compare myhash and jimrhash to help you debug and understand things.

### Notes

You should not need to change any of the files except hash.c. When you have completed the assignment, submit only hash.c on Canvas. The TAs will clone fresh starter code and copy your hash.c file in order to evaluate it.

You will probably want to uncomment and possibly add code to print things out in main() while you are working on the assignment.
