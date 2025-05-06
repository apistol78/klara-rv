.align 6

.globl _start

_start:
    li      t0, 0
__loop:
    sw      zero, 0(t0)
    j       __loop
