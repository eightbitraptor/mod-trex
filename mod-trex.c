#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("eightbitraptor");
MODULE_DESCRIPTION("A device that roars at you");
MODULE_VERSION("0.1");

int things(void)
{
        printk(KERN_CRIT "I'm in ur kernel");
        return 0;
}

static int __init trex_init(void)
{
        printk("Hello, world - this is the kernel speaking\n");
        things();
        return 0;
}

static void __exit trex_exit(void)
{
        printk("Short is the life of an LKM\n");
}

module_init(trex_init);
module_exit(trex_exit);
