#include <bits/stdc++.h>
using namespace std;

int buffer = 0, mutex = 1, empty = 1, full = 0;

void wait(int *s)
{
    while (*s <= 0)
        ;
    (*s)--;
}
void signal(int *s) { (*s)++; }

void produce()
{
    wait(&empty);
    wait(&mutex);
    buffer = 1;
    printf("Produced an item\n");
    signal(&mutex);
    signal(&full);
}

void consume()
{
    wait(&full);
    wait(&mutex);
    buffer = 0;
    printf("Consumed an item\n");
    signal(&mutex);
    signal(&empty);
}

int main()
{
    produce();
    consume();
    produce();
    consume();
    return 0;
}
