#include<stdio.h>
/*
��̬���ر��� 
*/
int g=0;
void f();

int main(){
	int i;
	for (i=0;i<3;i++){
		f();	
	}
	return 0;
}

void f(){
	static int a=0; //��̬���ر�������������ȫ�ֱ�������������������ȫ�ֱ���������
	printf("&g:%p\n",&g);
	printf("&a:%p\n",&a);
	a++;
	printf("a:%d\n",a);
	return ;
}

