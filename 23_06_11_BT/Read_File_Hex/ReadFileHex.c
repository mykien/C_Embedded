#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

//Hàm chuyển String từ Big to Little
void stringBigtoLittle(char* str) 
{
    int length = strlen(str);
    //Chạy vòng lặp for 2 lần
    for (int i = 0; i < length / 2; i += 2)
     {
        char temp = str[i];
        str[i] = str[length - i - 2];
        str[length - i - 2] = temp;

        temp = str[i + 1];
        str[i + 1] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}


int main() 
{
    FILE *inputFile;
    FILE *outputFile;
    char lines[MAX_LINES][MAX_LENGTH];
    char baseAddress[5]; // Mảng lưu trữ base address

    char LowAddress[5]; // Mảng lưu trữ low address
    unsigned int decimalLowAdress; // Chuyển địa chỉ low address về hệ số 10 để thực hiện việc tăng địa chỉ


    char lengthData[3];//Mảng lưu trữ độ dài của length data
    unsigned decimalLengthData;// độ dài của lenght data

    char tempAddress[9];    //Địa chỉ ghi vào file out.txt
    char tempData[9];  //Data ghi vào file out.txt

    // Mở file hex input
    inputFile = fopen("input.hex", "r");
    if (inputFile == NULL) 
    {
        printf("khong the mo file input.\n");
        return 0;
    }
    //Mở file output
    outputFile = fopen("output.txt","w");
    if (outputFile == NULL)
    {
        printf("khong the mo file output.\n");
        return 0;
    }

    /*  - Đọc từng dòng sau đó lưu vào mảng 2 chiều
        - Kiểm tra kí tự thứ 9 :
            + Nếu 4 : lấy địa chỉ base address
            + nếu 0 : Dòng chứa địa 2byte thấp và Data
            + Còn lại: Không phải là dữ liệu */

    int lineCount = 0; // Biến đếm số dòng đã đọc
    // Đọc từng dòng trong file input và lưu vào mảng 2 chiều Lines
    while (fgets(lines[lineCount], MAX_LENGTH, inputFile)) 
    {
        // Ghi dòng hiện tại cần xử lý vào file output
        fprintf(outputFile,"%s",lines[lineCount]);

        //Đọc về kí tự thứ 8 để kiểm tra type
        char character = lines[lineCount][8];

        //Nếu = 4 => dòng này mang địa chỉ 2 byte cao(base address)
        if (character == '4') 
        {
            // Copy kí tự từ thứ 9 đến 12 vào mảng baseAddress
            strncpy((baseAddress), lines[lineCount] + 9, 4);
            baseAddress[4] = '\0'; // Đảm bảo kết thúc chuỗi
            //Ghi base address vào file output     
            fprintf(outputFile,"Address base : 0x%s\n",baseAddress);
        } 
        //Nếu kí tự thứ 8 = 0 => đây là dòng mang dữ liệu
        else if (character == '0') 
        {
            // Đọc về kí tự thứ 1 và thứ 2 : xác định độ dài Data 
            strncpy((lengthData), lines[lineCount] + 1, 2);
            lengthData[2] = '\0'; // Đảm bảo kết thúc chuỗi
            decimalLengthData = strtol(lengthData, NULL, 16);//chuyển độ dài từ hex về decimal
         

            //Xác đinh 2 byte thấp địa chỉ
            strncpy((LowAddress), lines[lineCount] + 3, 4);
            LowAddress[4] = '\0'; // Đảm bảo kết thúc chuỗi
            decimalLowAdress = strtol(LowAddress, NULL, 16);    //Chuyển chuối về dạng integer để thực hiện việc tăng địa chỉ
            
            unsigned int PosData = 9;   //bắt đầu lấy dữ liệu từ vị trí thứ 9 của dòng
            //Vòng lặp thực hiện ghi dữ liệu của dòng đó theo địa chỉ tương ứng vào file Output
            for (int i = 0; i < decimalLengthData; i+=4)
            {
                strncpy((tempData), lines[lineCount] + PosData, 8);
                tempData[8] = '\0'; // Đảm bảo kết thúc chuỗi
                
                //Thực hiển chuyển chuỗi từ bigendian sang little endian
                stringBigtoLittle(tempData);
                
                strcpy(tempAddress, baseAddress);     // Sao chép baseAddress vào tempAddress
                strcat(tempAddress, LowAddress);        //Nối chuỗi địa chỉ base [address + lowAddress]

                //Ghi địa chỉ và data vào File Output
                fprintf(outputFile,"Address: 0x%s | Data: 0x%s\n",tempAddress, tempData);

                //tăng địa chỉ 2byte thấp lên 4
                decimalLowAdress += 4;

                //Gán lại vào chuối LowAddress với dạng Hexa
                sprintf (LowAddress, "%04x",decimalLowAdress);
                //tăng vị trí đọc lên 4 byte
                PosData += 8;
            }           
        } 
        else 
        {
            //Ghi vào file output dòng này không phải là dữ liệu
            fprintf(outputFile,"Dong nay khong phai la du lieu\n");
        }
        lineCount++; // Tăng biến đếm dòng
    }
    // Đóng input,output file
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
