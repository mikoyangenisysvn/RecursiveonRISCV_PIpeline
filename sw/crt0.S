.section .text.init, "ax", @progbits
.align 2
.globl  _start
.type   _start, @function

/*
 * RV32I startup code for the 5-stage pipelined core (Final Lab).
 *
 * IMEM : 0x0000_0000 - 0x0000_03FF (1 KiB, rx) -- code
 * DMEM : 0x0000_0400 - 0x0000_13FF (4 KiB, rw) -- .data/.bss/.canary (grows up)
 *                                                  stack             (grows down)
 *
 * _stack_top is defined by linker.ld as the top of DMEM (0x0000_1400).
 * recursive_sum(100) pushes 100 frames of 32 B each (3.2 KiB), well inside
 * the upper half of DMEM reserved for the stack.
 */
_start:
    /* Initialize gp so any gp-relative loads GCC emits (e.g. for the
     * canary check) resolve correctly, per __global_pointer$ in linker.ld.
     * norelax prevents the assembler from "optimizing" this into a single
     * relaxed instruction before gp itself is set. */
    .option push
    .option norelax
    lui     gp, %hi(__global_pointer$)
    addi    gp, gp, %lo(__global_pointer$)
    .option pop

    lui     sp, %hi(__stack_top)
    addi    sp, sp, %lo(__stack_top)

    /* Zero-initialize .bss (STACK_CANARY and .data are already set by their
     * initializers in the loaded image; anything left in .bss must not
     * carry leftover/garbage values from DMEM's pre-simulation state). */
    la      t0, __bss_start
    la      t1, __bss_end

.Lbss_zero_loop:
    bge     t0, t1, .Lbss_zero_done
    sw      zero, 0(t0)
    addi    t0, t0, 4
    j       .Lbss_zero_loop

.Lbss_zero_done:
    /* main() returns 0 (pass) or 1 (fail) in a0. */
    jal     ra, main

/* No OS to receive main's return value -- spin so the testbench can
 * detect completion (_halt-loop detection watches PC staying here). */
.Lhalt:
    j       .Lhalt

    .size   _start, . - _start
    .section .note.GNU-stack, "", @progbits


