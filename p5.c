#include<stdio.h>
/*
tic-tac-toeʤ���б� 
*/

int status(int a, int b, int size, int ret){
	if ( a == size){
		return 0;
	}
	else if (b == size){
		return 1;
	}
	return ret;
}

int main(){
	const int size=3;
	int board[size][size];
	int a,i,j;
	int num0,num1;
	int ret = -1; // ƽ�� 
	printf("�������̣�\n");
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			scanf("%d",&board[i][j]);
		}
	}
	// �����a=0����a=1 
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
	    //���Խ���
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
		//���Խ���
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
	//������ 
	if (ret == 0){
		printf("0ʤ��");
	}
	else if (ret ==1 ){
		printf("1ʤ��");
	}
	else{
		printf("ƽ��");
	}
	return 0;
}

