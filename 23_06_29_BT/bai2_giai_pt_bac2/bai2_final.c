#include <stdio.h>
#include <math.h>

// Hàm giải phương trình bậc 2
void giaiPt(float a, float b, float c) 
{
    if (a == 0 && b == 0 && c == 0) 
    {
        printf("Thoat chuong trinh.\n");
        return;
    }

    if (a == 0) 
    {
        if (b == 0) 
        {
            if (c != 0)
            {
                printf("Phuong trinh vo nghiem.\n");
            }
        } else 
        {
            float x = -c / b;
            printf("Phuong trinh chi co 1 nghiem la: x = %.3f\n", x);
        }
    } else 
    {
        //Tính delta
        float delta = pow(b,2) - 4 * a * c;

        if (delta > 0) 
        {
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Phuong trinh co 2 nghiem la: x1 = %.3f, x2 = %.3f\n", x1, x2);
        } 
        else if (delta == 0) 
        {
            float x = -b / (2 * a);
            printf("Phuong trinh co 1 nghiem la: x = %.3f\n", x);
        } 
        else 
        {
            printf("Phuong trinh vo nghiem.\n");
        }
    }
}

int main() 
{
    float a, b, c;
    //Vòng lặp vô hạn while , cho đến khi gặp a=0,b=0,c=0
    while (1) 
    {
        printf("Nhap a: ");
        scanf("%f", &a);
        printf("Nhap b: ");
        scanf("%f", &b);
        printf("Nhap c: ");
        scanf("%f", &c);
        printf("He pt: %.3fx^2 + %.3fx + %.3f = 0\n", a,b,c); 
        giaiPt(a, b, c);    
        if (a == 0 && b == 0 && c == 0) 
        {
            break;
        }
              
    }

    return 0;
}
