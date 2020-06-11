dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

AC_INIT(libfslparser, 3.0.6)
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AM_MAINTAINER_MODE

PKG_PROG_PKG_CONFIG

test "x$prefix" = xNONE && prefix=$ac_default_prefix

AC_DEFUN([CHECK_PARSER_DISABLE],
[
    AC_ARG_ENABLE($1,
        [AS_HELP_STRING([--disable-[$1]], [$2])],
        [use_[$1]=$enableval],
        [use_[$1]=yes])
    if test "$use_[$1]" = "yes"; then
        AM_CONDITIONAL(HAS_LIB_FSL_[$3], true)
        enabled_parser="$enabled_parser\n\t\t[$1]"
    else
        disabled_parser="$disabled_parser\n\t\t[$1]"
    fi
])

CHECK_PARSER_DISABLE([mp4parser], [disable mp4 parser], [MP4_PARSER])
CHECK_PARSER_DISABLE([mpg2parser], [disable mpg2 parser], [MPG2_PARSER])
CHECK_PARSER_DISABLE([aviparser], [disable avi parser], [AVI_PARSER])
CHECK_PARSER_DISABLE([avidrmparser], [disable avidrm parser], [AVIDRM_PARSER])
CHECK_PARSER_DISABLE([oggparser], [disable ogg parser], [OGG_PARSER])
CHECK_PARSER_DISABLE([mkvparser], [disable mkv parser], [MKV_PARSER])
CHECK_PARSER_DISABLE([flvparser], [disable flv parser], [FLV_PARSER])
CHECK_PARSER_DISABLE([mp3parser], [disable mp3 parser], [MP3_PARSER])

AC_OUTPUT([
Makefile
libfslparser.pc
])

echo -e "Configure result:"
echo -e "\tEnabled parser:$enabled_parser"
echo -e "\tDisabled parser:$disabled_parser"
