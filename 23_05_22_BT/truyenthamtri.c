#include <stdio.h>

// Hàm tăng giá trị của biến a bằng 1 sử dụng truyền tham trị
void increaseValue(int a) {
    a++; // Tăng giá trị của biến a lên 1
    printf("a trong ham: %d\n", a);
}

int main() {
    int num = 5;
    printf("ban dau: %d\n", num);

    // Truyền tham trị biến num vào hàm increaseValue
    increaseValue(num);

    printf("sau khi tang: %d\n", num);

    return 0;
}
