#include<stdio.h>
#include<string.h> 

//ͼ������˳���
#define Maxsize 100  //��
#define ok 1
#define ERROR 0
#define OVERFLOW -1
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

typedef int Status ;	 //status���ط���ֵ״̬ 

Status Initlist(Sqlist &L)					//1.��ʼ������һ���յ�˳���L		
{
	L.elem = new Book[Maxsize];		//���ٴ�СΪmaxsize��С������ռ� 
	if(!L.elem) return (OVERFLOW);	//�洢����ʧ���˳� 
	L.length = 0;					//�ձ���Ϊ0 
	return ok; 
 } 

Status Getelem(Sqlist L,int i,Book &e)		//2.˳����ȡֵ
{
	if(i<1||i>L.length) return ERROR;
	e = L.elem[i-1];
	return ok;
	 
}
Status Findelem(Sqlist L,Book e)		//3.˳���Ĳ�ѯ 
{
	for(int i=0;i<L.length;i++)
	{
		if(L.elem[i].id=="1704405135") return i+1;	//���ҳɹ�,������� 
	return 0;
	}
 } 

Status Listinsert (Sqlist &L,int i,Book e)			//4.˳���Ĳ��� 
{
	if(i<1||(i>L.length+1)) return ERROR;
	if(L.length==Maxsize) return ERROR;
	for(int j=L.length-1;j>i-1;j--)
		L.elem[j+1] = L.elem[j];	//ȫ��������һλ 
	
	L.elem[i-1] = e;
	++L.length;
	return ok;
 } 
 
Status Listdel(Sqlist &L,int i)		//5.˳����ɾ�� 
{
	if(i<1||i>L.length) return ERROR;
	for (int j=i;j<=L.length-1;j++)
		L.elem[j-1] =L.elem[j];
	--L.length;
	return ok;
		 } 

main()
{	Sqlist L; 		//��ʼ��������� 
	Book one; 
	printf("��ʼ������ֵ:%d\n",Initlist(L)) ;
	strcpy(L.elem[0].id ,"1704405135"); 	//ʹ��strcpy����Ϊ����ռ丳ֵ 
	strcpy(L.elem[0].name ,"hello world"); 
	printf("��ѯ���ؽ��%d",Getelem(L,0,one)); 	

	
	
}

