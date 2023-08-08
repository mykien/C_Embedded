#include <stdio.h>
#include <string.h>

struct car
{
    char chCode[20]; // Mã xe
    char chType[30]; // Loại xe
    char chBrand[30]; // Hãng xe
    int nCost; // Giá xe
    int nSeat; // Số ghế
    int nWeight; // Trọng lượng xe
};

void printCarInfo(const struct car* c)
{
    printf("ma xe: %s\n", c->chCode);
    printf("Loai xe: %s\n", c->chType);
    printf("Hang xe: %s\n", c->chBrand);
    printf("Gia xe: %d\n", c->nCost);
    printf("So ghe: %d\n", c->nSeat);
    printf("Trong luong xe: %d\n\n", c->nWeight);
}

int main()
{
    const int MAX_SIZE = 100;
    struct car carList[MAX_SIZE];
    int numCars;

    // Nhập danh sách xe
    printf("Nhap so luong xe: ");
    scanf("%d", &numCars);

    for (int i = 0; i < numCars; i++)
    {
        printf("Nhap thong tin xe #%d\n", (i + 1));
        printf("Ma xe: ");
        fflush(stdin);
        fgets(carList[i].chCode,sizeof(carList[i].chCode), stdin);
        //scanf("%s", carList[i].chCode);
        printf("\nLoai xe: ");
        fflush(stdin);
        fgets(carList[i].chType,sizeof(carList[i].chType), stdin);
        //scanf("%s", carList[i].chType);
        printf("\nHang xe: ");
        fflush(stdin);
        fgets(carList[i].chBrand,sizeof(carList[i].chBrand), stdin);
        //scanf("%s", carList[i].chBrand);
        printf("\nGia xe: ");
        scanf("%d", &carList[i].nCost);
        printf("\nSo ghe: ");
        scanf("%d", &carList[i].nSeat);
        printf("\nTrong luong xe: ");
        scanf("%d", &carList[i].nWeight);
        printf("\n");
    }

    // Tính tổng giá trị của số xe đã nhập
    int totalCost = 0;
    for (int i = 0; i < numCars; i++)
    {
        totalCost += carList[i].nCost;
    }
    printf("Tong gia tri xe da nhap: %d\n", totalCost);

    // Tìm xe có giá lớn nhất
    int maxCostIndex = 0;
    for (int i = 1; i < numCars; i++)
    {
        if (carList[i].nCost > carList[maxCostIndex].nCost)
        {
            maxCostIndex = i;
        }
    }
    printf("Thong tin xe co gia lon nhat:\n");
    printCarInfo(&carList[maxCostIndex]);

    // Tìm xe có giá thấp nhất
    int minCostIndex = 0;
    for (int i = 1; i < numCars; i++)
    {
        if (carList[i].nCost < carList[minCostIndex].nCost)
        {
            minCostIndex = i;
        }
    }
    printf("Thong tin xe co gia thap nhat:\n");
    printCarInfo(&carList[minCostIndex]);

    // In ra thông tin xe của hãng Toyota
    printf("Thong tin xe co hang Toyota:\n");
   
    for (int i = 0; i < numCars; i++)
    {
        if (strcmp(carList[i].chBrand, "Toyota") == 0)
        {
            printCarInfo(&carList[i]);
        }
    }

    // Sắp xếp xe theo số chỗ ngồi tăng dần
    for (int i = 0; i < numCars - 1; i++)
    {
        for (int j = i + 1; j < numCars; j++)
        {
            if (carList[i].nSeat > carList[j].nSeat)
            {
                struct car temp = carList[i];
                carList[i] = carList[j];
                carList[j] = temp;
            }
        }
    }

    // In ra thông tin xe theo số chỗ ngồi tăng dần
    printf("cho ngoi tang dan:\n");
    for (int i = 0; i < numCars; i++)
    {
        printCarInfo(&carList[i]);
    }

    // Sắp xếp xe theo số chỗ ngồi giảm dần
    for (int i = 0; i < numCars - 1; i++)
    {
        for (int j = i + 1; j < numCars; j++)
        {
            if (carList[i].nSeat < carList[j].nSeat)
            {
                struct car temp = carList[i];
                carList[i] = carList[j];
                carList[j] = temp;
            }
        }
    }

    // In ra thông tin xe theo số chỗ ngồi giảm dần
    printf("cho ngoi giam dan:\n");
    for (int i = 0; i < numCars; i++)
    {
        printCarInfo(&carList[i]);
    }

    return 0;
}
