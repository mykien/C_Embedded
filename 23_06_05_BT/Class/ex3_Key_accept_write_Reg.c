//* Ứng dụng reset factory - key hardware
/*Khi write key vào 3 byte cao (key của nhà Sản xuất), 1 byte thấp cuối cùng là giá trị, khi write bắt buộc phải write 4 byte trên cùng 1 dòng lệnh
Key = AA55C0
write -> c : 25*/

*c = 0xAA55C025;



