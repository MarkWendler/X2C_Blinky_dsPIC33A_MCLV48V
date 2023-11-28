# Model based X2C Blinky demo MCLV-48V-300W and dsPIC33AK128MC106 Motor Control DIM

## 1. INTRODUCTION
This document describes the setup requirements for driving a Permanent Magnet Synchronous Motor (PMSM) using Sensorless Field Oriented Control (FOC) and PLL Estimator Algorithms on the hardware platform MCLV-48V-300W Inverter Board and dsPIC33AK128MC106 Motor Control Dual In-line Module (DIM).

For details about PLL estimator refer to Microchip application note [AN1292](https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ApplicationNotes/ApplicationNotes/01292A.pdf) “Sensorless Field Oriented Control (FOC) for a Permanent Magnet Synchronous Motor (PMSM) Using a PLL Estimator and Field Weakening (FW)”

</br>

## 2. SUGGESTED DEMONSTRATION REQUIREMENTS

### 2.2 Software Tools Used for Testing the firmware
- MPLAB® X IDE **MPLABX v6.15** 
- DFP: **dsPIC33AK-MC_DEV_DFP v0.1.59**
- MPLAB® XC16 Compiler **XC-DSC_3.15.B2**
- MPLAB® PICkit™ on board 4 In-Circuit Debugger 
- Scilab v2023.1.0
- X2C v6.4.2980

Please refer to [(link)](https://confluence.microchip.com/display/MCU16APP/MC+-+dsPIC33AK128MC106+validation+by+MC+team) for information on software used.

### 2.3 Hardware Tools Required for the Demonstration
- MCLV-48V-300W Inverter Board (EV18H47A)
- dsPIC33AK128MC106 Motor Control Dual In-line Module 
- 24V Power Supply [(AC002013)](https://www.microchipdirect.com/dev-tools/AC002013)
- 24V 3-Phase Brushless DC Motor [(AC300020)](https://www.microchip.com/en-us/development-tool/AC300020).

> **_NOTE:_**
> All items listed under the section Hardware Tools Required for the Demonstration are available at [microchip DIRECT](https://www.microchipdirect.com/)

## 3. HARDWARE SETUP
<p style='text-align: justify;'>This section describes hardware setup required for the demonstration.</p>

1. <p style='text-align: justify;'> Insert the dsPIC33AK128MC106 Motor Control DIM into the DIM Interface Connector J8 provided on the MCLV-48V-300W Inverter Board. Make sure the DIM is placed correctly and oriented before going ahead.</p>

    <p align="left">
    <img  src="images/dimconnected.PNG"></p>

2. <p style='text-align: justify;'>	Plug in the 24V power supply to connector J1 provided on the MCLV-48V-300W Inverter Board. Alternatively, the Inverter Board can also be powered through Connector J3.</p>
      <p align="left">
      <img  src="images/mclvpower.png"></p>

3. <p style='text-align: justify;'>The board has an onboard programmer ‘PICkit™ On Board (PKoB4)’ , which can be used for debugging the dsPIC33CK256MP508. To use an on-board programmer/debugger, connect a micro-USB cable between Host PC and Connector J16 provided on the MCLV-48V-300W Inverter Board.</p>

      <p align="left">
     <img  src="images/mclvpkob4.png"></p>
 

<br />

## 4. SOFTWARE SETUP AND RUN
### 4.1 Setup: MPLAB X IDE and MPLAB XC-DSC Compiler

Install MPLAB X IDE and MPLAB XC-DSC Compiler versions that support the device dsPIC33AK128MC106. The MPLAB X IDE, MPLAB XC-DSC Compiler, and X2C-Scope plug-in used for testing the firmware are mentioned in the [Motor Control Application Firmware Required for the Demonstration](#21-motor-control-application-firmware-required-for-the-demonstration) section. To get help on  

- MPLAB X IDE installation, refer [link](https://microchipdeveloper.com/mplabx:installation)
- MPLAB XC-DSC Compiler installation steps, refer [link](https://microchipdeveloper.com/XCDSC:installation)

## 5.0 Peripheral Connections: 
   **Interrupt to call X2C Model** : This is a UI component in the X2C MCC UI. User has options to select different 
   peripherals(Timer,PWM,ADC) as the Interrupt source to call the X2C Model. Based on the model sample time 
   users have to configure the interrupt rate to match the model sample time.
   
   For Example: If the Model sample rate is set as 10KHz(100 Micro Seconds)  and Timer1 is selcted to execute the model
   (Interrupt to call X2C Model), then Timer1 needs to be configured    to have a period of 100 Micro Seconds(Interrupt 
   is generated every 100 Micro Seconds).(Note: Any interrupt which can produce constant timing can be used.)

   If the user has requirement for any other peripheral based on the model , they have to add the peripheral to the Project 
   and configure them.

| board    | pin  | 
|:--------:|:----:| 
| SW1       |  RD9   |
| SW2	     |  RD10   |
| POT      |  AD1AN10   |
| LED1     |  RD5   |
| LED2     |  RC9   |

## UART settings: 

   **Communication**: For X2C Scope Communication currently UART is used. User needs to select the required UART instance 
   and Configure the UART.

| Baudrate | Databits | Parity | Stopbits |
| -------- | -------- | ------ | -------- |
| 115200   | 8        | none   | 1        |

    _U1RXR = 44;
    _RP43R = 9;

## Running the tests

Open the project in MPLABX, then program the device.