#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define PRO_NUM 3   // Number of producer threads
#define CON_NUM 2   // Number of consumer threads
#define BUFFER_SIZE 3 // Size of the buffer (Ps:can be changed!!!To simulate Bobo's expected execution, I set 3 here!!!)

pthread_cond_t n_full;  // Condition variable for buffer not full
pthread_cond_t n_empty; // Condition variable for buffer not empty
pthread_mutex_t mutex;   // Mutex for critical section
int buffer[BUFFER_SIZE]; 
int in_index = 0;       // Index to insert into the buffer
int out_index = 0;      // Index to remove from the buffer
int g_num = 0;          // Number of products in the buffer

// Producer thread function
void* pro_route(void* arg) {
    int id = *((int*)arg);
    while (1) {
        pthread_mutex_lock(&mutex);
        while (g_num == BUFFER_SIZE) {
            printf("Producer thread %d must wait.\n", id);
            pthread_cond_wait(&n_empty, &mutex); // Buffer is full, wait
        }
        // Produce an item
        int item = rand() % 100 + 1; // Random item to produce
        buffer[in_index] = item;
        in_index = (in_index + 1) % BUFFER_SIZE;
        g_num++;
        printf("Producer thread %d now produces\n", id);
        printf("The number of products produced %d\n", g_num);
        pthread_cond_signal(&n_full); // Signal that buffer is not full
        pthread_mutex_unlock(&mutex);
        // No need to free(arg) here, as we are using a loop
        sleep(1); // Simulate time taken to produce an item
    }
    return NULL;
}

// Consumer thread function
void* con_route(void* arg) {
    int id = *((int*)arg);
    while (1) {
        pthread_mutex_lock(&mutex);
        while (g_num == 0) {
            printf("Consumer thread %d must wait.\n", id);
            pthread_cond_wait(&n_full, &mutex); // Buffer is empty, wait
        }
        // Consume an item
        int item = buffer[out_index];
        out_index = (out_index + 1) % BUFFER_SIZE;
        g_num--;
        printf("The consumer thread %d consumes product %d\n", id, item);
        printf("The consumer thread %d has finished consuming product\n", id);
        pthread_cond_signal(&n_empty); // Signal that buffer is not full
        pthread_mutex_unlock(&mutex);
        sleep(1); // Simulate time taken to consume an item
    }
    return NULL;
}

int main() {
    // Bobo's code is: [srand(getpid());]
    srand((unsigned int)time(NULL)); // This line is different from Teacher Bobo's code: I wanna ensure the program to create values referring to current time

    pthread_t tids[PRO_NUM + CON_NUM];

    // Initialize mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&n_full, NULL);
    pthread_cond_init(&n_empty, NULL);

    // Create producer threads
    for (int i = 0; i < PRO_NUM; ++i) {
        int* p = (int*)malloc(sizeof(int));
        *p = i;
        pthread_create(&tids[i], NULL, pro_route, p);
    }

    // Create consumer threads
    for (int i = 0; i < CON_NUM; ++i) {
        int* p = (int*)malloc(sizeof(int));
        *p = i;
        pthread_create(&tids[i + PRO_NUM], NULL, con_route, p);
    }

    // Wait for all threads to finish (this will never happen in this loop)
    for (int i = 0; i < PRO_NUM + CON_NUM; ++i) {
        pthread_join(tids[i], NULL);
    }

    // Destroy mutex and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&n_full);
    pthread_cond_destroy(&n_empty);

    return 0;
}