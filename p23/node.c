#include "node.h"
#include <stdlib.h>
#include <stdio.h>

void addNode(List *list, int val) {
	Node *p=(Node *)malloc(sizeof(Node)); //创建一个新节点
	p->data=val;
	p->prior=p->next=NULL;
	if (list->head) { //链表头存在
		list->tail->prior->next=p;//新节点插入尾部
		p->prior=list->tail->prior;//新节点插入尾部
		p->next=list->tail;//新节点与尾部相连
		list->tail->prior=p;//新节点与尾部相连
	} else {
		list->head=list->tail=p;//初始化链表头部和尾部
		list->head->next=list->tail;//链表头部和尾部相连
		list->tail->prior=list->head;//链表头部和尾部相连
	}
	list->num++;
}

void insertNode(List *list, int idx, int val) {
	Node *tmp=(Node *)malloc(sizeof(Node));//创建新节点
	tmp->data=val;//新节点赋值
	tmp->prior=tmp->next=NULL;//新节点赋值
	Node *p;
	int i=0;
	for(p=list->head; p; p=p->next) {
		if (i == idx) {
			tmp->prior = p->prior;//新节点的前序节点是p的前序节点
			tmp->next = p;//新节点的后续节点是p
			p->prior->next=tmp;//p的前序节点的后续节点是新节点
			p->prior=tmp;//p的前序节点是新节点
			if (i==0) {
				list->head=p->prior;//插入头部时
			}
			break;
		} else if (p->next==list->head) { //默认插入尾部
			printf("将值插入尾部！\n");
			tmp->prior=p;//新节点的前序节点是p
			tmp->next=p->next;//新节点的后续节点是p的后续节点
			p->next=tmp;//p的后续节点是tmp
			break;
		}
		i++;
	}
	list->num++;
}

void deleteNode(List *list, int val) {
	Node *p;
	for(p=list->head; p; p=p->next) {
		if (p->data==val) {
			p->prior->next=p->next;
			p->next->prior=p->prior;
			if (p==list->head) {
				list->head=	p->next;
			}
			printf("Delete value: %d in %p\n",val, p);
			free(p);
			list->num--;
			break;
		} else if (p->next==list->head) {
			printf("Not found value: %d\n",val);
			break;
		}
	}
}

void setValue(List *list, int idx, int val) {
	Node *p;
	int i=0;
	for (p=list->head; p; p=p->next) {
		if (i == idx || p->next==list->head) {
			if (i==idx) {
				p->data=val;
			}
			break;
		}
		i++;
	}
}

int getValue(const List *list, int idx) {
	Node *p;
	int i=0,ret;
	for (p=list->head; p; p=p->next) {
		if (i == idx || p->next==list->head) {
			break;
		}
		i++;
	}
	return p->data;
}

bool checkIndex(const List *list,int idx) {
	bool status=false;
	if (idx>=0 && idx<list->num) {
		status=true;
	}
	return status;
}

void printList(const List *list) {
	Node *p=NULL;
	printf("一共有 %d 个数：",list->num);
	for(p=list->head; p; p=p->next) {
		printf("%d ",p->data);
		if (p->next==list->head) {
			break;
		}
	}
	printf("\n");
}

void freeList(List *list) {
	Node *p;
	for (p=list->head; p; p=p->next) {
		printf("%p\n",p);
		free(p);
		if (p->next==list->head) {
			break;
		}
	}
}

