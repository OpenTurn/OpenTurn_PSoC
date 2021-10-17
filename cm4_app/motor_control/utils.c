/*
 * utils.c
 *
 *  Created on: 21.02.2021
 *      Author: achim
 */

#include "utils.h"


float limit_F32(float val, float limit)
{
    if(val > limit)
    {
        return limit;
    }
    if(val < -limit)
    {
        return -limit;
    }

    return val;
}

int32_t limit_I32(int32_t val, int32_t limit)
{
    if(val > limit)
    {
        return limit;
    }
    if(val < -limit)
    {
        return -limit;
    }

    return val;
}

uint32_t limit_U32(uint32_t val, uint32_t limit)
{
    if(val > limit)
    {
        return limit;
    }

    return val;
}


float facosf(float x)
{
   return (((-0.69813170079773212f * x * x - 0.87266462599716477f) * x) * 180.0f / 1.5707963267948966f) + 180.0f;
}

float fatanf(float x)
{
    return (M_PI_4 * x - x * (fabsf(x) - 1.0f) * (0.2447f + 0.0663f * fabsf(x))) * 180.0f / M_PI;
}


void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int intToStr(int x, char str[], int d)
{
    int i = 0;
    do {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    } while (x);

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}

char ftoa_temp_array[30];
char* ftoa(float n, int afterpoint)
{
    int i = 0;

    if(n <0.0f)
    {
      ftoa_temp_array[i++] = '-';
      n = fabsf(n);
    }

    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    i += intToStr(ipart, ftoa_temp_array + i, 0);

    // check for display option after point
    if (afterpoint != 0) {
        ftoa_temp_array[i] = '.'; // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter
        // is needed to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, ftoa_temp_array + i + 1, afterpoint);
    }

    return &ftoa_temp_array[0];
}

void Print_MotorParamHeader(void)
{
  PrintDebug("\r\ntorque_set");
  PrintDebug(";position");
  PrintDebug(";MotorSVPWM.i_a");
  PrintDebug(";MotorSVPWM.i_b");
  PrintDebug(";i_alpha");
  PrintDebug(";i_beta");
  PrintDebug(";i_d_error");
  PrintDebug(";i_q_error");
  PrintDebug(";i_d");
  PrintDebug(";i_q");
  PrintDebug(";v_d");
  PrintDebug(";v_q");
  PrintDebug(";v_alpha");
  PrintDebug(";v_beta");
  PrintDebug(";v_pwm1");
  PrintDebug(";v_pwm2");
  PrintDebug(";v_pwm3");

  return;
}

void Print_MotorParam(stc_motor_param_t params)
{
  union{
    uint32_t u_data;
    float f_data;
  }temp;

  temp.f_data = params.torque_set;
  PrintDebugStrH32("\r\n", temp.u_data);

  temp.f_data = params.position;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.i_a;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.i_b;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.i_alpha;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.i_beta;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.i_d_error;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.i_q_error;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.i_d;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.i_q;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.v_d;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.v_q;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.v_alpha;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.v_beta;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.v_pwm1;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.v_pwm2;
  PrintDebugStrH32(";", temp.u_data);

  temp.f_data = params.MotorSVPWM.v_pwm3;
  PrintDebugStrH32(";", temp.u_data);

  return;
}
