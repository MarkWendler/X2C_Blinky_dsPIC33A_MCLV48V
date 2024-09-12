/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: blinky_dspic33ak_fip_mclv48                                                                                 */
/* Date:  2024-09-12 10:33                                                                                            */

/* X2C-Version: 6.5.3419                                                                                              */
/* X2C-Edition: Free                                                                                                  */

/* Common includes                                                                                                    */
#include <stddef.h>
#include "TableStruct.h"
/* Generated file includes                                                                                            */
#include "FlashTable.h"
#include "RamTable.h"
#include "X2C.h"

/**********************************************************************************************************************/
/**                                                       Model                                                      **/
/**********************************************************************************************************************/
struct x2cModel x2cModel;

/* Model identifier                                                                                                   */
const uint32 x2cModelIdentifier = 0xCF466559U;

/**********************************************************************************************************************/
/**                                                       Scope                                                      **/
/**********************************************************************************************************************/
SCOPE_MAIN x2cScope;

/* Block function table                                                                                               */
const tBlockFunctions blockFunctionTable[] = {
    FUNCTIONS,
    { 0U, NULL, NULL, NULL, NULL, NULL } /* End of table entry */
};

/* Parameter identifier table                                                                                         */
const tParameterTable parameterIdTable[] = {
    PARAMETER_TABLE,
    { 0U, NULL } /* End of table entry */
};

/* Inport Parameter identifier table                                                                                  */
const tIoParamIdEntry inportParamIdTable[] = {
    INPORT_PARAMID_TABLE, 
    { 0U, 0U, NULL } /* End of table entry */
};

/* Outport Parameter identifier table                                                                                 */
const tIoParamIdEntry outportParamIdTable[] = {
    OUTPORT_PARAMID_TABLE, 
    { 0U, 0U, NULL } /* End of table entry */
};

/* Mask Parameter identifier table                                                                                    */
const tMaskParameterEntry maskParamIdTable[] = {
    { 0U, NULL, NULL, NULL, NULL } /* End of table entry */
};

/* Extended Mask Parameter identifier table (used by Model API)                                                       */
const tMaskParamExtRecord maskParamExtTable[] = {
    { 0U, 0U, NULL, NULL, NULL, NULL, NULL } /* End of table entry */
};

/* Mask Parameter data table (used by Model API)                                                                      */
const tMaskParamDataRecord maskParamDataTable[] = {
    { 0U, 0U, NULL, 0U, 0U } /* End of table entry */
};

/**********************************************************************************************************************/
/** Model Sample Time                                                                                                **/
/**********************************************************************************************************************/
float_CoT getModelSampleTime()
{
    return ((float_CoT)1.0E-4);
}

/**********************************************************************************************************************/
/**                                                  Initialization                                                  **/
/**********************************************************************************************************************/
void X2C_Init(void)
{
    /******************************************************************************************************************/
    /**                                          Initialize Block Parameters                                         **/
    /******************************************************************************************************************/

    /* Block: Amplitude                                                                                               */
    /* Value = 0.5                                                                                                    */
    x2cModel.blocks.bAmplitude.K = 16384;

    /* Block: AutoSwitch1                                                                                             */
    /* Thresh_up = 0.0                                                                                                */
    /* Thresh_down = 0.0                                                                                              */
    x2cModel.blocks.bAutoSwitch1.Thresh_up = 0;
    x2cModel.blocks.bAutoSwitch1.Thresh_down = 0;
    x2cModel.blocks.bAutoSwitch1.Status = &RamTable_int16[0];

    /* Block: Frequency                                                                                               */
    /* Value = 0.001                                                                                                  */
    x2cModel.blocks.bFrequency.K = 33;

    /* Block: Gain                                                                                                    */
    /* Gain = 0.03                                                                                                    */
    x2cModel.blocks.bGain.V = 983;
    x2cModel.blocks.bGain.sfr = 15;

    /* Block: LED off                                                                                                 */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.bLED_off.K = 0;

    /* Block: LED on                                                                                                  */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.bLED_on.K = 32767;

    /* Block: Oscillator/AutoSwitch                                                                                   */
    /* Thresh_up = 0.5                                                                                                */
    /* Thresh_down = -0.5                                                                                             */
    x2cModel.blocks.sOscillator.bAutoSwitch.Thresh_up = 16384;
    x2cModel.blocks.sOscillator.bAutoSwitch.Thresh_down = -16384;
    x2cModel.blocks.sOscillator.bAutoSwitch.Status = &RamTable_int16[1];

    /* Block: Oscillator/Constant                                                                                     */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sOscillator.bConstant.K = 32767;

    /* Block: Oscillator/Enable                                                                                       */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sOscillator.bEnable.K = 1;

    /* Block: Oscillator/I                                                                                            */
    /* Ki = 0.0                                                                                                       */
    /* ts_fact = 3.0                                                                                                  */
    x2cModel.blocks.sOscillator.bI.b0 = 0;
    x2cModel.blocks.sOscillator.bI.sfr = 15;
    x2cModel.blocks.sOscillator.bI.i_old = 0;
    x2cModel.blocks.sOscillator.bI.enable_old = 0;

    /* Block: Oscillator/Init                                                                                         */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sOscillator.bInit.K = 0;

    /* Block: Oscillator/LoopBreaker                                                                                  */

    /* Block: Oscillator/Negation                                                                                     */

    /* Block: PT1                                                                                                     */
    /* V = 1.0                                                                                                        */
    /* fc = 10.0                                                                                                      */
    /* ts_fact = 1.0                                                                                                  */
    /* method = zoh                                                                                                   */
    x2cModel.blocks.bPT1.b0 = 205;
    x2cModel.blocks.bPT1.b1 = 0;
    x2cModel.blocks.bPT1.a0 = -32563;
    x2cModel.blocks.bPT1.sfrb = 15;
    x2cModel.blocks.bPT1.sfra = 15;
    x2cModel.blocks.bPT1.in_old = 0;

    /* Block: Sin3Gen                                                                                                 */
    /* fmax = 1000.0                                                                                                  */
    /* Offset = 0.0                                                                                                   */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.bSin3Gen.delta_phi = 6554;
    x2cModel.blocks.bSin3Gen.offset = 0;
    x2cModel.blocks.bSin3Gen.phi = 0;

    /* Block: SinGen                                                                                                  */
    /* fmax = 1000.0                                                                                                  */
    /* Offset = 0.0                                                                                                   */
    /* Phase = 0.0                                                                                                    */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.bSinGen.delta_phi = 6554;
    x2cModel.blocks.bSinGen.phase = 0;
    x2cModel.blocks.bSinGen.offset = 0;
    x2cModel.blocks.bSinGen.phi = 0;


    /* Initialize RAM table content */
    initRamTables();

    /******************************************************************************************************************/
    /**                                              Initialize Inports                                              **/
    /******************************************************************************************************************/
    x2cModel.inports.bCPULoad = (int16)0;
    x2cModel.inports.bSW1 = (int16)0;
    x2cModel.inports.bSW2 = (int16)0;
    x2cModel.inports.bVPot = (int16)0;

    /******************************************************************************************************************/
    /**                                               Link Block Inputs                                              **/
    /******************************************************************************************************************/

    /* Block Amplitude                                                                                                */

    /* Block AutoSwitch1                                                                                              */
    x2cModel.blocks.bAutoSwitch1.In1 =
        &x2cModel.blocks.bLED_off.Out;
    x2cModel.blocks.bAutoSwitch1.Switch =
        &x2cModel.blocks.bSinGen.u;
    x2cModel.blocks.bAutoSwitch1.In3 =
        &x2cModel.blocks.bLED_on.Out;

    /* Block Frequency                                                                                                */

    /* Block Gain                                                                                                     */
    x2cModel.blocks.bGain.In =
        &x2cModel.inports.bVPot;

    /* Block LEDoff                                                                                                   */

    /* Block LEDon                                                                                                    */

    /* Block AutoSwitch                                                                                               */
    x2cModel.blocks.sOscillator.bAutoSwitch.In1 =
        &x2cModel.blocks.sOscillator.bNegation.Out;
    x2cModel.blocks.sOscillator.bAutoSwitch.Switch =
        &x2cModel.blocks.sOscillator.bI.Out;
    x2cModel.blocks.sOscillator.bAutoSwitch.In3 =
        &x2cModel.blocks.sOscillator.bConstant.Out;

    /* Block Constant                                                                                                 */

    /* Block Enable                                                                                                   */

    /* Block I                                                                                                        */
    x2cModel.blocks.sOscillator.bI.In =
        &x2cModel.blocks.sOscillator.bLoopBreaker.Out;
    x2cModel.blocks.sOscillator.bI.I0 =
        &x2cModel.blocks.sOscillator.bInit.Out;
    x2cModel.blocks.sOscillator.bI.Enable =
        &x2cModel.blocks.sOscillator.bEnable.Out;

    /* Block Init                                                                                                     */

    /* Block LoopBreaker                                                                                              */
    x2cModel.blocks.sOscillator.bLoopBreaker.In =
        &x2cModel.blocks.sOscillator.bAutoSwitch.Out;

    /* Block Negation                                                                                                 */
    x2cModel.blocks.sOscillator.bNegation.In =
        &x2cModel.blocks.sOscillator.bConstant.Out;

    /* Block PT1                                                                                                      */
    x2cModel.blocks.bPT1.In =
        &x2cModel.blocks.bSinGen.u;

    /* Block Sin3Gen                                                                                                  */
    x2cModel.blocks.bSin3Gen.A =
        &x2cModel.blocks.bAmplitude.Out;
    x2cModel.blocks.bSin3Gen.f =
        &x2cModel.blocks.bFrequency.Out;

    /* Block SinGen                                                                                                   */
    x2cModel.blocks.bSinGen.A =
        &x2cModel.blocks.bAmplitude.Out;
    x2cModel.blocks.bSinGen.f =
        &x2cModel.blocks.bGain.Out;

    /******************************************************************************************************************/
    /**                                                 Link Outports                                                **/
    /******************************************************************************************************************/
    x2cModel.outports.bFLT =
        &x2cModel.blocks.bPT1.Out;
    x2cModel.outports.bLED1 =
        &x2cModel.blocks.bAutoSwitch1.Out;
    x2cModel.outports.bLED2 =
        &x2cModel.inports.bSW1;
    x2cModel.outports.bOsc_out =
        &x2cModel.blocks.sOscillator.bLoopBreaker.Out;

    /******************************************************************************************************************/
    /**                                           Run Block Init Functions                                           **/
    /******************************************************************************************************************/
    Constant_FiP16_Init(&x2cModel.blocks.bAmplitude);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.bAutoSwitch1);
    Constant_FiP16_Init(&x2cModel.blocks.bFrequency);
    Gain_FiP16_Init(&x2cModel.blocks.bGain);
    Constant_FiP16_Init(&x2cModel.blocks.bLED_off);
    Constant_FiP16_Init(&x2cModel.blocks.bLED_on);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sOscillator.bAutoSwitch);
    Constant_FiP16_Init(&x2cModel.blocks.sOscillator.bConstant);
    Constant_Bool_Init(&x2cModel.blocks.sOscillator.bEnable);
    I_FiP16_Init(&x2cModel.blocks.sOscillator.bI);
    Constant_FiP16_Init(&x2cModel.blocks.sOscillator.bInit);
    LoopBreaker_FiP16_Init(&x2cModel.blocks.sOscillator.bLoopBreaker);
    Negation_FiP16_Init(&x2cModel.blocks.sOscillator.bNegation);
    PT1_FiP16_Init(&x2cModel.blocks.bPT1);
    Sin3Gen_FiP16_Init(&x2cModel.blocks.bSin3Gen);
    SinGen_FiP16_Init(&x2cModel.blocks.bSinGen);
    Scope_Main_Init(&x2cScope);

    /* Initialize TableStruct tables                                                                                  */
    TableStruct->TFncTable = blockFunctionTable;
    TableStruct->TParamTable = parameterIdTable;
    TableStruct->inportParamTable = inportParamIdTable;
    TableStruct->outportParamTable = outportParamIdTable;
    TableStruct->maskParameterTable = maskParamIdTable;
}

/**********************************************************************************************************************/
/**                                            Run Block Update Functions                                            **/
/**********************************************************************************************************************/
static uint16 cnt_3 = X2C_UPDATE_3_DIVIDER - 1;
void X2C_Update(void)
{
    X2C_Update_1();
    if (cnt_3 == 0)
    {
        cnt_3 = X2C_UPDATE_3_DIVIDER;
        X2C_Update_3();
    }

    cnt_3--;
}

/* X2C_Update for blocks with 1*Ts                                                                                    */
void X2C_Update_1(void)
{
    LoopBreaker_FiP16_Update(&x2cModel.blocks.sOscillator.bLoopBreaker);
    Gain_FiP16_Update(&x2cModel.blocks.bGain);
    Negation_FiP16_Update(&x2cModel.blocks.sOscillator.bNegation);
    SinGen_FiP16_Update(&x2cModel.blocks.bSinGen);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.bAutoSwitch1);
    PT1_FiP16_Update(&x2cModel.blocks.bPT1);
    Sin3Gen_FiP16_Update(&x2cModel.blocks.bSin3Gen);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sOscillator.bAutoSwitch);
    Scope_Main_Update(&x2cScope);
}

/* X2C_Update for blocks with 3*Ts                                                                                    */
void X2C_Update_3(void)
{
    I_FiP16_Update(&x2cModel.blocks.sOscillator.bI);
}

