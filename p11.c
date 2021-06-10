#include<stdio.h>
#include<string.h>
/*
strlen及原型 
*/

size_t mylen(const char *s); // strlen原型 

int main(){
	char a[]="Hello";
	printf("strlen(a):%d\n",strlen(a));
	printf(" mylen(a):%d\n",strlen(a));
	printf("sizeof(a):%d\n",sizeof(a));
	return 0;
}

size_t  mylen(const char *s){
	int idx=0;
//	while (s[idx] != '\0'){
    while(*s++){
		idx++;
	}
	return idx;
}

