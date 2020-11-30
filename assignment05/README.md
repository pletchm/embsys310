# EMBSYS 310 - AU20 Assignment 05
This is the directory containing my work for Assignment 05.

## Goal
1. To gain in depth understanding of the pass-by-value for function arguments in C.
2. To gain hands-on experience with the ARM Cortex-M4 assembly language.

## Problems: 

### 1. Swapping pointers.
_Create a function in C that allows swapping of two pointers._

Here is the code for this problem:
[SwapPointers/main.c](https://github.com/pletchm/embsys310/blob/main/assignment05/SwapPointers/main.c).

#### a. Explain what the main function does.
_Explain what the "main" function does in order to setup the input arguments prior to calling
the "swap_pointer" function._

Since the internals of the `swap` function actually were not altered at all, the main function,
needs to pass the address of the pointers and cast them integers-pointers (i.e., `int*`). The C code
below shows the function call.
```c
int x = 82;
int y = 14;
int* xPtr = &x;
int* yPtr = &y;
swap_pointer((int*) &xPtr, (int*) &yPtr);
```
**NOTE:**
Another way to do this (and the preferable way) would be to change the signature of the function
so that it takes pointers-to-pointers-to-integers, i.e., `int**`. Then function would look like

```c
void swap_pointer(int** a, int** b);
```
and woud be called like
```c
int 
swap_pointer(&xPtr, &yPtr);
```
This way no type-casting is needed. 

#### b. The "R0" and "R1" registers during the swap
_What are the values in "R0" and "R1" when "swap_pointer" is called?_

When the `swap_pointer` function is called, the register `R0` contains the first argument, the
address of the first pointer, and the register `R1` contains the second argument, the address
of the second pointer.
![registers_R0_and_R1_during](registers_R0_and_R1_during.PNG)

#### c. Screenshot of "Locals" View.
_Share a screenshot of the local variables inside of "main" after the function
"swap_pointer" returns showing the values of the pointers and what they are pointing to._

The image below shows the "Locals" view before the `swap_pointer` function is called.
![locals_before_swap](locals_before_swap.PNG)

The image below shows the "Locals" view after the `swap_pointer` function is called.
![locals_after_swap](locals_after_swap.PNG)


