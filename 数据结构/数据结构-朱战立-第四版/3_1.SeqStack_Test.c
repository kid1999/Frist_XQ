#include<stdio.h>
#define MaxSize 100
typedef int DataType;
#include "SeqStack.h"

main(){
	SeqStack myStack;
	int i,x;
	
	StackInitiate(&myStack); 	//��ʼ��
	for (i=0;i<10;i++)
		StackPush(&myStack,i+1);
	
	StackTop(&myStack,&x);
	printf("��ǰջ��Ԫ��Ϊ: %d\n",x);
	
	printf("���γ�ջ:\n");
	while(StackNotEmpyt(myStack)){	//�ǿ�
		StackPop(&myStack,&x);
		printf("%d\t",x);	  //��ջ��ʾ 
	} 
}
