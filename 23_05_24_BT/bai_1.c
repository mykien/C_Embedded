#include <stdio.h>

// Hàm ktra số nguyên tố
int checkN(int n) 
{
    if (n <= 1) 
    {
        // Nếu số n là 0 hoặc 1, không phải là số nguyên tố   
        return 0;  
    }

    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            // Nếu số n có ước số khác 1 và chính nó, không phải là số nguyên tố
            return 0;  
        }
    }
// Nếu số n không có ước số khác 1 và chính nó, là số nguyên tố
    return 1;  
}

int main() 
{
    int N;
    printf("Nhap vao so N: ");
    scanf("%d", &N);
    if (N<1 || N>10000)
    {
        printf ("Vui long nhap lai so N (1 < N < 10000)");
    }
    else
    {
        // nếu hàm trả về 1 thì đó là số nguyên tố , hàm trả về 0 đó không phải là số nguyên tố
        if (checkN(N) == 1) 
        {
            printf("%d la so nguyen to.\n", N);
        } 
        else 
        {
            printf("%d khong la so nguyen to.\n", N);
        }
    }

        return 0;
}
