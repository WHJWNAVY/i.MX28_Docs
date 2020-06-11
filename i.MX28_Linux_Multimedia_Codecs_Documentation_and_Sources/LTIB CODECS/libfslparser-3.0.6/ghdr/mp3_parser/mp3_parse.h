/*
 ***********************************************************************
 * Copyright 2005-2010 by Freescale Semiconductor, Inc.
 * All modifications are confidential and proprietary information
 * of Freescale Semiconductor, Inc. ALL RIGHTS RESERVED.
 ***********************************************************************
 */

#ifndef _MP3_PARSE_
#define _MP3_PARSE_

typedef enum {
	MP3_OK,
	MP3_ERR
} mp3_err;

#define MAX_V2_STRING 255
#define MAX_V1_STRING 31
#define MAX_LENGTH    255





typedef struct tag_meta_data_v1
{
	char song_title[MAX_V1_STRING];
	char artist[MAX_V1_STRING];
	char album[MAX_V1_STRING];
	char year[MAX_V1_STRING];
	char comment[MAX_V1_STRING];
	char genre;
	char genre_string[MAX_LENGTH];

}meta_data_v1;


typedef struct tag_meta_data_v2
{
	char song_title[MAX_V2_STRING];
	char artist[MAX_V2_STRING];
	char album[MAX_V2_STRING];
	char year[MAX_V2_STRING];
	char comment[MAX_V2_STRING];
	char genre[MAX_V2_STRING];
	char composer[MAX_V2_STRING];
	char copyright[MAX_V2_STRING];
	

}meta_data_v2;

/*For parsing Xing header and find frame header more correctly,add CRC*/
typedef enum {
  MAD_MODE_SINGLE_CHANNEL = 3,		/* single channel */
  MAD_MODE_DUAL_CHANNEL	  = 2,		/* dual channel */
  MAD_MODE_JOINT_STEREO	  = 1,		/* joint (MS/intensity) stereo */
  MAD_MODE_STEREO	  = 0		/* normal LR stereo */
} MAD_MODE_T;
enum {
  FLAG_SUCCESS,
  FLAG_NEEDMORE_DATA
};

typedef struct t_mp3_fr_info
{
	int frm_size;
	int index;
	int b_rate;

	MAD_MODE_T channel_mode;
	int  flags;
	int xing_exist;
        int vbri_exist;
        int total_frame_num;
	int total_bytes;
	unsigned int sampling_rate;
	unsigned int sample_per_fr;
    int layer;
    int version;
}mp3_fr_info;


mp3_err mp3_parser_parse_v2(meta_data_v2 *v2_data,char *buf);
int mp3_parser_get_id3_v2_size(char *buf);
mp3_err get_metadata_v1(meta_data_v1 *info,char *buf);
mp3_fr_info mp3_parser_parse_frame_header(char *frame_buffer,int buf_size, mp3_fr_info * in_info);
mp3_err mp3_check_next_frame_header ( char *frame_buffer, 
                                      int ref_mpeg_version,
                                      int ref_layer,
                                      int ref_sampling_frequency
                                    );


#endif
