#include<stdio.h>

void add(int *pa, int *pb, int *ps){
	*ps = *pa + *pb;
}

int main(){
	int a,b,s;
	scanf("%d,%d",&a,&b);
	add(&a,&b,&s);
	printf("s=%d\n",s);
	return 0;
}


