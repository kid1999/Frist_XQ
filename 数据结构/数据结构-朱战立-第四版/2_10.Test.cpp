#include<stdio.h>
#include<malloc.h>
typedef int DataType;

// 链表 
typedef struct Node{
	DataType data;
	struct Node *next;
}SLNode;

//init
void ListInitiate(SLNode **head){	//接收指针  用二重指针 
	*head = (SLNode *)malloc(sizeof(SLNode));	//申请头结点 
	(*head)->next = NULL; 					// 结束标志 
}

//insert
int ListInsert(SLNode *head,int i,DataType x){
	SLNode *p,*q;
	int j;
	p = head;
	j = -1;
	while(p->next != NULL && j<i-1){	//p指向i-1个元素 
		p = p->next;
		j++;
	}
	if(j != i-1){
		printf("插入位置参数错误\n");
		return 0; 
	}
	
	q = (SLNode *)malloc(sizeof(SLNode));	//新节点
	q->data = x;
	
	
	q->next = p->next; 	// 插入步骤 1
	p->next = q;		//插入步骤 2 
	return 1; 
}

//ListGet
int ListGet(SLNode *head,int i,DataType *x){
	SLNode *p;
	int j;
	p = head;
	j = -1;
	while(p->next !=NULL && j<i){
		p = p->next;		// p 指向 i-1 
		j++;
	}
	if(j != i){
		printf("取元素位置参数错误\n");
		return 0;
	} 
	
	*x = p->data;
	return 1;
}
//length
int ListLength(SLNode *head)
{
	SLNode *p = head;
	int size = 0;
	
	while(p->next !=NULL){
		p = p->next;
		size ++;
	}
	return size;
 } 



void DoSomeThing(SLNode *L){
	SLNode *q,*p,*s = L->next;
	if(s != NULL && s->next !=NULL){
		q = s;
		s = s->next;
		while(p->next != NULL)
			p = p->next;
		L->next = q->next;
		p->next = q;
		q->next = NULL;
	}
}

main(){
	SLNode *head;	//定义头指针变量
	int i,x;
	
	ListInitiate(&head);	//初始化
	for (i = 0;i<10;i++)
		ListInsert(head,i,i+1);
		
	DoSomeThing(head); 
		
	for (i=0;i<ListLength(head);i++){	//遍历显示 
		ListGet(head,i,&x);
		printf("%d\t",x);
	}
}
