#include<stdio.h>
#include<malloc.h>
typedef int DataType;

// ���� 
typedef struct Node{
	DataType data;
	struct Node *next;
}SLNode;

//init
void ListInitiate(SLNode **head){	//����ָ��  �ö���ָ�� 
	*head = (SLNode *)malloc(sizeof(SLNode));	//����ͷ��� 
	(*head)->next = NULL; 					// ������־ 
}

//insert
int ListInsert(SLNode *head,int i,DataType x){
	SLNode *p,*q;
	int j;
	p = head;
	j = -1;
	while(p->next != NULL && j<i-1){	//pָ��i-1��Ԫ�� 
		p = p->next;
		j++;
	}
	if(j != i-1){
		printf("����λ�ò�������\n");
		return 0; 
	}
	
	q = (SLNode *)malloc(sizeof(SLNode));	//�½ڵ�
	q->data = x;
	
	
	q->next = p->next; 	// ���벽�� 1
	p->next = q;		//���벽�� 2 
	return 1; 
}

//ListGet
int ListGet(SLNode *head,int i,DataType *x){
	SLNode *p;
	int j;
	p = head;
	j = -1;
	while(p->next !=NULL && j<i){
		p = p->next;		// p ָ�� i-1 
		j++;
	}
	if(j != i){
		printf("ȡԪ��λ�ò�������\n");
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
	SLNode *head;	//����ͷָ�����
	int i,x;
	
	ListInitiate(&head);	//��ʼ��
	for (i = 0;i<10;i++)
		ListInsert(head,i,i+1);
		
	DoSomeThing(head); 
		
	for (i=0;i<ListLength(head);i++){	//������ʾ 
		ListGet(head,i,&x);
		printf("%d\t",x);
	}
}
