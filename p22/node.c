#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include "node.h"

List* add(List *list, int number){
	Node *last =list->head;
	Node *p=(Node*)malloc(sizeof(Node));//创建新节点
	p->value = number;//给新节点赋值 
	p->next=NULL;//新结点指向空 
	if (last){//链表头存在 
		while (last->next){//定位到链表尾 
			last = last->next;
		}
		last->next=p;//在链表尾加上新节点 
	} else{//初始化链表头 
		list->head=p;
	}
	return list;
}

void printList(const List *list){
	Node *p=NULL;
	for(p=list->head;p;p=p->next){//输出链表 
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
