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
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");


static struct tasklet_struct *t2;
static struct tasklet_struct *t3;

static void f(unsigned long name)
{
    printk("%s() on cpu %d \n", (char*)name, smp_processor_id());
}

static void f2(unsigned long name)
{
    f(name);
    mdelay(200); 
    tasklet_schedule(t2);
}

static void f3(unsigned long name)
{
    f(name);
    mdelay(300); 
    tasklet_schedule(t3);
}

static DECLARE_TASKLET(t1, f, (unsigned long)"t1");

extern uint rtw_drv_log_level;

static int __init rtw_drv_entry(void)
{
	int ret = 0;

	printk("module init start : %d\n", rtw_drv_log_level);

        t2 = kzalloc(sizeof(struct tasklet_struct), GFP_KERNEL);
        tasklet_init(t2, f2, (unsigned long)"t2");
        t3 = kzalloc(sizeof(struct tasklet_struct), GFP_KERNEL);
        tasklet_init(t3, f3, (unsigned long)"t3");

        tasklet_schedule(&t1);
        tasklet_schedule(t2);
        tasklet_schedule(t3);
exit:
	printk("module init ret=%d\n", ret);
	return ret;
}

static void __exit rtw_drv_halt(void)
{
	printk("module exit start\n");

	tasklet_kill(&t1);
	tasklet_kill(t2);
	tasklet_kill(t3);

	printk("module exit success : %d\n", rtw_drv_log_level);
}


module_init(rtw_drv_entry);
module_exit(rtw_drv_halt);

