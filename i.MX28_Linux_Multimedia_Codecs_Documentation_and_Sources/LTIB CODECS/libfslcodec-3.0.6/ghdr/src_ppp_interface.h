/*
 ***************************************************************************
 * Copyright 2007-2009 by Freescale Semiconductor, Inc.
 * All modifications are confidential and proprietary information
 * of Freescale Semiconductor, Inc. ALL RIGHTS RESERVED.
 ***************************************************************************
 ****************************************************************************
 * ANSI C source code
 *
 * Project Name : Sample rate convertor ppp
 * File Name      : src_ppp_interface.h
 *
 * FREESCALE CONFIDENTIAL PROPRIETARY
 ***************************************************************************/
 /***************************************************************************
 *
 *   (C) 2009 FREESCALE SEMICONDUCTOR.
 *
 *   CHANGE HISTORY
 *    dd/mm/yy        Code Ver      CR          Author        Description      
 *    --------        -------      -------      ------     ----------- 
 *   05/03/2009       0.1     	     eng          Yaoming.Qin    created file   
 **************************************************************************/

 #ifndef SRC_PPP_INTERFACE_H
 #define SRC_PPP_INTERFACE_H


typedef int                        SRC_I32;
typedef unsigned int               SRC_U32; 
typedef signed short               SRC_I16;
typedef unsigned short             SRC_U16;
typedef signed char                SRC_I8;
typedef unsigned char              SRC_U8;
typedef unsigned int               SRC_BOOL;
typedef void                       SRC_VOID;
#if defined  WIN32 || defined UNDER_CE   
typedef __int64                    SRC_I64;  
#else
typedef long long int              SRC_I64;
#endif


/* Define NULL pointer value*/
#ifndef NULL
#ifdef  __cplusplus
#define NULL    0
#else
#define NULL    ((SRC_VOID *)0)
#endif
#endif

#ifndef TRUE
#define TRUE 1
#endif /* !defined(TRUE) */

#ifndef FALSE
#define FALSE 0
#endif /* !defined(FALSE) */


/* Error types */
typedef enum {
	/* Sucess */
 SRC_OK = 0,                             /* Success,no error */
   /* parameter error */
 SRC_ERROR_CHN_NUMBER=31,
 SRC_ERROR_INPUT_SAMPLERATE,
 SRC_ERROR_OUTPUT_SAMPLERATE,
 SRC_ERROR_INPUT_BITPERSAMPLE,
 SRC_ERROR_OUTPUT_BITPERSAMPLE,
 SRC_ERROR_INPUT_BLOCKSIZE,
 SRC_ERROR_BUFFER_ALLOCATE,
   /* internal error */
 SRC_ERROR_DSLINIT=41,
 SRC_ERROR_PREFILTER,	
 SRC_ERROR_DSLPROC,
 SRC_ERROR_POLYFILTER,
 SRC_ERROR_POSTFILTER,
 SRC_ERROR_OUTPUTPROC,
 SRC_ERROR_PASSTHROUGH,
 
 SRC_ERROR_INIT = 51,                    /* initialization error */
 SRC_ERROR_INVALID_PARAM = 52, 
 SRC_END_OF_STREAM                      /* end of bit stream */
    /*any other errors need to add*/
} SRC_RET_TYPE;


/*Memory type*/
#define SRC_FAST_MEMORY                  1
#define SRC_SLOW_MEMORY                  2

/*SRC parameters information*/
#define SRC_MAX_INPUT_CHANNELS           8
#define SRC_MAX_INPUT_SAMPLERATE         192000
#define SRC_MIN_INPUT_SAMPLERATE         8000
#define SRC_MAX_OUTPUT_SAMPLERATE        192000
#define SRC_MIN_OUTPUT_SAMPLERATE        8000

#define SRC_BITSPERSAMPLE_8BIT           8 
#define SRC_BITSPERSAMPLE_16BIT          16
#define SRC_BITSPERSAMPLE_24BIT          24

/*SRC config*/
#define SRC_MAX_INPUT_BLOCKSIZE          128
#define SRC_MIN_INPUT_BLOCKSIZE          32 
#define SRC_INPUT_BLOCKSIZE              128
#define SRC_DATA_ALIGN_IN_BYTES          4
#define SRC_MAX_NUM_MEM_REQS             10



typedef struct {
	SRC_I32		 src_size;                                    /* Size in bytes */
	SRC_I32 	 src_type;	                              /* Memory type Fast or Slow */
	SRC_VOID         *app_base_ptr;                               /* Pointer to the base memory , which will be allocated by the  application */
} SRC_Mem_Alloc_Info_Sub;


typedef struct {
	SRC_I16          src_num_reqs;
	SRC_Mem_Alloc_Info_Sub 	mem_info_sub [SRC_MAX_NUM_MEM_REQS];
} SRC_Mem_Alloc_Info;


typedef struct Src_Config_Struct{

       SRC_Mem_Alloc_Info src_mem_info;
       SRC_VOID           * pSrcInfoStruct;
       SRC_I32            InputBlockSize;                            /* the number of the sample per channel in  input buffer */
       SRC_I32            nOutputBufferSize;                         /* inform the app the size of the buffer that should be allocated */
       SRC_I32            OutputByteNum;                             /*  the number of the bytes the SRC module produce  */
  
}Src_Config;

typedef struct Src_Params_struct{

	SRC_I32   nSampleRate_in;
        SRC_I32   nSampleRate_out;
	SRC_I32   nChannels;
	SRC_I32   wBitsPerSample_in;
	SRC_I32   wBitsPerSample_out;
	SRC_BOOL  Packed_24Bit_out;                                  /* for the 24 bit, the output should be packed or not,  the default is FALSE   */
	SRC_BOOL  FastSrcMode;                                       /* the fast src mode is faster but has lower performance, the default is FALSE */

}Src_Params;

#ifdef __cplusplus
#define EXTERN 
#else
#define EXTERN extern
#endif
#ifdef __SYMBIAN32__
#define EXPORT_C __declspec(dllexport)
#else
#define EXPORT_C
#endif
#ifdef __cplusplus
extern "C"
{
#endif 
 EXTERN const SRC_I8 *src_ppp_versionInfo(void);
 EXTERN SRC_RET_TYPE src_query_ppp_mem( Src_Config *pSrcConfig, Src_Params SrcParams); 
 EXTERN SRC_RET_TYPE src_ppp_init     ( Src_Config *pSrcConfig, Src_Params SrcParams);
 EXTERN SRC_RET_TYPE src_ppp_process  ( Src_Config *pSrcConfig,
                                        SRC_I32 *pInputBuffer, 
                                        SRC_I32 *pOutputBuffer                          
                                      );
#ifdef __cplusplus
}
#endif
#endif //SRC_PPP_INTERFACE_H


