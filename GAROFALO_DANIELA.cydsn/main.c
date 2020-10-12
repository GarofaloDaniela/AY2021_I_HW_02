/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/*
    File main.c
    Function aimed to call the functions necessary to switch the LED in function of the state of the device
    Author: Daniela Garofalo
*/
    
#include "project.h"
#include <InterruptServiceRoutine.h>
#include <RGBLedDriver.h>

#define PERIOD_2S 60000 
#define PERIOD_1S 30000
#define PERIOD_500MS 15000
// Starting values to configure the initial value from which the counter starts in order to create the PWM square wave

extern int stato; // Creation of a global variable that is updated by the ISR
void RGBLedDriver(int period, double RED_dc, double GREEN_dc, int RED_pos, int GREEN_pos); // Declaration of the function 

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_1_Start(); // Start the PWM
    isr_1_StartEx(custom_PushButton_ISR); // Enable the local interrupt linked to hardware debouncer
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    stato = 1; // Initialisation of the state at the power-up of the device
    int red7high = -1; /* Initialisation of a variable that takes into account of the different blinking period
    associated to the red channel with respect to the green one in the state 7: when red7high < 0 the output
    signal will switch off the LED, while when red7high > 0 the output signal will switch on the LED */
    
    for(;;)
    {
        /* Place your application code here. */
        switch (stato)
        {
            case 1:
            {
                RGBLedDriver(PERIOD_2S, 1, 1, 1, 1);
                break;
            }
            case 2:
            {
                RGBLedDriver(PERIOD_2S, 1, 0.5, 1, 1);
                break;
            }
            case 3:
            {
                RGBLedDriver(PERIOD_2S, 0.5, 1, -1, 1);
                break;
            }
            case 4:
            {
                RGBLedDriver(PERIOD_1S, 0.5, 0.5, 1, -1);
                break;
            }
            case 5:
            {
                RGBLedDriver(PERIOD_500MS, 0.5, 0.5, -1, 1);
                break;
            }
            case 6:
            {
                RGBLedDriver(PERIOD_2S, 0.75, 0.5, 1, 1);
                break;
            }
            case 7:
            {
                RGBLedDriver(PERIOD_1S, 1, 0.5, red7high, 1);
                while(PWM_1_ReadCounter() > 0); // Waiting until the counter arrives to zero: equivalent to one period
                red7high = -1*red7high; // After one period of 1s, the signal associated to the red LED changes its edge
                break;
            }
        }
    }
}

/* [] END OF FILE */
