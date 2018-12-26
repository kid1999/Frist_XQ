//   ����������

typedef struct Node{
	DataType data;
	int  leftThread;
	int  rightThread;
	struct Node *leftChild;
	struct Node *rightChild;
}ThreadBiTree;


//  init
void init(ThreadBiTree *curr,ThreadBiTree **pre){
	// ��������������
	if(curr != NULL) {
		init(curr->leftChild,pre);	//����������������
		if(curr->leftChild == NULL){
			curr->leftThread = 1;	// ��������� 
			curr->leftChild = *pre;	// ����������ָ�� 
		} 
		else curr->leftThread = 0;
		
		if(curr->rightChild != NULL)
			curr->rightThread = 0;
		else curr->rightThread = 1;
		
		if((*pre)->rightChild == NULL){
			(*pre)->rightThread = 1;	//��������� 
			(*pre)->rightChild = curr;	//������ָ�� 
		} 
		else curr->rightThread = 0;
		
		*pre = curr; 	//ǰ��ڵ�ָ�� = ��ǰ�ڵ�ָ��
		init(curr->rightChild,pre);		//���������������� 
	}
} 

void CreatThread(ThreadBiTree **root){
	// ��������������������
	ThreadBiTree *t = *root;		//����ԭ�����������ڵ�ָ��
	ThreadBiTree  *curr ,*pre = *root;
	
	// ����ͷ���
	*root = (ThreadBiTree*)malloc(sizeof(ThreadBiTree));
	if(t == NULL){
		(*root)->leftThread = 0;
		(*root)->rightThread = 0;
		(*root)->leftChild = *root;
		(*root)->rightChild = *root;
	} 
	else		//������Ϊ��ʱ
	{
		curr = t;
		(*root)->leftChild = t;		//��ͷ������ָ��
		(*root)->leftThread = 0;	//��ͷ����������
		
		init(curr,&pre);	//������������
		
		pre->rightChild = *root;	//�����һ���ڵ����ָ�� 
		pre->rightThread = 1; 		//���һ���ڵ��������
		(*root)->rightChild = pre;	//ͷ������ָ��
		(*root)->rightThread = 1;  	//ͷ���� ������ 
	} 
} 
