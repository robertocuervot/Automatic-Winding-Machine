/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set DOUT aliases
#define DOUT_TRIS                 TRISAbits.TRISA0
#define DOUT_LAT                  LATAbits.LATA0
#define DOUT_PORT                 PORTAbits.RA0
#define DOUT_WPU                  WPUAbits.WPUA0
#define DOUT_OD                   ODCONAbits.ODCA0
#define DOUT_ANS                  ANSELAbits.ANSELA0
#define DOUT_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define DOUT_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define DOUT_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define DOUT_GetValue()           PORTAbits.RA0
#define DOUT_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define DOUT_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define DOUT_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define DOUT_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define DOUT_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define DOUT_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define DOUT_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define DOUT_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSELA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set STEP1 aliases
#define STEP1_TRIS                 TRISDbits.TRISD0
#define STEP1_LAT                  LATDbits.LATD0
#define STEP1_PORT                 PORTDbits.RD0
#define STEP1_WPU                  WPUDbits.WPUD0
#define STEP1_OD                   ODCONDbits.ODCD0
#define STEP1_ANS                  ANSELDbits.ANSELD0
#define STEP1_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define STEP1_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define STEP1_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define STEP1_GetValue()           PORTDbits.RD0
#define STEP1_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define STEP1_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define STEP1_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define STEP1_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define STEP1_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define STEP1_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define STEP1_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define STEP1_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set STEP2 aliases
#define STEP2_TRIS                 TRISDbits.TRISD1
#define STEP2_LAT                  LATDbits.LATD1
#define STEP2_PORT                 PORTDbits.RD1
#define STEP2_WPU                  WPUDbits.WPUD1
#define STEP2_OD                   ODCONDbits.ODCD1
#define STEP2_ANS                  ANSELDbits.ANSELD1
#define STEP2_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define STEP2_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define STEP2_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define STEP2_GetValue()           PORTDbits.RD1
#define STEP2_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define STEP2_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define STEP2_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define STEP2_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define STEP2_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define STEP2_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define STEP2_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define STEP2_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set DIR1 aliases
#define DIR1_TRIS                 TRISDbits.TRISD2
#define DIR1_LAT                  LATDbits.LATD2
#define DIR1_PORT                 PORTDbits.RD2
#define DIR1_WPU                  WPUDbits.WPUD2
#define DIR1_OD                   ODCONDbits.ODCD2
#define DIR1_ANS                  ANSELDbits.ANSELD2
#define DIR1_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define DIR1_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define DIR1_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define DIR1_GetValue()           PORTDbits.RD2
#define DIR1_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define DIR1_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define DIR1_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define DIR1_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define DIR1_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define DIR1_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define DIR1_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define DIR1_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set DIR2 aliases
#define DIR2_TRIS                 TRISDbits.TRISD3
#define DIR2_LAT                  LATDbits.LATD3
#define DIR2_PORT                 PORTDbits.RD3
#define DIR2_WPU                  WPUDbits.WPUD3
#define DIR2_OD                   ODCONDbits.ODCD3
#define DIR2_ANS                  ANSELDbits.ANSELD3
#define DIR2_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define DIR2_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define DIR2_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define DIR2_GetValue()           PORTDbits.RD3
#define DIR2_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define DIR2_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define DIR2_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define DIR2_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define DIR2_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define DIR2_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define DIR2_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define DIR2_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set FC_A aliases
#define FC_A_TRIS                 TRISDbits.TRISD4
#define FC_A_LAT                  LATDbits.LATD4
#define FC_A_PORT                 PORTDbits.RD4
#define FC_A_WPU                  WPUDbits.WPUD4
#define FC_A_OD                   ODCONDbits.ODCD4
#define FC_A_ANS                  ANSELDbits.ANSELD4
#define FC_A_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define FC_A_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define FC_A_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define FC_A_GetValue()           PORTDbits.RD4
#define FC_A_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define FC_A_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define FC_A_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define FC_A_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define FC_A_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define FC_A_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define FC_A_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define FC_A_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set FC_B aliases
#define FC_B_TRIS                 TRISDbits.TRISD5
#define FC_B_LAT                  LATDbits.LATD5
#define FC_B_PORT                 PORTDbits.RD5
#define FC_B_WPU                  WPUDbits.WPUD5
#define FC_B_OD                   ODCONDbits.ODCD5
#define FC_B_ANS                  ANSELDbits.ANSELD5
#define FC_B_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define FC_B_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define FC_B_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define FC_B_GetValue()           PORTDbits.RD5
#define FC_B_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define FC_B_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define FC_B_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define FC_B_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define FC_B_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define FC_B_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define FC_B_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define FC_B_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set PULS aliases
#define PULS_TRIS                 TRISDbits.TRISD6
#define PULS_LAT                  LATDbits.LATD6
#define PULS_PORT                 PORTDbits.RD6
#define PULS_WPU                  WPUDbits.WPUD6
#define PULS_OD                   ODCONDbits.ODCD6
#define PULS_ANS                  ANSELDbits.ANSELD6
#define PULS_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define PULS_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define PULS_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define PULS_GetValue()           PORTDbits.RD6
#define PULS_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define PULS_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define PULS_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define PULS_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define PULS_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define PULS_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define PULS_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define PULS_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set SCK aliases
#define SCK_TRIS                 TRISDbits.TRISD7
#define SCK_LAT                  LATDbits.LATD7
#define SCK_PORT                 PORTDbits.RD7
#define SCK_WPU                  WPUDbits.WPUD7
#define SCK_OD                   ODCONDbits.ODCD7
#define SCK_ANS                  ANSELDbits.ANSELD7
#define SCK_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define SCK_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define SCK_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define SCK_GetValue()           PORTDbits.RD7
#define SCK_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define SCK_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define SCK_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define SCK_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define SCK_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define SCK_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define SCK_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/