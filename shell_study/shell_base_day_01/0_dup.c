#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    if(fork() != 0) {
        wait(0);
        write(1, "world\n", 6);
    } else {
        int fd = dup(1);
        write(fd, "hello ", 6);
        exit(0);
    }
    return 0;
}

