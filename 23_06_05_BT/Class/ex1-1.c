#include <stdio.h>
#include <stdint.h>

#define A (*(volatile int*)0x00101AB)
#define SETBIT(reg, bit) (reg |= (1 << bit))

int main()
{
    SETBIT(A, 2);
    SETBIT(A, 3);
    SETBIT(A, 6);

    uint32_t* B = (uint32_t*)&A;

    printf("%x\n", *B);
    
    return 0;
}
