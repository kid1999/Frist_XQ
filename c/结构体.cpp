#include<stdio.h>

//����һ���ṹ��
struct books{     //��ǩ
	char title[50];
	char author[50];
	char subject[100];
	int book_id;    //��������
}book = {"C","jack","math",12138};      //��Ȼ��ʼ��


main()
{
	printf("%s  %s  %s  %d \n",book.title,book.author,book.subject,book.book_id);
}
