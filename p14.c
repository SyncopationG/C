#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
strchr��ʹ�� 
*/
int main(){
	char a[]="Hello"; //�����ַ��� 
	char *b=strchr(a,'l');//���ַ���a�в��ҳ���l�ĵ�1���ַ� 
//	b=strchr(b+1,'l');//���ַ���a�в��ҳ���l�ĵ�2���ַ� 
	char c=*b;
	printf("b:%s\n",b);
	printf("b:0x%0x\n",b);
	*b='\0';//����ַ�����βλ�� 
	printf("a:%s\n",a);
	printf("a:0x%0x\n",a);
	char *t = (char *)malloc(strlen(a)+1);
	strcpy(t,a);
	printf("t:%s\n",t);
	free(t);//maclloc��Ӧ��free 
	*b=c;//��ԭ��ǵ��ַ�����βλ�� 
	printf("a:%s\n",a);
	printf("a:0x%0x\n",a);
	return 0;
}

