#include<stdio.h>
#include<malloc.h>

typedef int DataType;
#include "LinkList.h"

main(){
	SLNode *head;	//����ͷָ�����
	int i,x;
	
	ListInitiate(&head);	//��ʼ��
	for (i = 0;i<10;i++)
		ListInsert(head,i,i+1);
	ListDelete(head,4,&x);
	printf("ɾ����Ԫ����:%d\n",x);
	
	LinkListInsert(head,15); 
	LinkListInsert(head,3); 
//	LinkListSort(head); 
	
	for (i=0;i<ListLength(head);i++){	//������ʾ 
		ListGet(head,i,&x);
		printf("%d\t",x);
	}
	
	Destroy(&head);		//�������� 
} 
