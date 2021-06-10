#ifndef __NODE_H
#define __NODE_H
typedef struct _Node{
	int value;
	struct _Node *next;
}Node;
typedef struct _List{
	int num;
	Node *head;
}List;
List* add(List *list, int number);
void printList(const List *list);
void freeList(List *list); 
#endif
