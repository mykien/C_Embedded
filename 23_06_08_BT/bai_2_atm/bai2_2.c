#include <stdio.h>
#include <stdbool.h>
//Thêm thư viện gọi các hàm
#include "bai2_my_library_menu_selection.h"


int main() {
    struct Account user = {123456, "Kien", "password", 23, "Nam", 100000};
    bool isLoggedIn = false;
    int choice;
    bool exitProgram = false;
    
    // Vòng lặp cho phép người dùng đăng nhập
    while (!exitProgram) {
              
           
                isLoggedIn = login(&user);
                if (!isLoggedIn) 
                {
                    printf("Dang nhap that bai. Vui long thu lai.\n");
                }

        // Nếu đã đăng nhập thành công, vào vòng lặp menu list
        if (isLoggedIn) {
            // Giao diện menu list
            while (true) {
                printf("\nMENU:\n");
                printf("1. Kiem tra thong tin tai khoan\n");
                printf("2. Rut tien\n");
                printf("3. Chuyen tien\n");
                printf("4. Cap nhat thong tin tai khoan\n");
                printf("5. Thoat\n");
                printf("Nhap lua chon cua ban: ");
                scanf("%d", &choice);
                
                switch (choice) {
                    case 1:
                        checkAccount(user);
                        break;
                    case 2:
                        withdraw(&user);
                        break;
                    case 3:
                        transfer(&user);
                        break;
                    case 4:
                        updateAccount(&user);
                        break;
                    case 5:
                        printf("Da thoat khoi menu list.\n");
                        isLoggedIn = false;
                        break;
                    default:
                        printf("Lua chon khong hop le. Vui long thu lai.\n");
                }
                
                // Nếu không đăng nhập hoặc chọn thoát, thoát khỏi vòng lặp menu list
                if (!isLoggedIn) {
                    break;
                }
            }
        }
    }
    
    return 0;
}
