#include "pthread.h"

int var1;
pthread_mutex_t var2;

void *Thread1(void *x) {
    // w(x)1
    var1++;
    // acq(y)2
    pthread_mutex_lock(&var2);
    // rel(y)3
    pthread_mutex_unlock(&var2);
    return NULL;
}

void *Thread2(void *x) {
    // acq(y)4
    pthread_mutex_lock(&var2);
    // w(x)5
    var1--;
    // rel(y)6
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
