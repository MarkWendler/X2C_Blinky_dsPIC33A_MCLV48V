/* ************************************************************************** */
/** X2CMain.c

  @Company
    Microchip Technology

  @Summary
 Implementation of X2C In and Outport connections

 */
/* ************************************************************************** */
#include <xc.h>
#include "X2CMain.h"

#include "X2C.h"
#include "../hal/port_config.h"
#include "../hal/timer1.h"

#ifndef X2C_H
#warning "Please generate the code from the model!"
#endif

extern int32_t pot,ia,ib,offset_a,offset_b,ia1,ib1, adcDataBuffer;

uint32_t cpuLoadBegin, cpuLoadEnd;

void UpdateInports(void) {

    /*
     * Pass the peripheral values to model Inports
     * if (PORTA & 1) { 
     *    x2cModel.inports.bInport = INT16_MAX;
     * }else {
     *    x2cModel.inports.bInport = 0;
     * }
     * 
     * The following inputs of the model can be used:
      x2cModel.inports.bCPULoad = Scaling*A_PeripheralVariable
      x2cModel.inports.bSW1 = Scaling*A_PeripheralVariable
      x2cModel.inports.bSW2 = Scaling*A_PeripheralVariable
      x2cModel.inports.bVPot = Scaling*A_PeripheralVariable

     */
    x2cModel.inports.bCPULoad  = (cpuLoadEnd-cpuLoadBegin) * INT16_MAX / TIMER1_PERIOD_COUNT;
    
    x2cModel.inports.bVPot = pot<<3;//Left align
    
    if (SW1) {
        x2cModel.inports.bSW1 = 0;
    } else {
        x2cModel.inports.bSW1 = INT16_MAX;
    }
    if (SW2) {
        x2cModel.inports.bSW2 = 0;
    } else {
        x2cModel.inports.bSW2 = INT16_MAX;
    }
    

}

void UpdateOutports(void) {
    
    /*
     * Pass model outports to peripherals e.g.:
     * 
     * if (*x2cModel.outports.bOutport) {  // if model Outport differ than zero 
     *    LATB |= 1; // set LATB0 
     * } else {
     *    LATB &= ~1; // clear LATB0
     * }    
     * 
     * The following outputs of the model can be used:
      A_PeripheralVariable = *x2cModel.outports.bFLT*Scaling
      A_PeripheralVariable = *x2cModel.outports.bLED1*Scaling
      A_PeripheralVariable = *x2cModel.outports.bLED2*Scaling
      A_PeripheralVariable = *x2cModel.outports.bOsc_out*Scaling
     */    
    if (*x2cModel.outports.bLED1 != 0) {
        LED1 = 1;
    } else {
        LED1 = 0;
    }    
    
    if (*x2cModel.outports.bLED2 != 0) {
        LED2 = 1;
    } else {
        LED2 = 0;
    }    

}
/**
 * Calls the inports update function
 * Then run model calculation
 * Last read model outports and update the peripherals
*/

//Interrupt handler to call model update


void TMR1_CallBack(void){
    cpuLoadBegin = TIMER1_CounterRead();
    
    UpdateInports();
    X2C_Update();
    UpdateOutports();
    
    cpuLoadEnd = TIMER1_CounterRead();
}

/* *****************************************************************************
 End of File
 */
