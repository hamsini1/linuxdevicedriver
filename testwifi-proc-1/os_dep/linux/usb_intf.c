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
#define _HCI_INTF_C_

#include <drv_types.h>

#include "rtw_proc.h"

extern uint rtw_drv_log_level;

static int __init rtw_drv_entry(void)
{
	int ret = 0;

    printk("module init start : %d\n", rtw_drv_log_level);

    //proc creation
    rtw_drv_proc_init();

exit:
    printk("module init ret=%d\n", ret);
	
    return ret;
}

static void __exit rtw_drv_halt(void)
{
	printk("module exit start\n");

	// proc remove
	rtw_drv_proc_deinit();

	printk("module exit success\n");
}


module_init(rtw_drv_entry);
module_exit(rtw_drv_halt);

