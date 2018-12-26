// ģ�� ����ϵͳ���̹���

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
		printf("���ܴ��ļ�task.dat!\n");
		exit(0);
	} 
	QueueInit(&myPQueue);
	while(!feof(fp))		// ��ʼ�� ˳�����ȼ����� 
	{
		fscanf(fp,"%d %d",&task.elem,&task.proiorty);	//������
		QueueAppend(&myPQueue,task);	//���ݶ�������� 
	}
	i = 1;
	printf("���    �����               ���ȼ�\n");
	while(QueueNotEmpty(myPQueue))	//���������ʾ
	{
		QueueDelete(&myPQueue,&task);	//������
		printf("%d         ",i);	//���
		printf("%d			",task.elem);// ��ʾ�����
		printf("%d			\n",task.proiorty);
		i++; 
		 
	} 
}
