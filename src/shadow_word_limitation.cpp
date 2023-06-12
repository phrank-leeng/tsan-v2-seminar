//
// Created by unknown on 31.05.23.
//

#include "shadow_word_limitation.h"
#include "pthread.h"
#include "iostream"
using namespace std;

int var1;
int threadcount = 5;
pthread_mutex_t m;

void *Thread1(void *x) {
    // acq(y)1
    // w(x)2
    var1=1;
    pthread_mutex_lock(&m);
    // rel(y)3
    pthread_mutex_unlock(&m);
    return NULL;
}

void *ThreadN(void *x) {
    // acq(x)
    pthread_mutex_lock(&m);
    pthread_mutex_unlock(&m);
    // r(x)n
    cout<<var1;
    return NULL;
}

void *Thread6(void *x) {
    pthread_mutex_lock(&m);
    pthread_mutex_unlock(&m);
    var1=1;
    return NULL;
}

void shadow_word_limitation::run() {
    pthread_t t[threadcount];
    for (int i = 0; i < threadcount; i++) {
        if (i == 0) {
            pthread_create(&t[i], NULL, Thread1, NULL);
        } else if (i == threadcount - 1) {
            pthread_create(&t[i], NULL, Thread6, NULL);
        } else {
            pthread_create(&t[i], NULL, ThreadN, NULL);
        }
    }

    for (pthread_t& thread : t) {
        pthread_join(thread, NULL);
    }
}