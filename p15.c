#include<stdio.h>
//#include<string.h>
/*
ö�� 
*/
enum colors {Red,Green,Blue,NumColors
};

int main(){
	enum colors a=Red;
	char *colorsName[]={
	"red","green","blue"
	};
	int i=0,j;
//	char p[]=" ";
	char *p=NULL;
	printf("a:%d\n",a);
	while (1){
		printf("������ɫ���룺");
		scanf("%d",&i);
		if (i>=0 && i<NumColors){
//			strcpy(p,colorsName[i]);
			p=colorsName[i];
			printf("p:%s\n",p);
			break;
		}
	} 
	return 0;
}

