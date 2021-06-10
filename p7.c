#include<stdio.h>
#include<stdlib.h>
/*
c99创建数组
和c99之前创建数组（动态分配内存） 
*/
int main01(){ //c99创建数组 
	int n;
	printf("输入数组的大小：");
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
 int main(){//c99之前创建数组（动态分配内存） 
 	int n;
 	int *a;
 	int i; 
 	printf("输入数组的大小：");
	scanf("%d",&n);
 	a = (int *)malloc((n+1)*sizeof(int));
 	for (i=0;i<n;i++){
 		a[i]=i;
	 }
	a[n]=-1;//用-1标记数组末尾
	for (i=0;i<n;i++){//常规遍历 
	    printf("%d ",a[i]);
	}
	printf("\n");
	int *b=a;//使用指针遍历 
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
 
