#include<stdio.h>
/*
ʹ���ַ�������·� 
*/
int main(int argc, const char *argv[]){
	int i;
	int month;
	char *calendar[]={
	"January","February","March","April",
	"May","June","July","Agust",
	"September","October","Noverber","December" 
	};//�ַ������� 
	for (i=0;i<argc;i++){
		printf("%d:%s",i,argv[i]);
	}
	printf("\n");
	while(1){
		printf("�����·ݣ�");
		scanf("%d",&month);	
		if (month>=1 && month <=12){
			printf("%d�£�%s\n",month,calendar[month-1]); ;
		}
		else{
			if (month == -1){
			    break;
		    }
			printf("\n�������\n");
	    }
	}
	return 0;
}

