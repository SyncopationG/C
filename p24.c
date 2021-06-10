#include <stdio.h>
#include <time.h>

int factorial(int n);
int foo(int n);

int main(int argc, char *argv[]) {
	int a=10,b=30;
	int ret;
	clock_t start,end;
	double duration;
	start = clock();
	ret = factorial(a);
	end = clock();
	duration = (double)(end-start)/CLOCKS_PER_SEC;
	printf("Time cost: %.6f\n",duration);
	start = clock();
	ret = foo(b);
	end = clock();
	duration = (double)(end-start)/CLOCKS_PER_SEC;
	printf("Time cost: %.6f\n",duration);
	return 0;
}

int factorial(int n) {
	if (n==1) {
		return 1;
	}
	return n*factorial(n-1);
}

int foo(int n) {
	if (n==1) {
		return 1;
	} else if (n==2) {
		return 2;
	}
	return foo(n-1)+foo(n-2);
}

