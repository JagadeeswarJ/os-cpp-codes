#include <stdio.h>

int mutex = 1;

void wait(int *s)
{
    while (*s <= 0)
        ;
    (*s)--;
}

void signal(int *s)
{
    (*s)++;
}

void critical_section(int id)
{
    wait(&mutex);
    printf("Process %d is in critical section\n", id);
    signal(&mutex);
}

int main()
{
    critical_section(1);
    critical_section(2);
    critical_section(3);
    critical_section(4);
    critical_section(5);
    return 0;
}
