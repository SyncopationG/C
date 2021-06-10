#include<stdio.h>
/*
使用指针 tic-tac-toe胜负判别
*/

int status(int a, int b, int size, int cur);
int check(int **board, int size);

int main(){
	const int size=3;
	int board[size][size];
	int *p[size]; // 二维数组指针 
	int i,j;
	int ret = -1; // 平局 
	printf("输入棋盘：\n");
	for (i=0;i<size;i++){
		printf("borad[%d]: %0x\n",i, board[i]);
		for (j=0;j<size;j++){
			scanf("%d",&board[i][j]);
			printf("&borad[%d][%d]: %0x ", i,j,&board[i][j]);
		}
		printf("\n");
	}
	for (i=0;i<size;i++){ //二维数组指针赋值 
		p[i]=board[i];
		printf("p[%d]:%0x board[%d]:%0x\n",i,p[i],i,board[i]);
	}
	ret = check(p,size);
	//输出结果
	if (ret == 0){
		printf("0胜！");
	}
	else if (ret ==1 ){
		printf("1胜！");
	}
	else{
		printf("平局");
	}
	return 0;
}

int status(int a, int b, int size, int cur){
	if ( a == size){
		return 0;
	}
	else if (b == size){
		return 1;
	}
	return cur;
}

int check(int **board, int size){
	int a,i,j;
	int num0,num1;
	int ret = -1; // 平局 
	// 检查行a=0和列a=1 
	for (a=0;a<2;a++){
		for (i=0;i<size;i++){
			num0=num1=0;
			for (j=0;j<size;j++){
				if ((board[i][j] == 0 && a == 0 ) || (board[j][i] == 0 && a == 1 )){
					num0++;
				}
				else{
					num1++;
				} 
			}
		    ret = status(num0,num1,size,ret);
		    if (ret != -1){
		    	break;
			}
		}
	}
	if (ret == -1){
	    //检查对角线
		num0=num1=0;
		for (i=0;i<size;i++){
			if (board[i][i]==0){
				num0++;
			}
			else{
				num1++;
			}
		}
	    ret = status(num0,num1,size,ret);
	}
	if (ret == -1){
		//检查对角线
		num0=num1=0;
		for (i=0;i<size;i++){
			if (board[i][size-i-1]==0){
				num0++;
			}
			else{
				num1++;
			}
		}
		ret = status(num0,num1,size,ret);
	}
	return ret;
}

