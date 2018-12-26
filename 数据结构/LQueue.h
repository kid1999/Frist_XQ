
//   ��ʽ����

typedef struct qnode{
	DataType data;
	struct qnode *next; 
}LQNode;

typedef struct {
	LQNode *front;		//��ͷָ��
	LQNode *rear; 		//��β 
}LQueue;

// init 
void QueueInit(LQueue *q){
	q->front = NULL;
	q->rear = NULL; 
} 

// �ǿշ�
int QueueNotEmpty(LQueue q){
	if(q.front == NULL) return 0;
	else return 1;
} 

// �����
void QueueAppend(LQueue *q ,DataType x){
	LQNode *p;
	p = (LQNode *)malloc(sizeof(LQNode));
	
	p->data = x;
	p->next = NULL;
	
	if(q->rear != NULL) q->rear->next = p;	//ԭ���зǿ� ��β�����½ڵ� 
	q->rear = p;							// �޸Ķ�βָ�� 
	if(q->front == NULL) q->front = p;		// ����ԭ��Ϊ��ʱ �޸Ķ�ͷָ�� 
}  

// ������
int QueueDetele(LQueue *q,DataType *d){
	LQNode *p;
	if(q->front ==NULL){
		printf("�����ѿ� �޷�����\n");
		return 0;
	}
	else{
		*d = q->front->data;
		p = q->front;
		q->front = q->front->next;   	// �����нڵ� ����
		if(q->front == NULL) q->rear = NULL;	//ɾ�����һ���ڵ� ��βָ�� Ϊ��
		
		free(p);
		return 1; 
	}
} 

//  ȡ��ͷ����Ԫ�� 
int QueueGet(LQueue q,DataType *d){
	if(q.front == NULL){
		printf("�����ѿ� �޷���������\n");
		return 0;
	} 
	else{
		*d = q.front->data;
		return 1;
	}
}

// ��������ռ�
void Destroy(LQueue q){
	LQNode *p,*p1;
	p = q.front;
	while(p != NULL){
		p1 = p;
		p = p->next;
		free(p1);
	}
	printf("�����ɹ�\n");
} 
