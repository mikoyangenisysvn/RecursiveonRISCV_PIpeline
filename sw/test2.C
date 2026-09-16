//no recursion
#include <stdint.h>

#define N_TARGET      100u
#define CANARY_VALUE  0xDEADBEEFu

volatile uint32_t STACK_CANARY __attribute__((section(".canary"))) = CANARY_VALUE;

static int iterative_sum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

static int reference_sum(int n)
{
    return (n * (n + 1)) / 2;
}

int main(void)
{
    int result   = iterative_sum((int)N_TARGET);
    int expected = reference_sum((int)N_TARGET);
    int status   = 0;

    if (STACK_CANARY != CANARY_VALUE) {
        status = 1;
    } else if (result != expected) {
        status = 1;
    }

    return status;
}
