## Process this file with automake to produce Makefile.in

TOPDIR = .

######################### AUDIO ###########################
if HAS_LIB_FSL_PEQ
fslpeqinclude = \
    $(TOPDIR)/ghdr/peq_ppp_interface.h 	\
    $(TOPDIR)/ghdr/ppp_interface.h
fslpeqlib = \
    $(TOPDIR)/release/lib/lib_peq_arm11_elinux.so
endif

if HAS_LIB_FSL_SRC
fslsrcinclude = \
    $(TOPDIR)/ghdr/src_ppp_interface.h
fslsrclib = \
    $(TOPDIR)/release/lib/lib_src_ppp_arm11_elinux.so
endif

if HAS_LIB_FSL_UNI_AUDIO
fsluniaudioinclude = \
    $(TOPDIR)/ghdr/uni_audio/fsl_types.h \
    $(TOPDIR)/ghdr/uni_audio/fsl_unia.h

libfsluniaudiodocdir = $(docdir)/imx-mm/audio-codec/uni-audio
libfsluniaudiodoc_DATA = \
    $(TOPDIR)/docs/uni_audio/fsl_audio_api_spec.pdf

if HAS_LIB_FSL_AAC_DEC
fslaacdecwraplib = \
    $(TOPDIR)/release/lib/lib_aacd_wrap_arm11_elinux.so \
    $(TOPDIR)/release/lib/lib_aacd_wrap_arm12_elinux.so \
    $(TOPDIR)/release/lib/lib_aacd_wrap_arm9_elinux.so
endif

if HAS_LIB_FSL_MP3_DEC
fslmp3decwraplib = \
    $(TOPDIR)/release/lib/lib_mp3d_wrap_arm12_elinux.so \
    $(TOPDIR)/release/lib/lib_mp3d_wrap_arm11_elinux.so \
    $(TOPDIR)/release/lib/lib_mp3d_wrap_arm9_elinux.so
endif

if HAS_LIB_FSL_VORBIS_DEC
fslvorbisdecwraplib = \
    $(TOPDIR)/release/lib/lib_vorbisd_wrap_arm12_elinux.so \
    $(TOPDIR)/release/lib/lib_vorbisd_wrap_arm11_elinux.so
endif

endif # end of HAS_LIB_FSL_UNI_AUDIO

if HAS_LIB_FSL_AAC_DEC
fslaacdecinclude = \
    $(TOPDIR)/ghdr/aacd_dec_interface.h

fslaacdeclib = \
    $(TOPDIR)/release/lib/lib_aac_dec_arm11_elinux.so   \
    $(TOPDIR)/release/lib/lib_aac_dec_arm12_elinux.so   \
    $(TOPDIR)/release/lib/lib_aac_dec_arm9_elinux.so

libfslaacdecdocdir = $(docdir)/imx-mm/audio-codec/aac-dec
libfslaacdecdoc_DATA = \
    $(TOPDIR)/docs/aac_dec/aac_dec_api.pdf  \
    $(TOPDIR)/docs/aac_dec/datasheet/aac_dec_datasheet.pdf  \
    $(TOPDIR)/docs/aac_dec/aac_dec_release_notes.pdf

libfslaacdectestbindir = $(datadir)/imx-mm/audio-codec/examples/aac-dec/bin
libfslaacdectestbin_DATA = \
    $(TOPDIR)/release/exe/test_aac_dec_arm11_elinux \
    $(TOPDIR)/release/exe/test_aac_dec_arm12_elinux \
    $(TOPDIR)/release/exe/test_aac_dec_arm9_elinux

libfslaacdectestsrcdir = $(datadir)/imx-mm/audio-codec/examples/aac-dec/c_src
libfslaacdectestsrc_DATA = \
    $(TOPDIR)/test/aac_dec/c_src/aac_aux.c  \
    $(TOPDIR)/test/aac_dec/c_src/aac_main.c \
    $(TOPDIR)/test/aac_dec/c_src/log_api.c  \
    $(TOPDIR)/test/aac_dec/c_src/portio.c

libfslaacdectestdir = $(datadir)/imx-mm/audio-codec/examples/aac-dec
libfslaacdectest_DATA = \
    $(TOPDIR)/test/aac_dec/Makefile
endif # end of HAS_LIB_FSL_AAC_DEC

if HAS_LIB_FSL_MP3_DEC
fslmp3decinclude = \
    $(TOPDIR)/ghdr/mp3_dec_interface.h

fslmp3declib = \
    $(TOPDIR)/release/lib/lib_mp3_dec_arm12_elinux.so \
    $(TOPDIR)/release/lib/lib_mp3_dec_arm11_elinux.so \
    $(TOPDIR)/release/lib/lib_mp3_dec_arm9_elinux.so

libfslmp3decdocdir = $(docdir)/imx-mm/audio-codec/mp3-dec
libfslmp3decdoc_DATA = \
    $(TOPDIR)/docs/mp3_dec/mp3_dec_api.pdf            \
    $(TOPDIR)/docs/mp3_dec/datasheet/mp3_dec_datasheet.pdf \
    $(TOPDIR)/docs/mp3_dec/mp3_dec_release_notes.pdf

libfslmp3dectestbindir = $(datadir)/imx-mm/audio-codec/examples/mp3-dec/bin
libfslmp3dectestbin_DATA = \
    $(TOPDIR)/release/exe/test_mp3_dec_arm12_elinux \
    $(TOPDIR)/release/exe/test_mp3_dec_arm11_elinux \
    $(TOPDIR)/release/exe/test_mp3_dec_arm9_elinux

libfslmp3dectestsrcdir = $(datadir)/imx-mm/audio-codec/examples/mp3-dec/c_src
libfslmp3dectestsrc_DATA = \
    $(TOPDIR)/test/mp3_dec/c_src/mp3_dec_test.c

libfslmp3dectestdir = $(datadir)/imx-mm/audio-codec/examples/mp3-dec
libfslmp3dectest_DATA = \
    $(TOPDIR)/test/mp3_dec/Makefile
endif # end of HAS_LIB_FSL_MP3_DEC

if HAS_LIB_FSL_MP3_ENC
fslmp3encinclude = \
    $(TOPDIR)/ghdr/mp3_enc_interface.h

fslmp3enclib = \
    $(TOPDIR)/release/lib/lib_mp3_enc_arm12_elinux.so \
    $(TOPDIR)/release/lib/lib_mp3_enc_arm11_elinux.so \
    $(TOPDIR)/release/lib/lib_mp3_enc_arm9_elinux.so

libfslmp3encdocdir = $(docdir)/imx-mm/audio-codec/mp3-enc
libfslmp3encdoc_DATA = \
    $(TOPDIR)/docs/mp3_enc/mp3_enc_api.pdf                 \
    $(TOPDIR)/docs/mp3_enc/mp3_enc_release_notes.pdf       \
    $(TOPDIR)/docs/mp3_enc/datasheet/mp3_enc_datasheet.pdf

libfslmp3enctestbindir = $(datadir)/imx-mm/audio-codec/examples/mp3-enc/bin
libfslmp3enctestbin_DATA = \
    $(TOPDIR)/release/exe/test_mp3_enc_arm12_elinux \
    $(TOPDIR)/release/exe/test_mp3_enc_arm11_elinux \
    $(TOPDIR)/release/exe/test_mp3_enc_arm9_elinux

libfslmp3enctestsrcdir = $(datadir)/imx-mm/audio-codec/examples/mp3-enc/c_src
libfslmp3enctestsrc_DATA = \
    $(TOPDIR)/test/mp3_enc/c_src/test_mp3enc.c  \
    $(TOPDIR)/test/mp3_enc/c_src/wave_functions.c

libfslmp3enctesthdrdir = $(datadir)/imx-mm/audio-codec/examples/mp3-enc/hdr
libfslmp3enctesthdr_DATA = \
    $(TOPDIR)/test/mp3_enc/hdr/test_mp3enc.h    \
    $(TOPDIR)/test/mp3_enc/hdr/wave_functions.h

libfslmp3enctestdir = $(datadir)/imx-mm/audio-codec/examples/mp3-enc
libfslmp3enctest_DATA = \
    $(TOPDIR)/test/mp3_enc/makefile     \
    $(TOPDIR)/test/mp3_enc/makefile_standalone
endif # end of HAS_LIB_FSL_MP3_ENC

if HAS_LIB_FSL_VORBIS_DEC
fslvorbisdecinclude = \
    $(TOPDIR)/ghdr/oggvorbis_dec_api.h \
    $(TOPDIR)/ghdr/oggvorbis_dec_os_types.h

fslvorbisdeclib = \
    $(TOPDIR)/release/lib/lib_oggvorbis_dec_arm11_elinux.so

libfslvorbisdecdocdir = $(docdir)/imx-mm/audio-codec/oggvorbis-dec
libfslvorbisdecdoc_DATA = \
    $(TOPDIR)/docs/oggvorbis_dec/oggvorbis_dec_api.pdf          \
    $(TOPDIR)/docs/oggvorbis_dec/datasheet/oggvorbis_dec_datasheet.pdf \
    $(TOPDIR)/docs/oggvorbis_dec/oggvorbis_dec_release_notes.pdf

libfslvorbisdectestbindir = $(datadir)/imx-mm/audio-codec/examples/oggvorbis-dec/bin
libfslvorbisdectestbin_DATA = \
    $(TOPDIR)/release/exe/test_oggvorbis_dec_arm11_elinux

libfslvorbisdectestsrcdir = $(datadir)/imx-mm/audio-codec/examples/oggvorbis-dec/c_src
libfslvorbisdectestsrc_DATA = \
    $(TOPDIR)/test/oggvorbis_dec/c_src/ivorbisfile_example.c

libfslvorbisdectestdir = $(datadir)/imx-mm/audio-codec/examples/oggvorbis-dec
libfslvorbisdectest_DATA = \
    $(TOPDIR)/test/oggvorbis_dec/Makefile
endif # end of HAS_LIB_FSL_VORBIS_DEC

if HAS_LIB_FSL_BSAC_DEC
fslbsacdecinclude = \
    $(TOPDIR)/ghdr/bsacd_dec_interface.h

fslbsacdeclib = \
    $(TOPDIR)/release/lib/lib_bsac_dec_arm11_elinux.so

libfslbsacdecdocdir = $(docdir)/imx-mm/audio-codec/bsac-dec
libfslbsacdecdoc_DATA = \
    $(TOPDIR)/docs/bsac_dec/bsac_dec_api.pdf                 \
    $(TOPDIR)/docs/bsac_dec/datasheet/bsac_dec_datasheet.pdf \
    $(TOPDIR)/docs/bsac_dec/bsac_dec_release_notes.pdf

libfslbsacdectestsrcdir = $(datadir)/imx-mm/audio-codec/examples/bsac-dec/c_src
libfslbsacdectestsrc_DATA = \
    $(TOPDIR)/test/bsac_dec/c_src/aac_aux.c     \
    $(TOPDIR)/test/bsac_dec/c_src/bsac_main.c   \
    $(TOPDIR)/test/bsac_dec/c_src/portio.c

libfslbsacdectestdir = $(datadir)/imx-mm/audio-codec/examples/bsac-dec
libfslbsacdectest_DATA = \
    $(TOPDIR)/test/bsac_dec/makefile
endif # end of HAS_LIB_FSL_BSAC_DEC

if HAS_LIB_FSL_FLAC_DEC
fslflacdecinclude = \
    $(TOPDIR)/ghdr/flac_dec_interface.h

fslflacdeclib = \
    $(TOPDIR)/release/lib/lib_flac_dec_arm11_elinux.so \
    $(TOPDIR)/release/lib/lib_flac_dec_arm9_elinux.so

libfslflacdecdocdir = $(docdir)/imx-mm/audio-codec/flac-dec
libfslflacdecdoc_DATA = \
    $(TOPDIR)/docs/flac_dec/flac_dec_datasheet.pdf     \
    $(TOPDIR)/docs/flac_dec/flac_dec_release_notes.pdf \
    $(TOPDIR)/docs/flac_dec/flac_dec_api.pdf
endif # end of HAS_LIB_FSL_FLAC_DEC

if HAS_LIB_FSL_SBC_ENC
libfslsbcencincludedir = $(includedir)/imx-mm/audio-codec/sbc
libfslsbcencinclude_HEADERS = \
    $(TOPDIR)/ghdr/sbc/sbc_api.h    \
    $(TOPDIR)/ghdr/sbc/sbc_defs.h   \
    $(TOPDIR)/ghdr/sbc/sbc_typedefs.h

fslsbcenclib = \
    $(TOPDIR)/release/lib/lib_sbc_enc_arm11_elinux.so   \
    $(TOPDIR)/release/lib/lib_sbc_enc_arm9_elinux.so

libfslsbcencdocdir = $(docdir)/imx-mm/audio-codec/sbc-enc
libfslsbcencdoc_DATA = \
    $(TOPDIR)/docs/sbc_enc/sbc_enc_api.pdf                  \
    $(TOPDIR)/docs/sbc_enc/datasheet/sbc_enc_datasheet.pdf  \
    $(TOPDIR)/docs/sbc_enc/sbc_enc_release_notes.pdf

libfslsbcenctestbindir = $(datadir)/imx-mm/audio-codec/examples/sbc-enc/bin
libfslsbcenctestbin_DATA = \
    $(TOPDIR)/release/exe/test_sbc_enc_arm11_elinux \
    $(TOPDIR)/release/exe/test_sbc_enc_arm9_elinux

libfslsbcenctestsrcdir = $(datadir)/imx-mm/audio-codec/examples/sbc-enc/c_src
libfslsbcenctestsrc_DATA = \
    $(TOPDIR)/test/sbc_enc/c_src/sbc_enc_test_handler.c

libfslsbcenctesthdrdir = $(datadir)/imx-mm/audio-codec/examples/sbc-enc/hdr
libfslsbcenctesthdr_DATA = \
    $(TOPDIR)/test/sbc_enc/hdr/sbc_enc_test_handler.h

libfslsbcenctestdir = $(datadir)/imx-mm/audio-codec/examples/sbc-enc
libfslsbcenctest_DATA = \
    $(TOPDIR)/test/sbc_enc/Makefile
endif # end of HAS_LIB_FSL_SBC_ENC

if HAS_LIB_FSL_G726
fslg726include = \
    $(TOPDIR)/ghdr/g726_dec_api.h   \
    $(TOPDIR)/ghdr/g726_enc_api.h

fslg726lib = \
    $(TOPDIR)/release/lib/lib_g.726_dec_arm11_elinux.so \
    $(TOPDIR)/release/lib/lib_g.726_dec_arm9_elinux.so  \
    $(TOPDIR)/release/lib/lib_g.726_enc_arm11_elinux.so \
    $(TOPDIR)/release/lib/lib_g.726_enc_arm9_elinux.so

libfslg726docdir = $(docdir)/imx-mm/audio-codec/g726
libfslg726doc_DATA = \
    $(TOPDIR)/docs/g.726/g726_codec_api.pdf             \
    $(TOPDIR)/docs/g.726/g726_codec_datasheet.pdf       \
    $(TOPDIR)/docs/g.726/g726_codec_release_notes.pdf

libfslg726testbindir = $(datadir)/imx-mm/audio-codec/examples/g726/bin
libfslg726testbin_DATA = \
    $(TOPDIR)/release/exe/test_g.726_dec_arm11_elinux   \
    $(TOPDIR)/release/exe/test_g.726_dec_arm9_elinux    \
    $(TOPDIR)/release/exe/test_g.726_enc_arm11_elinux   \
    $(TOPDIR)/release/exe/test_g.726_enc_arm9_elinux

libfslg726testcomsrcdir = $(datadir)/imx-mm/audio-codec/examples/g726/c_src/common
libfslg726testcomsrc_DATA = \
    $(TOPDIR)/test/g.726/c_src/common/log_api.c     \
    $(TOPDIR)/test/g.726/c_src/common/staticmemory.c\
    $(TOPDIR)/test/g.726/c_src/common/strfunc.c

libfslg726testdecsrcdir = $(datadir)/imx-mm/audio-codec/examples/g726/c_src/decoder
libfslg726testdecsrc_DATA = \
    $(TOPDIR)/test/g.726/c_src/decoder/g726_dectest.c

libfslg726testencsrcdir = $(datadir)/imx-mm/audio-codec/examples/g726/c_src/encoder
libfslg726testencsrc_DATA = \
    $(TOPDIR)/test/g.726/c_src/encoder/g726_enctest.c

libfslg726testhdrdir = $(datadir)/imx-mm/audio-codec/examples/g726/hdr
libfslg726testhdr_DATA = \
    $(TOPDIR)/test/g.726/hdr/g726_dectest.h \
    $(TOPDIR)/test/g.726/hdr/g726_enctest.h \
    $(TOPDIR)/test/g.726/hdr/staticmemory.h \
    $(TOPDIR)/test/g.726/hdr/strfunc.h

libfslg726testdir = $(datadir)/imx-mm/audio-codec/examples/g726
libfslg726test_DATA = \
    $(TOPDIR)/test/g.726/Makefile
endif # end of HAS_LIB_FSL_G726

if HAS_LIB_FSL_G711
fslg711include = \
    $(TOPDIR)/ghdr/g711_type.h      \
    $(TOPDIR)/ghdr/g711_dec_api.h   \
    $(TOPDIR)/ghdr/g711_enc_api.h

fslg711lib = \
    $(TOPDIR)/release/lib/lib_g.711_dec_arm11_elinux.so \
    $(TOPDIR)/release/lib/lib_g.711_dec_arm9_elinux.so  \
    $(TOPDIR)/release/lib/lib_g.711_enc_arm11_elinux.so \
    $(TOPDIR)/release/lib/lib_g.711_enc_arm9_elinux.so

libfslg711docdir = $(docdir)/imx-mm/audio-codec/g711
libfslg711doc_DATA = \
    $(TOPDIR)/docs/G.711/g711_codec_api.pdf             \
    $(TOPDIR)/docs/G.711/g711_codec_datasheet.pdf       \
    $(TOPDIR)/docs/G.711/g711_codec_release_notes.pdf

libfslg711testbindir = $(datadir)/imx-mm/audio-codec/examples/g711/bin
libfslg711testbin_DATA = \
    $(TOPDIR)/release/exe/test_g.711_dec_arm11_elinux   \
    $(TOPDIR)/release/exe/test_g.711_dec_arm9_elinux    \
    $(TOPDIR)/release/exe/test_g.711_enc_arm11_elinux   \
    $(TOPDIR)/release/exe/test_g.711_enc_arm9_elinux

libfslg711testcomsrcdir = $(datadir)/imx-mm/audio-codec/examples/g711/c_src/common
libfslg711testcomsrc_DATA = \
    $(TOPDIR)/test/g.711/c_src/common/process_cmdline.c

libfslg711testdecsrcdir = $(datadir)/imx-mm/audio-codec/examples/g711/c_src/decoder
libfslg711testdecsrc_DATA = \
    $(TOPDIR)/test/g.711/c_src/decoder/g711_decode_test.c

libfslg711testencsrcdir = $(datadir)/imx-mm/audio-codec/examples/g711/c_src/encoder
libfslg711testencsrc_DATA = \
    $(TOPDIR)/test/g.711/c_src/encoder/g711_encode_test.c

libfslg711testhdrdir = $(datadir)/imx-mm/audio-codec/examples/g711/hdr
libfslg711testhdr_DATA = \
    $(TOPDIR)/test/g.711/hdr/process_cmdline.h

libfslg711testdir = $(datadir)/imx-mm/audio-codec/examples/g711
libfslg711test_DATA = \
    $(TOPDIR)/test/g.711/Makefile
endif # end of HAS_LIB_FSL_G711

if HAS_LIB_FSL_G723
fslg723include = \
    $(TOPDIR)/ghdr/g723_common_api.h    \
    $(TOPDIR)/ghdr/g723_dec_api.h       \
    $(TOPDIR)/ghdr/g723_enc_api.h

fslg723lib = \
    $(TOPDIR)/release/lib/lib_g.723.1_dec_arm11_elinux.so   \
    $(TOPDIR)/release/lib/lib_g.723.1_dec_arm9_elinux.so    \
    $(TOPDIR)/release/lib/lib_g.723.1_enc_arm11_elinux.so   \
    $(TOPDIR)/release/lib/lib_g.723.1_enc_arm9_elinux.so

libfslg723docdir = $(docdir)/imx-mm/audio-codec/g723
libfslg723doc_DATA = \
    $(TOPDIR)/docs/g.723.1/g723_codec_api.pdf           \
    $(TOPDIR)/docs/g.723.1/g723_codec_datasheet.pdf     \
    $(TOPDIR)/docs/g.723.1/g723_codec_release_notes.pdf

libfslg723testbindir = $(datadir)/imx-mm/audio-codec/examples/g723/bin
libfslg723testbin_DATA = \
    $(TOPDIR)/release/exe/test_g.723.1_dec_arm11_elinux \
    $(TOPDIR)/release/exe/test_g.723.1_dec_arm9_elinux  \
    $(TOPDIR)/release/exe/test_g.723.1_enc_arm11_elinux \
    $(TOPDIR)/release/exe/test_g.723.1_enc_arm9_elinux

libfslg723testcomsrcdir = $(datadir)/imx-mm/audio-codec/examples/g723/c_src/common
libfslg723testcomsrc_DATA = \
    $(TOPDIR)/test/g.723.1/c_src/common/log_api.c   \
    $(TOPDIR)/test/g.723.1/c_src/common/strfunc.c

libfslg723testdecsrcdir = $(datadir)/imx-mm/audio-codec/examples/g723/c_src/decoder
libfslg723testdecsrc_DATA = \
    $(TOPDIR)/test/g.723.1/c_src/decoder/g723_dectest.c

libfslg723testencsrcdir = $(datadir)/imx-mm/audio-codec/examples/g723/c_src/encoder
libfslg723testencsrc_DATA = \
    $(TOPDIR)/test/g.723.1/c_src/encoder/g723_enctest.c

libfslg723testhdrdir = $(datadir)/imx-mm/audio-codec/examples/g723/hdr
libfslg723testhdr_DATA = \
    $(TOPDIR)/test/g.723.1/hdr/g723_dectest.h   \
    $(TOPDIR)/test/g.723.1/hdr/g723_enctest.h   \
    $(TOPDIR)/test/g.723.1/hdr/strfunc.h

libfslg723testdir = $(datadir)/imx-mm/audio-codec/examples/g723
libfslg723test_DATA = \
    $(TOPDIR)/test/g.723.1/Makefile
endif # end of HAS_LIB_FSL_G723

if HAS_LIB_FSL_G729
fslg729include = \
    $(TOPDIR)/ghdr/g729_dec_api.h   \
    $(TOPDIR)/ghdr/g729_enc_api.h

fslg729lib = \
    $(TOPDIR)/release/lib/lib_g.729ab_dec_arm11_elinux.so \
    $(TOPDIR)/release/lib/lib_g.729ab_dec_arm9_elinux.so  \
    $(TOPDIR)/release/lib/lib_g.729ab_enc_arm11_elinux.so \
    $(TOPDIR)/release/lib/lib_g.729ab_enc_arm9_elinux.so

libfslg729docdir = $(docdir)/imx-mm/audio-codec/g729
libfslg729doc_DATA = \
    $(TOPDIR)/docs/g.729ab/g729_codec_api.pdf           \
    $(TOPDIR)/docs/g.729ab/g729_codec_datasheet.pdf     \
    $(TOPDIR)/docs/g.729ab/g729_codec_release_notes.pdf

libfslg729testbindir = $(datadir)/imx-mm/audio-codec/examples/g729/bin
libfslg729testbin_DATA = \
    $(TOPDIR)/release/exe/test_g.729ab_dec_arm11_elinux \
    $(TOPDIR)/release/exe/test_g.729ab_dec_arm9_elinux  \
    $(TOPDIR)/release/exe/test_g.729ab_enc_arm11_elinux \
    $(TOPDIR)/release/exe/test_g.729ab_enc_arm9_elinux

libfslg729testdecsrcdir = $(datadir)/imx-mm/audio-codec/examples/g729/c_src/decoder
libfslg729testdecsrc_DATA = \
    $(TOPDIR)/test/g.729ab/c_src/decoder/g729_dectest.c

libfslg729testencsrcdir = $(datadir)/imx-mm/audio-codec/examples/g729/c_src/encoder
libfslg729testencsrc_DATA = \
    $(TOPDIR)/test/g.729ab/c_src/encoder/g729_enctest.c

libfslg729testhdrdir = $(datadir)/imx-mm/audio-codec/examples/g729/hdr
libfslg729testhdr_DATA = \
    $(TOPDIR)/test/g.729ab/hdr/g729_dectest.h \
    $(TOPDIR)/test/g.729ab/hdr/g729_enctest.h

libfslg729testdir = $(datadir)/imx-mm/audio-codec/examples/g729
libfslg729test_DATA = \
    $(TOPDIR)/test/g.729ab/Makefile
endif # end of HAS_LIB_FSL_G729

if HAS_LIB_FSL_AMRNB
fslamrnbinclude = \
    $(TOPDIR)/ghdr/nb_amr_common_api.h  \
    $(TOPDIR)/ghdr/nb_amr_dec_api.h     \
    $(TOPDIR)/ghdr/nb_amr_enc_api.h

fslamrnblib = \
    $(TOPDIR)/release/lib/lib_nb_amr_dec_arm9_elinux.so \
    $(TOPDIR)/release/lib/lib_nb_amr_enc_arm9_elinux.so

libfslamrnbdocdir = $(docdir)/imx-mm/audio-codec/amrnb
libfslamrnbdoc_DATA = \
    $(TOPDIR)/docs/nb_amr/nbamr_codec_api.pdf           \
    $(TOPDIR)/docs/nb_amr/nbamr_codec_datasheet.pdf     \
    $(TOPDIR)/docs/nb_amr/nbamr_codec_release_notes.pdf

libfslamrnbtestbindir = $(datadir)/imx-mm/audio-codec/examples/amrnb/bin
libfslamrnbtestbin_DATA = \
    $(TOPDIR)/release/exe/test_nb_amr_dec_arm9_elinux   \
    $(TOPDIR)/release/exe/test_nb_amr_enc_arm9_elinux

libfslamrnbtestcomsrcdir = $(datadir)/imx-mm/audio-codec/examples/amrnb/c_src/common
libfslamrnbtestcomsrc_DATA = \
    $(TOPDIR)/test/nb_amr/c_src/common/log_api.c    \
    $(TOPDIR)/test/nb_amr/c_src/common/table_size.c

libfslamrnbtestdecsrcdir = $(datadir)/imx-mm/audio-codec/examples/amrnb/c_src/decoder
libfslamrnbtestdecsrc_DATA = \
    $(TOPDIR)/test/nb_amr/c_src/decoder/nbamr_dectest.c

libfslamrnbtestencsrcdir = $(datadir)/imx-mm/audio-codec/examples/amrnb/c_src/encoder
libfslamrnbtestencsrc_DATA = \
    $(TOPDIR)/test/nb_amr/c_src/encoder/nbamr_enctest.c

libfslamrnbtesthdrdir = $(datadir)/imx-mm/audio-codec/examples/amrnb/hdr
libfslamrnbtesthdr_DATA = \
    $(TOPDIR)/test/nb_amr/hdr/nbamr_dectest.h   \
    $(TOPDIR)/test/nb_amr/hdr/nbamr_enctest.h   \
    $(TOPDIR)/test/nb_amr/hdr/nbamr_tables.h    \
    $(TOPDIR)/test/nb_amr/hdr/vertex.h

libfslamrnbtestdir = $(datadir)/imx-mm/audio-codec/examples/amrnb
libfslamrnbtest_DATA = \
    $(TOPDIR)/test/nb_amr/Makefile
endif # end of HAS_LIB_FSL_AMRNB

if HAS_LIB_FSL_AMRWB
fslamrwbinclude = \
    $(TOPDIR)/ghdr/wbamr_common_interface.h \
    $(TOPDIR)/ghdr/wbamr_dec_interface.h    \
    $(TOPDIR)/ghdr/wbamr_enc_interface.h

fslamrwblib = \
    $(TOPDIR)/release/lib/lib_wb_amr_dec_arm9_elinux.so \
    $(TOPDIR)/release/lib/lib_wb_amr_enc_arm9_elinux.so

libfslamrwbtestbindir = $(datadir)/imx-mm/audio-codec/examples/amrwb/bin
libfslamrwbtestbin_DATA = \
    $(TOPDIR)/release/exe/test_wb_amr_dec_arm9_elinux   \
    $(TOPDIR)/release/exe/test_wb_amr_enc_arm9_elinux
endif # end of HAS_LIB_FSL_AMRWB

######################### VIDEO ###########################
libfsluniformtestbindir = $(datadir)/imx-mm/video-codec/examples/uniform-test/bin
libfsluniformtestbin_DATA = \
    $(TOPDIR)/release/exe/test_dec_arm_elinux

libfsluniformtestsrcdir = $(datadir)/imx-mm/video-codec/examples/uniform-test/src
libfsluniformtestsrc_DATA = \
    $(TOPDIR)/test/video_test/uniform_test/src/ColorConversion_Safe.cpp \
    $(TOPDIR)/test/video_test/uniform_test/src/makefile                 \
    $(TOPDIR)/test/video_test/uniform_test/src/render_lcd.c             \
    $(TOPDIR)/test/video_test/uniform_test/src/sources                  \
    $(TOPDIR)/test/video_test/uniform_test/src/test_dec_arm_elinux.c    \
    $(TOPDIR)/test/video_test/uniform_test/src/ui.c                     \
    $(TOPDIR)/test/video_test/uniform_test/src/video_test.cpp           \
    $(TOPDIR)/test/video_test/uniform_test/src/YUVDisplayer.cpp

libfsluniformtesthdrdir = $(datadir)/imx-mm/video-codec/examples/uniform-test/hdr
libfsluniformtesthdr_DATA = \
    $(TOPDIR)/test/video_test/uniform_test/hdr/ColorConversion_Safe.h   \
    $(TOPDIR)/test/video_test/uniform_test/hdr/defs.h                   \
    $(TOPDIR)/test/video_test/uniform_test/hdr/render_lcd.h             \
    $(TOPDIR)/test/video_test/uniform_test/hdr/ui.h                     \
    $(TOPDIR)/test/video_test/uniform_test/hdr/YUVDisplayer.h

libfsluniformtestdir = $(datadir)/imx-mm/video-codec/examples/uniform-test
libfsluniformtest_DATA = \
    $(TOPDIR)/test/video_test/uniform_test/Makefile     \
    $(TOPDIR)/test/video_test/uniform_test/MakefileEx   \
    $(TOPDIR)/test/video_test/uniform_test/MakefileEx.test.def.init \
    $(TOPDIR)/test/video_test/uniform_test/Makefile_RVDS

if HAS_LIB_FSL_DEINTERLACE
fsldeinterlaceinclude = \
    $(TOPDIR)/ghdr/deinterlace_api.h

fsldeinterlacelib = \
    $(TOPDIR)/release/lib/lib_deinterlace_arm11_elinux.so

libfsldeinterlacedocdir = $(docdir)/imx-mm/video-codec/deinterlace
libfsldeinterlacedoc_DATA = \
    $(TOPDIR)/docs/deinterlace/deinterlace_api.pdf          \
    $(TOPDIR)/docs/deinterlace/deinterlace_data_sheet.pdf   \
    $(TOPDIR)/docs/deinterlace/deinterlace_release_notes.pdf

libfsldeinterlacetestbindir = $(datadir)/imx-mm/video-codec/examples/deinterlace/bin
libfsldeinterlacetestbin_DATA = \
    $(TOPDIR)/release/exe/test_deinterlace_arm11_elinux \
    $(TOPDIR)/release/exe/test_deinterlace_arm9_elinux

libfsldeinterlacetestappsrcdir = $(datadir)/imx-mm/video-codec/examples/deinterlace/applications/PerformanceTest
libfsldeinterlacetestappsrc_DATA = \
    $(TOPDIR)/test/deinterlace/applications/PerformanceTest/DeintApp.cpp            \
    $(TOPDIR)/test/deinterlace/applications/PerformanceTest/deinterlace_cmd.txt     \
    $(TOPDIR)/test/deinterlace/applications/PerformanceTest/Makefile                \
    $(TOPDIR)/test/deinterlace/applications/PerformanceTest/Makefile.test.def.init  \
    $(TOPDIR)/test/deinterlace/applications/PerformanceTest/RawMovieViewView.cpp    \
    $(TOPDIR)/test/deinterlace/applications/PerformanceTest/RawMovieViewView.h

libfsldeinterlacetestmidsrcdir = $(datadir)/imx-mm/video-codec/examples/deinterlace/midware/cpp_src
libfsldeinterlacetestmidsrc_DATA = \
    $(TOPDIR)/test/deinterlace/midware/cpp_src/ColorConversion_UnSafe.cpp   \
    $(TOPDIR)/test/deinterlace/midware/cpp_src/Deinterlace.cpp              \
    $(TOPDIR)/test/deinterlace/midware/cpp_src/PictureManagement.cpp        \
    $(TOPDIR)/test/deinterlace/midware/cpp_src/ProcCtrl.cpp                 \
    $(TOPDIR)/test/deinterlace/midware/cpp_src/RawMovieFile.cpp

libfsldeinterlacetestmidhdrdir = $(datadir)/imx-mm/video-codec/examples/deinterlace/midware/hdr
libfsldeinterlacetestmidhdr_DATA = \
    $(TOPDIR)/test/deinterlace/midware/hdr/ColorConversion_UnSafe.h \
    $(TOPDIR)/test/deinterlace/midware/hdr/Deinterlace.h            \
    $(TOPDIR)/test/deinterlace/midware/hdr/PictureManagement.h      \
    $(TOPDIR)/test/deinterlace/midware/hdr/ProcCtrl.h               \
    $(TOPDIR)/test/deinterlace/midware/hdr/RawMovieFile.h
endif # end of HAS_LIB_FSL_DEINTERLACE

if HAS_LIB_FSL_H264_DEC
fslh264decinclude = \
    $(TOPDIR)/ghdr/avcd_dec_api.h

fslh264declib = \
    $(TOPDIR)/release/lib/lib_H264_dec_arm11_elinux.so  \
    $(TOPDIR)/release/lib/lib_H264_dec_arm9_elinux.so

libfslh264decdocdir = $(docdir)/imx-mm/video-codec/h264-dec
libfslh264decdoc_DATA = \
    $(TOPDIR)/docs/h264_dec/h264_dec_api.pdf        \
    $(TOPDIR)/docs/h264_dec/h264_dec_datasheet.pdf  \
    $(TOPDIR)/docs/h264_dec/h264_dec_release_notes.pdf

libfslh264dectestbindir = $(datadir)/imx-mm/video-codec/examples/h264-dec/bin
libfslh264dectestbin_DATA = \
    $(TOPDIR)/release/exe/test_dec_arm_elinux       \
    $(TOPDIR)/release/exe/libDutDecH264-1.7.so      \
    $(TOPDIR)/release/exe/libDutDecH264-1.8.so      \
    $(TOPDIR)/release/exe/libDutDecH264_arm11.so    \
    $(TOPDIR)/release/exe/libDutDecH264_arm9.so

libfslh264dectestsrcdir = $(datadir)/imx-mm/video-codec/examples/h264-dec/h264_dut/src
libfslh264dectestsrc_DATA = \
    $(TOPDIR)/test/video_test/h264_dut/src/h264_dec_dut.c   \
    $(TOPDIR)/test/video_test/h264_dut/src/io.c

libfslh264dectesthdrdir = $(datadir)/imx-mm/video-codec/examples/h264-dec/h264_dut/hdr
libfslh264dectesthdr_DATA = \
    $(TOPDIR)/test/video_test/h264_dut/hdr/dirUtils.h       \
    $(TOPDIR)/test/video_test/h264_dut/hdr/io.h

libfslh264dectestdir = $(datadir)/imx-mm/video-codec/examples/h264-dec/h264_dut
libfslh264dectest_DATA = \
    $(TOPDIR)/test/video_test/h264_dut/Makefile             \
    $(TOPDIR)/test/video_test/h264_dut/MakefileEx.def.init  \
    $(TOPDIR)/test/video_test/h264_dut/MakefileEx
endif # end of HAS_LIB_FSL_H264_DEC

if HAS_LIB_FSL_MPEG2_DEC
fslmpeg2decinclude = \
    $(TOPDIR)/ghdr/mpeg2_dec_api.h

fslmpeg2declib = \
    $(TOPDIR)/release/lib/lib_mpeg2_dec_arm11_elinux.so

libfslmpeg2decdocdir = $(docdir)/imx-mm/video-codec/mpeg2-dec
libfslmpeg2decdoc_DATA = \
    $(TOPDIR)/docs/mpeg2_dec/mpeg2_dec_api.pdf          \
    $(TOPDIR)/docs/mpeg2_dec/mpeg2_dec_data_sheet.pdf   \
    $(TOPDIR)/docs/mpeg2_dec/mpeg2_dec_release_notes.pdf

libfslmpeg2dectestbindir = $(datadir)/imx-mm/video-codec/examples/mpeg2-dec/bin
libfslmpeg2dectestbin_DATA = \
    $(TOPDIR)/release/exe/libDutDecMPG2_arm11.so \
    $(TOPDIR)/release/exe/libDutDecMPG2-1.7.so

libfslmpeg2dectestsrcdir = $(datadir)/imx-mm/video-codec/examples/mpeg2-dec/mpeg2_dut/src
libfslmpeg2dectestsrc_DATA = \
    $(TOPDIR)/test/video_test/mpeg2_dut/src/dut_mpg2_api_vts.c

libfslmpeg2dectesthdrdir = $(datadir)/imx-mm/video-codec/examples/mpeg2-dec/mpeg2_dut/hdr
libfslmpeg2dectesthdr_DATA = \
    $(TOPDIR)/test/video_test/mpeg2_dut/hdr/MPEG2DecTestApp.h \
    $(TOPDIR)/test/video_test/mpeg2_dut/hdr/common.h

libfslmpeg2dectestdir = $(datadir)/imx-mm/video-codec/examples/mpeg2-dec/mpeg2_dut
libfslmpeg2dectest_DATA = \
    $(TOPDIR)/test/video_test/mpeg2_dut/makefile
endif # end of HAS_LIB_FSL_MPEG2_DEC

if HAS_LIB_FSL_MPEG4ASP_DEC
fslmpeg4aspdecinclude = \
    $(TOPDIR)/ghdr/mpeg4_asp_api.h

fslmpeg4aspdeclib = \
    $(TOPDIR)/release/lib/lib_MPEG4ASP_dec_arm11_elinux.so \
    $(TOPDIR)/release/lib/lib_MPEG4ASP_dec_arm9_elinux.so

libfslmpeg4aspdecdocdir = $(docdir)/imx-mm/video-codec/mpeg4asp-dec
libfslmpeg4aspdecdoc_DATA = \
    $(TOPDIR)/docs/MPEG4ASP_dec/mpeg4_asp_dec_api.pdf           \
    $(TOPDIR)/docs/MPEG4ASP_dec/mpeg4_asp_dec_datasheet.pdf     \
    $(TOPDIR)/docs/MPEG4ASP_dec/mpeg4_asp_dec_release_notes.pdf

libfslmpeg4aspdectestbindir = $(datadir)/imx-mm/video-codec/examples/mpeg4asp-dec/bin
libfslmpeg4aspdectestbin_DATA = \
    $(TOPDIR)/release/exe/libDutDecMPEG4ASP-2.1.so      \
    $(TOPDIR)/release/exe/libDutDecMPEG4ASP_ARM11-2.1.so\
    $(TOPDIR)/release/exe/libDutDecMPEG4ASP_arm11.so    \
    $(TOPDIR)/release/exe/libDutDecMPEG4ASP_ARM9-2.1.so \
    $(TOPDIR)/release/exe/libDutDecMPEG4ASP_arm9.so

libfslmpeg4aspdectestsrcdir = $(datadir)/imx-mm/video-codec/examples/mpeg4asp-dec/MPEG4_dec_dut/src
libfslmpeg4aspdectestsrc_DATA = \
    $(TOPDIR)/test/video_test/MPEG4_dec_dut/src/mpeg4_dec_dut.c

libfslmpeg4aspdectesthdrdir = $(datadir)/imx-mm/video-codec/examples/mpeg4asp-dec/MPEG4_dec_dut/hdr
libfslmpeg4aspdectesthdr_DATA = \
    $(TOPDIR)/test/video_test/MPEG4_dec_dut/hdr/mpeg4types.h

libfslmpeg4aspdectestdir = $(datadir)/imx-mm/video-codec/examples/mpeg4asp-dec/MPEG4_dec_dut
libfslmpeg4aspdectest_DATA = \
    $(TOPDIR)/test/video_test/MPEG4_dec_dut/src/makefile
endif # end of HAS_LIB_FSL_MPEG4ASP_DEC

if HAS_LIB_FSL_JPEG_DEC
fsljpegdecinclude = \
    $(TOPDIR)/ghdr/jpeg_dec_interface.h

fsljpegdeclib = \
    $(TOPDIR)/release/lib/lib_jpeg_dec_arm11_elinux.so          \
    $(TOPDIR)/release/lib/lib_jpeg_dec_arm11_elinux_novpu.so    \
    $(TOPDIR)/release/lib/lib_jpeg_dec_arm9_elinux.so

libfsljpegdecdocdir = $(docdir)/imx-mm/video-codec/jpeg-dec
libfsljpegdecdoc_DATA = \
    $(TOPDIR)/docs/jpeg_dec/jpeg_dec_api.pdf            \
    $(TOPDIR)/docs/jpeg_dec/jpeg_dec_data_sheet.pdf     \
    $(TOPDIR)/docs/jpeg_dec/jpeg_dec_release_notes.pdf

libfsljpegdectestbindir = $(datadir)/imx-mm/video-codec/examples/jpeg-dec/bin
libfsljpegdectestbin_DATA = \
    $(TOPDIR)/release/exe/test_jpeg_dec_arm11_elinux        \
    $(TOPDIR)/release/exe/test_jpeg_dec_arm11_elinux_novpu  \
    $(TOPDIR)/release/exe/test_jpeg_dec_arm9_elinux

libfsljpegdectestsrcdir = $(datadir)/imx-mm/video-codec/examples/jpeg-dec/c_src
libfsljpegdectestsrc_DATA = \
    $(TOPDIR)/test/jpeg_dec/c_src/jpeg_dec_app.c    \
    $(TOPDIR)/test/jpeg_dec/c_src/log_api.c         \
    $(TOPDIR)/test/jpeg_dec/c_src/wrbmp.c

libfsljpegdectesthdrdir = $(datadir)/imx-mm/video-codec/examples/jpeg-dec/hdr
libfsljpegdectesthdr_DATA = \
    $(TOPDIR)/test/jpeg_dec/hdr/suspend.h   \
    $(TOPDIR)/test/jpeg_dec/hdr/wrbmp.h

libfsljpegdectestdir = $(datadir)/imx-mm/video-codec/examples/jpeg-dec
libfsljpegdectest_DATA = \
    $(TOPDIR)/test/jpeg_dec/Makefile            \
    $(TOPDIR)/test/jpeg_dec/README-Independent-JPEG.txt
endif # end of HAS_LIB_FSL_JPEG_DEC

if HAS_LIB_FSL_JPEG_ENC
fsljpegencinclude = \
    $(TOPDIR)/ghdr/jpeg_enc_interface.h

fsljpegenclib = \
    $(TOPDIR)/release/lib/lib_jpeg_enc_arm11_elinux.so

libfsljpegencdocdir = $(docdir)/imx-mm/video-codec/jpeg-enc
libfsljpegencdoc_DATA = \
    $(TOPDIR)/docs/jpeg_enc/jpeg_enc_api.pdf            \
    $(TOPDIR)/docs/jpeg_enc/jpeg_enc_data_sheet.pdf     \
    $(TOPDIR)/docs/jpeg_enc/jpeg_enc_release_notes.pdf

libfsljpegenctestbindir = $(datadir)/imx-mm/video-codec/examples/jpeg-enc/bin
libfsljpegenctestbin_DATA = \
    $(TOPDIR)/release/exe/test_jpeg_enc_arm11_elinux

libfsljpegenctestsrcdir = $(datadir)/imx-mm/video-codec/examples/jpeg-enc/c_src
libfsljpegenctestsrc_DATA = \
    $(TOPDIR)/test/jpeg_enc/c_src/application.c \
    $(TOPDIR)/test/jpeg_enc/c_src/log_api.c

libfsljpegenctestdir = $(datadir)/imx-mm/video-codec/examples/jpeg-enc
libfsljpegenctest_DATA = \
    $(TOPDIR)/test/jpeg_enc/Makefile            \
    $(TOPDIR)/test/jpeg_enc/README-Independent-JPEG.txt
endif # end of HAS_LIB_FSL_JPEG_ENC

if HAS_LIB_FSL_BMP_DEC
fslbmpdecinclude = \
    $(TOPDIR)/ghdr/bmp_interface.h

fslbmpdeclib = \
    $(TOPDIR)/release/lib/lib_bmp_dec_arm11_elinux.so

libfslbmpdecdocdir = $(docdir)/imx-mm/video-codec/bmp-dec
libfslbmpdecdoc_DATA = \
    $(TOPDIR)/docs/bmp_dec/bmp_dec_api.pdf          \
    $(TOPDIR)/docs/bmp_dec/bmp_dec_data_sheet.pdf   \
    $(TOPDIR)/docs/bmp_dec/bmp_dec_release_notes.pdf

libfslbmpdectestbindir = $(datadir)/imx-mm/video-codec/examples/bmp-dec/bin
libfslbmpdectestbin_DATA = \
    $(TOPDIR)/release/exe/test_bmp_dec_arm11_elinux \
    $(TOPDIR)/release/exe/test_bmp_dec_arm9_elinux

libfslbmpdectestsrcdir = $(datadir)/imx-mm/video-codec/examples/bmp-dec/c_src
libfslbmpdectestsrc_DATA = \
    $(TOPDIR)/test/bmp_dec/c_src/log_api.c  \
    $(TOPDIR)/test/bmp_dec/c_src/test_bmp.c

libfslbmpdectesthdrdir = $(datadir)/imx-mm/video-codec/examples/bmp-dec/hdr
libfslbmpdectesthdr_DATA = \
    $(TOPDIR)/test/bmp_dec/hdr/log_api.h

libfslbmpdectestdir = $(datadir)/imx-mm/video-codec/examples/bmp-dec
libfslbmpdectest_DATA = \
    $(TOPDIR)/test/bmp_dec/Makefile
endif # end of HAS_LIB_FSL_BMP_DEC

if HAS_LIB_FSL_PNG_DEC
fslpngdecinclude = \
    $(TOPDIR)/ghdr/png_dec_interface.h  \
    $(TOPDIR)/ghdr/png_type.h

fslpngdeclib = \
    $(TOPDIR)/release/lib/lib_png_dec_arm11_elinux.so

libfslpngdecdocdir = $(docdir)/imx-mm/video-codec/png-dec
libfslpngdecdoc_DATA = \
    $(TOPDIR)/docs/png_dec/png_dec_api.pdf          \
    $(TOPDIR)/docs/png_dec/png_dec_data_sheet.pdf   \
    $(TOPDIR)/docs/png_dec/png_dec_release_notes.pdf

libfslpngdectestbindir = $(datadir)/imx-mm/video-codec/examples/png-dec/bin
libfslpngdectestbin_DATA = \
    $(TOPDIR)/release/exe/test_png_dec_arm11_elinux \
    $(TOPDIR)/release/exe/test_png_dec_arm9_elinux

libfslpngdectestsrcdir = $(datadir)/imx-mm/video-codec/examples/png-dec/c_src
libfslpngdectestsrc_DATA = \
    $(TOPDIR)/test/png_dec/c_src/log_api.c          \
    $(TOPDIR)/test/png_dec/c_src/png_test_wrapper.c

libfslpngdectesthdrdir = $(datadir)/imx-mm/video-codec/examples/png-dec/hdr
libfslpngdectesthdr_DATA = \
    $(TOPDIR)/test/png_dec/hdr/log_api.h

libfslpngdectestdir = $(datadir)/imx-mm/video-codec/examples/png-dec
libfslpngdectest_DATA = \
    $(TOPDIR)/test/png_dec/Makefile
endif # end of HAS_LIB_FSL_PNG_DEC

if HAS_LIB_FSL_GIF_DEC
fslgifdecinclude = \
    $(TOPDIR)/ghdr/gif_dec_interface.h

fslgifdeclib = \
    $(TOPDIR)/release/lib/lib_gif_dec_arm11_elinux.so

libfslgifdecdocdir = $(docdir)/imx-mm/video-codec/gif-dec
libfslgifdecdoc_DATA = \
    $(TOPDIR)/docs/gif_dec/gif_dec_api.pdf          \
    $(TOPDIR)/docs/gif_dec/gif_dec_data_sheet.pdf   \
    $(TOPDIR)/docs/gif_dec/gif_dec_release_notes.pdf

libfslgifdectestbindir = $(datadir)/imx-mm/video-codec/examples/gif-dec/bin
libfslgifdectestbin_DATA = \
    $(TOPDIR)/release/exe/test_gif_dec_arm11_elinux

libfslgifdectestsrcdir = $(datadir)/imx-mm/video-codec/examples/gif-dec/c_src
libfslgifdectestsrc_DATA = \
    $(TOPDIR)/test/gif_dec/c_src/gif_test.c \
    $(TOPDIR)/test/gif_dec/c_src/log_api.c

libfslgifdectesthdrdir = $(datadir)/imx-mm/video-codec/examples/gif-dec/hdr
libfslgifdectesthdr_DATA = \
    $(TOPDIR)/test/gif_dec/hdr/log_api.h

libfslgifdectestdir = $(datadir)/imx-mm/video-codec/examples/gif-dec
libfslgifdectest_DATA = \
    $(TOPDIR)/test/gif_dec/Makefile
endif # end of HAS_LIB_FSL_GIF_DEC

pcaudiofile = libfslaudiocodec.pc
pcvideofile = libfslvideocodec.pc

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = $(pcaudiofile) $(pcvideofile)

libfslaudiocodecincludedir = $(includedir)/imx-mm/audio-codec
libfslaudiocodecinclude_HEADERS = \
    $(fslpeqinclude)		      \
    $(fslsrcinclude)		      \
    $(fsluniaudioinclude)         \
    $(fslaacdecinclude)           \
    $(fslmp3decinclude)           \
    $(fslmp3encinclude)           \
    $(fslvorbisdecinclude)        \
    $(fslbsacdecinclude)          \
    $(fslflacdecinclude)          \
    $(fslg726include)             \
    $(fslg711include)             \
    $(fslg723include)             \
    $(fslg729include)             \
    $(fslamrnbinclude)            \
    $(fslamrwbinclude)

libfslvideocodecincludedir = $(includedir)/imx-mm/video-codec
libfslvideocodecinclude_HEADERS = \
    $(TOPDIR)/ghdr/render_type.h  \
    $(fsldeinterlaceinclude)      \
    $(fslh264decinclude)          \
    $(fslmpeg2decinclude)         \
    $(fslmpeg4aspdecinclude)      \
    $(fsljpegdecinclude)          \
    $(fsljpegencinclude)          \
    $(fslbmpdecinclude)           \
    $(fslpngdecinclude)           \
    $(fslgifdecinclude)

libfslaudiocodeclibdir = $(libdir)/imx-mm/audio-codec
libfslaudiocodeclib_DATA = \
    $(fslpeqlib) 	   \
    $(fslsrclib) 	   \
    $(fslaacdeclib)    \
    $(fslmp3declib)    \
    $(fslmp3enclib)    \
    $(fslvorbisdeclib) \
    $(fslbsacdeclib)   \
    $(fslflacdeclib)   \
    $(fslsbcenclib)    \
    $(fslg726lib)      \
    $(fslg711lib)      \
    $(fslg723lib)      \
    $(fslg729lib)      \
    $(fslamrnblib)     \
    $(fslamrwblib)

libfslaudiowraplibdir = $(libdir)/imx-mm/audio-codec/wrap
libfslaudiowraplib_DATA = \
    $(fslaacdecwraplib)   \
    $(fslmp3decwraplib)   \
    $(fslvorbisdecwraplib)

libfslvideocodeclibdir = $(libdir)/imx-mm/video-codec
libfslvideocodeclib_DATA = \
    $(fsldeinterlacelib)   \
    $(fslh264declib)       \
    $(fslmpeg2declib)      \
    $(fslmpeg4aspdeclib)   \
    $(fsljpegdeclib)       \
    $(fsljpegenclib)       \
    $(fslbmpdeclib)        \
    $(fslpngdeclib)        \
    $(fslgifdeclib)

libfslaudiocodectestdir = $(datadir)/imx-mm/audio-codec/build
libfslaudiocodectest_DATA = Makefile_test.init

libfslvideocodectestdir = $(datadir)/imx-mm/video-codec/build
libfslvideocodectest_DATA = Makefile_test.init

EXTRA_DIST = autogen.sh \
    Makefile_test.init  \
    $(libfslaudiocodectest_DATA)\
    $(libfslvideocodectest_DATA)\
                                \
    $(libfslaudiocodeclib_DATA) \
    $(libfslaudiowraplib_DATA)  \
    $(libfslvideocodeclib_DATA) \
                                \
    $(libfsluniaudiodoc_DATA)   \
                                \
    $(libfslaacdecdoc_DATA)     \
    $(libfslaacdectestbin_DATA) \
    $(libfslaacdectestsrc_DATA) \
    $(libfslaacdectest_DATA)    \
                                \
    $(libfslmp3decdoc_DATA)     \
    $(libfslmp3dectestbin_DATA) \
    $(libfslmp3dectestsrc_DATA) \
    $(libfslmp3dectest_DATA)    \
                                \
    $(libfslmp3encdoc_DATA)     \
    $(libfslmp3enctestbin_DATA) \
    $(libfslmp3enctestsrc_DATA) \
    $(libfslmp3enctesthdr_DATA) \
    $(libfslmp3enctest_DATA)    \
                                \
    $(libfslvorbisdecdoc_DATA)     \
    $(libfslvorbisdectestbin_DATA) \
    $(libfslvorbisdectestsrc_DATA) \
    $(libfslvorbisdectest_DATA)    \
                                \
    $(libfslbsacdecdoc_DATA)    \
    $(libfslbsacdectestsrc_DATA)\
    $(libfslbsacdectest_DATA)   \
                                \
    $(libfslflacdecdoc_DATA)    \
                                \
    $(libfslsbcencdoc_DATA)     \
    $(libfslsbcenctestbin_DATA) \
    $(libfslsbcenctestsrc_DATA) \
    $(libfslsbcenctesthdr_DATA) \
    $(libfslsbcenctest_DATA)    \
                                \
    $(libfslg726doc_DATA)       \
    $(libfslg726testbin_DATA)   \
    $(libfslg726testcomsrc_DATA)\
    $(libfslg726testdecsrc_DATA)\
    $(libfslg726testencsrc_DATA)\
    $(libfslg726testhdr_DATA)   \
    $(libfslg726test_DATA)      \
                                \
    $(libfslg711doc_DATA)       \
    $(libfslg711testbin_DATA)   \
    $(libfslg711testcomsrc_DATA)\
    $(libfslg711testdecsrc_DATA)\
    $(libfslg711testencsrc_DATA)\
    $(libfslg711testhdr_DATA)   \
    $(libfslg711test_DATA)      \
                                \
    $(libfslg723doc_DATA)       \
    $(libfslg723testbin_DATA)   \
    $(libfslg723testcomsrc_DATA)\
    $(libfslg723testdecsrc_DATA)\
    $(libfslg723testencsrc_DATA)\
    $(libfslg723testhdr_DATA)   \
    $(libfslg723test_DATA)      \
                                \
    $(libfslg729doc_DATA)       \
    $(libfslg729testbin_DATA)   \
    $(libfslg729testdecsrc_DATA)\
    $(libfslg729testencsrc_DATA)\
    $(libfslg729testhdr_DATA)   \
    $(libfslg729test_DATA)      \
                                \
    $(libfslamrnbdoc_DATA)       \
    $(libfslamrnbtestbin_DATA)   \
    $(libfslamrnbtestcomsrc_DATA)\
    $(libfslamrnbtestdecsrc_DATA)\
    $(libfslamrnbtestencsrc_DATA)\
    $(libfslamrnbtesthdr_DATA)   \
    $(libfslamrnbtest_DATA)      \
                                \
    $(libfslamrwbtestbin_DATA)  \
                                \
    $(libfsluniformtestbin_DATA)\
    $(libfsluniformtestsrc_DATA)\
    $(libfsluniformtesthdr_DATA)\
    $(libfsluniformtest_DATA)   \
                                \
    $(libfsldeinterlacedoc_DATA)        \
    $(libfsldeinterlacetestbin_DATA)    \
    $(libfsldeinterlacetestappsrc_DATA) \
    $(libfsldeinterlacetestmidsrc_DATA) \
    $(libfsldeinterlacetestmidhdr_DATA) \
                                \
    $(libfslh264decdoc_DATA)        \
    $(libfslh264dectestbin_DATA)    \
    $(libfslh264dectestsrc_DATA)    \
    $(libfslh264dectesthdr_DATA)    \
    $(libfslh264dectest_DATA)   \
                                \
    $(libfslmpeg2decdoc_DATA)        \
    $(libfslmpeg2dectestbin_DATA)    \
    $(libfslmpeg2dectestsrc_DATA)    \
    $(libfslmpeg2dectesthdr_DATA)    \
    $(libfslmpeg2dectest_DATA)  \
                                \
    $(libfslmpeg4aspdecdoc_DATA)        \
    $(libfslmpeg4aspdectestbin_DATA)    \
    $(libfslmpeg4aspdectestsrc_DATA)    \
    $(libfslmpeg4aspdectesthdr_DATA)    \
    $(libfslmpeg4aspdectest_DATA)       \
                                     \
    $(libfsljpegdecdoc_DATA)         \
    $(libfsljpegdectestbin_DATA)     \
    $(libfsljpegdectestsrc_DATA)     \
    $(libfsljpegdectesthdr_DATA)     \
    $(libfsljpegdectest_DATA)        \
                                     \
    $(libfsljpegencdoc_DATA)         \
    $(libfsljpegenctestbin_DATA)     \
    $(libfsljpegenctestsrc_DATA)     \
    $(libfsljpegenctest_DATA)        \
                                     \
    $(libfslbmpdecdoc_DATA)         \
    $(libfslbmpdectestbin_DATA)     \
    $(libfslbmpdectestsrc_DATA)     \
    $(libfslbmpdectesthdr_DATA)     \
    $(libfslbmpdectest_DATA)        \
                                    \
    $(libfslpngdecdoc_DATA)         \
    $(libfslpngdectestbin_DATA)     \
    $(libfslpngdectestsrc_DATA)     \
    $(libfslpngdectesthdr_DATA)     \
    $(libfslpngdectest_DATA)        \
                                    \
    $(libfslgifdecdoc_DATA)         \
    $(libfslgifdectestbin_DATA)     \
    $(libfslgifdectestsrc_DATA)     \
    $(libfslgifdectesthdr_DATA)     \
    $(libfslgifdectest_DATA)        \
    $(TOPDIR)/EULA.txt

install-data-hook:
	@for f in $(libfslaudiocodeclib_DATA); do                           \
        base=`basename $$f`;                                            \
        basepath=$(DESTDIR)$(libfslaudiocodeclibdir)/$$base;                      \
        soname=`readelf -d $$basepath | grep soname | sed -e 's/.*\[\(.*\)]/\1/'`;\
        rtname=`echo $$soname | sed -e 's/\(.*\.so\)\..*/\1/'`;                   \
        mv $$basepath $(DESTDIR)$(libfslaudiocodeclibdir)/$$soname;               \
        ln -sf $$soname $(DESTDIR)$(libfslaudiocodeclibdir)/$$rtname;             \
    done;                                                               \
	for f in $(libfslaudiowraplib_DATA); do                             \
        base=`basename $$f`;                                            \
        basepath=$(DESTDIR)$(libfslaudiowraplibdir)/$$base;                       \
        soname=`readelf -d $$basepath | grep soname | sed -e 's/.*\[\(.*\)]/\1/'`;\
        rtname=`echo $$soname | sed -e 's/\(.*\.so\)\..*/\1/'`;                   \
        mv $$basepath $(DESTDIR)$(libfslaudiowraplibdir)/$$soname;                \
        ln -sf $$soname $(DESTDIR)$(libfslaudiowraplibdir)/$$rtname;              \
    done;                                                               \
	for f in $(libfslvideocodeclib_DATA); do                            \
        base=`basename $$f`;                                            \
        basepath=$(DESTDIR)$(libfslvideocodeclibdir)/$$base;                      \
        soname=`readelf -d $$basepath | grep soname | sed -e 's/.*\[\(.*\)]/\1/'`;\
        if [ -z "$$soname" ]; then                                                \
            continue;                                                             \
        fi;                                                                       \
        if [ "$$soname" = "$$base" ]; then                                        \
            soname="$$soname".1;                                                  \
        fi;                                                                 \
        rtname=`echo $$soname | sed -e 's/\(.*\.so\)\..*/\1/'`;             \
        mv $$basepath $(DESTDIR)$(libfslvideocodeclibdir)/$$soname;         \
        ln -sf $$soname $(DESTDIR)$(libfslvideocodeclibdir)/$$rtname;       \
    done;                                                                   \
    for f in $(DESTDIR)$(datadir)/imx-mm/audio-codec/examples/*/bin/*; do   \
        chmod +x $$f;                                                       \
    done;                                                                   \
    for f in $(DESTDIR)$(datadir)/imx-mm/video-codec/examples/*/bin/*; do   \
        chmod +x $$f;                                                       \
    done

uninstall-hook:
	@for f in $(libfslaudiocodeclib_DATA); do           \
        base=`basename $$f`;                            \
        rm -f "$(DESTDIR)$(libfslaudiocodeclibdir)/$$base"*;      \
    done;                                               \
	for f in $(libfslaudiowraplib_DATA); do             \
        base=`basename $$f`;                            \
        rm -f "$(DESTDIR)$(libfslaudiowraplibdir)/$$base"*;       \
    done;                                               \
	for f in $(libfslvideocodeclib_DATA); do            \
        base=`basename $$f`;                            \
        rm -f "$(DESTDIR)$(libfslvideocodeclibdir)/$$base"*;      \
    done
