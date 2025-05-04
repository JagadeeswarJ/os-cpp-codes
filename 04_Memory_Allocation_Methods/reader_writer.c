#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, rw_mutex;
int read_count = 0;

void* reader(void* arg) {
    int reader_id = *((int*)arg);

    sem_wait(&mutex);
    read_count++;
    if (read_count == 1) {
        sem_wait(&rw_mutex);
    }
    sem_post(&mutex);

    printf("Reader %d is reading the resource.\n", reader_id);
    sleep(1);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0) {
        sem_post(&rw_mutex);
    }
    sem_post(&mutex);

    printf("Reader %d has finished reading.\n", reader_id);
    return NULL;
}

void* writer(void* arg) {
    int writer_id = *((int*)arg);

    sem_wait(&rw_mutex);
    printf("Writer %d is writing to the resource.\n", writer_id);
    sleep(2);
    sem_post(&rw_mutex);

    printf("Writer %d has finished writing.\n", writer_id);
    return NULL;
}

int main() {
    pthread_t readers[5], writers[2];
    int reader_ids[5] = {1, 2, 3, 4, 5};
    int writer_ids[2] = {1, 2};

    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);

    for (int i = 0; i < 5; i++) {
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }
    for (int i = 0; i < 2; i++) {
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&rw_mutex);

    return 0;
}
