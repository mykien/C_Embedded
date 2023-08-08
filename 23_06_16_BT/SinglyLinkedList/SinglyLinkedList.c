#include "SinglyLinkedList.h"

static NODE* getNodePosition(LIST* list, int position);

void init_List(LIST* list)
{
	list->pHead = NULL;
	list->pTail = NULL;
}

void print_List(LIST list)
{
	for (NODE* nodeTemp = list.pHead; nodeTemp != NULL; nodeTemp = nodeTemp->pNext)
	{
		printf("%d\t", nodeTemp->data);
	}
	printf("\n");
}

void free_List(LIST* list)
{
	while (list->pHead != NULL)
	{
		NODE* nodeTemp = list->pHead;
		list->pHead    = list->pHead->pNext;
		free(nodeTemp);
	}
	list->pTail = NULL;
}

int get_Count_List(LIST list)
{
	int count = 0;
	for (NODE* nodeTemp = list.pHead; nodeTemp != NULL; nodeTemp = nodeTemp->pNext)
	{
		count++;
	}
	return count;
}

void sort_List(LIST* list)
{
	 if (list->pHead == NULL || list->pHead->pNext == NULL) {
        // Danh sách rỗng hoặc chỉ có 1 node, bỏ qua sắp xếp
        return;
    }

    NODE* sortedList = NULL;
    NODE* current = list->pHead;

    while (current != NULL) {
        NODE* nextNode = current->pNext;
        NODE** sortedNode = &sortedList;

        // Tìm vị trí thích hợp để chèn node hiện tại vào danh sách đã sắp xếp
        while (*sortedNode != NULL && (*sortedNode)->data < current->data) {
            sortedNode = &(*sortedNode)->pNext;
        }

        // Chèn node hiện tại vào danh sách node đã sắp xếp
        current->pNext = *sortedNode;
        *sortedNode = current;

        current = nextNode;
    }

    // Cập nhật lại pHead của danh sách node đã sắp xếp
    list->pHead = sortedList;

}

NODE* create_Node(int value)
{
	NODE* Node  = (NODE*)malloc(sizeof(NODE));
	Node->data  = value;
	Node->pNext = NULL;
}

void add_Node_to_Tail(LIST* list, int value)
{
	/* create 1 node */
	NODE* node = create_Node(value);

	/* Check whether list is NULL? */
	if (list->pHead == NULL)
	{
		list->pHead = node;
		list->pTail = node;
	}
	else {
		list->pTail->pNext = node;
		list->pTail = node;
	}
}

void remove_Node_at_Head(LIST* list)
{
	int count = get_Count_List(*list);
	if (count == 0) {}
	else if (count == 1) {
		NODE* nodetemp = list->pHead;
		list->pHead = NULL;
		list->pTail = NULL;
		free(nodetemp);
	}
	else {
		NODE* nodetemp = list->pHead;
		list->pHead = list->pHead->pNext;
		free(nodetemp);
	}
}

static NODE* getNodePosition(LIST* list, int position)
{
	int counttemp = 0;
	NODE* nodetemp;
	for (nodetemp = list->pHead; nodetemp != NULL; nodetemp = nodetemp->pNext)
	{
		if (position == counttemp)
		{
			break;
		}
		counttemp++;
	}
	return nodetemp;
}

void addNode(LIST* list, int value, int position)
{
 
/*
	// create 1 node 
	NODE* node = create_Node(value);

	NODE* nodetemp;

	int count = get_Count_List(*list);

	if (position >= count) {
		add_Node_to_Tail(list, value);
	}
	else {
		nodetemp = getNodePosition(list, position);

		node->pNext = nodetemp->pNext;
		nodetemp->pNext = node;
	}
*/
NODE* node = create_Node(value);
    int count = get_Count_List(*list);

    if (position >= count) {
        add_Node_to_Tail(list, value);
    }
    else if (position == 0) {
        node->pNext = list->pHead;
        list->pHead = node;
    }
    else {
        NODE* nodetemp = getNodePosition(list, position - 1);
        node->pNext = nodetemp->pNext;
        nodetemp->pNext = node;
    }
}

void removeNode(LIST* list, int position)
{
	int count = get_Count_List(*list);

    if (position < 0 || position >= count) {
        // Vị trí không có Node => bỏ qua
        return;
    }

    if (position == 0) {
        // Xóa node đầu danh sách
        NODE* nodetemp = list->pHead;
        list->pHead = list->pHead->pNext;
        free(nodetemp);

        if (list->pHead == NULL) {
            // Nếu danh sách trở thành rỗng, cập nhật con trỏ pTail về NULL
            list->pTail = NULL;
        }
    }
    else {
        // Xóa node ở vị trí khác
        NODE* nodetemp = getNodePosition(list, position - 1);
        NODE* nodeToRemove = nodetemp->pNext;
        nodetemp->pNext = nodeToRemove->pNext;
        free(nodeToRemove);

        if (nodetemp->pNext == NULL) {
            // Nếu node bị xóa là nút cuối danh sách, cập nhật con trỏ pTail
            list->pTail = nodetemp;
        }
    }

}
