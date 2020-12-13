/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function that swaps the values of two
                  char-variables.
*******************************************************************************/

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN PrintByte    // PrintByte is defined outside this file.
    
    PUBLIC swapCharsAsm       // Exports symbols to other modules
                              // Making swapCharsAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Swaps the values of two variables of type char.
C Prototype     : int swapCharsAsm(char* char1, char* char2)
                : Where char1 and char2 point to the characters to swap.
Parameters      : R0: The first character of the two to swap.
                  R1: The second character of the two to swap.
Return value    : 0 if the two chars are identical; otherwise, return 1.
*******************************************************************************/  
  
swapCharsAsm    
    LDRB R2,[R0]  // Read a byte value from address in R0 and store it in R2.
    LDRB R3,[R1]  // Read a byte value from address in R1 and store it in R3.
    STRB R3,[R0]  // Store byte value in R3 at address in R0.
    STRB R2,[R1]  // Store byte value in R2 at address in R1.
    
    MOV R0,#0     // Store the return value in R0. Initialize it to 0.
    CMP R2,R3     // Compare the two characters.
    IT EQ         // Start Equals conditional.
        MOVEQ R0,#1  // Return value is 1, if the two characters are equal.

    BX LR         // return (with function result in R0)

    END