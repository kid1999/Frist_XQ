#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef int DataType;
#include "LinStack.h"

main(){
	LSNode *myStack;
	int i,x;	
	StackInitiate(&myStack);		//��ʼ��	
	printf("%d\n",StackNotEmpty(myStack));		//�ж��Ƿ�ǿ�

		
	for(i=0;i<10;i++)
		StackPush(myStack,i+1);
		
	StackTop(myStack,&x);	
	printf("��ǰջ��Ԫ��Ϊ: %d\n",x);
	
	printf("���γ�ջ:\n");	
	while(StackNotEmpty(myStack)){	//�ǿ�
		StackPop(myStack,&x);
		printf("%d  ",x);	  //��ջ��ʾ 
	}	
	Destroy(myStack);          
}
