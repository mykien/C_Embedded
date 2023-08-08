#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Hàm kiểm tra giá trị nhập vào có phải là ký tự 0-9?
bool checkValidNumber(const char* str) 
{
    for (int i = 0; i < strlen(str); i++) 
    {
        if (str[i] < '0' || str[i] > '9') 
        {
            return false;
        }
    }
    return true;
}

//Hàm so sánh giá trị 2 chuỗi s1 và s2
int compareStrings(const char* s1, const char* s2) 
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 > len2) 
    {
        return 1;  // trả về s1 lớn hơn
    } 
    else if (len1 < len2) 
    {
        return 2;  // trả về s2 lớn hơn
    } 
    else 
    {
        int cmp = strcmp(s1, s2);
        if (cmp > 0) 
        {
            return 1;  // trả về s1 lớn hơn
        } 
        else if (cmp < 0) 
        {
            return 2;  // trả về s2 lớn hơn
        } 
        else 
        {
            return 0;  // s1 = s2
        }
    }
}

int main() 
{
    char s1[101];
    char s2[101];

        //Nhập chuỗi s1
        printf("Nhap chuoi s1: ");
        //fgets(s1,sizeof(s1),stdin);
        scanf("%s", s1);
        //Nhập chuỗi s2
        printf("Nhap chuoi s2: ");
        //fgets(s1,sizeof(s1),stdin);
        scanf("%s", s2);
        //ktra giá trị chuỗi s1
        if (!checkValidNumber(s1)) 
        {
            printf("Invalid strings. Break program\n");
            return 0;
        }
        //ktra giá trị chuỗi s2
        if (!checkValidNumber(s2)) 
        {
            printf("Invalid strings. Break program\n");
            return 0;
        }
        // Xác định chuỗi lớn có giá trị lớn
        int result = compareStrings(s1, s2);
        if (result == 1) 
        {
            printf("Output: s1 = %s\n",s1);
        } 
        else if (result == 2) 
        {
            printf("Output: s2 = %s\n",s2);
        }
        else 
        {
            printf("Output: s1 = s2\n");
        }
    

    return 0;
}
