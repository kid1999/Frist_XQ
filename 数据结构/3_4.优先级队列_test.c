// 模拟 操作系统进程管理

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MaxSize 100
typedef int ElemType;
#include "SeqPQueue.h"

main(){
	SeqPQueue myPQueue;
	FILE *fp;
	DataType task;
	int i;
	
	if((fp = fopen("task.dat","r")) == NULL){
		printf("不能打开文件task.dat!\n");
		exit(0);
	} 
	QueueInit(&myPQueue);
	while(!feof(fp))		// 初始化 顺序优先级队列 
	{
		fscanf(fp,"%d %d",&task.elem,&task.proiorty);	//读数据
		QueueAppend(&myPQueue,task);	//数据读入队列中 
	}
	i = 1;
	printf("序号    任务号               优先级\n");
	while(QueueNotEmpty(myPQueue))	//逐个出队显示
	{
		QueueDelete(&myPQueue,&task);	//出队列
		printf("%d         ",i);	//序号
		printf("%d			",task.elem);// 显示任务号
		printf("%d			\n",task.proiorty);
		i++; 
		 
	} 
}
