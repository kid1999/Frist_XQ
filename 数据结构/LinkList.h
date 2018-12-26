
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

//delete
int ListDelete(SLNode *head,int i,DataType *x){
	SLNode *p,*s;
	int j;
	p = head;
	j = -1;
	while(p->next !=NULL && p->next->next != NULL && j<i-1){
		//p指向 i-1 个节点
		p = p->next;
		j++; 
	}
	if(j != i-1){
		printf("删除位置参数错\n");
		return 0;
	}
	
	s = p->next;  //指针s指向ai节点
	*x = s->data;
	p->next = p->next->next;	//删除节点
	free(s);					//释放内存 
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

//Destroy
int Destroy(SLNode **head){
	SLNode *p,*p1;
	p = *head;
	while(p != NULL){
		p1 = p;
		p = p->next;
		free(p1);			//从头开始删除到NULL 
	}
	*head = NULL;	//最后返回一个空表头 
} 

//  顺序插入 
void LinkListInsert(SLNode *head,DataType x){
	SLNode *p,*q,*curr;
	curr = head->next;	// curr 指向第一个元素 
	p = head;			// pre 指向头结点
	 
	while(curr != NULL && curr->data <=x){	//p指向插入节点位置 
		p = curr;
		curr = curr->next; 
	}
	//申请节点空间 
	q = (SLNode *)malloc(sizeof(SLNode));	//新节点
	q->data = x;
	
	//q所指向的新节点 插入p后面 
	q->next = p->next; 	// 插入步骤 1
	p->next = q;		//插入步骤 2 

}

//排序 链表
void LinkListSort(SLNode *head){
	SLNode *curr,*pre,*p,*q;
	
	p = head->next;		//	p 指针所指节点逐个取出作为插入节点 
	head->next = NULL;	//	head指针带头结点 初始 NULL
	
	while(p != NULL){
		curr = head->next;
		pre = head;
		while(curr != NULL && curr->data <= p->data){	//pre 指向插入节点位置 
			pre = curr;
			curr = curr->next;
		}
	
		q = p;		//	 q 指向要插入的节点 
		p = p->next; 	//p指针指向下一个节点 
		
		//把q指针所指节点插入pre指针所指节点后
		p->next = pre->next;
		pre->next = q; 
	} 
}
	
