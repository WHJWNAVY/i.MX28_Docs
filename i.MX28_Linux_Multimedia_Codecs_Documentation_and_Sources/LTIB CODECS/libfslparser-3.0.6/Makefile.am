## Process this file with automake to produce Makefile.in

TOPDIR = .

libfsluniparserincludedir = $(includedir)/imx-mm/parser
libfsluniparserinclude_HEADERS = \
    $(TOPDIR)/ghdr/common/fsl_parser.h  \
    $(TOPDIR)/ghdr/common/fsl_types.h   \
    $(TOPDIR)/ghdr/common/fsl_media_types.h

libfsluniparserdocdir = $(docdir)/imx-mm/parser
libfsluniparserdoc_DATA = \
    $(TOPDIR)/docs/parser_common_api/fsl_parser_api_spec.pdf

if HAS_LIB_FSL_MP4_PARSER
fslmp4parser =  \
    $(TOPDIR)/release/lib/lib_mp4_parser_arm11_elinux.so    \
    $(TOPDIR)/release/lib/lib_mp4_parser_arm9_elinux.so
endif # end of HAS_LIB_FSL_MP4_PARSER

if HAS_LIB_FSL_MPG2_PARSER
fslmpg2parser =  \
    $(TOPDIR)/release/lib/lib_mpg2_parser_arm11_elinux.so    \
    $(TOPDIR)/release/lib/lib_mpg2_parser_arm9_elinux.so
endif # end of HAS_LIB_FSL_MPG2_PARSER

if HAS_LIB_FSL_AVI_PARSER
fslaviparser =  \
    $(TOPDIR)/release/lib/lib_avi_parser_arm11_elinux.so    \
    $(TOPDIR)/release/lib/lib_avi_parser_arm9_elinux.so
endif # end of HAS_LIB_FSL_AVI_PARSER

#if HAS_LIB_FSL_AVIDRM_PARSER
#fslavidrmparser =  \
#    $(TOPDIR)/release/lib/lib_avi_drm_arm11_elinux.so       \
#    $(TOPDIR)/release/lib/lib_avi_drm_arm9_elinux.so
#endif # end of HAS_LIB_FSL_AVIDRM_PARSER

if HAS_LIB_FSL_OGG_PARSER
fsloggparser =  \
    $(TOPDIR)/release/lib/lib_ogg_parser_arm11_elinux.so       \
    $(TOPDIR)/release/lib/lib_ogg_parser_arm9_elinux.so
endif # end of HAS_LIB_FSL_OGG_PARSER

if HAS_LIB_FSL_MKV_PARSER
fslmkvparser =  \
    $(TOPDIR)/release/lib/lib_mkv_parser_arm11_elinux.so       \
    $(TOPDIR)/release/lib/lib_mkv_parser_arm9_elinux.so
endif # end of HAS_LIB_FSL_MKV_PARSER

if HAS_LIB_FSL_FLV_PARSER
fslflvparser =  \
    $(TOPDIR)/release/lib/lib_flv_parser_arm11_elinux.so       \
    $(TOPDIR)/release/lib/lib_flv_parser_arm9_elinux.so
endif # end of HAS_LIB_FSL_FLV_PARSER

if HAS_LIB_FSL_MP3_PARSER
libfslmp3parserincludedir = $(includedir)/imx-mm/parser/mp3_parser
libfslmp3parserinclude_HEADERS = \
    $(TOPDIR)/ghdr/mp3_parser/mp3_parse.h

libfslmp3parserlibdir = $(libdir)
libfslmp3parserlib_DATA = \
    $(TOPDIR)/release/lib/lib_mp3_parser_arm11_elinux.so       \
    $(TOPDIR)/release/lib/lib_mp3_parser_arm9_elinux.so
endif # end of HAS_LIB_FSL_FLV_PARSER

pcparserfile = libfslparser.pc

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = $(pcparserfile)

libfslparserlibdir = $(libdir)/imx-mm/parser
libfslparserlib_DATA = \
    $(fslmp4parser)  \
    $(fslmpg2parser) \
    $(fslaviparser)  \
    $(fslavidrmparser)   \
    $(fsloggparser)  \
    $(fslmkvparser)  \
    $(fslflvparser)  \
    $(fslmp3parser)

EXTRA_DIST = autogen.sh \
    $(libfsluniparserdoc_DATA)  \
    $(libfslparserlib_DATA)     \
    $(libfslmp3parserlib_DATA)  \
    $(TOPDIR)/EULA.txt

install-data-hook:
	@for f in $(libfslparserlib_DATA); do               \
        base=`basename $$f`;                            \
        basepath=$(DESTDIR)$(libfslparserlibdir)/$$base;          \
        soname=`readelf -d $$basepath | grep soname | sed -e 's/.*\[\(.*\)]/\1/'`;  \
        ifname=`echo $$soname | sed -e 's/\(.*\.so\.[0-9][0-9]*\).*/\1/'`;          \
        rtname=`echo $$soname | sed -e 's/\(.*\.so\)\..*/\1/'`;                     \
        mv $$basepath $(DESTDIR)$(libfslparserlibdir)/$$soname;   \
        ln -sf $$soname $(DESTDIR)$(libfslparserlibdir)/$$ifname; \
        ln -sf $$soname $(DESTDIR)$(libfslparserlibdir)/$$rtname; \
    done;                                                         \
    for f in $(libfslmp3parserlib_DATA); do             \
        base=`basename $$f`;                            \
        basepath=$(DESTDIR)$(libfslmp3parserlibdir)/$$base;          \
        soname=`readelf -d $$basepath | grep soname | sed -e 's/.*\[\(.*\)]/\1/'`;  \
        rtname=`echo $$soname | sed -e 's/\(.*\.so\)\..*/\1/'`;                     \
        mv $$basepath $(DESTDIR)$(libfslmp3parserlibdir)/$$soname;   \
        ln -sf $$soname $(DESTDIR)$(libfslmp3parserlibdir)/$$rtname; \
    done

uninstall-hook:
	@for f in $(libfslparserlib_DATA); do           \
        base=`basename $$f`;                        \
        rm -f "$(DESTDIR)$(libfslparserlibdir)/$$base"*;      \
    done;                                           \
    for f in $(libfslmp3parserlib_DATA); do         \
        base=`basename $$f`;                        \
        rm -f "$(DESTDIR)$(libfslmp3parserlibdir)/$$base"*;   \
    done
