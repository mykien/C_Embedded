//Check bit trong 1 thanh ghi đã set lên 1 chưa

#define A (volatile int*)0x001001AB
#define B (volatile int*)0x00200345
#define READ_BIT (reg , bit) (*reg & (1<<bit))
int main()
{
    int a =0 ;
    int b =0;
    if (READ_BIT (&b,2) == 1 ) 
    {
        printf("true");
    }
    if (READ_BIT (&b,1) == 0 )
    {
        printf("False");
    }
    return 0;
}