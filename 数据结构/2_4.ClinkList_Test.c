#include<stdio.h>
#include<malloc.h>

typedef int DataType;
#include "ClinkList.h"

main(){
	SLNode *head;	//����ͷָ�����
	int i,x;
	
	ListInitiate(&head);	//��ʼ��
	for (i = 0;i<10;i++)
		ListInsert(head,i,i+1);
	ListDelete(head,4,&x);
	printf("ɾ����Ԫ����:%d\n",x);
	
	for (i=0;i<ListLength(head);i++){	//������ʾ 
		ListGet(head,i,&x);
		printf("%d\t",x);
	}
	Destroy(&head);		//�������� 
} 
