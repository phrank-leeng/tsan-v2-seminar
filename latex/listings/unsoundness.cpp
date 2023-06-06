#include <pthread.h>

int var1;
int var2;

void *Thread1(void *x) {
    // r(x)1
    // w(y)2
    var2 = var1 + 5;
    return NULL;
}

void *Thread2(void *x) {
    // r(y)3
    if (var2 == 5)
    	// w(x)4
        var1 = 10;
    else
        while (true);
    return NULL;
}

int main() {
    pthread_t t[2];
    pthread_create(&t[0], NULL, Thread1, NULL);
    pthread_create(&t[1], NULL, Thread2, NULL);
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
}
