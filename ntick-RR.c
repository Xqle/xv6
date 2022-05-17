#include "types.h"
#include "stat.h"
#include "user.h"

// 2 processes infinite loop
int main(int argc, char *argv[])
{
    fork();

    while(1){}

    exit();
}





