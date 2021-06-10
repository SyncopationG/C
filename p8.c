#include<stdio.h>
/*
使用字符串输出月份 
*/
int main(int argc, const char *argv[]){
	int i;
	int month;
	char *calendar[]={
	"January","February","March","April",
	"May","June","July","Agust",
	"September","October","Noverber","December" 
	};//字符串数组 
	for (i=0;i<argc;i++){
		printf("%d:%s",i,argv[i]);
	}
	printf("\n");
	while(1){
		printf("输入月份：");
		scanf("%d",&month);	
		if (month>=1 && month <=12){
			printf("%d月：%s\n",month,calendar[month-1]); ;
		}
		else{
			if (month == -1){
			    break;
		    }
			printf("\n输入错误！\n");
	    }
	}
	return 0;
}

