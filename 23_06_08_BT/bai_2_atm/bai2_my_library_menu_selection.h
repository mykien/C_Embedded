// Khai báo kiểu dữ liệu struct
struct Account 
{
    int accountNumber;  //stk
    char name[50];      //Tên chủ tài khoản
    char password[20];  //Mật khẩu
    int age;            //Tuổi
    char sex[10];       //Giới tính
    int balance;        //Số dư tài khoản
};




//Hàm đăng nhập tài khoản
bool login(struct Account *user);

//Hàm kiểm tra thông tin tài khoản
void checkAccount(struct Account user);

//Hàm rút tiền
void withdraw(struct Account *user);

//Hàm chuyển tiền
void transfer(struct Account *user);

//Hàm cập nhật thông tin tài khoản
void updateAccount(struct Account *user);

