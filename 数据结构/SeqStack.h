
// 顺序链表
typedef struct {
	DataType stack[MaxSize];
	int top;
}SeqStack;

//init
void StackInitiate(SeqStack *s){
	s->top = 0;
} 

//非空否
int StackNotEmpyt(SeqStack s){
	if(s.top <=0) return 0;
	else return 1;
} 

//入栈
int StackPush(SeqStack *s,DataType x){
	if(s->top >= MaxSize){
		printf("栈堆已满无法插入!\n");
		return 0;
	}
	else{
		s->stack[s->top] = x;
		s->top ++;
		return 1;
	}
} 

// 出栈
int StackPop(SeqStack *s,DataType *d){
	if(s->top <=0){
		printf("栈堆已空无元素出栈\n");
		return 0;		
	}
	else{
		s->top --;
		*d = s->stack[s->top];
		return 1;
	}
} 

// 取占顶元素
int StackTop(SeqStack *s,DataType *d){
	if(s->top <=0){
		printf("栈堆已空\n");
		return 0;
	}
	else{
		*d = s->stack[s->top - 1];
		return 1;
	}
} 
