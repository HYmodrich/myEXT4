#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>

extern int lwj_commit_time;
extern int c2j_max_sleep;
extern int c2j_decision_time;

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

static int do_changemaxsleep(unsigned int time)
{
        int temp_sleep;

    temp_sleep = c2j_max_sleep;
    c2j_max_sleep = time;

    printk("[C2J]c2j_max_sleep:%u->%uus\n", temp_sleep, c2j_max_sleep);
    return 1;
}
SYSCALL_DEFINE1(changemaxsleep, unsigned int, time)
{
        return do_changemaxsleep(time);
}


static int do_changedecisiontime(unsigned int time)
{
        int temp_interval;

    temp_interval = c2j_decision_time;
    c2j_decision_time = time;

    printk("[C2J]c2j_decision_time:%u->%uus\n", temp_interval, c2j_decision_time);
    return 1;
}
SYSCALL_DEFINE1(changedecisiontime, unsigned int, time)
{
        return do_changedecisiontime(time);
}

