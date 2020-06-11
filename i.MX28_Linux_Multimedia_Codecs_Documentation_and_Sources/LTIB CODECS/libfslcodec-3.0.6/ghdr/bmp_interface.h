

/******************************************************************************
 *
 *   MOTOROLA CONFIDENTIAL PROPRIETARY
 *
 *
 *   (C) 2004 MOTOROLA INDIA ELECTRONICS PVT. LTD.
 *
 *   FILENAME        - bmp_interface.h
 *   ORIGINAL AUTHOR - Rajesh Gupta
 *
 *******************************************************************************
 *
 *   CHANGE HISTORY
 *   dd/mm/yy        Code Ver      Description                 Author
 *   --------        --------      -----------                 ------
 *   10/03/2004      0.1            Initial version             Rajesh Gupta
 *   17/04/2008      0.2            add 32 bit color          Eagle Zhou : related CRs:ENGR00073179
 *******************************************************************************
 *
 *   DESCRIPTION
 *   Header file for bmp interface.
 *****************************************************************************/
/************************************************************************
* Copyright 2005-2010 by Freescale Semiconductor, Inc.
* All modifications are confidential and proprietary information
* of Freescale Semiconductor, Inc.
************************************************************************/

#ifndef  __BMP_INTERFACE_H
#define  __BMP_INTERFACE_H

#define BMP_MAX_NUM_MEM_REQS 5

#define BMP_NUM_WARNING 20
#define BMP_NUM_RECOVERROR 20
#define BMP_WARNING_BASE 11
#define BMP_RECOVERROR_BASE (BMP_NUM_WARNING+BMP_WARNING_BASE)
#define BMP_FATALERROR_BASE (BMP_RECOVERROR_BASE+BMP_NUM_RECOVERROR)



typedef		unsigned long		BMP_UINT32;
typedef	 	long			    BMP_INT32;
typedef		unsigned short 		BMP_UINT16;
typedef		short			    BMP_INT16;
typedef		unsigned char		BMP_UINT8;
typedef 	char			    BMP_INT8;


typedef enum
{
    BMP_ERR_NO_ERROR,
	BMP_ERR_DECODING_COMPLETE,

	/*Warnings start from here*/
	BMP_ERR_SUSPEND=BMP_WARNING_BASE,

   /*Recoverable errors start from here*/
    BMP_ERR_EOF=BMP_RECOVERROR_BASE,

	/*Fatal errors start from here*/

	BMP_ERR_ERROR=BMP_FATALERROR_BASE,
    BMP_ERR_NO_ARRAY,
    BMP_ERR_IO_ERROR,
    BMP_ERR_NO_MEMORY,
    BMP_ERR_UNSUPPORTED_TYPE,
    BMP_ERR_CORRUPTED_FORMAT,
	BMP_32BIT_NOT_SUPPORTED,
	BMP_INVALID_BPP,
	BMP_INVALID_COMPRESSION_SCHEME,
	BMP_INVALID_ORIGIN,
	BMP_INCORRECT_COLOR_ENCODING,
	BMP_INVALID_WIDTH,
	BMP_INVALID_HEIGHT

}BMP_error_type;

typedef enum
{
    BMP_SEEK_FILE_START,
    BMP_SEEK_FILE_CURR_POSITION
}BMP_Seek_File_Position;

typedef enum
{
    E_BMP_OUTPUTFORMAT_RGB888,
    E_BMP_OUTPUTFORMAT_RGB565,
	E_BMP_OUTPUTFORMAT_RGB555,
	E_BMP_OUTPUTFORMAT_RGB666,
    E_BMP_LAST_OUTPUT_FORMAT
}bmp_output_format;

typedef enum
{
    E_BMP_BIT_COUNT_1  = 1,
    E_BMP_BIT_COUNT_4  = 4,
    E_BMP_BIT_COUNT_8  = 8,
    E_BMP_BIT_COUNT_16 = 16,
    E_BMP_BIT_COUNT_24 = 24,
    E_BMP_BIT_COUNT_32 = 32,
}bit_bmp_count;

typedef enum
{
    E_BMP_RGB   = 0,
    E_BMP_RLE8  = 1,
    E_BMP_RLE4  = 2
}bmp_compression_type;

typedef enum
{
    E_BMP_NO_SCALE,               /* No software scaling */
    E_BMP_INT_SCALE_PRESERVE_AR,  /* Software scaling using integer scaling
                                 factor preserving pixel aspect ratio */
    E_BMP_LAST_SCALE_MODE
} bmp_scaling_mode;

typedef enum
{
    E_BMP_FAST_MEMORY,
    E_BMP_SLOW_MEMORY
}BMP_DEC_Mem_type;

typedef struct
{
    BMP_INT32	     size;		 /* Size in bytes */
    BMP_DEC_Mem_type type;		 /* Memory type Fast or Slow */
    BMP_INT32	     align;		 /* Alignment of memory in bytes */
    void	     *ptr;		 /* Pointer to the memory */
} BMP_Mem_Alloc_Info_Sub;


typedef struct
{
    BMP_INT32			    	num_reqs;
    BMP_Mem_Alloc_Info_Sub 	mem_info_sub[BMP_MAX_NUM_MEM_REQS ];
} BMP_Mem_Alloc_Info;

typedef struct
{
    bmp_output_format out_format;
    bmp_scaling_mode  scale_mode;
    BMP_UINT16        output_width;
    BMP_UINT16        output_height;
} BMP_Decoder_Params;

typedef struct
{
    BMP_UINT16  	     image_width;      /* Input Image width */
#if 1 //eagle
    BMP_INT16  	     image_height;     /* Input Image height */
#else
    BMP_UINT16  	     image_height;     /* Input Image height */
#endif
    BMP_UINT16           output_width;     /* width of rendered output  */
    BMP_UINT16           output_height;    /* height of rendered output */
    bit_bmp_count        bit_cnt;          /* Bits per pixel ? 1, 4, 8, 16, or 24 */
    bmp_compression_type cmpr_type;        /* RGB, RLE4, RLE8 etc */
    BMP_UINT32           file_size;        /* BMP file size in bytes */
    BMP_UINT16           BMP_components;   /* Number of components in the BMP */
    BMP_UINT16           output_components;/* Number of components rendered output */
} BMP_Decoder_Info_Init;


typedef struct BMP_Decoder_Object {
	BMP_Mem_Alloc_Info   	mem_info;
	BMP_Decoder_Params	    dec_param;
	BMP_Decoder_Info_Init  	dec_info_init;
    BMP_UINT32                  rows_decoded;
	BMP_INT32					num_byte_read_in_row;
	BMP_error_type (*BMP_get_new_data)
		(BMP_UINT8 **new_buf_ptr, BMP_UINT32 *new_buf_len, struct BMP_Decoder_Object *dec_object);
	BMP_error_type (*BMP_seek_file)
		(struct BMP_Decoder_Object *dec_object, BMP_INT32 num_bytes, BMP_Seek_File_Position start_or_current);
    void                    *vptr;
} BMP_Decoder_Object;


typedef void (*FPBmpOutputformat)(BMP_INT32*, BMP_UINT8*, BMP_INT32);
extern FPBmpOutputformat arrayFPBmpOutputformat[E_BMP_LAST_OUTPUT_FORMAT];

/* Function prototypes */
/* Refer to API doc for detail */
#ifdef __SYMBIAN32__
#define EXPORT_C __declspec(dllexport)
#else
#define EXPORT_C
#endif

 #ifdef __cplusplus
extern "C"
{
#endif
 BMP_error_type BMP_query_dec_mem (BMP_Decoder_Object *);
 BMP_error_type BMP_decoder_init (BMP_Decoder_Object *);
 BMP_error_type BMP_decode_row_pp(BMP_Decoder_Object *dec_obj, BMP_UINT8 *output_buf);
 BMP_error_type BMP_get_new_data (BMP_UINT8 **new_buf_ptr, BMP_UINT32 *new_buf_len, BMP_Decoder_Object *);
 BMP_error_type BMP_seek_file(BMP_Decoder_Object *, BMP_INT32 num_bytes, BMP_Seek_File_Position start_or_current);
 void BMP_Convert_RGB565(BMP_INT32 *pixels, BMP_UINT8 *outbuff, BMP_INT32 output_image_width);
 void BMP_Convert_RGB888(BMP_INT32 *pixels, BMP_UINT8 *outbuff, BMP_INT32 output_image_width);
 void BMP_Convert_RGB555(BMP_INT32 *pixels, BMP_UINT8 *outbuff, BMP_INT32 output_image_width);
 void BMP_Convert_RGB666(BMP_INT32 *pixels, BMP_UINT8 *outbuff, BMP_INT32 output_image_width);
#ifdef __cplusplus
}
#endif
#endif
