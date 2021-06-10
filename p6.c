#include<stdio.h>
/*
使用指针交换两个数的值 
*/
void swap(int *pa,int *pb);

int main(){
	int a,b;
	a=5,b=6;
	swap(&a,&b);
	printf("a: %d, b: %d\n",a,b);
	printf("&a:0x%0x\n&b:0x%0x\n",&a,&b);
	return 0;
}

void swap(int *pa,int *pb){
	int tmp=*pa;
	*pa=*pb;
	*pb=tmp;
}

