#include <stdio.h>
//Hàm in mảng 
void printArray(int* arr, int n) 
{
    printf("Arr = ");
    int* ptr =arr;

    for (int i = 0; i < n; i++) 
    {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
}

int main() 
{
    unsigned int n;
    //Nhập số lượng phần tử trong mảng
    printf("Nhap n = ");
    scanf("%d", &n);

    int arr[n];

    //Nhập giá trị từng phần tử trong mảng
    printf("Nhap phan tu trong mang:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printArray(arr, n);

    return 0;
}

