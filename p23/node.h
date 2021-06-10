#ifndef _NODE_H
#define _NODE_H
#include <stdbool.h>
typedef struct _Node {
	int data;
	struct _Node *prior,*next;
} Node;
typedef struct List {
	Node *head,*tail;
	int num;
} List;
void addNode(List *list, int val); //添加新节点
void insertNode(List *list, int idx, int val);//插入节点
void deleteNode(List *list, int val); //删除节点
void setValue(List *list, int idx, int val);//设置某个位置的数
int getValue(const List *list, int idx);//获取某个位置的数
bool checkIndex(const List *list,int idx);//检查边界
void printList(const List *list);//输出链表
void freeList(List *list);//释放链表
#endif
