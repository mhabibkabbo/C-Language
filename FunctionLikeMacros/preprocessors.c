//demonstration of function like macros
#include <stdio.h>

#define print printf("Print this.\n");

#define inc(x) x + 1 // function like macro 

#define area(base, height) 0.5 * base * height
#define min(x, y) (((x) < (y)) ? x : y)
// typeof(data) is gonna make this macro more generic
#define find_max(array, length) ({ \
    typeof(array[0]) current_max = array[0]; \
    for(int i = 1; i < length; i++) \
        if(array[i] > current_max) \
            current_max = array[i]; \
    current_max; \
})
int main()
{
    print // works .. gcc -E -o d preprocessor.c for details

    int a = 2;
    a = inc(a);
    printf("%d", a);

    int area1 = area(10,20);
    printf("\narea : %d\n", area1);

    int ar[] = {1,2,3,5,6,7,8,4};
    int max_int = find_max(ar, 8);
    printf("%d", max_int);
    return 0;
}