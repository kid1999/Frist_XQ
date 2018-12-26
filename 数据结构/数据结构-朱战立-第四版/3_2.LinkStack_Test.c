#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef int DataType;
#include "LinStack.h"

main(){
	LSNode *myStack;
	int i,x;	
	StackInitiate(&myStack);		//初始化	
	printf("%d\n",StackNotEmpty(myStack));		//判断是否非空

		
	for(i=0;i<10;i++)
		StackPush(myStack,i+1);
		
	StackTop(myStack,&x);	
	printf("当前栈顶元素为: %d\n",x);
	
	printf("依次出栈:\n");	
	while(StackNotEmpty(myStack)){	//非空
		StackPop(myStack,&x);
		printf("%d  ",x);	  //出栈显示 
	}	
	Destroy(myStack);          
}
