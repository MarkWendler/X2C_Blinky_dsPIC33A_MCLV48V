/**
 * @file
 * @brief Generated model file.
 * 
 * Date:  2024-09-12 10:33
 * 
 * X2C-Version: 6.5.3419
 * X2C-Edition: Free
 */
/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: blinky_dspic33ak_fip_mclv48                                                                                 */
/* Date:  2024-09-12 10:33                                                                                            */

/* X2C-Version: 6.5.3419                                                                                              */
/* X2C-Edition: Free                                                                                                  */

#ifndef X2C_H
#define X2C_H

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************************************************/
/**     Includes                                                                                                     **/
/**********************************************************************************************************************/
/* Common includes                                                                                                    */
#include "Constant_Bool.h"
#include "Gain_FiP16.h"
#include "SinGen_FiP16.h"
#include "Constant_FiP16.h"
#include "I_FiP16.h"
#include "Sin3Gen_FiP16.h"
#include "Negation_FiP16.h"
#include "PT1_FiP16.h"
#include "AutoSwitch_FiP16.h"
#include "LoopBreaker_FiP16.h"
#include "Scope_Main.h"
#include "CommonFcts.h"

/**********************************************************************************************************************/
/**     Defines                                                                                                      **/
/**********************************************************************************************************************/
#define FUNCTIONS \
    CONSTANT_BOOL_FUNCTIONS , \
    GAIN_FIP16_FUNCTIONS , \
    SINGEN_FIP16_FUNCTIONS , \
    CONSTANT_FIP16_FUNCTIONS , \
    I_FIP16_FUNCTIONS , \
    SIN3GEN_FIP16_FUNCTIONS , \
    NEGATION_FIP16_FUNCTIONS , \
    PT1_FIP16_FUNCTIONS , \
    AUTOSWITCH_FIP16_FUNCTIONS , \
    LOOPBREAKER_FIP16_FUNCTIONS , \
    SCOPE_MAIN_FUNCTIONS

#define PARAMETER_TABLE \
    { 1U, &x2cModel.blocks.bAmplitude } , \
    { 2U, &x2cModel.blocks.bAutoSwitch1 } , \
    { 3U, &x2cModel.blocks.bFrequency } , \
    { 4U, &x2cModel.blocks.bGain } , \
    { 5U, &x2cModel.blocks.bLED_off } , \
    { 6U, &x2cModel.blocks.bLED_on } , \
    { 7U, &x2cModel.blocks.sOscillator.bAutoSwitch } , \
    { 8U, &x2cModel.blocks.sOscillator.bConstant } , \
    { 9U, &x2cModel.blocks.sOscillator.bEnable } , \
    { 10U, &x2cModel.blocks.sOscillator.bI } , \
    { 11U, &x2cModel.blocks.sOscillator.bInit } , \
    { 12U, &x2cModel.blocks.sOscillator.bLoopBreaker } , \
    { 13U, &x2cModel.blocks.sOscillator.bNegation } , \
    { 14U, &x2cModel.blocks.bPT1 } , \
    { 15U, &x2cModel.blocks.bSin3Gen } , \
    { 16U, &x2cModel.blocks.bSinGen } , \
    { 25U, &x2cScope }

#define INPORT_PARAMID_TABLE \
    { 17U, 2U, &x2cModel.inports.bCPULoad } , \
    { 18U, 2U, &x2cModel.inports.bSW1 } , \
    { 19U, 2U, &x2cModel.inports.bSW2 } , \
    { 20U, 2U, &x2cModel.inports.bVPot } 

#define OUTPORT_PARAMID_TABLE \
    { 21U, 2U, &x2cModel.outports.bFLT } , \
    { 22U, 2U, &x2cModel.outports.bLED1 } , \
    { 23U, 2U, &x2cModel.outports.bLED2 } , \
    { 24U, 2U, &x2cModel.outports.bOsc_out } 


/**********************************************************************************************************************/
/**                                            Model structure definition                                            **/
/**********************************************************************************************************************/
struct x2cModel {
/*  Control Blocks                                                                                                    */
    struct {
/*      Sub-system Oscillator                                                                                         */
        struct {
            AUTOSWITCH_FIP16 bAutoSwitch;
            CONSTANT_FIP16 bConstant;
            CONSTANT_BOOL bEnable;
            I_FIP16 bI;
            CONSTANT_FIP16 bInit;
            LOOPBREAKER_FIP16 bLoopBreaker;
            NEGATION_FIP16 bNegation;
        } sOscillator;
        CONSTANT_FIP16 bAmplitude;
        AUTOSWITCH_FIP16 bAutoSwitch1;
        CONSTANT_FIP16 bFrequency;
        GAIN_FIP16 bGain;
        CONSTANT_FIP16 bLED_off;
        CONSTANT_FIP16 bLED_on;
        PT1_FIP16 bPT1;
        SIN3GEN_FIP16 bSin3Gen;
        SINGEN_FIP16 bSinGen;
    } blocks;
/*  Inports                                                                                                           */
    struct {
        int16 bCPULoad;
        int16 bSW1;
        int16 bSW2;
        int16 bVPot;
    } inports;
/*  Outports                                                                                                          */
    struct {
        int16* bFLT;
        int16* bLED1;
        int16* bLED2;
        int16* bOsc_out;
    } outports;
};

/**********************************************************************************************************************/
/**     Externals                                                                                                    **/
/**********************************************************************************************************************/
extern struct x2cModel x2cModel;

extern const uint32 x2cModelIdentifier;

extern const tBlockFunctions blockFunctionTable[];
extern const tParameterTable parameterIdTable[];
extern const tIoParamIdEntry inportParamIdTable[];
extern const tIoParamIdEntry outportParamIdTable[];
extern const tMaskParameterEntry maskParamIdTable[];
extern const tMaskParamExtRecord maskParamExtTable[];
extern const tMaskParamDataRecord maskParamDataTable[];

#define X2C_UPDATE_3_DIVIDER 3

/**********************************************************************************************************************/
/**     Prototypes                                                                                                   **/
/**********************************************************************************************************************/
void X2C_Init(void);
void X2C_Update(void);
void X2C_Update_1(void);
void X2C_Update_3(void);

#ifdef __cplusplus
}
#endif

#endif
