#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_THREADS 2

int turn;
bool flag[NUM_THREADS];

void critical_section(int process_id)
{
    printf("Process %d is in the critical section.\n", process_id);
}

void peterson_algorithm(int process_id)
{
    int other_process = 1 - process_id;

    flag[process_id] = true;
    printf("Process %d is trying to enter the critical section.\n", process_id);
    turn = other_process;

    while (flag[other_process] && turn == other_process)
    {
    }

    critical_section(process_id);

    printf("Process %d is leaving the critical section.\n", process_id);
    flag[process_id] = false;
}

void *process(void *arg)
{
    int process_id = *((int *)arg);

    for (int i = 0; i < 5; i++)
    {
        peterson_algorithm(process_id);
    }

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int process_ids[NUM_THREADS] = {0, 1};

    for (int i = 0; i < NUM_THREADS; i++)
    {
        flag[i] = false;
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, process, &process_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
