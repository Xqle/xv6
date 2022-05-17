#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int id = sem_create(1); // create semaphore
    int pid = fork();
    int i, n;
    for(i = 0; i < 100000; i++)
    {
        sem_p(id);          // acquire resource
        n = sh_var_read();
        sh_var_write(n + 1);
        sem_v(id);          // release resource
    }

    if(pid == 0) printf(1, "Child Process: sum = %d\n", sh_var_read());
    else printf(1, "Parent Process: sum = %d\n", sh_var_read());
    if(pid > 0)
    {
        wait();
        sem_free(id);   // free semaphore
    }

    exit();
}




