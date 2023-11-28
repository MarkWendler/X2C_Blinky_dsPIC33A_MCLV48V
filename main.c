/*
 * File:   main.c
 * Author: I14883
 *
 * Created on March 2, 2023, 12:21 PM
 */


#include "xc.h"
#include "stdio.h"
#include "stdbool.h"
#include "hal/port_config.h"
#include "hal/timer1.h"
#include "hal/uart1.h"
#include "hal/pwm.h"
#include "hal/clock.h"
#include "hal/adc.h"
#include "foc/sineTable.h"
#include "foc/control.h"
#include "foc/estim.h"
#include "hal/measure.h"
#include "foc/park.h"
#include "foc/pi.h"
#include "foc/svgen.h"
#include "foc/userparms.h"
#include "foc/estim.h"

#include "Util.h"

#include "X2CCode/X2CUtils.h"
#include "X2CCode/X2CMain.h"
#include "X2CCode/X2C.h"

#define X2C_DATA __attribute__((section("x2cscope_data_buf")))
#define X2C_BAUDRATE_DIVIDER 54 /** 100M/(16*54) = 115.7 kbps */

void initPeripherals();

int main(void) 
{

    initPeripherals();
    X2C_Initialise();
    
   
    while(1)
    {
        X2C_Communicate();
        
//        if (SW2) {
//            LED2 = 0;
//        } else {
//            LED2 = 1;
//        }
    }
}

//10kHz Timer 1
void __attribute__((__interrupt__, no_auto_psv))_T1Interrupt(void){
    _T1IF = 0;
    TMR1_CallBack(); //X2CMain.c run model

}

int32_t pot = 0,ia = 0,ib = 0,offset_a = 2047,offset_b = 2047,ia1=0,ib1=0, adcDataBuffer ;

void __attribute__((__interrupt__, no_auto_psv))HAL_MC1ADCInterrupt(void)
{   

    ia = ADCBUF_IA ;
    ib = ADCBUF_IB ;
    
    pot = ADCBUF_POT;
    ia = (2048-ia);
    ia = ia<<4;
    
    ib = (2048-ib);
    ib = ib<<4;
    
    
    adcDataBuffer = AD1DATA0;
    HAL_MC1ADCInterruptFlagClear;
}

void initPeripherals(void){
    SetupGPIOPorts();
    InitClock();
    UART1_InterruptReceiveDisable();
    UART1_InterruptReceiveFlagClear();
    UART1_InterruptTransmitDisable();
    UART1_InterruptTransmitFlagClear();
    UART1_Initialize();
    UART1_BaudRateDividerSet(X2C_BAUDRATE_DIVIDER); 
    UART1_SpeedModeStandard();
    UART1_ModuleEnable();      
    
    TIMER1_Initialize();
    TIMER1_InputClockSet();
    TIMER1_PeriodSet(TIMER1_PERIOD_COUNT);
    TIMER1_InterruptPrioritySet(5);
    TIMER1_InterruptFlagClear();
    TIMER1_InterruptEnable(); 
    TIMER1_ModuleStart();
    Init_ADC();
    InitPWMGenerators();  
}
