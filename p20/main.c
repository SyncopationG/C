#include <stdio.h>
#include "max.h"
#include "min.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a=5,b=6;
	printf("%d\n",max(a,b));
	printf("%d\n",min(a,b));
	return 0;
}
