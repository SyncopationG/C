#include<stdio.h>
/*
���ϡ������ڴ档 
*/

//union A{
//	int i;
//	char chr[sizeof(int)];
//};

typedef union{
	int i;
	char chr[sizeof(int)];
} A;

int main(int argc, const char *argv[]){
	printf("sizeof(A):%d\n",sizeof(A));//����ռ�õ��ڴ������ռ���ڴ����ı���ռ�õ��ڴ� 
//	union A a;
	A a;
	int i;
	a.i = 5050;
	for (i=0;i<sizeof(int);i++){
		printf("%02hhx",a.chr[i]);
	}
	return 0;
}

