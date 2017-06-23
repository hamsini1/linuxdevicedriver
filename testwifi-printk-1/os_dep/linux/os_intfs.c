/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/
#define _OS_INTFS_C_

#include <drv_types.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Realtek Wireless Lan Driver");
MODULE_AUTHOR("Realtek Semiconductor Corp.");

/* set log level when inserting driver module, default log level is _DRV_INFO_ = 4,
* please refer to "How_to_set_driver_debug_log_level.doc" to set the available level.
*/
#ifdef RTW_LOG_LEVEL
	uint rtw_drv_log_level = (uint)RTW_LOG_LEVEL; /* from Makefile */
#else
	uint rtw_drv_log_level = _DRV_INFO_;
#endif
module_param(rtw_drv_log_level, uint, 0644);
MODULE_PARM_DESC(rtw_drv_log_level, "set log level when insert driver module, default log level is _DRV_INFO_ = 4");

