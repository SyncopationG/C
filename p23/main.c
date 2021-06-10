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
	printf("输入数据（以-1结束）：");
	while (true) {
		scanf("%d",&val);
		if (val==-1) {
			break;
		} else {
			addNode(pList,val);//向链表添加新节点
		}
	}
	printf("输入了 %d 个数：",pList->num);
	printList(pList);
	printf("输入删除的数：");
	scanf("%d",&val);
	deleteNode(pList,val);
	printf("删除数 %d 后：", val);
	printList(pList);
	printf("输入插入的位置 插入的数：");
	scanf("%d %d",&loc,&val);
	printf("在位置 %d 插入数 %d 后：",loc,val);
	insertNode(pList,loc,val);
	printList(pList);
	while (true) {
		printf("输入查找的位置：");
		scanf("%d",&loc);
		if (checkIndex(pList,loc)) {
			val = getValue(pList,loc);
			printf("位置 %d 的数是 %d\n",loc,val);
			break;
		}
		printf("输入位置错误！\n");
	}
	printf("输入修改的位置 新的数：");
	scanf("%d %d",&loc,&val);
	printf("修改位置 %d 的数为 %d 后：",loc,val);
	setValue(pList,loc,val);
	printList(pList);
	freeList(pList);
	return 0;
}

