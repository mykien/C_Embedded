#include <stdio.h>
#include <dirent.h>
#include <string.h>

void getTxtFilePathsInFolder(const char* folderPath, char* filePath1, char* filePath2, char* fileName1, char* fileName2) {
    DIR* directory = opendir(folderPath);
    if (directory == NULL) {
        printf("Khong the mo thu muc Input!\n");
        return;
    }

    int fileCount = 0;
    struct dirent* entry;
    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_REG && strstr(entry->d_name, ".txt") != NULL) {
            char filePath[100];
            snprintf(filePath, sizeof(filePath), "%s/%s", folderPath, entry->d_name);
            if (fileCount == 0) {
                strcpy(filePath1, filePath);
                strncpy(fileName1, entry->d_name, strlen(entry->d_name) - 4); // Loại bỏ 4 ký tự cuối (.txt)
                fileName1[strlen(entry->d_name) - 4] = '\0'; // Đảm bảo chuỗi kết thúc bằng ký tự null
            } else if (fileCount == 1) {
                strcpy(filePath2, filePath);
                strncpy(fileName2, entry->d_name, strlen(entry->d_name) - 4); // Loại bỏ 4 ký tự cuối (.txt)
                fileName2[strlen(entry->d_name) - 4] = '\0'; // Đảm bảo chuỗi kết thúc bằng ký tự null
            }
            fileCount++;
        }
    }

    closedir(directory);
}

int main() {
    const char* folderPath = "C:/Users/PC/Desktop/tsst";
    char filePath1[100];
    char filePath2[100];
    char fileName1[100];
    char fileName2[100];

    getTxtFilePathsInFolder(folderPath, filePath1, filePath2, fileName1, fileName2);

    printf("Duong dan hoan chinh cua file 1: %s\n", filePath1);
    printf("Duong dan hoan chinh cua file 2: %s\n", filePath2);
    printf("Ten file 1: %s\n", fileName1);
    printf("Ten file 2: %s\n", fileName2);

    return 0;
}
