#define __KERNEL__
#define MODULE

#include <linux/module.h>

int things(void)
{
        printk(KERN_CRIT "I'm in ur kernel");
        return 0;
}

int init_module()
{
        printk("Hello, world - this is the kernel speaking\n");
        things();
        return 0;
}

void cleanup_module()
{
        printk("Short is the life of an LKM\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("eightbitraptor");
