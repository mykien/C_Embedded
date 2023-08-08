#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct staff_t 
{
    char name[100];    
    char address[100]; 
    int job;           // job [1-8]
    int level;         // level [1-7]
    long salary;      
};

// Hàm so sánh chuỗi
int compare_string(const char* str1, const char* str2) 
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') 
    {
        if (str1[i] != str2[i]) 
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Hàm swap chuỗi
void swap_string(struct staff_t* ptr1, struct staff_t* ptr2) 
{
    struct staff_t temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

// Hàm sắp xếp nhân viên theo name
void soft_by_name_ascending(struct staff_t* staffList, int count) 
{
    int i, j;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (compare_string(staffList[j].name, staffList[j + 1].name) > 0) {
                swap_string(&staffList[j], &staffList[j + 1]);
            }
        }
    }
}



// Hàm sắp xếp nhân viên theo level
void soft_by_level(struct staff_t* staffList, int count) {
    int i, j;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (staffList[j].level > staffList[j + 1].level) {
                swap_string(&staffList[j], &staffList[j + 1]);
            }
        }
    }
}

// Hàm thêm nhân viên
void add_staff(struct staff_t* staffList, int* count) {
    struct staff_t newStaff;

    printf("name: ");
    fgets(newStaff.name, sizeof(newStaff.name), stdin);
    newStaff.name[strcspn(newStaff.name, "\n")] = '\0';

    printf("address: ");
    fgets(newStaff.address, sizeof(newStaff.address), stdin);
    newStaff.address[strcspn(newStaff.address, "\n")] = '\0';

    printf("job: ");
    scanf("%d", &newStaff.job);

    printf("level: ");
    scanf("%d", &newStaff.level);

    printf("salary: ");
    scanf("%ld", &newStaff.salary);

    getchar(); // Đọc kí tự newline

    staffList[*count] = newStaff;
    (*count)++;
    printf("---Add staff success---\n");
}

// Hàm hiển thị danh sách nhân viên
void show_staff_list(struct staff_t* staffList, int count) {
    printf("\nShow list of staffs:\n");
    for (int i = 0; i < count; i++) {
        printf("name: %s\n", staffList[i].name);
        printf("address: %s\n", staffList[i].address);
        printf("job: %d\n", staffList[i].job);
        printf("level: %d\n", staffList[i].level);
        printf("salary: %ld\n\n", staffList[i].salary);
    }
}

int main() {
    struct staff_t staffList[1000];
    int count = 0;
    int choice;

    do {
        printf("\n1. Add staff\n");
        printf("2. Soft by name\n");
        printf("3. Soft by level\n");
        printf("4. Show list of staffs\n");
        printf("5. Exit program\n");
        printf("Nhap lua chon trong menu[1->5]: ");
        scanf("%d", &choice);
        getchar(); // Đọc kí tự newline 

        switch (choice) {
            case 1:
                add_staff(staffList, &count);
                break;
            case 2:
                soft_by_name_ascending(staffList, count);
                show_staff_list(staffList, count);
                break;
            case 3:
                soft_by_level(staffList, count);
                show_staff_list(staffList, count);
                break;
            case 4:
                show_staff_list(staffList, count);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon phai tu 1->5. vui long nhap lai:\n\n");
        }
    } while (choice != 5);

    return 0;
}
