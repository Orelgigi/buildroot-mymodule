#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>

#define DEVICE_NAME "my_device"

static dev_t device_number;

static int __init mymod_init(void)
{
    int ret;
    ret = alloc_chrdev_region(&device_number, 0, 1, DEVICE_NAME);
    if (ret < 0)
    {
        pr_err("my_module: allocation failed: %d\n", ret);
        return ret;
    }
    pr_info("my_module: registered with major = %u minor = %u\n", MAJOR(device_number), MINOR(device_number));

    pr_info("my_module: initialized\n");
    return 0;
}

static void __exit mymod_exit(void)
{
    pr_info("my_module: exiting\n");
    unregister_chrdev_region(device_number, 1);
}

module_init(mymod_init);
module_exit(mymod_exit);
MODULE_LICENSE("GPL");
