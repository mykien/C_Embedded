#include <stdio.h>
#include <stdbool.h>

typedef enum
{
  a1,
  a2,
  a3,
  a4,
  a5,
  a6,
  a7,
  a8,
  a9,
  a10,
  a11,
  a12,
  a13,
  a14,
  a15, 
} Kien;
bool test_bool;

typedef struct test1 
{
  bool e_1;
  char kien1[3];
  Kien hoai;
}test;



int func(int a, int b) {
    // Biến local trong hàm func
    int localVar1 = 10;
    int localVar2 = 20;

    // Kích thước của biến local
    int size_localVar1 = sizeof(localVar1);
    int size_localVar2 = sizeof(localVar2);
    int size_a = sizeof(a);
    int size_b = sizeof(b);

    //int sum = a + b;

    // Tổng dung lượng RAM sử dụng trong hàm func
    int total_ram = size_localVar1 + size_localVar2 + size_a + size_b;


    printf("Size of RAM used by variables in func function:\n");
    printf("localVar1 (func function): %d bytes\n", size_localVar1);
    printf("localVar2 (func function): %d bytes\n", size_localVar2);
    printf("size a = %d\n", size_a);
    printf("size b = %d",size_b);
    printf("\nTotal RAM used by variables in func function: %d bytes\n", total_ram);

    return a + b;
}

int main() {
    int* ptr1;
    char* ptr2;
    // Biến local trong hàm main
    int x = 5;
    int y = 10;
    int sum;

    // Kích thước của biến local trong hàm main
    int size_x = sizeof(x);
    int size_y = sizeof(y);
    func(x,y);
    // Kích thước của hàm func
    int size_func = sizeof(func);

    // Tổng dung lượng RAM sử dụng trong hàm main
    int total_ram_main = size_x + size_y + size_func;

   

    printf("\nSize of RAM used by variables in main function:\n");
    printf("x (main function): %d bytes\n", size_x);
    printf("y (main function): %d bytes\n", size_y);
    printf("func (main function): %d bytes\n", size_func);
    printf("\nTotal RAM used by variables in main function: %d bytes\n", total_ram_main);
    printf("\nsize enum = %zu", sizeof(Kien));
    printf ("\nsize struc = %d",sizeof(test));
    printf ("\nsize ptr1: %d",sizeof(ptr1));
    printf ("\nsize ptr1: %d",sizeof(ptr2));
    printf ("\nsize_bool = %d", sizeof(test_bool));
      return 0;
  }
