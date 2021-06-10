#include<stdio.h>
#include<stdbool.h>
/*
结构的使用。
明天的日期。
定义类型。
*/

typedef struct {
	int month;
	int day;
	int year;
} Date; //定义类型。typedef var* name*;
int month[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
int isLeap(const Date *p);//判断是否是闰年
int numDays(const Date *p);//判断月份的天数
Date * getDate(Date *p); //读入date
void printDate(const Date *p);//输出date
Date * dateCopy(Date *restrict dst, const Date *restrict src);//拷贝date,restrict修饰的是指针,const修饰的是变量
Date * addOneDay(Date *t, const Date *p);//加1天

int main(int argc, const char *argv[]) {
	Date today,tomorrow= (Date) {7,6,2021};
	Date *pToday=&today;
	printf("输入日期 mm dd yyyy：");
	getDate(pToday);
	tomorrow = *addOneDay(&tomorrow,pToday); //赋值为指针取值 ，C语言始终是值传递
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
		if (p->month >=1 && p->month<=12) {//检查输入
			if (p->day>=1 && p->day<=numDays(p)) {
				break;
			} else {
				printf("天数输入错误!");
			}
		} else {
			printf("月份输入错误！");
		}
		printf("重新输入日期 mm dd yyyy：") ;
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
	if (p->day==numDays(p)) { //当月最后一天
		t->day=1;
		if (p->month==12) { //最后一月
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

