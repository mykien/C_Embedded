#include <stdio.h>

void swap(int* evenNumber, int* oddNumber)
{
    int temp = *evenNumber;
    *evenNumber = *oddNumber;
    *oddNumber = temp;
}
int main()
{
    int evenNumber = 2;
    int oddNumber = 3;
    printf ("evenNumber: %d, oddNumber: %d\n", evenNumber, oddNumber);
    swap (&evenNumber,&oddNumber);
    printf("evenNumber: %d,oddNumber: %d\n",evenNumber,oddNumber);
    return 0;
}
