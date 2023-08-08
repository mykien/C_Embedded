#include <stdio.h>

int main()
{
    //set bit
    int a = 0;  //0000 0000

    printf ("a = %d\n", a);

    a = a | (1 << 0 ); //0000 0001

    printf ("a_setbit0 = %d\n", a);

    //clear bit 0

    a &= ~(1<<0);   //0000 0000

    printf ("a_clearbit = %d\n", a);

    //Đảo bit
    a ^= (1<<2);    //.... 0100
    printf ("a_daobit = %d\n", a);

    //check a bit
    if ((a & (1 << 2)) != 0) // vì kết quả trả về là 4 - nên xét bit khác 0 hoặc là 0 (k dc sd là ==1)
    {
        printf ("true\n");
    }
    else
    {
        printf ("false\n");
    }

    // check giá trị đó có phải là số mũ của 2 hay không

    int x = 8;
    if ((x & (x-1)) == 0)
    {
        printf ("x la so mu cua 2\n");
    }
    else
    {
        printf("X khong la so mu cua 2\n");
    }

    //Change position byte

    int y = 0x89ABCDEF; //khai báo kiểu dữ liệu hexa
    // Thay đổi vị trí 2 byte thấp thành 2 byte cao
    // Chức năng của & 0xFFFF là chỉ giữ lại CDEF và xóa đi 89AB
    // Chức năng của & 0xFFFF 0000 là giữ lại 89AB và xóa đi CDEF
    // Sau khi dịch xong sẽ or 2 kết quả lại sẽ ra được giá trị sau khi dịch
    y = ((y & 0xFFFF)<<16) | ((y & 0xFFFF0000)>>16);
    printf ("y sau khi swap = %x\n", y);

    // Thay đổi vị trí little -> Big endien

    y = (((y & 0xFF000000)>>24) | ((y & 0xFF0000)>>8) | ((y & 0xFF00)<<8) | ((y & 0xFF)<<24));
    printf ("y sau khi LE-> BE : %x\n", y);

    return 0;
}