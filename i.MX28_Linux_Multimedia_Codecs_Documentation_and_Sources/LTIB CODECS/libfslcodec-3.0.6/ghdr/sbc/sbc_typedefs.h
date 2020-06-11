/*
 ***********************************************************************
 * Copyright 2005-2008 by Freescale Semiconductor, Inc.
 * All modifications are confidential and proprietary information
 * of Freescale Semiconductor, Inc. ALL RIGHTS RESERVED.
 ***********************************************************************
 */
/*==================================================================================================

    Module Name:  sbc_typedefs.h

    General Description: SBC encoder/decoder typedefs
====================================================================================================

Revsion History:
                            Modification     Tracking
Author                          Date          Number     Description of Changes
-------------------------   ------------    ----------   -------------------------------------------
Dusan Veselinovic           08/01/2004                   Initial Creation
Tao Jun                     21/03/2008      engr69557    add int64 typedef

==================================================================================================*/
#ifndef SBC_TYPEDEFS_H
#define SBC_TYPEDEFS_H

typedef long unsigned int uint32;
typedef long int int32;
typedef short int16;
typedef short unsigned int uint16;
typedef char int8;
typedef unsigned char uint8;
#ifdef _WIN32
typedef __int64 int64;
#else
typedef long long int64;
#endif

typedef enum
{
	SBC_OK    =0x00,
	SBC_CRC_MISMATCH,
	SBC_UNSUPPORTED_FORMAT,
	SBC_NO_SYNCWORD,
	SBC_INVALID_BITPOOL_VALUE,
	SBC_FAIL =  0xFF
}SBC_RET_TYPE;

#endif

