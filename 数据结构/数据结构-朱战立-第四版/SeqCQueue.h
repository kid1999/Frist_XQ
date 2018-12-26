
//  ˳��ѭ������
typedef struct {|
	DataType queue[MaxSize];
	int rear;	//��βָ��
	int front; //��ͷָ��
	int count;	// ������		
}SeqCQueue;

// init
void QueueInitiate(SeqCQueue *q){
	q->rear = 0;
	q->front = 0;
	q->count = 0;
} 

// �ǿշ�
int QueueNotEmpty(SeqCQueue q){
	if(q.count != 0) return 1;
	else return 0;
} 

// �����
int QueueAppend(SeqCQueue *q,DataType x)
{
	if(q->count > 0 && q->rear == q->front)
	{
		printf("���������޷�����!\n");
		return 0;
	 } 
	 else{
	 	q->queue[q->rear] = x;			//	x���� ��β 
	 	q->rear = (q->rear +1) % MaxSize;	// ��β ָʾ���� 1
		q->count ++;
		return 1; 
	 }
 } 
 
 
 // ������
 int QueueDelete(SeqCQueue *q,DataType *d){
 	if(q->count == 0){
 		printf("�����ѿ��޷���ջ\n");
 		return 0;
	 }
	 else{
	 	*d = q->queue[q->front];
	 	q->front = (q->count +1) % MaxSize;
	 	q->count --;
	 	return 1;
	 }
 } 
 
 // ȡ��ͷָ��Ԫ��
 
 int QueueGet(SeqCQueue q,DataType *d){
 	if(q.count == 0){
 		printf("�����ѿ�������Ԫ�ؿ�ȡ\n");
		return 0; 
	 }
	 else{
	 	*d = q.queue[q.front];
		 return 1; 
	 } 
 } 
 

