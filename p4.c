#include<stdio.h>
#include<math.h>
/*
�㷨�������ж� 
�㷨���Ӷȣ�sqrt(n)/2 
*/
int isPrime(int x){
	int ret = 1; //���������� 
	int i;
	if (x == 1 || (x % 2 == 0 && x != 2)){
		ret = 0;
	}
	for (i=3;i<sqrt(x);i+=2){
		if (x%i == 0){
			ret = 0;
			break;
		}
	}
	return ret;
}

int main(){
	int a;
	printf("����һ������");
	scanf("%d",&a);
	if (isPrime(a)){
		printf("%d ��������",a);
	}
	else{
		printf("%d ����������",a);
	}
	return 0;
}

