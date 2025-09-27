// This is a demonstration of how we can create 
// a function which can deal with variable number of
// arguments, just like printf, scanf functions

#include <stdio.h>
#include <stdarg.h> // Must needed library
#include <string.h>

// A simple function to add variable number of integers
int sum(int num_args, ...); // ... in the prototype represents variable number of arguments

// Let's create our own version of print functionn
void lekho(char *cmd, ...); // we will restrict it into integer and floating point numbers

int main()
{
    int x = 0;
    x = sum(7, 1,2,3,4,5,6,7);
    printf("%d\n", x); 

    lekho("ddfd", 2,3,4.07,4);
    return 0;
}

int sum(int num_args, ...)
{
    va_list arg_list; //It is a sort of a pointer of the argument list.
    
    va_start(arg_list, num_args);//va_start(takes the beginning of the list, parameter name just before the arguments)

    // We want to access the argument
    // for this we can use a loop as it the variable number is
    // unknown, it can be 2 or 100
    
    int i;
    int sum = 0;
    for(i = 0; i < num_args; i++)
    {
        // va_arg(arg_list, int); va_arg(arg_list, type of the data)
        // it returns the argument
        int x = va_arg(arg_list, int);
        sum += x;
    }

    va_end(arg_list); // terminator 
    return sum;
}

void lekho(char *cmd, ...)
{
    va_list list;
    int noOfArg = strlen(cmd); // No of arguments

    va_start(list, cmd);

    int i;
    for(i = 0; i < noOfArg; i++)
    {
        if(cmd[i] == 'd')
        {
            int x = va_arg(list, int);
            printf("%d\n", x);
        }
        else {
            double x = va_arg(list, double);
            printf("%lf\n", x);
        }
    }

    va_end(list);
}