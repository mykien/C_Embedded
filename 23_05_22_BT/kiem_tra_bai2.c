#include <stdio.h>
#include <string.h>

int main() 
{
    //khai bao
    char string1[100];
    char string2[100];
    //nhap chuoi
    printf("Nhap string1: ");
    fgets(string1, sizeof(string1), stdin);

    printf("Nhap string2: ");
    fgets(string2, sizeof(string2), stdin);


    int length1 = strlen(string1);
    int length2 = strlen(string2);

    //so sanh do dai string
    if (length1 > length2) 
    {
        printf("String1:%s\n", string1);
    } 
    else if (length2 > length1) 
    {
        printf("String2:%s\n", string2);
    } 
    else 
    {
        printf("Equal length\n");
    }

    return 0;
}
