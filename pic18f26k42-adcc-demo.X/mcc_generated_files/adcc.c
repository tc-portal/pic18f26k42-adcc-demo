/**
  ADCC Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adcc.c

  @Summary
    This is the generated driver implementation file for the ADCC driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides implementations for driver APIs for ADCC.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F26K42
        Driver Version    :  2.1.4
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB             :  MPLAB X 5.20
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 

    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "adcc.h"
#include <stdlib.h>
#include "uart1.h"

void (*ADCC_ADTI_InterruptHandler)(void);

/**
  Section: ADCC Module APIs
*/

void ADCC_Init_AVG_Mode(void)
{ 
    ADLTHL = 0x70;                                                              // Lower threshold set to -400 diff from setpoint 
    ADLTHH = 0xFE;                                                               
    ADUTHL = 0x90;                                                              // Upper threshold set to +400 diff from setpoint
    ADUTHH = 0x01;
    ADSTPTL = 0xFF;                                                             // Setpoint set to 2047 
    ADSTPTH = 0x07;                                                             
    ADACCU = 0x00;     
    ADRPT = 0x04;                                                               // RPT 4; 
    ADPCH = 0x00;                                                               // PCH ANA0;
    ADACQL = 0xC8;
    ADACQH = 0x00; 
    ADCAP = 0x00;                                                               // CAP Additional uC disabled;
    ADPREL = 0x00;
    ADPREH = 0x00;  
    ADCON1 = 0x00;                                                              // DSEN disabled; 
    ADCON2 = 0x22;                                                              // CRS 2; MD Average_mode; PSIS FLTR;  
    ADCON3 = 0x13;                                                              // CALC Actual vs setpoint; TMD ADERR > ADLTH and ADERR < ADUTH;
    ADSTAT = 0x00; 
    ADREF = 0x00;                                                               // NREF VSS; PREF VDD; 
    ADACT = 0x00;                                                               // ACT disabled; 
    ADCLK = 0x03;                                                               // ADCS FOSC/8;  
    ADCON0 = 0x84;                                                              // GO stop; FM right; ON enabled; CS ADCRC;
    
    PIR1bits.ADTIF = 0;
    PIE1bits.ADTIE = 1;                                                         // Enable Threshold interrupts

    ADCC_SetADTIInterruptHandler(ADCC_DefaultInterruptHandler);
}

void ADCC_Init_BurstAverage_Mode()
{      
    ADCON1 = 0x00;                                                              // DSEN disabled;
    ADCON2 = 0x23;                                                              // CRS 2; MD Burst Average_mode; PSIS ADFLTR;   
    ADCON3 = 0x13;                                                              // CALC Actual vs setpoint; ADTMD ADERR > ADLTH and ADERR < ADUTH; 
    ADACT = 0x00;                                                               // ACT disabled; 
    ADSTAT = 0x00;                                                              // AOV ACC or ERR not Overflowed;
    ADCLK = 0x03;                                                               // CS FOSC/16;  
    ADREF = 0x00;                                                               // NREF VSS; ADPREF VDD; 
    ADCAP = 0x00;                                                               // CAP Additional uC disabled;
    ADPRE = 0x00; 
    ADACQL = 0xC8;
    ADACQH = 0x00;                                                              // 10; 
    ADPCH = 0x00;                                                               // PCH ANA0 - Pot input; 
    ADRPT = 0x04; 
    ADLTHL = 0x70;                                                              // Lower threshold set to -400 diff from setpoint 
    ADLTHH = 0xFE;                                                               
    ADUTHL = 0x90;                                                              // Upper threshold set to +400 diff from setpoint
    ADUTHH = 0x01; 
    ADSTPTL = 0xFF;                                                             // Setpoint set to 2047
    ADSTPTH = 0x07;                                                              
    ADCON0 = 0x84;
    PIR1bits.ADTIF = 0;
    PIE1bits.ADTIE = 1;

    ADCC_SetADTIInterruptHandler(ADCC_DefaultInterruptHandler);   
}

void ADCC_Init_Basic_Mode(void)
{  
    ADCON1 = 0x00;                                                              // DSEN disabled;     
    ADCON2 = 0x20;                                                              // ADCRS 2; MD Basic_mode; PSIS ADFLTR;      
    ADCON3 = 0x07;                                                              // CALC First derivative of Single measurement; TMD enabled;
    ADACT = 0x00; 
    ADSTAT = 0x00; 
    ADCLK = 0x03;                                                               // CS FOSC/8; 
    ADREF = 0x00;                                                               // NREF VSS; PREF VDD;     
    ADCAP = 0x00;                                                               // CAP Additional uC disabled; 
    ADPRE = 0x00; 
    ADACQL = 0xC8;
    ADACQH = 0x00;     
    ADPCH = 0x00;                                                               // PCH ANA0; 
    ADRPT = 0x04; 
    ADLTHL = 0x70;                                                              // Lower threshold set to -400 diff from setpoint (not used in basic) 
    ADLTHH = 0xFE;                                                                   
    ADUTHL = 0x90;                                                              // Upper threshold set to +400 diff from setpoint 
    ADUTHH = 0x01;     
    ADSTPTL = 0xFF;                                                             // Setpoint set to 2047     
    ADSTPTH = 0x07;                                                              
     
    ADCON0 = 0x84;                                                              // GO stop; FM right; ON enabled;  CS FRC;
    PIR1bits.ADTIF = 0;
    PIE1bits.ADTIE = 1;

    ADCC_SetADTIInterruptHandler(ADCC_DefaultInterruptHandler);
}

void ADCC_Init_LPF_Mode(void)
{
    ADCON1 = 0x00;
    ADCON2 = 0x14;
    ADCON3 = 0x57;
    ADREF = 0x00;
    ADACQL = 0x14;
    ADACQH = 0x00; 
    ADPCH = 0x01;
    
    ADCON2bits.CRS = 1;                                                         // Change this for -3dB cut-off
    ADRPT = 2;                                                                  // Should always be 2^CRS
    ADCLK = 0x03;                                                               
    ADCON0 = 0x84;
    PIR1bits.ADTIF = 0;
    PIE1bits.ADTIE = 1;    
}

adc_result_t ADCC_GetSingleConversion(adcc_channel_t channel)
{
    ADPCH = channel;                                                            // Select the A/D channel
    ADCON0bits.ADON = 1;                                                        // Turn on the ADC module
    ADCON0bits.ADCONT = 0;                                                      // Disable the continuous mode.
    ADCON0bits.ADGO = 1;                                                        // Start the conversion

    while (ADCON0bits.ADGO)                                                     // Wait for the conversion to finish
    {
    }
    return ((adc_result_t)((ADRESH << 8) + ADRESL));                            // Conversion finished, return the result
}

uint16_t ADCC_GetFilterValue(void)
{
    return ((uint16_t)((ADFLTRH << 8) + ADFLTRL));                              // Return the contents of ADFLTRH and ADFLTRL registers
}

uint16_t ADCC_GetPreviousResult(void)
{
    return ((uint16_t)((ADPREVH << 8) + ADPREVL));                              // Return the contents of ADPREVH and ADPREVL registers
}

void ADCC_ThresholdISR(void)
{
    PIR1bits.ADTIF = 0;                                                         // Clear the ADCC Threshold interrupt flag
    if(count == 2)                                                              // Basic mode
    {
        printf ("ADRES = %d Filter not used No Threshold Set\r\n", ADRES);
    }

    if(count == 0)                                                              // Average mode
    {
        printf ("ADRES = %d - within threshold limits\r\n", ADRES);
    }
    if(count == 1)                                                              // Burst Average mode
    {
        printf ("ADRES = %d - within threshold limits\r\n", ADRES);    
    }
    if(count == 3)                                                              // This routine is for LPF mode 
    {
        UART1_Write(0x03);                                                      // These are commands sent to the Data Visualizer, 0x03 = Start                                              
        UART1_Write(ADFLTRL);                                                   // Visualizer reads low byte first
        UART1_Write(ADFLTRH);                                                   // Then reads the high byte
        UART1_Write(0xFC);                                                      // Stop command  
    }
    if (ADCC_ADTI_InterruptHandler)
        ADCC_ADTI_InterruptHandler();
}

void ADCC_SetADTIInterruptHandler(void (* InterruptHandler)(void))
{
    ADCC_ADTI_InterruptHandler = InterruptHandler;
}
void ADCC_DefaultInterruptHandler(void)
{
}





/**
 End of File
*/
