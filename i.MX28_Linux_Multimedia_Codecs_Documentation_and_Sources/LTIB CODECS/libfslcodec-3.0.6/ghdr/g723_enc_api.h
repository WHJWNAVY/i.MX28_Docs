
/*****************************************************************************
 *
 * Motorola Inc.
 * (c) Copyright 2004 Motorola, Inc.
 * ALL RIGHTS RESERVED.
 *
 /************************************************************************
  * Copyright 2005-2010 by Freescale Semiconductor, Inc.
  * All modifications are confidential and proprietary information
  * of Freescale Semiconductor, Inc.
  ************************************************************************/
/*****************************************************************************
 *
 * File Name: g723_enc_api.h
 *
 * Description: This is a header file corresponding to G723_enc_api.c.
 *
 ****************************** Change History********************************
 *
 *   DD/MMM/YYYY     Code Ver     Description      Author
 *   -----------     --------     -----------      ------
 *   18/Oct/2004     0.1          File created     Tommy Tang
 *****************************************************************************/

#ifndef G723_ENC_API_H
#define G723_ENC_API_H

/*****************************<INCLUDE_FILES BEGIN>***************************/
#include "g723_common_api.h"
/*******************************<INCLUDE_FILES END>***************************/

/******************************<DEFINES BEGIN>********************************/
/* this should be set to 0xF to enable all the debug level logs
 * value of 0x1 will enbale - log level 1 only
 * value of 0x2 will enable - log level 2 only
 * value of 0x3 will enable - level 1 and 2 logs
 * value of 0x4 will enable - level 3 logs
 * value of 0x8 will enabel - level 4 log
 */
#define G723E_DEBUG_LVL 0x0

/* this is start of log message */
#define G723E_BEGIN_DBG_MSGID  1000
/* end of message id */
#define G723E_END_DBG_MSGID    1499
/******************************* < DEFINE END> *******************************/

/******************************<ENUM BEGIN> **********************************/
/***** Encoder return type, other return value to be added ****/
/* Success is assigned to 0.
   As of now there can be 20 warnings, starting from 11 to 30.
   Recoverable errors can be 20, starting from 31 to 50.
   Fatal errors can be 20, starting from 51 to 70.
   Later more error types can be added */
typedef enum
{
     E_G723E_OK = 0,
     E_G723E_WARNING = G723_WARNING_BASE,
     /*Recoverable error*/
     E_G723E_INVALID_MODE = G723_RECOVERROR_BASE,
     /*Recoverable error*/
     E_G723E_INIT_ERROR,
     /*fatal error base*/
     E_G723E_MEMALLOC_ERROR=G723_FATALERROR_BASE,
     E_G723E_ERROR
} eG723EReturnType;

typedef enum
{
	E_G723E_HPFILTER_DISABLE,
	E_G723E_HPFILTER_ENABLE
} eG723EHighPassFilterType;

typedef enum
{
	E_G723_VAD_DISABLE,
	E_G723_VAD_ENABLE
} eG723EVadCngType;

typedef enum
{
	E_G723E_BITRATE_53,
	E_G723E_BITRATE_63
}eG723EBitRateType;
/******************************<ENUM BEGIN> **********************************/

/****************************<STRUCTURES/UNIONS BEGIN>***********************/
typedef struct
{
    G723_S32   s32G723ESize;      /* Size in bytes */
    G723_U8    u8G723EType;      /* Static or scratch */
    G723_U8    u8G723EMemTypeFs; /* Memory type Fast or Slow */
    G723_Void  *pvAPPEBasePtr;    /* Pointer to the base memory,
                                      which will be allocated and
                                      filled by the application */
    G723_U8  u8G723EMemPriority; /* priority in which memory needs
                             to be allocated in fast memory */
} sG723EMemAllocInfoSubType;

/* Memory information structure array*/
typedef struct
{
    /* Number of valid memory requests */
    G723_S32                   s32G723ENumMemReqs;
    sG723EMemAllocInfoSubType   asMemInfoSub[G723_MAX_NUM_MEM_REQS];
} sG723EMemAllocInfoType;

typedef struct
{
    sG723EMemAllocInfoType sG723EMemInfo;
    G723_Void             *pvG723EEncodeInfoPtr;
    G723_U8             *pu8APPEInitializedDataStart;
    G723_U8             u8APPEHighPassFilter;
    G723_U8             u8APPEBitRate;
    G723_U8             u8APPEVADFlag;
    G723_U8		watermarkFlag;
} sG723EEncoderConfigType;

/****************************<STRUCTURES/UNIONS END>**************************/

/***************************<GLOBAL_VARIABLES BEGIN>**************************/
                                   /* None */

/***************************<GLOBAL_VARIABLES END>****************************/

/**************************<STATIC_VARIABLES BEGIN>***************************/
                                    /* None */
/**************************<STATIC_VARIABLES END>*****************************/

#ifdef __cplusplus
extern "C"
{
#endif
 eG723EReturnType eG723EQueryMem(sG723EEncoderConfigType *psEncConfig);
 eG723EReturnType eG723EEncodeInit(sG723EEncoderConfigType *psEncConfig);
 eG723EReturnType eG723EEncodeFrame(
                     sG723EEncoderConfigType *psEncConfig,
                     G723_S16 *ps16InBuf,
                     G723_S16 *ps16OutBuf
                     );
 const char *G723_get_version_info(void);
#ifdef __cplusplus
}
#endif
/**************************<FUNCTION_PROTOTYPES END>**************************/
#endif /* end of G723_ENC_API_H header file */
/**************************<END OF THE FILE>**********************************/
