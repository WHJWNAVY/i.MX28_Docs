/*
 ***********************************************************************
 * Copyright 2005-2008 by Freescale Semiconductor, Inc.
 * All modifications are confidential and proprietary information
 * of Freescale Semiconductor, Inc. ALL RIGHTS RESERVED.
 ***********************************************************************
 */
/*==================================================================================================

    Module Name:  sbc_api.h

    General Description: SBC encoder/decoder API
====================================================================================================


Revsion History:
                            Modification     Tracking
Author                          Date          Number     Description of Changes
-------------------------   ------------    ----------   -------------------------------------------
Dusan Veselinovic           08/01/2004                   Initial Creation
Tao   Jun                   21/03/2008      engr69557    change some datatype and delete <stdio.h>
Tao   Jun		      20/05/2008      engr76823   Added version API
==================================================================================================*/
#ifndef SBC_API_H
#define SBC_API_H
#include "sbc_typedefs.h"


#define SBC_ENABLE              0x01
#define SBC_INIT	            0x02
#define SBC_DISABLE             0x00

#define     SBC_MEM_STATIC      0
#define     SBC_MEM_SCRATCH     1
#define     SBC_FAST_MEMORY     0
#define     SBC_SLOW_MEMORY     1
#define     SBC_MAX_NUM_MEM_REQS	20
#define     SBC_PRIORITY_LOWEST  255
#define     SBC_PRIORITY_NORMAL  128
#define     SBC_PRIORITY_HIGHEST 0

struct sbc_data_struct{
	uint32 nrof_subbands;
    uint32 sampling_freq;
    uint32 nrof_blocks;
    uint32 channel_mode;
	uint32 allocation_method;
	uint32 bitpool;
	uint32 bitrate;
	uint32 super_frame_size;
	uint32 frame_size;
};

struct sbc_enc_input_struct{
     void  *input_frame_buf;
};

struct sbc_output_struct{
      struct sbc_data_struct *sbc_data;
      void 	*out_buffer;
      uint32	size;
      uint8	debug_info;
};
typedef struct
{
	int	 nSBCSize;	  /* Size in bytes */
	int  nSBCMemType;	  /* Memory is STATIC or SCRATCH */
	int  nSBCMemTypeFs; /* Memory type FAST or SLOW */
	void *pSBCBasePtr;
	char cSBCMemPriority; /* Priority level */

} sbc_mem_allocinfo_subtype;

typedef struct sbc_mem_info{
	int nNumMemReqs;
	sbc_mem_allocinfo_subtype sMemInfoSub[SBC_MAX_NUM_MEM_REQS];

}sbc_mem_info;

typedef struct tSbcEncConfig {
	uint8 sbc_enc_status;
	uint8 control_word;
	void *sbc_info;
	void *x;
	sbc_mem_info mem_info;
	struct sbc_data_struct *sbc_data;

}SbcEncConfig;


#ifdef __SYMBIAN32__
#define EXPORT_C __declspec(dllexport)
#else
#define EXPORT_C
#endif

#ifdef __cplusplus
extern "C"
{
#endif

SBC_RET_TYPE sbc_enc_query_mem(SbcEncConfig *sbc_enc_config);
SBC_RET_TYPE sbc_enc_init(SbcEncConfig *sbc_enc_config);


SBC_RET_TYPE sbc_encoder_encode(SbcEncConfig *sbc_enc_config,
								struct sbc_enc_input_struct	*sbc_input,
                           		struct sbc_output_struct *sbc_output);
const char *SBCEncVersionInfo(void);




#ifdef __cplusplus 
}
#endif



#if 0 /* Decoder specific- Not supported in the present release*/

struct sbc_dec_input_struct{
      uint8 *read_ptr;
      uint8 *write_ptr;
      uint8 *circ_buf_start;
      uint8 *circ_buf_end;
      void  *input_frame_buf;
      struct sbc_data_struct *sbc_data;
};

typedef struct tSbcDecConfig {
	uint8	sbc_dec_status;
	uint8 control_word;
	void *sbc_info;
	void *v;
	sbc_mem_info mem_info;
}SbcDecConfig;

SBC_RET_TYPE	sbc_dec_init(SbcDecConfig *sbc_dec_config);
SBC_RET_TYPE    sbc_dec_query_mem(SbcDecConfig *sbc_dec_config);

SBC_RET_TYPE sbc_decoder_decode(SbcDecConfig *sbc_dec_config, struct sbc_dec_input_struct *sbc_input,
                           struct sbc_output_struct *sbc_output);


#endif
#endif


