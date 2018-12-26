#include<stdio.h>
#include<errno.h>
#include <string.h>


extern int erron;	//导入错误代码 

main(){
	
	FILE *fp;
	int errnum;
	fp = fopen("E:\\有道云笔记\\C\\test1.txt","r");
	
	//  异常处理
	if(fp == NULL)
	{
		//使用stderr保存 -》输出所有错误 
		errnum = errno;
		fprintf(stderr,"错误号: %d\n",errno);
		//方法一   来自 errno库 
		perror("通过 perror 输出错误");
		//方法二  来自string库 
		fprintf(stderr,"打开文件错误： %s \n",strerror(errnum)); 
	 } 
	 else{
	 	fclose(fp);
	 }
	
}
