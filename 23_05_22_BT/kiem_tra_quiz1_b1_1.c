#include <stdio.h>

void swap(int evenNumber, int oddNumber)
{
    int temp = evenNumber;
    evenNumber = oddNumber;
    oddNumber = temp;
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
 /* write a C program that compares the length of 2 input strings and return the string that has longer length. if two string are of equal length printf "equal length"
user will input 2 strings step, then program will output the string that is longer
for example: string 1 = "abc", string2 = "qwer". Output should be : string2 = : */