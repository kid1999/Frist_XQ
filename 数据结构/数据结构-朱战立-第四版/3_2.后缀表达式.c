#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<ctype.h>

typedef int DataType;
//  ��׺�������ʽ  ����
#include "LinStack.h"
int PostExp(char str[])
{
	DataType x,x1,x2;
	int i;
	LSNode *head;
	
	StackInitiate(&head);
	for(i=0;str[i] != '#';i++){			// ѭ�� ֱ�� ���� # 
		if(isdigit(str[i])){			//�� stri Ϊ������ʱ 
			x = (int)(str[i] -48);		// ת��Ϊint ���͵����ݴ��� x ��
			StackPush(head,x);			// x ��ջ 
		}
		else{
			StackPop(head,&x2);			// ��ջ �ò�����  ������� x2 
			StackPop(head,&x1);			//  ��ջ �ñ�������  ������� x1
			switch(str[i]){
				case '+': x1 += x2;break;
				case '-': x1 -= x2;break;
				case '*': x1 *= x2;break;
				case '/': {
					if(x2 == 0.0){
						printf("����Ϊ0\n");
						exit(0);
					}else{
						x1 /= x2;break;
					}
				}
			}
			StackPush(head,x1);	//��������ջ 
		}
	} 
	StackPop(head,&x);		//������ ���� x 
	return x; 				// ���ؼ����� 
} 

main(){
//	char str [] = "3642/-5*+#";
	printf("ǰ�����׺���ʽ��\n");
	char str[20];
	scanf("%s",str);
	int result ;
	result = PostExp(str);
	printf("��׺���ʽ������Ϊ��%d",result);
} 

