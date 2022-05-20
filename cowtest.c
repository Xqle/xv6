#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    char* str = malloc(4096 * 8);
    str[0] = 'A';
    
    int pid = cow_fork();
    if(pid > 0)
    {
        printf(1, "parent pid: %d | data: %c\n", getpid(), str[0]);
        wait();
        printf(1, "parent pid: %d | data: %c\n", getpid(), str[0]);
        str[0] = 'C';
        printf(1, "parent pid: %d | data: %c\n", getpid(), str[0]);
    }
    else
    {
        sleep(1);
        str[0] = 'B';
        printf(1, "child pid: %d | data: %c\n", getpid(), str[0]);
    }

    exit();
}
