#include "pthread.h"

int var1;
pthread_mutex_t var2;

void *Thread1(void *x) {
    // w(x)1
    var1++;
    // acq(y)1
    pthread_mutex_lock(&var2);
    // rel(y)1
    pthread_mutex_unlock(&var2);
    return NULL;
}

void *Thread2(void *x) {
    // acq(y)2
    pthread_mutex_lock(&var2);
    // w(x)2
    var1--;
    // rel(y)2
    pthread_mutex_unlock(&var2);
    return NULL;
}

int main() {
    pthread_t t[2];
    pthread_create(&t[0], NULL, Thread1, NULL);
    pthread_create(&t[1], NULL, Thread2, NULL);
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
}
