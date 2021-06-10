#include<stdio.h>
#define PI 3.14159 // 不加; 
#define cude(x) ((x)*(x)*(x)) //带参数的宏。一切都要括号 
/*
宏定义 
*/
int main(int argc,char *argv[]){
	int i;
	printf("输入i:");
	scanf("%d",&i);
	printf("cude(i):%d\n",cude(i));
	printf("2*PI*i:%lf\n",2*PI*i);
	return 0;
}

