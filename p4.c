#include<stdio.h>
#include<math.h>
/*
算法：素数判断 
算法复杂度：sqrt(n)/2 
*/
int isPrime(int x){
	int ret = 1; //假设是素数 
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
	printf("输入一个数：");
	scanf("%d",&a);
	if (isPrime(a)){
		printf("%d 是素数。",a);
	}
	else{
		printf("%d 不是素数。",a);
	}
	return 0;
}

