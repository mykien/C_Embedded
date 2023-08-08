#include <stdio.h.>
#include <stdio.h>

int main()
{
    char string1[100];
    char string2[100];
    char* ptr;
    int i = 0;
    int count1 = 0;
    int count2 = 0;
    printf ("Nhap string1 :");
    fflush(stdin);
    fgets(string1, sizeof(string1), stdin);
    printf ("Nhap string2 :");
    fflush(stdin);
    fgets(string2, sizeof(string2), stdin);

    for (i; i < 100;i++)
    {
        if (string1[i] !=0)
        {
            count1 = count1 + 1;
            string1[i]="0";
            
        }
        if (string2[i] != "0")
        {
            count2 = count2 + 1;
            string2[i]=0;
        }
    }
    printf("count1 : %d\n", count1);
    printf("count2 : %d\n", count2);
    int strcmp(string1 , string2);
    
    if (count1 == count2)
    {
        printf("equal");
    }
    else if (count1 > count2)
    {
        printf ("string1 > string2");
    }
    else
    {
        printf ("string2 > string1");
    }
    return 0;

}