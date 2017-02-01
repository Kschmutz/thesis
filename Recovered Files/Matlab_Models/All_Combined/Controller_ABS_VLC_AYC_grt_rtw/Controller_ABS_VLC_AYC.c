/*
 * Controller_ABS_VLC_AYC.c
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
#include "Controller_ABS_VLC_AYC.h"
#include "Controller_ABS_VLC_AYC_private.h"

/* Block signals (auto storage) */
BlockIO_Controller_ABS_VLC_AYC Controller_ABS_VLC_AYC_B;

/* Block states (auto storage) */
D_Work_Controller_ABS_VLC_AYC Controller_ABS_VLC_AYC_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_Controller_ABS_VLC_AYC Controller_ABS_VLC_AYC_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_Controller_ABS_VLC_AYC Controller_ABS_VLC_AYC_Y;

/* Real-time model */
RT_MODEL_Controller_ABS_VLC_AYC Controller_ABS_VLC_AYC_M_;
RT_MODEL_Controller_ABS_VLC_AYC *const Controller_ABS_VLC_AYC_M =
  &Controller_ABS_VLC_AYC_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Controller_ABS_VLC_AYC_M->Timing.TaskCounters.TID[2])++;
  if ((Controller_ABS_VLC_AYC_M->Timing.TaskCounters.TID[2]) > 999) {/* Sample time: [0.1s, 0.0s] */
    Controller_ABS_VLC_AYC_M->Timing.TaskCounters.TID[2] = 0;
  }

  Controller_ABS_VLC_AYC_M->Timing.sampleHits[2] =
    (Controller_ABS_VLC_AYC_M->Timing.TaskCounters.TID[2] == 0);
}

/*
 * Output and update for action system:
 *    '<S89>/If Action Subsystem1'
 *    '<S90>/If Action Subsystem3'
 *    '<S91>/If Action Subsystem3'
 *    '<S92>/If Action Subsystem1'
 *    '<S93>/If Action Subsystem3'
 *    '<S94>/If Action Subsystem3'
 *    '<S95>/If Action Subsystem3'
 *    '<S126>/If Action Subsystem1'
 *    '<S127>/If Action Subsystem3'
 *    '<S128>/If Action Subsystem3'
 *    ...
 */
void Controller_A_IfActionSubsystem1(real_T rtu_x, real_T *rty_Out1, real_T
  rtp_a, real_T rtp_b)
{
  /* Product: '<S97>/Product ab (trimf)' incorporates:
   *  Constant: '<S97>/a'
   *  Constant: '<S97>/b'
   *  Sum: '<S97>/Sum'
   *  Sum: '<S97>/Sum1'
   */
  *rty_Out1 = (rtu_x - rtp_a) / (rtp_b - rtp_a);
}

/*
 * Output and update for action system:
 *    '<S89>/If Action Subsystem3'
 *    '<S92>/If Action Subsystem3'
 *    '<S126>/If Action Subsystem3'
 *    '<S129>/If Action Subsystem3'
 */
void Controller_A_IfActionSubsystem3(real_T rtu_x, real_T *rty_Out1, real_T
  rtp_c, real_T rtp_d)
{
  /* Product: '<S99>/Product cd (trimf)' incorporates:
   *  Constant: '<S99>/c'
   *  Constant: '<S99>/d'
   *  Sum: '<S99>/Sum2'
   *  Sum: '<S99>/Sum3'
   */
  *rty_Out1 = 1.0 / (rtp_d - rtp_c) * (rtp_d - rtu_x);
}

/*
 * Output and update for action system:
 *    '<S90>/If Action Subsystem2'
 *    '<S91>/If Action Subsystem2'
 *    '<S93>/If Action Subsystem2'
 *    '<S94>/If Action Subsystem2'
 *    '<S95>/If Action Subsystem2'
 *    '<S127>/If Action Subsystem2'
 *    '<S128>/If Action Subsystem2'
 *    '<S130>/If Action Subsystem2'
 *    '<S131>/If Action Subsystem2'
 *    '<S132>/If Action Subsystem2'
 */
void Controller_A_IfActionSubsystem2(real_T rtu_x, real_T *rty_Out1, real_T
  rtp_b, real_T rtp_c)
{
  /* Product: '<S102>/Product cd (trimf)' incorporates:
   *  Constant: '<S102>/b'
   *  Constant: '<S102>/c'
   *  Sum: '<S102>/Sum2'
   *  Sum: '<S102>/Sum3'
   */
  *rty_Out1 = 1.0 / (rtp_c - rtp_b) * (rtp_c - rtu_x);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
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
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
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

/* Model output function */
static void Controller_ABS_VLC_AYC_output(void)
{
  /* local block i/o variables */
  real_T rtb_Sum1;
  real_T minV;
  real_T minV_0[101];
  real_T minV_1[101];
  real_T minV_2[101];
  real_T minV_3[101];
  real_T minV_4[101];
  real_T minV_5[101];
  real_T minV_6[101];
  real_T minV_7[101];
  real_T minV_8[101];
  real_T minV_9[101];
  real_T minV_a[101];
  real_T minV_b[101];
  real_T minV_c[101];
  real_T minV_d[101];
  real_T minV_e[101];
  real_T minV_f[101];
  real_T minV_g[101];
  real_T minV_h[101];
  real_T minV_i[101];
  real_T minV_j[101];
  real_T minV_k[101];
  real_T minV_l[101];
  real_T minV_m[101];
  real_T minV_n[101];
  real_T minV_o[101];
  real_T minV_p[101];
  real_T minV_q[101];
  real_T minV_r[101];
  real_T minV_s[101];
  real_T minV_t[101];
  real_T minV_u[101];
  real_T minV_v[101];
  real_T minV_w[101];
  real_T minV_x[101];
  real_T minV_y[101];
  real_T minV_z[101];
  real_T minV_10[101];
  real_T minV_11[101];
  real_T minV_12[101];
  real_T minV_13[101];
  real_T minV_14[101];
  int32_T j;
  real_T rtb_Weighting_hm;
  int8_T rtAction;
  real_T rtb_Weighting;
  real_T rtb_Weighting_o;
  real_T rtb_Weighting_n;
  real_T rtb_Weighting_a;
  real_T rtb_Weighting_am;
  real_T rtb_Weighting_j;
  real_T rtb_Weighting_m;
  real_T rtb_Weighting_k;
  real_T rtb_Weighting_i;
  real_T rtb_Weighting_as;
  real_T rtb_Weighting_c;
  real_T rtb_Weighting_e;
  real_T rtb_Weighting_g;
  real_T rtb_Weighting_b;
  real_T rtb_Weighting_os;
  real_T rtb_Weighting_em;
  real_T rtb_Weighting_be;
  real_T rtb_Weighting_k3;
  real_T rtb_Weighting_h;
  real_T rtb_Weighting_cb;
  real_T rtb_Weighting_oa;
  real_T rtb_Weighting_ci;
  real_T rtb_Weighting_oo;
  real_T rtb_Weighting_j5;
  real_T rtb_Weighting_ha;
  real_T rtb_Weighting_kf;
  real_T rtb_Weighting_ct;
  real_T rtb_Weighting_oz;
  real_T rtb_Weighting_g1;
  real_T rtb_Weighting_ix;
  real_T rtb_Weighting_l;
  real_T rtb_Weighting_gv;
  real_T rtb_Weighting_bo;
  real_T rtb_Weighting_j2;
  real_T rtb_Weighting_cp;
  real_T rtb_Weighting_br;
  real_T rtb_Weighting_j2f;
  real_T rtb_Weighting_mw;
  real_T rtb_Weighting_gi;
  real_T rtb_Weighting_mn;
  real_T rtb_Weighting_d;
  real_T rtb_Weighting_ok;
  real_T rtb_Weighting_kl;
  real_T rtb_Weighting_bx;
  real_T rtb_Weighting_lv;
  real_T rtb_Weighting_m2;
  real_T rtb_Weighting_f;
  boolean_T rtb_LowerRelop1;
  real_T rtb_ProductCOA[101];
  real_T rtb_Sum;
  int32_T i;
  real_T y;

  /* SampleTimeMath: '<S13>/TSamp' incorporates:
   *  Inport: '<Root>/FL_SR'
   *
   * About '<S13>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Controller_ABS_VLC_AYC_B.TSamp = Controller_ABS_VLC_AYC_U.FL_SR * 10000.0;

  /* Sum: '<S13>/Diff' incorporates:
   *  UnitDelay: '<S13>/UD'
   */
  Controller_ABS_VLC_AYC_B.Diff = Controller_ABS_VLC_AYC_B.TSamp -
    Controller_ABS_VLC_AYC_DWork.UD_DSTATE;

  /* S-Function Block: <S14>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK.FISPointer;
    fis->input[0]->value = Controller_ABS_VLC_AYC_B.Diff;
    fis->input[1]->value = Controller_ABS_VLC_AYC_U.FL_SR;
    fisEvaluate(fis, 101);
    Controller_ABS_VLC_AYC_B.FISSfunction = fis->output[0]->value;
  }

  /* S-Function (sdspfilter2): '<S16>/Generated Filter Block' */
  minV = Controller_ABS_VLC_AYC_B.FISSfunction * -0.0007564686406292;
  i = 1;
  for (j = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFFID; j < 403;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STATE[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  for (j = 0; j < Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFFID;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STATE[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  i = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFFID - 1;
  if (i < 0) {
    i = 402;
  }

  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STATE[i] =
    Controller_ABS_VLC_AYC_B.FISSfunction;
  Controller_ABS_VLC_AYC_B.GeneratedFilterBlock = minV;
  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFFID = i;

  /* End of S-Function (sdspfilter2): '<S16>/Generated Filter Block' */

  /* Gain: '<S3>/FL Available Acceleration Torque [Nm]1' */
  Controller_ABS_VLC_AYC_B.FLAvailableAccelerationTorqueNm = 150.0 *
    Controller_ABS_VLC_AYC_B.GeneratedFilterBlock;

  /* Fcn: '<S11>/Velocity Magnitude' incorporates:
   *  Inport: '<Root>/Vx_cont'
   */
  rtb_Sum = rt_powd_snf(Controller_ABS_VLC_AYC_U.Vx_cont, 2.0);
  if (rtb_Sum < 0.0) {
    rtb_Sum = -rt_powd_snf(-rtb_Sum, 0.5);
  } else {
    rtb_Sum = rt_powd_snf(rtb_Sum, 0.5);
  }

  /* Fcn: '<S11>/Desired Yaw Calc' incorporates:
   *  Fcn: '<S11>/Velocity Magnitude'
   *  Inport: '<Root>/S_Ang'
   */
  minV = rt_powd_snf(cos(Controller_ABS_VLC_AYC_U.S_Ang) / sin
                     (Controller_ABS_VLC_AYC_U.S_Ang), 2.0) * 9.0 + 2.25;
  if (minV < 0.0) {
    minV = -rt_powd_snf(-minV, 0.5);
  } else {
    minV = rt_powd_snf(minV, 0.5);
  }

  Controller_ABS_VLC_AYC_B.DesiredYawCalc = rtb_Sum / minV;

  /* End of Fcn: '<S11>/Desired Yaw Calc' */

  /* Sum: '<S11>/Sum' incorporates:
   *  Inport: '<Root>/r_cont'
   */
  Controller_ABS_VLC_AYC_B.Yawerror = Controller_ABS_VLC_AYC_B.DesiredYawCalc -
    Controller_ABS_VLC_AYC_U.r_cont;

  /* Derivative: '<S6>/Derivative' */
  {
    real_T t = Controller_ABS_VLC_AYC_M->Timing.t[0];
    real_T timeStampA = Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.TimeStampB;
    real_T *lastU = &Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      Controller_ABS_VLC_AYC_B.Derivative = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      Controller_ABS_VLC_AYC_B.Derivative = (Controller_ABS_VLC_AYC_B.Yawerror -
        *lastU++) / deltaT;
    }
  }

  /* If: '<S89>/If' incorporates:
   *  Constant: '<S96>/0'
   *  Constant: '<S98>/0'
   */
  if (Controller_ABS_VLC_AYC_B.Derivative > -0.5) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S89>/If Action Subsystem' incorporates:
     *  ActionPort: '<S96>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge = 0.0;

    /* End of Outputs for SubSystem: '<S89>/If Action Subsystem' */
  } else if ((Controller_ABS_VLC_AYC_B.Derivative >= (rtMinusInf)) &&
             (Controller_ABS_VLC_AYC_B.Derivative <= -1.0)) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S89>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S98>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge = 1.0;

    /* End of Outputs for SubSystem: '<S89>/If Action Subsystem2' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S89>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S99>/Action Port'
     */
    Controller_A_IfActionSubsystem3(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge, -1.0, -0.5);

    /* End of Outputs for SubSystem: '<S89>/If Action Subsystem3' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem = rtAction;

  /* End of If: '<S89>/If' */

  /* If: '<S126>/If' incorporates:
   *  Constant: '<S133>/0'
   *  Constant: '<S135>/0'
   */
  if (Controller_ABS_VLC_AYC_B.Yawerror > -0.5) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem' incorporates:
     *  ActionPort: '<S133>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_b = 0.0;

    /* End of Outputs for SubSystem: '<S126>/If Action Subsystem' */
  } else if ((Controller_ABS_VLC_AYC_B.Yawerror >= (rtMinusInf)) &&
             (Controller_ABS_VLC_AYC_B.Yawerror <= -1.0)) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S135>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_b = 1.0;

    /* End of Outputs for SubSystem: '<S126>/If Action Subsystem2' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S136>/Action Port'
     */
    Controller_A_IfActionSubsystem3(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_b, -1.0, -0.5);

    /* End of Outputs for SubSystem: '<S126>/If Action Subsystem3' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_e = rtAction;

  /* End of If: '<S126>/If' */

  /* MinMax: '<S39>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_b <= Controller_ABS_VLC_AYC_B.Merge) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_b;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge;
  }

  /* Product: '<S39>/Weighting' incorporates:
   *  MinMax: '<S39>/andorMethod'
   */
  rtb_Weighting_hm = minV;

  /* MinMax: '<S39>/impMethod' incorporates:
   *  Constant: '<S38>/NVB'
   *  MinMax: '<S39>/andorMethod'
   */
  for (i = 0; i < 101; i++) {
    if ((minV <= Controller_ABS_VLC_AYC_ConstP.NVB_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.NVB_Value[i])) {
      rtb_ProductCOA[i] = minV;
    } else {
      rtb_ProductCOA[i] = Controller_ABS_VLC_AYC_ConstP.NVB_Value[i];
    }
  }

  /* If: '<S90>/If' incorporates:
   *  Constant: '<S100>/0'
   *  Constant: '<S101>/0'
   */
  if ((Controller_ABS_VLC_AYC_B.Derivative < -1.0) ||
      (Controller_ABS_VLC_AYC_B.Derivative > -0.25)) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S90>/If Action Subsystem' incorporates:
     *  ActionPort: '<S100>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_k = 0.0;

    /* End of Outputs for SubSystem: '<S90>/If Action Subsystem' */
  } else if (Controller_ABS_VLC_AYC_B.Derivative == -0.5) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S90>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S101>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_k = 1.0;

    /* End of Outputs for SubSystem: '<S90>/If Action Subsystem1' */
  } else if (Controller_ABS_VLC_AYC_B.Derivative < -0.5) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S90>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S103>/Action Port'
     */
    Controller_A_IfActionSubsystem1(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge_k, -1.0, -0.5);

    /* End of Outputs for SubSystem: '<S90>/If Action Subsystem3' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S90>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S102>/Action Port'
     */
    Controller_A_IfActionSubsystem2(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge_k, -0.5, -0.25);

    /* End of Outputs for SubSystem: '<S90>/If Action Subsystem2' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_i = rtAction;

  /* End of If: '<S90>/If' */

  /* MinMax: '<S50>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_b <= Controller_ABS_VLC_AYC_B.Merge_k) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_k)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_b;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge_k;
  }

  /* Product: '<S50>/Weighting' incorporates:
   *  MinMax: '<S50>/andorMethod'
   */
  rtb_Weighting = minV;

  /* MinMax: '<S50>/impMethod' incorporates:
   *  Constant: '<S38>/NVB'
   *  MinMax: '<S50>/andorMethod'
   */
  for (i = 0; i < 101; i++) {
    if ((minV <= Controller_ABS_VLC_AYC_ConstP.NVB_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.NVB_Value[i])) {
      minV_0[i] = minV;
    } else {
      minV_0[i] = Controller_ABS_VLC_AYC_ConstP.NVB_Value[i];
    }
  }

  /* If: '<S91>/If' incorporates:
   *  Constant: '<S104>/0'
   *  Constant: '<S105>/0'
   */
  if ((Controller_ABS_VLC_AYC_B.Derivative < -0.5) ||
      (Controller_ABS_VLC_AYC_B.Derivative > 0.0)) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S91>/If Action Subsystem' incorporates:
     *  ActionPort: '<S104>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_o = 0.0;

    /* End of Outputs for SubSystem: '<S91>/If Action Subsystem' */
  } else if (Controller_ABS_VLC_AYC_B.Derivative == -0.25) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S91>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S105>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_o = 1.0;

    /* End of Outputs for SubSystem: '<S91>/If Action Subsystem1' */
  } else if (Controller_ABS_VLC_AYC_B.Derivative < -0.25) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S91>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S107>/Action Port'
     */
    Controller_A_IfActionSubsystem1(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge_o, -0.5, -0.25);

    /* End of Outputs for SubSystem: '<S91>/If Action Subsystem3' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S91>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S106>/Action Port'
     */
    Controller_A_IfActionSubsystem2(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge_o, -0.25, 0.0);

    /* End of Outputs for SubSystem: '<S91>/If Action Subsystem2' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_p = rtAction;

  /* End of If: '<S91>/If' */

  /* MinMax: '<S61>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_b <= Controller_ABS_VLC_AYC_B.Merge_o) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_o)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_b;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge_o;
  }

  /* Product: '<S61>/Weighting' incorporates:
   *  MinMax: '<S61>/andorMethod'
   */
  rtb_Weighting_o = minV;

  /* MinMax: '<S61>/impMethod' incorporates:
   *  Constant: '<S38>/NVB'
   *  MinMax: '<S61>/andorMethod'
   */
  for (i = 0; i < 101; i++) {
    if ((minV <= Controller_ABS_VLC_AYC_ConstP.NVB_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.NVB_Value[i])) {
      minV_1[i] = minV;
    } else {
      minV_1[i] = Controller_ABS_VLC_AYC_ConstP.NVB_Value[i];
    }
  }

  /* If: '<S95>/If' incorporates:
   *  Constant: '<S120>/0'
   *  Constant: '<S121>/0'
   */
  if ((Controller_ABS_VLC_AYC_B.Derivative < -0.25) ||
      (Controller_ABS_VLC_AYC_B.Derivative > 0.25)) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem' incorporates:
     *  ActionPort: '<S120>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_f = 0.0;

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem' */
  } else if (Controller_ABS_VLC_AYC_B.Derivative == 0.0) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S121>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_f = 1.0;

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem1' */
  } else if (Controller_ABS_VLC_AYC_B.Derivative < 0.0) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    Controller_A_IfActionSubsystem1(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge_f, -0.25, 0.0);

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem3' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S122>/Action Port'
     */
    Controller_A_IfActionSubsystem2(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge_f, 0.0, 0.25);

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem2' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_f = rtAction;

  /* End of If: '<S95>/If' */

  /* MinMax: '<S72>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_b <= Controller_ABS_VLC_AYC_B.Merge_f) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_f)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_b;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge_f;
  }

  /* Product: '<S72>/Weighting' incorporates:
   *  MinMax: '<S72>/andorMethod'
   */
  rtb_Weighting_n = minV;

  /* MinMax: '<S72>/impMethod' incorporates:
   *  Constant: '<S38>/NB'
   *  MinMax: '<S72>/andorMethod'
   */
  for (i = 0; i < 101; i++) {
    if ((minV <= Controller_ABS_VLC_AYC_ConstP.NB_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.NB_Value[i])) {
      minV_2[i] = minV;
    } else {
      minV_2[i] = Controller_ABS_VLC_AYC_ConstP.NB_Value[i];
    }
  }

  /* If: '<S94>/If' incorporates:
   *  Constant: '<S116>/0'
   *  Constant: '<S117>/0'
   */
  if ((Controller_ABS_VLC_AYC_B.Derivative < 0.0) ||
      (Controller_ABS_VLC_AYC_B.Derivative > 0.5)) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_kg = 0.0;

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem' */
  } else if (Controller_ABS_VLC_AYC_B.Derivative == 0.25) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S117>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_kg = 1.0;

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem1' */
  } else if (Controller_ABS_VLC_AYC_B.Derivative < 0.25) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    Controller_A_IfActionSubsystem1(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge_kg, 0.0, 0.25);

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem3' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    Controller_A_IfActionSubsystem2(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge_kg, 0.25, 0.5);

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem2' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_ey = rtAction;

  /* End of If: '<S94>/If' */

  /* MinMax: '<S83>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_b <= Controller_ABS_VLC_AYC_B.Merge_kg) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_kg)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_b;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge_kg;
  }

  /* Product: '<S83>/Weighting' incorporates:
   *  MinMax: '<S83>/andorMethod'
   */
  rtb_Weighting_a = minV;

  /* MinMax: '<S83>/impMethod' incorporates:
   *  Constant: '<S38>/NM'
   *  MinMax: '<S83>/andorMethod'
   */
  for (i = 0; i < 101; i++) {
    if ((minV <= Controller_ABS_VLC_AYC_ConstP.NM_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.NM_Value[i])) {
      minV_3[i] = minV;
    } else {
      minV_3[i] = Controller_ABS_VLC_AYC_ConstP.NM_Value[i];
    }
  }

  /* If: '<S93>/If' incorporates:
   *  Constant: '<S112>/0'
   *  Constant: '<S113>/0'
   */
  if ((Controller_ABS_VLC_AYC_B.Derivative < 0.25) ||
      (Controller_ABS_VLC_AYC_B.Derivative > 1.0)) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S93>/If Action Subsystem' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_fu = 0.0;

    /* End of Outputs for SubSystem: '<S93>/If Action Subsystem' */
  } else if (Controller_ABS_VLC_AYC_B.Derivative == 0.5) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S93>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_fu = 1.0;

    /* End of Outputs for SubSystem: '<S93>/If Action Subsystem1' */
  } else if (Controller_ABS_VLC_AYC_B.Derivative < 0.5) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S93>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    Controller_A_IfActionSubsystem1(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge_fu, 0.25, 0.5);

    /* End of Outputs for SubSystem: '<S93>/If Action Subsystem3' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S93>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S114>/Action Port'
     */
    Controller_A_IfActionSubsystem2(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge_fu, 0.5, 1.0);

    /* End of Outputs for SubSystem: '<S93>/If Action Subsystem2' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_g = rtAction;

  /* End of If: '<S93>/If' */

  /* MinMax: '<S84>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_b <= Controller_ABS_VLC_AYC_B.Merge_fu) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_fu)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_b;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge_fu;
  }

  /* Product: '<S84>/Weighting' incorporates:
   *  MinMax: '<S84>/andorMethod'
   */
  rtb_Weighting_am = minV;

  /* MinMax: '<S84>/impMethod' incorporates:
   *  Constant: '<S38>/NS'
   *  MinMax: '<S84>/andorMethod'
   */
  for (i = 0; i < 101; i++) {
    if ((minV <= Controller_ABS_VLC_AYC_ConstP.NS_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.NS_Value[i])) {
      minV_4[i] = minV;
    } else {
      minV_4[i] = Controller_ABS_VLC_AYC_ConstP.NS_Value[i];
    }
  }

  /* If: '<S92>/If' incorporates:
   *  Constant: '<S108>/0'
   *  Constant: '<S110>/0'
   */
  if (Controller_ABS_VLC_AYC_B.Derivative < 0.5) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S92>/If Action Subsystem' incorporates:
     *  ActionPort: '<S108>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_oo = 0.0;

    /* End of Outputs for SubSystem: '<S92>/If Action Subsystem' */
  } else if ((Controller_ABS_VLC_AYC_B.Derivative >= 1.0) &&
             (Controller_ABS_VLC_AYC_B.Derivative <= (rtInf))) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S92>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S110>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_oo = 1.0;

    /* End of Outputs for SubSystem: '<S92>/If Action Subsystem2' */
  } else if (Controller_ABS_VLC_AYC_B.Derivative < 1.0) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S92>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S109>/Action Port'
     */
    Controller_A_IfActionSubsystem1(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge_oo, 0.5, 1.0);

    /* End of Outputs for SubSystem: '<S92>/If Action Subsystem1' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S92>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S111>/Action Port'
     */
    Controller_A_IfActionSubsystem3(Controller_ABS_VLC_AYC_B.Derivative,
      &Controller_ABS_VLC_AYC_B.Merge_oo, rtInf, rtInf);

    /* End of Outputs for SubSystem: '<S92>/If Action Subsystem3' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_go = rtAction;

  /* End of If: '<S92>/If' */

  /* MinMax: '<S85>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_b <= Controller_ABS_VLC_AYC_B.Merge_oo) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_oo)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_b;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge_oo;
  }

  /* Product: '<S85>/Weighting' incorporates:
   *  MinMax: '<S85>/andorMethod'
   */
  rtb_Weighting_j = minV;

  /* MinMax: '<S85>/impMethod' incorporates:
   *  Constant: '<S38>/Z'
   *  MinMax: '<S85>/andorMethod'
   */
  for (i = 0; i < 101; i++) {
    if ((minV <= Controller_ABS_VLC_AYC_ConstP.Z_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.Z_Value[i])) {
      minV_5[i] = minV;
    } else {
      minV_5[i] = Controller_ABS_VLC_AYC_ConstP.Z_Value[i];
    }
  }

  /* If: '<S127>/If' incorporates:
   *  Constant: '<S137>/0'
   *  Constant: '<S138>/0'
   */
  if ((Controller_ABS_VLC_AYC_B.Yawerror < -1.0) ||
      (Controller_ABS_VLC_AYC_B.Yawerror > -0.25)) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S127>/If Action Subsystem' incorporates:
     *  ActionPort: '<S137>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_l = 0.0;

    /* End of Outputs for SubSystem: '<S127>/If Action Subsystem' */
  } else if (Controller_ABS_VLC_AYC_B.Yawerror == -0.5) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S127>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S138>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_l = 1.0;

    /* End of Outputs for SubSystem: '<S127>/If Action Subsystem1' */
  } else if (Controller_ABS_VLC_AYC_B.Yawerror < -0.5) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S127>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S140>/Action Port'
     */
    Controller_A_IfActionSubsystem1(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_l, -1.0, -0.5);

    /* End of Outputs for SubSystem: '<S127>/If Action Subsystem3' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S127>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S139>/Action Port'
     */
    Controller_A_IfActionSubsystem2(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_l, -0.5, -0.25);

    /* End of Outputs for SubSystem: '<S127>/If Action Subsystem2' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_c = rtAction;

  /* End of If: '<S127>/If' */

  /* MinMax: '<S86>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_l <= Controller_ABS_VLC_AYC_B.Merge) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge)) {
    /* Product: '<S86>/Weighting' */
    rtb_Weighting_m = Controller_ABS_VLC_AYC_B.Merge_l;
  } else {
    /* Product: '<S86>/Weighting' */
    rtb_Weighting_m = Controller_ABS_VLC_AYC_B.Merge;
  }

  /* End of MinMax: '<S86>/andorMethod' */

  /* MinMax: '<S87>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_l <= Controller_ABS_VLC_AYC_B.Merge_k) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_k)) {
    /* Product: '<S87>/Weighting' */
    rtb_Weighting_k = Controller_ABS_VLC_AYC_B.Merge_l;
  } else {
    /* Product: '<S87>/Weighting' */
    rtb_Weighting_k = Controller_ABS_VLC_AYC_B.Merge_k;
  }

  /* End of MinMax: '<S87>/andorMethod' */

  /* MinMax: '<S40>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_l <= Controller_ABS_VLC_AYC_B.Merge_o) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_o)) {
    /* Product: '<S40>/Weighting' */
    rtb_Weighting_i = Controller_ABS_VLC_AYC_B.Merge_l;
  } else {
    /* Product: '<S40>/Weighting' */
    rtb_Weighting_i = Controller_ABS_VLC_AYC_B.Merge_o;
  }

  /* End of MinMax: '<S40>/andorMethod' */

  /* MinMax: '<S41>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_l <= Controller_ABS_VLC_AYC_B.Merge_f) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_f)) {
    /* Product: '<S41>/Weighting' */
    rtb_Weighting_as = Controller_ABS_VLC_AYC_B.Merge_l;
  } else {
    /* Product: '<S41>/Weighting' */
    rtb_Weighting_as = Controller_ABS_VLC_AYC_B.Merge_f;
  }

  /* End of MinMax: '<S41>/andorMethod' */

  /* MinMax: '<S42>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_l <= Controller_ABS_VLC_AYC_B.Merge_kg) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_kg)) {
    /* Product: '<S42>/Weighting' */
    rtb_Weighting_c = Controller_ABS_VLC_AYC_B.Merge_l;
  } else {
    /* Product: '<S42>/Weighting' */
    rtb_Weighting_c = Controller_ABS_VLC_AYC_B.Merge_kg;
  }

  /* End of MinMax: '<S42>/andorMethod' */

  /* MinMax: '<S43>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_l <= Controller_ABS_VLC_AYC_B.Merge_fu) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_fu)) {
    /* Product: '<S43>/Weighting' */
    rtb_Weighting_e = Controller_ABS_VLC_AYC_B.Merge_l;
  } else {
    /* Product: '<S43>/Weighting' */
    rtb_Weighting_e = Controller_ABS_VLC_AYC_B.Merge_fu;
  }

  /* End of MinMax: '<S43>/andorMethod' */

  /* MinMax: '<S44>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_l <= Controller_ABS_VLC_AYC_B.Merge_oo) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_oo)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_l;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge_oo;
  }

  /* Product: '<S44>/Weighting' incorporates:
   *  MinMax: '<S44>/andorMethod'
   */
  rtb_Weighting_g = minV;
  for (i = 0; i < 101; i++) {
    /* MinMax: '<S86>/impMethod' incorporates:
     *  Constant: '<S38>/NVB'
     */
    if ((rtb_Weighting_m <= Controller_ABS_VLC_AYC_ConstP.NVB_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NVB_Value[i])) {
      minV_6[i] = rtb_Weighting_m;
    } else {
      minV_6[i] = Controller_ABS_VLC_AYC_ConstP.NVB_Value[i];
    }

    /* MinMax: '<S87>/impMethod' incorporates:
     *  Constant: '<S38>/NVB'
     */
    if ((rtb_Weighting_k <= Controller_ABS_VLC_AYC_ConstP.NVB_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NVB_Value[i])) {
      minV_7[i] = rtb_Weighting_k;
    } else {
      minV_7[i] = Controller_ABS_VLC_AYC_ConstP.NVB_Value[i];
    }

    /* MinMax: '<S40>/impMethod' incorporates:
     *  Constant: '<S38>/NB'
     */
    if ((rtb_Weighting_i <= Controller_ABS_VLC_AYC_ConstP.NB_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NB_Value[i])) {
      minV_8[i] = rtb_Weighting_i;
    } else {
      minV_8[i] = Controller_ABS_VLC_AYC_ConstP.NB_Value[i];
    }

    /* MinMax: '<S41>/impMethod' incorporates:
     *  Constant: '<S38>/NM'
     */
    if ((rtb_Weighting_as <= Controller_ABS_VLC_AYC_ConstP.NM_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NM_Value[i])) {
      minV_9[i] = rtb_Weighting_as;
    } else {
      minV_9[i] = Controller_ABS_VLC_AYC_ConstP.NM_Value[i];
    }

    /* MinMax: '<S42>/impMethod' incorporates:
     *  Constant: '<S38>/NS'
     */
    if ((rtb_Weighting_c <= Controller_ABS_VLC_AYC_ConstP.NS_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NS_Value[i])) {
      minV_a[i] = rtb_Weighting_c;
    } else {
      minV_a[i] = Controller_ABS_VLC_AYC_ConstP.NS_Value[i];
    }

    /* MinMax: '<S43>/impMethod' incorporates:
     *  Constant: '<S38>/Z'
     */
    if ((rtb_Weighting_e <= Controller_ABS_VLC_AYC_ConstP.Z_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.Z_Value[i])) {
      minV_b[i] = rtb_Weighting_e;
    } else {
      minV_b[i] = Controller_ABS_VLC_AYC_ConstP.Z_Value[i];
    }

    /* MinMax: '<S44>/impMethod' incorporates:
     *  Constant: '<S38>/PS'
     *  MinMax: '<S44>/andorMethod'
     */
    if ((minV <= Controller_ABS_VLC_AYC_ConstP.PS_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.PS_Value[i])) {
      minV_c[i] = minV;
    } else {
      minV_c[i] = Controller_ABS_VLC_AYC_ConstP.PS_Value[i];
    }
  }

  /* If: '<S128>/If' incorporates:
   *  Constant: '<S141>/0'
   *  Constant: '<S142>/0'
   */
  if ((Controller_ABS_VLC_AYC_B.Yawerror < -0.5) ||
      (Controller_ABS_VLC_AYC_B.Yawerror > 0.0)) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S128>/If Action Subsystem' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_g = 0.0;

    /* End of Outputs for SubSystem: '<S128>/If Action Subsystem' */
  } else if (Controller_ABS_VLC_AYC_B.Yawerror == -0.25) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S128>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S142>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_g = 1.0;

    /* End of Outputs for SubSystem: '<S128>/If Action Subsystem1' */
  } else if (Controller_ABS_VLC_AYC_B.Yawerror < -0.25) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S128>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S144>/Action Port'
     */
    Controller_A_IfActionSubsystem1(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_g, -0.5, -0.25);

    /* End of Outputs for SubSystem: '<S128>/If Action Subsystem3' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S128>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    Controller_A_IfActionSubsystem2(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_g, -0.25, 0.0);

    /* End of Outputs for SubSystem: '<S128>/If Action Subsystem2' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_o = rtAction;

  /* End of If: '<S128>/If' */

  /* MinMax: '<S45>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_g <= Controller_ABS_VLC_AYC_B.Merge) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge)) {
    /* Product: '<S45>/Weighting' */
    rtb_Weighting_b = Controller_ABS_VLC_AYC_B.Merge_g;
  } else {
    /* Product: '<S45>/Weighting' */
    rtb_Weighting_b = Controller_ABS_VLC_AYC_B.Merge;
  }

  /* End of MinMax: '<S45>/andorMethod' */

  /* MinMax: '<S46>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_g <= Controller_ABS_VLC_AYC_B.Merge_k) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_k)) {
    /* Product: '<S46>/Weighting' */
    rtb_Weighting_os = Controller_ABS_VLC_AYC_B.Merge_g;
  } else {
    /* Product: '<S46>/Weighting' */
    rtb_Weighting_os = Controller_ABS_VLC_AYC_B.Merge_k;
  }

  /* End of MinMax: '<S46>/andorMethod' */

  /* MinMax: '<S47>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_g <= Controller_ABS_VLC_AYC_B.Merge_o) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_o)) {
    /* Product: '<S47>/Weighting' */
    rtb_Weighting_em = Controller_ABS_VLC_AYC_B.Merge_g;
  } else {
    /* Product: '<S47>/Weighting' */
    rtb_Weighting_em = Controller_ABS_VLC_AYC_B.Merge_o;
  }

  /* End of MinMax: '<S47>/andorMethod' */

  /* MinMax: '<S48>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_g <= Controller_ABS_VLC_AYC_B.Merge_f) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_f)) {
    /* Product: '<S48>/Weighting' */
    rtb_Weighting_be = Controller_ABS_VLC_AYC_B.Merge_g;
  } else {
    /* Product: '<S48>/Weighting' */
    rtb_Weighting_be = Controller_ABS_VLC_AYC_B.Merge_f;
  }

  /* End of MinMax: '<S48>/andorMethod' */

  /* MinMax: '<S49>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_g <= Controller_ABS_VLC_AYC_B.Merge_kg) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_kg)) {
    /* Product: '<S49>/Weighting' */
    rtb_Weighting_k3 = Controller_ABS_VLC_AYC_B.Merge_g;
  } else {
    /* Product: '<S49>/Weighting' */
    rtb_Weighting_k3 = Controller_ABS_VLC_AYC_B.Merge_kg;
  }

  /* End of MinMax: '<S49>/andorMethod' */

  /* MinMax: '<S51>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_g <= Controller_ABS_VLC_AYC_B.Merge_fu) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_fu)) {
    /* Product: '<S51>/Weighting' */
    rtb_Weighting_h = Controller_ABS_VLC_AYC_B.Merge_g;
  } else {
    /* Product: '<S51>/Weighting' */
    rtb_Weighting_h = Controller_ABS_VLC_AYC_B.Merge_fu;
  }

  /* End of MinMax: '<S51>/andorMethod' */

  /* MinMax: '<S52>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_g <= Controller_ABS_VLC_AYC_B.Merge_oo) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_oo)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_g;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge_oo;
  }

  /* Product: '<S52>/Weighting' incorporates:
   *  MinMax: '<S52>/andorMethod'
   */
  rtb_Weighting_cb = minV;
  for (i = 0; i < 101; i++) {
    /* MinMax: '<S45>/impMethod' incorporates:
     *  Constant: '<S38>/NVB'
     */
    if ((rtb_Weighting_b <= Controller_ABS_VLC_AYC_ConstP.NVB_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NVB_Value[i])) {
      minV_d[i] = rtb_Weighting_b;
    } else {
      minV_d[i] = Controller_ABS_VLC_AYC_ConstP.NVB_Value[i];
    }

    /* MinMax: '<S46>/impMethod' incorporates:
     *  Constant: '<S38>/NB'
     */
    if ((rtb_Weighting_os <= Controller_ABS_VLC_AYC_ConstP.NB_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NB_Value[i])) {
      minV_e[i] = rtb_Weighting_os;
    } else {
      minV_e[i] = Controller_ABS_VLC_AYC_ConstP.NB_Value[i];
    }

    /* MinMax: '<S47>/impMethod' incorporates:
     *  Constant: '<S38>/NM'
     */
    if ((rtb_Weighting_em <= Controller_ABS_VLC_AYC_ConstP.NM_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NM_Value[i])) {
      minV_f[i] = rtb_Weighting_em;
    } else {
      minV_f[i] = Controller_ABS_VLC_AYC_ConstP.NM_Value[i];
    }

    /* MinMax: '<S48>/impMethod' incorporates:
     *  Constant: '<S38>/NS'
     */
    if ((rtb_Weighting_be <= Controller_ABS_VLC_AYC_ConstP.NS_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NS_Value[i])) {
      minV_g[i] = rtb_Weighting_be;
    } else {
      minV_g[i] = Controller_ABS_VLC_AYC_ConstP.NS_Value[i];
    }

    /* MinMax: '<S49>/impMethod' incorporates:
     *  Constant: '<S38>/Z'
     */
    if ((rtb_Weighting_k3 <= Controller_ABS_VLC_AYC_ConstP.Z_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.Z_Value[i])) {
      minV_h[i] = rtb_Weighting_k3;
    } else {
      minV_h[i] = Controller_ABS_VLC_AYC_ConstP.Z_Value[i];
    }

    /* MinMax: '<S51>/impMethod' incorporates:
     *  Constant: '<S38>/PS'
     */
    if ((rtb_Weighting_h <= Controller_ABS_VLC_AYC_ConstP.PS_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PS_Value[i])) {
      minV_i[i] = rtb_Weighting_h;
    } else {
      minV_i[i] = Controller_ABS_VLC_AYC_ConstP.PS_Value[i];
    }

    /* MinMax: '<S52>/impMethod' incorporates:
     *  Constant: '<S38>/PM'
     *  MinMax: '<S52>/andorMethod'
     */
    if ((minV <= Controller_ABS_VLC_AYC_ConstP.PM_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.PM_Value[i])) {
      minV_j[i] = minV;
    } else {
      minV_j[i] = Controller_ABS_VLC_AYC_ConstP.PM_Value[i];
    }
  }

  /* If: '<S132>/If' incorporates:
   *  Constant: '<S157>/0'
   *  Constant: '<S158>/0'
   */
  if ((Controller_ABS_VLC_AYC_B.Yawerror < -0.25) ||
      (Controller_ABS_VLC_AYC_B.Yawerror > 0.25)) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S132>/If Action Subsystem' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_e = 0.0;

    /* End of Outputs for SubSystem: '<S132>/If Action Subsystem' */
  } else if (Controller_ABS_VLC_AYC_B.Yawerror == 0.0) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S132>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_e = 1.0;

    /* End of Outputs for SubSystem: '<S132>/If Action Subsystem1' */
  } else if (Controller_ABS_VLC_AYC_B.Yawerror < 0.0) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S132>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S160>/Action Port'
     */
    Controller_A_IfActionSubsystem1(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_e, -0.25, 0.0);

    /* End of Outputs for SubSystem: '<S132>/If Action Subsystem3' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S132>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S159>/Action Port'
     */
    Controller_A_IfActionSubsystem2(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_e, 0.0, 0.25);

    /* End of Outputs for SubSystem: '<S132>/If Action Subsystem2' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_j = rtAction;

  /* End of If: '<S132>/If' */

  /* MinMax: '<S53>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_e <= Controller_ABS_VLC_AYC_B.Merge) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge)) {
    /* Product: '<S53>/Weighting' */
    rtb_Weighting_oa = Controller_ABS_VLC_AYC_B.Merge_e;
  } else {
    /* Product: '<S53>/Weighting' */
    rtb_Weighting_oa = Controller_ABS_VLC_AYC_B.Merge;
  }

  /* End of MinMax: '<S53>/andorMethod' */

  /* MinMax: '<S54>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_e <= Controller_ABS_VLC_AYC_B.Merge_k) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_k)) {
    /* Product: '<S54>/Weighting' */
    rtb_Weighting_ci = Controller_ABS_VLC_AYC_B.Merge_e;
  } else {
    /* Product: '<S54>/Weighting' */
    rtb_Weighting_ci = Controller_ABS_VLC_AYC_B.Merge_k;
  }

  /* End of MinMax: '<S54>/andorMethod' */

  /* MinMax: '<S55>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_e <= Controller_ABS_VLC_AYC_B.Merge_o) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_o)) {
    /* Product: '<S55>/Weighting' */
    rtb_Weighting_oo = Controller_ABS_VLC_AYC_B.Merge_e;
  } else {
    /* Product: '<S55>/Weighting' */
    rtb_Weighting_oo = Controller_ABS_VLC_AYC_B.Merge_o;
  }

  /* End of MinMax: '<S55>/andorMethod' */

  /* MinMax: '<S56>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_e <= Controller_ABS_VLC_AYC_B.Merge_f) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_f)) {
    /* Product: '<S56>/Weighting' */
    rtb_Weighting_j5 = Controller_ABS_VLC_AYC_B.Merge_e;
  } else {
    /* Product: '<S56>/Weighting' */
    rtb_Weighting_j5 = Controller_ABS_VLC_AYC_B.Merge_f;
  }

  /* End of MinMax: '<S56>/andorMethod' */

  /* MinMax: '<S57>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_e <= Controller_ABS_VLC_AYC_B.Merge_kg) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_kg)) {
    /* Product: '<S57>/Weighting' */
    rtb_Weighting_ha = Controller_ABS_VLC_AYC_B.Merge_e;
  } else {
    /* Product: '<S57>/Weighting' */
    rtb_Weighting_ha = Controller_ABS_VLC_AYC_B.Merge_kg;
  }

  /* End of MinMax: '<S57>/andorMethod' */

  /* MinMax: '<S58>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_e <= Controller_ABS_VLC_AYC_B.Merge_fu) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_fu)) {
    /* Product: '<S58>/Weighting' */
    rtb_Weighting_kf = Controller_ABS_VLC_AYC_B.Merge_e;
  } else {
    /* Product: '<S58>/Weighting' */
    rtb_Weighting_kf = Controller_ABS_VLC_AYC_B.Merge_fu;
  }

  /* End of MinMax: '<S58>/andorMethod' */

  /* MinMax: '<S59>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_e <= Controller_ABS_VLC_AYC_B.Merge_oo) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_oo)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_e;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge_oo;
  }

  /* Product: '<S59>/Weighting' incorporates:
   *  MinMax: '<S59>/andorMethod'
   */
  rtb_Weighting_ct = minV;
  for (i = 0; i < 101; i++) {
    /* MinMax: '<S53>/impMethod' incorporates:
     *  Constant: '<S38>/NB'
     */
    if ((rtb_Weighting_oa <= Controller_ABS_VLC_AYC_ConstP.NB_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NB_Value[i])) {
      minV_k[i] = rtb_Weighting_oa;
    } else {
      minV_k[i] = Controller_ABS_VLC_AYC_ConstP.NB_Value[i];
    }

    /* MinMax: '<S54>/impMethod' incorporates:
     *  Constant: '<S38>/NM'
     */
    if ((rtb_Weighting_ci <= Controller_ABS_VLC_AYC_ConstP.NM_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NM_Value[i])) {
      minV_l[i] = rtb_Weighting_ci;
    } else {
      minV_l[i] = Controller_ABS_VLC_AYC_ConstP.NM_Value[i];
    }

    /* MinMax: '<S55>/impMethod' incorporates:
     *  Constant: '<S38>/NS'
     */
    if ((rtb_Weighting_oo <= Controller_ABS_VLC_AYC_ConstP.NS_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NS_Value[i])) {
      minV_m[i] = rtb_Weighting_oo;
    } else {
      minV_m[i] = Controller_ABS_VLC_AYC_ConstP.NS_Value[i];
    }

    /* MinMax: '<S56>/impMethod' incorporates:
     *  Constant: '<S38>/Z'
     */
    if ((rtb_Weighting_j5 <= Controller_ABS_VLC_AYC_ConstP.Z_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.Z_Value[i])) {
      minV_n[i] = rtb_Weighting_j5;
    } else {
      minV_n[i] = Controller_ABS_VLC_AYC_ConstP.Z_Value[i];
    }

    /* MinMax: '<S57>/impMethod' incorporates:
     *  Constant: '<S38>/PS'
     */
    if ((rtb_Weighting_ha <= Controller_ABS_VLC_AYC_ConstP.PS_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PS_Value[i])) {
      minV_o[i] = rtb_Weighting_ha;
    } else {
      minV_o[i] = Controller_ABS_VLC_AYC_ConstP.PS_Value[i];
    }

    /* MinMax: '<S58>/impMethod' incorporates:
     *  Constant: '<S38>/PM'
     */
    if ((rtb_Weighting_kf <= Controller_ABS_VLC_AYC_ConstP.PM_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PM_Value[i])) {
      minV_p[i] = rtb_Weighting_kf;
    } else {
      minV_p[i] = Controller_ABS_VLC_AYC_ConstP.PM_Value[i];
    }

    /* MinMax: '<S59>/impMethod' incorporates:
     *  Constant: '<S38>/PB'
     *  MinMax: '<S59>/andorMethod'
     */
    if ((minV <= Controller_ABS_VLC_AYC_ConstP.PB_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.PB_Value[i])) {
      minV_q[i] = minV;
    } else {
      minV_q[i] = Controller_ABS_VLC_AYC_ConstP.PB_Value[i];
    }
  }

  /* If: '<S131>/If' incorporates:
   *  Constant: '<S153>/0'
   *  Constant: '<S154>/0'
   */
  if ((Controller_ABS_VLC_AYC_B.Yawerror < 0.0) ||
      (Controller_ABS_VLC_AYC_B.Yawerror > 0.5)) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S131>/If Action Subsystem' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_oh = 0.0;

    /* End of Outputs for SubSystem: '<S131>/If Action Subsystem' */
  } else if (Controller_ABS_VLC_AYC_B.Yawerror == 0.25) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S131>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S154>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_oh = 1.0;

    /* End of Outputs for SubSystem: '<S131>/If Action Subsystem1' */
  } else if (Controller_ABS_VLC_AYC_B.Yawerror < 0.25) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S131>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    Controller_A_IfActionSubsystem1(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_oh, 0.0, 0.25);

    /* End of Outputs for SubSystem: '<S131>/If Action Subsystem3' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S131>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    Controller_A_IfActionSubsystem2(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_oh, 0.25, 0.5);

    /* End of Outputs for SubSystem: '<S131>/If Action Subsystem2' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_j3 = rtAction;

  /* End of If: '<S131>/If' */

  /* MinMax: '<S60>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_oh <= Controller_ABS_VLC_AYC_B.Merge) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge)) {
    /* Product: '<S60>/Weighting' */
    rtb_Weighting_oz = Controller_ABS_VLC_AYC_B.Merge_oh;
  } else {
    /* Product: '<S60>/Weighting' */
    rtb_Weighting_oz = Controller_ABS_VLC_AYC_B.Merge;
  }

  /* End of MinMax: '<S60>/andorMethod' */

  /* MinMax: '<S62>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_oh <= Controller_ABS_VLC_AYC_B.Merge_k) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_k)) {
    /* Product: '<S62>/Weighting' */
    rtb_Weighting_g1 = Controller_ABS_VLC_AYC_B.Merge_oh;
  } else {
    /* Product: '<S62>/Weighting' */
    rtb_Weighting_g1 = Controller_ABS_VLC_AYC_B.Merge_k;
  }

  /* End of MinMax: '<S62>/andorMethod' */

  /* MinMax: '<S63>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_oh <= Controller_ABS_VLC_AYC_B.Merge_o) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_o)) {
    /* Product: '<S63>/Weighting' */
    rtb_Weighting_ix = Controller_ABS_VLC_AYC_B.Merge_oh;
  } else {
    /* Product: '<S63>/Weighting' */
    rtb_Weighting_ix = Controller_ABS_VLC_AYC_B.Merge_o;
  }

  /* End of MinMax: '<S63>/andorMethod' */

  /* MinMax: '<S64>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_oh <= Controller_ABS_VLC_AYC_B.Merge_f) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_f)) {
    /* Product: '<S64>/Weighting' */
    rtb_Weighting_l = Controller_ABS_VLC_AYC_B.Merge_oh;
  } else {
    /* Product: '<S64>/Weighting' */
    rtb_Weighting_l = Controller_ABS_VLC_AYC_B.Merge_f;
  }

  /* End of MinMax: '<S64>/andorMethod' */

  /* MinMax: '<S65>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_oh <= Controller_ABS_VLC_AYC_B.Merge_kg) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_kg)) {
    /* Product: '<S65>/Weighting' */
    rtb_Weighting_gv = Controller_ABS_VLC_AYC_B.Merge_oh;
  } else {
    /* Product: '<S65>/Weighting' */
    rtb_Weighting_gv = Controller_ABS_VLC_AYC_B.Merge_kg;
  }

  /* End of MinMax: '<S65>/andorMethod' */

  /* MinMax: '<S66>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_oh <= Controller_ABS_VLC_AYC_B.Merge_fu) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_fu)) {
    /* Product: '<S66>/Weighting' */
    rtb_Weighting_bo = Controller_ABS_VLC_AYC_B.Merge_oh;
  } else {
    /* Product: '<S66>/Weighting' */
    rtb_Weighting_bo = Controller_ABS_VLC_AYC_B.Merge_fu;
  }

  /* End of MinMax: '<S66>/andorMethod' */

  /* MinMax: '<S67>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_oh <= Controller_ABS_VLC_AYC_B.Merge_oo) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_oo)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_oh;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge_oo;
  }

  /* Product: '<S67>/Weighting' incorporates:
   *  MinMax: '<S67>/andorMethod'
   */
  rtb_Weighting_j2 = minV;
  for (i = 0; i < 101; i++) {
    /* MinMax: '<S60>/impMethod' incorporates:
     *  Constant: '<S38>/NM'
     */
    if ((rtb_Weighting_oz <= Controller_ABS_VLC_AYC_ConstP.NM_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NM_Value[i])) {
      minV_r[i] = rtb_Weighting_oz;
    } else {
      minV_r[i] = Controller_ABS_VLC_AYC_ConstP.NM_Value[i];
    }

    /* MinMax: '<S62>/impMethod' incorporates:
     *  Constant: '<S38>/NS'
     */
    if ((rtb_Weighting_g1 <= Controller_ABS_VLC_AYC_ConstP.NS_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NS_Value[i])) {
      minV_s[i] = rtb_Weighting_g1;
    } else {
      minV_s[i] = Controller_ABS_VLC_AYC_ConstP.NS_Value[i];
    }

    /* MinMax: '<S63>/impMethod' incorporates:
     *  Constant: '<S38>/Z'
     */
    if ((rtb_Weighting_ix <= Controller_ABS_VLC_AYC_ConstP.Z_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.Z_Value[i])) {
      minV_t[i] = rtb_Weighting_ix;
    } else {
      minV_t[i] = Controller_ABS_VLC_AYC_ConstP.Z_Value[i];
    }

    /* MinMax: '<S64>/impMethod' incorporates:
     *  Constant: '<S38>/PS'
     */
    if ((rtb_Weighting_l <= Controller_ABS_VLC_AYC_ConstP.PS_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PS_Value[i])) {
      minV_u[i] = rtb_Weighting_l;
    } else {
      minV_u[i] = Controller_ABS_VLC_AYC_ConstP.PS_Value[i];
    }

    /* MinMax: '<S65>/impMethod' incorporates:
     *  Constant: '<S38>/PM'
     */
    if ((rtb_Weighting_gv <= Controller_ABS_VLC_AYC_ConstP.PM_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PM_Value[i])) {
      minV_v[i] = rtb_Weighting_gv;
    } else {
      minV_v[i] = Controller_ABS_VLC_AYC_ConstP.PM_Value[i];
    }

    /* MinMax: '<S66>/impMethod' incorporates:
     *  Constant: '<S38>/PB'
     */
    if ((rtb_Weighting_bo <= Controller_ABS_VLC_AYC_ConstP.PB_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PB_Value[i])) {
      minV_w[i] = rtb_Weighting_bo;
    } else {
      minV_w[i] = Controller_ABS_VLC_AYC_ConstP.PB_Value[i];
    }

    /* MinMax: '<S67>/impMethod' incorporates:
     *  Constant: '<S38>/PVB'
     *  MinMax: '<S67>/andorMethod'
     */
    if ((minV <= Controller_ABS_VLC_AYC_ConstP.PVB_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.PVB_Value[i])) {
      minV_x[i] = minV;
    } else {
      minV_x[i] = Controller_ABS_VLC_AYC_ConstP.PVB_Value[i];
    }
  }

  /* If: '<S130>/If' incorporates:
   *  Constant: '<S149>/0'
   *  Constant: '<S150>/0'
   */
  if ((Controller_ABS_VLC_AYC_B.Yawerror < 0.25) ||
      (Controller_ABS_VLC_AYC_B.Yawerror > 1.0)) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem' incorporates:
     *  ActionPort: '<S149>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_a = 0.0;

    /* End of Outputs for SubSystem: '<S130>/If Action Subsystem' */
  } else if (Controller_ABS_VLC_AYC_B.Yawerror == 0.5) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_a = 1.0;

    /* End of Outputs for SubSystem: '<S130>/If Action Subsystem1' */
  } else if (Controller_ABS_VLC_AYC_B.Yawerror < 0.5) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    Controller_A_IfActionSubsystem1(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_a, 0.25, 0.5);

    /* End of Outputs for SubSystem: '<S130>/If Action Subsystem3' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S130>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    Controller_A_IfActionSubsystem2(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_a, 0.5, 1.0);

    /* End of Outputs for SubSystem: '<S130>/If Action Subsystem2' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_h = rtAction;

  /* End of If: '<S130>/If' */

  /* MinMax: '<S68>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_a <= Controller_ABS_VLC_AYC_B.Merge) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge)) {
    /* Product: '<S68>/Weighting' */
    rtb_Weighting_cp = Controller_ABS_VLC_AYC_B.Merge_a;
  } else {
    /* Product: '<S68>/Weighting' */
    rtb_Weighting_cp = Controller_ABS_VLC_AYC_B.Merge;
  }

  /* End of MinMax: '<S68>/andorMethod' */

  /* MinMax: '<S69>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_a <= Controller_ABS_VLC_AYC_B.Merge_k) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_k)) {
    /* Product: '<S69>/Weighting' */
    rtb_Weighting_br = Controller_ABS_VLC_AYC_B.Merge_a;
  } else {
    /* Product: '<S69>/Weighting' */
    rtb_Weighting_br = Controller_ABS_VLC_AYC_B.Merge_k;
  }

  /* End of MinMax: '<S69>/andorMethod' */

  /* MinMax: '<S70>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_a <= Controller_ABS_VLC_AYC_B.Merge_o) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_o)) {
    /* Product: '<S70>/Weighting' */
    rtb_Weighting_j2f = Controller_ABS_VLC_AYC_B.Merge_a;
  } else {
    /* Product: '<S70>/Weighting' */
    rtb_Weighting_j2f = Controller_ABS_VLC_AYC_B.Merge_o;
  }

  /* End of MinMax: '<S70>/andorMethod' */

  /* MinMax: '<S71>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_a <= Controller_ABS_VLC_AYC_B.Merge_f) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_f)) {
    /* Product: '<S71>/Weighting' */
    rtb_Weighting_mw = Controller_ABS_VLC_AYC_B.Merge_a;
  } else {
    /* Product: '<S71>/Weighting' */
    rtb_Weighting_mw = Controller_ABS_VLC_AYC_B.Merge_f;
  }

  /* End of MinMax: '<S71>/andorMethod' */

  /* MinMax: '<S73>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_a <= Controller_ABS_VLC_AYC_B.Merge_kg) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_kg)) {
    /* Product: '<S73>/Weighting' */
    rtb_Weighting_gi = Controller_ABS_VLC_AYC_B.Merge_a;
  } else {
    /* Product: '<S73>/Weighting' */
    rtb_Weighting_gi = Controller_ABS_VLC_AYC_B.Merge_kg;
  }

  /* End of MinMax: '<S73>/andorMethod' */

  /* MinMax: '<S74>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_a <= Controller_ABS_VLC_AYC_B.Merge_fu) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_fu)) {
    /* Product: '<S74>/Weighting' */
    rtb_Weighting_mn = Controller_ABS_VLC_AYC_B.Merge_a;
  } else {
    /* Product: '<S74>/Weighting' */
    rtb_Weighting_mn = Controller_ABS_VLC_AYC_B.Merge_fu;
  }

  /* End of MinMax: '<S74>/andorMethod' */

  /* MinMax: '<S75>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_a <= Controller_ABS_VLC_AYC_B.Merge_oo) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_oo)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_a;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge_oo;
  }

  /* Product: '<S75>/Weighting' incorporates:
   *  MinMax: '<S75>/andorMethod'
   */
  rtb_Weighting_d = minV;
  for (i = 0; i < 101; i++) {
    /* MinMax: '<S68>/impMethod' incorporates:
     *  Constant: '<S38>/NS'
     */
    if ((rtb_Weighting_cp <= Controller_ABS_VLC_AYC_ConstP.NS_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.NS_Value[i])) {
      minV_y[i] = rtb_Weighting_cp;
    } else {
      minV_y[i] = Controller_ABS_VLC_AYC_ConstP.NS_Value[i];
    }

    /* MinMax: '<S69>/impMethod' incorporates:
     *  Constant: '<S38>/Z'
     */
    if ((rtb_Weighting_br <= Controller_ABS_VLC_AYC_ConstP.Z_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.Z_Value[i])) {
      minV_z[i] = rtb_Weighting_br;
    } else {
      minV_z[i] = Controller_ABS_VLC_AYC_ConstP.Z_Value[i];
    }

    /* MinMax: '<S70>/impMethod' incorporates:
     *  Constant: '<S38>/PS'
     */
    if ((rtb_Weighting_j2f <= Controller_ABS_VLC_AYC_ConstP.PS_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PS_Value[i])) {
      minV_10[i] = rtb_Weighting_j2f;
    } else {
      minV_10[i] = Controller_ABS_VLC_AYC_ConstP.PS_Value[i];
    }

    /* MinMax: '<S71>/impMethod' incorporates:
     *  Constant: '<S38>/PM'
     */
    if ((rtb_Weighting_mw <= Controller_ABS_VLC_AYC_ConstP.PM_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PM_Value[i])) {
      minV_11[i] = rtb_Weighting_mw;
    } else {
      minV_11[i] = Controller_ABS_VLC_AYC_ConstP.PM_Value[i];
    }

    /* MinMax: '<S73>/impMethod' incorporates:
     *  Constant: '<S38>/PB'
     */
    if ((rtb_Weighting_gi <= Controller_ABS_VLC_AYC_ConstP.PB_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PB_Value[i])) {
      minV_12[i] = rtb_Weighting_gi;
    } else {
      minV_12[i] = Controller_ABS_VLC_AYC_ConstP.PB_Value[i];
    }

    /* MinMax: '<S74>/impMethod' incorporates:
     *  Constant: '<S38>/PVB'
     */
    if ((rtb_Weighting_mn <= Controller_ABS_VLC_AYC_ConstP.PVB_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PVB_Value[i])) {
      minV_13[i] = rtb_Weighting_mn;
    } else {
      minV_13[i] = Controller_ABS_VLC_AYC_ConstP.PVB_Value[i];
    }

    /* MinMax: '<S75>/impMethod' incorporates:
     *  Constant: '<S38>/PVB'
     *  MinMax: '<S75>/andorMethod'
     */
    if ((minV <= Controller_ABS_VLC_AYC_ConstP.PVB_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.PVB_Value[i])) {
      minV_14[i] = minV;
    } else {
      minV_14[i] = Controller_ABS_VLC_AYC_ConstP.PVB_Value[i];
    }
  }

  /* If: '<S129>/If' incorporates:
   *  Constant: '<S145>/0'
   *  Constant: '<S147>/0'
   */
  if (Controller_ABS_VLC_AYC_B.Yawerror < 0.5) {
    rtAction = 0;

    /* Outputs for IfAction SubSystem: '<S129>/If Action Subsystem' incorporates:
     *  ActionPort: '<S145>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_c = 0.0;

    /* End of Outputs for SubSystem: '<S129>/If Action Subsystem' */
  } else if ((Controller_ABS_VLC_AYC_B.Yawerror >= 1.0) &&
             (Controller_ABS_VLC_AYC_B.Yawerror <= (rtInf))) {
    rtAction = 1;

    /* Outputs for IfAction SubSystem: '<S129>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S147>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_c = 1.0;

    /* End of Outputs for SubSystem: '<S129>/If Action Subsystem2' */
  } else if (Controller_ABS_VLC_AYC_B.Yawerror < 1.0) {
    rtAction = 2;

    /* Outputs for IfAction SubSystem: '<S129>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S146>/Action Port'
     */
    Controller_A_IfActionSubsystem1(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_c, 0.5, 1.0);

    /* End of Outputs for SubSystem: '<S129>/If Action Subsystem1' */
  } else {
    rtAction = 3;

    /* Outputs for IfAction SubSystem: '<S129>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S148>/Action Port'
     */
    Controller_A_IfActionSubsystem3(Controller_ABS_VLC_AYC_B.Yawerror,
      &Controller_ABS_VLC_AYC_B.Merge_c, rtInf, rtInf);

    /* End of Outputs for SubSystem: '<S129>/If Action Subsystem3' */
  }

  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_n = rtAction;

  /* End of If: '<S129>/If' */

  /* MinMax: '<S76>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_c <= Controller_ABS_VLC_AYC_B.Merge) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge)) {
    /* Product: '<S76>/Weighting' */
    rtb_Weighting_ok = Controller_ABS_VLC_AYC_B.Merge_c;
  } else {
    /* Product: '<S76>/Weighting' */
    rtb_Weighting_ok = Controller_ABS_VLC_AYC_B.Merge;
  }

  /* End of MinMax: '<S76>/andorMethod' */

  /* MinMax: '<S77>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_c <= Controller_ABS_VLC_AYC_B.Merge_k) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_k)) {
    /* Product: '<S77>/Weighting' */
    rtb_Weighting_kl = Controller_ABS_VLC_AYC_B.Merge_c;
  } else {
    /* Product: '<S77>/Weighting' */
    rtb_Weighting_kl = Controller_ABS_VLC_AYC_B.Merge_k;
  }

  /* End of MinMax: '<S77>/andorMethod' */

  /* MinMax: '<S78>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_c <= Controller_ABS_VLC_AYC_B.Merge_o) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_o)) {
    /* Product: '<S78>/Weighting' */
    rtb_Weighting_bx = Controller_ABS_VLC_AYC_B.Merge_c;
  } else {
    /* Product: '<S78>/Weighting' */
    rtb_Weighting_bx = Controller_ABS_VLC_AYC_B.Merge_o;
  }

  /* End of MinMax: '<S78>/andorMethod' */

  /* MinMax: '<S79>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_c <= Controller_ABS_VLC_AYC_B.Merge_f) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_f)) {
    /* Product: '<S79>/Weighting' */
    rtb_Weighting_lv = Controller_ABS_VLC_AYC_B.Merge_c;
  } else {
    /* Product: '<S79>/Weighting' */
    rtb_Weighting_lv = Controller_ABS_VLC_AYC_B.Merge_f;
  }

  /* End of MinMax: '<S79>/andorMethod' */

  /* MinMax: '<S80>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_c <= Controller_ABS_VLC_AYC_B.Merge_kg) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_kg)) {
    /* Product: '<S80>/Weighting' */
    rtb_Weighting_m2 = Controller_ABS_VLC_AYC_B.Merge_c;
  } else {
    /* Product: '<S80>/Weighting' */
    rtb_Weighting_m2 = Controller_ABS_VLC_AYC_B.Merge_kg;
  }

  /* End of MinMax: '<S80>/andorMethod' */

  /* MinMax: '<S81>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_c <= Controller_ABS_VLC_AYC_B.Merge_fu) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_fu)) {
    /* Product: '<S81>/Weighting' */
    rtb_Weighting_f = Controller_ABS_VLC_AYC_B.Merge_c;
  } else {
    /* Product: '<S81>/Weighting' */
    rtb_Weighting_f = Controller_ABS_VLC_AYC_B.Merge_fu;
  }

  /* End of MinMax: '<S81>/andorMethod' */

  /* MinMax: '<S82>/andorMethod' */
  if ((Controller_ABS_VLC_AYC_B.Merge_c <= Controller_ABS_VLC_AYC_B.Merge_oo) ||
      rtIsNaN(Controller_ABS_VLC_AYC_B.Merge_oo)) {
    minV = Controller_ABS_VLC_AYC_B.Merge_c;
  } else {
    minV = Controller_ABS_VLC_AYC_B.Merge_oo;
  }

  /* MinMax: '<S35>/AggMethod1' incorporates:
   *  Constant: '<S38>/PB'
   *  Constant: '<S38>/PM'
   *  Constant: '<S38>/PS'
   *  Constant: '<S38>/PVB'
   *  Constant: '<S38>/Z'
   *  MinMax: '<S39>/impMethod'
   *  MinMax: '<S40>/impMethod'
   *  MinMax: '<S41>/impMethod'
   *  MinMax: '<S42>/impMethod'
   *  MinMax: '<S43>/impMethod'
   *  MinMax: '<S44>/impMethod'
   *  MinMax: '<S45>/impMethod'
   *  MinMax: '<S46>/impMethod'
   *  MinMax: '<S47>/impMethod'
   *  MinMax: '<S48>/impMethod'
   *  MinMax: '<S49>/impMethod'
   *  MinMax: '<S50>/impMethod'
   *  MinMax: '<S51>/impMethod'
   *  MinMax: '<S52>/impMethod'
   *  MinMax: '<S53>/impMethod'
   *  MinMax: '<S54>/impMethod'
   *  MinMax: '<S55>/impMethod'
   *  MinMax: '<S56>/impMethod'
   *  MinMax: '<S57>/impMethod'
   *  MinMax: '<S58>/impMethod'
   *  MinMax: '<S59>/impMethod'
   *  MinMax: '<S60>/impMethod'
   *  MinMax: '<S61>/impMethod'
   *  MinMax: '<S62>/impMethod'
   *  MinMax: '<S63>/impMethod'
   *  MinMax: '<S64>/impMethod'
   *  MinMax: '<S65>/impMethod'
   *  MinMax: '<S66>/impMethod'
   *  MinMax: '<S67>/impMethod'
   *  MinMax: '<S68>/impMethod'
   *  MinMax: '<S69>/impMethod'
   *  MinMax: '<S70>/impMethod'
   *  MinMax: '<S71>/impMethod'
   *  MinMax: '<S72>/impMethod'
   *  MinMax: '<S73>/impMethod'
   *  MinMax: '<S74>/impMethod'
   *  MinMax: '<S75>/impMethod'
   *  MinMax: '<S76>/impMethod'
   *  MinMax: '<S77>/impMethod'
   *  MinMax: '<S78>/impMethod'
   *  MinMax: '<S79>/impMethod'
   *  MinMax: '<S80>/impMethod'
   *  MinMax: '<S81>/impMethod'
   *  MinMax: '<S82>/andorMethod'
   *  MinMax: '<S82>/impMethod'
   *  MinMax: '<S83>/impMethod'
   *  MinMax: '<S84>/impMethod'
   *  MinMax: '<S85>/impMethod'
   *  MinMax: '<S86>/impMethod'
   *  MinMax: '<S87>/impMethod'
   */
  for (i = 0; i < 101; i++) {
    if ((rtb_ProductCOA[i] >= minV_0[i]) || rtIsNaN(minV_0[i])) {
      rtb_Sum = rtb_ProductCOA[i];
    } else {
      rtb_Sum = minV_0[i];
    }

    if (!((rtb_Sum >= minV_1[i]) || rtIsNaN(minV_1[i]))) {
      rtb_Sum = minV_1[i];
    }

    if (!((rtb_Sum >= minV_2[i]) || rtIsNaN(minV_2[i]))) {
      rtb_Sum = minV_2[i];
    }

    if (!((rtb_Sum >= minV_3[i]) || rtIsNaN(minV_3[i]))) {
      rtb_Sum = minV_3[i];
    }

    if (!((rtb_Sum >= minV_4[i]) || rtIsNaN(minV_4[i]))) {
      rtb_Sum = minV_4[i];
    }

    if (!((rtb_Sum >= minV_5[i]) || rtIsNaN(minV_5[i]))) {
      rtb_Sum = minV_5[i];
    }

    if (!((rtb_Sum >= minV_6[i]) || rtIsNaN(minV_6[i]))) {
      rtb_Sum = minV_6[i];
    }

    if (!((rtb_Sum >= minV_7[i]) || rtIsNaN(minV_7[i]))) {
      rtb_Sum = minV_7[i];
    }

    if (!((rtb_Sum >= minV_8[i]) || rtIsNaN(minV_8[i]))) {
      rtb_Sum = minV_8[i];
    }

    if (!((rtb_Sum >= minV_9[i]) || rtIsNaN(minV_9[i]))) {
      rtb_Sum = minV_9[i];
    }

    if (!((rtb_Sum >= minV_a[i]) || rtIsNaN(minV_a[i]))) {
      rtb_Sum = minV_a[i];
    }

    if (!((rtb_Sum >= minV_b[i]) || rtIsNaN(minV_b[i]))) {
      rtb_Sum = minV_b[i];
    }

    if (!((rtb_Sum >= minV_c[i]) || rtIsNaN(minV_c[i]))) {
      rtb_Sum = minV_c[i];
    }

    if (!((rtb_Sum >= minV_d[i]) || rtIsNaN(minV_d[i]))) {
      rtb_Sum = minV_d[i];
    }

    if (!((rtb_Sum >= minV_e[i]) || rtIsNaN(minV_e[i]))) {
      rtb_Sum = minV_e[i];
    }

    if (!((rtb_Sum >= minV_f[i]) || rtIsNaN(minV_f[i]))) {
      rtb_Sum = minV_f[i];
    }

    if (!((rtb_Sum >= minV_g[i]) || rtIsNaN(minV_g[i]))) {
      rtb_Sum = minV_g[i];
    }

    if (!((rtb_Sum >= minV_h[i]) || rtIsNaN(minV_h[i]))) {
      rtb_Sum = minV_h[i];
    }

    if (!((rtb_Sum >= minV_i[i]) || rtIsNaN(minV_i[i]))) {
      rtb_Sum = minV_i[i];
    }

    if (!((rtb_Sum >= minV_j[i]) || rtIsNaN(minV_j[i]))) {
      rtb_Sum = minV_j[i];
    }

    if (!((rtb_Sum >= minV_k[i]) || rtIsNaN(minV_k[i]))) {
      rtb_Sum = minV_k[i];
    }

    if (!((rtb_Sum >= minV_l[i]) || rtIsNaN(minV_l[i]))) {
      rtb_Sum = minV_l[i];
    }

    if (!((rtb_Sum >= minV_m[i]) || rtIsNaN(minV_m[i]))) {
      rtb_Sum = minV_m[i];
    }

    if (!((rtb_Sum >= minV_n[i]) || rtIsNaN(minV_n[i]))) {
      rtb_Sum = minV_n[i];
    }

    if (!((rtb_Sum >= minV_o[i]) || rtIsNaN(minV_o[i]))) {
      rtb_Sum = minV_o[i];
    }

    if (!((rtb_Sum >= minV_p[i]) || rtIsNaN(minV_p[i]))) {
      rtb_Sum = minV_p[i];
    }

    if (!((rtb_Sum >= minV_q[i]) || rtIsNaN(minV_q[i]))) {
      rtb_Sum = minV_q[i];
    }

    if (!((rtb_Sum >= minV_r[i]) || rtIsNaN(minV_r[i]))) {
      rtb_Sum = minV_r[i];
    }

    if (!((rtb_Sum >= minV_s[i]) || rtIsNaN(minV_s[i]))) {
      rtb_Sum = minV_s[i];
    }

    if (!((rtb_Sum >= minV_t[i]) || rtIsNaN(minV_t[i]))) {
      rtb_Sum = minV_t[i];
    }

    if (!((rtb_Sum >= minV_u[i]) || rtIsNaN(minV_u[i]))) {
      rtb_Sum = minV_u[i];
    }

    if (!((rtb_Sum >= minV_v[i]) || rtIsNaN(minV_v[i]))) {
      rtb_Sum = minV_v[i];
    }

    if (!((rtb_Sum >= minV_w[i]) || rtIsNaN(minV_w[i]))) {
      rtb_Sum = minV_w[i];
    }

    if (!((rtb_Sum >= minV_x[i]) || rtIsNaN(minV_x[i]))) {
      rtb_Sum = minV_x[i];
    }

    if (!((rtb_Sum >= minV_y[i]) || rtIsNaN(minV_y[i]))) {
      rtb_Sum = minV_y[i];
    }

    if (!((rtb_Sum >= minV_z[i]) || rtIsNaN(minV_z[i]))) {
      rtb_Sum = minV_z[i];
    }

    if (!((rtb_Sum >= minV_10[i]) || rtIsNaN(minV_10[i]))) {
      rtb_Sum = minV_10[i];
    }

    if (!((rtb_Sum >= minV_11[i]) || rtIsNaN(minV_11[i]))) {
      rtb_Sum = minV_11[i];
    }

    if (!((rtb_Sum >= minV_12[i]) || rtIsNaN(minV_12[i]))) {
      rtb_Sum = minV_12[i];
    }

    if (!((rtb_Sum >= minV_13[i]) || rtIsNaN(minV_13[i]))) {
      rtb_Sum = minV_13[i];
    }

    if (!((rtb_Sum >= minV_14[i]) || rtIsNaN(minV_14[i]))) {
      rtb_Sum = minV_14[i];
    }

    if ((rtb_Weighting_ok <= Controller_ABS_VLC_AYC_ConstP.Z_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.Z_Value[i])) {
      y = rtb_Weighting_ok;
    } else {
      y = Controller_ABS_VLC_AYC_ConstP.Z_Value[i];
    }

    if (!((rtb_Sum >= y) || rtIsNaN(y))) {
      rtb_Sum = y;
    }

    if ((rtb_Weighting_kl <= Controller_ABS_VLC_AYC_ConstP.PS_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PS_Value[i])) {
      y = rtb_Weighting_kl;
    } else {
      y = Controller_ABS_VLC_AYC_ConstP.PS_Value[i];
    }

    if (!((rtb_Sum >= y) || rtIsNaN(y))) {
      rtb_Sum = y;
    }

    if ((rtb_Weighting_bx <= Controller_ABS_VLC_AYC_ConstP.PM_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PM_Value[i])) {
      y = rtb_Weighting_bx;
    } else {
      y = Controller_ABS_VLC_AYC_ConstP.PM_Value[i];
    }

    if (!((rtb_Sum >= y) || rtIsNaN(y))) {
      rtb_Sum = y;
    }

    if ((rtb_Weighting_lv <= Controller_ABS_VLC_AYC_ConstP.PB_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PB_Value[i])) {
      y = rtb_Weighting_lv;
    } else {
      y = Controller_ABS_VLC_AYC_ConstP.PB_Value[i];
    }

    if (!((rtb_Sum >= y) || rtIsNaN(y))) {
      rtb_Sum = y;
    }

    if ((rtb_Weighting_m2 <= Controller_ABS_VLC_AYC_ConstP.PVB_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PVB_Value[i])) {
      y = rtb_Weighting_m2;
    } else {
      y = Controller_ABS_VLC_AYC_ConstP.PVB_Value[i];
    }

    if (!((rtb_Sum >= y) || rtIsNaN(y))) {
      rtb_Sum = y;
    }

    if ((rtb_Weighting_f <= Controller_ABS_VLC_AYC_ConstP.PVB_Value[i]) ||
        rtIsNaN(Controller_ABS_VLC_AYC_ConstP.PVB_Value[i])) {
      y = rtb_Weighting_f;
    } else {
      y = Controller_ABS_VLC_AYC_ConstP.PVB_Value[i];
    }

    if (!((rtb_Sum >= y) || rtIsNaN(y))) {
      rtb_Sum = y;
    }

    if ((minV <= Controller_ABS_VLC_AYC_ConstP.PVB_Value[i]) || rtIsNaN
        (Controller_ABS_VLC_AYC_ConstP.PVB_Value[i])) {
      y = minV;
    } else {
      y = Controller_ABS_VLC_AYC_ConstP.PVB_Value[i];
    }

    if (!((rtb_Sum >= y) || rtIsNaN(y))) {
      rtb_Sum = y;
    }

    rtb_ProductCOA[i] = rtb_Sum;
  }

  /* Sum: '<S37>/Sum1' incorporates:
   *  MinMax: '<S35>/AggMethod1'
   */
  rtb_Sum = rtb_ProductCOA[0];
  for (i = 0; i < 100; i++) {
    rtb_Sum += rtb_ProductCOA[i + 1];
  }

  rtb_Sum1 = rtb_Sum;

  /* End of Sum: '<S37>/Sum1' */

  /* If: '<S37>/If' incorporates:
   *  Constant: '<S124>/One'
   *  Inport: '<S125>/u1'
   */
  if (rtb_Sum1 <= 0.0) {
    Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_il = 0;

    /* Outputs for IfAction SubSystem: '<S37>/Action: One' incorporates:
     *  ActionPort: '<S124>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_g2 = 1.0;

    /* End of Outputs for SubSystem: '<S37>/Action: One' */
  } else {
    Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_il = 1;

    /* Outputs for IfAction SubSystem: '<S37>/Action: u1' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    Controller_ABS_VLC_AYC_B.Merge_g2 = rtb_Sum1;

    /* End of Outputs for SubSystem: '<S37>/Action: u1' */
  }

  /* End of If: '<S37>/If' */

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/MidRange'
   *  Constant: '<S35>/Zero'
   *  MinMax: '<S82>/andorMethod'
   *  Product: '<S37>/Averaging (COA)'
   *  RelationalOperator: '<S35>/Zero Firing Strength?'
   *  Sum: '<S35>/Total Firing Strength'
   */
  if (((((((((((((((((((((((((((((((((((((((((((((((((rtb_Weighting_hm +
      rtb_Weighting) + rtb_Weighting_o) + rtb_Weighting_n) + rtb_Weighting_a) +
      rtb_Weighting_am) + rtb_Weighting_j) + rtb_Weighting_m) + rtb_Weighting_k)
    + rtb_Weighting_i) + rtb_Weighting_as) + rtb_Weighting_c) + rtb_Weighting_e)
    + rtb_Weighting_g) + rtb_Weighting_b) + rtb_Weighting_os) + rtb_Weighting_em)
    + rtb_Weighting_be) + rtb_Weighting_k3) + rtb_Weighting_h) +
      rtb_Weighting_cb) + rtb_Weighting_oa) + rtb_Weighting_ci) +
      rtb_Weighting_oo) + rtb_Weighting_j5) + rtb_Weighting_ha) +
      rtb_Weighting_kf) + rtb_Weighting_ct) + rtb_Weighting_oz) +
      rtb_Weighting_g1) + rtb_Weighting_ix) + rtb_Weighting_l) +
                       rtb_Weighting_gv) + rtb_Weighting_bo) + rtb_Weighting_j2)
                    + rtb_Weighting_cp) + rtb_Weighting_br) + rtb_Weighting_j2f)
                 + rtb_Weighting_mw) + rtb_Weighting_gi) + rtb_Weighting_mn) +
              rtb_Weighting_d) + rtb_Weighting_ok) + rtb_Weighting_kl) +
           rtb_Weighting_bx) + rtb_Weighting_lv) + rtb_Weighting_m2) +
        rtb_Weighting_f) + minV > 0.0) >= 1) {
    /* Product: '<S37>/Product (COA)' incorporates:
     *  Constant: '<S37>/x data'
     *  MinMax: '<S35>/AggMethod1'
     */
    for (i = 0; i < 101; i++) {
      rtb_ProductCOA[i] *= Controller_ABS_VLC_AYC_ConstP.xdata_Value[i];
    }

    /* End of Product: '<S37>/Product (COA)' */

    /* Sum: '<S37>/Sum' */
    rtb_Sum = rtb_ProductCOA[0];
    for (i = 0; i < 100; i++) {
      rtb_Sum += rtb_ProductCOA[i + 1];
    }

    /* End of Sum: '<S37>/Sum' */
    Controller_ABS_VLC_AYC_B.Switch = rtb_Sum /
      Controller_ABS_VLC_AYC_B.Merge_g2;
  } else {
    Controller_ABS_VLC_AYC_B.Switch = 0.0;
  }

  /* End of Switch: '<S35>/Switch' */

  /* Gain: '<S6>/Available Torque [Nm]' */
  rtb_Sum = 150.0 * Controller_ABS_VLC_AYC_B.Switch;

  /* Gain: '<S1>/Available Torque [Nm]' incorporates:
   *  Inport: '<Root>/T_P'
   */
  Controller_ABS_VLC_AYC_B.TorquefrompedalNm = 150.0 *
    Controller_ABS_VLC_AYC_U.T_P;

  /* Sum: '<S6>/Sum1' */
  Controller_ABS_VLC_AYC_B.Sum1 = rtb_Sum +
    Controller_ABS_VLC_AYC_B.TorquefrompedalNm;

  /* RelationalOperator: '<S21>/LowerRelop1' */
  rtb_LowerRelop1 = (Controller_ABS_VLC_AYC_B.Sum1 >
                     Controller_ABS_VLC_AYC_B.FLAvailableAccelerationTorqueNm);

  /* S-Function Block: <S15>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_j.FISPointer;
    fis->input[0]->value = Controller_ABS_VLC_AYC_B.Diff;
    fis->input[1]->value = Controller_ABS_VLC_AYC_U.FL_SR;
    fisEvaluate(fis, 101);
    Controller_ABS_VLC_AYC_B.FISSfunction_m = fis->output[0]->value;
  }

  /* S-Function (sdspfilter2): '<S17>/Generated Filter Block' */
  minV = Controller_ABS_VLC_AYC_B.FISSfunction_m * -0.0007564686406292;
  i = 1;
  for (j = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_k; j < 403;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_j[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  for (j = 0; j < Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_k;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_j[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  i = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_k - 1;
  if (i < 0) {
    i = 402;
  }

  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_j[i] =
    Controller_ABS_VLC_AYC_B.FISSfunction_m;
  Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_f = minV;
  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_k = i;

  /* End of S-Function (sdspfilter2): '<S17>/Generated Filter Block' */

  /* UnaryMinus: '<S3>/Unary Minus' incorporates:
   *  Gain: '<S3>/FL Available Braking Torque [Nm]1'
   */
  Controller_ABS_VLC_AYC_B.UnaryMinus = -(150.0 *
    Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_f);

  /* Switch: '<S21>/Switch2' incorporates:
   *  RelationalOperator: '<S21>/UpperRelop'
   *  Switch: '<S21>/Switch'
   */
  if (rtb_LowerRelop1) {
    Controller_ABS_VLC_AYC_B.Switch2 =
      Controller_ABS_VLC_AYC_B.FLAvailableAccelerationTorqueNm;
  } else if (Controller_ABS_VLC_AYC_B.Sum1 < Controller_ABS_VLC_AYC_B.UnaryMinus)
  {
    /* Switch: '<S21>/Switch' */
    Controller_ABS_VLC_AYC_B.Switch2 = Controller_ABS_VLC_AYC_B.UnaryMinus;
  } else {
    Controller_ABS_VLC_AYC_B.Switch2 = Controller_ABS_VLC_AYC_B.Sum1;
  }

  /* End of Switch: '<S21>/Switch2' */

  /* Outport: '<Root>/TFL' */
  Controller_ABS_VLC_AYC_Y.TFL = Controller_ABS_VLC_AYC_B.Switch2;

  /* SampleTimeMath: '<S23>/TSamp' incorporates:
   *  Inport: '<Root>/FR_SR'
   *
   * About '<S23>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Controller_ABS_VLC_AYC_B.TSamp_i = Controller_ABS_VLC_AYC_U.FR_SR * 10000.0;

  /* Sum: '<S23>/Diff' incorporates:
   *  UnitDelay: '<S23>/UD'
   */
  Controller_ABS_VLC_AYC_B.Diff_p = Controller_ABS_VLC_AYC_B.TSamp_i -
    Controller_ABS_VLC_AYC_DWork.UD_DSTATE_c;

  /* S-Function Block: <S24>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_d.FISPointer;
    fis->input[0]->value = Controller_ABS_VLC_AYC_B.Diff_p;
    fis->input[1]->value = Controller_ABS_VLC_AYC_U.FR_SR;
    fisEvaluate(fis, 101);
    Controller_ABS_VLC_AYC_B.FISSfunction_mc = fis->output[0]->value;
  }

  /* S-Function (sdspfilter2): '<S26>/Generated Filter Block' */
  minV = Controller_ABS_VLC_AYC_B.FISSfunction_mc * -0.0007564686406292;
  i = 1;
  for (j = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_j; j < 403;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_i[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  for (j = 0; j < Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_j;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_i[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  i = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_j - 1;
  if (i < 0) {
    i = 402;
  }

  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_i[i] =
    Controller_ABS_VLC_AYC_B.FISSfunction_mc;
  Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_c = minV;
  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_j = i;

  /* End of S-Function (sdspfilter2): '<S26>/Generated Filter Block' */

  /* Gain: '<S5>/FR Available Acceleration Torque [Nm]1' */
  Controller_ABS_VLC_AYC_B.FRAvailableAccelerationTorqueNm = 150.0 *
    Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_c;

  /* Sum: '<S6>/Sum2' */
  Controller_ABS_VLC_AYC_B.Sum2 = Controller_ABS_VLC_AYC_B.TorquefrompedalNm -
    rtb_Sum;

  /* RelationalOperator: '<S31>/LowerRelop1' */
  rtb_LowerRelop1 = (Controller_ABS_VLC_AYC_B.Sum2 >
                     Controller_ABS_VLC_AYC_B.FRAvailableAccelerationTorqueNm);

  /* S-Function Block: <S25>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_g.FISPointer;
    fis->input[0]->value = Controller_ABS_VLC_AYC_B.Diff_p;
    fis->input[1]->value = Controller_ABS_VLC_AYC_U.FR_SR;
    fisEvaluate(fis, 101);
    Controller_ABS_VLC_AYC_B.FISSfunction_o = fis->output[0]->value;
  }

  /* S-Function (sdspfilter2): '<S27>/Generated Filter Block' */
  minV = Controller_ABS_VLC_AYC_B.FISSfunction_o * -0.0007564686406292;
  i = 1;
  for (j = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_l; j < 403;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_k[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  for (j = 0; j < Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_l;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_k[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  i = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_l - 1;
  if (i < 0) {
    i = 402;
  }

  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_k[i] =
    Controller_ABS_VLC_AYC_B.FISSfunction_o;
  Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_h = minV;
  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_l = i;

  /* End of S-Function (sdspfilter2): '<S27>/Generated Filter Block' */

  /* UnaryMinus: '<S5>/Unary Minus' incorporates:
   *  Gain: '<S5>/FR Available Braking Torque [Nm]1'
   */
  Controller_ABS_VLC_AYC_B.UnaryMinus_d = -(150.0 *
    Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_h);

  /* Switch: '<S31>/Switch2' incorporates:
   *  RelationalOperator: '<S31>/UpperRelop'
   *  Switch: '<S31>/Switch'
   */
  if (rtb_LowerRelop1) {
    Controller_ABS_VLC_AYC_B.Switch2_j =
      Controller_ABS_VLC_AYC_B.FRAvailableAccelerationTorqueNm;
  } else if (Controller_ABS_VLC_AYC_B.Sum2 <
             Controller_ABS_VLC_AYC_B.UnaryMinus_d) {
    /* Switch: '<S31>/Switch' */
    Controller_ABS_VLC_AYC_B.Switch2_j = Controller_ABS_VLC_AYC_B.UnaryMinus_d;
  } else {
    Controller_ABS_VLC_AYC_B.Switch2_j = Controller_ABS_VLC_AYC_B.Sum2;
  }

  /* End of Switch: '<S31>/Switch2' */

  /* Outport: '<Root>/TFR' */
  Controller_ABS_VLC_AYC_Y.TFR = Controller_ABS_VLC_AYC_B.Switch2_j;

  /* SampleTimeMath: '<S162>/TSamp' incorporates:
   *  Inport: '<Root>/RL_SR'
   *
   * About '<S162>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Controller_ABS_VLC_AYC_B.TSamp_o = Controller_ABS_VLC_AYC_U.RL_SR * 10000.0;

  /* Sum: '<S162>/Diff' incorporates:
   *  UnitDelay: '<S162>/UD'
   */
  Controller_ABS_VLC_AYC_B.Diff_n = Controller_ABS_VLC_AYC_B.TSamp_o -
    Controller_ABS_VLC_AYC_DWork.UD_DSTATE_o;

  /* S-Function Block: <S163>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_h.FISPointer;
    fis->input[0]->value = Controller_ABS_VLC_AYC_B.Diff_n;
    fis->input[1]->value = Controller_ABS_VLC_AYC_U.RL_SR;
    fisEvaluate(fis, 101);
    Controller_ABS_VLC_AYC_B.FISSfunction_f = fis->output[0]->value;
  }

  /* S-Function (sdspfilter2): '<S165>/Generated Filter Block' */
  minV = Controller_ABS_VLC_AYC_B.FISSfunction_f * -0.0007564686406292;
  i = 1;
  for (j = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUF_jm; j < 403;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_ST_kp[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  for (j = 0; j < Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUF_jm;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_ST_kp[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  i = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUF_jm - 1;
  if (i < 0) {
    i = 402;
  }

  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_ST_kp[i] =
    Controller_ABS_VLC_AYC_B.FISSfunction_f;
  Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_l = minV;
  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUF_jm = i;

  /* End of S-Function (sdspfilter2): '<S165>/Generated Filter Block' */

  /* Gain: '<S8>/Available Acceleration Torque [Nm]1' */
  Controller_ABS_VLC_AYC_B.AvailableAccelerationTorqueNm1 = 150.0 *
    Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_l;

  /* Sum: '<S6>/Sum3' */
  Controller_ABS_VLC_AYC_B.Sum3 = rtb_Sum +
    Controller_ABS_VLC_AYC_B.TorquefrompedalNm;

  /* RelationalOperator: '<S170>/LowerRelop1' */
  rtb_LowerRelop1 = (Controller_ABS_VLC_AYC_B.Sum3 >
                     Controller_ABS_VLC_AYC_B.AvailableAccelerationTorqueNm1);

  /* S-Function Block: <S164>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_e.FISPointer;
    fis->input[0]->value = Controller_ABS_VLC_AYC_B.Diff_n;
    fis->input[1]->value = Controller_ABS_VLC_AYC_U.RL_SR;
    fisEvaluate(fis, 101);
    Controller_ABS_VLC_AYC_B.FISSfunction_p = fis->output[0]->value;
  }

  /* S-Function (sdspfilter2): '<S166>/Generated Filter Block' */
  minV = Controller_ABS_VLC_AYC_B.FISSfunction_p * -0.0007564686406292;
  i = 1;
  for (j = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_g; j < 403;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_h[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  for (j = 0; j < Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_g;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_h[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  i = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_g - 1;
  if (i < 0) {
    i = 402;
  }

  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_h[i] =
    Controller_ABS_VLC_AYC_B.FISSfunction_p;
  Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_j = minV;
  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_g = i;

  /* End of S-Function (sdspfilter2): '<S166>/Generated Filter Block' */

  /* UnaryMinus: '<S8>/Unary Minus' incorporates:
   *  Gain: '<S8>/Available Braking Torque [Nm]1'
   */
  Controller_ABS_VLC_AYC_B.UnaryMinus_f = -(150.0 *
    Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_j);

  /* Switch: '<S170>/Switch2' incorporates:
   *  RelationalOperator: '<S170>/UpperRelop'
   *  Switch: '<S170>/Switch'
   */
  if (rtb_LowerRelop1) {
    Controller_ABS_VLC_AYC_B.Switch2_c =
      Controller_ABS_VLC_AYC_B.AvailableAccelerationTorqueNm1;
  } else if (Controller_ABS_VLC_AYC_B.Sum3 <
             Controller_ABS_VLC_AYC_B.UnaryMinus_f) {
    /* Switch: '<S170>/Switch' */
    Controller_ABS_VLC_AYC_B.Switch2_c = Controller_ABS_VLC_AYC_B.UnaryMinus_f;
  } else {
    Controller_ABS_VLC_AYC_B.Switch2_c = Controller_ABS_VLC_AYC_B.Sum3;
  }

  /* End of Switch: '<S170>/Switch2' */

  /* Outport: '<Root>/TRL' */
  Controller_ABS_VLC_AYC_Y.TRL = Controller_ABS_VLC_AYC_B.Switch2_c;

  /* SampleTimeMath: '<S172>/TSamp' incorporates:
   *  Inport: '<Root>/RR_SR'
   *
   * About '<S172>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Controller_ABS_VLC_AYC_B.TSamp_m = Controller_ABS_VLC_AYC_U.RR_SR * 10000.0;

  /* Sum: '<S172>/Diff' incorporates:
   *  UnitDelay: '<S172>/UD'
   */
  Controller_ABS_VLC_AYC_B.Diff_p5 = Controller_ABS_VLC_AYC_B.TSamp_m -
    Controller_ABS_VLC_AYC_DWork.UD_DSTATE_n;

  /* S-Function Block: <S173>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_g3.FISPointer;
    fis->input[0]->value = Controller_ABS_VLC_AYC_B.Diff_p5;
    fis->input[1]->value = Controller_ABS_VLC_AYC_U.RR_SR;
    fisEvaluate(fis, 101);
    Controller_ABS_VLC_AYC_B.FISSfunction_o5 = fis->output[0]->value;
  }

  /* S-Function (sdspfilter2): '<S175>/Generated Filter Block' */
  minV = Controller_ABS_VLC_AYC_B.FISSfunction_o5 * -0.0007564686406292;
  i = 1;
  for (j = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_m; j < 403;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_g[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  for (j = 0; j < Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_m;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_g[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  i = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_m - 1;
  if (i < 0) {
    i = 402;
  }

  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_g[i] =
    Controller_ABS_VLC_AYC_B.FISSfunction_o5;
  Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_p = minV;
  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_m = i;

  /* End of S-Function (sdspfilter2): '<S175>/Generated Filter Block' */

  /* Gain: '<S10>/Available Acceleration Torque [Nm]1' */
  Controller_ABS_VLC_AYC_B.AvailableAccelerationTorqueNm_m = 150.0 *
    Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_p;

  /* Sum: '<S6>/Sum4' */
  Controller_ABS_VLC_AYC_B.Sum4 = Controller_ABS_VLC_AYC_B.TorquefrompedalNm -
    rtb_Sum;

  /* RelationalOperator: '<S180>/LowerRelop1' */
  rtb_LowerRelop1 = (Controller_ABS_VLC_AYC_B.Sum4 >
                     Controller_ABS_VLC_AYC_B.AvailableAccelerationTorqueNm_m);

  /* S-Function Block: <S174>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_l.FISPointer;
    fis->input[0]->value = Controller_ABS_VLC_AYC_B.Diff_p5;
    fis->input[1]->value = Controller_ABS_VLC_AYC_U.RR_SR;
    fisEvaluate(fis, 101);
    Controller_ABS_VLC_AYC_B.FISSfunction_n = fis->output[0]->value;
  }

  /* S-Function (sdspfilter2): '<S176>/Generated Filter Block' */
  minV = Controller_ABS_VLC_AYC_B.FISSfunction_n * -0.0007564686406292;
  i = 1;
  for (j = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_e; j < 403;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_m[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  for (j = 0; j < Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_e;
       j++) {
    minV += Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_m[j] *
      Controller_ABS_VLC_AYC_ConstP.pooled14[i];
    i++;
  }

  i = Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_e - 1;
  if (i < 0) {
    i = 402;
  }

  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_m[i] =
    Controller_ABS_VLC_AYC_B.FISSfunction_n;
  Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_ch = minV;
  Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_e = i;

  /* End of S-Function (sdspfilter2): '<S176>/Generated Filter Block' */

  /* UnaryMinus: '<S10>/Unary Minus' incorporates:
   *  Gain: '<S10>/Available Braking Torque [Nm]1'
   */
  Controller_ABS_VLC_AYC_B.UnaryMinus_i = -(150.0 *
    Controller_ABS_VLC_AYC_B.GeneratedFilterBlock_ch);

  /* Switch: '<S180>/Switch2' incorporates:
   *  RelationalOperator: '<S180>/UpperRelop'
   *  Switch: '<S180>/Switch'
   */
  if (rtb_LowerRelop1) {
    Controller_ABS_VLC_AYC_B.Switch2_h =
      Controller_ABS_VLC_AYC_B.AvailableAccelerationTorqueNm_m;
  } else if (Controller_ABS_VLC_AYC_B.Sum4 <
             Controller_ABS_VLC_AYC_B.UnaryMinus_i) {
    /* Switch: '<S180>/Switch' */
    Controller_ABS_VLC_AYC_B.Switch2_h = Controller_ABS_VLC_AYC_B.UnaryMinus_i;
  } else {
    Controller_ABS_VLC_AYC_B.Switch2_h = Controller_ABS_VLC_AYC_B.Sum4;
  }

  /* End of Switch: '<S180>/Switch2' */

  /* Outport: '<Root>/TRR' */
  Controller_ABS_VLC_AYC_Y.TRR = Controller_ABS_VLC_AYC_B.Switch2_h;
  if (Controller_ABS_VLC_AYC_M->Timing.TaskCounters.TID[2] == 0) {
    /* SignalConversion: '<S12>/TmpSignal ConversionAtAnimation1Inport1' */
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimation1[0] = 0.0;
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimation1[1] = 0.0;

    /* SignalConversion: '<S18>/TmpSignal ConversionAtAnimation1Inport1' */
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimatio_c[0] = 0.0;
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimatio_c[1] = 0.0;
  }

  if (Controller_ABS_VLC_AYC_M->Timing.TaskCounters.TID[2] == 0) {
    /* SignalConversion: '<S22>/TmpSignal ConversionAtAnimation1Inport1' */
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimatio_h[0] = 0.0;
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimatio_h[1] = 0.0;

    /* SignalConversion: '<S28>/TmpSignal ConversionAtAnimation1Inport1' */
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimati_he[0] = 0.0;
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimati_he[1] = 0.0;
  }

  if (Controller_ABS_VLC_AYC_M->Timing.TaskCounters.TID[2] == 0) {
    /* ZeroOrderHold: '<S32>/Zero-Order Hold' */
    Controller_ABS_VLC_AYC_B.ZeroOrderHold[0] =
      Controller_ABS_VLC_AYC_B.Yawerror;
    Controller_ABS_VLC_AYC_B.ZeroOrderHold[1] =
      Controller_ABS_VLC_AYC_B.Derivative;
  }

  if (Controller_ABS_VLC_AYC_M->Timing.TaskCounters.TID[2] == 0) {
    /* SignalConversion: '<S161>/TmpSignal ConversionAtAnimation1Inport1' */
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimatio_f[0] = 0.0;
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimatio_f[1] = 0.0;

    /* SignalConversion: '<S167>/TmpSignal ConversionAtAnimation1Inport1' */
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimatio_o[0] = 0.0;
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimatio_o[1] = 0.0;
  }

  if (Controller_ABS_VLC_AYC_M->Timing.TaskCounters.TID[2] == 0) {
    /* SignalConversion: '<S171>/TmpSignal ConversionAtAnimation1Inport1' */
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimatio_l[0] = 0.0;
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimatio_l[1] = 0.0;

    /* SignalConversion: '<S177>/TmpSignal ConversionAtAnimation1Inport1' */
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimatio_i[0] = 0.0;
    Controller_ABS_VLC_AYC_B.TmpSignalConversionAtAnimatio_i[1] = 0.0;
  }
}

/* Model update function */
static void Controller_ABS_VLC_AYC_update(void)
{
  /* Update for UnitDelay: '<S13>/UD' */
  Controller_ABS_VLC_AYC_DWork.UD_DSTATE = Controller_ABS_VLC_AYC_B.TSamp;

  /* Update for Derivative: '<S6>/Derivative' */
  {
    real_T timeStampA = Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.TimeStampB;
    real_T* lastTime = &Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.TimeStampA;
    real_T* lastU = &Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.TimeStampB;
        lastU = &Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.TimeStampB;
        lastU = &Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = Controller_ABS_VLC_AYC_M->Timing.t[0];
    *lastU++ = Controller_ABS_VLC_AYC_B.Yawerror;
  }

  /* Update for UnitDelay: '<S23>/UD' */
  Controller_ABS_VLC_AYC_DWork.UD_DSTATE_c = Controller_ABS_VLC_AYC_B.TSamp_i;

  /* Update for UnitDelay: '<S162>/UD' */
  Controller_ABS_VLC_AYC_DWork.UD_DSTATE_o = Controller_ABS_VLC_AYC_B.TSamp_o;

  /* Update for UnitDelay: '<S172>/UD' */
  Controller_ABS_VLC_AYC_DWork.UD_DSTATE_n = Controller_ABS_VLC_AYC_B.TSamp_m;
  if (Controller_ABS_VLC_AYC_M->Timing.TaskCounters.TID[2] == 0) {
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Controller_ABS_VLC_AYC_M->Timing.clockTick0)) {
    ++Controller_ABS_VLC_AYC_M->Timing.clockTickH0;
  }

  Controller_ABS_VLC_AYC_M->Timing.t[0] =
    Controller_ABS_VLC_AYC_M->Timing.clockTick0 *
    Controller_ABS_VLC_AYC_M->Timing.stepSize0 +
    Controller_ABS_VLC_AYC_M->Timing.clockTickH0 *
    Controller_ABS_VLC_AYC_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Controller_ABS_VLC_AYC_M->Timing.clockTick1)) {
      ++Controller_ABS_VLC_AYC_M->Timing.clockTickH1;
    }

    Controller_ABS_VLC_AYC_M->Timing.t[1] =
      Controller_ABS_VLC_AYC_M->Timing.clockTick1 *
      Controller_ABS_VLC_AYC_M->Timing.stepSize1 +
      Controller_ABS_VLC_AYC_M->Timing.clockTickH1 *
      Controller_ABS_VLC_AYC_M->Timing.stepSize1 * 4294967296.0;
  }

  if (Controller_ABS_VLC_AYC_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Controller_ABS_VLC_AYC_M->Timing.clockTick2)) {
      ++Controller_ABS_VLC_AYC_M->Timing.clockTickH2;
    }

    Controller_ABS_VLC_AYC_M->Timing.t[2] =
      Controller_ABS_VLC_AYC_M->Timing.clockTick2 *
      Controller_ABS_VLC_AYC_M->Timing.stepSize2 +
      Controller_ABS_VLC_AYC_M->Timing.clockTickH2 *
      Controller_ABS_VLC_AYC_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void Controller_ABS_VLC_AYC_initialize(void)
{
  /* S-Function Block: <S14>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_VLC_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"|SR|");
      fis->input[1]->bound[0] = 0.0;
      fis->input[1]->bound[1] = 0.25;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vl");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = 0.025;
      fis->input[1]->mf[0]->params[3] = 0.05;
      (void) strcpy(fis->input[1]->mf[1]->label, "l");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = 0.025;
      fis->input[1]->mf[1]->params[1] = 0.05;
      fis->input[1]->mf[1]->params[2] = 0.1;
      (void) strcpy(fis->input[1]->mf[2]->label, "m");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = 0.05;
      fis->input[1]->mf[2]->params[1] = 0.1;
      fis->input[1]->mf[2]->params[2] = 0.15;
      (void) strcpy(fis->input[1]->mf[3]->label, "h");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = 0.1;
      fis->input[1]->mf[3]->params[1] = 0.15;
      fis->input[1]->mf[3]->params[2] = 0.2;
      (void) strcpy(fis->input[1]->mf[4]->label, "vh");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = 0.15;
      fis->input[1]->mf[4]->params[1] = 0.2;
      fis->input[1]->mf[4]->params[2] = 0.225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = 0.2;
      fis->input[1]->mf[5]->params[1] = 0.225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 7;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 4;
      fis->rule_list[1][1] = 2;
      fis->rule_list[1][2] = 5;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 4;
      fis->rule_list[2][1] = 3;
      fis->rule_list[2][2] = 3;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 4;
      fis->rule_list[3][1] = 4;
      fis->rule_list[3][2] = 2;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 4;
      fis->rule_list[4][1] = 5;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 6;
      fis->rule_list[5][2] = 1;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 1;
      fis->rule_list[6][2] = 8;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 2;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 6;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 2;
      fis->rule_list[8][1] = 3;
      fis->rule_list[8][2] = 4;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 2;
      fis->rule_list[9][1] = 4;
      fis->rule_list[9][2] = 3;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 2;
      fis->rule_list[10][1] = 5;
      fis->rule_list[10][2] = 2;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 6;
      fis->rule_list[11][2] = 1;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 1;
      fis->rule_list[12][2] = 9;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 3;
      fis->rule_list[13][1] = 2;
      fis->rule_list[13][2] = 8;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 3;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 5;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 3;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 3;
      fis->rule_list[16][1] = 5;
      fis->rule_list[16][2] = 3;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 6;
      fis->rule_list[17][2] = 1;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 1;
      fis->rule_list[18][2] = 9;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 1;
      fis->rule_list[19][1] = 2;
      fis->rule_list[19][2] = 9;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 1;
      fis->rule_list[20][1] = 3;
      fis->rule_list[20][2] = 6;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 1;
      fis->rule_list[21][1] = 4;
      fis->rule_list[21][2] = 5;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 1;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 4;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 6;
      fis->rule_list[23][2] = 1;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 1;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 5;
      fis->rule_list[25][1] = 2;
      fis->rule_list[25][2] = 9;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 5;
      fis->rule_list[26][1] = 3;
      fis->rule_list[26][2] = 7;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 5;
      fis->rule_list[27][1] = 4;
      fis->rule_list[27][2] = 6;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 5;
      fis->rule_list[28][1] = 5;
      fis->rule_list[28][2] = 5;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 1;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK.FISPointer = fis;
  }

  /* Start for If: '<S89>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S89>/If Action Subsystem2' */
  /* VirtualOutportStart for Outport: '<S98>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge = 0.0;

  /* End of Start for SubSystem: '<S89>/If Action Subsystem2' */

  /* Start for If: '<S126>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_e = -1;

  /* Start for IfAction SubSystem: '<S126>/If Action Subsystem2' */
  /* VirtualOutportStart for Outport: '<S135>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_b = 0.0;

  /* End of Start for SubSystem: '<S126>/If Action Subsystem2' */

  /* Start for If: '<S90>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S90>/If Action Subsystem1' */
  /* VirtualOutportStart for Outport: '<S101>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_k = 1.0;

  /* End of Start for SubSystem: '<S90>/If Action Subsystem1' */

  /* Start for If: '<S91>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_p = -1;

  /* Start for IfAction SubSystem: '<S91>/If Action Subsystem1' */
  /* VirtualOutportStart for Outport: '<S105>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_o = 1.0;

  /* End of Start for SubSystem: '<S91>/If Action Subsystem1' */

  /* Start for If: '<S95>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S95>/If Action Subsystem1' */
  /* VirtualOutportStart for Outport: '<S121>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_f = 1.0;

  /* End of Start for SubSystem: '<S95>/If Action Subsystem1' */

  /* Start for If: '<S94>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_ey = -1;

  /* Start for IfAction SubSystem: '<S94>/If Action Subsystem1' */
  /* VirtualOutportStart for Outport: '<S117>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_kg = 1.0;

  /* End of Start for SubSystem: '<S94>/If Action Subsystem1' */

  /* Start for If: '<S93>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_g = -1;

  /* Start for IfAction SubSystem: '<S93>/If Action Subsystem1' */
  /* VirtualOutportStart for Outport: '<S113>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_fu = 1.0;

  /* End of Start for SubSystem: '<S93>/If Action Subsystem1' */

  /* Start for If: '<S92>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_go = -1;

  /* Start for IfAction SubSystem: '<S92>/If Action Subsystem2' */
  /* VirtualOutportStart for Outport: '<S110>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_oo = 0.0;

  /* End of Start for SubSystem: '<S92>/If Action Subsystem2' */

  /* Start for If: '<S127>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_c = -1;

  /* Start for IfAction SubSystem: '<S127>/If Action Subsystem1' */
  /* VirtualOutportStart for Outport: '<S138>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_l = 1.0;

  /* End of Start for SubSystem: '<S127>/If Action Subsystem1' */

  /* Start for If: '<S128>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S128>/If Action Subsystem1' */
  /* VirtualOutportStart for Outport: '<S142>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_g = 1.0;

  /* End of Start for SubSystem: '<S128>/If Action Subsystem1' */

  /* Start for If: '<S132>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_j = -1;

  /* Start for IfAction SubSystem: '<S132>/If Action Subsystem1' */
  /* VirtualOutportStart for Outport: '<S158>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_e = 1.0;

  /* End of Start for SubSystem: '<S132>/If Action Subsystem1' */

  /* Start for If: '<S131>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_j3 = -1;

  /* Start for IfAction SubSystem: '<S131>/If Action Subsystem1' */
  /* VirtualOutportStart for Outport: '<S154>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_oh = 1.0;

  /* End of Start for SubSystem: '<S131>/If Action Subsystem1' */

  /* Start for If: '<S130>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_h = -1;

  /* Start for IfAction SubSystem: '<S130>/If Action Subsystem1' */
  /* VirtualOutportStart for Outport: '<S150>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_a = 1.0;

  /* End of Start for SubSystem: '<S130>/If Action Subsystem1' */

  /* Start for If: '<S129>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_n = -1;

  /* Start for IfAction SubSystem: '<S129>/If Action Subsystem2' */
  /* VirtualOutportStart for Outport: '<S147>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_c = 0.0;

  /* End of Start for SubSystem: '<S129>/If Action Subsystem2' */

  /* Start for If: '<S37>/If' */
  Controller_ABS_VLC_AYC_DWork.If_ActiveSubsystem_il = -1;

  /* Start for IfAction SubSystem: '<S37>/Action: One' */
  /* VirtualOutportStart for Outport: '<S124>/Out1' */
  Controller_ABS_VLC_AYC_B.Merge_g2 = 0.0;

  /* End of Start for SubSystem: '<S37>/Action: One' */

  /* S-Function Block: <S15>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_ABS_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"SR");
      fis->input[1]->bound[0] = -0.25;
      fis->input[1]->bound[1] = 0.0;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = -0.225;
      fis->input[1]->mf[0]->params[3] = -0.2;
      (void) strcpy(fis->input[1]->mf[1]->label, "vh");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = -0.225;
      fis->input[1]->mf[1]->params[1] = -0.2;
      fis->input[1]->mf[1]->params[2] = -0.15;
      (void) strcpy(fis->input[1]->mf[2]->label, "h");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = -0.2;
      fis->input[1]->mf[2]->params[1] = -0.15;
      fis->input[1]->mf[2]->params[2] = -0.1;
      (void) strcpy(fis->input[1]->mf[3]->label, "m");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = -0.15;
      fis->input[1]->mf[3]->params[1] = -0.1;
      fis->input[1]->mf[3]->params[2] = -0.05;
      (void) strcpy(fis->input[1]->mf[4]->label, "l");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = -0.1;
      fis->input[1]->mf[4]->params[1] = -0.05;
      fis->input[1]->mf[4]->params[2] = -0.0225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vl");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = -0.05;
      fis->input[1]->mf[5]->params[1] = -0.0225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 1;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 2;
      fis->rule_list[1][1] = 1;
      fis->rule_list[1][2] = 1;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 3;
      fis->rule_list[2][1] = 1;
      fis->rule_list[2][2] = 1;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 1;
      fis->rule_list[3][1] = 1;
      fis->rule_list[3][2] = 1;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 5;
      fis->rule_list[4][1] = 1;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 2;
      fis->rule_list[5][2] = 2;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 2;
      fis->rule_list[6][2] = 3;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 3;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 4;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 1;
      fis->rule_list[8][1] = 2;
      fis->rule_list[8][2] = 5;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 5;
      fis->rule_list[9][1] = 2;
      fis->rule_list[9][2] = 6;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 4;
      fis->rule_list[10][1] = 3;
      fis->rule_list[10][2] = 3;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 3;
      fis->rule_list[11][2] = 4;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 3;
      fis->rule_list[12][2] = 5;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 1;
      fis->rule_list[13][1] = 3;
      fis->rule_list[13][2] = 6;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 5;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 7;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 4;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 2;
      fis->rule_list[16][1] = 4;
      fis->rule_list[16][2] = 5;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 4;
      fis->rule_list[17][2] = 6;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 4;
      fis->rule_list[18][2] = 7;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 5;
      fis->rule_list[19][1] = 4;
      fis->rule_list[19][2] = 8;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 4;
      fis->rule_list[20][1] = 5;
      fis->rule_list[20][2] = 5;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 2;
      fis->rule_list[21][1] = 5;
      fis->rule_list[21][2] = 6;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 3;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 7;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 5;
      fis->rule_list[23][2] = 8;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 5;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 4;
      fis->rule_list[25][1] = 6;
      fis->rule_list[25][2] = 7;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 2;
      fis->rule_list[26][1] = 6;
      fis->rule_list[26][2] = 8;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 3;
      fis->rule_list[27][1] = 6;
      fis->rule_list[27][2] = 9;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 1;
      fis->rule_list[28][1] = 6;
      fis->rule_list[28][2] = 9;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 9;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_j.FISPointer = fis;
  }

  /* S-Function Block: <S24>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_VLC_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"|SR|");
      fis->input[1]->bound[0] = 0.0;
      fis->input[1]->bound[1] = 0.25;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vl");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = 0.025;
      fis->input[1]->mf[0]->params[3] = 0.05;
      (void) strcpy(fis->input[1]->mf[1]->label, "l");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = 0.025;
      fis->input[1]->mf[1]->params[1] = 0.05;
      fis->input[1]->mf[1]->params[2] = 0.1;
      (void) strcpy(fis->input[1]->mf[2]->label, "m");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = 0.05;
      fis->input[1]->mf[2]->params[1] = 0.1;
      fis->input[1]->mf[2]->params[2] = 0.15;
      (void) strcpy(fis->input[1]->mf[3]->label, "h");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = 0.1;
      fis->input[1]->mf[3]->params[1] = 0.15;
      fis->input[1]->mf[3]->params[2] = 0.2;
      (void) strcpy(fis->input[1]->mf[4]->label, "vh");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = 0.15;
      fis->input[1]->mf[4]->params[1] = 0.2;
      fis->input[1]->mf[4]->params[2] = 0.225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = 0.2;
      fis->input[1]->mf[5]->params[1] = 0.225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 7;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 4;
      fis->rule_list[1][1] = 2;
      fis->rule_list[1][2] = 5;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 4;
      fis->rule_list[2][1] = 3;
      fis->rule_list[2][2] = 3;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 4;
      fis->rule_list[3][1] = 4;
      fis->rule_list[3][2] = 2;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 4;
      fis->rule_list[4][1] = 5;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 6;
      fis->rule_list[5][2] = 1;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 1;
      fis->rule_list[6][2] = 8;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 2;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 6;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 2;
      fis->rule_list[8][1] = 3;
      fis->rule_list[8][2] = 4;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 2;
      fis->rule_list[9][1] = 4;
      fis->rule_list[9][2] = 3;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 2;
      fis->rule_list[10][1] = 5;
      fis->rule_list[10][2] = 2;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 6;
      fis->rule_list[11][2] = 1;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 1;
      fis->rule_list[12][2] = 9;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 3;
      fis->rule_list[13][1] = 2;
      fis->rule_list[13][2] = 8;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 3;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 5;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 3;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 3;
      fis->rule_list[16][1] = 5;
      fis->rule_list[16][2] = 3;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 6;
      fis->rule_list[17][2] = 1;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 1;
      fis->rule_list[18][2] = 9;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 1;
      fis->rule_list[19][1] = 2;
      fis->rule_list[19][2] = 9;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 1;
      fis->rule_list[20][1] = 3;
      fis->rule_list[20][2] = 6;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 1;
      fis->rule_list[21][1] = 4;
      fis->rule_list[21][2] = 5;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 1;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 4;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 6;
      fis->rule_list[23][2] = 1;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 1;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 5;
      fis->rule_list[25][1] = 2;
      fis->rule_list[25][2] = 9;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 5;
      fis->rule_list[26][1] = 3;
      fis->rule_list[26][2] = 7;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 5;
      fis->rule_list[27][1] = 4;
      fis->rule_list[27][2] = 6;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 5;
      fis->rule_list[28][1] = 5;
      fis->rule_list[28][2] = 5;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 1;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_d.FISPointer = fis;
  }

  /* S-Function Block: <S25>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_ABS_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"SR");
      fis->input[1]->bound[0] = -0.25;
      fis->input[1]->bound[1] = 0.0;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = -0.225;
      fis->input[1]->mf[0]->params[3] = -0.2;
      (void) strcpy(fis->input[1]->mf[1]->label, "vh");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = -0.225;
      fis->input[1]->mf[1]->params[1] = -0.2;
      fis->input[1]->mf[1]->params[2] = -0.15;
      (void) strcpy(fis->input[1]->mf[2]->label, "h");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = -0.2;
      fis->input[1]->mf[2]->params[1] = -0.15;
      fis->input[1]->mf[2]->params[2] = -0.1;
      (void) strcpy(fis->input[1]->mf[3]->label, "m");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = -0.15;
      fis->input[1]->mf[3]->params[1] = -0.1;
      fis->input[1]->mf[3]->params[2] = -0.05;
      (void) strcpy(fis->input[1]->mf[4]->label, "l");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = -0.1;
      fis->input[1]->mf[4]->params[1] = -0.05;
      fis->input[1]->mf[4]->params[2] = -0.0225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vl");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = -0.05;
      fis->input[1]->mf[5]->params[1] = -0.0225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 1;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 2;
      fis->rule_list[1][1] = 1;
      fis->rule_list[1][2] = 1;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 3;
      fis->rule_list[2][1] = 1;
      fis->rule_list[2][2] = 1;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 1;
      fis->rule_list[3][1] = 1;
      fis->rule_list[3][2] = 1;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 5;
      fis->rule_list[4][1] = 1;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 2;
      fis->rule_list[5][2] = 2;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 2;
      fis->rule_list[6][2] = 3;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 3;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 4;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 1;
      fis->rule_list[8][1] = 2;
      fis->rule_list[8][2] = 5;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 5;
      fis->rule_list[9][1] = 2;
      fis->rule_list[9][2] = 6;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 4;
      fis->rule_list[10][1] = 3;
      fis->rule_list[10][2] = 3;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 3;
      fis->rule_list[11][2] = 4;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 3;
      fis->rule_list[12][2] = 5;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 1;
      fis->rule_list[13][1] = 3;
      fis->rule_list[13][2] = 6;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 5;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 7;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 4;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 2;
      fis->rule_list[16][1] = 4;
      fis->rule_list[16][2] = 5;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 4;
      fis->rule_list[17][2] = 6;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 4;
      fis->rule_list[18][2] = 7;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 5;
      fis->rule_list[19][1] = 4;
      fis->rule_list[19][2] = 8;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 4;
      fis->rule_list[20][1] = 5;
      fis->rule_list[20][2] = 5;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 2;
      fis->rule_list[21][1] = 5;
      fis->rule_list[21][2] = 6;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 3;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 7;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 5;
      fis->rule_list[23][2] = 8;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 5;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 4;
      fis->rule_list[25][1] = 6;
      fis->rule_list[25][2] = 7;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 2;
      fis->rule_list[26][1] = 6;
      fis->rule_list[26][2] = 8;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 3;
      fis->rule_list[27][1] = 6;
      fis->rule_list[27][2] = 9;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 1;
      fis->rule_list[28][1] = 6;
      fis->rule_list[28][2] = 9;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 9;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_g.FISPointer = fis;
  }

  /* S-Function Block: <S163>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_VLC_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"|SR|");
      fis->input[1]->bound[0] = 0.0;
      fis->input[1]->bound[1] = 0.25;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vl");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = 0.025;
      fis->input[1]->mf[0]->params[3] = 0.05;
      (void) strcpy(fis->input[1]->mf[1]->label, "l");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = 0.025;
      fis->input[1]->mf[1]->params[1] = 0.05;
      fis->input[1]->mf[1]->params[2] = 0.1;
      (void) strcpy(fis->input[1]->mf[2]->label, "m");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = 0.05;
      fis->input[1]->mf[2]->params[1] = 0.1;
      fis->input[1]->mf[2]->params[2] = 0.15;
      (void) strcpy(fis->input[1]->mf[3]->label, "h");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = 0.1;
      fis->input[1]->mf[3]->params[1] = 0.15;
      fis->input[1]->mf[3]->params[2] = 0.2;
      (void) strcpy(fis->input[1]->mf[4]->label, "vh");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = 0.15;
      fis->input[1]->mf[4]->params[1] = 0.2;
      fis->input[1]->mf[4]->params[2] = 0.225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = 0.2;
      fis->input[1]->mf[5]->params[1] = 0.225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 7;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 4;
      fis->rule_list[1][1] = 2;
      fis->rule_list[1][2] = 5;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 4;
      fis->rule_list[2][1] = 3;
      fis->rule_list[2][2] = 3;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 4;
      fis->rule_list[3][1] = 4;
      fis->rule_list[3][2] = 2;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 4;
      fis->rule_list[4][1] = 5;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 6;
      fis->rule_list[5][2] = 1;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 1;
      fis->rule_list[6][2] = 8;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 2;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 6;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 2;
      fis->rule_list[8][1] = 3;
      fis->rule_list[8][2] = 4;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 2;
      fis->rule_list[9][1] = 4;
      fis->rule_list[9][2] = 3;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 2;
      fis->rule_list[10][1] = 5;
      fis->rule_list[10][2] = 2;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 6;
      fis->rule_list[11][2] = 1;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 1;
      fis->rule_list[12][2] = 9;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 3;
      fis->rule_list[13][1] = 2;
      fis->rule_list[13][2] = 8;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 3;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 5;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 3;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 3;
      fis->rule_list[16][1] = 5;
      fis->rule_list[16][2] = 3;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 6;
      fis->rule_list[17][2] = 1;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 1;
      fis->rule_list[18][2] = 9;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 1;
      fis->rule_list[19][1] = 2;
      fis->rule_list[19][2] = 9;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 1;
      fis->rule_list[20][1] = 3;
      fis->rule_list[20][2] = 6;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 1;
      fis->rule_list[21][1] = 4;
      fis->rule_list[21][2] = 5;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 1;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 4;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 6;
      fis->rule_list[23][2] = 1;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 1;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 5;
      fis->rule_list[25][1] = 2;
      fis->rule_list[25][2] = 9;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 5;
      fis->rule_list[26][1] = 3;
      fis->rule_list[26][2] = 7;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 5;
      fis->rule_list[27][1] = 4;
      fis->rule_list[27][2] = 6;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 5;
      fis->rule_list[28][1] = 5;
      fis->rule_list[28][2] = 5;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 1;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_h.FISPointer = fis;
  }

  /* S-Function Block: <S164>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_ABS_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"SR");
      fis->input[1]->bound[0] = -0.25;
      fis->input[1]->bound[1] = 0.0;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = -0.225;
      fis->input[1]->mf[0]->params[3] = -0.2;
      (void) strcpy(fis->input[1]->mf[1]->label, "vh");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = -0.225;
      fis->input[1]->mf[1]->params[1] = -0.2;
      fis->input[1]->mf[1]->params[2] = -0.15;
      (void) strcpy(fis->input[1]->mf[2]->label, "h");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = -0.2;
      fis->input[1]->mf[2]->params[1] = -0.15;
      fis->input[1]->mf[2]->params[2] = -0.1;
      (void) strcpy(fis->input[1]->mf[3]->label, "m");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = -0.15;
      fis->input[1]->mf[3]->params[1] = -0.1;
      fis->input[1]->mf[3]->params[2] = -0.05;
      (void) strcpy(fis->input[1]->mf[4]->label, "l");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = -0.1;
      fis->input[1]->mf[4]->params[1] = -0.05;
      fis->input[1]->mf[4]->params[2] = -0.0225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vl");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = -0.05;
      fis->input[1]->mf[5]->params[1] = -0.0225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 1;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 2;
      fis->rule_list[1][1] = 1;
      fis->rule_list[1][2] = 1;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 3;
      fis->rule_list[2][1] = 1;
      fis->rule_list[2][2] = 1;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 1;
      fis->rule_list[3][1] = 1;
      fis->rule_list[3][2] = 1;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 5;
      fis->rule_list[4][1] = 1;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 2;
      fis->rule_list[5][2] = 2;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 2;
      fis->rule_list[6][2] = 3;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 3;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 4;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 1;
      fis->rule_list[8][1] = 2;
      fis->rule_list[8][2] = 5;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 5;
      fis->rule_list[9][1] = 2;
      fis->rule_list[9][2] = 6;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 4;
      fis->rule_list[10][1] = 3;
      fis->rule_list[10][2] = 3;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 3;
      fis->rule_list[11][2] = 4;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 3;
      fis->rule_list[12][2] = 5;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 1;
      fis->rule_list[13][1] = 3;
      fis->rule_list[13][2] = 6;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 5;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 7;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 4;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 2;
      fis->rule_list[16][1] = 4;
      fis->rule_list[16][2] = 5;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 4;
      fis->rule_list[17][2] = 6;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 4;
      fis->rule_list[18][2] = 7;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 5;
      fis->rule_list[19][1] = 4;
      fis->rule_list[19][2] = 8;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 4;
      fis->rule_list[20][1] = 5;
      fis->rule_list[20][2] = 5;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 2;
      fis->rule_list[21][1] = 5;
      fis->rule_list[21][2] = 6;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 3;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 7;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 5;
      fis->rule_list[23][2] = 8;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 5;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 4;
      fis->rule_list[25][1] = 6;
      fis->rule_list[25][2] = 7;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 2;
      fis->rule_list[26][1] = 6;
      fis->rule_list[26][2] = 8;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 3;
      fis->rule_list[27][1] = 6;
      fis->rule_list[27][2] = 9;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 1;
      fis->rule_list[28][1] = 6;
      fis->rule_list[28][2] = 9;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 9;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_e.FISPointer = fis;
  }

  /* S-Function Block: <S173>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_VLC_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"|SR|");
      fis->input[1]->bound[0] = 0.0;
      fis->input[1]->bound[1] = 0.25;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vl");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = 0.025;
      fis->input[1]->mf[0]->params[3] = 0.05;
      (void) strcpy(fis->input[1]->mf[1]->label, "l");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = 0.025;
      fis->input[1]->mf[1]->params[1] = 0.05;
      fis->input[1]->mf[1]->params[2] = 0.1;
      (void) strcpy(fis->input[1]->mf[2]->label, "m");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = 0.05;
      fis->input[1]->mf[2]->params[1] = 0.1;
      fis->input[1]->mf[2]->params[2] = 0.15;
      (void) strcpy(fis->input[1]->mf[3]->label, "h");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = 0.1;
      fis->input[1]->mf[3]->params[1] = 0.15;
      fis->input[1]->mf[3]->params[2] = 0.2;
      (void) strcpy(fis->input[1]->mf[4]->label, "vh");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = 0.15;
      fis->input[1]->mf[4]->params[1] = 0.2;
      fis->input[1]->mf[4]->params[2] = 0.225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = 0.2;
      fis->input[1]->mf[5]->params[1] = 0.225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 7;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 4;
      fis->rule_list[1][1] = 2;
      fis->rule_list[1][2] = 5;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 4;
      fis->rule_list[2][1] = 3;
      fis->rule_list[2][2] = 3;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 4;
      fis->rule_list[3][1] = 4;
      fis->rule_list[3][2] = 2;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 4;
      fis->rule_list[4][1] = 5;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 6;
      fis->rule_list[5][2] = 1;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 1;
      fis->rule_list[6][2] = 8;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 2;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 6;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 2;
      fis->rule_list[8][1] = 3;
      fis->rule_list[8][2] = 4;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 2;
      fis->rule_list[9][1] = 4;
      fis->rule_list[9][2] = 3;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 2;
      fis->rule_list[10][1] = 5;
      fis->rule_list[10][2] = 2;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 6;
      fis->rule_list[11][2] = 1;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 1;
      fis->rule_list[12][2] = 9;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 3;
      fis->rule_list[13][1] = 2;
      fis->rule_list[13][2] = 8;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 3;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 5;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 3;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 3;
      fis->rule_list[16][1] = 5;
      fis->rule_list[16][2] = 3;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 6;
      fis->rule_list[17][2] = 1;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 1;
      fis->rule_list[18][2] = 9;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 1;
      fis->rule_list[19][1] = 2;
      fis->rule_list[19][2] = 9;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 1;
      fis->rule_list[20][1] = 3;
      fis->rule_list[20][2] = 6;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 1;
      fis->rule_list[21][1] = 4;
      fis->rule_list[21][2] = 5;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 1;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 4;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 6;
      fis->rule_list[23][2] = 1;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 1;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 5;
      fis->rule_list[25][1] = 2;
      fis->rule_list[25][2] = 9;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 5;
      fis->rule_list[26][1] = 3;
      fis->rule_list[26][2] = 7;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 5;
      fis->rule_list[27][1] = 4;
      fis->rule_list[27][2] = 6;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 5;
      fis->rule_list[28][1] = 5;
      fis->rule_list[28][2] = 5;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 1;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_g3.FISPointer = fis;
  }

  /* S-Function Block: <S174>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_ABS_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"SR");
      fis->input[1]->bound[0] = -0.25;
      fis->input[1]->bound[1] = 0.0;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = -0.225;
      fis->input[1]->mf[0]->params[3] = -0.2;
      (void) strcpy(fis->input[1]->mf[1]->label, "vh");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = -0.225;
      fis->input[1]->mf[1]->params[1] = -0.2;
      fis->input[1]->mf[1]->params[2] = -0.15;
      (void) strcpy(fis->input[1]->mf[2]->label, "h");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = -0.2;
      fis->input[1]->mf[2]->params[1] = -0.15;
      fis->input[1]->mf[2]->params[2] = -0.1;
      (void) strcpy(fis->input[1]->mf[3]->label, "m");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = -0.15;
      fis->input[1]->mf[3]->params[1] = -0.1;
      fis->input[1]->mf[3]->params[2] = -0.05;
      (void) strcpy(fis->input[1]->mf[4]->label, "l");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = -0.1;
      fis->input[1]->mf[4]->params[1] = -0.05;
      fis->input[1]->mf[4]->params[2] = -0.0225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vl");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = -0.05;
      fis->input[1]->mf[5]->params[1] = -0.0225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 1;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 2;
      fis->rule_list[1][1] = 1;
      fis->rule_list[1][2] = 1;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 3;
      fis->rule_list[2][1] = 1;
      fis->rule_list[2][2] = 1;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 1;
      fis->rule_list[3][1] = 1;
      fis->rule_list[3][2] = 1;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 5;
      fis->rule_list[4][1] = 1;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 2;
      fis->rule_list[5][2] = 2;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 2;
      fis->rule_list[6][2] = 3;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 3;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 4;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 1;
      fis->rule_list[8][1] = 2;
      fis->rule_list[8][2] = 5;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 5;
      fis->rule_list[9][1] = 2;
      fis->rule_list[9][2] = 6;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 4;
      fis->rule_list[10][1] = 3;
      fis->rule_list[10][2] = 3;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 3;
      fis->rule_list[11][2] = 4;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 3;
      fis->rule_list[12][2] = 5;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 1;
      fis->rule_list[13][1] = 3;
      fis->rule_list[13][2] = 6;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 5;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 7;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 4;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 2;
      fis->rule_list[16][1] = 4;
      fis->rule_list[16][2] = 5;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 4;
      fis->rule_list[17][2] = 6;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 4;
      fis->rule_list[18][2] = 7;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 5;
      fis->rule_list[19][1] = 4;
      fis->rule_list[19][2] = 8;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 4;
      fis->rule_list[20][1] = 5;
      fis->rule_list[20][2] = 5;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 2;
      fis->rule_list[21][1] = 5;
      fis->rule_list[21][2] = 6;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 3;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 7;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 5;
      fis->rule_list[23][2] = 8;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 5;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 4;
      fis->rule_list[25][1] = 6;
      fis->rule_list[25][2] = 7;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 2;
      fis->rule_list[26][1] = 6;
      fis->rule_list[26][2] = 8;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 3;
      fis->rule_list[27][1] = 6;
      fis->rule_list[27][2] = 9;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 1;
      fis->rule_list[28][1] = 6;
      fis->rule_list[28][2] = 9;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 9;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_l.FISPointer = fis;
  }

  /* S-Function Block: <S19>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_ABS_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"SR");
      fis->input[1]->bound[0] = -0.25;
      fis->input[1]->bound[1] = 0.0;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = -0.225;
      fis->input[1]->mf[0]->params[3] = -0.2;
      (void) strcpy(fis->input[1]->mf[1]->label, "vh");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = -0.225;
      fis->input[1]->mf[1]->params[1] = -0.2;
      fis->input[1]->mf[1]->params[2] = -0.15;
      (void) strcpy(fis->input[1]->mf[2]->label, "h");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = -0.2;
      fis->input[1]->mf[2]->params[1] = -0.15;
      fis->input[1]->mf[2]->params[2] = -0.1;
      (void) strcpy(fis->input[1]->mf[3]->label, "m");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = -0.15;
      fis->input[1]->mf[3]->params[1] = -0.1;
      fis->input[1]->mf[3]->params[2] = -0.05;
      (void) strcpy(fis->input[1]->mf[4]->label, "l");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = -0.1;
      fis->input[1]->mf[4]->params[1] = -0.05;
      fis->input[1]->mf[4]->params[2] = -0.0225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vl");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = -0.05;
      fis->input[1]->mf[5]->params[1] = -0.0225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 1;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 2;
      fis->rule_list[1][1] = 1;
      fis->rule_list[1][2] = 1;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 3;
      fis->rule_list[2][1] = 1;
      fis->rule_list[2][2] = 1;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 1;
      fis->rule_list[3][1] = 1;
      fis->rule_list[3][2] = 1;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 5;
      fis->rule_list[4][1] = 1;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 2;
      fis->rule_list[5][2] = 2;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 2;
      fis->rule_list[6][2] = 3;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 3;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 4;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 1;
      fis->rule_list[8][1] = 2;
      fis->rule_list[8][2] = 5;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 5;
      fis->rule_list[9][1] = 2;
      fis->rule_list[9][2] = 6;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 4;
      fis->rule_list[10][1] = 3;
      fis->rule_list[10][2] = 3;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 3;
      fis->rule_list[11][2] = 4;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 3;
      fis->rule_list[12][2] = 5;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 1;
      fis->rule_list[13][1] = 3;
      fis->rule_list[13][2] = 6;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 5;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 7;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 4;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 2;
      fis->rule_list[16][1] = 4;
      fis->rule_list[16][2] = 5;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 4;
      fis->rule_list[17][2] = 6;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 4;
      fis->rule_list[18][2] = 7;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 5;
      fis->rule_list[19][1] = 4;
      fis->rule_list[19][2] = 8;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 4;
      fis->rule_list[20][1] = 5;
      fis->rule_list[20][2] = 5;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 2;
      fis->rule_list[21][1] = 5;
      fis->rule_list[21][2] = 6;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 3;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 7;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 5;
      fis->rule_list[23][2] = 8;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 5;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 4;
      fis->rule_list[25][1] = 6;
      fis->rule_list[25][2] = 7;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 2;
      fis->rule_list[26][1] = 6;
      fis->rule_list[26][2] = 8;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 3;
      fis->rule_list[27][1] = 6;
      fis->rule_list[27][2] = 9;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 1;
      fis->rule_list[28][1] = 6;
      fis->rule_list[28][2] = 9;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 9;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_b.FISPointer = fis;
  }

  /* S-Function Block: <S20>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_VLC_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"|SR|");
      fis->input[1]->bound[0] = 0.0;
      fis->input[1]->bound[1] = 0.25;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vl");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = 0.025;
      fis->input[1]->mf[0]->params[3] = 0.05;
      (void) strcpy(fis->input[1]->mf[1]->label, "l");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = 0.025;
      fis->input[1]->mf[1]->params[1] = 0.05;
      fis->input[1]->mf[1]->params[2] = 0.1;
      (void) strcpy(fis->input[1]->mf[2]->label, "m");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = 0.05;
      fis->input[1]->mf[2]->params[1] = 0.1;
      fis->input[1]->mf[2]->params[2] = 0.15;
      (void) strcpy(fis->input[1]->mf[3]->label, "h");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = 0.1;
      fis->input[1]->mf[3]->params[1] = 0.15;
      fis->input[1]->mf[3]->params[2] = 0.2;
      (void) strcpy(fis->input[1]->mf[4]->label, "vh");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = 0.15;
      fis->input[1]->mf[4]->params[1] = 0.2;
      fis->input[1]->mf[4]->params[2] = 0.225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = 0.2;
      fis->input[1]->mf[5]->params[1] = 0.225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 7;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 4;
      fis->rule_list[1][1] = 2;
      fis->rule_list[1][2] = 5;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 4;
      fis->rule_list[2][1] = 3;
      fis->rule_list[2][2] = 3;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 4;
      fis->rule_list[3][1] = 4;
      fis->rule_list[3][2] = 2;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 4;
      fis->rule_list[4][1] = 5;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 6;
      fis->rule_list[5][2] = 1;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 1;
      fis->rule_list[6][2] = 8;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 2;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 6;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 2;
      fis->rule_list[8][1] = 3;
      fis->rule_list[8][2] = 4;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 2;
      fis->rule_list[9][1] = 4;
      fis->rule_list[9][2] = 3;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 2;
      fis->rule_list[10][1] = 5;
      fis->rule_list[10][2] = 2;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 6;
      fis->rule_list[11][2] = 1;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 1;
      fis->rule_list[12][2] = 9;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 3;
      fis->rule_list[13][1] = 2;
      fis->rule_list[13][2] = 8;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 3;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 5;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 3;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 3;
      fis->rule_list[16][1] = 5;
      fis->rule_list[16][2] = 3;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 6;
      fis->rule_list[17][2] = 1;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 1;
      fis->rule_list[18][2] = 9;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 1;
      fis->rule_list[19][1] = 2;
      fis->rule_list[19][2] = 9;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 1;
      fis->rule_list[20][1] = 3;
      fis->rule_list[20][2] = 6;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 1;
      fis->rule_list[21][1] = 4;
      fis->rule_list[21][2] = 5;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 1;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 4;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 6;
      fis->rule_list[23][2] = 1;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 1;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 5;
      fis->rule_list[25][1] = 2;
      fis->rule_list[25][2] = 9;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 5;
      fis->rule_list[26][1] = 3;
      fis->rule_list[26][2] = 7;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 5;
      fis->rule_list[27][1] = 4;
      fis->rule_list[27][2] = 6;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 5;
      fis->rule_list[28][1] = 5;
      fis->rule_list[28][2] = 5;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 1;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_lj.FISPointer = fis;
  }

  /* S-Function Block: <S29>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_ABS_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"SR");
      fis->input[1]->bound[0] = -0.25;
      fis->input[1]->bound[1] = 0.0;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = -0.225;
      fis->input[1]->mf[0]->params[3] = -0.2;
      (void) strcpy(fis->input[1]->mf[1]->label, "vh");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = -0.225;
      fis->input[1]->mf[1]->params[1] = -0.2;
      fis->input[1]->mf[1]->params[2] = -0.15;
      (void) strcpy(fis->input[1]->mf[2]->label, "h");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = -0.2;
      fis->input[1]->mf[2]->params[1] = -0.15;
      fis->input[1]->mf[2]->params[2] = -0.1;
      (void) strcpy(fis->input[1]->mf[3]->label, "m");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = -0.15;
      fis->input[1]->mf[3]->params[1] = -0.1;
      fis->input[1]->mf[3]->params[2] = -0.05;
      (void) strcpy(fis->input[1]->mf[4]->label, "l");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = -0.1;
      fis->input[1]->mf[4]->params[1] = -0.05;
      fis->input[1]->mf[4]->params[2] = -0.0225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vl");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = -0.05;
      fis->input[1]->mf[5]->params[1] = -0.0225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 1;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 2;
      fis->rule_list[1][1] = 1;
      fis->rule_list[1][2] = 1;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 3;
      fis->rule_list[2][1] = 1;
      fis->rule_list[2][2] = 1;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 1;
      fis->rule_list[3][1] = 1;
      fis->rule_list[3][2] = 1;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 5;
      fis->rule_list[4][1] = 1;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 2;
      fis->rule_list[5][2] = 2;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 2;
      fis->rule_list[6][2] = 3;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 3;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 4;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 1;
      fis->rule_list[8][1] = 2;
      fis->rule_list[8][2] = 5;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 5;
      fis->rule_list[9][1] = 2;
      fis->rule_list[9][2] = 6;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 4;
      fis->rule_list[10][1] = 3;
      fis->rule_list[10][2] = 3;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 3;
      fis->rule_list[11][2] = 4;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 3;
      fis->rule_list[12][2] = 5;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 1;
      fis->rule_list[13][1] = 3;
      fis->rule_list[13][2] = 6;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 5;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 7;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 4;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 2;
      fis->rule_list[16][1] = 4;
      fis->rule_list[16][2] = 5;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 4;
      fis->rule_list[17][2] = 6;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 4;
      fis->rule_list[18][2] = 7;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 5;
      fis->rule_list[19][1] = 4;
      fis->rule_list[19][2] = 8;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 4;
      fis->rule_list[20][1] = 5;
      fis->rule_list[20][2] = 5;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 2;
      fis->rule_list[21][1] = 5;
      fis->rule_list[21][2] = 6;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 3;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 7;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 5;
      fis->rule_list[23][2] = 8;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 5;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 4;
      fis->rule_list[25][1] = 6;
      fis->rule_list[25][2] = 7;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 2;
      fis->rule_list[26][1] = 6;
      fis->rule_list[26][2] = 8;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 3;
      fis->rule_list[27][1] = 6;
      fis->rule_list[27][2] = 9;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 1;
      fis->rule_list[28][1] = 6;
      fis->rule_list[28][2] = 9;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 9;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_dw.FISPointer = fis;
  }

  /* S-Function Block: <S30>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_VLC_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"|SR|");
      fis->input[1]->bound[0] = 0.0;
      fis->input[1]->bound[1] = 0.25;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vl");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = 0.025;
      fis->input[1]->mf[0]->params[3] = 0.05;
      (void) strcpy(fis->input[1]->mf[1]->label, "l");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = 0.025;
      fis->input[1]->mf[1]->params[1] = 0.05;
      fis->input[1]->mf[1]->params[2] = 0.1;
      (void) strcpy(fis->input[1]->mf[2]->label, "m");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = 0.05;
      fis->input[1]->mf[2]->params[1] = 0.1;
      fis->input[1]->mf[2]->params[2] = 0.15;
      (void) strcpy(fis->input[1]->mf[3]->label, "h");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = 0.1;
      fis->input[1]->mf[3]->params[1] = 0.15;
      fis->input[1]->mf[3]->params[2] = 0.2;
      (void) strcpy(fis->input[1]->mf[4]->label, "vh");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = 0.15;
      fis->input[1]->mf[4]->params[1] = 0.2;
      fis->input[1]->mf[4]->params[2] = 0.225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = 0.2;
      fis->input[1]->mf[5]->params[1] = 0.225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 7;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 4;
      fis->rule_list[1][1] = 2;
      fis->rule_list[1][2] = 5;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 4;
      fis->rule_list[2][1] = 3;
      fis->rule_list[2][2] = 3;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 4;
      fis->rule_list[3][1] = 4;
      fis->rule_list[3][2] = 2;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 4;
      fis->rule_list[4][1] = 5;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 6;
      fis->rule_list[5][2] = 1;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 1;
      fis->rule_list[6][2] = 8;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 2;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 6;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 2;
      fis->rule_list[8][1] = 3;
      fis->rule_list[8][2] = 4;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 2;
      fis->rule_list[9][1] = 4;
      fis->rule_list[9][2] = 3;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 2;
      fis->rule_list[10][1] = 5;
      fis->rule_list[10][2] = 2;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 6;
      fis->rule_list[11][2] = 1;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 1;
      fis->rule_list[12][2] = 9;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 3;
      fis->rule_list[13][1] = 2;
      fis->rule_list[13][2] = 8;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 3;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 5;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 3;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 3;
      fis->rule_list[16][1] = 5;
      fis->rule_list[16][2] = 3;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 6;
      fis->rule_list[17][2] = 1;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 1;
      fis->rule_list[18][2] = 9;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 1;
      fis->rule_list[19][1] = 2;
      fis->rule_list[19][2] = 9;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 1;
      fis->rule_list[20][1] = 3;
      fis->rule_list[20][2] = 6;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 1;
      fis->rule_list[21][1] = 4;
      fis->rule_list[21][2] = 5;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 1;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 4;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 6;
      fis->rule_list[23][2] = 1;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 1;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 5;
      fis->rule_list[25][1] = 2;
      fis->rule_list[25][2] = 9;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 5;
      fis->rule_list[26][1] = 3;
      fis->rule_list[26][2] = 7;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 5;
      fis->rule_list[27][1] = 4;
      fis->rule_list[27][2] = 6;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 5;
      fis->rule_list[28][1] = 5;
      fis->rule_list[28][2] = 5;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 1;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_a.FISPointer = fis;
  }

  /* S-Function Block: <S168>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_ABS_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"SR");
      fis->input[1]->bound[0] = -0.25;
      fis->input[1]->bound[1] = 0.0;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = -0.225;
      fis->input[1]->mf[0]->params[3] = -0.2;
      (void) strcpy(fis->input[1]->mf[1]->label, "vh");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = -0.225;
      fis->input[1]->mf[1]->params[1] = -0.2;
      fis->input[1]->mf[1]->params[2] = -0.15;
      (void) strcpy(fis->input[1]->mf[2]->label, "h");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = -0.2;
      fis->input[1]->mf[2]->params[1] = -0.15;
      fis->input[1]->mf[2]->params[2] = -0.1;
      (void) strcpy(fis->input[1]->mf[3]->label, "m");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = -0.15;
      fis->input[1]->mf[3]->params[1] = -0.1;
      fis->input[1]->mf[3]->params[2] = -0.05;
      (void) strcpy(fis->input[1]->mf[4]->label, "l");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = -0.1;
      fis->input[1]->mf[4]->params[1] = -0.05;
      fis->input[1]->mf[4]->params[2] = -0.0225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vl");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = -0.05;
      fis->input[1]->mf[5]->params[1] = -0.0225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 1;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 2;
      fis->rule_list[1][1] = 1;
      fis->rule_list[1][2] = 1;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 3;
      fis->rule_list[2][1] = 1;
      fis->rule_list[2][2] = 1;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 1;
      fis->rule_list[3][1] = 1;
      fis->rule_list[3][2] = 1;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 5;
      fis->rule_list[4][1] = 1;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 2;
      fis->rule_list[5][2] = 2;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 2;
      fis->rule_list[6][2] = 3;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 3;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 4;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 1;
      fis->rule_list[8][1] = 2;
      fis->rule_list[8][2] = 5;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 5;
      fis->rule_list[9][1] = 2;
      fis->rule_list[9][2] = 6;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 4;
      fis->rule_list[10][1] = 3;
      fis->rule_list[10][2] = 3;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 3;
      fis->rule_list[11][2] = 4;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 3;
      fis->rule_list[12][2] = 5;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 1;
      fis->rule_list[13][1] = 3;
      fis->rule_list[13][2] = 6;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 5;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 7;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 4;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 2;
      fis->rule_list[16][1] = 4;
      fis->rule_list[16][2] = 5;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 4;
      fis->rule_list[17][2] = 6;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 4;
      fis->rule_list[18][2] = 7;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 5;
      fis->rule_list[19][1] = 4;
      fis->rule_list[19][2] = 8;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 4;
      fis->rule_list[20][1] = 5;
      fis->rule_list[20][2] = 5;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 2;
      fis->rule_list[21][1] = 5;
      fis->rule_list[21][2] = 6;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 3;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 7;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 5;
      fis->rule_list[23][2] = 8;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 5;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 4;
      fis->rule_list[25][1] = 6;
      fis->rule_list[25][2] = 7;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 2;
      fis->rule_list[26][1] = 6;
      fis->rule_list[26][2] = 8;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 3;
      fis->rule_list[27][1] = 6;
      fis->rule_list[27][2] = 9;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 1;
      fis->rule_list[28][1] = 6;
      fis->rule_list[28][2] = 9;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 9;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_he.FISPointer = fis;
  }

  /* S-Function Block: <S169>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_VLC_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"|SR|");
      fis->input[1]->bound[0] = 0.0;
      fis->input[1]->bound[1] = 0.25;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vl");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = 0.025;
      fis->input[1]->mf[0]->params[3] = 0.05;
      (void) strcpy(fis->input[1]->mf[1]->label, "l");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = 0.025;
      fis->input[1]->mf[1]->params[1] = 0.05;
      fis->input[1]->mf[1]->params[2] = 0.1;
      (void) strcpy(fis->input[1]->mf[2]->label, "m");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = 0.05;
      fis->input[1]->mf[2]->params[1] = 0.1;
      fis->input[1]->mf[2]->params[2] = 0.15;
      (void) strcpy(fis->input[1]->mf[3]->label, "h");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = 0.1;
      fis->input[1]->mf[3]->params[1] = 0.15;
      fis->input[1]->mf[3]->params[2] = 0.2;
      (void) strcpy(fis->input[1]->mf[4]->label, "vh");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = 0.15;
      fis->input[1]->mf[4]->params[1] = 0.2;
      fis->input[1]->mf[4]->params[2] = 0.225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = 0.2;
      fis->input[1]->mf[5]->params[1] = 0.225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 7;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 4;
      fis->rule_list[1][1] = 2;
      fis->rule_list[1][2] = 5;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 4;
      fis->rule_list[2][1] = 3;
      fis->rule_list[2][2] = 3;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 4;
      fis->rule_list[3][1] = 4;
      fis->rule_list[3][2] = 2;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 4;
      fis->rule_list[4][1] = 5;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 6;
      fis->rule_list[5][2] = 1;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 1;
      fis->rule_list[6][2] = 8;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 2;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 6;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 2;
      fis->rule_list[8][1] = 3;
      fis->rule_list[8][2] = 4;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 2;
      fis->rule_list[9][1] = 4;
      fis->rule_list[9][2] = 3;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 2;
      fis->rule_list[10][1] = 5;
      fis->rule_list[10][2] = 2;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 6;
      fis->rule_list[11][2] = 1;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 1;
      fis->rule_list[12][2] = 9;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 3;
      fis->rule_list[13][1] = 2;
      fis->rule_list[13][2] = 8;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 3;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 5;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 3;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 3;
      fis->rule_list[16][1] = 5;
      fis->rule_list[16][2] = 3;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 6;
      fis->rule_list[17][2] = 1;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 1;
      fis->rule_list[18][2] = 9;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 1;
      fis->rule_list[19][1] = 2;
      fis->rule_list[19][2] = 9;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 1;
      fis->rule_list[20][1] = 3;
      fis->rule_list[20][2] = 6;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 1;
      fis->rule_list[21][1] = 4;
      fis->rule_list[21][2] = 5;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 1;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 4;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 6;
      fis->rule_list[23][2] = 1;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 1;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 5;
      fis->rule_list[25][1] = 2;
      fis->rule_list[25][2] = 9;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 5;
      fis->rule_list[26][1] = 3;
      fis->rule_list[26][2] = 7;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 5;
      fis->rule_list[27][1] = 4;
      fis->rule_list[27][2] = 6;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 5;
      fis->rule_list[28][1] = 5;
      fis->rule_list[28][2] = 5;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 1;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_ek.FISPointer = fis;
  }

  /* S-Function Block: <S178>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_ABS_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"SR");
      fis->input[1]->bound[0] = -0.25;
      fis->input[1]->bound[1] = 0.0;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = -0.225;
      fis->input[1]->mf[0]->params[3] = -0.2;
      (void) strcpy(fis->input[1]->mf[1]->label, "vh");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = -0.225;
      fis->input[1]->mf[1]->params[1] = -0.2;
      fis->input[1]->mf[1]->params[2] = -0.15;
      (void) strcpy(fis->input[1]->mf[2]->label, "h");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = -0.2;
      fis->input[1]->mf[2]->params[1] = -0.15;
      fis->input[1]->mf[2]->params[2] = -0.1;
      (void) strcpy(fis->input[1]->mf[3]->label, "m");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = -0.15;
      fis->input[1]->mf[3]->params[1] = -0.1;
      fis->input[1]->mf[3]->params[2] = -0.05;
      (void) strcpy(fis->input[1]->mf[4]->label, "l");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = -0.1;
      fis->input[1]->mf[4]->params[1] = -0.05;
      fis->input[1]->mf[4]->params[2] = -0.0225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vl");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = -0.05;
      fis->input[1]->mf[5]->params[1] = -0.0225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 1;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 2;
      fis->rule_list[1][1] = 1;
      fis->rule_list[1][2] = 1;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 3;
      fis->rule_list[2][1] = 1;
      fis->rule_list[2][2] = 1;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 1;
      fis->rule_list[3][1] = 1;
      fis->rule_list[3][2] = 1;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 5;
      fis->rule_list[4][1] = 1;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 2;
      fis->rule_list[5][2] = 2;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 2;
      fis->rule_list[6][2] = 3;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 3;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 4;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 1;
      fis->rule_list[8][1] = 2;
      fis->rule_list[8][2] = 5;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 5;
      fis->rule_list[9][1] = 2;
      fis->rule_list[9][2] = 6;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 4;
      fis->rule_list[10][1] = 3;
      fis->rule_list[10][2] = 3;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 3;
      fis->rule_list[11][2] = 4;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 3;
      fis->rule_list[12][2] = 5;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 1;
      fis->rule_list[13][1] = 3;
      fis->rule_list[13][2] = 6;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 5;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 7;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 4;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 2;
      fis->rule_list[16][1] = 4;
      fis->rule_list[16][2] = 5;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 4;
      fis->rule_list[17][2] = 6;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 4;
      fis->rule_list[18][2] = 7;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 5;
      fis->rule_list[19][1] = 4;
      fis->rule_list[19][2] = 8;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 4;
      fis->rule_list[20][1] = 5;
      fis->rule_list[20][2] = 5;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 2;
      fis->rule_list[21][1] = 5;
      fis->rule_list[21][2] = 6;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 3;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 7;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 5;
      fis->rule_list[23][2] = 8;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 5;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 4;
      fis->rule_list[25][1] = 6;
      fis->rule_list[25][2] = 7;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 2;
      fis->rule_list[26][1] = 6;
      fis->rule_list[26][2] = 8;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 3;
      fis->rule_list[27][1] = 6;
      fis->rule_list[27][2] = 9;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 1;
      fis->rule_list[28][1] = 6;
      fis->rule_list[28][2] = 9;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 9;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_n.FISPointer = fis;
  }

  /* S-Function Block: <S179>/FIS S-function (sffis) */
  {
    FIS *fis;
    if ((fis = (FIS *)calloc(1, sizeof(FIS))) == NULL ) {
      rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
      return;
    }

    (void)strcpy(fis->name, "Fuzzy_Slip_Ctl_VLC_2");
    (void)strcpy(fis->type, "mamdani");
    (void)strcpy(fis->andMethod, "min");
    (void)strcpy(fis->orMethod, "max");
    (void)strcpy(fis->defuzzMethod, "som");
    (void)strcpy(fis->impMethod, "min");
    (void)strcpy(fis->aggMethod, "max");

    {
      IO *io_list;
      int_T *in_mf_n;
      int_T i;
      if ((in_mf_n = (int_T *)calloc(2, sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      in_mf_n[0] = 5;
      in_mf_n[1] = 6;
      io_list = fisBuildIoList(2, in_mf_n);
      free(in_mf_n);
      fis->in_n = 2;
      if ((fis->input = (IO **)calloc(2, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 2; i++) {
        fis->input[i] = io_list+i;
      }

      (void) strcpy(fis->input[0]->name,"dSR/dt");
      fis->input[0]->bound[0] = -2.0;
      fis->input[0]->bound[1] = 2.0;
      fis->input[0]->mf_n = 5;
      (void) strcpy(fis->input[0]->mf[0]->label, "p");
      (void) strcpy(fis->input[0]->mf[0]->type, "trimf");
      fis->input[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[0]->params[0] = 0.0;
      fis->input[0]->mf[0]->params[1] = 1.0;
      fis->input[0]->mf[0]->params[2] = 2.0;
      (void) strcpy(fis->input[0]->mf[1]->label, "n");
      (void) strcpy(fis->input[0]->mf[1]->type, "trimf");
      fis->input[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[1]->params[0] = -2.0;
      fis->input[0]->mf[1]->params[1] = -1.0;
      fis->input[0]->mf[1]->params[2] = 0.0;
      (void) strcpy(fis->input[0]->mf[2]->label, "z");
      (void) strcpy(fis->input[0]->mf[2]->type, "trimf");
      fis->input[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[2]->params[0] = -1.0;
      fis->input[0]->mf[2]->params[1] = 0.0;
      fis->input[0]->mf[2]->params[2] = 1.0;
      (void) strcpy(fis->input[0]->mf[3]->label, "nb");
      (void) strcpy(fis->input[0]->mf[3]->type, "trapmf");
      fis->input[0]->mf[3]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[3]->params[0] = rtMinusInf;
      fis->input[0]->mf[3]->params[1] = rtMinusInf;
      fis->input[0]->mf[3]->params[2] = -2.0;
      fis->input[0]->mf[3]->params[3] = -1.0;
      (void) strcpy(fis->input[0]->mf[4]->label, "pb");
      (void) strcpy(fis->input[0]->mf[4]->type, "trapmf");
      fis->input[0]->mf[4]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[0]->mf[4]->params[0] = 1.0;
      fis->input[0]->mf[4]->params[1] = 2.0;
      fis->input[0]->mf[4]->params[2] = rtInf;
      fis->input[0]->mf[4]->params[3] = rtInf;
      (void) strcpy(fis->input[1]->name,"|SR|");
      fis->input[1]->bound[0] = 0.0;
      fis->input[1]->bound[1] = 0.25;
      fis->input[1]->mf_n = 6;
      (void) strcpy(fis->input[1]->mf[0]->label, "vl");
      (void) strcpy(fis->input[1]->mf[0]->type, "trapmf");
      fis->input[1]->mf[0]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[0]->params[0] = rtMinusInf;
      fis->input[1]->mf[0]->params[1] = rtMinusInf;
      fis->input[1]->mf[0]->params[2] = 0.025;
      fis->input[1]->mf[0]->params[3] = 0.05;
      (void) strcpy(fis->input[1]->mf[1]->label, "l");
      (void) strcpy(fis->input[1]->mf[1]->type, "trimf");
      fis->input[1]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[1]->params[0] = 0.025;
      fis->input[1]->mf[1]->params[1] = 0.05;
      fis->input[1]->mf[1]->params[2] = 0.1;
      (void) strcpy(fis->input[1]->mf[2]->label, "m");
      (void) strcpy(fis->input[1]->mf[2]->type, "trimf");
      fis->input[1]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[2]->params[0] = 0.05;
      fis->input[1]->mf[2]->params[1] = 0.1;
      fis->input[1]->mf[2]->params[2] = 0.15;
      (void) strcpy(fis->input[1]->mf[3]->label, "h");
      (void) strcpy(fis->input[1]->mf[3]->type, "trimf");
      fis->input[1]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[3]->params[0] = 0.1;
      fis->input[1]->mf[3]->params[1] = 0.15;
      fis->input[1]->mf[3]->params[2] = 0.2;
      (void) strcpy(fis->input[1]->mf[4]->label, "vh");
      (void) strcpy(fis->input[1]->mf[4]->type, "trimf");
      fis->input[1]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->input[1]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[4]->params[0] = 0.15;
      fis->input[1]->mf[4]->params[1] = 0.2;
      fis->input[1]->mf[4]->params[2] = 0.225;
      (void) strcpy(fis->input[1]->mf[5]->label, "vvh");
      (void) strcpy(fis->input[1]->mf[5]->type, "trapmf");
      fis->input[1]->mf[5]->params = (real_T *)calloc(4, sizeof(real_T));
      if (fis->input[1]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->input[1]->mf[5]->params[0] = 0.2;
      fis->input[1]->mf[5]->params[1] = 0.225;
      fis->input[1]->mf[5]->params[2] = rtInf;
      fis->input[1]->mf[5]->params[3] = rtInf;
    }

    {
      IO *io_list;
      int_T *out_mf_n;
      int_T i;
      if ((out_mf_n = (int_T *)calloc(1, sizeof(int_T))) == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      out_mf_n[0] = 9;
      io_list = fisBuildIoList(1, out_mf_n);
      free(out_mf_n);
      fis->out_n = 1;
      if ((fis->output = (IO **)calloc(1, sizeof(IO *))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i=0; i< 1; i++) {
        fis->output[i] = io_list+i;
      }

      (void) strcpy(fis->output[0]->name,"output1");
      fis->output[0]->bound[0] = 0.0;
      fis->output[0]->bound[1] = 1.0;
      fis->output[0]->mf_n = 9;
      (void) strcpy(fis->output[0]->mf[0]->label, "z");
      (void) strcpy(fis->output[0]->mf[0]->type, "trimf");
      fis->output[0]->mf[0]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[0]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[0]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[0]->params[0] = -0.125;
      fis->output[0]->mf[0]->params[1] = 0.0;
      fis->output[0]->mf[0]->params[2] = 0.125;
      (void) strcpy(fis->output[0]->mf[1]->label, "p1");
      (void) strcpy(fis->output[0]->mf[1]->type, "trimf");
      fis->output[0]->mf[1]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[1]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[1]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[1]->params[0] = 0.0;
      fis->output[0]->mf[1]->params[1] = 0.125;
      fis->output[0]->mf[1]->params[2] = 0.25;
      (void) strcpy(fis->output[0]->mf[2]->label, "p2");
      (void) strcpy(fis->output[0]->mf[2]->type, "trimf");
      fis->output[0]->mf[2]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[2]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[2]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[2]->params[0] = 0.125;
      fis->output[0]->mf[2]->params[1] = 0.25;
      fis->output[0]->mf[2]->params[2] = 0.375;
      (void) strcpy(fis->output[0]->mf[3]->label, "p3");
      (void) strcpy(fis->output[0]->mf[3]->type, "trimf");
      fis->output[0]->mf[3]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[3]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[3]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[3]->params[0] = 0.25;
      fis->output[0]->mf[3]->params[1] = 0.375;
      fis->output[0]->mf[3]->params[2] = 0.5;
      (void) strcpy(fis->output[0]->mf[4]->label, "p4");
      (void) strcpy(fis->output[0]->mf[4]->type, "trimf");
      fis->output[0]->mf[4]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[4]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[4]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[4]->params[0] = 0.375;
      fis->output[0]->mf[4]->params[1] = 0.5;
      fis->output[0]->mf[4]->params[2] = 0.625;
      (void) strcpy(fis->output[0]->mf[5]->label, "p5");
      (void) strcpy(fis->output[0]->mf[5]->type, "trimf");
      fis->output[0]->mf[5]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[5]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[5]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[5]->params[0] = 0.5;
      fis->output[0]->mf[5]->params[1] = 0.625;
      fis->output[0]->mf[5]->params[2] = 0.75;
      (void) strcpy(fis->output[0]->mf[6]->label, "p6");
      (void) strcpy(fis->output[0]->mf[6]->type, "trimf");
      fis->output[0]->mf[6]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[6]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[6]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[6]->params[0] = 0.625;
      fis->output[0]->mf[6]->params[1] = 0.75;
      fis->output[0]->mf[6]->params[2] = 0.875;
      (void) strcpy(fis->output[0]->mf[7]->label, "p7");
      (void) strcpy(fis->output[0]->mf[7]->type, "trimf");
      fis->output[0]->mf[7]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[7]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[7]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[7]->params[0] = 0.75;
      fis->output[0]->mf[7]->params[1] = 0.875;
      fis->output[0]->mf[7]->params[2] = 1.0;
      (void) strcpy(fis->output[0]->mf[8]->label, "p8");
      (void) strcpy(fis->output[0]->mf[8]->type, "trimf");
      fis->output[0]->mf[8]->value_array = (real_T *)calloc(101, sizeof(real_T));
      if (fis->output[0]->mf[8]->value_array == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params = (real_T *)calloc(3, sizeof(real_T));
      if (fis->output[0]->mf[8]->params == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->output[0]->mf[8]->params[0] = 0.875;
      fis->output[0]->mf[8]->params[1] = 1.0;
      fis->output[0]->mf[8]->params[2] = 1.125;
      fis->rule_n = 30;
      fis->rule_list = (int_T **) fisCreateMatrix(30, fis->in_n + fis->out_n,
        sizeof(int_T));
      if ((fis->rule_weight = (real_T *)calloc(30,sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->and_or = (int_T *)calloc(30,sizeof(int_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->rule_list[0][0] = 4;
      fis->rule_list[0][1] = 1;
      fis->rule_list[0][2] = 7;
      fis->rule_weight[0] = 1.0;
      fis->and_or[0] = 1;
      fis->rule_list[1][0] = 4;
      fis->rule_list[1][1] = 2;
      fis->rule_list[1][2] = 5;
      fis->rule_weight[1] = 1.0;
      fis->and_or[1] = 1;
      fis->rule_list[2][0] = 4;
      fis->rule_list[2][1] = 3;
      fis->rule_list[2][2] = 3;
      fis->rule_weight[2] = 1.0;
      fis->and_or[2] = 1;
      fis->rule_list[3][0] = 4;
      fis->rule_list[3][1] = 4;
      fis->rule_list[3][2] = 2;
      fis->rule_weight[3] = 1.0;
      fis->and_or[3] = 1;
      fis->rule_list[4][0] = 4;
      fis->rule_list[4][1] = 5;
      fis->rule_list[4][2] = 1;
      fis->rule_weight[4] = 1.0;
      fis->and_or[4] = 1;
      fis->rule_list[5][0] = 4;
      fis->rule_list[5][1] = 6;
      fis->rule_list[5][2] = 1;
      fis->rule_weight[5] = 1.0;
      fis->and_or[5] = 1;
      fis->rule_list[6][0] = 2;
      fis->rule_list[6][1] = 1;
      fis->rule_list[6][2] = 8;
      fis->rule_weight[6] = 1.0;
      fis->and_or[6] = 1;
      fis->rule_list[7][0] = 2;
      fis->rule_list[7][1] = 2;
      fis->rule_list[7][2] = 6;
      fis->rule_weight[7] = 1.0;
      fis->and_or[7] = 1;
      fis->rule_list[8][0] = 2;
      fis->rule_list[8][1] = 3;
      fis->rule_list[8][2] = 4;
      fis->rule_weight[8] = 1.0;
      fis->and_or[8] = 1;
      fis->rule_list[9][0] = 2;
      fis->rule_list[9][1] = 4;
      fis->rule_list[9][2] = 3;
      fis->rule_weight[9] = 1.0;
      fis->and_or[9] = 1;
      fis->rule_list[10][0] = 2;
      fis->rule_list[10][1] = 5;
      fis->rule_list[10][2] = 2;
      fis->rule_weight[10] = 1.0;
      fis->and_or[10] = 1;
      fis->rule_list[11][0] = 2;
      fis->rule_list[11][1] = 6;
      fis->rule_list[11][2] = 1;
      fis->rule_weight[11] = 1.0;
      fis->and_or[11] = 1;
      fis->rule_list[12][0] = 3;
      fis->rule_list[12][1] = 1;
      fis->rule_list[12][2] = 9;
      fis->rule_weight[12] = 1.0;
      fis->and_or[12] = 1;
      fis->rule_list[13][0] = 3;
      fis->rule_list[13][1] = 2;
      fis->rule_list[13][2] = 8;
      fis->rule_weight[13] = 1.0;
      fis->and_or[13] = 1;
      fis->rule_list[14][0] = 3;
      fis->rule_list[14][1] = 3;
      fis->rule_list[14][2] = 5;
      fis->rule_weight[14] = 1.0;
      fis->and_or[14] = 1;
      fis->rule_list[15][0] = 3;
      fis->rule_list[15][1] = 4;
      fis->rule_list[15][2] = 4;
      fis->rule_weight[15] = 1.0;
      fis->and_or[15] = 1;
      fis->rule_list[16][0] = 3;
      fis->rule_list[16][1] = 5;
      fis->rule_list[16][2] = 3;
      fis->rule_weight[16] = 1.0;
      fis->and_or[16] = 1;
      fis->rule_list[17][0] = 3;
      fis->rule_list[17][1] = 6;
      fis->rule_list[17][2] = 1;
      fis->rule_weight[17] = 1.0;
      fis->and_or[17] = 1;
      fis->rule_list[18][0] = 1;
      fis->rule_list[18][1] = 1;
      fis->rule_list[18][2] = 9;
      fis->rule_weight[18] = 1.0;
      fis->and_or[18] = 1;
      fis->rule_list[19][0] = 1;
      fis->rule_list[19][1] = 2;
      fis->rule_list[19][2] = 9;
      fis->rule_weight[19] = 1.0;
      fis->and_or[19] = 1;
      fis->rule_list[20][0] = 1;
      fis->rule_list[20][1] = 3;
      fis->rule_list[20][2] = 6;
      fis->rule_weight[20] = 1.0;
      fis->and_or[20] = 1;
      fis->rule_list[21][0] = 1;
      fis->rule_list[21][1] = 4;
      fis->rule_list[21][2] = 5;
      fis->rule_weight[21] = 1.0;
      fis->and_or[21] = 1;
      fis->rule_list[22][0] = 1;
      fis->rule_list[22][1] = 5;
      fis->rule_list[22][2] = 4;
      fis->rule_weight[22] = 1.0;
      fis->and_or[22] = 1;
      fis->rule_list[23][0] = 1;
      fis->rule_list[23][1] = 6;
      fis->rule_list[23][2] = 1;
      fis->rule_weight[23] = 1.0;
      fis->and_or[23] = 1;
      fis->rule_list[24][0] = 5;
      fis->rule_list[24][1] = 1;
      fis->rule_list[24][2] = 9;
      fis->rule_weight[24] = 1.0;
      fis->and_or[24] = 1;
      fis->rule_list[25][0] = 5;
      fis->rule_list[25][1] = 2;
      fis->rule_list[25][2] = 9;
      fis->rule_weight[25] = 1.0;
      fis->and_or[25] = 1;
      fis->rule_list[26][0] = 5;
      fis->rule_list[26][1] = 3;
      fis->rule_list[26][2] = 7;
      fis->rule_weight[26] = 1.0;
      fis->and_or[26] = 1;
      fis->rule_list[27][0] = 5;
      fis->rule_list[27][1] = 4;
      fis->rule_list[27][2] = 6;
      fis->rule_weight[27] = 1.0;
      fis->and_or[27] = 1;
      fis->rule_list[28][0] = 5;
      fis->rule_list[28][1] = 5;
      fis->rule_list[28][2] = 5;
      fis->rule_weight[28] = 1.0;
      fis->and_or[28] = 1;
      fis->rule_list[29][0] = 5;
      fis->rule_list[29][1] = 6;
      fis->rule_list[29][2] = 1;
      fis->rule_weight[29] = 1.0;
      fis->and_or[29] = 1;
      fisAssignMfPointer(fis);
      fisAssignFunctionPointer(fis);
      if ((fis->firing_strength = (real_T *)calloc(30, sizeof(real_T))) == NULL )
      {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->rule_output = (real_T *)calloc(30, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      if ((fis->mfs_of_rule = (real_T *)calloc(2, sizeof(real_T))) == NULL ) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigOutMfMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigOutMfMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      fis->BigWeightMatrix = (real_T *) calloc(3030, sizeof(real_T));
      if (fis->BigWeightMatrix == NULL) {
        rtmSetErrorStatus(Controller_ABS_VLC_AYC_M, "Memory Allocation Error");
        return;
      }

      for (i = 0; i < 1; i++) {
        fisComputeOutputMfValueArray(fis, 101);
      }

      fisCheckDataStructure(fis);
    }

    fis->next = NULL;
    Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_f.FISPointer = fis;
  }

  {
    int32_T j;

    /* InitializeConditions for UnitDelay: '<S13>/UD' */
    Controller_ABS_VLC_AYC_DWork.UD_DSTATE = 0.0;

    /* InitializeConditions for S-Function (sdspfilter2): '<S16>/Generated Filter Block' */
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFFID = 0;
    memset(&Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STATE[0], 0,
           403U * sizeof(real_T));
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STATE[403] = 0.0;

    /* InitializeConditions for Derivative: '<S6>/Derivative' */
    Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.TimeStampA = rtInf;
    Controller_ABS_VLC_AYC_DWork.Derivative_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for S-Function (sdspfilter2): '<S17>/Generated Filter Block' */
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_k = 0;
    for (j = 0; j < 403; j++) {
      /* InitializeConditions for S-Function (sdspfilter2): '<S17>/Generated Filter Block' */
      Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_j[j] = 0.0;

      /* InitializeConditions for S-Function (sdspfilter2): '<S26>/Generated Filter Block' */
      Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_i[j] = 0.0;

      /* InitializeConditions for S-Function (sdspfilter2): '<S27>/Generated Filter Block' */
      Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_k[j] = 0.0;

      /* InitializeConditions for S-Function (sdspfilter2): '<S165>/Generated Filter Block' */
      Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_ST_kp[j] = 0.0;

      /* InitializeConditions for S-Function (sdspfilter2): '<S166>/Generated Filter Block' */
      Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_h[j] = 0.0;

      /* InitializeConditions for S-Function (sdspfilter2): '<S175>/Generated Filter Block' */
      Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_g[j] = 0.0;

      /* InitializeConditions for S-Function (sdspfilter2): '<S176>/Generated Filter Block' */
      Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_m[j] = 0.0;
    }

    /* InitializeConditions for S-Function (sdspfilter2): '<S17>/Generated Filter Block' */
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_j[403] = 0.0;

    /* InitializeConditions for UnitDelay: '<S23>/UD' */
    Controller_ABS_VLC_AYC_DWork.UD_DSTATE_c = 0.0;

    /* InitializeConditions for S-Function (sdspfilter2): '<S26>/Generated Filter Block' */
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_j = 0;
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_i[403] = 0.0;

    /* InitializeConditions for S-Function (sdspfilter2): '<S27>/Generated Filter Block' */
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_l = 0;
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_k[403] = 0.0;

    /* InitializeConditions for UnitDelay: '<S162>/UD' */
    Controller_ABS_VLC_AYC_DWork.UD_DSTATE_o = 0.0;

    /* InitializeConditions for S-Function (sdspfilter2): '<S165>/Generated Filter Block' */
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUF_jm = 0;
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_ST_kp[403] = 0.0;

    /* InitializeConditions for S-Function (sdspfilter2): '<S166>/Generated Filter Block' */
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_g = 0;
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_h[403] = 0.0;

    /* InitializeConditions for UnitDelay: '<S172>/UD' */
    Controller_ABS_VLC_AYC_DWork.UD_DSTATE_n = 0.0;

    /* InitializeConditions for S-Function (sdspfilter2): '<S175>/Generated Filter Block' */
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_m = 0;
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_g[403] = 0.0;

    /* InitializeConditions for S-Function (sdspfilter2): '<S176>/Generated Filter Block' */
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_CIRCBUFF_e = 0;
    Controller_ABS_VLC_AYC_DWork.GeneratedFilterBlock_FILT_STA_m[403] = 0.0;
  }
}

/* Model terminate function */
void Controller_ABS_VLC_AYC_terminate(void)
{
  /* S-Function Block: <S14>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S15>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_j.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S24>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_d.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S25>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_g.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S163>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_h.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S164>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_e.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S173>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_g3.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S174>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_l.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S19>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_b.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S20>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_lj.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S29>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_dw.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S30>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_a.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S168>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_he.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S169>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_ek.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S178>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_n.FISPointer;
    fisFreeFisNode(fis);
  }

  /* S-Function Block: <S179>/FIS S-function (sffis) */
  {
    FIS *fis = (FIS *)
      Controller_ABS_VLC_AYC_DWork.FISSfunction_PWORK_f.FISPointer;
    fisFreeFisNode(fis);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Controller_ABS_VLC_AYC_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Controller_ABS_VLC_AYC_update();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
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
  Controller_ABS_VLC_AYC_initialize();
}

void MdlTerminate(void)
{
  Controller_ABS_VLC_AYC_terminate();
}

RT_MODEL_Controller_ABS_VLC_AYC *Controller_ABS_VLC_AYC(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Controller_ABS_VLC_AYC_M, 0,
                sizeof(RT_MODEL_Controller_ABS_VLC_AYC));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Controller_ABS_VLC_AYC_M->solverInfo,
                          &Controller_ABS_VLC_AYC_M->Timing.simTimeStep);
    rtsiSetTPtr(&Controller_ABS_VLC_AYC_M->solverInfo, &rtmGetTPtr
                (Controller_ABS_VLC_AYC_M));
    rtsiSetStepSizePtr(&Controller_ABS_VLC_AYC_M->solverInfo,
                       &Controller_ABS_VLC_AYC_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Controller_ABS_VLC_AYC_M->solverInfo,
                          (&rtmGetErrorStatus(Controller_ABS_VLC_AYC_M)));
    rtsiSetRTModelPtr(&Controller_ABS_VLC_AYC_M->solverInfo,
                      Controller_ABS_VLC_AYC_M);
  }

  rtsiSetSimTimeStep(&Controller_ABS_VLC_AYC_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Controller_ABS_VLC_AYC_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Controller_ABS_VLC_AYC_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Controller_ABS_VLC_AYC_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Controller_ABS_VLC_AYC_M->Timing.sampleTimes =
      (&Controller_ABS_VLC_AYC_M->Timing.sampleTimesArray[0]);
    Controller_ABS_VLC_AYC_M->Timing.offsetTimes =
      (&Controller_ABS_VLC_AYC_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Controller_ABS_VLC_AYC_M->Timing.sampleTimes[0] = (0.0);
    Controller_ABS_VLC_AYC_M->Timing.sampleTimes[1] = (0.0001);
    Controller_ABS_VLC_AYC_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    Controller_ABS_VLC_AYC_M->Timing.offsetTimes[0] = (0.0);
    Controller_ABS_VLC_AYC_M->Timing.offsetTimes[1] = (0.0);
    Controller_ABS_VLC_AYC_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Controller_ABS_VLC_AYC_M, &Controller_ABS_VLC_AYC_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = Controller_ABS_VLC_AYC_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    Controller_ABS_VLC_AYC_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Controller_ABS_VLC_AYC_M, 6.0);
  Controller_ABS_VLC_AYC_M->Timing.stepSize0 = 0.0001;
  Controller_ABS_VLC_AYC_M->Timing.stepSize1 = 0.0001;
  Controller_ABS_VLC_AYC_M->Timing.stepSize2 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Controller_ABS_VLC_AYC_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Controller_ABS_VLC_AYC_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Controller_ABS_VLC_AYC_M->rtwLogInfo, (NULL));
    rtliSetLogT(Controller_ABS_VLC_AYC_M->rtwLogInfo, "tout");
    rtliSetLogX(Controller_ABS_VLC_AYC_M->rtwLogInfo, "");
    rtliSetLogXFinal(Controller_ABS_VLC_AYC_M->rtwLogInfo, "");
    rtliSetSigLog(Controller_ABS_VLC_AYC_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Controller_ABS_VLC_AYC_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Controller_ABS_VLC_AYC_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Controller_ABS_VLC_AYC_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Controller_ABS_VLC_AYC_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Controller_ABS_VLC_AYC_Y.TFL,
        &Controller_ABS_VLC_AYC_Y.TFR,
        &Controller_ABS_VLC_AYC_Y.TRL,
        &Controller_ABS_VLC_AYC_Y.TRR
      };

      rtliSetLogYSignalPtrs(Controller_ABS_VLC_AYC_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "Controller_ABS_VLC_AYC/TFL",
        "Controller_ABS_VLC_AYC/TFR",
        "Controller_ABS_VLC_AYC/TRL",
        "Controller_ABS_VLC_AYC/TRR" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          4,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(Controller_ABS_VLC_AYC_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[3];
    }

    rtliSetLogY(Controller_ABS_VLC_AYC_M->rtwLogInfo, "yout");
  }

  Controller_ABS_VLC_AYC_M->solverInfoPtr =
    (&Controller_ABS_VLC_AYC_M->solverInfo);
  Controller_ABS_VLC_AYC_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&Controller_ABS_VLC_AYC_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&Controller_ABS_VLC_AYC_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Controller_ABS_VLC_AYC_M->ModelData.blockIO = ((void *)
    &Controller_ABS_VLC_AYC_B);
  (void) memset(((void *) &Controller_ABS_VLC_AYC_B), 0,
                sizeof(BlockIO_Controller_ABS_VLC_AYC));

  /* states (dwork) */
  Controller_ABS_VLC_AYC_M->Work.dwork = ((void *) &Controller_ABS_VLC_AYC_DWork);
  (void) memset((void *)&Controller_ABS_VLC_AYC_DWork, 0,
                sizeof(D_Work_Controller_ABS_VLC_AYC));

  /* external inputs */
  Controller_ABS_VLC_AYC_M->ModelData.inputs = (((void*)
    &Controller_ABS_VLC_AYC_U));
  (void) memset((void *)&Controller_ABS_VLC_AYC_U, 0,
                sizeof(ExternalInputs_Controller_ABS_VLC_AYC));

  /* external outputs */
  Controller_ABS_VLC_AYC_M->ModelData.outputs = (&Controller_ABS_VLC_AYC_Y);
  (void) memset((void *)&Controller_ABS_VLC_AYC_Y, 0,
                sizeof(ExternalOutputs_Controller_ABS_VLC_AYC));

  /* Initialize Sizes */
  Controller_ABS_VLC_AYC_M->Sizes.numContStates = (0);/* Number of continuous states */
  Controller_ABS_VLC_AYC_M->Sizes.numY = (4);/* Number of model outputs */
  Controller_ABS_VLC_AYC_M->Sizes.numU = (9);/* Number of model inputs */
  Controller_ABS_VLC_AYC_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  Controller_ABS_VLC_AYC_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Controller_ABS_VLC_AYC_M->Sizes.numBlocks = (467);/* Number of blocks */
  Controller_ABS_VLC_AYC_M->Sizes.numBlockIO = (69);/* Number of block outputs */
  return Controller_ABS_VLC_AYC_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
