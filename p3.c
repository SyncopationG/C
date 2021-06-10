#include<stdio.h>
#include<time.h>
/*
ö��N���ڵ����� 
*/
int main(){
	clock_t start, end;
	double duration;
	const int N=25;
	int isPrime[N];
	int i,j;
	for (i=0;i<N;i++){
		isPrime[i]=1;//������������������ 
	}
	start = clock();
	for (i=2;i<N;i++){
		if (isPrime[i]){//������ 
			for (j=2;i*j<N;j++){
				isPrime[i*j]=0;//�����ı����������� 
			}
		}
	}
	end = clock();
	duration = (double)(end-start)/CLOCKS_PER_SEC;
	printf("%d���ڵ�����������", N);
	for (i=2;i<N;i++){
		if (isPrime[i]){
			printf("%d ", i);
		}
	}
	printf("\n�����ʱ: %lf ��\n",duration);
	return 0;
}

