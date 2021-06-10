#include "node.h"
#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/*
链表。 
*/
int main(int argc, char *argv[]) {
	List list;
	list.head=NULL;
	List *pList=&list;
	int num;
	printf("输入数据（以-1结束）：");
	while (true){
		scanf("%d",&num);
		if (num==-1){
			break;
		}else{
			add(pList,num);//向链表添加数据 
			pList->num++;
		}
	}
	printf("sizeof(Node): %d\n",sizeof(Node)); 
	printf("sizeof(List): %d\n",sizeof(List)); 
	printf("输入了 %d 个数：",pList->num);
	printList(pList);
	freeList(pList);
	return 0;
}
