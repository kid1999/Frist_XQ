#include<stdio.h>
#include<string.h> 

//ͼ������˳���
#define Maxsize 100  //��
typedef struct	//ͼ����Ϣ���� 
{
	char id[20];
	char name[50];
	float price;
 } Book;
 
 typedef struct
 {
 	Book *elem;		//����ռ����ַ 
 	int length;		//ͼ������ 
 }Sqlist;			//ͼ���˳��洢����Ϊsqlist


main()
{	Sqlist L; 		//��ʼ��������� 
	strcpy(L.elem[3].id ,"1704405135"); 	//ʹ��strcpy����Ϊ����ռ丳ֵ 
	strcpy(L.elem[3].name ,"hello world"); 
	printf("%s",L.elem[3].id) ;
}

