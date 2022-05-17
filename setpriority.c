#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf(1, "Error! serpriority [PID] [Priority]");
        exit();
    }
    
    int PID, prio;
    PID = atoi(argv[1]);
    prio = atoi(argv[2]);
    chpri(PID, prio);
    
    return 0;
}
