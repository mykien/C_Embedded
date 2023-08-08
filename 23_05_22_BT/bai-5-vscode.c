#include <stdio.h>
#include <string.h>

struct car
{
    char chCode[20]; // Mã xe
    char chType[30]; // Loại xe
    char chBrand[30]; // Hãng xe
    int nCost; // Giá xe
    int nSeat; // Số ghế
    int nWeight; // Trọng lượng xe
};


//Hàm nhập thông tin xe
void nhapThongtinXe(struct car xe)
{
    printf("Ma xe: ");
    fflush(stdin);
    fgets(xe.chCode, sizeof(xe.chCode), stdin);
    getchar();
    printf ("\nloai xe: ");   
    fflush(stdin);
    fgets(xe.chType, sizeof(xe.chType), stdin);
    getchar();
    printf ("\nHang xe: ");
    fflush(stdin);
    fgets(xe.chBrand, sizeof(xe.chBrand), stdin);
    getchar();
    printf ("\nGia xe: ");
    
    scanf ("%d", &xe.nCost);
    getchar();
   
    printf ("\nSo ghe: ");
 
    scanf ("%d", &xe.nSeat);
    getchar();
    printf ("\nTrong luong xe: ");

    scanf ("%d", &xe.nWeight);
    getchar();

}
void inThongtinXe (struct car xe)
{
    printf ("Ma xe: %s", xe.chCode);
    printf ("\nLoai xe: %s", xe.chType);
    printf ("\nHang xe: %s", xe.chCode);
    printf ("\ngia xe: %d", xe.nCost);
    printf ("\nSo ghe: %d", xe.nSeat);
    printf ("\nTrong luong xe: %d", xe.nWeight);
}
int main()
{
    struct car xe1;
    nhapThongtinXe(xe1);
    inThongtinXe(xe1);
    return 0;
}