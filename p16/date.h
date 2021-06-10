#ifndef _DATE_H
#define _DATE_H
#include<stdbool.h>
typedef struct _Date {
	int month;
	int day;
	int year;
} Date;
Date * getDate(Date *p);//����Date
void printDate(const Date *p);//���Date
bool isLeap(const Date *p);//�ж�����
int numDay(const Date *p);//��������
Date * dateCopy(Date *restrict dst,const Date *restrict src);//����Date
Date * addOne(Date *t,const Date *p);//��һ��
#endif
