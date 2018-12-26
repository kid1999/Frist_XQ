#include<stdio.h>
#include<string.h> 

//图书数据顺序表
#define Maxsize 100  //表长
#define ok 1
#define ERROR 0
#define OVERFLOW -1
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

typedef int Status ;	 //status返回返回值状态 

Status Initlist(Sqlist &L)					//1.初始化构造一个空的顺序表L		
{
	L.elem = new Book[Maxsize];		//开辟大小为maxsize大小的数组空间 
	if(!L.elem) return (OVERFLOW);	//存储分配失败退出 
	L.length = 0;					//空表长度为0 
	return ok; 
 } 

Status Getelem(Sqlist L,int i,Book &e)		//2.顺序表的取值
{
	if(i<1||i>L.length) return ERROR;
	e = L.elem[i-1];
	return ok;
	 
}
Status Findelem(Sqlist L,Book e)		//3.顺序表的查询 
{
	for(int i=0;i<L.length;i++)
	{
		if(L.elem[i].id=="1704405135") return i+1;	//查找成功,返回序号 
	return 0;
	}
 } 

Status Listinsert (Sqlist &L,int i,Book e)			//4.顺序表的插入 
{
	if(i<1||(i>L.length+1)) return ERROR;
	if(L.length==Maxsize) return ERROR;
	for(int j=L.length-1;j>i-1;j--)
		L.elem[j+1] = L.elem[j];	//全部往后移一位 
	
	L.elem[i-1] = e;
	++L.length;
	return ok;
 } 
 
Status Listdel(Sqlist &L,int i)		//5.顺序表的删除 
{
	if(i<1||i>L.length) return ERROR;
	for (int j=i;j<=L.length-1;j++)
		L.elem[j-1] =L.elem[j];
	--L.length;
	return ok;
		 } 

main()
{	Sqlist L; 		//初始化定义语句 
	Book one; 
	printf("初始化返回值:%d\n",Initlist(L)) ;
	strcpy(L.elem[0].id ,"1704405135"); 	//使用strcpy方法为储存空间赋值 
	strcpy(L.elem[0].name ,"hello world"); 
	printf("查询返回结果%d",Getelem(L,0,one)); 	

	
	
}

