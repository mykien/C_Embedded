#include <stdio.h>
#include "bai2_my_library_calculate.h"
int main() 
{
    float a, b;

    printf("Nhap so A: ");
    scanf("%f", &a);
    printf("Nhap so B: ");
    scanf("%f", &b);

    printf("Add(A, B) = %.2f\n", Add(&a, &b));
    printf("Sub(A, B) = %.2f\n", Sub(&a, &b));
    printf("Multi(A, B) = %.2f\n", Multi(&a, &b));
    printf("Div(A, B) = %.7f\n", Div(&a, &b));  
    printf("Mod(A, B) = %.2f\n", Mod(&a, &b));  

    return 0;
}
