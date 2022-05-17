#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[])
{
    // s1o0 should be allocated to it
    char* str1 = salloc(20);
    str1[0] = '1';
    printf(1, "VM of str1: %p | content: %c\n\n", str1, str1[0]);
    
    // s1o1 should be allocated to it
    char* str2 = salloc(21);
    str2[0] = '2';
    printf(1, "VM of str2: %p | content: %c\n\n", str2, str2[0]);
    
    // free s1o0
    sfree(str1);
    printf(1, "\n");

    // s1o0 should be allocated to it
    char* str3 = salloc(22);
    str3[0] = '3';
    printf(1, "VM of str3: %p | content: %c\n\n", str3, str3[0]);
   
    sfree(str2);    // free s1o1
    printf(1, "\n");
   
    sfree(str3);    // free s1o0 & undo mapping
    printf(1, "\n");

    // s1o0 should be allocated to it
    char* str4 = salloc(22);
    str4[0] = '4';
    printf(1, "VM of str4 %p | content: %c\n\n", str4, str4[0]);

    exit();  // there will be error if use "return 0;"
}




