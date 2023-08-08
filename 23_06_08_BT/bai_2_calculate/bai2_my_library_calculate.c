#include "bai2_my_library_calculate.h"
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
