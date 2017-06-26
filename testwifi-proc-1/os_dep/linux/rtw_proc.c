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

#include <linux/ctype.h>	/* tolower() */
#include <linux/fs.h>
#include <net/net_namespace.h>
#include "drv_types.h"
#include "osdep_service.h"
#include "rtw_proc.h"


static struct proc_dir_entry *rtw_proc = NULL;

inline struct proc_dir_entry *get_rtw_drv_proc(void)
{
	return rtw_proc;
}

#define RTW_PROC_NAME "rtl88x2bu"


static int proc_get_drv_version(struct seq_file *m, void *v)
{
    seq_printf(m, "rtl88x2bu : MYTEST \n");
    return 0;
}

static int rtw_drv_proc_open(struct inode *inode, struct file *file)
{
    return single_open(file, proc_get_drv_version, NULL);
}

static ssize_t rtw_drv_proc_write(struct file *file, const char __user *buffer, size_t count, loff_t *pos) 

{
    return -EROFS;
}


static const struct file_operations rtw_drv_proc_sseq_fops = {
    .owner = THIS_MODULE,
    .open = rtw_drv_proc_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .write = rtw_drv_proc_write,
    .release = single_release,
};



int rtw_drv_proc_init(void)
{
	int ret = _FAIL;
	ssize_t i;
	struct proc_dir_entry *entry = NULL;

	if (rtw_proc != NULL) {
	    printk("%s : rtw_proc != NULL \r\n", 
		__FUNCTION__);
		goto exit;
	}

	rtw_proc = proc_mkdir_data(RTW_PROC_NAME, S_IRUGO | S_IXUGO, init_net.proc_net, NULL);

	if (rtw_proc == NULL) {
	    printk("%s : rtw_proc = NULL after creation \r\n",
		 __FUNCTION__);
		goto exit;
	}

        entry = proc_create_data("ver_info", 
		S_IFREG | S_IRUGO | S_IWUGO, 
		rtw_proc, &rtw_drv_proc_sseq_fops, 0);	

	if (!entry) {
	    printk("%s : proc_create_data failed \r\n",
		 __FUNCTION__);
	    goto exit;
	}

	ret = _SUCCESS;

exit:
	return ret;
}

void rtw_drv_proc_deinit(void)
{
	int i;

	if (rtw_proc == NULL) {
	    printk("%s : rtw_proc == NULL \r\n", 
		__FUNCTION__);
	    return;
        }

	remove_proc_entry(RTW_PROC_NAME, init_net.proc_net);
	rtw_proc = NULL;
}

