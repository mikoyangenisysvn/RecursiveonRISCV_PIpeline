//recursive
#include <stdint.h>

#define N_TARGET      100u
#define CANARY_VALUE  0xDEADBEEFu

/*
 * Explicitly placed in the dedicated .canary linker section (see
 * linker.ld), which is emitted right after .bss — the highest address
 * in the .data/.bss/.canary block, closest to where the stack would
 * intrude first on overflow. This placement no longer depends on link
 * order or on being the first .data variable in this file.
 *
 * The testbench writes CANARY_VALUE into DMEM at __canary_start before
 * simulation starts (DMEM is not loaded from imem.hex). main() re-checks
 * this after the recursion returns; a changed value means the stack
 * wrote past its reserved 1.6 KiB budget (100 frames x 32 B) and
 * clobbered .canary/.bss/.data.
 */
volatile uint32_t STACK_CANARY __attribute__((section(".canary"))) = CANARY_VALUE;

/*
 * recursive_sum(n) = 1 + 2 + ... + n, base case n == 0.
 *
 * Left as a plain, unoptimized-looking recursive function on purpose: at
 * -O0 the compiler emits a standard RV32 prologue/epilogue per call
 * (sw ra,12(sp) / sw a0,8(sp) and the matching restores), which is what
 * stresses jal/jalr control hazards and sp/ra/a0 data hazards across the
 * pipeline on every one of the 100 recursive calls.
 */
static int recursive_sum(int n)
{
    if (n == 0) {
        return 0;
    }
    return n + recursive_sum(n - 1);
}

/* C reference model: N(N+1)/2, used to check correctness without recursion. */
static int reference_sum(int n)
{
    return (n * (n + 1)) / 2;
}

int main(void)
{
    int result   = recursive_sum((int)N_TARGET);
    int expected = reference_sum((int)N_TARGET);
    int status   = 0;

    if (STACK_CANARY != CANARY_VALUE) {
        /* Stack overflowed into .canary/.bss/.data during recursion. */
        status = 1;
    } else if (result != expected) {
        /* Wrong result: likely a mishandled forwarding/stall/flush hazard. */
        status = 1;
    }

    return status; /* 0 = pass, 1 = fail (checked in a0 by the testbench) */
}
