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
 *
 * File Name: g726_dec_api.h
 *
 * Description: This is a header file for g726_dec_api.c.
 *
 *
 ****************************** Change History********************************
 *
 *   DD/MMM/YYYY     Code Ver     Description      Author
 *   -----------     --------     -----------      ------
 *   28/Jul/2004     0.1          File created     Tommy Tang
 *   19/Aug/2004     1.0          Review rework    Tommy Tang
 *   6/11/2008       engr79565    WinCE build      Qiu Cunshou,Add API for version
 *****************************************************************************/

#ifndef G726_DEC_API_H
#define G726_DEC_API_H

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
#define G726D_DEBUG_LVL 0x0

/* this is start of log message */
#define G726D_BEGIN_DBG_MSGID   1500
#define G726D_END_DBG_MSGID     1999

/******************************<DEFINES END>**********************************/

/******************************<ENUMS BEGIN>**********************************/
/***** Decoder return type, other return value to be added ****/
/* As of now there can be 20 warnings, starting from 11 to 30.
   Recoverable errors can be 20, starting from 31 to 50.
   Fatal errors can be 20, starting from 51 to 70.
   Later more error types can be added */
typedef enum
{
     G726D_OK = 0,
     G726D_WARNING = G726_WARNING_BASE,
     G726D_INVALID_MODE = G726_RECOVERROR_BASE,   /*Recoverable error     */
     G726D_INIT_ERROR,                            /*Recoverable error    */
     G726D_MEMALLOC_ERROR = G726_FATALERROR_BASE, /*fatal error base     */
     G726D_ERROR
} eG726DReturnType;

/******************************<ENUMS END>************************************/

/****************************<STRUCTURES/UNIONS BEGIN>************************/
typedef struct
{
    G726_S32   s32G726DSize;       /* Size in bytes                  */
    G726_S32   s32G726DType;       /* Static or scratch              */
    G726_S32   s32G726DMemTypeFs;  /* Memory type Fast or Slow       */
    G726_Void  *pvAPPDBasePtr;     /* Pointer to the base memory,
                                       which will be allocated and
                                       filled by the application      */
    G726_U8    u8G726DMemPriority; /* priority in which memory needs
                                       to be allocated in fast memory */
} sG726DMemAllocInfoSubType;

/* Memory information structure array*/
typedef struct
{
    /* Number of valid memory requests */
    G726_S32                    s32G726DNumMemReqs;
    sG726DMemAllocInfoSubType   asMemInfoSub[G726_MAX_NUM_MEM_REQS];
} sG726DMemAllocInfoType;

typedef struct
{
    sG726DMemAllocInfoType sG726DMemInfo;
    G726_Void             *pvG726DDecodeInfoPtr;
    G726_U8               *pu8APPDInitializedDataStart;
    G726_S32              s32APPDBitRate;
    G726_S32              s32APPDPcmFormat;
    G726_S32              s32APPDSampleNum;
    G726_S32              watermarkFlag;
} sG726DDecoderConfigType;

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

  eG726DReturnType eG726DQueryMem(sG726DDecoderConfigType *psDecConfig);
  eG726DReturnType eG726DDecodeInit(sG726DDecoderConfigType *psDecConfig);
  eG726DReturnType eG726DDecode(
                    sG726DDecoderConfigType *psDecConfig,
                    G726_S16 *ps16InBuf,
                    G726_S16 *ps16OutBuf
                    );
  const char *G726D_get_version_info(void);
#ifdef __cplusplus
}
#endif
/**************************<FUNCTION_PROTOTYPES END>***************************/

#endif /* end of G726_DEC_API_H header file */
/**************************<END OF THE FILE>***********************************/
