// Thread represents a single, independent sequence
// of executions within a program
// A multi threaded program means multiple segments
// are going on simultaneously when possible 
// sometimes it is not possible for the OS to 
// access the segments run simultaneously but
// both the threads run concurrently

#include <stdio.h>
#include <pthread.h>

void *computation(void *add);

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    long value1 = 5;
    long value2 = 10;
    // creating multiple threads
    pthread_create(&thread1, NULL, computation, (void*) &value1); 
    pthread_create(&thread2, NULL, computation, (void*) &value2);
    // multi-thread system 
    // runs faster than 2 single thread system
    pthread_join(thread1, NULL); 
    pthread_join(thread2, NULL);

    return 0;
}

void *computation(void *add)
{
    long *add_num = (long *) (add);
    printf("Add: %ld\n", *add_num);
    return NULL;
}