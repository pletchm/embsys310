
/* Embedded program for STM32L475VG evaluation board that blinks LED1.
 * 
 * It is written by manipulating hardcoded register addresses and bit-banding.
 */

#define PERIPHERAL_BIT_BAND_ALIAS 0x42000000
#define RCC_AHB2ENR_OFFSET 0x2104C

// Common GPIO offsets and reset values:
#define GPIO_MODER_OFFSET 0x00
#define GPIO_ODR_OFFSET 0x14

// LED 1 General Input/Ouput Port Registers:
#define GPIOA_BASE 0x48000000 // Base address for GPIOA registers.
// Port A Mode register -- 
#define GPIOA_MODER ( *((unsigned int*)(GPIOA_BASE + GPIO_MODER_OFFSET)) )
// Port A Output register -- 
#define GPIOA_ODR ( *((unsigned int*) (GPIOA_BASE + GPIO_ODR_OFFSET)) )

// LED 2 General Input/Ouput Port Registers:
#define GPIOB_BASE 0x48000400 // Base Address for GPIOB registers.
// Port B Mode register -- I/Os are configured in alternate function mode
// through this register.
#define GPIOB_MODER ( *((unsigned int*)(GPIOB_BASE + GPIO_MODER_OFFSET)) )
// Port B Ouptut Data register --
#define GPIOB_ODR ( *((unsigned int*) (GPIOB_BASE + GPIO_ODR_OFFSET)) )

#define ORD5 (1<<5) // i.e., 0x5
#define ORD14 (1<<14) // i.e., 0x4000

volatile unsigned int counter = 0;

int main()
{   
    // Set bit[0] to enable I/O port A clock.
    *((unsigned int*)(PERIPHERAL_BIT_BAND_ALIAS + (RCC_AHB2ENR_OFFSET * 32) + (0 * 4))) = 1;
    
    // Clear bit[11] and set bit[10] --> enable PB5 GPIO as output mode.
    // Note: bits[11:10] is for Mode 5, and we want to set them to "01" for
    // General Purpose Output Mode.
    GPIOA_MODER &= 0xFFFFF7FF;
    
    while (1) {
        while (counter < 100000) {
            counter++;
        }

        // Set bit[5] = 1 --> Turn on LED1.
        GPIOA_ODR |= ORD5;
        
        counter = 0;
        while (counter < 1000) {
            counter++;
        }

        // Set bit[5] = 0 --> Turn off LED1. 
        GPIOA_ODR &= ~ORD5;
    }
}
