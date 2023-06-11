//
// Created by unknown on 31.05.23.
//

#include "thread_count_limitation.h"
#include "pthread.h"
#include "iostream"
using namespace std;

int var1;
int threadCount = 18;
pthread_mutex_t m;

void *Thread1(void *x) {
    // w(x)1
    var1++;
    pthread_mutex_lock(&m);
    pthread_mutex_unlock(&m);
    return NULL;
}

void *ThreadN(void *x) {
    // w(x)n
    pthread_mutex_lock(&m);
    pthread_mutex_unlock(&m);
    cout<<var1;
    return NULL;
}

void *Thread18(void *x) {
    // w(x)257
    var1--;
    return NULL;
}

void thread_count_limitation::run() {
    pthread_t t[threadCount];
    for (int i = 0; i < threadCount; i++) {
        if (i == 0) {
            pthread_create(&t[i], NULL, Thread1, NULL);
        } else if (i == threadCount - 1) {
            pthread_create(&t[i], NULL, Thread18, NULL);
        } else {
            pthread_create(&t[i], NULL, ThreadN, NULL);
        }
    }

    for (pthread_t& thread : t) {
        pthread_join(thread, NULL);
    }
}