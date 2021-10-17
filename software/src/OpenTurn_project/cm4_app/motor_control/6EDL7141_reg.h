/*!
 * \name        6EDL7141_reg.h - Library for the 6EDL7141 gate driver.
 * \author      // TODO
 * \copyright   // TODO
 * \version     // TODO
 * \brief       // TODO
 *
 */

#include "stdint.h"

#ifndef IFX_6EDL7141_REG_H
#define IFX_6EDL7141_REG_H

typedef enum {
  REG_FAULT_ST = 0x00,  /* Fault and warning status */
  REG_TEMP_ST,          /* Temperature status */
  REG_SUPPLY_ST,        /* Power supply status */
  REG_FUNC_ST,          /* Functional status */
  REG_OTP_ST,           /* OTP status */
  REG_ADC_ST,           /* ADC status */
  REG_CP_ST,            /* Charge pumps status */
  REG_DEVICE_ID,        /* Device ID */
  RES1,
  RES2,
  RES3,
  RES4,
  RES5,
  RES6,
  RES7,
  RES8,
  REG_FAULT_CLR = 0x10, /* Fault clear */
  REG_SUPPLY_CFG,       /* Power supply configuration */
  REG_ADC_CFG,          /* ADC configuration */
  REG_PWM_CFG,          /* PWM configuration */
  REG_SENSOR_CFG,       /* Sensor configuration */
  REG_WD_CFG,           /* Watchdog configuration */
  REG_WD_CFG2,          /* Watchdog configuration 2 */
  REG_IDRIVE_CFG,       /* Gate driver current configuration */
  REG_IDRIVE_PRE_CFG,   /* Pre-charge gate driver current configuration */
  REG_TDRIVE_SRC_CFG,   /* Gate driver sourcing timing configuration */
  REG_TDRIVE_SINK_CFG,  /* Gate driver sinking timing configuration */
  REG_DT_CFG,           /* Dead time configuration */
  REG_CP_CFG,           /* Charge pump configuration */
  REG_CSAMP_CFG,        /* Current sense amplifier configuration */
  REG_CSAMP_CFG2,       /* Current sense amplifier configuration 2 */
  REG_OTP_PROG,         /* OTP program */
  MAX_NUM_REG_6EDL7141
} e_reg_6EDL7141_t;

/*!
 * Error types from safety word
 */
typedef enum
{
  IFX_6EDL7141_NO_ERROR      = 0x0000, //!< NO ERROR
  IFX_6EDL7141_ERROR         = 0x0001, //!< ERROR occured
  IFX_6EDL7141_OPT_FAILED    = 0x0002, //!< OTP failed or was already performed
  IFX_6EDL7141_PARAM_ERROR   = 0x0004  //!< wrong parameter
} e_6EDL7141_errorTypes_t;

typedef struct                         //!< Fault and warning status 0x00
{
  union
  {
    struct
    {
      uint16_t CS_OCP_FLT     : 3;     //!< bits 2:0 Current sense amplifier OCP fault status
      uint16_t CP_FLT         : 1;     //!< bits 3:3 Charge pumps fault status
      uint16_t DVDD_OCP_FLT   : 1;     //!< bits 4:4 DVDD OCP (Over-Current Protection) fault status
      uint16_t DVDD_UV_FLT    : 1;     //!< bits 5:5 DVDD UVLO (Under-Voltage Lock-Out) fault status
      uint16_t DVDD_OV_FLT    : 1;     //!< bits 6:6 DVDD OVLO (Over-Voltage Lock-Out)fault status
      uint16_t BK_OCP_FLT     : 1;     //!< bits 7:7 Buck OCP fault status
      uint16_t OTS_FLT        : 1;     //!< bits 8:8 Over-temperature shutdown fault status
      uint16_t OTW_FLT        : 1;     //!< bits 9:9 Over-temperature warning status
      uint16_t RLOCK_FLT      : 1;     //!< bits 10:10 Locked rotor fault status
      uint16_t WD_FLT         : 1;     //!< bits 11:11 Watchdog fault status
      uint16_t OTP_FLT        : 1;     //!< bits 12:12 OTP status
      uint16_t RESERVED0      : 1;     //!< bits 15:13 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}fault_st_t;

typedef struct                         //!< Temperature status 0x01
{
  union
  {
    struct
    {
      uint16_t TEMP_VAL       : 7;     //!< bits 6:0 Temperature reading
      uint16_t RESERVED0      : 9;     //!< bits 15:7 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}temp_st_t;

typedef struct                         //!< Power supply status 0x02
{
  union
  {
    struct
    {
      uint16_t VCCLS_UVST     : 1;     //!< bits 0:0 Charge Pump low side UVLO status
      uint16_t VCCHS_UVST     : 1;     //!< bits 1:1 Charge Pump high side UVLO status
      uint16_t DVDD_UVST      : 1;     //!< bits 2:2 DVDD UVLO status
      uint16_t DVDD_OVST      : 1;     //!< bits 3:3 DVDD OVLO (Over-Voltage Lock-Out) status
      uint16_t VDDB_UVST      : 1;     //!< bits 4:4 VDDB UVLO status
      uint16_t VDDB_OVST      : 1;     //!< bits 5:5 VDDB OVLO status
      uint16_t PVDD_VAL       : 7;     //!< bits 12:6 PVDD ADC result reading value
      uint16_t RESERVED0      : 3;     //!< bits 15:13 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}supply_st_t;

typedef struct                         //!< Functional status 0x03
{
  union
  {
    struct
    {
      uint16_t HALLIN_ST      : 3;     //!< bits 2:0 Hall sensor inputs status
      uint16_t HALLPOL_ST     : 1;     //!< bits 3:3 Hall sensor polarity equal indicator
      uint16_t DVDD_ST        : 1;     //!< bits 4:4 DVDD set point status
      uint16_t CS_GAIN_ST     : 3;     //!< bits 7:5 Status of the current sense amplifiers gain
      uint16_t RESERVED0      : 8;     //!< bits 15:8 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}func_st_t;

typedef struct                         //!< OTP status 0x04
{
  union
  {
    struct
    {
      uint16_t OTP_USED       : 1;     //!< bits 0:0 OTP used
      uint16_t OTP_PASS       : 1;     //!< bits 1:1 User OTP programming status
      uint16_t OTP_PROG_BLOCK : 1;     //!< bits 1:1 User OTP programming blocked
      uint16_t OTP_PROG_FAIL  : 1;     //!< bits 1:1 OTP Programming fail
      uint16_t RESERVED0      : 12;    //!< bits 15:4 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}otp_st_t;

typedef struct                         //!< ADC status 0x05
{
  union
  {
    struct
    {
      uint16_t ADC_OD_RDY     : 1;     //!< bits 0:0 ADC on demand conversion result ready
      uint16_t ADC_OD_VAL     : 7;     //!< bits 7:1 ADC on demand result value
      uint16_t RESERVED0      : 8;     //!< bits 15:8 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}adc_st_t;

typedef struct                         //!< Charge pumps status 0x06
{
  union
  {
    struct
    {
      uint16_t VCCHS_VAL      : 7;     //!< bits 6:0 VCCHS ADC result reading value
      uint16_t VCCLS_VAL      : 7;     //!< bits 13:7 VCCLS ADC result reading value
      uint16_t RESERVED0      : 2;     //!< bits 15:14 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}cp_st_t;

typedef struct                         //!< Device ID 0x07
{
  union
  {
    struct
    {
      uint16_t DEV_ID         : 4;     //!< bits 3:0 Device ID
      uint16_t ADCTV_Y        : 12;    //!< bits 15:4 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}device_id_t;

typedef struct                         //!< Fault clear 0x10
{
  union
  {
    struct
    {
      uint16_t CLR_FLTS       : 1;     //!< bits 0:0 Clear all faults
      uint16_t CLR_LATCH      : 1;     //!< bits 1:1 Clear all latched faults
      uint16_t RESERVED0      : 14;    //!< bits 15:2 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}fault_clr_t;

typedef struct                         //!< Power supply configuration 0x11
{
  union
  {
    struct
    {
      uint16_t PVCC_SETPT       : 2;   //!< bits 1;0 PVCC set point
      uint16_t CS_REF_CFG       : 2;   //!< bits 3:2 Current sense reference configuration (internal VREF voltage)
      uint16_t DVDD_OCP_CFG     : 2;   //!< bits 5:4 DVDD OCP threshold configuration
      uint16_t DVDD_SFTSTRT     : 4;   //!< bits 9:6 DVDD soft-start configuration
      uint16_t DVDD_SETPT       : 2;   //!< bits 11:10 DVDD set point configuration
      uint16_t BK_FREQ          : 1;   //!< bits 12:12 Buck converter switching frequency selection
      uint16_t DVDD_TON_DELAY   : 2;   //!< bits 14:13 DVDD turn on delay configuration
      uint16_t CP_PRECHARGE_EN  : 1;   //!< bits 15:15 Charge pump pre-charge configuration
    };
    uint16_t reg;                      //!< the register value
  };
}supply_cfg_t;

typedef struct                         //!< ADC configuration 0x12
{
  union
  {
    struct
    {
      uint16_t ADC_OD_REQ         : 1; //!< bits 0:0 ADC on demand conversion request
      uint16_t ADC_OD_INSEL       : 2; //!< bits 2:1 ADC input selection for on demand conversions
      uint16_t ADC_EN_FILT        : 1; //!< bits 3:3 Enable filtering for on demand ADC measurement
      uint16_t ADC_FILT_CFG       : 2; //!< bits 5:4 ADC generic filtering configuration
      uint16_t ADC_FILT_CFG_PVDD  : 2; //!< bits 7:6 PVDD ADC measurement result filtering configuration
      uint16_t RESERVED0          : 8; //!< bits 15:8 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}adc_cfg_t;

typedef struct                         //!< PWM configuration 0x13
{
  union
  {
    struct
    {
      uint16_t PWM_MODE       : 3;     //!< bits 2:0 PWM commutation mode selection
      uint16_t PWM_FREEW_CFG  : 1;     //!< bits 3:3 PWM freewheeling configuration
      uint16_t BRAKE_CFG      : 2;     //!< bits 5:4 Brake configuration
      uint16_t PWM_RECIRC     : 1;     //!< bits 6:6 PWM recirculation selection (only if PWM_MODE = b011:)
      uint16_t RESERVED0      : 9;     //!< bits 15:7 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}pwm_cfg_t;

typedef struct                         //!< Sensor configuration 0x14
{
  union
  {
    struct
    {
      uint16_t HALL_DEGLITCH  : 4;     //!< bits 3:0 Hall Sensor deglitch
      uint16_t OTS_DIS        : 1;     //!< bits 4:4 Over-temperature shutdown disable
      uint16_t CS_TMODE       : 2;     //!< bits 6:5 Current sense amplifier timing mode
      uint16_t RESERVED0      : 9;     //!< bits 15:7 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}sensor_cfg_t;

typedef struct                         //!< Watchdog configuration 0x15
{
  union
  {
    struct
    {
      uint16_t WD_EN        : 1;       //!< bits 0:0 Watchdog enable
      uint16_t WD_INSEL     : 3;       //!< bits 3:1 Watchdog input selection
      uint16_t WD_FLTCFG    : 1;       //!< bits 4:4 Watchdog fault configuration
      uint16_t WD_TIMER_T   : 10;      //!< bits 14:5 Watchdog timer period value
      uint16_t RESERVED0    : 1;       //!< bits 15:15 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}wd_cfg_t;

typedef struct                         //!< Watchdog configuration 2 0x16
{
  union
  {
    struct
    {
      uint16_t WD_BRAKE           : 1; //!< bits 0:0 Brake on watchdog timer overflow
      uint16_t WD_EN_LATCH        : 1; //!< bits 1:1 Enable latching of watchdog fault
      uint16_t WD_DVDD_RSTRT_ATT  : 2; //!< bits 3:2 Restart delay for DVDD
      uint16_t WD_DVDD_RSTRT_DLY  : 4; //!< bits 7:4 DVDD restart delay
      uint16_t WD_RLOCK_EN        : 1; //!< bits 8:8 Enable rotor locked detection
      uint16_t WD_RLOCK_T         : 3; //!< bits 11:9 Rotor locked watchdog timeout
      uint16_t WD_BK_DIS          : 1; //!< bits 12:12 Buck watchdog disable
      uint16_t RESERVED0          : 3; //!< bits 15:13 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}wd_cfg2_t;

typedef struct                         //!< Gate driver current configuration 0x17
{
  union
  {
    struct
    {
      uint16_t IHS_SRC    : 4;         //!< bits 3:0 High-side source current (default b1011 - 200mA)
      uint16_t IHS_SINK   : 4;         //!< bits 7:4 High-side sink current (default b1011 - 200mA)
      uint16_t ILS_SRC    : 4;         //!< bits 11:8 Low-side source current (default b1011 - 200mA)
      uint16_t ILS_SINK   : 4;         //!< bits 15:12 Low-side sink current (default b1011 - 200mA)
    };
    uint16_t reg;                      //!< the register value
  };
}idrive_cfg_t;

typedef struct                         //!< Pre-charge gate driver current configuration 0x18
{
  union
  {
    struct
    {
      uint16_t I_PRE_SRC  : 4;         //!< bits 3:0 Pre-charge source current setting (TDRIVE1) (default b1011 - 200mA)
      uint16_t I_PRE_SINK : 4;         //!< bits 7:4 Pre-charge sink current setting (TDRIVE3) (default b1011 - 200mA)
      uint16_t I_PRE_EN   : 1;         //!< bits 8:8 Gate driver pre-charge mode enable
      uint16_t RESERVED0  : 7;         //!< bits 15:9 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
}idrive_pre_cfg_t;

typedef struct                         //!< Gate driver sourcing timing configuration 0x19
{
  union
  {
    struct
    {
      uint16_t TDRIVE1  : 8;           //!< bits 7:0 TDRIVE1 timing
      uint16_t TDRIVE2  : 8;           //!< bits 15:8 TDRIVE2 timing
    };
    uint16_t reg;                      //!< the register value
  };
}tdrive_src_cfg_t;

typedef struct                         //!< Gate driver sinking timing configuration 0x1A
{
  union
  {
    struct
    {
      uint16_t TDRIVE3  : 8;           //!< bits 7:0 TDRIVE3 timing
      uint16_t TDRIVE4  : 8;           //!< bits 15:8 TDRIVE4 timing
    };
    uint16_t reg;                      //!< the register value
  };
}tdrive_sink_cfg_t;

typedef struct                         //!< Dead time configuration 0x1B
{
  union
  {
    struct
    {
      uint16_t DT_RISE  : 8;           //!< bits 7:0 Dead time rise (of phase node voltage)
      uint16_t DT_FALL  : 8;           //!< bits 15:8 Dead time fall (of phase node voltage)
    };
    uint16_t reg;                      //!< the register value
  };
} dt_cfg_t;

typedef struct                         //!< Charge pump configuration 0x1C
{
  union
  {
    struct
    {
      uint16_t CP_CLK_CFG     : 2;     //!< bits 1:0 Charge pump clock frequency configuration
      uint16_t CP_CLK_SS_DIS  : 1;     //!< bits 2:2 Charge pump clock spread spectrum disable
      uint16_t RESERVED0      : 13;    //!< bits 15:3 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
} cp_cfg_t;

typedef struct                         //!< Current sense amplifier configuration 0x1D
{
  union
  {
    struct
    {
      uint16_t CS_GAIN          : 3;   //!< bits 2:0 Gain of current sense amplifiers
      uint16_t CS_GAIN_ANA      : 1;   //!< bits 3:3 CS Gain analogue programming enable
      uint16_t CS_EN            : 3;   //!< bits 6:4 Enable of each current shunt amplifier
      uint16_t CS_BLANK         : 4;   //!< bits 10:7 Current shunt amplifier blanking time
      uint16_t CS_EN_DCCAL      : 1;   //!< bits 11:11 Enable DC Calibration of CS amplifier
      uint16_t CS_OCP_DEGLITCH  : 2;   //!< bits 13:12 Current sense amplifier OCP deglitch
      uint16_t CS_OCPFLT_CFG    : 2;   //!< bits 15:14 Current sense amplifier OCP fault trigger configuration
    };
    uint16_t reg;                      //!< the register value
  };
} csamp_cfg_t;

typedef struct                         //!< Current sense amplifier configuration 2 0x1E
{
  union
  {
    struct
    {
      uint16_t CS_OCP_PTHR      : 4;   //!< bits 3:0 Current sense amplifier OCP positive thresholds
      uint16_t CS_OCP_NTHR      : 4;   //!< bits 7:4 Current sense amplifier OCP negative thresholds
      uint16_t CS_OCP_LATCH     : 1;   //!< bits 8:8 OCP latch choice
      uint16_t CS_MODE          : 1;   //!< bits 9:9 Current sense amplifier sensing mode
      uint16_t CS_OCP_BRAKE     : 1;   //!< bits 10:10 Current sense amplifier brake on OCP configuration
      uint16_t CS_TRUNC_DIS     : 1;   //!< bits 11:11 PWM truncation disable
      uint16_t VREF_INSEL       : 1;   //!< bits 12:12 VREF source selection
      uint16_t CS_NEG_OCP_DIS   : 1;   //!< bits 13:13 Current sense negative OCP disable
      uint16_t CS_AZ_CFG        : 2;   //!< bits 15:14 Current sense Auto-Zero configuration
    };
    uint16_t reg;                      //!< the register value
  };
} csamp_cfg2_t;

typedef struct                         //!< OTP program 0x1F
{
  union
  {
    struct
    {
      uint16_t OTP_PROG     : 1;       //!< bits 0:0 Program OTP
      uint16_t USER_ID      : 4;       //!< bits 4:1 User ID
      uint16_t RESERVED0    : 11;      //!< bits 15:5 Reserved
    };
    uint16_t reg;                      //!< the register value
  };
} otp_prog_t;

typedef struct
{
  union
  {
    uint16_t registers[MAX_NUM_REG_6EDL7141]; //!< raw register memory 
    struct
    {
      fault_st_t FAULT_ST;             //!< Fault and warning status 0x00
      temp_st_t TEMP_ST;               //!< Temperature status 0x01
      supply_st_t SUPPLY_ST;           //!< Power supply status 0x02
      func_st_t FUNC_ST;               //!< Functional status 0x03
      otp_st_t OTP_ST;                 //!< OTP status 0x04
      adc_st_t ADC_ST;                 //!< ADC status 0x05
      cp_st_t CP_ST;                   //!< Charge pumps status 0x06
      device_id_t DEVICE_ID;           //!< Device ID 0x07
      uint16_t reserved1[8];
      fault_clr_t FAULT_CLR;           //!< Fault clear 0x10
      supply_cfg_t SUPPLY_CFG;         //!< Power supply configuration 0x11
      adc_cfg_t ADC_CFG;               //!< ADC configuration 0x12
      pwm_cfg_t PWM_CFG;               //!< PWM configuration 0x13
      sensor_cfg_t SENSOR_CFG;         //!< Sensor configuration 0x14
      wd_cfg_t WD_CFG;                 //!< Watchdog configuration 0x15
      wd_cfg2_t WD_CFG2;               //!< Watchdog configuration 2 0x16
      idrive_cfg_t IDRIVE_CFG;         //!< Gate driver current configuration 0x17
      idrive_pre_cfg_t IDRIVE_PRE_CFG; //!< Pre-charge gate driver current configuration 0x18
      tdrive_src_cfg_t TDRIVE_SRC_CFG; //!< Gate driver sourcing timing configuration 0x19
      tdrive_sink_cfg_t TDRIVE_SINK_CFG; //!< Gate driver sinking timing configuration 0x1A
      dt_cfg_t DT_CFG;                 //!< Dead time configuration 0x1B
      cp_cfg_t CP_CFG;                 //!< Charge pump configuration 0x1C
      csamp_cfg_t CSAMP_CFG;           //!< Current sense amplifier configuration 0x1D
      csamp_cfg2_t CSAMP_CFG2;         //!< Current sense amplifier configuration 2 0x1E
      otp_prog_t OTP_PROG;
    };
  };
} reg6EDL7141_t;

reg6EDL7141_t _6EDL7141_Register;      //!< sensor register read and separation

#endif /* IFX_6EDL7141_REG_H */
