#include <stdio.h>

int main() {
    char c[5] = {1, 2, 3, 4, 5};

    int* a;
    char* charPtr;

    a = (int*)&c[0]; // Ép kiểu con trỏ từ int* sang int* (không có sự thay đổi)

    charPtr = (char*)a; // Ép kiểu con trỏ từ int* sang char*

    printf("%c", *charPtr);

    return 0;
}
