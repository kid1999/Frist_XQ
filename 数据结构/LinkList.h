
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

//delete
int ListDelete(SLNode *head,int i,DataType *x){
	SLNode *p,*s;
	int j;
	p = head;
	j = -1;
	while(p->next !=NULL && p->next->next != NULL && j<i-1){
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

//Destroy
int Destroy(SLNode **head){
	SLNode *p,*p1;
	p = *head;
	while(p != NULL){
		p1 = p;
		p = p->next;
		free(p1);			//��ͷ��ʼɾ����NULL 
	}
	*head = NULL;	//��󷵻�һ���ձ�ͷ 
} 

//  ˳����� 
void LinkListInsert(SLNode *head,DataType x){
	SLNode *p,*q,*curr;
	curr = head->next;	// curr ָ���һ��Ԫ�� 
	p = head;			// pre ָ��ͷ���
	 
	while(curr != NULL && curr->data <=x){	//pָ�����ڵ�λ�� 
		p = curr;
		curr = curr->next; 
	}
	//����ڵ�ռ� 
	q = (SLNode *)malloc(sizeof(SLNode));	//�½ڵ�
	q->data = x;
	
	//q��ָ����½ڵ� ����p���� 
	q->next = p->next; 	// ���벽�� 1
	p->next = q;		//���벽�� 2 

}

//���� ����
void LinkListSort(SLNode *head){
	SLNode *curr,*pre,*p,*q;
	
	p = head->next;		//	p ָ����ָ�ڵ����ȡ����Ϊ����ڵ� 
	head->next = NULL;	//	headָ���ͷ��� ��ʼ NULL
	
	while(p != NULL){
		curr = head->next;
		pre = head;
		while(curr != NULL && curr->data <= p->data){	//pre ָ�����ڵ�λ�� 
			pre = curr;
			curr = curr->next;
		}
	
		q = p;		//	 q ָ��Ҫ����Ľڵ� 
		p = p->next; 	//pָ��ָ����һ���ڵ� 
		
		//��qָ����ָ�ڵ����preָ����ָ�ڵ��
		p->next = pre->next;
		pre->next = q; 
	} 
}
	
