#include <pthread.h>

int var;

void *Thread1(void *x) {
    // w(x)1
    var++;
    return NULL;
}

void *Thread2(void *x) {
    // w(x)2
    var--;
    // w(x)3
    // this write will not be reported as part of a data race
    var++;
    return NULL;
}

int main() {
    pthread_t t[2];
    pthread_create(&t[0], NULL, Thread1, NULL);
    pthread_create(&t[1], NULL, Thread2, NULL);
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
}
