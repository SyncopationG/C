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
void addNode(List *list, int val); //����½ڵ�
void insertNode(List *list, int idx, int val);//����ڵ�
void deleteNode(List *list, int val); //ɾ���ڵ�
void setValue(List *list, int idx, int val);//����ĳ��λ�õ���
int getValue(const List *list, int idx);//��ȡĳ��λ�õ���
bool checkIndex(const List *list,int idx);//���߽�
void printList(const List *list);//�������
void freeList(List *list);//�ͷ�����
#endif
