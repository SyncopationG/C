#include "node.h"
#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/*
���� 
*/
int main(int argc, char *argv[]) {
	List list;
	list.head=NULL;
	List *pList=&list;
	int num;
	printf("�������ݣ���-1��������");
	while (true){
		scanf("%d",&num);
		if (num==-1){
			break;
		}else{
			add(pList,num);//������������� 
			pList->num++;
		}
	}
	printf("sizeof(Node): %d\n",sizeof(Node)); 
	printf("sizeof(List): %d\n",sizeof(List)); 
	printf("������ %d ������",pList->num);
	printList(pList);
	freeList(pList);
	return 0;
}
