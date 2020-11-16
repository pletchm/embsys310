/* Small embedded program, that uses the International Morse Code and the user
 * LED (i.e., LED1 and LED2) to present my first name on a B-L475E-IOT01A1
 * (i.e., STM32L475VG) evaluation board.
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
#define ORD5 (1<<5) // i.e., 0x5

// LED 2 General Input/Ouput Port Registers:
#define GPIOB_BASE 0x48000400 // Base Address for GPIOB registers.
// Port B Mode register -- I/Os are configured in alternate function mode
// through this register.
#define GPIOB_MODER ( *((unsigned int*)(GPIOB_BASE + GPIO_MODER_OFFSET)) )
// Port B Ouptut Data register --
#define GPIOB_ODR ( *((unsigned int*) (GPIOB_BASE + GPIO_ODR_OFFSET)) )
#define ORD14 (1<<14) // i.e., 0x4000

#define DOT_DURATION  (unsigned long long) 200000
#define DASH_DURATION (unsigned long long) 3 * DOT_DURATION

volatile unsigned int counter = 0;

void init_user_LED();
void turn_on_user_LED();
void turn_off_user_LED();
void write_pause(unsigned int factor);
void write_dot();
void write_dash();
void write_M();
void write_A();
void write_R();
void write_T();
void write_Y();

int main()
{   
    init_user_LED();
    while (1) {
        write_M();
        write_A();
        write_R();
        write_T();
        write_Y();
        write_pause(4); // 7 units between words -- already 3 in letter function
    }
}

void write_pause(unsigned int factor)
{
    counter = 0;
    while (counter < (DOT_DURATION * factor) ) {
        counter++;
    }
}

void write_dot()
{
    turn_on_user_LED();
    counter = 0;
    while (counter < DOT_DURATION) {
        counter++;
    }
    turn_off_user_LED();
    write_pause(1);
}

void write_dash()
{
    turn_on_user_LED();
    counter = 0;
    while (counter < DASH_DURATION) {
        counter++;
    }
    turn_off_user_LED();
    write_pause(1);
}

void write_M()
{
    // The Letter M: dash, dash
    write_dash();
    write_dash();
    write_pause(2); // 3 units between letters -- already 1 in dash function.
}

void write_A()
{
    // The Letter A: dot, dash
    write_dot();
    write_dash();
    write_pause(2); // 3 units between letters -- already 1 in dash function.
}
    
void write_R()
{
    // The Letter R: dot, dash, dot
    write_dot();
    write_dash();
    write_dot();
    write_pause(2); // 3 units between letters -- already 1 in dash function.    
}

void write_T()
{
    // The Letter T: dash
    write_dash();
    write_pause(2); // 3 units between letters -- already 1 in dash function.    
}

void write_Y()
{
    // The Letter Y: dash, dot, dash, dash
    write_dash();
    write_dot();
    write_dash();
    write_dash();
    write_pause(2); // 3 units between letters -- already 1 in dash function.    
}

void init_user_LED()
{
    // Set bit[0] and bit[1] to enable I/O port A and port B clocks.
    RCC_AHB2ENR |= 0x3;
    // Clear bit[11] and set bit[10] --> enable PB5 GPIO as output mode.
    // Note: bits[11:10] is for Mode 5, and we want to set them to "01" for
    // General Purpose Output Mode.
    GPIOA_MODER &= 0xFFFFF7FF;
    // Clear bit[29] and set bit[28] --> enable PB14 GPIO as output mode.
    // Note: bits[29:28] is for Mode 14, and we want to set them to "01" for
    // General Purpose Output Mode.
    GPIOB_MODER &= 0xDFFFFFFF;
}

void turn_on_user_LED()
{
    // Set bit[5] = 1 --> Turn on LED1.
    GPIOA_ODR |= ORD5;
    // Set bit[14] = 1 --> Turn on LED2.
    GPIOB_ODR |= ORD14;
}

void turn_off_user_LED()
{
    // Set bit[5] = 0 --> Turn off LED1. 
    GPIOA_ODR &= ~ORD5;
    // Set bit[14] = 0 --> Turn off LED2. 
    GPIOB_ODR &= ~ORD14; // Set to 0
}
