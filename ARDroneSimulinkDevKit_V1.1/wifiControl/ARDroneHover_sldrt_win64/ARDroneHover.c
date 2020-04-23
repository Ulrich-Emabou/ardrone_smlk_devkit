/*
 * ARDroneHover.c
 *
 * Code generation for model "ARDroneHover".
 *
 * Model version              : $Id: UAV_PIL.mdl 965 2013-03-21 01:08:53Z escobar $
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sat Feb  1 22:21:05 2020
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ARDroneHover.h"
#include "ARDroneHover_private.h"
#include "ARDroneHover_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  3.232235777E+9,
  5554.0,
};

/* options for Simulink Desktop Real-Time board 1 */
static double SLDRTBoardOptions1[] = {
  3.232235777E+9,
  5556.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 2;
const double SLDRTTimers[4] = {
  0.065, 0.0,
  0.65, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 2;
SLDRTBOARD SLDRTBoards[2] = {
  { "Standard_Devices/UDP_Protocol", 5554U, 2, SLDRTBoardOptions0 },

  { "Standard_Devices/UDP_Protocol", 5556U, 2, SLDRTBoardOptions1 },
};

/* Block signals (auto storage) */
B_ARDroneHover_T ARDroneHover_B;

/* Continuous states */
X_ARDroneHover_T ARDroneHover_X;

/* Block states (auto storage) */
DW_ARDroneHover_T ARDroneHover_DW;

/* Real-time model */
RT_MODEL_ARDroneHover_T ARDroneHover_M_;
RT_MODEL_ARDroneHover_T *const ARDroneHover_M = &ARDroneHover_M_;

/* Forward declaration for local functions */
static void ARDroneHover_dec2hex(const uint8_T d[4], char_T s_data[], int32_T
  s_size[2]);
static real_T ARDroneHover_hex2dec(const char_T s_data[], const int32_T s_size[2]);
static real_T ARDroneHover_rt_powd_snf(real_T u0, real_T u1);
static void ARDroneHover_getString(real_T a, char_T strOut_data[], int32_T
  strOut_size[2]);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(ARDroneHover_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(ARDroneHover_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (ARDroneHover_M->Timing.TaskCounters.TID[1] == 0) {
    ARDroneHover_M->Timing.RateInteraction.TID1_2 =
      (ARDroneHover_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    ARDroneHover_M->Timing.perTaskSampleHits[5] =
      ARDroneHover_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ARDroneHover_M->Timing.TaskCounters.TID[2])++;
  if ((ARDroneHover_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.65s, 0.0s] */
    ARDroneHover_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  ARDroneHover_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S1>/ARDrone data decoding' */
static void ARDroneHover_dec2hex(const uint8_T d[4], char_T s_data[], int32_T
  s_size[2])
{
  uint8_T di;
  uint8_T r;
  int32_T j;
  int32_T firstcol;
  boolean_T p;
  boolean_T exitg1;
  boolean_T exitg2;
  s_size[0] = 4;
  s_size[1] = 2;
  for (j = 0; j < 8; j++) {
    s_data[j] = '0';
  }

  di = d[0];
  j = 2;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    r = di;
    di = (uint8_T)((uint32_T)di >> 4);
    r = (uint8_T)((uint32_T)r - (di << 4));
    if (r > 9) {
      r = (uint8_T)(r + 7U);
    }

    s_data[(j - 1) << 2] = (int8_T)(r + 48);
    if (di > 0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  di = d[1];
  j = 2;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    r = di;
    di = (uint8_T)((uint32_T)di >> 4);
    r = (uint8_T)((uint32_T)r - (di << 4));
    if (r > 9) {
      r = (uint8_T)(r + 7U);
    }

    s_data[1 + ((j - 1) << 2)] = (int8_T)(r + 48);
    if (di > 0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  di = d[2];
  j = 2;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    r = di;
    di = (uint8_T)((uint32_T)di >> 4);
    r = (uint8_T)((uint32_T)r - (di << 4));
    if (r > 9) {
      r = (uint8_T)(r + 7U);
    }

    s_data[2 + ((j - 1) << 2)] = (int8_T)(r + 48);
    if (di > 0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  di = d[3];
  j = 2;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    r = di;
    di = (uint8_T)((uint32_T)di >> 4);
    r = (uint8_T)((uint32_T)r - (di << 4));
    if (r > 9) {
      r = (uint8_T)(r + 7U);
    }

    s_data[3 + ((j - 1) << 2)] = (int8_T)(r + 48);
    if (di > 0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  firstcol = 2;
  j = 1;
  exitg1 = false;
  while ((!exitg1) && (j <= 1)) {
    p = false;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j <= 3)) {
      if (s_data[j] != '0') {
        p = true;
        exitg2 = true;
      } else {
        j++;
      }
    }

    if (p) {
      firstcol = 1;
      exitg1 = true;
    } else {
      j = 2;
    }
  }

  if (firstcol > 1) {
    s_data[0] = s_data[4];
    s_data[1] = s_data[5];
    s_data[2] = s_data[6];
    s_data[3] = s_data[7];
    s_size[0] = 4;
    s_size[1] = 1;
  }
}

/* Function for MATLAB Function: '<S1>/ARDrone data decoding' */
static real_T ARDroneHover_hex2dec(const char_T s_data[], const int32_T s_size[2])
{
  real_T x;
  int32_T j;
  int32_T b;
  int32_T b_j;
  x = 0.0;
  ARDroneHover_B.p16 = 1.0;
  b = (int32_T)(((-1.0 - (real_T)s_size[1]) + 1.0) / -1.0);
  for (b_j = 1; b_j - 1 < b; b_j++) {
    j = s_size[1] - b_j;
    if (s_data[s_size[0] * j] != ' ') {
      j = (uint8_T)s_data[s_size[0] * j];
      if ((j != 0) && (j != 48)) {
        if (!(j <= 57)) {
          if (j > 70) {
            j -= 39;
          } else {
            j -= 7;
          }
        }

        x += ((real_T)j - 48.0) * ARDroneHover_B.p16;
      }

      ARDroneHover_B.p16 *= 16.0;
    }
  }

  return x;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static real_T ARDroneHover_rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    ARDroneHover_B.d0 = fabs(u0);
    ARDroneHover_B.d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (ARDroneHover_B.d0 == 1.0) {
        y = 1.0;
      } else if (ARDroneHover_B.d0 > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (ARDroneHover_B.d1 == 0.0) {
      y = 1.0;
    } else if (ARDroneHover_B.d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S7>/Drone state request' */
static void ARDroneHover_getString(real_T a, char_T strOut_data[], int32_T
  strOut_size[2])
{
  int32_T d;
  int32_T k;
  int32_T digit_size_idx_1;
  d = 0;
  if ((a >= 10.0) && (a < 100.0)) {
    d = 1;
  }

  if ((a >= 100.0) && (a < 1000.0)) {
    d = 2;
  }

  if ((a >= 1000.0) && (a < 10000.0)) {
    d = 3;
  }

  if ((a >= 10000.0) && (a < 100000.0)) {
    d = 4;
  }

  if ((a >= 100000.0) && (a < 1.0E+6)) {
    d = 5;
  }

  if ((a >= 1.0E+6) && (a < 1.0E+7)) {
    d = 6;
  }

  if ((a >= 1.0E+7) && (a < 1.0E+8)) {
    d = 7;
  }

  if ((a >= 1.0E+8) && (a < 1.0E+9)) {
    d = 8;
  }

  if ((a >= 1.0E+9) && (a < 1.0E+10)) {
    d = 9;
  }

  if (a >= 1.0E+10) {
    d = 10;
  }

  digit_size_idx_1 = d + 1;
  if (0 <= d) {
    memset(&ARDroneHover_B.digit_data[0], 0, (d + 1) * sizeof(uint8_T));
  }

  for (k = 0; k <= d; k++) {
    if (!rtIsInf(a)) {
      if (a == 0.0) {
        ARDroneHover_B.r = 0.0;
      } else {
        ARDroneHover_B.r = fmod(a, ARDroneHover_rt_powd_snf(10.0, 1.0 + (real_T)
          k));
        if (ARDroneHover_B.r == 0.0) {
          ARDroneHover_B.r = 0.0;
        }
      }
    } else {
      ARDroneHover_B.r = (rtNaN);
    }

    ARDroneHover_B.digit_data[d - k] = (uint8_T)(int8_T)(ARDroneHover_B.r /
      ARDroneHover_rt_powd_snf(10.0, (1.0 + (real_T)k) - 1.0) + 48.0);
  }

  strOut_size[0] = 1;
  strOut_size[1] = digit_size_idx_1;
  for (d = 0; d < digit_size_idx_1; d++) {
    strOut_data[d] = (int8_T)ARDroneHover_B.digit_data[d];
  }
}

/* Model output function for TID0 */
void ARDroneHover_output0(void)        /* Sample time: [0.0s, 0.0s] */
{
  static const char_T c[10] = { 'A', 'T', '*', 'C', 'O', 'N', 'F', 'I', 'G', '='
  };

  static const char_T d[30] = { ',', '\"', 'g', 'e', 'n', 'e', 'r', 'a', 'l',
    ':', 'n', 'a', 'v', 'd', 'a', 't', 'a', '_', 'd', 'e', 'm', 'o', '\"', ',',
    '\"', 'T', 'R', 'U', 'E', '\"' };

  static const char_T e[10] = { 'A', 'T', '*', 'C', 'O', 'M', 'W', 'D', 'G', '='
  };

  static const char_T f[7] = { 'A', 'T', '*', 'R', 'E', 'F', '=' };

  static const char_T h[30] = { '\"', 'c', 'o', 'n', 'r', 'o', 'l', ':', 'a',
    'l', 't', 'i', 't', 'u', 'd', 'e', '_', 'm', 'a', 'x', '\"', ',', '\"', '1',
    '0', '0', '0', '0', '0', '\"' };

  static const char_T i[9] = { 'A', 'T', '*', 'F', 'T', 'R', 'I', 'M', '=' };

  static const char_T j[10] = { ',', '2', '9', '0', '7', '1', '8', '2', '0', '8'
  };

  int32_T loop_ub;
  uint32_T x;
  boolean_T guard1 = false;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    /* set solver stop time */
    if (!(ARDroneHover_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ARDroneHover_M->solverInfo,
                            ((ARDroneHover_M->Timing.clockTickH0 + 1) *
        ARDroneHover_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ARDroneHover_M->solverInfo,
                            ((ARDroneHover_M->Timing.clockTick0 + 1) *
        ARDroneHover_M->Timing.stepSize0 + ARDroneHover_M->Timing.clockTickH0 *
        ARDroneHover_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ARDroneHover_M)) {
    ARDroneHover_M->Timing.t[0] = rtsiGetT(&ARDroneHover_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    /* S-Function (sldrtpi): '<S1>/Packet Input' */
    /* S-Function Block: <S1>/Packet Input */
    {
      uint8_T indata[500U];
      int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 500U,
        &ARDroneHover_ConstP.pooled6, (double*) indata, NULL);
      ARDroneHover_B.PacketInput_o2 = status & 0x1;/* Data Ready port */
      if (status & 0x1) {
        RTWin_ANYTYPEPTR indp;
        indp.p_uint8_T = indata;

        {
          int_T i1;
          uint8_T *y0 = &ARDroneHover_B.PacketInput_o1[0];
          for (i1=0; i1 < 500; i1++) {
            y0[i1] = *indp.p_uint8_T++;
          }
        }
      }
    }

    /* MATLAB Function: '<S1>/Data synchronization ' */
    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < 500; ARDroneHover_B.i++) {
      ARDroneHover_DW.buffer[(int32_T)(ARDroneHover_DW.countBuffer + ((real_T)
        ARDroneHover_B.i + 1.0)) - 1] =
        ARDroneHover_B.PacketInput_o1[ARDroneHover_B.i];
    }

    ARDroneHover_B.bytesToRead = ARDroneHover_DW.countBuffer + 500.0;
    ARDroneHover_B.aux = 0;
    exitg1 = false;
    while ((!exitg1) && (ARDroneHover_B.aux <= (int32_T)
                         (ARDroneHover_DW.countBuffer + 500.0) - 1)) {
      if ((ARDroneHover_DW.countHeader == 4.0) && (ARDroneHover_DW.count < 496.0))
      {
        ARDroneHover_B.bytesLeft = 496.0 - ARDroneHover_DW.count;
        ARDroneHover_B.b_tmp = (1.0 + (real_T)ARDroneHover_B.aux) + (496.0 -
          ARDroneHover_DW.count);
        if (1.0 + (real_T)ARDroneHover_B.aux > ARDroneHover_B.b_tmp - 1.0) {
          ARDroneHover_B.m = 1;
          ARDroneHover_B.loop_ub = 0;
        } else {
          ARDroneHover_B.m = ARDroneHover_B.aux + 1;
          ARDroneHover_B.loop_ub = (int32_T)(ARDroneHover_B.b_tmp - 1.0);
        }

        ARDroneHover_B.i = (int32_T)(ARDroneHover_DW.count + 1.0) - 1;
        ARDroneHover_B.loop_ub -= ARDroneHover_B.m;
        for (ARDroneHover_B.loop_ub_g = 0; ARDroneHover_B.loop_ub_g <=
             ARDroneHover_B.loop_ub; ARDroneHover_B.loop_ub_g++) {
          ARDroneHover_DW.frame[ARDroneHover_B.i + ARDroneHover_B.loop_ub_g] =
            ARDroneHover_DW.buffer[(ARDroneHover_B.m + ARDroneHover_B.loop_ub_g)
            - 1];
        }

        ARDroneHover_DW.count = 496.0;
        ARDroneHover_DW.countBuffer = (ARDroneHover_DW.countBuffer + 500.0) -
          ARDroneHover_B.bytesLeft;
        ARDroneHover_B.bytesLeft += 1.0 + (real_T)ARDroneHover_B.aux;
        if (ARDroneHover_B.bytesLeft > ARDroneHover_B.bytesToRead) {
          ARDroneHover_B.aux = 0;
          ARDroneHover_B.m = 0;
        } else {
          ARDroneHover_B.aux = (int32_T)ARDroneHover_B.bytesLeft - 1;
          ARDroneHover_B.m = (int32_T)ARDroneHover_B.bytesToRead;
        }

        ARDroneHover_B.loop_ub = ARDroneHover_B.m - ARDroneHover_B.aux;
        for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
             ARDroneHover_B.i++) {
          ARDroneHover_B.tmp_data[ARDroneHover_B.i] =
            ARDroneHover_DW.buffer[ARDroneHover_B.aux + ARDroneHover_B.i];
        }

        if (0 <= ARDroneHover_B.loop_ub - 1) {
          memcpy(&ARDroneHover_DW.buffer[0], &ARDroneHover_B.tmp_data[0],
                 ARDroneHover_B.loop_ub * sizeof(uint8_T));
        }

        exitg1 = true;
      } else if ((ARDroneHover_DW.countHeader == 3.0) &&
                 (ARDroneHover_DW.buffer[ARDroneHover_B.aux] == 85)) {
        ARDroneHover_DW.countHeader = 4.0;
        ARDroneHover_B.bytesLeft = (ARDroneHover_DW.countBuffer + 500.0) - (1.0
          + (real_T)ARDroneHover_B.aux);
        if (ARDroneHover_B.bytesLeft > 496.0) {
          ARDroneHover_DW.count = 496.0;
          for (ARDroneHover_B.i = 0; ARDroneHover_B.i < 496; ARDroneHover_B.i++)
          {
            ARDroneHover_DW.frame[(int16_T)ARDroneHover_B.i] =
              ARDroneHover_DW.buffer[(int32_T)((1.0 + (real_T)ARDroneHover_B.aux)
              + (real_T)(int16_T)(1 + ARDroneHover_B.i)) - 1];
          }

          ARDroneHover_DW.countBuffer = ((ARDroneHover_DW.countBuffer + 500.0) -
            (1.0 + (real_T)ARDroneHover_B.aux)) - 496.0;
          if (((1.0 + (real_T)ARDroneHover_B.aux) + 496.0) + 1.0 >
              ARDroneHover_B.bytesToRead) {
            ARDroneHover_B.aux = 0;
            ARDroneHover_B.m = 0;
          } else {
            ARDroneHover_B.aux = (int32_T)(((1.0 + (real_T)ARDroneHover_B.aux) +
              496.0) + 1.0) - 1;
            ARDroneHover_B.m = (int32_T)ARDroneHover_B.bytesToRead;
          }

          ARDroneHover_B.loop_ub = ARDroneHover_B.m - ARDroneHover_B.aux;
          for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
               ARDroneHover_B.i++) {
            ARDroneHover_B.tmp_data[ARDroneHover_B.i] =
              ARDroneHover_DW.buffer[ARDroneHover_B.aux + ARDroneHover_B.i];
          }

          if (0 <= ARDroneHover_B.loop_ub - 1) {
            memcpy(&ARDroneHover_DW.buffer[0], &ARDroneHover_B.tmp_data[0],
                   ARDroneHover_B.loop_ub * sizeof(uint8_T));
          }
        } else {
          ARDroneHover_DW.count = ARDroneHover_B.bytesLeft;
          if (ARDroneHover_DW.count > 0.0) {
            if ((1.0 + (real_T)ARDroneHover_B.aux) + 1.0 >
                ARDroneHover_DW.countBuffer + 500.0) {
              ARDroneHover_B.aux = 1;
              ARDroneHover_B.m = 0;
            } else {
              ARDroneHover_B.aux = (int32_T)((1.0 + (real_T)ARDroneHover_B.aux)
                + 1.0);
              ARDroneHover_B.m = (int32_T)(ARDroneHover_DW.countBuffer + 500.0);
            }

            ARDroneHover_B.loop_ub = ARDroneHover_B.m - ARDroneHover_B.aux;
            for (ARDroneHover_B.i = 0; ARDroneHover_B.i <=
                 ARDroneHover_B.loop_ub; ARDroneHover_B.i++) {
              ARDroneHover_DW.frame[ARDroneHover_B.i] = ARDroneHover_DW.buffer
                [(ARDroneHover_B.aux + ARDroneHover_B.i) - 1];
            }
          }

          ARDroneHover_DW.countBuffer = 0.0;
        }

        exitg1 = true;
      } else {
        if ((ARDroneHover_DW.countHeader == 2.0) &&
            (ARDroneHover_DW.buffer[ARDroneHover_B.aux] == 102)) {
          ARDroneHover_DW.countHeader = 3.0;
        }

        if ((ARDroneHover_DW.countHeader == 1.0) &&
            (ARDroneHover_DW.buffer[ARDroneHover_B.aux] == 119)) {
          ARDroneHover_DW.countHeader = 2.0;
        }

        if ((ARDroneHover_DW.countHeader == 0.0) &&
            (ARDroneHover_DW.buffer[ARDroneHover_B.aux] == 136)) {
          ARDroneHover_DW.countHeader = 1.0;
        }

        ARDroneHover_B.aux++;
      }
    }

    if (ARDroneHover_DW.count == 496.0) {
      for (ARDroneHover_B.i = 0; ARDroneHover_B.i < 496; ARDroneHover_B.i++) {
        ARDroneHover_DW.lastFrame[ARDroneHover_B.i] =
          ARDroneHover_DW.frame[ARDroneHover_B.i];
        ARDroneHover_DW.frame[ARDroneHover_B.i] = 0U;
      }

      ARDroneHover_DW.count = 0.0;
      ARDroneHover_DW.countHeader = 0.0;
    }

    /* MATLAB Function: '<S1>/ARDrone data decoding' incorporates:
     *  MATLAB Function: '<S1>/Data synchronization '
     */
    memcpy(&ARDroneHover_B.data[0], &ARDroneHover_DW.lastFrame[0], 496U * sizeof
           (uint8_T));
    if (ARDroneHover_DW.lastFrame[14] == 148) {
      memcpy(&ARDroneHover_DW.dataPrev[0], &ARDroneHover_DW.lastFrame[0], 496U *
             sizeof(uint8_T));
    } else {
      memcpy(&ARDroneHover_B.data[0], &ARDroneHover_DW.dataPrev[0], 496U *
             sizeof(uint8_T));
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < 32; ARDroneHover_B.i++) {
      ARDroneHover_B.status[ARDroneHover_B.i] = 0;
    }

    ARDroneHover_dec2hex(&ARDroneHover_B.data[0], ARDroneHover_B.hex_data,
                         ARDroneHover_B.hex_size);
    ARDroneHover_B.loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.m = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.loop_ub_g = ARDroneHover_B.hex_size[1];
    loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.aux = ((ARDroneHover_B.hex_size[1] + ARDroneHover_B.hex_size
      [1]) + ARDroneHover_B.hex_size[1]) + ARDroneHover_B.hex_size[1];
    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        3];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.m;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i + ARDroneHover_B.loop_ub] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        2];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub_g;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[(ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m] = ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] *
        ARDroneHover_B.i + 1];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < loop_ub; ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[((ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m) + ARDroneHover_B.loop_ub_g] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i];
    }

    ARDroneHover_B.m = 0;
    while (ARDroneHover_B.m <= ARDroneHover_B.aux - 1) {
      if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == 'F') {
        ARDroneHover_B.status[((1 + ARDroneHover_B.m) << 2) - 4] = 1;
        ARDroneHover_B.status[((1 + ARDroneHover_B.m) << 2) - 3] = 1;
        ARDroneHover_B.status[((1 + ARDroneHover_B.m) << 2) - 2] = 1;
        ARDroneHover_B.status[((1 + ARDroneHover_B.m) << 2) - 1] = 1;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == 'E') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 0;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == 'D') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 1;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == 'C') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 0;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == 'B') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 1;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == 'A') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 0;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == '9') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 1;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == '8') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 0;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == '7') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 1;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == '6') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 0;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == '5') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 1;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == '4') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 0;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == '3') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 1;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == '2') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 1;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 0;
      } else if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == '1') {
        ARDroneHover_B.i = ((1 + ARDroneHover_B.m) << 2) - 4;
        ARDroneHover_B.status[ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[1 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[2 + ARDroneHover_B.i] = 0;
        ARDroneHover_B.status[3 + ARDroneHover_B.i] = 1;
      } else {
        if (ARDroneHover_B.b_hex_data[ARDroneHover_B.m] == '0') {
          ARDroneHover_B.status[((1 + ARDroneHover_B.m) << 2) - 4] = 0;
          ARDroneHover_B.status[((1 + ARDroneHover_B.m) << 2) - 3] = 0;
          ARDroneHover_B.status[((1 + ARDroneHover_B.m) << 2) - 2] = 0;
          ARDroneHover_B.status[((1 + ARDroneHover_B.m) << 2) - 1] = 0;
        }
      }

      ARDroneHover_B.m++;
    }

    ARDroneHover_dec2hex(&ARDroneHover_B.data[20], ARDroneHover_B.hex_data,
                         ARDroneHover_B.hex_size);
    ARDroneHover_B.loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.m = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.loop_ub_g = ARDroneHover_B.hex_size[1];
    loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.hex_size_g[0] = 1;
    ARDroneHover_B.hex_size_g[1] = ((ARDroneHover_B.hex_size[1] +
      ARDroneHover_B.hex_size[1]) + ARDroneHover_B.hex_size[1]) +
      ARDroneHover_B.hex_size[1];
    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        3];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.m;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i + ARDroneHover_B.loop_ub] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        2];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub_g;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[(ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m] = ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] *
        ARDroneHover_B.i + 1];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < loop_ub; ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[((ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m) + ARDroneHover_B.loop_ub_g] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i];
    }

    /* DataTypeConversion: '<S1>/Type Conversion' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneHover_B.TypeConversion = ARDroneHover_hex2dec
      (ARDroneHover_B.b_hex_data, ARDroneHover_B.hex_size_g);

    /* MATLAB Function: '<S1>/ARDrone data decoding' */
    ARDroneHover_dec2hex(&ARDroneHover_B.data[24], ARDroneHover_B.hex_data,
                         ARDroneHover_B.hex_size);
    ARDroneHover_B.loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.m = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.loop_ub_g = ARDroneHover_B.hex_size[1];
    loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.hex_size_f[0] = 1;
    ARDroneHover_B.hex_size_f[1] = ((ARDroneHover_B.hex_size[1] +
      ARDroneHover_B.hex_size[1]) + ARDroneHover_B.hex_size[1]) +
      ARDroneHover_B.hex_size[1];
    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        3];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.m;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i + ARDroneHover_B.loop_ub] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        2];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub_g;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[(ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m] = ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] *
        ARDroneHover_B.i + 1];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < loop_ub; ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[((ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m) + ARDroneHover_B.loop_ub_g] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i];
    }

    ARDroneHover_B.bytesLeft = rt_roundd_snf(ARDroneHover_hex2dec
      (ARDroneHover_B.b_hex_data, ARDroneHover_B.hex_size_f));
    if (ARDroneHover_B.bytesLeft < 4.294967296E+9) {
      if (ARDroneHover_B.bytesLeft >= 0.0) {
        x = (uint32_T)ARDroneHover_B.bytesLeft;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&ARDroneHover_B.res, (void *)&x, (uint32_T)((size_t)1 *
            sizeof(real32_T)));
    ARDroneHover_dec2hex(&ARDroneHover_B.data[28], ARDroneHover_B.hex_data,
                         ARDroneHover_B.hex_size);
    ARDroneHover_B.loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.m = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.loop_ub_g = ARDroneHover_B.hex_size[1];
    loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.hex_size_cv[0] = 1;
    ARDroneHover_B.hex_size_cv[1] = ((ARDroneHover_B.hex_size[1] +
      ARDroneHover_B.hex_size[1]) + ARDroneHover_B.hex_size[1]) +
      ARDroneHover_B.hex_size[1];
    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        3];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.m;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i + ARDroneHover_B.loop_ub] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        2];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub_g;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[(ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m] = ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] *
        ARDroneHover_B.i + 1];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < loop_ub; ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[((ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m) + ARDroneHover_B.loop_ub_g] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i];
    }

    ARDroneHover_B.bytesLeft = rt_roundd_snf(ARDroneHover_hex2dec
      (ARDroneHover_B.b_hex_data, ARDroneHover_B.hex_size_cv));
    if (ARDroneHover_B.bytesLeft < 4.294967296E+9) {
      if (ARDroneHover_B.bytesLeft >= 0.0) {
        x = (uint32_T)ARDroneHover_B.bytesLeft;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&ARDroneHover_B.b_res, (void *)&x, (uint32_T)((size_t)1 *
            sizeof(real32_T)));
    ARDroneHover_dec2hex(&ARDroneHover_B.data[32], ARDroneHover_B.hex_data,
                         ARDroneHover_B.hex_size);
    ARDroneHover_B.loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.m = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.loop_ub_g = ARDroneHover_B.hex_size[1];
    loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.hex_size_p[0] = 1;
    ARDroneHover_B.hex_size_p[1] = ((ARDroneHover_B.hex_size[1] +
      ARDroneHover_B.hex_size[1]) + ARDroneHover_B.hex_size[1]) +
      ARDroneHover_B.hex_size[1];
    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        3];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.m;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i + ARDroneHover_B.loop_ub] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        2];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub_g;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[(ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m] = ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] *
        ARDroneHover_B.i + 1];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < loop_ub; ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[((ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m) + ARDroneHover_B.loop_ub_g] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i];
    }

    ARDroneHover_B.bytesLeft = rt_roundd_snf(ARDroneHover_hex2dec
      (ARDroneHover_B.b_hex_data, ARDroneHover_B.hex_size_p));
    if (ARDroneHover_B.bytesLeft < 4.294967296E+9) {
      if (ARDroneHover_B.bytesLeft >= 0.0) {
        x = (uint32_T)ARDroneHover_B.bytesLeft;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&ARDroneHover_B.yawAngle, (void *)&x, (uint32_T)((size_t)1 *
            sizeof(real32_T)));
    ARDroneHover_dec2hex(&ARDroneHover_B.data[36], ARDroneHover_B.hex_data,
                         ARDroneHover_B.hex_size);
    ARDroneHover_B.loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.m = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.loop_ub_g = ARDroneHover_B.hex_size[1];
    loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.hex_size_b[0] = 1;
    ARDroneHover_B.hex_size_b[1] = ((ARDroneHover_B.hex_size[1] +
      ARDroneHover_B.hex_size[1]) + ARDroneHover_B.hex_size[1]) +
      ARDroneHover_B.hex_size[1];
    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        3];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.m;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i + ARDroneHover_B.loop_ub] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        2];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub_g;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[(ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m] = ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] *
        ARDroneHover_B.i + 1];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < loop_ub; ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[((ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m) + ARDroneHover_B.loop_ub_g] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i];
    }

    ARDroneHover_B.bytesToRead = ARDroneHover_hex2dec(ARDroneHover_B.b_hex_data,
      ARDroneHover_B.hex_size_b) / 1000.0;
    ARDroneHover_dec2hex(&ARDroneHover_B.data[40], ARDroneHover_B.hex_data,
                         ARDroneHover_B.hex_size);
    ARDroneHover_B.loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.m = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.loop_ub_g = ARDroneHover_B.hex_size[1];
    loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.hex_size_cx[0] = 1;
    ARDroneHover_B.hex_size_cx[1] = ((ARDroneHover_B.hex_size[1] +
      ARDroneHover_B.hex_size[1]) + ARDroneHover_B.hex_size[1]) +
      ARDroneHover_B.hex_size[1];
    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        3];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.m;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i + ARDroneHover_B.loop_ub] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        2];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub_g;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[(ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m] = ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] *
        ARDroneHover_B.i + 1];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < loop_ub; ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[((ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m) + ARDroneHover_B.loop_ub_g] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i];
    }

    ARDroneHover_B.bytesLeft = rt_roundd_snf(ARDroneHover_hex2dec
      (ARDroneHover_B.b_hex_data, ARDroneHover_B.hex_size_cx));
    if (ARDroneHover_B.bytesLeft < 4.294967296E+9) {
      if (ARDroneHover_B.bytesLeft >= 0.0) {
        x = (uint32_T)ARDroneHover_B.bytesLeft;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&ARDroneHover_B.u, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));
    ARDroneHover_dec2hex(&ARDroneHover_B.data[44], ARDroneHover_B.hex_data,
                         ARDroneHover_B.hex_size);
    ARDroneHover_B.loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.m = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.loop_ub_g = ARDroneHover_B.hex_size[1];
    loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.hex_size_k[0] = 1;
    ARDroneHover_B.hex_size_k[1] = ((ARDroneHover_B.hex_size[1] +
      ARDroneHover_B.hex_size[1]) + ARDroneHover_B.hex_size[1]) +
      ARDroneHover_B.hex_size[1];
    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        3];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.m;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i + ARDroneHover_B.loop_ub] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        2];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub_g;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[(ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m] = ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] *
        ARDroneHover_B.i + 1];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < loop_ub; ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[((ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m) + ARDroneHover_B.loop_ub_g] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i];
    }

    ARDroneHover_B.bytesLeft = rt_roundd_snf(ARDroneHover_hex2dec
      (ARDroneHover_B.b_hex_data, ARDroneHover_B.hex_size_k));
    if (ARDroneHover_B.bytesLeft < 4.294967296E+9) {
      if (ARDroneHover_B.bytesLeft >= 0.0) {
        x = (uint32_T)ARDroneHover_B.bytesLeft;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&ARDroneHover_B.v, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));
    ARDroneHover_dec2hex(&ARDroneHover_B.data[48], ARDroneHover_B.hex_data,
                         ARDroneHover_B.hex_size);
    ARDroneHover_B.loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.m = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.loop_ub_g = ARDroneHover_B.hex_size[1];
    loop_ub = ARDroneHover_B.hex_size[1];
    ARDroneHover_B.hex_size_c[0] = 1;
    ARDroneHover_B.hex_size_c[1] = ((ARDroneHover_B.hex_size[1] +
      ARDroneHover_B.hex_size[1]) + ARDroneHover_B.hex_size[1]) +
      ARDroneHover_B.hex_size[1];
    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        3];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.m;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[ARDroneHover_B.i + ARDroneHover_B.loop_ub] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i +
        2];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub_g;
         ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[(ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m] = ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] *
        ARDroneHover_B.i + 1];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < loop_ub; ARDroneHover_B.i++) {
      ARDroneHover_B.b_hex_data[((ARDroneHover_B.i + ARDroneHover_B.loop_ub) +
        ARDroneHover_B.m) + ARDroneHover_B.loop_ub_g] =
        ARDroneHover_B.hex_data[ARDroneHover_B.hex_size[0] * ARDroneHover_B.i];
    }

    ARDroneHover_B.bytesLeft = rt_roundd_snf(ARDroneHover_hex2dec
      (ARDroneHover_B.b_hex_data, ARDroneHover_B.hex_size_c));
    if (ARDroneHover_B.bytesLeft < 4.294967296E+9) {
      if (ARDroneHover_B.bytesLeft >= 0.0) {
        x = (uint32_T)ARDroneHover_B.bytesLeft;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&ARDroneHover_B.w, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));
    if ((ARDroneHover_B.status[31] == 1) && (ARDroneHover_B.bytesToRead < 0.2))
    {
      ARDroneHover_B.bytesToRead = ARDroneHover_DW.hPrev;
    } else {
      if (ARDroneHover_B.status[31] == 1) {
        ARDroneHover_DW.hPrev = ARDroneHover_B.bytesToRead;
      }
    }

    ARDroneHover_B.yawAngle /= 1000.0F;
    ARDroneHover_B.u /= 1000.0F;
    ARDroneHover_B.v /= 1000.0F;
    ARDroneHover_B.w /= 1000.0F;

    /* DataTypeConversion: '<S1>/Type Conversion1' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneHover_B.TypeConversion1 = ARDroneHover_B.b_res / 1000.0F;

    /* DataTypeConversion: '<S1>/Type Conversion2' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneHover_B.TypeConversion2 = ARDroneHover_B.res / 1000.0F;

    /* MATLAB Function: '<S1>/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ' incorporates:
     *  DataTypeConversion: '<S1>/Type Conversion3'
     *  UnitDelay: '<S1>/Unit Delay to avoid algebraic loop'
     */
    ARDroneHover_B.yawOut = ARDroneHover_B.yawAngle;
    if ((ARDroneHover_DW.UnitDelaytoavoidalgebraicloop_DSTATE == 1.0) &&
        (ARDroneHover_DW.mode == 0.0)) {
      ARDroneHover_DW.yaw0 = ARDroneHover_B.yawAngle;
    }

    ARDroneHover_B.bytesLeft = ARDroneHover_B.yawOut;
    if ((!rtIsInf(ARDroneHover_B.yawOut)) && (!rtIsNaN(ARDroneHover_B.yawOut)))
    {
      if (ARDroneHover_B.yawOut == 0.0) {
        ARDroneHover_B.yawOut = 0.0;
      } else {
        ARDroneHover_B.yawOut = fmod(ARDroneHover_B.yawOut, 360.0);
        if (ARDroneHover_B.yawOut == 0.0) {
          ARDroneHover_B.yawOut = 0.0;
        } else {
          if (ARDroneHover_B.bytesLeft < 0.0) {
            ARDroneHover_B.yawOut += 360.0;
          }
        }
      }
    } else {
      ARDroneHover_B.yawOut = (rtNaN);
    }

    if (ARDroneHover_B.yawOut > 180.0) {
      ARDroneHover_B.yawOut += -360.0;
    }

    /* End of MATLAB Function: '<S1>/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ' */
    /* DataTypeConversion: '<S1>/Type Conversion4' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneHover_B.TypeConversion4 = ARDroneHover_B.bytesToRead;
  }

  /* Integrator: '<S17>/Integrator' */
  if (ARDroneHover_DW.Integrator_IWORK != 0) {
    ARDroneHover_X.Integrator_CSTATE[0] = 0.0;
    ARDroneHover_X.Integrator_CSTATE[1] = 0.0;
  }

  ARDroneHover_B.Integrator[0] = ARDroneHover_X.Integrator_CSTATE[0];
  ARDroneHover_B.Integrator[1] = ARDroneHover_X.Integrator_CSTATE[1];

  /* End of Integrator: '<S17>/Integrator' */
  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    /* Gain: '<Root>/deg 2 rad' */
    ARDroneHover_B.deg2rad[0] = 0.017453292519943295 *
      ARDroneHover_B.TypeConversion1;
    ARDroneHover_B.deg2rad[1] = 0.017453292519943295 *
      ARDroneHover_B.TypeConversion2;
    ARDroneHover_B.deg2rad[2] = 0.017453292519943295 * ARDroneHover_B.yawOut;

    /* DataTypeConversion: '<S1>/Type Conversion5' */
    ARDroneHover_B.TypeConversion5 = ARDroneHover_B.u;

    /* DataTypeConversion: '<S1>/Type Conversion6' */
    ARDroneHover_B.TypeConversion6 = ARDroneHover_B.v;

    /* DataTypeConversion: '<S1>/Type Conversion7' */
    ARDroneHover_B.TypeConversion7 = ARDroneHover_B.w;

    /* SignalConversion: '<S4>/TmpSignal ConversionAtTo WorkspaceInport1' */
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[0] =
      ARDroneHover_B.deg2rad[0];
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[1] =
      ARDroneHover_B.deg2rad[1];
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[2] =
      ARDroneHover_B.deg2rad[2];
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[3] =
      ARDroneHover_B.TypeConversion5;
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[4] =
      ARDroneHover_B.TypeConversion6;
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[5] =
      ARDroneHover_B.TypeConversion7;
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[6] =
      ARDroneHover_B.Integrator[0];
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[7] =
      ARDroneHover_B.Integrator[1];
    ARDroneHover_B.TmpSignalConversionAtToWorkspaceInport1[8] =
      ARDroneHover_B.TypeConversion4;

    /* Gain: '<S4>/deg 2 rad1' */
    ARDroneHover_B.deg2rad1 = 57.295779513082323 * ARDroneHover_B.deg2rad[2];
  }

  /* MATLAB Function: '<S15>/Coordinate trnasformation  from inertial frame to body frame ' incorporates:
   *  MATLAB Function: '<S17>/Velocity from vehicle body frame  to inertial NED  frame'
   */
  ARDroneHover_B.bytesToRead = cos(ARDroneHover_B.deg2rad[2]);
  ARDroneHover_B.bytesLeft = sin(ARDroneHover_B.deg2rad[2]);

  /* Gain: '<S14>/Gain1' incorporates:
   *  MATLAB Function: '<S15>/Coordinate trnasformation  from inertial frame to body frame '
   *  Sum: '<S14>/Sum5'
   *  Sum: '<S15>/Sum4'
   */
  ARDroneHover_B.b_tmp = (((1.0 - ARDroneHover_B.Integrator[0]) *
    -ARDroneHover_B.bytesLeft + (1.0 - ARDroneHover_B.Integrator[1]) *
    ARDroneHover_B.bytesToRead) - ARDroneHover_B.TypeConversion6) * 0.4;

  /* Saturate: '<S1>/Saturation 1' */
  if (ARDroneHover_B.b_tmp > 1.0) {
    ARDroneHover_B.Saturation1 = 1.0;
  } else if (ARDroneHover_B.b_tmp < -1.0) {
    ARDroneHover_B.Saturation1 = -1.0;
  } else {
    ARDroneHover_B.Saturation1 = ARDroneHover_B.b_tmp;
  }

  /* End of Saturate: '<S1>/Saturation 1' */

  /* Gain: '<S11>/Gain' incorporates:
   *  MATLAB Function: '<S15>/Coordinate trnasformation  from inertial frame to body frame '
   *  Sum: '<S11>/Sum2'
   *  Sum: '<S15>/Sum4'
   */
  ARDroneHover_B.b_tmp = (((1.0 - ARDroneHover_B.Integrator[0]) *
    ARDroneHover_B.bytesToRead + (1.0 - ARDroneHover_B.Integrator[1]) *
    ARDroneHover_B.bytesLeft) - ARDroneHover_B.TypeConversion5) * -0.5;

  /* Saturate: '<S1>/Saturation 2' */
  if (ARDroneHover_B.b_tmp > 1.0) {
    ARDroneHover_B.Saturation2 = 1.0;
  } else if (ARDroneHover_B.b_tmp < -1.0) {
    ARDroneHover_B.Saturation2 = -1.0;
  } else {
    ARDroneHover_B.Saturation2 = ARDroneHover_B.b_tmp;
  }

  /* End of Saturate: '<S1>/Saturation 2' */
  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    /* MATLAB Function: '<S7>/Drone state request' */
    memset(&ARDroneHover_B.dataControl[0], 0, 150U * sizeof(uint8_T));
    ARDroneHover_B.loop_ub_g = 0;
    guard1 = false;
    if (ARDroneHover_DW.SequenceNumber <= 1.0) {
      guard1 = true;
    } else {
      if (!rtIsInf(ARDroneHover_DW.SequenceNumber)) {
        ARDroneHover_B.b_tmp = fmod(ARDroneHover_DW.SequenceNumber, 100.0);
        if (ARDroneHover_B.b_tmp == 0.0) {
          ARDroneHover_B.b_tmp = 0.0;
        }
      } else {
        ARDroneHover_B.b_tmp = (rtNaN);
      }

      if (ARDroneHover_B.b_tmp == 0.0) {
        guard1 = true;
      }
    }

    if (guard1) {
      ARDroneHover_DW.SequenceNumber++;
      ARDroneHover_getString(ARDroneHover_DW.SequenceNumber,
        ARDroneHover_B.strCmd_data, ARDroneHover_B.hex_size);
      ARDroneHover_B.loop_ub_g = 41 + ARDroneHover_B.hex_size[1];
      for (ARDroneHover_B.i = 0; ARDroneHover_B.i < 10; ARDroneHover_B.i++) {
        ARDroneHover_B.cmd_data[ARDroneHover_B.i] = c[ARDroneHover_B.i];
      }

      ARDroneHover_B.loop_ub = ARDroneHover_B.hex_size[0] *
        ARDroneHover_B.hex_size[1];
      if (0 <= ARDroneHover_B.loop_ub - 1) {
        memcpy(&ARDroneHover_B.cmd_data[10], &ARDroneHover_B.strCmd_data[0],
               ARDroneHover_B.loop_ub * sizeof(char_T));
      }

      for (ARDroneHover_B.i = 0; ARDroneHover_B.i < 30; ARDroneHover_B.i++) {
        ARDroneHover_B.cmd_data[(ARDroneHover_B.i + ARDroneHover_B.loop_ub) + 10]
          = d[ARDroneHover_B.i];
      }

      ARDroneHover_B.cmd_data[40 + ARDroneHover_B.loop_ub] = '\x0d';
    }

    ARDroneHover_DW.SequenceNumber++;
    ARDroneHover_getString(ARDroneHover_DW.SequenceNumber,
      ARDroneHover_B.strCmd_data, ARDroneHover_B.hex_size);
    ARDroneHover_B.aux = ARDroneHover_B.loop_ub_g + 10;

    /* MATLAB Function: '<S7>/Drone state request' */
    ARDroneHover_B.m = ARDroneHover_B.hex_size[1];
    loop_ub = ARDroneHover_B.aux + ARDroneHover_B.hex_size[1];
    ARDroneHover_B.loop_ub_g = loop_ub + 1;
    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < 10; ARDroneHover_B.i++) {
      /* MATLAB Function: '<S7>/Drone state request' */
      ARDroneHover_B.cmd_data[(ARDroneHover_B.aux + ARDroneHover_B.i) - 10] =
        e[ARDroneHover_B.i];
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.m;
         ARDroneHover_B.i++) {
      /* MATLAB Function: '<S7>/Drone state request' */
      ARDroneHover_B.cmd_data[ARDroneHover_B.aux + ARDroneHover_B.i] =
        ARDroneHover_B.strCmd_data[ARDroneHover_B.i];
    }

    /* MATLAB Function: '<S7>/Drone state request' */
    ARDroneHover_B.cmd_data[loop_ub] = '\x0d';
    if ((ARDroneHover_DW.SequenceNumber > 20.0) &&
        (ARDroneHover_DW.SequenceNumber < 22.0)) {
      ARDroneHover_DW.SequenceNumber = 22.0;
      ARDroneHover_getString(22.0, ARDroneHover_B.strCmd_data,
        ARDroneHover_B.hex_size);
      loop_ub = ARDroneHover_B.loop_ub_g + ARDroneHover_B.hex_size[1];
      ARDroneHover_B.aux = loop_ub + 10;
      if (0 <= ARDroneHover_B.loop_ub_g - 1) {
        memcpy(&ARDroneHover_B.cmd_data_m[0], &ARDroneHover_B.cmd_data[0],
               ARDroneHover_B.loop_ub_g * sizeof(char_T));
      }

      for (ARDroneHover_B.i = 0; ARDroneHover_B.i < 9; ARDroneHover_B.i++) {
        ARDroneHover_B.cmd_data_m[ARDroneHover_B.i + ARDroneHover_B.loop_ub_g] =
          i[ARDroneHover_B.i];
      }

      ARDroneHover_B.loop_ub = ARDroneHover_B.hex_size[1];
      for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
           ARDroneHover_B.i++) {
        ARDroneHover_B.cmd_data_m[(ARDroneHover_B.i + ARDroneHover_B.loop_ub_g)
          + 9] = ARDroneHover_B.strCmd_data[ARDroneHover_B.hex_size[0] *
          ARDroneHover_B.i];
      }

      ARDroneHover_B.cmd_data_m[loop_ub + 9] = '\x0d';
      ARDroneHover_B.loop_ub_g = ARDroneHover_B.aux;
      if (0 <= ARDroneHover_B.aux - 1) {
        memcpy(&ARDroneHover_B.cmd_data[0], &ARDroneHover_B.cmd_data_m[0],
               ARDroneHover_B.aux * sizeof(char_T));
      }
    } else if ((ARDroneHover_DW.SequenceNumber >= 22.0) &&
               (ARDroneHover_DW.SequenceNumber < 25.0)) {
      ARDroneHover_B.aux = ARDroneHover_B.loop_ub_g + 10;
      ARDroneHover_B.m = ARDroneHover_B.hex_size[1];
      loop_ub = ARDroneHover_B.aux + ARDroneHover_B.hex_size[1];
      ARDroneHover_B.loop_ub_g = loop_ub + 31;
      for (ARDroneHover_B.i = 0; ARDroneHover_B.i < 10; ARDroneHover_B.i++) {
        ARDroneHover_B.cmd_data[(ARDroneHover_B.aux + ARDroneHover_B.i) - 10] =
          c[ARDroneHover_B.i];
      }

      for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.m;
           ARDroneHover_B.i++) {
        ARDroneHover_B.cmd_data[ARDroneHover_B.aux + ARDroneHover_B.i] =
          ARDroneHover_B.strCmd_data[ARDroneHover_B.i];
      }

      for (ARDroneHover_B.i = 0; ARDroneHover_B.i < 30; ARDroneHover_B.i++) {
        ARDroneHover_B.cmd_data[(ARDroneHover_B.aux + ARDroneHover_B.i) +
          ARDroneHover_B.m] = h[ARDroneHover_B.i];
      }

      ARDroneHover_B.cmd_data[loop_ub + 30] = '\x0d';
    } else {
      if ((ARDroneHover_DW.SequenceNumber >= 25.0) && (ARDroneHover_B.status[31]
           == 0)) {
        ARDroneHover_DW.SequenceNumber++;
        ARDroneHover_getString(ARDroneHover_DW.SequenceNumber,
          ARDroneHover_B.strCmd_data, ARDroneHover_B.hex_size);
        loop_ub = ARDroneHover_B.loop_ub_g + ARDroneHover_B.hex_size[1];
        ARDroneHover_B.aux = loop_ub + 18;
        if (0 <= ARDroneHover_B.loop_ub_g - 1) {
          memcpy(&ARDroneHover_B.cmd_data_m[0], &ARDroneHover_B.cmd_data[0],
                 ARDroneHover_B.loop_ub_g * sizeof(char_T));
        }

        for (ARDroneHover_B.i = 0; ARDroneHover_B.i < 7; ARDroneHover_B.i++) {
          ARDroneHover_B.cmd_data_m[ARDroneHover_B.i + ARDroneHover_B.loop_ub_g]
            = f[ARDroneHover_B.i];
        }

        ARDroneHover_B.loop_ub = ARDroneHover_B.hex_size[1];
        for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub;
             ARDroneHover_B.i++) {
          ARDroneHover_B.cmd_data_m[(ARDroneHover_B.i + ARDroneHover_B.loop_ub_g)
            + 7] = ARDroneHover_B.strCmd_data[ARDroneHover_B.hex_size[0] *
            ARDroneHover_B.i];
        }

        for (ARDroneHover_B.i = 0; ARDroneHover_B.i < 10; ARDroneHover_B.i++) {
          ARDroneHover_B.cmd_data_m[((ARDroneHover_B.i +
            ARDroneHover_B.loop_ub_g) + ARDroneHover_B.hex_size[1]) + 7] =
            j[ARDroneHover_B.i];
        }

        ARDroneHover_B.cmd_data_m[loop_ub + 17] = '\x0d';
        ARDroneHover_B.loop_ub_g = ARDroneHover_B.aux;
        if (0 <= ARDroneHover_B.aux - 1) {
          memcpy(&ARDroneHover_B.cmd_data[0], &ARDroneHover_B.cmd_data_m[0],
                 ARDroneHover_B.aux * sizeof(char_T));
        }
      }
    }

    for (ARDroneHover_B.i = 0; ARDroneHover_B.i < ARDroneHover_B.loop_ub_g;
         ARDroneHover_B.i++) {
      ARDroneHover_B.dataControl[ARDroneHover_B.i] = (uint8_T)
        ARDroneHover_B.cmd_data[ARDroneHover_B.i];
    }

    ARDroneHover_B.isFlying = ARDroneHover_B.status[31];

    /* S-Function (sldrtpo): '<S7>/Packet Output' */
    /* S-Function Block: <S7>/Packet Output */

    /* no code required */

    /* RateTransition: '<S10>/Rate Transition' */
    if (ARDroneHover_M->Timing.RateInteraction.TID1_2) {
      ARDroneHover_B.RateTransition[0] = 1U;
      ARDroneHover_B.RateTransition[1] = 13U;
    }

    /* End of RateTransition: '<S10>/Rate Transition' */

    /* MATLAB Function: '<S17>/Velocity from vehicle body frame  to inertial NED  frame' incorporates:
     *  SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport1'
     */
    ARDroneHover_B.Vel_xy[0] = 0.0;
    ARDroneHover_B.Vel_xy[0] += ARDroneHover_B.bytesToRead *
      ARDroneHover_B.TypeConversion5;
    ARDroneHover_B.Vel_xy[0] += -sin(ARDroneHover_B.deg2rad[2]) *
      ARDroneHover_B.TypeConversion6;
    ARDroneHover_B.Vel_xy[1] = 0.0;
    ARDroneHover_B.Vel_xy[1] += ARDroneHover_B.bytesLeft *
      ARDroneHover_B.TypeConversion5;
    ARDroneHover_B.Vel_xy[1] += ARDroneHover_B.bytesToRead *
      ARDroneHover_B.TypeConversion6;
  }

  /* Clock: '<Root>/Clock1' */
  ARDroneHover_B.Clock1 = ARDroneHover_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
  }
}

/* Model update function for TID0 */
void ARDroneHover_update0(void)        /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Integrator: '<S17>/Integrator' */
  ARDroneHover_DW.Integrator_IWORK = 0;
  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    /* Update for UnitDelay: '<S1>/Unit Delay to avoid algebraic loop' */
    ARDroneHover_DW.UnitDelaytoavoidalgebraicloop_DSTATE =
      ARDroneHover_B.isFlying;

    /* Update for S-Function (sldrtpo): '<S7>/Packet Output' */

    /* S-Function Block: <S7>/Packet Output */
    {
      uint8_T outdata[150U];
      RTWin_ANYTYPEPTR outdp;
      outdp.p_uint8_T = outdata;

      {
        int_T i1;
        const uint8_T *u0 = &ARDroneHover_B.dataControl[0];
        for (i1=0; i1 < 150; i1++) {
          {
            uint8_T pktout = u0[i1];
            *outdp.p_uint8_T++ = pktout;
          }
        }
      }

      RTBIO_DriverIO(1, STREAMOUTPUT, IOWRITE, 150U,
                     &ARDroneHover_ConstP.pooled6, (double*) outdata, NULL);
    }
  }

  if (rtmIsMajorTimeStep(ARDroneHover_M)) {
    rt_ertODEUpdateContinuousStates(&ARDroneHover_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ARDroneHover_M->Timing.clockTick0)) {
    ++ARDroneHover_M->Timing.clockTickH0;
  }

  ARDroneHover_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ARDroneHover_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ARDroneHover_M->Timing.clockTick1)) {
    ++ARDroneHover_M->Timing.clockTickH1;
  }

  ARDroneHover_M->Timing.t[1] = ARDroneHover_M->Timing.clockTick1 *
    ARDroneHover_M->Timing.stepSize1 + ARDroneHover_M->Timing.clockTickH1 *
    ARDroneHover_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void ARDroneHover_derivatives(void)
{
  XDot_ARDroneHover_T *_rtXdot;
  _rtXdot = ((XDot_ARDroneHover_T *) ARDroneHover_M->derivs);

  /* Derivatives for Integrator: '<S17>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ARDroneHover_B.Vel_xy[0];
  _rtXdot->Integrator_CSTATE[1] = ARDroneHover_B.Vel_xy[1];
}

/* Model output function for TID2 */
void ARDroneHover_output2(void)        /* Sample time: [0.65s, 0.0s] */
{
  /* S-Function (sldrtpo): '<S10>/Packet Output1' */
  /* S-Function Block: <S10>/Packet Output1 */

  /* no code required */
}

/* Model update function for TID2 */
void ARDroneHover_update2(void)        /* Sample time: [0.65s, 0.0s] */
{
  /* Update for S-Function (sldrtpo): '<S10>/Packet Output1' */

  /* S-Function Block: <S10>/Packet Output1 */
  {
    uint8_T outdata[2U];
    RTWin_ANYTYPEPTR outdp;
    outdp.p_uint8_T = outdata;

    {
      uint8_T pktout = ARDroneHover_B.RateTransition[0];
      *outdp.p_uint8_T++ = pktout;
    }

    {
      uint8_T pktout = ARDroneHover_B.RateTransition[1];
      *outdp.p_uint8_T++ = pktout;
    }

    RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 2U, &ARDroneHover_ConstP.pooled6,
                   (double*) outdata, NULL);
  }

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ARDroneHover_M->Timing.clockTick2)) {
    ++ARDroneHover_M->Timing.clockTickH2;
  }

  ARDroneHover_M->Timing.t[2] = ARDroneHover_M->Timing.clockTick2 *
    ARDroneHover_M->Timing.stepSize2 + ARDroneHover_M->Timing.clockTickH2 *
    ARDroneHover_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void ARDroneHover_output(int_T tid)
{
  switch (tid) {
   case 0 :
    ARDroneHover_output0();
    break;

   case 2 :
    ARDroneHover_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void ARDroneHover_update(int_T tid)
{
  switch (tid) {
   case 0 :
    ARDroneHover_update0();
    break;

   case 2 :
    ARDroneHover_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void ARDroneHover_initialize(void)
{
  /* Start for S-Function (sldrtpo): '<S7>/Packet Output' */

  /* S-Function Block: <S7>/Packet Output */
  /* no initial value should be set */

  /* Start for S-Function (sldrtpo): '<S10>/Packet Output1' */

  /* S-Function Block: <S10>/Packet Output1 */
  /* no initial value should be set */

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay to avoid algebraic loop' */
  ARDroneHover_DW.UnitDelaytoavoidalgebraicloop_DSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S17>/Integrator' */
  if (rtmIsFirstInitCond(ARDroneHover_M)) {
    ARDroneHover_X.Integrator_CSTATE[0] = 0.0;
    ARDroneHover_X.Integrator_CSTATE[1] = 0.0;
  }

  ARDroneHover_DW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S17>/Integrator' */

  /* SystemInitialize for MATLAB Function: '<S1>/Data synchronization ' */
  memset(&ARDroneHover_DW.buffer[0], 0, sizeof(uint8_T) << 10U);
  ARDroneHover_DW.countBuffer = 0.0;
  ARDroneHover_DW.count = 0.0;
  ARDroneHover_DW.countHeader = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/ARDrone data decoding' */
  ARDroneHover_DW.hPrev = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/Data synchronization ' */
  memset(&ARDroneHover_DW.frame[0], 0, 496U * sizeof(uint8_T));
  memset(&ARDroneHover_DW.lastFrame[0], 0, 496U * sizeof(uint8_T));

  /* SystemInitialize for MATLAB Function: '<S1>/ARDrone data decoding' */
  memset(&ARDroneHover_DW.dataPrev[0], 0, 496U * sizeof(uint8_T));

  /* SystemInitialize for MATLAB Function: '<S1>/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ' */
  ARDroneHover_DW.yaw0 = 0.0;
  ARDroneHover_DW.mode = 0.0;

  /* SystemInitialize for MATLAB Function: '<S7>/Drone state request' */
  ARDroneHover_DW.SequenceNumber = 1.0;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ARDroneHover_M)) {
    rtmSetFirstInitCond(ARDroneHover_M, 0);
  }
}

/* Model terminate function */
void ARDroneHover_terminate(void)
{
  /* Terminate for S-Function (sldrtpo): '<S7>/Packet Output' */

  /* S-Function Block: <S7>/Packet Output */
  /* no initial value should be set */

  /* Terminate for S-Function (sldrtpo): '<S10>/Packet Output1' */

  /* S-Function Block: <S10>/Packet Output1 */
  /* no initial value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  ARDroneHover_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  ARDroneHover_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ARDroneHover_initialize();
}

void MdlTerminate(void)
{
  ARDroneHover_terminate();
}

/* Registration function */
RT_MODEL_ARDroneHover_T *ARDroneHover(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ARDroneHover_M, 0,
                sizeof(RT_MODEL_ARDroneHover_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ARDroneHover_M->solverInfo,
                          &ARDroneHover_M->Timing.simTimeStep);
    rtsiSetTPtr(&ARDroneHover_M->solverInfo, &rtmGetTPtr(ARDroneHover_M));
    rtsiSetStepSizePtr(&ARDroneHover_M->solverInfo,
                       &ARDroneHover_M->Timing.stepSize0);
    rtsiSetdXPtr(&ARDroneHover_M->solverInfo, &ARDroneHover_M->derivs);
    rtsiSetContStatesPtr(&ARDroneHover_M->solverInfo, (real_T **)
                         &ARDroneHover_M->contStates);
    rtsiSetNumContStatesPtr(&ARDroneHover_M->solverInfo,
      &ARDroneHover_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ARDroneHover_M->solverInfo,
      &ARDroneHover_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ARDroneHover_M->solverInfo,
      &ARDroneHover_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ARDroneHover_M->solverInfo,
      &ARDroneHover_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ARDroneHover_M->solverInfo, (&rtmGetErrorStatus
      (ARDroneHover_M)));
    rtsiSetRTModelPtr(&ARDroneHover_M->solverInfo, ARDroneHover_M);
  }

  rtsiSetSimTimeStep(&ARDroneHover_M->solverInfo, MAJOR_TIME_STEP);
  ARDroneHover_M->intgData.f[0] = ARDroneHover_M->odeF[0];
  ARDroneHover_M->contStates = ((real_T *) &ARDroneHover_X);
  rtsiSetSolverData(&ARDroneHover_M->solverInfo, (void *)
                    &ARDroneHover_M->intgData);
  rtsiSetSolverName(&ARDroneHover_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ARDroneHover_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    ARDroneHover_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ARDroneHover_M->Timing.sampleTimes =
      (&ARDroneHover_M->Timing.sampleTimesArray[0]);
    ARDroneHover_M->Timing.offsetTimes =
      (&ARDroneHover_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ARDroneHover_M->Timing.sampleTimes[0] = (0.0);
    ARDroneHover_M->Timing.sampleTimes[1] = (0.065);
    ARDroneHover_M->Timing.sampleTimes[2] = (0.65);

    /* task offsets */
    ARDroneHover_M->Timing.offsetTimes[0] = (0.0);
    ARDroneHover_M->Timing.offsetTimes[1] = (0.0);
    ARDroneHover_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(ARDroneHover_M, &ARDroneHover_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ARDroneHover_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = ARDroneHover_M->Timing.perTaskSampleHitsArray;
    ARDroneHover_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    ARDroneHover_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ARDroneHover_M, -1);
  ARDroneHover_M->Timing.stepSize0 = 0.065;
  ARDroneHover_M->Timing.stepSize1 = 0.065;
  ARDroneHover_M->Timing.stepSize2 = 0.65;
  rtmSetFirstInitCond(ARDroneHover_M, 1);

  /* External mode info */
  ARDroneHover_M->Sizes.checksums[0] = (1444131570U);
  ARDroneHover_M->Sizes.checksums[1] = (1298493410U);
  ARDroneHover_M->Sizes.checksums[2] = (2049201821U);
  ARDroneHover_M->Sizes.checksums[3] = (4055319250U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    ARDroneHover_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ARDroneHover_M->extModeInfo,
      &ARDroneHover_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ARDroneHover_M->extModeInfo,
                        ARDroneHover_M->Sizes.checksums);
    rteiSetTPtr(ARDroneHover_M->extModeInfo, rtmGetTPtr(ARDroneHover_M));
  }

  ARDroneHover_M->solverInfoPtr = (&ARDroneHover_M->solverInfo);
  ARDroneHover_M->Timing.stepSize = (0.065);
  rtsiSetFixedStepSize(&ARDroneHover_M->solverInfo, 0.065);
  rtsiSetSolverMode(&ARDroneHover_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  ARDroneHover_M->blockIO = ((void *) &ARDroneHover_B);
  (void) memset(((void *) &ARDroneHover_B), 0,
                sizeof(B_ARDroneHover_T));

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ARDroneHover_X;
    ARDroneHover_M->contStates = (x);
    (void) memset((void *)&ARDroneHover_X, 0,
                  sizeof(X_ARDroneHover_T));
  }

  /* states (dwork) */
  ARDroneHover_M->dwork = ((void *) &ARDroneHover_DW);
  (void) memset((void *)&ARDroneHover_DW, 0,
                sizeof(DW_ARDroneHover_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ARDroneHover_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Initialize Sizes */
  ARDroneHover_M->Sizes.numContStates = (2);/* Number of continuous states */
  ARDroneHover_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ARDroneHover_M->Sizes.numY = (0);    /* Number of model outputs */
  ARDroneHover_M->Sizes.numU = (0);    /* Number of model inputs */
  ARDroneHover_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ARDroneHover_M->Sizes.numSampTimes = (3);/* Number of sample times */
  ARDroneHover_M->Sizes.numBlocks = (61);/* Number of blocks */
  ARDroneHover_M->Sizes.numBlockIO = (21);/* Number of block outputs */
  return ARDroneHover_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
