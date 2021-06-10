#include<stdio.h>
#include<string.h> 

/*
strcpy及原型 
*/

char * mycpy(char *restrict dst, const char *restrict src); // strcpy原型 

int main(){
	char *a="Hello"; // 只读 
	char b[]=" "; // 可写 
	char c[]=" ";
	strcpy(b,a);
	mycpy(c,a);
	printf("a:%s\n",a);
	printf("b:%s\n",b);
	printf("c:%s\n",c);
	return 0;
}

char * mycpy(char *dst, const char *src){
 // strcpy原型 
	char *ret = dst;
	while(*dst++ = *src++);
	*dst = '\0';
	return ret;
}

