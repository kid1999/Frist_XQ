#include<stdio.h>

main(){
	
	//指针 
	FILE *fp = NULL;	
	fp = fopen("C:\\Users\\Administrator\\Desktop\\C\\斗破.txt","r");
	
	//缓存
	char buff[255]; 
	
	//读取显示文件内容 
	fscanf(fp,"%s",buff);		//遇到 空格就返回 
	printf("1 : %s \n",buff);
	
	fgets(buff,255,(FILE*)fp);	//返回 第一行剩下的  
	printf("2 : %s \n",buff);
	
	fgets(buff,255,(FILE*)fp);		//返回完整的第二排 
	printf("3: %s \n",buff); 
	
	
} 
