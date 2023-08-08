#include <stdio.h>
#define max (a>b?a:b)

int main()
{
    //b1: mo file
    FILE* FileIn;
    FILE* FileOut;

    char c = 'k';
    char name[100];
    int a;
    int b;
    //File Out ở chế độ write
    FileOut = fopen ("output.txt", "w");
    //File in ở chế độ read
    FileIn = fopen("input.txt", "r");
    if (FileIn == NULL)
    {
        printf ("Truy cap that bai\n");
    }
    else
    {
        printf ("mo file thanh cong\n");
    }

    //b2: thao tac tren file
    //*Đọc 1 ký tự từ file về 
    //c = fgetc (FileIn); //Cách 1
    //fscanf(FileIn,"%c" ,&c);  //cách 2

    //*Viết 1 ký tự vào file
    //fputc(c,FileIn);

    //*Đọc 1 chuỗi từ file
    //fgets(name, 30, FileIn);


    //*Đọc về 1 số 
    fscanf (FileIn, "%d", &a);
    fscanf (FileIn, "%d", &b);
    
    //*Đọc toàn bộ file .txt
   /* while (!feof(FileIn))
    {
        c = fgetc (FileIn);
        printf ("%c",c);
    }
    */


    //*In ra một chuỗi
    //printf ("%s",name);

    //*In ra 1 số
    printf ("%d",a);
    printf ("%d\n",b);

    //*Tìm ra số max bằng define
    printf ("%d",max);

    //*Ghi số Max vào File Out - fputc : dùng để ghi char , Fprintf: dùng để ghi số
    //fputc (max,FileOut);
    fprintf (FileOut, "%d", max);


    //*close file
    fclose (FileIn);
    fclose (FileOut);
   
    return 0;
}