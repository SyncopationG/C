#include<stdio.h>
#include<stdlib.h>
/*
c99��������
��c99֮ǰ�������飨��̬�����ڴ棩 
*/
int main01(){ //c99�������� 
	int n;
	printf("��������Ĵ�С��");
	scanf("%d",&n);
	int a[n];
	int i;
	for (i=0;i<n;i++){
		a[i]=i;
	}
	for (i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
 int main(){//c99֮ǰ�������飨��̬�����ڴ棩 
 	int n;
 	int *a;
 	int i; 
 	printf("��������Ĵ�С��");
	scanf("%d",&n);
 	a = (int *)malloc((n+1)*sizeof(int));
 	for (i=0;i<n;i++){
 		a[i]=i;
	 }
	a[n]=-1;//��-1�������ĩβ
	for (i=0;i<n;i++){//������� 
	    printf("%d ",a[i]);
	}
	printf("\n");
	int *b=a;//ʹ��ָ����� 
	printf("a:%0x\nb:%0x\n",a,b);
	while (*b!=-1){
		printf("%d ",*b++);
	}
	printf("\n");
	printf("sizeof(a):%0x\nsizeof(b):%0x\n",sizeof(a),sizeof(b));
	printf("a:%0x\nb:%0x\n",a,b);
	printf("b-a:%d",b-a);
 	free(a);
 	return 0;
 }
 
