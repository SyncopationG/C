#include<stdio.h>
/*
数组的使用：统计0~9的个数 
*/
int main(){
const int n=10;
int count[n];
int i,x=0;
for (i=0;i<n;i++){
	count[i]=0;
}
printf("输入数字（以-1结束）：") ;
while (x!=-1){
	scanf("%d",&x);
	if (x>=0 && x<=9){
		count[x]++;
	}
}
for (i=0;i<n;i++){
	printf("%d: %d\n",i,count[i]);
}
return 0;	
}

