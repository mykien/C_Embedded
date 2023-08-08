#include <stdio.h>
#include <stdbool.h>

struct user {
    int soTaiKhoan;
    char ten[100];
    char matKhau[100];
    int tuoi;
    char gioiTinh[10];
    float soDuTaiKhoan;
};

void dangNhapTaiKhoan(struct user user) {
    int soTaiKhoan;
    char matKhau[100];

    printf("Nhap stk: ");
    scanf("%d", &soTaiKhoan);
    printf("Nhap mat khau: ");
    scanf("%s", matKhau);

    if (soTaiKhoan == user.soTaiKhoan && strcmp(matKhau, user.matKhau) == 0) {
        printf("Dang nhap thanh cong!\n");
    } else {
        printf("STK hoac MK khong hop le!\n");
    }
}

void kiemTraTaiKhoan(struct user user) {
    printf("STK: %d\n", user.soTaiKhoan);
    printf("Ten: %s\n", user.ten);
    printf("Tuoi: %d\n", user.tuoi);
    printf("Gioi tinh: %s\n", user.gioiTinh);
    printf("So du tai khoan: %.2f VND\n", user.soDuTaiKhoan);
}

void rutTien(struct user *user) {
    float soTien;

    printf("Nhap so tien muon rut (phai la boi so 10,000 VND): ");
    scanf("%f", &soTien);

    if (soTien >= 50000 && fmod(soTien, 10000) == 0) {
        if (soTien <= user->soDuTaiKhoan) {
            user->soDuTaiKhoan -= soTien;
            printf("Rut tien thanh cong!\n");
        } else {
            printf("So du tai khoan khong du!\n");
        }
    } else {
        printf("So tien khong hop le!\n");
    }
}

void chuyenKhoan(struct user *user) {
    int soTaiKhoanNhan;
    float soTien;

    printf("Nhap stk nguoi nhan: ");
    scanf("%d", &soTaiKhoanNhan);
    printf("Nhap so tien muon chuyen: ");
    scanf("%f", &soTien);

    if (soTien >= 50000) {
        if (soTien <= user->soDuTaiKhoan) {
            user->soDuTaiKhoan -= soTien;
            printf("Chuyen khoan thanh cong!\n");
        } else {
            printf("So du tai khoan khong du!\n");
        }
    } else {
        printf("So tien chuyen khong hop le!\n");
    }
}

void capNhatTaiKhoan(struct user *user) {
    int luaChon;
    float soTien;
    

    printf("1. Nap tien\n");
    printf("2. Rut tien\n");
    printf("3. Thay doi thong tin tai khoan\n");
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &luaChon);

    switch (luaChon) {
        case 1:
            printf("Nhap so tien muon nap: ");
            scanf("%f", &soTien);
            user->soDuTaiKhoan += soTien;
            printf("Nap tien thanh cong!\n");
            break;
        case 2:
            rutTien(user);
            break;
        case 3:
            printf("1. Thay doi ten\n");
            printf("2. Thay doi mat khau\n");
            printf("Nhap lua chon cua ban: ");
            scanf("%d", &luaChon);

            switch (luaChon) {
                case 1:
                    printf("Nhap ten moi: ");
                    scanf("%s", user->ten);
                    printf("Thay đoi ten thanh cong!\n");
                    break;
                case 2:
                    printf("Nhap mat khau moi: ");
                    scanf("%s", user->matKhau);
                    printf("Thay doi mat khau thanh cong!\n");
                    break;
                default:
                    printf("Lua chon khong hop le!\n");
                    break;
            }
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
    }
}

int main() {
    struct user user = {123456, "John Doe", "password", 30, "Nam", 5000000.0};
    int luaChon;
    // Đăng nhập tài khoản

    do {
        printf("\n--- Menu May ATM ---\n");
        printf("1. dang nhap tai khoan\n");
        printf("2. Kiem tra tai khoan\n");
        printf("3. Rut tien\n");
        printf("4. Chuyen khoan\n");
        printf("5. Cap nhat tai khoan\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);
        printf ("\n****in lua chon : %d\n", luaChon);

        switch (luaChon) {
            case 1:
                dangNhapTaiKhoan(user);
                printf ("\n****in lua chon : %d\n", luaChon);
                break;
            case 2:
                kiemTraTaiKhoan(user);
                break;
            case 3:
                rutTien(&user);
                break;
            case 4:
                chuyenKhoan(&user);
                break;
            case 5:
                capNhatTaiKhoan(&user);
                break;
            case 6:
                printf("dang thoat khoi may atm, tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (luaChon != 6);

    return 0;
}
