# EMBSYS 310 - AU20 Assignment 03
This is the directory containing my work for Assignment 03.

TODO: ![1_locals_view](1_locals_view.PNG)

## Goal
1. Become familiar with C programming language's pre-processor, volatile directive,    and how GPIOs work.
2. Explore using the STM32MXCube too to generate code for the evaluation board.

## Problems:
1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible
   rate.
2. Use XOR bit-wise operator to toggle the LED. **See the program for proplems _1_ and _2_ here:**
   [BlinkingLED1/main.c](https://github.com/pletchm/embsys310/blob/main/assignment03/BlinkingLED1/main.c).
3. Morse Code is considered a sequence of binaries.
   a. Morse code is a method for encoding text as sequences of two different values. Historically, these
      values were dots and dashes, but they can be represented through other media like light or sound.
      Using light or sound the distinction between a dot and a dash is based on the duration of the signal
      -- a dash is 3 times longer than a dot, where the duration of the dot is established as the basic
      unit of measurment for Morse code communication.
   b. Samuel Morse invented Morse code, who also contributed to the invention of telegraph.
4. Using the International Code, write a program to present your first name with Morse Code using the user
   LED your B-L475E-IOT01A1 evaluation board. **MP4 video file posted on Canvas. See the program here:**
   [MorseCode/main.c](https://github.com/pletchm/embsys310/blob/main/assignment03/MorseCode/main.c).
