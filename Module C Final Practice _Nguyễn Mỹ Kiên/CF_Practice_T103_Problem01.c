#include <stdio.h>
#include <math.h>

//Hàm kiểm tra group bits
int groupsOfBits(int n) 
{
    int count = 0;
    int checkbit = 0;

    while (n > 0) 
    {
        if (n & 1) {
            checkbit++;
        } else {
            if (checkbit > 0) 
            {
                count++;
            }
            checkbit = 0;
        }
        n >>= 1;  // Dịch bit n qua phải 1 vị trí
    }

    if (checkbit > 0) {
        count++;
    }

    return count;
}

int main() {
    int n;
    //Nhập n 
    do {
        printf("Nhap n = ");
        scanf("%d", &n);
    if (n > 0 && n <= pow(10,9))
    {              
    int result = groupsOfBits(n);
    printf("Group of bits: %d\n", result);
    }
    //Nếu n = 0 thì sẽ thoát chương trình, n < 0 hoặc n > 10^9 sẽ nhập lại n
    } while ( n < 0 || n > pow(10,9));

    return 0;
}