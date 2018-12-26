#include<stdio.h>
#include<malloc.h>

typedef int DataType;
#include "ClinkList.h"

main(){
	SLNode *head;	//定义头指针变量
	int i,x;
	
	ListInitiate(&head);	//初始化
	for (i = 0;i<10;i++)
		ListInsert(head,i,i+1);
	ListDelete(head,4,&x);
	printf("删除的元素是:%d\n",x);
	
	for (i=0;i<ListLength(head);i++){	//遍历显示 
		ListGet(head,i,&x);
		printf("%d\t",x);
	}
	Destroy(&head);		//撤销链表 
} 
