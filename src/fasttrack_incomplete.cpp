//
// fasttrack_incomplete to show incompleteness of TSan v2, as shown on slides

#include "fasttrack_incomplete.h"
#include <pthread.h>
#include <stdio.h>

#include <pthread.h>
#include <stdio.h>

int Global;

void *Thread1(void *x) {
    // w(x)1
    Global++;
    return NULL;
}

void *Thread2(void *x) {
    // w(x)2
    Global--;
    // w(x)3
    Global++;
    return NULL;
}

int main() {
    pthread_t t[2];
    pthread_create(&t[0], NULL, Thread1, NULL);
    pthread_create(&t[1], NULL, Thread2, NULL);
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
}