# EMBSYS 310 - AU20 Assignment 04
This is the directory containing my work for Assignment 04.

## Goal
1. Practice the use of bit-banding region.
2. Examine the assembly code generated for a function with multiple parameters.
3. Practice API design, testing, etc.
4. Apply usage of pointers and Endianness.

## Problems:
1. Blink LED1 (PA5) at a visible rate using the bit-band region to enable the clock to port A. 
   See the code here [BitBanding/main.c](https://github.com/pletchm/embsys310/blob/main/assignment04/BitBanding/main.c).

    a. What instructions does the compiler produce in assembly for "writing" to the GPIO bit
       when using bit-band adress?
       **Three assembly instructions:**
       ```assembly
       MOVS    R0, #1
       LDR.N   R1, [PC, #0x48]
       STR     R0, [R1]
       ```
    
    b. What were the instructions produced when writing to the GPIOx_ODR without using bit-banding.
       ****
       ```assembly

       LDR.N   R0, [PC, #0x4c]
       LDR     R1, [R0]
       ORRS.W  R1, R1, #1
       STR     R1, [R0]
       ```

