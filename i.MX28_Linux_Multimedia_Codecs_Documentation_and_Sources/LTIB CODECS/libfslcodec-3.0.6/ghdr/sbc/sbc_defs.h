
/*
 ***********************************************************************
 * Copyright 2005-2008 by Freescale Semiconductor, Inc.
 * All modifications are confidential and proprietary information
 * of Freescale Semiconductor, Inc. ALL RIGHTS RESERVED.
 ***********************************************************************
 */
/*==================================================================================================

    Module Name:  sbc_defs.h

    General Description: SBC encoder/decoder definitions
====================================================================================================

Revsion History:
                            Modification     Tracking
Author                          Date          Number     Description of Changes
-------------------------   ------------    ----------   -------------------------------------------
Dusan Veselinovic           08/01/2004                   Initial Creation


==================================================================================================*/
#ifndef SBC_DEFS_H
#define SBC_DEFS_H

#include "sbc_typedefs.h"

#define CRC8_SBC_POLYNOMIAL 0x1D

#define SBC_MONO                0x00
#define SBC_DUAL_CHANNEL        0x01
#define SBC_STEREO              0x02
#define SBC_JOINT_STEREO        0x03

#define SBC_LOUDNESS            0x00
#define SBC_SNR                 0x01

#define TRUE                0x01
#define FALSE               0x00


/* BUFFER SIZES */
#define SBC_DEC_IN_BUF_SIZE         1012 /* max encoded frame length: 1012 bytes */
#define SBC_DEC_OUT_BUF_SIZE        256  /* max decoded frame size (in samples): 2 channels, 8 subbands, 16 blocks*/
#define SBC_ENC_IN_BUF_SIZE	        4096 /* max super_frame size: 2048 samples = 4096 bytes */
#define SBC_ENC_OUT_BUF_SIZE        1012 /* max encoded frame length: 1012 bytes */

#endif


