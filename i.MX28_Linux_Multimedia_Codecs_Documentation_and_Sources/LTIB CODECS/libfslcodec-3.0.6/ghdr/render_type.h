 /************************************************************************
  * Copyright 2011 by Freescale Semiconductor, Inc.
  ************************************************************************/
#ifndef _RENDER_TYPE_H_
#define _RENDER_TYPE_H_

/**************************************************
 * Direct rendering type and data structure
 **************************************************/
typedef void* (*bufferGetter)(void* /*pvAppContext*/);
typedef void (*bufferRejecter)(void* /*mem_ptr*/, void* /*pvAppContext*/);

// new api format to support additional callback such as release,...
typedef void (*bufferReleaser)(void* /*mem_ptr*/, void* /*pvAppContext*/);

typedef enum
{
 E_GET_FRAME =0,
 E_REJECT_FRAME,
 E_RELEASE_FRAME,
 E_QUERY_PHY_ADDR,
} eCallbackType; //add this to indicate additional callback function type.

typedef enum
{
	E_CB_SET_OK =0,
	E_CB_SET_FAIL,
} eCallbackSetRet; //add this to indicate additional callback function type.

#endif


