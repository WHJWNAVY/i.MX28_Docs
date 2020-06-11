 /************************************************************************
  * Copyright 2005-2010 by Freescale Semiconductor, Inc.
  * All modifications are confidential and proprietary information
  * of Freescale Semiconductor, Inc. ALL RIGHTS RESERVED.
  ************************************************************************/

/*****************************************************************************
 *
 * File Name: g729_enc_api.h
 *
 * Description: This is a header file corresponding to G729_enc_api.c.
 *
 ****************************** Change History********************************
 *
 *   DD/MMM/YYYY     Code Ver     Description      Author
 *   -----------     --------     -----------      ------
 *   15/Jul/2004     0.1          File created     Bing Song
 *****************************************************************************/
#ifndef G729_ENC_API_H
#define G729_ENC_API_H

/*****************************<INCLUDE_FILES BEGIN>***************************/
#include "g729_common_api.h"
/*******************************<INCLUDE_FILES END>***************************/
#define E_G729_VAD_DISABLE 0
#define E_G729_VAD_ENABLE 1

/******************************<ENUM BEGIN> **********************************/
/***** Encoder return type, other return value to be added ****/
/* Success is assigned to 0.
   As of now there can be 20 warnings, starting from 11 to 30.
   Recoverable errors can be 20, starting from 31 to 50.
   Fatal errors can be 20, starting from 51 to 70.
   Later more error types can be added */
typedef enum
{
     E_G729E_OK = 0,
     E_G729E_WARNING = G729_WARNING_BASE,
     /*Recoverable error*/
     E_G729E_INVALID_MODE = G729_RECOVERROR_BASE,
     /*Recoverable error*/
     E_G729E_INIT_ERROR,
     /*fatal error base*/
     E_G729E_MEMALLOC_ERROR=G729_FATALERROR_BASE,
     E_G729E_ERROR
} eG729EReturnType;

/******************************<ENUM BEGIN> **********************************/

/****************************<STRUCTURES/UNIONS BEGIN>***********************/
typedef struct
{
    G729_S32   s32G729ESize;      /* Size in bytes */
    G729_U8    u8G729EType;      /* Static or scratch */
    G729_U8    u8G729EMemTypeFs; /* Memory type Fast or Slow */
    G729_Void  *pvAPPEBasePtr;    /* Pointer to the base memory,
                                      which will be allocated and
                                      filled by the application */
    G729_U8  u8G729EMemPriority; /* priority in which memory needs
                             to be allocated in fast memory */
} sG729EMemAllocInfoSubType;

/* Memory information structure array*/
typedef struct
{
    /* Number of valid memory requests */
    G729_S32                   s32G729ENumMemReqs;
    sG729EMemAllocInfoSubType   asMemInfoSub[G729_MAX_NUM_MEM_REQS];
} sG729EMemAllocInfoType;

#ifdef DEBUG_G729
#define MAXDBGFILE	64				/* Max # of debug files in table	*/
#endif

typedef struct
{
    sG729EMemAllocInfoType sG729EMemInfo;
    G729_Void             *pvG729EEncodeInfoPtr;
    G729_U8             u8APPEVADFlag;
    G729_U8             watermarkFlag;
#ifdef DEBUG_G729
	char *debugdir;
	G729_Void (*filetw_func)(char *filename, char *text);
	G729_Void (*filefw_func)(char *filename, G729_S32 *buf, G729_S32 start, G729_S32 count);
	G729_Void (*filesw_func)(char *filename, G729_S16 *buf, G729_S32 start, G729_S32 count);
	G729_Void (*fileinit_func)(char *filename,int useverbose,int * filecnt, char files[][128]);
	G729_S32  (*sprintf_ext)( char * str, const char * format, ... );
#endif
} sG729EEncoderConfigType;

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
 G729_S8 * s8G729VersionInfo(void);
 eG729EReturnType eG729EQueryMem(sG729EEncoderConfigType *psEncConfig);
 eG729EReturnType eG729EEncodeInit(sG729EEncoderConfigType *psEncConfig);
 eG729EReturnType eG729EEncodeFrame(
                     sG729EEncoderConfigType *psEncConfig,
                     G729_S16 *ps16InBuf,
                     G729_S16 *ps16OutBuf
                     );
#ifdef __cplusplus
}
#endif
/**************************<FUNCTION_PROTOTYPES END>**************************/
#endif /* end of G729_ENC_API_H header file */
/**************************<END OF THE FILE>**********************************/
