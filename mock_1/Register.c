#include <stdio.h>

//Hàm Nhập đường dẫn cho file Input
void getInputFilePath(char* inputFilePath)
{
  printf ("Enter input file path :");
  scanf("%s",inputFilePath);
  getchar();
}

//Hàm nhập đường dẫn cho file Output
void getOutputFilePath(char* outputFilePath)
{
  printf ("Enter Output file path :");
  scanf("%s",outputFilePath);
  getchar();
}

//Hàm tạo file Output .h dựa trên đường dẫn đã nhập cho file Output 
 
int main()
{
unsigned int l_choice_u32;
unsigned int l_choice1_u32;
char p_inputFilePath_c[100]="";
char p_outFilePath_c[100]="";

  do
  {
    printf ("\n1. Choose location option\n");
    printf ("2. Generate file Register_S32K144.h\n");
    printf ("3. Exits\n");
    printf ("Entry your choice :");
    scanf ("%d",&l_choice_u32);
    getchar();

      switch (l_choice_u32)
      {
        case 1:
          do 
          {
            printf ("\n1.1 Set input file location\n");
            printf ("1.2 Set output file location\n");
            printf ("1.3 Back\n");
            printf ("Entry your choice :");
            scanf ("%d",&l_choice1_u32);
            getchar();

            switch (l_choice1_u32)
            {
              case 1:
                getInputFilePath(p_inputFilePath_c);
                printf("%s",p_inputFilePath_c);
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

          }while (l_choice1_u32 != 3);

          break;
        case 2:

          break;
        case 3:
          printf ("Exits program");
          break;     
        default:
          printf ("Your choice must be 1->3. Please entry again");
      }
  }while(l_choice_u32 != 3);

return 0;
    
}