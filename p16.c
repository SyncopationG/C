#include<stdio.h>
#include<stdbool.h>
/*
结构的使用。
明天的日期。
*/

struct date {
	int month;
	int day;
	int year;
} today;
int month[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
int isLeap(const struct date *p);//判断是否是闰年
int numDays(const struct date *p);//判断月份的天数
struct date * getDate(struct date *p); //读入date
void printDate(const struct date *p);//输出date
struct date * dateCopy(struct date *restrict dst, const struct date *restrict src);//拷贝date,restrict修饰的是指针,const修饰的是变量
struct date * addOneDay(struct date *t,const struct date *p);//加1天

int main(int argc, const char *argv[]) {
	struct date tomorrow;
	struct date *pToday=&today;
	tomorrow = (struct date){7,6,2021};
	printf("输入日期 mm dd yyyy：");
	getDate(pToday);
	tomorrow = *addOneDay(&tomorrow,pToday);
	printDate(pToday);
	printDate(&tomorrow);
	return 0;
}

int isLeap(const struct date *p) {
	bool ret = false;
	if ((p->year%4==0 && p->year!=100)||p->year%400==0) {
		ret = true;
	}
	return ret;
}

int numDays(const struct date *p) {
	int days=month[p->month-1];
	if (isLeap(p) && p->month==2) {
		days = 29;
	}
	return days;
}

struct date * getDate(struct date *p) {
	int day;
	while (true) {
		scanf("%d",&p->month);
		scanf("%d",&p->day);
		scanf("%d",&p->year);
		if (p->month >=1 && p->month<=12) {
			day = numDays(p);
			if (p->day>=1 && p->day<=day) {
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

void printDate(const struct date *p) {
	printf("%2i %2i, %4i\n",p->month,p->day,p->year);
}

struct date * dateCopy(struct date *restrict dst, const struct date *restrict src) {
	dst->month=src->month;
	dst->day=src->day;
	dst->year=src->year;
	return dst;
}

struct date * addOneDay(struct date *t,const struct date *p) {
	t = dateCopy(t,p);
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

