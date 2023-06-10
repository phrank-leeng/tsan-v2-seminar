//
// Created by unknown on 31.05.23.
//

#include "vector_clock_limitation_example.h"
#include "pthread.h"

int var1;
int var2;
int threadCount = 258;

pthread_mutex_t m;

void *Thread1(void *x) {
    // w(x)1
    var1++;
    return NULL;
}

void *ThreadN(void *x) {
    // w(x)n
    if (var2 == 1) {}
    for (int i = 0; i<10000*10000; i++) {
    }
    return NULL;
}

void *Thread257(void *x) {
    // w(x)257
    var1--;
    return NULL;
}

void vector_clock_limitation_example::run() {
    pthread_t t[threadCount];
    for (int i = 0; i < threadCount; i++) {
        if (i == 0) {
            pthread_create(&t[i], NULL, Thread1, NULL);
        } else if (i == threadCount - 1) {
            pthread_create(&t[i], NULL, Thread257, NULL);
        } else {
            pthread_create(&t[i], NULL, ThreadN, NULL);
        }
    }

    for (pthread_t& thread : t) {
        pthread_join(thread, NULL);
    }
}