#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
int data;
struct node* pNext;
} NODE;

NODE* createNode(int value)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = value;
    node->pNext = NULL;

}

int main()
{
    list list;
    NODE* node1 = createNode(1);

    NODE* node2 = createNode(2);

    NODE* node3 = createNode(3);

    NODE* node4 = createNode(4);


    //Liên kết các node
    node1->pNext = node2;
    node2->pNext = node3;
    node3->pNext = node4;

    //quản lý các node
    list.pHead = node1;


    //In giá trị
    for (NODE* nodetemp = node1; nodetemp->pNext != NULL; nodetemp = nodetemp->pNext)
    {
        printf("%d",nodetemp->data);
    }

    //Free bộ nhớ cấp phát động
    free(node1);
    free(node2);
    free(node3);
    free(node4);


}
