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
#include <linux/usb.h>



static struct usb_device_id rtw_usb_id_tbl[] = {
 { USB_DEVICE(0x0bda, 0xb82c) },
 {} /* Terminating entry */
};

MODULE_DEVICE_TABLE(usb, rtw_usb_id_tbl);


//
static int rtw_drv_init(struct usb_interface *pbus_intf, 
			const struct usb_device_id *pdid)
{
    printk("rtw_drv_init is HERE\r\n");
    return 0;
}

static void rtw_dev_remove(struct usb_interface *pusb_intf)
{
    printk("rtw_dev_remove is HERE\r\n");
    return;
}


struct usb_driver usbdrv = {
    .name = "rtl88x2bu",
    .probe = rtw_drv_init,
    .disconnect = rtw_dev_remove,
    .id_table = rtw_usb_id_tbl
};



static int __init rtw_drv_entry(void)
{
    int ret;

    ret = usb_register(&usbdrv);
    printk("usb_register : ret=%d \r\n", ret);

exit:
    printk("module init ret=%d\n", ret);
	
    return ret;
}

static void __exit rtw_drv_halt(void)
{

    printk("module exit start\n");

    usb_deregister(&usbdrv);

    printk("module exit success\n");
}


module_init(rtw_drv_entry);
module_exit(rtw_drv_halt);

