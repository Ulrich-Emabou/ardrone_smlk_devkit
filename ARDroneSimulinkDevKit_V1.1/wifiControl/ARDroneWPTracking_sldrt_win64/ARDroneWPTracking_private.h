/*
 * ARDroneWPTracking_private.h
 *
 * Code generation for model "ARDroneWPTracking".
 *
 * Model version              : $Id: UAV_PIL.mdl 965 2013-03-21 01:08:53Z escobar $
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Mon Jan 27 00:10:40 2020
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ARDroneWPTracking_private_h_
#define RTW_HEADER_ARDroneWPTracking_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "ARDroneWPTracking.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_powd_snf(real_T u0, real_T u1);
void ARDroneWPTracking_output0(void);
void ARDroneWPTracking_update0(void);
void ARDroneWPTracking_output2(void);
void ARDroneWPTracking_update2(void);  /* private model entry point functions */
extern void ARDroneWPTracking_derivatives(void);

#endif                                 /* RTW_HEADER_ARDroneWPTracking_private_h_ */
