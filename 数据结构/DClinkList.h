
//  ˫��ѭ������

typedef struct Node{
	DataType data;
	struct Node *next;
	struct Node *prior;
}DLNode;

//init
void ListInitiate(DLNode **head){
	*head = (DLNode *)malloc(sizeof(DLNode));
	(*head)->prior = *head;		//ǰ��ѭ��
	(*head)->next = *head;		//���ѭ�� 
}

// insert 
int ListInsert(DLNode *head,int i,DataType x){
	DLNode *p, *s;
	int j;
	
	p = head->next;
	j = 0;
	while(p !=head && j<i){		//pָ�� i �ڵ� 
		p = p->next;
		j++;
	}
	if(j != i){
		printf("����λ�ò�������\n");
		return 0;
	}
	
	s = (DLNode *)malloc(sizeof(DLNode));
	s->data = x;
	
	//���벽�� 
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	
	return 1;
} 

// delete
int ListDelete(DLNode *head,int i,DataType *x){
	DLNode *p;
	int j;
	p = head->next;
	j = 0;
	while(p->next !=head && j<i){	//��λ�� i Ԫ�� 
		p = p->next;
		j++;
	}
	*x = p->data;
	if(j != i){
		printf("ɾ��λ�ò�������\n");
		return 0;
	}
	
	//ɾ������ 
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return 1;
}

// Listlength
int ListLength(DLNode *head){
	DLNode *p = head;
	int size = 0;
	while(p->next !=head){
		p = p->next;
		size ++;
	}
	return size;
}

//Destroy
void Destroy(DLNode **head){
	DLNode *p,*p1;
	int i,n = ListLength(*head);
	
	p = *head;
	for (i =0;i<=n;i++){
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}
