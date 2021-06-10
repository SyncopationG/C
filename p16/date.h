#ifndef _DATE_H
#define _DATE_H
#include<stdbool.h>
typedef struct _Date {
	int month;
	int day;
	int year;
} Date;
Date * getDate(Date *p);//输入Date
void printDate(const Date *p);//输出Date
bool isLeap(const Date *p);//判断闰年
int numDay(const Date *p);//当月天数
Date * dateCopy(Date *restrict dst,const Date *restrict src);//拷贝Date
Date * addOne(Date *t,const Date *p);//加一天
#endif
