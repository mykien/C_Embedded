#include <stdio.h>

int daoBit(int num, int k) 
{
    int mask = 1 << (k - 1);  // Tạo một mask với bit thứ K được đặt là 1
    int ketQua = num ^ mask;  // Thực hiện phép XOR để đảo bit thứ K
    
    return ketQua;
}


int main() 
{
    int N = 1;
    int K = 2;

    printf("Gia tri ban dau cua N: %d\n", N);

    // Đảo bit thứ K
    int newN = daoBit(N, K);
    printf("Gia tri moi cua N: %d\n", newN);

    return 0;
}
