#include<stdio.h>

main(){
	
	FILE *fp = NULL;	//文件流指针 
	fp = fopen("C:\\Users\\Administrator\\Desktop\\C\\斗破.txt","w+");
	
	//写入文件
	
	//写入字符值  成功返回值else  EOF 
	fputc('C',fp);	
	
	
	//写入字符串 成功返回 非负数
	fputs("hello world \n",fp);	
	
	fprintf(fp,"This is a io program");
	 	
	fclose(fp);
	 

	
	
} 
