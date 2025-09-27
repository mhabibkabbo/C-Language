#include <stdio.h>

void function(int x)
{
    printf("%d\n", x);
}

double add(double x, double y)
{
    return x + y;
}

// A function pointer stores the memory 
// address of a function

int sum (int x, int y);
int divide (int x, int y);
int mult (int x, int y);
int sub (int x, int y);

int (*select_operation()) (int, int);

int main()
{
    // format : <return type> (*pointerName) (parameters)
    void (*functionPointer) (int);

    functionPointer = &function; // stores the 'function' address

    (*functionPointer)(4); // * is used to dereferencing the pointer
                            // (4) passing parameter.
    // this is another pointer
    double (*addpointer) (double, double) = add;
    double a, b;
    a = b = 10;
    double result = (*addpointer)(a, b);
    printf("%lf\n", result);
    

    // We can also create an array of function pointer
    int (*func[]) (int, int) = {sub, sum, mult, divide};
    printf("Product : %d \n", (*func[1]) (2,4));

    // Using function pointer as return type
    int (*operation)(int, int) = select_operation();
    printf("Answer : %d\n", operation(20,40));

    return 0;
}

int sum (int x, int y)
{
    return x + y;
}

int sub (int x, int y)
{
    return x - y;
}

int mult (int x, int y)
{
    return x * y;
}

int divide (int x, int y)
{
    if(y == 0)
    {
        printf("Divide by 0 is not possible.\n");
        return 1;
    }
    else
        return x / y;
}

int (*select_operation())(int, int)
{
    int option = 0;
    printf("Select an operation : \n");
    printf("1) Subtract\n2) Addition\n3) Divide\n4)Multiply\n");
    scanf("%d", &option);
    switch(option)
    {
        case 1 : return sub;
        case 2 : return sum;
        case 3 : return divide;
        case 4 : return mult;
        defualt:
                printf("Unknown Command.\n");
                return NULL;
    }
}
