#include<stdio.h>
#include<string.h> 

/*
strcpy��ԭ�� 
*/

char * mycpy(char *restrict dst, const char *restrict src); // strcpyԭ�� 

int main(){
	char *a="Hello"; // ֻ�� 
	char b[]=" "; // ��д 
	char c[]=" ";
	strcpy(b,a);
	mycpy(c,a);
	printf("a:%s\n",a);
	printf("b:%s\n",b);
	printf("c:%s\n",c);
	return 0;
}

char * mycpy(char *dst, const char *src){
 // strcpyԭ�� 
	char *ret = dst;
	while(*dst++ = *src++);
	*dst = '\0';
	return ret;
}

