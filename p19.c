#include<stdio.h>
#define PI 3.14159 // ����; 
#define cude(x) ((x)*(x)*(x)) //�������ĺꡣһ�ж�Ҫ���� 
/*
�궨�� 
*/
int main(int argc,char *argv[]){
	int i;
	printf("����i:");
	scanf("%d",&i);
	printf("cude(i):%d\n",cude(i));
	printf("2*PI*i:%lf\n",2*PI*i);
	return 0;
}

