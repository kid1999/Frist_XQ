#include<stdio.h>
#include<string.h>
//Ԥ����
#define True 1
#define False 0 

//��typedef���ṹ�嶨��һ���µ���������

typedef struct Books 
{
	char title[20];
	int book_id;
 } Book;

main()
{
	typedef unsigned char BYTE; //����һ��BYTE����..	
	BYTE b1,b2;
	 

	Book book;	//���¶���������� Book
	strcpy( book.title, "C �̳�");
	book.book_id = 12345;
	
	printf("%s  %d \n",book.title,book.book_id);
	
	printf("%d",True); 
 } 
