#include<stdio.h>
#include<malloc.h>

typedef int DataType;
#include "LQueue.h"

main(){
	LQueue L;
	int x;
	QueueInit(&L);	// ��ʼ��
	QueueAppend(&L,1);
	QueueAppend(&L,2);
	QueueAppend(&L,3);
	QueueGet(L,&x);
	printf("����Ԫ�� %d\n",x);
	printf("���в�Ϊ�� %d\n",QueueNotEmpty(L));
	QueueDetele(&L,&x);
	printf("���� %d\n",x); 
	QueueDetele(&L,&x);
	printf("���� %d\n",x); 
	
	Destroy(L);
	 
} 
