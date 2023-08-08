#include <stdio.h>
// Khai báo hàm đổi giá trị
void swap(int* x,int* y)
{
    int aux = *x;
    *x = *y;
    *y = aux;

}
int main()
{
    //Nhập giá trị a và b 
    int a,b;
    printf("Nhap gia tri a: ");
    scanf("%d", &a);
    printf("Nhap gia tri b: ");
    scanf("%d", &b);
    // In ra giá trị a và b sau khi hoán đổi giá trị
    swap(&a,&b);
    printf("Sau khi swap gia tri:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
return 0;
}