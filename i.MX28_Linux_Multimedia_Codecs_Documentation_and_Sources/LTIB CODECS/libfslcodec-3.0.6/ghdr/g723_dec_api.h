
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
 * File Name: g723_dec_api.h
 *
 * Description: This is a header file for g723_dec_api.c.
 *
 ****************************** Change History********************************
 *
 *   DD/MMM/YYYY     Code Ver     Description                   Author
 *   -----------     --------     -----------                   ------
 *   18/Oct/2004     0.1          File created                  Tommy Tang
 *****************************************************************************/
#ifndef G723_DEC_API_H
#define G723_DEC_API_H
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
#define G723D_DEBUG_LVL 0x0

/* this is start of log message */
#define G723D_BEGIN_DBG_MSGID   1500
#define G723D_END_DBG_MSGID     1999
/******************************<DEFINES END>**********************************/

/******************************<ENUMS BEGIN>**********************************/
/***** Decoder return type, other return value to be added ****/
/* As of now there can be 20 warnings, starting from 11 to 30.
   Recoverable errors can be 20, starting from 31 to 50.
   Fatal errors can be 20, starting from 51 to 70.
   Later more error types can be added */
typedef enum
{
     E_G723D_OK = 0,
     E_G723D_WARNING = G723_WARNING_BASE,
     /* Recoverable error */
     E_G723D_INVALID_MODE = G723_RECOVERROR_BASE,
     /* Recoverable error */
     E_G723D_INIT_ERROR,
     /*fatal error base*/
     E_G723D_MEMALLOC_ERROR=G723_FATALERROR_BASE,
     E_G723D_ERROR
} eG723DReturnType;

/* Post filter enumeration */
typedef enum
{
	E_G723D_P_FILTER_DISABLE,
	E_G723D_P_FILTER_ENABLE
} eG723DPostFilterType;

/* Frame erasure enumeration */
typedef enum
{
	E_G723D_FR_ERASED,
	E_G723D_FR_NOTERASED
} eG723DFrameErasureType;

/******************************<ENUMS END>************************************/

/****************************<STRUCTURES/UNIONS BEGIN>************************/
typedef struct
{
    G723_S32   s32G723DSize;        /* Size in bytes     */
    G723_U8    u8G723DType;         /* Static or scratch */
    G723_U8    u8G723DMemTypeFs;    /* Memory type Fast or Slow */
    G723_Void  *pvAPPDBasePtr;      /* Pointer to the base memory,
                                       which will be allocated and
                                       filled by the application   */
    G723_U8    u8G723DMemPriority;  /* priority in which memory needs
                                       to be allocated in fast memory*/
} sG723DMemAllocInfoSubType;

/* Memory information structure array*/
typedef struct
{
    /* Number of valid memory requests */
    G723_S32                    s32G723DNumMemReqs;
    sG723DMemAllocInfoSubType   asMemInfoSub[G723_MAX_NUM_MEM_REQS];
} sG723DMemAllocInfoType;

typedef struct
{
     sG723DMemAllocInfoType    sG723DMemInfo;
     G723_Void	               *pvG723DDecodeInfoPtr;
     G723_U8                   *pu8APPDInitializedDataStart;
     G723_U8                   u8APPDPostFilter;
     G723_U8			       u8APPDFrameErasureFlag;
     G723_U8		       watermarkFlag;
} sG723DDecoderConfigType;
/****************************<STRUCTURES/UNIONS END>**************************/

/***************************<GLOBAL_VARIABLES BEGIN>**************************/
                                  /* None */
/***************************<GLOBAL_VARIABLES END>****************************/

/**************************<STATIC_VARIABLES BEGIN>***************************/
                                    /* None */
/**************************<STATIC_VARIABLES END>*****************************/

/**************************<FUNCTION_PROTOTYPES BEGIN>************************/
#ifdef __cplusplus
extern "C"
{
#endif
 EXTERN eG723DReturnType eG723DQueryMem(sG723DDecoderConfigType *psDecConfig);
 EXTERN eG723DReturnType eG723DDecodeInit(sG723DDecoderConfigType *psDecConfig);
 EXTERN eG723DReturnType eG723DDecodeFrame(
                    sG723DDecoderConfigType *psDecConfig,
                    G723_S16 *ps16InBuf,
                    G723_S16 *ps16OutBuf
                    );
 const char *G723_get_version_info(void);
/**************************<FUNCTION_PROTOTYPES END>***************************/

#ifdef __cplusplus
}
#endif
#endif /* end of G723_DEC_API_H header file */
/**************************<END OF THE FILE>***********************************/
