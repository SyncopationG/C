#include<stdio.h>

int main()
{
	char *books[] = { //�ַ���ָ�����飬ÿ������Ԫ����һ���ַ���ָ�� 
	"c���Գ������",
	"c++ Primer 1.0",
	"opencv Python",
	};
	char *basic[2];  //�ַ���ָ������ 
	char *application; //�ַ���ָ�� 
	basic[0] = books[0]; //��һ��basic�ַ���ָ��ָ��books�ĵ�һ���ַ����ĵ�ַ 
	basic[1] = books[1];
	application = books[2];
	printf("basic[0]: %s\n",basic[0]);
	printf("basic[1]: %s\n",basic[1]); 
	printf("application: %s\n",application);
	printf("�鿴��ַ\n");
	printf("basic[0] = %p, books[0] = %p, &books[0][0] = %p\n", basic[0], books[0], &books[0][0]);
	printf("basic[1] = %p, books[1] = %p, &books[1][0] = %p\n", basic[1], books[1], &books[1][0]);
	printf("application = %p, books[2] = %p, &books[2][0] = %p\n", application, books[2], &books[2][0]);
	printf("�鿴��ַ���\n"); 
	printf("books[1]-books[0] = %d\n", books[1]-books[0]);
	printf("books[2]-books[1] = %d\n", books[2]-books[1]);
	return 0;
}


