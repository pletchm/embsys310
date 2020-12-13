/* Embedded program for STM32L475VG evaluation board that blinks LED1.
 *
 * It is written by manipulating members of CMSIS data structures.
 */
#include <stdint.h>
#include "system_stm32l4xx.h"
#include "stm32l475xx.h"

void delay(unsigned int iteration);

int main()
{
    // Reset and Clock Control (RCC) registers are used for clock gating.
    // Peripheral clock gating is controlled by the RCC_AHBxENR and RCC_APBxENR
    // registers. In this case, the Advanced High speed Bus #2(AHB2) is attached
    // to the bus that the GPIO registers are attached to.
    
    // Enable the I/O clock to the peripheral (port A).
    // RCC AHB2 Peripheral clock enable register (RECC_AHB2ENR)
    // Set bit[1] to 1
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // Enable PA5 as output.
    // Clear bit[11] and set bit[10] --> enable PB5 GPIO as output mode.
    // Note: bits[11:10] is for Mode 5, and we want to set them to "01" for
    // General Purpose Output Mode.
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    while (1) {
        // Set bit[5] = 1 --> Turn on LED1.
        // Set bit[5] = 0 --> Turn off LED1.
        GPIOA->ODR ^= GPIO_ODR_OD5;  // Use XOR operator to flip the bit[5]
        delay(100000);
    }
}

void delay(unsigned int iteration)
{
    while (iteration > 0)
    {
        iteration--;    
    }
}
