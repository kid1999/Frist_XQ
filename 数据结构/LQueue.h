
//   链式队列

typedef struct qnode{
	DataType data;
	struct qnode *next; 
}LQNode;

typedef struct {
	LQNode *front;		//队头指针
	LQNode *rear; 		//队尾 
}LQueue;

// init 
void QueueInit(LQueue *q){
	q->front = NULL;
	q->rear = NULL; 
} 

// 非空否
int QueueNotEmpty(LQueue q){
	if(q.front == NULL) return 0;
	else return 1;
} 

// 入队列
void QueueAppend(LQueue *q ,DataType x){
	LQNode *p;
	p = (LQNode *)malloc(sizeof(LQNode));
	
	p->data = x;
	p->next = NULL;
	
	if(q->rear != NULL) q->rear->next = p;	//原队列非空 队尾加入新节点 
	q->rear = p;							// 修改队尾指针 
	if(q->front == NULL) q->front = p;		// 队列原来为空时 修改队头指针 
}  

// 出队列
int QueueDetele(LQueue *q,DataType *d){
	LQNode *p;
	if(q->front ==NULL){
		printf("队列已空 无法出队\n");
		return 0;
	}
	else{
		*d = q->front->data;
		p = q->front;
		q->front = q->front->next;   	// 出队列节点 脱链
		if(q->front == NULL) q->rear = NULL;	//删除最后一个节点 置尾指针 为空
		
		free(p);
		return 1; 
	}
} 

//  取队头数据元素 
int QueueGet(LQueue q,DataType *d){
	if(q.front == NULL){
		printf("队列已空 无法继续出队\n");
		return 0;
	} 
	else{
		*d = q.front->data;
		return 1;
	}
}

// 撤销申请空间
void Destroy(LQueue q){
	LQNode *p,*p1;
	p = q.front;
	while(p != NULL){
		p1 = p;
		p = p->next;
		free(p1);
	}
	printf("撤销成功\n");
} 
