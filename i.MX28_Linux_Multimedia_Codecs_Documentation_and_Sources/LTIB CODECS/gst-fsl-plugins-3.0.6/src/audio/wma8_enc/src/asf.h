//*@@@+++@@@@******************************************************************
//
// Microsoft Windows Media
// Copyright (C) Microsoft Corporation. All rights reserved.
//
//*@@@---@@@@******************************************************************
#ifndef _ASF_H_
#define _ASF_H_
#if defined(TGT_OS_LERVDS) || defined(TGT_OS_ELINUX)
#define assert(a) 
#endif

#if defined(WINCE_WARNLVL4_DISABLE)
	// disable some level-4 warnings, use #pragma warning(enable:###) to re-enable
	#pragma warning(disable:4100) // warning C4100: unreferenced formal parameter
	#pragma warning(disable:4201) // warning C4201: nonstandard extension used : nameless struct/union
	#pragma warning(disable:4512) // warning C4512: assignment operator could not be generated
	#pragma warning(disable:4127) // warning C4127: conditional expression is constant 
#endif //#if defined(WINCE_WARNLVL4_DISABLE)

#define ASF_HEADER sizeof(struct s_asf_packet_header_type)
//#define TOTAL_HEADER_PAD_LENGTH UDP_HEADER+ASF_HEADER
#define NUMPACKET 4
#ifdef ASF_FRAGMENTATION
#define ASF_PER_WMA 4
#else
#define ASF_PER_WMA 1
#endif

#define L_ENDIAN
#define ASF_TRUE               1
#define ASF_FALSE              0
//#define PACKET_BYTE_LENGTH 1372 * 4  // WMA packet size. Should be multiple integer of 1372
//////#define MAX_PACKET_BYTE_LENGTH 1372 * 7  // WMA packet size. Should be multiple integer of 1372
//#define ASF_PAYLOAD_LENGTH PACKET_BYTE_LENGTH/ASF_PER_WMA  // 
//#define ASF_PACKET_SIZE ASF_PAYLOAD_LENGTH+ASF_HEADER  //
//#define UDP_PACKET_SIZE UDP_DATA_LENGTH+UDP_HEADER  // if UDP smaller than WMA packet size then fragment

//#define PACKETLENGTH PACKET_BYTE_LENGTH*8

#define ASF_GUID_HEADER_OBJECT       {0x30,0x26,0xb2,0x75,0x8e,0x66,0xcf,0x11,\
                                      0xa6,0xd9,0x0,0xaa,0x0,0x62,0xce,0x6c}
#define ASF_GUID_PREFIX_file_header  {-95,-36,-85,-116,71,-87,-49,17, \
                                      -114,-28,0,-64,12,32,83,101}
#define ASF_FILE_ID                  {0xe9,0x3d,0x9f,0x3c,0x67,0x45,0x8b,0x6b, \
                                      0xc6,0x23,0x7b,0x32,0x0,0x0,0x0,0x0}
#define ASF_GUID_STREAM_PROP_OBJECT  {0x91,0x7,0xdc,0xb7,0xb7,0xa9,0xcf,0x11, \
                                      0x8e,0xe6,0x0,0xc0,0xc,0x20,0x53,0x65}
#define ASF_GUID_STREAM_PROP_OBJECT_TYPE   {0x40,0x9e,0x69,0xf8,0x4d,0x5b,0xcf,0x11, \
                                            0xa8,0xfd,0x0,0x80,0x5f,0x5c,0x44,0x2b}
#define ASF_GUID_ERROR_CORRECT_OBJECT {0x50,0xcd,0xC3,0xBF,0x8F,0x61,0xCF,0x11, \
                                       0x8B,0xB2,0x0,0xAA,0x0,0xB4,0xE2,0x20}
#define ASF_Header_ExtentionObject    {-75,3,-65,95,46,-87,-49,17, \
                                       -114,-29,0,-64,12,32,83,101}
#define ASF_GUID_Reserved1            {17,-46,-45,-85,-70,-87,-49,17, \
                                       -114,-26,0,-64,12,32,83,101}
#define ASF_GUID_CODEC_LIST_OBJECT    {0x40,0x52,0xD1,0x86, 0x1D,0x31,0xd0,0x11, \
                                       0xa3,0xa4,0x0,0xa0,0xc9,0x3,0x48,0xf6}
#define ASF_CODEC_LIST_Reserved       {0x41,0x52,0xD1,0x86,0x1D,0x31,0xD0,0x11, \
                                       0xA3,0xA4,0x0,0xA0,0xC9,0x3,0x48,0xF6}
#define ASF_GUID_CONT_DESC_OBJECT     {0x33,0x26,0xB2,0x75,0x8E,0x66,0xCF,0x11, \
                                       0xA6,0xD9,0x00,0xAA,0x00,0x62,0xCE,0x6C}
#define ASF_CODEC_NAME                "Windows Media Audio V8i  "
#define ASF_CODEC_DESCRIP             "140 kbps, 44 kHz, stereo "

#define ASF_GUID_DATA_OBJECT          {0x36,0x26,0xb2,0x75,0x8e,0x66,0xcf,0x11, \
                                       0xa6,0xd9,0x00,0xaa,0x00,0x62,0xce,0x6c}

/* status */
#ifndef _ASFRESULTS_DEFINED
#define _ASFRESULTS_DEFINED
typedef enum tagASFResults
{
    cASF_NoErr,                 /* -> always first entry */
                                /* remaining entry order is not guaranteed */
    cASF_Failed,
    cASF_BadArgument,
    cASF_BadAsfHeader,
    cASF_BadPacketHeader,
    cASF_BrokenFrame,
    cASF_NoMoreFrames,
}ASFRESULTS;
#endif


//***********************************************************************
//   Data type 
//***********************************************************************
typedef unsigned char		  ASF_UINT8;
typedef char			        ASF_INT8;
typedef unsigned short		ASF_UINT16;
typedef short		        	ASF_INT16;
typedef unsigned int		  ASF_UINT32;
typedef int			          ASF_INT32;
typedef ASF_UINT32       ASF_Bool;

#if _WIN32
typedef unsigned __int64        ASF_UINT64;
typedef __int64                 ASF_INT64;
#else
typedef unsigned long long      ASF_UINT64;
typedef long long               ASF_INT64;
#endif



typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long long qword;

#ifndef _STRUCT_ASF_PACKET_
#define _STRUCT_ASF_PACKET_

#if ((defined(TGT_OS_LERVDS) || defined(TGT_OS_ELINUX))) && (defined(__arm))
#define PACKED  __packed
#else
#define PACKED  
#pragma pack(push,1)
#endif

typedef PACKED struct 
{ 
#ifdef UNDER_CE        
        char reserved[16];
#else
        byte reserved[16];
#endif  
  qword len;
} id_size_t;

typedef PACKED struct s_asf_header_type {

    // Header Object
    PACKED struct s_header_obj {
        id_size_t header;  
        byte cno[4];  
        byte v1;  
        byte v2;
    } header_obj;                       

    // File Properties Object
   PACKED struct s_file_obj {
        id_size_t fheader;
        byte file_id[16];
        byte file_size[8];
        byte creation_time[8];
        byte num_packets[8];
        byte play_duration[8];
        byte send_duration[8];
        byte preroll[8];
        byte flags[4];
        byte min_packet_size[4];
        byte max_packet_size[4];
        byte max_bitrate[4];
    } file_obj;                    

    // Stream Properites Object
    PACKED struct s_stream_obj {
        id_size_t sheader;
        byte     stream_type[16];
        byte     concealment[16];
        byte     time_offset[8];
        byte     type_size[4];
        byte     error_corr_size[4];
        byte     stream_num[2];
        byte     reserved1[4];

        PACKED struct s_audio_media {   // Specific data: Audio Media Type
            byte codec_id[2];
            byte channel_num[2];
            byte samples_per_sec[4];
            byte bytes_per_sec[4];
            byte block_alignment[2];
            byte bits_per_sample[2];
            byte codec_specific_size[2];
            byte samples_per_block[4];
            byte encode_options[2];
            byte super_block_align[4];
        } audio_media;

        PACKED struct s_spread_audio {       // Error Correction Data: Spread Audio
            byte span;
            byte virtual_packet_len[2];
            byte virtual_chunk_len[2];
            byte silence_data_len[2];
            byte silence_data;
        } spread_audio;
    } stream_obj;

    // Header Extension Object
    PACKED struct s_ext_obj {
        id_size_t extheader;
#ifdef UNDER_CE        
        char reserved[16];
#else
        byte reserved[16];
#endif        
        byte unknown[2];
        byte length[4];
    } ext_obj;

    // Codec List Object
    PACKED struct s_codec_obj {
        id_size_t codecheader;
        byte codec_reserved[16];
        byte entries_num[4];
        byte codec_type[2];
        byte codec_name_len[2];
        word codec_name[26];
        byte codec_descript_len[2];
        word codec_descript[26];
        byte codec_info_len[2];
        byte codec_info[2];
    } codec_obj;  

    // Content Description Object
    // This structure does not include the actual
    // content description fields (title, author...)
    PACKED struct s_cont_desc_obj {
        id_size_t contdescheader;
        word      title_len;
        word      author_len;
        word      copyright_len;
        word      description_len;
        word      rating_len;
    } cont_desc_obj;

    // Data Object
    PACKED struct s_data_obj {
        id_size_t dataheader;
        byte file_id[16];
        byte num_data_packets[8];
        byte reserved[2];    /* reserved the value shall be 0x11 */
    } data_obj;

} asf_header_type;

typedef PACKED struct s_asf_packet_header_type {
    byte error_corr_flags;
    byte error_corr_data[2];
    byte length_type_flags;
    byte property_flags;
    byte padding_length[2];
    byte send_time[4];
    byte duration[2];
    byte stream_id;
    byte media_obj_id;
    byte offset[4];
    byte replicated_len;
    byte media_obj_size[4];
    byte pres_time[4];
} asf_packet_header_type;
#ifndef __arm
#pragma pack(pop)
#endif
#endif

#ifndef _STRUCT_ASFFORMATINFO_
#define _STRUCT_ASFFORMATINFO_
typedef struct 
{
    // base WAVEFORMATEX
    ASF_UINT32 nSamplesPerSec;
    ASF_UINT32 nChannels;
    ASF_UINT32 nAvgBytesPerSec;
    ASF_UINT32 nBlockAlign;
    // extended WAVEFORMATES
    ASF_UINT32 nSamplesPerBlock;
    ASF_UINT32 dwSuperBlockAlign;
    ASF_UINT16 wEncodeOptions;
    // miscellaneous
    ASF_UINT32 nFramesPerPacket;
    ASF_UINT32 nSamplesPerFrame;
    ASF_UINT32 nMaxSamplesPerPacket;
    ASF_UINT32 nLookaheadSamples;
    ASF_UINT32 nSuperFrameSamples; // useless ?
    ASF_UINT32 ulOfficialBitrate;
    ASF_INT64  nAudioDelaySizeMs;  
} ASFFormatInfo;
#endif

typedef struct
{
  asf_header_type asf_header;
  ASF_INT32 media_offset;
  ASF_INT64 asf_packet_count;
  ASF_UINT8 wma_packet_id;
  ASF_INT64 wma_packet_count;
  ASF_INT64 asf_file_size;
  
  ASF_INT32 nAudioSampleperSec;
  ASF_INT32 nMaxBitRate;
  ASF_INT64 nSendTime;
  ASF_INT16 nDuration;
  
  ASF_UINT32 WMAE_packet_byte_length;
  ASF_INT32  g_asf_packet_size;
  ASF_INT32  g_asf_payload_length;

  ASF_UINT32 g_space_in_packet;
  
  ASF_UINT16 *g_wszTitle;        // Cont Desc: Title
  ASF_UINT16 *g_wszAuthor;       // Cont Desc: Author
  ASF_UINT16 *g_wszCopyright;    // Cont Desc: Copyright
  ASF_UINT16 *g_wszDescription;  // Cont Desc: Description
  ASF_UINT16 *g_wszRating;       // Cont Desc: Rating
  
  ASF_UINT16 g_cTitle;              // length of Title
  ASF_UINT16 g_cAuthor;             // length of Author
  ASF_UINT16 g_cCopyright;          // length of Copyright
  ASF_UINT16 g_cDescription;        // length of Description
  ASF_UINT16 g_cRating;             // length of Rating
  
  ASF_INT64 nAudioDelayBuffer;
  ASF_INT64 presentation_time; 
  ASF_INT64 nAudioSamplesDone;
  ASF_UINT32 nSize,nSR;  
  ASFFormatInfo pFormat; 
}ASFParams;


#define SWAP_WORD( w )    (w) = (((w) & 0xFF ) << 8) | (((w) & 0xFF00 ) >> 8)
#define SWAP_DWORD( dw )  (dw) = ((dw) << 24) | ( ((dw) & 0xFF00) << 8 ) | ( ((dw) & 0xFF0000) >> 8 ) | ( ((dw) & 0xFF000000) >> 24);

#define ASFPUT8(slot, val) {        \
  char *dst =(char *) slot;         \
  *dst++ = (char)((val));           \
  *dst++ = (char)((val)>> 8);       \
  *dst++ = (char)((val)>>16);       \
  *dst++ = (char)((val)>>24);       \
  *dst++ = (char)((val)>>32);       \
  *dst++ = (char)((val)>>40);       \
  *dst++ = (char)((val)>>48);       \
  *dst++ = (char)((val)>>56); }

#define ASFPUT4(slot, val) {        \
  char *dst = (char *) slot;        \
  *dst++ = (char)((val));           \
  *dst++ = (char)((val)>> 8);       \
  *dst++ = (char)((val)>>16);       \
  *dst++ = (char)((val)>>24); }

#define ASFPUT2(slot, val) {        \
  char *dst =(char *) slot;         \
  *dst++ = (char)((val));           \
  *dst++ = (char)((val)>>8); }

#ifdef L_ENDIAN

#define ASF_2(  word )  (word)
#define ASF_4( dword ) (dword)
#define ASF_8( qword ) (qword)

#else

// these may require modification depending
// upon your big-endian memory layout. the
// values need to be written out in little-
// endian.

#define ASF_2(  word )  SWAP_WORD(  word )
#define ASF_4( dword ) SWAP_DWORD( dword )
#define ASF_8( qword ) ( ( SWAP_DWORD( qword >> 32 ) << 32 ) \
                         | SWAP_DWORD( qword & 0xffffffff ) )
#endif


#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN 
#endif
//void asf_packetize(ASFParams *pAsfParams,char *outBuf);
//void update_asf_file_header(ASFParams *pAsfParams, char *outBuf);
EXTERN ASFRESULTS write_asf_file_header ( ASFParams *pAsfParams,ASF_INT8* buf);
EXTERN ASFRESULTS update_asf_file_header(ASFParams *pAsfParams,ASF_UINT32 kbps,ASF_UINT32 kHz,ASF_UINT32 ch,ASF_UINT16 nBlockAlign,ASF_INT32 cFrameSize);
EXTERN ASF_INT32 add_asf_file_header (ASFParams *pAsfParams);
EXTERN ASFRESULTS asf_packetize (ASFParams *pAsfParams,ASF_INT8 *RawInput, ASF_INT8 *asfOutBuf,ASF_Bool WMAE_isPacketReady,ASF_INT32 WMAE_nEncodeSamplesDone);
#endif



