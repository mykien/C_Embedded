#include <stdio.h>
#include <stdint.h>

int main()
{
//Set các bit trong 1 thanh ghi lên 1
#define A *(volatile int*)0x00101AB
#define SETBIT (reg, bit) reg|= (1 << bit)
uint32_t* A = SETBIT (*A, 2) |
              SETBIT (*A,3) |
              SETBIT (*A,6);
uint32_t* B = *A;

printf ("%x",*B);
return 0;
}

