#include <stdio.h>

int NumLength(char*str)
{
    char* track = str;
    int count = 0;
    while (track[count++]);

    return --count;
}

int strlength (char* s, int n)
{
    int cnt;
    for (int i =0;i<n;i++)
    {
        if (*(s+i)=='/0')
        break;
        else
        cnt++;

    }
    return cnt;
}

int main()
{
    int length;
    char* str_test = "12345678";
    char str_test[100] = "12345678";
    length = NumLength(str_test);
    printf("do dai chuoi la :%d",length);
    return 0;
}