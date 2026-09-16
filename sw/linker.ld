OUTPUT_ARCH(riscv)
ENTRY(_start)

/*
 * Final Lab memory map (5-stage pipeline core).
 *
 * IMEM is 1 KiB, addressed by PC[31:2], and holds executable code
 * (0x0000_0000 - 0x0000_03FF).
 * DMEM is a separate 4 KiB data memory starting right after IMEM
 * (0x0000_0400 - 0x0000_13FF). .data/.bss/.canary are placed at the
 * bottom of DMEM and grow upward; the call stack starts at the very
 * top of DMEM (_stack_top = 0x0000_1400) and grows downward, so the
 * two regions grow toward each other. crt0.S initializes sp = _stack_top.
 *
 * .data and .canary carry real initial values and are emitted into
 * dmem_init.hex (via objcopy) for $readmemh into DMEM at sim start.
 * .bss stays NOLOAD -- it has no initializer and is zero-filled at
 * runtime by crt0.S instead of being embedded in the hex image.
 *
 * recursive_sum(100) uses 100 stack frames x 32 B = 3.2 KiB. The lower
 * half of DMEM (2 KiB) is reserved for .data/.bss/.canary so there is
 * always >= 2 KiB of headroom between the deepest stack frame and the
 * top of .canary.
 */
MEMORY
{
    IMEM (rx)  : ORIGIN = 0x00000000, LENGTH = 0x400
    DMEM (rw)  : ORIGIN = 0x00000400, LENGTH = 0x1000
}

SECTIONS
{
    .text : ALIGN(4)
    {
        KEEP(*(.text.init))
        *(.text .text.*)
    } > IMEM
    . = ALIGN(4);
    __text_end = .;

    .data : ALIGN(4)
    {
        __data_start = .;
        *(.sdata .sdata.*)
        *(.data .data.*)
        *(.rodata .rodata.*)
        __data_end = .;
    } > DMEM

    .bss (NOLOAD) : ALIGN(4)
    {
        __bss_start = .;
        *(.sbss .sbss.*)
        *(.bss .bss.*)
        *(COMMON)
        __bss_end = .;
    } > DMEM

    /*
     * Dedicated section for the stack canary, placed immediately after
     * .bss so it sits at the highest address of the .data/.bss/.canary
     * block -- right where the stack would intrude first on overflow.
     * Explicitly section-tagged in main.c
     * (__attribute__((section(".canary")))) so its placement does not
     * depend on link order. NOT marked NOLOAD -- unlike .bss, it carries
     * a real initializer (CANARY_VALUE) that must be embedded in the
     * ELF so it appears in dmem_init.hex.
     */
    .canary : ALIGN(4)
    {
        __canary_start = .;
        *(.canary)
        __canary_end = .;
    } > DMEM

    /* Kept for toolchain compatibility; this lab builds with small data off. */
    __global_pointer$ = ORIGIN(DMEM) + 0x200;

    /* Stack starts at the top of DMEM and grows downward. */
    __stack_top = ORIGIN(DMEM) + LENGTH(DMEM);
    _stack_top = __stack_top;

    /DISCARD/ :
    {
        *(.comment)
        *(.note*)
        *(.eh_frame*)
    }

    .riscv.attributes 0 :
    {
        *(.riscv.attributes)
    }

    ASSERT(__text_end <= ORIGIN(IMEM) + LENGTH(IMEM),
           "ERROR: program does not fit in the 1 KiB instruction memory")
    ASSERT(__canary_end <= ORIGIN(DMEM) + 0x800,
           "ERROR: .data/.bss/.canary overflow into the half of DMEM reserved for the stack")
}


