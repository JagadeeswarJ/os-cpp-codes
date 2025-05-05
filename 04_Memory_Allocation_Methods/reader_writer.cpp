#include <stdio.h>

int readcount = 0, wrt = 1, mutex = 1;

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

void reader(int id)
{
    wait(&mutex);
    readcount++;
    if (readcount == 1)
        wait(&wrt);
    signal(&mutex);

    printf("Reader %d is reading\n", id);

    wait(&mutex);
    readcount--;
    if (readcount == 0)
        signal(&wrt);
    signal(&mutex);
}

void writer(int id)
{
    wait(&wrt);
    printf("Writer %d is writing\n", id);
    signal(&wrt);
}

int main()
{
    reader(1);
    reader(2);
    writer(1);
    reader(3);
    writer(2);
    return 0;
}

