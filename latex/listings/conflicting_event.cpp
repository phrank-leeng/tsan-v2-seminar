#include "pthread.h"

int x;
pthread_mutex_t y;

void *Thread1(void *x) {
    // w(x)1
    x++;
    // acq(y)1
    pthread_mutex_lock(&y);
    // rel(y)1
    pthread_mutex_unlock(&y);
    return NULL;
}

void *Thread2(void *x) {
    // acq(y)2
    pthread_mutex_lock(&y);
    // w(x)2
    x--;
    // rel(y)2
    pthread_mutex_unlock(&y);
    return NULL;
}

int main() {
    pthread_t t[2];
    pthread_create(&t[0], NULL, Thread1, NULL);
    pthread_create(&t[1], NULL, Thread2, NULL);
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
}
