#include<stdio.h>

#define MaxSize 100
typedef int DataType;

#include "SeqList.h" 

main(){
	SeqList myList;
	int x,i;
	ListInitiate(&myList);
	for(i=0;i<10;i++)
		ListInsert(&myList,i,i+1);	//���� 
	ListDelete(&myList,4,&x);	//ɾ�� 4 λ�õ�ֵ 
	ListDataDelete(&myList,4);	//ɾ�� 4 
	ListDisplay(&myList);	//չʾ
	
	ListInsert(&myList,8,4);
	ListInsert(&myList,9,4);
	ListInsert(&myList,10,4);
	ListMoreDataDelete(&myList,4);
	ListDisplay(&myList); 
	
	
	
	 
}
