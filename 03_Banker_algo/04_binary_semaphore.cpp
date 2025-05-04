#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct
{
    int value;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} binary_semaphore;

void init_semaphore(binary_semaphore *sem, int initial_value)
{
    sem->value = initial_value;
    pthread_mutex_init(&sem->mutex, NULL);
    pthread_cond_init(&sem->cond, NULL);
}

void wait(binary_semaphore *sem)
{
    pthread_mutex_lock(&sem->mutex);
    while (sem->value == 0)
    {
        pthread_cond_wait(&sem->cond, &sem->mutex);
    }
    sem->value = 0;
    pthread_mutex_unlock(&sem->mutex);
}

void signal(binary_semaphore *sem)
{
    pthread_mutex_lock(&sem->mutex);
    sem->value = 1;
    pthread_cond_signal(&sem->cond);
    pthread_mutex_unlock(&sem->mutex);
}

void *thread_func(void *arg)
{
    binary_semaphore *sem = (binary_semaphore *)arg;
    printf("Thread is trying to enter critical section.\n");
    wait(sem);
    printf("Thread is in critical section.\n");
    sleep(2);
    printf("Thread is leaving critical section.\n");
    signal(sem);
    return NULL;
}

int main()
{
    binary_semaphore sem;
    init_semaphore(&sem, 1);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread_func, &sem);
    pthread_create(&t2, NULL, thread_func, &sem);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&sem.mutex);
    pthread_cond_destroy(&sem.cond);

    return 0;
}
