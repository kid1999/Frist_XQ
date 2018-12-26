
// ��ʽ��ջ  ͷ�ڵ�ָ�� top �������ɾ��

typedef struct snode{
	DataType data;
	struct snode *next;
}LSNode;

//init 
void StackInitiate(LSNode **head){
	*head = (LSNode *)malloc(sizeof(LSNode));
	(*head)->next = NULL;
}

// �ǿշ�
int StackNotEmpty(LSNode *head){
	if(head->next == NULL) 	return 0;	
	else return 1;
} 

//��ջ
 void StackPush(LSNode *head, DataType x){
 	LSNode *p;
 	p = (LSNode *)malloc(sizeof(LSNode));
 	p->data = x;
	p->next = head->next;
	head->next = p;
 } 
 
 // ��ջ
int StackPop(LSNode *head,DataType *d){
	LSNode *p = head->next;
	if(p == NULL){
		printf("��ջ�ѿճ���\n");
		return 0;
	}
		head->next = p->next;
		*d = p->data;
		free(p);
		return 1;	
} 

//ȡ ջ��Ԫ��
int StackTop(LSNode *head,DataType *d){
	LSNode *p = head->next;
	if(p == NULL){
		printf("��ջ�ѿճ���\n");
		return 0;
	}
	*d = p->data;
	return 1;
} 



// ������̬����
void Destroy(LSNode *head){
	LSNode *p1,*top;	
	top = head;
	while(top->next != NULL){
		p1 = top;
		top = top->next;
		free(p1);
	}
	printf("������ɣ�");
} 
