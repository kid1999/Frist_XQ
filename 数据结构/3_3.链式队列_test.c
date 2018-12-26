#include<stdio.h>
#include<malloc.h>

typedef int DataType;
#include "LQueue.h"

main(){
	LQueue L;
	int x;
	QueueInit(&L);	// 初始化
	QueueAppend(&L,1);
	QueueAppend(&L,2);
	QueueAppend(&L,3);
	QueueGet(L,&x);
	printf("队首元素 %d\n",x);
	printf("队列不为空 %d\n",QueueNotEmpty(L));
	QueueDetele(&L,&x);
	printf("出队 %d\n",x); 
	QueueDetele(&L,&x);
	printf("出队 %d\n",x); 
	
	Destroy(L);
	 
} 
