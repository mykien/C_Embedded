#include <stdbool.h>
#include <stdio.h>
#include "bai2_my_library_menu_selection.h"
#include <string.h>




//Hàm đăng nhập tài khoản
bool login(struct Account *user)
{
    int accountNumber;
    char password[20];

    printf("**GIAO DIEN DANG NHAP**\n");
    printf("Nhap so tai khoan: ");
    scanf("%d", &accountNumber);
    printf("Nhap mat khau: ");
    scanf("%s", password);
    
    // Kiểm tra thông tin đăng nhập
    if (accountNumber == user->accountNumber && strcmp(password, user->password) == 0)
    {
        return true;
    }

return false;
}

// Hàm kiểm tra thông tin tài khoản
void checkAccount(struct Account user) 
{
    printf("\nThong tin tai khoan cua ban:\n");
    printf("So tai khoan: %d\n", user.accountNumber);
    printf("Ho ten: %s\n", user.name);
    printf("Tuoi: %d\n", user.age);
    printf("Gioi tinh: %s\n", user.sex);
    printf("So du tai khoan: %d VND\n", user.balance);
}

// Hàm rút tiền
void withdraw(struct Account *user) 
{
    int amount;
    
    printf("Nhap so tien muon rut (boi so cua 10,000 VND): ");
    scanf("%d", &amount);
    user->balance -= amount;
    //Ktra tài khoản sau khi rút phải còn lớn hơn 50,000 VND
    if (user->balance < 50000)
        printf("So du tai khoan phai > 50,000 VND.\n");
        return;    
    // Kiểm tra số tiền muốn rút
    if (amount % 10000 != 0) {
        printf("So tien muon rut phai la boi so cua 10,000 VND.\n");
        return;
    }             
    // Cập nhật số dư tài khoản   
    printf("Da rut %d VND tu tai khoan cua ban.\n", amount);
    printf("So du con lai trong tai khoan: %d VND\n", user->balance);
}

// Hàm chuyển tiền
void transfer(struct Account *user) 
{
    int amount;
    int receiverAccountNumber;  //STK nhận chuyển tiền
    
    printf("Nhap so tien muon chuyen (> 10,000 VND): ");
    scanf("%d", &amount);
    
    // Kiểm tra số tiền muốn chuyển
    if (amount < 10000) 
    {
        printf("So tien muon chuyen phai > 10,000 VND.\n");
        return;
    }
    
    // Kiểm tra số dư tài khoản
    if (amount > user->balance) {
        printf("So du trong tai khoan khong du de chuyen tien.\n");
        return;
    }
    
    printf("Nhap so tai khoan nguoi nhan: ");
    scanf("%d", &receiverAccountNumber);
    
    // Thực hiện chuyển tiền 
    
    printf("Da chuyen %d VND den tai khoan %d.\n", amount, receiverAccountNumber);
    printf("So du con lai trong tai khoan: %d VND\n", user->balance - amount);
}

// Hàm cập nhật thông tin tài khoản
void updateAccount(struct Account *user)
 {
    // Thực hiện cập nhật thông tin tài khoản 
    int choice;
    float soTien;
    // Cập nhật số dư tài khoản
    printf("1. Cap nhat so du tai khoan\n");
    printf("2. Thay doi thong tin tai khoan\n");
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:
            //Nhập số dư tài khoản muốn cập nhật
            printf("Nhap so du tai khoan muon cap nhat: ");
            scanf("%d", &soTien);
            user->balance = soTien;
            printf("Cap nhat so du tai khoan thanh cong!\n");
            break;
        case 2:
            printf("1. Thay doi ten\n");
            printf("2. Thay doi mat khau\n");
            printf("3. Thay doi gioi tinh\n");
            printf("4. Thay doi tuoi\n"); 
            printf("Nhap lua chon cua ban: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Nhap ten moi: ");
                    scanf("%s", user->name);
                    printf("Thay đoi ten thanh cong!\n");
                    break;
                case 2:
                    printf("Nhap mat khau moi: ");
                    scanf("%s", user->password);
                    printf("Thay doi mat khau thanh cong!\n");
                    break;
                case 3:
                    printf ("Nhap gioi tinh moi: ");
                    scanf("%s",user->sex);
                    printf("Thay doi gioi tinh thanh cong");
                    break;
                case 4:
                    printf ("Nhap tuoi moi: ");
                    scanf("%d",user->age);
                    printf("Thay doi tuoi thanh cong");
                    break;
                default:
                    printf("Lua chon khong hop le!\n");
                    break;
            }
            break;           
        default:
            printf("Lua chon khong hop le!\n");
            break;

    //printf("Da cap nhat thong tin tai khoan.\n");
}
}