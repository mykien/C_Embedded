#include "SinglyLinkedList.h"

int main()
{	
	LIST list;

	init_List(&list);

	/* lien ket cac node */
	add_Node_to_Tail(&list, 1);
	add_Node_to_Tail(&list, 2);
	add_Node_to_Tail(&list, 3);  
	add_Node_to_Tail(&list, 4);

	
	addNode(&list, 10, 3);

	print_List(list);

	removeNode(&list,7);
	
	print_List(list);

	sort_List(&list);

	print_List(list);


	free_List(&list);

	return 1;
}
