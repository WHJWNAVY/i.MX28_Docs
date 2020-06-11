
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
 * File Name: g723_common_api.h
 *
 * Description: This is common header interface file to be used by decoder
 *              and encoder.
 *
 ****************************** Change History********************************
 *   DD/MMM/YYYY     Code Ver     Description      Author
 *   -----------     --------     -----------      ------
 *   18/Oct/2004     0.1          File created     Tommy Tang
 *****************************************************************************/
#ifndef G723_COMMON_API_H
#define G723_COMMON_API_H

/******************************************************************************/
#define G723_TRUE               1
#define G723_FALSE              0
#define G723_SUCCESS            0
#define G723_FAILURE            1
#define G723_FAST_MEMORY        0
#define G723_SLOW_MEMORY        1

#define G723_MEM_TYPE           G723_FAST_MEMORY
#define G723_MEM_STATIC         0
#define G723_MEM_SCRATCH        1

#define G723_L_FRAME             240 /* DSPhl28122*/
#define CODED_FRAMESIZE          24
#define G723_MAX_NUM_MEM_REQS         10
#define G723_PRIORITY_LOWEST    255
#define G723_PRIORITY_NORMAL    128
#define G723_PRIORITY_HIGHEST   0

#define G723_WARNING_BASE      11
#define G723_RECOVERROR_BASE   31
#define G723_FATALERROR_BASE   51

typedef char                     G723_S8;
typedef unsigned char            G723_U8;

typedef short                    G723_S16;
typedef unsigned short           G723_U16;

typedef int                      G723_S32;
typedef unsigned int             G723_U32;

typedef void                     G723_Void;

#ifdef	NULL
#undef	NULL
#define NULL	(G723_Void *)0
#endif

#define	G723_NULL NULL

#ifdef __SYMBIAN32__
#define EXPORT_C __declspec(dllexport)
#define EXTERN
#else
#define EXTERN
#define EXPORT_C
#endif

/******************************* <END OF FILE> ********************************/
#endif
