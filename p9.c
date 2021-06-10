#include<stdio.h>
int main(){
	char *a="Hello world!";
	char *b="Hello world!";
	char c[]="Hello world!";
	printf("a:0x%0x\nb:0x%0x\nc:0x%0x\n",a,b,c);
	printf("a:%s\n",a);
	printf("b:%s\n",b);
	printf("c:%s\n",c);
	return 0;
}

