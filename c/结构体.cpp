#include<stdio.h>

//定义一个结构体
struct books{     //标签
	char title[50];
	char author[50];
	char subject[100];
	int book_id;    //声明变量
}book = {"C","jack","math",12138};      //自然初始化


main()
{
	printf("%s  %s  %s  %d \n",book.title,book.author,book.subject,book.book_id);
}
