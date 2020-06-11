

/******************************************************************************
 *
 *   MOTOROLA CONFIDENTIAL PROPRIETARY
 *
 *
 *   (C) 2004 MOTOROLA INDIA ELECTRONICS PVT. LTD.
 *
 *   FILENAME        - gif_dec_interface.h
 *   ORIGINAL AUTHOR - M.Intiyas Pasha
 *
 *******************************************************************************
 *
 *   CHANGE HISTORY
 *   dd/mm/yy        Code Ver      Description                 Author
 *   --------        --------      -----------                 ------
 *   27/06/2004      0.1            Initial version            M.Intiyas Pasha
 *   19/12/2004      0.2            Modified version           Sameer P.Rapate
 *   17/11/2008      0.3            ENGR00099100: add BGR format		Eagle Zhou
 *******************************************************************************
 *
 *   DESCRIPTION
 *   Header file for gif decoder interface.
 *****************************************************************************/
/************************************************************************
* Copyright 2005-2010 by Freescale Semiconductor, Inc.
* All modifications are confidential and proprietary information
* of Freescale Semiconductor, Inc.
************************************************************************/

#ifndef __GIF_INTERFACE_H_
#define __GIF_INTERFACE_H_

#define TYPE_GIF        (0x474946)   /* 'GIF' */
#define TYPE_VER_87a	(0x383761)	 /* '87a' */
#define TYPE_VER_89a	(0x383961)	 /* '89a' */

#define			MAX_NUM_MEM_REQS 10
#define			TRUE			1
#define			FALSE			0


/*Success is assigned to 0. As of now there can be 20 warnings,
starting from 11 to 30. Recoverable errors can be 20, starting from 31 to 50.
Fatal errors can be 20, starting from 51 to 70. Later more error types can be added */

#define GIFD_NUM_WARNING 20
#define GIFD_NUM_RECOVERROR 20
#define GIFD_WARNING_BASE 11
#define GIFD_RECOVERROR_BASE (GIFD_NUM_WARNING+GIFD_WARNING_BASE)
#define GIFD_FATALERROR_BASE (GIFD_RECOVERROR_BASE+GIFD_NUM_RECOVERROR)


typedef			int		 			GIF_INT32;
typedef 		unsigned int 		GIF_UINT32;
typedef			char				GIF_INT8;
typedef			unsigned char		GIF_UINT8;
typedef			short				GIF_INT16;
typedef			unsigned short		GIF_UINT16;




/*Various types of errors in
enumerated data types*/
typedef enum
{
    GIF_ERR_NO_ERROR,
    GIF_ERR_DECODING_COMPLETE,

	/*Warnings start from here*/
    GIFD_SUSPEND = GIFD_WARNING_BASE,
	GIF_ERR_TERMINATOR_REACHED,
   /* Recoverable error types start from here */
   /* Fatal error types start from here*/
    GIF_ERR_ERROR=GIFD_FATALERROR_BASE,
    GIF_ERR_NO_ARRAY,
    GIF_ERR_IO_ERROR,
    GIF_ERR_NO_MEMORY,
    GIF_ERR_EOF ,
    GIF_ERR_UNSUPPORTED_TYPE,
	GIF_ERR_INVALID_SIG_OR_VER,
	GIF_ERR_INVALID_GLOBAL_HEIGHT,
	GIF_ERR_INVALID_GLOBAL_WIDTH,
	GIF_ERR_ZERO_BLOCK_LENGTH,
	GIF_INVALID_MIN_CODE_SIZE,
	GIFD_INVALID_BLK_SIZE
}GIFD_RET_TYPE;


/*Types of output formats*/
typedef enum
{
    E_GIF_OUTPUTFORMAT_RGB888,
    E_GIF_OUTPUTFORMAT_RGB565,
    E_GIF_OUTPUTFORMAT_RGB555,
    E_GIF_OUTPUTFORMAT_RGB666,
    E_GIF_OUTPUTFORMAT_BGR888,
    E_GIF_OUTPUTFORMAT_BGR565,
    E_GIF_OUTPUTFORMAT_BGR555,
    E_GIF_OUTPUTFORMAT_BGR666,
    E_GIF_LAST_OUTPUT_FORMAT
}gif_output_format;


/*Indicates whether scaling of output image is required or not*/
typedef enum
{
	E_GIF_NO_SCALE,
	E_GIF_INT_SCALE_PRESERVE_AR,
	E_GIF_LAST_SCALE_MODE
} gif_scaling_mode;


/*Bitcount in enumerated data types*/
typedef enum
{
    GIF_E_BIT_COUNT_1  = 1,
    GIF_E_BIT_COUNT_2  = 2,
	GIF_E_BIT_COUNT_3  = 3,
    GIF_E_BIT_COUNT_4  = 4,
    GIF_E_BIT_COUNT_5  = 5,
    GIF_E_BIT_COUNT_6  = 6,
    GIF_E_BIT_COUNT_7  = 7,
    GIF_E_BIT_COUNT_8 =  8
}gif_bit_count;


/*Indicates the type of memory used*/
typedef enum
{
    GIF_E_FAST_MEMORY,
    GIF_E_SLOW_MEMORY
}GIF_Mem_type;


/*Memory allocation information*/
typedef struct
{
    GIF_INT32	     size;
    GIF_Mem_type type;
    GIF_INT32	     align;
    void	     *ptr;
} GIF_Mem_Alloc_Info_Sub;


/*Memory allocation and number of memory requests*/
typedef struct
{
    GIF_INT32			    	num_reqs;
	GIF_Mem_Alloc_Info_Sub 	mem_info_sub[MAX_NUM_MEM_REQS];
} GIF_Mem_Alloc_Info;


/*GIF decoder parameters for the output format,scaling,width and height*/
typedef struct
{
    gif_output_format out_format;
    gif_scaling_mode  scale_mode;
    GIF_UINT16        output_width;
    GIF_UINT16        output_height;
} GIF_Decoder_Params;

/*Not sure about various fields used in this structure variable*/
typedef struct
{
	/*Global Fields*/
	GIF_INT16 globwidth;		/*Width of the global screen*/
	GIF_INT16 globheight;		/*Height of the global screen*/
	GIF_INT16 glob_out_width;		/*Width of the global screen*/
	GIF_INT16 glob_out_height;		/*Height of the global screen*/

	GIF_UINT8 globpixbits;		/*Number of bits per pixel in global table*/
	GIF_UINT8 globbc;			/*Back ground color*/
	GIF_UINT8 globaspect;		/*Pixel aspect ratio*/
	GIF_UINT8 glob_color_tbl_size;/*2 power N+1 gives entries in color table*/
	GIF_UINT8 glob_color_tbl_sort_flag;/*Color table Sort Flag*/
	GIF_UINT8 glob_bpp;			  /*Bits per pixel minus 1*/
	GIF_UINT8 glob_color_tbl_flag;/*Set if Global color table is present*/

	/*Local Fields*/
	GIF_INT16 image_left;		/*Left offset of Image within logical screen*/
	GIF_INT16 image_top;		/*Top offset of Image within logical screen*/
	GIF_INT16 scaled_image_left;/*Scaled left offset of Image within logical screen*/
	GIF_INT16 scaled_image_top; /*Scaled top offset of Image within logical screen*/
	GIF_INT16 image_width;		/*Input Image width*/
	GIF_INT16 image_height;		/*Input Image height*/
	GIF_INT16 out_image_width;	/*Output Image width*/
	GIF_INT16 out_image_height;	/*Output Image height*/
	GIF_UINT8 image_pixbits;	/*Local color table size*/
	GIF_UINT8 interlace;		/*No Interlace - 0 and Interlaced - 1*/
	GIF_UINT8 local_color_table_flag;/*Indicator for local color table flag presence*/


	GIF_UINT8 trans_color_flag;     /*Flag to indicate the  usage  of
									transparency color index*/
	GIF_UINT8 user_input_flag;      /*User input flag*/
	GIF_UINT8 disposal_method; 		/*Disposal Method*/
	GIF_UINT16 delay_time;			/*Delay Time*/
	GIF_UINT16 trans_color_index;	/*Transparency Color index*/
	GIF_INT16  loop_count;			/*Number of times animation should repeat.
									  Present in application extension block*/
	GIF_INT32 pass;					/*Pass*/
	GIF_UINT32 pix_count;			/*Pixel count*/
}GIF_Decoder_Info_Init;


//GIF decoder object
typedef struct GIF_Decoder_Object
{
	GIF_Mem_Alloc_Info	 	mem_info;
	GIF_Decoder_Params		dec_param;
	GIF_Decoder_Info_Init  	dec_info_init;
	GIFD_RET_TYPE (*GIF_get_new_data)(GIF_UINT8**,GIF_UINT32 *,struct GIF_Decoder_Object *);
	void           			*vptr;
	GIF_INT32				number_of_frames;
	GIF_INT32				bytes_read_in_a_frame;
} GIF_Decoder_Object;


typedef void (*GIF_FPOutputformat)(GIF_INT32*, GIF_UINT8*, GIF_INT32);
extern  GIF_FPOutputformat gif_arrayFPOutputformat[E_GIF_LAST_OUTPUT_FORMAT];
typedef void (*GIF_FPOutputformatMerge)(unsigned char *pixels_data, unsigned char* color_table,GIF_INT16 tranparent_index,GIF_UINT8 *outbuff, GIF_INT16 image_width);
extern  GIF_FPOutputformatMerge gif_arrayFPOutputformat_merge[E_GIF_LAST_OUTPUT_FORMAT];

#ifdef __SYMBIAN32__
#define EXPORT_C __declspec(dllexport)
#else
#define EXPORT_C
#endif
#ifdef __cplusplus
extern "C"
{
#endif
// Function prototypes for memory query,initialization and decoding
 GIFD_RET_TYPE GIF_query_dec_mem (GIF_Decoder_Object *);
 GIFD_RET_TYPE GIF_decoder_init (GIF_Decoder_Object *);
 GIFD_RET_TYPE GIF_decode(GIF_Decoder_Object *,unsigned char *);

 GIFD_RET_TYPE GIF_query_dec_mem_frame (GIF_Decoder_Object *);
 GIFD_RET_TYPE GIF_decoder_init_frame (GIF_Decoder_Object *);

 void GIF_Convert_RGB565(GIF_INT32 *pixels, GIF_UINT8 *outbuff, GIF_INT32 output_image_width);
 void GIF_Convert_RGB888(GIF_INT32 *pixels, GIF_UINT8 *outbuff, GIF_INT32 output_image_width);
 void GIF_Convert_RGB555(GIF_INT32 *pixels, GIF_UINT8 *outbuff, GIF_INT32 output_image_width);
 void GIF_Convert_RGB666(GIF_INT32 *pixels, GIF_UINT8 *outbuff, GIF_INT32 output_image_width);

 void GIF_Convert_BGR565(GIF_INT32 *pixels, GIF_UINT8 *outbuff, GIF_INT32 output_image_width);
 void GIF_Convert_BGR888(GIF_INT32 *pixels, GIF_UINT8 *outbuff, GIF_INT32 output_image_width);
 void GIF_Convert_BGR555(GIF_INT32 *pixels, GIF_UINT8 *outbuff, GIF_INT32 output_image_width);
 void GIF_Convert_BGR666(GIF_INT32 *pixels, GIF_UINT8 *outbuff, GIF_INT32 output_image_width);

 void GIF_Merge_RGB565(unsigned char *pixels_data, unsigned char* color_table,GIF_INT16 tranparent_index,GIF_UINT8 *outbuff, GIF_INT16 image_width);
 void GIF_Merge_RGB888(unsigned char *pixels_data, unsigned char* color_table,GIF_INT16 tranparent_index,GIF_UINT8 *outbuff, GIF_INT16 image_width);
 void GIF_Merge_RGB555(unsigned char *pixels_data, unsigned char* color_table,GIF_INT16 tranparent_index,GIF_UINT8 *outbuff, GIF_INT16 image_width);
 void GIF_Merge_RGB666(unsigned char *pixels_data, unsigned char* color_table,GIF_INT16 tranparent_index,GIF_UINT8 *outbuff, GIF_INT16 image_width);

 void GIF_Merge_BGR565(unsigned char *pixels_data, unsigned char* color_table,GIF_INT16 tranparent_index,GIF_UINT8 *outbuff, GIF_INT16 image_width);
 void GIF_Merge_BGR888(unsigned char *pixels_data, unsigned char* color_table,GIF_INT16 tranparent_index,GIF_UINT8 *outbuff, GIF_INT16 image_width);
 void GIF_Merge_BGR555(unsigned char *pixels_data, unsigned char* color_table,GIF_INT16 tranparent_index,GIF_UINT8 *outbuff, GIF_INT16 image_width);
 void GIF_Merge_BGR666(unsigned char *pixels_data, unsigned char* color_table,GIF_INT16 tranparent_index,GIF_UINT8 *outbuff, GIF_INT16 image_width);


/*query lib version*/
const char *  GIFD_CodecVersionInfo(void);

//Callback Function Prototype
 GIFD_RET_TYPE GIF_get_new_data (GIF_UINT8 **, GIF_UINT32 *,GIF_Decoder_Object * );
#ifdef __cplusplus
}
#endif
#endif

/**********************End of File*************************/
