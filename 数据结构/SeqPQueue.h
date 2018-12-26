

// 优先级 队列
typedef struct {
	int proiorty;	//优先级
	ElemType elem;	//其他内容 
}DataType;

typedef struct {
	DataType queue[MaxSize];	//队列数组 
	int size;					//	元素个数	 
}SeqPQueue; 					//优先级队列结构体


// init
void QueueInit(SeqPQueue *q){
	q->size = 0;
} 

// 非空否
int QueueNotEmpty(SeqPQueue q){
	if(q.size <= 0) return 0;
	else return 1;
} 

// 入队
int QueueAppend(SeqPQueue *q,DataType x){
	if(q->size >= MaxSize){
		printf("队列已满 无法插入\n");
		return 0;
	}
	else{
		q->queue[q->size] = x;
		q->size ++;
		return 1;
	}
} 

// 出队
int QueueDelete(SeqPQueue *q,DataType *d){
	DataType min;
	int minIndex,i;
	
	if(q->size <=0){
		printf("队列已空 无元素出列\n");
		return 0;
	}
	else{
		min = q->queue[0];	//初始选 queue[0]最高级的元素 
		minIndex = 0;		//最高级元素的下标
		for (i=1;i<q->size;i++)	//寻找优先级最高的元素对应下标 
			if(q->queue[i].proiorty <min.proiorty){
				min = q->queue[i];
				minIndex = i;
			} 
			*d = q->queue[minIndex];	//找到优先级最高的元素
			for (i = minIndex+1;i<q->size;i++)	//数据元素依次前移
				q->queue[i-1] = q->queue[i];
			q->size --;
			return 1; 
	}
} 

// 取 优先级最高的元素
int QueueGet(SeqPQueue *q,DataType *d){
	DataType min;
	int minIndex,i;
	if(q->size <=0){
		printf("队列已空 无元素出列\n");
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
		*d = q->queue[minIndex];	//找到最高级元素
		return 1; 
	}
} 
