#include <linux/unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
        unsigned int num = atoi(argv[1]);
	printf("num:%d\n", num);
        syscall(437, num);
        return 0;
}

