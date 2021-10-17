# Infineon 6EDL7141 3 phase smart gate driver library for use with PSoC® 6

This is a driver library to interface with an Infineon 6EDL7141 3 phase smart gate driver using a PSOC 6.

## Library Organization

The src directory contains all source code for this library.

## Quick Start

To use the library:

1. Include the header file *IFX_6EDL7141.h*.

2. Default SPI Naming is FETDRV_SPI and no other device is connected to the same SPI bus. If this has to be changed, use defines to select the new configuration.

3. Call the function *IFX_6EDL7141_Init* to initialize the SPI interface and inititialize the driver with default settings.

4. Call *IFX_6EDL7141_EnableCalibrationMode*  and *IFX_6EDL7141_SetEnable* to put the device in calibration mode and short the OpAmp inputs for ADC offset calibration.

5. Call *IFX_6EDL7141_DisableCalibrationMode*  and *FX_6EDL7141_SetDisable* to return to idle mode.

6. Setup PWMs and call *IFX_6EDL7141_SetEnable*  to enabled the FET driver stages.

**Example Code**

The folowing code will initialize the sensor and will then read values and print results every 200ms.

    #include "IFX_6EDL7141.h"

    IFX_6EDL7141_Init();
    PWM_Init();
    ADC_Init();
    
    IFX_6EDL7141_EnableCalibrationMode();
    IFX_6EDL7141_SetEnable();
    
    ADC_DoOffsetCalibration();
    
    IFX_6EDL7141_DisableCalibrationMode();
    IFX_6EDL7141_ClrEnable();
    
    PWM_SetCompare();
