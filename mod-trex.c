#include <linux/module.h>
#include <linux/device.h>
#include <linux/fs.h>

#define DEVICE_NAME "trex"
#define CLASS_NAME "trex"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("eightbitraptor");
MODULE_DESCRIPTION("A device that roars at you");
MODULE_VERSION("0.1");

static int majorNumber;
static struct class*  charClass  = NULL;
static struct device* charDevice = NULL;

static int dev_open(struct inode *inodep, struct file *filep) {
        return 0;
}

static int dev_release(struct inode *inodep, struct file *filep) {
        return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset){
        return 0;
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
        return 0;
}

static struct file_operations fops =
{
        .open = dev_open,
        .read = dev_read,
        .write = dev_write,
        .release = dev_release,
};

static int __init trex_init(void)
{
        majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
        if (majorNumber<0){
                printk(KERN_ALERT "failed to register a major number\n");
                return majorNumber;
        }

        charClass = class_create(THIS_MODULE, CLASS_NAME);
        if (IS_ERR(charClass)){
                unregister_chrdev(majorNumber, DEVICE_NAME);
                printk(KERN_ALERT "Failed to register device class\n");
                return PTR_ERR(charClass);
        }

        charDevice = device_create(charClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);
        if (IS_ERR(charDevice)){
                class_destroy(charClass);
                unregister_chrdev(majorNumber, DEVICE_NAME);
                printk(KERN_ALERT "Failed to create the device\n");
                return PTR_ERR(charDevice);
        }
        printk(KERN_INFO "mod-trex successfully initialised\n");
        return 0;
}

static void __exit trex_exit(void)
{
        device_destroy(charClass, MKDEV(majorNumber, 0));
        class_unregister(charClass);
        class_destroy(charClass);
        unregister_chrdev(majorNumber, DEVICE_NAME);
        printk(KERN_INFO "mod-trex successfully unloaded\n");
}

module_init(trex_init);
module_exit(trex_exit);
