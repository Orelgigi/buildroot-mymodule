#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

static int __init mymod_init(void)
{
    printk(KERN_INFO " hello my module\n");
    return 0;
}

static void __exit mymod_exit(void)
{
    printk(KERN_INFO "bye bye module\n");
}

module_init(mymod_init);
module_exit(mymod_exit);
MODULE_LICENSE("GPL");
