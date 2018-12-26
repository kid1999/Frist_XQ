#include<stdio.h>
#include<string.h> 

//图书数据顺序表
#define Maxsize 100  //表长
typedef struct	//图书信息定义 
{
	char id[20];
	char name[50];
	float price;
 } Book;
 
 typedef struct
 {
 	Book *elem;		//储存空间基地址 
 	int length;		//图书数量 
 }Sqlist;			//图书表顺序存储类型为sqlist


main()
{	Sqlist L; 		//初始化定义语句 
	strcpy(L.elem[3].id ,"1704405135"); 	//使用strcpy方法为储存空间赋值 
	strcpy(L.elem[3].name ,"hello world"); 
	printf("%s",L.elem[3].id) ;
}

