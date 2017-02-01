/*
 * Controller_ABS_VLC_AYC_private.h
 *
 * Code generation for model "Controller_ABS_VLC_AYC".
 *
 * Model version              : 1.37
 * Simulink Coder version : 8.2 (R2012a) 29-Dec-2011
 * C source code generated on : Mon Dec 15 21:01:36 2014
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Texas Instruments->TMS470
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Controller_ABS_VLC_AYC_private_h_
#define RTW_HEADER_Controller_ABS_VLC_AYC_private_h_
#include "rtwtypes.h"
#include "fis.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern void fisAssignMfPointer(FIS *fis);
  extern void fisCheckDataStructure(FIS *fis);
  extern void fisAssignFunctionPointer(FIS *fis);
  extern IO *fisBuildIoList(int_T node_n, int_T *mf_n);
  extern void fisComputeOutputMfValueArray(FIS *fis, int numofpoints);
  extern char **fisCreateMatrix(int row_n, int col_n, int element_size);
  extern void fisFreeFisNode(FIS *fis);
  extern void fisEvaluate(FIS *fis, int numofpoints);

#ifdef __cplusplus

}
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern real_T rt_powd_snf(real_T u0, real_T u1);

/* Exported functions */
extern void Controller_A_IfActionSubsystem1(real_T rtu_x, real_T *rty_Out1,
  real_T rtp_a, real_T rtp_b);
extern void Controller_A_IfActionSubsystem3(real_T rtu_x, real_T *rty_Out1,
  real_T rtp_c, real_T rtp_d);
extern void Controller_A_IfActionSubsystem2(real_T rtu_x, real_T *rty_Out1,
  real_T rtp_b, real_T rtp_c);

#endif                                 /* RTW_HEADER_Controller_ABS_VLC_AYC_private_h_ */
