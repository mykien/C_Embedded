#include <stdio.h>
#include <stdbool.h>

// Khai báo cấu trúc tài khoản người dùng
struct Account {
    int accountNumber;
    char name[50];
    char password[20];
    int age;
    char sex[10];
    int balance;
};

// Hàm đăng nhập tài khoản
bool login(struct Account *user) {
    int accountNumber;
    char password[20];
    
    printf("Nhap so tai khoan: ");
    scanf("%d", &accountNumber);
    printf("Nhap mat khau: ");
    scanf("%s", password);
    
    // Kiểm tra thông tin đăng nhập
    // (giả sử thông tin tài khoản đã được lưu trước đó)
    if (accountNumber == 123456 && strcmp(password, "123456") == 0) {
        // Gán thông tin tài khoản người dùng đã đăng nhập
        user->accountNumber = accountNumber;
        strcpy(user->name, "Nguyen Van A");
        strcpy(user->password, "123456");
        user->age = 30;
        strcpy(user->sex, "Nam");
        user->balance = 50000000;
        
        return true;
    }
    
    return false;
}

// Hàm kiểm tra thông tin tài khoản
void checkAccount(struct Account user) {
    printf("Thong tin tai khoan:\n");
    printf("So tai khoan: %d\n", user.accountNumber);
    printf("Ho ten: %s\n", user.name);
    printf("Tuoi: %d\n", user.age);
    printf("Gioi tinh: %s\n", user.sex);
    printf("So du tai khoan: %d VND\n", user.balance);
}

// Hàm rút tiền
void withdraw(struct Account *user) {
    int amount;
    
    printf("Nhap so tien muon rut (boi so cua 10,000 VND): ");
    scanf("%d", &amount);
    
    // Kiểm tra số tiền muốn rút
    if (amount % 10000 != 0) {
        printf("So tien muon rut phai la boi so cua 10,000 VND.\n");
        return;
    }
    
    // Kiểm tra số dư tài khoản
    if (amount > user->balance) {
        printf("So du trong tai khoan khong du de rut tien.\n");
        return;
    }
    
    // Cập nhật số dư tài khoản
    user->balance -= amount;
    
    printf("Da rut %d VND tu tai khoan cua ban.\n", amount);
    printf("So du con lai trong tai khoan: %d VND\n", user->balance);
}

// Hàm chuyển tiền
void transfer(struct Account *user) {
    int amount;
    int receiverAccountNumber;
    
    printf("Nhap so tien muon chuyen (boi so cua 10,000 VND): ");
    scanf("%d", &amount);
    
    // Kiểm tra số tiền muốn chuyển
    if (amount % 10000 != 0) {
        printf("So tien muon chuyen phai la boi so cua 10,000 VND.\n");
        return;
    }
    
    // Kiểm tra số dư tài khoản
    if (amount > user->balance) {
        printf("So du trong tai khoan khong du de chuyen tien.\n");
        return;
    }
    
    printf("Nhap so tai khoan nguoi nhan: ");
    scanf("%d", &receiverAccountNumber);
    
    // Thực hiện chuyển tiền (giả sử đã có xử lý logic)
    
    printf("Da chuyen %d VND den tai khoan %d.\n", amount, receiverAccountNumber);
    printf("So du con lai trong tai khoan: %d VND\n", user->balance - amount);
}

// Hàm cập nhật thông tin tài khoản
void updateAccount(struct Account *user) {
    // Thực hiện cập nhật thông tin tài khoản (giả sử đã có xử lý logic)
    
    printf("Da cap nhat thong tin tai khoan.\n");
}

int main() {
    struct Account user;
    bool isLoggedIn = false;
    int choice;
    
    // Vòng lặp cho phép người dùng đăng nhập
    while (!isLoggedIn) {
        isLoggedIn = login(&user);
        if (!isLoggedIn) {
            printf("Dang nhap that bai. Vui long thu lai.\n");
        }
    }
    
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
                printf("Da thoat khoi chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    }
    
    return 0;
}
