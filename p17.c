#include<stdio.h>
/*
联合。共用内存。 
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
	printf("sizeof(A):%d\n",sizeof(A));//联合占用的内存等于其占用内存最大的变量占用的内存 
//	union A a;
	A a;
	int i;
	a.i = 5050;
	for (i=0;i<sizeof(int);i++){
		printf("%02hhx",a.chr[i]);
	}
	return 0;
}

