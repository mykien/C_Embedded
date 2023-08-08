#include <stdio.h>
// tìm Ước chung lớn nhất
int ucln(int a, int b)
{
    while (b!=0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
// tìm bội chung nhỏ nhất = a*b /UCLN
int bcnn(int a, int b)
{
    return a*b/ucln(a,b);
}

int main()
{
    int a,b ;
    printf ("Nhap so a =");
    scanf ("%d",&a);
    printf ("Nhap so b =");
    scanf ("%d",&b);
    if (a <1 || b > 10000)
    {
        //Nhập lại hệ số a và b
        printf("vui long nhap lai a va b (a >= 1 và b <= 10000)");
    }
    else
    {
        //In ra màn hình ước chung lớn nhất và bội chung nhỏ nhất
        printf ("UCLN a va b la :%d", ucln(a,b));
        printf ("\nBCNN a va b la :%d",bcnn(a,b));
    }
    return 0;

}