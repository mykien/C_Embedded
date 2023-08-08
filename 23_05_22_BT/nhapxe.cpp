#include <stdio.h>
#include <string.h>

struct car
{
    char chCode[20]; // Ma xe
    char chType[30]; // Loai xe
    char chBrand[30]; // Hang xe
    int nCost; // Gia xe
    int nSeat; // so ghe ngoi
    int nWeight; // Trong luong xe
};


//Ham nhap thong tin xe
void nhapThongtinXe(struct car *xe)
{
    printf("Ma xe: ");
    fflush(stdin);
    fgets(xe->chCode, sizeof(xe->chCode), stdin);
    printf ("\nloai xe: ");   
    fflush(stdin);
    fgets(xe->chType, sizeof(xe->chType), stdin); 
    printf ("\nHang xe: ");
    fflush(stdin);
    fgets(xe->chBrand, sizeof(xe->chBrand), stdin); 
    printf ("\nGia xe: ");   
    scanf ("%d", &(xe->nCost));
    printf ("\nSo ghe: "); 
    scanf ("%d", &(xe->nSeat)); 
    printf ("\nTrong luong xe:");
    scanf ("%d", &(xe->nWeight));
}

//ham nhap danh sach xe
void nhapDanhsachXe(struct car ds[], int &n)
{
	do 
	{
		printf ("\nNhap vao so luong xe:");
		scanf ("%d",&n);
	}
	while (n<=0);
		for (int i=0; i<n; i++)
		{
			printf ("\nnhap vao xe so %d\n", i);
			nhapThongtinXe(&ds[i]); 
		}
}

//ham in thong tin xe
void inThongtinXe (car xe)
{	
			
   	printf ("\nMa xe: %s", xe.chCode);
    printf ("\nLoai xe: %s", xe.chType);
    printf ("\nHang xe: %s", xe.chBrand);
    printf ("\ngia xe: %d\n", xe.nCost);
    printf ("\nSo ghe: %d\n", xe.nSeat);
    printf ("\nTrong luong xe: %d\n", xe.nWeight);
}

//ham xuat so xe da nhap
void xuatDanhsachxe (car ds[], int n)
{
	for (int i = 0; i<n; i++)
	{
		inThongtinXe(ds[i]);
	}
}

//Tong gia tri xe da nhap
int tongGiaxe(car ds[], int n)
{
	int sum;
	for (int i = 0; i < n; i++)
	{
		sum = sum + ds[i].nCost;
	}
	return sum;
}

//Tim xe co gia cao nhat va in ra thong tin nhung xe co gia cao nhat 
void giaXecaonhat(car ds[], int n)
{
	int slxeMax = 0;	//Xac dinh sl xe co gia cao nhat
	int giaMax = 0;
	// tim gia xe cao nhat
	for (int i = 0 ; i < n; i++)
	{
		if (giaMax < ds[i].nCost)
		{		
			giaMax = ds[i].nCost;			
		}
		//tim sl xe co gia max nhat
		if (giaMax = ds[i].nCost)
		{
			slxeMax++;
		}
	}

	// in ra thong tin nhung xe co gia cao nhat
	printf ("co %d xe co gia cao nhat la xe:\n",slxeMax++);
	printf ("gia max la %d:",giaMax);
	
	for (int x = 0 ;x < n; x++ )
	{
		if (giaMax = ds[x].nCost )  
		{
			printf ("\ngia max %d\n", giaMax);
			inThongtinXe(ds[x]);
		}
	}		
}
	
//ham tim max gia tri xe
int maxGiaXe(car ds[], int n)
{
	int max = ds[0].nCost;
	for (int i=0; i<n; i++)
	{
		if (max < ds[i].nCost)
		{
			max = ds[i].nCost;
		}
	}
	return max;
}


int main()
{
	car ds[100];
	int n;
	nhapDanhsachXe(ds, n);
	printf("\nGia xe cao nhat la : %d", maxGiaXe(ds,n));
	printf ("\nTong gia xe da nhap : %d\n", tongGiaxe(ds,n));
	giaXecaonhat(ds,n);

    return 0;
}