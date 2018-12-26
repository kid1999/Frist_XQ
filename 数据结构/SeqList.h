#include<stdio.h>
//静态数组实现顺序表

//预定义 
//#define MaxSize 10
//typedef  int DataType

//结构体 
typedef struct {
	DataType list[MaxSize];
	int size;
}SeqList; 

//方法
void ListInitiate(SeqList *L)		//初始化 
{
	L->size = 0;
}

int ListLength(SeqList L)		//求当前元素个数 
{
	return L.size;
}

int ListInsert(SeqList *L,int i,DataType x)  //插入 
{
	int j;
	if(L->size >= MaxSize){
		printf("顺序表已满! \n");
		return 0;
	}
	else if(i<0 || i > L->size){
		printf("参数不合法! \n");
		return 0; 
	} 
	else{
		for (j = L->size;j>i;j--)
			//数据后移 挪位置
			L->list[j] = L->list[j-1];
			
		L->list[i] = x;
		L->size ++;
		return 1; 
	
	}
}

int ListDelete(SeqList *L,int i,DataType *x){	//删除 
	//删除L中的第i个元素 并保存到x中
	int j;
	if(L->size <= 0)
	{
		printf("顺序表为空! \n");
		return 0;
	 } 
	 else if(i < 0||i > L->size-1){
	 	printf("参数不合法");
		 return 0; 
	 }
	 else{
	 	*x = L->list[i];
	 	for (j =i+1;j <=L->size-1;j++)
	 		L->list[j-1] = L->list[j];
	 	
	 	L->size--;
	 	return 1;
	 }
}

int ListGet(SeqList L,int i,DataType *x)
{
	//取出顺序表中第i个元素存于X中
	if(i<0||i>L.size-1)
	{
		printf("参数不合法!\n");
		return 0; 
	 } 
	 else{
	 	*x = L.list[i];
		 return 1; 
	 }
 } 
 
void ListDisplay(SeqList *L){
	int i;
	for (i=0;i<L->size;i++){		//可用ListLength函数代替 
		printf("%d ",L->list[i]);
	}
	printf("\n"); 
}

// 按值 删除 
int ListDataDelete(SeqList *L,DataType x){
	int i,j;
	for(i=0;i<L->size;i++)
		if( x== L->list[i]) break;
	
	if(i == L->size) return 0;	//未找到x
	else{
		for (j=i;j<L->size-1;j++)
			L->list[j] = L->list[j+1];
		
		L->size--;
		return 1;
	} 
} 

// 删除 相同值
int ListMoreDataDelete(SeqList *L,DataType x){
	int i,j;
	int tag = 0;	//初始删除标记位置为 0 
	
	for(i=0;i<L->size;i++)
	{
		if( x== L->list[i]){
			//  寻找运输  x
			for (j=i;j<L->size-1;j++)		//依次前移 
				L->list[j] = L->list[j+1];
	
		L->size --;
		i --;
		tag = 1; 
		}
	}
	return tag;			//返回删除个数 
} 
