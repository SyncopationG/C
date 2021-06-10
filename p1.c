#include<stdio.h>
#include<time.h>
/*
青蛙跳阶问题
*/

int dynamic_program(int n){
	if (n ==1 ){ // 台阶数为1 
		return 1;
	}
	else if (n==2){ //台阶数为2 
		return 2;
	}
	else { // 台阶数大于2 
		int i,p[3]={1,2,};
		for (i=2;i<n;i++){
			p[2]=p[0]+p[1],p[0]=p[1],p[1]=p[2];
		}
		return p[2];
	}
}

int main() {
	clock_t start,finish;
	double duration;
	int p,n;
	printf("输入台阶数：");
	scanf("%d",&n);
	start = clock();
	p = dynamic_program(n);
	finish = clock();
	duration = (double)(finish-start)/CLOCKS_PER_SEC;
	printf("总的跳法: %d \n",p);
	printf("求解用时: %lf 秒\n",duration);
	return 0;
}

