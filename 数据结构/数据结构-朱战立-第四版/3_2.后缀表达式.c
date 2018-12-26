#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<ctype.h>

typedef int DataType;
//  后缀算数表达式  函数
#include "LinStack.h"
int PostExp(char str[])
{
	DataType x,x1,x2;
	int i;
	LSNode *head;
	
	StackInitiate(&head);
	for(i=0;str[i] != '#';i++){			// 循环 直到 输入 # 
		if(isdigit(str[i])){			//当 stri 为操作数时 
			x = (int)(str[i] -48);		// 转化为int 类型的数据存入 x 中
			StackPush(head,x);			// x 入栈 
		}
		else{
			StackPop(head,&x2);			// 退栈 得操作数  存入变量 x2 
			StackPop(head,&x1);			//  退栈 得被操作数  存入变量 x1
			switch(str[i]){
				case '+': x1 += x2;break;
				case '-': x1 -= x2;break;
				case '*': x1 *= x2;break;
				case '/': {
					if(x2 == 0.0){
						printf("除数为0\n");
						exit(0);
					}else{
						x1 /= x2;break;
					}
				}
			}
			StackPush(head,x1);	//运算结果入栈 
		}
	} 
	StackPop(head,&x);		//计算结果 存入 x 
	return x; 				// 返回计算结果 
} 

main(){
//	char str [] = "3642/-5*+#";
	printf("前输入后缀表达式：\n");
	char str[20];
	scanf("%s",str);
	int result ;
	result = PostExp(str);
	printf("后缀表达式运算结果为：%d",result);
} 

