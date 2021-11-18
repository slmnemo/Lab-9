// So my code looks less empty
// Using GPL license :0
// Please don't use this for E85.
// It's not good code.
// NL

// Includes EasyREDVIO.h to work with pins easier.

#include <stdint.h>
#include <math.h>
#include <EasyREDVIO.h>

// Structure to work with PWM memory map

typedef struct
{
    volatile uint32_t pwmcfg;       // (0x00) scales counter frequency
    volatile uint32_t reserved;     // (0x04) Reserved
    volatile uint32_t pwmcount;     // (0x08) No clue
    volatile uint32_t reserved2;    // (0x0C) Reserved
    volatile uint32_t pwms;    // (0x10) No clue
    volatile uint32_t reserved3;    // (0x14) Reserved
    volatile uint32_t reserved4;    // (0x18) Reserved
    volatile uint32_t reserved5;    // (0x1C) Reserved
    volatile uint32_t pwmcmp0;      // (0x20) pwm0 compare register
    volatile uint32_t pwmcmp1;      // (0x24) pwm1 compare register
    volatile uint32_t pwmcmp2;      // (0x28) pwm2 compare register
    volatile uint32_t pwmcmp3;      // (0x2C) pwm3 compare register
} PWM;

// Define the registers for PWM2_PWMCFG, PWM2_PWMCMP0, and PWM2_PWMCMP1.

#define PWM2_BASE   (0x10035000)
#define PWM2        ((PWM*)PWM2_BASE)

// Function to initialize pwm.

void pwmInit(void)
{
    PWM2->pwmcfg    &= 0x0;
    PWM2->pwmcfg    |= (1 << 12);
    PWM2->pwmcfg    |= (1 << 9);
    pinMode(11,GPIO_IOF1);
};

// Define pwmscale to be 8 because I do NOT want to die.

// Function to write a frequency to pwm by changing pwm

void pwm(int freq, float duty)
{
    int pwmscale = 8;
    PWM2->pwmcfg |= pwmscale;     // Writes pwmscale to pwmcfg
    double maxfreq = 1.6*pow(10, 7);
    float divisor = (pow(2, pwmscale));
    float scaledfreq = maxfreq/divisor;
    if (duty == 0)  {
        PWM2->pwmcmp0 = 1;
        PWM2->pwmcmp1 = 0;
    }
    
    else  {
        float period = ((float)scaledfreq/freq);
        PWM2->pwmcmp0 = (int)period;
        PWM2->pwmcmp1 = (int)(period*(1 - duty));
    }
};