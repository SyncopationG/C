#include<stdio.h>
#include<stdbool.h>
/*
�ṹ��ʹ�á�
��������ڡ�
�������͡�
*/

typedef struct {
	int month;
	int day;
	int year;
} Date; //�������͡�typedef var* name*;
int month[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
int isLeap(const Date *p);//�ж��Ƿ�������
int numDays(const Date *p);//�ж��·ݵ�����
Date * getDate(Date *p); //����date
void printDate(const Date *p);//���date
Date * dateCopy(Date *restrict dst, const Date *restrict src);//����date,restrict���ε���ָ��,const���ε��Ǳ���
Date * addOneDay(Date *t, const Date *p);//��1��

int main(int argc, const char *argv[]) {
	Date today,tomorrow= (Date) {7,6,2021};
	Date *pToday=&today;
	printf("�������� mm dd yyyy��");
	getDate(pToday);
	tomorrow = *addOneDay(&tomorrow,pToday); //��ֵΪָ��ȡֵ ��C����ʼ����ֵ����
	printDate(pToday);
	printDate(&tomorrow);
	return 0;
}

int isLeap(const Date *p) {
	bool ret = false;
	if ((p->year%4==0 && p->year!=100)||p->year%400==0) {
		ret = true;
	}
	return ret;
}

int numDays(const Date *p) {
	int days=month[p->month-1];
	if (isLeap(p) && p->month==2) {
		days = 29;
	}
	return days;
}

Date * getDate(Date *p) {
	while (true) {
		scanf("%d",&p->month);
		scanf("%d",&p->day);
		scanf("%d",&p->year);
		if (p->month >=1 && p->month<=12) {//�������
			if (p->day>=1 && p->day<=numDays(p)) {
				break;
			} else {
				printf("�����������!");
			}
		} else {
			printf("�·��������");
		}
		printf("������������ mm dd yyyy��") ;
	}
	return p;
}

void printDate(const Date *p) {
	printf("%2i %2i, %4i\n",p->month,p->day,p->year);
}

Date * dateCopy(Date *restrict dst, const Date *restrict src) {
	dst->month=src->month;
	dst->day=src->day;
	dst->year=src->year;
	return dst;
}

Date * addOneDay(Date *t,const Date *p) {
	t = dateCopy(t, p);
	if (p->day==numDays(p)) { //�������һ��
		t->day=1;
		if (p->month==12) { //���һ��
			t->month=1;
			t->year+=1;
		} else {
			t->month+=1;
		}
	} else {
		t->day+=1;
	}
	return t;
}

