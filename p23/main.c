#include "node.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	printf("sizeof(Node): %d\n",sizeof(Node));
	printf("sizeof(List): %d\n",sizeof(List));
	List list;
	list.head=list.tail=NULL;
	List *pList=&list;
	int loc,val;
	printf("�������ݣ���-1��������");
	while (true) {
		scanf("%d",&val);
		if (val==-1) {
			break;
		} else {
			addNode(pList,val);//����������½ڵ�
		}
	}
	printf("������ %d ������",pList->num);
	printList(pList);
	printf("����ɾ��������");
	scanf("%d",&val);
	deleteNode(pList,val);
	printf("ɾ���� %d ��", val);
	printList(pList);
	printf("��������λ�� ���������");
	scanf("%d %d",&loc,&val);
	printf("��λ�� %d ������ %d ��",loc,val);
	insertNode(pList,loc,val);
	printList(pList);
	while (true) {
		printf("������ҵ�λ�ã�");
		scanf("%d",&loc);
		if (checkIndex(pList,loc)) {
			val = getValue(pList,loc);
			printf("λ�� %d ������ %d\n",loc,val);
			break;
		}
		printf("����λ�ô���\n");
	}
	printf("�����޸ĵ�λ�� �µ�����");
	scanf("%d %d",&loc,&val);
	printf("�޸�λ�� %d ����Ϊ %d ��",loc,val);
	setValue(pList,loc,val);
	printList(pList);
	freeList(pList);
	return 0;
}

