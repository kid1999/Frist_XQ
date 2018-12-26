#include<stdio.h>
//��̬����ʵ��˳���

//Ԥ���� 
//#define MaxSize 10
//typedef  int DataType

//�ṹ�� 
typedef struct {
	DataType list[MaxSize];
	int size;
}SeqList; 

//����
void ListInitiate(SeqList *L)		//��ʼ�� 
{
	L->size = 0;
}

int ListLength(SeqList L)		//��ǰԪ�ظ��� 
{
	return L.size;
}

int ListInsert(SeqList *L,int i,DataType x)  //���� 
{
	int j;
	if(L->size >= MaxSize){
		printf("˳�������! \n");
		return 0;
	}
	else if(i<0 || i > L->size){
		printf("�������Ϸ�! \n");
		return 0; 
	} 
	else{
		for (j = L->size;j>i;j--)
			//���ݺ��� Ųλ��
			L->list[j] = L->list[j-1];
			
		L->list[i] = x;
		L->size ++;
		return 1; 
	
	}
}

int ListDelete(SeqList *L,int i,DataType *x){	//ɾ�� 
	//ɾ��L�еĵ�i��Ԫ�� �����浽x��
	int j;
	if(L->size <= 0)
	{
		printf("˳���Ϊ��! \n");
		return 0;
	 } 
	 else if(i < 0||i > L->size-1){
	 	printf("�������Ϸ�");
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
	//ȡ��˳����е�i��Ԫ�ش���X��
	if(i<0||i>L.size-1)
	{
		printf("�������Ϸ�!\n");
		return 0; 
	 } 
	 else{
	 	*x = L.list[i];
		 return 1; 
	 }
 } 
 
void ListDisplay(SeqList *L){
	int i;
	for (i=0;i<L->size;i++){		//����ListLength�������� 
		printf("%d ",L->list[i]);
	}
	printf("\n"); 
}

// ��ֵ ɾ�� 
int ListDataDelete(SeqList *L,DataType x){
	int i,j;
	for(i=0;i<L->size;i++)
		if( x== L->list[i]) break;
	
	if(i == L->size) return 0;	//δ�ҵ�x
	else{
		for (j=i;j<L->size-1;j++)
			L->list[j] = L->list[j+1];
		
		L->size--;
		return 1;
	} 
} 

// ɾ�� ��ֵͬ
int ListMoreDataDelete(SeqList *L,DataType x){
	int i,j;
	int tag = 0;	//��ʼɾ�����λ��Ϊ 0 
	
	for(i=0;i<L->size;i++)
	{
		if( x== L->list[i]){
			//  Ѱ������  x
			for (j=i;j<L->size-1;j++)		//����ǰ�� 
				L->list[j] = L->list[j+1];
	
		L->size --;
		i --;
		tag = 1; 
		}
	}
	return tag;			//����ɾ������ 
} 
