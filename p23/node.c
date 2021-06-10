#include "node.h"
#include <stdlib.h>
#include <stdio.h>

void addNode(List *list, int val) {
	Node *p=(Node *)malloc(sizeof(Node)); //����һ���½ڵ�
	p->data=val;
	p->prior=p->next=NULL;
	if (list->head) { //����ͷ����
		list->tail->prior->next=p;//�½ڵ����β��
		p->prior=list->tail->prior;//�½ڵ����β��
		p->next=list->tail;//�½ڵ���β������
		list->tail->prior=p;//�½ڵ���β������
	} else {
		list->head=list->tail=p;//��ʼ������ͷ����β��
		list->head->next=list->tail;//����ͷ����β������
		list->tail->prior=list->head;//����ͷ����β������
	}
	list->num++;
}

void insertNode(List *list, int idx, int val) {
	Node *tmp=(Node *)malloc(sizeof(Node));//�����½ڵ�
	tmp->data=val;//�½ڵ㸳ֵ
	tmp->prior=tmp->next=NULL;//�½ڵ㸳ֵ
	Node *p;
	int i=0;
	for(p=list->head; p; p=p->next) {
		if (i == idx) {
			tmp->prior = p->prior;//�½ڵ��ǰ��ڵ���p��ǰ��ڵ�
			tmp->next = p;//�½ڵ�ĺ����ڵ���p
			p->prior->next=tmp;//p��ǰ��ڵ�ĺ����ڵ����½ڵ�
			p->prior=tmp;//p��ǰ��ڵ����½ڵ�
			if (i==0) {
				list->head=p->prior;//����ͷ��ʱ
			}
			break;
		} else if (p->next==list->head) { //Ĭ�ϲ���β��
			printf("��ֵ����β����\n");
			tmp->prior=p;//�½ڵ��ǰ��ڵ���p
			tmp->next=p->next;//�½ڵ�ĺ����ڵ���p�ĺ����ڵ�
			p->next=tmp;//p�ĺ����ڵ���tmp
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
	printf("һ���� %d ������",list->num);
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

