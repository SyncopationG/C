#include<stdio.h>
#include<time.h>
/*
������������
*/

int dynamic_program(int n){
	if (n ==1 ){ // ̨����Ϊ1 
		return 1;
	}
	else if (n==2){ //̨����Ϊ2 
		return 2;
	}
	else { // ̨��������2 
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
	printf("����̨������");
	scanf("%d",&n);
	start = clock();
	p = dynamic_program(n);
	finish = clock();
	duration = (double)(finish-start)/CLOCKS_PER_SEC;
	printf("�ܵ�����: %d \n",p);
	printf("�����ʱ: %lf ��\n",duration);
	return 0;
}

