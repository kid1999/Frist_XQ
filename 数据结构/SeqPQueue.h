

// ���ȼ� ����
typedef struct {
	int proiorty;	//���ȼ�
	ElemType elem;	//�������� 
}DataType;

typedef struct {
	DataType queue[MaxSize];	//�������� 
	int size;					//	Ԫ�ظ���	 
}SeqPQueue; 					//���ȼ����нṹ��


// init
void QueueInit(SeqPQueue *q){
	q->size = 0;
} 

// �ǿշ�
int QueueNotEmpty(SeqPQueue q){
	if(q.size <= 0) return 0;
	else return 1;
} 

// ���
int QueueAppend(SeqPQueue *q,DataType x){
	if(q->size >= MaxSize){
		printf("�������� �޷�����\n");
		return 0;
	}
	else{
		q->queue[q->size] = x;
		q->size ++;
		return 1;
	}
} 

// ����
int QueueDelete(SeqPQueue *q,DataType *d){
	DataType min;
	int minIndex,i;
	
	if(q->size <=0){
		printf("�����ѿ� ��Ԫ�س���\n");
		return 0;
	}
	else{
		min = q->queue[0];	//��ʼѡ queue[0]��߼���Ԫ�� 
		minIndex = 0;		//��߼�Ԫ�ص��±�
		for (i=1;i<q->size;i++)	//Ѱ�����ȼ���ߵ�Ԫ�ض�Ӧ�±� 
			if(q->queue[i].proiorty <min.proiorty){
				min = q->queue[i];
				minIndex = i;
			} 
			*d = q->queue[minIndex];	//�ҵ����ȼ���ߵ�Ԫ��
			for (i = minIndex+1;i<q->size;i++)	//����Ԫ������ǰ��
				q->queue[i-1] = q->queue[i];
			q->size --;
			return 1; 
	}
} 

// ȡ ���ȼ���ߵ�Ԫ��
int QueueGet(SeqPQueue *q,DataType *d){
	DataType min;
	int minIndex,i;
	if(q->size <=0){
		printf("�����ѿ� ��Ԫ�س���\n");
		return 0;
	}
	else{
		min = q->queue[0];
		minIndex = 0;
		for(i=1;i<q->size;i++){
			if(q->queue[i].proiorty <min.proiorty)
			{
				min = q->queue[i];
				minIndex = i;
			}
		}
		*d = q->queue[minIndex];	//�ҵ���߼�Ԫ��
		return 1; 
	}
} 
