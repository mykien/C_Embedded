#include <stdio.h>
//Hàm gộp Array và sắp xếp phần tử trong mảng sau khi tạo (bé -> lớn)
void combineArray(int arr1[], int n, int arr2[], int m, int combine[]) 
{
    int i, j, k;
    int totalSize = n + m;

    // Ghi các phần tử từ mảng arr1 vào mảng combine
    for (i = 0; i < n; i++) 
    {
        combine[i] = arr1[i];
    }

    // Ghi các phần tử từ mảng arr2 vào mảng combine, bắt đầu từ vị trí sau cùng của arr1
    for (j = 0; j < m; j++) 
    {
        combine[n + j] = arr2[j];
    }

    // Sắp xếp mảng combine theo thứ tự tăng dần
    for (i = 0; i < totalSize - 1; i++) {
        for (j = 0; j < totalSize - i - 1; j++) 
        {
            if (combine[j] > combine[j + 1]) 
            {
                int temp = combine[j];
                combine[j] = combine[j + 1];
                combine[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int n, m;
    printf("Nhap so luong phan tu array1[n]= ");
    scanf("%d", &n);
    printf("Nhap so luong phan tu array2[m]= ");
    scanf("%d", &m);

    int arr1[n];
    int arr2[m];
    int combine[n + m];
    //Nhập giá trị phần tử trong mảng 1
    printf("Input_array1[%d]:\n",n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr1[i]);
    }
    //Nhập giá trị phần tử trong mảng 2
    printf("Input_array2[%d]:\n",m);
    for (int i = 0; i < m; i++) 
    {
        scanf("%d", &arr2[i]);
    }
    //Gọi hàm combine 2 mảng
    combineArray(arr1, n, arr2, m, combine);
    //In mảng sau khi gộp và sắp xếp
    printf("Output_array[%d]:\n",(m+n));
    for (int i = 0; i < n + m; i++) 
    {
        printf("%d ", combine[i]);
    }
    printf("\n");

    return 0;
}
