
 #include<stdio.h>

// Ham tim so n Finonacci bắt đầu từ 0,1,1,2...
int fibonacci(int n) {
    int f0 = 0;
    int f1 = 1;
    int fn = 1;
    int i;
 
    if (n < 0) 
    {
        return -1;
    } 
    else if (n == 0 || n == 1) 
    {
        return n;
    } 
    else 
    {
        for (i = 2; i < n; i++) {
            f0 = f1;
            f1 = fn;
            fn = f0 + f1;
        }
    }
    return fn;
}
 // Ham main
 
int main() {
 int i;
 int count;
    //Nhập số lượng số Fibonacci cần in
    printf("Nhap so luong so Fibonacci can in: ");
    scanf ("%d",&count);
    if (count < 1 || count > 100)
    {
        printf ("vui long nhap lai so luong so Fibonacci (1<= count <=1000)");
    }
    else
    {
        //in số lượng số Fibonacci
        for (i = 0; i < count ; i++) 
        {
            printf("%d ", fibonacci(i));
        }
    }
    return 0;
}