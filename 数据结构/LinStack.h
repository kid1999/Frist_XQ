
// 链式堆栈  头节点指向 top 方便插入删除

typedef struct snode{
	DataType data;
	struct snode *next;
}LSNode;

//init 
void StackInitiate(LSNode **head){
	*head = (LSNode *)malloc(sizeof(LSNode));
	(*head)->next = NULL;
}

// 非空否
int StackNotEmpty(LSNode *head){
	if(head->next == NULL) 	return 0;	
	else return 1;
} 

//入栈
 void StackPush(LSNode *head, DataType x){
 	LSNode *p;
 	p = (LSNode *)malloc(sizeof(LSNode));
 	p->data = x;
	p->next = head->next;
	head->next = p;
 } 
 
 // 出栈
int StackPop(LSNode *head,DataType *d){
	LSNode *p = head->next;
	if(p == NULL){
		printf("堆栈已空出错！\n");
		return 0;
	}
		head->next = p->next;
		*d = p->data;
		free(p);
		return 1;	
} 

//取 栈顶元素
int StackTop(LSNode *head,DataType *d){
	LSNode *p = head->next;
	if(p == NULL){
		printf("堆栈已空出错！\n");
		return 0;
	}
	*d = p->data;
	return 1;
} 



// 撤销动态链表
void Destroy(LSNode *head){
	LSNode *p1,*top;	
	top = head;
	while(top->next != NULL){
		p1 = top;
		top = top->next;
		free(p1);
	}
	printf("撤销完成！");
} 
