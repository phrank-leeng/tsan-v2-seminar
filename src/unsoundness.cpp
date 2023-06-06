//
// Created by unknown on 06.06.23.
//
#include <pthread.h>
#include "unsoundness.h"

int var1;
int var2;

void *Thread1(void *x) {
    // w(x)1
    var2 = var1 + 5;
    return NULL;
}

void *Thread2(void *x) {
    // w(x)2
    if (var2 == 5)
        var1 = 10;
    else
        while (true);
    return NULL;
}

void unsoundness::run() {
    pthread_t t[2];
    pthread_create(&t[0], NULL, Thread1, NULL);
    pthread_create(&t[1], NULL, Thread2, NULL);
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
}