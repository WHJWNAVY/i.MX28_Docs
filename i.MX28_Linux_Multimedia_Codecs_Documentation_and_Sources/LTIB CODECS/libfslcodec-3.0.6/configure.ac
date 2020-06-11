dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

AC_INIT(libfslcodec, 3.0.6)
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AM_MAINTAINER_MODE

PKG_PROG_PKG_CONFIG

test "x$prefix" = xNONE && prefix=$ac_default_prefix

AC_DEFUN([CHECK_CODEC_DISABLE],
[
    AC_ARG_ENABLE($1,
        [AS_HELP_STRING([--disable-[$1]], [$2])],
        [use_[$1]=$enableval],
        [use_[$1]=yes])
    if test "$use_[$1]" = "yes"; then
        AM_CONDITIONAL(HAS_LIB_FSL_[$3], true)
        if test "$1" != "uniaudio"; then
            enabled_[$4]_codec="$enabled_[$4]_codec\n\t\t[$1]"
        fi
    else
        AM_CONDITIONAL(HAS_LIB_FSL_[$3], false)
        if test "$1" != "uniaudio"; then
            disabled_[$4]_codec="$disabled_[$4]_codec\n\t\t[$1]"
        fi
    fi
])

# audio codecs
CHECK_CODEC_DISABLE([peq], [disable peq], [PEQ], [audio])
CHECK_CODEC_DISABLE([src], [disable src], [SRC], [audio])
CHECK_CODEC_DISABLE([uniaudio], [disable unified audio wrapper], [UNI_AUDIO], [audio])
CHECK_CODEC_DISABLE([aacdec], [disable aac decoder], [AAC_DEC], [audio])
CHECK_CODEC_DISABLE([mp3dec], [disable mp3 decoder], [MP3_DEC], [audio])
CHECK_CODEC_DISABLE([mp3enc], [disable mp3 encoder], [MP3_ENC], [audio])
CHECK_CODEC_DISABLE([vorbisdec], [disable vorbis decoder], [VORBIS_DEC], [audio])
CHECK_CODEC_DISABLE([bsacdec], [disable bsac decoder], [BSAC_DEC], [audio])
CHECK_CODEC_DISABLE([flacdec], [disable flac decoder], [FLAC_DEC], [audio])
CHECK_CODEC_DISABLE([sbcenc], [disable sbc encoder], [SBC_ENC], [audio])
CHECK_CODEC_DISABLE([g726], [disable g726 decoder and encoder], [G726], [audio])
CHECK_CODEC_DISABLE([g711], [disable g711 decoder and encoder], [G711], [audio])
CHECK_CODEC_DISABLE([g723], [disable g723 decoder and encoder], [G723], [audio])
CHECK_CODEC_DISABLE([g729], [disable g729 decoder and encoder], [G729], [audio])
CHECK_CODEC_DISABLE([amrnb], [disable amrnb decoder and encoder], [AMRNB], [audio])
CHECK_CODEC_DISABLE([amrwb], [disable amrwb decoder and encoder], [AMRWB], [audio])

# video codecs
CHECK_CODEC_DISABLE([deinterlace], [disable deinterlace], [DEINTERLACE], [video])
CHECK_CODEC_DISABLE([h264dec], [disable h264 decoder], [H264_DEC], [video])
CHECK_CODEC_DISABLE([mpeg2dec], [disable mpeg2 decoder], [MPEG2_DEC], [video])
CHECK_CODEC_DISABLE([mpeg4aspdec], [disable mpeg4asp decoder], [MPEG4ASP_DEC], [video])
CHECK_CODEC_DISABLE([jpegdec], [disable jpeg decoder], [JPEG_DEC], [video])
CHECK_CODEC_DISABLE([jpegenc], [disable jpeg encoder], [JPEG_ENC], [video])
CHECK_CODEC_DISABLE([bmpdec], [disable bmp decoder], [BMP_DEC], [video])
CHECK_CODEC_DISABLE([pngdec], [disable png decoder], [PNG_DEC], [video])
CHECK_CODEC_DISABLE([gifdec], [disable gif decoder], [GIF_DEC], [video])

AC_OUTPUT([
Makefile
libfslaudiocodec.pc
libfslvideocodec.pc
])

echo -e "Configure result (with uni_audio: $use_uniaudio):"
echo -e "\tEnabled audio codec:$enabled_audio_codec"
echo -e "\tDisabled audio codec:$disabled_audio_codec"
echo -e "\tEnabled video codec:$enabled_video_codec"
echo -e "\tDisabled video codec:$disabled_video_codec"
