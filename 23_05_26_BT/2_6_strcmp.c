#include <stdio.h>

void copyString(char source[], char destination[]) 
{
    int i = 0;

    while (source[i] != '\0') 
    {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';
}

int main() {
    char source[100];
    char destination[100];

    printf("Nhap chuoi nguon: ");
    scanf("%s", source);

    copyString(source, destination);

    printf("Chuoi sao chep: %s\n", destination);

    return 0;
}

