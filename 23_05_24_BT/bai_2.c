#include <stdio.h>

int main()
{
    int n;
    // Nhập vào một số 
    printf ("nNhap vao 1 so : ");
    scanf ("%d",&n);
    // Kiểm tra số đó là chẵn hay lẻ
    if (n % 2 == 0)
    {
        // in ra đây là số chẵn
        printf ("%d la so chan ", n);
    }
    else
    {
        // in ra đây là số lẻ
        printf ("%d la so le",n);
    }
return 0;

}