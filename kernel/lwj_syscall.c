#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>

extern int lwj_commit_time;

static int do_changetime(unsigned int time)
{
	int temp_time;
	printk("time: %d\n", time);

    temp_time = lwj_commit_time;
    lwj_commit_time = time;

    printk("[C2J]lwj_commit_time:%u->%uus\n", temp_time, lwj_commit_time);
    return 1;
}
SYSCALL_DEFINE1(changetime, unsigned int, time)
{
	return do_changetime(time);
}
