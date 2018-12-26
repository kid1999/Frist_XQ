
//  顺序循环队列
typedef struct {|
	DataType queue[MaxSize];
	int rear;	//队尾指针
	int front; //队头指针
	int count;	// 计数器		
}SeqCQueue;

// init
void QueueInitiate(SeqCQueue *q){
	q->rear = 0;
	q->front = 0;
	q->count = 0;
} 

// 非空否
int QueueNotEmpty(SeqCQueue q){
	if(q.count != 0) return 1;
	else return 0;
} 

// 入队列
int QueueAppend(SeqCQueue *q,DataType x)
{
	if(q->count > 0 && q->rear == q->front)
	{
		printf("队列已满无法插入!\n");
		return 0;
	 } 
	 else{
	 	q->queue[q->rear] = x;			//	x插入 队尾 
	 	q->rear = (q->rear +1) % MaxSize;	// 队尾 指示器加 1
		q->count ++;
		return 1; 
	 }
 } 
 
 
 // 出队列
 int QueueDelete(SeqCQueue *q,DataType *d){
 	if(q->count == 0){
 		printf("队列已空无法出栈\n");
 		return 0;
	 }
	 else{
	 	*d = q->queue[q->front];
	 	q->front = (q->count +1) % MaxSize;
	 	q->count --;
	 	return 1;
	 }
 } 
 
 // 取队头指针元素
 
 int QueueGet(SeqCQueue q,DataType *d){
 	if(q.count == 0){
 		printf("队列已空无数据元素可取\n");
		return 0; 
	 }
	 else{
	 	*d = q.queue[q.front];
		 return 1; 
	 } 
 } 
 

