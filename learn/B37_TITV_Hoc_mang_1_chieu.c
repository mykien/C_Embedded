#include <stdio.h>
char c[5] = "text";

void nhapmang(int x[100], int *ptrN)
{
    printf("nhap vao so luong phan tu: ");
    scanf("%d", ptrN); // địa chỉ của biến n 
    for (int i = 0; i < *ptrN; i++)
    {
        printf ("nhap x[%d]", i);
        scanf("%d", &x[i]);
    }
}

void xuatmang(int x[100], int n)
{
    
    printf ("Gia tri cua mang la: ");

    for (int i = 0 ; i < n ; i++)
    {
        printf ("Gia tri cua mang la : %d\n", x[i]);
    }
}



int main()
{
    
    int a[100];
    int n;
    nhapmang(a,&n);
    printf ("n= %d ",n);
    xuatmang(a,n);
    

}
    