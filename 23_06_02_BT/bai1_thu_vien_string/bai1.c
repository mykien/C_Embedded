#include <stdio.h>

// Hàm nối chuỗi
char* strcat_custom(char* destination, const char* source) 
{
    char* ptr = destination;
    
    // Di chuyển con trỏ đến cuối chuỗi destination
    while (*ptr != '\0') {
        ptr++;
    }
    
    // Sao chép từng ký tự của chuỗi source vào chuỗi destination
    while (*source != '\0') {
        *ptr = *source;
        ptr++;
        source++;
    }
    
    *ptr = '\0'; // Đặt ký tự kết thúc chuỗi = null
    
    return destination;
}

// Hàm sao chép chuỗi
char* strcpy_custom(char* destination, const char* source) 
{
    char* ptr = destination;
    
    // Sao chép từng ký tự của chuỗi source vào chuỗi destination
    while (*source != '\0') {
        *ptr = *source;
        ptr++;
        source++;
    }
    
    *ptr = '\0'; // Đặt ký tự kết thúc chuỗi
    
    return destination;
}


// Hàm chuyển đổi chuỗi về dạng lowercase
void toLowercase(char* str) 
{

    int i = 0;
    while (str[i] != '\0') 
    {
        if (str[i] >= 'A' && str[i] <= 'Z') 
        {
            str[i] += 32; // Chuyển đổi ký tự thành lowercase bằng cách tăng giá trị của ký tự lên 32 giá trị (tương ứng với bảng ASCII)
        }
        i++;
    }
}

//Hàm chuyển đổi chuỗi về dạng Uppercase
void uppercase(char* str)
{
    int i =0;
    while(str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <='z')
        {
            str[i] -= 32;// chuyển đổi ký tự thành uppercase bằng cách giảm giá trị của kí tự xuống 32 giá trị (tương ứng với bảng ASCII)
        }
        i++;
    }
}

//Hàm xóa xuống dòng
void removeNewline(char* str) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}



int main() {
    char str1[200];
    char str2[200];
    char input1[] = "HELLO";
    char input2[] = "hello";

    //Nhập chuỗi 1
    printf("Nhap chuoi 1 (destination) : ");
    fgets(str1, sizeof(str1), stdin);
    removeNewline(str1);
    //Nhập chuỗi 2
    printf("Nhap chuoi 2 (source): ");
    fgets(str2, sizeof(str2), stdin);
    removeNewline(str2);
    //Gọi hàm nối chuỗi
    strcat_custom(str1, str2); 
    printf("Chuoi sau khi noi (destination): %s\n", str1);

    //Gọi hàm copy chuỗi
    strcpy_custom(str1,str2);
    printf ("Chuoi sau khi copy (destination): %s\n",str1);

    //Gọi hàm hàm chuyển tất cả về ký tự Thường
    toLowercase(input1);
    printf ("Chuoi ky tu thuong : %s\n",input1);
    
    //Gọi hàm chuyển tất cả về ký tự Hoa
    uppercase(input2);
    printf ("Chuoi ky tu Hoa : %s",input2);
 
    return 0;
}
