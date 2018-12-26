
// ѭ������   ��ʹ��β�ڵ���ѣ� 
typedef struct Node{
	DataType data;
	struct Node *next;
}SLNode;

//init
void ListInitiate(SLNode **head){	//����ָ��  �ö���ָ�� 
	*head = (SLNode *)malloc(sizeof(SLNode));	//����ͷ��� 
	(*head)->next = *head; 					// ������־ 
} 

//length
int ListLength(SLNode *head)
{
	SLNode *p = head;
	int size = 0;
	
	while(p->next !=head){
		p = p->next;
		size ++;
	}
	return size;
 } 

//insert
int ListInsert(SLNode *head,int i,DataType x){
	SLNode *p,*q;
	int j;
	p = head;
	j = -1;
	while(p->next != head && j<i-1){	//pָ��i-1��Ԫ�� 
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

//delete
int ListDelete(SLNode *head,int i,DataType *x){
	SLNode *p,*s;
	int j;
	p = head;
	j = -1;
	while(p->next !=head && p->next->next != head && j<i-1){
		//pָ�� i-1 ���ڵ�
		p = p->next;
		j++; 
	}
	if(j != i-1){
		printf("ɾ��λ�ò�����\n");
		return 0;
	}
	
	s = p->next;  //ָ��sָ��ai�ڵ�
	*x = s->data;
	p->next = p->next->next;	//ɾ���ڵ�
	free(s);					//�ͷ��ڴ� 
	return 1; 
}

//ListGet
int ListGet(SLNode *head,int i,DataType *x){
	SLNode *p;
	int j;
	p = head;
	j = -1;
	while(p->next !=head && j<i){
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

//Destroy
int Destroy(SLNode **head){
	SLNode *p,*p1;
	p = *head;
	while(p != head){
		p1 = p;
		p = p->next;
		free(p1);			//��ͷ��ʼɾ����NULL 
	}
	*head = NULL;	//��󷵻�һ���ձ�ͷ 
} 
