#include<stdio.h>
/*
静态本地变量 
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
	static int a=0; //静态本地变量，本质上是全局变量，但在作用域上与全局变量有区别
	printf("&g:%p\n",&g);
	printf("&a:%p\n",&a);
	a++;
	printf("a:%d\n",a);
	return ;
}

