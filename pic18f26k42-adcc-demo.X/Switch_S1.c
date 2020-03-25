/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    Switch_S1.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65
        Device            :  PIC18F26K42
        Driver Version    :  2.00
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
#include "Switch_S1.h"

void ToggleSwitch(void) 
{  
    if (buttonPressed == 1)                                                     // Was switch S1 pressed to change modes?
    {
        switch(count) 
        {
            case 1:
                LED_D2_Toggle();                                                // Turn on LED D2 to show change in mode
                LED_D3_LAT = 0;                                                 // Turn off LED D3 
                ADCC_Init_BurstAverage_Mode();                                  // Configure ADCC for Burst Average mode
                break;
            case 2:
                LED_D3_Toggle();                                                // Turn on LED D3 to show change in mode
                LED_D2_LAT = 0;                                                 // Turn off LED D2
                ADCC_Init_Basic_Mode();                                         // Configure ADCC for Basic mode
                break;
            case 3:
                LED_D2_LAT = 1;                                                 // Turn on both LEDs for LPF mode
                LED_D3_LAT = 1;
                ADCC_Init_LPF_Mode();                                           // Configure ADCC for LPF mode
                break;
            default:
                LED_D2_LAT = 0;                                                 // Both LEDs should be off by default
                LED_D3_LAT = 0;
                count = 0;                                                      // Ensure count is back to zero
                ADCC_Init_AVG_Mode();                                           // Configure ADCC for Average mode
                break;
        }
        buttonPressed = 0;                                                      // Clear the button flag
    }   
}
