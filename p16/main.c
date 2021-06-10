#include"date.h"
int main(int argc,const char *argv[]) {
	Date today;
	Date *pToday=&today;
	Date tomorrow=(Date) {
		6,9,2021
	};
	getDate(pToday);
	tomorrow=*addOne(&tomorrow,pToday);
	printDate(pToday);
	printDate(&tomorrow);
	return 0;
}
