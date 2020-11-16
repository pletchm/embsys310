
/* Embedded program for STM32L475VG evaluation board that blinks LED1.
 * 
 * It is written by manipulating hardcoded register addresses.
 */

// Reset and Clock Control (RCC) registers are used for clock gating.
#define RCC_BASE 0x40021000 // Base Address for RCC registers
// Peripheral clock gating is controlled by the RCC_AHBxENR and RCC_APBxENR
// registers. In this case, the Advanced High speed Bus #2(AHB2) is attached to
// the bus that the GPIO registers are attached to.
#define RCC_AHB2ENR ( *((unsigned int*)(RCC_BASE + 0x4C)) )

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
    RCC_AHB2ENR |= 0x1;
    /* NOTE: To flash LED1 and LED2, we'll need to enable both the I/O port A
    and I/O port B clocks. Instead use 0x3*/
    
    /* UNCOMMENT FOR LED2:
    // Clear bit[29] and set bit[28] --> enable PB14 GPIO as output mode.
    // Note: bits[29:28] is for Mode 14, and we want to set them to "01" for
    // General Purpose Output Mode.
    GPIOB_MODER &= 0xDFFFFFFF;
    */

    // Clear bit[11] and set bit[10] --> enable PB5 GPIO as output mode.
    // Note: bits[11:10] is for Mode 5, and we want to set them to "01" for
    // General Purpose Output Mode.
    GPIOA_MODER &= 0xFFFFF7FF;
    
    while (1) {
        while (counter < 100000) {
            counter++;
        }
        
        /* UNCOMMENT FOR LED2: 
        // Set bit[14] = 1 --> Turn on LED2.
        GPIOB_ODR |= ORD14;
        */

        // Set bit[5] = 1 --> Turn on LED1.
        GPIOA_ODR |= ORD5;
        
        counter = 0;
        while (counter < 1000) {
            counter++;
        }
        
        /* UNCOMMENT FOR LED2: 
        // Set bit[14] = 0 --> Turn off LED2. 
        GPIOB_ODR &= ~ORD14; // Set to 0
        */

        // Set bit[5] = 0 --> Turn off LED1. 
        GPIOA_ODR &= ~ORD5;
    }
}
