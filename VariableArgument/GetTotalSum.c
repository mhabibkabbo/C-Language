// Function with Variable Arguments
// It returns the total sum 
// for strings the summation of all letter's ASCII Value
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int getTotalSum(int, ...);

int main()
{
    int total_sum = getTotalSum(2, "sicc", "I am confident", 2, 'p', 'a', "I will pass", 3, 'p', 'b');   
    printf("%d", total_sum);
    return 0;
}

int getTotalSum(int n, ...)
{
    va_list arg_list;

    va_start(arg_list, n);
    char *s = va_arg(arg_list, char *);
    int i, j;
    int sum = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < strlen(s); j++)
        {
            if(s[j] == 's')
            {
                char *p = va_arg(arg_list, char *);
                while(*p)
                {
                    sum += (*p);
                    p++;
                }
            }
            else if(s[j] == 'c')
            {
                sum += va_arg(arg_list, int);
            }
            else if(s[j] == 'i')
            {
                sum += va_arg(arg_list, int);
            }
        }
    }
    va_end(arg_list);
    return sum;
}
