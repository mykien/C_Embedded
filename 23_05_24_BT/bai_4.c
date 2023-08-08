#include <stdio.h>

int main()
{
    float a,b,x;
    //Nhập dữ liệu
    printf ("nhap he so cua phuong trinh ax + b = 0");
    printf ("\na=");
    scanf ("%f", &a);
    printf ("\nb=");
    scanf ("%f",&b);
    //giải phương trình
    x = -a/b;
    // in kết quả
    printf ("x= %.2f",x);
    return 0;
}