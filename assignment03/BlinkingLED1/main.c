
/* Embedded program for STM32L475VG evaluation board that blinks LED1.
 * 
 * It is written by manipulating hardcoded register addresses.
 */

/*
 */
#define RCC_BASE 0x40021000 // Base Address for RCC registers
/* Peripheral clock gating is controlled by the RCC_AHBxENR and RCC_APBxENR
 * registers. AHB2 is attached to the bus that the GPIO registers are attached
 * to.
 */
#define 

#define GPIOA_BASE 0x48000000 // Base address for GPIOA registers.
#define GPIOB_BASE 0x48000400 // Base Address for GPIOB registers.

int main()
{
  
  return 0;
}
