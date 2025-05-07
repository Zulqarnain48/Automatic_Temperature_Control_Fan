#include <reg51.h>   // Include header file for 8051 microcontroller
#include <stdio.h>   // Include standard I/O header (optional here, not used in this code)

// Define switch inputs connected to Port 1
sbit s0 = P1^0;  // Switch 0
sbit s1 = P1^1;  // Switch 1
sbit s2 = P1^2;  // Switch 2
sbit s3 = P1^3;  // Switch 3
sbit s4 = P1^4;  // Switch 4
sbit s5 = P1^5;  // Switch 5

// Define fan output connected to Port 2, Pin 0
sbit fan = P2^0;

// Function prototype for delay
void msdelay(unsigned int time);

// Main program starts here
void main() 
{ 
    while (1)  // Infinite loop
    {
        // If switch s0 is pressed (LOW), turn fan OFF
        if (s0 == 0)
            fan = 0;

        // If switch s1 is pressed, fan ON for 2ms, OFF for 8ms (slowest speed)
        if (s1 == 0) {
            fan = 0;
            msdelay(8);  // OFF delay
            fan = 1;
            msdelay(2);  // ON delay
        }

        // If switch s2 is pressed, fan ON for 4ms, OFF for 6ms
        if (s2 == 0) {
            fan = 0;
            msdelay(6);
            fan = 1;
            msdelay(4);
        }

        // If switch s3 is pressed, fan ON for 6ms, OFF for 4ms
        if (s3 == 0) {
            fan = 0;
            msdelay(4);
            fan = 1;
            msdelay(6);
        }

        // If switch s4 is pressed, fan ON for 8ms, OFF for 2ms (faster speed)
        if (s4 == 0) {
            fan = 0;
            msdelay(2);
            fan = 1;
            msdelay(8);
        }

        // If switch s5 is pressed, fan stays fully ON
        if (s5 == 0)
            fan = 1;

        // If no switch is pressed, fan remains OFF
        else
            fan = 0;
    }
}

// Delay function (~1 ms per unit at 12 MHz clock)
void msdelay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 113; j++);  // Loop to create delay
}
