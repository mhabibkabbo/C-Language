// Thread represents a single, independent sequence
// of executions within a program
// A multi threaded program means multiple segments
// are going on simultaneously when possible 
// sometimes it is not possible for the OS to 
// access the segments run simultaneously but
// both the thread run concurrently

#include <stdio.h>
#include <pthread.h>

void *computation();

int main()
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, computation, NULL); 
    pthread_join(thread1, NULL); 

    return 0;
}

void *computation()
{
    printf("Computation\n");
    return NULL;
}