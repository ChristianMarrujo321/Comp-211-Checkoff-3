#include <stdio.h>

int main(void) {
    long long sum = 0;

    for (long long i = 0; i < 1000000000; i++) {   // 1 billion iterations
        sum += i % 7;
    }

    printf("%lld\n", sum);
    return 0;
}
