#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/jiffies.h>
#include <linux/param.h>
#include <linux/sched.h> 
#include <linux/kthread.h>

extern int my_flagCount;
static struct task_struct *taskToIncrementFlagCount;

static int flagCount(void* data)
{
    uint32_t i=0;
    printk("::Inside Thread Function::\n");
    for(i = 0;i<10;i++)
    {
        set_current_state(TASK_INTERRUPTIBLE);
    	printk(KERN_INFO "%d.\n", my_flagCount++);
    	schedule_timeout((signed long)30*HZ); // sleep for 30 seconds.
    }
    printk("Done executing the loop for 10 times \n");
    printk("Exiting Thread Function::\n");
    return 0;
}

static int __init modB_init(void)
{
    taskToIncrementFlagCount = kthread_run((int (*)(void *))flagCount,NULL, "mythread");
    return 0;
}

static void __exit modB_exit(void)
{
    if(taskToIncrementFlagCount)
    {
        kthread_stop(taskToIncrementFlagCount);
    }
}

module_init(modB_init);
module_exit(modB_exit);

MODULE_AUTHOR("Shivshankar Manivasagam");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module dependency");

