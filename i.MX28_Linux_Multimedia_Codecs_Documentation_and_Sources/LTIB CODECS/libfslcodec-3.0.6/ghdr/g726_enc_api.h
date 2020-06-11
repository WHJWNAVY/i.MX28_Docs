
/*****************************************************************************
 *
 * Motorola Inc.
 * (c) Copyright 2004 Motorola, Inc.
 * ALL RIGHTS RESERVED.
 *
 *****************************************************************************/
 /************************************************************************
  * Copyright 2005-2010 by Freescale Semiconductor, Inc.
  * All modifications are confidential and proprietary information
  * of Freescale Semiconductor, Inc.
  ************************************************************************/
/*****************************************************************************
 * File Name: g726_enc_api.h
 *
 * Description: This is a header file corresponding to G726_enc_api.c.
 *
 ****************************** Change History********************************
 *
 *   DD/MMM/YYYY     Code Ver     Author       Description
 *   -----------     --------     ------       -----------
 *   28/Jul/2004     0.1          Tommy Tang   File created
 *   16/Aug/2004     1.0          Tommy Tang   Review rework
 *   6/11/2008       engr79565    Qiu Cunshou  WinCE build,Add API for version
 *****************************************************************************/

#ifndef G726_ENC_API_H
#define G726_ENC_API_H

/*****************************<INCLUDE_FILES BEGIN>***************************/
#include "g726_com_api.h"
/*******************************<INCLUDE_FILES END>***************************/

/******************************<DEFINES BEGIN>********************************/
/* this should be set to 0xF to enable all the debug level logs
 * value of 0x1 will enbale - log level 1 only
 * value of 0x2 will enable - log level 2 only
 * value of 0x3 will enable - level 1 and 2 logs
 * value of 0x4 will enable - level 3 logs
 * value of 0x8 will enabel - level 4 log
 */
#define G726E_DEBUG_LVL 0x0

/* this is start of log message */
#define G726E_BEGIN_DBG_MSGID  1000
/* end of message id */
#define G726E_END_DBG_MSGID    1499

/******************************<DEFINES END>**********************************/

/******************************<ENUMS BEGIN>**********************************/
/***** Encoder return type, other return value to be added ****/
/* Success is assigned to 0.
   As of now there can be 20 warnings, starting from 11 to 30.
   Recoverable errors can be 20, starting from 31 to 50.
   Fatal errors can be 20, starting from 51 to 70.
   Later more error types can be added */
typedef enum
{
     G726E_OK = 0,
     G726E_WARNING = G726_WARNING_BASE,
     G726E_INVALID_MODE = G726_RECOVERROR_BASE, /*Recoverable error    */
     G726E_INIT_ERROR,                            /*Recoverable error   */
     G726E_MEMALLOC_ERROR = G726_FATALERROR_BASE, /*fatal error base    */
     G726E_ERROR
} eG726EReturnType;

/******************************<ENUMS END>************************************/

/****************************<STRUCTURES/UNIONS BEGIN>************************/
typedef struct
{
    G726_S32   s32G726ESize;      /* Size in bytes */
    G726_S32   s32G726EType;      /* Static or scratch */
    G726_S32   s32G726EMemTypeFs; /* Memory type Fast or Slow */
    G726_Void  *pvAPPEBasePtr;    /* Pointer to the base memory,
                                      which will be allocated and
                                      filled by the application   */
    G726_U8    u8G726EMemPriority; /* priority in which memory needs to be
                                       allocated in fast memory */
} sG726EMemAllocInfoSubType;

/* Memory information structure array*/
typedef struct
{
    /* Number of valid memory requests */
    G726_S32                    s32G726ENumMemReqs;
    sG726EMemAllocInfoSubType   asMemInfoSub[G726_MAX_NUM_MEM_REQS];
} sG726EMemAllocInfoType;

typedef struct
{
    sG726EMemAllocInfoType sG726EMemInfo;
    G726_Void             *pvG726EEncodeInfoPtr;
    G726_U8               *pu8APPEInitializedDataStart;
    G726_S32              s32APPEBitRate;
    G726_S32              s32APPEPcmFormat;
    G726_S32              s32APPESampleNum;
    G726_S32              watermarkFlag;
} sG726EEncoderConfigType;
/****************************<STRUCTURES/UNIONS END>**************************/

/***************************<GLOBAL_VARIABLES BEGIN>**************************/
                                   /* None */

/***************************<GLOBAL_VARIABLES END>****************************/

/**************************<STATIC_VARIABLES BEGIN>***************************/
                                    /* None */
/**************************<STATIC_VARIABLES END>*****************************/

/**************************<FUNCTION_PROTOTYPES BEGIN>************************/
#ifdef __SYMBIAN32__
#define EXPORT_C __declspec(dllexport)
#define EXTERN
#else
#define EXTERN
#define EXPORT_C
#endif
#ifdef __cplusplus
extern "C"
{
#endif
 EXTERN eG726EReturnType eG726EQueryMem(sG726EEncoderConfigType *psEncConfig);
 EXTERN eG726EReturnType eG726EEncodeInit(sG726EEncoderConfigType *psEncConfig);
 EXTERN eG726EReturnType eG726EEncode(
                     sG726EEncoderConfigType *psEncConfig,
                     G726_S16 *ps16InBuf,
                     G726_S16 *ps16OutBuf
                     );
 const char *G726E_get_version_info(void);
#ifdef __cplusplus
}
#endif
/**************************<FUNCTION_PROTOTYPES END>**************************/
#endif /* end of G726_ENC_API_H header file */
/**************************<END OF THE FILE>**********************************/
