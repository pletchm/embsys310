# EMBSYS 310 - AU20 Assignment 06
This is the directory containing my work for Assignment 06.

## Goal
1. Practice the use of **Cortex Microcontroller Software Interface Standard (CMSIS)**.
2. Gain more practice with the Cortex-M4 assembly language.

## Problems: 

### 1. Using CMSIS.
_Use the CMSIS to implement the code to blink the user **LED1** (PA5) on the STM32L475 board._

_Add the files `stm32l475xx.h` and `system_stm32l4xx.h` to the folder on your drive
where `main.c` is saved._

_Enable use of CMSIS in project options settings._

#### e. Toggle LED1.
_Implement toggling of LED1 using the CMSIS data structures._

#### Problem 1 Solution.
Here is the code for problem 1:
[UsingCMSIS/main.c](https://github.com/pletchm/embsys310/blob/main/assignment06/UsingCMSIS/Src/main.c)

### 2. Blinking LED in Assembly.
_Convert the blinking LED1 program into assembly code._

#### Problem 2 Solution.
Here is the code for problem 2:

* [BlinkyAsm/main.c](https://github.com/pletchm/embsys310/blob/main/assignment06/BlinkyAsm/main.c)
* [BlinkyAsm/user_led.s](https://github.com/pletchm/embsys310/blob/main/assignment06/BlinkyAsm/user_led.s)
* [BlinkyAsm/delay.s](https://github.com/pletchm/embsys310/blob/main/assignment06/BlinkyAsm/delay.s)

### 3. Bonus.
_Implement `enable_rcc` function in assembly inside the `rcc_ctrl.s` provided skeleton file.
Use the bit-band region to enable the clock associated with LED1 GPIOA. The function takes as
input the bit position for the corresponding GPIO bank._

#### Problem 3 Solution.
Here is the code for problem 3:

* [BlinkyAsm/rcc_ctrl.s](https://github.com/pletchm/embsys310/blob/main/assignment06/BlinkyAsm/rcc_ctrl.s)


