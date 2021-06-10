#include"date.h"
#include<stdio.h>
#include<stdbool.h>

static int days[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

Date * getDate(Date *p) {
	printf("输入日期mm dd yyyy: ");
	while (true) {
		scanf("%d",&p->month);
		scanf("%d",&p->day);
		scanf("%d",&p->year);
		if (p->month >0 && p->month<13) { //检查输入的合法性
			if (p->day>0 &&((isLeap(p)&&p->day<30)||p->day<=days[p->month-1])) {
				break;
			} else {
				printf("天数不合法！\n");
			}
		} else {
			printf("月份不合法！\n");
		}
		printf("重新输入日期mm dd yyyy: ");
	}
	return p;
}

void printDate(const Date *p) {
	printf("%2i %2i,%4i\n",p->month,p->day,p->year);
}

bool isLeap(const Date *p) {
	bool ret=false;
	if ((p->year%4==0&&p->year%100!=0)||p->year%400==0) {
		ret=true;
	}
	return ret;
}

int numDay(const Date *p) {
	int ret=days[p->month-1];
	if (isLeap(p)&&p->month==2) {
		ret=29;
	}
	return ret;
}

Date * dateCopy(Date *restrict dst,const     Date *restrict src) {
	dst->month=src->month;
	dst->day=src->day;
	dst->year=src->year;
	return dst;
}

Date * addOne(Date *t,const Date *p) {
	t=dateCopy(t,p);
	if (p->day==numDay(p)) {
		t->day=1;
		if (p->month==12) {
			t->month=1;
			t->year++;
		} else {
			t->month++;
		}
	} else {
		t->day++;
	}
	return t;
}

