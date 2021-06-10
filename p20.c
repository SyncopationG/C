#include<stdio.h>
#include<string.h>
/*
文件的读写。 
fwrite：写入文件
size_t __cdecl fwrite(const void * __restrict__ _Str,size_t _Size,size_t _Count,FILE * __restrict__ _File); 
fscanf：读取文件 
int __cdecl fscanf(FILE * __restrict__ _File,const char * __restrict__ _Format,...) __MINGW_ATTRIB_DEPRECATED_SEC_WARN; 
*/
int main01(){
	FILE *fp=fopen("./p20.txt","w");
	int n;
	char *s="Write\n";
	if (fp){ //写入文件 
		n=fwrite(s,sizeof(char),strlen(s),fp); 
		fclose(fp);
	}
	printf("n:%d\n",n);
	return 0;
} 

int main02(){
	FILE *fp=fopen("./p20.txt","r");
	char s[]=" ";
	if (fp){ //读取文件 
		fscanf(fp,"%s",s);
		fclose(fp);
	}
	printf("s:%s\n",s);
	printf("strlen(s):%d\n",strlen(s));
	return 0;
} 

int main03(){
	FILE *fp;
	char a[]="1 2 3 4 5 6 7 8 9 10";
	fp = fopen("./p20-1.txt","w");
	if (fp){ 
	    fwrite(a,sizeof(char),sizeof(a),fp);
		fclose(fp);
	}
	return 0;
}

int main(){
	FILE *fp;
	int size;
	fp = fopen("./p20-1.txt","r");
	fseek(fp,0L,SEEK_END);//定位文件到文件尾
	size=ftell(fp);//获取文件指针的偏移量，即文件大小
	fseek(fp,0L,0);//定位文件到文件头 
	char a[size];
	printf("size:%d\n",size);
	if (fp){
		fgets(a,size,fp);//读取size个变量 到a 
		fclose(fp);
	}
	printf("a:%s\n",a);
	printf("sizeof(a):%d\n",sizeof(a));	
	printf("strlen(a):%d\n",strlen(a));	
	return 0;
}

