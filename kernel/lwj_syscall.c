#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>

extern int lwj_commit_time;
extern int max_psp;

static int do_changetime(unsigned int time)
{
 	int temp_time;

   	temp_time = lwj_commit_time;
    	lwj_commit_time = time;

    	printk("[C2J]lwj_commit_time:%u->%uus\n", temp_time, lwj_commit_time);
    	return 1;
}
SYSCALL_DEFINE1(changetime, unsigned int, time)
{
	return do_changetime(time);
}

static int change_max_psp(unsigned int num)
{
	int temp_num;
	
	temp_num = max_psp;
	max_psp = num;

	printk("[lwj] max_psp:%u->%d\n", temp_num, max_psp);
	return 1;
}

SYSCALL_DEFINE1(change_max_psp, unsigned int, num)
{
        return change_max_psp(num);
}
