#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/jiffies.h>
#include <linux/param.h>

int my_flagCount = 0;

static int __init modA_init(void)
{
    printk(KERN_INFO "Inside First module A\n");
    printk(KERN_INFO "Initial value of my_flagcount is %d\n",my_flagCount);
    return 0;
}

static void __exit modA_exit(void)
{
    printk(KERN_INFO "Exiting module A and Final value of my_flagcount is %d\n",my_flagCount);
}

module_init(modA_init);
module_exit(modA_exit);
EXPORT_SYMBOL(my_flagCount);

MODULE_AUTHOR("Author");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module dependency");

