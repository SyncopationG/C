#include<stdio.h>
/*
getchar()
putchar()
*/
int main(){
	int ch;
	while ((ch=getchar())!=EOF){//EOF������־: win ctrl+z, linux ctrl+d 
		putchar(ch);
	}
	printf("EOF\n");
	return 0;
}

