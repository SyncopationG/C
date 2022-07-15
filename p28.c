#include<stdio.h>

int main()
{
	char *books[] = { //字符型指针数组，每个数组元素是一个字符型指针 
	"c语言程序设计",
	"c++ Primer 1.0",
	"opencv Python",
	};
	char *basic[2];  //字符型指针数组 
	char *application; //字符型指针 
	basic[0] = books[0]; //第一个basic字符型指针指向books的第一个字符串的地址 
	basic[1] = books[1];
	application = books[2];
	printf("basic[0]: %s\n",basic[0]);
	printf("basic[1]: %s\n",basic[1]); 
	printf("application: %s\n",application);
	printf("查看地址\n");
	printf("basic[0] = %p, books[0] = %p, &books[0][0] = %p\n", basic[0], books[0], &books[0][0]);
	printf("basic[1] = %p, books[1] = %p, &books[1][0] = %p\n", basic[1], books[1], &books[1][0]);
	printf("application = %p, books[2] = %p, &books[2][0] = %p\n", application, books[2], &books[2][0]);
	printf("查看地址间隔\n"); 
	printf("books[1]-books[0] = %d\n", books[1]-books[0]);
	printf("books[2]-books[1] = %d\n", books[2]-books[1]);
	return 0;
}


