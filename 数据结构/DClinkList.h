
//  双向循环链表

typedef struct Node{
	DataType data;
	struct Node *next;
	struct Node *prior;
}DLNode;

//init
void ListInitiate(DLNode **head){
	*head = (DLNode *)malloc(sizeof(DLNode));
	(*head)->prior = *head;		//前驱循环
	(*head)->next = *head;		//后继循环 
}

// insert 
int ListInsert(DLNode *head,int i,DataType x){
	DLNode *p, *s;
	int j;
	
	p = head->next;
	j = 0;
	while(p !=head && j<i){		//p指向 i 节点 
		p = p->next;
		j++;
	}
	if(j != i){
		printf("插入位置参数出错\n");
		return 0;
	}
	
	s = (DLNode *)malloc(sizeof(DLNode));
	s->data = x;
	
	//插入步骤 
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
	while(p->next !=head && j<i){	//定位到 i 元素 
		p = p->next;
		j++;
	}
	*x = p->data;
	if(j != i){
		printf("删除位置参数错误\n");
		return 0;
	}
	
	//删除步骤 
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
