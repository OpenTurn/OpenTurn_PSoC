/*!
 * \name        Tle5012b_reg.h - Library for Arduino for the TLE5012B angle sensor.
 * \author      Infineon Technologies AG (Dr.Olaf Filies)
 * \copyright   2019 Infineon Technologies AG
 * \version     2.0.1
 * \brief       GMR-based angle sensor for angular position sensing in automotive applications
 *              This library include the register read and bit separation function.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 * disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "stdint.h"

#ifndef TLE5012B_REG_H
#define TLE5012B_REG_H

#define MAX_NUM_REG    0x30   //!< defines the value for temporary data to read all readable registers

// Sensor registers
#define READ_SENSOR                 0x8000    //!< base command for read
#define WRITE_SENSOR                0x5000    //!< base command for write
#define READ_BLOCK_CRC              0x8088    //!< initialize block CRC check command

#define REG_STAT                    0x0000    //!< STAT status register
#define REG_ACSTAT                  0x0001    //!< ACSTAT activation status register
#define REG_AVAL                    0x0002    //!< AVAL angle value register
#define REG_ASPD                    0x0003    //!< ASPD angle speed register
#define REG_AREV                    0x0004    //!< AREV angle revolution register
#define REG_FSYNC                   0x0005    //!< FSYNC frame synchronization register
#define REG_MOD_1                   0x0006    //!< MOD_1 interface mode1 register
#define REG_SIL                     0x0007    //!< SIL register
#define REG_MOD_2                   0x0008    //!< MOD_2 interface mode2 register
#define REG_MOD_3                   0x0009    //!< MOD_3 interface mode3 register
#define REG_OFFX                    0x000A    //!< OFFX offset x
#define REG_OFFY                    0x000B    //!< OFFY offset y
#define REG_SYNCH                   0x000C    //!< SYNCH synchronicity
#define REG_IFAB                    0x000D    //!< IFAB register
#define REG_MOD_4                   0x000E    //!< MOD_4 interface mode4 register
#define REG_TCO_Y                   0x000F    //!< TCO_Y temperature coefficient register
#define REG_ADC_X                   0x0010    //!< ADC_X ADC X-raw value
#define REG_ADC_Y                   0x0011    //!< ADC_Y ADC Y-raw value
#define REG_D_MAG                   0x0014    //!< D_MAG angle vector magnitude
#define REG_T_RAW                   0x0015    //!< T_RAW temperature sensor raw-value
#define REG_IIF_CNT                 0x0020    //!< IIF_CNT IIF counter value
#define REG_T25O                    0x0030    //!< T25O temperature 25°c offset value

#define SYSTEM_ERROR_MASK           0x4000    //!< System error masks for safety words
#define INTERFACE_ERROR_MASK        0x2000    //!< Interface error masks for safety words
#define INV_ANGLE_ERROR_MASK        0x1000    //!< Angle error masks for safety words

#define CRC_POLYNOMIAL              0x1D      //!< values used for calculating the CRC
#define CRC_SEED                    0xFF
#define CRC_NUM_REGISTERS           0x0008    //!< number of CRC relevant registers
#define MAX_REGISTER_MEM            0x0030    //!< max readable register values buffer

#define DELETE_BIT_15               0x7FFF    //!< Value used to delete everything except the first 15 bits
#define CHANGE_UINT_TO_INT_15       0x8000    //!< Value used to change unsigned 16bit integer into signed
#define CHECK_BIT_14                0x4000    //!<
#define GET_BIT_14_4                0x7FF0    //!<

#define DELETE_7BITS                0x01FF    //!< values used to calculate 9 bit signed integer sent by the sensor
#define CHANGE_UNIT_TO_INT_9        0x0200    //!< Value used to change unsigned 9bit integer into signed
#define CHECK_BIT_9                 0x0100

#define POW_2_15                    32768.0   //!< values used to for final calculations of angle speed, revolutions, range and value
#define POW_2_7                     128.0     //!<
#define ANGLE_360_VAL               360.0

#define TEMP_OFFSET                 152.0     //!< values used to calculate the temperature
#define TEMP_DIV                    2.776

	/*!
	 * Error types from safety word
	 */
	typedef enum
	{
		NO_ERROR               = 0x0000,    // NO_ERROR = Safety word was OK
		SYSTEM_ERROR           = 0x0001,    // SYSTEM_ERROR = over/under voltage, VDD negative, GND off, ROM defect
		INTERFACE_ACCESS_ERROR = 0x0002,    // INTERFACE_ACCESS_ERROR = wrong address or wrong lock
		INVALID_ANGLE_ERROR    = 0x0003,    // INVALID_ANGLE_ERROR = NO_GMR_A = 1 or NO_GMR_XY = 1
		ANGLE_SPEED_ERROR      = 0x0004,    // ANGLE_SPEED_ERROR = combined error, angular speed calculation wrong
		SSC_ERROR			         = 0x00F0,    // Communication error, command did not match received data
		CRC_ERROR              = 0x00FF,    // CRC_ERROR = Cyclic Redundancy Check (CRC), which includes the STAT and RESP bits wrong
		WRITE_ERROR            = 0x0100,    // WRITE ERROR = written value not the same as read value
		PARAMETER_ERROR        = 0x0200     // Function Parameter not allowed (out of range)
	} e_errorTypes_t;

	/*!
	  * Set the UPDate bit high (read from update buffer) or low (read directly)
	  */
	enum updTypes
	{
		UPD_low  = 0x0000,           //!< read normal registers
		UPD_high = 0x0400,           //!< read update buffer registers
	};

	/*!
	  * Switch on/off safety word generation
	  */
	enum safetyTypes
	{
		SAFE_low  = 0x0000,          //!< switch of safety word generation
		SAFE_high = 0x0001,          //!< switch on safety word generation
	};



	/*!
	 * Automatic calibration of offset and amplitude synchronicity for applications
	 * with full-turn. Only 1 LSB corrected at each update. CRC check of calibration
	 * registers is automatically disabled if AUTOCAL activated.
	 */
	typedef enum
	{
		noAutoCal = 0x0,//!< noAutoCal = no auto-calibration
		mode1,          //!< mode1 update every angle update cycle (FIR_MD setting)
		mode2,          //!< mode2 update every 1.5 revolutions
		mode3           //!< mode3 update every 11.25°
	}e_calibrationMode_t;

	/*!
	 * List of possible interface types
	 * witch are preset by fuses and can
	 * be changed into each other
	 */
	typedef enum
	{
		IIF = 0,  //!< IIF Incremental Interface (IIF)
		PWM,      //!< PWM Pulse-Width-Modulation (PWM)
		HSM,      //!< HSM Hall Switch Mode (HSM)
		SPC,      //!< SPC Short-PWM-Code (SPC)
		SSC       //!< SSC Synchronous Serial Communication (SSC)
	}e_interfaceType_t;

	/*!
	 * List of possible Sensor types and PCB variants
	 * with and without attached XMC2Go
	 */
	typedef enum
	{
		TLE5012B_E1000= 0x0,//!< TLE5012B_E1000 Sensor2Go variant
		TLE5012B_E3005,     //!< TLE5012B_E3005
		TLE5012B_E5000,     //!< TLE5012B_E5000 Sensor2Go variant
		TLE5012B_E5020,     //!< TLE5012B_E5020
		TLE5012B_E9000,     //!< TLE5012B_E9000 Sensor2Go variant
	}e_sensorType_t;

	typedef struct        //!< Status register 0x00
	{
		union
		{
			struct
			{
				uint16_t S_RST		: 1;       //!< bits 0:0 Status Reset
				uint16_t S_WD		: 1;       //!< bits 1:1 Status Watch dog
				uint16_t S_VR		: 1;       //!< bits 2:2 Status voltage regulator
				uint16_t S_FUSE		: 1;       //!< bits 3:3 Status fuse CRC
				uint16_t S_DSPU		: 1;       //!< bits 4:4 Status digital signal processing unit
				uint16_t S_OV		: 1;       //!< bits 5:5 Status overflow
				uint16_t S_XYOL		: 1;       //!< bits 6:6 Status  X,Y Data out of Limit
				uint16_t S_MAGOL	: 1;       //!< bits 7:7 Status magnitude out of Limit
				uint16_t Reserved1	: 1;       //!< bits 8:8
				uint16_t S_ADCT		: 1;       //!< bits 9:9 Status ADC Test
				uint16_t S_ROM		: 1;       //!< bits 10:10 Status ROM
				uint16_t NO_GMR_XY	: 1;       //!< bits 11:11 No valid GMR XY values
				uint16_t NO_GMR_A	: 1;       //!< bits 12:12 No valid GMR angle value
				uint16_t S_NR		: 2;       //!< bits 14:13 Slave number
				uint16_t RD_ST 		: 1;       //!< bits 15:15 Read status
			};
			uint16_t reg;           //!< the register value
		};
	}stat_t;

	typedef struct      //!< Activation Status register offset 0x01
	{
		union
		{
			struct
			{
				uint16_t AS_RST		: 1;     //!< bits 0:0 Activation of Hardware Reset
				uint16_t AS_WD		: 1;     //!< bits 1:1 Enable DSPU Watch dog
				uint16_t AS_VR		: 1;     //!< bits 2:2 Enable Voltage regulator Check
				uint16_t AS_FUSE	: 1;     //!< bits 3:3 Activation Fuse CRC
				uint16_t AS_DSPU	: 1;     //!< bits 4:4 Activation DSPU BIST
				uint16_t AS_OV		: 1;     //!< bits 5:5 Enable of DSPU Overflow Check
				uint16_t AS_VEC_XY	: 1;     //!< bits 6:6 Activation of X,Y Out of Limit-Check
				uint16_t AS_VEG_MAG	: 1;     //!< bits 7:7 Activation of Magnitude Check
				uint16_t Reserved1	: 1;     //!< bits 8:8
				uint16_t AS_ADCT	: 1;     //!< bits 9:9 Enable ADC Test vector Check
				uint16_t AS_FRST	: 1;     //!< bits 10:10 Activation of Firmware Reset
				uint16_t Reserved2	: 5;     //!< bits 15:11
			};
			uint16_t reg;           //!< the register value
		};
	}acstat_t;

	typedef struct        //!< Angle Value register offset 0x02
	{
		union
		{
			struct
			{
				int16_t ANG_VAL	    : 15;     //!< bits 14:0 Calculated Angle Value (signed 15-bit)
				uint16_t RD_AV		: 1;      //!< bits 15:15  Read Status, Angle Value
			};
			uint16_t reg;           //!< the register value
		};
	}aval_t;

	typedef struct        //!< Angle Speed register offset 0x03
	{
		union
		{
			struct
			{
				int16_t ANG_SPD	    : 15;     //!< bits 14:0 Signed value, where the sign bit [14] indicates the direction of the rotation.
				uint16_t RD_AS		: 1;      //!< bits 15:15 Read Status, Angle Speed
			};
			uint16_t reg;           //!< the register value
		};
	}aspd_t;

	typedef struct        //!< Angle Revolution register offset 0x04
	{
		union
		{
			struct
			{
				int16_t REVOL		: 9;      //!< bits 8:0 Revolution counter. Increments for every full rotation in counter-clockwise direction
				uint16_t FCNT		: 6;      //!< bits 14:9 Internal frame counter. Increments every update period
				uint16_t RD_REV		: 1;      //!< bits 15:15 Read Status, Revolution
			};
			uint16_t reg;           //!< the register value
		};
	}arev_t;

	typedef struct       //!< Frame Synchronization register offset 0x05
	{
		union
		{
			struct
			{
				int16_t TEMPER		: 9;       //!< bits 8:0 Signed offset compensated temperature value.
				uint16_t FSYNC		: 7;       //!< bits 15:9 Frame Synchronization Counter Value
			};
			uint16_t reg;           //!< the register value
		};
	}fsync_t;

	typedef struct        //!< MOD_1 Interface Mode1 register offset 0x06
	{
		union
		{
			struct
			{
				uint16_t IIF_MOD	: 2;       //!< bits 1:0 Incremental Interface Mode
				uint16_t DSPU_HOLD	: 1;       //!< bits 2:2 If DSPU is on hold, no watch dog reset is performed by DSPU
				uint16_t Reserverd1	: 1;       //!< bits 3:3
				uint16_t CLK_SEL	: 1;       //!< bits 4:4 Switch to external clock at start-up only.
				uint16_t Reserverd2	: 9;       //!< bits 13:5
				uint16_t FIR_MD		: 2;       //!< bits 15:14 Update Rate Setting
			};
			uint16_t reg;           //!< the register value
		};
	}mod1_t;

	typedef struct         //!< SIL register offset 0x07
	{
		union
		{
			struct
			{
				uint16_t ADCTV_X	: 3;       //!< bits 2:0 Test vector Y
				uint16_t ADCTV_Y	: 3;       //!< bits 5:3 Test vector X
				uint16_t ADCTV_EN	: 1;       //!< bits 6:6 Sensor elements are internally disconnected and test voltages are connected to ADCs.
				uint16_t Reserverd2	: 3;       //!< bits 9:7
				uint16_t FUSE_REL	: 1;       //!< bits 10:10 Triggers reload of default values from laser fuses into configuration registers.
				uint16_t Reserverd1	: 3;       //!< bits 13:11 The X- and Y-signals are inverted. The angle output is then shifted by 180°.
				uint16_t FILT_INV	: 1;       //!< bits 14:14 The raw X-signal is routed also to the raw Y-signal input of the filter so SIN and COS signal should be identical.
				uint16_t FILT_PAR	: 1;       //!< bits 15:15
			};
			uint16_t reg;           //!< the register value
		};
	}sil_t;

	typedef struct        //!< MOD_2 Interface Mode2 register offset 0x08
	{
		union
		{
			struct
			{
				uint16_t AUTOCAL	: 2;       //!< bits 1:0 Automatic calibration of offset and amplitude synchronicity for applications with full-turn.
				uint16_t PREDICT	: 1;       //!< bits 2:2 Prediction of angle value based on current angle speed
				uint16_t ANG_DIR	: 1;       //!< bits 3:3 Inverts angle and angle speed values and revolution counter behavior.
				uint16_t ANG_RANGE	: 11;      //!< bits 14:4 Changes the representation of the angle output by multiplying the output with a factor ANG_RANGE/128.
				uint16_t Reserverd1	: 1;       //!< bits 15:15
			};
			uint16_t reg;           //!< the register value
		};
	}mod2_t;

	typedef struct        //!< MOD_3 Interface Mode3 register offset 0x09
	{
		union
		{
			struct
			{
				uint16_t PAD_DRV	: 2;       //!< bits 1;0 Configuration of Pad-Driver
				uint16_t SSC_OD		: 1;       //!< bits 2:2 SSC-Interface Data Pin Output Mode
				uint16_t SPIKEF		: 1;       //!< bits 3:3 Filters voltage spikes on input pads (IFC, SCK and CSQ).
				int16_t ANG_BASE	: 12;      //!< bits 15:4 Sets the 0° angle position (12 bit value). Angle base is factory-calibrated to make the 0° direction parallel to the edge of the chip.
			};
			uint16_t reg;           //!< the register value
		};
	}mod3_t;

	typedef struct        //!< Offset X offset 0x0a
	{
		union
		{
			struct
			{
				uint16_t Reserverd1	: 4;       //!< bits 3:0
				int16_t X_OFFSET	: 12;      //!< bits 15:4 12-bit signed integer value of raw X-signal offset correction at 25°C.
			};
			uint16_t reg;           //!< the register value
		};
	}offx_t;

	typedef struct        //!< Offset Y offset 0x0b
	{
		union
		{
			struct
			{
				uint16_t Reserverd1	: 4;       //!< bits 3:0
				int16_t Y_OFFSET	: 12;      //!< bits 15:4 12-bit signed integer value of raw Y-signal offset correction at 25°C.
			};
			uint16_t reg;           //!< the register value
		};
	}offy_t;

	typedef struct  	//!< Synchronicity offset 0x0c
	{
		union
		{
			struct
			{
				uint16_t Reserverd1	: 4;		//!< bits 3:0
				int16_t SYNCH		: 12;		//!< bits 15:4 12-bit signed integer value of amplitude synchronicity
			};
			uint16_t reg;			//!< the register value
		};
	}synch_t;

	typedef struct  		//!< IFAB register offset 0x0d
	{
		union
		{
			struct
			{
				uint16_t IFAB_HYST	: 2;		//!< bits 1:0 Hysteresis (multi-purpose)
				uint16_t IFAB_OD	: 1;		//!< bits 2:2 IFA,IFB,IFC Output Modeuint16_t FIRUDR		: 4;		//!< bits 3:3 Initial filter update rate (FIR)
				uint16_t FIR_UDR	: 1;		//!< bits 3:3 Initial filter update rate (FIR)
				int16_t ORTHO		: 12;		//!< bits 15:4 Orthogonality Correction of X and Y Components
			};
			uint16_t reg;			//!< the register value
		};
	}ifab_t;

	typedef struct  		//!< MOD_4 Interface Mode4 register offset 0x0e
	{
		union
		{
			struct
			{
				uint16_t IF_MD		: 2;		//!< bits 1:0 Interface Mode on IFA,IFB,IFC
				uint16_t Reserverd1	: 1;		//!< bits 2:2
				uint16_t IFAB_RES	: 2;		//!< bits 4:3 IIF resolution (multi-purpose)
				uint16_t HSM_PLP	: 4;		//!< bits 8:5 Hall Switch mode (multi-purpose)
				int16_t TCO_X_T	    : 7;		//!< bits 15:9 7-bit signed integer value of X-offset temperature coefficient.
			};
		uint16_t reg;			//!< the register value
		};
	}mod4_t;

	typedef struct  		//!< TCO_Y Temperature Coefficient register offset 0x0f
	{
		union
		{
			struct
			{
				uint16_t CRC_PAR	: 8;		//!< bits 7:0 CRC of Parameters
				uint16_t SBIST		: 1;		//!< bits 8:8 Startup-BIST
				int16_t TCO_Y_T	    : 7;		//!< bits 15:9 7-bit signed integer value of Y-offset temperature coefficient.
			};
			uint16_t reg;			//!< the register value
		};
	}tcoy_t;

	typedef struct 		//!< ADC_X offset 0x10, ADC_Y offset 0x11
	{
		int16_t ADCX;			//!< bits 15:0 ADC value of X-GMR
		int16_t ADCY;			//!< bits 15:0 ADC value of Y-GMR
	}adc_t;

	typedef struct  		//!< D_Mag vector magnitude offset 0x14
	{
		union
		{
			struct
			{
				uint16_t MAG		: 10;	    //!< bits 9:0 Unsigned Angle Vector Magnitude after X, Y error compensation (due to temperature).
				uint16_t Reserverd1	: 6;	    //!< bits 15:10
			};
			uint16_t reg;			//!< the register value
		};
	}dmag_t;

	typedef struct  		//!< T_RAW temperature raw data offset 0x15
	{
		union
		{
			struct
			{
				uint16_t T_RAW		: 10;		//!< bits 9:0 Temperature Sensor Raw-Value at ADC without offset
				uint16_t Reserverd1	: 5;		//!< bits 14:10
				uint16_t T_TGL		: 1;		//!< bits 15:15 Temperature Sensor Raw-Value Toggle toggles after every new temperature value
			};
			uint16_t reg;			//!< the register value
		};
	}traw_t;

	typedef struct  	//!< IIF counter value offset 0x20
	{
		union
		{
			struct
			{
				uint16_t IIF_CNT	: 14;		//!< bits 13:0 14 bit counter value of IIF increments
				uint16_t Reserverd1	: 2;		//!< bits 15:14
			};
			uint16_t reg;			//!< the register value
		};
	} iifcnt_t;

	typedef struct  		//!< register T250 offset 0x30
	{
		union
		{
			struct
			{
				uint16_t Reserverd1	: 9;		//!< bit 8:0
				int16_t T25O		: 7;		//!< bits 15:9 Signed offset value at 25°C temperature; 1dig=0.36°C.
			};
			uint16_t reg;			//!< the register value
		};
	} t25o_t;

	typedef struct
	{
		union
		{
			uint16_t registers[MAX_NUM_REG];	//!< raw register memory
			struct{
				stat_t stat;
				acstat_t acstat;
				aval_t aval;
				aspd_t aspd;
				arev_t arev;
				fsync_t fsync;
				mod1_t mod1;
				sil_t sil;
				mod2_t mod2;
				mod3_t mod3;
				offx_t offx;
				offy_t offy;
				synch_t synch;
				ifab_t ifab;
				mod4_t mod4;
				tcoy_t tcoy;
				adc_t adc;
				uint16_t reserved1[2];
				dmag_t dmag;
				traw_t traw;
				uint16_t reserved2[10];
				iifcnt_t iifcnt;
				uint16_t reserved3[15];
				t25o_t t25o;
			};
		};
	} regSensor_t;

	regSensor_t tle5012b_Register;		//!< sensor register read and separation

#endif
