#include<stdio.h>
#include<string.h>
//预定义
#define True 1
#define False 0 

//用typedef给结构体定义一个新的类型名字

typedef struct Books 
{
	char title[20];
	int book_id;
 } Book;

main()
{
	typedef unsigned char BYTE; //定义一个BYTE代表..	
	BYTE b1,b2;
	 

	Book book;	//用新定义的类型名 Book
	strcpy( book.title, "C 教程");
	book.book_id = 12345;
	
	printf("%s  %d \n",book.title,book.book_id);
	
	printf("%d",True); 
 } 
