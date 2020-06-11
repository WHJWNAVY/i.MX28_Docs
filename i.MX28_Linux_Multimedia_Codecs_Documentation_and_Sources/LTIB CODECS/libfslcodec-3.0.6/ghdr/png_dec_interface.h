/******************************************************************************
 ***********************************************************************
 *
 *   MOTOROLA CONFIDENTIAL PROPRIETARY
 *
 *
 *   (C) 2004 MOTOROLA INDIA ELECTRONICS PVT. LTD.
 *
 *   FILENAME        - png_dec_interface.h
 *   ORIGINAL AUTHOR - Sameer P.Rapate
 *
 *******************************************************************************
 * Copyright 2005-2010 by Freescale Semiconductor, Inc.
 * All modifications are confidential and proprietary information
 * of Freescale Semiconductor, Inc.
 ***********************************************************************
 *
 *   CHANGE HISTORY
 *   dd/mm/yy        Code Ver      Description                    Author
 *   --------        --------      -----------                    ------
 *   12/10/2004      0.1            Initial version             Sameer P.Rapate
 *   05/12/2006      0.2            Added two more enums        Durgaprasad S.Bilagi
 *                                  for grayscale with &
 *                                  without alpha output formats
 *   10/12/2008      0.3            ENGR00102074: add BGR support    Eagle Zhou
 *   05/10/2010                     engr123203: add png_type.h      Lyon Wang
 *******************************************************************************
 *
 *   DESCRIPTION
 *   Header file for png decoder interface.
 *****************************************************************************/

#ifndef __PNG_INTERFACE_H
#define __PNG_INTERFACE_H

#include "png_type.h"
/*
 Success is assigned to 0.
 As of now there can be 20 warnings, starting from 11 to 30.
 Recoverable errors can be 20, starting from 31 to 50.
 Fatal errors can be 20, starting from 51 to 70.
 Later more error types can be added
*/

#define PNGD_NUM_WARNING 20
#define PNGD_NUM_RECOVERROR 20
#define PNGD_WARNING_BASE 11
#define PNGD_RECOVERROR_BASE (PNGD_NUM_WARNING+PNGD_WARNING_BASE)
#define PNGD_FATALERROR_BASE (PNGD_RECOVERROR_BASE+PNGD_NUM_RECOVERROR)

typedef enum
{
     PNGD_OK,
     PNG_ERR_DECODING_COMPLETE,

     /* Warnings start from here*/
     PNGD_DUPLICATE_CHUNK = PNGD_WARNING_BASE,
     PNGD_INCORRECT_CHUNK_LENGTH,
     PNGD_TRUNC_INCORRECT_CHUNK_LENGTH,
     PNGD_OUT_OF_PLACE_CHUNK,
     PNGD_ZERO_LENGTH_CHUNK,
     PNGD_UNKNOWN_COMPR_TYPE,
     PNGD_MNG_NOT_SUPPORTED,
     PNGD_IGNORING_BAD_FILTER_TYPE,
     PNGD_INVALID_CHUNK_AFTER_IDAT,
     PNGD_TRNSCHUNK_NOT_ALLOWED_WITH_ALPHA,
     PNGD_ERR_SUSPEND,

    /* Recoverable error types start from here */
     PNGD_ERR_EOF = PNGD_RECOVERROR_BASE,

    /* Fatal error types start from here*/
     PNGD_ERR_UNSUPPORTED_TYPE = PNGD_FATALERROR_BASE,
     PNGD_ERR_NO_MEMORY,
     PNGD_ERR_IO_ERROR,
     PNGD_DECODE_ROW_ERROR,
     PNGD_DEC_ERR_INIT,
     PNGD_INVALID_BIT_DEPTH,
     PNGD_INVALID_COLOR_TYPE,
     PNGD_INVALID_IMAGE_WIDTH,
     PNGD_INVALID_IMAGE_HEIGHT,
     PNGD_MISSING_IHDR_BEFORE_IDAT,
     PNGD_MISSING_PLTE_BEFORE_IDAT,
     PNGD_DECOMPRESSION_ERROR,
     PNGD_EXTRA_COMPRESSED_DATA,
     PNGD_16_BIT_NOT_SUPPORTED,
     PNGD_RD_END_ERROR,
     PNGD_LIB_ERR,
     PNG_DEC_INVALID_OUTFORMAT

} PNGD_RET_TYPE;

//dsphl28117
//Types of output formats
typedef enum
{
    E_PNG_OUTPUTFORMAT_RGB888,
    E_PNG_OUTPUTFORMAT_RGB565,
    E_PNG_OUTPUTFORMAT_RGB555,
    E_PNG_OUTPUTFORMAT_RGB666,
    E_PNG_OUTPUTFORMAT_BGR888,
    E_PNG_OUTPUTFORMAT_BGR565,
    E_PNG_OUTPUTFORMAT_BGR555,
    E_PNG_OUTPUTFORMAT_BGR666,
    E_PNG_OUTPUTFORMAT_ARGB,
    E_PNG_OUTPUTFORMAT_BGRA,
    E_PNG_OUTPUTFORMAT_AG,
    E_PNG_OUTPUTFORMAT_G,
    E_PNG_LAST_OUTPUT_FORMAT

}png_output_format;


/*typedef struct
{
   PNG_INT8 red;
   PNG_INT8 green;
   PNG_INT8 blue;
} Color_table;*/


typedef struct
{
    PNG_UINT32 width;
    PNG_UINT32 height;
    PNG_UINT32 output_width;
    PNG_UINT32 output_height;
    PNG_UINT32 rowbytes;
    PNG_UINT8 channels_orig;
	PNG_UINT8 channels_after_transform;
    PNG_UINT8 number_passes;
    PNG_UINT16 num_palette;
    PNG_UINT16 num_trans;
    PNG_UINT32 bit_depth;
    PNG_UINT32 color_type;
    PNG_UINT32 interlace_type;
    PNG_UINT8 pixel_depth;
	PNG_UINT32 scaling_factor;
	PNG_UINT8 pass;


	PNG_INT32 compression_type;
    PNG_INT32 filter_method;
    PNG_UINT8 compression_level;
	//Color_table palette[256];
	//PNG_UINT16 histogram_info[65536];
    PNG_UINT8 srgb_info;
    PNG_UINT32 image_gamma;
    Background_Info bkgd_info;
    Trans_Info_Rgb_And_Gray trans_rgb_gray;
    Trans_Info_Indexed trans_indexed;
    Significant_Bits_Info sig_bits;
    Chromaticity_Info chrm_info;
    Phy_Dimension_Info phy_dim_info;
}PNG_Decoder_Info_Init;

//dsphl28117
typedef struct
{
    png_output_format 	outformat;
    png_scaling_mode	scale_mode;
    PNG_UINT16  		output_width;
    PNG_UINT16  		output_height;
} PNG_Decoder_Params;

typedef struct{
    PNG_Decoder_Info_Init dec_info_init;
    PNG_Decoder_Params dec_param;
    void *png_ptr;
    void *info_ptr;
	void *end_info_ptr;
	PNG_INT32 *pixels;
	PNG_UINT8 *row_buf;
	PNG_UINT8 *out_interlaced_buf;

	void *pAppContext; /* application data */ //DSPhl27779

	PNGD_RET_TYPE (*PNG_app_read_data)(void *, PNG_UINT8*,
                             PNG_UINT32, PNG_UINT32, void *); //DSPhl27779

    void * (*PNG_app_malloc)(void *, PNG_UINT32, void *); //DSPhl27779
    void (*PNG_app_free)(void *,  void *); //DSPhl27779
	PNG_UINT32    rows_decoded;
} PNG_Decoder_Object;

typedef void (*PNG_FPOutputformat)(PNG_INT32*, PNG_UINT8*, PNG_INT32);    //DSPhl28074
//dsphl28117
#ifdef __SYMBIAN32__
#define EXTERN
#define EXPORT_C __declspec(dllexport)
#else
#define EXTERN
#define EXPORT_C
#endif

extern PNG_FPOutputformat png_arrayFPOutputformat[E_PNG_LAST_OUTPUT_FORMAT];  //DSPhl28074

#ifdef __cplusplus
extern "C"
{
#endif
 PNGD_RET_TYPE PNG_dec_init(PNG_Decoder_Object *png_dec_object);
 PNGD_RET_TYPE PNG_decode_row(PNG_Decoder_Object *png_dec_object, PNG_UINT8 *outbuf);
 PNGD_RET_TYPE PNG_decode_frame(PNG_Decoder_Object *png_dec_object, PNG_UINT8 *outbuf);
 PNGD_RET_TYPE PNG_cleanup(PNG_Decoder_Object *png_dec_object);


 void PNG_Convert_RGB565(PNG_INT32 *pixels, PNG_UINT8 *outbuff, PNG_INT32 output_image_width);
 void PNG_Convert_RGB888(PNG_INT32 *pixels, PNG_UINT8 *outbuff, PNG_INT32 output_image_width);
 void PNG_Convert_RGB555(PNG_INT32 *pixels, PNG_UINT8 *outbuff, PNG_INT32 output_image_width);
 void PNG_Convert_RGB666(PNG_INT32 *pixels, PNG_UINT8 *outbuff, PNG_INT32 output_image_width);
 void PNG_Convert_ARGB(PNG_INT32 *pixels, PNG_UINT8 *outbuff, PNG_INT32 output_image_width);

 void PNG_Convert_BGR565(PNG_INT32 *pixels, PNG_UINT8 *outbuff, PNG_INT32 output_image_width);
 void PNG_Convert_BGR888(PNG_INT32 *pixels, PNG_UINT8 *outbuff, PNG_INT32 output_image_width);
 void PNG_Convert_BGR555(PNG_INT32 *pixels, PNG_UINT8 *outbuff, PNG_INT32 output_image_width);
 void PNG_Convert_BGR666(PNG_INT32 *pixels, PNG_UINT8 *outbuff, PNG_INT32 output_image_width);
 void PNG_Convert_BGRA(PNG_INT32 *pixels, PNG_UINT8 *outbuff, PNG_INT32 output_image_width);

 void * PNG_app_malloc(void *ptr, PNG_UINT32 size,  void *pAppContext); //DSPhl27779
 void PNG_app_free(void *ptr,  void *pAppContext); //DSPhl27779
 PNGD_RET_TYPE PNG_app_read_data(void *input_ptr, PNG_UINT8 *input_data,
								PNG_UINT32 length_requested, PNG_UINT32 length_returned,  void *pAppContext); //DSPhl27779
/*query lib version*/
const char *  PNGD_CodecVersionInfo(void);
#ifdef __cplusplus
}
#endif

#endif

