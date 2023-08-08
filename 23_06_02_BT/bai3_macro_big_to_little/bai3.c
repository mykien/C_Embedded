#include <stdio.h>
#include <stdint.h>

#define BIG_TO_LITTLE_ENDIAN_32(value) (((value) >> 24) & 0xFF) | (((value) >> 8) & 0xFF00) | (((value) << 8) & 0xFF0000) | (((value) << 24) & 0xFF000000)

int main() 
{
    uint32_t input = 0x12345678;
    uint32_t output = BIG_TO_LITTLE_ENDIAN_32(input);

    printf("Input: 0x%x\n", input);
    printf("Output: 0x%x\n", output);

    return 0;
}
