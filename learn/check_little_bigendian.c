#include <stdio.h>

int clear_bit (int* ptr, int a)
{
    *ptr &= ~(1<<a);   //0000 0000

    return *ptr;
}

int all_clear (int* ptr)
{
    *ptr = 0x00000000;
    return *ptr;
}

main ()
{
    int value = 7;
    int a = 0;
    clear_bit(&value, a);
    printf ("a_clearbit = %d\n", value);

    for (int i = 0 ; i < 32 ; i++)
    {
        if ((a & (1 << 2)) != 0);
    }

    all_clear(&value);
    printf ("a_clearbit = %d\n", value);
    




    return 0;
}
typedef struct {
    volatile uint32_t CTRL;     // Control register
    volatile uint32_t DIV;      // Divider register
    // Other SCG registers...
} SCG_REG;

#define SCG_BASE_ADDRESS 0x40064000
#define SCG ((SCG_REG*)SCG_BASE_ADDRESS)

