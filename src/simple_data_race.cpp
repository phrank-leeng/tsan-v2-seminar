//
// Created by unknown on 31.05.23.
//

#include "simple_data_race.h"
#include "pthread.h"

int var;
pthread_mutex_t m;

void *Thread1(void *x) {
    // w(x)1
    var++;
    // acq(y)1
    pthread_mutex_lock(&m);
    // rel(y)1
    pthread_mutex_unlock(&m);
    return NULL;
}

void *Thread2(void *x) {
    // acq(y)2
    pthread_mutex_lock(&m);
    // w(x)2
    var--;
    // rel(y)2
    pthread_mutex_unlock(&m);
    return NULL;
}

void simple_data_race::run() {
    pthread_t t[2];
    pthread_create(&t[0], NULL, Thread1, NULL);
    pthread_create(&t[1], NULL, Thread2, NULL);
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
}
