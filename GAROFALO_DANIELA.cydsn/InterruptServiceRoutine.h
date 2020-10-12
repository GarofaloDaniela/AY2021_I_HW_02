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
    File InterruptServiceRoutine.h
    Function aimed to include the libraries needed to implement the ISR related to the hardware debouncer
    Author: Daniela Garofalo
*/

#ifndef _INTERRUPT_SERVICE_ROUTINE_H_ // Verifica se la dichiarazione è già stata eseguita una volta 
    #define _INTERRUPT_SERVICE_ROUTINE_H_
    
    #include <PushButton.h>
    
    CY_ISR_PROTO(custom_PushButton_ISR);
    
#endif

/* [] END OF FILE */
