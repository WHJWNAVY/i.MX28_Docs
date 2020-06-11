 /************************************************************************
  * Copyright 2005-2010 by Freescale Semiconductor, Inc.
  * All modifications are confidential and proprietary information
  * of Freescale Semiconductor, Inc. ALL RIGHTS RESERVED.
  ************************************************************************/
#ifndef PNG_TYPE_H
#define PNG_TYPE_H

//Type definitions
typedef			int		 			PNG_INT32;
typedef 		unsigned int 		PNG_UINT32;
typedef			char				PNG_INT8;
typedef			unsigned char		PNG_UINT8;
typedef			short				PNG_INT16;
typedef			unsigned short		PNG_UINT16;

//dsphl28117
//Indicates whether scaling of output image is required or not
typedef enum
{
	E_PNG_NO_SCALE,
	E_PNG_INT_SCALE_PRESERVE_AR,
	E_PNG_LAST_SCALE_MODE
} png_scaling_mode;

typedef struct
{
  /*Following RGB values can be used as a default
    background color.Applicable for True-color
	Images (Color type 2 and 6)*/

   PNG_UINT16 red;
   PNG_UINT16 green;
   PNG_UINT16 blue;
  /*Following grayscale value can be used as a
    default background color.Applicable for
    Grayscale Images (Color type 0)*/
   PNG_UINT16 gray;

 /*Following index value can be used
   as a default background color.Applicable
   for Indexed-Color Images (Color type 3)*/

  PNG_UINT8 index;

} Background_Info;

typedef struct
{
  /*Pixels of the specified RGB sample values
    are treated as transparent.	Applicable
	for True-color Images without alpha
	(Color type 2)*/

   PNG_UINT16 red;
   PNG_UINT16 green;
   PNG_UINT16 blue;

  /*Pixels of the specified grey sample
    values are treated as transparent.
	Applicable for True-color Images
	without alpha (Color type 0)*/
   PNG_UINT16 gray;

} Trans_Info_Rgb_And_Gray;

typedef struct
{
/*Array indicating transparency information
  for indexed (color type 3) images (as provided
  in PNG Transparency chunk).
  There are "num_trans" transparency values stored
  in the same order as the palette colors, starting
  from index 0. Values for the data are in the range
  [0, 255], ranging from fully transparent to fully
  opaque, respectively*/
  //PNG_INT8 trans[256];

  /*Number of transparent palette colors*/

  PNG_UINT16 num_trans;
} Trans_Info_Indexed;

typedef struct
{
/* Following values provided
   significant red, green and blue bits
   for true-color and indexed images
   (color types 2 and 3) files */

   PNG_UINT8 red;
   PNG_UINT8 green;
   PNG_UINT8 blue;

/* Following value provides significant
   gray bits for grayscale images
   (color type 0) files */
   PNG_UINT8 gray;

/* Following value provides significant
   alpha bits for grayscale and true-color
   images with alpha channel
   (color types 4 and 6) files */

   PNG_UINT8 alpha; /* for alpha channel files */
} Significant_Bits_Info;

typedef struct
{
/*Each value is encoded as a four-byte
	PNG unsigned integer, representing the
	x or y value times 100000.
	Refer spec for details*/

   PNG_INT32 white_x; /*White point x*/
   PNG_INT32 white_y; /*White point y*/
   PNG_INT32 red_x; /*Red x*/
   PNG_INT32 red_y; /*Red y*/
   PNG_INT32 green_x; /*Green x*/
   PNG_INT32 green_y; /*Green y*/
   PNG_INT32 blue_x; /*Blue x*/
   PNG_INT32 blue_y; /*Blue y*/
} Chromaticity_Info;

typedef struct
{
   PNG_UINT32 x_pixels_per_unit;  /* horizontal pixel density */
   PNG_UINT32 y_pixels_per_unit;  /* vertical pixel density */
   PNG_UINT32 phys_unit_type;     /* resolution type  */
} Phy_Dimension_Info;


#endif