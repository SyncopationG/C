#include<stdio.h>
#include<time.h>
/*
枚举N以内的素数 
*/
int main(){
	clock_t start, end;
	double duration;
	const int N=25;
	int isPrime[N];
	int i,j;
	for (i=0;i<N;i++){
		isPrime[i]=1;//假设所有数都是素数 
	}
	start = clock();
	for (i=2;i<N;i++){
		if (isPrime[i]){//是素数 
			for (j=2;i*j<N;j++){
				isPrime[i*j]=0;//素数的倍数不是素数 
			}
		}
	}
	end = clock();
	duration = (double)(end-start)/CLOCKS_PER_SEC;
	printf("%d以内的所有素数：", N);
	for (i=2;i<N;i++){
		if (isPrime[i]){
			printf("%d ", i);
		}
	}
	printf("\n求解用时: %lf 秒\n",duration);
	return 0;
}

