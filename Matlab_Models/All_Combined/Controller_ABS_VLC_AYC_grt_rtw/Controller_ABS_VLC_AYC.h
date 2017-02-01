/*
 * Controller_ABS_VLC_AYC.h
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
#ifndef RTW_HEADER_Controller_ABS_VLC_AYC_h_
#define RTW_HEADER_Controller_ABS_VLC_AYC_h_
#ifndef Controller_ABS_VLC_AYC_COMMON_INCLUDES_
# define Controller_ABS_VLC_AYC_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#endif                                 /* Controller_ABS_VLC_AYC_COMMON_INCLUDES_ */

#include "Controller_ABS_VLC_AYC_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Controller_ABS_VLC_AYC_rtModel RT_MODEL_Controller_ABS_VLC_AYC

/* Block signals (auto storage) */
typedef struct {
  real_T TSamp;                        /* '<S13>/TSamp' */
  real_T Diff;                         /* '<S13>/Diff' */
  real_T FISSfunction;                 /* '<S14>/FIS S-function' */
  real_T FLAvailableAccelerationTorqueNm;/* '<S3>/FL Available Acceleration Torque [Nm]1' */
  real_T DesiredYawCalc;               /* '<S11>/Desired Yaw Calc' */
  real_T Yawerror;                     /* '<S11>/Sum' */
  real_T Derivative;                   /* '<S6>/Derivative' */
  real_T Merge;                        /* '<S89>/Merge' */
  real_T Merge_b;                      /* '<S126>/Merge' */
  real_T Merge_k;                      /* '<S90>/Merge' */
  real_T Merge_o;                      /* '<S91>/Merge' */
  real_T Merge_f;                      /* '<S95>/Merge' */
  real_T Merge_kg;                     /* '<S94>/Merge' */
  real_T Merge_fu;                     /* '<S93>/Merge' */
  real_T Merge_oo;                     /* '<S92>/Merge' */
  real_T Merge_l;                      /* '<S127>/Merge' */
  real_T Merge_g;                      /* '<S128>/Merge' */
  real_T Merge_e;                      /* '<S132>/Merge' */
  real_T Merge_oh;                     /* '<S131>/Merge' */
  real_T Merge_a;                      /* '<S130>/Merge' */
  real_T Merge_c;                      /* '<S129>/Merge' */
  real_T Merge_g2;                     /* '<S37>/Merge' */
  real_T Switch;                       /* '<S35>/Switch' */
  real_T TorquefrompedalNm;            /* '<S1>/Available Torque [Nm]' */
  real_T Sum1;                         /* '<S6>/Sum1' */
  real_T FISSfunction_m;               /* '<S15>/FIS S-function' */
  real_T UnaryMinus;                   /* '<S3>/Unary Minus' */
  real_T Switch2;                      /* '<S21>/Switch2' */
  real_T TSamp_i;                      /* '<S23>/TSamp' */
  real_T Diff_p;                       /* '<S23>/Diff' */
  real_T FISSfunction_mc;              /* '<S24>/FIS S-function' */
  real_T FRAvailableAccelerationTorqueNm;/* '<S5>/FR Available Acceleration Torque [Nm]1' */
  real_T Sum2;                         /* '<S6>/Sum2' */
  real_T FISSfunction_o;               /* '<S25>/FIS S-function' */
  real_T UnaryMinus_d;                 /* '<S5>/Unary Minus' */
  real_T Switch2_j;                    /* '<S31>/Switch2' */
  real_T TSamp_o;                      /* '<S162>/TSamp' */
  real_T Diff_n;                       /* '<S162>/Diff' */
  real_T FISSfunction_f;               /* '<S163>/FIS S-function' */
  real_T AvailableAccelerationTorqueNm1;/* '<S8>/Available Acceleration Torque [Nm]1' */
  real_T Sum3;                         /* '<S6>/Sum3' */
  real_T FISSfunction_p;               /* '<S164>/FIS S-function' */
  real_T UnaryMinus_f;                 /* '<S8>/Unary Minus' */
  real_T Switch2_c;                    /* '<S170>/Switch2' */
  real_T TSamp_m;                      /* '<S172>/TSamp' */
  real_T Diff_p5;                      /* '<S172>/Diff' */
  real_T FISSfunction_o5;              /* '<S173>/FIS S-function' */
  real_T AvailableAccelerationTorqueNm_m;/* '<S10>/Available Acceleration Torque [Nm]1' */
  real_T Sum4;                         /* '<S6>/Sum4' */
  real_T FISSfunction_n;               /* '<S174>/FIS S-function' */
  real_T UnaryMinus_i;                 /* '<S10>/Unary Minus' */
  real_T Switch2_h;                    /* '<S180>/Switch2' */
  real_T TmpSignalConversionAtAnimation1[2];
  real_T TmpSignalConversionAtAnimatio_c[2];
  real_T TmpSignalConversionAtAnimatio_h[2];
  real_T TmpSignalConversionAtAnimati_he[2];
  real_T ZeroOrderHold[2];             /* '<S32>/Zero-Order Hold' */
  real_T TmpSignalConversionAtAnimatio_f[2];
  real_T TmpSignalConversionAtAnimatio_o[2];
  real_T TmpSignalConversionAtAnimatio_l[2];
  real_T TmpSignalConversionAtAnimatio_i[2];
  real_T GeneratedFilterBlock;         /* '<S16>/Generated Filter Block' */
  real_T GeneratedFilterBlock_f;       /* '<S17>/Generated Filter Block' */
  real_T GeneratedFilterBlock_c;       /* '<S26>/Generated Filter Block' */
  real_T GeneratedFilterBlock_h;       /* '<S27>/Generated Filter Block' */
  real_T GeneratedFilterBlock_l;       /* '<S165>/Generated Filter Block' */
  real_T GeneratedFilterBlock_j;       /* '<S166>/Generated Filter Block' */
  real_T GeneratedFilterBlock_p;       /* '<S175>/Generated Filter Block' */
  real_T GeneratedFilterBlock_ch;      /* '<S176>/Generated Filter Block' */
} BlockIO_Controller_ABS_VLC_AYC;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S13>/UD' */
  real_T GeneratedFilterBlock_FILT_STATE[404];/* '<S16>/Generated Filter Block' */
  real_T GeneratedFilterBlock_FILT_STA_j[404];/* '<S17>/Generated Filter Block' */
  real_T UD_DSTATE_c;                  /* '<S23>/UD' */
  real_T GeneratedFilterBlock_FILT_STA_i[404];/* '<S26>/Generated Filter Block' */
  real_T GeneratedFilterBlock_FILT_STA_k[404];/* '<S27>/Generated Filter Block' */
  real_T UD_DSTATE_o;                  /* '<S162>/UD' */
  real_T GeneratedFilterBlock_FILT_ST_kp[404];/* '<S165>/Generated Filter Block' */
  real_T GeneratedFilterBlock_FILT_STA_h[404];/* '<S166>/Generated Filter Block' */
  real_T UD_DSTATE_n;                  /* '<S172>/UD' */
  real_T GeneratedFilterBlock_FILT_STA_g[404];/* '<S175>/Generated Filter Block' */
  real_T GeneratedFilterBlock_FILT_STA_m[404];/* '<S176>/Generated Filter Block' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S6>/Derivative' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK;                /* '<S14>/FIS S-function' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_j;              /* '<S15>/FIS S-function' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_d;              /* '<S24>/FIS S-function' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_g;              /* '<S25>/FIS S-function' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_h;              /* '<S163>/FIS S-function' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_e;              /* '<S164>/FIS S-function' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_g3;             /* '<S173>/FIS S-function' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_l;              /* '<S174>/FIS S-function' */

  struct {
    void *LoggedData;
  } LeftTorqueScope_PWORK;             /* '<S1>/Left Torque Scope' */

  struct {
    void *LoggedData;
  } RightTorqueScope1_PWORK;           /* '<S1>/Right Torque Scope1' */

  struct {
    void *LoggedData;
  } ThrottleBrakeScope_PWORK;          /* '<S1>/Throttle//Brake Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S2>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S2>/Scope1' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_b;              /* '<S19>/FIS S-function' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_lj;             /* '<S20>/FIS S-function' */

  struct {
    void *LoggedData;
  } Scope_PWORK_h;                     /* '<S4>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_g;                    /* '<S4>/Scope1' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_dw;             /* '<S29>/FIS S-function' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_a;              /* '<S30>/FIS S-function' */

  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     /* '<S6>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_b;                    /* '<S6>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S6>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_m;                     /* '<S7>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_h;                    /* '<S7>/Scope1' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_he;             /* '<S168>/FIS S-function' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_ek;             /* '<S169>/FIS S-function' */

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     /* '<S9>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_p;                    /* '<S9>/Scope1' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_n;              /* '<S178>/FIS S-function' */

  struct {
    void *FISPointer;
  } FISSfunction_PWORK_f;              /* '<S179>/FIS S-function' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_m;                    /* '<S11>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_b;                    /* '<S11>/Scope2' */

  int32_T GeneratedFilterBlock_CIRCBUFFID;/* '<S16>/Generated Filter Block' */
  int32_T GeneratedFilterBlock_CIRCBUFF_k;/* '<S17>/Generated Filter Block' */
  int32_T GeneratedFilterBlock_CIRCBUFF_j;/* '<S26>/Generated Filter Block' */
  int32_T GeneratedFilterBlock_CIRCBUFF_l;/* '<S27>/Generated Filter Block' */
  int32_T GeneratedFilterBlock_CIRCBUF_jm;/* '<S165>/Generated Filter Block' */
  int32_T GeneratedFilterBlock_CIRCBUFF_g;/* '<S166>/Generated Filter Block' */
  int32_T GeneratedFilterBlock_CIRCBUFF_m;/* '<S175>/Generated Filter Block' */
  int32_T GeneratedFilterBlock_CIRCBUFF_e;/* '<S176>/Generated Filter Block' */
  int8_T If_ActiveSubsystem;           /* '<S89>/If' */
  int8_T If_ActiveSubsystem_e;         /* '<S126>/If' */
  int8_T If_ActiveSubsystem_i;         /* '<S90>/If' */
  int8_T If_ActiveSubsystem_p;         /* '<S91>/If' */
  int8_T If_ActiveSubsystem_f;         /* '<S95>/If' */
  int8_T If_ActiveSubsystem_ey;        /* '<S94>/If' */
  int8_T If_ActiveSubsystem_g;         /* '<S93>/If' */
  int8_T If_ActiveSubsystem_go;        /* '<S92>/If' */
  int8_T If_ActiveSubsystem_c;         /* '<S127>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S128>/If' */
  int8_T If_ActiveSubsystem_j;         /* '<S132>/If' */
  int8_T If_ActiveSubsystem_j3;        /* '<S131>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S130>/If' */
  int8_T If_ActiveSubsystem_n;         /* '<S129>/If' */
  int8_T If_ActiveSubsystem_il;        /* '<S37>/If' */
} D_Work_Controller_ABS_VLC_AYC;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T FISSfunction;           /* '<S19>/FIS S-function' */
  const real_T FISSfunction_i;         /* '<S20>/FIS S-function' */
  const real_T FISSfunction_h;         /* '<S29>/FIS S-function' */
  const real_T FISSfunction_f;         /* '<S30>/FIS S-function' */
  const real_T FISSfunction_o;         /* '<S168>/FIS S-function' */
  const real_T FISSfunction_m;         /* '<S169>/FIS S-function' */
  const real_T FISSfunction_g;         /* '<S178>/FIS S-function' */
  const real_T FISSfunction_p;         /* '<S179>/FIS S-function' */
} ConstBlockIO_Controller_ABS_VLC_AYC;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: NumCoeffs)
   * Referenced by:
   *   '<S16>/Generated Filter Block'
   *   '<S17>/Generated Filter Block'
   *   '<S26>/Generated Filter Block'
   *   '<S27>/Generated Filter Block'
   *   '<S165>/Generated Filter Block'
   *   '<S166>/Generated Filter Block'
   *   '<S175>/Generated Filter Block'
   *   '<S176>/Generated Filter Block'
   */
  real_T pooled14[404];

  /* Expression: Xdata
   * Referenced by: '<S37>/x data'
   */
  real_T xdata_Value[101];

  /* Expression: trapmf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(1).params)
   * Referenced by: '<S38>/NVB'
   */
  real_T NVB_Value[101];

  /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(2).params)
   * Referenced by: '<S38>/NB'
   */
  real_T NB_Value[101];

  /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(3).params)
   * Referenced by: '<S38>/NM'
   */
  real_T NM_Value[101];

  /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(4).params)
   * Referenced by: '<S38>/NS'
   */
  real_T NS_Value[101];

  /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(5).params)
   * Referenced by: '<S38>/Z'
   */
  real_T Z_Value[101];

  /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(6).params)
   * Referenced by: '<S38>/PS'
   */
  real_T PS_Value[101];

  /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(7).params)
   * Referenced by: '<S38>/PM'
   */
  real_T PM_Value[101];

  /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(8).params)
   * Referenced by: '<S38>/PB'
   */
  real_T PB_Value[101];

  /* Expression: trapmf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(9).params)
   * Referenced by: '<S38>/PVB'
   */
  real_T PVB_Value[101];
} ConstParam_Controller_ABS_VLC_AYC;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T Vx_cont;                      /* '<Root>/Vx_cont' */
  real_T Vy_cont;                      /* '<Root>/Vy_cont' */
  real_T r_cont;                       /* '<Root>/r_cont' */
  real_T S_Ang;                        /* '<Root>/S_Ang' */
  real_T FL_SR;                        /* '<Root>/FL_SR' */
  real_T FR_SR;                        /* '<Root>/FR_SR' */
  real_T RL_SR;                        /* '<Root>/RL_SR' */
  real_T RR_SR;                        /* '<Root>/RR_SR' */
  real_T T_P;                          /* '<Root>/T_P' */
} ExternalInputs_Controller_ABS_VLC_AYC;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T TFL;                          /* '<Root>/TFL' */
  real_T TFR;                          /* '<Root>/TFR' */
  real_T TRL;                          /* '<Root>/TRL' */
  real_T TRR;                          /* '<Root>/TRR' */
} ExternalOutputs_Controller_ABS_VLC_AYC;

/* Backward compatible GRT Identifiers */
#define rtB                            Controller_ABS_VLC_AYC_B
#define BlockIO                        BlockIO_Controller_ABS_VLC_AYC
#define rtU                            Controller_ABS_VLC_AYC_U
#define ExternalInputs                 ExternalInputs_Controller_ABS_VLC_AYC
#define rtXdot                         Controller_ABS_VLC_AYC_Xdot
#define StateDerivatives               StateDerivatives_Controller_ABS_VLC_AYC
#define tXdis                          Controller_ABS_VLC_AYC_Xdis
#define StateDisabled                  StateDisabled_Controller_ABS_VLC_AYC
#define rtY                            Controller_ABS_VLC_AYC_Y
#define ExternalOutputs                ExternalOutputs_Controller_ABS_VLC_AYC
#define rtDWork                        Controller_ABS_VLC_AYC_DWork
#define D_Work                         D_Work_Controller_ABS_VLC_AYC
#define tConstBlockIOType              ConstBlockIO_Controller_ABS_VLC_AYC
#define rtC                            Controller_ABS_VLC_AYC_ConstB
#define ConstParam                     ConstParam_Controller_ABS_VLC_AYC
#define rtcP                           Controller_ABS_VLC_AYC_ConstP

/* Real-time Model Data Structure */
struct RT_MODEL_Controller_ABS_VLC_AYC {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    struct {
      uint16_T TID[3];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block signals (auto storage) */
extern BlockIO_Controller_ABS_VLC_AYC Controller_ABS_VLC_AYC_B;

/* Block states (auto storage) */
extern D_Work_Controller_ABS_VLC_AYC Controller_ABS_VLC_AYC_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_Controller_ABS_VLC_AYC Controller_ABS_VLC_AYC_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_Controller_ABS_VLC_AYC Controller_ABS_VLC_AYC_Y;
extern const ConstBlockIO_Controller_ABS_VLC_AYC Controller_ABS_VLC_AYC_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstParam_Controller_ABS_VLC_AYC Controller_ABS_VLC_AYC_ConstP;

/* Real-time Model object */
extern struct RT_MODEL_Controller_ABS_VLC_AYC *const Controller_ABS_VLC_AYC_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Controller_ABS_VLC_AYC'
 * '<S1>'   : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control'
 * '<S2>'   : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FL Slip Controller'
 * '<S3>'   : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FL Torque Gains and Saturation'
 * '<S4>'   : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FR Slip Controller'
 * '<S5>'   : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FR Torque Gains and Saturation'
 * '<S6>'   : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller'
 * '<S7>'   : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RL Slip Controller'
 * '<S8>'   : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RL Torque Gains and Saturation'
 * '<S9>'   : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RR Slip Controller'
 * '<S10>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RR Torque Gains and Saturation'
 * '<S11>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Yaw Reference//Error Generator'
 * '<S12>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FL Slip Controller/ABS Fuzzy Controller'
 * '<S13>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FL Slip Controller/Discrete Derivative'
 * '<S14>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FL Slip Controller/Fuzzy Logic  Controller'
 * '<S15>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FL Slip Controller/Fuzzy Logic  Controller1'
 * '<S16>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FL Slip Controller/Lowpass Filter'
 * '<S17>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FL Slip Controller/Lowpass Filter1'
 * '<S18>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FL Slip Controller/VLC Fuzzy Controller'
 * '<S19>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FL Slip Controller/ABS Fuzzy Controller/Fuzzy Logic Controller'
 * '<S20>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FL Slip Controller/VLC Fuzzy Controller/Fuzzy Logic Controller'
 * '<S21>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FL Torque Gains and Saturation/FL Saturation Dynamic'
 * '<S22>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FR Slip Controller/ABS Fuzzy Controller'
 * '<S23>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FR Slip Controller/Discrete Derivative'
 * '<S24>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FR Slip Controller/Fuzzy Logic  Controller'
 * '<S25>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FR Slip Controller/Fuzzy Logic  Controller1'
 * '<S26>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FR Slip Controller/Lowpass Filter'
 * '<S27>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FR Slip Controller/Lowpass Filter1'
 * '<S28>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FR Slip Controller/VLC Fuzzy Controller'
 * '<S29>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FR Slip Controller/ABS Fuzzy Controller/Fuzzy Logic Controller'
 * '<S30>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FR Slip Controller/VLC Fuzzy Controller/Fuzzy Logic Controller'
 * '<S31>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/FR Torque Gains and Saturation/FR Saturation Dynamic'
 * '<S32>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller'
 * '<S33>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/Manual Switch (AYC ON//OFF)'
 * '<S34>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller'
 * '<S35>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard'
 * '<S36>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError'
 * '<S37>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Defuzzification1'
 * '<S38>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/OutputTorqueChange'
 * '<S39>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule1'
 * '<S40>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule10'
 * '<S41>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule11'
 * '<S42>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule12'
 * '<S43>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule13'
 * '<S44>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule14'
 * '<S45>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule15'
 * '<S46>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule16'
 * '<S47>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule17'
 * '<S48>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule18'
 * '<S49>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule19'
 * '<S50>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule2'
 * '<S51>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule20'
 * '<S52>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule21'
 * '<S53>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule22'
 * '<S54>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule23'
 * '<S55>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule24'
 * '<S56>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule25'
 * '<S57>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule26'
 * '<S58>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule27'
 * '<S59>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule28'
 * '<S60>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule29'
 * '<S61>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule3'
 * '<S62>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule30'
 * '<S63>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule31'
 * '<S64>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule32'
 * '<S65>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule33'
 * '<S66>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule34'
 * '<S67>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule35'
 * '<S68>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule36'
 * '<S69>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule37'
 * '<S70>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule38'
 * '<S71>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule39'
 * '<S72>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule4'
 * '<S73>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule40'
 * '<S74>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule41'
 * '<S75>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule42'
 * '<S76>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule43'
 * '<S77>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule44'
 * '<S78>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule45'
 * '<S79>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule46'
 * '<S80>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule47'
 * '<S81>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule48'
 * '<S82>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule49'
 * '<S83>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule5'
 * '<S84>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule6'
 * '<S85>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule7'
 * '<S86>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule8'
 * '<S87>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Rule9'
 * '<S88>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError'
 * '<S89>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NB'
 * '<S90>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NM'
 * '<S91>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NS'
 * '<S92>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PB'
 * '<S93>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PM'
 * '<S94>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PS'
 * '<S95>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/Z'
 * '<S96>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NB/If Action Subsystem'
 * '<S97>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NB/If Action Subsystem1'
 * '<S98>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NB/If Action Subsystem2'
 * '<S99>'  : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NB/If Action Subsystem3'
 * '<S100>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NM/If Action Subsystem'
 * '<S101>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NM/If Action Subsystem1'
 * '<S102>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NM/If Action Subsystem2'
 * '<S103>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NM/If Action Subsystem3'
 * '<S104>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NS/If Action Subsystem'
 * '<S105>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NS/If Action Subsystem1'
 * '<S106>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NS/If Action Subsystem2'
 * '<S107>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/NS/If Action Subsystem3'
 * '<S108>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PB/If Action Subsystem'
 * '<S109>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PB/If Action Subsystem1'
 * '<S110>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PB/If Action Subsystem2'
 * '<S111>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PB/If Action Subsystem3'
 * '<S112>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PM/If Action Subsystem'
 * '<S113>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PM/If Action Subsystem1'
 * '<S114>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PM/If Action Subsystem2'
 * '<S115>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PM/If Action Subsystem3'
 * '<S116>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PS/If Action Subsystem'
 * '<S117>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PS/If Action Subsystem1'
 * '<S118>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PS/If Action Subsystem2'
 * '<S119>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/PS/If Action Subsystem3'
 * '<S120>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/Z/If Action Subsystem'
 * '<S121>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/Z/If Action Subsystem1'
 * '<S122>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/Z/If Action Subsystem2'
 * '<S123>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/ChaneInYawRateError/Z/If Action Subsystem3'
 * '<S124>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Defuzzification1/Action: One'
 * '<S125>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/Defuzzification1/Action: u1'
 * '<S126>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NB'
 * '<S127>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NM'
 * '<S128>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NS'
 * '<S129>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PB'
 * '<S130>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PM'
 * '<S131>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PS'
 * '<S132>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/Z'
 * '<S133>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NB/If Action Subsystem'
 * '<S134>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NB/If Action Subsystem1'
 * '<S135>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NB/If Action Subsystem2'
 * '<S136>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NB/If Action Subsystem3'
 * '<S137>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NM/If Action Subsystem'
 * '<S138>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NM/If Action Subsystem1'
 * '<S139>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NM/If Action Subsystem2'
 * '<S140>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NM/If Action Subsystem3'
 * '<S141>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NS/If Action Subsystem'
 * '<S142>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NS/If Action Subsystem1'
 * '<S143>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NS/If Action Subsystem2'
 * '<S144>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/NS/If Action Subsystem3'
 * '<S145>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PB/If Action Subsystem'
 * '<S146>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PB/If Action Subsystem1'
 * '<S147>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PB/If Action Subsystem2'
 * '<S148>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PB/If Action Subsystem3'
 * '<S149>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PM/If Action Subsystem'
 * '<S150>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PM/If Action Subsystem1'
 * '<S151>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PM/If Action Subsystem2'
 * '<S152>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PM/If Action Subsystem3'
 * '<S153>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PS/If Action Subsystem'
 * '<S154>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PS/If Action Subsystem1'
 * '<S155>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PS/If Action Subsystem2'
 * '<S156>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/PS/If Action Subsystem3'
 * '<S157>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/Z/If Action Subsystem'
 * '<S158>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/Z/If Action Subsystem1'
 * '<S159>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/Z/If Action Subsystem2'
 * '<S160>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/Fuzzy Yaw Controller/AYC Fuzzy Controller/Fuzzy Logic Controller/FIS Wizard/YawRateError/Z/If Action Subsystem3'
 * '<S161>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RL Slip Controller/ABS Fuzzy Controller'
 * '<S162>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RL Slip Controller/Discrete Derivative'
 * '<S163>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RL Slip Controller/Fuzzy Logic  Controller'
 * '<S164>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RL Slip Controller/Fuzzy Logic  Controller1'
 * '<S165>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RL Slip Controller/Lowpass Filter'
 * '<S166>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RL Slip Controller/Lowpass Filter1'
 * '<S167>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RL Slip Controller/VLC Fuzzy Controller'
 * '<S168>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RL Slip Controller/ABS Fuzzy Controller/Fuzzy Logic Controller'
 * '<S169>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RL Slip Controller/VLC Fuzzy Controller/Fuzzy Logic Controller'
 * '<S170>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RL Torque Gains and Saturation/Saturation Dynamic'
 * '<S171>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RR Slip Controller/ABS Fuzzy Controller'
 * '<S172>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RR Slip Controller/Discrete Derivative'
 * '<S173>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RR Slip Controller/Fuzzy Logic  Controller'
 * '<S174>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RR Slip Controller/Fuzzy Logic  Controller1'
 * '<S175>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RR Slip Controller/Lowpass Filter'
 * '<S176>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RR Slip Controller/Lowpass Filter1'
 * '<S177>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RR Slip Controller/VLC Fuzzy Controller'
 * '<S178>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RR Slip Controller/ABS Fuzzy Controller/Fuzzy Logic Controller'
 * '<S179>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RR Slip Controller/VLC Fuzzy Controller/Fuzzy Logic Controller'
 * '<S180>' : 'Controller_ABS_VLC_AYC/ABS//VLC//AYC Control/RR Torque Gains and Saturation/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_Controller_ABS_VLC_AYC_h_ */
