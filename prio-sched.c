#include "types.h"
#include "stat.h"
#include "user.h"

// 4 Processes infinite loop
int main()
{
    int pid = fork();
    if(pid == 0) chpri(getpid(), 13);
    else chpri(getpid(), 14);

    pid = fork();
    if(pid == 0) chpri(getpid(), 15);


    while(1){}

    exit();
}





