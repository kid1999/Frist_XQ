
// ˳������
typedef struct {
	DataType stack[MaxSize];
	int top;
}SeqStack;

//init
void StackInitiate(SeqStack *s){
	s->top = 0;
} 

//�ǿշ�
int StackNotEmpyt(SeqStack s){
	if(s.top <=0) return 0;
	else return 1;
} 

//��ջ
int StackPush(SeqStack *s,DataType x){
	if(s->top >= MaxSize){
		printf("ջ�������޷�����!\n");
		return 0;
	}
	else{
		s->stack[s->top] = x;
		s->top ++;
		return 1;
	}
} 

// ��ջ
int StackPop(SeqStack *s,DataType *d){
	if(s->top <=0){
		printf("ջ���ѿ���Ԫ�س�ջ\n");
		return 0;		
	}
	else{
		s->top --;
		*d = s->stack[s->top];
		return 1;
	}
} 

// ȡռ��Ԫ��
int StackTop(SeqStack *s,DataType *d){
	if(s->top <=0){
		printf("ջ���ѿ�\n");
		return 0;
	}
	else{
		*d = s->stack[s->top - 1];
		return 1;
	}
} 
