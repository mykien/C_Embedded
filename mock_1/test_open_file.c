#include <stdio.h>
#include <dirent.h>
#include <string.h>





int main() {
    // Đường dẫn đến thư mục chứa file .txt
    const char *folder_path = "C:/Users/PC/Desktop/txt";

    // Mở thư mục
    DIR *dir = opendir(folder_path);
    if (dir == NULL) {
        printf("khong the mo thu muc\n");
        return 1;
    }

    // Duyệt qua các tệp tin trong thư mục
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Kiểm tra đuôi của tệp tin
        if (entry->d_type == DT_REG && strcmp(".txt", strrchr(entry->d_name, '.')) == 0) {
            // Tìm thấy tệp tin .txt
            char file_path[256];
            snprintf(file_path, sizeof(file_path), "%s/%s", folder_path, entry->d_name);

            // Đọc và in ra nội dung của file
            FILE *file = fopen(file_path, "r");
            if (file == NULL) {
                printf("Khong the mo file: %s\n", file_path);
                continue;
            }

            printf("Noi dung file %s:\n", file_path);

            char ch;
            while ((ch = fgetc(file)) != EOF) {
                printf("%c", ch);
            }

            fclose(file);
        }
    }

    // Đóng thư mục
    closedir(dir);

    return 0;
}
