//   线索二叉树

typedef struct Node{
	DataType data;
	int  leftThread;
	int  rightThread;
	struct Node *leftChild;
	struct Node *rightChild;
}ThreadBiTree;


//  init
void init(ThreadBiTree *curr,ThreadBiTree **pre){
	// 中序线索二叉树
	if(curr != NULL) {
		init(curr->leftChild,pre);	//中序线索化左子树
		if(curr->leftChild == NULL){
			curr->leftThread = 1;	// 左线索标记 
			curr->leftChild = *pre;	// 建立左线索指针 
		} 
		else curr->leftThread = 0;
		
		if(curr->rightChild != NULL)
			curr->rightThread = 0;
		else curr->rightThread = 1;
		
		if((*pre)->rightChild == NULL){
			(*pre)->rightThread = 1;	//右线索标记 
			(*pre)->rightChild = curr;	//右线索指针 
		} 
		else curr->rightThread = 0;
		
		*pre = curr; 	//前序节点指针 = 当前节点指针
		init(curr->rightChild,pre);		//中序线索化右子树 
	}
} 

void CreatThread(ThreadBiTree **root){
	// 创建中序线索化二叉树
	ThreadBiTree *t = *root;		//保留原来二叉树根节点指针
	ThreadBiTree  *curr ,*pre = *root;
	
	// 建立头结点
	*root = (ThreadBiTree*)malloc(sizeof(ThreadBiTree));
	if(t == NULL){
		(*root)->leftThread = 0;
		(*root)->rightThread = 0;
		(*root)->leftChild = *root;
		(*root)->rightChild = *root;
	} 
	else		//二叉树为空时
	{
		curr = t;
		(*root)->leftChild = t;		//置头结点的左指针
		(*root)->leftThread = 0;	//置头结点的左线索
		
		init(curr,&pre);	//线索化二叉树
		
		pre->rightChild = *root;	//置最后一个节点的右指针 
		pre->rightThread = 1; 		//最后一个节点的右线索
		(*root)->rightChild = pre;	//头结点的右指针
		(*root)->rightThread = 1;  	//头结点的 右线索 
	} 
} 
