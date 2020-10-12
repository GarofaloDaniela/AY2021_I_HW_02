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
    File RGBLedDriver.c
    Function aimed to define the PWM configurations as a function of the state of the device
    Author: Daniela Garofalo
*/
#include <RGBLedDriver.h>

void RGBLedDriver(int period, double RED_dc, double GREEN_dc, int RED_pos, int GREEN_pos)
{
    PWM_1_WritePeriod(period);
    if (RED_pos > 0) // The first edge in the red LED behaviour is positive (switch on)
    {
        PWM_1_SetCompareMode1(PWM_1__B_PWM__LESS_THAN);
        PWM_1_WriteCompare1(period*RED_dc);
    } else {  // The first edge in the red LED behaviour is negative (switch off)
        PWM_1_SetCompareMode1(PWM_1__B_PWM__GREATER_THAN);
        PWM_1_WriteCompare1(period*(1 - RED_dc));
    }
    if (GREEN_pos > 0) // The first edge in the green LED behaviour is positive (switch on)
    {
        PWM_1_SetCompareMode2(PWM_1__B_PWM__LESS_THAN);
        PWM_1_WriteCompare2(period*GREEN_dc);
    } else {  // The first edge in the green LED behaviour is negative (switch off)
        PWM_1_SetCompareMode2(PWM_1__B_PWM__GREATER_THAN);
        PWM_1_WriteCompare2(period*(1 - GREEN_dc));
    }
}

/* [] END OF FILE */
