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
    File InterruptServiceRoutine.c
    Function aimed to update the state of the device as a function of the output of the hardware debouncer connected to the switch
    Author: Daniela Garofalo
*/

# include <InterruptServiceRoutine.h>

# define BUTTON_PRESSED 0
int stato;

CY_ISR(custom_PushButton_ISR)
{
    if (PushButton_Read() == BUTTON_PRESSED)
    {
        stato++;
        if (stato > 7)
        {
            stato = 1;
        }
    }
}

/* [] END OF FILE */
