#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include "node.h"

List* add(List *list, int number){
	Node *last =list->head;
	Node *p=(Node*)malloc(sizeof(Node));//�����½ڵ�
	p->value = number;//���½ڵ㸳ֵ 
	p->next=NULL;//�½��ָ��� 
	if (last){//����ͷ���� 
		while (last->next){//��λ������β 
			last = last->next;
		}
		last->next=p;//������β�����½ڵ� 
	} else{//��ʼ������ͷ 
		list->head=p;
	}
	return list;
}

void printList(const List *list){
	Node *p=NULL;
	for(p=list->head;p;p=p->next){//������� 
		printf("%d ",p->value);
	}
	printf("\n");
}

void freeList(List *list){
	Node *p,*q;
	for (p=list->head;p;p=q){
		printf("%p\n",p);
		q=p->next;
		free(p);
	}
}
