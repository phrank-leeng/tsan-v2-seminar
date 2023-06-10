//
// Created by unknown on 31.05.23.
//

#include "shadow_word_limitation.h"
#include "pthread.h"
#include "iostream"
using namespace std;

int var1;
int threadCount = 18;

pthread_mutex_t m;

void *Thread1(void *x) {
    // w(x)1
    pthread_mutex_lock(&m);
    var1=1;
    pthread_mutex_unlock(&m);
    return NULL;
}

void *Thread2(void *x) {
    // w(x)1
    pthread_mutex_lock(&m);
    cout<<var1;
    pthread_mutex_unlock(&m);
    return NULL;
}


void *ThreadN(void *x) {
    // r(x)n
    std::cout<<var1;
    return NULL;
}

void *Thread5(void *x) {
    var1=1;
    return NULL;
}

void shadow_word_limitation::run() {
    pthread_t t[threadCount];
    for (int i = 0; i < threadCount; i++) {
        if (i == 0) {
            pthread_create(&t[i], NULL, Thread1, NULL);
        } else if (i == threadCount - 1) {
            pthread_create(&t[i], NULL, ThreadN, NULL);
        } else {
            pthread_create(&t[i], NULL, Thread2, NULL);
        }
    }

    for (pthread_t& thread : t) {
        pthread_join(thread, NULL);
    }
}