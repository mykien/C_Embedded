#ifndef _SINGLY_LINKED_LIST
#define _SINGLY_LINKED_LIST

#include <stdio.h>

typedef struct node {
	int data;
	struct node* pNext;
} NODE;

typedef struct list {
	NODE* pHead;
	NODE* pTail;
} LIST;

/* List */
void init_List(LIST* list);
void print_List(LIST list);
void free_List(LIST* list);
int  get_Count_List(LIST list);
void sort_List(LIST* list);

/* Node*/
NODE* create_Node(int value);
void  add_Node_to_Tail(LIST* list, int value);
void  remove_Node_at_Head(LIST* list);
void  addNode(LIST* list, int value, int position);
void  removeNode(LIST* list, int position);

#endif
