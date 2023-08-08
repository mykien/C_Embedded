#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/*Hàm Nhập đường dẫn cho file Input*/
void Reg_GetInputFilePath(char* p_InputFilePath_aa)
{
  printf ("Enter input file path :");
  scanf("%s",p_InputFilePath_aa);
  getchar();
}   

//Hàm nhập đường dẫn cho file Output
void getOutputFilePath(char* outputFilePath)
{
  printf ("Enter Output file path :");
  scanf("%s",outputFilePath);
  getchar();
}

//Hàm xác định đường dẫn file Input
void getTxtAndCsvFilePathsInFolder(const char* folderPath, char* txtFilePath, char* csvFilePath, char* txtFileName, char* csvFileName) {
    DIR* directory = opendir(folderPath);
    if (directory == NULL) {
        printf("Khong the mo thu muc!\n");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_REG) {
            char filePath[100];
            snprintf(filePath, sizeof(filePath), "%s/%s", folderPath, entry->d_name);
            if (strstr(entry->d_name, ".txt") != NULL) {
                strcpy(txtFilePath, filePath);
                strncpy(txtFileName, entry->d_name, strlen(entry->d_name) - 4);
                txtFileName[strlen(entry->d_name) - 4] = '\0';
            } else if (strstr(entry->d_name, ".csv") != NULL) {
                strcpy(csvFilePath, filePath);
                strncpy(csvFileName, entry->d_name, strlen(entry->d_name) - 4);
                csvFileName[strlen(entry->d_name) - 4] = '\0';
            }
        }
    }

    closedir(directory);
}

//Hàm tạo file .h dựa trên đường dẫn Output đã nhập và tên file .csv
void generateHeaderFile(const char* folderPath, const char* fileName, char* hFilePath) {
    // Tạo tên file .h dựa trên tên file được truyền vào
    snprintf(hFilePath, 100, "%s/%s.h", folderPath, fileName);

    // Tạo file .h và ghi nội dung vào
    FILE* headerFile = fopen(hFilePath, "w");
    if (headerFile != NULL) {
        // Ghi nội dung vào file .hs
       
        printf("Da tao file .h: %s\n", hFilePath);
    } else {
        printf("Khong the tao file .h: %s\n", hFilePath);
    }
}

//Hàm copy nội dung file .txt vào file .h
// Hàm thay thế chuỗi "<NOW>" bằng thời gian hiện tại trong một chuỗi
void replaceNowWithCurrentTime(char* str) {
    time_t now = time(NULL);
    struct tm* current_time = localtime(&now);
    char currentTime[20];
    strftime(currentTime, sizeof(currentTime), "%d/%m/%Y", current_time);

    const char* nowMarker = "<NOW>";
    unsigned int nowMarkerLen = strlen(nowMarker);
    unsigned int currentTimeLen = strlen(currentTime);

    char* markerPtr = strstr(str, nowMarker);
    while (markerPtr != NULL) {
        memmove(markerPtr + currentTimeLen, markerPtr + nowMarkerLen, strlen(markerPtr + nowMarkerLen) + 1);
        memcpy(markerPtr, currentTime, currentTimeLen);
        markerPtr = strstr(markerPtr + currentTimeLen, nowMarker);
    }
}

// Hàm thay thế chuỗi "<NAME_FLIE>" bằng tên file trong một chuỗi
void replaceFileName(char* str, const char* fileName) {
    const char* fileMarker = "<NAME_FILE>";
    unsigned int fileMarkerLen = strlen(fileMarker);
    unsigned int fileNameLen = strlen(fileName);

    char* markerPtr = strstr(str, fileMarker);
    if (markerPtr != NULL) {
        unsigned int remainingLen = strlen(markerPtr + fileMarkerLen);

        memmove(markerPtr + fileNameLen, markerPtr + fileMarkerLen, remainingLen + 1);
        memcpy(markerPtr, fileName, fileNameLen);
    }
}

// Hàm trợ giúp để tách chuỗi từ vị trí start cho đến vị trí end
void extractSubstring(const char* source, char* destination, int start, int end) {
    int j = 0;
    for (int i = start; i < end; i++) {
        destination[j++] = source[i];
    }
    destination[j] = '\0';
}

// Hàm trợ giúp để tìm vị trí của kí tự delimiter trong chuỗi
int findDelimiter(const char* source, char delimiter, int start) {
    int i = start;
    while (source[i] != delimiter && source[i] != '\0' && source[i] != '\n') {
        i++;
    }
    return i;
}

void readCsvFile(FILE* csvFile, FILE* headerFile) {
    const unsigned int bufferSize = 1000;
    char buffer[bufferSize];
    int delimiterPos;  // Khai báo biến delimiterPos ở đầu hàm

    char baseAddress[12];
    char peripheralName[20];
    char offsetAddress[100];
    char registerName[100];
    char width[100];
    char access[100];

    int calculate_width;
    char display_datatype[100];

    int pre_offsetAdress;
    int dec_offsetAdress=0;
    int value_dummy = 0;
    int count_dummy=0;
    int check_baseAddress=0;
    char pre_peripheralName[20];
    char pre_baseAddress[12];
    
    while (fgets(buffer, bufferSize, csvFile) != NULL) {
        //in ra #define
        if (buffer[0] == '0' && buffer[1] == 'x' && check_baseAddress == 1 || buffer[0]=='E' && buffer[1] =='O' && buffer[2] == 'F'){
            fprintf(headerFile,"} %s_REG;\n\n",pre_peripheralName);
            fprintf(headerFile,"#define %s_BASE_ADDRS (%s)\n",pre_peripheralName, pre_baseAddress);
            fprintf(headerFile,"#define %s ((%s_REG*)%s_BASE_ADDRS)\n",pre_peripheralName,pre_peripheralName,pre_peripheralName);
            
            printf("} %s_REG;\n\n",pre_peripheralName);
            printf("#define %s_BASE_ADDRS (%s)\n",pre_peripheralName, pre_baseAddress);
            printf("#define %s ((%s_REG*)%s_BASE_ADDRS)\n",pre_peripheralName,pre_peripheralName,pre_peripheralName);
          }



        if (buffer[0] == '0' && buffer[1] == 'x') {
          // Read base address
            delimiterPos = findDelimiter(buffer, ',', 0);
            extractSubstring(buffer, baseAddress, 0, delimiterPos);
            
            // Read peripheral name
            int start = delimiterPos + 1;
            delimiterPos = findDelimiter(buffer, ',', start);
            extractSubstring(buffer, peripheralName, start, delimiterPos);
            
            // Read offset address
            start = delimiterPos + 1;
            delimiterPos = findDelimiter(buffer, ',', start);
            extractSubstring(buffer, offsetAddress, start, delimiterPos);

            // Read register name
            start = delimiterPos + 1;
            delimiterPos = findDelimiter(buffer, ',', start);
            extractSubstring(buffer, registerName, start, delimiterPos);

            // Read width
            start = delimiterPos + 1;
            delimiterPos = findDelimiter(buffer, ',', start);
            extractSubstring(buffer, width, start, delimiterPos);

            // Read access
            start = delimiterPos + 1;
            delimiterPos = findDelimiter(buffer, '\0', start);
            extractSubstring(buffer, access, start, delimiterPos);

            //Lưu pre_offsetAddress
            pre_offsetAdress = strtol (offsetAddress, NULL ,16);
            
            //bắt đầu khai báo
            fprintf (headerFile,"\n/* %s */\n",peripheralName);
            fprintf (headerFile,"typedef struct {\n");

            printf ("\n/* %s */\n",peripheralName);
            printf ("typedef struct {\n");


            
        }
        else if (buffer[0] == ',' && buffer[1] == ','){
          // Process special case
            int start = 2;

            // Read offset address
            delimiterPos = findDelimiter(buffer, ',', start);          
            extractSubstring(buffer, offsetAddress, start, delimiterPos);

            // Read register name
            start = delimiterPos + 1;
            delimiterPos = findDelimiter(buffer, ',', start);
            extractSubstring(buffer, registerName, start, delimiterPos);

            // Read width
            start = delimiterPos + 1;
            delimiterPos = findDelimiter(buffer, ',', start);
            extractSubstring(buffer, width, start, delimiterPos);

            // Read access
            start = delimiterPos + 1;
            delimiterPos = findDelimiter(buffer, '\0', start);
            extractSubstring(buffer, access, start, delimiterPos);
        }

        //Xử lý độ rộng của thanh ghi - data type
        if (strcmp(width, "32") == 0){
            calculate_width = 4;
            strcpy(display_datatype,"unsigned int");
        }

        //Xử lý dummy
        if (buffer[0] == ',' && buffer[1] == ','){
        dec_offsetAdress = strtol (offsetAddress, NULL ,16);
        value_dummy = dec_offsetAdress - pre_offsetAdress-calculate_width;
          if (value_dummy > 0){
            count_dummy++;
            fprintf (headerFile,"  dummy%d[%d];\n",count_dummy, value_dummy);
            printf ("  dummy%d[%d];\n",count_dummy, value_dummy);
          }
        pre_offsetAdress = dec_offsetAdress; 
        }

        //khai báo thanh ghi
        if (buffer[0] == '0' && buffer[1] == 'x' && check_baseAddress == 1 ||buffer[0] == ',' && buffer[1] == ','){
          if (strcmp(access, "RO") == 0){
            fprintf(headerFile,"  volatile const %s %s;\n",display_datatype, registerName);
            printf("  volatile const %s %s;\n",display_datatype, registerName);
          }
          else if(strcmp(access,"RW") == 0) {
            fprintf(headerFile,"  volatile %s %s;\n",display_datatype, registerName);
            printf("  volatile %s %s;\n",display_datatype, registerName);
          }
        }
        
        //Xử lý khai báo define
        if (buffer[0] == '0' && buffer[1] == 'x' && check_baseAddress == 0)
        {
          strcpy(pre_peripheralName, peripheralName);
          strcpy(pre_baseAddress,baseAddress);
          check_baseAddress++;
        }
        else if (buffer[0] == '0' && buffer[1] == 'x' && check_baseAddress == 1)
        {
          strcpy(pre_peripheralName, peripheralName);
          strcpy(pre_baseAddress,baseAddress);
        } 

    }
}

// Hàm sao chép nội dung từ file .txt vào file .h
void copyTxtFileToHeaderFile(const char* txtFilePath, const char* hFilePath, const char* fileName, const char* csvFilePath) {
    FILE* txtFile = fopen(txtFilePath, "r");
    FILE* hFile = fopen(hFilePath, "w");
    FILE* csvFile = fopen(csvFilePath, "r");

    if (txtFile == NULL || hFile == NULL || csvFile == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    const unsigned int bufferSize = 1000;
    char buffer[bufferSize];
    int isInDefineSection = 0;

    while (fgets(buffer, bufferSize, txtFile) != NULL) {
        if (strstr(buffer, "/*start_define_register*/") != NULL) {
            isInDefineSection = 1;
            readCsvFile(csvFile, hFile); // Gọi hàm để đọc nội dung từ CSV và ghi vào file header
            continue; // Bỏ qua dòng này và không ghi vào file header
        }
        else if (strstr(buffer, "/*end_define_register*/") != NULL) {
            isInDefineSection = 0;
            continue; // Bỏ qua dòng này và không ghi vào file header
        }

        if (!isInDefineSection) {
            replaceNowWithCurrentTime(buffer);
            replaceFileName(buffer, fileName);
            fputs(buffer, hFile);
        }
    }

    fclose(txtFile);
    fclose(hFile);
    fclose(csvFile);

    printf("\nFile .h has been created and populated with content from .txt and .csv files.\n");
}

//Hàm chính
int main()
{
unsigned int l_choiceMenu_u32;
unsigned int l_choiceMenu1_u32;

char p_inputFilePath_c[100];
char p_outFilePath_c[100];

char txtFilePath[100];
char csvFilePath[100];
char txtFileName[100];
char csvFileName[100];
char hFilepath[100];

  do
  {
    printf ("\n1. Choose location option\n");
    printf ("2. Generate file Register_S32K144.h\n");
    printf ("3. Exits\n");
    printf ("Entry your choice :");
    scanf ("%d",&l_choiceMenu_u32);
    getchar();

      switch (l_choiceMenu_u32)
      {
        case 1:
          do 
          {
            printf ("\n1.1 Set input file location\n");
            printf ("1.2 Set output file location\n");
            printf ("1.3 Back\n");
            printf ("Entry your choice :");
            scanf ("%d",&l_choiceMenu1_u32);
            getchar();

            switch (l_choiceMenu1_u32)
            {
              case 1:
                Reg_GetInputFilePath(p_inputFilePath_c);
                printf("%s\n",p_inputFilePath_c);
                getTxtAndCsvFilePathsInFolder(p_inputFilePath_c, txtFilePath, csvFilePath, txtFileName, csvFileName);

                printf("Duong dan hoan chinh cua file 1: %s\n", txtFilePath);
                printf("Duong dan hoan chinh cua file 2: %s\n", csvFilePath);
                printf("Ten file txt: %s", txtFileName);
                printf("\nTen file csv: %s", csvFileName);
                break;
              case 2:
                getOutputFilePath(p_outFilePath_c);
                printf("%s",p_outFilePath_c);
                break;
              case 3:
                printf ("Back");
                break;
              default :
              printf ("Your choice must be 1->3. Please entry again");
            }

          }while (l_choiceMenu1_u32 != 3);

          break;
        case 2:
          //Tạo ra file .h
          generateHeaderFile(p_outFilePath_c,csvFileName,hFilepath);
          printf("\nten file csv:%s",csvFileName);
          copyTxtFileToHeaderFile(txtFilePath,hFilepath,csvFileName,csvFilePath);
          
          break;
        case 3:
          printf ("Exits program");
          break;     
        default:
          printf ("Your choice must be 1->3. Please entry again");
      }
  }while(l_choiceMenu_u32 != 3);

return 0;
    
}