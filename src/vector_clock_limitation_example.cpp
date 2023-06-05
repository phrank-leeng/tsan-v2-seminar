//
// Created by unknown on 31.05.23.
//

#include <cstdio>
#include "vector_clock_limitation_example.h"
#include "pthread.h"

int Global;
int dummy;
int threadCount = 257;

pthread_mutex_t m;

void *Thread1(void *x) {
    // w(x)1
    Global++;
    return NULL;
}

void *ThreadN(void *x) {
    pthread_mutex_lock(&m);
    dummy++;
    pthread_mutex_unlock(&m);
    return NULL;
}

void *Thread257(void *x) {
    // w(x)257
    Global--;
    return NULL;
}

void run() {
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