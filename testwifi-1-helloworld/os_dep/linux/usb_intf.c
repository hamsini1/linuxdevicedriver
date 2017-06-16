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

#include <linux/init.h>
#include <linux/module.h>


static int rtw_drv_entry(void)
{
	int ret = 0;

	printk("module init start\n");

exit:
	printk("module init ret=%d\n", ret);
	return ret;
}

static void rtw_drv_halt(void)
{
	printk("module exit start\n");


	printk("module exit success\n");
}


module_init(rtw_drv_entry);
module_exit(rtw_drv_halt);

