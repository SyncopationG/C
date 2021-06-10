#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
strchr的使用 
*/
int main(){
	char a[]="Hello"; //构造字符串 
	char *b=strchr(a,'l');//在字符串a中查找出现l的第1个字符 
//	b=strchr(b+1,'l');//在字符串a中查找出现l的第2个字符 
	char c=*b;
	printf("b:%s\n",b);
	printf("b:0x%0x\n",b);
	*b='\0';//标记字符串结尾位置 
	printf("a:%s\n",a);
	printf("a:0x%0x\n",a);
	char *t = (char *)malloc(strlen(a)+1);
	strcpy(t,a);
	printf("t:%s\n",t);
	free(t);//maclloc对应的free 
	*b=c;//还原标记的字符串结尾位置 
	printf("a:%s\n",a);
	printf("a:0x%0x\n",a);
	return 0;
}

