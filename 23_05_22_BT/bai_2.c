#include <stdio.h>

int main()
{
    int myNum = 50;
    int myNum1 = 19;
    myNum = myNum + myNum1;
    int numX = 0;
    int numY = 0;
    numX = 32767 - myNum;
    numY = -32768 - myNum1;
    myNum1 = myNum1 + numY;
    printf ("numX = %d",myNum);
    printf ("\nnumY = %d",myNum1);
    return 0;
}