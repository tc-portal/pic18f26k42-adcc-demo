/**
  ADCC Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    adcc.h

  @Summary
    This is the generated header file for the ADCC driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  @Description
    This header file provides APIs for driver for ADCC.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65
        Device            :  PIC18F26K42
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.10
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

#ifndef _ADCC_H
#define _ADCC_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Data Types Definitions
*/

/**
 *  result size of an A/D conversion
 */

typedef uint16_t adc_result_t;
#ifndef uint24_t
typedef __uint24 uint24_t;
#endif
uint8_t count = 0, buttonPressed = 0;
/** ADC Channel Definition

 @Summary
   Defines the channels available for conversion.

 @Description
   This routine defines the channels that are available for the module to use.

 Remarks:
   None
 */

typedef enum
{
    POT_INPUT =  0x0,
    LPF_INPUT = 0x01,
    channel_VSS =  0x3B,
    channel_Temp =  0x3C,
    channel_DAC1 =  0x3D,
    channel_FVR_Buffer1 =  0x3E,
    channel_FVR_Buffer2 =  0x3F
} adcc_channel_t;

/**
  Section: ADC Module APIs
*/

/**
  @Summary
    Initializes the ADCC

  @Description
    This routine initializes the Initializes the ADCC.
    This routine must be called before any other ADCC routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    uint16_t convertedValue;    

    ADCC_Initialize();
    convertedValue = ADCC_GetSingleConversion(AN1_Channel);
    </code>
*/
void ADCC_Init_AVG_Mode(void);

/**
  @Summary
    Returns the ADCC conversion value
    also allows selection of a channel for conversion.

  @Description
    This routine is used to select desired channel for conversion
    and to get the analog to digital converted value after a single conversion.

  @Preconditions
    ADCC_Initialize() and ADCC_DisableContinuousConversion() functions should have been called before calling this function.

  @Returns
    Returns the converted value.

  @Param
    Pass in required channel number.
    "For available channel refer to enum under adcc.h file"

  @Example
    <code>
    uint16_t convertedValue;

    ADCC_Initialize();
    ADCC_DisableContinuousConversion();
	
    convertedValue = ADCC_GetSingleConversion(AN1_Channel);
    </code>
*/
adc_result_t ADCC_GetSingleConversion(adcc_channel_t channel);



/**
  @Summary
   Returns the contents of ADFLTRH and ADFLTRL registers.

  @Description
    None

  @Preconditions
    None.

  @Returns
    16 bit value obtained from ADFLTRH and ADFLTRL registers.

  @Param
    None.

  @Example
    <code>
	uint16_t filterValue = ADCC_GetFilterValue();
	
    </code>
*/
uint16_t ADCC_GetFilterValue(void);

/**
  @Summary
   Returns the contents of ADPREVH and ADPREVL registers.

  @Description
    None

  @Preconditions
    None.

  @Returns
    16 bit value obtained from ADPREVH and ADPREVL registers.

  @Param
    None.

  @Example
    <code>
	uint16_t prevResult = ADCC_GetPreviousResult();
	
    </code>
*/
uint16_t ADCC_GetPreviousResult(void);

/**
  @Summary
    Implements ISR

  @Description
    This routine is used to set the callback for the ADTI Interrupt.

  @Returns
    None

  @Param
    Callback Function to be called
*/
void ADCC_SetADTIInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Implements ISR

  @Description
    This routine is used to implement the ISR for the interrupt-driven
    implementations.

  @Returns
    None

  @Param
    None
*/
void ADCC_ThresholdISR(void);

/**
  @Summary
    Default ADCC Interrupt Handler

  @Description
    This is the default Interrupt Handler function

  @Preconditions
    Initialize  the ADCC module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
void ADCC_DefaultInterruptHandler(void);
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
    
void ADCC_Init_BurstAverage_Mode(void);
void ADCC_Init_Basic_Mode(void);
void ADCC_Init_LPF_Mode(void);

#endif	//_ADCC_H
/**
 End of File
*/

