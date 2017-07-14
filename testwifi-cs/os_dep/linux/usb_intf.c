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
#include <linux/workqueue.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");


static void f2(struct work_struct *);
static void f3(struct work_struct *);
struct work_struct f2_work;
struct work_struct f3_work;
struct workqueue_struct *t2_workqueue;
struct workqueue_struct *t3_workqueue;

static int x = 0;



static void f2(struct work_struct *ws)
{
   volatile int t;
    msleep(1);
    while (1) {
        if ( x <  6) {
            t=x;
            t++;
            x=t;
            msleep(1);
            printk("f2() x=%d \r\n", x);
        } else {
	    break;
        }
    }
}

static void f3(struct work_struct *ws)
{
    volatile int t;
    msleep(1);
    while (1) {
        if ( x <  6) {
            printk("f3() x=%d \r\n", x);
            msleep(1);
            t=x;
            t++;
            x=t;
        } else {
            break;
        }
    }
}


extern uint rtw_drv_log_level;

static int __init rtw_drv_entry(void)
{
    int ret = 0;

    printk("module init start : %d\n", rtw_drv_log_level);

    t2_workqueue = create_workqueue("t2_wq");
    t3_workqueue = create_workqueue("t3_wq");
    INIT_WORK(&f2_work, f2);
    INIT_WORK(&f3_work, f3);
    queue_work(t2_workqueue, &f2_work);
    queue_work(t3_workqueue, &f3_work);

exit:
    printk("module init ret=%d\n", ret);
    return ret;
}

static void __exit rtw_drv_halt(void)
{
    printk("module exit start\n");

    destroy_workqueue(t2_workqueue);
    destroy_workqueue(t3_workqueue);
    printk("module exit success : %d\n", rtw_drv_log_level);
}


module_init(rtw_drv_entry);
module_exit(rtw_drv_halt);

