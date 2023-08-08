#include <stdio.h>
#include <math.h>

// Hàm tính tổng
float Add(float *a, float *b) 
{
    return (*a) + (*b);
}

// Hàm tính hiệu
float Sub(float *a, float *b) 
{
    return (*a) - (*b);
}

// Hàm tính tích
float Multi(float *a, float *b) 
{
    return (*a) * (*b);
}

// Hàm tính thương
float Div(float *a, float *b) 
{
    return (*a) / (*b);
}

// Hàm tính phần dư sử dụng thư viện math.h
float Mod(float *a, float *b) 
{
    return fmod(*a, *b);
}

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
    printf("Div(A, B) = %.7f\n", Div(&a, &b));  //lấy kết quả đến số thập phân thứ 7
    printf("Mod(A, B) = %.2f\n", Mod(&a, &b));  

    return 0;
}
