/*****************************************************************************
 *
 * Motorola Inc.
 * (c) Copyright 2004 Motorola, Inc.
 * ALL RIGHTS RESERVED.
 *
 *****************************************************************************
 ************************************************************************
 * Copyright 2005-2010 by Freescale Semiconductor, Inc.
 * All modifications are confidential and proprietary information
 * of Freescale Semiconductor, Inc.
 ************************************************************************
 * File Name: g729_dec_api.h
 *
 * Description: This is a header file for g729_dec_api.c.
 *
 ****************************** Change History********************************
 *
 *   DD/MMM/YYYY     Code Ver     Description                   Author
 *   -----------     --------     -----------                   ------
 *   15/Jul/2008      0.1               File created                     Bing Song
 *****************************************************************************/
#ifndef G729_DEC_API_H
#define G729_DEC_API_H
/*****************************<INCLUDE_FILES BEGIN>***************************/
#include "g729_common_api.h"
/*******************************<INCLUDE_FILES END>***************************/

/******************************<ENUMS BEGIN>**********************************/
/***** Decoder return type, other return value to be added ****/
/* As of now there can be 20 warnings, starting from 11 to 30.
   Recoverable errors can be 20, starting from 31 to 50.
   Fatal errors can be 20, starting from 51 to 70.
   Later more error types can be added */
typedef enum
{
     E_G729D_OK = 0,
     E_G729D_WARNING = G729_WARNING_BASE,
     /* Recoverable error */
     E_G729D_INVALID_MODE = G729_RECOVERROR_BASE,
     /* Recoverable error */
     E_G729D_INIT_ERROR,
     /*fatal error base*/
     E_G729D_MEMALLOC_ERROR=G729_FATALERROR_BASE,
     E_G729D_ERROR
} eG729DReturnType;

/******************************<ENUMS END>************************************/

/****************************<STRUCTURES/UNIONS BEGIN>************************/
typedef struct
{
    G729_S32   s32G729DSize;        /* Size in bytes     */
    G729_U8    u8G729DType;         /* Static or scratch */
    G729_U8    u8G729DMemTypeFs;    /* Memory type Fast or Slow */
    G729_Void  *pvAPPDBasePtr;      /* Pointer to the base memory,
                                       which will be allocated and
                                       filled by the application   */
    G729_U8    u8G729DMemPriority;  /* priority in which memory needs
                                       to be allocated in fast memory*/
} sG729DMemAllocInfoSubType;

/* Memory information structure array*/
typedef struct
{
    /* Number of valid memory requests */
    G729_S32                    s32G729DNumMemReqs;
    sG729DMemAllocInfoSubType   asMemInfoSub[G729_MAX_NUM_MEM_REQS];
} sG729DMemAllocInfoType;

/* Frame erasure enumeration */
#define	E_G729D_FR_ERASED 1
#define	E_G729D_FR_NOTERASED 0

#ifdef DEBUG_G729
#define MAXDBGFILE	64				/* Max # of debug files in table	*/
#endif

typedef struct
{
     sG729DMemAllocInfoType    sG729DMemInfo;
     G729_Void	               *pvG729DDecodeInfoPtr;
     G729_U8			       u8APPDFrameErasureFlag;
     G729_U8                   watermarkFlag;
#ifdef DEBUG_G729
		 char *debugdir;
		 G729_Void (*filetw_func)(char *filename, char *text);
		 G729_Void (*filefw_func)(char *filename, G729_S32 *buf, G729_S32 start, G729_S32 count);
		 G729_Void (*filesw_func)(char *filename, G729_S16 *buf, G729_S32 start, G729_S32 count);
		 G729_Void (*fileinit_func)(char *filename,int useverbose,int * filecnt, char files[][128]);
		 G729_S32  (*sprintf_ext)( char * str, const char * format, ... );
#endif
} sG729DDecoderConfigType;
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
eG729DReturnType eG729DQueryMem(sG729DDecoderConfigType *psDecConfig);
eG729DReturnType eG729DDecodeInit(sG729DDecoderConfigType *psDecConfig);
eG729DReturnType eG729DDecodeFrame(
                    sG729DDecoderConfigType *psDecConfig,
                    G729_S16 *ps16InBuf,
                    G729_S16 *ps16OutBuf
                    );
/**************************<FUNCTION_PROTOTYPES END>***************************/

#ifdef __cplusplus
}
#endif
#endif /* end of G729_DEC_API_H header file */
/**************************<END OF THE FILE>***********************************/
