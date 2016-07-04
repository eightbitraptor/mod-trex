#define __KERNEL__
#define MODULE

#include <linux/modversions.h>
#include <linux/module.h>

#include <linux/tty.h>      /* console_print() interface */

void main()
{
        console_print("I'm in ur kernel");
}

int init_module()
{
        console_print("Hello, world - this is the kernel speaking\n");
        main();
        return 0;
}

void cleanup_module()
{
        console_print("Short is the life of an LKM\n");
}
