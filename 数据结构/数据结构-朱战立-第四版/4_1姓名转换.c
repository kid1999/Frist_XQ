#include<stdio.h>
#include<string.h>

void ReverseName(char *name,char *newName){
	char *p;
	p = strchr(name,' ');	// p 指向空格位置
	*p = '\0';	// 空格换为\0
	
	strcpy(newName,p+1);	// p+1 指向 name
	strcat(newName,",");    //newname = 姓 + ,
	strcat(newName,name);	//newname = 姓 + , + 名
	*p = ' ';	//恢复name初始状态 
} 

main(){
	char name[] = "Hello World",newName[30];
	ReverseName(name,newName);
	printf("转换后的名字: %s\n",newName); 
} 
