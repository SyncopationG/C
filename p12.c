#include<stdio.h>
#include<string.h>
 /*
 strcmp及原型 
 */
 
int mycmp(const char *s1, const char *s2); // strcmp原型 

int main(){
	char *a="abc";
	char *b="abc";
	char *c="abcd";
	char *d="abce";
	char *e="abcde";
	printf("strcmp(a,b):%d\n",strcmp(a,b));
	printf(" mycmp(a,b):%d\n",mycmp(a,b));
	printf(" mycmp(a,c):%d\n",mycmp(a,c));
	printf("0-d:%d\n",'\0'-'d');
	printf(" mycmp(c,d):%d\n",mycmp(c,d));
	printf("d-e:%d\n",'d'-'e');
	printf(" mycmp(a,e):%d\n",mycmp(a,e));
	printf("0-d:%d\n",'\0'-'d');
	return 0;
} 

int mycmp(const char *s1, const char *s2){
 	while (*s1==*s2 && *s1 != '\0'){
	 	s1++;
		s2++;
	}
 	return *s1-*s2;
}

