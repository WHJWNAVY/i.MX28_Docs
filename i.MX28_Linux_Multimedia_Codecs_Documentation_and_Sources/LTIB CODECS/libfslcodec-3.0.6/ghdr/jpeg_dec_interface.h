
/****************************************************************************
 *
 * (C) 2003 MOTOROLA INDIA ELECTRONICS LTD.
 *
 *   CHANGE HISTORY
 *   dd/mm/yy   Code Ver    Description                         Author
 *   --------   -------     -----------                         ------
 *   08/01/04   01          Created.                            B.Venkatarao
 *   16/01/04   02          API changes                         B.Venkatarao
 *   28/01/04   03          Error handling                      B.Venkatarao
 *   28/01/04   04          Removed unnecessary code from       B.Venkatarao
 *                          jdmaster.c
 *   29/01/04   05          Decoder instance-id is added to     B.Venkatarao
 *                          the interface of jpegd_get_new_data
 *   29/01/04   06          DCT scaling added.                  B.Venkatarao
 *   18/02/04   07          DCT scaling disabled and            B.Venkatarao
 *                          image down-scaling added.
 *   23/02/04   08          Handling for end of input added     B.Venkatarao
 *   27/02/04   09          Interface changes done.             B.Venkatarao
 *   20/03/04   10          output_pixel_size is changed        B.Venkatarao
 *                           to output_format and enum is
 *                           added
 *   22/03/04   11          API changes for giving output       B.Venkatarao
 *                           format same as encoded image
 *                           format
 *   10/04/04   12          Added JPEGD_UINT64 and JPEGD_INT64              B.Venkatarao
 *   10/04/04   13          Change stride var type              B.Venkatarao
 *   26/04/04   14          Enable dct_method option for        B.Venkatarao
 *                              TARGET also
 *   11/05/04   15          Review rework for API changes       B.Venkatarao
 *   01/06/04   16          Added TRUE and FALSE flags          B.Venkatarao
 *   16/11/04   17          Added support for suspension        B.Venkatarao
 *   11/12/04   18          API changes, structures modified    B.Venkatarao
 *   13/12/04   19          API changes for error types.        B.Venkatarao
 *                          For all error types defined in
 *                          jpeg_dec_interface.h, local types
 *                          are also defined to index into the
 *                          message table correctly.
 *   14/12/06   20          Added jpegd_get_file_info api.      Gauri Deshpande
 *                          Added exif related structures
 *                          Added new params: decoding_mode
 *                           and exif_info_needed
 *                          Added new initialisation params
 *                          Added new error codes
 *   27/12/04   21          Review rework for exif and          Gauri Deshpande
 *                           thumbnail
 *   07/01/05   22          Prefix all the data types, defines  B.Venkatarao
 *                           exposed to API. Also modified
 *                           mem_info structure
 ****************************************************************************/
	 
/************************************************************************
  * Copyright 2005-2010 by Freescale Semiconductor, Inc.
  * All modifications are confidential and proprietary information
  * of Freescale Semiconductor, Inc. 
  ************************************************************************/
/*
*******************************************************************************
*
*	File Description:	  Contains header info for decoder interface.
*
*	  DD/MMM/YYYY	  Code Ver			  Description				Author
*	  -----------	  --------		----------- 			         ------------
*	  30/July/08	        23	                  Add version query 			    Wang Zening
*       12/11/08            24                 add bgr format:ENGR00098581		Eagle Zhou 
*       02/03/09            25                 add frame api: ENGR00108642		Eagle Zhou 
*       14/05/09            26                 add VPU support: ENGR00112433	Eagle Zhou 
*******************************************************************************
*
*/

#ifndef JPEG_DEC_INTERFACE_H
#define JPEG_DEC_INTERFACE_H

#ifndef JPEGD_DEBUG_LEVEL
#define JPEGD_DEBUG_LEVEL 0x00
#endif

/* Defines needed for the application */
#define JPEGD_MAX_NUM_COMPS 4
#define JPEGD_MAX_NUM_MEM_REQS (5+1)

/* Return types for jpegd_get_new_data() */
enum
{
    JPEGD_SUCCESS = 0,
    JPEGD_END_OF_FILE,
    JPEGD_SUSPEND
};

/* Memory types */
enum
{
    JPEGD_FAST_MEMORY = 0,
    JPEGD_SLOW_MEMORY
};

enum
{
    JPEGD_STATIC_MEMORY = 0,
    JPEGD_SCRATCH_MEMORY,
    JPEGD_PHY_SUCCESSIVE_MEMORY,
};

/* Data types */
typedef unsigned char       JPEGD_UINT8;
typedef char                JPEGD_INT8;
typedef unsigned short      JPEGD_UINT16;
typedef short               JPEGD_INT16;
typedef unsigned long       JPEGD_UINT32;
typedef long                JPEGD_INT32;
#ifdef WIN32 //eagle: for windows debug version
typedef unsigned __int64  JPEGD_UINT64;
typedef __int64           JPEGD_INT64;
#else
typedef unsigned long long  JPEGD_UINT64;
typedef long long           JPEGD_INT64;
#endif

/* DCT/IDCT algorithm options. */
typedef enum
{
    JPEGD_IDCT_SLOW,     /* Slow but accurate integer algorithm */
    JPEGD_IDCT_FAST,     /* Faster, less accurate integer method */
    JPEGD_IDCT_FLOAT,     /* Floating-point: accurate, fast on fast HW,
                     *  not supported for TARGET
                     */
    JPEGD_IDCT_FIRST = JPEGD_IDCT_SLOW,
    JPEGD_IDCT_LAST = JPEGD_IDCT_FLOAT
} JPEGD_DCT_METHOD;

/* Output formats */
typedef enum
{
    JPEGD_OFMT_ENC_IMAGE_FMT,        /* Same as Encoded image format */
    JPEGD_OFMT_RGB_565,
    JPEGD_OFMT_RGB_888,              /* Default */
    JPEGD_OFMT_BGR_565,
    JPEGD_OFMT_BGR_888, 
    JPEGD_OFMT_FIRST = JPEGD_OFMT_ENC_IMAGE_FMT,
    JPEGD_OFMT_LAST = JPEGD_OFMT_BGR_888
} JPEGD_OUTPUT_FORMAT;

enum
{
    JPEGD_FILE_IS_JFIF = 0,
    JPEGD_FILE_IS_EXIF
};

// decoding modes
enum
{
    JPEGD_PRIMARY = 0,
    JPEGD_THUMBNAIL
};

enum
{
    JPEGD_EXIF_LITTLE_ENDIAN = 0,
    JPEGD_EXIF_BIG_ENDIAN,
    JPEGD_EXIF_ENDIAN_CORRUPT
};

typedef enum
{
    JPEGD_NO_THUMBNAIL = 0,
    JPEGD_THUMBNAIL_JPEG,
    JPEGD_THUMBNAIL_UNCOMPRESSED,
    JPEGD_THUMBNAIL_CORRUPT,
    JPEGD_THUMBNAIL_UNKNOWN,
} JPEGD_THUMBNAIL_TYPE;

/* Error types */
typedef enum
{
    /* Successfull return values */
    JPEGD_ERR_NO_ERROR = 0,

    /* Warnings
     *      The application can check the warnings and can continue
     *      decoding.
     */
    JPEGD_ERR_WARNINGS_START = 11,
    JPEGD_ERR_SUSPENDED = JPEGD_ERR_WARNINGS_START,
    JPEGD_ERR_WARNINGS_END,

    /* Recoverable errors
     *      These are the application errors. The application can
     *      correct the error and call the decoder again from the beginning
     */
    JPEGD_ERR_REC_ERRORS_START = 61,
    JPEGD_ERR_INVALID_DCT_METHOD = JPEGD_ERR_REC_ERRORS_START,
    JPEGD_ERR_INVALID_OUTPUT_FORMAT,
    JPEGD_ERR_INVALID_OUT_BUFFER_PTR,
    JPEGD_ERR_INVALID_OUT_STRIDE_WIDTH,
    JPEGD_ERR_MEM_NOT_INITIALIZED,
    JPEGD_ERR_MEM_NOT_ALIGNED,
    JPEGD_ERR_OUT_BUFFER_NOT_ALIGNED,
    JPEGD_ERR_REC_ERRORS_END,

    /* Fatal errors
     *      These are the codec errors which can not be recovered
     */
    JPEGD_ERR_FATAL_ERRORS_START = 111,
    JPEGD_ERR_ARITH_NOTIMPL = JPEGD_ERR_FATAL_ERRORS_START,
    JPEGD_ERR_BAD_COMPONENT_ID,
    JPEGD_ERR_BAD_DCTSIZE,
    JPEGD_ERR_BAD_HUFF_TABLE,
    JPEGD_ERR_BAD_J_COLORSPACE,
    JPEGD_ERR_BAD_LENGTH,
    JPEGD_ERR_BAD_LIB_VERSION,
    JPEGD_ERR_BAD_MCU_SIZE,
    JPEGD_ERR_BAD_PRECISION,
    JPEGD_ERR_BAD_PROGRESSION,
    JPEGD_ERR_BAD_SAMPLING,
    JPEGD_ERR_BAD_STATE,
    JPEGD_ERR_BAD_STRUCT_SIZE,
    JPEGD_ERR_CCIR601_NOTIMPL,
    JPEGD_ERR_COMPONENT_COUNT,
    JPEGD_ERR_CONVERSION_NOTIMPL,
    JPEGD_ERR_DAC_INDEX,
    JPEGD_ERR_DAC_VALUE,
    JPEGD_ERR_DHT_INDEX,
    JPEGD_ERR_DQT_INDEX,
    JPEGD_ERR_EMPTY_IMAGE,
    JPEGD_ERR_EOI_EXPECTED,
    JPEGD_ERR_FRACT_SAMPLE_NOTIMPL,
    JPEGD_ERR_IMAGE_TOO_BIG,
    JPEGD_ERR_NOTIMPL,
    JPEGD_ERR_NOT_COMPILED,
    JPEGD_ERR_NO_HUFF_TABLE,
    JPEGD_ERR_NO_IMAGE,
    JPEGD_ERR_NO_QUANT_TABLE,
    JPEGD_ERR_NO_SOI,
    JPEGD_ERR_OUT_OF_MEMORY,
    JPEGD_ERR_SOF_DUPLICATE,
    JPEGD_ERR_SOF_NO_SOS,
    JPEGD_ERR_SOF_UNSUPPORTED,
    JPEGD_ERR_SOI_DUPLICATE,
    JPEGD_ERR_SOS_NO_SOF,
    JPEGD_ERR_TOO_LITTLE_DATA,
    JPEGD_ERR_UNKNOWN_MARKER,
    JPEGD_ERR_WIDTH_OVERFLOW,
    JPEGD_ERR_BAD_THUMBNAIL_DATA,       /* Thumbnail related errors */
    JPEGD_ERR_BAD_INPUT_PARAM_EXIF,
    JPEGD_ERR_BAD_INPUT_PARAM_MODE,
    JPEGD_ERR_UNCOMPRESSED_THUMBNAIL,
    JPEGD_ERR_THUMBNAIL_OFFSET_NOT_FOUND,
    JPEGD_ERR_BAD_THUMBNAIL_TYPE,
    JPEGD_ERR_FATAL_ERRORS_END,
    /* Vpu errors
     *      These are the vpu errors
     */
    JPEGD_ERR_VPU_START=311,
    JPEGD_ERR_VPU_SETTING_ERROR=JPEGD_ERR_VPU_START,
    JPEGD_ERR_VPU_UNSUPPORTED_FMT,
    JPEGD_ERR_VPU_INVALID_MEMORY,
    JPEGD_ERR_VPU_INIT_FAILURE,
    JPEGD_ERR_VPU_OPEN_FAILURE,
    JPEGD_ERR_VPU_FILL_BUFFER_FAILURE,
    JPEGD_ERR_VPU_GET_INFO_FAILURE,
    JPEGD_ERR_VPU_REGISTER_FRAME_FAILURE,
    JPEGD_ERR_VPU_DECODE_FAILURE,
    JPEGD_ERR_VPU_GET_OUTPUT_FAILURE,
    JPEGD_ERR_VPU_END,
} JPEGD_RET_TYPE;

/* Structure definitions */
/* JPEGD_Mem_Alloc_Info and JPEGD_Mem_Alloc_Info_Sub are the memory allocation
 *  structures filled by the decoder in jpegd_query_dec_mem() function.
 *  Then memory pointers (ptr) will be initialized by the application
 */
typedef struct
{
    JPEGD_INT32   align;      /* Alignment of memory in bytes */
    JPEGD_INT32   size;       /* Size in bytes */
    JPEGD_INT32   mem_type_speed; /* Memory type Fast or Slow */
    JPEGD_INT32   mem_type_usage; /* Memory type static or scratch */
    JPEGD_INT32   priority;   /* Memory priority */
    void    *ptr;       /* Pointer to the memory */
    void    *phy_ptr;       /* Pointer to the physical memory */	
} JPEGD_Mem_Alloc_Info_Sub;

typedef struct
{
    JPEGD_INT32                       num_reqs;
    JPEGD_Mem_Alloc_Info_Sub    mem_info_sub[JPEGD_MAX_NUM_MEM_REQS];
} JPEGD_Mem_Alloc_Info;

/*
 * Decoder parameters. These parameters should be set by the
 *  application, before calling any decoder functions.
 */
typedef struct
{
    //JPEGD_UINT16  desired_output_width;   /* If set to '0', it is equal to original_ image_width */
    //JPEGD_UINT16  desired_output_height;  /* If set to '0', it is equal to original_image_height */
    JPEGD_DCT_METHOD dct_method;    /* default is JPEGD_IDCT_FAST, fast IDCT */
    JPEGD_OUTPUT_FORMAT  output_format;     /* default is JPEGD_OFMT_ENC_IMAGE_FMT */

    JPEGD_UINT8 decoding_mode;		/* JPEGD_PRIMARY, JPEGD_THUMBNAIL */
    JPEGD_UINT8 exif_info_needed;     /* Used only if file_format is exif */

    /* downscale set */
    JPEGD_UINT8 scale;	

    /*vpu setting*/	
    JPEGD_UINT8 vpu_enable;		  /*1: enable; 0:disable*/
    /*If below vpu parameters is 0, decoder will use internal default value*/	
    JPEGD_UINT32	vpu_bitstream_buf_size; /*buffer size used for raw data*/
    JPEGD_UINT32	vpu_fill_size;	/*unit size of data which decoder feed to vpu every time*/
    JPEGD_UINT32	vpu_wait_time;	/*decoder's waiting time before vpu need more data, unit: millisecond*/
} JPEGD_Decoder_Params;

/*
 * Important Note:
 *
 * The below decoder information is initialized in jpegd_decoder_init() and
 *  will remain constant throughout the decoding except for the following
 *  parameters. The following parameters are initialized in
 *  jpegd_decoder_init() and will be updated in the decoder routine
 *  jpegd_decode_mcu_row().
 *
 *      dec_info->output_scanline
 *      dec_info->num_lines
 *      dec_info->comp_info[i]->output_scanline
 *      dec_info->comp_info[i]->num_lines
 *
 * Also note that the Component Info structure dec_info->comp_info will
 * be filled by the decoder only for YUV outputs
 */
/* Following structure is used only when
 *  output_format == JPEGD_OFMT_ENC_IMAGE_FMT
 *  This is the decoder info and is read-only for the application
 *  This structure contains information about one component of the (Y or U or
 *  V) original input color space.
 */
typedef struct
{
    /* Relative horizontal  sampling factor of a  component */
    JPEGD_UINT8       h_samp;
    /* Relative vertical sampling factor of a component */
    JPEGD_UINT8       v_samp;

    /* Output width and height of a  component */
    JPEGD_UINT16      actual_output_width;
    JPEGD_UINT16      actual_output_height;
  /* Number of lines decoded so far of a  comp */
    JPEGD_UINT16      output_scanline;

   /* Maximum number of lines decoder can emit for a  component */
    JPEGD_INT32       max_lines;

    /* Number of lines returned for a  comp by jpegd_decode_mcu_row() */
    JPEGD_INT32       num_lines;
} JPEGD_Component_Info;

/* Following structure is the decoder info and is read-only for the application */
typedef struct
{
    JPEGD_UINT8       mode;       /* Sequential or Progressive */
    JPEGD_UINT8       h_samp_max; /* Maximum  Horizontal sampling factor */
    JPEGD_UINT8       v_samp_max; /* Maximum  vertical sampling factor */
    JPEGD_UINT8       num_components; /* Number of components in JPEG file */

    JPEGD_UINT16      original_image_width;  /* Input Image width, as present in
                                           the JPEG bitstream */
    JPEGD_UINT16      original_image_height; /* Input Image height, as present in
                                           the JPEG bitstream */
    /*  actual_output_width set by the decoder based on the
     *  configured parameter dec_param->desired_output_width.
     *  This can be different from (always <=) dec_param->desired_output_width
     */
    JPEGD_UINT16      actual_output_width;
    /*  actual_output_height set by the decoder based on the
     *  configured parameter dec_param->desired_output_height.
     *  This can be different from (always <=) dec_param->desired_output_height
     */
    JPEGD_UINT16      actual_output_height;

    /* For YUV outputs, following three parameters output_scanline, max_lines,
     * and num_lines are the parameters of the maximum component present
     * in the JPEG file. */
    /* Number of lines decoded so far */
    JPEGD_UINT16      output_scanline;


    /* Maximum number of lines decoder can emit  when jpegd_decode_mcu_row
     * is called
     */
    JPEGD_INT32       max_lines;

    /* Number of lines returned by jpegd_decode_mcu_row() */
    JPEGD_INT32       num_lines;

    //JPEGD_UINT8       thumbnail_flag;
    JPEGD_THUMBNAIL_TYPE thumbnail_type;
    JPEGD_UINT8       file_format;
    JPEGD_UINT32      min_size_exif;

    /* Information of the components present in the JPEG file  */
    JPEGD_Component_Info     comp_info[JPEGD_MAX_NUM_COMPS];
  
} JPEGD_Decoder_Info;

typedef struct
{
    JPEGD_UINT32 count;  /* count is size of the tag in bytes */
    void* ptr;
} JPEGD_tag;

typedef struct
{
    JPEGD_UINT32 x_resolution[2];
    JPEGD_UINT32 y_resolution[2];
    JPEGD_UINT16 resolution_unit;
    JPEGD_UINT16 ycbcr_positioning;
    JPEGD_UINT16 orientation;	
} JPEGD_IFD0_appinfo;

typedef struct
{
    JPEGD_UINT8 exif_version[4];
    JPEGD_UINT8 componentsconfiguration[4];
    JPEGD_UINT8 flashpix_version[4];
    JPEGD_UINT16 colorspace;
    JPEGD_UINT16 pixel_x_dimension;
    JPEGD_UINT16 pixel_y_dimension;

} JPEGD_exifIFD_appinfo;

typedef struct
{
    JPEGD_UINT32 x_resolution[2];
    JPEGD_UINT32 y_resolution[2];
    JPEGD_UINT16 resolution_unit;
    JPEGD_UINT16 compression; /* = 6 for compressed thumbnail, others invalid */
    JPEGD_UINT32 jpeg_interchange_format; /* offset to thumbnail image */
    JPEGD_UINT32 jpeg_interchange_format_length; /* size of thumbnail image */
    JPEGD_UINT16 orientation;	
} JPEGD_IFD1_appinfo;

typedef struct
{
    JPEGD_UINT8 endianness;
    /* flags to indicate the presence of IFDs */
    JPEGD_UINT8 IFD0_flag;
    JPEGD_UINT8 ExifIFD_flag;
    JPEGD_UINT8 IFD1_flag;
    JPEGD_UINT8 InteropIFD_flag;
    JPEGD_UINT8 GpsIFD_flag;

    //JPEGD_UINT8 compressed_thumbnail;
    JPEGD_THUMBNAIL_TYPE thumbnail_type;
    /* IFD structs to hold the tag info  */
    JPEGD_IFD0_appinfo ifd0_info;
    JPEGD_exifIFD_appinfo exififd_info;
    JPEGD_IFD1_appinfo ifd1_info;
    /* currently doesn't support GPS IFD and Interop IFD */

} JPEGD_exif_info;

typedef struct
{
    JPEGD_UINT8 jfif_major_version;
    JPEGD_UINT8 jfif_minor_version;
    JPEGD_UINT8 density_unit; // 0 = no unit, 1 = dots per inch, 2 = dots per cm
    JPEGD_UINT16 Xdensity;
    JPEGD_UINT16 Ydensity;
    //JPEGD_UINT8 compressed_thumbnail;
    JPEGD_THUMBNAIL_TYPE thumbnail_type;
} JPEGD_jfif_info;

/*
 * Decoder Object. This structure contains all the information
 *  about the decoder for one instance.
 */
typedef struct
{
    JPEGD_Mem_Alloc_Info        mem_info;
    JPEGD_Decoder_Params        dec_param;
    JPEGD_Decoder_Info          dec_info;

    void                        *cinfo;
    JPEGD_exif_info             exif_info;
    JPEGD_jfif_info             jfif_info;

  /*Changes Made for Call back*/
  JPEGD_UINT8 				(*jpegd_get_new_data_fun) (JPEGD_UINT8 **, JPEGD_UINT32 * ,JPEGD_UINT32 , JPEGD_UINT8 ,void *);
  /*Changes Made for Call back*/
} JPEGD_Decoder_Object;
#ifdef __cplusplus
#define EXTERN 
#else
#define EXTERN 
#endif

#ifdef __SYMBIAN32__
#define EXPORT_C __declspec(dllexport)
#define EXTERN
#else
#define EXPORT_C
#endif
#ifdef __cplusplus
extern "C"
{
#endif
 EXTERN JPEGD_RET_TYPE jpegd_query_dec_mem (JPEGD_Decoder_Object *dec_obj);
 EXTERN JPEGD_RET_TYPE jpegd_decoder_init (JPEGD_Decoder_Object *dec_obj);
 EXTERN JPEGD_RET_TYPE jpegd_decode_mcu_row (JPEGD_Decoder_Object *dec_obj, JPEGD_UINT8 **out_buf,
                            JPEGD_INT32 *out_stride_width);
 EXTERN JPEGD_RET_TYPE jpegd_decode_frame (JPEGD_Decoder_Object *dec_obj, JPEGD_UINT8 **out_buf,
                            JPEGD_INT32 *out_stride_width);
//JPEGD_UINT8 jpegd_get_new_data (JPEGD_UINT8 **ppBuf, JPEGD_UINT32 *pLen,
  //                        JPEGD_UINT32 mcu_offset, JPEGD_UINT8 begin_flag,
   //                       void *obj_ptr);

/*Changes Made for Call back*/
 EXTERN JPEGD_RET_TYPE jpegd_register_jpegd_get_new_data(JPEGD_UINT8 (* func)(JPEGD_UINT8 **, JPEGD_UINT32 * ,
											JPEGD_UINT32 , JPEGD_UINT8 ,void *),JPEGD_Decoder_Object *);
/*Changes Made for Call back*/

 EXTERN JPEGD_RET_TYPE jpegd_get_file_info (JPEGD_Decoder_Object *dec_obj, JPEGD_UINT8 *file_format,
                           JPEGD_THUMBNAIL_TYPE *thumbnail_type, JPEGD_UINT32 *min_size_exif);
/*query lib version*/
EXTERN const char *  jpegd_CodecVersionInfo(void);
#ifdef __cplusplus
}
#endif
#endif
/* End of file */
