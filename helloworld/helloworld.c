
#include <linux/init.h>
#include <linux/module.h>


static int neo_drv_entry(void)
{
	int ret = 0;

	printk("module init start\n");

	printk("module init ret=%d\n", ret);
	return ret;
}

static void neo_drv_halt(void)
{
	printk("module exit start\n");


	printk("module exit success\n");
}


module_init(neo_drv_entry);
module_exit(neo_drv_halt);

