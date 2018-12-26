typedef struct Node{
	DataType data;	//������
	struct Node *leftChild;
	struct Node *rightChild;	//������ָ�� 
}BiTreeNode;

// init
void Initiate(BiTreeNode **root){
	*root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
} 

// �����ڵ� 
//��ԭ����ڵ� Ϊ�� �²�����ڵ�
//��ԭ���ǿ�  ԭ�������ݲ����½ڵ����ڵ�
BiTreeNode *InsertLeftNode(BiTreeNode *curr,DataType x){
	BiTreeNode *s,*t;
	if(curr == NULL) return NULL;
	t = curr->leftChild;	//����ԭ����������ָ��
	s = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->leftChild = t;
	s->rightChild = NULL;
	
	curr->leftChild = s;	//�½ڵ��Ϊ curr������
	return curr->leftChild; 
} 

//�Ҳ���ڵ� 
BiTreeNode *InsertRightNode(BiTreeNode *curr,DataType x){
	BiTreeNode *s,*t;
	if(curr == NULL) return NULL;
	t = curr->rightChild;	//����ԭ����������ָ��
	s = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->rightChild = t;
	s->leftChild = NULL;
	
	curr->rightChild = s;	//�½ڵ��Ϊ curr������
	return curr->rightChild; 
}


// ����������
void Destroy(BiTreeNode **root){
	if((*root) != NULL && (*root)->leftChild != NULL) 
		Destroy(&(*root)->leftChild);
	if((*root) != NULL && (*root)->rightChild != NULL) 
		Destroy(&(*root)->rightChild);
	free(*root);
} 

//��ɾ������
//�� curr �ǿ� ɾ��curr��ָ����
//ɾ���ɹ�����˫�׽ڵ�ָ��
BiTreeNode *DeleteLeftTree(BiTreeNode *curr){
	if(curr == NULL || curr->leftChild == NULL) return NULL;
	
	Destroy(&curr->leftChild);
	curr->leftChild = NULL;
	return curr;
} 

//��ɾ������
BiTreeNode *DeleteRightTree(BiTreeNode *curr){
	if(curr == NULL || curr->leftChild == NULL) return NULL;
	
	Destroy(&curr->leftChild);
	curr->leftChild = NULL;
	return curr;
} 

		//  ����  ������
// ��ʾ�ڵ���Ϣ 
void visit(DataType item){
	printf("%c   ",item); 
}

// �������
void  preOrder(BiTreeNode *root,void visit(DataType item)){
	if(root != NULL){
		visit(root->data);		//�� 
		preOrder(root->leftChild,visit);	//�� 
		preOrder(root->rightChild,visit);	//�� 
	}
} 

//�������
void  inOrder(BiTreeNode *root,void visit(DataType item)){
	if(root != NULL){
		inOrder(root->leftChild,visit);	//�� 
		visit(root->data);		//�� 
		inOrder(root->rightChild,visit);	//�� 
	}
} 

//�������
void  PosOrder(BiTreeNode *root,void visit(DataType item)){
	if(root != NULL){
		PosOrder(root->leftChild,visit);	//�� 
		PosOrder(root->rightChild,visit);	//�� 
		visit(root->data);		//�� 
	}
} 


// ��ӡ ������
void PrintBiTree(BiTreeNode *root,int n){
	int i;
	if(root == NULL) return;	// �ݹ����
	PrintBiTree(root->rightChild,n+1);	//������ӡ������
	
	// ���ʸ��ڵ�
	for(i=0;i<n-1;i++)  printf("  ");
	if(n >0)
	{
		printf("----");
		printf("%c\n",root->data);
	 } 
	
	PrintBiTree(root->leftChild,n+1);		// ������ӡ������ 
} 

//  ����Ԫ��
BiTreeNode *Search(BiTreeNode *root,DataType x){
	// ��������Ԫ��x  �Ƿ��� ��������
	BiTreeNode *find = NULL;
	if(root!=NULL){
		if(root->data == x)
			find  = root;
		else{
			find = Search(root->leftChild,x);	//��������ѯ
			if(find == NULL)
				find = Search(root->rightChild,x);	//��������ѯ 
		}
	} 
	return find; 
} 

