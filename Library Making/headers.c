#include <stdio.h> 
#include "library.h"
// running command is a bit different
// you have to compile both file at the same time
// gcc -o <executable file> <first_file> <second_file>
// another alternative is make file

int main()
{
    printf("%d\n", number+10); // this thing accessible because 
                                // we used extern keyword here
    //printf("%d\n", num+12); //this will generate an error message
    printf("%d", add(7,8));
    return 0;
}