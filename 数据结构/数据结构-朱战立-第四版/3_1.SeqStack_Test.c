#include<stdio.h>
#define MaxSize 100
typedef int DataType;
#include "SeqStack.h"

main(){
	SeqStack myStack;
	int i,x;
	
	StackInitiate(&myStack); 	//初始化
	for (i=0;i<10;i++)
		StackPush(&myStack,i+1);
	
	StackTop(&myStack,&x);
	printf("当前栈顶元素为: %d\n",x);
	
	printf("依次出栈:\n");
	while(StackNotEmpyt(myStack)){	//非空
		StackPop(&myStack,&x);
		printf("%d\t",x);	  //出栈显示 
	} 
}
